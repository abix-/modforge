//! Route search from the player to a point, using only moves the game
//! proves: walking from the game's own navigation, and jumps or dashes
//! only when a body the player's size, swept along the move's arc with
//! the game's own movement collision, touches nothing.
//!
//! Prior art: navigation libraries generate jump links the same way:
//! Recast's off-mesh connections and Unreal's NavLinkProxy are what an
//! AI jumps along, and jump-link generators simulate the character's
//! arc between two pieces of walkable ground and keep it only when the
//! collision shape fits along it.
//!
//! Steps, all inside the game process:
//! 1. Read the player's body (capsule) and jump numbers from the game.
//! 2. Sample walkable ground in a box with the game's nav projection.
//! 3. Join samples into patches only where the game's navigation finds a
//!    complete walking path between them.
//! 4. Between patches, try the closest sample pairs as jumps (or a jump
//!    and dash), each swept with an invisible probe Character.
//! 5. Breadth first over patches for the fewest moves. When the target's
//!    patch cannot be reached the route goes to the closest reachable
//!    ground and says so.
//! 6. Optionally draw the route as pipes at head height, cut into 2 m
//!    pieces on the ground so none run into a bulge.
//!
//! The work runs on a worker thread in short game-thread batches, so the
//! game keeps running. Ops: `route.find`, `route.state`, `route.stop`,
//! `route.clear`.

use std::sync::Arc;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

use parking_lot::Mutex;
use serde_json::{Value, json};

use crate::ue::UObject;

static STATE: Mutex<Value> = Mutex::new(Value::Null);
static RUNNING: AtomicBool = AtomicBool::new(false);
static CANCEL: AtomicBool = AtomicBool::new(false);
/// Pipes spawned by the last draw, for `route.clear`.
static PIPES: Mutex<Vec<u64>> = Mutex::new(Vec::new());

/// A head is this far above the floor.
const HEAD: f64 = 170.0;
/// Pipes are cut into pieces this long.
const PIECE: f64 = 200.0;

#[derive(Clone, Copy, Debug)]
struct Body {
    radius: f64,
    half: f64,
    jump: f64,
    gravity: f64,
    run: f64,
}

#[derive(Clone, Debug)]
struct Search {
    player: u64,
    from: Option<[f64; 3]>,
    to: [f64; 3],
    bbox: Option<[f64; 6]>,
    step: f64,
    dash: f64,
    draw: bool,
}

fn progress(phase: &str, extra: Value) {
    let mut s = STATE.lock();
    let mut v = json!({"phase": phase, "running": RUNNING.load(Ordering::Relaxed)});
    if let (Some(m), Some(e)) = (v.as_object_mut(), extra.as_object()) {
        m.extend(e.clone());
    }
    *s = v;
}

/// Run `f` on the game thread and bring its value back.
fn game<T: Send + 'static>(f: impl FnOnce() -> Result<T, String> + Send + 'static) -> Result<T, String> {
    if CANCEL.load(Ordering::Relaxed) {
        return Err("stopped".into());
    }
    let slot: Arc<Mutex<Option<T>>> = Arc::new(Mutex::new(None));
    let out = slot.clone();
    crate::game_thread::run(
        move || {
            let v = modforge::seh::guard(f).map_err(|e| format!("fault on the game thread: {e:?}"))??;
            *out.lock() = Some(v);
            Ok(Value::Null)
        },
        Duration::from_secs(30),
    )?;
    let v = slot.lock().take();
    v.ok_or_else(|| "game thread gave no result".into())
}

fn obj(addr: u64) -> Result<&'static UObject, String> {
    if addr == 0 || !crate::ue::is_live(addr as usize) {
        return Err(format!("0x{addr:X} is not a live object"));
    }
    // SAFETY: just checked live in GObjects.
    Ok(unsafe { &*(addr as *const UObject) })
}

/// Game thread.
fn call(addr: u64, class: &str, function: &str, params: Value) -> Result<Value, String> {
    let o = obj(addr)?;
    let m = params.as_object().cloned().unwrap_or_default();
    // SAFETY: game thread (callers run inside `game`), live target.
    unsafe { crate::reflect::call(o, class, function, &m) }
}

fn get(addr: u64, fields: &[&str]) -> Result<Value, String> {
    let names: Vec<String> = fields.iter().map(|s| s.to_string()).collect();
    // SAFETY: game thread, live object.
    unsafe { crate::reflect::get_fields(obj(addr)?, &names) }
}

fn addr_of(v: &Value) -> Option<u64> {
    v["addr"].as_str().and_then(|s| u64::from_str_radix(s.trim_start_matches("0x"), 16).ok()).filter(|a| *a != 0)
}

fn vec3(v: &Value) -> Option<[f64; 3]> {
    Some([v["X"].as_f64()?, v["Y"].as_f64()?, v["Z"].as_f64()?])
}

fn xyz(p: [f64; 3]) -> Value {
    json!({"X": p[0], "Y": p[1], "Z": p[2]})
}

fn hex(a: u64) -> String {
    format!("0x{a:X}")
}

fn flat(a: [f64; 3], b: [f64; 3]) -> f64 {
    ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt()
}

fn dist(a: [f64; 3], b: [f64; 3]) -> f64 {
    (flat(a, b).powi(2) + (a[2] - b[2]).powi(2)).sqrt()
}

/// Game thread: the player's body and its centre location.
fn read_body(player: u64) -> Result<(Body, [f64; 3]), String> {
    let parts = get(player, &["CharacterMovement", "CapsuleComponent"])?;
    let moving = addr_of(&parts["CharacterMovement"]).ok_or("player has no CharacterMovement")?;
    let capsule = addr_of(&parts["CapsuleComponent"]).ok_or("player has no CapsuleComponent")?;
    let m = get(moving, &["JumpZVelocity", "MaxWalkSpeed"])?;
    let c = get(capsule, &["CapsuleRadius", "CapsuleHalfHeight"])?;
    let g = call(moving, "MovementComponent", "GetGravityZ", json!({}))?;
    let at = call(player, "Actor", "K2_GetActorLocation", json!({}))?;
    let body = Body {
        radius: c["CapsuleRadius"].as_f64().ok_or("CapsuleRadius")?,
        half: c["CapsuleHalfHeight"].as_f64().ok_or("CapsuleHalfHeight")?,
        jump: m["JumpZVelocity"].as_f64().ok_or("JumpZVelocity")?,
        gravity: -g["ReturnValue"].as_f64().ok_or("GetGravityZ")?,
        run: m["MaxWalkSpeed"].as_f64().ok_or("MaxWalkSpeed")?,
    };
    if body.gravity <= 0.0 {
        return Err(format!("gravity {} is not downward", body.gravity));
    }
    Ok((body, vec3(&at["ReturnValue"]).ok_or("player location")?))
}

/// Game thread: the nearest walkable ground to `p`.
fn project(ctx: u64, p: [f64; 3], extent: [f64; 3]) -> Option<[f64; 3]> {
    let r = call(ctx, "NavigationSystemV1", "K2_ProjectPointToNavigation", json!({"WorldContextObject": hex(ctx), "Point": xyz(p), "QueryExtent": xyz(extent)})).ok()?;
    (r["ReturnValue"] == true).then(|| vec3(&r["ProjectedLocation"])).flatten()
}

/// Game thread: the game's complete walking path from a to b, as points.
fn walk_path(ctx: u64, a: [f64; 3], b: [f64; 3]) -> Option<(Vec<[f64; 3]>, f64)> {
    let r = call(ctx, "NavigationSystemV1", "FindPathToLocationSynchronously", json!({"WorldContextObject": hex(ctx), "PathStart": xyz(a), "PathEnd": xyz(b)})).ok()?;
    let path = addr_of(&r["ReturnValue"])?;
    let partial = call(path, "NavigationPath", "IsPartial", json!({})).ok()?;
    if partial["ReturnValue"] != false {
        return None;
    }
    let len = call(path, "NavigationPath", "GetPathLength", json!({})).ok()?["ReturnValue"].as_f64()?;
    // SAFETY: game thread, live path object.
    let pts = unsafe { crate::reflect::array_get(obj(path).ok()?, "PathPoints", None) }.ok()?;
    let pts: Vec<[f64; 3]> = pts["elements"].as_array()?.iter().filter_map(vec3).collect();
    (pts.len() >= 2).then_some((pts, len))
}

/// The body's centre along a move from floor point p to floor point q:
/// a jump at the body's launch speed and gravity, with the run speed
/// needed to cover the distance; or, with `dash`, up to the apex, `dash`
/// across at that height and a fall. None when the move cannot make it.
fn arc(b: &Body, p: [f64; 3], q: [f64; 3], dash: Option<f64>) -> Option<Vec<[f64; 3]>> {
    let lift = b.half + 2.0;
    let across = flat(p, q);
    let rise = q[2] - p[2];
    let disc = b.jump * b.jump - 2.0 * b.gravity * rise;
    if disc < 0.0 {
        return None;
    }
    let air = (b.jump + disc.sqrt()) / b.gravity;
    let at = |s: f64, z: f64| [p[0] + (q[0] - p[0]) * s, p[1] + (q[1] - p[1]) * s, z + lift];
    let mut pts = Vec::new();
    let Some(dash) = dash else {
        if across / air > b.run {
            return None;
        }
        for k in 0..=12 {
            let t = air * k as f64 / 12.0;
            pts.push(at(t / air, p[2] + b.jump * t - b.gravity * t * t / 2.0));
        }
        return Some(pts);
    };
    let apex_t = b.jump / b.gravity;
    let apex = p[2] + b.jump * apex_t / 2.0;
    if apex < q[2] || across > dash + b.run * apex_t * 2.0 {
        return None;
    }
    pts.push(at(0.0, p[2]));
    pts.push(at(0.1, apex));
    let fall = ((2.0 * (apex - q[2]) / b.gravity).sqrt() * b.run / across.max(1.0)).min(0.3);
    for k in 1..=8 {
        pts.push(at(0.1 + (0.9 - fall) * k as f64 / 8.0, apex));
    }
    pts.push(at(1.0, q[2]));
    Some(pts)
}

/// Game thread: an invisible Character the player's size, movement off.
fn spawn_probe(player: u64, body: &Body, at: [f64; 3]) -> Result<u64, String> {
    let ctx = hex(player);
    let transform = json!({"Rotation": {"X": 0, "Y": 0, "Z": 0, "W": 1}, "Translation": xyz([at[0], at[1], at[2] + 400.0]), "Scale3D": {"X": 1, "Y": 1, "Z": 1}});
    let begin = call(player, "GameplayStatics", "BeginDeferredActorSpawnFromClass", json!({"WorldContextObject": ctx, "ActorClass": "class:Character", "SpawnTransform": transform, "CollisionHandlingOverride": 1}))?;
    let probe = addr_of(&begin["ReturnValue"]).ok_or("probe spawn failed")?;
    call(player, "GameplayStatics", "FinishSpawningActor", json!({"Actor": hex(probe), "SpawnTransform": transform}))?;
    let parts = get(probe, &["CapsuleComponent", "CharacterMovement"])?;
    if let Some(c) = addr_of(&parts["CapsuleComponent"]) {
        call(c, "CapsuleComponent", "SetCapsuleSize", json!({"InRadius": body.radius, "InHalfHeight": body.half, "bUpdateOverlaps": false}))?;
    }
    if let Some(m) = addr_of(&parts["CharacterMovement"]) {
        call(m, "CharacterMovementComponent", "SetMovementMode", json!({"NewMovementMode": 0, "NewCustomMode": 0}))?;
    }
    Ok(probe)
}

/// Game thread: sweep the probe along `pts`. True when it touches
/// nothing but the player and the floor it lands on.
fn sweep_clear(probe: u64, body: &Body, player_at: [f64; 3], pts: &[[f64; 3]]) -> bool {
    let mv = |p: [f64; 3], swept: bool| call(probe, "Actor", "K2_SetActorLocation", json!({"NewLocation": xyz(p), "bSweep": swept, "bTeleport": true}));
    if mv(pts[0], false).is_err() {
        return false;
    }
    for (k, p) in pts.iter().enumerate().skip(1) {
        let Ok(r) = mv(*p, true) else { return false };
        let hit = &r["SweepHitResult"];
        if hit["bBlockingHit"] != true {
            continue;
        }
        let point = vec3(&hit["ImpactPoint"]).unwrap_or(*p);
        // The player's own body.
        if flat(point, player_at) < body.radius * 2.0 + 20.0 && (point[2] - player_at[2]).abs() < body.half + 20.0 {
            continue;
        }
        let up = hit["ImpactNormal"]["Z"].as_f64().unwrap_or(0.0);
        return k == pts.len() - 1 && up > 0.7;
    }
    true
}

fn run(s: Search) -> Result<Value, String> {
    let t = Instant::now();
    let player = s.player;
    let (body, centre) = game(move || read_body(player))?;
    let start = s.from.unwrap_or([centre[0], centre[1], centre[2] - body.half]);
    let goal = s.to;
    let m = 1500.0;
    let bbox = s.bbox.unwrap_or([
        start[0].min(goal[0]) - m,
        start[0].max(goal[0]) + m,
        start[1].min(goal[1]) - m,
        start[1].max(goal[1]) + m,
        start[2].min(goal[2]) - 300.0,
        start[2].max(goal[2]) + 300.0,
    ]);
    let step = s.step;

    // 2. Walkable ground, one column of the box per game-thread batch.
    let mut samples: Vec<[f64; 3]> = Vec::new();
    let mut x = bbox[0];
    while x <= bbox[1] {
        let col = game(move || {
            let mut out = Vec::new();
            let mut y = bbox[2];
            while y <= bbox[3] {
                let mut z = bbox[4];
                while z <= bbox[5] {
                    if let Some(p) = project(player, [x, y, z], [step / 2.0, step / 2.0, 100.0]) {
                        out.push(p);
                    }
                    z += 200.0;
                }
                y += step;
            }
            Ok(out)
        })?;
        for p in col {
            if !samples.iter().any(|q| (q[0] - p[0]).abs() < 50.0 && (q[1] - p[1]).abs() < 50.0 && (q[2] - p[2]).abs() < 50.0) {
                samples.push(p);
            }
        }
        progress("sampling ground", json!({"samples": samples.len(), "done": (x - bbox[0]) / (bbox[1] - bbox[0]).max(1.0)}));
        x += step;
    }
    let goal_ground = game(move || Ok(project(player, goal, [150.0, 150.0, 300.0])))?;
    samples.push(start);
    if let Some(g) = goal_ground {
        samples.push(g);
    }
    let n = samples.len();

    // 3. Patches: samples the game walks between.
    let mut patch: Vec<usize> = (0..n).collect();
    fn root(p: &mut [usize], i: usize) -> usize {
        let mut r = i;
        while p[r] != r {
            r = p[r];
        }
        p[i] = r;
        r
    }
    let shared = Arc::new(samples.clone());
    for i in 0..n {
        let near: Vec<usize> = (i + 1..n).filter(|&j| flat(samples[i], samples[j]) <= step * 1.5 && (samples[i][2] - samples[j][2]).abs() <= step).collect();
        let near: Vec<usize> = near.into_iter().filter(|&j| root(&mut patch, i) != root(&mut patch, j)).collect();
        if near.is_empty() {
            continue;
        }
        let sm = shared.clone();
        let joined = game(move || {
            Ok(near
                .into_iter()
                .filter(|&j| walk_path(player, sm[i], sm[j]).is_some_and(|(_, len)| len <= flat(sm[i], sm[j]) * 1.5 + 100.0))
                .collect::<Vec<_>>())
        })?;
        for j in joined {
            let (ri, rj) = (root(&mut patch, i), root(&mut patch, j));
            patch[ri] = rj;
        }
        if i % 20 == 0 {
            progress("joining walkable ground", json!({"samples": n, "done": i as f64 / n as f64}));
        }
    }
    let mut groups: std::collections::BTreeMap<usize, Vec<usize>> = Default::default();
    for i in 0..n {
        let r = root(&mut patch, i);
        groups.entry(r).or_default().push(i);
    }
    let groups: Vec<Vec<usize>> = groups.into_values().collect();
    let group_of = |i: usize| groups.iter().position(|g| g.contains(&i)).unwrap_or(0);
    let from = group_of(n - if goal_ground.is_some() { 2 } else { 1 });
    let to = goal_ground.map(|_| group_of(n - 1));

    // 4 and 5. Moves between patches, checked with the probe; fewest moves.
    let probe = game(move || spawn_probe(player, &body, start))?;
    let groups_arc = Arc::new(groups.clone());
    let max_across = s.dash + 2.0 * body.run * body.jump / body.gravity;
    let dash = s.dash;
    let mut prev: Vec<Option<(usize, String, [f64; 3], [f64; 3])>> = vec![None; groups.len()];
    let mut seen = vec![false; groups.len()];
    seen[from] = true;
    let mut queue = std::collections::VecDeque::from([from]);
    let mut swept = 0usize;
    let result = (|| -> Result<(), String> {
        while let Some(a) = queue.pop_front() {
            if Some(a) == to {
                break;
            }
            let unseen: Vec<usize> = (0..groups.len()).filter(|&b| !seen[b]).collect();
            let (sm, gs) = (shared.clone(), groups_arc.clone());
            let links = game(move || {
                let mut out = Vec::new();
                let mut tried = 0usize;
                for b in unseen {
                    let mut pairs: Vec<(f64, [f64; 3], [f64; 3])> = Vec::new();
                    for &i in &gs[a] {
                        for &j in &gs[b] {
                            let (p, q) = (sm[i], sm[j]);
                            let d = flat(p, q);
                            if q[2] - p[2] <= body.jump * body.jump / (2.0 * body.gravity) && d <= max_across {
                                pairs.push((d, p, q));
                            }
                        }
                    }
                    pairs.sort_by(|x, y| x.0.total_cmp(&y.0));
                    for (_, p, q) in pairs.into_iter().take(6) {
                        let (kind, pts) = match arc(&body, p, q, None) {
                            Some(pts) => (if q[2] < p[2] - 60.0 { "drop" } else { "jump" }, pts),
                            None => match (dash > 0.0).then(|| arc(&body, p, q, Some(dash))).flatten() {
                                Some(pts) => ("jump and dash", pts),
                                None => continue,
                            },
                        };
                        tried += 1;
                        if sweep_clear(probe, &body, centre, &pts) {
                            out.push((b, kind.to_string(), p, q));
                            break;
                        }
                    }
                }
                Ok((out, tried))
            })?;
            swept += links.1;
            for (b, kind, p, q) in links.0 {
                if !seen[b] {
                    seen[b] = true;
                    prev[b] = Some((a, kind, p, q));
                    queue.push_back(b);
                }
            }
            progress("checking jumps and dashes", json!({"patches": groups.len(), "reached": seen.iter().filter(|s| **s).count(), "swept": swept}));
        }
        Ok(())
    })();
    let _ = game(move || call(probe, "Actor", "K2_DestroyActor", json!({})));
    result?;

    // The end: the target's ground when reached, else the closest ground reached.
    let reached_target = to.is_some_and(|g| seen[g]);
    let end_group = if reached_target {
        to.unwrap_or(from)
    } else {
        (0..groups.len()).filter(|&g| seen[g]).min_by(|&x, &y| {
            let d = |g: usize| groups[g].iter().map(|&i| dist(samples[i], goal)).fold(f64::MAX, f64::min);
            d(x).total_cmp(&d(y))
        }).unwrap_or(from)
    };
    let end_point = groups[end_group].iter().map(|&i| samples[i]).min_by(|x, y| dist(*x, goal).total_cmp(&dist(*y, goal))).unwrap_or(start);
    let mut steps = Vec::new();
    let mut g = end_group;
    while let Some((a, kind, p, q)) = prev[g].clone() {
        steps.push((kind, p, q));
        g = a;
    }
    steps.reverse();
    let mut points = vec![start];
    let mut moves: Vec<String> = Vec::new();
    for (kind, p, q) in &steps {
        points.push(*p);
        moves.push("walk".into());
        points.push(*q);
        moves.push(kind.clone());
    }
    points.push(end_point);
    moves.push("walk".into());

    let pipes = if s.draw { draw(player, &body, &points, &moves)? } else { 0 };
    Ok(json!({
        "reached_target": reached_target,
        "end": end_point,
        "end_from_target_m": dist(end_point, goal) / 100.0,
        "points": points,
        "moves": moves,
        "steps": steps.iter().map(|(k, p, q)| json!({"move": k, "from": p, "to": q, "across_m": flat(*p, *q) / 100.0, "up_m": (q[2] - p[2]) / 100.0})).collect::<Vec<_>>(),
        "samples": n,
        "patches": groups.len(),
        "swept": swept,
        "pipes": pipes,
        "seconds": t.elapsed().as_secs_f64(),
        "body": {"radius": body.radius, "half_height": body.half, "jump_speed": body.jump, "gravity": body.gravity, "run": body.run},
    }))
}

/// Pipes along the route at head height: walking legs from the game's
/// path cut into PIECE pieces each put on the ground under it, moves
/// along their arcs. Returns how many were spawned.
fn draw(player: u64, body: &Body, points: &[[f64; 3]], moves: &[String]) -> Result<usize, String> {
    clear_pipes()?;
    let (points, moves, body) = (points.to_vec(), moves.to_vec(), *body);
    let line = game(move || {
        let mut line: Vec<[f64; 3]> = vec![points[0]];
        for (w, kind) in points.windows(2).zip(&moves) {
            let (a, b) = (w[0], w[1]);
            if kind == "walk" {
                let pts = walk_path(player, a, b).map(|(p, _)| p).unwrap_or_else(|| vec![a, b]);
                for seg in pts.windows(2) {
                    let pieces = ((flat(seg[0], seg[1]) / PIECE).ceil() as usize).max(1);
                    for k in 1..=pieces {
                        let t = k as f64 / pieces as f64;
                        let p = [seg[0][0] + (seg[1][0] - seg[0][0]) * t, seg[0][1] + (seg[1][1] - seg[0][1]) * t, seg[0][2] + (seg[1][2] - seg[0][2]) * t];
                        line.push(if k < pieces { project(player, p, [50.0, 50.0, 300.0]).unwrap_or(p) } else { p });
                    }
                }
            } else {
                let dash = (kind == "jump and dash").then_some(flat(a, b));
                match arc(&body, a, b, dash) {
                    Some(pts) => line.extend(pts.into_iter().skip(1).map(|p| [p[0], p[1], p[2] - body.half - 2.0])),
                    None => line.push(b),
                }
            }
        }
        Ok(line)
    })?;
    let spawned = game(move || {
        let cylinder = crate::ue::actor::find_objects_by_chain("StaticMesh")
            .into_iter()
            // SAFETY: addresses from the GObjects walk.
            .find(|p| unsafe { &*(*p as *const UObject) }.name() == "Cylinder")
            .map(|p| p as u64)
            .ok_or("no loaded Cylinder mesh")?;
        let mut spawned = Vec::new();
        for w in line.windows(2) {
            let (a, b) = ([w[0][0], w[0][1], w[0][2] + HEAD], [w[1][0], w[1][1], w[1][2] + HEAD]);
            let d = [b[0] - a[0], b[1] - a[1], b[2] - a[2]];
            let len = (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]).sqrt();
            if len < 10.0 {
                continue;
            }
            let u = [d[0] / len, d[1] / len, d[2] / len];
            // Turn the cylinder's +Z onto the piece: axis Z x u, angle acos(u.z).
            let (ax, ay) = (-u[1], u[0]);
            let n = (ax * ax + ay * ay).sqrt();
            let half = u[2].clamp(-1.0, 1.0).acos() / 2.0;
            let (qx, qy) = if n < 1e-6 { (0.0, 0.0) } else { (ax / n * half.sin(), ay / n * half.sin()) };
            let transform = json!({
                "Rotation": {"X": qx, "Y": qy, "Z": 0.0, "W": half.cos()},
                "Translation": xyz([(a[0] + b[0]) / 2.0, (a[1] + b[1]) / 2.0, (a[2] + b[2]) / 2.0]),
                "Scale3D": {"X": 0.8, "Y": 0.8, "Z": len / 100.0},
            });
            let begin = call(player, "GameplayStatics", "BeginDeferredActorSpawnFromClass", json!({"WorldContextObject": hex(player), "ActorClass": "class:StaticMeshActor", "SpawnTransform": transform, "CollisionHandlingOverride": 1}))?;
            let Some(actor) = addr_of(&begin["ReturnValue"]) else { continue };
            call(player, "GameplayStatics", "FinishSpawningActor", json!({"Actor": hex(actor), "SpawnTransform": transform}))?;
            spawned.push(actor);
            let Some(c) = addr_of(&get(actor, &["StaticMeshComponent"])?["StaticMeshComponent"]) else { continue };
            call(c, "SceneComponent", "SetMobility", json!({"NewMobility": 2}))?;
            call(c, "StaticMeshComponent", "SetStaticMesh", json!({"NewMesh": hex(cylinder)}))?;
            call(c, "PrimitiveComponent", "SetCollisionEnabled", json!({"NewType": 0}))?;
        }
        Ok(spawned)
    })?;
    let n = spawned.len();
    *PIPES.lock() = spawned;
    Ok(n)
}

fn clear_pipes() -> Result<usize, String> {
    let pipes: Vec<u64> = std::mem::take(&mut *PIPES.lock());
    if pipes.is_empty() {
        return Ok(0);
    }
    game(move || {
        let mut n = 0;
        for p in pipes {
            if call(p, "Actor", "K2_DestroyActor", json!({})).is_ok() {
                n += 1;
            }
        }
        Ok(n)
    })
}

fn point(v: &Value) -> Option<[f64; 3]> {
    let a = v.as_array().filter(|a| a.len() == 3)?;
    Some([a[0].as_f64()?, a[1].as_f64()?, a[2].as_f64()?])
}

/// `route.find`, `route.state`, `route.stop`, `route.clear`.
pub fn register_ops() {
    use crate::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new(
            "route.find",
            "Search a route from the player to a point using only walks the game's navigation completes and jumps or dashes a player-sized body sweeps clear; runs in the background (route.state), then draws it as pipes at head height",
            "{player: selector, to: [x,y,z], from?: [x,y,z], box?: [x0,x1,y0,y1,z0,z1], step?: 300, dash?: cm (0 = none), draw?: true}",
            |args| {
                if RUNNING.swap(true, Ordering::SeqCst) {
                    return Err("a route search is already running; route.stop ends it".into());
                }
                let parsed = (|| -> Result<Search, String> {
                    let selector = args["player"].as_str().ok_or("player must be a selector")?;
                    let player = crate::selector::resolve(selector)? as *const UObject as u64;
                    Ok(Search {
                        player,
                        from: point(&args["from"]),
                        to: point(&args["to"]).ok_or("to must be [x, y, z]")?,
                        bbox: args["box"].as_array().filter(|b| b.len() == 6).and_then(|b| {
                            let v: Vec<f64> = b.iter().filter_map(Value::as_f64).collect();
                            (v.len() == 6).then(|| [v[0], v[1], v[2], v[3], v[4], v[5]])
                        }),
                        step: args["step"].as_f64().unwrap_or(300.0).max(100.0),
                        dash: args["dash"].as_f64().unwrap_or(0.0),
                        draw: args["draw"].as_bool().unwrap_or(true),
                    })
                })();
                let search = match parsed {
                    Ok(s) => s,
                    Err(e) => {
                        RUNNING.store(false, Ordering::SeqCst);
                        return Err(e);
                    }
                };
                CANCEL.store(false, Ordering::SeqCst);
                progress("starting", json!({}));
                std::thread::spawn(move || {
                    let r = std::panic::catch_unwind(|| run(search)).unwrap_or_else(|_| Err("search panicked".into()));
                    RUNNING.store(false, Ordering::SeqCst);
                    let v = match r {
                        Ok(v) => json!({"phase": "done", "running": false, "result": v}),
                        Err(e) => json!({"phase": "failed", "running": false, "error": e}),
                    };
                    crate::log!("route: {}", v);
                    *STATE.lock() = v;
                });
                Ok(json!({"started": true}))
            },
        ),
        OpDef::new("route.state", "Progress or result of the last route search", "{}", |_args| Ok(STATE.lock().clone())),
        OpDef::new("route.stop", "Stop a running route search", "{}", |_args| {
            CANCEL.store(true, Ordering::SeqCst);
            Ok(json!({"stopping": RUNNING.load(Ordering::SeqCst)}))
        }),
        OpDef::new("route.clear", "Remove the route pipes", "{}", |_args| Ok(json!({"removed": clear_pipes()?}))),
    ]);
    modforge::shutdown::SHUTDOWN_REGISTRY
        .record("ueforge/climb", "stop the route search".into(), 80, || {
            CANCEL.store(true, Ordering::SeqCst);
        })
        .keep();
}

#[cfg(test)]
mod tests {
    use super::*;

    const BODY: Body = Body { radius: 35.0, half: 96.0, jump: 480.0, gravity: 980.0, run: 400.0 };

    #[test]
    fn jump_height_limits_arc() {
        // v^2 / 2g = 117.6 cm.
        assert!(arc(&BODY, [0.0; 3], [100.0, 0.0, 110.0], None).is_some());
        assert!(arc(&BODY, [0.0; 3], [100.0, 0.0, 125.0], None).is_none());
    }

    #[test]
    fn jump_distance_limits_arc() {
        // Flat jump: 0.98 s in the air at 400 cm/s.
        assert!(arc(&BODY, [0.0; 3], [380.0, 0.0, 0.0], None).is_some());
        assert!(arc(&BODY, [0.0; 3], [420.0, 0.0, 0.0], None).is_none());
        assert!(arc(&BODY, [0.0; 3], [900.0, 0.0, 0.0], Some(1000.0)).is_some());
    }

    #[test]
    fn arc_ends_on_landing() {
        let pts = arc(&BODY, [0.0; 3], [300.0, 0.0, 50.0], None).unwrap();
        let last = pts.last().unwrap();
        assert!((last[0] - 300.0).abs() < 1e-6 && (last[2] - (50.0 + 98.0)).abs() < 1e-6);
    }
}

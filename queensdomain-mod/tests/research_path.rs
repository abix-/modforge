//! Can the game's own navigation find a walkable path from the player
//! to a point?
//!
//! - `path_to_point`: checks the game-thread queue answers, checks the
//!   call slot by asking the player for its location
//!   (Actor::K2_GetActorLocation), then asks
//!   NavigationSystemV1::FindPathToLocationSynchronously for a path
//!   from there to the point and prints each leg as a compass bearing,
//!   a distance and a height change. The navigation mesh is built for
//!   the enemies, so a path only exists where they can walk.
//!   Read only: it moves nothing.
//!
//! The point is the third beacon's unlit brazier unless PATH_TO="x,y,z".
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_path -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, instances, ping_or_skip};
use serde_json::{Value, json};

/// Beacon_Brazier_00_BP5_12, unlit, measured 2026-11-06 (research_progress).
const BRAZIER: [f64; 3] = [-3097.0, -10877.0, 2773.0];

fn vec3(v: &Value) -> Option<[f64; 3]> {
    Some([v.get("X")?.as_f64()?, v.get("Y")?.as_f64()?, v.get("Z")?.as_f64()?])
}

fn target() -> [f64; 3] {
    std::env::var("PATH_TO")
        .ok()
        .and_then(|s| {
            let p: Vec<f64> = s.split(',').filter_map(|c| c.trim().parse().ok()).collect();
            (p.len() == 3).then(|| [p[0], p[1], p[2]])
        })
        .unwrap_or(BRAZIER)
}

/// World -X is south and +Y is east, so the bearing is atan2(dy, dx).
fn compass(dx: f64, dy: f64) -> &'static str {
    const NAMES: [&str; 8] = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"];
    let deg = (dy.atan2(dx).to_degrees() + 360.0) % 360.0;
    NAMES[((deg + 22.5) / 45.0) as usize % 8]
}

/// Is there navigation data in this world? Lists navigation mesh
/// actors and the navigation system's own references to them, and asks
/// it to project the player's position onto the mesh.
#[test]
fn nav_data() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for class in ["NavigationSystemV1", "NavigationData", "RecastNavMesh", "NavMeshBoundsVolume"] {
        let found = modforge::client::walk_class_chain_instances(&api, class, 16);
        println!("{class}: {} objects", found.len());
        for i in found.iter().take(6) {
            println!("   {} @ {:#x}", i.name, i.addr);
        }
    }
    let sys = api.op(
        "object.get",
        json!({"object": "first_class:NavigationSystemV1", "fields": ["MainNavData", "NavDataSet", "bAutoCreateNavigationData", "bAllowClientSideNavigation", "bInitialBuildingLocked"]}),
    );
    println!("navigation system: ok={} {}", sys.ok, sys.result);
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        return;
    };
    let loc = api.op(
        "object.call",
        json!({"object": format!("addr:0x{player:X}"), "class": "Actor", "function": "K2_GetActorLocation"}),
    );
    let at = loc.result["ReturnValue"].clone();
    let proj = api.op(
        "object.call",
        json!({
            "object": "first_class:NavigationSystemV1",
            "class": "NavigationSystemV1",
            "function": "K2_ProjectPointToNavigation",
            "params": {"WorldContextObject": format!("0x{player:X}"), "Point": at, "QueryExtent": {"X": 500.0, "Y": 500.0, "Z": 500.0}},
        }),
    );
    println!("project player {at} onto the mesh: ok={} {}", proj.ok, proj.result);
}

fn project(api: &modforge::client::Api<Value>, ctx: u64, p: [f64; 3], e: [f64; 3]) -> Option<[f64; 3]> {
    let r = api.op(
        "object.call",
        json!({
            "object": "first_class:NavigationSystemV1",
            "class": "NavigationSystemV1",
            "function": "K2_ProjectPointToNavigation",
            "params": {"WorldContextObject": format!("0x{ctx:X}"), "Point": {"X": p[0], "Y": p[1], "Z": p[2]}, "QueryExtent": {"X": e[0], "Y": e[1], "Z": e[2]}},
        }),
    );
    (r.result["ReturnValue"] == true).then(|| vec3(&r.result["ProjectedLocation"])).flatten()
}

/// Player moves, in game units (cm). Jump height from the earlier dash
/// research; air dash is "FS Air Distance", set to 1000 by tweaks.rs.
const JUMP_UP: f64 = 120.0;
const DASH: f64 = 1000.0;
/// Two mesh samples this close and this level are one walkable patch.
const WALK_STEP: f64 = 320.0;
const WALK_RISE: f64 = 60.0;

/// Can the player get from the walkable ground to the third beacon's
/// brazier? Samples the navigation mesh in a box between where the
/// game's walking path ends and the brazier, groups the samples into
/// patches, and searches patch to patch using walking, jumps (up to
/// JUMP_UP higher), air dashes (gaps up to DASH) and drops. Read only.
/// Walls between two patches are not checked yet.
#[test]
fn climb_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        println!("no live player");
        return;
    };
    // Measured by path_to_point 2026-11-05: the walking path ends here.
    // PATH_FROM overrides it, and CLIMB_BOX="x0,x1,y0,y1,z0,z1" the box.
    let env3 = |k: &str, n: usize| {
        std::env::var(k).ok().map(|s| s.split(',').filter_map(|c| c.trim().parse::<f64>().ok()).collect::<Vec<_>>()).filter(|v| v.len() == n)
    };
    let start: [f64; 3] = env3("PATH_FROM", 3).map(|v| [v[0], v[1], v[2]]).unwrap_or([-6000.0, -8310.0, 553.0]);
    let goal = target();
    let (mut x0, mut x1) = (start[0].min(goal[0]) - 600.0, start[0].max(goal[0]) + 600.0);
    let (mut y0, mut y1) = (start[1].min(goal[1]) - 600.0, start[1].max(goal[1]) + 600.0);
    let (mut z0, mut z1) = (start[2] - 200.0, goal[2] + 200.0);
    if let Some(b) = env3("CLIMB_BOX", 6) {
        (x0, x1, y0, y1, z0, z1) = (b[0], b[1], b[2], b[3], b[4], b[5]);
    }
    let step = 300.0;
    let t = std::time::Instant::now();
    let mut samples: Vec<[f64; 3]> = Vec::new();
    let mut x = x0;
    while x <= x1 {
        let mut y = y0;
        while y <= y1 {
            let mut z = z0;
            while z <= z1 {
                if let Some(p) = project(&api, player, [x, y, z], [step / 2.0, step / 2.0, 100.0]) {
                    if !samples.iter().any(|q| (q[0] - p[0]).abs() < 50.0 && (q[1] - p[1]).abs() < 50.0 && (q[2] - p[2]).abs() < 50.0) {
                        samples.push(p);
                    }
                }
                z += 200.0;
            }
            y += step;
        }
        x += step;
    }
    println!("{} mesh samples in {:.0} s", samples.len(), t.elapsed().as_secs_f64());

    // Patches: union of samples that are walkably close.
    let n = samples.len();
    let mut patch: Vec<usize> = (0..n).collect();
    fn root(p: &mut Vec<usize>, i: usize) -> usize {
        let mut r = i;
        while p[r] != r {
            r = p[r];
        }
        p[i] = r;
        r
    }
    for i in 0..n {
        for j in i + 1..n {
            let (a, b) = (samples[i], samples[j]);
            if ((a[0] - b[0]).powi(2) + (a[1] - b[1]).powi(2)).sqrt() <= WALK_STEP && (a[2] - b[2]).abs() <= WALK_RISE {
                let (ri, rj) = (root(&mut patch, i), root(&mut patch, j));
                patch[ri] = rj;
            }
        }
    }
    let mut groups: std::collections::BTreeMap<usize, Vec<usize>> = Default::default();
    for i in 0..n {
        let r = root(&mut patch, i);
        groups.entry(r).or_default().push(i);
    }
    let groups: Vec<Vec<usize>> = groups.into_values().collect();
    let nearest = |p: [f64; 3]| {
        (0..groups.len())
            .min_by(|&a, &b| {
                let d = |g: usize| groups[g].iter().map(|&i| {
                    let s = samples[i];
                    (s[0] - p[0]).powi(2) + (s[1] - p[1]).powi(2) + (s[2] - p[2]).powi(2)
                }).fold(f64::MAX, f64::min);
                d(a).total_cmp(&d(b))
            })
    };
    let (Some(from), Some(to)) = (nearest(start), nearest(goal)) else {
        println!("no patches");
        return;
    };
    println!("{} patches; start in patch {from}, brazier in patch {to}", groups.len());

    // Best move between two patches: the closest pair of samples, as a
    // jump, dash or drop when the player can make it.
    let link = |a: usize, b: usize| -> Option<(f64, &'static str, [f64; 3], [f64; 3])> {
        let mut best: Option<(f64, &'static str, [f64; 3], [f64; 3])> = None;
        for &i in &groups[a] {
            for &j in &groups[b] {
                let (p, q) = (samples[i], samples[j]);
                let flat = ((p[0] - q[0]).powi(2) + (p[1] - q[1]).powi(2)).sqrt();
                let rise = q[2] - p[2];
                let kind = if rise > JUMP_UP {
                    continue;
                } else if flat <= WALK_STEP && rise > WALK_RISE {
                    "jump"
                } else if flat <= WALK_STEP {
                    "drop"
                } else if flat <= DASH {
                    if rise > 0.0 { "jump and dash" } else { "dash" }
                } else {
                    continue;
                };
                if best.is_none_or(|b| flat < b.0) {
                    best = Some((flat, kind, p, q));
                }
            }
        }
        best
    };
    // Breadth first over patches: fewest moves.
    let mut prev: Vec<Option<(usize, &'static str, [f64; 3], [f64; 3])>> = vec![None; groups.len()];
    let mut seen = vec![false; groups.len()];
    let mut queue = std::collections::VecDeque::from([from]);
    seen[from] = true;
    while let Some(a) = queue.pop_front() {
        if a == to {
            break;
        }
        for b in 0..groups.len() {
            if seen[b] {
                continue;
            }
            if let Some((_, kind, p, q)) = link(a, b) {
                seen[b] = true;
                prev[b] = Some((a, kind, p, q));
                queue.push_back(b);
            }
        }
    }
    let top = |g: usize| groups[g].iter().map(|&i| samples[i][2]).fold(f64::MIN, f64::max);
    if !seen[to] {
        let reach: Vec<usize> = (0..groups.len()).filter(|&g| seen[g]).collect();
        let high = reach.iter().map(|&g| top(g)).fold(f64::MIN, f64::max);
        println!("no route: {} patches reachable, highest at z {high:.0}, brazier patch at z {:.0}", reach.len(), top(to));
        for (g, s) in groups.iter().enumerate() {
            let c = samples[s[0]];
            println!("   patch {g:>3}: {:>3} samples, top z {:.0}, e.g. ({:.0}, {:.0}, {:.0}){}", s.len(), top(g), c[0], c[1], c[2], if seen[g] { " reachable" } else { "" });
        }
        return;
    }
    let mut steps = Vec::new();
    let mut g = to;
    while let Some((a, kind, p, q)) = prev[g] {
        steps.push((kind, p, q));
        g = a;
    }
    steps.reverse();
    println!("route in {} moves:", steps.len());
    for (k, (kind, p, q)) in steps.iter().enumerate() {
        let (dx, dy) = (q[0] - p[0], q[1] - p[1]);
        println!(
            "  {:>2}. walk to ({:.0}, {:.0}, {:.0}), then {kind} {} {:.1} m, height {:+.1} m, to ({:.0}, {:.0}, {:.0})",
            k + 1, p[0], p[1], p[2], compass(dx, dy), (dx * dx + dy * dy).sqrt() / 100.0, (q[2] - p[2]) / 100.0, q[0], q[1], q[2]
        );
    }
}

/// The climb route found by climb_route 2026-11-06: each takeoff or
/// turn point and what to do there.
const ROUTE: [([f64; 3], &str); 10] = [
    ([-8311.0, -11411.0, 10.0], "1. dash N 3 m"),
    ([-7201.0, -11618.0, 150.0], "2. jump NW up 0.7 m"),
    ([-6266.0, -12760.0, 613.0], "3. jump W up 0.6 m"),
    ([-6099.0, -13113.0, 721.0], "4. jump NE up 0.9 m"),
    ([-5638.0, -13122.0, 854.0], "5. air dash NE 8.2 m"),
    ([-5289.0, -12384.0, 847.0], "6. walk N along the level stretch"),
    ([-3900.0, -12450.0, 863.0], "7. turn S up the ramp"),
    ([-5060.0, -11580.0, 1623.0], "8. turn N up the second ramp"),
    ([-3720.0, -11570.0, 2363.0], "9. walk NE 8 m to the ledge"),
    ([-3180.0, -10850.0, 2403.0], "ledge under the brazier"),
];

/// Where is the player against ROUTE: the nearest step, and the
/// direction and distance to it and to the next one. Read only.
#[test]
fn where_on_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        println!("no live player");
        return;
    };
    let loc = api.op(
        "object.call",
        json!({"object": format!("addr:0x{player:X}"), "class": "Actor", "function": "K2_GetActorLocation"}),
    );
    let Some(p) = vec3(&loc.result["ReturnValue"]) else {
        println!("player location call failed: {}", loc.result);
        return;
    };
    // Feet are about 0.9 m under the capsule centre (nav projection, 2026-11-05).
    let feet = p[2] - 92.0;
    println!("player at ({:.0}, {:.0}, {:.0}), feet z {feet:.0}", p[0], p[1], p[2]);
    // Where the camera faces, so directions read as "ahead" or "left".
    let rot = api.op(
        "object.call",
        json!({"object": format!("addr:0x{player:X}"), "class": "Pawn", "function": "GetControlRotation"}),
    );
    let yaw = rot.result["ReturnValue"]["Yaw"].as_f64();
    let to = |q: [f64; 3]| {
        let (dx, dy) = (q[0] - p[0], q[1] - p[1]);
        let turn = yaw.map(|y| {
            let rel = ((dy.atan2(dx).to_degrees() - y) % 360.0 + 540.0) % 360.0 - 180.0;
            match rel {
                r if r.abs() <= 20.0 => "straight ahead".to_string(),
                r if r.abs() >= 160.0 => "behind you".to_string(),
                r if r > 0.0 => format!("{r:.0} deg right"),
                r => format!("{:.0} deg left", -r),
            }
        });
        format!(
            "{} {:.1} m, height {:+.1} m{}",
            compass(dx, dy),
            (dx * dx + dy * dy).sqrt() / 100.0,
            (q[2] - feet) / 100.0,
            turn.map(|t| format!(", {t}")).unwrap_or_default()
        )
    };
    for (q, what) in ROUTE {
        println!("   {what:<36} {}", to(q));
    }
}

/// Where mark_route keeps the lights it spawned, for clear_route_marks.
fn marks_file() -> std::path::PathBuf {
    std::env::temp_dir().join("queensdomain_route_marks.txt")
}

/// Light colour for a ROUTE step: yellow jump, blue dash, red the
/// ledge, green a walking turn.
fn mark_colour(what: &str) -> [f64; 3] {
    if what.contains("dash") {
        [0.1, 0.4, 1.0]
    } else if what.contains("jump") {
        [1.0, 0.85, 0.0]
    } else if what.contains("ledge") {
        [1.0, 0.0, 0.0]
    } else {
        [0.0, 1.0, 0.2]
    }
}

/// Draw ROUTE in the world: a coloured point light 1 m above each step,
/// spawned the way Blueprints do (GameplayStatics
/// BeginDeferredActorSpawnFromClass then FinishSpawningActor). Runtime
/// actors, not saved; clear_route_marks destroys them. A write, so
/// ignored by default.
#[test]
#[ignore]
fn mark_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        println!("no live player");
        return;
    };
    let call = |object: &str, class: &str, function: &str, params: Value| {
        api.op("object.call", json!({"object": object, "class": class, "function": function, "params": params}))
    };
    let mut spawned = Vec::new();
    for (q, what) in ROUTE {
        let transform = json!({
            "Rotation": {"X": 0.0, "Y": 0.0, "Z": 0.0, "W": 1.0},
            "Translation": {"X": q[0], "Y": q[1], "Z": q[2] + 100.0},
            "Scale3D": {"X": 1.0, "Y": 1.0, "Z": 1.0},
        });
        // Static functions ignore the object they run on, and this game's
        // GameplayStatics default object is not found, so use the player.
        let statics = format!("addr:0x{player:X}");
        let begin = call(&statics, "GameplayStatics", "BeginDeferredActorSpawnFromClass", json!({
            "WorldContextObject": format!("0x{player:X}"),
            "ActorClass": "class:PointLight",
            "SpawnTransform": transform,
            "CollisionHandlingOverride": 1,
        }));
        let Some(actor) = begin.result["ReturnValue"]["addr"].as_str().map(str::to_owned) else {
            println!("{what}: spawn failed: {} {:?}", begin.result, begin.error);
            continue;
        };
        let done = call(&statics, "GameplayStatics", "FinishSpawningActor", json!({"Actor": actor, "SpawnTransform": transform}));
        spawned.push(actor.clone());
        let comp = api.op("object.get", json!({"object": format!("addr:{actor}"), "fields": ["LightComponent"]}));
        let Some(c) = comp.result["LightComponent"]["addr"].as_str().map(|a| format!("addr:{a}")) else {
            println!("{what}: no light component: {}", comp.result);
            continue;
        };
        let [r, g, b] = mark_colour(what);
        let steps = [
            call(&c, "SceneComponent", "SetMobility", json!({"NewMobility": 2})),
            call(&c, "LightComponent", "SetIntensity", json!({"NewIntensity": 200000.0})),
            call(&c, "LightComponent", "SetLightColor", json!({"NewLightColor": {"R": r, "G": g, "B": b, "A": 1.0}, "bSRGB": true})),
            call(&c, "LocalLightComponent", "SetAttenuationRadius", json!({"NewRadius": 800.0})),
        ];
        let failed: Vec<String> = steps.iter().filter(|s| !s.ok).map(|s| format!("{:?}", s.error)).collect();
        println!("{what}: light {actor} finished={} {}", done.ok, if failed.is_empty() { "set".to_string() } else { failed.join("; ") });
    }
    // Lights alone can wash out in daylight: add a 15 m pillar of the
    // engine's basic cylinder at each step. Loading it by path needs a
    // default object this game does not expose, so use the loaded one.
    let Some(cylinder) = instances(&api, "StaticMesh", 20000).into_iter().find(|(_, n)| n == "Cylinder").map(|(a, _)| format!("0x{a:X}")) else {
        println!("no loaded Cylinder mesh; lights only");
        let _ = std::fs::write(marks_file(), spawned.join("\n"));
        return;
    };
    for (q, what) in ROUTE {
        let transform = json!({
            "Rotation": {"X": 0.0, "Y": 0.0, "Z": 0.0, "W": 1.0},
            "Translation": {"X": q[0], "Y": q[1], "Z": q[2] + 750.0},
            "Scale3D": {"X": 0.3, "Y": 0.3, "Z": 15.0},
        });
        let statics = format!("addr:0x{player:X}");
        let begin = call(&statics, "GameplayStatics", "BeginDeferredActorSpawnFromClass", json!({
            "WorldContextObject": format!("0x{player:X}"),
            "ActorClass": "class:StaticMeshActor",
            "SpawnTransform": transform,
            "CollisionHandlingOverride": 1,
        }));
        let Some(actor) = begin.result["ReturnValue"]["addr"].as_str().map(str::to_owned) else {
            println!("{what}: pillar spawn failed: {:?}", begin.error);
            continue;
        };
        call(&statics, "GameplayStatics", "FinishSpawningActor", json!({"Actor": actor, "SpawnTransform": transform}));
        spawned.push(actor.clone());
        let comp = api.op("object.get", json!({"object": format!("addr:{actor}"), "fields": ["StaticMeshComponent"]}));
        let Some(c) = comp.result["StaticMeshComponent"]["addr"].as_str().map(|a| format!("addr:{a}")) else {
            println!("{what}: no mesh component: {}", comp.result);
            continue;
        };
        let steps = [
            call(&c, "SceneComponent", "SetMobility", json!({"NewMobility": 2})),
            call(&c, "StaticMeshComponent", "SetStaticMesh", json!({"NewMesh": cylinder})),
            call(&c, "PrimitiveComponent", "SetCollisionEnabled", json!({"NewType": 0})),
        ];
        let failed: Vec<String> = steps.iter().filter(|s| !s.ok || s.result["ReturnValue"] == false).map(|s| format!("{:?} {}", s.error, s.result)).collect();
        println!("{what}: pillar {actor} {}", if failed.is_empty() { "set".to_string() } else { failed.join("; ") });
    }
    let _ = std::fs::write(marks_file(), spawned.join("\n"));
    println!("{} marks; clear with clear_route_marks", spawned.len());
}

/// The lights mark_route spawned, as the game holds them now: where each
/// is, how far from the player, and its light settings. Read only.
#[test]
fn route_marks_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        return;
    };
    let loc = |obj: &str| {
        let r = api.op("object.call", json!({"object": obj, "class": "Actor", "function": "K2_GetActorLocation"}));
        vec3(&r.result["ReturnValue"])
    };
    let Some(p) = loc(&format!("addr:0x{player:X}")) else { return };
    println!("player at ({:.0}, {:.0}, {:.0})", p[0], p[1], p[2]);
    let list = std::fs::read_to_string(marks_file()).unwrap_or_default();
    for (i, actor) in list.lines().filter(|l| !l.is_empty()).enumerate() {
        let a = format!("addr:{actor}");
        let Some(q) = loc(&a) else {
            println!("{i}: {actor} gone");
            continue;
        };
        let d = ((q[0] - p[0]).powi(2) + (q[1] - p[1]).powi(2)).sqrt() / 100.0;
        let comp = api.op("object.get", json!({"object": a, "fields": ["LightComponent", "bHidden"]}));
        let c = comp.result["LightComponent"]["addr"].as_str().unwrap_or("0").to_string();
        let s = api.op("object.get", json!({"object": format!("addr:{c}"), "fields": ["Intensity", "LightColor", "Mobility", "bVisible", "bHiddenInGame", "AttenuationRadius", "IntensityUnits", "bAffectsWorld", "CastShadows"]}));
        println!("{i}: at ({:.0}, {:.0}, {:.0}), {d:.1} m away, actor hidden {}; light {}", q[0], q[1], q[2], comp.result["bHidden"], s.result);
    }
}

/// The first pillar mark_route spawned: its mesh, visibility, scale and
/// world bounds, to tell whether the game draws it. Read only.
#[test]
fn pillar_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = std::fs::read_to_string(marks_file()).unwrap_or_default();
    // MARK_INDEX picks another mark: 0-9 lights, 10-19 pillars, then rods.
    let index = std::env::var("MARK_INDEX").ok().and_then(|v| v.parse().ok()).unwrap_or(10);
    let Some(actor) = list.lines().filter(|l| !l.is_empty()).nth(index) else {
        println!("no pillar recorded");
        return;
    };
    let a = format!("addr:{actor}");
    let comp = api.op("object.get", json!({"object": a, "fields": ["StaticMeshComponent", "bHidden", "RootComponent"]}));
    println!("actor: {}", comp.result);
    let Some(c) = comp.result["StaticMeshComponent"]["addr"].as_str().map(|s| format!("addr:{s}")) else { return };
    let s = api.op("object.get", json!({"object": c, "fields": ["StaticMesh", "bVisible", "bHiddenInGame", "Mobility", "RelativeLocation", "RelativeScale3D", "OverrideMaterials", "bRenderInMainPass", "CachedMaxDrawDistance", "LDMaxDrawDistance"]}));
    println!("mesh component: {} {:?}", s.result, s.error);
    let b = api.op("object.call", json!({"object": a, "class": "Actor", "function": "GetActorBounds", "params": {"bOnlyCollidingComponents": false}}));
    println!("bounds: {} {:?}", b.result, b.error);
    let r = api.op("object.call", json!({"object": c, "class": "PrimitiveComponent", "function": "WasRecentlyRendered", "params": {"Tolerance": 0.5}}));
    println!("recently rendered: {} {:?}", r.result, r.error);
}

/// The whole route as points and how to get to the next one. Walking
/// legs are filled in from the game's own path search when drawn.
const LINE: [([f64; 3], &str); 12] = [
    ([-8311.0, -11411.0, 10.0], "dash"),
    ([-8000.0, -11500.0, 3.0], "walk"),
    ([-7201.0, -11618.0, 150.0], "jump"),
    ([-7100.0, -11800.0, 220.0], "walk"),
    ([-6266.0, -12760.0, 613.0], "jump"),
    ([-6200.0, -13000.0, 675.0], "walk"),
    ([-6099.0, -13113.0, 721.0], "jump"),
    ([-5910.0, -13010.0, 813.0], "walk"),
    ([-5638.0, -13122.0, 854.0], "dash"),
    ([-5289.0, -12384.0, 847.0], "walk"),
    ([-3180.0, -10850.0, 2403.0], "end"),
    ([-3097.0, -10877.0, 2773.0], "end"),
];

/// The route as one polyline on the floor, from the player's feet (0.9 m
/// under the actor, see where_on_route) through LINE; walking legs come
/// from the game's path search.
fn route_line(api: &modforge::client::Api<Value>, player: u64) -> Vec<[f64; 3]> {
    let ctx = format!("0x{player:X}");
    let me = format!("addr:{ctx}");
    let call = |object: &str, class: &str, function: &str, params: Value| {
        api.op("object.call", json!({"object": object, "class": class, "function": function, "params": params}))
    };
    let xyz = |p: [f64; 3]| json!({"X": p[0], "Y": p[1], "Z": p[2]});
    let loc = call(&me, "Actor", "K2_GetActorLocation", json!({}));
    let mut legs: Vec<([f64; 3], &str)> = Vec::new();
    if let Some(p) = vec3(&loc.result["ReturnValue"]) {
        legs.push(([p[0], p[1], p[2] - 92.0], "walk"));
    }
    legs.extend(LINE);
    let mut line: Vec<[f64; 3]> = vec![legs[0].0];
    for w in legs.windows(2) {
        let (a, kind) = w[0];
        let b = w[1].0;
        if kind == "walk" {
            let r = call(&me, "NavigationSystemV1", "FindPathToLocationSynchronously", json!({"WorldContextObject": ctx, "PathStart": xyz(a), "PathEnd": xyz(b)}));
            let pts = r.result["ReturnValue"]["addr"].as_str().and_then(|path| {
                let addr = u64::from_str_radix(path.trim_start_matches("0x"), 16).ok()?;
                let (_, off, _) = common::fields(api, "NavigationPath").into_iter().find(|f| f.0 == "PathPoints")?;
                let (data, num, _) = modforge::client::read_tarray(api, addr, off);
                let bytes = modforge::client::read_bytes(api, data, 0, num.clamp(0, 1000) as u64 * 12);
                Some(bytes.chunks_exact(12).map(|c| [0, 4, 8].map(|k| modforge::client::from_le_f32(c, k) as f64)).collect::<Vec<_>>())
            });
            match pts {
                Some(p) if p.len() >= 2 => line.extend(p.into_iter().skip(1)),
                _ => line.push(b),
            }
        } else {
            line.push(b);
        }
    }
    line
}

/// Draw the whole route over the game picture, seen through hills: one
/// cyan line at head height (1.7 m) from the player to the brazier, by
/// the HUD overlay. ROUTE_CLEAR=1 removes it. A write, so ignored.
#[test]
#[ignore]
fn overlay_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    if std::env::var("ROUTE_CLEAR").is_ok_and(|v| v == "1") {
        let r = api.op("overlay.clear", json!({}));
        println!("clear: {} {:?}", r.result, r.error);
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        return;
    };
    let line: Vec<Value> = route_line(&api, player).into_iter().map(|p| json!([p[0], p[1], p[2] + 170.0])).collect();
    println!("{} line points", line.len());
    let r = api.op("overlay.lines", json!({"lines": [{"points": line, "color": [0.0, 1.0, 1.0, 1.0], "thickness": 4.0}]}));
    println!("overlay: {} {:?}", r.result, r.error);
}

/// Draw the route as a line of rods 0.5 m above the ground: the game's
/// path for walking legs, straight rods for jumps and dashes, a glowing
/// material when one is loaded. Rods are added to the marks file, so
/// clear_route_marks removes them. A write, so ignored by default.
#[test]
#[ignore]
fn draw_route() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        return;
    };
    let call = |object: &str, class: &str, function: &str, params: Value| {
        api.op("object.call", json!({"object": object, "class": class, "function": function, "params": params}))
    };
    let ctx = format!("0x{player:X}");
    let me = format!("addr:{ctx}");
    let line = route_line(&api, player);
    println!("{} line points", line.len());

    let cylinder = instances(&api, "StaticMesh", 20000).into_iter().find(|(_, n)| n == "Cylinder").map(|(a, _)| format!("0x{a:X}"));
    let Some(cylinder) = cylinder else {
        println!("no loaded Cylinder mesh");
        return;
    };
    // Two smaller walks: one over every MaterialInterface overflows the
    // control plane's 10 MB reply. ROUTE_GLOW=1 only: EmissiveMeshMaterial
    // was not seen in game, the cylinder's own grey was.
    let want_glow = std::env::var("ROUTE_GLOW").is_ok_and(|v| v == "1");
    let glow = ["Material", "MaterialInstanceConstant"].into_iter().filter(|_| want_glow).find_map(|class| {
        instances(&api, class, 8000).into_iter().find(|(_, n)| {
            let l = n.to_ascii_lowercase();
            l.contains("glow") || l.contains("emiss")
        })
    });
    println!("material: {glow:?}");

    let mut spawned = Vec::new();
    for w in line.windows(2) {
        // Head height: the points are on the floor, a head is about 1.7 m up.
        let up = 170.0;
        let (a, b) = ([w[0][0], w[0][1], w[0][2] + up], [w[1][0], w[1][1], w[1][2] + up]);
        let d = [b[0] - a[0], b[1] - a[1], b[2] - a[2]];
        let len = (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]).sqrt();
        if len < 10.0 {
            continue;
        }
        let u = [d[0] / len, d[1] / len, d[2] / len];
        // Turn the cylinder's +Z onto the segment: axis Z x u, angle acos(u.z).
        let (ax, ay) = (-u[1], u[0]);
        let n = (ax * ax + ay * ay).sqrt();
        let half = u[2].clamp(-1.0, 1.0).acos() / 2.0;
        let (qx, qy) = if n < 1e-6 { (0.0, 0.0) } else { (ax / n * half.sin(), ay / n * half.sin()) };
        let transform = json!({
            "Rotation": {"X": qx, "Y": qy, "Z": 0.0, "W": half.cos()},
            "Translation": {"X": (a[0] + b[0]) / 2.0, "Y": (a[1] + b[1]) / 2.0, "Z": (a[2] + b[2]) / 2.0},
            // 20 cm rods were not seen on 2026-11-06; the 2 m grey pillar was.
            "Scale3D": {"X": 0.8, "Y": 0.8, "Z": len / 100.0},
        });
        let begin = call(&me, "GameplayStatics", "BeginDeferredActorSpawnFromClass", json!({"WorldContextObject": ctx, "ActorClass": "class:StaticMeshActor", "SpawnTransform": transform, "CollisionHandlingOverride": 1}));
        let Some(actor) = begin.result["ReturnValue"]["addr"].as_str().map(str::to_owned) else {
            println!("rod spawn failed: {:?}", begin.error);
            continue;
        };
        call(&me, "GameplayStatics", "FinishSpawningActor", json!({"Actor": actor, "SpawnTransform": transform}));
        spawned.push(actor.clone());
        let comp = api.op("object.get", json!({"object": format!("addr:{actor}"), "fields": ["StaticMeshComponent"]}));
        let Some(c) = comp.result["StaticMeshComponent"]["addr"].as_str().map(|s| format!("addr:{s}")) else { continue };
        call(&c, "SceneComponent", "SetMobility", json!({"NewMobility": 2}));
        call(&c, "StaticMeshComponent", "SetStaticMesh", json!({"NewMesh": cylinder}));
        call(&c, "PrimitiveComponent", "SetCollisionEnabled", json!({"NewType": 0}));
        if let Some((m, _)) = &glow {
            call(&c, "PrimitiveComponent", "SetMaterial", json!({"ElementIndex": 0, "Material": format!("0x{m:X}")}));
        }
    }
    let mut all = std::fs::read_to_string(marks_file()).unwrap_or_default();
    for s in &spawned {
        all.push('\n');
        all.push_str(s);
    }
    let _ = std::fs::write(marks_file(), all);
    println!("{} rods drawn; clear with clear_route_marks", spawned.len());
}

/// Make the recorded pillars bigger: PILLAR_SCALE="x,y,z" (default
/// 2,2,30: 2 m wide, 30 m tall). A write, so ignored by default.
#[test]
#[ignore]
fn grow_pillars() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let s: Vec<f64> = std::env::var("PILLAR_SCALE").ok().map(|v| v.split(',').filter_map(|c| c.trim().parse().ok()).collect()).filter(|v: &Vec<f64>| v.len() == 3).unwrap_or(vec![2.0, 2.0, 30.0]);
    let list = std::fs::read_to_string(marks_file()).unwrap_or_default();
    for actor in list.lines().skip(10).filter(|l| !l.is_empty()) {
        let r = api.op("object.call", json!({"object": format!("addr:{actor}"), "class": "Actor", "function": "SetActorScale3D", "params": {"NewScale3D": {"X": s[0], "Y": s[1], "Z": s[2]}}}));
        println!("{actor}: ok={} {:?}", r.ok, r.error);
    }
}

/// Every rod draw_route made: centre, distance from the player, and
/// whether the game drew it in the last half second. Read only.
#[test]
fn rods_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        return;
    };
    let r = api.op("object.call", json!({"object": format!("addr:0x{player:X}"), "class": "Actor", "function": "K2_GetActorLocation"}));
    let Some(p) = vec3(&r.result["ReturnValue"]) else { return };
    println!("player at ({:.0}, {:.0}, {:.0})", p[0], p[1], p[2]);
    let list = std::fs::read_to_string(marks_file()).unwrap_or_default();
    for (i, actor) in list.lines().filter(|l| !l.is_empty()).enumerate().skip(20) {
        let a = format!("addr:{actor}");
        let b = api.op("object.call", json!({"object": a, "class": "Actor", "function": "GetActorBounds", "params": {"bOnlyCollidingComponents": false}}));
        let Some(o) = vec3(&b.result["Origin"]) else {
            println!("{i}: gone {:?}", b.error);
            continue;
        };
        let comp = api.op("object.get", json!({"object": a, "fields": ["StaticMeshComponent"]}));
        let c = comp.result["StaticMeshComponent"]["addr"].as_str().unwrap_or("0").to_string();
        let seen = api.op("object.call", json!({"object": format!("addr:{c}"), "class": "PrimitiveComponent", "function": "WasRecentlyRendered", "params": {"Tolerance": 0.5}}));
        let d = ((o[0] - p[0]).powi(2) + (o[1] - p[1]).powi(2)).sqrt() / 100.0;
        println!("{i}: centre ({:.0}, {:.0}, {:.0}), {d:.1} m away, height {:+.1} m, drawn {}", o[0], o[1], o[2], (o[2] - p[2]) / 100.0, seen.result["ReturnValue"]);
    }
}

/// Loaded static meshes whose names suggest a simple shape, for markers.
#[test]
fn marker_meshes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let all = instances(&api, "StaticMesh", 20000);
    println!("{} static meshes loaded", all.len());
    for (a, n) in all.iter().filter(|(_, n)| {
        let l = n.to_ascii_lowercase();
        ["cylinder", "cube", "sphere", "pillar", "column", "beam", "pole"].iter().any(|w| l.contains(w))
    }).take(40) {
        println!("   {n} @ {a:#x}");
    }
}

/// Destroy the lights mark_route spawned. Ignored by default.
#[test]
#[ignore]
fn clear_route_marks() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let list = std::fs::read_to_string(marks_file()).unwrap_or_default();
    for actor in list.lines().filter(|l| !l.is_empty()) {
        let r = api.op("object.call", json!({"object": format!("addr:{actor}"), "class": "Actor", "function": "K2_DestroyActor"}));
        println!("{actor}: destroyed ok={} {:?}", r.ok, r.error);
    }
    let _ = std::fs::remove_file(marks_file());
}

#[test]
fn path_to_point() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let ping = api.op("pe_ping", json!({}));
    println!("game thread: ok={} {}", ping.ok, ping.result);
    if !ping.ok {
        println!("pe_stats: {}", api.op("pe_stats", json!({})).result);
        return;
    }

    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 4).into_iter().next() else {
        println!("no live player");
        return;
    };
    let loc = api.op(
        "object.call",
        json!({"object": format!("addr:0x{player:X}"), "class": "Actor", "function": "K2_GetActorLocation"}),
    );
    let Some(mut start) = vec3(&loc.result["ReturnValue"]) else {
        println!("player location call failed: {}", loc.result);
        return;
    };
    // PATH_FROM="x,y,z" starts somewhere other than the player.
    if let Some(p) = std::env::var("PATH_FROM").ok().and_then(|s| {
        let p: Vec<f64> = s.split(',').filter_map(|c| c.trim().parse().ok()).collect();
        (p.len() == 3).then(|| [p[0], p[1], p[2]])
    }) {
        start = p;
    }
    let mut end = target();
    // The mesh is where enemies walk, so a high point is usually off it:
    // ask for the nearest mesh point within growing boxes and path there.
    for extent in [200.0, 1000.0, 3000.0, 6000.0] {
        let proj = api.op(
            "object.call",
            json!({
                "object": "first_class:NavigationSystemV1",
                "class": "NavigationSystemV1",
                "function": "K2_ProjectPointToNavigation",
                "params": {"WorldContextObject": format!("0x{player:X}"), "Point": {"X": end[0], "Y": end[1], "Z": end[2]}, "QueryExtent": {"X": extent, "Y": extent, "Z": extent}},
            }),
        );
        if proj.result["ReturnValue"] == true {
            if let Some(p) = vec3(&proj.result["ProjectedLocation"]) {
                let flat = ((p[0] - end[0]).powi(2) + (p[1] - end[1]).powi(2)).sqrt() / 100.0;
                println!(
                    "nearest mesh point within {} m: ({:.0}, {:.0}, {:.0}), {flat:.1} m across and {:+.1} m from the point",
                    extent / 100.0, p[0], p[1], p[2], (p[2] - end[2]) / 100.0
                );
                end = p;
            }
            break;
        }
        println!("no mesh within {} m of the point", extent / 100.0);
    }
    println!("player at ({:.0}, {:.0}, {:.0}), point ({:.0}, {:.0}, {:.0})", start[0], start[1], start[2], end[0], end[1], end[2]);

    let xyz = |p: [f64; 3]| json!({"X": p[0], "Y": p[1], "Z": p[2]});
    let r = api.op(
        "object.call",
        json!({
            "object": "first_class:NavigationSystemV1",
            "class": "NavigationSystemV1",
            "function": "FindPathToLocationSynchronously",
            "params": {
                "WorldContextObject": format!("0x{player:X}"),
                "PathStart": xyz(start),
                "PathEnd": xyz(end),
            },
        }),
    );
    let Some(path) = r.result["ReturnValue"]["addr"].as_str().map(str::to_owned) else {
        println!("no path object: ok={} {}", r.ok, r.result);
        return;
    };
    let info = api.op(
        "array.get",
        json!({"object": format!("addr:{path}"), "field": "PathPoints"}),
    );
    let mut points: Vec<[f64; 3]> = info.result["elements"]
        .as_array()
        .into_iter()
        .flatten()
        .filter_map(vec3)
        .collect();
    if points.is_empty() {
        // Builds before the array reader learned UE 4.27's element
        // record: read TArray<FVector> by the field's reflected offset,
        // FVector being three f32 on this engine.
        let addr = u64::from_str_radix(path.trim_start_matches("0x"), 16).unwrap_or(0);
        if let Some((_, off, _)) = common::fields(&api, "NavigationPath").into_iter().find(|f| f.0 == "PathPoints") {
            let (data, num, _) = modforge::client::read_tarray(&api, addr, off);
            let b = modforge::client::read_bytes(&api, data, 0, num.clamp(0, 1000) as u64 * 12);
            points = b
                .chunks_exact(12)
                .map(|c| [0, 4, 8].map(|k| modforge::client::from_le_f32(c, k) as f64))
                .collect();
        }
    }
    let partial = api.op(
        "object.call",
        json!({"object": format!("addr:{path}"), "class": "NavigationPath", "function": "IsPartial"}),
    );
    println!("{} points, partial={}", points.len(), partial.result["ReturnValue"]);
    if points.is_empty() {
        println!("path call: {}", r.result);
        println!("path points: ok={} {} {:?}", info.ok, info.result, info.error);
    }
    let mut total = 0.0;
    for (i, w) in points.windows(2).enumerate() {
        let (dx, dy, dz) = (w[1][0] - w[0][0], w[1][1] - w[0][1], w[1][2] - w[0][2]);
        let flat = (dx * dx + dy * dy).sqrt() / 100.0;
        total += flat;
        println!(
            "  leg {:>2}: {:<2} {:>6.1} m, height {:+6.1} m, to ({:.0}, {:.0}, {:.0})",
            i + 1, compass(dx, dy), flat, dz / 100.0, w[1][0], w[1][1], w[1][2]
        );
    }
    if let Some(last) = points.last() {
        let gap = ((last[0] - end[0]).powi(2) + (last[1] - end[1]).powi(2)).sqrt() / 100.0;
        println!("{total:.1} m walked; path ends {gap:.1} m short, {:+.1} m below the point", (end[2] - last[2]) / 100.0);
    }
}

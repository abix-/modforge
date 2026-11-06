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

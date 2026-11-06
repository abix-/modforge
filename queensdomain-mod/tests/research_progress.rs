//! Where should the player go next?
//!
//! The operator has the shrine key, killed a skeleton, got a new
//! sword, opened a well and fell down it, and dies on hitting the
//! water at the bottom. This test lists what the game itself knows
//! about progress and about the well:
//! - loaded Blueprint classes whose names mention quest, objective,
//!   story, progress, waypoint, hint, well, water, drown or death,
//!   with their parents,
//! - the player character's fields and functions about the same.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_progress -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, dump, fields, instances, ping_or_skip};
use serde_json::json;

const WORDS: &[&str] = &[
    "quest", "objective", "story", "progress", "waypoint", "hint", "goal", "journal", "well",
    "water", "drown", "death", "kill", "swim", "fall",
];

fn hit(name: &str, words: &[&str]) -> bool {
    let l = name.to_ascii_lowercase();
    words.iter().any(|w| l.contains(w))
}

fn functions(api: &modforge::client::Api<serde_json::Value>, class: &str) -> Vec<String> {
    let r = api.op("discover_class_detail", json!({"name": class}));
    r.result
        .get("functions")
        .and_then(|v| v.as_array())
        .into_iter()
        .flatten()
        .filter_map(|f| f.get("name").and_then(|v| v.as_str()).map(str::to_string))
        .collect()
}

fn field_off(api: &modforge::client::Api<serde_json::Value>, class: &str, name: &str) -> Option<u64> {
    fields(api, class).into_iter().find(|f| f.0 == name).map(|f| f.1)
}

/// Root component RelativeLocation. Only a world position when the
/// root is attached to nothing, which holds for placed level actors.
fn position(api: &modforge::client::Api<serde_json::Value>, actor: u64, root: u64, loc: u64) -> Option<[f32; 3]> {
    let b = modforge::client::read_bytes(api, actor, root, 8);
    if b.len() < 8 {
        return None;
    }
    let comp = modforge::client::from_le_u64(&b, 0);
    if comp == 0 {
        return None;
    }
    let v = modforge::client::read_bytes(api, comp, loc, 12);
    if v.len() < 12 {
        return None;
    }
    let f = |i: usize| f32::from_le_bytes(v[i..i + 4].try_into().unwrap());
    Some([f(0), f(4), f(8)])
}

/// Quest state: every ActorQuestStateManager_C and ActorQuestState_C
/// with its fields; the player's death-pit flags; every well cover
/// and kill volume with position and distance from the player; every
/// loaded class naming a shrine, with live objects and distance.
#[test]
fn where_next() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let p = position(&api, player, root, loc).unwrap_or([0.0; 3]);
    println!("player at {p:?}");
    dump(&api, player, "FS_PlayerChar_C", Some(&["death", "water", "checkpoint"]));

    for class in ["ActorQuestStateManager_C", "ActorQuestState_C", "QuestForceUpdateVolume_C"] {
        let live = instances(&api, class, 40);
        println!("== {class}: {} live", live.len());
        for (addr, name) in live.iter().take(12) {
            println!("   {name}");
            dump(&api, *addr, class, None);
        }
    }

    let line = |addr: u64, name: &str| {
        let q = position(&api, addr, root, loc).unwrap_or([0.0; 3]);
        let (dx, dy, dz) = (q[0] - p[0], q[1] - p[1], q[2] - p[2]);
        let flat = (dx * dx + dy * dy).sqrt() / 100.0;
        (flat, format!("   {name} at ({:.0}, {:.0}, {:.0}) {flat:.0} m away, height {:+.0} m", q[0], q[1], q[2], dz / 100.0))
    };
    for class in ["Wellcover_Breakable_C", "KillVolume_C", "KillVolume_Black_C", "KillVolume_Red_C", "KillVolume_MagicFire_C"] {
        let mut rows: Vec<(f32, String)> =
            instances(&api, class, 200).iter().map(|(a, n)| line(*a, n)).collect();
        rows.sort_by(|a, b| a.0.total_cmp(&b.0));
        println!("== {class}: {} live, nearest first", rows.len());
        for r in rows.iter().take(8) {
            println!("{}", r.1);
        }
    }
    if let Some((w, _)) = instances(&api, "Wellcover_Breakable_C", 4).into_iter().next() {
        dump(&api, w, "Wellcover_Breakable_C", None);
    }

    println!("== shrine classes");
    for (_, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if !name.to_ascii_lowercase().contains("shrine") {
            continue;
        }
        let mut rows: Vec<(f32, String)> =
            instances(&api, &name, 20).iter().map(|(a, n)| line(*a, n)).collect();
        rows.sort_by(|a, b| a.0.total_cmp(&b.0));
        println!("-- {name}: {} live", rows.len());
        for r in rows.iter().take(6) {
            println!("{}", r.1);
        }
    }
}

/// Has the sword shrine been done? Dumps the two SwordShrineGate_BP_C
/// gates and the shrine boss spawner through their class chains, and
/// gives each one's direction from where the player's camera faces.
#[test]
fn shrine_state() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let off = |c: &str, n: &str| field_off(&api, c, n);
    let (Some(root), Some(loc), Some(ctrl), Some(rot)) = (
        off("Actor", "RootComponent"),
        off("SceneComponent", "RelativeLocation"),
        off("Pawn", "Controller"),
        off("Controller", "ControlRotation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let p = position(&api, player, root, loc).unwrap_or([0.0; 3]);
    let pc = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, player, ctrl, 8), 0);
    let r = modforge::client::read_bytes(&api, pc, rot, 12);
    let yaw = if r.len() == 12 { f32::from_le_bytes(r[4..8].try_into().unwrap()) } else { 0.0 };
    for class in ["SwordShrineGate_BP_C", "Boner_ShrineBoss_Spawner_C", "Boner_Shrineboss_BP_C", "Wellcover_Breakable_C"] {
        for (addr, name) in instances(&api, class, 4) {
            let q = position(&api, addr, root, loc).unwrap_or([0.0; 3]);
            let (dx, dy) = (q[0] - p[0], q[1] - p[1]);
            let mut rel = dy.atan2(dx).to_degrees() - yaw;
            while rel > 180.0 {
                rel -= 360.0;
            }
            while rel < -180.0 {
                rel += 360.0;
            }
            println!(
                "== {name}: {:.0} m, {rel:+.0} deg from camera (+ right), height {:+.0} m",
                (dx * dx + dy * dy).sqrt() / 100.0,
                (q[2] - p[2]) / 100.0
            );
            let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, addr, 0x10, 8), 0);
            let mut chain = vec![common::object_name(&api, cls)];
            chain.extend(common::super_chain(&api, cls));
            for c in chain.iter().take_while(|c| !matches!(c.as_str(), "Actor" | "SavableActor_C" | "FS_Actor")) {
                dump(&api, addr, c, None);
            }
        }
    }
}

/// The operator hit a statue with the Azure Torch and it lit up. Every
/// live actor within 15 m of the player whose class name suggests a
/// statue, brazier, torch, fire or light, nearest first; then the
/// nearest few dumped through their class chains, with function names.
#[test]
fn lit_statue() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() else {
        println!("no player");
        return;
    };
    let p = position(&api, player, root, loc).unwrap_or([0.0; 3]);
    println!("player at {p:?}");
    let words = ["statue", "brazier", "torch", "fire", "flame", "lit", "light", "candle", "lamp", "totem", "idol", "burn", "ignit", "shrine", "altar"];
    let mut near: Vec<(f32, u64, String, String)> = Vec::new();
    for (_, class) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = class.to_ascii_lowercase();
        if !words.iter().any(|w| l.contains(w)) || l.contains("weapon") || l.contains("projectile") || l.ends_with("_item_c") {
            continue;
        }
        for (a, n) in instances(&api, &class, 200) {
            let Some(q) = position(&api, a, root, loc) else { continue };
            let d = ((q[0] - p[0]).powi(2) + (q[1] - p[1]).powi(2) + (q[2] - p[2]).powi(2)).sqrt() / 100.0;
            if d < 15.0 {
                near.push((d, a, n, class.clone()));
            }
        }
    }
    near.sort_by(|a, b| a.0.total_cmp(&b.0));
    for (d, _, n, c) in &near {
        println!("   {d:5.1} m  {n} ({c})");
    }
    for (d, a, n, c) in near.iter().take(4) {
        println!("== {n} ({c}) {d:.1} m");
        let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, *a, 0x10, 8), 0);
        let mut chain = vec![c.clone()];
        chain.extend(common::super_chain(&api, cls));
        for k in chain.iter().take_while(|k| !matches!(k.as_str(), "Actor" | "SavableActor_C" | "FS_Actor")) {
            dump(&api, *a, k, None);
            println!("   functions: {}", functions(&api, k).join(", "));
        }
    }
}

/// What lighting a Beacon_Brazier_00_BP_C does (lit_statue found one
/// Active 14 m from the player): every live beacon with its Active flag
/// and distance, a scan of each of its functions, and every loaded
/// class whose name mentions a beacon.
#[test]
fn beacon_brazier() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let p = instances(&api, "FS_Full_PlayerChar_C", 2)
        .into_iter()
        .next()
        .and_then(|(a, _)| position(&api, a, root, loc))
        .unwrap_or([0.0; 3]);
    println!("player at ({:.0}, {:.0}, {:.0})", p[0], p[1], p[2]);
    let yaw = (|| {
        let (Some(ctrl), Some(rot)) = (field_off(&api, "Pawn", "Controller"), field_off(&api, "Controller", "ControlRotation")) else {
            return None;
        };
        let (player, _) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next()?;
        let pc = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, player, ctrl, 8), 0);
        let r = modforge::client::read_bytes(&api, pc, rot, 12);
        (r.len() == 12).then(|| f32::from_le_bytes(r[4..8].try_into().unwrap()))
    })()
    .unwrap_or(0.0);
    println!("camera yaw {yaw:.0}");
    let facing = |dx: f32, dy: f32| {
        let mut rel = dy.atan2(dx).to_degrees() - yaw;
        while rel > 180.0 {
            rel -= 360.0;
        }
        while rel < -180.0 {
            rel += 360.0;
        }
        rel
    };
    for class in ["Beacon_Brazier_00_BP_C", "Beacon_Top_Real_BP_C"] {
        let Some(active) = field_off(&api, class, "Active") else { continue };
        println!("-- {class}");
        for (a, n) in instances(&api, class, 100) {
            let q = position(&api, a, root, loc).unwrap_or([0.0; 3]);
            let (dx, dy) = (q[0] - p[0], q[1] - p[1]);
            let d = (dx * dx + dy * dy).sqrt() / 100.0;
            let on = modforge::client::read_bytes(&api, a, active, 1).first().copied().unwrap_or(0);
            println!(
                "   {n}: Active {on}, at ({:.0}, {:.0}, {:.0}), {d:.0} m, {:+.0} deg from camera (+ right), height {:+.0} m",
                q[0], q[1], q[2], facing(dx, dy), (q[2] - p[2]) / 100.0
            );
        }
    }
    if std::env::var("BEACON_SCAN").is_err() {
        return;
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if name.to_ascii_lowercase().contains("beacon") {
            println!("-- class {name}: {} live", instances(&api, &name, 100).len());
            for (f, n) in common::class_functions(&api, addr) {
                common::scan_script(&api, f, &format!("{name}::{n}"));
            }
        }
    }
}

/// How to get up to the third beacon site, whose two braziers stand
/// about 20 m above the ground the player reached (2026-11-06): live
/// actors within 60 m of the site whose class or own name suggests a
/// way up (lift, ladder, stairs, climb, vine, rope, jump pad, updraft,
/// wind, launch, platform, bridge, door, gate, lever, switch), nearest
/// first, with height against the braziers and the compass direction
/// from the site (-X south, +Y east).
#[test]
fn beacon_way_up() {
    const SITE: [f32; 3] = [-3900.0, -10600.0, 2773.0];
    const WORDS: &[&str] = &[
        "lift", "elevator", "ladder", "stair", "step", "climb", "vine", "rope", "ledge", "jump",
        "launch", "bounce", "updraft", "wind", "geyser", "platform", "bridge", "door", "gate",
        "lever", "switch", "button", "ramp", "path", "plank", "grapple", "teleport", "portal",
    ];
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let mut rows: Vec<(f32, String)> = Vec::new();
    let mut look = |class: &str, only_named: bool| {
        for (a, n) in instances(&api, class, 20000) {
            if only_named && !hit(&n, WORDS) {
                continue;
            }
            let Some(q) = position(&api, a, root, loc) else { continue };
            let (dx, dy) = (q[0] - SITE[0], q[1] - SITE[1]);
            let d = (dx * dx + dy * dy).sqrt() / 100.0;
            if d > 60.0 {
                continue;
            }
            let compass = (dy.atan2(dx).to_degrees() + 360.0) % 360.0;
            rows.push((
                d,
                format!(
                    "   {n} ({class}) {d:.0} m from the site, compass {compass:.0}, height {:+.0} m against the braziers",
                    (q[2] - SITE[2]) / 100.0
                ),
            ));
        }
    };
    for (_, class) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if hit(&class, WORDS) {
            look(&class, false);
        }
    }
    for class in ["StaticMeshActor", "InstancedFoliageActor"] {
        look(class, true);
    }
    rows.sort_by(|a, b| a.0.total_cmp(&b.0));
    println!("{} candidates within 60 m of the site", rows.len());
    for r in rows.iter().take(60) {
        println!("{}", r.1);
    }
}

/// What a JumpHelper_C / JumpAcrossHelper_C is (beacon_way_up found
/// three level with the third beacon's braziers): each class's parent
/// chain, one live object's fields, and a scan of every function.
#[test]
fn jump_helper() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if name != "JumpHelper_C" && name != "JumpAcrossHelper_C" {
            continue;
        }
        println!("== {name}: parents {:?}", common::super_chain(&api, addr));
        if let Some((obj, n)) = instances(&api, &name, 2).into_iter().next() {
            println!("-- {n}");
            dump(&api, obj, &name, None);
        }
        for (f, n) in common::class_functions(&api, addr) {
            common::scan_script(&api, f, &format!("{name}::{n}"));
        }
    }
}

/// What told the beacons to light: live actors within 60 m of the
/// player whose class names suggest a gargoyle, switch, activator,
/// trigger, lever or fire receiver, nearest first, the nearest few
/// dumped with their own fields and a scan of their functions.
#[test]
fn beacon_trigger() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let p = instances(&api, "FS_Full_PlayerChar_C", 2)
        .into_iter()
        .next()
        .and_then(|(a, _)| position(&api, a, root, loc))
        .unwrap_or([0.0; 3]);
    let words = ["gargoyle", "switch", "activat", "trigger", "lever", "receiver", "puzzle", "ignit", "flamm", "burnable"];
    let mut near: Vec<(f32, u64, String, String, u64)> = Vec::new();
    for (caddr, class) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = class.to_ascii_lowercase();
        if !words.iter().any(|w| l.contains(w)) || l.contains("weapon") || l.contains("widget") {
            continue;
        }
        for (a, n) in instances(&api, &class, 300) {
            let Some(q) = position(&api, a, root, loc) else { continue };
            let d = ((q[0] - p[0]).powi(2) + (q[1] - p[1]).powi(2) + (q[2] - p[2]).powi(2)).sqrt() / 100.0;
            if d < 60.0 {
                near.push((d, a, n, class.clone(), caddr));
            }
        }
    }
    near.sort_by(|a, b| a.0.total_cmp(&b.0));
    for (d, _, n, c, _) in &near {
        println!("   {d:5.1} m  {n} ({c})");
    }
    let mut done = std::collections::HashSet::new();
    for (d, a, n, c, caddr) in near.iter().take(6) {
        println!("== {n} ({c}) {d:.1} m");
        dump(&api, *a, c, None);
        if done.insert(c.clone()) {
            for (f, fname) in common::class_functions(&api, *caddr) {
                common::scan_script(&api, f, &format!("{c}::{fname}"));
            }
        }
    }
}

/// The statue the operator lit with the torch: every loaded class whose
/// name mentions a statue puzzle, its live objects with distance and
/// their fields, and a scan of every function.
#[test]
fn statue_puzzle() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let p = instances(&api, "FS_Full_PlayerChar_C", 2)
        .into_iter()
        .next()
        .and_then(|(a, _)| position(&api, a, root, loc))
        .unwrap_or([0.0; 3]);
    for (caddr, class) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = class.to_ascii_lowercase();
        if !(l.contains("statuepuzzle") || l.contains("puzzlestatue") || l.contains("aqrstatue")) {
            continue;
        }
        println!("-- class {class} (parents {:?})", common::super_chain(&api, caddr));
        for (a, n) in instances(&api, &class, 20) {
            let q = position(&api, a, root, loc).unwrap_or([0.0; 3]);
            let d = ((q[0] - p[0]).powi(2) + (q[1] - p[1]).powi(2)).sqrt() / 100.0;
            println!("== {n}: {d:.1} m, height {:+.1} m", (q[2] - p[2]) / 100.0);
            dump(&api, a, &class, None);
        }
        for (f, fname) in common::class_functions(&api, caddr) {
            common::scan_script(&api, f, &format!("{class}::{fname}"));
        }
    }
}

/// What lit Beacon_Brazier_00_BP_2: every loaded class whose name
/// mentions activation, hits, damage, magic fire or a sensor, with
/// live objects within 20 m of that beacon (measured from the beacon,
/// so it does not matter where the player has walked since), dumped.
#[test]
fn beacon_lighter() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let (Some(root), Some(loc)) = (
        field_off(&api, "Actor", "RootComponent"),
        field_off(&api, "SceneComponent", "RelativeLocation"),
    ) else {
        println!("a reflected offset was not found");
        return;
    };
    let Some(b) = instances(&api, "Beacon_Brazier_00_BP_C", 100)
        .into_iter()
        .find(|(_, n)| n == "Beacon_Brazier_00_BP_2")
        .and_then(|(a, _)| position(&api, a, root, loc))
    else {
        println!("Beacon_Brazier_00_BP_2 not loaded");
        return;
    };
    println!("beacon at {b:?}");
    let words = ["activat", "hit", "damage", "magicfire", "sensor", "receiv", "detector", "plate", "offering"];
    let skip = ["spook", "elevator", "music", "worldeventreceiver", "widget", "weapon", "projectile", "anim", "notify"];
    let mut near: Vec<(f32, u64, String, String)> = Vec::new();
    for (_, class) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = class.to_ascii_lowercase();
        if !words.iter().any(|w| l.contains(w)) || skip.iter().any(|w| l.contains(w)) {
            continue;
        }
        for (a, n) in instances(&api, &class, 300) {
            let Some(q) = position(&api, a, root, loc) else { continue };
            let d = ((q[0] - b[0]).powi(2) + (q[1] - b[1]).powi(2) + (q[2] - b[2]).powi(2)).sqrt() / 100.0;
            if d < 20.0 {
                near.push((d, a, n, class.clone()));
            }
        }
    }
    near.sort_by(|x, y| x.0.total_cmp(&y.0));
    for (d, a, n, c) in &near {
        println!("== {d:5.1} m from the beacon: {n} ({c})");
        dump(&api, *a, c, None);
    }
}

/// Class names only, no per-class scans, so it stays fast.
#[test]
fn progress_classes() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if hit(&name, WORDS) && !name.to_ascii_lowercase().contains("anim") {
            let parents = common::super_chain(&api, addr);
            println!("{name} <- {}", parents.iter().take(3).cloned().collect::<Vec<_>>().join(" <- "));
        }
    }
    for class in ["FS_PlayerChar_C", "FS_PlayerCharacter"] {
        println!("== {class}");
        for f in fields(&api, class) {
            if hit(&f.0, WORDS) {
                println!("   field {} +{:#x} ({})", f.0, f.1, f.2);
            }
        }
        for f in functions(&api, class) {
            if hit(&f, WORDS) {
                println!("   fn {f}");
            }
        }
    }
}

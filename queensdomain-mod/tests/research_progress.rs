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

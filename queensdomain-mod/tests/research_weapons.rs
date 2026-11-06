//! How do weapons level up: from damage dealt, or from kills?
//!
//! Prints, read live:
//! - every loaded Blueprint class whose name says weapon, xp or
//!   level-up, with its parents,
//! - their fields whose names mention xp, level, kill or damage,
//! - the player character's fields about weapons, xp and levels,
//! - functions on those classes that mention xp or level,
//! - the loaded data tables.
//!
//! EnemyData_C already carries XPReward (10 on a Looker) and
//! EnemyBase_C carries SkipXPReward, see research_aggro.rs.
//!
//! ```text
//! k3sc cargo-lock test -p queensdomain-mod --test research_weapons -- --test-threads=1 --nocapture
//! ```

mod common;
use common::{api, fields, instances, ping_or_skip};
use serde_json::json;

const WORDS: &[&str] = &["xp", "exp", "level", "kill", "damage", "upgrade", "rank", "mastery"];

fn matches(name: &str, words: &[&str]) -> bool {
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

/// The fast half: no per-class object scans. Fields and functions
/// about xp, levels, kills and damage on the player, the weapon
/// system component, the weapon script base, and the enemy base
/// classes (who hands XP out, and when).
#[test]
fn weapon_xp_owners() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let words = ["weapon", "xp", "exp", "level", "kill", "reward", "die", "death", "damage"];
    for class in [
        "FS_PlayerChar_C",
        "FS_PlayerCharacter",
        "WeaponSystem_C",
        "WeaponScriptBase_C",
        "EnemyBase_C",
        "FS_EnemyCharacterBase",
        "EnemyData_C",
    ] {
        println!("== {class}");
        for f in fields(&api, class) {
            if matches(&f.0, &words) {
                println!("   field {} +{:#x} ({})", f.0, f.1, f.2);
            }
        }
        for f in functions(&api, class) {
            if matches(&f, &words) {
                println!("   fn {f}");
            }
        }
    }
}

/// The operator has "Holy Sword Endu" and a rusty sword and asks how
/// they differ. Prints every FS_ItemData_C whose display name (FText
/// +0x110) says sword or endu: its asset name, description, DataTags
/// (+0x88, TMap of tag to f32 at stride 24, see research_charms) and
/// every field of the item data and of its StatData object (+0x30)
/// through their class chains.
#[test]
fn swords() {
    item_stats(&["sword", "endu"]);
}

/// The operator asks how the Azure Torch works. Same dump as swords.
#[test]
fn azure_torch() {
    item_stats(&["azure", "torch"]);
}

/// How the Azure Torch behaves: every loaded Blueprint class whose
/// name says torch, azure, fireball, blaze or burn (not anim), with
/// parents, the fields of one live object and a bytecode scan of each
/// function (common::scan_script); plus Torch_WeaponStats CustomStats
/// (FS_ItemStats +0x30, a TMap read as FName key and f32 value at
/// stride 24, as DataTags in research_charms) and the raw DamageTypes.
#[test]
fn azure_torch_logic() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    if let Some((stats, _)) = instances(&api, "FS_WeaponStats", 2000)
        .into_iter()
        .find(|(_, n)| n == "Torch_WeaponStats")
    {
        let h = modforge::client::read_bytes(&api, stats, 0x30, 16);
        let data = modforge::client::from_le_u64(&h, 0);
        let num = i32::from_le_bytes(h[8..12].try_into().unwrap()).clamp(0, 64) as u64;
        let b = modforge::client::read_bytes(&api, data, 0, num * 24);
        for i in 0..num as usize {
            if b.len() < i * 24 + 12 {
                break;
            }
            let f = modforge::client::from_le_u64(&b, i * 24);
            let r = api.op("fname_to_string", json!({"fname": f}));
            let v = f32::from_le_bytes(b[i * 24 + 8..i * 24 + 12].try_into().unwrap());
            println!(
                "custom stat {} = {v}",
                r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?")
            );
        }
        let d = modforge::client::read_bytes(&api, stats, 0x250, 32);
        println!("DamageTypes raw: {}", hex::encode(&d));
        let dp = modforge::client::from_le_u64(&d, 0);
        let dn = i32::from_le_bytes(d[8..12].try_into().unwrap()).clamp(0, 16) as u64;
        if dp != 0 && dn > 0 {
            println!("DamageTypes elements: {}", hex::encode(modforge::client::read_bytes(&api, dp, 0, dn * 8)));
        }
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = name.to_ascii_lowercase();
        if !["torch", "azure", "fireball", "blaze", "burn"].iter().any(|w| l.contains(w)) || l.contains("anim") {
            continue;
        }
        let parents = common::super_chain(&api, addr);
        println!("#### {name} <- {}", parents.iter().take(3).cloned().collect::<Vec<_>>().join(" <- "));
        if let Some((obj, _)) = instances(&api, &name, 1).into_iter().next() {
            common::dump(&api, obj, &name, None);
        }
        for (f, n) in common::class_functions(&api, addr) {
            if common::class_of(&api, f) == "Function" && !n.starts_with("ExecuteUbergraph") {
                common::scan_script(&api, f, &n);
            }
        }
    }
}

/// The torch's event graph and the magic fire it deals: scans
/// ExecuteUbergraph_Torch_WeaponScript (left out of azure_torch_logic),
/// every DamageUtils_C function about magic fire, PlayerBalance fields
/// about fire, burn, magic or torch, and every loaded class whose name
/// says magicfire or burn with its fields on one live object.
#[test]
fn azure_torch_fire() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    if let Some((pb, _)) = instances(&api, "PlayerBalance_C", 2).into_iter().next() {
        println!("== PlayerBalance");
        common::dump(&api, pb, "PlayerBalance_C", Some(&["fire", "burn", "magic", "torch", "ablaze", "light"]));
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = name.to_ascii_lowercase();
        if name == "Torch_WeaponScript_C" || name == "DamageUtils_C" {
            for (f, n) in common::class_functions(&api, addr) {
                let ln = n.to_ascii_lowercase();
                if (name == "Torch_WeaponScript_C" && n.starts_with("ExecuteUbergraph"))
                    || (name == "DamageUtils_C" && (ln.contains("fire") || ln.contains("burn")))
                {
                    common::scan_script(&api, f, &format!("{name}::{n}"));
                }
            }
        } else if (l.contains("magicfire") || l.contains("burn") || l.contains("onfire")) && !l.contains("anim") {
            println!("#### {name} <- {}", common::super_chain(&api, addr).first().cloned().unwrap_or_default());
            if let Some((obj, _)) = instances(&api, &name, 1).into_iter().next() {
                common::dump(&api, obj, &name, None);
            }
        }
    }
}

fn item_stats(words: &[&str]) {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    for (addr, name) in instances(&api, "FS_ItemData_C", 5000) {
        let shown = common::ftext(&api, addr, 0x110).unwrap_or_default();
        let l = format!("{name} {shown}").to_ascii_lowercase();
        if !words.iter().any(|w| l.contains(w)) {
            continue;
        }
        let desc = common::ftext(&api, addr, 0x128).unwrap_or_default();
        println!("== {name} \"{shown}\"\n   desc: {desc}");
        let h = modforge::client::read_bytes(&api, addr, 0x88, 16);
        if h.len() == 16 {
            let data = modforge::client::from_le_u64(&h, 0);
            let num = i32::from_le_bytes(h[8..12].try_into().unwrap());
            if data != 0 && (1..64).contains(&num) {
                let b = modforge::client::read_bytes(&api, data, 0, num as u64 * 24);
                for i in 0..num as usize {
                    let o = i * 24;
                    if b.len() < o + 12 {
                        break;
                    }
                    let f = modforge::client::from_le_u64(&b, o);
                    let r = api.op("fname_to_string", json!({"fname": f}));
                    let v = f32::from_le_bytes(b[o + 8..o + 12].try_into().unwrap());
                    println!(
                        "   tag {} = {v}",
                        r.result.get("string").and_then(|s| s.as_str()).unwrap_or("?")
                    );
                }
            }
        }
        let stat = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, addr, 0x30, 8), 0);
        for obj in [addr, stat] {
            if obj == 0 {
                continue;
            }
            let cls = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, obj, 0x10, 8), 0);
            let mut chain = vec![common::object_name(&api, cls)];
            chain.extend(common::super_chain(&api, cls));
            for c in chain.iter().take_while(|c| {
                !matches!(c.as_str(), "DataAsset" | "PrimaryDataAsset" | "Object")
            }) {
                common::dump(&api, obj, c, None);
            }
        }
    }
}

/// How does Endu's Wind Dash work? Lists loaded Blueprint classes
/// whose names say flyingsword, dash or wind (not anim), with parents,
/// their fields with values on the CDO-free live object when one is
/// loaded, and their functions; plus the player's dash fields.
#[test]
fn wind_dash() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let words = ["dash", "fly", "flight", "charge", "wind", "gem", "air", "glide"];
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let l = name.to_ascii_lowercase();
        if !(l.contains("flyingsword") || l.contains("dash") || l.contains("wind"))
            || l.contains("anim")
            || l.contains("window")
        {
            continue;
        }
        let parents = common::super_chain(&api, addr);
        println!("== {name} <- {}", parents.iter().take(3).cloned().collect::<Vec<_>>().join(" <- "));
        if let Some((obj, _)) = instances(&api, &name, 1).into_iter().next() {
            common::dump(&api, obj, &name, None);
        }
        let fns = functions(&api, &name);
        if !fns.is_empty() {
            println!("   functions: {}", fns.join(", "));
        }
    }
    println!("== player dash fields");
    if let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() {
        common::dump(&api, player, "FS_PlayerChar_C", Some(&words));
    }
    for f in functions(&api, "FS_PlayerChar_C") {
        if matches(&f, &words) {
            println!("   fn {f}");
        }
    }
    // The player's own Endu charge counter, not the first instance
    // the walk returns: FS_PlayerChar_C::FlyingSwordChargeLogic.
    if let (Some((player, _)), Some(off)) = (
        instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next(),
        fields(&api, "FS_PlayerChar_C").into_iter().find(|f| f.0 == "FlyingSwordChargeLogic").map(|f| f.1),
    ) {
        let comp = modforge::client::from_le_u64(&modforge::client::read_bytes(&api, player, off, 8), 0);
        if comp != 0 {
            println!("== player's FlyingSwordChargeLogic");
            common::dump(&api, comp, "FlyingSwordChargeLogic_C", None);
        }
    }
}

#[test]
fn weapon_xp() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let bps = instances(&api, "BlueprintGeneratedClass", 20000);
    let classes: Vec<(u64, String)> = bps
        .into_iter()
        .filter(|(_, n)| {
            let l = n.to_ascii_lowercase();
            (l.contains("weapon") || l.contains("xp") || l.contains("levelup") || l.contains("level_up"))
                && !l.contains("anim")
        })
        .collect();
    println!("== {} weapon / xp classes", classes.len());
    for (addr, name) in &classes {
        let parents = common::super_chain(&api, *addr);
        let fs: Vec<String> = fields(&api, name)
            .into_iter()
            .filter(|f| matches(&f.0, WORDS))
            .map(|f| format!("{}(+{:#x},{})", f.0, f.1, f.2))
            .collect();
        let fns: Vec<String> = functions(&api, name)
            .into_iter()
            .filter(|f| matches(f, &["xp", "exp", "level", "kill"]))
            .collect();
        let live = instances(&api, name, 1).len();
        println!(
            "-- {name} <- {}  live:{live}",
            parents.first().cloned().unwrap_or_default()
        );
        if !fs.is_empty() {
            println!("   fields: {}", fs.join(" "));
        }
        if !fns.is_empty() {
            println!("   functions: {}", fns.join(", "));
        }
    }

    println!("== player");
    for class in ["FS_PlayerChar_C", "FS_PlayerCharacter"] {
        for f in fields(&api, class) {
            if matches(&f.0, &["weapon", "xp", "exp", "level", "kill"]) {
                println!("   {class}.{} +{:#x} ({})", f.0, f.1, f.2);
            }
        }
        for f in functions(&api, class) {
            if matches(&f, &["weapon", "xp", "exp", "level", "kill"]) {
                println!("   {class} fn {f}");
            }
        }
    }
    for class in ["EnemyBase_C", "FS_EnemyCharacterBase"] {
        for f in functions(&api, class) {
            if matches(&f, &["xp", "exp", "kill", "die", "death", "reward"]) {
                println!("   {class} fn {f}");
            }
        }
    }

    let r = api.op("discover_data_tables", json!({}));
    println!("== data tables: {}", serde_json::to_string(&r.result).unwrap_or_default().chars().take(2000).collect::<String>());
}

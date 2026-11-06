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
use common::{api, class_of, fields, instances, ping_or_skip};
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

/// How fast does the torch's secondary recharge? Its stats say
/// MaxCharges 2, AbilityPointsPerCharge 10, ChargeOverTime true.
/// Prints where charge state and rates live: player, weapon script
/// base and PlayerBalance fields about ability points, charges and
/// regen, with values, and a bytecode scan of the functions whose
/// names say charge or ability on the player and weapon script base.
#[test]
fn torch_recharge() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let words = ["ability", "charge", "point", "regen", "overtime", "over time", "resource"];
    if let Some((pb, _)) = instances(&api, "PlayerBalance_C", 2).into_iter().next() {
        common::dump(&api, pb, "PlayerBalance_C", Some(&words));
    }
    if let Some((player, _)) = instances(&api, "FS_Full_PlayerChar_C", 2).into_iter().next() {
        common::dump(&api, player, "FS_PlayerChar_C", Some(&["ability", "weaponcharge", "abilitypoint", "regen"]));
    }
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if name != "WeaponScriptBase_C" && name != "Torch_WeaponScript_C" && name != "FS_PlayerChar_C" {
            continue;
        }
        if let Some((obj, _)) = instances(&api, &name, 1).into_iter().next() {
            if name != "FS_PlayerChar_C" {
                common::dump(&api, obj, &name, None);
            }
        }
        for (f, n) in common::class_functions(&api, addr) {
            let l = n.to_ascii_lowercase();
            if (l.contains("charge") || l.contains("ability")) && !l.contains("flying") && !l.contains("dagger") && !l.contains("ultra") {
                common::scan_script(&api, f, &format!("{name}::{n}"));
            }
        }
    }
}

/// Where the weapon-charge code is called from: every function of the
/// weapon script, torch script and player classes whose bytecode
/// touches a charge name, printed as the run of names around each
/// touch in bytecode order. Shows what drives the over-time refill
/// (ApplyCooldownWeaponAbilityPointGen), whether ChargeOverTime gates
/// it, and where hits add points (AddToCharge, Resource Conversion).
#[test]
fn torch_recharge_callers() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let targets = [
        "ApplyCooldownWeaponAbilityPointGen",
        "ApplyBindingAbilityPointDegen",
        "AddToCharge",
        "Gained A Charge",
        "ChargeOverTime",
        "Resource Conversion To Weapon Ability Points",
        "Resource Gen Per Weapon Ability Point Spent",
        "LastSpentAbilityPoints",
        "HeldInHand",
        "ChargeViaResourceGen",
        "LastWeaponAbilityPointsGeneratedFromResources",
    ];
    if let Some((stats, _)) = instances(&api, "FS_WeaponStats", 2000).into_iter().find(|(_, n)| n == "Torch_WeaponStats") {
        common::dump(&api, stats, "FS_WeaponStats", Some(&["charge", "ability", "resource"]));
    }
    let classes = ["WeaponScriptBase_C", "Torch_WeaponScript_C", "FS_PlayerChar_C", "FS_Full_PlayerChar_C"];
    let mut cache = Default::default();
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        if !classes.contains(&name.as_str()) {
            continue;
        }
        for (f, n) in common::class_functions(&api, addr) {
            let Some((_, _, refs)) = common::script_refs(&api, f, &mut cache) else { continue };
            let hit = |r: &common::ScriptRef| {
                let s = r.to_string();
                targets.iter().any(|t| s.contains(t))
            };
            let hits: Vec<usize> = refs.iter().enumerate().filter(|(_, r)| hit(&r.1)).map(|(i, _)| i).collect();
            if hits.is_empty() {
                continue;
            }
            println!("== {name}::{n} ({} refs, {} touches)", refs.len(), hits.len());
            let mut shown_to = 0usize;
            for &h in &hits {
                let from = h.saturating_sub(10).max(shown_to);
                let to = (h + 11).min(refs.len());
                if from >= to {
                    continue;
                }
                if from > shown_to {
                    println!("   ...");
                }
                let run: Vec<String> = refs[from..to].iter().map(|(o, r)| format!("{o:#x}:{r}")).collect();
                println!("   {}", run.join("  "));
                shown_to = to;
            }
        }
    }
}

/// Do all weapons max at level 10? Every loaded FS_WeaponStats asset's
/// fields about levels and xp, one line per weapon.
#[test]
fn weapon_max_levels() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let fs: Vec<_> = fields(&api, "FS_WeaponStats")
        .into_iter()
        .filter(|f| {
            let l = f.0.to_ascii_lowercase();
            l.contains("level") || l.contains("xp")
        })
        .collect();
    println!("level fields: {:?}", fs.iter().map(|f| (&f.0, f.1, f.2)).collect::<Vec<_>>());
    let end = fs.iter().map(|f| f.1 + f.2).max().unwrap_or(0);
    let mut rows: Vec<(String, String)> = instances(&api, "FS_WeaponStats", 2000)
        .into_iter()
        .map(|(a, n)| {
            let b = modforge::client::read_bytes(&api, a, 0, end);
            let vals: Vec<String> = fs.iter().map(|(f, o, s)| format!("{f}={}", common::show(&api, &b, *o, *s))).collect();
            (n, vals.join("  "))
        })
        .collect();
    rows.sort();
    for (n, v) in &rows {
        println!("{n:<40} {v}");
    }
    println!("{} weapons", rows.len());
}

/// How is the XP for each weapon level worked out, and does anything
/// past level 25 break? Scans every function whose name mentions a
/// weapon level or weapon XP on the utility, player, weapon, stats and
/// save classes.
#[test]
fn weapon_level_code() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    if let Some((pb, _)) = instances(&api, "PlayerBalance_C", 2).into_iter().next() {
        common::dump(&api, pb, "PlayerBalance_C", Some(&["level", "xp"]));
    }
    let class_words = ["utils", "player", "weapon", "stats", "save", "xp", "level", "math"];
    for (addr, name) in instances(&api, "BlueprintGeneratedClass", 20000) {
        let cl = name.to_ascii_lowercase();
        if !class_words.iter().any(|w| cl.contains(w)) || cl.contains("weaponscript_c") && cl != "weaponscriptbase_c" {
            continue;
        }
        for (f, n) in common::class_functions(&api, addr) {
            let l = n.to_ascii_lowercase();
            let about_level = (l.contains("weapon") && (l.contains("level") || l.contains("xp")))
                || name == "PlayerMathFunctions_C"
                || l.contains("xpforlevel")
                || l.contains("xptolevel")
                || l.contains("levelfromxp");
            if about_level && !l.starts_with("executeubergraph") {
                common::scan_script(&api, f, &format!("{name}::{n}"));
            }
        }
    }
}

/// Sets MaxWeaponLevel to env WEAPON_MAX_LEVEL on every loaded
/// FS_WeaponStats asset whose max is above 5 (the 1, 2 and 5 weapons
/// stay as they are), and reads each back. Safe past 25 because the
/// weapon level is a formula, not a table (weapon_level_code):
/// PlayerMathFunctions_C::CalculateLevelWithValues gives
/// min(floor(total XP / AmtPerLevel), MaxLevel), with AmtPerLevel =
/// PlayerBalance "Weapon XP Needed Per Level" 100 x XPPerWeaponLevelMult.
/// A live memory change: lost on restart, which restores the game's own
/// 10 and 25.
#[test]
#[ignore = "writes to the game; run by name"]
fn set_weapon_max_level() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(want) = std::env::var("WEAPON_MAX_LEVEL").ok().and_then(|v| v.parse::<i32>().ok()) else {
        println!("set WEAPON_MAX_LEVEL");
        return;
    };
    let Some(off) = fields(&api, "FS_WeaponStats").into_iter().find(|f| f.0 == "MaxWeaponLevel").map(|f| f.1) else {
        println!("MaxWeaponLevel not found");
        return;
    };
    let i32_at = |a: u64| {
        let b = modforge::client::read_bytes(&api, a, off, 4);
        i32::from_le_bytes(b[..4].try_into().unwrap())
    };
    let (mut changed, mut kept) = (0, Vec::new());
    for (a, n) in instances(&api, "FS_WeaponStats", 2000) {
        let before = i32_at(a);
        if before <= 5 {
            kept.push(format!("{n}={before}"));
            continue;
        }
        if before != want {
            modforge::client::write_bytes(&api, a, off, &want.to_le_bytes());
            changed += 1;
        }
        let after = i32_at(a);
        assert_eq!(after, want, "{n}");
    }
    println!("{changed} weapons set to max level {want}; kept: {}", kept.join(", "));
}

/// Sets the Azure Torch's AbilityPointsPerCharge on the loaded
/// Torch_WeaponStats asset (env TORCH_POINTS_PER_CHARGE, default 10,
/// the game's own value) and reads it back. The torch refills 0.33
/// points per second (torch_recharge_callers), so 10 is about 30 s per
/// charge and 5 about 15 s. Only the torch changes; the shared rate in
/// PlayerBalance is left alone. A live memory change: lost on restart.
#[test]
#[ignore = "writes to the game; run by name"]
fn set_torch_points_per_charge() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let want: f32 = std::env::var("TORCH_POINTS_PER_CHARGE").ok().and_then(|v| v.parse().ok()).unwrap_or(10.0);
    let Some((stats, _)) = instances(&api, "FS_WeaponStats", 2000).into_iter().find(|(_, n)| n == "Torch_WeaponStats") else {
        println!("Torch_WeaponStats not loaded");
        return;
    };
    let Some(off) = fields(&api, "FS_WeaponStats").into_iter().find(|f| f.0 == "AbilityPointsPerCharge").map(|f| f.1) else {
        println!("AbilityPointsPerCharge not found");
        return;
    };
    let f32_here = || {
        let b = modforge::client::read_bytes(&api, stats, off, 4);
        f32::from_le_bytes(b[..4].try_into().unwrap())
    };
    let before = f32_here();
    let ok = modforge::client::write_bytes(&api, stats, off, &want.to_le_bytes());
    let after = f32_here();
    println!("Torch AbilityPointsPerCharge {before} -> {after} (write ok: {ok}); about {:.1} s per charge at 0.33/s", after / 0.33);
    assert_eq!(after, want);
}

/// Measures the torch's recharge: every live Torch_WeaponScript_C's
/// CurrentAbilityPoints (WeaponScriptBase_C field) once a second for
/// 60 s, printing each change with the rate since the last one.
/// PlayerBalance says 0.33 points per second over time and the torch
/// needs 10 per charge, 2 charges max.
#[test]
fn torch_recharge_sampler() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let Some(off) = fields(&api, "WeaponScriptBase_C").into_iter().find(|f| f.0 == "CurrentAbilityPoints").map(|f| f.1) else {
        println!("CurrentAbilityPoints not found");
        return;
    };
    println!("sampling 90 s: equip the torch, fire the secondary until empty, then do not attack");
    let read = |a: u64| {
        let b = modforge::client::read_bytes(&api, a, off, 4);
        if b.len() == 4 { f32::from_le_bytes(b[..4].try_into().unwrap()) } else { f32::NAN }
    };
    let t0 = std::time::Instant::now();
    // address -> (label, last value, time of last change)
    let mut seen: std::collections::HashMap<u64, (String, f32, f32)> = Default::default();
    let mut next_look = 0.0f32;
    while t0.elapsed().as_secs() < 90 {
        let now = t0.elapsed().as_secs_f32();
        if now >= next_look {
            next_look = now + 2.0;
            for (a, n) in instances(&api, "WeaponScriptBase_C", 16) {
                seen.entry(a).or_insert_with(|| {
                    let label = format!("{n} ({})", class_of(&api, a));
                    let v = read(a);
                    println!("   {now:5.1} s {label}: {v:.2} points");
                    (label, v, now)
                });
            }
        }
        for (a, (label, last, at)) in seen.iter_mut() {
            let v = read(*a);
            if (v - *last).abs() > 0.05 {
                let rate = (v - *last) / (now - *at);
                println!("   {now:5.1} s {label}: {last:.2} -> {v:.2} points ({rate:+.3}/s)");
                *last = v;
                *at = now;
            }
        }
        std::thread::sleep(std::time::Duration::from_millis(500));
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

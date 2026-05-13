//! Wild West Miner skill catalog + Harmony hook wiring.
//!
//! v0 scope: enough plumbing to prove the bridge works end-to-end.
//! Two skills, one trigger source, in-memory state, manual
//! Add-XP / Level-Up via the HTTP debug surface.
//!
//! As modforge::rpg lands its Tracker / Skill / Effect traits,
//! migrate this to declarative catalog rows.

use std::sync::atomic::{AtomicU32, AtomicU64, Ordering};
use std::ffi::c_void;

use serde_json::{Value as Json, json};

use modforge::args::arg_str;
use modforge::ops::{OP_REGISTRY, OpDef};

use unityforge::hook::{HOOK_REGISTRY, patch_postfix};

/// Per-skill state for v0. Real state goes in modforge::rpg once
/// migrated. For now, atomics are enough to prove the round-trip.
static XP: AtomicU64 = AtomicU64::new(0);
static LEVEL_STRONG_BACK: AtomicU32 = AtomicU32::new(0);
static LEVEL_GREEDY_MINER: AtomicU32 = AtomicU32::new(0);

/// XP curve. Mirrors ueforge defaults: base=100, exponent=1.8.
fn cumulative_xp_for_level(level: u32) -> u64 {
    if level <= 1 {
        return 0;
    }
    let n = level.min(50) as f64;
    (100.0 * n.powf(1.8)).round() as u64
}

fn level_for_xp(xp: u64) -> u32 {
    let mut k = 1;
    while k < 50 && cumulative_xp_for_level(k + 1) <= xp {
        k += 1;
    }
    k
}

pub fn install() {
    register_ops();
    install_hooks();
}

fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "skill_state",
            "Snapshot of the wwm-rpg skill state",
            "{}",
            |_args| {
                let xp = XP.load(Ordering::Relaxed);
                Ok(json!({
                    "xp": xp,
                    "level": level_for_xp(xp),
                    "skills": {
                        "strong_back": LEVEL_STRONG_BACK.load(Ordering::Relaxed),
                        "greedy_miner": LEVEL_GREEDY_MINER.load(Ordering::Relaxed),
                    }
                }))
            },
        ),
        OpDef::new(
            "skill_add_xp",
            "Manually add XP (debug)",
            "{amount: u64}",
            |args| {
                let amount = args.get("amount").and_then(Json::as_u64).unwrap_or(0);
                let n = XP.fetch_add(amount, Ordering::Relaxed) + amount;
                Ok(json!({"xp": n, "level": level_for_xp(n)}))
            },
        ),
        OpDef::new(
            "skill_levelup",
            "Spend one point on a skill",
            "{id: str}",
            |args| {
                let id = arg_str(args, "id")?;
                let counter = match id {
                    "strong_back" => &LEVEL_STRONG_BACK,
                    "greedy_miner" => &LEVEL_GREEDY_MINER,
                    other => return Err(format!("unknown skill '{other}'")),
                };
                let n = counter.fetch_add(1, Ordering::Relaxed) + 1;
                Ok(json!({"id": id, "level": n}))
            },
        ),
    ]);
}

fn install_hooks() {
    // Harmony postfix on DigManager.Dig (whatever the actual
    // method name is). For v0 we wire it as a placeholder; the
    // catalog patch points get tuned once the user runs
    // `walk_class DigManager` + `inspect_object` against a
    // running game.
    if let Ok(hook) = patch_postfix("DigManager", "Dig", on_dig_postfix) {
        HOOK_REGISTRY.register(hook);
    }
    if let Ok(hook) = patch_postfix("PlayerManager", "AddPlayerCurrency", on_currency_postfix) {
        HOOK_REGISTRY.register(hook);
    }
}

/// Fired after every `DigManager.Dig`. Grants flat XP per swing.
/// Real catalog will gate on which Effect cares about OnDig.
extern "C" fn on_dig_postfix(_ctx: *const c_void) {
    XP.fetch_add(5, Ordering::Relaxed);
}

/// Fired after every `PlayerManager.AddPlayerCurrency`. Grants
/// XP proportional to the sale (placeholder: flat 10).
extern "C" fn on_currency_postfix(_ctx: *const c_void) {
    XP.fetch_add(10, Ordering::Relaxed);
}

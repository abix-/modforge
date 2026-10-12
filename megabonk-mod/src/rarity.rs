//! The rarity rolls: a record of each one, and a luck boost.
//!
//! `Rarity` (Il2CppAssets.Scripts.Inventory__Items__Pickups) is
//! where an offer's rarity is picked: `GetUpgradeOfferRarity`,
//! `GetEncounterOfferRarity` and `GetItemRarity` are static, take
//! one float each and return the rarity enum (research_rarity.rs,
//! 2026-10-03; chest rolls recorded the argument as 0.0 and results
//! 0 and 1).
//!
//! A postfix on `GetItemRarity` (the only one hooked for now, see
//! `install`):
//! - with the boost at 0 keeps the game's result (returns -1);
//! - with a boost set, calls the same method again with the
//!   argument plus the boost and hands back that result, so the
//!   game's own odds pick the rarity with more put in. The second
//!   call goes through this postfix too; `INNER` lets it pass
//!   untouched.
//!
//! Every outer roll is recorded (argument, game's result, result
//! used). Ops: `rarity_trace` reads the record, `luck_boost` reads
//! or sets the boost.
//!
//! The postfix shape is thewalkingtrade-mod's cleaner_trace.rs.

use std::cell::Cell;
use std::collections::VecDeque;
use std::ffi::{CStr, c_char, c_void};
use std::sync::atomic::{AtomicU32, Ordering};

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use unityforge::hook::{HOOK_REGISTRY, patch_postfix_result, write_result};
use unityforge::mono::{LogLevel, invoke_static, log};

const RARITY: &str = "Il2CppAssets.Scripts.Inventory__Items__Pickups.Rarity";

/// The most recent rolls; older ones fall off the front.
const KEEP: usize = 200;
static ROLLS: Mutex<VecDeque<Json>> = Mutex::new(VecDeque::new());

/// Added to each roll's argument; f32 bits, 0.0 means off.
static BOOST: AtomicU32 = AtomicU32::new(0);

thread_local! {
    /// Set while this module makes its own second call.
    static INNER: Cell<bool> = const { Cell::new(false) };
}

pub fn install() {
    // Only GetItemRarity for now. With all three hooked the game died
    // three times on 2026-10-03, the last with Windows' stack overflow
    // error ("A new guard page for the stack cannot be created"), and
    // GetUpgradeOfferRarity was never recorded once. GetItemRarity went
    // through the hook 13 times with no crash. Suspected, not proven:
    // the upgrade and encounter methods share one native body, so two
    // patches land on one address. The other two return once a test
    // shows whether their native code is the same.
    let results = [patch_postfix_result(RARITY, "GetItemRarity", &json!({}), after_item)];
    for r in results {
        match r {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(LogLevel::Error, &format!("megabonk-mod: rarity hook FAILED: {e}")),
        }
    }
    modforge::ops::OP_REGISTRY.register_many([
        modforge::ops::OpDef::new(
            "rarity_trace",
            "The recorded rarity rolls, oldest first: method, argument, game's result, result used",
            "{clear?: bool}",
            |args| {
                let mut rolls = ROLLS.lock();
                let out: Vec<Json> = rolls.iter().cloned().collect();
                if args.get("clear").and_then(Json::as_bool) == Some(true) {
                    rolls.clear();
                }
                Ok(json!({"rolls": out}))
            },
        ),
        modforge::ops::OpDef::new(
            "luck_boost",
            "Read the luck boost added to every rarity roll's argument, or set it with value (0 is off)",
            "{value?: f32}",
            |args| {
                if let Some(v) = args.get("value").and_then(Json::as_f64) {
                    BOOST.store((v as f32).to_bits(), Ordering::Relaxed);
                }
                Ok(json!({"boost": f32::from_bits(BOOST.load(Ordering::Relaxed))}))
            },
        ),
    ]);
}

fn roll(method: &str, args: *const c_char, result: *const c_char, out: *mut c_char, cap: i32) -> i32 {
    if INNER.with(Cell::get) {
        return -1;
    }
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let (args, result) = unsafe { (CStr::from_ptr(args), CStr::from_ptr(result)) };
    let args: Vec<Json> = serde_json::from_str(args.to_str().unwrap_or("[]")).unwrap_or_default();
    let game: Json = serde_json::from_str(result.to_str().unwrap_or("null")).unwrap_or(Json::Null);
    let arg = args.first().and_then(Json::as_f64);
    let boost = f32::from_bits(BOOST.load(Ordering::Relaxed));

    let mut used = game.clone();
    if boost != 0.0
        && let Some(a) = arg
    {
        INNER.with(|f| f.set(true));
        let again = invoke_static(RARITY, method, &json!([a + f64::from(boost)]));
        INNER.with(|f| f.set(false));
        match again {
            Ok(v) if v.is_number() => used = v,
            Ok(v) => log(LogLevel::Warn, &format!("megabonk-mod: {method} re-roll gave {v}")),
            Err(e) => log(LogLevel::Warn, &format!("megabonk-mod: {method} re-roll failed: {e}")),
        }
    }

    {
        let mut rolls = ROLLS.lock();
        if rolls.len() == KEEP {
            rolls.pop_front();
        }
        rolls.push_back(json!({
            "method": method,
            "arg": arg,
            "boost": boost,
            "game": game,
            "used": used,
        }));
    }

    if used == game {
        -1
    } else {
        // SAFETY: out and cap are the buffer the shim passed in.
        unsafe { write_result(out, cap, &used) }
    }
}

extern "C" fn after_item(
    _instance: *const c_void,
    args: *const c_char,
    result: *const c_char,
    out: *mut c_char,
    cap: i32,
) -> i32 {
    roll("GetItemRarity", args, result, out, cap)
}

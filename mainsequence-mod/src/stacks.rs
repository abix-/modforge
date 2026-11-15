//! Item stack size multiplier, 10x by default. Every item is an `Item`
//! data asset (`Content/Data/Items/ITEM_*`) with `MaxStackSize`, an
//! int. Items that stack to 1 (backpacks, exosuits) stay at 1.
//! Found by tests/research_stacks.rs stack_fields.
//!
//! K8s slot: Def=ClassNamedFieldTweak (ueforge), Registry=bare static,
//! Instance=its per-object vanilla map, Controller=apply.
//!
//! The multiplier is `stack_multiplier` in settings.json next to the
//! mod's DLL. Change it with the `stack_size` op (`{multiplier: 20}`),
//! which saves the file and re-applies at once, or edit the file and
//! restart. Every apply works from the vanilla value it first saw, so
//! changing the multiplier never compounds.
//!
//! The item assets are loaded with the game's item registry, so one
//! apply after they appear is enough: the watcher ends itself on the
//! first apply that finds any. Shutdown puts vanilla back so the next
//! hot reload captures the real vanilla, not the multiplied value.

use std::sync::OnceLock;

use modforge::rpg::poller::PollerHandle;
use modforge::settings::Settings;
use parking_lot::Mutex;
use serde::{Deserialize, Serialize};
use ueforge::data_table::ClassNamedFieldTweak;
use ueforge::ue::class_tweak::ClassTweakStats;

static MAX_STACK: ClassNamedFieldTweak<i32> = ClassNamedFieldTweak::new("Item", "MaxStackSize");
const DEFAULT_MULTIPLIER: i32 = 10;
const INTERVAL: std::time::Duration = std::time::Duration::from_secs(2);

#[derive(Clone, Serialize, Deserialize)]
#[serde(default)]
pub struct StackSettings {
    pub stack_multiplier: i32,
}

impl Default for StackSettings {
    fn default() -> Self {
        Self {
            stack_multiplier: DEFAULT_MULTIPLIER,
        }
    }
}

static SETTINGS: OnceLock<Settings<StackSettings>> = OnceLock::new();
static POLLER: Mutex<Option<PollerHandle>> = Mutex::new(None);

fn settings() -> &'static Settings<StackSettings> {
    SETTINGS.get_or_init(|| Settings::load("settings.json"))
}

pub fn multiplier() -> i32 {
    settings().get().stack_multiplier.max(1)
}

pub fn apply() -> Result<ClassTweakStats, String> {
    let m = multiplier();
    MAX_STACK.apply(
        |o| !o.is_default_object(),
        |v| (v > 1).then(|| v.saturating_mul(m)),
    )
}

pub fn start() {
    let handle = modforge::rpg::poller::spawn_interval("mainsequence/stacks", INTERVAL, || {
        match modforge::seh::guard(apply) {
            Ok(Ok(s)) if s.considered > 0 => {
                ueforge::log!(
                    "stacks: {}x on {} items, {} changed",
                    multiplier(),
                    s.considered,
                    s.patched
                );
                if let Some(h) = POLLER.lock().as_ref() {
                    h.stop_soon();
                }
            }
            Ok(Ok(_)) => {}
            Ok(Err(e)) => ueforge::log!("stacks: {e}"),
            Err(e) => ueforge::log!("stacks: apply faulted: {e}"),
        }
    });
    *POLLER.lock() = Some(handle);
    // Order 260: after the poller (250) has stopped.
    modforge::shutdown::SHUTDOWN_REGISTRY
        .record("stacks", "restore vanilla".into(), 260, restore)
        .keep();
}

fn restore() {
    match MAX_STACK.revert() {
        Ok(n) => ueforge::log!("stacks: {n} items back to vanilla"),
        Err(e) => ueforge::log!("stacks: revert: {e}"),
    }
}

/// `stack_size`: with `multiplier`, save it and re-apply; without,
/// re-apply the saved one. Reports how many items it touched.
pub fn register_ops() {
    ueforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "stack_size",
        "set the item stack size multiplier (saved to settings.json) and apply it now",
        "{multiplier?: i32}",
        |args| {
            if let Some(m) = args.get("multiplier").and_then(|v| v.as_i64()) {
                if !(1..=10_000).contains(&m) {
                    return Err(format!("multiplier {m} outside 1..=10000"));
                }
                settings().update(|s| s.stack_multiplier = m as i32);
            }
            let s = modforge::seh::guard(apply).map_err(|e| format!("apply faulted: {e}"))??;
            ueforge::log!(
                "stacks: {}x on {} items, {} changed (op)",
                multiplier(),
                s.considered,
                s.patched
            );
            Ok(serde_json::json!({
                "multiplier": multiplier(),
                "settings_file": settings().path().display().to_string(),
                "scanned": s.scanned,
                "considered": s.considered,
                "patched": s.patched,
            }))
        },
    ));
}

//! Health regen for the player's castle.
//!
//! Once a second, if the castle's currentHP is below maxHP, call
//! its own Heal(amount). Heal caps at maxHP on the game side
//! (tests/research_heal.rs: 54.7 + Heal(10) gave 60.0 with maxHP
//! 60), so the amount is passed as-is.
//!
//! Cheap by construction: the castle handle is found once by
//! walking VM and cached; the walk only runs again when a read on
//! the cached handle fails (new run, castle destroyed). Between
//! runs (no live VM) the tick costs one failed type walk per
//! second and nothing else.

use std::sync::atomic::{AtomicI32, Ordering};
use std::time::{Duration, Instant};

use parking_lot::Mutex;
use serde_json::json;
use unityforge::mono::{self, LogLevel, MonoType};

/// Health restored per second.
pub const HEAL_PER_SECOND: f64 = 6.0;

const EVERY: Duration = Duration::from_secs(1);

static LAST: Mutex<Option<Instant>> = Mutex::new(None);
static VM_HANDLE: AtomicI32 = AtomicI32::new(0);
static ANNOUNCED: Mutex<bool> = Mutex::new(false);

/// Called from the mod's per-frame tick on the Unity main thread.
pub fn tick() {
    {
        let now = Instant::now();
        let mut last = LAST.lock();
        if last.is_some_and(|t| now.duration_since(t) < EVERY) {
            return;
        }
        *last = Some(now);
    }
    if let Err(e) = heal_step() {
        // A failed read means the cached castle is gone; forget it
        // and try the walk again next second. Say so once per loss.
        if VM_HANDLE.swap(0, Ordering::Relaxed) != 0 {
            mono::log(LogLevel::Info, &format!("wanderburg-mod regen: castle lost ({e}); will look again"));
        }
    }
}

fn castle_handle() -> Result<i32, String> {
    let h = VM_HANDLE.load(Ordering::Relaxed);
    if h != 0 {
        return Ok(h);
    }
    let ty = MonoType::find("VM").ok_or("VM type not found")?;
    let walked = ty.walk(false)?;
    let h = walked
        .as_array()
        .and_then(|a| a.first())
        .and_then(mono::json_handle)
        .ok_or("no live VM")?;
    VM_HANDLE.store(h, Ordering::Relaxed);
    let mut announced = ANNOUNCED.lock();
    if !*announced {
        mono::log(LogLevel::Info, &format!("wanderburg-mod regen: castle found, {HEAL_PER_SECOND} hp/s"));
        *announced = true;
    }
    Ok(h)
}

fn heal_step() -> Result<(), String> {
    let h = castle_handle()?;
    mono::with_object(h, |vm| {
        let cur = vm.read_field("currentHP")?.as_f64().ok_or("currentHP unreadable")?;
        let max = vm.read_field("maxHP")?.as_f64().ok_or("maxHP unreadable")?;
        if cur < max {
            vm.invoke("Heal", &json!([HEAL_PER_SECOND]))?;
        }
        Ok(())
    })
}

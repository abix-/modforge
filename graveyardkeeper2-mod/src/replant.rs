//! Auto replant after a harvest, with the seeds that harvest dropped.
//!
//! A ready bed's death drops each item through WgoData.MakeDrop(Item). A
//! prefix keeps the seeds a garden_*_ready bed drops. On the next tick,
//! when the bed has become garden_empty:
//!   - fewer seeds of one kind than the planting craft needs
//!     (needItems[0].GetCount): every kept seed drops as it would have;
//!   - otherwise exactly that many go into the player's inventory, the rest
//!     drop, and the game's planting runs as GardenInteractionHandler
//!     .Interact does with a seed in hand: TrySetWorker,
//!     CraftComponent.Clear, TryApplySeed (takes the seeds from the
//!     worker's inventory first), ClearWorker.
//! Then work.rs works the planting craft, free of energy, until the bed
//! turns into the growing crop.

use parking_lot::Mutex;
use serde_json::{Value as Json, json};
use std::ffi::{CStr, c_char, c_void};
use std::sync::atomic::{AtomicBool, Ordering};
use unityforge::bridge::MonoHandle;
use unityforge::hook::{HOOK_REGISTRY, patch_prefix_instance_args};
use unityforge::mono::{LogLevel, MonoObject, invoke_static, log};

use crate::take_all::{arg, call, obj};
use crate::tweaks::{main_game, read_handle};
use crate::work;

/// (bed WgoData handle, seed Item handle) kept from a ready bed's drops.
static KEPT: Mutex<Vec<(i32, i32)>> = Mutex::new(Vec::new());
static HAS_WORK: AtomicBool = AtomicBool::new(false);
/// Set while this module drops kept seeds back, so the hook lets them go.
static REDROPPING: AtomicBool = AtomicBool::new(false);

pub fn install() {
    match patch_prefix_instance_args("WgoData", "MakeDrop(Item)", on_make_drop) {
        Ok(hook) => HOOK_REGISTRY.register(hook),
        Err(e) => log(LogLevel::Error, &format!("replant: hook failed: {e}")),
    }
}

fn own(h: i32) -> MonoObject {
    unsafe { MonoObject::from_handle(MonoHandle(h)) }
}

extern "C" fn on_make_drop(instance: *const c_void, args: *const c_char) -> i32 {
    let bed = instance as usize as i32;
    let item = if args.is_null() {
        None
    } else {
        unsafe { CStr::from_ptr(args) }
            .to_str()
            .ok()
            .and_then(|s| serde_json::from_str::<Json>(s).ok())
            .and_then(|j| j.get(0).and_then(|a| a.get("handle")).and_then(Json::as_i64))
            .map(|h| h as i32)
    };
    let (Some(item), true) = (item, bed != 0) else {
        for h in [Some(bed), item].into_iter().flatten().filter(|h| *h != 0) {
            drop(own(h));
        }
        return 0;
    };
    let keep = !REDROPPING.load(Ordering::Acquire) && is_ready_bed_seed(bed, item);
    if keep {
        KEPT.lock().push((bed, item));
        HAS_WORK.store(true, Ordering::Release);
        1
    } else {
        drop(own(bed));
        drop(own(item));
        0
    }
}

fn is_ready_bed_seed(bed: i32, item: i32) -> bool {
    let bed = std::mem::ManuallyDrop::new(own(bed));
    let item = std::mem::ManuallyDrop::new(own(item));
    let id = bed.read_field("id").ok();
    let id = id.as_ref().and_then(Json::as_str).unwrap_or("");
    id.starts_with("garden_")
        && id.ends_with("_ready")
        && item.invoke("get_IsSeed", &json!([])).ok() == Some(json!(true))
}

// Runs on the Unity main thread, like the hook.
pub fn on_tick() {
    if !HAS_WORK.load(Ordering::Acquire) {
        return;
    }
    HAS_WORK.store(false, Ordering::Release);
    let kept = std::mem::take(&mut *KEPT.lock());
    for (bed, seeds) in group_by_bed(kept) {
        match plant(&bed, &seeds) {
            Ok(true) => work::queue(bed, "replant", planted),
            Ok(false) => {}
            Err(e) => log(LogLevel::Warn, &format!("replant: {e}")),
        }
    }
}

/// The planting is worked once the bed is no longer empty.
fn planted(bed: &MonoObject) -> Result<bool, String> {
    Ok(bed.read_field("id")? != json!("garden_empty"))
}

/// Groups kept seeds by bed. Each hook call brought its own bed handle;
/// one per bed is kept, the others are released.
fn group_by_bed(kept: Vec<(i32, i32)>) -> Vec<(MonoObject, Vec<MonoObject>)> {
    let mut groups: Vec<(i64, MonoObject, Vec<MonoObject>)> = Vec::new();
    for (bed, item) in kept {
        let bed = own(bed);
        let key = bed.invoke("GetHashCode", &json!([])).ok().and_then(|j| j.as_i64()).unwrap_or(0);
        match groups.iter_mut().find(|g| g.0 == key) {
            Some(g) => g.2.push(own(item)),
            None => groups.push((key, bed, vec![own(item)])),
        }
    }
    groups.into_iter().map(|(_, b, s)| (b, s)).collect()
}

fn redrop(bed: &MonoObject, seeds: &[MonoObject]) {
    REDROPPING.store(true, Ordering::Release);
    for s in seeds {
        if s.invoke("get_Count", &json!([])).ok().and_then(|c| c.as_i64()).unwrap_or(0) > 0 {
            if let Err(e) = bed.invoke("MakeDrop", &json!([arg(s)])) {
                log(LogLevel::Warn, &format!("replant: redrop: {e}"));
            }
        }
    }
    REDROPPING.store(false, Ordering::Release);
}

/// Stage 1. Returns true when the planting craft was started.
fn plant(bed: &MonoObject, seeds: &[MonoObject]) -> Result<bool, String> {
    let result = plant_inner(bed, seeds);
    // Whatever was not moved to the player drops as the harvest intended.
    redrop(bed, seeds);
    result
}

fn plant_inner(bed: &MonoObject, seeds: &[MonoObject]) -> Result<bool, String> {
    if bed.read_field("id")? != json!("garden_empty") {
        return Ok(false);
    }
    // Seeds of one kind, and the planting craft that kind needs.
    let mut kinds: Vec<(String, i64)> = Vec::new();
    for s in seeds {
        let id = s.read_field("id")?.as_str().unwrap_or("").to_string();
        let n = s.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
        match kinds.iter_mut().find(|k| k.0 == id) {
            Some(k) => k.1 += n,
            None => kinds.push((id, n)),
        }
    }
    let mut chosen = None;
    for (id, total) in &kinds {
        let Some(first) = seeds.iter().find(|s| s.read_field("id").ok() == Some(json!(id))) else {
            continue;
        };
        let Some(craft) = obj(invoke_static(
            "GardenInteractionHandler",
            "TryFindGardenCraft",
            &json!([arg(first), arg(bed), false]),
        )?) else {
            continue;
        };
        let need_items = read_handle(&craft, "needItems")?;
        let need0 = call(&need_items, "get_Item", json!([0]))?.ok_or("craft has no needItems")?;
        let need = need0.invoke("GetCount", &json!([arg(bed)]))?.as_i64().unwrap_or(0);
        if need > 0 && *total >= need {
            chosen = Some((id.clone(), need, craft));
            break;
        }
    }
    let Some((seed_id, need, craft)) = chosen else {
        log(LogLevel::Info, "replant: not enough seeds dropped, not planting");
        return Ok(false);
    };

    if invoke_static("GardenInteractionHandler", "HasAssignedGardenOrder", &json!([arg(bed)]))? == json!(true) {
        return Ok(false);
    }
    let cc = read_handle(bed, "craftComponent")?;
    if cc.invoke("get_IsStarted", &json!([]))? == json!(true) {
        return Ok(false);
    }
    let mg = main_game()?;
    let player = read_handle(&mg, "playerController")?;
    let mastery = player.invoke("GetMasteryLevelForTalentBranch", &json!(["talent_green", null]))?;
    if mastery.as_i64().unwrap_or(0) <= 0 {
        return Ok(false);
    }

    // Move exactly `need` seeds of that kind into the player's inventory.
    let pd = read_handle(&player, "playerData")?;
    let inv = read_handle(&pd, "inventory")?;
    let mut moved = 0;
    let mut seed_for_craft = None;
    for s in seeds.iter().filter(|s| s.read_field("id").ok() == Some(json!(seed_id))) {
        if moved >= need {
            break;
        }
        let n = s.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0);
        let take = (need - moved).min(n);
        let part = call(s, "Split", json!([take, false]))?.ok_or("Split returned null")?;
        if inv.invoke("CanAddItemToInventory", &json!([arg(&part)]))? != json!(true)
            || inv.invoke("AddItemToInventory", &json!([arg(&part), null, false]))? != json!(true)
        {
            // Inventory full: give the part back to the dropped stack.
            let back = s.invoke("get_Count", &json!([]))?.as_i64().unwrap_or(0) + take;
            s.invoke("set_Count", &json!([back]))?;
            log(LogLevel::Info, "replant: inventory full, not planting");
            return Ok(false);
        }
        moved += take;
        seed_for_craft = Some(part);
    }
    let seed = seed_for_craft.ok_or("no seed moved")?;

    // GardenInteractionHandler.Interact, the seed branch.
    let set_worker = bed.invoke("get_Worker", &json!([]))?.is_null();
    if set_worker {
        bed.invoke("TrySetWorker", &json!([arg(&player), null]))?;
    }
    cc.invoke("Clear", &json!([]))?;
    let started = invoke_static(
        "GardenInteractionHandler",
        "TryApplySeed",
        &json!([arg(&seed), arg(&craft), arg(bed)]),
    )?;
    if set_worker {
        bed.invoke("ClearWorker", &json!([]))?;
    }
    // Interact also calls PlayerData.UpdateInteractingItem to refresh the
    // seed in hand. Replant does not use a held item, and with empty hands
    // that call dereferences a null item (PlayerData.SetInteractingItem).
    log(
        LogLevel::Info,
        &format!("replant: planted {seed_id} x{need}: {started}"),
    );
    Ok(started == json!(true))
}


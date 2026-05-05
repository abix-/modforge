// Spike A: kill detection.
//
// Hook Maine.HealthComponent's ProcessEvent slot. Every UFunction call on a
// HealthComponent instance flows through ours. We dispatch by cached
// UFunction* identity for the Kill function. On a Kill, log:
//   - the dying actor's class name (HealthComponent's outer)
//   - the killer's controller, resolved from LastDamageInfo.InstigatorController
//
// We always call the original ProcessEvent before reading LastDamageInfo,
// because the field is populated *during* the damage path that ends in Kill.
// In practice it's already set by the time Kill enters, but be safe.
//
// Filter: only log kills where the dying actor's class chain includes
// "SurvivalCreature". That excludes player deaths and prop / building
// destruction (those don't go through HealthComponent.Kill anyway, but
// belt-and-braces).

use std::ffi::c_void;
use std::sync::OnceLock;

use crate::bbp_log;
use crate::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::sdk::{self, GObjectsView, UClass, UFunction, UObject, find_class_fast, runtime};

const HEALTH_COMPONENT_LAST_DAMAGE_INFO: usize = 0x03B0;
const FDAMAGE_INFO_INSTIGATOR_CONTROLLER: usize = 0x0020;

// FWeakObjectPtr layout: { i32 ObjectIndex; i32 ObjectSerialNumber; }.
#[repr(C)]
#[derive(Clone, Copy)]
struct FWeakObjectPtr {
    object_index: i32,
    object_serial_number: i32,
}

struct State {
    kill_func: usize, // UFunction* for Maine.HealthComponent.Kill
    survival_creature_class: usize, // UClass* for ASurvivalCreature, for filtering
}

unsafe impl Send for State {}
unsafe impl Sync for State {}

static STATE: OnceLock<State> = OnceLock::new();

pub fn install() -> Result<ProcessEventHook, &'static str> {
    let health_class = find_class_fast("HealthComponent")
        .ok_or("HealthComponent class not loaded yet")?;
    let kill_func = health_class
        .get_function("HealthComponent", "Kill")
        .ok_or("HealthComponent.Kill UFunction not found")?;

    // The ASurvivalCreature class. Used to filter out player deaths.
    // SDK confirms ASurvivalCreature is the enemy base; players use
    // ABP_SurvivalPlayerCharacter_C via ASurvivalCharacter, NOT
    // ASurvivalCreature.
    let creature_class = find_class_fast("SurvivalCreature")
        .ok_or("SurvivalCreature class not loaded yet")?;

    let _ = STATE.set(State {
        kill_func: kill_func as *const UFunction as usize,
        survival_creature_class: creature_class as *const UClass as usize,
    });

    bbp_log!("rpg/kill: hooking HealthComponent (Kill UFunction at {:p})", kill_func);
    ProcessEventHook::install("HealthComponent", on_event)
}

fn on_event(this: &UObject, function: &UFunction, parms: *mut c_void, original: OriginalProcessEvent) {
    let Some(state) = STATE.get() else {
        unsafe { original.call(this, function, parms) };
        return;
    };

    let fn_id = function as *const UFunction as usize;
    let is_kill = fn_id == state.kill_func;

    // DIAGNOSTIC: log every PE call we see on HealthComponent. The Kill
    // UFunction turned out to be Final|Native -- the engine calls the C++
    // method directly and bypasses ProcessEvent. We need to find a
    // function that's actually PE-dispatched on death (likely
    // OnRep_HealthState, or none -- in which case we'll need a global PE
    // hook). Keep it on while we're investigating; remove once we know
    // the right signal.
    let func_name = function.as_object().name();
    let actor_name = this
        .outer()
        .map(|o| o.name())
        .unwrap_or_else(|| "<no-outer>".to_string());
    bbp_log!("rpg/kill diag: PE on HealthComponent: fn={} owner={}", func_name, actor_name);

    // Always call original first. Kill itself triggers the death-effects
    // path inside the engine; we want to read state after it commits.
    unsafe { original.call(this, function, parms) };

    if !is_kill {
        return;
    }

    // `this` is the UHealthComponent. Its outer is the dying actor.
    let Some(dying_actor) = this.outer() else {
        bbp_log!("rpg/kill: HealthComponent has no outer; skipping");
        return;
    };

    let actor_class_name = dying_actor
        .class()
        .map(|c| c.as_object().name())
        .unwrap_or_else(|| "<unknown>".to_string());

    // Filter: only log kills on creatures (or subclasses thereof). Skips
    // player deaths and any non-creature health-bearing entity.
    let is_creature = match dying_actor.class() {
        Some(c) => unsafe {
            let creature_uclass = &*(state.survival_creature_class as *const UClass);
            dying_actor.is_a(creature_uclass) || class_chain_contains(c, "SurvivalCreature")
        },
        None => false,
    };

    if !is_creature {
        // Kept gated to debug builds: player deaths are noisy.
        if cfg!(debug_assertions) {
            bbp_log!(
                "rpg/kill: ignored non-creature death: {} ({})",
                dying_actor.name(),
                actor_class_name
            );
        }
        return;
    }

    // Read LastDamageInfo.InstigatorController (FWeakObjectPtr) and
    // resolve via GObjects.
    let instigator_name = read_instigator(this).unwrap_or_else(|| "<unresolved>".to_string());

    bbp_log!(
        "rpg/kill: {} ({}) killed by {}",
        dying_actor.name(),
        actor_class_name,
        instigator_name
    );
}

fn read_instigator(health_component: &UObject) -> Option<String> {
    let weak_ptr: FWeakObjectPtr = unsafe {
        health_component
            .field_ptr(HEALTH_COMPONENT_LAST_DAMAGE_INFO + FDAMAGE_INFO_INSTIGATOR_CONTROLLER)
            .cast::<FWeakObjectPtr>()
            .read_unaligned()
    };
    if weak_ptr.object_index < 0 {
        return None;
    }
    let rt = runtime();
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    let obj = view.get(weak_ptr.object_index)?;
    // Stale-pointer guard: we don't have the per-object ObjectSerialNumber
    // table mapped, so accept the lookup if the class pointer is sane.
    // Worst case for a stale slot: we log a confusing class name. Fine
    // for a spike.
    let class_name = obj.class().map(|c| c.as_object().name()).unwrap_or_default();
    Some(format!("{} ({})", obj.name(), class_name))
}

fn class_chain_contains(class: &UClass, target: &str) -> bool {
    let mut cur: Option<&UClass> = Some(class);
    let mut depth = 0;
    while let Some(c) = cur {
        if depth > 32 {
            return false;
        }
        if c.as_object().name() == target {
            return true;
        }
        cur = c.super_class();
        depth += 1;
    }
    false
}

// silence unused-import warnings on sdk in builds where the only sdk
// references end up macro-shaped
#[allow(dead_code)]
fn _silence_sdk(_: &sdk::UClass) {}

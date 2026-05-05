// Spike A: kill detection.
//
// We hook Maine.HealthComponent's ProcessEvent slot. The kill signal is
// `MulticastHandleEffectsWithDamageFlags`: a NetMulticast RPC fired on
// every damage hit. Its `DamageFlags` int32 parm carries
// `EDamageInfoFlags::KillingBlow = 2` when the hit is lethal.
//
// We also read `HealthComponent.LastDamageInfo` (at +0x3B0) to get the
// killer's controller via FDamageInfo.InstigatorController (FWeakObjectPtr
// at +0x20 inside FDamageInfo).
//
// Why not Kill: it's `Final|Native`, the engine bypasses ProcessEvent on
// the internal damage path. Why not OnDeath delegate bindings: those PE
// dispatch on each enemy's vtable, not HealthComponent's, so a per-vtable
// hook here can't see them.
//
// Field offsets all from C:\tools\work\sdk\SDK:
//   UHealthComponent.LastDamageInfo:           0x03B0  (Maine_classes.hpp:42287)
//   FDamageInfo.InstigatorController:          0x0020  (Maine_structs.hpp:4815)
//   MulticastHandleEffectsWithDamageFlags parms:
//     HitLocation                              0x0000  (FVector_NetQuantize, 0x18)
//     Damage                                   0x0018  (float)
//     DamageFlags                              0x001C  (int32)
//                                                       (Maine_parameters.hpp:46232)
//   EDamageInfoFlags::KillingBlow              = 2     (Maine_structs.hpp:1769)

use std::ffi::c_void;
use std::sync::OnceLock;

use crate::bbp_log;
use crate::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::sdk::{GObjectsView, UClass, UFunction, UObject, find_class_fast, runtime};

const HEALTH_COMPONENT_LAST_DAMAGE_INFO: usize = 0x03B0;
const FDAMAGE_INFO_INSTIGATOR_CONTROLLER: usize = 0x0020;
const MULTICAST_HANDLE_EFFECTS_PARMS_DAMAGE_FLAGS: usize = 0x001C;

const DAMAGE_INFO_FLAG_KILLING_BLOW: i32 = 2;

// AController.Pawn (Engine_classes.hpp:30510). Standard UE5 layout,
// stable across builds.
const A_CONTROLLER_PAWN: usize = 0x0308;

// FWeakObjectPtr layout: { i32 ObjectIndex; i32 ObjectSerialNumber; }.
#[repr(C)]
#[derive(Clone, Copy)]
struct FWeakObjectPtr {
    object_index: i32,
    object_serial_number: i32,
}

struct State {
    multicast_handle_effects_with_damage_flags: usize, // UFunction*
    survival_creature_class: usize,                    // UClass* for filtering
}

unsafe impl Send for State {}
unsafe impl Sync for State {}

static STATE: OnceLock<State> = OnceLock::new();

pub fn install() -> Result<ProcessEventHook, &'static str> {
    let health_class =
        find_class_fast("HealthComponent").ok_or("HealthComponent class not loaded yet")?;
    let multicast_fn = health_class
        .get_function("HealthComponent", "MulticastHandleEffectsWithDamageFlags")
        .ok_or("HealthComponent.MulticastHandleEffectsWithDamageFlags not found")?;

    // ASurvivalCreature filter excludes player deaths AND buildings/props
    // (BP_BaseStructureBuilding, BP_PhysicsHarvestNode also fire this
    // function with IsKillingBlow on destruction).
    let creature_class =
        find_class_fast("SurvivalCreature").ok_or("SurvivalCreature class not loaded yet")?;

    let _ = STATE.set(State {
        multicast_handle_effects_with_damage_flags: multicast_fn as *const UFunction as usize,
        survival_creature_class: creature_class as *const UClass as usize,
    });

    bbp_log!(
        "rpg/kill: hooking HealthComponent (MulticastHandleEffectsWithDamageFlags at {:p})",
        multicast_fn
    );
    ProcessEventHook::install("HealthComponent", on_event)
}

fn on_event(
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let Some(state) = STATE.get() else {
        unsafe { original.call(this, function, parms) };
        return;
    };

    let fn_id = function as *const UFunction as usize;
    let is_target = fn_id == state.multicast_handle_effects_with_damage_flags;

    // Read parms before forwarding so we don't race with anything that
    // might mutate them (the multicast handler is read-only on parms in
    // practice, but be safe).
    let killing_blow = if is_target && !parms.is_null() {
        let damage_flags: i32 = unsafe {
            (parms as *const u8)
                .add(MULTICAST_HANDLE_EFFECTS_PARMS_DAMAGE_FLAGS)
                .cast::<i32>()
                .read_unaligned()
        };
        (damage_flags & DAMAGE_INFO_FLAG_KILLING_BLOW) != 0
    } else {
        false
    };

    unsafe { original.call(this, function, parms) };

    if !killing_blow {
        return;
    }

    // `this` is the UHealthComponent. Its outer is the dying actor.
    let Some(dying_actor) = this.outer() else {
        return;
    };
    let actor_class = match dying_actor.class() {
        Some(c) => c,
        None => return,
    };

    // Filter: only creatures (XP source). Players and props/buildings
    // also fire this function with IsKillingBlow on death/destruction.
    let creature_uclass = unsafe { &*(state.survival_creature_class as *const UClass) };
    let is_creature = dying_actor.is_a(creature_uclass);
    if !is_creature {
        if cfg!(debug_assertions) {
            bbp_log!(
                "rpg/kill: ignoring non-creature kill: {} ({})",
                dying_actor.name(),
                actor_class.as_object().name()
            );
        }
        return;
    }

    let class_name = actor_class.as_object().name();
    let instigator = resolve_instigator(this);
    let kind = classify(instigator);
    let killer_label = describe_instigator(instigator);

    use crate::rpg::tracker::{KillSource, record_kill};
    match kind {
        KillerKind::Player => {
            bbp_log!(
                "rpg/kill: PLAYER {} ({}) killed by {}",
                dying_actor.name(),
                class_name,
                killer_label
            );
            record_kill(&class_name, KillSource::Player);
        }
        KillerKind::Buggy => {
            bbp_log!(
                "rpg/kill: BUGGY {} ({}) killed by {}",
                dying_actor.name(),
                class_name,
                killer_label
            );
            record_kill(&class_name, KillSource::Buggy);
        }
        KillerKind::Other => {
            bbp_log!(
                "rpg/kill: skip {} ({}) -- killer was {}",
                dying_actor.name(),
                class_name,
                killer_label
            );
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum KillerKind {
    Player,
    Buggy,
    Other,
}

fn classify(instigator: Option<&UObject>) -> KillerKind {
    let Some(controller) = instigator else {
        return KillerKind::Other;
    };

    // 1. Direct player kill: controller's class chain contains
    //    "PlayerController". Covers BP_SurvivalPlayerController_C and
    //    its variants (Augusta etc.).
    if class_chain_contains(controller, "PlayerController") {
        return KillerKind::Player;
    }

    // 2. Buggy kill: AIC's class chain contains "Buggy", or the
    //    possessed pawn's class does. Buggies in Grounded 2 are tame
    //    creatures used as the player's mount; their AICs are named
    //    `AIC_<Species>_..._Buggy_C` and the pawns' BP classes contain
    //    "Buggy" too.
    if class_chain_contains(controller, "Buggy") {
        return KillerKind::Buggy;
    }
    if let Some(pawn) = controller_pawn(controller)
        && class_chain_contains(pawn, "Buggy")
    {
        return KillerKind::Buggy;
    }

    // 3. Anything else: enemy-vs-enemy or some non-credit path.
    KillerKind::Other
}

fn controller_pawn(controller: &UObject) -> Option<&UObject> {
    unsafe {
        let p: *mut UObject = controller
            .field_ptr(A_CONTROLLER_PAWN)
            .cast::<*mut UObject>()
            .read_unaligned();
        p.as_ref()
    }
}

fn class_chain_contains(obj: &UObject, needle: &str) -> bool {
    let Some(cls) = obj.class() else { return false };
    let mut cur: Option<&UClass> = Some(cls);
    let mut depth = 0;
    while let Some(c) = cur {
        if depth > 32 {
            return false;
        }
        if c.as_object().name().contains(needle) {
            return true;
        }
        cur = c.super_class();
        depth += 1;
    }
    false
}

fn describe_instigator(instigator: Option<&UObject>) -> String {
    let Some(ctrl) = instigator else {
        return "<unresolved>".to_string();
    };
    let class_name = ctrl
        .class()
        .map(|c| c.as_object().name())
        .unwrap_or_default();
    format!("{} ({})", ctrl.name(), class_name)
}

fn resolve_instigator(health_component: &UObject) -> Option<&'static UObject> {
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
    view.get(weak_ptr.object_index)
        .map(|o| unsafe { &*(o as *const UObject) })
}

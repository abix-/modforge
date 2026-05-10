// Kill detection. Hook the player's HealthComponent ProcessEvent
// slot, watch for `MulticastHandleEffectsWithDamageFlags` with the
// `KillingBlow` flag bit set, identify the dying actor + killer, and
// award XP via `tracker::record_kill`.
//
// Why MulticastHandleEffectsWithDamageFlags: it's the lethal-hit
// signal in Maine. `Kill` is `Final|Native` (engine bypasses PE);
// OnDeath delegate dispatches per-actor vtable, not on
// HealthComponent's, so we'd need per-vtable hooks. The multicast
// fires at HC scope every lethal hit.
//
// Universal helpers (class-chain walks, weak-ptr resolve,
// FDamageInfo reads) live in `ueforge::ue::actor` +
// `ueforge::ue::damage_info`. Diagnostic damage tracing lives in
// `damage_trace`. Environmental-damage reversal lives in
// `impact_resistance`. This module is just the kill-credit core.

use std::ffi::c_void;
use std::sync::OnceLock;

use ueforge::hook::{OriginalProcessEvent, ProcessEventHook};
use ueforge::ue::actor::{class_chain_contains, controller_pawn, is_outer_named};
use ueforge::ue::damage_info::DamageInfoLayout;
use ueforge::ue::{ClassRef, UClass, UFunction, UObject};

use crate::counters;
use crate::rpg::{damage_trace, impact_resistance};

const PLAYER_OUTER_FILTER: &str = "BP_SurvivalPlayerCharacter";

/// Maine `FDamageInfo` layout. `last_damage_info_offset` is
/// `UHealthComponent.LastDamageInfo` at `0x03B0`; the four field
/// offsets are absolute (component-relative, already including the
/// base).
pub(crate) const DAMAGE_INFO: DamageInfoLayout = DamageInfoLayout {
    last_damage_info_offset: 0x03B0,
    instigator_offset: 0x03B0 + 0x0020,
    damage_source_offset: 0x03B0 + 0x0028,
    damage_type_class_offset: 0x03B0 + 0x0040,
    damage_flags_offset: 0x03B0 + 0x0070,
};

/// Parm offset of `DamageFlags` in
/// `MulticastHandleEffectsWithDamageFlags(HitLocation, Damage,
/// DamageFlags, ...)`.
const MULTICAST_DAMAGE_FLAGS_OFFSET: usize = 0x001C;
const KILLING_BLOW_BIT: i32 = 2;

struct State {
    multicast_fn_id: usize,        // UFunction*
    survival_creature_class: usize, // UClass*
}

unsafe impl Send for State {}
unsafe impl Sync for State {}

static STATE: OnceLock<State> = OnceLock::new();
static HEALTH: ClassRef = ClassRef::new("HealthComponent");
static SURVIVAL_CREATURE: ClassRef = ClassRef::new("SurvivalCreature");

pub fn install() -> Result<ProcessEventHook, &'static str> {
    let _hc_class = HEALTH.get().ok_or("HealthComponent class not loaded yet")?;
    let multicast_fn = HEALTH
        .find_function("MulticastHandleEffectsWithDamageFlags")
        .ok_or("HealthComponent.MulticastHandleEffectsWithDamageFlags not found")?;
    let creature_class = SURVIVAL_CREATURE
        .get()
        .ok_or("SurvivalCreature class not loaded yet")?;

    let _ = STATE.set(State {
        multicast_fn_id: multicast_fn as *const UFunction as usize,
        survival_creature_class: creature_class as *const UClass as usize,
    });

    ueforge::log!(
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
    let _t = ueforge::counters::time_scope(&counters::TIME_NS_KILL_HOOK);
    ueforge::counters::bump(&counters::KILL_HOOK_FIRES);

    // Drain the debug PE queue here -- re-entrance guard inside
    // `drain_pending` prevents recursive draining when a queued op
    // itself fans out PE (e.g. AddHealth -> OnRep -> kill_hook).
    crate::debug::drain_pending();

    let Some(state) = STATE.get() else {
        unsafe { original.call(this, function, parms) };
        return;
    };

    // Player-component fan-out: damage trace + impact-resistance
    // reversal. Both are no-ops on non-player HC events.
    let is_player_hc = !parms.is_null() && {
        ueforge::counters::bump(&counters::KILL_HOOK_OWNER_FULLNAME_ALLOCS);
        is_outer_named(this, PLAYER_OUTER_FILTER)
    };
    if is_player_hc {
        ueforge::counters::bump(&counters::KILL_HOOK_PLAYER_FIRES);
        if damage_trace::observe(this, function, parms) {
            damage_trace::log_last_damage_info(this);
        }
        impact_resistance::maybe_reverse(this, &function.as_object().name(), parms);
    }

    // Killing-blow detection on the multicast target fn.
    let fn_id = function as *const UFunction as usize;
    let is_target = fn_id == state.multicast_fn_id;
    let killing_blow = is_target
        && !parms.is_null()
        && unsafe {
            let flags: i32 = (parms as *const u8)
                .add(MULTICAST_DAMAGE_FLAGS_OFFSET)
                .cast::<i32>()
                .read_unaligned();
            (flags & KILLING_BLOW_BIT) != 0
        };

    // Snapshot CurrentDamage around the original call so we can log
    // whether the multicast IS the damage path or just notification.
    let before = is_player_hc.then(|| damage_trace::read_current_damage(this));
    unsafe { original.call(this, function, parms) };
    if let Some(b) = before {
        damage_trace::trace_current_damage_delta(this, b);
    }

    if !killing_blow {
        return;
    }
    award_kill(this, state);
}

fn award_kill(hc: &UObject, state: &State) {
    let Some(dying_actor) = hc.outer() else {
        return;
    };
    let Some(actor_class) = dying_actor.class() else {
        return;
    };

    // Filter: only creatures (XP source). Players + props/buildings
    // also fire MulticastHandleEffectsWithDamageFlags on death.
    let creature_uclass = unsafe { &*(state.survival_creature_class as *const UClass) };
    if !dying_actor.is_a(creature_uclass) {
        if cfg!(debug_assertions) {
            ueforge::log!(
                "rpg/kill: ignoring non-creature kill: {} ({})",
                dying_actor.name(),
                actor_class.as_object().name()
            );
        }
        return;
    }

    let class_name = actor_class.as_object().name();
    let instigator = DAMAGE_INFO.instigator(hc);
    let kind = classify(instigator);
    let killer_label = describe_instigator(instigator);

    use crate::rpg::tracker::{KillSource, record_kill};
    let (label, source) = match kind {
        KillerKind::Player => ("PLAYER", Some(KillSource::Player)),
        KillerKind::Buggy => ("BUGGY", Some(KillSource::Buggy)),
        KillerKind::Other => ("skip", None),
    };
    ueforge::log!(
        "rpg/kill: {} {} ({}) killed by {}",
        label,
        dying_actor.name(),
        class_name,
        killer_label
    );
    if let Some(s) = source {
        record_kill(&class_name, s);
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

    // Direct player kill.
    if class_chain_contains(controller, "PlayerController") {
        return KillerKind::Player;
    }

    // Buggy kill: AIC's class chain or its possessed pawn's class
    // contains "Buggy".
    if class_chain_contains(controller, "Buggy") {
        return KillerKind::Buggy;
    }
    if let Some(pawn) = controller_pawn(controller)
        && class_chain_contains(pawn, "Buggy")
    {
        return KillerKind::Buggy;
    }

    KillerKind::Other
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

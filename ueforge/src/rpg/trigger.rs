//! Trigger trait + per-trigger struct types.
//!
//! Per the workspace
//! [composition model](../../docs/architecture.md), a Skill is
//! an Effect (WHAT) + a Trigger (WHEN). Triggers are first-class
//! Defs, symmetric with Effects:
//!
//! ```text
//! K8s slot: Def=TriggerDef { kind, imp: &'static dyn Trigger },
//!           Registry=catalog (each SkillDef carries one TriggerDef inline),
//!           Instance=&'static dyn Trigger resolved per skill,
//!           Controller=per-trigger-type install + dispatch logic
//! ```
//!
//! ## Phase 1 (current): metadata only
//!
//! The framework ships [`OnSlotChangeTrigger`] -- the trigger every
//! CDO-write skill uses. `Tracker` fires effects on slot
//! activate / spend / refund just like before. The `trigger`
//! field on `SkillDef` is metadata: it documents intent and
//! enables the `list_triggers` op for client discovery.
//!
//! ## Future phases: event-driven dispatch
//!
//! Each non-trivial trigger gets its own struct + install method
//! (matching `damage::DamageHook`'s pattern):
//!
//! - `OnDamageDealtTrigger` -- wraps damage-multicast hook,
//!   filters player-instigator hits, fires per-event with a
//!   `&DamageEvent`.
//! - `OnKillTrigger` -- wraps the kill multicast filter,
//!   fires with `&KillEvent`.
//! - `OnFallTrigger` -- wraps fall_hook, fires with
//!   `&FallEvent`.
//! - `PeriodicTrigger(Duration)` -- poller-driven.
//!
//! Each trigger TYPE owns its own subscribe + dispatch. Effects
//! that care about that trigger's events get the typed event
//! through a per-trigger Binder trait (matching
//! `damage::DamageBinder`'s pattern).
//!
//! ## Why both HookDef AND TriggerDef
//!
//! Different layers, different responsibilities:
//!
//! - `HookDef` -- low-level vtable patch primitive. One per
//!   patched class. Plumbing.
//! - `TriggerDef` -- semantic event source. May install N
//!   underlying HookDefs OR no hooks at all (Periodic is a
//!   poller). Owns filter + decode + typed event dispatch.
//!
//! N:M between them: one trigger may install hooks on multiple
//! classes; one hook may fire multiple triggers (the damage
//! hook serves OnDamageDealt + OnDamageTaken).
//!
//! See [architecture.md](../../docs/architecture.md) "Composition
//! model" for the full rationale.

/// Typed event context passed to `Effect::apply`. Each variant
/// carries the data the effect needs to do its work for that
/// trigger kind. Adding a new trigger type adds a new variant
/// here + a new struct implementing [`Trigger`] + the framework
/// dispatcher that fires the variant when the event happens.
///
/// Phase 2a (current): only `SlotChange` is fired. Phase 2b
/// lifts kill_hook / fall_hook into framework triggers that fire
/// `Kill(&'a KillEvent)` / `Fall(&'a FallEvent)` etc.
pub enum TriggerCtx<'a> {
    /// Fired by `Tracker` on slot activate / spend / refund /
    /// toggle. CDO-write effects use this.
    SlotChange,
    /// Fired by the future `OnDamageDealtTrigger` per
    /// player-instigator damage hit.
    DamageDealt(&'a DamageEventStub),
    /// Fired by the future `OnDamageTakenTrigger` per
    /// player-target damage hit.
    DamageTaken(&'a DamageEventStub),
    /// Fired by the future `KillTrigger` per confirmed kill.
    Kill(&'a KillEventStub),
    /// Fired by the future `FallTrigger` per fall event.
    Fall(&'a FallEventStub),
    /// Fired by the future `PeriodicTrigger` per tick.
    Tick { dt: std::time::Duration },
}

// Stub event types -- placeholder shapes until Phase 2b lifts
// the real event decoders (currently in g2rpg's kill_hook /
// fall_hook). The stubs keep the variants typed and the doc
// surface honest; framework dispatchers don't fire these yet.

#[doc(hidden)]
pub struct DamageEventStub;
#[doc(hidden)]
pub struct KillEventStub;
#[doc(hidden)]
pub struct FallEventStub;

/// Trigger trait. Currently a marker with a `kind` tag for
/// discoverability. Per-trigger wiring (install / subscribe /
/// dispatch) lives in dedicated methods on the concrete trigger
/// struct, because each trigger has its own event type variant
/// in [`TriggerCtx`].
pub trait Trigger: Send + Sync + 'static {
    /// Stable name for client discovery (e.g. `"OnSlotChange"`,
    /// `"OnDamageDealt"`).
    fn kind(&self) -> &'static str;
}

/// Catalog-row reference to a Trigger implementation, plus a
/// kind tag duplicated for fast dispatch without virtual call.
pub struct TriggerDef {
    pub kind: &'static str,
    pub imp: &'static dyn Trigger,
}

impl TriggerDef {
    pub const fn new(kind: &'static str, imp: &'static dyn Trigger) -> Self {
        Self { kind, imp }
    }
}

// =====================================================================
// Standard triggers shipped by the framework.
// =====================================================================

/// Fires when the player's skill state changes (slot activate,
/// spend, refund, toggle). Used by every CDO-write skill --
/// effects fire on level change, do their writes, done. No
/// underlying hook; the Tracker drives dispatch directly.
pub struct OnSlotChangeTrigger;

impl Trigger for OnSlotChangeTrigger {
    fn kind(&self) -> &'static str {
        "OnSlotChange"
    }
}

static ON_SLOT_CHANGE_IMP: OnSlotChangeTrigger = OnSlotChangeTrigger;

/// Pre-built TriggerDef pointer -- catalog rows reference this
/// directly: `trigger: &ueforge::rpg::trigger::ON_SLOT_CHANGE`.
pub static ON_SLOT_CHANGE: TriggerDef =
    TriggerDef::new("OnSlotChange", &ON_SLOT_CHANGE_IMP);

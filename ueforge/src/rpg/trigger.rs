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
//! ## Triggers shipped by the framework
//!
//! - [`OnSlotChangeTrigger`] (`ON_SLOT_CHANGE`). Fired by
//!   `Tracker` on slot activate / spend / refund / toggle. The
//!   trigger every CDO-write skill uses.
//! - [`OnDamageDealtTrigger`] (`ON_DAMAGE_DEALT`). Fires per
//!   player-instigator damage hit (Lifesteal, Crit).
//! - [`OnDamageTakenTrigger`] (`ON_DAMAGE_TAKEN`). Fires per
//!   player-target damage hit (Evasion, Thorns).
//! - [`OnKillTrigger`] (`ON_KILL`). Fires per confirmed kill
//!   (kill-credit driven skills).
//! - [`OnFallTrigger`] (`ON_FALL`). Fires per player fall landing
//!   (Fall Resistance, Impact Resistance).
//!
//! Dispatch for the event-driven triggers is wired by the
//! game crate when it installs the underlying `DamageHook` /
//! fall hook. The framework provides the `TriggerCtx` payloads
//! and the static Defs; per-trigger dispatch helpers land in
//! Phase 5c.2.
//!
//! ## Why both HookDef AND TriggerDef
//!
//! Different layers, different responsibilities:
//!
//! - `HookDef`. Low-level vtable patch primitive. One per
//!   patched class. Plumbing.
//! - `TriggerDef`. Semantic event source. May install N
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
pub enum TriggerCtx<'a> {
    /// Fired by `Tracker` on slot activate / spend / refund /
    /// toggle. CDO-write effects use this.
    SlotChange,
    /// Fired by [`OnDamageDealtTrigger`] per player-instigator
    /// damage hit, BEFORE the engine applies the damage.
    /// Effects may inspect `damage` but cannot mutate it from
    /// here (use a `DamageBinder::before` for mutation).
    DamageDealt(&'a crate::damage::DamageEvent<'a>),
    /// Fired by [`OnDamageTakenTrigger`] per player-target
    /// damage hit, AFTER the engine applies the damage.
    DamageTaken(&'a crate::damage::DamageEvent<'a>),
    /// Fired by [`OnKillTrigger`] per confirmed creature kill
    /// (killing-blow flag set). Carries the resolved victim
    /// class name so subscribers don't have to re-resolve.
    Kill(&'a KillEvent<'a>),
    /// Fired by [`OnFallTrigger`] when the player's `OnLanded`
    /// UFunction fires. Velocity-Z at landing is exposed for
    /// fall-damage and impact-resistance effects.
    Fall(&'a FallEvent<'a>),
    /// Fired by a periodic poller per tick (reserved; no
    /// in-tree consumer yet).
    Tick { dt: std::time::Duration },
}

/// Confirmed kill event. The killing-blow flag has been checked
/// upstream so subscribers fire unconditionally.
pub struct KillEvent<'a> {
    /// The actor that died (typically the victim component's
    /// outer).
    pub victim: &'a crate::ue::UObject,
    /// Resolved name of `victim`'s UClass, pre-allocated by the
    /// trigger dispatcher so subscribers don't pay the FName
    /// lookup per fire.
    pub victim_class_name: &'a str,
    /// Damage instigator resolved from `FDamageInfo`. None if
    /// the weak pointer was unset.
    pub attacker: Option<&'static crate::ue::UObject>,
    /// Convenience: `attacker.class_chain_contains(player_controller_filter)`.
    pub attacker_is_player: bool,
    /// Damage value of the killing blow (after engine mutation,
    /// if any).
    pub damage: f32,
}

/// Player-fall landing event. Fires from inside the OnLanded
/// trampoline BEFORE the engine reads the live Velocity.Z, so
/// effects that mutate `Velocity.Z` (Fall Resistance) and
/// effects that subtract post-impact damage (Impact Resistance)
/// both work off the same fire.
pub struct FallEvent<'a> {
    /// The player pawn whose `OnLanded` fired.
    pub player: &'a crate::ue::UObject,
    /// Live `CharacterMovementComponent.Velocity.Z` snapshot
    /// taken just before the engine processes the landing.
    pub velocity_z_before: f64,
}

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
/// spend, refund, toggle). Used by every CDO-write skill.
/// effects fire on level change, do their writes, done. No
/// underlying hook; the Tracker drives dispatch directly.
pub struct OnSlotChangeTrigger;

impl Trigger for OnSlotChangeTrigger {
    fn kind(&self) -> &'static str {
        "OnSlotChange"
    }
}

static ON_SLOT_CHANGE_IMP: OnSlotChangeTrigger = OnSlotChangeTrigger;

/// Pre-built TriggerDef pointer. Catalog rows reference this
/// directly: `trigger: &ueforge::rpg::trigger::ON_SLOT_CHANGE`.
pub static ON_SLOT_CHANGE: TriggerDef =
    TriggerDef::new("OnSlotChange", &ON_SLOT_CHANGE_IMP);

/// Fires per player-instigator damage hit, BEFORE the engine
/// applies the damage. Used by Lifesteal, Critical, etc. The
/// underlying hook is `ueforge::damage::DamageHook`; the game
/// crate installs the hook and the framework dispatcher fans
/// out `TriggerCtx::DamageDealt(&event)` to subscribed skills.
pub struct OnDamageDealtTrigger;
impl Trigger for OnDamageDealtTrigger {
    fn kind(&self) -> &'static str {
        "OnDamageDealt"
    }
}
static ON_DAMAGE_DEALT_IMP: OnDamageDealtTrigger = OnDamageDealtTrigger;
pub static ON_DAMAGE_DEALT: TriggerDef =
    TriggerDef::new("OnDamageDealt", &ON_DAMAGE_DEALT_IMP);

/// Fires per player-target damage hit, AFTER the engine
/// applies the damage. Used by Evasion (pre-mutate via binder)
/// and Thorns (post-react). Same underlying hook as
/// [`OnDamageDealtTrigger`].
pub struct OnDamageTakenTrigger;
impl Trigger for OnDamageTakenTrigger {
    fn kind(&self) -> &'static str {
        "OnDamageTaken"
    }
}
static ON_DAMAGE_TAKEN_IMP: OnDamageTakenTrigger = OnDamageTakenTrigger;
pub static ON_DAMAGE_TAKEN: TriggerDef =
    TriggerDef::new("OnDamageTaken", &ON_DAMAGE_TAKEN_IMP);

/// Fires per confirmed creature kill (killing-blow flag set on
/// the damage multicast). Used by kill-credit driven skills.
/// Reuses the [`OnDamageDealtTrigger`] hook plumbing; the
/// dispatcher classifies + fires `TriggerCtx::Kill(&KillEvent)`.
pub struct OnKillTrigger;
impl Trigger for OnKillTrigger {
    fn kind(&self) -> &'static str {
        "OnKill"
    }
}
static ON_KILL_IMP: OnKillTrigger = OnKillTrigger;
pub static ON_KILL: TriggerDef = TriggerDef::new("OnKill", &ON_KILL_IMP);

/// Fires when the player's `OnLanded` UFunction fires. Used by
/// Fall Resistance + Impact Resistance. The underlying hook is
/// the framework `FallHook` (planned Phase 5c.4); the game crate
/// supplies player classes + velocity offsets and the framework
/// dispatcher fans out `TriggerCtx::Fall(&FallEvent)`.
pub struct OnFallTrigger;
impl Trigger for OnFallTrigger {
    fn kind(&self) -> &'static str {
        "OnFall"
    }
}
static ON_FALL_IMP: OnFallTrigger = OnFallTrigger;
pub static ON_FALL: TriggerDef = TriggerDef::new("OnFall", &ON_FALL_IMP);

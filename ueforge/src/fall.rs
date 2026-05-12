//! Generic player-fall hook framework. The "WHEN player lands"
//! seam every UE5 game with vertical traversal has.
//!
//! UE5 fires `ACharacter.OnLanded(FHitResult)` via ProcessEvent on
//! the player BP class just before the engine's native
//! `ApplyFallDamage` reads live `Velocity.Z` from the
//! `CharacterMovementComponent`. That ordering makes OnLanded the
//! one universal seam where a mod can:
//!
//! - **Observe** (fall telemetry, debug PE-queue drain).
//! - **Mutate Velocity.Z pre-application** (Fall Resistance:
//!   stomp `Velocity.Z` so the engine reads a smaller magnitude
//!   and applies less fall damage).
//! - **React post-application** (Impact Resistance: subtract the
//!   env-damage portion from the player HC after the engine's
//!   damage path runs).
//!
//! Class names + offsets vary per game; the pattern doesn't.
//! ueforge owns the PE hook install + OnLanded FName filter +
//! `Velocity.Z` snapshot + before/after dispatch; the game crate
//! supplies a [`FallHookConfig`] + a [`FallBinder`] impl.
//!
//! ```ignore
//! use ueforge::fall::{FallHook, FallHookConfig, FallBinder};
//! use ueforge::rpg::FallEvent;
//!
//! const G2_FALL: FallHookConfig = FallHookConfig {
//!     player_classes: &[
//!         "BP_SurvivalPlayerCharacter_C",
//!         "BP_SurvivalPlayerCharacter_Female02_C",
//!         "BP_SurvivalPlayerCharacter_Gellarde_C",
//!     ],
//!     on_landed_fn: "OnLanded",
//!     char_movement_component_offset: 0x1380,
//!     velocity_z_offset: 0x00E8, // absolute on CMC
//! };
//!
//! struct G2FallBinder;
//! impl FallBinder for G2FallBinder {
//!     fn before(&self, event: &FallEvent) {
//!         crate::tracker().fire(&ueforge::rpg::TriggerCtx::Fall(event));
//!     }
//! }
//!
//! static HOOK: FallHook<G2FallBinder> = FallHook::new(G2_FALL);
//!
//! // From `on_unreal_init`:
//! for h in HOOK.install(G2FallBinder)? { ueforge::hook::register(h); }
//! ```
//!
//! ### Forward semantics
//!
//! The trampoline ALWAYS forwards OnLanded to the engine's
//! original ProcessEvent. Binder `before` runs first (its writes
//! to `Velocity.Z` land before the engine reads them); binder
//! `after` runs once the engine's fall-damage application is
//! complete (impact-resistance reversal etc.).

use std::ffi::c_void;
use std::sync::OnceLock;

use crate::hook::{LazyFunctionPtr, OriginalProcessEvent, ProcessEventHook};
use crate::rpg::FallEvent;
use crate::ue::{TypedField, UFunction, UObject};

/// Per-game configuration for the player-fall hook.
#[derive(Debug, Clone, Copy)]
pub struct FallHookConfig {
    /// Player BP classes to install ProcessEvent hooks on. Each
    /// class is patched independently; classes not yet loaded
    /// are skipped at install time (see
    /// [`ProcessEventHook::install_many`]).
    pub player_classes: &'static [&'static str],
    /// UFunction name that fires on landing. UE5 default:
    /// `"OnLanded"`. The hook pointer-compares against the
    /// cached FunctionPtr per fire (zero-alloc filter).
    pub on_landed_fn: &'static str,
    /// Pawn-relative byte offset of the `*mut UMovementComponent`
    /// pointer to the player's `CharacterMovementComponent`.
    pub char_movement_component_offset: usize,
    /// Absolute byte offset of `FVector::Z` (f64) within the
    /// `CharacterMovementComponent` (typically
    /// `Velocity_offset + 0x10`).
    pub velocity_z_offset: usize,
}

/// Game-side knowledge the fall hook needs. Default impls let
/// games opt out of either side; the typical pattern is to fire
/// `tracker.fire(&TriggerCtx::Fall(event))` from `before` so
/// subscribed Effects (Fall Resistance via
/// [`crate::rpg::effect::FallVelocityStompEffect`], when shipped)
/// run with `Velocity.Z` still settable.
pub trait FallBinder: Send + Sync + 'static {
    /// Called BEFORE the engine's original ProcessEvent runs.
    /// `event.velocity_z_before` is the live `Velocity.Z`
    /// snapshot taken by the framework just before this call.
    fn before(&self, _event: &FallEvent) {}

    /// Called AFTER the engine's original ProcessEvent runs.
    /// Use for post-landing reactions (impact-resistance
    /// reversal, post-damage telemetry).
    fn after(&self, _event: &FallEvent) {}
}

/// Static player-fall hook. Construct with [`FallHook::new`],
/// install once at module init with [`install`](Self::install).
pub struct FallHook<B: FallBinder> {
    config: FallHookConfig,
    state: OnceLock<HookState<B>>,
    on_landed_ptr: LazyFunctionPtr,
}

struct HookState<B> {
    binder: B,
}

unsafe impl<B: FallBinder> Send for HookState<B> {}
unsafe impl<B: FallBinder> Sync for HookState<B> {}

impl<B: FallBinder> FallHook<B> {
    pub const fn new(config: FallHookConfig) -> Self {
        Self {
            config,
            state: OnceLock::new(),
            on_landed_ptr: LazyFunctionPtr::new(),
        }
    }

    pub fn config(&self) -> &FallHookConfig {
        &self.config
    }

    /// Install PE hooks on every player class in
    /// `config.player_classes`. Returns the per-class
    /// `ProcessEventHook` handles for the caller to register
    /// (so hot reload can shut them down cleanly).
    pub fn install(&'static self, binder: B) -> Result<Vec<ProcessEventHook>, &'static str> {
        if self.state.set(HookState { binder }).is_err() {
            return Err("FallHook: install called twice");
        }
        crate::log!(
            "fall: hooking {} on classes {:?}",
            self.config.on_landed_fn,
            self.config.player_classes
        );
        ProcessEventHook::install_many(self.config.player_classes, move |this, function, parms, original| {
            on_event(self, this, function, parms, original);
        })
    }
}

fn on_event<B: FallBinder>(
    hook: &FallHook<B>,
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let Some(state) = hook.state.get() else {
        unsafe { original.call(this, function, parms) };
        return;
    };

    // Fast path: identity-cached OnLanded check. One atomic
    // load + branch on warm path.
    if !hook.on_landed_ptr.matches(function, hook.config.on_landed_fn) {
        unsafe { original.call(this, function, parms) };
        return;
    }

    // Snapshot Velocity.Z before engine reads it.
    let cmc_field: TypedField<*mut UObject> =
        TypedField::at(hook.config.char_movement_component_offset);
    let vz_field: TypedField<f64> = TypedField::at(hook.config.velocity_z_offset);
    let velocity_z_before = unsafe {
        match cmc_field.deref(this) {
            Some(cmc) => vz_field.read(cmc),
            None => 0.0,
        }
    };

    let event = FallEvent {
        player: this,
        velocity_z_before,
    };

    state.binder.before(&event);

    unsafe { original.call(this, function, parms) };

    state.binder.after(&event);
}

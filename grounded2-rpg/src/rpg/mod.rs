// RPG / level-up subsystem.
//
// Spike A (DONE): kill detection. `kill_hook.rs` hooks HealthComponent's
// ProcessEvent slot, matches MulticastHandleEffectsWithDamageFlags, masks
// the DamageFlags parm with EDamageInfoFlags::KillingBlow, filters to
// ASurvivalCreature subclasses. On kill we have (dying actor, killer
// controller) reliably.
//
// Spike B (in progress): persistence. `save_slot.rs` reads the active
// playthrough's stable GUID from USaveLoadManager. `state.rs` defines
// the persisted shape and load/save against
// <DLL_dir>/saves/<guid>.json. `tracker.rs` is the live in-memory
// PlayerState that the kill hook bumps; flushes to disk after each
// change.

pub mod applier;
pub mod apply;
pub mod damage_trace;
pub mod fall_hook;
pub mod impact_resistance;
pub mod kill_hook;
pub mod save_slot;
pub mod skills;
pub mod tab;
pub mod tracker;
pub mod world_loader;
pub mod xp;

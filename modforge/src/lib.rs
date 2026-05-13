//! modforge: the engine-agnostic core shared by ueforge (UE5) and
//! unityforge (Unity Mono).
//!
//! Anything that does not touch UObject or Mono lives here once.
//! Both per-framework crates depend on `modforge = { path =
//! "../modforge" }` and call into it natively. There is no FFI:
//! both consumers are Rust.
//!
//! Submodules track the Phase 0 migration in
//! `docs/unityforge-plan.md`. As each ueforge file moves into
//! this crate it lands under the corresponding submodule with a
//! `pub use modforge::<mod>::*;` re-export left in ueforge so
//! existing call sites compile unchanged.

pub mod args;
pub mod counters;
pub mod envelope;
pub mod log;
pub mod ring;

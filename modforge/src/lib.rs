//! modforge: the engine-agnostic core shared by ueforge (UE5) and
//! unityforge (Unity Mono).
//!
//! Anything that does not touch UObject or Mono lives here once.
//! Both per-framework crates depend on `modforge = { path =
//! "../modforge" }` and call into it natively. There is no FFI:
//! both consumers are Rust.

pub mod args;
pub mod client;
pub mod counters;
pub mod debug;
pub mod envelope;
pub mod harness;
pub mod hot_reload;
pub mod log;
pub mod ops;
pub mod ring;
pub mod rpg;
pub mod scanner;
pub mod server;
pub mod settings;
pub mod shutdown;
pub mod snapshots;
pub mod ui;
pub mod winproc;
pub mod worker;

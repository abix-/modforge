//! uespy: base layer for every UE4SS Rust mod in this workspace.
//!
//! Three feature flags map to the three contexts a game crate
//! imports uespy from:
//!
//! - `runtime` (default) — runtime modules linked into the mod's
//!   cdylib: HTTP server, op envelope, queue, hook framework, UE
//!   SDK, UI bindings, mod entry-point macro, Win32 process probes,
//!   logger, etc.
//! - `client` — test-side wrapper. `[dev-dependencies]` activates
//!   `uespy::client::Api<S>`.
//! - `build` — `[build-dependencies]` activates
//!   `uespy::build::CppShim` for compiling the C++ shim into the
//!   cdylib.
//!
//! A game's `Cargo.toml`:
//!
//! ```toml
//! [dependencies]
//! uespy = { path = "../uespy" }
//!
//! [build-dependencies]
//! uespy = { path = "../uespy", default-features = false, features = ["build"] }
//!
//! [dev-dependencies]
//! uespy = { path = "../uespy", features = ["client"] }
//! ```
//!
//! Operating principle: always change uespy first. Game-specific
//! code goes on top; if it might apply to other UE games, it
//! belongs in uespy.

// Always-on: type-only modules used by both server and client.
pub mod args;
pub mod envelope;
pub mod hex;
pub mod parms;

// Runtime (cdylib).
#[cfg(feature = "runtime")]
pub mod counters;
#[cfg(feature = "runtime")]
pub mod hook;
#[cfg(feature = "runtime")]
pub mod log;
#[cfg(feature = "runtime")]
pub mod mod_main;
#[cfg(feature = "runtime")]
pub mod ops;
#[cfg(feature = "runtime")]
pub mod pe_queue;
#[cfg(feature = "runtime")]
pub mod ring;
#[cfg(feature = "runtime")]
pub mod selector;
#[cfg(feature = "runtime")]
pub mod server;
#[cfg(feature = "runtime")]
pub mod ue;
#[cfg(feature = "runtime")]
pub mod ui;
#[cfg(feature = "runtime")]
pub mod winproc;

#[cfg(feature = "runtime")]
pub use mod_main::{ModInfo, Tab};

// Convenience re-exports kept at the crate root for backward
// compatibility with mods written before the feature split.
#[cfg(feature = "runtime")]
pub use envelope::{OpResponse, parse_request};
#[cfg(feature = "runtime")]
pub use pe_queue::{DrainStats, Queue};
#[cfg(feature = "runtime")]
pub use server::{Config, spawn};

// Test client.
#[cfg(feature = "client")]
pub mod client;

// Build helper. The module is named `build` but lives at
// uespy/src/build.rs — only compiled when the `build` feature is
// active (i.e. uespy is pulled via [build-dependencies]).
#[cfg(feature = "build")]
pub mod build;

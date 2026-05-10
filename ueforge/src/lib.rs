//! ueforge: base layer for every UE4SS Rust mod in this workspace.
//!
//! One crate, no feature flags. ueforge's own `build.rs` compiles
//! the always-safe C++ (imgui vendor + `ueforge_ui.cpp`) into a
//! static lib that cargo links into every consumer of the crate
//! — cdylib, test binaries, the game's build-script binary alike.
//!
//! Mods that want the shipped UE4SS factory (`start_mod` /
//! `uninstall_mod` / `DllMain` + the `UespyMod` CppUserModBase
//! subclass) call [`build::CppShim::new`]`.compile()` from their
//! own `build.rs`. Mods with their own shim (grounded2-rpg
//! today) chain `.skip_default_shim()`.
//!
//! Operating principle: always change ueforge first. Game-specific
//! code goes on top; if it might apply to other UE games, it
//! belongs here.

pub mod args;
pub mod build;
pub mod client;
pub mod counters;
pub mod envelope;
pub mod hex;
pub mod hook;
pub mod log;
pub mod mod_main;
pub mod ops;
pub mod parms;
pub mod pe_queue;
pub mod rpg;
pub mod ring;
pub mod scanner;
pub mod selector;
pub mod server;
pub mod settings;
pub mod ue;
pub mod ui;
pub mod ui_scanner;
pub mod winproc;
pub mod worker;

pub use envelope::{OpResponse, parse_request};
pub use mod_main::{ModInfo, Tab};
pub use pe_queue::{DrainStats, Queue};
pub use server::{Config, spawn};

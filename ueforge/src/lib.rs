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
//!
//! ## The three pillars
//!
//! ueforge ships opinionated framework modules for the three most
//! common UE5 mod patterns. A new game's mod picks from these
//! menus and writes only game-specific knobs:
//!
//! - **[`rpg`]** -- skill catalog + XP curve + bestiary +
//!   per-slot persistence + ImGui tab + the `StandardEffect`
//!   variant menu covering 9 of the 10 most common skill shapes.
//! - **[`stacks`]** -- inventory stack-size data-table tweak with
//!   captured-vanilla baseline, idempotent re-apply, multiplier
//!   atomic, and on-first-sight worker.
//! - **[`difficulty`]** -- game-difficulty CDO field tweak (drain
//!   rates, damage multipliers, regen rates, etc) with the same
//!   capture / multiplier / re-apply pattern.
//!
//! Each pillar wraps a low-level primitive
//! (`StandardEffect` / `FieldTweak<T>` / `ClassFieldTweak<T>`)
//! with the universal apply-loop + atomic-knob + status-counter
//! pattern, so the game crate doesn't re-implement any of it.

pub mod args;
pub mod build;
pub mod client;
pub mod counters;
pub mod debug;
pub mod difficulty;
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
pub mod stacks;
pub mod uasset;
pub mod ue;
pub mod ui;
pub mod ui_scanner;
pub mod winproc;
pub mod worker;

pub use envelope::{OpResponse, parse_request};
pub use mod_main::{ModInfo, Tab};
pub use pe_queue::{DrainStats, Queue};
pub use server::{Config, spawn};

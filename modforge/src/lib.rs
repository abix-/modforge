//! modforge: the engine-agnostic core shared by ueforge (UE5) and
//! unityforge (Unity Mono).
//!
//! Anything that does not touch UObject or Mono lives here once.
//! Both per-framework crates depend on `modforge = { path =
//! "../modforge" }` and call into it natively. There is no FFI:
//! both consumers are Rust.

pub mod actions;
pub mod actor;
pub mod ai_orders;
pub mod annex;
pub mod args;
pub mod biome;
pub mod brain;
pub mod buying;
pub mod client;
pub mod code_patch;
pub mod combat;
pub mod command;
pub mod counters;
pub mod crafting;
pub mod debug;
pub mod duel;
pub mod edge;
pub mod envelope;
pub mod faction;
pub mod fluid;
pub mod genome;
pub mod grid;
pub mod ground;
pub mod handoff;
pub mod harness;
pub mod hook;
pub mod hot_reload;
pub mod hud;
pub mod inject;
pub mod input;
pub mod item;
pub mod learn;
pub mod log;
pub mod loot;
pub mod main_thread_queue;
pub mod map;
pub mod mcp;
pub mod memory;
pub mod memory_research;
pub mod mission;
pub mod monument;
pub mod msvc_std;
pub mod ops;
#[cfg(windows)]
pub mod overlay;
pub mod path;
pub mod patterns;
pub mod persona;
pub mod placement;
pub mod places;
pub mod process_memory;
pub mod quality;
pub mod read_once;
pub mod reality;
pub mod relationship;
pub mod research;
pub mod ring;
pub mod roll;
pub mod route;
pub mod rpg;
pub mod scanner;
pub mod seh;
pub mod server;
pub mod settings;
pub mod shutdown;
pub mod snapshots;
pub mod statetree;
pub mod storm;
pub mod storyteller;
pub mod structure;
pub mod studs;
pub mod survival;
pub mod talk;
pub mod test_queue;
pub mod testkit;
pub mod trade;
pub mod ui;
pub mod unknown;
pub mod upgrade;
pub mod valid;
pub mod vanilla;
pub mod vendor;
pub mod walk;
pub mod winproc;
pub mod worker;
pub mod world2d;
pub mod worldgen;

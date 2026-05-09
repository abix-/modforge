//! uespy: embedded HTTP control plane for Unreal Engine mods.
//!
//! Migration in progress — code is moving in piece by piece from
//! `better-backpack/src/debug.rs`, with that crate as the canary.
//!
//! Currently extracted:
//! - HTTP server bootstrap (`server`)
//! - Op envelope types and request parser (`envelope`)
//! - JSON arg helpers (`args`)
//!
//! Still in `better-backpack`: PE-thread queue, generic primitives
//! (read_bytes / write_bytes / call / walk_class), UObject helpers.
//!
//! Design: ~/.claude/skills/runtime-control-http/SKILL.md

pub mod args;
pub mod counters;
pub mod envelope;
pub mod hex;
pub mod log;
pub mod ops;
pub mod pe_queue;
pub mod ring;
pub mod selector;
pub mod server;
pub mod ue;
pub mod winproc;

pub use envelope::{OpResponse, parse_request};
pub use pe_queue::{DrainStats, Queue};
pub use server::{Config, spawn};

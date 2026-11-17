//! godotforge: Godot framework. Peer of ueforge and unityforge.
//!
//! Game mods compile as Rust cdylibs and depend on this crate.
//! A small GDScript loader (`gdscript/loader.gd`) builds a
//! GDNativeLibrary for the mod's DLL at run time and adds a
//! `GodotForge` NativeScript node to the scene tree. That node's
//! `_process` drains modforge's main-thread queue, so every op that
//! touches Godot runs on the main thread.
//!
//! Engine-agnostic infrastructure (op envelope, registry, server,
//! main-thread queue) lives in modforge and is consumed natively.

pub mod mod_main;

#[cfg(feature = "godot3")]
pub mod godot3;

#[cfg(feature = "godot3")]
pub use gdnative;

#[cfg(feature = "godot4")]
pub mod godot4;

#[cfg(feature = "godot4")]
pub use godot;

pub use mod_main::ModDef;

//! Standalone Unreal UDP client. No game process or mod is required.

mod bits;
mod actors;
mod customization;
mod movement;
pub mod handshake;
pub mod identity;
pub mod login;
pub mod profile;

/// Observed from Abiotic's LAN handshake on 2026-09-12. Override after updates.
pub const NETWORK_VERSION: u32 = 2_047_383_495;

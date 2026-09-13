//! Standalone Unreal UDP client. No game process or mod is required.

/// Where client messages go. The standalone binary keeps stderr; the mod
/// points this at its own log file so session events and errors are kept.
static LOG_SINK: std::sync::OnceLock<fn(&str)> = std::sync::OnceLock::new();

/// Install the one message sink. Later calls are ignored.
pub fn set_log_sink(sink: fn(&str)) {
    let _ = LOG_SINK.set(sink);
}

#[doc(hidden)]
pub fn log_line(message: String) {
    match LOG_SINK.get() {
        Some(sink) => sink(&message),
        None => eprintln!("[abiotic-client] {message}"),
    }
}

/// Every client message goes through here.
#[macro_export]
macro_rules! log {
    ($($arg:tt)*) => { $crate::log_line(format!($($arg)*)) };
}

/// Per-packet chatter (every position update) is off unless asked for.
static VERBOSE: std::sync::atomic::AtomicBool = std::sync::atomic::AtomicBool::new(false);

pub fn set_verbose(on: bool) {
    VERBOSE.store(on, std::sync::atomic::Ordering::Relaxed);
}

#[doc(hidden)]
pub fn verbose() -> bool {
    VERBOSE.load(std::sync::atomic::Ordering::Relaxed)
}

/// A message written only when verbose logging is on.
#[macro_export]
macro_rules! log_verbose {
    ($($arg:tt)*) => { if $crate::verbose() { $crate::log_line(format!($($arg)*)) } };
}

mod bits;
mod actors;
mod customization;
mod movement;
pub mod handshake;
pub mod identity;
pub mod login;
pub mod levels;
pub mod collision;
pub mod location;
pub mod profile;
pub mod travel;

/// Observed from Abiotic's LAN handshake on 2026-09-12. Override after updates.
pub const NETWORK_VERSION: u32 = 2_047_383_495;

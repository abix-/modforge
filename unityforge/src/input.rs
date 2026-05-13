//! Per-keypress callback binding.
//!
//! The active C# shim polls every registered binding on every
//! Update tick and fires the Rust callback synchronously on the
//! Unity main thread. Backend-agnostic: works on both Mono and
//! IL2CPP through the v3+ bridge.
//!
//! ```ignore
//! extern "C" fn on_space() {
//!     // runs on Unity main thread; safe to call bridge ops
//!     unityforge::mono::log(
//!         unityforge::mono::LogLevel::Info, "space pressed");
//! }
//!
//! unityforge::input::register_key_press(KeyCode::Space, on_space);
//! ```

use crate::bridge;

/// Unity `KeyCode` integer values. Subset; add more as needed.
/// Full enum: https://docs.unity3d.com/ScriptReference/KeyCode.html
#[repr(i32)]
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum KeyCode {
    Space = 32,
    Return = 13,
    Escape = 27,
    Tab = 9,
    LeftShift = 304,
    RightShift = 303,
    LeftControl = 306,
    RightControl = 305,
    LeftAlt = 308,
    RightAlt = 307,
    F1 = 282,
    F2 = 283,
    F3 = 284,
    F4 = 285,
    F5 = 286,
    F6 = 287,
    F7 = 288,
    F8 = 289,
    F9 = 290,
    F10 = 291,
    F11 = 292,
    F12 = 293,
    Insert = 277,
    Delete = 127,
    Home = 278,
    End = 279,
    PageUp = 280,
    PageDown = 281,
    UpArrow = 273,
    DownArrow = 274,
    RightArrow = 275,
    LeftArrow = 276,
    A = 97,
    B = 98,
    C = 99,
    D = 100,
    E = 101,
    F = 102,
    G = 103,
    H = 104,
    I = 105,
    J = 106,
    K = 107,
    L = 108,
    M = 109,
    N = 110,
    O = 111,
    P = 112,
    Q = 113,
    R = 114,
    S = 115,
    T = 116,
    U = 117,
    V = 118,
    W = 119,
    X = 120,
    Y = 121,
    Z = 122,
    Alpha0 = 48,
    Alpha1 = 49,
    Alpha2 = 50,
    Alpha3 = 51,
    Alpha4 = 52,
    Alpha5 = 53,
    Alpha6 = 54,
    Alpha7 = 55,
    Alpha8 = 56,
    Alpha9 = 57,
}

/// Register a callback that fires on every fresh keypress (one
/// fire per press, same semantics as `Input.GetKeyDown`).
/// Returns a binding handle that can be passed to
/// [`unregister`]. Returns `None` if the bridge isn't
/// installed yet.
pub fn register_key_press(key: KeyCode, callback: extern "C" fn()) -> Option<i32> {
    let bridge = bridge::get()?;
    let handle = (bridge.register_key_binding)(key as i32, callback);
    if handle == 0 { None } else { Some(handle) }
}

/// Drop a key binding. Idempotent.
pub fn unregister(binding: i32) {
    let Some(bridge) = bridge::get() else { return };
    (bridge.unregister_key_binding)(binding);
}

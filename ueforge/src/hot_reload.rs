//! Background watcher that auto-triggers UE4SS's hot reload when
//! a new `main-new.dll` lands. The deploy flow becomes:
//!
//! 1. `cargo deploy install` → writes `main-new.dll` next to the
//!    running `main.dll`.
//! 2. Watcher (this module) notices the file appear, synthesizes
//!    Ctrl+R via `SendInput`.
//! 3. UE4SS's keybind handler picks up Ctrl+R → calls our
//!    `ueforge_mod_shutdown` → `finalize_hot_reload_swap` does the
//!    file rename → UE4SS reloads `main.dll` (now the new image).
//!
//! No manual key press, no `mv main-new.dll main.dll` by hand.
//!
//! ## Caveats
//!
//! - The synthesized Ctrl+R reaches the foreground window. If the
//!   game has focus (typical while playing), UE4SS sees it and
//!   reloads. If focus is on a different window (browser, editor),
//!   that window gets the key instead -- the reload won't happen
//!   until next deploy or until the game has focus when the next
//!   poll cycle runs.
//! - One reload per deploy. After we send Ctrl+R the watcher
//!   exits; the freshly-loaded image's `on_unreal_init` spawns a
//!   new watcher for the next deploy generation.

use std::path::PathBuf;
use std::thread;
use std::time::Duration;

const POLL_INTERVAL: Duration = Duration::from_millis(1500);
const HOTKEY_R_VK: u16 = 0x52; // VK_R
const HOTKEY_CTRL_VK: u16 = 0x11; // VK_CONTROL

/// Spawn the background watcher. No-op if `dll_dir()` is unresolved.
pub fn spawn_watcher() {
    let Some(dir) = crate::log::dll_dir() else {
        crate::log!("hot_reload: dll_dir unresolved; watcher not spawned");
        return;
    };
    let _ = thread::Builder::new()
        .name("ueforge-hot-reload".into())
        .spawn(move || run(dir));
}

fn run(dir: PathBuf) {
    let new_dll = dir.join("main-new.dll");
    crate::log!(
        "hot_reload: watching for {} (poll every {:?})",
        new_dll.display(),
        POLL_INTERVAL
    );
    loop {
        thread::sleep(POLL_INTERVAL);
        if !new_dll.is_file() {
            continue;
        }
        crate::log!(
            "hot_reload: main-new.dll detected; synthesizing Ctrl+R to trigger UE4SS reload"
        );
        synthesize_ctrl_r();
        // Exit. The new image's on_unreal_init re-spawns the
        // watcher for the next deploy cycle.
        return;
    }
}

/// Push Ctrl+R into the OS input queue. The foreground window
/// receives it; if that's the game, UE4SS's keybind hook fires
/// and reloads mods.
fn synthesize_ctrl_r() {
    use windows_sys::Win32::UI::Input::KeyboardAndMouse::{
        INPUT, INPUT_0, INPUT_KEYBOARD, KEYBDINPUT, KEYEVENTF_KEYUP, SendInput,
    };
    let mk = |vk: u16, flags: u32| INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: vk,
                wScan: 0,
                dwFlags: flags,
                time: 0,
                dwExtraInfo: 0,
            },
        },
    };
    let mut events = [
        mk(HOTKEY_CTRL_VK, 0),
        mk(HOTKEY_R_VK, 0),
        mk(HOTKEY_R_VK, KEYEVENTF_KEYUP),
        mk(HOTKEY_CTRL_VK, KEYEVENTF_KEYUP),
    ];
    unsafe {
        SendInput(
            events.len() as u32,
            events.as_mut_ptr(),
            std::mem::size_of::<INPUT>() as i32,
        );
    }
}

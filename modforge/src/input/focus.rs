//! Whether this process's game window has focus, told on every change
//! without polling: a thread waits on Windows' foreground event
//! (SetWinEventHook EVENT_SYSTEM_FOREGROUND, out of context, so its
//! callback runs on that thread's message loop).
//!
//! "The game window" is a top-level window of this process with a given
//! class (UnrealWindow for Unreal games), so another window in the same
//! process, such as UE4SS's mod window, counts as focus leaving the game.

use std::sync::atomic::{AtomicU8, AtomicU32, Ordering};
use std::thread::JoinHandle;

use parking_lot::Mutex;
use windows_sys::Win32::Foundation::HWND;
use windows_sys::Win32::UI::Accessibility::{HWINEVENTHOOK, SetWinEventHook, UnhookWinEvent};
use windows_sys::Win32::UI::WindowsAndMessaging::{
    DispatchMessageW, EVENT_SYSTEM_FOREGROUND, GA_ROOTOWNER, GetAncestor, GetClassNameW,
    GetForegroundWindow, GetMessageW, GetWindowTextW, GetWindowThreadProcessId, MSG,
    PostThreadMessageW, WINEVENT_OUTOFCONTEXT, WM_QUIT,
};

/// The window class and the handler of the one watcher.
static WATCH: Mutex<Option<(&'static str, fn(bool, &str))>> = Mutex::new(None);
/// 0 not focused, 1 focused, 2 not told yet.
static LAST: AtomicU8 = AtomicU8::new(2);
/// The watcher thread's id, for WM_QUIT.
static THREAD: AtomicU32 = AtomicU32::new(0);
static HANDLE: Mutex<Option<JoinHandle<()>>> = Mutex::new(None);

fn class_of(hwnd: HWND) -> String {
    let mut buf = [0u16; 64];
    // SAFETY: Windows writes at most buf.len() UTF-16 units into the live buffer.
    let n = unsafe { GetClassNameW(hwnd, buf.as_mut_ptr(), buf.len() as i32) };
    String::from_utf16_lossy(&buf[..n.max(0) as usize])
}

fn title_of(hwnd: HWND) -> String {
    let mut buf = [0u16; 64];
    // SAFETY: Windows writes at most buf.len() UTF-16 units into the live buffer.
    let n = unsafe { GetWindowTextW(hwnd, buf.as_mut_ptr(), buf.len() as i32) };
    String::from_utf16_lossy(&buf[..n.max(0) as usize])
}

fn pid_of(hwnd: HWND) -> u32 {
    let mut pid = 0;
    // SAFETY: any HWND value is accepted; writes only to the live local.
    unsafe { GetWindowThreadProcessId(hwnd, &mut pid) };
    pid
}

/// The window, or the window that owns it (a game's popup or menu
/// window), is this process's window of `class`.
fn is_game_window(hwnd: HWND, class: &str) -> bool {
    if hwnd.is_null() || pid_of(hwnd) != std::process::id() {
        return false;
    }
    // SAFETY: any HWND value is accepted.
    let root = unsafe { GetAncestor(hwnd, GA_ROOTOWNER) };
    class_of(hwnd) == class || (!root.is_null() && class_of(root) == class)
}

/// Tell the handler when the state changed, with the foreground
/// window's class, title and process.
///
/// The event's window is not trusted: Windows also sends the event for
/// short-lived windows already gone by the time it arrives (no class,
/// process 0), right after the game took focus (Wicked Island,
/// 2026-11-22), which left the game told it had lost focus while it had
/// it. So the window is the one in the foreground now, and an event with
/// none, or with a window already gone, changes nothing.
fn report(_event_window: HWND) {
    let Some((class, f)) = *WATCH.lock() else {
        return;
    };
    // SAFETY: no arguments.
    let hwnd = unsafe { GetForegroundWindow() };
    if hwnd.is_null() || pid_of(hwnd) == 0 {
        return;
    }
    let now = is_game_window(hwnd, class) as u8;
    if LAST.swap(now, Ordering::AcqRel) != now {
        let window = if hwnd.is_null() {
            "no window".to_string()
        } else {
            format!(
                "{} '{}' pid {}",
                class_of(hwnd),
                title_of(hwnd),
                pid_of(hwnd)
            )
        };
        let _ = std::panic::catch_unwind(|| f(now == 1, &window));
    }
}

unsafe extern "system" fn on_foreground(
    _hook: HWINEVENTHOOK,
    _event: u32,
    hwnd: HWND,
    _object: i32,
    _child: i32,
    _thread: u32,
    _time: u32,
) {
    report(hwnd);
}

/// Start telling `on_change` whether the window of class `window_class`
/// in this process is the foreground window: once now, then on each
/// change. One watcher per process; a second call replaces nothing and
/// returns an error.
pub fn watch(window_class: &'static str, on_change: fn(bool, &str)) -> Result<(), String> {
    let mut handle = HANDLE.lock();
    if handle.is_some() {
        return Err("focus watcher already running".into());
    }
    *WATCH.lock() = Some((window_class, on_change));
    LAST.store(2, Ordering::Release);
    let (tx, rx) = std::sync::mpsc::channel::<Result<(), String>>();
    let thread = std::thread::Builder::new()
        .name("modforge-focus".into())
        .spawn(move || {
            // SAFETY: an out-of-context hook with a 'static callback; it is
            // removed below before the thread ends.
            let hook = unsafe {
                SetWinEventHook(
                    EVENT_SYSTEM_FOREGROUND,
                    EVENT_SYSTEM_FOREGROUND,
                    std::ptr::null_mut(),
                    Some(on_foreground),
                    0,
                    0,
                    WINEVENT_OUTOFCONTEXT,
                )
            };
            if hook.is_null() {
                let _ = tx.send(Err("SetWinEventHook failed".into()));
                return;
            }
            // SAFETY: no arguments.
            THREAD.store(
                unsafe { windows_sys::Win32::System::Threading::GetCurrentThreadId() },
                Ordering::Release,
            );
            let _ = tx.send(Ok(()));
            // SAFETY: no arguments.
            report(unsafe { GetForegroundWindow() });
            // SAFETY: a zeroed MSG is a valid out buffer; the loop ends on
            // WM_QUIT (0) or an error (-1).
            unsafe {
                let mut msg: MSG = std::mem::zeroed();
                while GetMessageW(&mut msg, std::ptr::null_mut(), 0, 0) > 0 {
                    DispatchMessageW(&msg);
                }
                UnhookWinEvent(hook);
            }
        })
        .map_err(|e| format!("spawn focus thread: {e}"))?;
    match rx.recv() {
        Ok(Ok(())) => {
            *handle = Some(thread);
            Ok(())
        }
        Ok(Err(e)) => {
            let _ = thread.join();
            *WATCH.lock() = None;
            Err(e)
        }
        Err(e) => {
            *WATCH.lock() = None;
            Err(format!("focus thread: {e}"))
        }
    }
}

/// Stop the watcher and wait for its thread. Run before the DLL unloads.
pub fn stop() {
    let Some(t) = HANDLE.lock().take() else {
        return;
    };
    let id = THREAD.swap(0, Ordering::AcqRel);
    // SAFETY: posts to the watcher thread's own queue.
    unsafe { PostThreadMessageW(id, WM_QUIT, 0, 0) };
    let _ = t.join();
    *WATCH.lock() = None;
}

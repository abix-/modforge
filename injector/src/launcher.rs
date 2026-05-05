// Launches Grounded 2 if it isn't already running, then polls until the
// process appears.

use std::ffi::OsStr;
use std::os::windows::ffi::OsStrExt;
use std::path::Path;
use std::ptr;
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{Context, Result, bail};
use windows_sys::Win32::Foundation::CloseHandle;
use windows_sys::Win32::System::Threading::{
    CREATE_NEW_CONSOLE, CreateProcessW, PROCESS_INFORMATION, STARTUPINFOW,
};
use windows_sys::Win32::UI::Shell::ShellExecuteW;
use windows_sys::Win32::UI::WindowsAndMessaging::SW_SHOWNORMAL;

use crate::{config::Config, find_target_pid, log_line};

pub fn launch_and_wait(cfg: &Config) -> Result<(u32, &'static str)> {
    let launch = &cfg.launch;

    if launch.steam_app_id != 0 {
        let uri = format!("steam://rungameid/{}", launch.steam_app_id);
        log_line("[+] ", &format!("launching via Steam: {uri}"));
        if let Err(e) = shell_execute_open(&uri) {
            log_line(
                "[!] ",
                &format!("Steam launch failed ({e}); will try fallback if any"),
            );
        }
    }

    if !launch.fallback_exe.is_empty() {
        let path = Path::new(&launch.fallback_exe);
        if path.exists() && find_target_pid().is_none() {
            log_line(
                "[+] ",
                &format!("launching exe directly: {}", path.display()),
            );
            if let Err(e) = create_process(path) {
                log_line("[!] ", &format!("direct launch failed: {e}"));
            }
        }
    }

    poll_for_target(launch.poll_interval_ms, launch.poll_timeout_sec)
}

fn poll_for_target(interval_ms: u64, timeout_sec: u64) -> Result<(u32, &'static str)> {
    let deadline = Instant::now() + Duration::from_secs(timeout_sec);
    let mut announced = false;
    while Instant::now() < deadline {
        if let Some(found) = find_target_pid() {
            return Ok(found);
        }
        if !announced {
            log_line(
                "[+] ",
                &format!(
                    "waiting for game process (up to {}s)...",
                    timeout_sec
                ),
            );
            announced = true;
        }
        thread::sleep(Duration::from_millis(interval_ms));
    }
    bail!(
        "game did not appear within {}s. Either the launch failed or the \
         load took too long. Bump poll_timeout_sec in inject.json.",
        timeout_sec
    )
}

fn shell_execute_open(arg: &str) -> Result<()> {
    let verb = wide("open");
    let target = wide(arg);
    let h = unsafe {
        ShellExecuteW(
            ptr::null_mut(),
            verb.as_ptr(),
            target.as_ptr(),
            ptr::null(),
            ptr::null(),
            SW_SHOWNORMAL,
        )
    };
    // ShellExecuteW returns an HINSTANCE; values <=32 indicate error.
    if (h as isize) <= 32 {
        bail!("ShellExecuteW returned {}", h as isize);
    }
    Ok(())
}

fn create_process(path: &Path) -> Result<()> {
    let mut cmdline = wide(&path.to_string_lossy());
    let mut si: STARTUPINFOW = unsafe { std::mem::zeroed() };
    si.cb = std::mem::size_of::<STARTUPINFOW>() as u32;
    let mut pi: PROCESS_INFORMATION = unsafe { std::mem::zeroed() };

    let ok = unsafe {
        CreateProcessW(
            ptr::null(),
            cmdline.as_mut_ptr(),
            ptr::null(),
            ptr::null(),
            0,
            CREATE_NEW_CONSOLE,
            ptr::null(),
            ptr::null(),
            &si,
            &mut pi,
        )
    };
    if ok == 0 {
        return Err(anyhow::anyhow!("CreateProcessW failed"))
            .context(format!("path: {}", path.display()));
    }
    unsafe {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    Ok(())
}

fn wide(s: &str) -> Vec<u16> {
    OsStr::new(s).encode_wide().chain(std::iter::once(0)).collect()
}

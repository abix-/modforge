//! Mod metadata + entry-point wiring.
//!
//! Game crates declare a single `static MOD_INFO: ModInfo = ...`
//! and call [`ue4ss_mod!`] once at the crate root. The macro emits
//! every `extern "C"` hook the shipped `ueforge_shim.cpp` calls
//! (`ueforge_mod_get_name`, `ueforge_mod_get_tab_count`,
//! `ueforge_mod_render_tab`, `ueforge_mod_dll_attach`,
//! `ueforge_mod_unreal_init`, `ueforge_mod_shutdown`), wires `DllMain`
//! into `ueforge::log::set_dll_module`, and initializes the logger
//! on `on_unreal_init`.
//!
//! Game side, in full:
//!
//! ```ignore
//! static MOD_INFO: ueforge::ModInfo = ueforge::ModInfo {
//!     name: "OWS Tweaks",
//!     version: "0.1.0",
//!     log_file: "ows_outworld_station_tweaks.log",
//!     console_title: "OWS Tweaks",
//!     console: cfg!(feature = "console"),
//!     on_unreal_init: || { ows::start(); },
//!     on_shutdown: || { ows::stop(); },
//!     tabs: &[
//!         ueforge::Tab { name: "Tweaks", render: ows::render_tweaks },
//!         ueforge::Tab { name: "Debug",  render: ows::render_debug },
//!     ],
//! };
//!
//! ueforge::ue4ss_mod!(MOD_INFO);
//! ```
//!
//! No `cpp/`, no `build.rs` C++ wiring, no DllMain — ueforge ships
//! all of it.

/// Top-level mod metadata. The shipped C++ shim reads this through
/// the macro-emitted `extern "C"` hooks.
pub struct ModInfo {
    /// Display name (UTF-8). Becomes UE4SS `ModName`.
    pub name: &'static str,
    pub version: &'static str,
    /// File written to under `<DLL_dir>/<log_file>`. Pass an empty
    /// string to disable file logging.
    pub log_file: &'static str,
    pub console_title: &'static str,
    /// Whether to pop a console window via `AllocConsole` on init.
    /// Typically `cfg!(feature = "console")`.
    pub console: bool,
    /// Called once on UE4SS `on_unreal_init`. Heavy lifting goes
    /// here (PE hooks, debug server, worker thread spawn).
    pub on_unreal_init: fn(),
    /// Called once when UE4SS destructs the mod.
    pub on_shutdown: fn(),
    /// Tabs to register in UE4SS's debug overlay. Order is stable
    /// — the shipped shim trampolines dispatch by index.
    pub tabs: &'static [Tab],
}

pub struct Tab {
    pub name: &'static str,
    pub render: fn(),
}

/// Wire a `static ModInfo` into the shipped C++ shim. Emits the
/// full set of `extern "C"` hooks plus `DllMain`.
///
/// Call once at the crate root.
#[macro_export]
macro_rules! ue4ss_mod {
    ($mod_info:ident) => {
        const _: &$crate::mod_main::ModInfo = &$mod_info;

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_name(out_len: *mut usize) -> *const u8 {
            unsafe { *out_len = $mod_info.name.len(); }
            $mod_info.name.as_ptr()
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_version(out_len: *mut usize) -> *const u8 {
            unsafe { *out_len = $mod_info.version.len(); }
            $mod_info.version.as_ptr()
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_log_file(out_len: *mut usize) -> *const u8 {
            unsafe { *out_len = $mod_info.log_file.len(); }
            $mod_info.log_file.as_ptr()
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_console_title(out_len: *mut usize) -> *const u8 {
            unsafe { *out_len = $mod_info.console_title.len(); }
            $mod_info.console_title.as_ptr()
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_tab_count() -> u32 {
            $mod_info.tabs.len() as u32
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_get_tab_name(idx: u32, out_len: *mut usize) -> *const u8 {
            let i = idx as usize;
            if i >= $mod_info.tabs.len() {
                unsafe { *out_len = 0; }
                return ::std::ptr::null();
            }
            let s = $mod_info.tabs[i].name;
            unsafe { *out_len = s.len(); }
            s.as_ptr()
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_dll_attach(hmod: *mut ::std::ffi::c_void) {
            // Forward HMODULE into the logger's DLL-dir resolver.
            $crate::log::set_dll_module(hmod as _);
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_unreal_init() {
            // Initialize the logger on first unreal_init so its
            // open call lands on the same thread that prints the
            // first line.
            if !$mod_info.log_file.is_empty() {
                $crate::log::init($crate::log::Config {
                    file_name: $crate::mod_main::leak_cstr($mod_info.log_file),
                    console_title: $crate::mod_main::leak_cstr($mod_info.console_title),
                    console: $mod_info.console,
                });
            }
            ($mod_info.on_unreal_init)();
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_shutdown() {
            ($mod_info.on_shutdown)();
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn ueforge_mod_render_tab(idx: u32) {
            // Bridge our locally-linked imgui at UE4SS's context.
            // The extern call is declared at the macro use site
            // (the game crate's cdylib) so ueforge.rlib itself never
            // references ueforge_ui_enable_imgui — letting build
            // scripts and test binaries that depend on ueforge
            // link cleanly without ueforge_shim.cpp's UE4SS deps.
            unsafe extern "C" {
                fn ueforge_ui_enable_imgui();
            }
            unsafe { ueforge_ui_enable_imgui() };
            let i = idx as usize;
            if let Some(t) = $mod_info.tabs.get(i) {
                (t.render)();
            }
        }
    };
}

/// Helper used by the macro to convert `&'static str` to
/// `&'static str` with a guaranteed nul terminator for APIs that
/// require it. Today `ueforge::log::Config` takes `&'static str`,
/// not nul-terminated; this is a no-op kept for forward-compat
/// with future C-string fields.
#[doc(hidden)]
pub const fn leak_cstr(s: &'static str) -> &'static str {
    s
}

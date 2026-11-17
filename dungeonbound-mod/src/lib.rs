//! Dungeonbound mod.
//!
//! Dungeonbound is Godot 4.7.1 and loads one GDExtension, GodotSteam,
//! from `libgodotsteam.windows.template_release.x86_64.dll` next to
//! the exe through its entry point `godotsteam_init`. This DLL is
//! deployed under that file name with the real GodotSteam renamed to
//! [`GODOTSTEAM_ORIGINAL`] beside it. Godot calls our
//! `godotsteam_init`; we call the real one, then godot-rust's, and
//! hand Godot one set of init callbacks that runs both.
//!
//! The control plane on 127.0.0.1:[`HTTP_PORT`]/op starts when the
//! main loop does. Ops that touch Godot queue onto
//! [`modforge::main_thread_queue::MAIN_QUEUE`], drained every frame.

use std::ffi::c_void;
use std::sync::OnceLock;
use std::time::Duration;

use godot::init::{ExtensionLibrary, InitStage, gdextension};
use godot::obj::Singleton;
use godot::sys;
use modforge::main_thread_queue::MAIN_QUEUE;
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

const HTTP_PORT: u16 = 31330;

/// The real GodotSteam, renamed by the deploy.
const GODOTSTEAM_ORIGINAL: &str = "libgodotsteam.windows.template_release.x86_64.original.dll";

/// Jobs drained per frame.
const TICK_BUDGET: usize = 32;

struct DungeonboundMod;

#[gdextension(entry_symbol = dungeonbound_gdext_init)]
unsafe impl ExtensionLibrary for DungeonboundMod {
    fn on_stage_init(stage: InitStage) {
        if stage == InitStage::MainLoop {
            start();
        }
    }

    fn on_main_loop_frame() {
        MAIN_QUEUE.drain(TICK_BUDGET);
    }

    fn on_stage_deinit(stage: InitStage) {
        if stage == InitStage::MainLoop {
            modforge::log!("dungeonbound-mod: main loop ending, shutting down");
            modforge::shutdown::SHUTDOWN_REGISTRY.run_all();
        }
    }
}

fn start() {
    OP_REGISTRY.register(OpDef::new(
        "engine",
        "Godot version, frames drawn, and whether the op ran on the main thread",
        "",
        engine_op,
    ));
    modforge::server::serve_ops(HTTP_PORT, "dungeonbound-mod-http", |message| {
        modforge::log!("{message}")
    });
    modforge::log!("dungeonbound-mod: listening on 127.0.0.1:{HTTP_PORT}/op");
}

fn engine_op(_args: &Json) -> Result<Json, String> {
    MAIN_QUEUE.run("engine", Duration::from_secs(5), || {
        let engine = godot::classes::Engine::singleton();
        json!({
            "version": engine.get_version_info().to_string(),
            "frames_drawn": engine.get_frames_drawn(),
            "main_thread": godot::init::is_main_thread(),
        })
    })
}

// ---------------------------------------------------------------------
// Entry point Godot resolves in GodotSteam's file.

/// The two extensions' init callbacks, kept for the combined ones.
struct Inits {
    steam: Option<sys::GDExtensionInitialization>,
    ours: sys::GDExtensionInitialization,
}

// SAFETY: written once in `godotsteam_init` before Godot calls any
// callback, then only read, all on Godot's main thread. The raw
// userdata pointers are owned by the two extensions.
unsafe impl Send for Inits {}
// SAFETY: see Send.
unsafe impl Sync for Inits {}

static INITS: OnceLock<Inits> = OnceLock::new();

/// # Safety
/// Called by Godot with the arguments of a GDExtension entry point.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn godotsteam_init(
    get_proc_address: sys::GDExtensionInterfaceGetProcAddress,
    library: sys::GDExtensionClassLibraryPtr,
    r_initialization: *mut sys::GDExtensionInitialization,
) -> sys::GDExtensionBool {
    set_log_module();
    modforge::log::init(modforge::log::Config {
        file_name: "dungeonbound-mod.log",
        console_title: "dungeonbound-mod",
        console: false,
    });
    modforge::log!("dungeonbound-mod: godotsteam_init");

    // SAFETY: same arguments Godot gave us, passed straight on.
    let steam = unsafe { init_godotsteam(get_proc_address, library) };

    let mut ours = empty_init();
    // SAFETY: Godot's own arguments; `ours` is a valid out pointer.
    let ok = unsafe { dungeonbound_gdext_init(get_proc_address, library, &mut ours) };
    if ok == 0 {
        modforge::log!("dungeonbound-mod: godot-rust init failed");
    }

    let minimum = match &steam {
        Some(s) => s
            .minimum_initialization_level
            .min(ours.minimum_initialization_level),
        None => ours.minimum_initialization_level,
    };
    if INITS.set(Inits { steam, ours }).is_err() {
        modforge::log!("dungeonbound-mod: godotsteam_init called twice");
        return 0;
    }
    // SAFETY: Godot passes a valid out pointer.
    unsafe {
        *r_initialization = sys::GDExtensionInitialization {
            minimum_initialization_level: minimum,
            userdata: std::ptr::null_mut(),
            initialize: Some(initialize),
            deinitialize: Some(deinitialize),
        };
    }
    1
}

/// Load the real GodotSteam beside this DLL and run its entry point.
/// None when it is missing or fails; the game then runs without Steam.
unsafe fn init_godotsteam(
    get_proc_address: sys::GDExtensionInterfaceGetProcAddress,
    library: sys::GDExtensionClassLibraryPtr,
) -> Option<sys::GDExtensionInitialization> {
    use windows_sys::Win32::System::LibraryLoader::{GetProcAddress, LoadLibraryW};

    let Some(dir) = modforge::log::dll_dir() else {
        modforge::log!("dungeonbound-mod: no dll dir, GodotSteam not loaded");
        return None;
    };
    let path = dir.join(GODOTSTEAM_ORIGINAL);
    let wide: Vec<u16> = std::os::windows::ffi::OsStrExt::encode_wide(path.as_os_str())
        .chain(std::iter::once(0))
        .collect();
    // SAFETY: NUL-terminated wide path.
    let module = unsafe { LoadLibraryW(wide.as_ptr()) };
    if module.is_null() {
        modforge::log!("dungeonbound-mod: LoadLibrary {} failed", path.display());
        return None;
    }
    // SAFETY: module is loaded; name is NUL-terminated.
    let Some(entry) = (unsafe { GetProcAddress(module, c"godotsteam_init".as_ptr().cast()) })
    else {
        modforge::log!(
            "dungeonbound-mod: {} has no godotsteam_init",
            path.display()
        );
        return None;
    };
    type Entry = unsafe extern "C" fn(
        sys::GDExtensionInterfaceGetProcAddress,
        sys::GDExtensionClassLibraryPtr,
        *mut sys::GDExtensionInitialization,
    ) -> sys::GDExtensionBool;
    // SAFETY: godotsteam_init is a GDExtension entry point; this is its
    // signature in gdextension_interface.h.
    let entry: Entry = unsafe { std::mem::transmute(entry) };
    let mut init = empty_init();
    // SAFETY: Godot's arguments and a valid out pointer.
    let ok = unsafe { entry(get_proc_address, library, &mut init) };
    if ok == 0 {
        modforge::log!("dungeonbound-mod: GodotSteam init returned false");
        return None;
    }
    modforge::log!(
        "dungeonbound-mod: GodotSteam loaded from {}",
        path.display()
    );
    Some(init)
}

fn empty_init() -> sys::GDExtensionInitialization {
    sys::GDExtensionInitialization {
        minimum_initialization_level: sys::GDEXTENSION_INITIALIZATION_CORE,
        userdata: std::ptr::null_mut(),
        initialize: None,
        deinitialize: None,
    }
}

unsafe extern "C" fn initialize(
    _userdata: *mut c_void,
    level: sys::GDExtensionInitializationLevel,
) {
    let Some(inits) = INITS.get() else { return };
    for init in inits.steam.iter().chain(std::iter::once(&inits.ours)) {
        if level >= init.minimum_initialization_level
            && let Some(f) = init.initialize
        {
            // SAFETY: the extension's own callback with its own userdata.
            unsafe { f(init.userdata, level) };
        }
    }
}

/// Reverse order: ours first, then GodotSteam.
unsafe extern "C" fn deinitialize(
    _userdata: *mut c_void,
    level: sys::GDExtensionInitializationLevel,
) {
    let Some(inits) = INITS.get() else { return };
    for init in std::iter::once(&inits.ours).chain(inits.steam.iter()) {
        if level >= init.minimum_initialization_level
            && let Some(f) = init.deinitialize
        {
            // SAFETY: the extension's own callback with its own userdata.
            unsafe { f(init.userdata, level) };
        }
    }
}

/// Point modforge's log at this DLL's folder (the game folder).
fn set_log_module() {
    use windows_sys::Win32::System::LibraryLoader::{
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        GetModuleHandleExW,
    };
    let mut module = std::ptr::null_mut();
    // SAFETY: the address is a function in this DLL; module is an out pointer.
    let ok = unsafe {
        GetModuleHandleExW(
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            set_log_module as *const () as *const u16,
            &mut module,
        )
    };
    if ok != 0 {
        modforge::log::set_dll_module(module as _);
    }
}

//! Standing in for a GDExtension the game already loads.
//!
//! Godot calls our export of the real extension's entry symbol. We
//! load the real extension (renamed beside us), call its entry, call
//! godot-rust's, and give Godot one init struct whose callbacks run
//! both: initialize in load order, deinitialize in reverse. Both
//! extensions share Godot's library pointer, so classes either one
//! registers belong to the one GDExtension Godot loaded.

use std::ffi::c_void;
use std::sync::OnceLock;

use godot::sys;

use crate::ModDef;

type Entry = unsafe extern "C" fn(
    sys::GDExtensionInterfaceGetProcAddress,
    sys::GDExtensionClassLibraryPtr,
    *mut sys::GDExtensionInitialization,
) -> sys::GDExtensionBool;

/// What the mod stands in for.
pub struct StandIn {
    /// File name of the real extension, beside this DLL.
    pub original: &'static str,
    /// The real extension's entry symbol, NUL-terminated.
    pub symbol: &'static str,
    /// godot-rust's entry point for this mod.
    pub ours: Entry,
}

/// The two extensions' init callbacks.
struct Inits {
    original: Option<sys::GDExtensionInitialization>,
    ours: sys::GDExtensionInitialization,
}

// SAFETY: written once in `stand_in` before Godot calls any callback,
// then only read, all on Godot's main thread. The userdata pointers
// belong to the two extensions.
unsafe impl Send for Inits {}
// SAFETY: see Send.
unsafe impl Sync for Inits {}

static INITS: OnceLock<Inits> = OnceLock::new();

/// The body of the exported entry point. See [`crate::godot4_mod`].
///
/// # Safety
/// Called with the arguments Godot passed to the entry point.
pub unsafe fn stand_in(
    def: &'static ModDef,
    stand_in: StandIn,
    get_proc_address: sys::GDExtensionInterfaceGetProcAddress,
    library: sys::GDExtensionClassLibraryPtr,
    r_initialization: *mut sys::GDExtensionInitialization,
) -> sys::GDExtensionBool {
    set_log_module();
    modforge::log::init(modforge::log::Config {
        file_name: def.log_file,
        console_title: def.name,
        console: false,
    });
    modforge::log!("{} {}: entry point", def.name, def.version);

    // SAFETY: Godot's arguments, passed on.
    let original = unsafe { init_original(&stand_in, get_proc_address, library) };

    let mut ours = empty_init();
    // SAFETY: Godot's arguments and a valid out pointer.
    if unsafe { (stand_in.ours)(get_proc_address, library, &mut ours) } == 0 {
        modforge::log!("{}: godot-rust init failed", def.name);
    }

    let minimum = match &original {
        Some(o) => o
            .minimum_initialization_level
            .min(ours.minimum_initialization_level),
        None => ours.minimum_initialization_level,
    };
    if INITS.set(Inits { original, ours }).is_err() {
        modforge::log!("{}: entry point called twice", def.name);
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

/// Load the real extension and run its entry. None when it is
/// missing or fails; the game then runs without it.
unsafe fn init_original(
    stand_in: &StandIn,
    get_proc_address: sys::GDExtensionInterfaceGetProcAddress,
    library: sys::GDExtensionClassLibraryPtr,
) -> Option<sys::GDExtensionInitialization> {
    use std::os::windows::ffi::OsStrExt;
    use windows_sys::Win32::System::LibraryLoader::{GetProcAddress, LoadLibraryW};

    let Some(dir) = modforge::log::dll_dir() else {
        modforge::log!("godotforge: no dll dir, {} not loaded", stand_in.original);
        return None;
    };
    let path = dir.join(stand_in.original);
    let wide: Vec<u16> = path
        .as_os_str()
        .encode_wide()
        .chain(std::iter::once(0))
        .collect();
    // SAFETY: NUL-terminated wide path.
    let module = unsafe { LoadLibraryW(wide.as_ptr()) };
    if module.is_null() {
        modforge::log!("godotforge: LoadLibrary {} failed", path.display());
        return None;
    }
    // SAFETY: module is loaded; the symbol is NUL-terminated.
    let Some(entry) = (unsafe { GetProcAddress(module, stand_in.symbol.as_ptr()) }) else {
        modforge::log!("godotforge: {} has no {}", path.display(), stand_in.symbol);
        return None;
    };
    // SAFETY: the symbol is a GDExtension entry point, whose signature
    // gdextension_interface.h fixes.
    let entry: Entry = unsafe { std::mem::transmute(entry) };
    let mut init = empty_init();
    // SAFETY: Godot's arguments and a valid out pointer.
    if unsafe { entry(get_proc_address, library, &mut init) } == 0 {
        modforge::log!("godotforge: {} entry returned false", path.display());
        return None;
    }
    modforge::log!("godotforge: started {}", path.display());
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
    for init in inits.original.iter().chain(std::iter::once(&inits.ours)) {
        if level >= init.minimum_initialization_level
            && let Some(f) = init.initialize
        {
            // SAFETY: the extension's own callback and userdata.
            unsafe { f(init.userdata, level) };
        }
    }
}

unsafe extern "C" fn deinitialize(
    _userdata: *mut c_void,
    level: sys::GDExtensionInitializationLevel,
) {
    let Some(inits) = INITS.get() else { return };
    for init in std::iter::once(&inits.ours).chain(inits.original.iter()) {
        if level >= init.minimum_initialization_level
            && let Some(f) = init.deinitialize
        {
            // SAFETY: the extension's own callback and userdata.
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
    // SAFETY: the address is a function in this DLL (godotforge is
    // linked into the mod's cdylib); module is an out pointer.
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

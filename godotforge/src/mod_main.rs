//! Mod entry: ModDef + the `godotforge_mod!` macro that emits the
//! GDNative entry points Godot resolves in the mod's DLL.

/// Per-game mod description. Each game mod declares one
/// `static MOD_INFO: godotforge::ModDef = ...;` and passes it to
/// the `godotforge_mod!` macro.
pub struct ModDef {
    /// Display name, surfaced in logs.
    pub name: &'static str,
    /// Version string ("0.1.0"). Empty for "unknown".
    pub version: &'static str,
    /// HTTP control port. Set 0 to disable.
    pub http_port: u16,
    /// Log file name, written beside the mod's DLL.
    pub log_file: &'static str,
    /// Fired once when the GodotForge node enters the tree, on the
    /// main thread. Register ops here.
    pub on_init: Option<fn()>,
    /// Fired every frame after the main-thread queue drain.
    pub on_tick: Option<fn(delta: f64)>,
    /// Fired when the GodotForge node leaves the tree, before the
    /// shutdown registry runs.
    pub on_shutdown: Option<fn()>,
}

/// Default per-frame job-drain budget.
pub const DEFAULT_TICK_BUDGET: usize = 32;

/// Emit the GDNative entry points for a Godot 3 mod.
///
/// `godot_gdnative_init`, `godot_nativescript_init` and
/// `godot_gdnative_terminate` come from gdnative's own
/// `godot_init!`; the init callback stores `$mod_info` and registers
/// the `GodotForge` class the loader instantiates.
#[cfg(feature = "godot3")]
#[macro_export]
macro_rules! godotforge_mod {
    ($mod_info:path) => {
        fn __godotforge_init(handle: $crate::gdnative::init::InitHandle) {
            $crate::godot3::install(&$mod_info, handle);
        }
        $crate::gdnative::init::godot_init!(__godotforge_init);
    };
}

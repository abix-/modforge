//! Godot 4 (GDExtension) mods.
//!
//! A Godot 4 game loads the GDExtensions its export lists, by file
//! name and entry symbol. A mod takes the file name of one the game
//! already loads (Dungeonbound: GodotSteam), loads the real one
//! renamed beside it, runs its entry point, then runs godot-rust's,
//! and hands Godot one set of init callbacks that runs both. See
//! [`chain`].
//!
//! The control plane starts when the main loop does. Every op that
//! touches Godot runs on the main thread through
//! [`modforge::main_thread_queue::MAIN_QUEUE`], drained every frame.
//!
//! Prior art for the ops: the Godot editor's remote scene tree and
//! remote inspector, which read a running game with the same calls
//! (`get_property_list`, `get`, `set`, `call`).
//!
//! # Panics are aborts
//!
//! The workspace's release profile aborts on panic, and godot-rust
//! reports many errors by panicking (`Variant::to`, `Object::call`,
//! `Array::at`). A panic in an op therefore closes the game. Use the
//! `try_` forms everywhere: `try_to`, `try_call`, `try_cast`,
//! `Gd::try_from_instance_id`, `get`.

pub mod chain;
pub mod files;
pub mod input;
pub mod ops;
pub mod target;
pub mod value;
pub mod watch;

use std::sync::OnceLock;
use std::sync::atomic::{AtomicU64, Ordering};
use std::time::{Duration, Instant};

use godot::init::InitStage;
use modforge::main_thread_queue::MAIN_QUEUE;

use crate::ModDef;

/// Per-frame job budget.
pub const TICK_BUDGET: usize = crate::mod_main::DEFAULT_TICK_BUDGET;

/// How long an op waits for the main thread.
pub const MAIN_TIMEOUT: Duration = Duration::from_secs(5);

static MOD: OnceLock<&'static ModDef> = OnceLock::new();

fn started_at() -> Instant {
    static START: OnceLock<Instant> = OnceLock::new();
    *START.get_or_init(Instant::now)
}

/// Nanoseconds since start at the last frame, for the frame delta.
static LAST_FRAME_NS: AtomicU64 = AtomicU64::new(0);

/// Called from the mod's `ExtensionLibrary::on_stage_init`.
pub fn on_stage_init(def: &'static ModDef, stage: InitStage) {
    if stage != InitStage::MainLoop {
        return;
    }
    let _ = MOD.set(def);
    ops::register_builtins();
    if let Some(on_init) = def.on_init {
        on_init();
    }
    if def.http_port != 0 {
        modforge::server::serve_ops(def.http_port, def.name, |message| {
            modforge::log!("{message}")
        });
        modforge::log!("{}: listening on 127.0.0.1:{}/op", def.name, def.http_port);
    }
}

/// Called from the mod's `ExtensionLibrary::on_main_loop_frame`.
pub fn on_frame() {
    MAIN_QUEUE.drain(TICK_BUDGET);
    let Some(def) = MOD.get() else { return };
    let Some(on_tick) = def.on_tick else { return };
    let now = started_at().elapsed().as_nanos() as u64;
    let last = LAST_FRAME_NS.swap(now, Ordering::Relaxed);
    on_tick(now.saturating_sub(last) as f64 / 1e9);
}

/// Called from the mod's `ExtensionLibrary::on_stage_deinit`.
pub fn on_stage_deinit(stage: InitStage) {
    if stage != InitStage::MainLoop {
        return;
    }
    if let Some(def) = MOD.get() {
        modforge::log!("{}: main loop ending, shutting down", def.name);
        if let Some(on_shutdown) = def.on_shutdown {
            on_shutdown();
        }
    }
    modforge::shutdown::SHUTDOWN_REGISTRY.run_all();
}

/// Run `f` on Godot's main thread and wait for its result.
pub fn on_main<T, F>(label: &str, f: F) -> Result<T, String>
where
    T: Send + 'static,
    F: FnOnce() -> Result<T, String> + Send + 'static,
{
    MAIN_QUEUE.run_result(label, MAIN_TIMEOUT, f)
}

/// Declare a Godot 4 mod that stands in for a GDExtension the game
/// already loads.
///
/// `stand_in` is the real extension's entry symbol, which this DLL
/// exports in its place. `original` is the file name the real
/// extension is renamed to, beside this DLL. The crate using this
/// must depend on `godot` directly: godot-rust's own macro names it.
///
/// ```ignore
/// godotforge::godot4_mod!(MOD_INFO,
///     stand_in: godotsteam_init,
///     original: "libgodotsteam.windows.template_release.x86_64.original.dll");
/// ```
#[macro_export]
macro_rules! godot4_mod {
    ($mod_info:path, stand_in: $symbol:ident, original: $original:expr) => {
        struct __GodotForgeExtension;

        #[::godot::init::gdextension(entry_symbol = __godotforge_gdext_init)]
        unsafe impl ::godot::init::ExtensionLibrary for __GodotForgeExtension {
            fn on_stage_init(stage: ::godot::init::InitStage) {
                $crate::godot4::on_stage_init(&$mod_info, stage);
            }

            fn on_main_loop_frame() {
                $crate::godot4::on_frame();
            }

            fn on_stage_deinit(stage: ::godot::init::InitStage) {
                $crate::godot4::on_stage_deinit(stage);
            }
        }

        /// # Safety
        /// Called by Godot with the arguments of a GDExtension entry point.
        #[unsafe(no_mangle)]
        pub unsafe extern "C" fn $symbol(
            get_proc_address: ::godot::sys::GDExtensionInterfaceGetProcAddress,
            library: ::godot::sys::GDExtensionClassLibraryPtr,
            r_initialization: *mut ::godot::sys::GDExtensionInitialization,
        ) -> ::godot::sys::GDExtensionBool {
            // SAFETY: Godot's own arguments, passed straight on.
            unsafe {
                $crate::godot4::chain::stand_in(
                    &$mod_info,
                    $crate::godot4::chain::StandIn {
                        original: $original,
                        symbol: concat!(stringify!($symbol), "\0"),
                        ours: __godotforge_gdext_init,
                    },
                    get_proc_address,
                    library,
                    r_initialization,
                )
            }
        }
    };
}

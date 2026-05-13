//! Mod entry: ModDef + the `unityforge_mod!` macro that emits
//! the `extern "C"` entry points the C# shim invokes.
//!
//! Each game mod declares one ModDef and invokes the macro. The
//! macro emits `unityforge_init`, `unityforge_tick`, and
//! `unityforge_shutdown` symbols that the shim resolves via
//! GetProcAddress.

/// Per-game mod description. Each game mod declares one
/// `static MOD_INFO: unityforge::ModDef = ...;` and passes it to
/// the `unityforge_mod!` macro.
pub struct ModDef {
    /// Display name, surfaced in logs.
    pub name: &'static str,
    /// Optional version string ("v0.1.0"). Empty for "unknown".
    pub version: &'static str,
    /// HTTP debug port. Set 0 to disable.
    pub http_port: u16,
    /// Optional callback fired once when the bridge installs.
    /// Use this to register hooks, ops, snapshot builders.
    pub on_init: Option<fn()>,
    /// Optional per-frame callback fired by the shim's Update.
    /// Runs AFTER the MainThreadQueue drain. Use this for
    /// poll-based work that needs the Unity main thread.
    pub on_tick: Option<fn(now: f32)>,
    /// Optional shutdown callback.
    pub on_shutdown: Option<fn()>,
    /// Declarative UI tabs. The render fn fires when the
    /// caller invokes the `render_tab` op or when the in-
    /// process ImGui pass (when bundled imgui lands) walks
    /// this list. Empty for mods that ship no UI.
    pub tabs: &'static [modforge::ui::TabDef],
}

/// Default per-frame job-drain budget. Override per mod by
/// pushing to MAIN_QUEUE.drain manually if needed.
pub const DEFAULT_TICK_BUDGET: usize = 32;

/// Emit the `extern "C"` entry points the C# shim calls.
///
/// The shim's contract:
/// - `unityforge_init(bridge: *const BridgeTable) -> i32`
///   Called once at plugin Awake. Returns 0 on success, non-zero
///   on failure (logged by shim; plugin then bails).
/// - `unityforge_tick(now: f32)`
///   Called every frame from the shim's MonoBehaviour.Update.
/// - `unityforge_shutdown()`
///   Called on plugin OnDestroy / process exit.
#[macro_export]
macro_rules! unityforge_mod {
    ($mod_info:path) => {
        #[unsafe(no_mangle)]
        pub extern "C" fn unityforge_init(bridge: *const $crate::bridge::BridgeTable) -> i32 {
            if bridge.is_null() {
                return -1;
            }
            // SAFETY: the shim guarantees the pointer is valid
            // for the duration of this call; we copy by value
            // into the OnceLock.
            let bridge = unsafe { &*bridge };
            if !$crate::bridge::install(bridge) {
                return -2;
            }
            $crate::mod_main::log_init_line(&$mod_info);
            if let Some(cb) = $mod_info.on_init {
                let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(cb));
            }
            $crate::mod_main::register_ui_ops(&$mod_info);
            if $mod_info.http_port != 0 {
                $crate::mod_main::start_http_server($mod_info.http_port);
            }
            0
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn unityforge_tick(now: f32) {
            $crate::main_thread_queue::MAIN_QUEUE
                .drain($crate::mod_main::DEFAULT_TICK_BUDGET);
            if let Some(cb) = $mod_info.on_tick {
                let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| cb(now)));
            }
        }

        #[unsafe(no_mangle)]
        pub extern "C" fn unityforge_shutdown() {
            if let Some(cb) = $mod_info.on_shutdown {
                let _ = std::panic::catch_unwind(std::panic::AssertUnwindSafe(cb));
            }
            $crate::hook::HOOK_REGISTRY.shutdown_all();
            modforge::shutdown::SHUTDOWN_REGISTRY.run_all();
        }
    };
}

/// Start the modforge HTTP listener on `127.0.0.1:<port>`,
/// dispatching every POST through `modforge::ops::OP_REGISTRY`.
/// Called by `unityforge_init` when ModDef::http_port is nonzero.
pub fn start_http_server(port: u16) {
    use modforge::envelope::{OpResponse, parse_request};
    use modforge::server::{Config, spawn};

    let cfg = Config {
        port,
        endpoint: "/op",
        thread_name: "unityforge-debug-http",
        auth_token: None,
    };

    spawn(
        cfg,
        |body| {
            let (op, args) = match parse_request(body) {
                Ok(v) => v,
                Err(e) => {
                    let r: OpResponse<serde_json::Value> =
                        OpResponse::err("<parse-error>", e, serde_json::json!({}));
                    return serde_json::to_vec(&r).unwrap_or_default();
                }
            };
            let result = modforge::ops::OP_REGISTRY
                .dispatch(&op, &args)
                .unwrap_or_else(|| Err(format!("unknown op '{op}'")));
            let r: OpResponse<serde_json::Value> =
                OpResponse::from_result(&op, result, serde_json::json!({}));
            serde_json::to_vec(&r).unwrap_or_default()
        },
        |msg| {
            crate::mono::log(crate::mono::LogLevel::Info, msg);
        },
    );
}

/// Register the declarative-UI ops against the workspace
/// [`modforge::ops::OP_REGISTRY`]. Called automatically from
/// `unityforge_init` after the mod's `on_init`.
///
/// Registers:
/// - `list_tabs`: returns `[ { name } ]` for each declared
///   tab.
/// - `render_tab`: invokes the named tab's `render` fn. The
///   render fn has a unit return type today (a fallback for
///   the in-process ImGui pass that hasn't shipped yet); the
///   op response is `{ "rendered": <name> }` for now.
pub fn register_ui_ops(mod_info: &'static ModDef) {
    use modforge::ops::{OP_REGISTRY, OpDef};
    use serde_json::{Value as Json, json};
    OP_REGISTRY.register(OpDef::new(
        "list_tabs",
        "List declarative UI tabs the mod ships",
        "{}",
        move |_args| {
            let arr: Vec<_> = mod_info
                .tabs
                .iter()
                .map(|t| json!({ "name": t.name }))
                .collect();
            Ok(Json::Array(arr))
        },
    ));
    OP_REGISTRY.register(OpDef::new(
        "render_tab",
        "Invoke the named tab's render fn",
        "{name: str}",
        move |args| {
            let name = args
                .get("name")
                .and_then(Json::as_str)
                .ok_or_else(|| "missing 'name'".to_string())?;
            for tab in mod_info.tabs.iter() {
                if tab.name == name {
                    (tab.render)();
                    return Ok(json!({"rendered": name}));
                }
            }
            Err(format!("unknown tab '{name}'"))
        },
    ));
}

/// Helper called by the macro. Lifted out so the macro body
/// stays small.
pub fn log_init_line(mod_info: &ModDef) {
    let ver = if mod_info.version.is_empty() {
        "?"
    } else {
        mod_info.version
    };
    crate::mono::log(
        crate::mono::LogLevel::Info,
        &format!("unityforge: init {} v{}", mod_info.name, ver),
    );
}

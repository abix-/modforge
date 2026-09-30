//! The Walking Trade mod. Rust cdylib loaded by Unityforge.Shim.Melon
//! (the MelonLoader entry) into the IL2CPP game.
//!
//! The framework's generic ops and Unity-side selectors for live
//! research on port 17181, plus the gameplay features listed in
//! docs/features.md.

use std::sync::atomic::{AtomicBool, Ordering};

use unityforge::ModDef;

mod barbed_wire;
mod cleaner_level;
mod craft_bench;
mod flee_return;
mod nav_snap;
mod no_death;
mod settings;
mod skill_repeat;
mod spiked_wall;
mod store_open;

static MOD_INFO: ModDef = ModDef {
    name: "TheWalkingTradeMod",
    version: "0.1.0",
    // 17181: 17172-17180 are held by the other modforge game mods.
    http_port: 17181,
    on_init: Some(on_init),
    on_tick: Some(on_tick),
    on_shutdown: None,
    tabs: &[],
};

unityforge::unityforge_mod!(MOD_INFO);

fn on_init() {
    unityforge::ops::register_builtins();
    unityforge::selector::register_builtins();

    flee_return::install();
    no_death::install();
    settings::install();
    skill_repeat::install();
    store_open::install();
    cleaner_level::install();
    barbed_wire::install();
    craft_bench::install();
    spiked_wall::install();
    nav_snap::install();
    match unityforge::hook::patch_postfix("Il2CppRuntime.Progression.Skills.Skill", "Load", after_skill_load) {
        Ok(h) => unityforge::hook::HOOK_REGISTRY.register(h),
        Err(e) => unityforge::mono::log(
            unityforge::mono::LogLevel::Error,
            &format!("thewalkingtrade-mod: patch Skill.Load FAILED: {e}"),
        ),
    }

    let kind = unityforge::unity::runtime_kind()
        .map(|k| format!("{k:?}"))
        .unwrap_or_else(|| "<unset>".to_string());
    unityforge::mono::log(
        unityforge::mono::LogLevel::Info,
        &format!("thewalkingtrade-mod: ready (runtime={kind})"),
    );
}

/// The context handle a Harmony prefix receives (patch_prefix_ctx);
/// the callback owns it. None when the context object was null.
pub(crate) fn ctx_object(ctx: *const std::ffi::c_void) -> Option<unityforge::mono::MonoObject> {
    let h = ctx as isize as i32;
    (h != 0).then(|| {
        unityforge::mono::MonoObject::from_owned_handle(unityforge::bridge::MonoHandle(h))
    })
}

/// Wall time of the previous frame, to count slow frames while
/// timing is on (timing_report "twt: frames ...").
static LAST_FRAME: std::sync::Mutex<Option<std::time::Instant>> = std::sync::Mutex::new(None);

fn count_frame() {
    if !modforge::counters::timing_on() {
        return;
    }
    let now = std::time::Instant::now();
    let Ok(mut last) = LAST_FRAME.lock() else { return };
    if let Some(prev) = last.replace(now) {
        let ms = now.duration_since(prev).as_secs_f64() * 1000.0;
        modforge::counters::tally("twt: frames", 1);
        if ms > 33.0 {
            modforge::counters::tally("twt: frames over 33 ms", 1);
        }
        if ms > 100.0 {
            modforge::counters::tally("twt: frames over 100 ms", 1);
        }
    }
}

/// Set by the `Skill.Load` postfix: a save has just loaded. Skill.Load
/// runs once per skill; the flag folds those into one apply.
static SAVE_LOADED: AtomicBool = AtomicBool::new(false);

extern "C" fn after_skill_load(_: *const std::ffi::c_void) {
    SAVE_LOADED.store(true, Ordering::Release);
}

/// Every frame, main thread: two flag loads unless something
/// happened. Nothing is searched on a timer (measured: a class
/// search costs about 45 ms).
fn on_tick(_now: f32) {
    count_frame();
    if SAVE_LOADED.swap(false, Ordering::Acquire) {
        let _m = modforge::counters::measure("twt: after load: skill repeat");
        skill_repeat::reapply();
    }
}

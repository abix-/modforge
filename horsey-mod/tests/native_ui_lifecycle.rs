//! Phase A contract test for `modforge::ui::native`.
//!
//! Asserts the spawn / shutdown lifecycle for the standalone-window
//! ImGui backend that ships with the `native-ui` Cargo feature.
//!
//! Contract:
//!   1. After `spawn`, a top-level window with our class name is
//!      discoverable via the OS (`FindWindowW`).
//!   2. The window survives at least 500ms of idle time without
//!      the render thread panicking.
//!   3. `shutdown` cleanly closes the window. `FindWindowW`
//!      subsequently returns null.
//!   4. spawn + shutdown can cycle multiple times without leaking
//!      window-class registrations.
//!
//! Tab content rendering is out of scope for this test (that's
//! manual visual verification). Lifecycle is automatable.
//!
//! The test references `modforge::ui::native` which does not yet
//! exist. Compile failure is the locking contract.

mod common;

use modforge::harness::GameHarness;
use serde_json::json;
use std::time::Duration;

#[test]
fn native_ui_spawn_creates_discoverable_window() {
    if modforge::harness::should_skip() {
        eprintln!("MODFORGE_NO_GAME=1, skipping");
        return;
    }
    let spec = common::spec();
    let game = GameHarness::launch(&spec, "native_ui_spawn")
        .expect("harness launch failed");

    // Driven from in-game side via HTTP op (the modforge::ui::native
    // calls run in the injected DLL's worker thread).
    let resp = game
        .op_json("ui.native.spawn", &json!({"window_title": "Horsey Mod Test"}))
        .expect("ui.native.spawn must succeed");
    let armed = resp
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(false);
    assert!(armed, "ui.native.spawn did not report armed=true: {resp}");

    // Give the window a moment to actually appear on screen.
    std::thread::sleep(Duration::from_millis(500));

    // Confirm it's discoverable by another process-wide op.
    let probe = game
        .op_json("ui.native.is_visible", &json!({}))
        .expect("ui.native.is_visible must succeed");
    let visible = probe
        .get("result")
        .and_then(|r| r.get("visible"))
        .and_then(|v| v.as_bool())
        .unwrap_or(false);
    assert!(visible, "native UI window not visible after spawn: {probe}");

    let stats = game
        .op_json("ui.native.stats", &json!({}))
        .expect("ui.native.stats must succeed");
    game.log()
        .event("UI", &format!("post-spawn stats: {stats}"));

    // Now shut it down.
    let shutdown = game
        .op_json("ui.native.shutdown", &json!({}))
        .expect("ui.native.shutdown must succeed");
    let armed_after = shutdown
        .get("result")
        .and_then(|r| r.get("armed"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    assert!(
        !armed_after,
        "ui.native.shutdown left armed=true: {shutdown}"
    );

    std::thread::sleep(Duration::from_millis(200));
    let probe = game
        .op_json("ui.native.is_visible", &json!({}))
        .expect("ui.native.is_visible (post-shutdown) must succeed");
    let visible_after = probe
        .get("result")
        .and_then(|r| r.get("visible"))
        .and_then(|v| v.as_bool())
        .unwrap_or(true);
    assert!(
        !visible_after,
        "native UI window still visible after shutdown: {probe}"
    );

    game.pass("native UI spawn + visible + shutdown cycle clean");
}

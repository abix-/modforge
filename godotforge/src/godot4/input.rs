//! Mouse, keys and input actions, fed to the game as real events.
//!
//! Events go through `Input.parse_input_event`, the same path the
//! OS's events take, so the game's GUI, `_input` and
//! `_unhandled_input` see them as the player's. Positions are window
//! pixels: the `window_rect` the `screen` op gives. A press and its
//! release are a frame or more apart, as a player's are.

use std::time::Duration;

use godot::builtin::{Rect2, StringName, Vector2};
use godot::classes::{
    CanvasItem, Input, InputEvent, InputEventAction, InputEventKey, InputEventMouseButton,
    InputEventMouseMotion, InputMap, Os,
};
use godot::global::{Key, MouseButton, MouseButtonMask};
use godot::obj::{Gd, NewGd, Singleton};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use super::{on_main, target};

/// Default time between press and release.
const DEFAULT_HOLD: Duration = Duration::from_millis(50);

pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "list_actions",
            "The game's input actions (InputMap) and the events bound to each",
            "{}",
            list_actions,
        ),
        OpDef::new(
            "move_mouse",
            "Move the game's mouse to window pixels, or to the middle of a node",
            "{x, y} | {id|node}",
            move_mouse,
        ),
        OpDef::new(
            "click",
            "Left click (or button: right, middle) at window pixels or the middle of a node: move, press, hold, release",
            "{x, y} | {id|node}, button?: str, hold_ms?: int",
            click,
        ),
        OpDef::new(
            "press_key",
            "Press and release a key by Godot's name for it (Escape, Space, A, F1)",
            "{key: str, hold_ms?: int}",
            press_key,
        ),
        OpDef::new(
            "press_action",
            "Press and release one of the game's input actions",
            "{action: str, hold_ms?: int}",
            press_action,
        ),
    ]);
}

fn hold(args: &Json) -> Duration {
    args.get("hold_ms")
        .and_then(Json::as_u64)
        .map_or(DEFAULT_HOLD, |ms| Duration::from_millis(ms.min(10_000)))
}

fn send(event: Gd<InputEvent>) {
    Input::singleton().parse_input_event(&event);
}

fn list_actions(_args: &Json) -> Result<Json, String> {
    on_main("list_actions", || {
        let mut map = InputMap::singleton();
        let rows: Vec<Json> = map
            .get_actions()
            .iter_shared()
            .map(|action| {
                let events: Vec<Json> = map
                    .action_get_events(&action)
                    .iter_shared()
                    .map(|e| json!(e.as_text().to_string()))
                    .collect();
                json!({"action": action.to_string(), "events": events})
            })
            .collect();
        Ok(json!({"actions": rows}))
    })
}

/// Window pixels from `{x, y}` or the middle of the target node.
/// Runs on the main thread.
fn point(args: &Json) -> Result<Vector2, String> {
    if let (Some(x), Some(y)) = (
        args.get("x").and_then(Json::as_f64),
        args.get("y").and_then(Json::as_f64),
    ) {
        return Ok(Vector2::new(x as f32, y as f32));
    }
    let item = target::object(args)?
        .try_cast::<CanvasItem>()
        .map_err(|_| "give x and y, or a 2D node".to_string())?;
    let node = item.clone().upcast::<godot::classes::Node>();
    let viewport = node.get_viewport().ok_or("node has no viewport")?;
    let xform = item.get_global_transform_with_canvas();
    let rect = if let Ok(control) = item.try_cast::<godot::classes::Control>() {
        xform * Rect2::new(Vector2::ZERO, control.get_size())
    } else {
        Rect2::new(xform.origin, Vector2::ZERO)
    };
    let window = viewport.get_screen_transform() * rect;
    Ok(window.center())
}

fn motion(at: Vector2) -> Gd<InputEvent> {
    let mut e = InputEventMouseMotion::new_gd();
    e.set_position(at);
    e.set_global_position(at);
    e.upcast()
}

fn button_event(at: Vector2, button: MouseButton, pressed: bool) -> Gd<InputEvent> {
    let mut e = InputEventMouseButton::new_gd();
    e.set_position(at);
    e.set_global_position(at);
    e.set_button_index(button);
    e.set_pressed(pressed);
    let mask = match (pressed, button) {
        (false, _) => MouseButtonMask::default(),
        (true, MouseButton::RIGHT) => MouseButtonMask::RIGHT,
        (true, MouseButton::MIDDLE) => MouseButtonMask::MIDDLE,
        (true, _) => MouseButtonMask::LEFT,
    };
    e.set_button_mask(mask);
    e.upcast()
}

fn move_mouse(args: &Json) -> Result<Json, String> {
    let args = args.clone();
    on_main("move_mouse", move || {
        let at = point(&args)?;
        send(motion(at));
        Ok(json!({"at": [at.x, at.y]}))
    })
}

fn click(args: &Json) -> Result<Json, String> {
    let button = match args.get("button").and_then(Json::as_str).unwrap_or("left") {
        "left" => MouseButton::LEFT,
        "right" => MouseButton::RIGHT,
        "middle" => MouseButton::MIDDLE,
        other => return Err(format!("unknown button {other}")),
    };
    let a = args.clone();
    let at = on_main("click press", move || {
        let at = point(&a)?;
        send(motion(at));
        send(button_event(at, button, true));
        Ok(at)
    })?;
    std::thread::sleep(hold(args));
    on_main("click release", move || {
        send(button_event(at, button, false));
        Ok(())
    })?;
    Ok(json!({"at": [at.x, at.y]}))
}

fn press_key(args: &Json) -> Result<Json, String> {
    let name = args
        .get("key")
        .and_then(Json::as_str)
        .ok_or("give key")?
        .to_string();
    let n = name.clone();
    let key = on_main("press_key", move || {
        let key = Os::singleton().find_keycode_from_string(n.as_str());
        if key == Key::NONE {
            return Err(format!("Godot has no key named {n}"));
        }
        send(key_event(key, true));
        Ok(key)
    })?;
    std::thread::sleep(hold(args));
    on_main("press_key release", move || {
        send(key_event(key, false));
        Ok(())
    })?;
    Ok(json!({"key": name}))
}

fn key_event(key: Key, pressed: bool) -> Gd<InputEvent> {
    let mut e = InputEventKey::new_gd();
    e.set_keycode(key);
    e.set_physical_keycode(key);
    e.set_pressed(pressed);
    e.upcast()
}

fn press_action(args: &Json) -> Result<Json, String> {
    let name = args
        .get("action")
        .and_then(Json::as_str)
        .ok_or("give action")?
        .to_string();
    let n = name.clone();
    on_main("press_action", move || {
        let action = StringName::from(n.as_str());
        if !InputMap::singleton().has_action(&action) {
            return Err(format!("the game has no action {n}"));
        }
        send(action_event(&action, true));
        Ok(())
    })?;
    std::thread::sleep(hold(args));
    let n = name.clone();
    on_main("press_action release", move || {
        send(action_event(&StringName::from(n.as_str()), false));
        Ok(())
    })?;
    Ok(json!({"action": name}))
}

fn action_event(action: &StringName, pressed: bool) -> Gd<InputEvent> {
    let mut e = InputEventAction::new_gd();
    e.set_action(action);
    e.set_pressed(pressed);
    e.set_strength(if pressed { 1.0 } else { 0.0 });
    e.upcast()
}

//! Selector grammar.
//!
//! Tests address objects in the running game by short strings:
//!
//! | form              | meaning                                    |
//! |-------------------|--------------------------------------------|
//! | `addr:0x...`      | raw object address (returned by `walk_class`) |
//! | `first_class:Foo` | first non-CDO instance of class `Foo`      |
//!
//! Game-specific shorthand (`live_player`, `current_save`, ...)
//! lives in the embedding crate. The pattern is: try `resolve_generic`
//! first, fall through to the game's resolver on `None`.

use crate::ue::{self, UObject};

/// Try to resolve a selector that's part of the generic vocabulary.
/// Returns `None` if the selector isn't one of the generic forms;
/// callers then dispatch to game-specific selectors.
pub fn resolve_generic(s: &str) -> Option<Result<&'static UObject, String>> {
    if let Some(rest) = s.strip_prefix("addr:0x").or_else(|| s.strip_prefix("addr:0X")) {
        return Some(resolve_addr(s, rest));
    }
    if let Some(name) = s.strip_prefix("first_class:") {
        return Some(resolve_first_class(name));
    }
    None
}

fn resolve_addr(orig: &str, hex: &str) -> Result<&'static UObject, String> {
    let addr =
        u64::from_str_radix(hex, 16).map_err(|e| format!("bad address '{orig}': {e}"))?;
    if addr == 0 {
        return Err("addr is null".to_string());
    }
    let p = addr as *const UObject;
    Ok(unsafe { &*p })
}

fn resolve_first_class(class_name: &str) -> Result<&'static UObject, String> {
    let rt = ue::try_runtime().ok_or("uespy: ue runtime not initialized")?;
    let class = ue::find_class_fast(class_name)
        .ok_or_else(|| format!("class '{class_name}' not found"))?;
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return Err("gobjects view invalid".to_string());
    }
    for obj in view.iter() {
        if obj.is_default_object() {
            continue;
        }
        if obj.is_a(class) {
            // SAFETY: while caller holds the resulting reference, GObjects
            // is stable as long as we're on the game thread (or quiescent
            // off-thread). Lifetime extension matches the rest of the SDK.
            let extended: &'static UObject =
                unsafe { std::mem::transmute::<&UObject, &'static UObject>(obj) };
            return Ok(extended);
        }
    }
    Err(format!("no instance of '{class_name}'"))
}

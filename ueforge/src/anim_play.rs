//! What a skeletal mesh plays now: its anim instance's active montage,
//! the position in it, and the AnimSequence and time that position falls
//! on (the montage's first slot track's segments). With anim_data.rs a
//! body's animation can then be read at any point of the montage.
//! Asked 2026-11-22: "ok lets add all the framework features needed"
//! (the full stroke).
//!
//! The segment fields are the engine's FAnimSegment (AnimReference,
//! StartPos, AnimStartTime, AnimEndTime, AnimPlayRate, LoopingCount), as
//! wickedisland-mod tests/research_parts.rs scene_capture reads them.

use serde_json::{Value, json};

use crate::ue::UObject;

/// A montage and where in it a body is.
pub struct Playing {
    pub montage: &'static UObject,
    /// Seconds into the montage.
    pub position: f32,
    /// The montage's length in seconds.
    pub length: f32,
}

fn call(o: &UObject, class: &str, function: &str, params: Value) -> Result<Value, String> {
    let params = params.as_object().cloned().unwrap_or_default();
    // SAFETY: callers are on the game thread with `o` live.
    unsafe { crate::reflect::call(o, class, function, &params) }
}

fn object(v: &Value) -> Option<&'static UObject> {
    crate::selector::resolve(&format!("addr:{}", v["addr"].as_str()?)).ok()
}

/// The montage skeletal mesh `mesh` plays now and its position. Game
/// thread.
pub fn playing(mesh: &UObject) -> Option<Playing> {
    let anim = object(
        &call(mesh, "SkeletalMeshComponent", "GetAnimInstance", json!({})).ok()?["ReturnValue"],
    )?;
    let montage = object(
        &call(anim, "AnimInstance", "GetCurrentActiveMontage", json!({})).ok()?["ReturnValue"],
    )?;
    let position = call(
        anim,
        "AnimInstance",
        "Montage_GetPosition",
        json!({"Montage": format!("0x{:X}", montage as *const UObject as usize)}),
    )
    .ok()?["ReturnValue"]
        .as_f64()? as f32;
    // SAFETY: game thread, montage live.
    let f = unsafe { crate::reflect::get_fields(montage, &["SequenceLength".to_owned()]) }.ok()?;
    let length = f["SequenceLength"].as_f64()? as f32;
    Some(Playing {
        montage,
        position,
        length,
    })
}

/// The AnimSequence and its time at `position` seconds into `montage`,
/// from the first slot track's segments. Game thread.
pub fn sequence_at(montage: &UObject, position: f32) -> Option<(&'static UObject, f32)> {
    // SAFETY: game thread, montage live.
    let f = unsafe { crate::reflect::get_fields(montage, &["SlotAnimTracks".to_owned()]) }.ok()?;
    let segments = f["SlotAnimTracks"][0]["AnimTrack"]["AnimSegments"].as_array()?;
    let num = |s: &Value, k: &str| s[k].as_f64().unwrap_or(0.0) as f32;
    for s in segments {
        let start = num(s, "StartPos");
        let (a, b) = (num(s, "AnimStartTime"), num(s, "AnimEndTime"));
        let rate = num(s, "AnimPlayRate").abs().max(1e-6);
        let loops = s["LoopingCount"].as_i64().unwrap_or(1).max(1) as f32;
        let span = b - a;
        if span <= 0.0 {
            continue;
        }
        let len = span / rate * loops;
        if position < start || position >= start + len {
            continue;
        }
        let local = ((position - start) * rate) % span;
        let time = if num(s, "AnimPlayRate") >= 0.0 {
            a + local
        } else {
            b - local
        };
        return Some((object(&s["AnimReference"])?, time));
    }
    None
}

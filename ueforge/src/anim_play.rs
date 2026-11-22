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

/// One segment of a montage's first slot track.
pub struct Segment {
    pub sequence: &'static UObject,
    /// Where it starts in the montage, seconds.
    pub start: f32,
    /// The part of the sequence it plays, seconds.
    pub anim_start: f32,
    pub anim_end: f32,
    /// Signed play rate.
    pub rate: f32,
    pub loops: u32,
}

impl Segment {
    fn len(&self) -> f32 {
        (self.anim_end - self.anim_start) / self.rate.abs().max(1e-6) * self.loops as f32
    }
}

/// The segments of `montage`'s first slot track. Game thread.
pub fn segments(montage: &UObject) -> Option<Vec<Segment>> {
    // SAFETY: game thread, montage live.
    let f = unsafe { crate::reflect::get_fields(montage, &["SlotAnimTracks".to_owned()]) }.ok()?;
    let list = f["SlotAnimTracks"][0]["AnimTrack"]["AnimSegments"].as_array()?;
    let num = |s: &Value, k: &str| s[k].as_f64().unwrap_or(0.0) as f32;
    Some(
        list.iter()
            .filter_map(|s| {
                Some(Segment {
                    sequence: object(&s["AnimReference"])?,
                    start: num(s, "StartPos"),
                    anim_start: num(s, "AnimStartTime"),
                    anim_end: num(s, "AnimEndTime"),
                    rate: num(s, "AnimPlayRate"),
                    loops: s["LoopingCount"].as_i64().unwrap_or(1).max(1) as u32,
                })
            })
            .filter(|s| s.anim_end > s.anim_start)
            .collect(),
    )
}

/// The AnimSequence and its time at `position` seconds into `montage`,
/// from the first slot track's segments. Game thread.
pub fn sequence_at(montage: &UObject, position: f32) -> Option<(&'static UObject, f32)> {
    for s in segments(montage)? {
        if position < s.start || position >= s.start + s.len() {
            continue;
        }
        let span = s.anim_end - s.anim_start;
        let local = ((position - s.start) * s.rate.abs().max(1e-6)) % span;
        let time = if s.rate >= 0.0 {
            s.anim_start + local
        } else {
            s.anim_end - local
        };
        return Some((s.sequence, time));
    }
    None
}

/// Where in `montage` the sequence `seq` is at `time` seconds into it:
/// the montage position, when one segment plays that time of it once
/// (None when no segment or several, or a looping one, do: each would be
/// a different montage time). Game thread.
pub fn position_of(montage: &UObject, seq: &UObject, time: f32) -> Option<f32> {
    let all: Vec<Segment> = segments(montage)?
        .into_iter()
        .filter(|s| std::ptr::eq(s.sequence, seq) && time >= s.anim_start && time <= s.anim_end)
        .collect();
    let [s] = all.as_slice() else { return None };
    if s.loops != 1 {
        return None;
    }
    let rate = s.rate.abs().max(1e-6);
    Some(if s.rate >= 0.0 {
        s.start + (time - s.anim_start) / rate
    } else {
        s.start + (s.anim_end - time) / rate
    })
}

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

fn anim_instance(mesh: &UObject) -> Option<&'static UObject> {
    object(&call(mesh, "SkeletalMeshComponent", "GetAnimInstance", json!({})).ok()?["ReturnValue"])
}

fn addr(o: &UObject) -> String {
    format!("0x{:X}", o as *const UObject as usize)
}

/// The play rate of the montage `mesh` plays (AnimInstance
/// Montage_GetPlayRate). Game thread.
pub fn play_rate(mesh: &UObject, montage: &UObject) -> Option<f32> {
    let anim = anim_instance(mesh)?;
    call(
        anim,
        "AnimInstance",
        "Montage_GetPlayRate",
        json!({"Montage": addr(montage)}),
    )
    .ok()?["ReturnValue"]
        .as_f64()
        .map(|r| r as f32)
}

/// Set the play rate of the montage `mesh` plays (AnimInstance
/// Montage_SetPlayRate). Game thread.
pub fn set_play_rate(mesh: &UObject, montage: &UObject, rate: f32) -> Result<(), String> {
    let anim = anim_instance(mesh).ok_or("no anim instance")?;
    call(
        anim,
        "AnimInstance",
        "Montage_SetPlayRate",
        json!({"Montage": addr(montage), "NewPlayRate": rate}),
    )
    .map(|_| ())
}

/// Every curve `mesh`'s anim instance holds now and its value
/// (AnimInstance GetAllCurveNames, GetCurveValue): what the animations
/// set this frame. Game thread. Asked 2026-11-22: "we need to be able to
/// do all all of the information about a scene so we can analyze it all
/// with simple, straightforward ops".
pub fn curves_now(mesh: &UObject) -> Result<Vec<(String, f32)>, String> {
    let anim = anim_instance(mesh).ok_or("no anim instance")?;
    let names = call(anim, "AnimInstance", "GetAllCurveNames", json!({}))?;
    let mut out = Vec::new();
    for n in names["OutNames"].as_array().into_iter().flatten() {
        let Some(n) = n.as_str() else { continue };
        let v = call(
            anim,
            "AnimInstance",
            "GetCurveValue",
            json!({"CurveName": n}),
        )?;
        out.push((
            n.to_string(),
            v["ReturnValue"].as_f64().unwrap_or(0.0) as f32,
        ));
    }
    Ok(out)
}

/// One animation an anim instance plays outside a montage: an asset
/// player node of its graph (a sequence or blend space player), or the
/// single node instance's asset.
pub struct Player {
    /// The node's field on the anim instance (CurrentAsset: the single
    /// node instance).
    pub node: String,
    pub asset: String,
    /// Seconds into the asset (InternalTimeAccumulator); None for the
    /// single node instance, which does not reflect it.
    pub time: Option<f64>,
    /// The node's weight in the graph (BlendWeight), as last updated: a
    /// node the graph no longer reaches keeps its last weight, so a time
    /// that does not move between two reads marks one not playing.
    pub weight: Option<f64>,
    pub rate: Option<f64>,
}

/// What `mesh`'s anim instance plays besides montages, from its
/// reflected fields: every field that is an asset player node (it has
/// InternalTimeAccumulator) with a weight above 0, with the asset it
/// plays (its Sequence or BlendSpace), and the single node instance's
/// CurrentAsset. Game thread. Asked 2026-11-22: "can you read the
/// animation with the ops??" (a Werebear scene with no montage on either
/// body).
pub fn players(mesh: &UObject) -> Result<(String, Vec<Player>), String> {
    let anim = anim_instance(mesh).ok_or("no anim instance")?;
    // SAFETY: game thread; anim is the mesh's live anim instance.
    let f = unsafe { crate::reflect::get_fields(anim, &[]) }?;
    let mut out = Vec::new();
    for (node, v) in f.as_object().into_iter().flatten() {
        if node == "CurrentAsset" {
            if let Some(a) = v["name"].as_str() {
                out.push(Player {
                    node: node.clone(),
                    asset: a.to_string(),
                    time: None,
                    weight: None,
                    rate: None,
                });
            }
            continue;
        }
        let Some(time) = v["InternalTimeAccumulator"].as_f64() else {
            continue;
        };
        let weight = v["BlendWeight"].as_f64();
        if weight.is_some_and(|w| w <= 0.0) {
            continue;
        }
        out.push(Player {
            node: node.clone(),
            asset: ["Sequence", "BlendSpace"]
                .iter()
                .find_map(|k| v[*k]["name"].as_str())
                .unwrap_or("")
                .to_string(),
            time: Some(time),
            weight,
            rate: v["PlayRate"].as_f64(),
        });
    }
    Ok((anim.full_name(), out))
}

/// The montage skeletal mesh `mesh` plays now and its position. Game
/// thread.
pub fn playing(mesh: &UObject) -> Option<Playing> {
    let anim = anim_instance(mesh)?;
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
    let all = segments(montage)?;
    let last = all.len().saturating_sub(1);
    for (i, s) in all.into_iter().enumerate() {
        // The montage's very end is the last segment's last frame.
        let end = s.start + s.len();
        if position < s.start || position > end || (position == end && i != last) {
            continue;
        }
        let span = s.anim_end - s.anim_start;
        let played = (position - s.start) * s.rate.abs().max(1e-6);
        let local = if played >= span * s.loops as f32 {
            span
        } else {
            played % span
        };
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
        .filter(|s| {
            std::ptr::eq(s.sequence, seq)
                && time >= s.anim_start - 1e-3
                && time <= s.anim_end + 1e-3
        })
        .collect();
    let [s] = all.as_slice() else { return None };
    if s.loops != 1 {
        return None;
    }
    // A sample time can miss the end by a float step.
    let time = time.clamp(s.anim_start, s.anim_end);
    let rate = s.rate.abs().max(1e-6);
    Some(if s.rate >= 0.0 {
        s.start + (time - s.anim_start) / rate
    } else {
        s.start + (s.anim_end - time) / rate
    })
}

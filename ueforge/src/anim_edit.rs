//! Rewrite a loaded animation in memory: decode every sample of an
//! AnimSequence (anim_data.rs), let the caller change the bones, encode
//! the result in the clip's own format, and point the engine's decoder at
//! the new data. The game then plays the changed animation itself, with
//! no work each frame. Undone by restore (and at shutdown). Asked
//! 2026-11-22: "shoudlnt we just FIX the animation? we decoded it", "we
//! need to be abe to rewrite the animoation. this needs to be supported
//! at framework", "lets do it", "identify the current scne's anmation and
//! change it".
//!
//! Prior art: UE's editor recompresses an edited animation through the
//! clip's codec; a shipped game has no editor, so the codecs' writers are
//! run here: ACL as UE's ACL plugin compresses (cpp/ueforge_acl.cpp
//! ueforge_acl_compress), and UE's own formats, the reverse of the
//! decoder ported from CUE4Parse: per track (anim_codec::encode_per_track)
//! and constant and variable key lerp (anim_codec::encode_key_lerp, in
//! the clip's own packing; asked 2026-11-22: "we need the framework to
//! support doing all the rewwites necessary").
//!
//! Where the engine reads the data (mine, from the engine's layout):
//! - ACL: UAnimSequence holds the bytes in a TArray (owned by the engine:
//!   never touched here) and a codec object with a TArrayView {data,
//!   int32 count} of them, which the codec decodes from. The buffer's
//!   address shows up once in the AnimSequence and once in an object it
//!   points to (wickedisland-mod tests/research_parts.rs anim_refs on
//!   Breath, 2026-11-22: offset 240 in it with count 0, and one outside
//!   with count 1776, the buffer's size). Only the view is repointed.
//! - UE's own codecs: the FUECompressedAnimData anim_data reads holds
//!   three TArrayViews: track offsets at 0x10, scale offsets at 0x20, the
//!   byte stream at 0x38. All three are repointed. The key format and the
//!   three packings at 0x60 stay: the engine picked its decoders (the
//!   three codec pointers before them) from them, so a key lerp clip is
//!   written in its own packing.
//!
//! New data is Rust's and never freed, as a worker thread may still read
//! it. Not proven: that a swap while worker threads animate cannot be
//! seen half done (the views are written one after another).
//!
//! Only non-additive clips. The rewrite is the animation alone: every
//! body that plays it gets it.
//!
//! Ops (register_ops): anim.refs, anim.shift (a test edit), anim.restore,
//! anim.edits.

use glam::{DQuat, DVec3};
use parking_lot::Mutex;
use serde_json::{Value, json};

use crate::anim_codec as codec;
use crate::anim_data::{Clip, Xform};
use crate::ue::UObject;

unsafe extern "C" {
    fn ueforge_acl_compress(
        raw: *const f32,
        reference: *const f32,
        parents: *const i32,
        num_tracks: u32,
        num_samples: u32,
        sample_rate: f32,
        out_size: *mut u32,
    ) -> *mut u8;
    fn ueforge_acl_free(buffer: *mut u8);
}

/// ACL's track type for bone transforms.
const QVVF: u32 = 12;
/// How far into an object the buffer's address is looked for.
const SCAN: usize = 0x100;
/// FUECompressedAnimData: the views and the key format (anim_data.rs
/// ue_clip).
const UE_OFFSETS: usize = 0x10;
const UE_SCALE_OFFSETS: usize = 0x20;
const UE_STREAM: usize = 0x38;
const UE_KEY_FORMAT: usize = 0x60;
/// How close the new data must read back to what was asked, in cm and
/// in quaternion dot.
const POS_TOLERANCE: f64 = 0.05;
const ROT_TOLERANCE: f64 = 0.9999;

/// A place that holds the ACL buffer's address.
#[derive(Clone, Copy, Debug)]
pub struct Ref {
    /// Address of the pointer.
    pub at: usize,
    /// In the AnimSequence itself (the engine's TArray), or in an object
    /// the AnimSequence points to (the codec's view).
    pub in_sequence: bool,
    /// The int32 count right after the pointer.
    pub count: i32,
}

/// One view written: where, what it held, what it holds now.
#[derive(Clone, Copy)]
struct Slot {
    at: usize,
    was: (usize, i32),
    now: (usize, i32),
}

/// One rewritten animation.
struct Edit {
    sequence: usize,
    name: String,
    format: &'static str,
    slots: Vec<Slot>,
}

static EDITS: Mutex<Vec<Edit>> = Mutex::new(Vec::new());
/// Every buffer ever put in, kept for the life of the process.
static KEPT: Mutex<Vec<Box<[u128]>>> = Mutex::new(Vec::new());

/// `bytes` copied into 16-byte aligned memory kept for the life of the
/// process; its address.
fn keep(bytes: &[u8]) -> usize {
    let mut b = vec![0u128; bytes.len().div_ceil(16).max(1)].into_boxed_slice();
    // SAFETY: `b` holds at least bytes.len() bytes.
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), b.as_mut_ptr() as *mut u8, bytes.len());
    }
    let at = b.as_ptr() as usize;
    KEPT.lock().push(b);
    at
}

fn read_slot(at: usize) -> Option<(usize, i32)> {
    Some((
        crate::anim_data::read::<usize>(at)?,
        crate::anim_data::read::<i32>(at + 8)?,
    ))
}

/// Write a view {data, int32 count}: the count, then the pointer.
///
/// # Safety
/// `at` is a live 8-byte aligned view slot.
unsafe fn write_slot(at: usize, (data, count): (usize, i32)) {
    // SAFETY: the caller's; an aligned pointer store is one write.
    unsafe {
        std::ptr::write_volatile((at + 8) as *mut i32, count);
        std::ptr::write_volatile(at as *mut usize, data);
    }
}

/// The bone data of `seq` as the engine plays it. anim_data::clip reads
/// an ACL clip from the sequence's own buffer, which a rewrite leaves as
/// the engine's (it points the codec's views at a new one), so a
/// rewritten ACL clip is read from the rewrite's buffer. UE format data
/// is read through the views already. Game thread.
pub fn played(seq: &UObject) -> Result<Clip, String> {
    let clip = crate::anim_data::clip(seq)?;
    let base = seq.as_ptr() as usize;
    let now = EDITS
        .lock()
        .iter()
        .find(|e| e.sequence == base && e.format != CURVES)
        .and_then(|e| e.slots.first().map(|s| s.now.0));
    Ok(match (now, clip.acl_buffer()) {
        (Some(b), Some(_)) => clip.with_acl_buffer(b),
        _ => clip,
    })
}

/// Every place in the AnimSequence, and in the objects it points to,
/// that holds the address of its ACL data. Game thread.
pub fn refs(seq: &UObject) -> Result<(Clip, Vec<Ref>), String> {
    let clip = crate::anim_data::clip(seq)?;
    let buffer = clip
        .acl_buffer()
        .ok_or_else(|| format!("{}: not ACL data", seq.name()))?;
    let base = seq.as_ptr() as usize;
    let size = match seq.class().map(|c| c.properties_size() as usize) {
        Some(s) if (0x30..0x10000).contains(&s) => s,
        _ => 0x200,
    };
    // A view this module put in points at its own buffer.
    let ours: Vec<usize> = EDITS
        .lock()
        .iter()
        .filter(|e| e.sequence == base)
        .flat_map(|e| e.slots.iter().map(|s| s.now.0).collect::<Vec<_>>())
        .collect();
    let mut out = Vec::new();
    let mut seen = Vec::new();
    for o in (0..size.saturating_sub(8)).step_by(8) {
        let Some(p) = crate::anim_data::read::<usize>(base + o) else {
            continue;
        };
        if p == buffer {
            out.push(Ref {
                at: base + o,
                in_sequence: true,
                count: crate::anim_data::read::<i32>(base + o + 8).unwrap_or(-1),
            });
            continue;
        }
        if p < 0x1_0000 || p == base || seen.contains(&p) || !crate::anim_data::readable(p, SCAN) {
            continue;
        }
        seen.push(p);
        for q in (0..SCAN - 8).step_by(8) {
            let Some(v) = crate::anim_data::read::<usize>(p + q) else {
                continue;
            };
            if v == buffer || ours.contains(&v) {
                out.push(Ref {
                    at: p + q,
                    in_sequence: false,
                    count: crate::anim_data::read::<i32>(p + q + 8).unwrap_or(-1),
                });
            }
        }
    }
    Ok((clip, out))
}

/// Every sample of the clip, each the local pose of every skeleton bone.
/// Game thread.
pub fn samples(clip: &Clip) -> Result<Vec<Vec<Xform>>, String> {
    (0..clip.samples).map(|i| clip.local_sample(i)).collect()
}

fn floats(x: &Xform) -> [f32; 10] {
    [
        x.rot.x as f32,
        x.rot.y as f32,
        x.rot.z as f32,
        x.rot.w as f32,
        x.pos.x as f32,
        x.pos.y as f32,
        x.pos.z as f32,
        x.scale.x as f32,
        x.scale.y as f32,
        x.scale.z as f32,
    ]
}

/// The ACL data for `poses` on `clip`'s tracks, rate and reference pose.
fn encode_acl(clip: &Clip, poses: &[Vec<Xform>]) -> Result<Vec<u8>, String> {
    let n = clip.tracks as usize;
    let s = poses.len();
    let mut raw = vec![0f32; n * s * 10];
    let mut reference = vec![0f32; n * 10];
    for (t, &b) in clip.track_bone.iter().enumerate() {
        let b = b as usize;
        reference[t * 10..t * 10 + 10].copy_from_slice(&floats(&clip.skeleton.reference[b]));
        for (i, pose) in poses.iter().enumerate() {
            raw[(t * s + i) * 10..(t * s + i) * 10 + 10].copy_from_slice(&floats(&pose[b]));
        }
    }
    // Each track's parent: the track of its nearest tracked ancestor.
    let mut track_of = vec![-1i32; clip.skeleton.parents.len()];
    for (t, &b) in clip.track_bone.iter().enumerate() {
        track_of[b as usize] = t as i32;
    }
    let parents: Vec<i32> = clip
        .track_bone
        .iter()
        .map(|&b| {
            let mut p = clip.skeleton.parents[b as usize];
            while p >= 0 && track_of[p as usize] < 0 {
                p = clip.skeleton.parents[p as usize];
            }
            if p < 0 { -1 } else { track_of[p as usize] }
        })
        .collect();
    let mut size = 0u32;
    // SAFETY: every array is sized for the counts passed.
    let out = unsafe {
        ueforge_acl_compress(
            raw.as_ptr(),
            reference.as_ptr(),
            parents.as_ptr(),
            clip.tracks,
            clip.samples,
            clip.rate,
            &mut size,
        )
    };
    if out.is_null() {
        return Err(match size {
            1 => "ACL compress: bad argument".into(),
            _ => "ACL compress failed".into(),
        });
    }
    // SAFETY: ACL's buffer is `size` bytes; freed right after the copy.
    let bytes = unsafe { std::slice::from_raw_parts(out, size as usize) }.to_vec();
    // SAFETY: from ueforge_acl_compress, freed once.
    unsafe { ueforge_acl_free(out) };
    Ok(bytes)
}

/// Whether `got` reads back as `want` on every tracked bone, within
/// `pos_tol` cm and quaternion dot `rot_tol`.
fn same(
    clip: &Clip,
    got: &[Xform],
    want: &[Xform],
    pos_tol: f64,
    rot_tol: f64,
) -> Result<(), String> {
    for &b in &clip.track_bone {
        let (g, w) = (&got[b as usize], &want[b as usize]);
        if (g.pos - w.pos).length() > pos_tol || g.rot.dot(w.rot).abs() < rot_tol {
            return Err(format!(
                "bone {} reads back {:?} {:?}, asked {:?} {:?}",
                clip.skeleton.bones[b as usize], g.pos, g.rot, w.pos, w.rot
            ));
        }
    }
    Ok(())
}

/// The views to write for ACL: the codec's view of the buffer.
fn acl_slots(seq: &UObject, clip: &Clip, poses: &[Vec<Xform>]) -> Result<Vec<Slot>, String> {
    let (_, refs) = refs(seq)?;
    let views: Vec<Ref> = refs.iter().filter(|r| !r.in_sequence).copied().collect();
    if views.is_empty() {
        return Err(format!(
            "{}: no view of the data found outside the AnimSequence ({} in it)",
            seq.name(),
            refs.len()
        ));
    }
    let bytes = encode_acl(clip, poses)?;
    let buffer = keep(&bytes);
    let h = crate::anim_data::acl_header(buffer).ok_or("ACL does not take the new data")?;
    if h.0 != clip.tracks || h.1 != clip.samples || h.4 != QVVF || h.5 == 0 {
        return Err(format!(
            "the new data reads as {} tracks, {} samples, type {}, default scale {}",
            h.0, h.1, h.4, h.5
        ));
    }
    Ok(views
        .iter()
        .map(|v| Slot {
            at: v.at,
            was: (crate::anim_data::read::<usize>(v.at).unwrap_or(0), v.count),
            now: (buffer, bytes.len() as i32),
        })
        .collect())
}

/// The views to write for UE's per track format, checked by decoding
/// the new data and comparing every sample. `was` is the clip before the
/// edit: a part with no data (the engine uses the bone's reference pose)
/// gets data only when the edit changed it.
fn ue_slots(clip: &Clip, was: &[Vec<Xform>], poses: &[Vec<Xform>]) -> Result<Vec<Slot>, String> {
    let p = clip.ue_data().ok_or("not UE data")?;
    let codes: Vec<u32> = (0..4)
        .map(|i| crate::anim_data::read::<u32>(p + UE_KEY_FORMAT + i * 4))
        .collect::<Option<_>>()
        .ok_or("key format")?;
    let key_format = codes[0];
    let per_track = key_format == codec::PER_TRACK;
    let offsets: Vec<i32> =
        crate::anim_data::view(p + UE_OFFSETS, 1 << 22).ok_or("track offsets")?;
    let scale_offsets: Vec<i32> =
        crate::anim_data::view(p + UE_SCALE_OFFSETS, 1 << 22).ok_or("scale offsets")?;
    let tracks = clip.tracks as usize;
    // Per track: two offsets a track, -1 for a part with no data. Key
    // lerp: an offset and a key count for each part, 0 keys for none.
    let per = if per_track { 2 } else { 4 };
    if offsets.len() != tracks * per {
        return Err(format!(
            "{} track offsets for {tracks} tracks",
            offsets.len()
        ));
    }
    let has_scale = !scale_offsets.is_empty();
    let (pos_has, rot_has, scale_has) = if per_track {
        (
            Box::new(|t: usize| offsets[t * 2] >= 0) as Box<dyn Fn(usize) -> bool>,
            Box::new(|t: usize| offsets[t * 2 + 1] >= 0) as Box<dyn Fn(usize) -> bool>,
            Box::new(|t: usize| scale_offsets.get(t).is_some_and(|&s| s >= 0))
                as Box<dyn Fn(usize) -> bool>,
        )
    } else {
        (
            Box::new(|t: usize| offsets[t * 4 + 1] > 0) as Box<dyn Fn(usize) -> bool>,
            Box::new(|t: usize| offsets[t * 4 + 3] > 0) as Box<dyn Fn(usize) -> bool>,
            Box::new(|t: usize| {
                scale_offsets
                    .get(t * 2..t * 2 + 2)
                    .is_some_and(|s| s[0] > 0 && s[1] > 0)
            }) as Box<dyn Fn(usize) -> bool>,
        )
    };
    // A part the clip has no data for keeps none unless the edit changed
    // it.
    let moved = |b: usize| {
        was.iter()
            .zip(poses)
            .any(|(a, q)| (a[b].pos - q[b].pos).length() > 1e-4)
    };
    let turned = |b: usize| {
        was.iter()
            .zip(poses)
            .any(|(a, q)| a[b].rot.dot(q[b].rot).abs() < 1.0 - 1e-7)
    };
    let sized = |b: usize| {
        was.iter()
            .zip(poses)
            .any(|(a, q)| (a[b].scale - q[b].scale).length() > 1e-5)
    };
    if !has_scale && let Some(&b) = clip.track_bone.iter().find(|&&b| sized(b as usize)) {
        return Err(format!(
            "{} was resized, but this clip keeps no scale data",
            clip.skeleton.bones[b as usize]
        ));
    }
    let keys: Vec<codec::TrackKeys> = clip
        .track_bone
        .iter()
        .enumerate()
        .map(|(t, &b)| {
            let b = b as usize;
            let pos = (pos_has(t) || moved(b))
                .then(|| poses.iter().map(|q| q[b].pos).collect::<Vec<DVec3>>());
            let rot = (rot_has(t) || turned(b))
                .then(|| poses.iter().map(|q| q[b].rot).collect::<Vec<DQuat>>());
            let scale = (has_scale && (scale_has(t) || sized(b)))
                .then(|| poses.iter().map(|q| q[b].scale).collect::<Vec<DVec3>>());
            codec::TrackKeys { pos, rot, scale }
        })
        .collect();
    // Per track is written in full floats; key lerp in the clip's own
    // packing (the engine's decoders were picked from it), so the check
    // allows what that packing can be off by.
    let (offsets_w, scale_w, stream_w, formats, pos_tol, rot_tol) = if per_track {
        let w = codec::encode_per_track(&keys, has_scale);
        (
            w.offsets,
            w.scale_offsets,
            w.stream,
            [0, 0, 0],
            POS_TOLERANCE,
            ROT_TOLERANCE,
        )
    } else {
        let f = codec::LerpFormats {
            key_format,
            translation: codes[1],
            rotation: codes[2],
            scale: codes[3],
        };
        let w = codec::encode_key_lerp(&keys, f, clip.samples, has_scale)?;
        (
            w.offsets,
            w.scale_offsets,
            w.stream,
            [codes[1], codes[2], codes[3]],
            POS_TOLERANCE.max(w.vec_step * 2.0),
            ROT_TOLERANCE.min(1.0 - 4.0 * w.rot_step * w.rot_step),
        )
    };
    let w = codec::Written {
        offsets: offsets_w,
        scale_offsets: scale_w,
        stream: stream_w,
    };
    // Read it back the way anim_data does and compare every sample.
    let d = codec::UeData {
        key_format,
        translation_format: formats[0],
        rotation_format: formats[1],
        scale_format: formats[2],
        num_frames: clip.samples,
        track_offsets: &w.offsets,
        scale_offsets: &w.scale_offsets,
        stream: &w.stream,
    };
    let back = codec::decode(&d, tracks, 1.0)?;
    for (i, want) in poses.iter().enumerate() {
        let rel = if clip.samples > 1 {
            i as f64 / f64::from(clip.samples - 1)
        } else {
            0.0
        };
        let mut got = want.clone();
        for (t, &b) in clip.track_bone.iter().enumerate() {
            let (rot, pos, scale) = back[t].sample(rel, clip.samples, false);
            got[b as usize] = Xform { rot, pos, scale };
        }
        same(clip, &got, want, pos_tol, rot_tol)
            .map_err(|e| format!("sample {i}: {e} (a part with no data was changed?)"))?;
    }
    let as_bytes = |v: &[i32]| v.iter().flat_map(|x| x.to_le_bytes()).collect::<Vec<u8>>();
    let mut slots = vec![
        Slot {
            at: p + UE_STREAM,
            was: read_slot(p + UE_STREAM).ok_or("stream view")?,
            now: (keep(&w.stream), w.stream.len() as i32),
        },
        Slot {
            at: p + UE_OFFSETS,
            was: read_slot(p + UE_OFFSETS).ok_or("offsets view")?,
            now: (keep(&as_bytes(&w.offsets)), w.offsets.len() as i32),
        },
    ];
    if has_scale {
        slots.push(Slot {
            at: p + UE_SCALE_OFFSETS,
            was: read_slot(p + UE_SCALE_OFFSETS).ok_or("scale offsets view")?,
            now: (
                keep(&as_bytes(&w.scale_offsets)),
                w.scale_offsets.len() as i32,
            ),
        });
    }
    Ok(slots)
}

/// Rewrite `seq`: `edit` gets the clip and every sample's local pose
/// (from the engine's own data, even when already rewritten) to change in
/// place; the result is encoded in the clip's format and the engine's
/// decoder pointed at it. Game thread. Returns a summary.
pub fn rewrite(
    seq: &UObject,
    edit: &mut dyn FnMut(&Clip, &mut [Vec<Xform>]) -> Result<(), String>,
) -> Result<Value, String> {
    let base = seq.as_ptr() as usize;
    // UE data is read through the views, so put the engine's back first.
    let was_edited = restore_where(base, false);
    let clip = crate::anim_data::clip(seq)?;
    if clip.additive {
        return Err(format!("{}: additive clips are not rewritten", seq.name()));
    }
    let mut poses = samples(&clip)?;
    let was = poses.clone();
    edit(&clip, &mut poses)?;
    let slots = match clip.ue_data() {
        Some(_) => ue_slots(&clip, &was, &poses)?,
        None => acl_slots(seq, &clip, &poses)?,
    };
    for s in &slots {
        // SAFETY: each slot is a view in the codec data, found and read
        // above on this game-thread call.
        unsafe { write_slot(s.at, s.now) };
    }
    let format = clip.format;
    let summary = json!({
        "sequence": seq.full_name(),
        "format": format,
        "samples": clip.samples,
        "tracks": clip.tracks,
        "again": was_edited,
        "views": slots.iter().map(|s| json!({
            "at": format!("0x{:X}", s.at),
            "was": [format!("0x{:X}", s.was.0), s.was.1],
            "now": [format!("0x{:X}", s.now.0), s.now.1],
        })).collect::<Vec<_>>(),
    });
    crate::log!(
        "anim_edit: {} rewritten ({format}, {} samples, {} tracks, {} views)",
        seq.name(),
        clip.samples,
        clip.tracks,
        slots.len()
    );
    EDITS.lock().push(Edit {
        sequence: base,
        name: seq.name(),
        format,
        slots,
    });
    Ok(summary)
}

/// The format of a curve rewrite, kept apart from the bones'.
const CURVES: &str = "curves";

/// Put the engine's own data back on the AnimSequence at `seq` (its
/// address), bones and curves. Returns whether it was rewritten.
pub fn restore(seq: usize) -> bool {
    let bones = restore_where(seq, false);
    restore_where(seq, true) || bones
}

/// Put back the bone rewrite (`curves` false) or the curve rewrite of
/// `seq`.
fn restore_where(seq: usize, curves: bool) -> bool {
    let e = {
        let mut all = EDITS.lock();
        let Some(i) = all
            .iter()
            .position(|e| e.sequence == seq && (e.format == CURVES) == curves)
        else {
            return false;
        };
        all.remove(i)
    };
    for s in e.slots.iter().rev() {
        // SAFETY: the slots rewrite() wrote; what they held is still the
        // engine's, untouched.
        unsafe { write_slot(s.at, s.was) };
    }
    crate::log!("anim_edit: {} {} restored", e.name, e.format);
    true
}

/// Rewrite the curves of a loaded AnimSequence: decode every sample
/// (`values[sample][curve]`, by curve index as `Curves::names` lists
/// them), let `edit` change them, encode them for the sequence's curve
/// codec (UE's ACL curve codec, or the compressed rich curve as linear
/// keys, rich_curve.rs), check every sample reads back within 0.005,
/// and put the new
/// buffer in the sequence's curve stream. The engine's buffer is kept
/// and put back by [`restore`]. A bone rewrite of the same sequence is
/// left as it is. Game thread.
///
/// `add` names curves the sequence lacks: they are added after its own
/// (0 at every sample until `edit` sets them), with a new curve name
/// table (anim_curves::name_table). A curve moves a morph only when the
/// skeleton's curve metadata marks it a morph target (UE 5.8
/// BoneContainer.cpp), so add names other animations of that skeleton
/// use. Asked 2026-11-22: "as we rewrite these animations we need to
/// add i whatever curvs/morphs we need".
pub fn rewrite_curves(
    seq: &UObject,
    add: &[&str],
    edit: &mut dyn FnMut(&crate::anim_curves::Curves, &mut [Vec<f32>]) -> Result<(), String>,
) -> Result<Value, String> {
    let base = seq.as_ptr() as usize;
    let was_edited = restore_where(base, true);
    let mut c = crate::anim_curves::curves(seq)?;
    let added: Vec<String> = add
        .iter()
        .filter(|a| !c.names.iter().any(|n| n == *a))
        .map(|a| a.to_string())
        .collect();
    c.names.extend(added.iter().cloned());
    if c.names.is_empty() {
        return Err(format!("{}: no curves", seq.name()));
    }
    if c.samples == 0 {
        return Err(format!("{}: no samples", seq.name()));
    }
    let mut values: Vec<Vec<f32>> = (0..c.samples)
        .map(|i| c.sample(i))
        .collect::<Result<_, _>>()?;
    edit(&c, &mut values)?;
    let bytes = crate::anim_curves::encode(&c, &values)?;
    let now = keep(&bytes);
    for (i, want) in values.iter().enumerate() {
        let got = crate::anim_curves::decode_sample(&c, now, bytes.len(), i as u32)?;
        if let Some((k, (a, b))) = want
            .iter()
            .zip(&got)
            .enumerate()
            .find(|(_, (a, b))| (*a - *b).abs() > 0.005)
        {
            return Err(format!(
                "{}: curve {} sample {i} reads back {b}, not {a}",
                seq.name(),
                c.names[k]
            ));
        }
    }
    let slot = Slot {
        at: c.array_at,
        was: c.stream(),
        now: (now, bytes.len() as i32),
    };
    let was_bytes = slot.was.1;
    // With curves added, the name table grows too. The order keeps every
    // read in bounds while the other half is still the old one: the ACL
    // codec writes one value per track into a table as long as the names,
    // so names first; the rich curve codec reads one descriptor per name
    // from the stream, so the stream first. restore undoes them in reverse.
    let mut slots = vec![slot];
    if !added.is_empty() {
        let table = crate::anim_curves::name_table(&c.names)?;
        let names = Slot {
            at: c.names_at,
            was: c.name_slot(),
            now: (keep(&table), c.names.len() as i32),
        };
        match c.codec {
            crate::anim_curves::Codec::Acl => slots.insert(0, names),
            crate::anim_curves::Codec::RichCurve => slots.push(names),
        }
    }
    for s in &slots {
        // SAFETY: the sequence's curve TArrays, found and read above on
        // this game-thread call.
        unsafe { write_slot(s.at, s.now) };
    }
    crate::log!(
        "anim_edit: {} curves rewritten ({} curves, {} added {:?}, {} samples, {} to {} bytes)",
        seq.name(),
        c.names.len(),
        added.len(),
        added,
        c.samples,
        was_bytes,
        bytes.len()
    );
    let summary = json!({
        "sequence": seq.full_name(),
        "format": CURVES,
        "curves": c.names,
        "samples": c.samples,
        "again": was_edited,
        "added": added,
        "bytes": [was_bytes, bytes.len()],
    });
    EDITS.lock().push(Edit {
        sequence: base,
        name: seq.name(),
        format: CURVES,
        slots,
    });
    Ok(summary)
}

/// Undo every rewrite (shutdown, hot reload).
pub fn restore_all() {
    let seqs: Vec<usize> = EDITS.lock().iter().map(|e| e.sequence).collect();
    for s in seqs {
        restore(s);
    }
}

/// Every rewrite in place.
pub fn edits() -> Value {
    json!(
        EDITS
            .lock()
            .iter()
            .map(|e| json!({
                "sequence": format!("0x{:X}", e.sequence),
                "name": e.name,
                "format": e.format,
                "views": e.slots.len(),
            }))
            .collect::<Vec<_>>()
    )
}

fn sequence(args: &Value) -> Result<&'static UObject, String> {
    if let Some(s) = args["sequence"].as_str() {
        return crate::selector::resolve(s);
    }
    crate::anim_data::find(
        args["name"]
            .as_str()
            .ok_or("sequence (selector) or name is required")?,
    )
}

fn refs_op(args: &Value) -> Result<Value, String> {
    let seq = sequence(args)?;
    let (clip, refs) = refs(seq)?;
    Ok(json!({
        "sequence": seq.full_name(),
        "buffer": format!("0x{:X}", clip.acl_buffer().unwrap_or(0)),
        "bytes": crate::anim_data::read::<u32>(clip.acl_buffer().unwrap_or(0)).unwrap_or(0),
        "refs": refs.iter().map(|r| json!({
            "at": format!("0x{:X}", r.at),
            "in_sequence": r.in_sequence,
            "offset": if r.in_sequence { r.at - seq.as_ptr() as usize } else { 0 },
            "count": r.count,
        })).collect::<Vec<_>>(),
    }))
}

/// A test edit: add `offset` to one bone's local translation at every
/// sample.
fn shift_op(args: &Value) -> Result<Value, String> {
    let seq = sequence(args)?;
    let bone = args["bone"].as_str().ok_or("bone is required")?.to_owned();
    let o = &args["offset"];
    let by = DVec3::new(
        o["X"].as_f64().unwrap_or(0.0),
        o["Y"].as_f64().unwrap_or(0.0),
        o["Z"].as_f64().unwrap_or(0.0),
    );
    rewrite(seq, &mut |clip, poses| {
        let b = clip
            .skeleton
            .bones
            .iter()
            .position(|n| *n == bone)
            .ok_or_else(|| format!("no bone {bone}"))?;
        for p in poses.iter_mut() {
            p[b].pos += by;
        }
        Ok(())
    })
}

fn restore_op(args: &Value) -> Result<Value, String> {
    if args["name"].is_null() && args["sequence"].is_null() {
        restore_all();
        return Ok(json!({"restored": "all"}));
    }
    let seq = sequence(args)?;
    Ok(json!({"restored": restore(seq.as_ptr() as usize)}))
}

/// The anim.* edit ops, on the game thread through `drain`.
pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    fn job(
        drain: &'static crate::pe_queue::GameThread,
        hint: &'static str,
        args: Value,
        f: fn(&Value) -> Result<Value, String>,
    ) -> Result<Value, String> {
        crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(20), hint, move || {
            f(&args)
        })
    }
    OP_REGISTRY.register_many([
        OpDef::new("anim.refs", "Where a loaded AnimSequence's ACL data address is held: in the AnimSequence (the engine's array) and in objects it points to (the codec's view). Read only", "{sequence?: selector, name?: str}", move |args| {
            job(drain, hint, args.clone(), refs_op)
        }),
        OpDef::new("anim.shift", "Test rewrite: add offset (cm) to one bone's local translation at every sample of a loaded AnimSequence, encode in the clip's format (ACL or UE per track) and point the engine's decoder at it", "{sequence?: selector, name?: str, bone: str, offset: {X,Y,Z}}", move |args| {
            job(drain, hint, args.clone(), shift_op)
        }),
        OpDef::new("anim.restore", "Put the engine's own data back on a rewritten AnimSequence, or on all with no name", "{sequence?: selector, name?: str}", move |args| {
            job(drain, hint, args.clone(), restore_op)
        }),
        OpDef::new("anim.edits", "Every rewritten AnimSequence", "{}", |_| Ok(edits())),
    ]);
    crate::shutdown::SHUTDOWN_REGISTRY.register(crate::shutdown::ShutdownHandlerDef {
        name: "anim_edit::restore_all",
        order: 50,
        run: restore_all,
    });
}

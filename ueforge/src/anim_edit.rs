//! Rewrite a loaded animation in memory: decode every sample of an
//! AnimSequence's ACL data (anim_data.rs), let the caller change the
//! bones, encode the result with ACL as UE's ACL plugin does, and point
//! the engine's decoder at the new data. The game then plays the changed
//! animation itself, with no work each frame. Undone by restore (and at
//! shutdown). Asked 2026-11-22: "shoudlnt we just FIX the animation? we
//! decoded it", "we need to be abe to rewrite the animoation. this needs
//! to be supported at framework", "lets do it".
//!
//! Prior art: UE's editor recompresses an edited animation through the
//! same codec (UAnimBoneCompressionCodec_ACLBase in nfrechette/
//! acl-ue4-plugin); a shipped game has no editor, so the codec's
//! compression is run here (cpp/ueforge_acl.cpp ueforge_acl_compress).
//!
//! Where the engine reads the data (mine, from the engine's layout, to be
//! proven live by wickedisland-mod tests/research_parts.rs anim_refs):
//! UAnimSequence holds FCompressedAnimSequence with the bytes in a TArray
//! (CompressedByteStream, owned by the engine: never touched here) and a
//! codec object (CompressedDataStructure, FACLCompressedAnimData) with a
//! TArrayView {data, int32 count} of the same bytes, which the ACL codec
//! decodes from. So the buffer's address shows up once in the
//! AnimSequence (the TArray) and once in an object it points to (the
//! view). Only views are repointed; the new buffer is Rust's and is never
//! freed, as a worker thread may still read it.
//!
//! Only non-additive ACL clips. The rewrite is the animation alone: every
//! body that plays it gets it.
//!
//! Ops (register_ops): anim.refs, anim.shift (a test edit), anim.restore,
//! anim.edits.

use parking_lot::Mutex;
use serde_json::{Value, json};

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

/// A place that holds the buffer's address.
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

/// One rewritten animation.
struct Edit {
    sequence: usize,
    name: String,
    /// The engine's own buffer and size, put back by restore.
    original: (usize, i32),
    /// The views repointed.
    views: Vec<usize>,
    buffer: usize,
    size: u32,
}

static EDITS: Mutex<Vec<Edit>> = Mutex::new(Vec::new());
/// Every buffer ever put in, kept for the life of the process.
static KEPT: Mutex<Vec<Box<[u128]>>> = Mutex::new(Vec::new());

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
    // A view this module put in points at its own buffer, not the
    // engine's.
    let ours: Option<usize> = EDITS
        .lock()
        .iter()
        .find(|e| e.sequence == base)
        .map(|e| e.buffer);
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
            let v = crate::anim_data::read::<usize>(p + q);
            if v == Some(buffer) || (v.is_some() && v == ours) {
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

/// The ACL data for `poses` (one local pose per sample, every skeleton
/// bone) on `clip`'s tracks, rate and reference pose, in 16-byte aligned
/// memory.
fn encode(clip: &Clip, poses: &[Vec<Xform>]) -> Result<(Box<[u128]>, u32), String> {
    let n = clip.tracks as usize;
    let s = poses.len();
    if s != clip.samples as usize {
        return Err(format!("{s} samples given, the clip has {}", clip.samples));
    }
    let mut raw = vec![0f32; n * s * 10];
    let mut reference = vec![0f32; n * 10];
    for (t, &b) in clip.track_bone.iter().enumerate() {
        let b = b as usize;
        reference[t * 10..t * 10 + 10].copy_from_slice(&floats(&clip.skeleton.reference[b]));
        for (i, pose) in poses.iter().enumerate() {
            let x = pose.get(b).ok_or("a pose is shorter than the skeleton")?;
            raw[(t * s + i) * 10..(t * s + i) * 10 + 10].copy_from_slice(&floats(x));
        }
    }
    // Each track's parent: the track of its nearest tracked ancestor.
    let bones = clip.skeleton.parents.len();
    let mut track_of = vec![-1i32; bones];
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
    let mut kept = vec![0u128; (size as usize).div_ceil(16)].into_boxed_slice();
    // SAFETY: ACL's buffer is `size` bytes; `kept` holds at least that.
    unsafe {
        std::ptr::copy_nonoverlapping(out, kept.as_mut_ptr() as *mut u8, size as usize);
        ueforge_acl_free(out);
    }
    Ok((kept, size))
}

/// Rewrite `seq`: `edit` gets the clip and every sample's local pose
/// (from the engine's own data, even when already rewritten) to change in
/// place; the result is encoded and the engine's decoder pointed at it.
/// Game thread. Returns a summary.
pub fn rewrite(
    seq: &UObject,
    edit: &mut dyn FnMut(&Clip, &mut [Vec<Xform>]) -> Result<(), String>,
) -> Result<Value, String> {
    let (clip, refs) = refs(seq)?;
    if clip.additive {
        return Err(format!("{}: additive clips are not rewritten", seq.name()));
    }
    let original = clip.acl_buffer().ok_or("not ACL data")?;
    let views: Vec<Ref> = refs.iter().filter(|r| !r.in_sequence).copied().collect();
    if views.is_empty() {
        return Err(format!(
            "{}: no view of the data found outside the AnimSequence ({} in it)",
            seq.name(),
            refs.len()
        ));
    }
    let mut poses = samples(&clip)?;
    edit(&clip, &mut poses)?;
    let (kept, size) = encode(&clip, &poses)?;
    let buffer = kept.as_ptr() as usize;
    // The new data must read back as the same clip.
    let h = crate::anim_data::acl_header(buffer).ok_or("ACL does not take the new data")?;
    if h.0 != clip.tracks || h.1 != clip.samples || h.4 != QVVF || h.5 == 0 {
        return Err(format!(
            "the new data reads as {} tracks, {} samples, type {}, default scale {}",
            h.0, h.1, h.4, h.5
        ));
    }
    let original_count = views[0].count;
    let base = seq.as_ptr() as usize;
    KEPT.lock().push(kept);
    for v in &views {
        // SAFETY: `at` is a pointer slot found holding the engine's (or
        // an earlier rewrite's) buffer address, 8-byte aligned, with its
        // int32 count after it; an aligned pointer store is one write.
        unsafe {
            std::ptr::write_volatile((v.at + 8) as *mut i32, size as i32);
            std::ptr::write_volatile(v.at as *mut usize, buffer);
        }
    }
    let mut all = EDITS.lock();
    let original = all
        .iter()
        .find(|e| e.sequence == base)
        .map(|e| e.original)
        .unwrap_or((original, original_count));
    all.retain(|e| e.sequence != base);
    all.push(Edit {
        sequence: base,
        name: seq.name(),
        original,
        views: views.iter().map(|v| v.at).collect(),
        buffer,
        size,
    });
    crate::log!(
        "anim_edit: {} rewritten ({} samples, {} tracks, {size} bytes, {} views)",
        seq.name(),
        clip.samples,
        clip.tracks,
        views.len()
    );
    Ok(json!({
        "sequence": seq.full_name(),
        "samples": clip.samples,
        "tracks": clip.tracks,
        "bytes": size,
        "original_bytes": original.1,
        "views": views.iter().map(|v| format!("0x{:X}", v.at)).collect::<Vec<_>>(),
    }))
}

/// Put the engine's own data back on the AnimSequence at `seq` (its
/// address). Returns whether it was rewritten.
pub fn restore(seq: usize) -> bool {
    let mut all = EDITS.lock();
    let Some(i) = all.iter().position(|e| e.sequence == seq) else {
        return false;
    };
    let e = all.remove(i);
    for &at in &e.views {
        // SAFETY: the slots rewrite() wrote; the engine's buffer is still
        // its TArray's, untouched.
        unsafe {
            std::ptr::write_volatile(at as *mut usize, e.original.0);
            std::ptr::write_volatile((at + 8) as *mut i32, e.original.1);
        }
    }
    crate::log!("anim_edit: {} restored", e.name);
    true
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
                "bytes": e.size,
                "original_bytes": e.original.1,
                "views": e.views.iter().map(|v| format!("0x{v:X}")).collect::<Vec<_>>(),
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
    let by = glam::DVec3::new(
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
        OpDef::new("anim.shift", "Test rewrite: add offset (cm) to one bone's local translation at every sample of a loaded AnimSequence, encode with ACL and point the engine's decoder at it", "{sequence?: selector, name?: str, bone: str, offset: {X,Y,Z}}", move |args| {
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

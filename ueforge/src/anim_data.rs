//! An animation's bones read straight from its data: every bone's
//! transform at any time of any loaded AnimSequence, with no body
//! playing it. Asked 2026-11-22: "we need to bea ble to read all the
//! aniatmion data. if necessary we do DRyu framwork upgrades", "the
//! right way is the framework upgrade to read the animation data
//! directly".
//!
//! Prior art: UE's ACL plugin (nfrechette/acl-ue4-plugin,
//! ACLDecompressionImpl.h) is how the game itself decodes; CUE4Parse
//! (FabianFG/CUE4Parse) reads the same data outside the engine with ACL.
//! UE's own GetAnimPoseAtTime is editor only
//! (Engine/Source/Editor/AnimationBlueprintLibrary), so a shipped game
//! has no engine function for this.
//!
//! How (cpp/ueforge_acl.cpp decodes):
//! - The bone data is ACL v2.1 compressed tracks. UE 5 keeps a pointer
//!   to the buffer in the AnimSequence (FCompressedAnimSequence, not
//!   reflected); it is found by its ACL tag (0xac11ac11 after the
//!   8-byte raw buffer header) and checked by ACL itself.
//! - The track to bone table (CompressedTrackToSkeletonMapTable, one
//!   int32 skeleton bone index per track) is the array in the object
//!   whose count is the track count and whose entries are bone indices.
//! - The skeleton's bones (FReferenceSkeleton in USkeleton, not
//!   reflected): raw bone infos (FName + parent, 12 bytes each), raw
//!   reference pose (FTransform of doubles, 96 bytes), then the final
//!   infos and pose, which add the virtual bones; found by those four
//!   arrays in a row with parents that point back. The tracks index the
//!   final list (Breath on SKEL_BaseFemale_UE5: 214 tracks, 212 raw and
//!   214 final bones; tests/research_parts.rs acl_block and
//!   skeleton_layout in wickedisland-mod, 2026-11-22).
//! - Bones an animation does not move keep the reference pose, as the
//!   plugin's writer does for a non-additive clip.
//!
//! The pose is the animation alone, in the skeleton's space: no
//! animation blueprint layers, physics or retargeting to a mesh.
//!
//! Ops (register_ops):
//! - anim.info {sequence | name}: tracks, samples, rate, duration,
//!   skeleton and bone count.
//! - anim.pose {sequence | name, time, bones?, space?}: each bone's
//!   name, parent, rotation, translation and scale at `time` seconds;
//!   space "component" (default, composed from the root) or "local"
//!   (relative to the parent).

use glam::{DQuat, DVec3};
use serde_json::{Value, json};

use crate::ue::UObject;

unsafe extern "C" {
    fn ueforge_acl_info(
        buffer: *const u8,
        num_tracks: *mut u32,
        num_samples: *mut u32,
        sample_rate: *mut f32,
        duration: *mut f32,
        track_type: *mut u32,
        default_scale: *mut i32,
    ) -> i32;
    fn ueforge_acl_sample(
        buffer: *const u8,
        time: f32,
        step: i32,
        reference: *const f32,
        out: *mut f32,
        num_tracks: u32,
    ) -> i32;
}

const ACL_TAG: u32 = 0xac11_ac11;
/// ACL's track type for bone transforms (rotation, translation, scale).
const QVVF: u32 = 12;

/// The header of an ACL buffer: (tracks, samples, rate, duration, track
/// type, default scale), None when ACL does not take it.
pub(crate) fn acl_header(buffer: usize) -> Option<(u32, u32, f32, f32, u32, i32)> {
    let (mut tracks, mut samples, mut rate, mut duration, mut kind, mut scale) =
        (0u32, 0u32, 0f32, 0f32, 0u32, 0i32);
    // SAFETY: the caller hands a readable buffer; ACL checks its header.
    let r = unsafe {
        ueforge_acl_info(
            buffer as *const u8,
            &mut tracks,
            &mut samples,
            &mut rate,
            &mut duration,
            &mut kind,
            &mut scale,
        )
    };
    (r == 0).then_some((tracks, samples, rate, duration, kind, scale))
}

/// One bone transform: rotation, translation, scale.
#[derive(Clone, Copy, Debug)]
pub struct Xform {
    pub rot: DQuat,
    pub pos: DVec3,
    pub scale: DVec3,
}

impl Xform {
    /// This transform, relative to `parent`, put in the parent's space
    /// (UE's FTransform child * parent).
    pub fn under(&self, parent: &Xform) -> Xform {
        Xform {
            rot: parent.rot * self.rot,
            pos: parent.rot * (parent.scale * self.pos) + parent.pos,
            scale: parent.scale * self.scale,
        }
    }

    /// A point in this transform's space, put in its parent's space.
    pub fn point(&self, p: DVec3) -> DVec3 {
        self.rot * (self.scale * p) + self.pos
    }

    /// A point in the parent's space, put in this transform's space.
    pub fn inverse_point(&self, p: DVec3) -> DVec3 {
        (self.rot.inverse() * (p - self.pos)) / self.scale
    }

    /// An FTransform as reflect reads it: {Rotation, Translation,
    /// Scale3D}.
    pub fn from_json(v: &Value) -> Option<Xform> {
        let f = |o: &Value, k: &str| o[k].as_f64();
        let r = &v["Rotation"];
        let t = &v["Translation"];
        let s = &v["Scale3D"];
        Some(Xform {
            rot: DQuat::from_xyzw(f(r, "X")?, f(r, "Y")?, f(r, "Z")?, f(r, "W")?).normalize(),
            pos: DVec3::new(f(t, "X")?, f(t, "Y")?, f(t, "Z")?),
            scale: DVec3::new(f(s, "X")?, f(s, "Y")?, f(s, "Z")?),
        })
    }

    fn json(&self) -> Value {
        json!({
            "rotation": {"X": self.rot.x, "Y": self.rot.y, "Z": self.rot.z, "W": self.rot.w},
            "translation": {"X": self.pos.x, "Y": self.pos.y, "Z": self.pos.z},
            "scale": {"X": self.scale.x, "Y": self.scale.y, "Z": self.scale.z},
        })
    }
}

/// A skeleton's final bone list (raw bones then virtual bones).
pub struct Skeleton {
    pub name: String,
    pub bones: Vec<String>,
    pub parents: Vec<i32>,
    pub reference: Vec<Xform>,
}

/// An animation's compressed bone data.
pub struct Clip {
    data: Data,
    /// "acl" or UE's key format (constant key lerp, variable key lerp,
    /// per track).
    pub format: &'static str,
    /// UE's Step interpolation: no blend between keys.
    pub step: bool,
    pub tracks: u32,
    pub samples: u32,
    pub rate: f32,
    pub duration: f32,
    pub additive: bool,
    /// Skeleton bone index of each track.
    pub track_bone: Vec<i32>,
    pub skeleton: Skeleton,
}

/// Where a clip's keys are.
enum Data {
    /// ACL compressed tracks, decoded on each sample.
    Acl { buffer: usize },
    /// UE's own codecs, decoded to keys once (anim_codec.rs); `at` is
    /// the FUECompressedAnimData they were read from.
    Ue {
        tracks: Vec<crate::anim_codec::Track>,
        at: usize,
    },
}

/// Every page of `len` bytes at `addr` is readable (pose_hide.rs uses
/// it too).
pub(crate) fn readable(addr: usize, len: usize) -> bool {
    let Some(end) = addr.checked_add(len) else {
        return false;
    };
    let mut p = addr;
    while p < end {
        if !modforge::winproc::is_addr_readable(p) {
            return false;
        }
        p = (p & !0xFFF) + 0x1000;
    }
    true
}

/// `T` at `addr`, when its bytes are readable.
pub(crate) fn read<T: Copy>(addr: usize) -> Option<T> {
    if !readable(addr, size_of::<T>()) {
        return None;
    }
    // SAFETY: the bytes were just checked readable; read_unaligned has
    // no alignment need.
    Some(unsafe { std::ptr::read_unaligned(addr as *const T) })
}

/// A TArray at `addr`: (data, count), when it looks like one.
fn array_at(addr: usize) -> Option<(usize, usize)> {
    let data: usize = read(addr)?;
    let num: i32 = read(addr + 8)?;
    let max: i32 = read(addr + 12)?;
    if data < 0x1_0000 || num <= 0 || max < num || num > 1 << 20 {
        return None;
    }
    Some((data, num as usize))
}

fn object_size(o: &UObject) -> usize {
    match o.class().map(|c| c.properties_size() as usize) {
        Some(s) if (0x30..0x10000).contains(&s) => s,
        _ => 0x200,
    }
}

/// Bone infos at `data` (12 bytes each): names and parents, when every
/// parent points back (the root's is -1).
fn bone_infos(data: usize, n: usize) -> Option<(Vec<String>, Vec<i32>)> {
    if !readable(data, n * 12) {
        return None;
    }
    let mut names = Vec::with_capacity(n);
    let mut parents = Vec::with_capacity(n);
    for i in 0..n {
        let parent: i32 = read(data + i * 12 + 8)?;
        if (i == 0 && parent != -1) || (i > 0 && !(0..i as i32).contains(&parent)) {
            return None;
        }
        // SAFETY: the 12 bytes were checked readable; read_at checks
        // the name is plausible before resolving it.
        let name = unsafe { crate::ue::fname::read_at((data + i * 12) as *const u8, 0) }?;
        names.push(name);
        parents.push(parent);
    }
    Some((names, parents))
}

/// FTransforms of doubles at `data` (96 bytes each).
fn transforms(data: usize, n: usize) -> Option<Vec<Xform>> {
    if !readable(data, n * 96) {
        return None;
    }
    (0..n)
        .map(|i| {
            let d = |k: usize| read::<f64>(data + i * 96 + k * 8);
            let rot = DQuat::from_xyzw(d(0)?, d(1)?, d(2)?, d(3)?);
            if (rot.length() - 1.0).abs() > 0.01 {
                return None;
            }
            Some(Xform {
                rot,
                pos: DVec3::new(d(4)?, d(5)?, d(6)?),
                scale: DVec3::new(d(8)?, d(9)?, d(10)?),
            })
        })
        .collect()
}

/// The final bone list of a USkeleton.
pub fn skeleton(skel: &UObject) -> Result<Skeleton, String> {
    let base = skel.as_ptr() as usize;
    let size = object_size(skel);
    for o in (0..size.saturating_sub(0x40)).step_by(8) {
        let (Some((raw_info, raw_n)), Some((raw_pose, pose_n))) =
            (array_at(base + o), array_at(base + o + 0x10))
        else {
            continue;
        };
        let (Some((fin_info, fin_n)), Some((fin_pose, fin_pose_n))) =
            (array_at(base + o + 0x20), array_at(base + o + 0x30))
        else {
            continue;
        };
        if pose_n != raw_n || fin_pose_n != fin_n || fin_n < raw_n {
            continue;
        }
        if bone_infos(raw_info, raw_n).is_none() || transforms(raw_pose, raw_n).is_none() {
            continue;
        }
        let Some((bones, parents)) = bone_infos(fin_info, fin_n) else {
            continue;
        };
        let Some(reference) = transforms(fin_pose, fin_n) else {
            continue;
        };
        return Ok(Skeleton {
            name: skel.name(),
            bones,
            parents,
            reference,
        });
    }
    Err(format!("{}: no reference skeleton found", skel.name()))
}

/// The bone data of an AnimSequence. Game thread (the asset must stay
/// loaded while it is read).
pub fn clip(seq: &UObject) -> Result<Clip, String> {
    // SAFETY: game thread; reflect reads a reflected field.
    let skel = unsafe { crate::reflect::get_fields(seq, &["Skeleton".to_owned()]) }?;
    let skel_addr = skel["Skeleton"]["addr"]
        .as_str()
        .and_then(|s| usize::from_str_radix(s.trim_start_matches("0x"), 16).ok())
        .ok_or_else(|| format!("{}: no skeleton", seq.name()))?;
    let skel = crate::selector::resolve(&format!("addr:0x{skel_addr:X}"))?;
    let skeleton = skeleton(skel)?;
    let base = seq.as_ptr() as usize;
    let size = object_size(seq);
    let names = ["SequenceLength", "Interpolation", "AdditiveAnimType"].map(str::to_owned);
    // SAFETY: game thread; reflected fields.
    let f = unsafe { crate::reflect::get_fields(seq, &names) }?;
    let length = f["SequenceLength"].as_f64().unwrap_or(0.0) as f32;
    // EAnimInterpolationType: 0 linear, 1 step.
    let step = f["Interpolation"].as_i64() == Some(1);
    let additive = f["AdditiveAnimType"].as_i64().unwrap_or(0) != 0;
    if let Some(a) = acl_clip(base, size, skeleton.bones.len())? {
        return Ok(Clip {
            data: Data::Acl { buffer: a.buffer },
            format: "acl",
            step,
            tracks: a.tracks,
            samples: a.samples,
            rate: a.rate,
            duration: a.duration,
            additive: a.additive,
            track_bone: a.track_bone,
            skeleton,
        });
    }
    ue_clip(seq, base, size, skeleton, length, step, additive)
}

/// The track to bone table: the array in the object of `tracks` entries
/// that are all bone indices.
fn track_table(base: usize, size: usize, tracks: usize, bones: usize) -> Option<Vec<i32>> {
    (0..size.saturating_sub(16))
        .step_by(8)
        .filter_map(|o| array_at(base + o))
        .filter(|&(_, n)| n == tracks)
        .find_map(|(data, n)| {
            let v: Option<Vec<i32>> = (0..n).map(|i| read::<i32>(data + i * 4)).collect();
            v.filter(|v| v.iter().all(|&b| b >= 0 && (b as usize) < bones))
        })
}

/// The offset in `seq` of its track to bone table (the array of `tracks`
/// bone indices).
pub(crate) fn track_table_offset(seq: &UObject, tracks: usize, bones: usize) -> Option<usize> {
    let base = seq.as_ptr() as usize;
    (0..object_size(seq).saturating_sub(16))
        .step_by(8)
        .find(|&o| {
            array_at(base + o).is_some_and(|(data, n)| {
                n == tracks
                    && (0..n).all(|i| {
                        read::<i32>(data + i * 4).is_some_and(|b| b >= 0 && (b as usize) < bones)
                    })
            })
        })
}

/// A TArrayView (data, int32 count) at `addr` copied out, when readable.
pub(crate) fn view<T: Copy>(addr: usize, max: usize) -> Option<Vec<T>> {
    let data: usize = read(addr)?;
    let n: i32 = read(addr + 8)?;
    if n == 0 {
        return Some(Vec::new());
    }
    if n < 0 || n as usize > max || !readable(data, n as usize * size_of::<T>()) {
        return None;
    }
    // SAFETY: the whole range was just checked readable; the values are
    // plain numbers.
    Some(
        (0..n as usize)
            .map(|i| unsafe { std::ptr::read_unaligned((data as *const T).add(i)) })
            .collect(),
    )
}

/// UE's own compressed data (FUECompressedAnimData, read in
/// tests/research_parts.rs ue_codec_layout, 01_idle 2026-11-22): after
/// the vtable, CompressedNumberOfKeys (int32) at 0x8, then three
/// TArrayViews of 16 bytes: track offsets at 0x10, scale offsets at 0x20
/// (with their strip size at 0x30), the byte stream at 0x38; three codec
/// pointers; then the key format and the translation, rotation and scale
/// formats as int32 at 0x60, 0x64, 0x68, 0x6C. Found as the pointer in
/// the AnimSequence whose target fits all of that.
fn ue_clip(
    seq: &UObject,
    base: usize,
    size: usize,
    skeleton: Skeleton,
    length: f32,
    step: bool,
    additive: bool,
) -> Result<Clip, String> {
    use crate::anim_codec as codec;
    let bones = skeleton.bones.len();
    for o in (0..size.saturating_sub(8)).step_by(8) {
        let Some(p) = read::<usize>(base + o) else {
            continue;
        };
        if p < 0x1_0000 || !readable(p, 0x70) {
            continue;
        }
        let Some(num_frames) = read::<i32>(p + 8) else {
            continue;
        };
        let codes: Option<Vec<u32>> = (0..4).map(|i| read::<u32>(p + 0x60 + i * 4)).collect();
        let Some(codes) = codes else { continue };
        if !(1..1_000_000).contains(&num_frames)
            || codes[0] > codec::PER_TRACK
            || codes[1..].iter().any(|&c| c > 6)
        {
            continue;
        }
        let (Some(offsets), Some(scale_offsets), Some(stream)) = (
            view::<i32>(p + 0x10, 1 << 22),
            view::<i32>(p + 0x20, 1 << 22),
            view::<u8>(p + 0x38, 256 << 20),
        ) else {
            continue;
        };
        let per = if codes[0] == codec::PER_TRACK { 2 } else { 4 };
        if offsets.is_empty() || offsets.len() % per != 0 || stream.is_empty() {
            continue;
        }
        let tracks = offsets.len() / per;
        let Some(track_bone) = track_table(base, size, tracks, bones) else {
            continue;
        };
        let data = codec::UeData {
            key_format: codes[0],
            translation_format: codes[1],
            rotation_format: codes[2],
            scale_format: codes[3],
            num_frames: num_frames as u32,
            track_offsets: &offsets,
            scale_offsets: &scale_offsets,
            stream: &stream,
        };
        let keys = codec::decode(&data, tracks, if additive { 0.0 } else { 1.0 })
            .map_err(|e| format!("{}: {e}", seq.name()))?;
        return Ok(Clip {
            data: Data::Ue {
                tracks: keys,
                at: p,
            },
            format: match codes[0] {
                codec::CONSTANT_KEY_LERP => "constant key lerp",
                codec::VARIABLE_KEY_LERP => "variable key lerp",
                _ => "per track",
            },
            step,
            tracks: tracks as u32,
            samples: num_frames as u32,
            rate: if length > 0.0 {
                (num_frames - 1).max(1) as f32 / length
            } else {
                0.0
            },
            duration: length,
            additive,
            track_bone,
            skeleton,
        });
    }
    Err(format!(
        "{}: no bone data found (neither ACL nor UE's own)",
        seq.name()
    ))
}

/// The ACL data of an AnimSequence, if it has it.
fn acl_clip(base: usize, size: usize, bones: usize) -> Result<Option<AclFound>, String> {
    let mut found = None;
    for o in (0..size.saturating_sub(8)).step_by(8) {
        let Some(p) = read::<usize>(base + o) else {
            continue;
        };
        if p < 0x1_0000 || read::<u32>(p + 8) != Some(ACL_TAG) {
            continue;
        }
        // The raw buffer header's first word is the whole size.
        let Some(len) = read::<u32>(p) else { continue };
        if !(24..64 << 20).contains(&len) || !readable(p, len as usize) {
            continue;
        }
        let (mut tracks, mut samples, mut rate, mut duration, mut kind, mut scale) =
            (0u32, 0u32, 0f32, 0f32, 0u32, 0i32);
        // SAFETY: the whole buffer is readable; ACL checks its header.
        let r = unsafe {
            ueforge_acl_info(
                p as *const u8,
                &mut tracks,
                &mut samples,
                &mut rate,
                &mut duration,
                &mut kind,
                &mut scale,
            )
        };
        if r == 0 && kind == QVVF {
            found = Some((p, tracks, samples, rate, duration, scale == 0));
            break;
        }
    }
    let Some((buffer, tracks, samples, rate, duration, additive)) = found else {
        return Ok(None);
    };
    let track_bone = track_table(base, size, tracks as usize, bones)
        .ok_or("ACL data but no track to bone table found")?;
    Ok(Some(AclFound {
        buffer,
        tracks,
        samples,
        rate,
        duration,
        additive,
        track_bone,
    }))
}

struct AclFound {
    buffer: usize,
    tracks: u32,
    samples: u32,
    rate: f32,
    duration: f32,
    additive: bool,
    track_bone: Vec<i32>,
}

impl Clip {
    /// Every skeleton bone's transform relative to its parent at `time`
    /// seconds (clamped to the clip). Bones with no track keep the
    /// reference pose. Game thread.
    pub fn local_pose(&self, time: f32) -> Result<Vec<Xform>, String> {
        self.local_pose_at(time, i32::from(self.step))
    }

    /// Every skeleton bone's transform relative to its parent at sample
    /// `i` of the clip, as stored (no blend between samples). Game
    /// thread.
    pub fn local_sample(&self, i: u32) -> Result<Vec<Xform>, String> {
        if let Data::Ue { tracks, .. } = &self.data {
            // Exactly at the frame: keys spread over frames 0..n-1.
            let rel = if self.samples > 1 {
                f64::from(i) / f64::from(self.samples - 1)
            } else {
                0.0
            };
            return Ok(self.ue_pose(tracks, rel, false));
        }
        if self.rate <= 0.0 {
            return Err("the clip has no sample rate".into());
        }
        self.local_pose_at(i as f32 / self.rate, 2)
    }

    /// The ACL buffer the clip was read from (the AnimSequence's own
    /// data, never one anim_edit put in), None for UE's own codecs.
    pub fn acl_buffer(&self) -> Option<usize> {
        match self.data {
            Data::Acl { buffer } => Some(buffer),
            Data::Ue { .. } => None,
        }
    }

    /// The same ACL clip read from another buffer of its layout (a
    /// rewrite's, anim_edit played); a UE format clip as it is.
    pub fn with_acl_buffer(mut self, buffer: usize) -> Clip {
        if let Data::Acl { .. } = self.data {
            self.data = Data::Acl { buffer };
        }
        self
    }

    /// The FUECompressedAnimData the clip was read from, None for ACL.
    pub fn ue_data(&self) -> Option<usize> {
        match self.data {
            Data::Ue { at, .. } => Some(at),
            Data::Acl { .. } => None,
        }
    }

    fn ue_pose(&self, tracks: &[crate::anim_codec::Track], rel: f64, step: bool) -> Vec<Xform> {
        let mut pose = self.skeleton.reference.clone();
        for (t, &b) in self.track_bone.iter().enumerate() {
            let (rot, pos, scale) = tracks[t].sample(rel, self.samples, step);
            pose[b as usize] = Xform { rot, pos, scale };
        }
        pose
    }

    /// `step`: 0 blend, 1 floor, 2 nearest sample (ueforge_acl_sample).
    fn local_pose_at(&self, time: f32, step: i32) -> Result<Vec<Xform>, String> {
        let time = time.clamp(0.0, self.duration);
        let buffer = match &self.data {
            Data::Acl { buffer } => *buffer,
            Data::Ue { tracks, .. } => {
                let rel = if self.duration > 0.0 {
                    f64::from(time / self.duration)
                } else {
                    0.0
                };
                return Ok(self.ue_pose(tracks, rel, step != 0));
            }
        };
        let n = self.tracks as usize;
        let mut reference = vec![0f32; n * 10];
        for (t, &b) in self.track_bone.iter().enumerate() {
            let x = &self.skeleton.reference[b as usize];
            reference[t * 10..t * 10 + 10].copy_from_slice(&[
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
            ]);
        }
        let mut out = vec![0f32; n * 10];
        // SAFETY: the buffer was checked readable and valid by clip();
        // both arrays hold 10 floats per track.
        let r = unsafe {
            ueforge_acl_sample(
                buffer as *const u8,
                time,
                step,
                reference.as_ptr(),
                out.as_mut_ptr(),
                self.tracks,
            )
        };
        if r != 0 {
            return Err(format!("ACL decode failed ({r})"));
        }
        let mut pose = self.skeleton.reference.clone();
        for (t, &b) in self.track_bone.iter().enumerate() {
            let f = &out[t * 10..t * 10 + 10];
            let d = |i: usize| f64::from(f[i]);
            pose[b as usize] = Xform {
                rot: DQuat::from_xyzw(d(0), d(1), d(2), d(3)).normalize(),
                pos: DVec3::new(d(4), d(5), d(6)),
                scale: DVec3::new(d(7), d(8), d(9)),
            };
        }
        Ok(pose)
    }

    /// Every skeleton bone's transform in the skeleton's component
    /// space at `time`, composed from the root down.
    pub fn component_pose(&self, time: f32) -> Result<Vec<Xform>, String> {
        let local = self.local_pose(time)?;
        let mut out: Vec<Xform> = Vec::with_capacity(local.len());
        for (i, x) in local.iter().enumerate() {
            let p = self.skeleton.parents[i];
            out.push(if p < 0 { *x } else { x.under(&out[p as usize]) });
        }
        Ok(out)
    }
}

/// A loaded AnimSequence by its object name (exact). Game thread.
pub fn find(name: &str) -> Result<&'static UObject, String> {
    let rt = crate::ue::try_runtime().ok_or("runtime not ready")?;
    // SAFETY: the runtime's image base and offsets describe this game.
    let view = unsafe { crate::ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    view.iter()
        .find(|o| {
            !o.is_default_object()
                && o.class()
                    .is_some_and(|c| c.as_object().name() == "AnimSequence")
                && o.name() == name
        })
        .map(|o| {
            // SAFETY: GObjects entries live as long as the object; the
            // op uses it within this game-thread call.
            unsafe { &*(o as *const UObject) }
        })
        .ok_or_else(|| format!("no loaded AnimSequence named {name}"))
}

fn sequence(args: &Value) -> Result<&'static UObject, String> {
    if let Some(s) = args["sequence"].as_str() {
        return crate::selector::resolve(s);
    }
    find(
        args["name"]
            .as_str()
            .ok_or("sequence (selector) or name is required")?,
    )
}

fn info(args: &Value) -> Result<Value, String> {
    let seq = sequence(args)?;
    let c = clip(seq)?;
    Ok(json!({
        "sequence": seq.full_name(),
        "format": c.format,
        "tracks": c.tracks,
        "samples": c.samples,
        "rate": c.rate,
        "duration": c.duration,
        "additive": c.additive,
        "skeleton": c.skeleton.name,
        "bones": c.skeleton.bones.len(),
    }))
}

fn pose(args: &Value) -> Result<Value, String> {
    let seq = sequence(args)?;
    let time = args["time"].as_f64().ok_or("time (seconds) is required")? as f32;
    let c = clip(seq)?;
    let xs = match args["space"].as_str().unwrap_or("component") {
        "component" => c.component_pose(time)?,
        "local" => c.local_pose(time)?,
        s => return Err(format!("space {s}: component or local")),
    };
    let want: Vec<&str> = args["bones"]
        .as_array()
        .map(|a| a.iter().filter_map(Value::as_str).collect())
        .unwrap_or_default();
    let bones: Vec<Value> = c
        .skeleton
        .bones
        .iter()
        .enumerate()
        .filter(|(_, n)| want.is_empty() || want.contains(&n.as_str()))
        .map(|(i, n)| {
            let mut v = xs[i].json();
            v["name"] = json!(n);
            v["parent"] = json!(c.skeleton.parents[i]);
            v
        })
        .collect();
    Ok(json!({"time": time.clamp(0.0, c.duration), "duration": c.duration, "bones": bones}))
}

/// anim.info and anim.pose, on the game thread through `drain`.
pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    fn job(
        drain: &'static crate::pe_queue::GameThread,
        hint: &'static str,
        args: Value,
        f: fn(&Value) -> Result<Value, String>,
    ) -> Result<Value, String> {
        crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(10), hint, move || {
            f(&args)
        })
    }
    OP_REGISTRY.register_many([
        OpDef::new("anim.info", "A loaded AnimSequence's bone data: tracks, samples, rate, duration, skeleton and bone count", "{sequence?: selector, name?: str}", move |args| {
            job(drain, hint, args.clone(), info)
        }),
        OpDef::new("anim.pose", "Every bone of a loaded AnimSequence at a time, read from its data (ACL): name, parent, rotation, translation, scale; space component (default) or local", "{sequence?: selector, name?: str, time: f64 (s), bones?: [str], space?: str}", move |args| {
            job(drain, hint, args.clone(), pose)
        }),
        OpDef::new("anim.curves", "A loaded AnimSequence's float curves (morph targets and others) read from its data (ACL): each curve's name, lowest and highest over the clip, and its value at time when given", "{sequence?: selector, name?: str, time?: f64 (s)}", move |args| {
            job(drain, hint, args.clone(), |a| {
                crate::anim_curves::info(sequence(a)?, a["time"].as_f64().map(|t| t as f32))
            })
        }),
        OpDef::new("anim.curve_probe", "What follows a loaded AnimSequence's track to bone table: each 8 bytes, as a TArray (count, first bytes, as FName entries) or an object", "{sequence?: selector, name?: str}", move |args| {
            job(drain, hint, args.clone(), |a| crate::anim_curves::probe(sequence(a)?))
        }),
    ]);
}

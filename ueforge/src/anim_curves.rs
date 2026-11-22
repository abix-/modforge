//! An AnimSequence's float curves (morph target and material curves):
//! where the cooked sequence keeps them. Asked 2026-11-22 (wickedisland
//! openings: "can we fix the animations so that openngs are open as
//! expected?", "open eexpect means it should follow the stroke
//! logically", "build all the features").
//!
//! UE 5.6 keeps the compressed data in FCompressedAnimSequence, not
//! reflected. Read live on Animation_4_female (wickedisland-mod
//! tests/research_parts.rs anim_curve_bytes, 2026-11-22), from the track
//! to bone table at T: T+0x20 a TArray of 7 entries (the curve names,
//! FAnimCompressedCurveIndexedName: FName then int32 curve index), T+0x50
//! a TArray of 533 bytes (the curve byte stream), T+0x68 the bone codec
//! (AnimBoneCompressionCodec_ACL), T+0x70 the curve codec
//! (AnimCurveCompressionCodec_ACL). The curve stream is an ACL buffer of
//! float1f tracks, one per curve, output index = curve index, as UE's ACL
//! plugin writes it; the codec decodes it from the TArray each time.
//!
//! Sequences whose curve codec is AnimCurveCompressionCodec_
//! CompressedRichCurve (the Ogre and Troll female animations) keep the
//! same table; their stream is read and written by rich_curve.rs.
//!
//! Rewriting puts a new buffer in that TArray (pointer and count; the
//! engine's buffer is kept and put back by anim_edit restore, at scene
//! end and shutdown).

use serde_json::{Value, json};

use crate::anim_data::{read, readable};
use crate::ue::UObject;

unsafe extern "C" {
    fn ueforge_acl_curves_info(
        buffer: *const u8,
        num_tracks: *mut u32,
        num_samples: *mut u32,
        sample_rate: *mut f32,
        duration: *mut f32,
    ) -> i32;
    fn ueforge_acl_curves_sample(
        buffer: *const u8,
        time: f32,
        step: i32,
        out: *mut f32,
        num_tracks: u32,
    ) -> i32;
    fn ueforge_acl_curves_compress(
        raw: *const f32,
        num_tracks: u32,
        num_samples: u32,
        sample_rate: f32,
        precision: f32,
        out_size: *mut u32,
    ) -> *mut u8;
    fn ueforge_acl_free(buffer: *mut u8);
}

/// From the track to bone table (see the module notes).
const NAMES: usize = 0x20;
const STREAM: usize = 0x50;
const CODEC: usize = 0x70;
/// Precision of a rewritten curve value (UE's ACL curve codec default
/// CurvePrecision is 0.001).
const PRECISION: f32 = 0.001;

/// The curve codec a sequence's curve stream is written for.
#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum Codec {
    Acl,
    /// AnimCurveCompressionCodec_CompressedRichCurve (rich_curve.rs).
    RichCurve,
}

const RICH_CURVE: &str = "AnimCurveCompressionCodec_CompressedRichCurve";

/// An AnimSequence's curves.
pub struct Curves {
    /// Curve names by curve index (the ACL track's output index, the
    /// rich curve descriptor's place).
    pub names: Vec<String>,
    pub samples: u32,
    pub rate: f32,
    pub duration: f32,
    pub codec: Codec,
    buffer: usize,
    len: usize,
    /// The curve stream TArray in the sequence.
    pub(crate) array_at: usize,
    /// The curve name TArray in the sequence.
    pub(crate) names_at: usize,
    /// How many curves the stream holds (`names` can be longer once
    /// curves are added for a rewrite).
    pub(crate) stored: usize,
}

/// A curve name table for `names`, as FCompressedAnimSequence keeps
/// it: entry k is curve k's FName and an int32, and the int32s list the
/// curves in FName::FastLess order (comparison index, then number), as
/// RebuildCurveIndexTable writes them (UE 5.8 AnimCompressionTypes.cpp)
/// and the codecs' DecompressCurves read them. New names are added to
/// the game's name table. Game thread.
pub(crate) fn name_table(names: &[String]) -> Result<Vec<u8>, String> {
    let ids: Vec<crate::ue::fname::FName> = names
        .iter()
        .map(|n| {
            crate::ue::fname::from_str(n, crate::ue::fname::FindName::Add)
                .ok_or_else(|| format!("no FName for {n}"))
        })
        .collect::<Result<_, _>>()?;
    let mut order: Vec<usize> = (0..ids.len()).collect();
    order.sort_by_key(|&k| (ids[k].comparison_index as u32, ids[k].number));
    let mut out = Vec::with_capacity(ids.len() * 12);
    for (k, id) in ids.iter().enumerate() {
        out.extend_from_slice(&id.as_u64().to_le_bytes());
        out.extend_from_slice(&(order[k] as i32).to_le_bytes());
    }
    Ok(out)
}

/// The curves of `seq`, when its curve codec is ACL or the compressed
/// rich curve. Game thread.
pub fn curves(seq: &UObject) -> Result<Curves, String> {
    let clip = crate::anim_data::clip(seq)?;
    let at =
        crate::anim_data::track_table_offset(seq, clip.tracks as usize, clip.skeleton.bones.len())
            .ok_or("no track to bone table")?;
    let base = seq.as_ptr() as usize;
    let codec: usize = read(base + at + CODEC).ok_or("no curve codec")?;
    if !crate::ue::uobject::is_live(codec) {
        return Err(format!("{}: no curve codec object", seq.name()));
    }
    // SAFETY: is_live found it in GObjects.
    let class = unsafe { &*(codec as *const UObject) }
        .class()
        .map(|c| c.as_object().name())
        .unwrap_or_default();
    let codec = match class.as_str() {
        "AnimCurveCompressionCodec_ACL" => Codec::Acl,
        RICH_CURVE => Codec::RichCurve,
        _ => {
            return Err(format!(
                "{}: curve codec {class}, not ACL or {RICH_CURVE}",
                seq.name()
            ));
        }
    };
    let array_at = base + at + STREAM;
    let names_at = base + at + NAMES;
    let buffer: usize = read(array_at).ok_or("no curve stream")?;
    let len: i32 = read(array_at + 8).ok_or("no curve stream")?;
    let names_data: usize = read(names_at).ok_or("no curve names")?;
    let n_names: i32 = read(names_at + 8).ok_or("no curve names")?;
    if n_names <= 0 || len <= 0 || buffer < 0x1_0000 || !readable(buffer, len as usize) {
        // No curves: the clip's samples, so curves can be added.
        return Ok(Curves {
            names: Vec::new(),
            samples: clip.samples,
            rate: clip.rate,
            duration: clip.duration,
            codec,
            buffer: 0,
            len: 0,
            array_at,
            names_at,
            stored: 0,
        });
    }
    if codec == Codec::RichCurve {
        let n = n_names as usize;
        if !readable(names_data, n * 12) || (len as usize) < n * 12 {
            return Err(format!(
                "{}: {n} curve names but a {len} byte rich curve stream",
                seq.name()
            ));
        }
        return Ok(Curves {
            names: read_names(names_data, n)?,
            samples: clip.samples,
            rate: clip.rate,
            duration: clip.duration,
            codec,
            buffer,
            len: len as usize,
            array_at,
            names_at,
            stored: n,
        });
    }
    let (mut n, mut samples, mut rate, mut duration) = (0u32, 0u32, 0f32, 0f32);
    // SAFETY: the buffer's bytes are readable; ACL checks the header.
    let r = unsafe {
        ueforge_acl_curves_info(
            buffer as *const u8,
            &mut n,
            &mut samples,
            &mut rate,
            &mut duration,
        )
    };
    if r != 0 {
        return Err(format!(
            "{}: curve stream is not ACL curves ({r})",
            seq.name()
        ));
    }
    if n as i32 != n_names || !readable(names_data, n as usize * 12) {
        return Err(format!(
            "{}: {n} curve tracks but {n_names} curve names",
            seq.name()
        ));
    }
    // The ACL track is the entry's place in the (name sorted) table, not
    // the int32 stored with it: on Animation_4_female only that order
    // gives the values the anim instance reads live (Anus_Open3 0.9,
    // ZExpansion Anus Gape 1.0, Z PAH Pain Full 0.79; wickedisland-mod
    // tests/research_parts.rs anim_curves and player_shapes, 2026-11-22).
    Ok(Curves {
        names: read_names(names_data, n as usize)?,
        samples,
        rate,
        duration,
        codec,
        buffer,
        len: len as usize,
        array_at,
        names_at,
        stored: n as usize,
    })
}

/// The `n` curve names of the (FName, int32) table at `at`, checked
/// readable.
fn read_names(at: usize, n: usize) -> Result<Vec<String>, String> {
    let mut names = Vec::with_capacity(n);
    for i in 0..n {
        // SAFETY: the entries were checked readable; read_at checks the
        // name before resolving it.
        let name = unsafe { crate::ue::fname::read_at((at + i * 12) as *const u8, 0) }
            .ok_or("unreadable curve name")?;
        names.push(name);
    }
    Ok(names)
}

/// The `len` bytes at `at`, read in place. Game thread, while the
/// stream is the sequence's.
fn bytes<'a>(at: usize, len: usize) -> Result<&'a [u8], String> {
    if at < 0x1_0000 || !readable(at, len) {
        return Err("curve stream not readable".into());
    }
    // SAFETY: checked readable; the stream stays put while the game
    // thread runs this call.
    Ok(unsafe { std::slice::from_raw_parts(at as *const u8, len) })
}

impl Curves {
    /// Every curve's value at sample `i` (by curve index).
    pub fn sample(&self, i: u32) -> Result<Vec<f32>, String> {
        self.at_time(i as f32 / self.rate.max(1e-6), 2)
    }

    /// Every curve's value at `time` seconds, blended between samples.
    pub fn value_at(&self, time: f32) -> Result<Vec<f32>, String> {
        self.at_time(time, 0)
    }

    fn at_time(&self, time: f32, step: i32) -> Result<Vec<f32>, String> {
        // Curves added for a rewrite (past `stored`) read 0.
        let mut out = vec![0f32; self.stored];
        if self.stored == 0 {
            out.resize(self.names.len(), 0.0);
            return Ok(out);
        }
        if self.codec == Codec::RichCurve {
            let b = bytes(self.buffer, self.len)?;
            let t = time.clamp(0.0, self.duration);
            for (k, v) in out.iter_mut().enumerate() {
                *v = crate::rich_curve::eval(b, k, t)?;
            }
            out.resize(self.names.len(), 0.0);
            return Ok(out);
        }
        // SAFETY: the buffer was checked as ACL curves with this count.
        let r = unsafe {
            ueforge_acl_curves_sample(
                self.buffer as *const u8,
                time.clamp(0.0, self.duration),
                step,
                out.as_mut_ptr(),
                out.len() as u32,
            )
        };
        if r != 0 {
            return Err(format!("curve sample failed ({r})"));
        }
        out.resize(self.names.len(), 0.0);
        Ok(out)
    }

    /// The stream TArray's pointer and count now.
    pub(crate) fn stream(&self) -> (usize, i32) {
        (
            read::<usize>(self.array_at).unwrap_or_default(),
            read::<i32>(self.array_at + 8).unwrap_or_default(),
        )
    }

    /// The name TArray's pointer and count now.
    pub(crate) fn name_slot(&self) -> (usize, i32) {
        (
            read::<usize>(self.names_at).unwrap_or_default(),
            read::<i32>(self.names_at + 8).unwrap_or_default(),
        )
    }
}

/// A new curve buffer for `c`'s codec: `values[sample][curve]` for
/// every curve of `c`, at its rate. A rich curve keeps each curve's
/// extrapolation.
pub(crate) fn encode(c: &Curves, values: &[Vec<f32>]) -> Result<Vec<u8>, String> {
    if c.codec == Codec::RichCurve {
        // A curve the stream had keeps its extrapolation; an added one
        // holds its end values (constant).
        let extrap = (0..c.names.len())
            .map(|k| {
                if k < c.stored {
                    crate::rich_curve::desc(bytes(c.buffer, c.len)?, k).map(|d| (d.pre, d.post))
                } else {
                    Ok(crate::rich_curve::CONSTANT_ENDS)
                }
            })
            .collect::<Result<Vec<_>, _>>()?;
        return crate::rich_curve::encode(values, c.rate, &extrap);
    }
    let n = c.names.len();
    let s = values.len();
    if n == 0 || s == 0 || values.iter().any(|v| v.len() != n) {
        return Err("curve values do not match the curves".into());
    }
    let mut raw = vec![0f32; n * s];
    for (i, v) in values.iter().enumerate() {
        for (t, x) in v.iter().enumerate() {
            raw[t * s + i] = *x;
        }
    }
    let mut size = 0u32;
    // SAFETY: raw is n * s floats.
    let out = unsafe {
        ueforge_acl_curves_compress(
            raw.as_ptr(),
            n as u32,
            s as u32,
            c.rate,
            PRECISION,
            &mut size,
        )
    };
    if out.is_null() {
        return Err(format!("ACL curve compression failed ({size})"));
    }
    // SAFETY: ACL's buffer is `size` bytes; freed right after the copy.
    let bytes = unsafe { std::slice::from_raw_parts(out, size as usize) }.to_vec();
    // SAFETY: from ueforge_acl_curves_compress, freed once.
    unsafe { ueforge_acl_free(out) };
    Ok(bytes)
}

/// The curves of the `len` bytes at `at` (a buffer from [`encode`] for
/// `c`) at sample `i`, to check it reads back.
pub(crate) fn decode_sample(c: &Curves, at: usize, len: usize, i: u32) -> Result<Vec<f32>, String> {
    let (n, rate) = (c.names.len(), c.rate);
    if c.codec == Codec::RichCurve {
        let b = bytes(at, len)?;
        let t = i as f32 / rate.max(1e-6);
        return (0..n).map(|k| crate::rich_curve::eval(b, k, t)).collect();
    }
    let bytes = at;
    let mut out = vec![0f32; n];
    // SAFETY: `bytes` is a buffer from encode with n tracks.
    let r = unsafe {
        ueforge_acl_curves_sample(
            bytes as *const u8,
            i as f32 / rate.max(1e-6),
            2,
            out.as_mut_ptr(),
            n as u32,
        )
    };
    if r != 0 {
        return Err(format!("curve read back failed ({r})"));
    }
    Ok(out)
}

/// A loaded sequence's curves: names, samples, rate, and each curve's
/// value at `time` (or its lowest and highest over the clip). Game
/// thread.
pub fn info(seq: &UObject, time: Option<f32>) -> Result<Value, String> {
    let c = curves(seq)?;
    let mut lo = vec![f32::MAX; c.names.len()];
    let mut hi = vec![f32::MIN; c.names.len()];
    for i in 0..c.samples {
        for (k, v) in c.sample(i)?.into_iter().enumerate() {
            lo[k] = lo[k].min(v);
            hi[k] = hi[k].max(v);
        }
    }
    let now = time.map(|t| c.value_at(t)).transpose()?;
    Ok(json!({
        "sequence": seq.full_name(),
        "samples": c.samples,
        "rate": c.rate,
        "codec": format!("{:?}", c.codec),
        "curves": c.names.iter().enumerate().map(|(k, n)| json!({
            "name": n,
            "lowest": lo[k],
            "highest": hi[k],
            "at_time": now.as_ref().map(|v| v[k]),
        })).collect::<Vec<_>>(),
    }))
}

/// What follows the track to bone table in `seq`: for 0x80 bytes in
/// steps of 8, the value there, and when it is a TArray its count and
/// first bytes, when it is an object its class. Game thread.
pub fn probe(seq: &UObject) -> Result<Value, String> {
    let clip = crate::anim_data::clip(seq)?;
    let base = seq.as_ptr() as usize;
    let at =
        crate::anim_data::track_table_offset(seq, clip.tracks as usize, clip.skeleton.bones.len())
            .ok_or("no track to bone table")?;
    let mut out = Vec::new();
    for k in (0..0x80).step_by(8) {
        let a = base + at + k;
        let Some(v) = read::<usize>(a) else { break };
        let mut e = json!({"offset": format!("0x{:X}", at + k), "value": format!("0x{v:X}")});
        let num: Option<i32> = read(a + 8);
        if let Some(n) = num.filter(|&n| n > 0 && n < 1 << 24)
            && v >= 0x1_0000
            && readable(v, 1)
        {
            let len = (n as usize).min(48);
            if readable(v, len) {
                let bytes: Vec<String> = (0..len)
                    .filter_map(|i| read::<u8>(v + i))
                    .map(|b| format!("{b:02x}"))
                    .collect();
                e["count"] = json!(n);
                e["bytes"] = json!(bytes.join(""));
                // As 12-byte (FName, int32) entries.
                // SAFETY: read_at checks the name before resolving it.
                let names: Vec<Value> = (0..(n as usize).min(16))
                    .map(|i| {
                        let name =
                            unsafe { crate::ue::fname::read_at((v + i * 12) as *const u8, 0) };
                        json!([name, read::<i32>(v + i * 12 + 8)])
                    })
                    .collect();
                e["as_names"] = json!(names);
            }
        }
        if crate::ue::uobject::is_live(v) {
            // SAFETY: is_live found it in GObjects.
            let o = unsafe { &*(v as *const UObject) };
            e["object"] = json!(o.full_name());
        }
        out.push(e);
    }
    Ok(json!({"sequence": seq.full_name(), "track_table": format!("0x{at:X}"), "slots": out}))
}

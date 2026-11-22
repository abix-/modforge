//! UE's own bone compression (the codecs before ACL: constant key lerp,
//! variable key lerp, per track), decoded to keys per track and sampled
//! at a time. anim_data.rs finds the data in a loaded AnimSequence and
//! uses this for every clip that is not ACL. Asked 2026-11-22: "ok so we
//! need to decode all the naiomations".
//!
//! Ported from CUE4Parse (FabianFG/CUE4Parse,
//! CUE4Parse-Conversion/Legacy/AnimConverter.cs ReadKeyLerpData,
//! ReadPerTrackData, ReadTimeArray; CUE4Parse/UE4/Assets/Exports/
//! Animation/AnimationCompressionUtils.cs for the packed numbers), which
//! follows UE's AnimEncoding_ConstantKeyLerp, _VariableKeyLerp and
//! _PerTrackCompression. Sampling follows UE's: keys spread evenly over
//! the clip unless a track has a frame table; rotations blend with
//! FQuat::FastLerp then normalize, vectors with a straight blend.

use glam::{DQuat, DVec3};

/// UE's AnimationKeyFormat.
pub const CONSTANT_KEY_LERP: u32 = 0;
pub const VARIABLE_KEY_LERP: u32 = 1;
pub const PER_TRACK: u32 = 2;

// UE's AnimationCompressionFormat.
const NONE: u32 = 0;
const FLOAT96: u32 = 1;
const FIXED48: u32 = 2;
const INTERVAL_FIXED32: u32 = 3;
const FIXED32: u32 = 4;
const FLOAT32: u32 = 5;
const IDENTITY: u32 = 6;

/// The keys of one part of a track (rotation, translation or scale),
/// with the frame of each key when the track has a frame table.
#[derive(Clone, Debug, Default)]
pub struct Keys<T> {
    pub keys: Vec<T>,
    pub frames: Option<Vec<f32>>,
}

/// One track's keys.
#[derive(Clone, Debug, Default)]
pub struct Track {
    pub rot: Keys<DQuat>,
    pub pos: Keys<DVec3>,
    pub scale: Keys<DVec3>,
}

/// What a FUECompressedAnimData holds.
pub struct UeData<'a> {
    pub key_format: u32,
    pub translation_format: u32,
    pub rotation_format: u32,
    pub scale_format: u32,
    /// CompressedNumberOfKeys: the frames the clip was sampled at.
    pub num_frames: u32,
    pub track_offsets: &'a [i32],
    pub scale_offsets: &'a [i32],
    pub stream: &'a [u8],
}

struct Reader<'a> {
    b: &'a [u8],
    pos: usize,
}

impl Reader<'_> {
    fn take<const N: usize>(&mut self) -> Result<[u8; N], String> {
        let s = self
            .b
            .get(self.pos..self.pos + N)
            .ok_or_else(|| format!("read past the stream at {}", self.pos))?;
        self.pos += N;
        Ok(s.try_into().unwrap())
    }
    fn u16(&mut self) -> Result<u16, String> {
        Ok(u16::from_le_bytes(self.take()?))
    }
    fn u32(&mut self) -> Result<u32, String> {
        Ok(u32::from_le_bytes(self.take()?))
    }
    fn f32(&mut self) -> Result<f32, String> {
        Ok(f32::from_le_bytes(self.take()?))
    }
    fn vec3(&mut self) -> Result<DVec3, String> {
        Ok(DVec3::new(
            f64::from(self.f32()?),
            f64::from(self.f32()?),
            f64::from(self.f32()?),
        ))
    }
    fn align4(&mut self) {
        self.pos = (self.pos + 3) & !3;
    }
    fn at(&mut self, offset: i32) -> Result<(), String> {
        if offset < 0 || offset as usize > self.b.len() {
            return Err(format!("offset {offset} outside the stream"));
        }
        self.pos = offset as usize;
        Ok(())
    }
}

const Q16_DIV: f32 = 32767.0;
const Q16_OFF: i32 = 32767;
const Q10_DIV: f32 = 511.0;
const Q10_OFF: i32 = 511;
const Q11_DIV: f32 = 1023.0;
const Q11_OFF: i32 = 1023;

fn quat_w(x: f32, y: f32, z: f32) -> DQuat {
    let w2 = 1.0 - x * x - y * y - z * z;
    let w = if w2 > 0.0 { w2.sqrt() } else { 0.0 };
    DQuat::from_xyzw(f64::from(x), f64::from(y), f64::from(z), f64::from(w))
}

fn quat_fixed48(r: &mut Reader, mask: u32) -> Result<DQuat, String> {
    let mut c = |bit: u32| -> Result<f32, String> {
        let v = if mask & bit != 0 {
            i32::from(r.u16()?)
        } else {
            Q16_OFF
        };
        Ok((v - Q16_OFF) as f32 / Q16_DIV)
    };
    let (x, y, z) = (c(1)?, c(2)?, c(4)?);
    Ok(quat_w(x, y, z))
}

fn quat_fixed32(r: &mut Reader) -> Result<DQuat, String> {
    let p = r.u32()?;
    let x = ((p >> 21) as i32 - Q11_OFF) as f32 / Q11_DIV;
    let y = (((p & 0x001f_fc00) >> 10) as i32 - Q11_OFF) as f32 / Q11_DIV;
    let z = ((p & 0x3ff) as i32 - Q10_OFF) as f32 / Q10_DIV;
    Ok(quat_w(x, y, z))
}

fn quat_interval32(r: &mut Reader, mins: DVec3, ranges: DVec3) -> Result<DQuat, String> {
    let p = r.u32()?;
    let x = ((p >> 21) as i32 - Q11_OFF) as f32 / Q11_DIV * ranges.x as f32 + mins.x as f32;
    let y = (((p & 0x001f_fc00) >> 10) as i32 - Q11_OFF) as f32 / Q11_DIV * ranges.y as f32
        + mins.y as f32;
    let z = ((p & 0x3ff) as i32 - Q10_OFF) as f32 / Q10_DIV * ranges.z as f32 + mins.z as f32;
    Ok(quat_w(x, y, z))
}

fn quat_float32(r: &mut Reader) -> Result<DQuat, String> {
    let p = r.u32()?;
    let (ux, uy, uz) = (p >> 21, (p & 0x001f_fc00) >> 10, p & 0x3ff);
    let x = f32::from_bits(
        ((((ux >> 7) & 7) + 123) << 23) | (((ux & 0x7F) | (32 * (ux & 0xFFFF_FC00))) << 16),
    );
    let y = f32::from_bits(
        ((((uy >> 7) & 7) + 123) << 23) | (((uy & 0x7F) | (32 * (uy & 0xFFFF_FC00))) << 16),
    );
    let z = f32::from_bits(
        ((((uz >> 6) & 7) + 123) << 23) | (((uz & 0x3F) | (32 * (uz & 0xFFFF_FE00))) << 17),
    );
    Ok(quat_w(x, y, z))
}

fn vec_fixed48(r: &mut Reader) -> Result<DVec3, String> {
    let mut c = || -> Result<f64, String> {
        Ok(f64::from(
            (i32::from(r.u16()?) - Q16_OFF) as f32 / Q16_DIV * 128.0,
        ))
    };
    Ok(DVec3::new(c()?, c()?, c()?))
}

fn vec_interval32(r: &mut Reader, mins: DVec3, ranges: DVec3) -> Result<DVec3, String> {
    let p = r.u32()?;
    let z = ((p >> 21) as i32 - Q11_OFF) as f32 / Q11_DIV;
    let y = (((p & 0x001f_fc00) >> 10) as i32 - Q11_OFF) as f32 / Q11_DIV;
    let x = ((p & 0x3ff) as i32 - Q10_OFF) as f32 / Q10_DIV;
    Ok(DVec3::new(
        f64::from(x) * ranges.x + mins.x,
        f64::from(y) * ranges.y + mins.y,
        f64::from(z) * ranges.z + mins.z,
    ))
}

fn fixed48_component(v: u16, log2: u32) -> f64 {
    let offset = (1i32 << (15 - log2)) - 1;
    let inv = 1.0 / f64::from(offset >> log2);
    f64::from(i32::from(v) - offset) * inv
}

/// The frame table after a track's keys: one byte per key when the clip
/// has under 256 frames, else two.
fn frame_table(r: &mut Reader, n: usize, num_frames: u32) -> Result<Vec<f32>, String> {
    let mut t = Vec::with_capacity(n);
    if n <= 1 {
        t.resize(n, 0.0);
        return Ok(t);
    }
    for _ in 0..n {
        t.push(if num_frames < 256 {
            f32::from(r.take::<1>()?[0])
        } else {
            f32::from(r.u16()?)
        });
    }
    r.align4();
    Ok(t)
}

fn mins_ranges_masked(r: &mut Reader, mask: u32) -> Result<(DVec3, DVec3), String> {
    let (mut mins, mut ranges) = (DVec3::ZERO, DVec3::ZERO);
    for (i, bit) in [1u32, 2, 4].into_iter().enumerate() {
        if mask & bit != 0 {
            mins[i] = f64::from(r.f32()?);
            ranges[i] = f64::from(r.f32()?);
        }
    }
    Ok((mins, ranges))
}

fn per_track_header(r: &mut Reader) -> Result<(u32, u32, usize), String> {
    let p = r.u32()?;
    Ok((p >> 28, (p >> 24) & 0xF, (p & 0xFF_FFFF) as usize))
}

fn per_track_quat(r: &mut Reader, num_frames: u32) -> Result<Keys<DQuat>, String> {
    let (format, mask, n) = per_track_header(r)?;
    let (mins, ranges) = if format == INTERVAL_FIXED32 {
        mins_ranges_masked(r, mask)?
    } else {
        (DVec3::ZERO, DVec3::ZERO)
    };
    let mut keys = Vec::with_capacity(n);
    for _ in 0..n {
        keys.push(match format {
            NONE | FLOAT96 => {
                let (x, y, z) = (r.f32()?, r.f32()?, r.f32()?);
                quat_w(x, y, z)
            }
            FIXED48 => quat_fixed48(r, mask)?,
            FIXED32 => quat_fixed32(r)?,
            INTERVAL_FIXED32 => quat_interval32(r, mins, ranges)?,
            FLOAT32 => quat_float32(r)?,
            IDENTITY => DQuat::IDENTITY,
            f => return Err(format!("rotation format {f}")),
        });
    }
    r.align4();
    let frames = if mask & 8 != 0 {
        Some(frame_table(r, n, num_frames)?)
    } else {
        None
    };
    Ok(Keys { keys, frames })
}

fn per_track_vec(r: &mut Reader, num_frames: u32) -> Result<Keys<DVec3>, String> {
    let (format, mask, n) = per_track_header(r)?;
    let (mins, ranges) = if format == INTERVAL_FIXED32 {
        mins_ranges_masked(r, mask)?
    } else {
        (DVec3::ZERO, DVec3::ZERO)
    };
    let mut keys = Vec::with_capacity(n);
    for _ in 0..n {
        keys.push(match format {
            NONE | FLOAT96 => {
                if mask & 7 != 0 {
                    let mut c = |bit: u32| -> Result<f64, String> {
                        Ok(if mask & bit != 0 {
                            f64::from(r.f32()?)
                        } else {
                            0.0
                        })
                    };
                    DVec3::new(c(1)?, c(2)?, c(4)?)
                } else {
                    r.vec3()?
                }
            }
            INTERVAL_FIXED32 => vec_interval32(r, mins, ranges)?,
            FIXED48 => {
                let mut c = |bit: u32| -> Result<f64, String> {
                    Ok(if mask & bit != 0 {
                        fixed48_component(r.u16()?, 7)
                    } else {
                        0.0
                    })
                };
                DVec3::new(c(1)?, c(2)?, c(4)?)
            }
            IDENTITY => DVec3::ZERO,
            f => return Err(format!("vector format {f}")),
        });
    }
    r.align4();
    let frames = if mask & 8 != 0 {
        Some(frame_table(r, n, num_frames)?)
    } else {
        None
    };
    Ok(Keys { keys, frames })
}

fn lerp_vec(
    r: &mut Reader,
    offset: i32,
    n: usize,
    mut format: u32,
    timed: bool,
    num_frames: u32,
) -> Result<Keys<DVec3>, String> {
    r.at(offset)?;
    // A single key is stored without compression.
    if n == 1 {
        format = NONE;
    }
    let (mins, ranges) = if format == INTERVAL_FIXED32 {
        (r.vec3()?, r.vec3()?)
    } else {
        (DVec3::ZERO, DVec3::ZERO)
    };
    let mut keys = Vec::with_capacity(n);
    for _ in 0..n {
        keys.push(match format {
            NONE | FLOAT96 => r.vec3()?,
            INTERVAL_FIXED32 => vec_interval32(r, mins, ranges)?,
            FIXED48 => vec_fixed48(r)?,
            IDENTITY => DVec3::ZERO,
            f => return Err(format!("vector format {f}")),
        });
    }
    r.align4();
    let frames = if timed {
        Some(frame_table(r, n, num_frames)?)
    } else {
        None
    };
    Ok(Keys { keys, frames })
}

fn lerp_quat(
    r: &mut Reader,
    offset: i32,
    n: usize,
    mut format: u32,
    timed: bool,
    num_frames: u32,
) -> Result<Keys<DQuat>, String> {
    r.at(offset)?;
    if n == 1 {
        format = FLOAT96;
    }
    let (mins, ranges) = if format == INTERVAL_FIXED32 {
        (r.vec3()?, r.vec3()?)
    } else {
        (DVec3::ZERO, DVec3::ZERO)
    };
    let mut keys = Vec::with_capacity(n);
    for _ in 0..n {
        keys.push(match format {
            NONE => {
                let (x, y, z, w) = (r.f32()?, r.f32()?, r.f32()?, r.f32()?);
                DQuat::from_xyzw(f64::from(x), f64::from(y), f64::from(z), f64::from(w))
            }
            FLOAT96 => {
                let (x, y, z) = (r.f32()?, r.f32()?, r.f32()?);
                quat_w(x, y, z)
            }
            FIXED48 => quat_fixed48(r, 7)?,
            FIXED32 => quat_fixed32(r)?,
            INTERVAL_FIXED32 => quat_interval32(r, mins, ranges)?,
            FLOAT32 => quat_float32(r)?,
            IDENTITY => DQuat::IDENTITY,
            f => return Err(format!("rotation format {f}")),
        });
    }
    r.align4();
    let frames = if timed {
        Some(frame_table(r, n, num_frames)?)
    } else {
        None
    };
    Ok(Keys { keys, frames })
}

/// Every track's keys. `default_scale` fills a track with no scale data
/// (1 for a normal clip, 0 for an additive one).
pub fn decode(d: &UeData, tracks: usize, default_scale: f64) -> Result<Vec<Track>, String> {
    let mut r = Reader {
        b: d.stream,
        pos: 0,
    };
    let no_scale = || Keys {
        keys: vec![DVec3::splat(default_scale)],
        frames: None,
    };
    let mut out = Vec::with_capacity(tracks);
    for t in 0..tracks {
        let track = if d.key_format == PER_TRACK {
            let at = |i: usize| d.track_offsets.get(i).copied().unwrap_or(-1);
            let (to, ro) = (at(t * 2), at(t * 2 + 1));
            let so = d.scale_offsets.get(t).copied().unwrap_or(-1);
            Track {
                pos: if to < 0 {
                    Keys {
                        keys: vec![DVec3::ZERO],
                        frames: None,
                    }
                } else {
                    r.at(to)?;
                    per_track_vec(&mut r, d.num_frames)?
                },
                rot: if ro < 0 {
                    Keys {
                        keys: vec![DQuat::IDENTITY],
                        frames: None,
                    }
                } else {
                    r.at(ro)?;
                    per_track_quat(&mut r, d.num_frames)?
                },
                scale: if so < 0 {
                    no_scale()
                } else {
                    r.at(so)?;
                    per_track_vec(&mut r, d.num_frames)?
                },
            }
        } else {
            let timed = d.key_format == VARIABLE_KEY_LERP;
            let o = d
                .track_offsets
                .get(t * 4..t * 4 + 4)
                .ok_or("track offsets shorter than the tracks")?;
            let (to, tn, ro, rn) = (o[0], o[1].max(0) as usize, o[2], o[3].max(0) as usize);
            let (so, sn) = match d.scale_offsets.get(t * 2..t * 2 + 2) {
                Some(s) => (s[0], s[1].max(0) as usize),
                None => (0, 0),
            };
            Track {
                pos: if tn > 0 {
                    lerp_vec(&mut r, to, tn, d.translation_format, timed, d.num_frames)?
                } else {
                    Keys {
                        keys: vec![DVec3::ZERO],
                        frames: None,
                    }
                },
                scale: if sn > 0 && so > 0 {
                    lerp_vec(&mut r, so, sn, d.scale_format, timed, d.num_frames)?
                } else {
                    no_scale()
                },
                rot: if rn > 0 {
                    lerp_quat(&mut r, ro, rn, d.rotation_format, timed, d.num_frames)?
                } else {
                    Keys {
                        keys: vec![DQuat::IDENTITY],
                        frames: None,
                    }
                },
            }
        };
        out.push(track);
    }
    Ok(out)
}

/// The two keys around `rel` (0..1 through the clip) and the blend
/// between them. Keys spread evenly unless there is a frame table, whose
/// entries are frames of the clip's `num_frames`.
fn bracket(
    n: usize,
    frames: Option<&[f32]>,
    rel: f64,
    num_frames: u32,
    step: bool,
) -> (usize, usize, f64) {
    if n <= 1 {
        return (0, 0, 0.0);
    }
    let (i0, i1, a) = match frames {
        None => {
            let pos = rel * (n - 1) as f64;
            let i0 = (pos.floor() as usize).min(n - 1);
            (i0, (i0 + 1).min(n - 1), pos - i0 as f64)
        }
        Some(f) => {
            let pos = rel * f64::from(num_frames.saturating_sub(1));
            let i1 = f.iter().position(|&k| f64::from(k) > pos).unwrap_or(n - 1);
            let i0 = i1.saturating_sub(1);
            let (f0, f1) = (f64::from(f[i0]), f64::from(f[i1]));
            let a = if f1 > f0 { (pos - f0) / (f1 - f0) } else { 0.0 };
            (i0, i1, a)
        }
    };
    let a = a.clamp(0.0, 1.0);
    if step { (i0, i1, 0.0) } else { (i0, i1, a) }
}

impl Track {
    /// This track at `rel` (0..1 through the clip).
    pub fn sample(&self, rel: f64, num_frames: u32, step: bool) -> (DQuat, DVec3, DVec3) {
        let (r0, r1, ra) = bracket(
            self.rot.keys.len(),
            self.rot.frames.as_deref(),
            rel,
            num_frames,
            step,
        );
        let (q0, mut q1) = (self.rot.keys[r0], self.rot.keys[r1]);
        // FQuat::FastLerp: blend the shorter way, then normalize.
        if q0.dot(q1) < 0.0 {
            q1 = -q1;
        }
        let rot = (q0 * (1.0 - ra) + q1 * ra).normalize();
        let vec = |k: &Keys<DVec3>| {
            let (i0, i1, a) = bracket(k.keys.len(), k.frames.as_deref(), rel, num_frames, step);
            k.keys[i0].lerp(k.keys[i1], a)
        };
        (rot, vec(&self.pos), vec(&self.scale))
    }
}

/// One track to write: each part's keys, None for a part the clip has no
/// data for (the decoder then uses its default).
pub struct TrackKeys {
    pub pos: Option<Vec<DVec3>>,
    pub rot: Option<Vec<DQuat>>,
    pub scale: Option<Vec<DVec3>>,
}

/// UE per-track data as FUECompressedAnimData holds it: two offsets per
/// track (translation, rotation), one scale offset per track, and the
/// byte stream.
pub struct Written {
    pub offsets: Vec<i32>,
    pub scale_offsets: Vec<i32>,
    pub stream: Vec<u8>,
}

/// Write `tracks` in UE's per track key format (the reverse of
/// per_track_vec and per_track_quat): every part as full floats
/// (Float96: rotations x y z with w made positive, vectors x y z), one
/// key per frame, no frame table. `scale` false leaves the scale offsets
/// empty, for a clip with no scale data.
pub fn encode_per_track(tracks: &[TrackKeys], scale: bool) -> Written {
    let mut stream: Vec<u8> = Vec::new();
    let mut offsets = Vec::with_capacity(tracks.len() * 2);
    let mut scale_offsets = Vec::new();
    let f = |s: &mut Vec<u8>, x: f64| s.extend_from_slice(&(x as f32).to_le_bytes());
    let header = |s: &mut Vec<u8>, n: usize| {
        s.extend_from_slice(&((FLOAT96 << 28) | (n as u32 & 0xFF_FFFF)).to_le_bytes());
    };
    let vecs = |s: &mut Vec<u8>, keys: &Option<Vec<DVec3>>| -> i32 {
        let Some(keys) = keys else { return -1 };
        let at = s.len() as i32;
        header(s, keys.len());
        for k in keys {
            f(s, k.x);
            f(s, k.y);
            f(s, k.z);
        }
        at
    };
    for t in tracks {
        offsets.push(vecs(&mut stream, &t.pos));
        offsets.push(match &t.rot {
            None => -1,
            Some(keys) => {
                let at = stream.len() as i32;
                header(&mut stream, keys.len());
                for q in keys {
                    let q = if q.w < 0.0 { -*q } else { *q }.normalize();
                    f(&mut stream, q.x);
                    f(&mut stream, q.y);
                    f(&mut stream, q.z);
                }
                at
            }
        });
        if scale {
            scale_offsets.push(vecs(&mut stream, &t.scale));
        }
    }
    Written {
        offsets,
        scale_offsets,
        stream,
    }
}

#[cfg(test)]
mod tests {
    /// What encode_per_track writes decodes back to the same keys.
    #[test]
    fn per_track_round_trip() {
        let q = DQuat::from_rotation_y(0.7) * DQuat::from_rotation_x(-0.3);
        let tracks = [
            TrackKeys {
                pos: Some(vec![
                    DVec3::new(1.0, 2.0, 3.0),
                    DVec3::new(-4.0, 5.5, 60.25),
                ]),
                rot: Some(vec![DQuat::IDENTITY, -q]),
                scale: Some(vec![DVec3::ONE, DVec3::splat(0.5)]),
            },
            TrackKeys {
                pos: None,
                rot: Some(vec![q, q]),
                scale: None,
            },
        ];
        let w = encode_per_track(&tracks, true);
        let d = UeData {
            key_format: PER_TRACK,
            translation_format: 0,
            rotation_format: 0,
            scale_format: 0,
            num_frames: 2,
            track_offsets: &w.offsets,
            scale_offsets: &w.scale_offsets,
            stream: &w.stream,
        };
        let t = decode(&d, 2, 1.0).unwrap();
        let (r, p, s) = t[0].sample(1.0, 2, false);
        assert!((p - DVec3::new(-4.0, 5.5, 60.25)).length() < 1e-4);
        assert!(r.dot(q).abs() > 0.99999);
        assert!((s - DVec3::splat(0.5)).length() < 1e-6);
        let (r, p, s) = t[1].sample(0.0, 2, false);
        assert_eq!(p, DVec3::ZERO);
        assert!(r.dot(q).abs() > 0.99999);
        assert_eq!(s, DVec3::ONE);
    }

    use super::*;

    fn f(v: &mut Vec<u8>, x: f32) {
        v.extend_from_slice(&x.to_le_bytes());
    }

    /// One constant key lerp track: translation 2 keys of full floats,
    /// rotation 2 keys of 48-bit packing, no scale. Halfway through the
    /// clip is halfway between the keys.
    #[test]
    fn constant_key_lerp_blends_between_keys() {
        let mut s = Vec::new();
        for x in [0.0, 0.0, 0.0, 10.0, 20.0, 30.0] {
            f(&mut s, x);
        }
        let rot_at = s.len() as i32;
        // Identity, then 90 degrees about Z: z = sin(45) = 0.7071.
        for q in [[0.0f32, 0.0, 0.0], [0.0, 0.0, 0.707_106_8]] {
            for c in q {
                s.extend_from_slice(&((c * Q16_DIV) as i32 + Q16_OFF).to_le_bytes()[..2]);
            }
        }
        let offsets = [0, 2, rot_at, 2];
        let d = UeData {
            key_format: CONSTANT_KEY_LERP,
            translation_format: NONE,
            rotation_format: FIXED48,
            scale_format: NONE,
            num_frames: 2,
            track_offsets: &offsets,
            scale_offsets: &[],
            stream: &s,
        };
        let t = decode(&d, 1, 1.0).unwrap();
        let (rot, pos, scale) = t[0].sample(0.5, 2, false);
        assert!((pos - DVec3::new(5.0, 10.0, 15.0)).length() < 1e-6);
        assert!((scale - DVec3::ONE).length() < 1e-9);
        let half = DQuat::from_rotation_z(45f64.to_radians());
        assert!(rot.dot(half).abs() > 0.9999, "{rot:?}");
        let (rot, pos, _) = t[0].sample(1.0, 2, false);
        assert!((pos - DVec3::new(10.0, 20.0, 30.0)).length() < 1e-6);
        assert!(rot.dot(DQuat::from_rotation_z(90f64.to_radians())).abs() > 0.9999);
    }

    /// A frame table puts keys at their frames, not evenly.
    #[test]
    fn frame_table_places_keys() {
        let k = Keys {
            keys: vec![DVec3::ZERO, DVec3::splat(10.0)],
            frames: Some(vec![0.0, 4.0]),
        };
        // 11 frames: rel 0.2 is frame 2, half way from frame 0 to 4.
        let (i0, i1, a) = bracket(2, k.frames.as_deref(), 0.2, 11, false);
        assert_eq!((i0, i1), (0, 1));
        assert!((a - 0.5).abs() < 1e-9);
        // Past the last key holds it.
        let (_, i1, a) = bracket(2, k.frames.as_deref(), 0.9, 11, false);
        assert_eq!(i1, 1);
        assert!((a - 1.0).abs() < 1e-9);
    }

    /// Per track: the packed header gives format, mask and key count;
    /// a missing component reads as 0.
    #[test]
    fn per_track_vector_masked() {
        let mut s = Vec::new();
        // Float96, mask x and z (1 | 4), 1 key.
        s.extend_from_slice(&((FLOAT96 << 28) | (5 << 24) | 1).to_le_bytes());
        f(&mut s, 3.0);
        f(&mut s, 7.0);
        let mut r = Reader { b: &s, pos: 0 };
        let k = per_track_vec(&mut r, 1).unwrap();
        assert_eq!(k.keys, vec![DVec3::new(3.0, 0.0, 7.0)]);
        assert!(k.frames.is_none());
    }
}

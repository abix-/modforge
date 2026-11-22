//! UE's compressed rich curve stream (AnimCurveCompressionCodec_
//! CompressedRichCurve): read every curve's value at a time, and write
//! a new stream. Asked 2026-11-22 (wickedisland openings in the Ogre and
//! Troll female animations, whose curves use this codec: "we need the
//! framework updates needed to rewrite sruves and mrophs righ?!?! same
//! way the scnes do").
//!
//! Layout from UE 5.4 and 5.8 source (the same in both; the game is
//! 5.6): AnimCurveCompressionCodec_CompressedRichCurve.cpp Compress
//! writes one 12-byte FCurveDesc per curve (compression format, key time
//! format, pre and post infinity extrapolation as bytes, then the
//! constant value or the key count, then the key data's offset from the
//! stream start), then each curve's keys as FRichCurve::CompressCurve
//! lays them out (RichCurve.cpp): interp modes (mixed: one byte a key;
//! weighted: two), key times (uint16 normalized plus min time and range,
//! or float32), then per key the value and, for cubic and mixed, the
//! arrive and leave tangents (MIXEDKEY_STRIPS_TANGENTS is 0). Reading
//! follows InterpEval there. Curve k's descriptor goes with the k-th
//! entry of the sequence's curve name table (DecompressCurves).
//!
//! Writing gives every curve a linear key at every sample with float32
//! times, keeping each curve's extrapolation: the codec then returns
//! the samples exactly and blends linearly between them, as the ACL
//! curve codec does.

const DESC: usize = 12;

// ERichCurveCompressionFormat.
const EMPTY: u8 = 0;
const CONSTANT: u8 = 1;
const LINEAR: u8 = 2;
const CUBIC: u8 = 3;
const MIXED: u8 = 4;
const WEIGHTED: u8 = 5;
// ERichCurveKeyTimeCompressionFormat.
const TIME_U16: u8 = 0;
const TIME_F32: u8 = 1;
// ERichCurveExtrapolation (0 is Cycle, the remap's default case).
#[cfg(test)]
const CYCLE: u8 = 0;
const CYCLE_WITH_OFFSET: u8 = 1;
const OSCILLATE: u8 = 2;
const EXTRAP_LINEAR: u8 = 3;
const EXTRAP_CONSTANT: u8 = 4;

/// One curve's descriptor.
#[derive(Clone, Copy, Debug)]
pub struct Desc {
    pub format: u8,
    pub key_time: u8,
    pub pre: u8,
    pub post: u8,
    /// The constant value's bits (empty, constant) or the key count.
    pub value_or_keys: u32,
    pub offset: i32,
}

fn f32_at(b: &[u8], at: usize) -> Result<f32, String> {
    b.get(at..at + 4)
        .map(|s| f32::from_le_bytes([s[0], s[1], s[2], s[3]]))
        .ok_or_else(|| format!("rich curve read past the stream at {at}"))
}

fn u16_at(b: &[u8], at: usize) -> Result<u16, String> {
    b.get(at..at + 2)
        .map(|s| u16::from_le_bytes([s[0], s[1]]))
        .ok_or_else(|| format!("rich curve read past the stream at {at}"))
}

fn align(x: usize, a: usize) -> usize {
    x.div_ceil(a) * a
}

/// Curve `k`'s descriptor in `stream`.
pub fn desc(stream: &[u8], k: usize) -> Result<Desc, String> {
    let d = stream
        .get(k * DESC..(k + 1) * DESC)
        .ok_or_else(|| format!("no descriptor for curve {k}"))?;
    Ok(Desc {
        format: d[0],
        key_time: d[1],
        pre: d[2],
        post: d[3],
        value_or_keys: u32::from_le_bytes([d[4], d[5], d[6], d[7]]),
        offset: i32::from_le_bytes([d[8], d[9], d[10], d[11]]),
    })
}

/// One curve's keys, read from the stream.
struct Keys<'a> {
    b: &'a [u8],
    n: usize,
    modes_at: usize,
    weighted: bool,
    times_at: usize,
    u16_range: Option<(f32, f32)>,
    data_at: usize,
    /// Floats per key in the key data.
    stride: usize,
    uniform: u8,
}

impl<'a> Keys<'a> {
    fn new(b: &'a [u8], d: &Desc) -> Result<Self, String> {
        let n = d.value_or_keys as usize;
        if n == 0 || d.offset < 0 {
            return Err("a keyed rich curve with no keys".into());
        }
        let base = d.offset as usize;
        let mode_bytes = match d.format {
            MIXED => n,
            WEIGHTED => 2 * n,
            _ => 0,
        };
        let (times_at, u16_range, data_at) = match d.key_time {
            TIME_U16 => {
                let t = base + align(mode_bytes, 2);
                let r = base + align(t - base + n * 2, 4);
                (t, Some((f32_at(b, r)?, f32_at(b, r + 4)?)), r + 8)
            }
            TIME_F32 => {
                let t = base + align(mode_bytes, 4);
                (t, None, base + align(t - base + n * 4, 4))
            }
            f => return Err(format!("rich curve key time format {f}")),
        };
        let stride = match d.format {
            LINEAR => 1,
            CUBIC | MIXED => 3,
            WEIGHTED => 5,
            f => return Err(format!("rich curve format {f} has no keys")),
        };
        if b.len() < data_at + n * stride * 4 {
            return Err("rich curve keys run past the stream".into());
        }
        Ok(Keys {
            b,
            n,
            modes_at: base,
            weighted: d.format == WEIGHTED,
            times_at,
            u16_range,
            data_at,
            stride,
            uniform: d.format,
        })
    }

    fn time(&self, i: usize) -> Result<f32, String> {
        match self.u16_range {
            Some((min, range)) => {
                Ok(u16_at(self.b, self.times_at + i * 2)? as f32 * (1.0 / 65535.0) * range + min)
            }
            None => f32_at(self.b, self.times_at + i * 4),
        }
    }

    fn float(&self, i: usize, k: usize) -> Result<f32, String> {
        f32_at(self.b, self.data_at + (i * self.stride + k) * 4)
    }

    fn value(&self, i: usize) -> Result<f32, String> {
        self.float(i, 0)
    }

    fn mode(&self, i: usize) -> u8 {
        match self.uniform {
            MIXED => self.b[self.modes_at + i],
            WEIGHTED => self.b[self.modes_at + 2 * i],
            f => f,
        }
    }

    /// RichCurve.cpp InterpEvalExtrapolate.
    fn extrapolate(
        &self,
        t: f32,
        extrap: u8,
        i0: usize,
        i1: usize,
        t0: f32,
    ) -> Result<f32, String> {
        let v0 = self.value(i0)?;
        if extrap != EXTRAP_LINEAR {
            return Ok(v0);
        }
        let dt = self.time(i1)? - t0;
        if dt.abs() <= 1e-8 {
            return Ok(v0);
        }
        Ok((self.value(i1)? - v0) / dt * (t - t0) + v0)
    }

    /// RichCurve.cpp CycleTime and RemapTimeValue.
    fn remap(
        &self,
        mut t: f32,
        extrap: u8,
        i0: usize,
        i1: usize,
        offset: &mut f32,
    ) -> Result<f32, String> {
        let min = self.time(0)?;
        let max = self.time(self.n - 1)?;
        let init = t;
        let dur = max - min;
        let mut count = 0i32;
        if t > max {
            count = ((max - t) / dur).floor() as i32;
            t += dur * count as f32;
        } else if t < min {
            count = ((t - min) / dur).floor() as i32;
            t -= dur * count as f32;
        }
        if t == max && init < min {
            t = min;
        }
        if t == min && init > max {
            t = max;
        }
        let count = count.abs();
        if extrap == CYCLE_WITH_OFFSET {
            *offset = (self.value(i0)? - self.value(i1)?) * count as f32;
        } else if extrap == OSCILLATE && count % 2 == 1 {
            t = min + (max - t);
        }
        Ok(t)
    }

    /// RichCurve.cpp InterpEval.
    fn eval(&self, mut t: f32, pre: u8, post: u8) -> Result<f32, String> {
        let n = self.n;
        let mut offset = 0f32;
        let first = self.time(0)?;
        if t < first {
            if pre != EXTRAP_LINEAR && pre != EXTRAP_CONSTANT {
                t = self.remap(t, pre, 0, n - 1, &mut offset)?;
            } else {
                return self.extrapolate(t, pre, 0, 1.min(n - 1), first);
            }
        }
        let last = self.time(n - 1)?;
        if t > last {
            if post != EXTRAP_LINEAR && post != EXTRAP_CONSTANT {
                t = self.remap(t, post, n - 1, 0, &mut offset)?;
            } else {
                return self.extrapolate(t, post, n - 1, n.saturating_sub(2), last);
            }
        }
        if n == 1 {
            return Ok(self.value(0)? + offset);
        }
        let (mut lo, mut count) = (1usize, n - 2);
        while count > 0 {
            let step = count / 2;
            let mid = lo + step;
            if t >= self.time(mid)? {
                lo = mid + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        let (i0, i1) = (lo - 1, lo);
        let (t0, t1) = (self.time(i0)?, self.time(i1)?);
        let diff = t1 - t0;
        let v0 = self.value(i0)?;
        if diff <= 0.0 {
            return Ok(v0 + offset);
        }
        let v1 = self.value(i1)?;
        let alpha = (t - t0) / diff;
        let v = match self.mode(i0) {
            CONSTANT => {
                if t < t1 {
                    v0
                } else {
                    v1
                }
            }
            LINEAR => v0 + (v1 - v0) * alpha,
            _ => {
                if self.weighted {
                    return Err("weighted rich curve keys are not read".into());
                }
                let third = diff / 3.0;
                let p1 = v0 + self.float(i0, 2)? * third;
                let p2 = v1 - self.float(i1, 1)? * third;
                bezier(v0, p1, p2, v1, alpha)
            }
        };
        Ok(v + offset)
    }
}

/// UE::Curves::BezierInterp.
fn bezier(p0: f32, p1: f32, p2: f32, p3: f32, a: f32) -> f32 {
    let lerp = |x: f32, y: f32| x + (y - x) * a;
    let (p01, p12, p23) = (lerp(p0, p1), lerp(p1, p2), lerp(p2, p3));
    let (p012, p123) = (lerp(p01, p12), lerp(p12, p23));
    lerp(p012, p123)
}

/// Curve `k`'s value at `time` seconds (FCompressedRichCurve::
/// StaticEval with a default value of 0).
pub fn eval(stream: &[u8], k: usize, time: f32) -> Result<f32, String> {
    let d = desc(stream, k)?;
    match d.format {
        EMPTY => {
            let v = f32::from_bits(d.value_or_keys);
            Ok(if v == f32::MAX { 0.0 } else { v })
        }
        CONSTANT => Ok(f32::from_bits(d.value_or_keys)),
        _ => Keys::new(stream, &d)?.eval(time, d.pre, d.post),
    }
}

/// A new stream: `values[sample][curve]` at `rate` samples a second,
/// each curve a linear key at every sample with float32 times, and the
/// extrapolation in `extrap[curve]` (pre, post).
pub fn encode(values: &[Vec<f32>], rate: f32, extrap: &[(u8, u8)]) -> Result<Vec<u8>, String> {
    let n = extrap.len();
    let s = values.len();
    if n == 0 || s == 0 || values.iter().any(|v| v.len() != n) {
        return Err("curve values do not match the curves".into());
    }
    let per_curve = s * 8;
    let mut out = Vec::with_capacity(n * (DESC + per_curve));
    for (k, &(pre, post)) in extrap.iter().enumerate() {
        out.extend_from_slice(&[LINEAR, TIME_F32, pre, post]);
        out.extend_from_slice(&(s as u32).to_le_bytes());
        out.extend_from_slice(&((n * DESC + k * per_curve) as i32).to_le_bytes());
    }
    for k in 0..n {
        for i in 0..s {
            out.extend_from_slice(&(i as f32 / rate.max(1e-6)).to_le_bytes());
        }
        for v in values {
            out.extend_from_slice(&v[k].to_le_bytes());
        }
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn encode_reads_back() {
        let values: Vec<Vec<f32>> = (0..5)
            .map(|i| vec![i as f32 * 0.25, 1.0 - i as f32 * 0.1])
            .collect();
        let b = encode(&values, 30.0, &[(EXTRAP_CONSTANT, EXTRAP_CONSTANT); 2]).unwrap();
        for (i, v) in values.iter().enumerate() {
            for k in 0..2 {
                assert!((eval(&b, k, i as f32 / 30.0).unwrap() - v[k]).abs() < 1e-6);
            }
        }
        // Halfway between samples 1 and 2, linear.
        assert!((eval(&b, 0, 1.5 / 30.0).unwrap() - 0.375).abs() < 1e-6);
        // Past the end holds the last value.
        assert!((eval(&b, 1, 1.0).unwrap() - 0.6).abs() < 1e-6);
    }

    #[test]
    fn cubic_u16_as_ue_lays_it_out() {
        // One cubic curve, uint16 times: 2 keys (0 s, 1 s), values 0 and
        // 1, flat tangents: the Bezier halfway is 0.5.
        let mut b = vec![CUBIC, TIME_U16, EXTRAP_CONSTANT, EXTRAP_CONSTANT];
        b.extend_from_slice(&2u32.to_le_bytes());
        b.extend_from_slice(&(DESC as i32).to_le_bytes());
        b.extend_from_slice(&0u16.to_le_bytes());
        b.extend_from_slice(&65535u16.to_le_bytes());
        b.extend_from_slice(&0f32.to_le_bytes());
        b.extend_from_slice(&1f32.to_le_bytes());
        for x in [0f32, 0.0, 0.0, 1.0, 0.0, 0.0] {
            b.extend_from_slice(&x.to_le_bytes());
        }
        assert!((eval(&b, 0, 0.5).unwrap() - 0.5).abs() < 1e-6);
        assert!(eval(&b, 0, 0.25).unwrap() < 0.25);
        assert_eq!(eval(&b, 0, 2.0).unwrap(), 1.0);
    }

    #[test]
    fn cycle_wraps() {
        let values = vec![vec![0.0], vec![1.0], vec![2.0]];
        let b = encode(&values, 1.0, &[(CYCLE, CYCLE)]).unwrap();
        // 2.5 s past a 0..2 s curve wraps to 0.5 s.
        assert!((eval(&b, 0, 2.5).unwrap() - 0.5).abs() < 1e-5);
    }
}

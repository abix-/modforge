//! A skeletal mesh's morph targets as the graphics card draws them, read
//! from and written back to the cooked mesh file (the legacy .uexp that
//! retoc to-legacy extracts). The running game keeps no CPU copy of the
//! deltas (the morph targets' own vertex lists are empty, read live
//! 2026-11-23), so a rewritten or added morph goes into this data in the
//! file, which the game then loads like its own (operator 2026-11-23:
//! "there's already morphs. we rewrite and add more morphs").
//!
//! The format is UE 5.6.1's FMorphTargetVertexInfoBuffers, serialized per
//! LOD in the mesh's render data: the packed words (one 10-word header
//! per batch of up to 64 deltas, then the bitstream), the per-morph
//! minimum and maximum, each morph's first batch and batch count, the
//! batch total and the two precisions. Encoding follows
//! FMorphTargetVertexInfoBuffers::Compress
//! (Engine/Source/Runtime/Engine/Private/Rendering/
//! MorphTargetVertexInfoBuffers.cpp, as in Viktor4221/ue5.6.1); decoding
//! follows it and CUE4Parse's FMorphTargetVertexInfoBuffers.cs.

/// Deltas per batch (Compress's BatchSize).
const BATCH: usize = 64;
/// Words in a batch header.
const HEADER_WORDS: usize = 10;

/// One moved vertex, quantized: positions in units of the LOD's
/// position precision, tangents in units of its tangent precision.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Delta {
    pub index: u32,
    pub position: [i32; 3],
    pub tangent: [i32; 3],
}

/// One LOD's morph data, as in the file.
#[derive(Clone, Debug, PartialEq)]
pub struct Buffers {
    /// Byte offset of the first field in the file.
    pub at: usize,
    /// Byte length of the serialized fields.
    pub len: usize,
    pub words: Vec<u32>,
    pub minimum: Vec<[f32; 4]>,
    pub maximum: Vec<[f32; 4]>,
    pub batch_start: Vec<u32>,
    pub batches: Vec<u32>,
    pub total_batches: u32,
    pub position_precision: f32,
    pub tangent_precision: f32,
}

fn u32_at(b: &[u8], o: usize) -> Option<u32> {
    Some(u32::from_le_bytes(b.get(o..o + 4)?.try_into().ok()?))
}

fn f32_at(b: &[u8], o: usize) -> Option<f32> {
    u32_at(b, o).map(f32::from_bits)
}

impl Buffers {
    /// The morph data serialized at `at`, when every field is consistent
    /// (the counts match, the batches add up, the first header points
    /// past all headers).
    fn parse(b: &[u8], at: usize) -> Option<Buffers> {
        let n_words = u32_at(b, at)? as usize;
        let mut o = at + 4;
        let words: Vec<u32> = (0..n_words)
            .map(|i| u32_at(b, o + 4 * i))
            .collect::<Option<_>>()?;
        o += 4 * n_words;
        let m = u32_at(b, o)? as usize;
        if m == 0 || m > 65_536 {
            return None;
        }
        let vec4s = |o: usize| -> Option<Vec<[f32; 4]>> {
            (0..m)
                .map(|i| {
                    let p = o + 16 * i;
                    Some([
                        f32_at(b, p)?,
                        f32_at(b, p + 4)?,
                        f32_at(b, p + 8)?,
                        f32_at(b, p + 12)?,
                    ])
                })
                .collect()
        };
        let minimum = vec4s(o + 4)?;
        o += 4 + 16 * m;
        if u32_at(b, o)? as usize != m {
            return None;
        }
        let maximum = vec4s(o + 4)?;
        o += 4 + 16 * m;
        let u32s =
            |o: usize| -> Option<Vec<u32>> { (0..m).map(|i| u32_at(b, o + 4 * i)).collect() };
        if u32_at(b, o)? as usize != m {
            return None;
        }
        let batch_start = u32s(o + 4)?;
        o += 4 + 4 * m;
        if u32_at(b, o)? as usize != m {
            return None;
        }
        let batches = u32s(o + 4)?;
        o += 4 + 4 * m;
        let total_batches = u32_at(b, o)?;
        let position_precision = f32_at(b, o + 4)?;
        let tangent_precision = f32_at(b, o + 8)?;
        o += 12;
        let mut next = 0u32;
        for (s, n) in batch_start.iter().zip(&batches) {
            if *s != next {
                return None;
            }
            next += n;
        }
        let total = total_batches as usize;
        if next != total_batches
            || !(position_precision > 0.0 && tangent_precision > 0.0)
            || (total > 0 && words.first().copied() != Some((total * HEADER_WORDS * 4) as u32))
            || words.len() < total * HEADER_WORDS
        {
            return None;
        }
        Some(Buffers {
            at,
            len: o - at,
            words,
            minimum,
            maximum,
            batch_start,
            batches,
            total_batches,
            position_precision,
            tangent_precision,
        })
    }

    /// Every LOD's morph data in a cooked mesh file, in file order: found
    /// at each place the per-morph counts repeat four times with a
    /// consistent layout around them.
    pub fn find_all(b: &[u8]) -> Vec<Buffers> {
        let mut found = Vec::new();
        let mut q = 0;
        while q + 16 < b.len() {
            let Some(m) = u32_at(b, q).map(|m| m as usize) else {
                break;
            };
            let hit = (1..=65_536).contains(&m)
                && u32_at(b, q + 4 + 16 * m) == Some(m as u32)
                && u32_at(b, q + 8 + 32 * m) == Some(m as u32)
                && u32_at(b, q + 12 + 36 * m) == Some(m as u32);
            if hit {
                // The packed words end at q: find their length prefix.
                let start = (8..=q)
                    .step_by(4)
                    .map(|d| q - d)
                    .find(|&s| u32_at(b, s).is_some_and(|n| s + 4 + 4 * n as usize == q));
                if let Some(buf) = start.and_then(|s| Buffers::parse(b, s)) {
                    q = buf.at + buf.len;
                    found.push(buf);
                    continue;
                }
            }
            q += 1;
        }
        found
    }

    /// The deltas of morph `m`, in index order.
    pub fn decode(&self, m: usize) -> Vec<Delta> {
        let first = self.batch_start[m] as usize;
        let mut out = Vec::new();
        for batch in first..first + self.batches[m] as usize {
            let h = &self.words[batch * HEADER_WORDS..(batch + 1) * HEADER_WORDS];
            let index_bits = h[1] & 0x1F;
            let pos_bits = [(h[1] >> 5) & 0x1F, (h[1] >> 10) & 0x1F, (h[1] >> 15) & 0x1F];
            let tangents = (h[1] >> 20) & 1 == 1;
            let n = (h[1] >> 21) as usize;
            let tan_bits = [h[6] & 0x1F, (h[6] >> 5) & 0x1F, (h[6] >> 10) & 0x1F];
            let pos_min = [h[3] as i32, h[4] as i32, h[5] as i32];
            let tan_min = [h[7] as i32, h[8] as i32, h[9] as i32];
            let mut r = BitReader {
                words: &self.words,
                bit: (h[0] as usize) * 8,
            };
            for local in 0..n {
                let index = h[2] + local as u32 + r.get(index_bits);
                let mut position = [0; 3];
                for k in 0..3 {
                    position[k] = pos_min[k].wrapping_add(r.get(pos_bits[k]) as i32);
                }
                let mut tangent = [0; 3];
                if tangents {
                    for k in 0..3 {
                        tangent[k] = tan_min[k].wrapping_add(r.get(tan_bits[k]) as i32);
                    }
                }
                out.push(Delta {
                    index,
                    position,
                    tangent,
                });
            }
        }
        out
    }

    /// Every morph's deltas.
    pub fn decode_all(&self) -> Vec<Vec<Delta>> {
        (0..self.batches.len()).map(|m| self.decode(m)).collect()
    }

    /// This LOD's data rebuilt from every morph's deltas (sorted by
    /// index, zero deltas dropped), as Compress lays it out. The minimum
    /// and maximum per morph stay as given.
    pub fn encode(&self, morphs: &[Vec<Delta>]) -> Buffers {
        let mut headers: Vec<[u32; HEADER_WORDS]> = Vec::new();
        let mut bits: Vec<u32> = Vec::new();
        let mut batch_start = Vec::with_capacity(morphs.len());
        let mut batches = Vec::with_capacity(morphs.len());
        for deltas in morphs {
            let mut d: Vec<Delta> = deltas
                .iter()
                .filter(|d| d.position != [0; 3] || d.tangent != [0; 3])
                .copied()
                .collect();
            d.sort_by_key(|d| d.index);
            batch_start.push(headers.len() as u32);
            for chunk in d.chunks(BATCH) {
                headers.push(encode_batch(chunk, &mut bits));
            }
            batches.push(headers.len() as u32 - batch_start.last().unwrap());
        }
        let head = (headers.len() * HEADER_WORDS * 4) as u32;
        let mut words = Vec::with_capacity(headers.len() * HEADER_WORDS + bits.len() + 3);
        for mut h in headers.iter().copied() {
            h[0] += head;
            words.extend_from_slice(&h);
        }
        words.extend_from_slice(&bits);
        if !words.is_empty() {
            words.extend_from_slice(&[0, 0, 0]);
        }
        let total_batches = headers.len() as u32;
        let mut out = Buffers {
            at: self.at,
            len: 0,
            words,
            minimum: self.minimum.clone(),
            maximum: self.maximum.clone(),
            batch_start,
            batches,
            total_batches,
            position_precision: self.position_precision,
            tangent_precision: self.tangent_precision,
        };
        out.len = out.to_bytes().len();
        out
    }

    /// The fields as the file stores them.
    pub fn to_bytes(&self) -> Vec<u8> {
        let mut b = Vec::new();
        let n = |b: &mut Vec<u8>, v: usize| b.extend_from_slice(&(v as u32).to_le_bytes());
        n(&mut b, self.words.len());
        self.words
            .iter()
            .for_each(|w| b.extend_from_slice(&w.to_le_bytes()));
        for v in [&self.minimum, &self.maximum] {
            n(&mut b, v.len());
            v.iter()
                .flatten()
                .for_each(|f| b.extend_from_slice(&f.to_le_bytes()));
        }
        for v in [&self.batch_start, &self.batches] {
            n(&mut b, v.len());
            v.iter().for_each(|w| b.extend_from_slice(&w.to_le_bytes()));
        }
        b.extend_from_slice(&self.total_batches.to_le_bytes());
        b.extend_from_slice(&self.position_precision.to_le_bytes());
        b.extend_from_slice(&self.tangent_precision.to_le_bytes());
        b
    }
}

/// Bits needed for values 0..=v (FMath::CeilLogTwo(v + 1)).
fn bits_for(v: u32) -> u32 {
    32 - v.leading_zeros()
}

/// One batch's header (data offset relative to the bitstream) and its
/// bits appended to `bits`, as Compress writes them.
fn encode_batch(d: &[Delta], bits: &mut Vec<u32>) -> [u32; HEADER_WORDS] {
    let adjusted = |i: usize| d[i].index - i as u32;
    let index_min = (0..d.len()).map(adjusted).min().unwrap();
    let index_max = (0..d.len()).map(adjusted).max().unwrap();
    let mut pos_min = [i32::MAX; 3];
    let mut pos_max = [i32::MIN; 3];
    let mut tan_min = [i32::MAX; 3];
    let mut tan_max = [i32::MIN; 3];
    for e in d {
        for k in 0..3 {
            pos_min[k] = pos_min[k].min(e.position[k]);
            pos_max[k] = pos_max[k].max(e.position[k]);
            tan_min[k] = tan_min[k].min(e.tangent[k]);
            tan_max[k] = tan_max[k].max(e.tangent[k]);
        }
    }
    let tangents = tan_min != [0; 3] || tan_max != [0; 3];
    let index_bits = bits_for(index_max - index_min);
    let pos_bits: [u32; 3] =
        std::array::from_fn(|k| bits_for(pos_max[k].wrapping_sub(pos_min[k]) as u32));
    let tan_bits: [u32; 3] =
        std::array::from_fn(|k| bits_for(tan_max[k].wrapping_sub(tan_min[k]) as u32));
    let offset = (bits.len() * 4) as u32;
    let mut w = BitWriter {
        out: bits,
        pending: 0,
        n: 0,
    };
    for (i, e) in d.iter().enumerate() {
        w.put(adjusted(i) - index_min, index_bits);
        for k in 0..3 {
            w.put(e.position[k].wrapping_sub(pos_min[k]) as u32, pos_bits[k]);
        }
        if tangents {
            for k in 0..3 {
                w.put(e.tangent[k].wrapping_sub(tan_min[k]) as u32, tan_bits[k]);
            }
        }
    }
    w.flush();
    [
        offset,
        index_bits
            | (pos_bits[0] << 5)
            | (pos_bits[1] << 10)
            | (pos_bits[2] << 15)
            | (u32::from(tangents) << 20)
            | ((d.len() as u32) << 21),
        index_min,
        pos_min[0] as u32,
        pos_min[1] as u32,
        pos_min[2] as u32,
        tan_bits[0] | (tan_bits[1] << 5) | (tan_bits[2] << 10),
        tan_min[0] as u32,
        tan_min[1] as u32,
        tan_min[2] as u32,
    ]
}

/// FDwordBitWriter: bits packed from the low end of each word.
struct BitWriter<'a> {
    out: &'a mut Vec<u32>,
    pending: u64,
    n: u32,
}

impl BitWriter<'_> {
    fn put(&mut self, v: u32, bits: u32) {
        self.pending |= u64::from(v) << self.n;
        self.n += bits;
        while self.n >= 32 {
            self.out.push(self.pending as u32);
            self.pending >>= 32;
            self.n -= 32;
        }
    }

    fn flush(&mut self) {
        if self.n > 0 {
            self.out.push(self.pending as u32);
        }
        self.pending = 0;
        self.n = 0;
    }
}

struct BitReader<'a> {
    words: &'a [u32],
    bit: usize,
}

impl BitReader<'_> {
    fn get(&mut self, bits: u32) -> u32 {
        let mut v = 0u64;
        for k in 0..bits as usize {
            let b = self.bit + k;
            let word = self.words.get(b / 32).copied().unwrap_or(0);
            v |= u64::from((word >> (b % 32)) & 1) << k;
        }
        self.bit += bits as usize;
        v as u32
    }
}

/// `file` with every LOD's morph data at its place replaced by `new`
/// (same order as [`Buffers::find_all`]), and the size change at each
/// replaced place: (byte offset in the old file, bytes added).
pub fn replace(file: &[u8], new: &[Buffers]) -> (Vec<u8>, Vec<(usize, i64)>) {
    let mut out = Vec::with_capacity(file.len());
    let mut changes = Vec::new();
    let mut from = 0;
    for b in new {
        out.extend_from_slice(&file[from..b.at]);
        let bytes = b.to_bytes();
        let old = Buffers::parse(file, b.at).map_or(0, |o| o.len);
        changes.push((b.at, bytes.len() as i64 - old as i64));
        out.extend_from_slice(&bytes);
        from = b.at + old;
    }
    out.extend_from_slice(&file[from..]);
    (out, changes)
}

fn i64_at(b: &[u8], o: usize) -> Option<i64> {
    Some(i64::from_le_bytes(b.get(o..o + 8)?.try_into().ok()?))
}

/// Where an export row keeps its serial size; its serial offset follows
/// (FObjectExport: four package indices, the object name, the flags).
const ROW_SIZE_AT: usize = 28;

/// The export table of a legacy package header: (first row, row stride,
/// rows), found as the (count, offset) pair whose rows' serial ranges
/// tile the export data from the end of the header to the end of the
/// .uexp, one after another.
fn export_table(uasset: &[u8], uexp_len: usize) -> Option<(usize, usize, usize)> {
    let h = uasset.len() as i64;
    let total = h + uexp_len as i64;
    for p in 0..uasset.len().min(4096).saturating_sub(8) {
        let count = u32_at(uasset, p)? as usize;
        let first = u32_at(uasset, p + 4)? as usize;
        if count == 0 || count > 1 << 20 || first >= uasset.len() {
            continue;
        }
        for stride in (64..=160).step_by(4) {
            let mut end = h;
            let tiles = (0..count).all(|i| {
                let row = first + i * stride + ROW_SIZE_AT;
                match (i64_at(uasset, row), i64_at(uasset, row + 8)) {
                    (Some(size), Some(off)) if off == end && size >= 0 => {
                        end += size;
                        true
                    }
                    _ => false,
                }
            });
            if tiles && end == total {
                return Some((first, stride, count));
            }
        }
    }
    None
}

/// The legacy package header fixed for a .uexp of `uexp_len` bytes that
/// grew by `changes` (byte offset in the .uexp, bytes added), as
/// [`replace`] reports them: the export holding each change grows, every
/// export after it moves, and the header's one field holding the old end
/// of the package (the bulk data start) moves with it.
pub fn fix_package(
    uasset: &[u8],
    uexp_len: usize,
    changes: &[(usize, i64)],
) -> Result<Vec<u8>, String> {
    let (first, stride, count) =
        export_table(uasset, uexp_len).ok_or("no export table tiles the .uexp")?;
    let h = uasset.len() as i64;
    let total = h + uexp_len as i64;
    let ends: Vec<usize> = (0..first.saturating_sub(8))
        .filter(|&p| i64_at(uasset, p) == Some(total))
        .collect();
    let [end_at] = ends[..] else {
        return Err(format!("{} header fields hold the package end", ends.len()));
    };
    let mut out = uasset.to_vec();
    let put = |out: &mut Vec<u8>, at: usize, v: i64| {
        out[at..at + 8].copy_from_slice(&v.to_le_bytes());
    };
    let mut grown = 0;
    // Last change first, so each change's old offset still names the
    // same export.
    let mut changes = changes.to_vec();
    changes.sort_by_key(|c| std::cmp::Reverse(c.0));
    for (at, d) in changes {
        let at = h + at as i64;
        for i in 0..count {
            let row = first + i * stride + ROW_SIZE_AT;
            let size = i64_at(&out, row).unwrap();
            let off = i64_at(&out, row + 8).unwrap();
            if off > at {
                put(&mut out, row + 8, off + d);
            } else if at < off + size {
                put(&mut out, row, size + d);
            }
        }
        grown += d;
    }
    put(&mut out, end_at, total + grown);
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn sample() -> Vec<Vec<Delta>> {
        let d = |index, p: [i32; 3], t: [i32; 3]| Delta {
            index,
            position: p,
            tangent: t,
        };
        vec![
            (0..150)
                .map(|i| d(i * 3 + 7, [i as i32 - 70, 5, -(i as i32)], [0; 3]))
                .collect(),
            vec![],
            vec![d(2, [1, 0, 0], [3, -4, 5]), d(9, [0, 0, -9], [0; 3])],
        ]
    }

    fn empty(m: usize) -> Buffers {
        Buffers {
            at: 0,
            len: 0,
            words: vec![],
            minimum: vec![[0.0; 4]; m],
            maximum: vec![[0.0; 4]; m],
            batch_start: vec![0; m],
            batches: vec![0; m],
            total_batches: 0,
            position_precision: 0.01,
            tangent_precision: 1.0 / 2048.0,
        }
    }

    #[test]
    fn encoded_morphs_decode_back() {
        let morphs = sample();
        let b = empty(3).encode(&morphs);
        assert_eq!(b.batches, vec![3, 0, 1]);
        assert_eq!(b.decode_all(), morphs);
    }

    #[test]
    fn written_bytes_are_found_and_read_back() {
        let b = empty(3).encode(&sample());
        let mut file = vec![0xAB; 37];
        file.extend_from_slice(&b.to_bytes());
        file.extend_from_slice(&[0xCD; 11]);
        let found = Buffers::find_all(&file);
        assert_eq!(found.len(), 1);
        assert_eq!(found[0].at, 37);
        assert_eq!(found[0].words, b.words);
        assert_eq!(found[0].decode_all(), sample());
    }

    #[test]
    fn replace_shifts_what_follows() {
        let b = empty(3).encode(&sample());
        let mut file = vec![1; 5];
        file.extend_from_slice(&b.to_bytes());
        file.extend_from_slice(&[2; 4]);
        let found = Buffers::find_all(&file);
        let mut morphs = sample();
        morphs[1] = vec![Delta {
            index: 4,
            position: [1, 1, 1],
            tangent: [0; 3],
        }];
        let new = found[0].encode(&morphs);
        let grown = new.len as i64 - found[0].len as i64;
        let (out, changes) = replace(&file, &[new]);
        assert_eq!(changes, vec![(5, grown)]);
        assert_eq!(out.len() as i64, file.len() as i64 + grown);
        assert_eq!(&out[out.len() - 4..], &[2; 4]);
        assert_eq!(Buffers::find_all(&out)[0].decode_all(), morphs);
    }
}

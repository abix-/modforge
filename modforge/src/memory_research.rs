//! Researching where fields sit in another process's memory, for mods
//! that read a game from outside (read-only [`ProcessMemory`]) instead
//! of from inside it.
//!
//! The server side answers the same `patterns.read_bytes` reply the
//! in-process mods give (horsey-mod ops.rs), so [`crate::research`]'s
//! parsing holds for both, plus `mem.wstring` for MSVC wide strings.
//! The client side, [`Remote`], is what research tests call: chunked
//! reads, 8-byte words, text, and the pointer checks a search needs.

use crate::client::Api;
use crate::process_memory::ProcessMemory;
use serde_json::{Value, json};
use std::time::Duration;

/// Most bytes one `patterns.read_bytes` call returns.
pub const READ_CHUNK: usize = 4096;

/// An address argument: a number, or hex text with or without 0x.
pub fn address_arg(v: &Value) -> Result<u64, String> {
    if let Some(n) = v.as_u64() {
        return Ok(n);
    }
    let s = v.as_str().ok_or("address must be a number or hex text")?;
    u64::from_str_radix(s.trim_start_matches("0x"), 16).map_err(|e| format!("address {s}: {e}"))
}

/// The `patterns.read_bytes` reply for `{addr, n}`: the bytes as
/// space-separated hex.
pub fn read_bytes_reply(mem: &ProcessMemory, args: &Value) -> Result<Value, String> {
    let addr = address_arg(&args["addr"])?;
    let n = args["n"].as_u64().unwrap_or(16) as usize;
    if n == 0 || n > READ_CHUNK {
        return Err(format!("n out of range: {n}"));
    }
    let bytes: Vec<u8> = mem
        .read_array(addr, n)
        .map_err(|e| format!("read {n} bytes at {addr:#x}: {e}"))?;
    let hex: Vec<String> = bytes.iter().map(|b| format!("{b:02x}")).collect();
    Ok(json!({"addr": format!("{addr:#x}"), "n": n, "bytes": hex.join(" ")}))
}

/// The `mem.wstring` reply for `{addr}`: the MSVC std::wstring there,
/// or why it is not one.
pub fn wstring_reply(mem: &ProcessMemory, args: &Value) -> Result<Value, String> {
    let addr = address_arg(&args["addr"])?;
    Ok(match crate::msvc_std::read_wstring(mem, addr) {
        Ok(s) => json!({"text": s}),
        Err(e) => json!({"error": format!("{e:#}")}),
    })
}

/// The `patterns.rip_sites` reply for `{sig}` over `image`'s code:
/// every match as its operand address and the address it points at,
/// with whether that lies in the image.
pub fn rip_sites_reply(
    image: &patternsleuth::image::Image<'_>,
    exe: &std::ops::Range<u64>,
    args: &Value,
) -> Result<Value, String> {
    let sig = args["sig"].as_str().ok_or("sig missing")?;
    let sites = crate::patterns::sleuth::rip_sites(
        image,
        sig,
        Some(crate::patterns::sleuth::TEXT_SECTION),
    )
    .map_err(|e| format!("{e:#}"))?;
    let rows: Vec<Value> = sites
        .iter()
        .map(|(operand, target)| {
            json!({
                "operand": format!("{operand:#x}"),
                "target": format!("{target:#x}"),
                "in_image": exe.contains(target),
            })
        })
        .collect();
    Ok(json!({"sig": sig, "count": rows.len(), "sites": rows}))
}

/// A user-space heap address outside `exe`, 8-byte aligned: what a
/// pointer to a game object looks like.
pub fn heap_pointer(p: u64, exe: &std::ops::Range<u64>) -> bool {
    (0x1_0000..0x7FFF_0000_0000).contains(&p) && !exe.contains(&p) && p.is_multiple_of(8)
}

/// A research test's view of a running mod's memory ops.
pub struct Remote {
    api: Api<Value>,
}

impl Remote {
    pub fn at(port: u16) -> Self {
        Self {
            api: Api::at(port, "/op").with_timeout(Duration::from_secs(60)),
        }
    }

    /// Any op's result, or its error.
    pub fn op(&self, name: &str, args: Value) -> Result<Value, String> {
        let r = self.api.try_op(name, args)?;
        if r.ok {
            Ok(r.result)
        } else {
            Err(format!("{name}: {:?}", r.error))
        }
    }

    /// `n` bytes at `addr`, fewer when the read stops early.
    pub fn bytes(&self, addr: u64, n: usize) -> Vec<u8> {
        let mut out = Vec::with_capacity(n);
        while out.len() < n {
            let at = addr.wrapping_add(out.len() as u64);
            let take = (n - out.len()).min(READ_CHUNK);
            let Ok(r) = self.op("patterns.read_bytes", json!({"addr": at, "n": take})) else {
                break;
            };
            let chunk: Vec<u8> = r["bytes"]
                .as_str()
                .unwrap_or("")
                .split_whitespace()
                .filter_map(|t| u8::from_str_radix(t, 16).ok())
                .collect();
            if chunk.is_empty() {
                break;
            }
            out.extend(chunk);
        }
        out
    }

    /// The 8-byte words in `len` bytes at `addr`.
    pub fn words(&self, addr: u64, len: usize) -> Vec<u64> {
        self.bytes(addr, len)
            .as_chunks::<8>()
            .0
            .iter()
            .map(|c| u64::from_le_bytes(*c))
            .collect()
    }

    /// One 8-byte word.
    pub fn word(&self, addr: u64) -> Option<u64> {
        self.words(addr, 8).first().copied()
    }

    /// The std::wstring at `addr`.
    pub fn wstring(&self, addr: u64) -> Option<String> {
        let r = self.op("mem.wstring", json!({"addr": addr})).ok()?;
        r["text"].as_str().map(str::to_string)
    }

    /// A zero-ended UTF-16 text of at most `max_units` at `addr`.
    pub fn wide_cstr(&self, addr: u64, max_units: usize) -> Option<String> {
        let b = self.bytes(addr, max_units * 2);
        let units: Vec<u16> = b
            .as_chunks::<2>()
            .0
            .iter()
            .map(|c| u16::from_le_bytes(*c))
            .take_while(|u| *u != 0)
            .collect();
        (units.len() < max_units).then(|| String::from_utf16_lossy(&units))
    }

    /// Follow `p`, then add each offset and read the word there.
    pub fn chain(&self, p: u64, offsets: &[u64]) -> Option<u64> {
        offsets
            .iter()
            .try_fold(p, |at, off| self.word(at.wrapping_add(*off)))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn replies_read_this_process() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let data = [0xABu8, 0x01, 0xFF];
        let r = read_bytes_reply(&mem, &json!({"addr": data.as_ptr() as u64, "n": 3})).unwrap();
        assert_eq!(r["bytes"], "ab 01 ff");
        assert!(read_bytes_reply(&mem, &json!({"addr": "0x10", "n": 0})).is_err());
        assert_eq!(address_arg(&json!("0x1f")), Ok(0x1F));
        assert_eq!(address_arg(&json!(31)), Ok(31));
        let exe = 0x1000_0000..0x2000_0000;
        assert!(heap_pointer(0x4_3900_0010, &exe));
        assert!(!heap_pointer(0x1000_0010, &exe));
        assert!(!heap_pointer(0x4_3900_0011, &exe));
    }
}

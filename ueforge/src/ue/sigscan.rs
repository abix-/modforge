//! Signature-scan helpers. The framework primitive behind the
//! "no hardcoded image-relative offsets" 10-year-bar item: every
//! UE patch shifts the four base offsets (`g_objects`, `g_names`,
//! `process_event`, `append_string`), and a hand-typed offset
//! table forces a code update + redeploy on every game update.
//! Sig-scan picks them out by their surrounding byte pattern,
//! which UE4SS upstream has been maintaining for a decade.
//!
//! ```ignore
//! use ueforge::ue::sigscan;
//!
//! // Pattern in IDA-style hex with `?` wildcards. Each token is
//! // either a hex byte or a `?` (or `??`). Whitespace is ignored.
//! let pat = sigscan::Pattern::parse(
//!     "48 8B 05 ? ? ? ? 48 89 4C 24 ?"
//! ).expect("pattern");
//!
//! // Search the host exe's .text section.
//! let text = unsafe { sigscan::text_section() }.expect("text");
//! let hit = sigscan::find(&pat, text).expect("pattern not found");
//!
//! // The first three bytes (`48 8B 05`) are `mov rax, [rip+disp32]`.
//! // The disp32 starts at +3 and the next instruction begins at +7.
//! // Resolve to the absolute target then subtract image_base for
//! // a stable offset that survives ASLR.
//! let target = unsafe {
//!     sigscan::resolve_rip32(text.as_ptr().add(hit), 3, 7)
//! };
//! let image_relative = target - ueforge::ue::platform::host_image_base();
//! ```
//!
//! ### Design notes
//!
//! - **No regex / SIMD on the first pass**: the search is a single
//!   linear scan, ~80MB of `.text` for a UE5 Shipping build, on a
//!   single thread, ONCE at init. Tens of milliseconds at most.
//!   If we ever need to scan from a hot path we'll add a Boyer-
//!   Moore byte-skip-table; not today.
//! - **Wildcards as `Option<u8>`**: simpler than the byte-mask
//!   shape, no manual mask construction, easy to debug-print.
//! - **RIP-relative resolution**: x86-64 instructions that
//!   reference data (`mov rax, [rip+disp32]`, `lea rcx,
//!   [rip+disp32]`) encode the disp32 as a signed 32-bit offset
//!   from the *end* of the instruction. Callers pass the offset
//!   to the disp32 within the matched bytes and the offset to
//!   the next instruction (which is also "end of this one").
//!
//! ### Why not just call UE4SS's helpers?
//!
//! UE4SS exposes its `Signatures.cpp` only via C++ headers that
//! aren't part of `UE4SS.lib`'s export surface. We'd be linking
//! against UE4SS internals that change every release. Owning a
//! tiny scan primitive in Rust keeps the framework
//! self-contained.

/// Parsed signature pattern. `None` entries are wildcards.
#[derive(Debug, Clone)]
pub struct Pattern {
    bytes: Vec<Option<u8>>,
}

impl Pattern {
    /// Parse an IDA-style hex pattern. Each whitespace-separated
    /// token is either a two-hex-digit byte (`"48"`, `"8B"`) or a
    /// wildcard (`"?"` or `"??"`). Case-insensitive. Empty input
    /// returns `None`.
    ///
    /// Returns `None` if any token is unparseable; surfacing the
    /// bad token is a follow-up if the message turns out to
    /// matter in practice. Today every caller hardcodes a
    /// literal, so a panic-style fail-fast at init is fine.
    pub fn parse(s: &str) -> Option<Self> {
        let mut bytes = Vec::with_capacity(s.len() / 3 + 1);
        for tok in s.split_whitespace() {
            if tok == "?" || tok == "??" {
                bytes.push(None);
                continue;
            }
            if tok.len() != 2 {
                return None;
            }
            let b = u8::from_str_radix(tok, 16).ok()?;
            bytes.push(Some(b));
        }
        if bytes.is_empty() {
            return None;
        }
        Some(Pattern { bytes })
    }

    pub fn len(&self) -> usize {
        self.bytes.len()
    }

    pub fn is_empty(&self) -> bool {
        self.bytes.is_empty()
    }

    /// First-match check at `haystack[offset]`. Used internally by
    /// `find`; exposed for callers that want to verify a
    /// candidate hit before resolving its RIP-relative target.
    pub fn matches_at(&self, haystack: &[u8], offset: usize) -> bool {
        if offset + self.bytes.len() > haystack.len() {
            return false;
        }
        for (i, p) in self.bytes.iter().enumerate() {
            if let Some(b) = p
                && haystack[offset + i] != *b
            {
                return false;
            }
        }
        true
    }
}

/// First match of `pat` in `haystack`. Returns the offset within
/// `haystack` of the start of the match. None if no match.
///
/// Linear scan, single-threaded. ~80MB of `.text` walks in tens
/// of milliseconds; called once at init. If hot-path use ever
/// appears we'll add a Boyer-Moore skip-table for the first
/// non-wildcard byte of the pattern.
pub fn find(pat: &Pattern, haystack: &[u8]) -> Option<usize> {
    if pat.bytes.is_empty() || haystack.len() < pat.bytes.len() {
        return None;
    }
    let last = haystack.len() - pat.bytes.len() + 1;
    for i in 0..last {
        if pat.matches_at(haystack, i) {
            return Some(i);
        }
    }
    None
}

/// All matches of `pat` in `haystack`. Cold-path; pre-allocates
/// reasonably and is fine for diagnostic dumps.
pub fn find_all(pat: &Pattern, haystack: &[u8]) -> Vec<usize> {
    let mut out = Vec::new();
    if pat.bytes.is_empty() || haystack.len() < pat.bytes.len() {
        return out;
    }
    let last = haystack.len() - pat.bytes.len() + 1;
    for i in 0..last {
        if pat.matches_at(haystack, i) {
            out.push(i);
        }
    }
    out
}

/// Decode a RIP-relative disp32 at `instr_addr + disp_offset`
/// and return the absolute target address.
///
/// `instr_addr` points at the first byte of the instruction
/// (the matched signature's start). `disp_offset` is the byte
/// offset of the disp32 within the instruction (typically 3 for
/// a 3-byte opcode like `48 8B 05` = `mov rax, [rip+disp32]`).
/// `next_instr_offset` is the length of the whole instruction
/// (typically 7 for the same example). The signed 32-bit
/// displacement is added to `instr_addr + next_instr_offset` to
/// produce the absolute target.
///
/// # Safety
/// `instr_addr` must be a valid pointer into a `.text` region
/// whose bytes match the signature (so the disp32 read won't
/// cross a page boundary into freed memory).
pub unsafe fn resolve_rip32(
    instr_addr: *const u8,
    disp_offset: usize,
    next_instr_offset: usize,
) -> usize {
    // SAFETY: caller guarantees the bytes at instr_addr +
    // disp_offset .. + disp_offset + 4 are readable (part of the
    // matched signature).
    let disp_ptr = unsafe { instr_addr.add(disp_offset) } as *const i32;
    // SAFETY: see above; .text pages are aligned but we use
    // read_unaligned for robustness against future patterns
    // where the disp lands on an odd offset.
    let disp = unsafe { disp_ptr.read_unaligned() } as isize;
    let next = (instr_addr as usize).wrapping_add(next_instr_offset);
    next.wrapping_add(disp as usize)
}

/// Returns the host exe's `.text` section as a byte slice with
/// `'static` lifetime (the exe stays mapped for the process
/// lifetime). Walks the PE header from `GetModuleHandleW(null)`.
/// Returns None if the PE walk fails (corrupt header, unusual
/// section names).
///
/// # Safety
/// Reads the host exe's PE header + section table. Safe to call
/// on any Windows process started normally; behavior is
/// undefined if the exe has been unmapped (impossible from
/// inside the process).
///
/// Every `unsafe { ... }` inside this fn shares the same SAFETY
/// contract: the bytes at `base + offset` are part of the loaded
/// PE image (offsets came either from the IMAGE_DOS_HEADER's
/// `e_lfanew` field or from IMAGE_FILE_HEADER's per-section
/// records); the image stays mapped for the process lifetime; no
/// pointer escapes its source section. The function-level allow
/// below documents this in one place instead of repeating it ~10
/// times across the PE walk.
#[allow(clippy::undocumented_unsafe_blocks)]
pub unsafe fn text_section() -> Option<&'static [u8]> {
    use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
    // SAFETY: GetModuleHandleW(null) returns the main exe's
    // HMODULE; cast to *const u8 for header math.
    let base = unsafe { GetModuleHandleW(std::ptr::null()) } as *const u8;
    if base.is_null() {
        return None;
    }
    // PE header layout:
    //   IMAGE_DOS_HEADER at base, e_lfanew at +0x3C is the file
    //   offset of IMAGE_NT_HEADERS.
    //   IMAGE_NT_HEADERS: Signature (4) + IMAGE_FILE_HEADER (20)
    //     + IMAGE_OPTIONAL_HEADER (size = OptionalHeader.SizeOfO
    //     ptionalHeader, varies per arch). Sections follow.
    // SAFETY: reading the first 0x40 bytes of any loaded PE
    // image is safe (IMAGE_DOS_HEADER size is fixed).
    let e_lfanew = unsafe { (base.add(0x3C) as *const u32).read_unaligned() } as usize;
    // SAFETY: e_lfanew points within the exe; the NT header is
    // mapped (or we wouldn't be running). Bound check below.
    let nt = unsafe { base.add(e_lfanew) };
    // Signature check ("PE\0\0").
    let sig: u32 = unsafe { (nt as *const u32).read_unaligned() };
    if sig != 0x0000_4550 {
        return None;
    }
    // IMAGE_FILE_HEADER.NumberOfSections at NT + 4 + 2.
    // IMAGE_FILE_HEADER.SizeOfOptionalHeader at NT + 4 + 16.
    let num_sections = unsafe { (nt.add(4 + 2) as *const u16).read_unaligned() } as usize;
    let size_of_optional = unsafe { (nt.add(4 + 16) as *const u16).read_unaligned() } as usize;
    // Sections table starts at NT + 4 + 20 + SizeOfOptionalHeader.
    let sections = unsafe { nt.add(4 + 20 + size_of_optional) };
    // Each section header is 40 bytes:
    //   Name (8) | VirtualSize (4) | VirtualAddress (4) |
    //   SizeOfRawData (4) | PointerToRawData (4) | ... (16 more)
    for i in 0..num_sections {
        let s = unsafe { sections.add(i * 40) };
        // Read 8 bytes of name; check for ".text\0\0\0".
        let name: [u8; 8] = unsafe { (s as *const [u8; 8]).read() };
        if &name[..5] == b".text" {
            let virtual_size =
                unsafe { (s.add(8) as *const u32).read_unaligned() } as usize;
            let virtual_address =
                unsafe { (s.add(12) as *const u32).read_unaligned() } as usize;
            // SAFETY: the section's mapped at `base +
            // VirtualAddress` with `virtual_size` bytes. The
            // slice has 'static lifetime because the exe stays
            // mapped for the process lifetime.
            let slice =
                unsafe { std::slice::from_raw_parts(base.add(virtual_address), virtual_size) };
            return Some(slice);
        }
    }
    None
}

/// Convenience: scan the host exe's `.text` for `pattern` and
/// resolve a RIP-relative reference at the match. Returns the
/// image-relative offset (subtract image_base from the absolute
/// target) suitable for stuffing into a `PlatformOffsets` field.
///
/// Returns:
///   - `Some(image_relative)` on success.
///   - `None` if the section walk fails, the pattern doesn't
///     match, or the resolved address is outside the image.
///
/// `disp_offset` + `next_instr_offset` follow the same shape as
/// [`resolve_rip32`].
pub fn find_image_relative_rip32(
    pattern: &Pattern,
    disp_offset: usize,
    next_instr_offset: usize,
) -> Option<usize> {
    // SAFETY: text_section() is documented safe (PE walk on the
    // host exe).
    let text = unsafe { text_section()? };
    let hit = find(pattern, text)?;
    // SAFETY: hit was returned by find() so it's bounded by
    // text.len() - pattern.len(); the resulting pointer is within
    // the .text section slice.
    let instr_addr = unsafe { text.as_ptr().add(hit) };
    // SAFETY: hit was returned by find() so instr_addr + pattern.len()
    // <= text.as_ptr() + text.len(); the disp32 read at +disp_offset
    // is within the matched bytes if pattern is consistent.
    let absolute = unsafe { resolve_rip32(instr_addr, disp_offset, next_instr_offset) };
    let image_base = crate::ue::platform::host_image_base();
    if absolute < image_base {
        return None;
    }
    Some(absolute - image_base)
}

/// Debug-op entry point. Args:
///   `{pattern: "48 8B 05 ? ? ? ?",
///     disp_offset?: 3, next_instr_offset?: 7, all?: false}`
///
/// Without disp_offset, returns the offset (within .text) of the
/// first match. With disp_offset, also resolves the RIP-relative
/// target and reports its image-relative form.
///
/// `all=true` returns every match (offset-only). Cold path; the
/// scan itself is fast enough (~80MB / tens of ms).
pub fn op_sig_scan(args: &serde_json::Value) -> Result<serde_json::Value, String> {
    use serde_json::json;
    let pattern_str = args
        .get("pattern")
        .and_then(|v| v.as_str())
        .ok_or_else(|| "sig_scan: missing 'pattern'".to_string())?;
    let pat = Pattern::parse(pattern_str)
        .ok_or_else(|| format!("sig_scan: bad pattern '{pattern_str}'"))?;
    // SAFETY: text_section() is documented safe.
    let text = unsafe { text_section() }
        .ok_or_else(|| "sig_scan: .text not found (PE walk failed)".to_string())?;
    let all = args.get("all").and_then(|v| v.as_bool()).unwrap_or(false);

    if all {
        let hits = find_all(&pat, text);
        return Ok(json!({
            "pattern": pattern_str,
            "match_count": hits.len(),
            "text_size": text.len(),
            "matches": hits,
        }));
    }

    let Some(hit) = find(&pat, text) else {
        return Ok(json!({
            "pattern": pattern_str,
            "text_size": text.len(),
            "matched": false,
        }));
    };

    let mut out = json!({
        "pattern": pattern_str,
        "matched": true,
        "text_offset": hit,
        "absolute_addr": format!("0x{:x}", text.as_ptr() as usize + hit),
    });

    if let Some(disp_offset) = args.get("disp_offset").and_then(|v| v.as_u64()) {
        let next_instr_offset = args
            .get("next_instr_offset")
            .and_then(|v| v.as_u64())
            .ok_or_else(|| {
                "sig_scan: 'disp_offset' set but 'next_instr_offset' missing".to_string()
            })?;
        // SAFETY: hit returned by find(), so text.as_ptr().add(hit)
        // is within text and the matched-pattern bytes (including
        // disp_offset+4) are readable.
        let instr_addr = unsafe { text.as_ptr().add(hit) };
        let absolute =
            unsafe { resolve_rip32(instr_addr, disp_offset as usize, next_instr_offset as usize) };
        let image_base = crate::ue::platform::host_image_base();
        out["resolved_absolute"] = json!(format!("0x{absolute:x}"));
        out["resolved_image_relative"] = if absolute >= image_base {
            json!(format!("0x{:x}", absolute - image_base))
        } else {
            json!(null)
        };
    }

    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn pattern_parse_basic() {
        let p = Pattern::parse("48 8B 05 ? ? ? ?").expect("parse");
        assert_eq!(p.len(), 7);
        assert_eq!(p.bytes[0], Some(0x48));
        assert_eq!(p.bytes[1], Some(0x8B));
        assert_eq!(p.bytes[2], Some(0x05));
        assert_eq!(p.bytes[3], None);
    }

    #[test]
    fn pattern_parse_case_insensitive_double_wildcard() {
        let p = Pattern::parse("ab CD ?? ef").expect("parse");
        assert_eq!(p.bytes[0], Some(0xAB));
        assert_eq!(p.bytes[1], Some(0xCD));
        assert_eq!(p.bytes[2], None);
        assert_eq!(p.bytes[3], Some(0xEF));
    }

    #[test]
    fn pattern_parse_rejects_garbage() {
        assert!(Pattern::parse("zz").is_none());
        assert!(Pattern::parse("48 xy").is_none());
        assert!(Pattern::parse("").is_none());
        assert!(Pattern::parse("4").is_none()); // single hex char.
    }

    #[test]
    fn find_first_match() {
        let h = [0x00, 0x48, 0x8B, 0x05, 0x10, 0x20, 0x30, 0x40, 0x90];
        let p = Pattern::parse("48 8B 05 ? ? ? ?").unwrap();
        assert_eq!(find(&p, &h), Some(1));
    }

    #[test]
    fn find_returns_none_when_too_short() {
        let h = [0x48, 0x8B];
        let p = Pattern::parse("48 8B 05").unwrap();
        assert!(find(&p, &h).is_none());
    }

    #[test]
    fn find_all_returns_every_match() {
        let h = [0x90, 0x48, 0x8B, 0x90, 0x48, 0x8B, 0xCC];
        let p = Pattern::parse("48 8B").unwrap();
        assert_eq!(find_all(&p, &h), vec![1, 4]);
    }

    #[test]
    fn resolve_rip32_basic() {
        // Synthetic instruction: `48 8B 05 04 00 00 00` =
        //   mov rax, [rip+0x4]; ends at +7; target = +7 + 4 = +11.
        let mut buf: [u8; 16] = [0; 16];
        buf[0] = 0x48;
        buf[1] = 0x8B;
        buf[2] = 0x05;
        buf[3..7].copy_from_slice(&4i32.to_le_bytes());
        let base = buf.as_ptr();
        let target = unsafe { resolve_rip32(base, 3, 7) };
        assert_eq!(target, base as usize + 11);
    }

    #[test]
    fn resolve_rip32_negative_disp() {
        // disp = -8, instr 7 bytes. target = base + 7 + (-8) = base - 1.
        let mut buf: [u8; 16] = [0; 16];
        buf[3..7].copy_from_slice(&(-8i32).to_le_bytes());
        let base = buf.as_ptr();
        let target = unsafe { resolve_rip32(base, 3, 7) };
        assert_eq!(target, (base as usize).wrapping_sub(1));
    }
}

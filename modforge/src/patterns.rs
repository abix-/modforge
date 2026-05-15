//! IDA-style byte-pattern scanner for resolving function entry points
//! in a loaded PE image.
//!
//! Drives R1/R2 from `horsey-mod/docs/ADDRESS-RESOLUTION.md`: instead
//! of hardcoded `fn_addr` RVAs that drift on game updates, every
//! patch target gets a signature (bytes from its prologue with `??`
//! wildcards for compiler-shifted operands) that we scan for at DLL
//! attach.
//!
//! Pattern grammar:
//!   - Whitespace separated.
//!   - Two-hex-digit token (e.g. `48`, `8b`) matches that exact byte.
//!   - `??` (or `?`) matches any byte.
//!   - Empty pattern is invalid.
//!
//! Examples:
//!   `"48 89 5c 24 ?? 57 48 83 ec ??"`
//!   matches the shadow-space + push rdi + sub rsp prologue with two
//!   compiler-controlled displacement bytes wildcarded.
//!
//! Reference implementation: `HorseyLiveTweaks/src/pattern_scan.cpp`
//! (GPL-3; we cite it but re-implement in Rust under MIT).

/// One element of a parsed pattern: either a required byte or a
/// wildcard.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PatByte {
    Byte(u8),
    Any,
}

/// Parse an IDA-style pattern string into a vector of `PatByte`.
/// Returns `Err` on malformed tokens or empty input.
pub fn parse(pattern: &str) -> Result<Vec<PatByte>, String> {
    let mut out = Vec::new();
    for tok in pattern.split_whitespace() {
        if tok == "?" || tok == "??" {
            out.push(PatByte::Any);
            continue;
        }
        if tok.len() != 2 {
            return Err(format!("token {tok:?} is not 2 hex digits or `??`"));
        }
        match u8::from_str_radix(tok, 16) {
            Ok(b) => out.push(PatByte::Byte(b)),
            Err(_) => return Err(format!("token {tok:?} is not valid hex")),
        }
    }
    if out.is_empty() {
        return Err("empty pattern".into());
    }
    Ok(out)
}

/// Find the FIRST offset in `haystack` where `pattern` matches.
/// Returns `None` if no match. Wildcards in `pattern` match any byte.
pub fn find_first(haystack: &[u8], pattern: &str) -> Option<usize> {
    let pat = parse(pattern).ok()?;
    find_first_parsed(haystack, &pat)
}

/// Like `find_first` but takes a pre-parsed pattern. Useful when
/// scanning many haystacks against the same pattern.
pub fn find_first_parsed(haystack: &[u8], pattern: &[PatByte]) -> Option<usize> {
    if pattern.is_empty() || pattern.len() > haystack.len() {
        return None;
    }
    let stop = haystack.len() - pattern.len() + 1;
    'outer: for i in 0..stop {
        for (j, pb) in pattern.iter().enumerate() {
            match pb {
                PatByte::Any => continue,
                PatByte::Byte(b) => {
                    if haystack[i + j] != *b {
                        continue 'outer;
                    }
                }
            }
        }
        return Some(i);
    }
    None
}

/// Find ALL offsets where `pattern` matches. Useful when the same
/// signature appears at multiple sites (e.g. inlined helpers); the
/// caller disambiguates.
pub fn find_all(haystack: &[u8], pattern: &str) -> Vec<usize> {
    let Ok(pat) = parse(pattern) else {
        return Vec::new();
    };
    find_all_parsed(haystack, &pat)
}

/// Scan the loaded `.exe` image for `pattern` and return the
/// matching runtime address. Reads `GetModuleHandleW(NULL)` for the
/// image base, walks PE section headers to find `.text`, and scans
/// that section's bytes.
///
/// Returns `None` if:
///   - The pattern doesn't parse.
///   - There's no `.text` section.
///   - The pattern doesn't match anywhere.
///
/// SAFETY: reads the loaded image read-only. Caller does not own
/// the returned address; treat as a function-entry pointer in our
/// own process.
pub fn scan_loaded_image(pattern: &str) -> Option<usize> {
    let pat = parse(pattern).ok()?;
    let (text_start, text_len) = locate_text_section()?;
    // SAFETY: `text_start..text_start+text_len` is inside the
    // loaded `.exe` image and stays valid for the process
    // lifetime. Read-only view.
    let bytes =
        unsafe { std::slice::from_raw_parts(text_start as *const u8, text_len) };
    let off = find_first_parsed(bytes, &pat)?;
    Some(text_start.wrapping_add(off))
}

/// Resolve the loaded `.exe`'s `.text` section: returns
/// `(runtime_start_addr, length_in_bytes)`, or `None` if the PE
/// shape isn't what we expect.
fn locate_text_section() -> Option<(usize, usize)> {
    use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
    // SAFETY: GetModuleHandleW(NULL) returns the .exe HMODULE
    // which on x64 equals the image base.
    let image_base = unsafe { GetModuleHandleW(std::ptr::null()) } as usize;
    if image_base == 0 {
        return None;
    }

    // PE header walk. Layout reference:
    //   IMAGE_DOS_HEADER at image_base; e_lfanew at +0x3c.
    //   IMAGE_NT_HEADERS64 at image_base + e_lfanew.
    //     Signature (4)
    //     FileHeader (20)        -> NumberOfSections at +6
    //     OptionalHeader64 (240) -> SizeOfOptionalHeader in FileHeader
    //   Section headers immediately follow OptionalHeader.
    //
    // Each IMAGE_SECTION_HEADER is 40 bytes:
    //   Name[8]
    //   VirtualSize: u32 (offset 0x08)
    //   VirtualAddress: u32 (offset 0x0c)
    //   ...

    // SAFETY: reading bytes from our own process image; bounds
    // sanity-checked below before each deref.
    unsafe {
        let dos = image_base as *const u8;
        // e_lfanew (i32 at +0x3c)
        let e_lfanew = *(dos.add(0x3c) as *const i32) as usize;
        let nt = dos.add(e_lfanew);
        // Validate "PE\0\0" signature.
        if *nt != b'P' || *nt.add(1) != b'E' || *nt.add(2) != 0 || *nt.add(3) != 0 {
            return None;
        }
        // FileHeader.NumberOfSections at NT + 4 + 2 = +6.
        let num_sections = *(nt.add(4 + 2) as *const u16) as usize;
        let size_of_opt_hdr =
            *(nt.add(4 + 16) as *const u16) as usize;
        // First section header: NT + 4 (sig) + 20 (FileHeader) + opt_hdr_size.
        let first_section = nt.add(4 + 20 + size_of_opt_hdr);
        for i in 0..num_sections {
            let sec = first_section.add(i * 40);
            let mut name = [0u8; 8];
            std::ptr::copy_nonoverlapping(sec, name.as_mut_ptr(), 8);
            // Section name is ".text" + 3 zero bytes.
            if &name[..6] == b".text\0" {
                let virtual_size = *(sec.add(0x08) as *const u32) as usize;
                let virtual_address = *(sec.add(0x0c) as *const u32) as usize;
                return Some((image_base + virtual_address, virtual_size));
            }
        }
        None
    }
}

pub fn find_all_parsed(haystack: &[u8], pattern: &[PatByte]) -> Vec<usize> {
    let mut out = Vec::new();
    if pattern.is_empty() || pattern.len() > haystack.len() {
        return out;
    }
    let stop = haystack.len() - pattern.len() + 1;
    'outer: for i in 0..stop {
        for (j, pb) in pattern.iter().enumerate() {
            match pb {
                PatByte::Any => continue,
                PatByte::Byte(b) => {
                    if haystack[i + j] != *b {
                        continue 'outer;
                    }
                }
            }
        }
        out.push(i);
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    // ----- parser -----

    #[test]
    fn parses_simple_bytes() {
        let p = parse("48 8b c4").unwrap();
        assert_eq!(
            p,
            vec![PatByte::Byte(0x48), PatByte::Byte(0x8b), PatByte::Byte(0xc4)]
        );
    }

    #[test]
    fn parses_wildcards() {
        let p = parse("48 ?? c4 ?").unwrap();
        assert_eq!(
            p,
            vec![PatByte::Byte(0x48), PatByte::Any, PatByte::Byte(0xc4), PatByte::Any]
        );
    }

    #[test]
    fn parses_handles_extra_whitespace() {
        let p = parse("  48\t  ??\n c4  ").unwrap();
        assert_eq!(p.len(), 3);
    }

    #[test]
    fn parser_rejects_empty() {
        assert!(parse("").is_err());
        assert!(parse("   ").is_err());
    }

    #[test]
    fn parser_rejects_malformed_tokens() {
        assert!(parse("48 GG c4").is_err());
        assert!(parse("48 1 c4").is_err()); // single digit
        assert!(parse("48 1234 c4").is_err()); // too long
    }

    // ----- find_first -----

    #[test]
    fn find_first_exact_match_at_start() {
        let hay = [0x48, 0x8b, 0xc4, 0x55, 0x53];
        assert_eq!(find_first(&hay, "48 8b c4"), Some(0));
    }

    #[test]
    fn find_first_exact_match_at_offset() {
        let hay = [0x90, 0x90, 0x48, 0x8b, 0xc4, 0x55, 0x53, 0x90];
        assert_eq!(find_first(&hay, "48 8b c4 55"), Some(2));
    }

    #[test]
    fn find_first_with_wildcards() {
        let hay = [0x90, 0x48, 0x8b, 0xc4, 0x55, 0x53, 0x90];
        // Wildcard replaces 0xc4.
        assert_eq!(find_first(&hay, "48 8b ?? 55 53"), Some(1));
    }

    #[test]
    fn find_first_no_match() {
        let hay = [0x90, 0x90, 0x90, 0x90];
        assert_eq!(find_first(&hay, "48 8b c4"), None);
    }

    #[test]
    fn find_first_pattern_longer_than_haystack() {
        let hay = [0x48, 0x8b];
        assert_eq!(find_first(&hay, "48 8b c4 55"), None);
    }

    #[test]
    fn find_first_returns_earliest_match() {
        // Two occurrences; must return the first.
        let hay = [0x48, 0x8b, 0x90, 0x48, 0x8b];
        assert_eq!(find_first(&hay, "48 8b"), Some(0));
    }

    #[test]
    fn find_first_at_haystack_end() {
        let hay = [0x90, 0x90, 0x48, 0x8b];
        assert_eq!(find_first(&hay, "48 8b"), Some(2));
    }

    // ----- find_all -----

    #[test]
    fn find_all_multiple_matches() {
        let hay = [0x90, 0xab, 0xcd, 0x90, 0xab, 0xcd, 0x90];
        assert_eq!(find_all(&hay, "ab cd"), vec![1, 4]);
    }

    #[test]
    fn find_all_overlapping_matches() {
        // Looking for `aa aa` in a run of 0xaa bytes; each starting
        // position is a match (no overlap suppression).
        let hay = [0xaa, 0xaa, 0xaa, 0xaa];
        assert_eq!(find_all(&hay, "aa aa"), vec![0, 1, 2]);
    }

    #[test]
    fn find_all_empty_on_no_match() {
        let hay = [0x90; 16];
        assert!(find_all(&hay, "12 34").is_empty());
    }

    // ----- regression: known Horsey.exe prologues -----
    //
    // These are signatures derived from prologue bytes captured by
    // `tests/dryrun_d1_d5.rs` against the live game. If pattern-scan
    // is doing its job, they will continue to find the same functions
    // in future builds. Living regression fence for R1.

    #[test]
    fn pattern_matches_apply_gene_to_horse_prologue() {
        // From dryrun_d1_d5: APPLY_GENE_TO_HORSE prologue is
        // `48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57 48`.
        let hay = [
            0x90, 0x90, 0x90, 0x90, // gap
            0x48, 0x8b, 0xc4, 0x55, 0x53, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55,
            0x41, 0x56, 0x41, 0x57, 0x48,
            0x90, 0x90,
        ];
        // Match the full 15-byte prologue.
        assert_eq!(
            find_first(&hay, "48 8b c4 55 53 56 57 41 54 41 55 41 56 41 57"),
            Some(4)
        );
    }

    #[test]
    fn pattern_matches_combinator_prologue_with_wildcards() {
        // From dryrun_d3_d4: GENE_COMBINATOR prologue is
        // `48 89 5c 24 08 48 89 6c 24 10 48 89 74 24 18 57`.
        // The `08`, `10`, `18` are stack displacement bytes that
        // would vary if the compiler reordered saves; wildcard them
        // to make the signature robust.
        let hay = [
            0xcc, 0xcc, 0xcc,
            0x48, 0x89, 0x5c, 0x24, 0x08, 0x48, 0x89, 0x6c, 0x24, 0x10,
            0x48, 0x89, 0x74, 0x24, 0x18, 0x57,
        ];
        assert_eq!(
            find_first(&hay, "48 89 5c 24 ?? 48 89 6c 24 ?? 48 89 74 24 ?? 57"),
            Some(3)
        );
    }
}

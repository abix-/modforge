//! patternsleuth-backed multi-target resolver.
//!
//! Promotes the hand-rolled `scan_loaded_image` into a production
//! address-resolution primitive backed by the `patternsleuth` crate:
//!   - SIMD-accelerated scanning across many patterns in one pass.
//!   - Per-target candidate-signature lists with first-match-wins.
//!   - Reads the loaded PE image via `process::internal::read_image`.
//!
//! Public API:
//!   - `Target { name, sigs }`: one symbol to resolve, with one or
//!     more IDA-style signature strings.
//!   - `resolve_all(&[Target]) -> Resolution`: scan the loaded image
//!     for every target, return a map from name to matched address.
//!
//! The intent is that every per-game mod (horsey-mod, schedule1,
//! grounded2, future) declares a single `&[Target]` constant at
//! attach time and calls `resolve_all`. The returned addresses are
//! used as the source of truth for detour install + patch sites.

use anyhow::{Context, Result, anyhow};
use patternsleuth::{PatternConfig, ScanResult};
use patternsleuth::process::internal::read_image;
use patternsleuth::scanner::Pattern;
use std::collections::HashMap;

// Scan only the executable .text section, so 16-byte runs of 0xff
// (or other innocuous data) in .rdata/.data don't pass for function
// addresses.
const TEXT_SECTION: object::SectionKind = object::SectionKind::Text;

/// One symbol to resolve. `sigs` is tried in order; first match wins.
/// Empty `sigs` is treated as "no candidates"; resolution returns
/// `None` for that name.
#[derive(Debug, Clone)]
pub struct Target<'a> {
    pub name: &'a str,
    pub sigs: &'a [&'a str],
}

/// Result of `resolve_all`: maps each requested target name to the
/// matched runtime address (`Some(addr)`) or `None` if no candidate
/// signature matched.
#[derive(Debug, Default, Clone)]
pub struct Resolution {
    pub by_name: HashMap<String, Option<usize>>,
}

impl Resolution {
    pub fn get(&self, name: &str) -> Option<usize> {
        self.by_name.get(name).copied().flatten()
    }
    pub fn require(&self, name: &str) -> Result<usize> {
        self.get(name)
            .ok_or_else(|| anyhow!("target {name:?} did not resolve"))
    }
    pub fn unresolved(&self) -> Vec<&str> {
        self.by_name
            .iter()
            .filter_map(|(k, v)| v.is_none().then_some(k.as_str()))
            .collect()
    }
}

/// Scan the loaded `.exe` image for every target's signature
/// candidates in a single pass. Returns a `Resolution` mapping each
/// target name to the matched address (or `None`).
///
/// Candidate-list semantics: for each target, signatures are tried
/// in order; the FIRST signature that matches in the image wins.
/// Subsequent candidates are not consulted for that name.
///
/// Errors only on PE parse failure (the loaded image is malformed),
/// which should never happen in practice; missing matches are not
/// errors, they appear as `None` in the resolution.
pub fn resolve_all(targets: &[Target<'_>]) -> Result<Resolution> {
    // Build patternsleuth pattern configs. The `S` (sig handle) we
    // use is `(target_index, sig_index)` so we can group results
    // back to the source target and pick the earliest-matching
    // candidate per target.
    type Sig = (usize, usize);
    let mut configs: Vec<PatternConfig<Sig>> = Vec::new();
    for (ti, t) in targets.iter().enumerate() {
        for (si, sig) in t.sigs.iter().enumerate() {
            let pat = Pattern::new(sig)
                .with_context(|| format!("target {:?} sig {si} parse failed", t.name))?;
            // Section None means "all sections"; we scan .text via
            // the section walk inside patternsleuth.
            configs.push(PatternConfig::new(
                (ti, si),
                t.name.to_string(),
                Some(TEXT_SECTION),
                pat,
            ));
        }
    }

    let image = read_image()
        .map_err(|e| anyhow!("patternsleuth read_image failed: {e}"))?;
    let scan_result: ScanResult<Sig> = image
        .scan(&configs)
        .map_err(|e| anyhow!("patternsleuth scan failed: {e}"))?;

    // For each target, walk its candidate signatures in order and
    // accept the first one that produced ANY match. If a signature
    // matches multiple addresses, we take the first (lowest)
    // because the candidate's job is to be specific enough to
    // identify one entry; ambiguity is the caller's problem.
    let mut by_name: HashMap<String, Option<usize>> = HashMap::new();
    for (ti, t) in targets.iter().enumerate() {
        let mut chosen: Option<usize> = None;
        for si in 0..t.sigs.len() {
            let mut matches: Vec<u64> = scan_result
                .results
                .iter()
                .filter(|(cfg, _)| cfg.sig == (ti, si))
                .map(|(_, r)| r.address)
                .collect();
            if !matches.is_empty() {
                matches.sort_unstable();
                chosen = Some(matches[0] as usize);
                break;
            }
        }
        by_name.insert(t.name.to_string(), chosen);
    }

    Ok(Resolution { by_name })
}

/// Scan the loaded image's `.text` for every position matching a
/// single patternsleuth signature. Unlike [`resolve_all`], returns
/// EVERY hit (not just the first per name). Use this for xref
/// scans (`X0x<target>`), enumerating all writes of a constant,
/// etc.
///
/// Addresses are returned sorted ascending, deduplicated.
pub fn scan_all_matches(sig: &str) -> Result<Vec<usize>> {
    let pat = Pattern::new(sig)
        .with_context(|| format!("sig {sig:?} parse failed"))?;
    let config = PatternConfig::new(
        (),
        "scan_all".to_string(),
        Some(TEXT_SECTION),
        pat,
    );
    let image = read_image()
        .map_err(|e| anyhow!("patternsleuth read_image failed: {e}"))?;
    let configs = [config];
    let scan_result: ScanResult<()> = image
        .scan(&configs)
        .map_err(|e| anyhow!("patternsleuth scan failed: {e}"))?;
    let mut addrs: Vec<usize> =
        scan_result.results.iter().map(|(_, r)| r.address as usize).collect();
    addrs.sort_unstable();
    addrs.dedup();
    Ok(addrs)
}

#[cfg(test)]
mod tests {
    use super::*;

    // No-game unit tests: ensure the parser-side of patternsleuth
    // wrappers behaves. Live-image resolution is tested in
    // `horsey-mod/tests/r2_resolver.rs` because it requires a
    // running game.

    #[test]
    fn resolution_get_returns_inner() {
        let mut r = Resolution::default();
        r.by_name.insert("X".into(), Some(0xdead));
        r.by_name.insert("Y".into(), None);
        assert_eq!(r.get("X"), Some(0xdead));
        assert_eq!(r.get("Y"), None);
        assert_eq!(r.get("Z"), None);
    }

    #[test]
    fn resolution_require_errs_on_missing() {
        let mut r = Resolution::default();
        r.by_name.insert("X".into(), None);
        assert!(r.require("X").is_err());
        assert!(r.require("Z").is_err());
    }

    #[test]
    fn resolution_unresolved_lists_nones_only() {
        let mut r = Resolution::default();
        r.by_name.insert("A".into(), Some(1));
        r.by_name.insert("B".into(), None);
        r.by_name.insert("C".into(), None);
        let mut got = r.unresolved();
        got.sort();
        assert_eq!(got, vec!["B", "C"]);
    }
}

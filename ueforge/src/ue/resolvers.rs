//! UE engine address resolution via [`patternsleuth`].
//!
//! The 10-year-bar lift, finally on the right foundation:
//! `trumank/patternsleuth` is the Rust sig-scan crate UE4SS
//! itself uses to locate engine functions at runtime. Its
//! `resolvers::unreal` module ships battle-tested patterns for
//! the canonical UE primitives (`GUObjectArray`, `FNamePool`,
//! `FNameToString`, `GMalloc`, ...). We pin a specific upstream
//! SHA in the workspace and consume the resolvers we need.
//!
//! ## What this module provides
//!
//! - [`ResolvedOffsets`]: image-relative resolutions of the
//!   three base UE primitives we care about today.
//!   (`ProcessEvent` stays hardcoded; it's a vtable slot index
//!   per UE major version, not an image offset, and
//!   patternsleuth doesn't ship a resolver for it.)
//! - [`resolve_image_offsets`]: the entry point.
//!   `patternsleuth::process::internal::read_image()` walks the
//!   host exe's PE image; `Resolution::resolver()` scans for
//!   every pattern across every section. The async runtime is
//!   built into patternsleuth (futures); we await synchronously
//!   because we run at mod init, off-game-thread.
//! - [`resolve_offsets_op`]: debug op `{}` -> JSON snapshot.
//!   Lets you compare the resolved values against the
//!   hardcoded STEAM/XBOX offsets from inside the running
//!   game without rebuilding.
//!
//! ## Migration path
//!
//! Today: hardcoded `STEAM` / `XBOX` blocks in
//! [`crate::ue::offsets`] are authoritative.
//!
//! Step 1 (this module): expose resolver-based offsets behind a
//! debug op for verification.
//!
//! Step 2 (future): once verified equivalent on every supported
//! build, flip `PlatformOffsets::detect` to call
//! [`resolve_image_offsets`] first and only fall back to
//! hardcoded blocks on a sig-scan miss. UE patches that shift
//! offsets become a non-event.

use patternsleuth::resolvers::impl_try_collector;
use patternsleuth::resolvers::unreal::fname::{FNamePool, FNameToString};
use patternsleuth::resolvers::unreal::guobject_array::GUObjectArray;

impl_try_collector! {
    /// Collection of resolvers patternsleuth runs in one pass.
    /// Each field's type is a resolver-singleton struct from
    /// `patternsleuth::resolvers::unreal::*`; resolution
    /// returns one absolute u64 per field.
    #[derive(Debug, PartialEq, Clone)]
    struct UeResolution {
        guobject_array: GUObjectArray,
        fname_pool: FNamePool,
        fname_to_string: FNameToString,
    }
}

/// Image-relative offsets resolved via patternsleuth. Subtract
/// `host_image_base()` from each absolute address so the
/// offsets are stable across runs / ASLR slides.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ResolvedOffsets {
    /// FUObjectArray instance (the `GUObjectArray` global).
    pub g_objects: usize,
    /// FNamePool / GNames (the global FName allocator).
    pub g_names: usize,
    /// `FName::ToString` / `AppendString`-shaped fn entry.
    pub append_string: usize,
}

/// Resolve the three base UE offsets via patternsleuth, returning
/// them image-relative.
///
/// Cost: one full scan of the host exe's `.text` (tens of ms,
/// init-only). The patternsleuth library handles the underlying
/// async + futures join internally; we drive the resulting
/// future to completion on this thread.
///
/// Returns an error string if patternsleuth couldn't read the
/// image or any resolver couldn't find a unique match. Game
/// crates wire this from their `on_unreal_init` worker as a
/// fallback when hardcoded `PlatformOffsets` are stale.
pub fn resolve_image_offsets() -> Result<ResolvedOffsets, String> {
    let exe = patternsleuth::process::internal::read_image()
        .map_err(|e| format!("patternsleuth: read_image failed: {e}"))?;
    let resolution = exe
        .resolve(UeResolution::resolver())
        .map_err(|e| format!("patternsleuth: resolve failed: {e}"))?;

    let image_base = crate::ue::platform::host_image_base();
    let to_rel = |abs: u64| -> Result<usize, String> {
        let abs = abs as usize;
        if abs < image_base {
            return Err(format!(
                "patternsleuth: absolute 0x{abs:x} < image_base 0x{image_base:x}"
            ));
        }
        Ok(abs - image_base)
    };

    Ok(ResolvedOffsets {
        g_objects: to_rel(resolution.guobject_array.0)?,
        g_names: to_rel(resolution.fname_pool.0)?,
        append_string: to_rel(resolution.fname_to_string.0)?,
    })
}

/// Debug op entry. Returns the resolved offsets + a side-by-side
/// comparison against the configured `PlatformOffsets`, so a
/// curl from outside the game tells you whether the hardcoded
/// table is still correct for this build.
///
/// Args: `{}` (no input).
///
/// Result shape:
/// ```text
/// {
///   "resolved": {
///     "g_objects": "0x09f6_7028",
///     "g_names":   "0x09e4_a7b8",
///     "append_string": "0x0125_2060"
///   },
///   "hardcoded": {
///     "g_objects": "0x09f6_7028",
///     "g_names":   "0x09e4_a7b8",
///     "append_string": "0x0125_2060",
///     "process_event": "0x0146_e7b0"
///   },
///   "matches": { "g_objects": true, "g_names": true, "append_string": true }
/// }
/// ```
pub fn resolve_offsets_op(_args: &serde_json::Value) -> Result<serde_json::Value, String> {
    use serde_json::json;
    let resolved = resolve_image_offsets()?;
    let rt = crate::ue::try_runtime()
        .ok_or_else(|| "ueforge runtime not initialized".to_string())?;
    let hc = rt.platform_offsets;
    Ok(json!({
        "resolved": {
            "g_objects": format!("0x{:x}", resolved.g_objects),
            "g_names": format!("0x{:x}", resolved.g_names),
            "append_string": format!("0x{:x}", resolved.append_string),
        },
        "hardcoded": {
            "g_objects": format!("0x{:x}", hc.g_objects),
            "g_names": format!("0x{:x}", hc.g_names),
            "append_string": format!("0x{:x}", hc.append_string),
            "process_event": format!("0x{:x}", hc.process_event),
        },
        "matches": {
            "g_objects": resolved.g_objects == hc.g_objects,
            "g_names": resolved.g_names == hc.g_names,
            "append_string": resolved.append_string == hc.append_string,
        },
    }))
}

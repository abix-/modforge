// FString = TArray<wchar_t>. Layout: { data: *mut u16, num: i32, max: i32 }.
// We treat it as borrowed for read paths, but FStrings produced by game
// functions (AppendString, ToString-style getters) own their wchar_t
// buffer; we have to free that buffer.
//
// The SDK pattern is to call `delete[]` (C++ operator) on Data when Max>0.
// Calling `delete[]` from Rust would require linking the game's CRT, which
// is messy. Instead we leak the buffer. It's bytes-per-conversion small
// and game-process scoped. If this becomes a problem we'll add a release
// pass that calls a game-side free helper.

use std::slice;

#[repr(C)]
pub struct FString {
    data: *mut u16,
    num: i32,
    max: i32,
}

impl Default for FString {
    fn default() -> Self {
        Self {
            data: std::ptr::null_mut(),
            num: 0,
            max: 0,
        }
    }
}

/// Replace the FString whose header is at `header` with `text`, growing
/// its buffer through the engine allocator when the current capacity is
/// too small. Proved live on a PlayerState name (abioticfactor-mod host.rs,
/// 2026-09-12).
///
/// # Safety
/// `header` must point at a live FString on the game thread.
pub unsafe fn write_at(header: *mut u8, text: &str) -> Result<(), String> {
    let needed = i32::try_from(text.encode_utf16().count() + 1).map_err(|_| "string too long")?;
    // SAFETY: the TArray header is data pointer, count, capacity.
    unsafe {
        let max = ((header as usize + 12) as *const i32).read_unaligned();
        // An empty string into an empty FString needs no buffer: leave the zero header.
        if text.is_empty() && max == 0 { return Ok(()); }
        if max < needed {
            super::tarray::grow_raw(header, 2, needed)?;
        }
        let data = (header as *const *mut u16).read_unaligned();
        for (index, unit) in text.encode_utf16().chain(std::iter::once(0)).enumerate() {
            data.add(index).write_unaligned(unit);
        }
        ((header as usize + 8) as *mut i32).write_unaligned(needed);
    }
    Ok(())
}

impl FString {
    pub fn len(&self) -> i32 {
        self.num
    }

    pub fn is_empty(&self) -> bool {
        self.num <= 0 || self.data.is_null()
    }

    pub fn as_string(&self) -> String {
        if self.is_empty() {
            return String::new();
        }
        // Cap reads at a plausible-name length. Engine-side
        // `AppendString` on a corrupt FName index has been observed
        // writing many KB of concatenated FFieldClass names into
        // the out buffer (UE pool spilling). 4096 wide chars is
        // comfortably above any real FName + protects against
        // unbounded reads.
        const MAX_WIDE: usize = 4096;
        let len = (self.num as usize).min(MAX_WIDE);
        // Strip trailing NUL if present.
        // SAFETY: is_empty() above short-circuited on null data
        // and num <= 0; len is clamped to MAX_WIDE = 4096 and to
        // `self.num`. The engine's FString invariant is that
        // `data` points at `num` wchar_t elements (we also cap
        // beyond that as a corruption defense). slice lifetime
        // ends at the closing `}`.
        let slice_len = if len > 0 && unsafe { slice::from_raw_parts(self.data, len) }[len - 1] == 0
        {
            len - 1
        } else {
            len
        };
        // SAFETY: same invariant as the preceding read; `slice_len`
        // is one of `{ len - 1, len }` so it is also bounded by
        // MAX_WIDE and by the engine-provided `num`.
        let units = unsafe { slice::from_raw_parts(self.data, slice_len) };
        let s = String::from_utf16_lossy(units);
        // Defense in depth: if the (capped) result still contains
        // interior NULs, the name is corrupt. Truncate at the
        // first NUL. Real FName strings never have interior NULs.
        if let Some(nul) = s.find('\0') {
            s[..nul].to_string()
        } else {
            s
        }
    }
}

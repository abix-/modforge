// FString = TArray<wchar_t>. Layout: { data: *mut u16, num: i32, max: i32 }.
// We treat it as borrowed for read paths, but FStrings produced by game
// functions (AppendString, ToString-style getters) own their wchar_t
// buffer; we have to free that buffer.
//
// The SDK pattern is to call `delete[]` (C++ operator) on Data when Max>0.
// Calling `delete[]` from Rust would require linking the game's CRT, which
// is messy. Instead we leak the buffer -- it's bytes-per-conversion small
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
        let slice_len = if len > 0 && unsafe { slice::from_raw_parts(self.data, len) }[len - 1] == 0
        {
            len - 1
        } else {
            len
        };
        let units = unsafe { slice::from_raw_parts(self.data, slice_len) };
        let s = String::from_utf16_lossy(units);
        // Defense in depth: if the (capped) result still contains
        // interior NULs, the name is corrupt -- truncate at the
        // first NUL. Real FName strings never have interior NULs.
        if let Some(nul) = s.find('\0') {
            s[..nul].to_string()
        } else {
            s
        }
    }
}

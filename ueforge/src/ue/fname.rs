// FName: 8 bytes ({ comparison_index: i32, number: u32 }). To resolve it to
// a string we call the game's AppendString export at module_base +
// offsets.append_string. Matches Basic.hpp:341.
//
// `to_string` caches by FName u64 to avoid re-running AppendString for the
// same name on every call. Each AppendString invocation leaks its FString
// buffer (we don't bind UE's FMemory::Free); the cache caps the leak at
// one buffer per unique FName -- bounded by the game's name pool size
// (~50K) instead of unbounded per call. See `fstring.rs`.
//
// The cache stores `Arc<str>` so cache hits return one ref-bump
// instead of a heap-allocating `String::clone`. Callers that need
// an owned `String` call `.to_string()` once at the boundary --
// same cost as before; callers that just compare or substring
// (e.g. `name.starts_with("Default__")`) save the allocation
// entirely.

use std::collections::HashMap;
use std::sync::Arc;

use parking_lot::RwLock;

use crate::ue::fstring::FString;
use crate::ue::offsets::PlatformOffsets;

#[repr(C)]
#[derive(Clone, Copy, Debug)]
pub struct FName {
    pub comparison_index: i32,
    pub number: u32,
}

// Compile-time guard: every `transmute_copy::<u64, FName>` /
// `as_u64()` site assumes FName is exactly 8 bytes. If UE ever
// changes the layout (e.g. UE5.x bumps to a 12-byte
// `WIDE_NAME_LENGTH` scheme), this fires at build time instead
// of silently corrupting names at runtime.
const _: () = {
    assert!(
        std::mem::size_of::<FName>() == 8,
        "FName must be 8 bytes for u64 transmute round-trips"
    );
    assert!(
        std::mem::align_of::<FName>() <= 8,
        "FName alignment must fit in u64"
    );
};

impl FName {
    pub fn is_none(self) -> bool {
        self.comparison_index == 0 && self.number == 0
    }

    /// Pack the 8-byte FName into a single u64 -- usable as a hash
    /// key, useful for transmute round-trips with the engine
    /// (`std::mem::transmute_copy` from a u64 reproduces the same
    /// FName).
    pub fn as_u64(self) -> u64 {
        ((self.number as u64) << 32) | (self.comparison_index as u32 as u64)
    }
}

type AppendStringFn = unsafe extern "system" fn(*const FName, *mut FString);

pub struct NameResolver {
    append_string: AppendStringFn,
    cache: RwLock<HashMap<u64, Arc<str>>>,
}

impl NameResolver {
    pub unsafe fn new(image_base: usize, offsets: &PlatformOffsets) -> Self {
        let addr = image_base + offsets.append_string;
        let append_string: AppendStringFn = unsafe { std::mem::transmute(addr) };
        Self {
            append_string,
            // 8K starting capacity covers the average game's
            // hot-path name set without growing.
            cache: RwLock::new(HashMap::with_capacity(8192)),
        }
    }

    /// Cached resolve. Cache hit returns an `Arc<str>` ref-bump;
    /// miss runs AppendString once (leaks one FString buffer per
    /// unique FName) and stores the result.
    pub unsafe fn to_arc(&self, name: FName) -> Arc<str> {
        let key = name.as_u64();
        if let Some(s) = self.cache.read().get(&key) {
            return s.clone();
        }
        let mut out = FString::default();
        unsafe { (self.append_string)(&name as *const FName, &mut out as *mut FString) };
        let arc: Arc<str> = Arc::from(out.as_string().into_boxed_str());
        self.cache.write().insert(key, arc.clone());
        arc
    }

    /// Owned `String` form. One alloc at the boundary; identical
    /// cost to the old API. Prefer [`Self::to_arc`] when the caller
    /// only needs a borrowed `&str`.
    pub unsafe fn to_string(&self, name: FName) -> String {
        unsafe { self.to_arc(name) }.to_string()
    }
}

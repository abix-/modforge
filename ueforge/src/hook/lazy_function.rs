//! Lazily-cached UFunction pointer for hot-path identity dispatch.
//!
//! ProcessEvent trampolines fire thousands of times per second. The
//! handler's job is: "if `function` is `OnLanded`, do work; else
//! forward to the engine." Calling `function.as_object().name()` to
//! check costs an FName resolve + heap allocation per fire -- ~1k+
//! string allocs/sec for a busy class. The fix is to cache the
//! `&UFunction` pointer the first time we see the right name and
//! pointer-compare on every subsequent fire.
//!
//! `LazyFunctionPtr` packages this pattern. The trampoline calls
//! [`LazyFunctionPtr::matches`] -- one atomic load + one branch on
//! the warm path; the cold path resolves the FName once, populates
//! the cache, and is never taken again for that function.
//!
//! ```ignore
//! static ON_LANDED: LazyFunctionPtr = LazyFunctionPtr::new();
//!
//! fn on_event(this: &UObject, function: &UFunction, parms: *mut c_void, original: OriginalProcessEvent) {
//!     if !ON_LANDED.matches(function, "OnLanded") {
//!         unsafe { original.call(this, function, parms) };
//!         return;
//!     }
//!     // ... handle the OnLanded event ...
//!     unsafe { original.call(this, function, parms) };
//! }
//! ```
//!
//! Compare with [`super::function_table!`] which resolves *every*
//! function at install time from a known class. `LazyFunctionPtr`
//! is for trampolines that hook a *class* and want to fast-discriminate
//! one (or a few) functions on that class without paying the install-
//! time round trip for every UFunction the class might dispatch.

use std::sync::atomic::{AtomicUsize, Ordering};

use crate::ue::UFunction;

pub struct LazyFunctionPtr {
    cached: AtomicUsize,
}

impl Default for LazyFunctionPtr {
    fn default() -> Self {
        Self::new()
    }
}

impl LazyFunctionPtr {
    pub const fn new() -> Self {
        Self {
            cached: AtomicUsize::new(0),
        }
    }

    /// Returns `true` iff `function` is the cached UFunction OR (on
    /// the very first match-by-name call) iff its FName equals
    /// `expected_name`. Caches the pointer on the name-match path so
    /// every subsequent fire is a single atomic load + branch.
    ///
    /// Hot-path properties:
    /// - Warm path (cache populated, function is the right one):
    ///   1 atomic load + 1 compare.
    /// - Warm path (cache populated, function is something else):
    ///   1 atomic load + 1 compare. **No FName resolve.**
    /// - Cold path (cache empty, first fire of any function):
    ///   1 FName resolve + string compare. If matched, 1 atomic
    ///   write. Each function sees this at most once.
    pub fn matches(&self, function: &UFunction, expected_name: &str) -> bool {
        let fp = function as *const UFunction as usize;
        let cached = self.cached.load(Ordering::Relaxed);
        if cached != 0 {
            return cached == fp;
        }
        // Cold path: cache empty. Resolve name; cache on match.
        if function.as_object().name() == expected_name {
            // Race-tolerant: any number of trampoline threads may
            // win, all stores are the same pointer.
            self.cached.store(fp, Ordering::Relaxed);
            return true;
        }
        false
    }

    /// True if the cache has been populated at least once.
    pub fn is_cached(&self) -> bool {
        self.cached.load(Ordering::Relaxed) != 0
    }

    /// Raw cached pointer as `usize`, or 0 if not yet seen. For
    /// debug/snapshot use.
    pub fn cached_ptr(&self) -> usize {
        self.cached.load(Ordering::Relaxed)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn const_constructible() {
        const _F: LazyFunctionPtr = LazyFunctionPtr::new();
    }

    #[test]
    fn empty_initially() {
        let f = LazyFunctionPtr::new();
        assert!(!f.is_cached());
        assert_eq!(f.cached_ptr(), 0);
    }

    // We can't construct a real UFunction from a unit test (would
    // require a running UE process), so the cache state-machine here
    // is exercised on bbp's in-game smoke runs. The const + initial
    // state checks above are what unit tests can guarantee.
}

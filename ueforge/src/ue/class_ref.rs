//! Typed cached UClass handle.
//!
//! `ClassRef::new("Name")` is a `const`-friendly handle that
//! resolves the class lazily on first use and pointer-compares
//! forever after. Replaces the hand-rolled
//! `OnceLock<*const UClass>` + `find_class_fast` + `is_a` walk
//! pattern that every UE4SS-Rust mod ends up with.
//!
//! ```ignore
//! static HEALTH: ClassRef = ClassRef::new("HealthComponent");
//!
//! HEALTH.with_cdo(|cdo| {
//!     // read default fields...
//! });
//! HEALTH.for_each_instance(|hc| {
//!     // mutate live components...
//! });
//! let func = HEALTH.find_function("ApplyDamageFromInfo");
//! ```
//!
//! Lifetimes: UClasses, CDOs and the UFunctions they own live for
//! the life of the UE process once they exist in GObjects. The
//! handle hands out `&'static` references; callers that want a
//! shorter lifetime can re-borrow.

use std::sync::OnceLock;

use crate::ue::{
    GObjectsView, UClass, UFunction, UObject, find_class_fast, try_runtime,
};

pub struct ClassRef {
    name: &'static str,
    /// `*const UClass as usize` so the static is `Send + Sync`. The
    /// pointer is to a UClass that lives forever in GObjects.
    cached: OnceLock<usize>,
}

impl ClassRef {
    pub const fn new(name: &'static str) -> Self {
        Self {
            name,
            cached: OnceLock::new(),
        }
    }

    pub fn name(&self) -> &'static str {
        self.name
    }

    /// Resolve the class. None if the engine has not loaded it yet
    /// (early hook install before GObjects has the target class).
    /// Cached on first hit.
    pub fn get(&self) -> Option<&'static UClass> {
        if let Some(&p) = self.cached.get() {
            // SAFETY: UClasses live for life of process; the cached
            // pointer was a valid `&'static UClass` at insert time.
            return unsafe { (p as *const UClass).as_ref() };
        }
        let class = find_class_fast(self.name)?;
        let _ = self.cached.set(class as *const UClass as usize);
        Some(class)
    }

    /// True once the class has been resolved at least once.
    pub fn is_cached(&self) -> bool {
        self.cached.get().is_some()
    }

    /// Class default object. None if class not loaded or CDO missing.
    pub fn cdo(&self) -> Option<&'static UObject> {
        let cls = self.get()?;
        cls.class_default_object().map(|o| unsafe {
            // SAFETY: CDO lives as long as the class.
            &*(o as *const UObject)
        })
    }

    /// Find a UFunction whose outer chain contains this class. Uses
    /// the receiver's class name automatically -- no need to pass it
    /// twice the way `UClass::get_function` requires.
    pub fn find_function(&self, fn_name: &str) -> Option<&'static UFunction> {
        let cls = self.get()?;
        cls.get_function(self.name, fn_name)
            .map(|f| unsafe { &*(f as *const UFunction) })
    }

    /// Call `f` on the CDO. Returns true on hit.
    pub fn with_cdo<R>(&self, f: impl FnOnce(&UObject) -> R) -> Option<R> {
        self.cdo().map(f)
    }

    /// Call `f` on every non-CDO instance of this class (including
    /// subclasses, via `is_a`) in GObjects. Returns the count.
    /// Cold path -- walks the full GObjects array.
    pub fn for_each_instance(&self, mut f: impl FnMut(&UObject)) -> usize {
        let Some(rt) = try_runtime() else {
            return 0;
        };
        let Some(cls) = self.get() else {
            return 0;
        };
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return 0;
        }
        let mut count = 0;
        for obj in view.iter() {
            if !obj.is_a(cls) || obj.is_default_object() {
                continue;
            }
            f(obj);
            count += 1;
        }
        count
    }

    /// Call `f` on the first non-CDO instance found. Returns true on
    /// hit. Useful for singleton-style classes (UGlobalCombatData,
    /// AInGameGameState).
    pub fn with_first_instance<R>(&self, f: impl FnOnce(&UObject) -> R) -> Option<R> {
        let rt = try_runtime()?;
        let cls = self.get()?;
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return None;
        }
        for obj in view.iter() {
            if !obj.is_a(cls) || obj.is_default_object() {
                continue;
            }
            return Some(f(obj));
        }
        None
    }

    /// Call `f` on every non-CDO instance matching `is_a(self)` for
    /// which `pred` returns true. Returns the count. Use for "live
    /// instances of class X whose full_name contains substring Y"
    /// patterns -- the generic shape of every per-player-pawn walk
    /// in apply code.
    pub fn for_each_matching(
        &self,
        mut pred: impl FnMut(&UObject) -> bool,
        mut f: impl FnMut(&UObject),
    ) -> usize {
        let Some(rt) = try_runtime() else {
            return 0;
        };
        let Some(cls) = self.get() else {
            return 0;
        };
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return 0;
        }
        let mut count = 0;
        for obj in view.iter() {
            if !obj.is_a(cls) || obj.is_default_object() {
                continue;
            }
            if !pred(obj) {
                continue;
            }
            f(obj);
            count += 1;
        }
        count
    }

    /// Call `f` on EVERY object in GObjects matching `is_a(self)`
    /// (both CDOs and non-CDOs). Use for singleton-style data
    /// assets where the CDO IS the real data (e.g.
    /// `UGlobalCombatData`).
    pub fn for_each_any(&self, mut f: impl FnMut(&UObject)) -> usize {
        let Some(rt) = try_runtime() else {
            return 0;
        };
        let Some(cls) = self.get() else {
            return 0;
        };
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return 0;
        }
        let mut count = 0;
        for obj in view.iter() {
            if !obj.is_a(cls) {
                continue;
            }
            f(obj);
            count += 1;
        }
        count
    }

    /// Call `f` on every CDO matching `is_a(self)` (the class's own
    /// CDO plus subclass CDOs). Returns the count. Distinct from
    /// [`Self::cdo`], which returns only the exact class's CDO.
    pub fn for_each_cdo_subclass(&self, mut f: impl FnMut(&UObject)) -> usize {
        let Some(rt) = try_runtime() else {
            return 0;
        };
        let Some(cls) = self.get() else {
            return 0;
        };
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return 0;
        }
        let mut count = 0;
        for obj in view.iter() {
            if !obj.is_a(cls) || !obj.is_default_object() {
                continue;
            }
            f(obj);
            count += 1;
        }
        count
    }

    /// Same as [`Self::for_each_cdo_subclass`] but with a predicate.
    /// For "every player-class CDO whose full_name marks it as the
    /// player BP" patterns.
    pub fn for_each_cdo_matching(
        &self,
        mut pred: impl FnMut(&UObject) -> bool,
        mut f: impl FnMut(&UObject),
    ) -> usize {
        let Some(rt) = try_runtime() else {
            return 0;
        };
        let Some(cls) = self.get() else {
            return 0;
        };
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return 0;
        }
        let mut count = 0;
        for obj in view.iter() {
            if !obj.is_a(cls) || !obj.is_default_object() {
                continue;
            }
            if !pred(obj) {
                continue;
            }
            f(obj);
            count += 1;
        }
        count
    }

    /// Runtime constructor that takes a borrowed `&str`. Leaks one
    /// heap copy of the name so the resulting ClassRef carries a
    /// `&'static str`. Cold path; intended for the rare apply call
    /// where the class name is computed (e.g. catalog row) instead
    /// of declared as a static constant. The underlying UClass
    /// lookup still rides `find_class_fast`'s internal cache, so
    /// the warm path is just as cheap as a static ClassRef.
    pub fn new_dynamic(name: &str) -> Self {
        let leaked: &'static str = Box::leak(name.to_owned().into_boxed_str());
        Self::new(leaked)
    }

    /// Walk every non-CDO instance and collect those for which
    /// `pred` returns true. Cold path; for one-shot lookups.
    pub fn find_instance(&self, mut pred: impl FnMut(&UObject) -> bool) -> Option<&'static UObject> {
        let rt = try_runtime()?;
        let cls = self.get()?;
        let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
        if !view.is_valid() {
            return None;
        }
        for obj in view.iter() {
            if !obj.is_a(cls) || obj.is_default_object() {
                continue;
            }
            if pred(obj) {
                return Some(unsafe { &*(obj as *const UObject) });
            }
        }
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    // We can't construct a real UClass without a running engine, so
    // these tests only exercise the lifecycle / not-yet-resolved path.

    #[test]
    fn unresolved_returns_none() {
        let cr = ClassRef::new("DoesNotExist");
        assert!(!cr.is_cached());
        assert!(cr.get().is_none());
        assert!(cr.cdo().is_none());
        assert!(cr.find_function("Foo").is_none());
        assert_eq!(cr.for_each_instance(|_| {}), 0);
        assert!(cr.with_first_instance(|_| ()).is_none());
        assert!(cr.find_instance(|_| true).is_none());
    }

    #[test]
    fn name_round_trip() {
        const FOO: ClassRef = ClassRef::new("FooClass");
        assert_eq!(FOO.name(), "FooClass");
    }

    #[test]
    fn const_constructible() {
        // Compile-time check: ClassRef::new must be const so it can
        // sit in a `static`.
        const _CR: ClassRef = ClassRef::new("X");
    }
}

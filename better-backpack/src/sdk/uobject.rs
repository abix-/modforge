// UObject + UClass + UFunction wrappers.
//
// We model these as zero-sized newtypes over raw pointers (well, around the
// actual UObject memory in the game). Field access goes through `field()`
// helpers that read at known offsets. No Rust-level inheritance -- callers
// pass `&UObject` everywhere and downcast via `is_a()`.

use std::ffi::c_void;
use std::sync::OnceLock;

use crate::sdk::fname::{FName, NameResolver};
use crate::sdk::offsets::{self, PlatformOffsets, fuobject_item, tuobject_array, uclass};

#[repr(transparent)]
pub struct UObject {
    _opaque: [u8; 0],
}

impl UObject {
    pub fn as_ptr(&self) -> *const u8 {
        self as *const UObject as *const u8
    }

    pub fn as_mut_ptr(&self) -> *mut u8 {
        self as *const UObject as *mut u8
    }

    unsafe fn read_field<T: Copy>(&self, offset: usize) -> T {
        unsafe { (self.as_ptr().add(offset) as *const T).read_unaligned() }
    }

    pub unsafe fn write_field<T: Copy>(&self, offset: usize, value: T) {
        unsafe { (self.as_mut_ptr().add(offset) as *mut T).write_unaligned(value) }
    }

    pub unsafe fn field_ptr(&self, offset: usize) -> *mut u8 {
        unsafe { self.as_mut_ptr().add(offset) }
    }

    pub fn class(&self) -> Option<&UClass> {
        unsafe {
            let p: *mut UClass = self.read_field(offsets::uobject::CLASS);
            p.as_ref()
        }
    }

    pub fn outer(&self) -> Option<&UObject> {
        unsafe {
            let p: *mut UObject = self.read_field(offsets::uobject::OUTER);
            p.as_ref()
        }
    }

    pub fn fname(&self) -> FName {
        unsafe { self.read_field(offsets::uobject::NAME) }
    }

    pub fn index(&self) -> i32 {
        unsafe { self.read_field(offsets::uobject::INDEX) }
    }

    /// "Default__" shows up in the FName for every CDO -- mirrors the C++
    /// IsDefaultObject implementation.
    pub fn is_default_object(&self) -> bool {
        let name = unsafe { runtime().name_resolver.to_string(self.fname()) };
        name.starts_with("Default__")
    }

    pub fn name(&self) -> String {
        unsafe { runtime().name_resolver.to_string(self.fname()) }
    }

    pub fn full_name(&self) -> String {
        let mut parts: Vec<String> = Vec::new();
        let mut cur = self.outer();
        while let Some(o) = cur {
            parts.push(o.name());
            cur = o.outer();
        }
        parts.reverse();
        let mut out = String::new();
        if let Some(cls) = self.class() {
            out.push_str(&cls.as_object().name());
            out.push(' ');
        }
        for (i, p) in parts.iter().enumerate() {
            if i > 0 {
                out.push('.');
            }
            out.push_str(p);
        }
        if !parts.is_empty() {
            out.push('.');
        }
        out.push_str(&self.name());
        out
    }

    pub fn is_a(&self, target: &UClass) -> bool {
        let mut cur: Option<&UClass> = self.class();
        while let Some(c) = cur {
            if std::ptr::eq(c, target) {
                return true;
            }
            cur = c.super_class();
        }
        false
    }

    /// Calls vtable[ProcessEventIdx] with (self, function, parms).
    pub unsafe fn process_event(&self, function: &UFunction, parms: *mut c_void) {
        let rt = runtime();
        unsafe {
            let vtable: *const *const c_void = self.read_field(offsets::uobject::VTABLE);
            let slot = *vtable.add(rt.platform_offsets.process_event_idx);
            let pe: ProcessEventFn = std::mem::transmute(slot);
            pe(self, function, parms);
        }
    }
}

pub type ProcessEventFn =
    unsafe extern "system" fn(this: *const UObject, function: *const UFunction, parms: *mut c_void);

#[repr(transparent)]
pub struct UClass {
    _opaque: [u8; 0],
}

impl UClass {
    pub fn as_object(&self) -> &UObject {
        unsafe { &*(self as *const UClass as *const UObject) }
    }

    pub fn class_default_object(&self) -> Option<&UObject> {
        unsafe {
            let p: *mut UObject = (self as *const UClass as *const u8)
                .add(uclass::CLASS_DEFAULT_OBJECT)
                .cast::<*mut UObject>()
                .read_unaligned();
            p.as_ref()
        }
    }

    pub fn super_class(&self) -> Option<&UClass> {
        unsafe {
            let p: *mut UClass = (self as *const UClass as *const u8)
                .add(offsets::ustruct::SUPER_STRUCT)
                .cast::<*mut UClass>()
                .read_unaligned();
            p.as_ref()
        }
    }

    /// Walk Children list looking for a UFunction whose name == `func_name`
    /// and whose outer chain contains an entry matching `class_name`.
    pub fn get_function(&self, class_name: &str, func_name: &str) -> Option<&UFunction> {
        let mut cur: Option<&UObject> = unsafe {
            let p: *mut UObject = (self as *const UClass as *const u8)
                .add(offsets::ustruct::CHILDREN)
                .cast::<*mut UObject>()
                .read_unaligned();
            p.as_ref()
        };
        while let Some(field) = cur {
            // UFunction inherits from UStruct inherits from UField. The
            // UField::Next chain at offset 0x28 gives us the sibling list.
            // We don't know up front whether `field` is a UFunction; we
            // match by name and let the caller's parms layout enforce
            // correctness.
            if field.name() == func_name {
                // Confirm it's owned (transitively) by `class_name`.
                let mut outer = field.outer();
                while let Some(o) = outer {
                    if o.name() == class_name {
                        return unsafe { Some(&*(field as *const UObject as *const UFunction)) };
                    }
                    outer = o.outer();
                }
            }
            cur = unsafe {
                let p: *mut UObject = field
                    .as_ptr()
                    .add(offsets::ufield::NEXT)
                    .cast::<*mut UObject>()
                    .read_unaligned();
                p.as_ref()
            };
        }
        None
    }
}

#[repr(transparent)]
pub struct UFunction {
    _opaque: [u8; 0],
}

impl UFunction {
    pub fn as_object(&self) -> &UObject {
        unsafe { &*(self as *const UFunction as *const UObject) }
    }

    pub fn function_flags(&self) -> u32 {
        unsafe {
            (self as *const UFunction as *const u8)
                .add(offsets::ufunction::FUNCTION_FLAGS)
                .cast::<u32>()
                .read_unaligned()
        }
    }

    pub fn set_function_flags(&self, flags: u32) {
        unsafe {
            (self as *const UFunction as *mut u8)
                .add(offsets::ufunction::FUNCTION_FLAGS)
                .cast::<u32>()
                .write_unaligned(flags);
        }
    }
}

// ---- GObjects ------------------------------------------------------------
//
// TUObjectArrayWrapper at image_base + offsets.g_objects holds a pointer to
// a TUObjectArray { Objects, MaxElements, NumElements }. Each element is an
// FUObjectItem { Object*, pad }.

pub struct GObjectsView {
    array: *const u8,
}

impl GObjectsView {
    pub unsafe fn from_image(image_base: usize, offsets: &PlatformOffsets) -> Self {
        // image_base + offsets.g_objects IS the address of the TUObjectArray
        // struct in game memory (first field is `Objects`, then MaxElements,
        // NumElements). Don't dereference -- treat it as the struct pointer
        // directly. This matches `reinterpret_cast<TUObjectArray*>(addr)`
        // in the C++ wrapper's operator->.
        let array = (image_base + offsets.g_objects) as *const u8;
        Self { array }
    }

    pub fn is_valid(&self) -> bool {
        !self.array.is_null()
    }

    pub fn num(&self) -> i32 {
        if self.array.is_null() {
            return 0;
        }
        unsafe {
            self.array
                .add(tuobject_array::NUM_ELEMENTS)
                .cast::<i32>()
                .read_unaligned()
        }
    }

    fn objects_ptr(&self) -> *const u8 {
        unsafe {
            self.array
                .add(tuobject_array::OBJECTS)
                .cast::<*const u8>()
                .read_unaligned()
        }
    }

    pub fn get(&self, index: i32) -> Option<&UObject> {
        if index < 0 || index >= self.num() {
            return None;
        }
        unsafe {
            let item = self.objects_ptr().add(index as usize * fuobject_item::SIZE);
            let obj: *const UObject = item
                .add(fuobject_item::OBJECT)
                .cast::<*const UObject>()
                .read_unaligned();
            obj.as_ref()
        }
    }

    pub fn iter(&self) -> impl Iterator<Item = &UObject> + '_ {
        (0..self.num()).filter_map(|i| self.get(i))
    }
}

// ---- Runtime singleton ---------------------------------------------------
//
// Captures image base + platform offsets + name resolver once at startup.
// Every UObject helper that needs offsets pulls from here. Initialized via
// `init_runtime` from the worker thread.

pub struct Runtime {
    pub image_base: usize,
    pub platform_offsets: &'static PlatformOffsets,
    pub name_resolver: NameResolver,
}

static RUNTIME: OnceLock<Runtime> = OnceLock::new();

pub fn runtime() -> &'static Runtime {
    RUNTIME.get().expect("sdk runtime not initialized")
}

pub fn try_runtime() -> Option<&'static Runtime> {
    RUNTIME.get()
}

/// One-shot. Subsequent calls are ignored.
pub unsafe fn init_runtime(
    image_base: usize,
    platform_offsets: &'static PlatformOffsets,
) -> &'static Runtime {
    let resolver = unsafe { NameResolver::new(image_base, platform_offsets) };
    let _ = RUNTIME.set(Runtime {
        image_base,
        platform_offsets,
        name_resolver: resolver,
    });
    runtime()
}

/// Walks GObjects looking for a UClass with the given short name. The
/// meta-class filter accepts native `Class` *and* its subclasses
/// (BlueprintGeneratedClass, WidgetBlueprintGeneratedClass, etc.) so
/// Blueprint-generated classes are returned too.
pub fn find_class_fast(name: &str) -> Option<&'static UClass> {
    let rt = try_runtime()?;
    let view = unsafe { GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return None;
    }
    for obj in view.iter() {
        if obj.name() != name {
            continue;
        }
        if !is_uclass_meta(obj.class()) {
            continue;
        }
        return unsafe { Some(&*(obj as *const UObject as *const UClass)) };
    }
    None
}

fn is_uclass_meta(meta: Option<&UClass>) -> bool {
    let mut cur = meta;
    let mut depth = 0;
    while let Some(c) = cur {
        if depth > 16 {
            return false;
        }
        if c.as_object().name() == "Class" {
            return true;
        }
        cur = c.super_class();
        depth += 1;
    }
    false
}

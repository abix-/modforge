//! Empty runtime subclasses that inherit the engine's fields and functions.
//! Def=DerivedClassDef, Registry=engine class table, Instance=UClass,
//! Controller=ensure. There are no Rust callbacks in the resulting class.
use crate::ue::{UClass, UObject};

/// Addresses and layout verified against the consuming game's binary.
pub struct ClassBindings {
    pub construct: u32,
    pub set_super: u32,
    pub bind: u32,
    pub link: u32,
    pub create_default: u32,
    pub update_defaults: u32,
    pub class_flags: usize,
    pub class_within: usize,
    pub config_name: usize,
}

pub struct DerivedClassDef {
    pub name: &'static str,
    pub parent: &'static str,
}

// FStaticConstructObjectParameters in UE 5.4. Empty TFunction storage has
// no callable or allocation; all optional construction inputs remain null.
#[repr(C, align(16))]
struct ConstructionParams {
    class: u64,
    outer: u64,
    name: u64,
    flags: u32,
    internal_flags: u32,
    options: [u8; 8],
    template: u64,
    instance_graph: u64,
    external_package: u64,
    callback: [u8; 64],
    subobject_overrides: u64,
}
const _: () = assert!(std::mem::size_of::<ConstructionParams>() == 144);

impl DerivedClassDef {
    /// Creates one process-lifetime class. Existing instances continue to use
    /// native engine code across mod reload; class definitions change on restart.
    ///
    /// # Safety
    /// Game thread only. Bindings must match the running engine, including the
    /// construction parameter ABI. The parent must already be fully loaded.
    pub unsafe fn ensure(&self, bindings: &ClassBindings, configure_defaults: impl FnOnce(&UObject) -> Result<(), String>) -> Result<&'static UClass, String> {
        let parent = crate::ue::find_class_fast(self.parent).ok_or_else(|| format!("parent {} unavailable", self.parent))?;
        if let Some(class) = crate::ue::find_class_fast(self.name) {
            if class.class_default_object().is_none() {
                return Err(format!("{} did not finish initialization; restart required", self.name));
            }
            if class.super_class().map(|c| c.as_object().name()).as_deref() != Some(self.parent) {
                return Err(format!("{} already exists with a different parent", self.name));
            }
            return Ok(class);
        }
        let meta = crate::ue::find_class_fast("BlueprintGeneratedClass").ok_or("BlueprintGeneratedClass unavailable")?;
        let outer = parent.as_object().outer().ok_or("parent class has no package")?;
        let name = crate::ue::fname::from_str(self.name, crate::ue::fname::FindName::Add).ok_or("class name unavailable")?;
        let params = ConstructionParams {
            class: meta as *const _ as u64, outer: outer.as_ptr() as u64,
            name: name.as_u64(), flags: 0x40 | 0x80, internal_flags: 0,
            options: [0; 8], template: 0, instance_graph: 0, external_package: 0,
            callback: [0; 64], subobject_overrides: 0,
        };
        let image = crate::ue::platform::host_image_base();
        // SAFETY: the caller supplies verified native ABI bindings. Construction
        // roots the class through the engine; no dangling class cache entry can
        // survive GC. Only native constructors and inherited script are retained.
        unsafe {
            let construct: unsafe extern "system" fn(*const ConstructionParams) -> u64 = std::mem::transmute(image + bindings.construct as usize);
            let set_super: unsafe extern "system" fn(u64, u64) = std::mem::transmute(image + bindings.set_super as usize);
            let bind: unsafe extern "system" fn(u64) = std::mem::transmute(image + bindings.bind as usize);
            let link: unsafe extern "system" fn(u64, bool) = std::mem::transmute(image + bindings.link as usize);
            let create_default: unsafe extern "system" fn(u64) -> u64 = std::mem::transmute(image + bindings.create_default as usize);
            let update: unsafe extern "system" fn(u64) = std::mem::transmute(image + bindings.update_defaults as usize);
            let result = modforge::seh::guard(|| {
                let address = construct(&params);
                if address == 0 { return Err("class construction returned null".to_owned()); }
                let parent_address = parent as *const UClass as usize;
                let bytes = address as *mut u8;
                // CLASS_ScriptInherit from ObjectMacros.h. Do not inherit native,
                // abstract, replication-cache, or assembled-GC-schema flags.
                let inherit = 0x8 | 0x10 | 0x2 | 0x4 | 0x400 | 0x40000000 |
                    0x200 | 0x10000 | 0x800000 | 0x2000000 | 0x200000 |
                    0x8000000 | 0x40 | 0x8000 | 0x20000 | 0x1000 | 0x2000;
                let flags = ((parent_address + bindings.class_flags) as *const u32).read_unaligned();
                bytes.add(bindings.class_flags).cast::<u32>().write_unaligned((flags & inherit) | 0x40000 | 0x8);
                for offset in [bindings.class_within, bindings.config_name] {
                    bytes.add(offset).cast::<u64>().write_unaligned(((parent_address + offset) as *const u64).read_unaligned());
                }
                set_super(address, parent_address as u64);
                bind(address);
                link(address, true);
                let defaults = create_default(address);
                if defaults == 0 { return Err("derived class has no default object".to_owned()); }
                configure_defaults(&*(defaults as *const UObject))?;
                update(address);
                Ok(address)
            }).map_err(|e| format!("create class {}: {e:?}", self.name))??;
            let class = &*(result as *const UClass);
            if class.super_class().map(|c| c as *const UClass) != Some(parent as *const UClass) {
                return Err("engine did not establish requested superclass".into());
            }
            Ok(class)
        }
    }
}

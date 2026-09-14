//! Read and write any reflected field of any live object from a JSON value,
//! call any function with named parameters, spawn any object: the generic
//! surface that lets behaviour be data instead of a rebuild. Every type is
//! decided by the property's own class name (ObjectProperty, BoolProperty,
//! ...), read from the property record the way the endpoint's field walker
//! does: the record's class pointer, then that class's name.
//!
//! Object references in JSON are strings: "0x..." an address, "asset:/Game/
//! Path.Name" an asset loaded on demand, "class:Name" a class, "null".
//! Bitfield bools write only their bit. Struct fields take a JSON object of
//! their own fields. FName fields take a string.
use crate::ue::{UObject, UClass};
use crate::ue::uobject::NativeProperty;
use serde_json::{Value, json};

/// The property record's class name: "ObjectProperty", "BoolProperty", ...
pub fn property_type(property: &NativeProperty) -> Option<String> {
    if property.address == 0 { return None; }
    let class = crate::ue::offsets::ffield::CLASS_PRIVATE;
    if !crate::winproc::is_addr_readable(property.address + class + 8) { return None; }
    // SAFETY: the FFieldClass pointer inside a live property record; its name is its first field.
    let field_class = unsafe { ((property.address + class) as *const u64).read_unaligned() };
    if field_class == 0 || !crate::winproc::is_addr_readable(field_class as usize + 8) { return None; }
    unsafe { crate::ue::fname::read_at(field_class as *const u8, 0) }
}

/// FStructProperty::Struct and FObjectProperty::PropertyClass follow the
/// FProperty base, which ends at 0x70 in this engine (FBoolProperty's own
/// fields start there, read from the shipped PDB: abioticfactor-mod
/// docs/history/lan-loading.md).
const PROPERTY_EXTRA: usize = 0x70;

/// The UScriptStruct a StructProperty holds, walkable as a UClass.
fn struct_of(property: &NativeProperty) -> Option<&'static UClass> {
    let at = property.address + PROPERTY_EXTRA;
    if property.address == 0 || !crate::winproc::is_addr_readable(at + 8) { return None; }
    // SAFETY: the Struct pointer after the FProperty base of a live record.
    let ptr = unsafe { (at as *const u64).read_unaligned() };
    if ptr == 0 { return None; }
    Some(unsafe { &*(ptr as *const UClass) })
}

/// Every reflected field of the object's class chain, with its type.
pub fn fields_of(object: &UObject) -> Vec<(NativeProperty, String)> {
    fields_in_chain(object.class())
}

fn fields_in_chain(mut class: Option<&UClass>) -> Vec<(NativeProperty, String)> {
    let mut out = Vec::new();
    let mut depth = 0;
    while let Some(current) = class {
        if depth >= 64 { break; }
        for property in current.cached_native_properties().iter() {
            out.push((property.clone(), property_type(property).unwrap_or_default()));
        }
        class = current.super_class();
        depth += 1;
    }
    out
}

/// One field of a class chain (or a struct) by name, with its type.
fn find_field(fields: &[(NativeProperty, String)], name: &str) -> Result<(NativeProperty, String), String> {
    fields.iter().find(|(p, _)| p.name == name).cloned().ok_or_else(|| format!("no reflected field {name}; fields: {:?}", fields.iter().map(|(p, t)| format!("{}:{t}", p.name)).collect::<Vec<_>>()))
}

/// Resolve a JSON object reference to a pointer.
pub fn object_ref(value: &Value) -> Result<u64, String> {
    match value {
        Value::Null => Ok(0),
        Value::Number(n) => n.as_u64().ok_or("object reference must be a non-negative integer".into()),
        Value::String(s) if s.is_empty() || s == "null" => Ok(0),
        Value::String(s) if s.starts_with("0x") => u64::from_str_radix(&s[2..], 16).map_err(|e| format!("{s}: {e}")),
        Value::String(s) if s.starts_with("class:") => crate::ue::find_class_fast(&s[6..]).map(|c| c as *const _ as u64).ok_or_else(|| format!("class {} not found", &s[6..])),
        Value::String(s) if s.starts_with("asset:") => {
            let (package, object) = s[6..].rsplit_once('.').ok_or("asset reference must be package.Object")?;
            let package = crate::ue::fname::from_str(package, crate::ue::fname::FindName::Add).ok_or("package FName unavailable")?;
            let object = crate::ue::fname::from_str(object, crate::ue::fname::FindName::Add).ok_or("asset FName unavailable")?;
            let loaded = crate::assets::load_asset(package.as_u64(), object.as_u64())?;
            if loaded == 0 { Err(format!("{s} did not load")) } else { Ok(loaded) }
        }
        Value::String(s) => crate::selector::resolve(s).map(|o| o as *const UObject as u64),
        other => Err(format!("cannot use {other} as an object reference")),
    }
}

/// Write one value at `base + property.offset` by the property's type. Game thread.
///
/// # Safety
/// `base` must be live memory laid out by the class or struct the property belongs to.
pub unsafe fn write_value(base: *mut u8, property: &NativeProperty, kind: &str, value: &Value) -> Result<(), String> {
    let at = unsafe { base.add(property.offset as usize) };
    let name = &property.name;
    // {"raw": "hex"}: the field's bytes as read back by read_value for kinds
    // it does not decode, passed through unchanged (a soft object reference, say).
    if let Some(hex) = value.get("raw").and_then(|v| v.as_str()) {
        let bytes = (0..hex.len() / 2).map(|i| u8::from_str_radix(&hex[i * 2..i * 2 + 2], 16)).collect::<Result<Vec<u8>, _>>().map_err(|e| format!("{name}: raw hex: {e}"))?;
        if bytes.len() > property.element_size as usize { return Err(format!("{name}: {} raw bytes exceed the field's {}", bytes.len(), property.element_size)); }
        // SAFETY: at most the field's own size.
        unsafe { std::ptr::copy_nonoverlapping(bytes.as_ptr(), at, bytes.len()) };
        return Ok(());
    }
    // SAFETY: the field's own bytes, sized by its type.
    unsafe {
        match kind {
            "BoolProperty" => {
                let layout = property.address + crate::ue::offsets::fboolproperty::FIELD_SIZE;
                let bytes = (layout as *const [u8; 4]).read_unaligned();
                if bytes[0] != 1 || bytes[3] == 0 { return Err(format!("{name}: unexpected bool layout {bytes:?}")); }
                let byte = at.add(bytes[1] as usize);
                let current = std::ptr::read_volatile(byte);
                let wanted = if value.as_bool().ok_or_else(|| format!("{name} takes a bool"))? { current | bytes[3] } else { current & !bytes[3] };
                std::ptr::write_volatile(byte, wanted);
            }
            "ByteProperty" | "EnumProperty" => std::ptr::write_volatile(at, value.as_u64().ok_or_else(|| format!("{name} takes a byte"))? as u8),
            "IntProperty" => std::ptr::write_volatile(at as *mut i32, value.as_i64().ok_or_else(|| format!("{name} takes an int"))? as i32),
            "UInt32Property" => std::ptr::write_volatile(at as *mut u32, value.as_u64().ok_or_else(|| format!("{name} takes an unsigned int"))? as u32),
            "Int64Property" => std::ptr::write_volatile(at as *mut i64, value.as_i64().ok_or_else(|| format!("{name} takes an int"))?),
            "FloatProperty" => std::ptr::write_volatile(at as *mut f32, value.as_f64().ok_or_else(|| format!("{name} takes a number"))? as f32),
            "DoubleProperty" => std::ptr::write_volatile(at as *mut f64, value.as_f64().ok_or_else(|| format!("{name} takes a number"))?),
            "NameProperty" => {
                let text = value.as_str().ok_or_else(|| format!("{name} takes a string"))?;
                let fname = crate::ue::fname::from_str(text, crate::ue::fname::FindName::Add).ok_or_else(|| format!("FName {text} unavailable"))?;
                std::ptr::write_volatile(at as *mut u64, fname.as_u64());
            }
            "ObjectProperty" | "ClassProperty" | "SoftObjectProperty" | "WeakObjectProperty" | "InterfaceProperty" => std::ptr::write_volatile(at as *mut u64, object_ref(value)?),
            "StrProperty" => crate::ue::fstring::write_at(at, value.as_str().ok_or_else(|| format!("{name} takes a string"))?)?,
            "StructProperty" => {
                let layout = struct_of(property).ok_or_else(|| format!("{name}: struct type unreadable"))?;
                let fields = fields_in_chain(Some(layout));
                let map = value.as_object().ok_or_else(|| format!("{name} takes an object of its struct's fields: {:?}", fields.iter().map(|(p, t)| format!("{}:{t}", p.name)).collect::<Vec<_>>()))?;
                for (sub, sub_value) in map {
                    let (sub_property, sub_kind) = find_field(&fields, sub)?;
                    write_value(at, &sub_property, &sub_kind, sub_value)?;
                }
            }
            "ArrayProperty" => {
                // A JSON array replaces the contents: count to zero, then one typed push per element.
                let elements = value.as_array().ok_or_else(|| format!("{name} takes an array"))?;
                let (inner, inner_kind) = inner_of(property)?;
                let stride = inner.element_size as usize;
                (at.add(8) as *mut i32).write_unaligned(0);
                for (index, element) in elements.iter().enumerate() {
                    crate::ue::tarray::grow_raw(at, stride, index as i32 + 1)?;
                    let data = (at as *const *mut u8).read_unaligned();
                    let slot = data.add(index * stride);
                    std::ptr::write_bytes(slot, 0, stride);
                    write_value(slot, &inner, &inner_kind, element)?;
                    (at.add(8) as *mut i32).write_unaligned(index as i32 + 1);
                }
            }
            other => return Err(format!("{name}: writing a {other} is not supported")),
        }
    }
    Ok(())
}

/// Read one value at `base + property.offset` by the property's type. Game thread.
///
/// # Safety
/// As [`write_value`].
pub unsafe fn read_value(base: *const u8, property: &NativeProperty, kind: &str) -> Value {
    let at = unsafe { base.add(property.offset as usize) };
    // SAFETY: the field's own bytes, sized by its type.
    unsafe {
        match kind {
            "BoolProperty" => {
                let layout = property.address + crate::ue::offsets::fboolproperty::FIELD_SIZE;
                let bytes = (layout as *const [u8; 4]).read_unaligned();
                json!(std::ptr::read_volatile(at.add(bytes[1] as usize)) & bytes[3] != 0)
            }
            "ByteProperty" | "EnumProperty" => json!(std::ptr::read_volatile(at)),
            "IntProperty" => json!((at as *const i32).read_unaligned()),
            "UInt32Property" => json!((at as *const u32).read_unaligned()),
            "Int64Property" => json!((at as *const i64).read_unaligned()),
            "FloatProperty" => json!((at as *const f32).read_unaligned()),
            "DoubleProperty" => json!((at as *const f64).read_unaligned()),
            "NameProperty" => json!(crate::ue::fname::read_at(at, 0).unwrap_or_default()),
            "ObjectProperty" | "ClassProperty" | "WeakObjectProperty" | "InterfaceProperty" => {
                let ptr = (at as *const u64).read_unaligned();
                if ptr == 0 || !crate::winproc::is_addr_readable(ptr as usize + 0x28) { Value::Null } else {
                    let object = &*(ptr as *const UObject);
                    json!({"addr": format!("0x{ptr:X}"), "name": object.name(), "class": object.class().map(|c| c.as_object().name()).unwrap_or_default()})
                }
            }
            "StrProperty" => json!((&*(at as *const crate::ue::FString)).as_string()),
            "StructProperty" => match struct_of(property) {
                Some(layout) => {
                    let mut map = serde_json::Map::new();
                    for (sub, kind) in fields_in_chain(Some(layout)) {
                        map.insert(sub.name.clone(), read_value(at, &sub, &kind));
                    }
                    Value::Object(map)
                }
                None => json!("struct"),
            },
            "ArrayProperty" => {
                let (data, count) = ((at as *const *const u8).read_unaligned(), (at.add(8) as *const i32).read_unaligned().max(0) as usize);
                if count == 0 { return json!([]); }
                match inner_of(property) {
                    Ok((inner, inner_kind)) if !data.is_null() => {
                        let stride = inner.element_size as usize;
                        json!((0..count.min(256)).map(|i| read_value(data.add(i * stride), &inner, &inner_kind)).collect::<Vec<_>>())
                    }
                    _ => json!({"count": count}),
                }
            }
            _ => {
                // Undecoded kinds come back as their raw bytes, which write_value accepts unchanged.
                let size = (property.element_size as usize).min(256);
                let bytes = std::slice::from_raw_parts(at, size);
                json!({"raw": bytes.iter().map(|b| format!("{b:02x}")).collect::<String>(), "kind": kind})
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty_arrays_decode_as_arrays_without_element_memory() {
        let property = NativeProperty { name: "OutActors".into(), offset: 0, element_size: 16, address: 0 };
        for data in [0u64, 8u64] {
            let header = [data, 0u64];
            // SAFETY: a complete empty TArray header; no element is accessed.
            let value = unsafe { read_value(header.as_ptr().cast(), &property, "ArrayProperty") };
            assert_eq!(value, json!([]));
        }
    }
}

/// The element property of an ArrayProperty (FArrayProperty::Inner), as a
/// property at offset 0 of each element. Read live from Abiotic Factor's
/// records (2026-09-13, abioticfactor-mod tests/research_tree.rs): the
/// element record pointer sits at +0x78, one pointer past where a struct
/// property keeps its struct (+0x70); +0x70 is zero on array records.
const ARRAY_INNER: usize = PROPERTY_EXTRA + 8;

fn inner_of(property: &NativeProperty) -> Result<(NativeProperty, String), String> {
    let at = property.address + ARRAY_INNER;
    if property.address == 0 || !crate::winproc::is_addr_readable(at + 8) { return Err(format!("{}: array record unreadable", property.name)); }
    // SAFETY: the Inner pointer after the FProperty base of a live array record.
    let inner = unsafe { (at as *const u64).read_unaligned() } as usize;
    let size_at = inner + crate::ue::runtime().platform_offsets.struct_layout.element_size;
    if inner == 0 || !crate::winproc::is_addr_readable(size_at + 4) { return Err(format!("{}: array element record unreadable", property.name)); }
    // SAFETY: the element record's own ElementSize.
    let element_size = unsafe { (size_at as *const i32).read_unaligned() };
    if element_size <= 0 || element_size > 65536 { return Err(format!("{}: implausible element size {element_size}", property.name)); }
    let inner = NativeProperty { name: format!("{}[]", property.name), offset: 0, element_size: element_size as u32, address: inner };
    let kind = property_type(&inner).unwrap_or_default();
    Ok((inner, kind))
}

/// Read the elements of an array field, all or one index. Game thread.
///
/// # Safety
/// `object` must be live.
pub unsafe fn array_get(object: &UObject, field: &str, index: Option<usize>) -> Result<Value, String> {
    let (property, kind) = find_field(&fields_of(object), field)?;
    if kind != "ArrayProperty" { return Err(format!("{field} is a {kind}, not an array")); }
    let (inner, inner_kind) = inner_of(&property)?;
    // SAFETY: a TArray header on the live object; elements sized by the inner property.
    let (data, count) = unsafe { let h = object.field_ptr(property.offset as usize); ((h as *const *const u8).read_unaligned(), (h.add(8) as *const i32).read_unaligned().max(0) as usize) };
    let stride = inner.element_size as usize;
    let read = |i: usize| -> Value { if i >= count || data.is_null() { Value::Null } else { unsafe { read_value(data.add(i * stride), &inner, &inner_kind) } } };
    Ok(match index {
        Some(i) => json!({"field": field, "count": count, "index": i, "value": read(i)}),
        None => json!({"field": field, "count": count, "element_type": inner_kind, "elements": (0..count.min(256)).map(read).collect::<Vec<_>>()}),
    })
}

/// Append one element to an array field, written by the element type. Game thread.
///
/// # Safety
/// `object` must be live.
pub unsafe fn array_push(object: &UObject, field: &str, value: &Value) -> Result<usize, String> {
    let (property, kind) = find_field(&fields_of(object), field)?;
    if kind != "ArrayProperty" { return Err(format!("{field} is a {kind}, not an array")); }
    let (inner, inner_kind) = inner_of(&property)?;
    let stride = inner.element_size as usize;
    // SAFETY: the TArray header on the live object; the new element is zeroed before the typed write.
    unsafe {
        let header = object.field_ptr(property.offset as usize);
        let count = (header.add(8) as *const i32).read_unaligned().max(0);
        crate::ue::tarray::grow_raw(header, stride, count + 1)?;
        let data = (header as *const *mut u8).read_unaligned();
        let slot = data.add(count as usize * stride);
        std::ptr::write_bytes(slot, 0, stride);
        write_value(slot, &inner, &inner_kind, value)?;
        (header.add(8) as *mut i32).write_unaligned(count + 1);
        Ok(count as usize + 1)
    }
}

/// Copy selected inherited fields by the engine's property copier. Unlike a byte copy, this
/// preserves separate ownership of maps, arrays and soft references.
///
/// # Safety
/// Both objects must be live on the game thread. The supplied RVA must be
/// this game's FProperty::CopyCompleteValueToScriptVM, verified from symbols.
pub unsafe fn copy_named_fields(from: &UObject, to: &UObject, names: &[&str], copy_value_rva: u32) -> Result<(), String> {
    let source = fields_of(from);
    let destination = fields_of(to);
    type CopyValue = unsafe extern "system" fn(usize, *mut u8, *const u8);
    // SAFETY: the caller supplies the verified native method for this image.
    let copy: CopyValue = unsafe { std::mem::transmute(crate::ue::platform::host_image_base() + copy_value_rva as usize) };
    for name in names {
        let (src, _) = find_field(&source, name)?;
        let (dst, _) = find_field(&destination, name)?;
        if src.address != dst.address { return Err(format!("{name}: objects do not share the declaring property")); }
        // SAFETY: the same inherited property describes both live values;
        // the engine performs deep copying through its virtual property API.
        modforge::seh::guard(|| unsafe {
            copy(src.address, to.as_mut_ptr().add(dst.offset as usize), from.as_ptr().add(src.offset as usize))
        }).map_err(|e| format!("copy {name}: {e}"))?;
    }
    Ok(())
}

/// Copy every reflected field of the classes both objects share, from one
/// to the other, by bytes. The engine's own way to give a new object an
/// existing one's values, used for cloning sense configs. Game thread.
///
/// # Safety
/// Both must be live objects.
pub unsafe fn copy_fields(from: &UObject, to: &UObject) -> Result<usize, String> {
    let (Some(from_class), Some(to_class)) = (from.class(), to.class()) else { return Err("an object has no class".into()) };
    let from_addr = from_class as *const UClass as usize;
    // The classes copied are those on the destination's chain that the source also derives from.
    let mut copied = 0usize;
    let mut class = Some(to_class);
    let mut depth = 0;
    while let Some(current) = class {
        if depth >= 64 { break; }
        let mut source = Some(from_class);
        let mut shares = false;
        while let Some(s) = source { if s as *const UClass as usize == current as *const UClass as usize { shares = true; break; } source = s.super_class(); }
        let _ = from_addr;
        if shares {
            for property in current.cached_native_properties().iter() {
                let (offset, size) = (property.offset as usize, property.element_size as usize);
                if offset < crate::ue::offsets::uobject::SIZE || size == 0 || size > 4096 { continue; }
                // SAFETY: a reflected field of both live objects of this shared class.
                unsafe { std::ptr::copy_nonoverlapping(from.as_ptr().add(offset), to.as_mut_ptr().add(offset), size) };
                copied += 1;
            }
        }
        class = current.super_class();
        depth += 1;
    }
    Ok(copied)
}

/// Write named fields of a live object from a JSON map. Game thread.
///
/// # Safety
/// `object` must be live.
pub unsafe fn set_fields(object: &UObject, values: &serde_json::Map<String, Value>) -> Result<(), String> {
    let fields = fields_of(object);
    for (name, value) in values {
        let (property, kind) = find_field(&fields, name)?;
        unsafe { write_value(object.as_mut_ptr(), &property, &kind, value)? };
    }
    Ok(())
}

/// Read named fields (or every field) of a live object. Game thread.
///
/// # Safety
/// `object` must be live.
pub unsafe fn get_fields(object: &UObject, names: &[String]) -> Result<Value, String> {
    let fields = fields_of(object);
    let mut map = serde_json::Map::new();
    if names.is_empty() {
        for (property, kind) in &fields { map.insert(property.name.clone(), unsafe { read_value(object.as_ptr(), property, kind) }); }
    } else {
        for name in names {
            let (property, kind) = find_field(&fields, name)?;
            map.insert(name.clone(), unsafe { read_value(object.as_ptr(), &property, &kind) });
        }
    }
    Ok(Value::Object(map))
}

/// Call `class::function` on `target` with named parameters from JSON,
/// each written by its parameter's type; returns the output parameters
/// (ReturnValue included) read the same way. Game thread.
///
/// # Safety
/// `target` must be live.
pub unsafe fn call(target: &UObject, class: &str, function: &str, params: &serde_json::Map<String, Value>) -> Result<Value, String> {
    let uclass = crate::ue::find_class_fast(class).ok_or_else(|| format!("class '{class}' not found"))?;
    let func = uclass.get_function(class, function).ok_or_else(|| format!("function '{class}::{function}' not found"))?;
    let parameters: Vec<(NativeProperty, String)> = func.iter_parameters().into_iter().map(|p| { let t = property_type(&p).unwrap_or_default(); (p, t) }).collect();
    let mut parms = vec![0u8; func.parms_size().max(1) as usize];
    for (name, value) in params {
        let (property, kind) = find_field(&parameters, name)?;
        unsafe { write_value(parms.as_mut_ptr(), &property, &kind, value)? };
    }
    // SAFETY: game thread; the block is sized from the function's own ParmsSize.
    unsafe { target.process_event(func, parms.as_mut_ptr().cast()) };
    let mut out = serde_json::Map::new();
    for (property, kind) in &parameters {
        if params.contains_key(&property.name) { continue; }
        out.insert(property.name.clone(), unsafe { read_value(parms.as_ptr(), property, kind) });
    }
    Ok(Value::Object(out))
}

/// A new object of a class, owned by `outer`, through GameplayStatics::SpawnObject. Game thread.
///
/// # Safety
/// `outer` must be live.
pub unsafe fn spawn_object(class: &str, outer: u64) -> Result<u64, String> {
    let class_ptr = crate::ue::find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
    let statics = crate::selector::resolve("singleton:GameplayStatics")?;
    let reply = unsafe { call(statics, "GameplayStatics", "SpawnObject", &json!({"ObjectClass": format!("0x{:X}", class_ptr as *const _ as u64), "Outer": format!("0x{outer:X}")}).as_object().cloned().unwrap())? };
    let object = reply["ReturnValue"]["addr"].as_str().and_then(|a| u64::from_str_radix(a.trim_start_matches("0x"), 16).ok()).unwrap_or(0);
    if object == 0 { return Err(format!("SpawnObject returned null for {class}")); }
    Ok(object)
}

/// The ops: object.get, object.set, object.call, object.spawn. Each runs on
/// the game thread through the crate's own queue.
pub fn register_ops(drain: &'static crate::pe_queue::GameThread, hint: &'static str) {
    use crate::ops::{OP_REGISTRY, OpDef};
    let job = move |timeout: u64, f: Box<dyn FnOnce() -> Result<Value, String> + Send>| -> Result<Value, String> {
        crate::debug::enqueue_pe(drain, std::time::Duration::from_secs(timeout), hint, f)
    };
    OP_REGISTRY.register_many([
        OpDef::new("struct.layout", "A script struct's reflected fields (name, type, offset, size) from the live game", "{name: str}", |args| {
            let name = args["name"].as_str().ok_or("name is required")?;
            let layout = crate::ue::find_struct_fast(name).ok_or_else(|| format!("struct {name} not found"))?;
            let fields: Vec<Value> = fields_in_chain(Some(layout)).iter().map(|(p, kind)| json!({"name": p.name, "type": kind, "offset": p.offset, "size": p.element_size})).collect();
            Ok(json!({"name": name, "fields": fields}))
        }),
        OpDef::new("array.get", "Read an array field of a live object: every element (up to 256) or one index, decoded by the element type", "{object: selector, field: str, index?: u64}", move |args| {
            let selector = args["object"].as_str().ok_or("object must be a selector")?.to_owned();
            let field = args["field"].as_str().ok_or("field is required")?.to_owned();
            let index = args["index"].as_u64().map(|i| i as usize);
            job(10, Box::new(move || { let object = crate::selector::resolve(&selector)?; unsafe { array_get(object, &field, index) } }))
        }),
        OpDef::new("array.push", "Append one element to an array field of a live object, written by the element type", "{object: selector, field: str, value: value}", move |args| {
            let selector = args["object"].as_str().ok_or("object must be a selector")?.to_owned();
            let field = args["field"].as_str().ok_or("field is required")?.to_owned();
            let value = args["value"].clone();
            job(10, Box::new(move || { let object = crate::selector::resolve(&selector)?; Ok(json!({"count": unsafe { array_push(object, &field, &value)? }})) }))
        }),
        OpDef::new("object.copy", "Copy every reflected field of the classes two objects share, from one to the other", "{from: selector, to: selector}", move |args| {
            let from = args["from"].as_str().ok_or("from must be a selector")?.to_owned();
            let to = args["to"].as_str().ok_or("to must be a selector")?.to_owned();
            job(10, Box::new(move || { let (from, to) = (crate::selector::resolve(&from)?, crate::selector::resolve(&to)?); Ok(json!({"copied": unsafe { copy_fields(from, to)? }})) }))
        }),
        OpDef::new("object.get", "Read reflected fields of a live object by name (all fields when none given), decoded by their property types", "{object: selector, fields?: [str]}", move |args| {
            let selector = args["object"].as_str().ok_or("object must be a selector")?.to_owned();
            let names: Vec<String> = args["fields"].as_array().into_iter().flatten().filter_map(|v| v.as_str().map(str::to_owned)).collect();
            job(10, Box::new(move || { let object = crate::selector::resolve(&selector)?; unsafe { get_fields(object, &names) } }))
        }),
        OpDef::new("object.set", "Write reflected fields of a live object from a JSON map, each by its property type (bitfield bools by their bit, objects by 0x address, asset:Path.Name or class:Name, structs by an object of their fields)", "{object: selector, fields: {name: value}}", move |args| {
            let selector = args["object"].as_str().ok_or("object must be a selector")?.to_owned();
            let values = args["fields"].as_object().cloned().ok_or("fields must be an object")?;
            job(10, Box::new(move || { let object = crate::selector::resolve(&selector)?; unsafe { set_fields(object, &values)? }; Ok(json!({"written": values.len()})) }))
        }),
        OpDef::new("object.call", "Call class::function on a live object with named parameters from JSON; returns the output parameters", "{object: selector, class: str, function: str, params?: {name: value}}", move |args| {
            let selector = args["object"].as_str().ok_or("object must be a selector")?.to_owned();
            let class = args["class"].as_str().ok_or("class is required")?.to_owned();
            let function = args["function"].as_str().ok_or("function is required")?.to_owned();
            let params = args["params"].as_object().cloned().unwrap_or_default();
            job(30, Box::new(move || { let object = crate::selector::resolve(&selector)?; unsafe { call(object, &class, &function, &params) } }))
        }),
        OpDef::new("object.spawn", "Create an object of a class owned by outer (GameplayStatics::SpawnObject), optionally setting fields", "{class: str, outer: selector, fields?: {name: value}}", move |args| {
            let class = args["class"].as_str().ok_or("class is required")?.to_owned();
            let outer = args["outer"].as_str().ok_or("outer must be a selector")?.to_owned();
            let values = args["fields"].as_object().cloned().unwrap_or_default();
            job(10, Box::new(move || {
                let outer = crate::selector::resolve(&outer)? as *const UObject as u64;
                let object = unsafe { spawn_object(&class, outer)? };
                // SAFETY: the object the engine just created.
                unsafe { set_fields(&*(object as *const UObject), &values)? };
                Ok(json!({"addr": format!("0x{object:X}"), "class": class}))
            }))
        }),
    ]);
}

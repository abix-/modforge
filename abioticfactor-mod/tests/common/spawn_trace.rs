//! Read-only semantic trace of the cooked spawn loop identified by stack unwinding.
use modforge::client::Api;
use serde_json::{Value, json};
use windows_sys::Win32::{Foundation::HANDLE, System::Diagnostics::Debug::ReadProcessMemory};

fn http_read(api: &Api<Value>, address: u64, length: usize) -> Result<Vec<u8>, String> {
    let reply = api.try_op("read_bytes", json!({"instance_selector":format!("addr:0x{address:X}"),"length":length})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("HTTP read failed: {:?}", reply.error)); }
    hex::decode(reply.result["bytes_hex"].as_str().ok_or("missing bytes_hex")?).map_err(|e| e.to_string())
}

pub fn navigation_generation(api: &Api<Value>) -> Result<(), String> {
    let reply = api.try_op("walk_class_chain", json!({"needle":"RecastNavMesh","max":128})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("navigation instances: {:?}", reply.error)); }
    let pdb = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    let generation_enum = ueforge::symbols::enumeration(pdb, "ERuntimeGenerationType").map_err(|e| e.to_string())?;
    let mut offsets = std::collections::BTreeMap::new();
    let mut meshes = Vec::new();
    for instance in reply.result["instances"].as_array().ok_or("navigation instances")? {
        let address = u64::from_str_radix(instance["addr"].as_str().ok_or("navigation address")?.trim_start_matches("0x"),16).map_err(|e| e.to_string())?;
        let class = u64::from_le_bytes(http_read(api, address + 16,8)?.try_into().unwrap());
        let offset = if let Some(offset) = offsets.get(&class) { *offset } else {
            let (_, offset) = class_field(api, class, "RuntimeGeneration")?;
            offsets.insert(class, offset);
            offset
        };
        let value = http_read(api, address + u64::from(offset),1)?[0];
        let label = generation_enum.iter().find(|(_, number)| *number == i64::from(value))
            .map(|(name, _)| name).ok_or("unknown runtime generation value")?;
        meshes.push(json!({"instance":instance,"runtime_generation":label,"value":value}));
    }
    if meshes.is_empty() { return Err("no navigation mesh instances".into()); }
    let result = json!({"meshes":meshes,"generation_enum":generation_enum});
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/navigation-generation.json");
    std::fs::write(path, serde_json::to_vec_pretty(&result).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("{result}");
    Ok(())
}

pub fn sophia_movement_state(api: &Api<Value>) -> Result<(), String> {
    let reply = api.try_op("walk_class_chain", json!({"needle":"Abiotic_PlayerController_C","max":32})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("controllers: {:?}", reply.error)); }
    let mut matches = Vec::new();
    for instance in reply.result["instances"].as_array().ok_or("controllers")? {
        let address = u64::from_str_radix(instance["addr"].as_str().ok_or("controller address")?.trim_start_matches("0x"),16).map_err(|e| e.to_string())?;
        let state = object_field(api, address, "PlayerState")?;
        if state == 0 { continue; }
        let offset = field_offset(api, state, "PlayerNamePrivate")?;
        let bytes = http_read(api, state + u64::from(offset), 16)?;
        let pointer = u64::from_le_bytes(bytes[..8].try_into().unwrap());
        let count = u32::from_le_bytes(bytes[8..12].try_into().unwrap()) as usize;
        if count == 0 { continue; }
        if count > 256 { return Err("oversized player name".into()); }
        let name = String::from_utf16(&http_read(api, pointer, count * 2)?.chunks_exact(2).take(count-1)
            .map(|b| u16::from_le_bytes([b[0],b[1]])).collect::<Vec<_>>()).map_err(|e| e.to_string())?;
        if name == "Sophia" { matches.push(address); }
    }
    if matches.len() != 1 { return Err(format!("expected one Sophia controller, found {}", matches.len())); }
    let controller = matches[0];
    let character = object_field(api, controller, "PlayerCharacter")?;
    if character == 0 { return Err("Sophia controller has no initialized character".into()); }
    let root = object_field(api, character, "RootComponent")?;
    let movement = object_field(api, character, "CharacterMovement")?;
    let mut result = json!({"player":"Sophia","transform":scene_transform(api,root)?});
    let class = u64::from_le_bytes(http_read(api,character + 16,8)?.try_into().unwrap());
    for name in ["IsDisabled", "ServerLevelLoaded", "OwningLevelLoaded", "IsDead", "IsDBNO"] {
        let (property, offset) = class_field(api, class, name)?;
        // Current shipped PDB FBoolProperty: FieldSize/ByteOffset/ByteMask/FieldMask.
        let layout = http_read(api, property + 0x70,4)?;
        if layout[0] != 1 || layout[3] == 0 { return Err("unexpected boolean layout".into()); }
        let byte = http_read(api, character + u64::from(offset) + u64::from(layout[1]),1)?[0];
        result[name] = json!({"offset":offset,"raw_byte":byte,"field_mask":layout[3],"value":byte & layout[3] != 0});
    }
    let offset = field_offset(api, movement, "MovementMode")?;
    result["movement_mode"] = json!(http_read(api,movement + u64::from(offset),1)?[0]);
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/sophia-movement-state.json");
    std::fs::write(path, serde_json::to_vec_pretty(&result).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("{result}");
    Ok(())
}

pub fn sector_table(api: &Api<Value>) -> Result<(), String> {
    let reply = api.try_op("walk_class_chain", json!({"needle":"DataTable","max":256})).map_err(|e| e.to_string())?;
    let table = reply.result["instances"].as_array().ok_or("table instances")?.iter()
        .find(|row| row["name"].as_str() == Some("DT_Levels") || row["full_name"].as_str().is_some_and(|n| n.ends_with(".DT_Levels"))).ok_or("DT_Levels instance")?;
    let address = u64::from_str_radix(table["addr"].as_str().ok_or("table address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
    let header = http_read(api, address + 0x28, 88)?;
    let row_struct = u64::from_le_bytes(header[..8].try_into().unwrap());
    let (_, file_offset) = class_field(api, row_struct, "LevelFileName_4_4189631446EDDBE4B5EAE69952F1577C")?;
    let (_, sector_offset) = class_field(api, row_struct, "SectorName_13_6D7367C44F16A1C849E2EA9A512F6777")?;
    let (_, day_offset) = class_field(api, row_struct, "LevelFXRow_Day_9_730F761F48B9E958F8502BB10C47C998")?;
    let (_, night_offset) = class_field(api, row_struct, "LevelFXRow_Night_8_0062E3FB47C3AD2FA814B988D9F37B33")?;
    let rows = u64::from_le_bytes(header[8..16].try_into().unwrap());
    let count = u32::from_le_bytes(header[16..20].try_into().unwrap());
    let free = u32::from_le_bytes(header[60..64].try_into().unwrap());
    if count > 1000 || free != 0 { return Err("unexpected sparse level table".into()); }
    let mut result = Vec::new();
    for row in http_read(api, rows, count as usize * 24)?.chunks_exact(24) {
        let row_name = schema_name(api, u64::from_le_bytes(row[..8].try_into().unwrap()))?;
        let pointer = u64::from_le_bytes(row[8..16].try_into().unwrap());
        let file_name = schema_name(api, u64::from_le_bytes(http_read(api, pointer + u64::from(file_offset), 8)?.try_into().unwrap()))?;
        let day = schema_name(api, u64::from_le_bytes(http_read(api, pointer + u64::from(day_offset) + 8, 8)?.try_into().unwrap()))?;
        let night = schema_name(api, u64::from_le_bytes(http_read(api, pointer + u64::from(night_offset) + 8, 8)?.try_into().unwrap()))?;
        let sector = sector_text(api, pointer + u64::from(sector_offset))?;
        result.push(json!({"row":row_name,"level":file_name,"sector":sector,"day":day,"night":night}));
    }
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/sector-table.json");
    std::fs::write(path, serde_json::to_vec_pretty(&result).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("{} level/sector rows exported", result.len());
    Ok(())
}

/// Every reflected field of a struct or class chain: (name, property class, offset).
/// Offset is at +0x44, the same field the working object lookup reads.
fn struct_fields(api: &Api<Value>, mut class: u64) -> Result<Vec<(String, String, u32)>, String> {
    let mut fields = Vec::new();
    for _ in 0..32 {
        if class == 0 { break; }
        let mut field = u64::from_le_bytes(http_read(api, class + 80, 8)?.try_into().unwrap());
        let mut seen = std::collections::BTreeSet::new();
        while field != 0 && seen.insert(field) && seen.len() < 10000 {
            let data = http_read(api, field, 72)?;
            let name = schema_name(api, u64::from_le_bytes(data[32..40].try_into().unwrap()))?;
            let field_class = u64::from_le_bytes(data[8..16].try_into().unwrap());
            let kind = schema_name(api, u64::from_le_bytes(http_read(api, field_class, 8)?.try_into().unwrap()))?;
            let offset = u32::from_le_bytes(data[68..72].try_into().unwrap());
            if offset > 100_000 { return Err(format!("field {name} ({kind}) has implausible offset {offset}")); }
            fields.push((name, kind, offset));
            field = u64::from_le_bytes(data[24..32].try_into().unwrap());
        }
        class = u64::from_le_bytes(http_read(api, class + 64, 8)?.try_into().unwrap());
    }
    Ok(fields)
}

/// Every reflected field of a live object's class chain: (name, property class, offset).
pub fn object_fields(api: &Api<Value>, object: u64) -> Result<Vec<(String, String, u32)>, String> {
    let class = u64::from_le_bytes(http_read(api, object + 16, 8)?.try_into().unwrap());
    struct_fields(api, class)
}

/// The name of a live object (its FName at +24), or None for a null pointer.
fn object_name(api: &Api<Value>, object: u64) -> Result<Option<String>, String> {
    if object == 0 { return Ok(None); }
    Ok(Some(schema_name(api, u64::from_le_bytes(http_read(api, object + 24, 8)?.try_into().unwrap()))?))
}

/// Decode one row field by its property class, reading only the fixed byte
/// width that property type needs (no element-size read, which was unreliable).
fn decode_field(api: &Api<Value>, kind: &str, address: u64) -> Result<Value, String> {
    let read = |n: usize| http_read(api, address, n);
    Ok(match kind {
        "NameProperty" => json!(schema_name(api, u64::from_le_bytes(read(8)?.try_into().unwrap()))?),
        "ObjectProperty" | "ClassProperty" | "WeakObjectProperty" => json!(object_name(api, u64::from_le_bytes(read(8)?.try_into().unwrap()))?),
        "SoftObjectProperty" | "SoftClassProperty" => {
            let b = read(16)?;
            json!(format!("{}.{}", schema_name(api, u64::from_le_bytes(b[..8].try_into().unwrap()))?, schema_name(api, u64::from_le_bytes(b[8..16].try_into().unwrap()))?))
        }
        "FloatProperty" => json!(f32::from_le_bytes(read(4)?.try_into().unwrap())),
        "DoubleProperty" => json!(f64::from_le_bytes(read(8)?.try_into().unwrap())),
        "IntProperty" => json!(i32::from_le_bytes(read(4)?.try_into().unwrap())),
        "BoolProperty" | "ByteProperty" | "EnumProperty" => json!(read(1)?[0]),
        "StrProperty" => {
            let b = read(16)?;
            let (pointer, count) = (u64::from_le_bytes(b[..8].try_into().unwrap()), u32::from_le_bytes(b[8..12].try_into().unwrap()) as usize);
            if pointer != 0 && count > 1 && count < 1024 {
                json!(String::from_utf16_lossy(&http_read(api, pointer, count * 2)?.chunks_exact(2).take(count - 1).map(|b| u16::from_le_bytes([b[0], b[1]])).collect::<Vec<_>>()))
            } else { json!("") }
        }
        _ => json!(kind),
    })
}

/// Dump the named rows of a data table with every field decoded. Reads the
/// table's row struct and row map directly, since the generic snapshot cannot
/// decode this build's Blueprint row structs.
pub fn table_rows(api: &Api<Value>, table_name: &str, wanted: &[&str]) -> Result<Value, String> {
    let reply = api.try_op("walk_class_chain", json!({"needle":"DataTable","max":512})).map_err(|e| e.to_string())?;
    let table = reply.result["instances"].as_array().ok_or("table instances")?.iter()
        .find(|row| row["name"].as_str() == Some(table_name) || row["full_name"].as_str().is_some_and(|n| n.ends_with(&format!(".{table_name}")))).ok_or(format!("{table_name} instance"))?;
    let address = u64::from_str_radix(table["addr"].as_str().ok_or("table address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
    let header = http_read(api, address + 0x28, 88)?;
    let row_struct = u64::from_le_bytes(header[..8].try_into().unwrap());
    let fields = struct_fields(api, row_struct)?;
    let rows = u64::from_le_bytes(header[8..16].try_into().unwrap());
    let count = u32::from_le_bytes(header[16..20].try_into().unwrap());
    if count > 2000 { return Err("unexpected row count".into()); }
    let mut result = serde_json::Map::new();
    for row in http_read(api, rows, count as usize * 24)?.chunks_exact(24) {
        let row_name = schema_name(api, u64::from_le_bytes(row[..8].try_into().unwrap()))?;
        if !wanted.contains(&row_name.as_str()) { continue; }
        let pointer = u64::from_le_bytes(row[8..16].try_into().unwrap());
        let mut decoded = serde_json::Map::new();
        for (name, kind, offset) in &fields {
            let short = name.split('_').next().unwrap_or(name).to_owned();
            decoded.insert(format!("{short} ({kind})"), decode_field(api, kind, pointer + u64::from(*offset))?);
        }
        result.insert(row_name, Value::Object(decoded));
    }
    Ok(Value::Object(result))
}

/// Every live sense config (sight and hearing) with its numbers and owner path,
/// the perception setup enemies use to find targets.
pub fn perception_configs(api: &Api<Value>) -> Result<Value, String> {
    let mut result = Vec::new();
    for (needle, names) in [
        ("AISenseConfig_Sight", &["SightRadius", "LoseSightRadius", "PeripheralVisionAngleDegrees", "AutoSuccessRangeFromLastSeenLocation", "PointOfViewBackwardOffset", "NearClippingRadius", "MaxAge"][..]),
        ("AISenseConfig_Hearing", &["HearingRange", "LoSHearingRange", "MaxAge"][..]),
    ] {
        let reply = api.try_op("walk_class_chain", json!({"needle": needle, "max": 256})).map_err(|e| e.to_string())?;
        let mut offsets: Option<Vec<(String, String, u32)>> = None;
        for instance in reply.result["instances"].as_array().ok_or("sense config instances")? {
            if instance["is_cdo"] == true { continue; }
            let address = u64::from_str_radix(instance["addr"].as_str().ok_or("config address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
            if offsets.is_none() {
                let class = u64::from_le_bytes(http_read(api, address + 16, 8)?.try_into().unwrap());
                offsets = Some(struct_fields(api, class)?);
            }
            let mut row = serde_json::Map::new();
            row.insert("owner".into(), json!(instance["full_name"].as_str().unwrap_or("")));
            for (name, kind, offset) in offsets.as_ref().unwrap() {
                if names.contains(&name.as_str()) || name == "DetectionByAffiliation" {
                    row.insert(name.clone(), decode_field(api, kind, address + u64::from(*offset))?);
                }
            }
            result.push(Value::Object(row));
        }
    }
    Ok(json!(result))
}

// The existing mod's generic table decoder uses stale declarations. This pure
// text conversion uses the current reflected parameter layout instead.
fn sector_text(api: &Api<Value>, address: u64) -> Result<String, String> {
    let params = api.try_op("function_parameters", json!({"class":"KismetTextLibrary","function":"Conv_TextToString"})).map_err(|e| e.to_string())?;
    if !params.ok { return Err(format!("text conversion parameters: {:?}", params.error)); }
    let fields = params.result["parameters"].as_array().ok_or("text conversion fields")?;
    let input = fields.iter().find(|f| f["name"] == "InText").ok_or("InText")?;
    let output = fields.iter().find(|f| f["name"] == "ReturnValue").ok_or("ReturnValue")?;
    let input_offset = input["offset"].as_u64().ok_or("input offset")? as usize;
    let output_offset = output["offset"].as_u64().ok_or("output offset")? as usize;
    let size = params.result["parms_size"].as_u64().ok_or("parameter size")? as usize;
    if size != 32 || input["element_size"] != 16 || output["element_size"] != 16 { return Err(format!("text conversion layout: {}", params.result)); }
        let mut buffer = vec![0; size];
        buffer[input_offset..input_offset + 16].copy_from_slice(&http_read(api, address, 16)?);
        let converted = api.try_op("call", json!({"class":"KismetTextLibrary","function":"Conv_TextToString","instance_selector":"singleton:KismetTextLibrary","parms_hex":hex::encode(buffer)})).map_err(|e| e.to_string())?;
        if !converted.ok { return Err(format!("text conversion: {:?}", converted.error)); }
        let bytes = hex::decode(converted.result["parms_hex_after"].as_str().ok_or("converted text buffer")?).map_err(|e| e.to_string())?;
        let string = &bytes[output_offset..output_offset + 16];
        let pointer = u64::from_le_bytes(string[..8].try_into().unwrap());
        let count = u32::from_le_bytes(string[8..12].try_into().unwrap());
        if count > 1024 { return Err("oversized sector text".into()); }
        let sector = if count == 0 { String::new() } else {
            let wide = http_read(api, pointer, count as usize * 2)?;
            String::from_utf16(&wide.chunks_exact(2).take(count as usize - 1).map(|v| u16::from_le_bytes([v[0],v[1]])).collect::<Vec<_>>()).map_err(|e| e.to_string())?
        };
    Ok(sector)
}

pub fn sector_client_snapshot(api: &Api<Value>) -> Result<(), String> {
    let reply = api.try_op("resolve_selector", json!({"selector":"first_class:Abiotic_PlayerController_C"})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("controller lookup: {:?}", reply.error)); }
    let address = u64::from_str_radix(reply.result["addr"].as_str().ok_or("controller address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
    let mut result = serde_json::Map::new();
    let declaration = api.try_op("function_parameters", json!({"class":"AbioticFunctionLibrary","function":"IsDemoMode"})).map_err(|e| e.to_string())?;
    if !declaration.ok || declaration.result["parms_size"] != 1 {
        return Err(format!("demo mode declaration: {}", declaration.result));
    }
    let demo = api.try_op("call", json!({"class":"AbioticFunctionLibrary","function":"IsDemoMode","instance_selector":"singleton:AbioticFunctionLibrary","parms_hex":"00"})).map_err(|e| e.to_string())?;
    if !demo.ok { return Err(format!("demo mode query: {:?}", demo.error)); }
    let demo = hex::decode(demo.result["parms_hex_after"].as_str().ok_or("demo mode result")?).map_err(|e| e.to_string())?;
    if demo.len() != 1 { return Err("demo mode result length".into()); }
    result.insert("demo_mode".into(), json!(demo[0] != 0));
    for name in ["ActiveLevelFXName", "CheatLevelFXName", "OverrideLevelFXName", "ActiveWeatherFXName", "ActiveSubFXName", "Day_FX_Row", "Night_FX_Row"] {
        let offset = field_offset(api, address, name)?;
        let value = schema_name(api, u64::from_le_bytes(http_read(api, address + u64::from(offset), 8)?.try_into().unwrap()))?;
        result.insert(name.into(), json!(value));
    }
    let offset = field_offset(api, address, "Location_CurrentSectorName")?;
    result.insert("sector".into(), json!(sector_text(api, address + u64::from(offset))?));
    let offset = field_offset(api, address, "ActiveLevelName")?;
    let string = http_read(api, address + u64::from(offset), 16)?;
    let pointer = u64::from_le_bytes(string[..8].try_into().unwrap());
    let count = u32::from_le_bytes(string[8..12].try_into().unwrap());
    if count == 0 || count > 1024 { return Err("missing/oversized active level name".into()); }
    let wide = http_read(api, pointer, count as usize * 2)?;
    let level = String::from_utf16(&wide.chunks_exact(2).take(count as usize - 1).map(|v| u16::from_le_bytes([v[0], v[1]])).collect::<Vec<_>>()).map_err(|e| e.to_string())?;
    result.insert("level".into(), json!(level));
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/sector-client-snapshot.json");
    std::fs::write(path, serde_json::to_vec_pretty(&result).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("client sector observation: {}", Value::Object(result));
    Ok(())
}

fn scene_transform(api: &Api<Value>, component: u64) -> Result<Value, String> {
    // Current PDB: USceneComponent::ComponentToWorld +0x1D0; TTransform<double>
    // rotation/translation/scale at +0/+0x20/+0x40 in a 96-byte aligned record.
    let bytes = http_read(api, component + 0x130, 0x100)?;
    let socket = schema_name(api, u64::from_le_bytes(http_read(api, component + 0xC0, 8)?.try_into().unwrap()))?;
    scene_transform_bytes(&bytes, &socket)
}

fn scene_transform_bytes(bytes: &[u8], socket: &str) -> Result<Value, String> {
    if bytes.len() != 0x100 { return Err("scene transform byte count".into()); }
    let vector = |offset: usize, count: usize| -> Result<Vec<f64>, String> {
        let values: Vec<_> = bytes[offset..offset + count * 8].chunks_exact(8)
            .map(|b| f64::from_le_bytes(b.try_into().unwrap())).collect();
        if !values.iter().all(|v| v.is_finite()) { return Err("non-finite component transform".into()); }
        Ok(values)
    };
    Ok(json!({"rotation":vector(0xA0,4)?,"translation":vector(0xC0,3)?,"scale":vector(0xE0,3)?,
        "relative_location":vector(0,3)?,"relative_rotation":vector(0x18,3)?,"relative_scale":vector(0x30,3)?,"flags":bytes[0x60],"socket":socket}))
}

fn sector_overlap_components(api: &Api<Value>, volume: u64, character: u64) -> Result<Value, String> {
    let declaration = api.try_op("function_parameters", json!({"class":"Actor","function":"GetOverlappingComponents"})).map_err(|e| e.to_string())?;
    let fields = declaration.result["parameters"].as_array().ok_or("component overlap declaration")?;
    if !declaration.ok || declaration.result["parms_size"] != 16 || fields.len() != 1 || fields[0]["offset"] != 0 || fields[0]["element_size"] != 16 {
        return Err(format!("unexpected component overlap declaration: {}", declaration.result));
    }
    let reply = api.try_op("call", json!({"class":"Actor","function":"GetOverlappingComponents","instance_selector":format!("addr:0x{volume:X}"),"parms_hex":hex::encode([0_u8;16])})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("component overlap query: {:?}", reply.error)); }
    let bytes = hex::decode(reply.result["parms_hex_after"].as_str().ok_or("component overlap array")?).map_err(|e| e.to_string())?;
    if bytes.len() != 16 { return Err("component overlap result length".into()); }
    let pointer = u64::from_le_bytes(bytes[..8].try_into().unwrap());
    let count = u32::from_le_bytes(bytes[8..12].try_into().unwrap()) as usize;
    if count > 1024 { return Err("oversized component overlap array".into()); }
    let mut result = Vec::new();
    if count != 0 {
        for pointer in http_read(api, pointer, count * 8)?.chunks_exact(8) {
            let component = u64::from_le_bytes(pointer.try_into().unwrap());
            let header = http_read(api, component, 40)?;
            let class = u64::from_le_bytes(header[16..24].try_into().unwrap());
            let name = schema_name(api, u64::from_le_bytes(header[24..32].try_into().unwrap()))?;
            let class = schema_name(api, u64::from_le_bytes(http_read(api, class + 24, 8)?.try_into().unwrap()))?;
            let outer = u64::from_le_bytes(header[32..40].try_into().unwrap());
            if outer != character { continue; }
            let outer_name = schema_name(api, u64::from_le_bytes(http_read(api, outer + 24, 8)?.try_into().unwrap()))?;
            let mut entry = json!({"address":component,"name":name,"class":class,"outer":outer_name,"outer_is_observed_character":outer == character});
            entry["world_transform"] = scene_transform(api, component)?;
            if class == "CapsuleComponent" {
                let capsule = http_read(api, component + 0x548, 8)?;
                entry["unscaled_half_height"] = json!(f32::from_le_bytes(capsule[..4].try_into().unwrap()));
                entry["unscaled_radius"] = json!(f32::from_le_bytes(capsule[4..].try_into().unwrap()));
            } else if class == "SphereComponent" {
                let offset = field_offset(api, component, "SphereRadius")?;
                entry["radius_offset"] = json!(offset);
                entry["unscaled_radius"] = json!(f32::from_le_bytes(http_read(api, component + u64::from(offset), 4)?.try_into().unwrap()));
            }
            for name in ["RelativeLocation", "RelativeRotation", "RelativeScale3D"] {
                let offset = field_offset(api, component, name)?;
                let bytes = http_read(api, component + u64::from(offset), 24)?;
                entry[name] = json!(bytes.chunks_exact(8).map(|bytes| f64::from_le_bytes(bytes.try_into().unwrap())).collect::<Vec<_>>());
            }
            let parent = object_field(api, component, "AttachParent")?;
            entry["attach_parent"] = if parent == 0 { Value::Null } else {
                json!(schema_name(api, u64::from_le_bytes(http_read(api, parent + 24, 8)?.try_into().unwrap()))?)
            };
            let mut chain = Vec::new();
            let mut parent = parent;
            let mut seen = std::collections::BTreeSet::new();
            while parent != 0 {
                if !seen.insert(parent) || seen.len() > 16 { return Err("attachment chain cycle/limit".into()); }
                let name = schema_name(api, u64::from_le_bytes(http_read(api, parent + 24, 8)?.try_into().unwrap()))?;
                chain.push(json!({"address":parent,"name":name,"transform":scene_transform(api,parent)?}));
                parent = object_field(api, parent, "AttachParent")?;
            }
            entry["attachment_chain"] = json!(chain);
            result.push(entry);
        }
    }
    Ok(json!(result))
}

pub fn sector_level_selection(api: &Api<Value>) -> Result<(), String> {
    capture_sector(api, false)
}

pub fn sector_pose_snapshot(api: &Api<Value>) -> Result<(), String> {
    // Fail before the long discovery capture if the installed mod predates
    // the new operation. This call reads one byte of the controller only.
    let reply = api.try_op("read_snapshot", json!({"reads":[{
        "instance_selector":"first_class:Abiotic_PlayerController_C","length":1
    }]})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("read_snapshot unavailable: {:?}", reply.error)); }
    capture_sector(api, true)
}

fn refresh_character_pose(api: &Api<Value>, observations: &mut [Value]) -> Result<Value, String> {
    let mut addresses = std::collections::BTreeMap::<u64, usize>::new();
    for observation in observations.iter() {
        for component in observation["components"].as_array().ok_or("components")? {
            let length = if component["class"] == "CapsuleComponent" { 0x550 } else if component["class"] == "SphereComponent" {
                let offset = component["radius_offset"].as_u64().ok_or("radius offset")?;
                if offset > 0x10000 { return Err("unexpected radius offset".into()); }
                (offset as usize + 4).max(0x230)
            } else { return Err("unknown character shape".into()); };
            let address = component["address"].as_u64().ok_or("component address")?;
            addresses.entry(address).and_modify(|size| *size = (*size).max(length)).or_insert(length);
            for parent in component["attachment_chain"].as_array().ok_or("attachment chain")? {
                addresses.entry(parent["address"].as_u64().ok_or("parent address")?).or_insert(0x230);
            }
        }
    }
    if addresses.is_empty() { return Err("no character components discovered".into()); }
    // Read headers, parent/socket, both transforms and shape dimensions in
    // one queued operation. Discovery names are checked against these headers.
    let reads: Vec<_> = addresses.iter().map(|(address, length)| json!({
        "instance_selector":format!("addr:0x{address:X}"),"length":length
    })).collect();
    let reply = api.try_op("read_snapshot", json!({"reads":reads})).map_err(|e| e.to_string())?;
    if !reply.ok || reply.result["game_thread"] != true {
        return Err(format!("character snapshot: {:?}", reply.error));
    }
    let results = reply.result["reads"].as_array().ok_or("snapshot ranges")?;
    if results.len() != addresses.len() { return Err("snapshot range count".into()); }
    let mut captured = std::collections::BTreeMap::new();
    for ((address, length), result) in addresses.iter().zip(results) {
        let bytes = hex::decode(result["bytes_hex"].as_str().ok_or("snapshot bytes")?).map_err(|e| e.to_string())?;
        if bytes.len() != *length { return Err("snapshot component byte count".into()); }
        captured.insert(*address, bytes);
    }
    let transform = |address: u64, expected_name: &Value| -> Result<Value, String> {
        let bytes = captured.get(&address).ok_or("uncaptured component")?;
        let name = schema_name(api, u64::from_le_bytes(bytes[24..32].try_into().unwrap()))?;
        if expected_name != &json!(name) { return Err("component changed after discovery".into()); }
        let socket = schema_name(api, u64::from_le_bytes(bytes[0xC0..0xC8].try_into().unwrap()))?;
        scene_transform_bytes(&bytes[0x130..0x230], &socket)
    };
    for observation in observations.iter_mut() {
        for component in observation["components"].as_array_mut().ok_or("components")? {
            let address = component["address"].as_u64().ok_or("component address")?;
            component["world_transform"] = transform(address, &component["name"])?;
            let mut child = address;
            for parent in component["attachment_chain"].as_array_mut().ok_or("attachment chain")? {
                let address = parent["address"].as_u64().ok_or("parent address")?;
                if u64::from_le_bytes(captured[&child][0xB8..0xC0].try_into().unwrap()) != address {
                    return Err("attachment changed after discovery".into());
                }
                parent["transform"] = transform(address, &parent["name"])?;
                child = address;
            }
            if captured[&child][0xB8..0xC0] != [0; 8] { return Err("root attachment changed".into()); }
            let bytes = &captured[&address];
            if component["class"] == "CapsuleComponent" {
                component["unscaled_half_height"] = json!(f32::from_le_bytes(bytes[0x548..0x54C].try_into().unwrap()));
                component["unscaled_radius"] = json!(f32::from_le_bytes(bytes[0x54C..0x550].try_into().unwrap()));
            } else if component["class"] == "SphereComponent" {
                let offset = component["radius_offset"].as_u64().ok_or("radius offset")? as usize;
                let value = bytes.get(offset..offset + 4).ok_or("radius outside capture")?;
                component["unscaled_radius"] = json!(f32::from_le_bytes(value.try_into().unwrap()));
            }
            for (field, key) in [("RelativeLocation","relative_location"), ("RelativeRotation","relative_rotation"), ("RelativeScale3D","relative_scale")] {
                component[field] = component["world_transform"][key].clone();
            }
        }
    }
    Ok(json!({"game_thread":true,"frame":reply.result["frame"],"scope":"character transforms and dimensions only"}))
}

fn capture_sector(api: &Api<Value>, coherent_pose: bool) -> Result<(), String> {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    sector_client_snapshot(api)?;
    let observed_before = std::fs::read(root.join("sector-client-snapshot.json")).map_err(|e| e.to_string())?;
    let resolve = |selector: &str| -> Result<u64, String> {
        let reply = api.try_op("resolve_selector", json!({"selector":selector})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("resolve {selector}: {:?}", reply.error)); }
        u64::from_str_radix(reply.result["addr"].as_str().ok_or("object address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())
    };
    let controller = resolve("first_class:Abiotic_PlayerController_C")?;
    let spectator = object_field(api, controller, "ActiveSpectatorActor")?;
    if spectator != 0 { return Err("capture requires normal non-spectating client".into()); }
    let character = object_field(api, controller, "PlayerCharacter")?;
    if character == 0 { return Err("controller has no character".into()); }
    let mut world = controller;
    for _ in 0..16 {
        let class = u64::from_le_bytes(http_read(api, world + 16, 8)?.try_into().unwrap());
        let name = schema_name(api, u64::from_le_bytes(http_read(api, class + 24, 8)?.try_into().unwrap()))?;
        if name == "World" { break; }
        world = u64::from_le_bytes(http_read(api, world + 32, 8)?.try_into().unwrap());
        if world == 0 { return Err("level manager has no world outer".into()); }
    }
    let world_class = u64::from_le_bytes(http_read(api, world + 16, 8)?.try_into().unwrap());
    if schema_name(api, u64::from_le_bytes(http_read(api, world_class + 24, 8)?.try_into().unwrap()))? != "World" {
        return Err("world outer traversal limit".into());
    }
    // Resolve through the controller's world and native GetComponent path;
    // first_class:LevelManagerComponent may resolve a component template.
    let game_state = u64::from_le_bytes(http_read(api, world + 0x160, 8)?.try_into().unwrap());
    if game_state == 0 { return Err("controller's world has no game state".into()); }
    let component = u64::from_le_bytes(http_read(api, game_state + 0x438, 8)?.try_into().unwrap());
    if component == 0 || http_read(api, component + 0xB8, 1)?[0] == 0 { return Err("world level manager is not initialized".into()); }
    let world_time = f64::from_le_bytes(http_read(api, world + 0x6C0, 8)?.try_into().unwrap());
    let params = api.try_op("function_parameters", json!({"class":"Actor","function":"IsOverlappingActor"})).map_err(|e| e.to_string())?;
    if !params.ok { return Err(format!("actor overlap parameters: {:?}", params.error)); }
    let fields = params.result["parameters"].as_array().ok_or("overlap parameter fields")?;
    let input = fields.iter().find(|f| f["name"] == "Other").ok_or_else(|| format!("overlap input declaration: {}", params.result))?;
    let output = fields.iter().find(|f| f["name"] == "ReturnValue").ok_or("overlap return field")?;
    let size = params.result["parms_size"].as_u64().ok_or("overlap parameter size")? as usize;
    let input_offset = input["offset"].as_u64().ok_or("Other offset")? as usize;
    let output_offset = output["offset"].as_u64().ok_or("overlap return offset")? as usize;
    if size > 128 || input_offset + 8 > size || output_offset >= size || input["element_size"] != 8 || output["element_size"] != 1 {
        return Err(format!("unexpected overlap layout: {}", params.result));
    }
    let header = http_read(api, component + 0xC0, 56)?;
    let data = u64::from_le_bytes(header[..8].try_into().unwrap());
    let count = u32::from_le_bytes(header[8..12].try_into().unwrap()) as usize;
    let bit_count = u32::from_le_bytes(header[40..44].try_into().unwrap()) as usize;
    let bits_pointer = u64::from_le_bytes(header[32..40].try_into().unwrap());
    if count == 0 || count > 1024 || bit_count != count { return Err("unexpected level sparse map size".into()); }
    let mask_bytes = count.div_ceil(32) * 4;
    let mask = if bits_pointer != 0 { http_read(api, bits_pointer, mask_bytes)? } else {
        if mask_bytes > 16 { return Err("level map exceeds inline allocation mask".into()); }
        header[16..16 + mask_bytes].to_vec()
    };
    let entries = http_read(api, data, count * 24)?;
    let mut levels = Vec::new();
    let mut collision_observations = Vec::new();
    let mut volume_observations = Vec::new();
    for (index, entry) in entries.chunks_exact(24).enumerate() {
        if mask[index / 8] & (1 << (index % 8)) == 0 { continue; }
        let instance = u64::from_le_bytes(entry[8..16].try_into().unwrap());
        let bytes = http_read(api, instance + 0x28, 0x90)?;
        let streaming = u64::from_le_bytes(bytes[..8].try_into().unwrap());
        if streaming == 0 { return Err("capture contains missing level streaming object".into()); }
        let level = schema_name(api, u64::from_le_bytes(http_read(api, streaming + 0x38, 8)?.try_into().unwrap()))?;
        let last_visible = f32::from_le_bytes(bytes[0x88..0x8C].try_into().unwrap());
        let volumes_pointer = u64::from_le_bytes(bytes[8..16].try_into().unwrap());
        let volume_count = u32::from_le_bytes(bytes[16..20].try_into().unwrap()) as usize;
        if volume_count > 1024 { return Err("oversized instance volume array".into()); }
        let mut overlapping_volumes = Vec::new();
        if volume_count != 0 {
            for pointer in http_read(api, volumes_pointer, volume_count * 8)?.chunks_exact(8) {
                let volume = u64::from_le_bytes(pointer.try_into().unwrap());
                if volume == 0 { continue; }
                let mut buffer = vec![0; size];
                buffer[input_offset..input_offset + 8].copy_from_slice(&character.to_le_bytes());
                let reply = api.try_op("call", json!({"class":"Actor","function":"IsOverlappingActor","instance_selector":format!("addr:0x{volume:X}"),"parms_hex":hex::encode(buffer)})).map_err(|e| e.to_string())?;
                if !reply.ok { return Err(format!("overlap query: {:?}", reply.error)); }
                let output = hex::decode(reply.result["parms_hex_after"].as_str().ok_or("overlap output")?).map_err(|e| e.to_string())?;
                let overlaps = output.get(output_offset).copied().ok_or("short overlap output")? != 0;
                let name = schema_name(api, u64::from_le_bytes(http_read(api, volume + 24, 8)?.try_into().unwrap()))?;
                let brush = object_field(api, volume, "BrushComponent")?;
                volume_observations.push(json!({"name":name,"level":level,"overlapping":overlaps,"transform":scene_transform(api,brush)?,"registered":true}));
                if overlaps {
                    collision_observations.push(json!({"volume":name,"components":sector_overlap_components(api, volume, character)?}));
                    overlapping_volumes.push(name);
                }
            }
        }
        if !last_visible.is_finite() { return Err("non-finite visibility time".into()); }
        levels.push(json!({"level":level,"last_time_visible":last_visible,"overlapping":!overlapping_volumes.is_empty(),"overlapping_volumes":overlapping_volumes,"native_index":index}));
    }
    let actors = api.try_op("actors_of_class", json!({"world_context":character,"class":"AbioticLevelStreamingVolume"})).map_err(|e| e.to_string())?;
    if !actors.ok { return Err(format!("world volumes: {:?}", actors.error)); }
    for actor in actors.result["actors"].as_array().ok_or("world volume actors")? {
        let name = actor["name"].as_str().ok_or("volume actor name")?;
        if volume_observations.iter().any(|v| v["name"] == name) { continue; }
        let volume = u64::from_str_radix(actor["addr"].as_str().ok_or("volume actor address")?.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
        let mut buffer = vec![0; size];
        buffer[input_offset..input_offset + 8].copy_from_slice(&character.to_le_bytes());
        let reply = api.try_op("call", json!({"class":"Actor","function":"IsOverlappingActor","instance_selector":format!("addr:0x{volume:X}"),"parms_hex":hex::encode(buffer)})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("unregistered volume overlap: {:?}", reply.error)); }
        let output = hex::decode(reply.result["parms_hex_after"].as_str().ok_or("overlap output")?).map_err(|e| e.to_string())?;
        let overlaps = output.get(output_offset).copied().ok_or("short overlap output")? != 0;
        let offset = field_offset(api, volume, "LevelToLoad")?;
        let level = schema_name(api, u64::from_le_bytes(http_read(api, volume + u64::from(offset) + 16, 8)?.try_into().unwrap()))?;
        let brush = object_field(api, volume, "BrushComponent")?;
        volume_observations.push(json!({"name":name,"level":level,"overlapping":overlaps,"transform":scene_transform(api,brush)?,"registered":false}));
    }
    if http_read(api, component + 0xC0, 56)? != header { return Err("level map changed during capture".into()); }
    sector_client_snapshot(api)?;
    let observed_after = std::fs::read(root.join("sector-client-snapshot.json")).map_err(|e| e.to_string())?;
    if observed_before != observed_after { return Err("client sector changed during capture".into()); }
    let observed: Value = serde_json::from_slice(&observed_after).map_err(|e| e.to_string())?;
    let pose_snapshot = if coherent_pose { refresh_character_pose(api, &mut collision_observations)? } else { Value::Null };
    let result = json!({"world_time":world_time,"levels":levels,"expected_level":observed["level"],"expected_sector":observed["sector"],"demo_mode":observed["demo_mode"],"collision_observations":collision_observations,"volume_observations":volume_observations,"pose_snapshot":pose_snapshot});
    let file = if coherent_pose { "sector-pose-snapshot.json" } else { "sector-level-selection.json" };
    std::fs::write(root.join(file), serde_json::to_vec_pretty(&result).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("captured {} level instances in native order; selected {}", result["levels"].as_array().ok_or("levels")?.len(), observed["level"]);
    Ok(())
}

pub fn movement_rpc_schema(api: &Api<Value>) -> Result<(), String> {
    let pointer = |selector: &str, offset: u64| -> Result<u64, String> {
        let reply = api.try_op("read_bytes", json!({"instance_selector":selector,"offset":offset,"length":8})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("{:?}", reply.error)); }
        let data = hex::decode(reply.result["bytes_hex"].as_str().ok_or("pointer bytes")?).map_err(|e| e.to_string())?;
        Ok(u64::from_le_bytes(data.try_into().map_err(|_| "pointer size")?))
    };
    let class = pointer("singleton:Abiotic_PlayerCharacter_C", 16)?;
    let index = u32::from_le_bytes(http_read(api, class + 12, 4)?.try_into().unwrap());
    let manager = pointer("first_class:NetDriverEOS", 0x1a0)?;
    if manager == 0 { return Err("live driver has no class cache".into()); }
    let map = http_read(api, manager + 8, 16)?;
    let data = u64::from_le_bytes(map[..8].try_into().unwrap());
    let count = u32::from_le_bytes(map[8..12].try_into().unwrap());
    if count > 10000 { return Err("oversized class cache".into()); }
    let rows = http_read(api, data, count as usize * 24)?;
    let row = rows.chunks_exact(24).find(|r| u32::from_le_bytes(r[..4].try_into().unwrap()) == index).ok_or("pawn class cache absent")?;
    let mut cache = u64::from_le_bytes(row[8..16].try_into().unwrap());
    let mut seen = std::collections::BTreeSet::new();
    while cache != 0 && seen.insert(cache) && seen.len() < 32 {
        let header = http_read(api, cache, 48)?;
        let fields = u64::from_le_bytes(header[32..40].try_into().unwrap());
        let count = u32::from_le_bytes(header[40..44].try_into().unwrap());
        if count > 1000 { return Err("oversized field cache".into()); }
        if count == 0 { cache = u64::from_le_bytes(header[8..16].try_into().unwrap()); continue; }
        for field in http_read(api, fields, count as usize * 24)?.chunks_exact(24) {
            let variant = u64::from_le_bytes(field[..8].try_into().unwrap());
            if variant & 1 == 0 || variant == 1 { continue; }
            let object = variant & !1;
            let name = schema_name(api, u64::from_le_bytes(http_read(api, object + 24, 8)?.try_into().unwrap()))?;
            if name.contains("Move") || name.contains("Adjust") || name.contains("Respawn") {
                println!("RPC {}: {name}", u32::from_le_bytes(field[8..12].try_into().unwrap()));
            }
        }
        cache = u64::from_le_bytes(header[8..16].try_into().unwrap());
    }
    for name in ["ServerMoveOld", "ServerMoveNoBase", "ServerMovePacked", "Request_RespawnPlayerCharacter"] {
        let class = if name.contains("Respawn") { "Abiotic_PlayerCharacter_C" } else { "Character" };
        let reply = api.try_op("function_parameters", json!({"class":class,"function":name})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("{:?}", reply.error)); }
        println!("{name}: {}", reply.result);
    }
    Ok(())
}

pub fn readiness(api: &Api<Value>, process: HANDLE, object: u64) -> Result<(), String> {
    let pawn = std::env::var_os("ABIOTIC_TRACE_PAWN").is_some();
    let object = if pawn { u64::from_le_bytes(http_read(api, object + 728, 8)?.try_into().unwrap()) } else { object };
    let mut object = object;
    if let Ok(path) = std::env::var("ABIOTIC_TRACE_OBJECT_FIELD") {
        for field in path.split('.') {
            object = if field == "outer" { u64::from_le_bytes(http_read(api, object + 32, 8)?.try_into().unwrap()) } else { object_field(api, object, field)? };
            if object == 0 { return Err(format!("null object at {field}")); }
        }
    }
    let research_class = std::env::var("ABIOTIC_TRACE_CLASS").ok();
    if object == 0 && research_class.is_none() { return Err("missing possessed pawn".into()); }
    if std::env::var("ABIOTIC_TRACE_OBJECT_FIELD").as_deref() == Ok("PlayerState") {
        let offset = field_offset(api, object, "PlayerSaveID")?;
        let value = http_read(api, object + u64::from(offset), 16)?;
        let data = u64::from_le_bytes(value[..8].try_into().unwrap());
        let count = u32::from_le_bytes(value[8..12].try_into().unwrap());
        let is_zero = count == 2 && http_read(api, data, 4)? == [b'0', 0, 0, 0];
        println!("readiness save ID: empty={}, numeric_zero={is_zero}", count == 0);
    }
    let graph = if pawn { "ExecuteUbergraph_Abiotic_PlayerCharacter" } else { "ExecuteUbergraph_Abiotic_PlayerController" };
    let mut class = if let Some(name) = research_class {
        let reply = api.try_op("read_bytes", json!({"instance_selector":format!("singleton:{name}"),"offset":16,"length":8})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("class lookup failed: {:?}", reply.error)); }
        let bytes = hex::decode(reply.result["bytes_hex"].as_str().ok_or("class pointer bytes")?).map_err(|e| e.to_string())?;
        u64::from_le_bytes(bytes.try_into().map_err(|_| "class pointer length")?)
    } else { u64::from_le_bytes(http_read(api, object + 16, 8)?.try_into().unwrap()) };
    let mut seen = std::collections::BTreeSet::new();
    let mut scripts = std::collections::BTreeMap::new();
    let requested = std::env::var("ABIOTIC_TRACE_FUNCTION").ok();
    let mut classes = std::collections::BTreeSet::new();
    while class != 0 && classes.insert(class) && classes.len() <= 32 {
        println!("readiness class {}", schema_name(api, u64::from_le_bytes(http_read(api, class + 24, 8)?.try_into().unwrap()))?);
        let mut function = u64::from_le_bytes(http_read(api, class + 72, 8)?.try_into().unwrap());
        while function != 0 && seen.insert(function) && seen.len() < 1000 {
            let header = http_read(api, function, 112)?;
            let name = u64::from_le_bytes(header[24..32].try_into().unwrap());
            let reply = api.try_op("fname_to_string", json!({"fname":name})).map_err(|e| e.to_string())?;
            let name = reply.result["string"].as_str().ok_or("function name")?.to_owned();
            if !scripts.contains_key(&name) && (requested.as_deref() == Some(name.as_str()) || name.starts_with("ExecuteUbergraph_") || name.contains("BeginPlay") || name.contains("Setup") || name.contains("Spawn") || name.contains("Load") || name.contains("Volume") || name.contains("Save") || name.contains("Login") || name.contains("Logout") || matches!(name.as_str(), "Local_WaitForLocalPlayerReplication" | "Request_ConfirmCharacterReplication")) {
                let data = u64::from_le_bytes(header[96..104].try_into().unwrap());
                let count = u32::from_le_bytes(header[104..108].try_into().unwrap()) as usize;
                if count > 1_000_000 { return Err("oversized script".into()); }
                let code = if count == 0 { Vec::new() } else { http_read(api, data, count)? };
                println!("readiness function {name}: {count} bytes");
                if !name.starts_with("ExecuteUbergraph_") && code.len() < 200 { println!("readiness wrapper {name}: {}", hex::encode(&code)); }
                scripts.insert(name, code);
            }
            function = u64::from_le_bytes(header[40..48].try_into().unwrap());
        }
        if requested.as_ref().is_none_or(|name| scripts.contains_key(name)) { break; }
        class = u64::from_le_bytes(http_read(api, class + 64, 8)?.try_into().unwrap());
    }
    let selected = std::env::var("ABIOTIC_TRACE_FUNCTION").unwrap_or_else(|_| scripts.keys().find(|name| name.starts_with("ExecuteUbergraph_")).cloned().unwrap_or_else(|| graph.into()));
    let artifact = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join(format!("../target/abioticfactor-client/{selected}-scripts.json"));
    std::fs::write(artifact, serde_json::to_vec(&scripts).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    let code = scripts.get(&selected).ok_or("missing script")?;
    if code.is_empty() { return Err(format!("{selected} has no Blueprint script; inspect its native implementation")); }
    let ranges = std::env::var("ABIOTIC_TRACE_RANGES").unwrap_or_else(|_| format!("0:{}", code.len()));
    for range in ranges.split(',') {
        let (start, end) = range.split_once(':').ok_or("expected start:end")?;
        let start = start.parse::<usize>().map_err(|e| e.to_string())?;
        let end = end.parse::<usize>().map_err(|e| e.to_string())?;
        if start >= end || end > code.len() { return Err("range outside script".into()); }
        let mut parser = Parser { api, process, code, position: start, object, locals: 0, names: Default::default() };
        while parser.position < end { parser.expression(0)?; }
        if parser.position != end { return Err("range ends inside an expression".into()); }
    }
    Ok(())
}

fn object_field(api: &Api<Value>, object: u64, wanted: &str) -> Result<u64, String> {
    let offset = field_offset(api, object, wanted)?;
    Ok(u64::from_le_bytes(http_read(api, object + u64::from(offset), 8)?.try_into().unwrap()))
}

fn field_offset(api: &Api<Value>, object: u64, wanted: &str) -> Result<u32, String> {
    let class = u64::from_le_bytes(http_read(api, object + 16, 8)?.try_into().unwrap());
    class_field(api, class, wanted).map(|(_, offset)| offset)
}

fn class_field(api: &Api<Value>, mut class: u64, wanted: &str) -> Result<(u64, u32), String> {
    for _ in 0..32 {
        if class == 0 { break; }
        let mut field = u64::from_le_bytes(http_read(api, class + 80, 8)?.try_into().unwrap());
        let mut seen = std::collections::BTreeSet::new();
        while field != 0 && seen.insert(field) && seen.len() < 10000 {
            let data = http_read(api, field, 72)?;
            let name = u64::from_le_bytes(data[32..40].try_into().unwrap());
            let reply = api.try_op("fname_to_string", json!({"fname":name})).map_err(|e| e.to_string())?;
            if reply.result["string"] == wanted {
                let offset = u32::from_le_bytes(data[68..72].try_into().unwrap());
                if offset > 1_000_000 { return Err("invalid object field offset".into()); }
                return Ok((field, offset));
            }
            field = u64::from_le_bytes(data[24..32].try_into().unwrap());
        }
        class = u64::from_le_bytes(http_read(api, class + 64, 8)?.try_into().unwrap());
    }
    Err(format!("object field {wanted} not found"))
}

pub fn streaming_properties(api: &Api<Value>) -> Result<(), String> {
    let pdb = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    let layout = ueforge::symbols::layout(pdb, "FProperty").map_err(|e| e.to_string())?;
    let flags = layout.fields.iter().find(|field| field.name == "PropertyFlags").ok_or("PropertyFlags layout")?.offset;
    let property_flags = ueforge::symbols::enumeration(pdb, "EPropertyFlags").map_err(|e| e.to_string())?;
    let net = property_flags.iter().find(|(name, _)| name == "CPF_Net").ok_or("CPF_Net enum")?.1 as u64;
    for (class, fields) in [
        ("Abiotic_Character_ParentBP_C", &["OverlappingLevelVolumes"][..]),
        ("AbioticLevelStreamingVolume", &["LevelToLoad", "RequiredParentLevel", "RequiredEntitlement", "RequiredWorldFlag"][..]),
    ] {
        let reply = api.try_op("read_bytes", json!({"instance_selector":format!("singleton:{class}"),"offset":16,"length":8})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("class lookup: {:?}", reply.error)); }
        let bytes = hex::decode(reply.result["bytes_hex"].as_str().ok_or("class bytes")?).map_err(|e| e.to_string())?;
        let pointer = u64::from_le_bytes(bytes.try_into().map_err(|_| "class pointer size")?);
        for name in fields {
            let (property, offset) = class_field(api, pointer, name)?;
            let value = u64::from_le_bytes(http_read(api, property + flags, 8)?.try_into().unwrap());
            println!("streaming property {class}.{name}: offset={offset}, flags=0x{value:X}, replicated={}", value & net != 0);
        }
    }
    Ok(())
}

pub fn streaming_world_snapshot(api: &Api<Value>) -> Result<(), String> {
    let player = api.try_op("resolve_selector", json!({"selector":"first_class:Abiotic_PlayerCharacter_C"})).map_err(|e| e.to_string())?;
    if !player.ok { return Err(format!("player lookup: {:?}", player.error)); }
    let address = player.result["addr"].as_str().ok_or("player address")?;
    let address = u64::from_str_radix(address.trim_start_matches("0x"), 16).map_err(|e| e.to_string())?;
    let offset = field_offset(api, address, "OverlappingLevelVolumes")?;
    let array = http_read(api, address + u64::from(offset), 16)?;
    let count = u32::from_le_bytes(array[8..12].try_into().unwrap());
    let capacity = u32::from_le_bytes(array[12..16].try_into().unwrap());
    if count > capacity || capacity > 10000 { return Err("invalid overlap array".into()); }
    let volumes = api.try_op("actors_of_class", json!({"world_context":address,"class":"AbioticLevelStreamingVolume"})).map_err(|e| e.to_string())?;
    if !volumes.ok { return Err(format!("world volume enumeration: {:?}", volumes.error)); }
    let artifact = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/live-streaming-volumes.json");
    std::fs::write(artifact, serde_json::to_vec_pretty(&json!({"player_overlap_count":count,"world_volumes":volumes.result})).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    println!("live player overlapping volumes: {count}; world volume count: {}", volumes.result["count"]);
    Ok(())
}

pub fn map_property_schema(api: &Api<Value>) -> Result<(), String> {
    let mut classes = std::collections::BTreeMap::new();
    let mut pending = Vec::new();
    for target in ["AbioticLevelStreamingVolume", "BrushComponent", "BodySetup", "Model", "World", "LevelStreamingDynamic", "RecastNavMesh", "NavMeshBoundsVolume"] {
        let reply = api.try_op("read_bytes", json!({"instance_selector":format!("singleton:{target}"),"offset":16,"length":8})).map_err(|e| e.to_string())?;
        if !reply.ok { return Err(format!("schema class {target}: {:?}", reply.error)); }
        let bytes = hex::decode(reply.result["bytes_hex"].as_str().ok_or("class bytes")?).map_err(|e| e.to_string())?;
        pending.push(u64::from_le_bytes(bytes.try_into().map_err(|_| "class pointer length")?));
    }
    while let Some(mut class) = pending.pop() {
        if classes.len() > 1000 { return Err("schema type limit".into()); }
        for _ in 0..64 {
            if class == 0 { break; }
            let header = http_read(api, class, 88)?;
            let name = schema_name(api, u64::from_le_bytes(header[24..32].try_into().unwrap()))?;
            if classes.contains_key(&name) { break; }
            let parent = u64::from_le_bytes(header[64..72].try_into().unwrap());
            let super_name = if parent == 0 { None } else { Some(schema_name(api, u64::from_le_bytes(http_read(api, parent + 24, 8)?.try_into().unwrap()))?) };
            let mut field = u64::from_le_bytes(header[80..88].try_into().unwrap());
            let mut seen = std::collections::BTreeSet::new();
            let mut properties = Vec::new();
            while field != 0 {
                if !seen.insert(field) || seen.len() > 10000 { return Err("property chain cycle/limit".into()); }
                let bytes = http_read(api, field, 72)?;
                let kind = u64::from_le_bytes(bytes[8..16].try_into().unwrap());
                let kind = schema_name(api, u64::from_le_bytes(http_read(api, kind, 8)?.try_into().unwrap()))?;
                let field_name = schema_name(api, u64::from_le_bytes(bytes[32..40].try_into().unwrap()))?;
                let inner = schema_type(api, field, &kind, &mut pending, 0)?;
                properties.push(json!({"name":field_name,"kind":kind,"inner":inner,"array_dim":u32::from_le_bytes(bytes[48..52].try_into().unwrap()),"flags":u64::from_le_bytes(bytes[56..64].try_into().unwrap())}));
                field = u64::from_le_bytes(bytes[24..32].try_into().unwrap());
            }
            println!("map schema {name}: {} declared properties", properties.len());
            classes.insert(name, json!({"super":super_name,"properties":properties}));
            class = parent;
        }
    }
    let artifact = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/map-property-schema.json");
    std::fs::write(artifact, serde_json::to_vec_pretty(&classes).map_err(|e| e.to_string())?).map_err(|e| e.to_string())?;
    Ok(())
}

fn schema_type(api: &Api<Value>, field: u64, kind: &str, pending: &mut Vec<u64>, depth: usize) -> Result<Value, String> {
    if depth > 32 { return Err("property type recursion limit".into()); }
    let member = |offset| -> Result<u64, String> { Ok(u64::from_le_bytes(http_read(api, field + offset, 8)?.try_into().unwrap())) };
    let nested = |pointer, pending: &mut Vec<u64>| -> Result<Value, String> {
        let class = u64::from_le_bytes(http_read(api, pointer + 8, 8)?.try_into().unwrap());
        let kind = schema_name(api, u64::from_le_bytes(http_read(api, class, 8)?.try_into().unwrap()))?;
        schema_type(api, pointer, &kind, pending, depth + 1)
    };
    // Member offsets below are from this build's FStruct/FArray/FMap/FSet/FEnumProperty PDB layouts.
    Ok(match kind {
        "StructProperty" => {
            let pointer = member(0x70)?;
            pending.push(pointer);
            let name = schema_name(api, u64::from_le_bytes(http_read(api, pointer + 24, 8)?.try_into().unwrap()))?;
            json!({"Struct":{"name":name}})
        }
        "ArrayProperty" => json!({"Array":{"inner":nested(member(0x78)?, pending)?}}),
        "MapProperty" => json!({"Map":{"key":nested(member(0x70)?, pending)?,"value":nested(member(0x78)?, pending)?}}),
        "SetProperty" => json!({"Set":{"key":nested(member(0x70)?, pending)?}}),
        "EnumProperty" => {
            let enumeration = member(0x78)?;
            let name = schema_name(api, u64::from_le_bytes(http_read(api, enumeration + 24, 8)?.try_into().unwrap()))?;
            json!({"Enum":{"inner":nested(member(0x70)?, pending)?,"name":name}})
        }
        "ClassProperty" => json!("Object"),
        "SoftClassProperty" => json!("SoftObject"),
        "MulticastInlineDelegateProperty" | "MulticastSparseDelegateProperty" => json!("MulticastDelegate"),
        other => json!(other.strip_suffix("Property").ok_or("unknown field class")?),
    })
}

fn schema_name(api: &Api<Value>, name: u64) -> Result<String, String> {
    let reply = api.try_op("fname_to_string", json!({"fname":name})).map_err(|e| e.to_string())?;
    if !reply.ok { return Err(format!("schema name: {:?}", reply.error)); }
    reply.result["string"].as_str().map(str::to_owned).ok_or("schema name missing".into())
}

pub fn read(process: HANDLE, address: u64, length: usize) -> Result<Vec<u8>, String> {
    let mut bytes = vec![0; length];
    let mut count = 0;
    if unsafe { ReadProcessMemory(process, address as *const _, bytes.as_mut_ptr().cast(), length, &mut count) } == 0 || count != length {
        return Err(format!("read at {address:#x}: {}", std::io::Error::last_os_error()));
    }
    Ok(bytes)
}

pub fn trace(api: &Api<Value>, process: HANDLE, function: u64, object: u64, locals: u64) -> Result<(), String> {
    let header = read(process, function + 96, 12)?;
    let data = u64::from_le_bytes(header[..8].try_into().unwrap());
    let count = u32::from_le_bytes(header[8..12].try_into().unwrap()) as usize;
    if count > 1_000_000 || count < 6334 { return Err("unexpected spawn script size".into()); }
    let script = read(process, data, count)?;
    let mut parser = Parser { api, process, code: &script, position: 4889, object, locals, names: Default::default() };
    while parser.position < 5438 { parser.expression(0)?; }
    parser.position = 8646;
    for _ in 0..8 { parser.expression(0)?; }
    Ok(())
}

struct Parser<'a> { api: &'a Api<Value>, process: HANDLE, code: &'a [u8], position: usize, object: u64, locals: u64, names: std::cell::RefCell<std::collections::BTreeMap<u64, String>> }
impl Parser<'_> {
    fn number(&mut self, size: usize) -> Result<u64, String> {
        let bytes = self.code.get(self.position..self.position + size).ok_or("truncated expression")?;
        self.position += size;
        Ok(bytes.iter().enumerate().fold(0, |v, (i, byte)| v | (u64::from(*byte) << (i * 8))))
    }
    fn name(&self, value: u64) -> Result<String, String> {
        let reply = self.api.try_op("fname_to_string", json!({"fname":value})).map_err(|e| e.to_string())?;
        reply.result["string"].as_str().map(str::to_owned).ok_or("name lookup failed".into())
    }
    fn pointer_name(&self, pointer: u64, offset: u64) -> Result<String, String> {
        if let Some(name) = self.names.borrow().get(&(pointer + offset)) { return Ok(name.clone()); }
        let name = self.name(u64::from_le_bytes(http_read(self.api, pointer + offset, 8)?.try_into().unwrap()))?;
        self.names.borrow_mut().insert(pointer + offset, name.clone());
        Ok(name)
    }
    fn expression(&mut self, depth: usize) -> Result<(), String> {
        if depth > 40 { return Err("expression depth".into()); }
        let at = self.position;
        let token = self.number(1)?;
        if depth == 0 { println!("spawn {at} statement {token:#x}"); }
        match token {
            0x00..=0x02 | 0x48 | 0x64 => {
                let pointer = self.number(8)?;
                let name = self.pointer_name(pointer, 32)?;
                println!("spawn {at} field {name}");
                if self.locals != 0 && matches!(name.as_str(), "PlayerCharacter" | "PlayerSpawnAttempts" | "CallFunc_TeleportPlayer_ReturnValue" | "CallFunc_GetAllActorsOfClass_OutActors_1") {
                    // This cooked build has the 48-byte FField header. Validate
                    // against the previously resolved controller property layout.
                    let offset = u32::from_le_bytes(read(self.process, pointer + 68, 4)?.try_into().unwrap());
                    if name == "PlayerSpawnAttempts" && offset != 4544 { return Err(format!("property layout mismatch: {offset}")); }
                    let base = if token == 1 { self.object } else { self.locals };
                    let size = match name.as_str() { "PlayerCharacter" => 8, "PlayerSpawnAttempts" => 4, "CallFunc_GetAllActorsOfClass_OutActors_1" => 16, _ => 1 };
                    if offset < 1_000_000 {
                        let value = read(self.process, base + u64::from(offset), size)?;
                        println!("spawn value {name} token {token:#x} offset {offset} bytes {value:?}");
                    }
                }
                if token == 0x64 { self.expression(depth + 1)?; }
            }
            0x0f => { self.number(8)?; self.expression(depth + 1)?; self.expression(depth + 1)?; }
            0x14 | 0x5c | 0x5f | 0x60 | 0x62 => { self.expression(depth + 1)?; self.expression(depth + 1)?; }
            0x5d | 0x51 => { self.expression(depth + 1)?; }
            0x63 => { self.number(8)?; self.expression(depth + 1)?; while self.code.get(self.position) != Some(&0x16) { self.expression(depth + 1)?; } self.position += 1; }
            0x69 => { let cases = self.number(2)?; self.number(4)?; self.expression(depth + 1)?; for _ in 0..cases { self.expression(depth + 1)?; self.number(4)?; self.expression(depth + 1)?; } self.expression(depth + 1)?; }
            0x29 => { match self.number(1)? { 0 => {}, 1 => { for _ in 0..3 { self.expression(depth + 1)?; } }, 2 | 3 => self.expression(depth + 1)?, 4 => { self.number(8)?; self.expression(depth + 1)?; self.expression(depth + 1)?; }, other => return Err(format!("unknown text literal {other}")) } }
            0x65 => { self.number(8)?; self.number(4)?; while self.code.get(self.position) != Some(&0x66) { self.expression(depth + 1)?; } self.position += 1; }
            0x67 => { self.expression(depth + 1)?; }
            0x6b => { self.expression(depth + 1)?; self.expression(depth + 1)?; }
            0x61 => { let index = self.number(4)?; self.number(4)?; let number = self.number(4)?; println!("spawn {at} bind {}", self.name(index | number << 32)?); self.expression(depth + 1)?; self.expression(depth + 1)?; }
            0x12 | 0x19 | 0x1a => { self.expression(depth + 1)?; self.number(4)?; self.number(8)?; self.expression(depth + 1)?; }
            0x1b | 0x45 | 0x1c | 0x46 | 0x68 => {
                let name = if token == 0x1b || token == 0x45 {
                    let index = self.number(4)?; self.number(4)?; let number = self.number(4)?;
                    self.name(index | number << 32)?
                } else { let pointer = self.number(8)?; let name = self.pointer_name(pointer, 24)?;
                    if matches!(name.as_str(), "GetPlayerSaveID" | "IsLevelLoaded" | "Client_DoTraitSelectionSequence") {
                        let owner = u64::from_le_bytes(http_read(self.api, pointer + 32, 8)?.try_into().unwrap());
                        println!("readiness native owner {} function {name}", self.pointer_name(owner, 24)?);
                    }
                    name };
                println!("spawn {at} call {name}");
                while self.code.get(self.position) != Some(&0x16) { self.expression(depth + 1)?; }
                self.position += 1;
            }
            0x13 | 0x2e | 0x52 | 0x54 | 0x55 => { self.number(8)?; self.expression(depth + 1)?; }
            0x42 => { let field = self.number(8)?; println!("spawn {at} member {}", self.pointer_name(field, 32)?); self.expression(depth + 1)?; }
            0x2f => { self.number(8)?; self.number(4)?; while self.code.get(self.position) != Some(&0x30) { self.expression(depth + 1)?; } self.position += 1; }
            0x31 => { self.expression(depth + 1)?; while self.code.get(self.position) != Some(&0x32) { self.expression(depth + 1)?; } self.position += 1; }
            0x06 | 0x07 | 0x4c => { let target = self.number(4)?; println!("spawn {at} jump {target} token {token:#x}"); if token == 0x07 { self.expression(depth + 1)?; } }
            0x04 | 0x4e | 0x4f => { self.expression(depth + 1)?; }
            0x38 => { self.number(1)?; self.expression(depth + 1)?; }
            0x1d | 0x1e | 0x5b => { let value = self.number(4)?; println!("spawn {at} constant {value}"); }
            0x20 => { let pointer = self.number(8)?; if pointer != 0 { println!("spawn {at} object {}", self.pointer_name(pointer, 24)?); } }
            0x21 => { let index = self.number(4)?; self.number(4)?; let n = self.number(4)?; println!("spawn {at} name {}", self.name(index | n << 32)?); }
            0x22 | 0x23 => { self.number(8)?; self.number(8)?; self.number(8)?; }
            0x35..=0x37 => { self.number(8)?; }
            0x24 | 0x2c => { self.number(1)?; }
            0x1f | 0x34 => { let size = if token == 0x34 { 2 } else { 1 }; let mut value = Vec::new(); loop { let c = self.number(size)?; if c == 0 { break; } value.push(c as u16); } println!("spawn {at} string {:?}", String::from_utf16_lossy(&value)); }
            0x27 | 0x28 => { println!("spawn {at} bool {}", token == 0x27); }
            0x0b | 0x17 | 0x25 | 0x26 | 0x2a | 0x4d | 0x53 => {}
            _ => return Err(format!("unsupported expression {token:#x} at {at}")),
        }
        Ok(())
    }
}

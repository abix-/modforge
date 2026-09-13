//! UE unversioned fragments and schema-driven values for map research.
//! Fragment encoding follows unreal_asset/unversioned/header.rs (MIT).
use anyhow::{Context, Result, bail, ensure};
use byteorder::{LittleEndian as LE, ReadBytesExt};
use retoc::{legacy_asset::{FLegacyPackageHeader, FMinimalName}, ser::Readable};
use serde_json::{Value, json};
use std::io::{Cursor, Read};
use usmap::{Property, PropertyInner, Usmap};

pub fn update_schema(mappings: &mut Usmap, current: &Value) -> Result<()> {
    for (name, description) in current.as_object().context("current schema object")? {
        let mut properties = Vec::new();
        let mut index = 0u16;
        for field in description["properties"].as_array().context("schema property list")? {
            let field_name = field["name"].as_str().context("property name")?;
            let inner = serde_json::from_value(field["inner"].clone()).with_context(|| format!("current type {name}.{field_name}"))?;
            let array_dim = u8::try_from(field["array_dim"].as_u64().context("array dimension")?)?;
            properties.push(Property { name:field_name.into(),array_dim,index,inner });
            index = index.checked_add(u16::from(array_dim)).context("schema index overflow")?;
        }
        let schema = usmap::Struct { name:name.clone(), properties, super_struct:description["super"].as_str().map(str::to_owned) };
        if let Some(old) = mappings.structs.iter_mut().find(|s| &s.name == name) { *old = schema; }
        else { mappings.structs.push(schema); }
    }
    Ok(())
}

pub struct Reader<'a> {
    bytes: Cursor<&'a [u8]>,
    package: &'a FLegacyPackageHeader,
    mappings: &'a Usmap,
}

impl<'a> Reader<'a> {
    /// UE5.4 cooked actor prefix and Recast version/size/count, following
    /// CUE4Parse's UObject, AActor and ARecastNavMesh deserializers.
    pub fn navigation_summary(&mut self) -> Result<Value> {
        let start = self.bytes.position();
        let has_guid = self.bytes.read_i32::<LE>()?;
        ensure!((0..=1).contains(&has_guid), "invalid object GUID flag");
        if has_guid == 1 {
            let mut guid = [0; 16];
            self.bytes.read_exact(&mut guid)?;
        }
        let cooked = self.bytes.read_i32::<LE>()?;
        ensure!(cooked == 1, "expected cooked navigation actor");
        let label = String::de(&mut self.bytes)?;
        let version = self.bytes.read_i32::<LE>()?;
        ensure!(version == 26, "unsupported navigation version {version}");
        let size_position = self.bytes.position();
        let size = self.bytes.read_u32::<LE>()?;
        ensure!(size >= 4 && size_position + u64::from(size) == self.bytes.get_ref().len() as u64,
            "navigation payload size disagrees with export boundary");
        let tile_count = if size == 4 { 0 } else { self.bytes.read_i32::<LE>()? };
        ensure!(tile_count >= 0, "negative navigation tile count");
        Ok(json!({"start":start,"label":label,"version":version,"mesh_size":size,"tile_count":tile_count}))
    }

    pub fn new(bytes: &'a [u8], package: &'a FLegacyPackageHeader, mappings: &'a Usmap) -> Self {
        Self { bytes: Cursor::new(bytes), package, mappings }
    }

    fn schema(&self, name: &str, depth: usize) -> Result<Vec<Option<&'a Property>>> {
        ensure!(depth < 64, "schema inheritance cycle");
        let schema = self.mappings.structs.iter().find(|s| s.name == name).with_context(|| format!("missing schema {name}"))?;
        let count = schema.properties.iter().map(|p| usize::from(p.index) + usize::from(p.array_dim)).max().unwrap_or(0);
        let mut fields = vec![None; count];
        for property in &schema.properties {
            for i in 0..usize::from(property.array_dim) { fields[usize::from(property.index) + i] = Some(property); }
        }
        if let Some(parent) = &schema.super_struct { fields.extend(self.schema(parent, depth + 1)?); }
        Ok(fields)
    }

    pub fn properties(&mut self, class: &str, depth: usize) -> Result<Value> {
        ensure!(depth < 64, "property recursion limit");
        let schema = self.schema(class, 0)?;
        let mut fragments = Vec::new();
        let mut zero_count = 0usize;
        loop {
            ensure!(fragments.len() < 10000, "fragment limit");
            let fragment = self.bytes.read_u16::<LE>()?;
            if fragment & 0x80 != 0 { zero_count += usize::from(fragment >> 9); }
            fragments.push(fragment);
            if fragment & 0x100 != 0 { break; }
        }
        let mask_bytes = match zero_count { 0 => 0, 1..=8 => 1, 9..=16 => 2, n => n.div_ceil(32) * 4 };
        let mut zeros = vec![0u8; mask_bytes];
        self.bytes.read_exact(&mut zeros)?;
        let mut index = 0usize;
        let mut zero_index = 0usize;
        let mut result = serde_json::Map::new();
        for fragment in fragments {
            index += usize::from(fragment & 0x7f);
            for _ in 0..fragment >> 9 {
                let property = schema.get(index).and_then(|p| *p).with_context(|| format!("{class} property index {index} outside schema"))?;
                let zero = if fragment & 0x80 != 0 {
                    let value = zeros[zero_index / 8] & (1 << (zero_index % 8)) != 0;
                    zero_index += 1;
                    value
                } else { false };
                let value = if zero { json!({"serialized_zero":true}) } else {
                    self.value(&property.inner, depth + 1).with_context(|| format!("{class}.{} at {}", property.name, self.bytes.position()))?
                };
                if property.array_dim > 1 {
                    let array_index = schema[..index].iter().rev()
                        .take_while(|slot| slot.is_some_and(|p| std::ptr::eq(p, property))).count();
                    let values = result.entry(property.name.clone())
                        .or_insert_with(|| Value::Array(vec![Value::Null; usize::from(property.array_dim)]))
                        .as_array_mut().context("static array value")?;
                    values[array_index] = value;
                } else {
                    ensure!(!result.contains_key(&property.name), "duplicate property {}", property.name);
                    result.insert(property.name.clone(), value);
                }
                if depth == 0 && std::env::var_os("ABIOTIC_MAP_TRACE").is_some() {
                    eprintln!("{class} index={index} {} end={} value={}", property.name, self.bytes.position(), result[&property.name]);
                }
                index += 1;
            }
        }
        Ok(Value::Object(result))
    }

    fn name(&mut self) -> Result<String> {
        let name = FMinimalName::de(&mut self.bytes)?;
        Ok(self.package.name_map.get(name)?.into_owned())
    }

    /// World's native tail follows its properties. Layout follows unreal_asset's
    /// world_export.rs and the shipped UWorld::Serialize call sequence.
    pub fn world_references(&mut self) -> Result<Value> {
        let start = self.bytes.position();
        let prefix = self.bytes.read_i32::<LE>()?;
        ensure!(prefix == 0, "unsupported World prefix {prefix}");
        let persistent_level = self.bytes.read_i32::<LE>()?;
        let mut read_array = || -> Result<Vec<i32>> {
            let count = self.bytes.read_i32::<LE>()?;
            ensure!((0..=10000).contains(&count), "invalid World reference array count {count}");
            (0..count).map(|_| Ok(self.bytes.read_i32::<LE>()?)).collect()
        };
        let extra_objects = read_array()?;
        let streaming_levels = read_array()?;
        let end = self.bytes.position();
        let trailing = &self.bytes.get_ref()[end as usize..];
        Ok(json!({"start":start,"end":end,"persistent_level":persistent_level,"extra_objects":extra_objects,"streaming_levels":streaming_levels,"trailing":trailing}))
    }

    fn value(&mut self, kind: &PropertyInner, depth: usize) -> Result<Value> {
        ensure!(depth < 64, "value recursion limit");
        use PropertyInner::*;
        Ok(match kind {
            Bool => json!(self.bytes.read_u8()? != 0),
            Byte => json!(self.bytes.read_u8()?),
            Int8 => json!(self.bytes.read_i8()?),
            Int16 => json!(self.bytes.read_i16::<LE>()?),
            UInt16 => json!(self.bytes.read_u16::<LE>()?),
            Int | Object | WeakObject => json!(self.bytes.read_i32::<LE>()?),
            UInt32 => json!(self.bytes.read_u32::<LE>()?),
            Int64 => json!(self.bytes.read_i64::<LE>()?),
            UInt64 => json!(self.bytes.read_u64::<LE>()?),
            Float => json!(self.bytes.read_f32::<LE>()?),
            Double => json!(self.bytes.read_f64::<LE>()?),
            Name => json!(self.name()?),
            Str => json!(String::de(&mut self.bytes)?),
            Enum { inner, .. } => self.value(inner, depth + 1)?,
            SoftObject => json!({"package":self.name()?,"asset":self.name()?,"subpath":String::de(&mut self.bytes)?}),
            Array { inner } => {
                let count = self.bytes.read_i32::<LE>()?;
                ensure!((0..=100000).contains(&count), "array count {count}");
                let mut values = Vec::with_capacity(count as usize);
                for _ in 0..count { values.push(self.value(inner, depth + 1)?); }
                Value::Array(values)
            }
            Struct { name } => match name.as_str() {
                "SoftClassPath" | "SoftObjectPath" => self.value(&SoftObject, depth + 1)?,
                // FNavAgentSelector::Serialize writes its packed uint32.
                "NavAgentSelector" => json!({"packed_bits":self.bytes.read_u32::<LE>()?}),
                "Color" => json!({"b":self.bytes.read_u8()?,"g":self.bytes.read_u8()?,"r":self.bytes.read_u8()?,"a":self.bytes.read_u8()?}),
                "LinearColor" => json!([self.bytes.read_f32::<LE>()?, self.bytes.read_f32::<LE>()?, self.bytes.read_f32::<LE>()?, self.bytes.read_f32::<LE>()?]),
                "Vector" | "Rotator" => json!([self.bytes.read_f64::<LE>()?, self.bytes.read_f64::<LE>()?, self.bytes.read_f64::<LE>()?]),
                "Quat" => json!([self.bytes.read_f64::<LE>()?, self.bytes.read_f64::<LE>()?, self.bytes.read_f64::<LE>()?, self.bytes.read_f64::<LE>()?]),
                "Guid" => json!([self.bytes.read_u32::<LE>()?, self.bytes.read_u32::<LE>()?, self.bytes.read_u32::<LE>()?, self.bytes.read_u32::<LE>()?]),
                "Box" => {
                    let min = self.value(&Struct { name:"Vector".into() }, depth + 1)?;
                    let max = self.value(&Struct { name:"Vector".into() }, depth + 1)?;
                    json!({"min":min,"max":max,"valid":self.bytes.read_u8()?})
                }
                _ => self.properties(name, depth + 1)?,
            },
            _ => bail!("unsupported map property type {kind:?}"),
        })
    }
}

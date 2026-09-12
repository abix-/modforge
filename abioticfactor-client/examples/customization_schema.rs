//! Offline cooked UFunction field metadata from a UAssetAPI JSON export.
use std::{fs, io};
use serde_json::Value;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args: Vec<_> = std::env::args().collect();
    let asset: Value = serde_json::from_slice(&fs::read(&args[1])?)?;
    let raw = fs::read(&args[2])?;
    let mut cursor = 18;
    let count = number(&raw, &mut cursor, 4)?;
    for _ in 0..count { field(&asset, &raw, &mut cursor)?; }
    Ok(())
}

fn number(raw: &[u8], cursor: &mut usize, size: usize) -> io::Result<u64> {
    let bytes = raw.get(*cursor..*cursor + size).ok_or_else(|| io::Error::other("truncated property"))?;
    *cursor += size;
    Ok(bytes.iter().enumerate().fold(0, |value, (i, byte)| value | (u64::from(*byte) << (i * 8))))
}

fn name<'a>(asset: &'a Value, raw: &[u8], cursor: &mut usize) -> io::Result<&'a str> {
    let index = number(raw, cursor, 4)?;
    number(raw, cursor, 4)?;
    asset["NameMap"][index as usize].as_str().ok_or_else(|| io::Error::other("invalid name"))
}

fn field(asset: &Value, raw: &[u8], cursor: &mut usize) -> io::Result<()> {
    let kind = name(asset, raw, cursor)?;
    let name = name(asset, raw, cursor)?;
    number(raw, cursor, 4)?;
    let array = number(raw, cursor, 4)?;
    let size = number(raw, cursor, 4)?;
    let flags = number(raw, cursor, 8)?;
    number(raw, cursor, 2)?;
    number(raw, cursor, 8)?;
    number(raw, cursor, 1)?;
    println!("{name}: {kind}, size {size}, array {array}, flags {flags:#x}");
    match kind {
        "StructProperty" | "ObjectProperty" | "SoftObjectProperty" | "ByteProperty" => {
            let index = number(raw, cursor, 4)? as u32 as i32;
            if index < 0 { println!("  type {}", asset["Imports"][(-index - 1) as usize]["ObjectName"]); }
        }
        "NameProperty" | "IntProperty" | "FloatProperty" | "DoubleProperty" => {}
        other => return Err(io::Error::other(format!("unsupported {other}"))),
    }
    Ok(())
}

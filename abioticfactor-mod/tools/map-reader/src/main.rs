use anyhow::{Context, Result, ensure};
use retoc::{legacy_asset::FLegacyPackageHeader, version::EngineVersion};
use std::path::PathBuf;
use std::io::Write;
mod properties;

fn main() -> Result<()> {
    let args: Vec<_> = std::env::args_os().skip(1).collect();
    ensure!(args.len() == 3, "usage: abiotic-map-reader <map.umap> <output.json> <current-schema.json>");
    let mut mappings = usmap::Usmap { enums:Vec::new(),structs:Vec::new(),cext:None,ppth:None,eatr:None,envp:None };
    let current: serde_json::Value = serde_json::from_reader(std::fs::File::open(&args[2])?)?;
    properties::update_schema(&mut mappings, &current)?;
    let path = PathBuf::from(&args[0]);
    let header = std::fs::read(&path).context("read converted map header")?;
    let body = std::fs::read(path.with_extension("uexp")).context("read converted map exports")?;
    let package = FLegacyPackageHeader::deserialize(&mut std::io::Cursor::new(&header), Some(EngineVersion::UE5_4.package_file_version()))
        .context("parse converted map header")?;
    let mut exports = Vec::new();
    let mut class_counts = std::collections::BTreeMap::<String, usize>::new();
    for (index, export) in package.exports.iter().enumerate() {
        let name = package.name_map.get(export.object_name)?;
        let class = if export.class_index.is_import() {
            let import = package.imports.get(export.class_index.to_import_index() as usize).context("class import index")?;
            package.name_map.get(import.object_name)?.into_owned()
        } else { String::new() };
        *class_counts.entry(class.clone()).or_default() += 1;
        if matches!(class.as_str(), "AbioticLevelStreamingVolume" | "BrushComponent" | "BodySetup" | "Model" | "World" | "LevelStreamingDynamic" | "RecastNavMesh" | "NavMeshBoundsVolume") {
            let start = usize::try_from(export.serial_offset)?.checked_sub(header.len()).context("export starts before payload")?;
            let end = start.checked_add(usize::try_from(export.serial_size)?).context("export range overflow")?;
            ensure!(end <= body.len(), "export {name} outside payload");
            let mut reader = properties::Reader::new(&body[start..end], &package, &mappings);
            let props = reader.properties(&class, 0).with_context(|| format!("decode {class} {name}"))?;
            let native = if class == "World" { reader.world_references().context("decode World native references")? }
                else if class == "RecastNavMesh" { reader.navigation_summary().with_context(|| format!("navigation header {name}"))? } else { serde_json::Value::Null };
            exports.push(serde_json::json!({"index":index + 1,"name":name,"class":class,"outer":export.outer_index.index,"payload_offset":start,"payload_size":end-start,"properties":props,"native":native}));
        }
    }
    let data = serde_json::json!({"unversioned_properties":package.summary.uses_unversioned_property_serialization(),"total_exports":package.exports.len(),"class_counts":class_counts,"exports":exports});
    let output = std::fs::File::create(&args[1]).context("create parsed map output")?;
    let mut output = std::io::BufWriter::new(output);
    serde_json::to_writer_pretty(&mut output, &data).context("write parsed map")?;
    output.flush().context("flush parsed map")?;
    println!("Parsed {}", path.display());
    Ok(())
}

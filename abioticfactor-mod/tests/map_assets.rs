//! Offline map research using the installed Rust retoc converter.
use std::{path::Path, process::Command};
use serde_json::Value;

/// Compare shipped volume roots with the saved, read-only world observation.
#[test]
#[ignore = "requires parse_facility_map and live_streaming_volumes artifacts"]
fn facility_volumes_match_observation() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let read = |name: &str| -> Value {
        serde_json::from_slice(&std::fs::read(root.join(name)).expect("read research artifact"))
            .expect("decode research artifact")
    };
    let parsed = read("facility-parsed.json");
    let live = read("live-streaming-volumes.json");
    let exports = parsed["exports"].as_array().expect("exports");
    let resolve = |reference: &Value, class: &str| -> &Value {
        let index = reference.as_u64().expect("positive export reference");
        let export = exports.iter().find(|e| e["index"].as_u64() == Some(index))
            .expect("referenced export captured");
        assert_eq!(export["class"], class);
        export
    };
    let volumes: Vec<_> = exports.iter().filter(|e| e["class"] == "AbioticLevelStreamingVolume").collect();
    let actors = live["world_volumes"]["actors"].as_array().expect("observed actors");
    assert_eq!(volumes.len(), 223, "Facility research baseline");
    assert_eq!(actors.len(), volumes.len());
    let mut convex_count = 0;
    let mut max_error = 0.0_f64;
    for volume in volumes {
        let name = volume["name"].as_str().expect("volume name");
        let full_name = format!("AbioticLevelStreamingVolume /Game/Maps/Facility.Facility.PersistentLevel.{name}");
        let matches: Vec<_> = actors.iter().filter(|a| a["full_name"] == full_name).collect();
        assert_eq!(matches.len(), 1, "unique observed volume {name}");
        let brush = resolve(&volume["properties"]["BrushComponent"], "BrushComponent");
        assert_eq!(brush["outer"], volume["index"]);
        assert_eq!(volume["properties"]["RootComponent"], brush["index"]);
        assert!(brush["properties"].get("AttachParent").is_none(), "attached root {name}");
        for axis in 0..3 {
            let stored = brush["properties"]["RelativeLocation"][axis].as_f64().expect("stored location");
            let observed = matches[0]["location"][axis].as_f64().expect("observed location");
            let error = (stored - observed).abs();
            assert!(error.is_finite() && error < 0.001, "location mismatch {name}, axis {axis}: {error}");
            max_error = max_error.max(error);
        }
        let level = volume["properties"]["LevelToLoad"]["package"].as_str().expect("level package");
        assert!(level.starts_with("/Game/Maps/"), "unexpected level {level}");
        let body = resolve(&brush["properties"]["BrushBodySetup"], "BodySetup");
        let convexes = body["properties"]["AggGeom"]["ConvexElems"].as_array().expect("convex collision");
        assert!(!convexes.is_empty(), "missing collision {name}");
        for convex in convexes {
            let vertices = convex["VertexData"].as_array().expect("convex vertices");
            assert!(vertices.len() >= 4);
            for vertex in vertices {
                let coordinates = vertex.as_array().expect("vertex coordinates");
                assert_eq!(coordinates.len(), 3);
                assert!(coordinates.iter().all(|v| v.as_f64().is_some_and(f64::is_finite)));
            }
            let indices = convex["IndexData"].as_array().expect("convex triangle indices");
            assert!(!indices.is_empty() && indices.len() % 3 == 0);
            assert!(indices.iter().all(|i| i.as_u64().is_some_and(|i| i < vertices.len() as u64)));
            convex_count += 1;
        }
    }
    println!("Matched 223 volume locations; max error {max_error}; validated {convex_count} convex meshes");
}

#[test]
#[ignore = "requires the Facility map produced by extract_facility_map"]
fn parse_facility_map() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let path = root.join("map-assets/AbioticFactor/Content/Maps/Facility.umap");
    let reader = root.join("map-reader/x86_64-pc-windows-msvc/debug/abiotic-map-reader.exe");
    let result = Command::new(reader).arg(&path).arg(root.join("facility-parsed.json")).arg(root.join("map-property-schema.json")).output().expect("run built Rust map reader");
    assert!(result.status.success(), "map reader: {}", String::from_utf8_lossy(&result.stderr));
    println!("{}", String::from_utf8_lossy(&result.stdout));
    let parsed: Value = serde_json::from_slice(&std::fs::read(root.join("facility-parsed.json")).expect("parsed Facility")).expect("Facility JSON");
    let meshes: Vec<_> = parsed["exports"].as_array().expect("exports").iter()
        .filter(|e| e["class"] == "RecastNavMesh").collect();
    assert_eq!(meshes.len(), 62, "current Facility navigation baseline");
    for mesh in meshes {
        assert_eq!(mesh["native"]["version"], 26);
        assert_eq!(mesh["native"]["tile_count"], 0, "saved tiles changed: {}", mesh["name"]);
    }
}

#[test]
#[ignore = "requires installed Abiotic Factor content and retoc"]
fn extract_office1_navigation() {
    let input = Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Content/Paks");
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let output = root.join("map-assets");
    let result = Command::new("retoc").arg("to-legacy").arg(input).arg(&output)
        .args(["--filter", "/Maps/Facility_Office1.umap", "--no-shaders", "--version", "UE5_4"])
        .output().expect("convert Office1 package");
    assert!(result.status.success(), "retoc: {}", String::from_utf8_lossy(&result.stderr));
    let reader = root.join("map-reader/x86_64-pc-windows-msvc/debug/abiotic-map-reader.exe");
    let result = Command::new(reader).arg(output.join("AbioticFactor/Content/Maps/Facility_Office1.umap"))
        .arg(root.join("office1-parsed.json")).arg(root.join("map-property-schema.json"))
        .output().expect("parse Office1 package");
    assert!(result.status.success(), "map reader: {}", String::from_utf8_lossy(&result.stderr));
    println!("{}", String::from_utf8_lossy(&result.stdout));
    let parsed: Value = serde_json::from_slice(&std::fs::read(root.join("office1-parsed.json")).expect("parsed Office1")).expect("Office1 JSON");
    let counts = parsed["class_counts"].as_object().expect("class counts");
    assert!(!counts.contains_key("RecastNavMesh"));
    assert!(!counts.contains_key("RecastNavMeshDataChunk"));
}

#[test]
#[ignore = "requires installed Abiotic Factor content and retoc"]
fn extract_facility_map() {
    let input = Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Content/Paks");
    let output = Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/map-assets");
    let result = Command::new("retoc").arg("to-legacy").arg(input).arg(&output)
        .args(["--filter", "/Maps/Facility.umap", "--no-shaders", "--version", "UE5_4"])
        .output().expect("run retoc map conversion");
    assert!(result.status.success(), "retoc: {}", String::from_utf8_lossy(&result.stderr));
    let map = output.join("AbioticFactor/Content/Maps/Facility.umap");
    assert!(map.is_file(), "missing converted Facility map: {}", String::from_utf8_lossy(&result.stdout));
    println!("Facility map converted to {}", map.display());
}

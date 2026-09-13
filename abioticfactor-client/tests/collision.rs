use abioticfactor_client::collision::{CharacterShape, FacilityCollision, Transform};
use parry3d_f64::math::Rot3;
use serde_json::Value;
use std::collections::{BTreeMap, BTreeSet};

#[test]
#[ignore = "requires current Facility map and sector_level_selection_research exports"]
fn facility_registration_matches_real_client() {
    let root =
        std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let bytes = std::fs::read(root.join("facility-parsed.json")).expect("map export");
    let observed: Value = serde_json::from_slice(
        &std::fs::read(root.join("sector-level-selection.json")).expect("client capture"),
    )
    .expect("client observation");
    let levels = abioticfactor_client::levels::register_facility_levels(
        &bytes,
        observed["demo_mode"].as_bool().expect("demo mode"),
    )
    .expect("registration");
    let names: Vec<_> = levels.iter().map(|l| l.level.as_str()).collect();
    let expected: Vec<_> = observed["levels"]
        .as_array()
        .expect("levels")
        .iter()
        .map(|l| l["level"].as_str().expect("level name"))
        .collect();
    assert_eq!(names, expected, "all level names in native order");
    let registered: BTreeSet<_> = levels.iter().flat_map(|l| l.volumes.iter()).collect();
    let volumes = observed["volume_observations"].as_array().expect("volumes");
    for volume in volumes {
        let name = volume["name"].as_str().expect("volume name");
        assert_eq!(
            registered.iter().any(|v| v.as_str() == name),
            volume["registered"].as_bool().expect("registration"),
            "{name}"
        );
    }
    let full =
        abioticfactor_client::levels::register_facility_levels(&bytes, false).expect("full game");
    let demo =
        abioticfactor_client::levels::register_facility_levels(&bytes, true).expect("demo game");
    assert_eq!(full.iter().map(|l| l.volumes.len()).sum::<usize>(), 223);
    assert_eq!(demo.iter().map(|l| l.volumes.len()).sum::<usize>(), 222);
    assert!(full.iter().any(|l| {
        l.volumes
            .iter()
            .any(|v| v == "AbioticLevelStreamingVolume_61")
    }));
    assert!(!demo.iter().any(|l| {
        l.volumes
            .iter()
            .any(|v| v == "AbioticLevelStreamingVolume_61")
    }));
    println!(
        "Map matches {} native levels and all {} volume registration decisions",
        levels.len(),
        volumes.len()
    );
}

fn assert_transform_matches(actual: &Transform, expected: &Transform, name: &str) {
    for (a, b) in actual
        .translation
        .iter()
        .zip(&expected.translation)
        .chain(actual.scale.iter().zip(&expected.scale))
    {
        assert!((a - b).abs() < 1.0e-6, "transform {name}: {a} != {b}");
    }
    let a = Rot3::from_array(actual.rotation);
    let b = Rot3::from_array(expected.rotation);
    assert!((a.dot(b).abs() - 1.0).abs() < 1.0e-10, "rotation {name}");
}

fn reconstruct_component(component: &Value) -> Value {
    let mut parent = None;
    let chain = component["attachment_chain"]
        .as_array()
        .expect("attachment chain");
    let transforms = chain
        .iter()
        .rev()
        .map(|entry| &entry["transform"])
        .chain(std::iter::once(&component["world_transform"]));
    for observed in transforms {
        assert_eq!(
            observed["flags"].as_u64().expect("scene flags") & 0x1C,
            0,
            "absolute transform overrides need research"
        );
        assert_eq!(
            observed["socket"], "None",
            "socket attachment needs research"
        );
        let local = Transform::from_relative(
            serde_json::from_value(observed["relative_location"].clone())
                .expect("relative location"),
            serde_json::from_value(observed["relative_rotation"].clone())
                .expect("relative rotation"),
            serde_json::from_value(observed["relative_scale"].clone()).expect("relative scale"),
        )
        .expect("local transform");
        let world = if let Some(parent) = &parent {
            local.attached_to(parent).expect("attachment composition")
        } else {
            local
        };
        let captured = serde_json::from_value(observed.clone()).expect("cached world transform");
        assert_transform_matches(
            &world,
            &captured,
            component["name"].as_str().expect("component name"),
        );
        parent = Some(world);
    }
    let mut result = component.clone();
    result["world_transform"] =
        serde_json::to_value(parent.expect("component transform")).expect("computed transform");
    result
}

#[test]
#[ignore = "requires sector_pose_snapshot_research export from updated mod"]
fn character_attachments_match_same_update_snapshot() {
    let root =
        std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let observed: Value = serde_json::from_slice(
        &std::fs::read(root.join("sector-pose-snapshot.json")).expect("pose snapshot"),
    )
    .expect("pose observation");
    assert_eq!(observed["pose_snapshot"]["game_thread"], true);
    let mut names = BTreeSet::new();
    for observation in observed["collision_observations"]
        .as_array()
        .expect("observations")
    {
        for component in observation["components"].as_array().expect("components") {
            CharacterShape::from_observation(&reconstruct_component(component))
                .expect("same-update shape");
            names.insert(component["name"].as_str().expect("name"));
        }
    }
    assert_eq!(names.len(), 2, "normal capsule and camera sphere");
    println!(
        "Character attachment transforms match in game frame {}",
        observed["pose_snapshot"]["frame"]
    );
}

#[test]
#[ignore = "requires current Facility map and sector_level_selection_research exports"]
fn facility_collision_matches_real_client_overlaps() {
    let root =
        std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let facility = FacilityCollision::from_json(
        &std::fs::read(root.join("facility-parsed.json")).expect("map export"),
    )
    .expect("Facility collision");
    let observed: Value = serde_json::from_slice(
        &std::fs::read(root.join("sector-level-selection.json")).expect("client capture"),
    )
    .expect("client observation");
    let volumes = observed["volume_observations"]
        .as_array()
        .expect("volume transforms and overlap results");
    let mut shapes = BTreeMap::new();
    for observation in observed["collision_observations"]
        .as_array()
        .expect("shape observations")
    {
        for component in observation["components"].as_array().expect("components") {
            shapes
                .entry(component["name"].as_str().expect("component name"))
                .or_insert_with(|| {
                    CharacterShape::from_observation(&reconstruct_component(component))
                        .expect("reconstructed character shape")
                });
        }
    }
    assert_eq!(shapes.len(), 2, "current normal-client shape baseline");
    let shapes: Vec<_> = shapes.into_values().collect();
    let indexed: BTreeMap<_, _> = volumes
        .iter()
        .map(|v| (v["name"].as_str().expect("volume name"), v))
        .collect();
    assert_eq!(indexed.len(), volumes.len(), "unique captured volumes");
    assert_eq!(facility.volumes.len(), 223);
    assert_eq!(indexed.len(), facility.volumes.len());
    let mut actual = BTreeSet::new();
    let mut expected = BTreeSet::new();
    for volume in &facility.volumes {
        let live = indexed.get(volume.name.as_str()).expect("volume captured");
        assert_eq!(live["level"], volume.level);
        let transform: Transform =
            serde_json::from_value(live["transform"].clone()).expect("world transform");
        assert_transform_matches(&volume.transform, &transform, &volume.name);
        if facility.overlaps(volume, &shapes).expect("collision query") {
            actual.insert(volume.name.as_str());
        }
        if live["overlapping"].as_bool().expect("observed overlap") {
            expected.insert(volume.name.as_str());
        }
    }
    assert!(!expected.is_empty(), "capture must exercise actual overlap");
    assert_eq!(
        actual, expected,
        "local convex collision vs actual actor overlap"
    );
    let registration = abioticfactor_client::levels::register_facility_levels(
        &std::fs::read(root.join("facility-parsed.json")).expect("map export"),
        observed["demo_mode"].as_bool().expect("observed demo mode"),
    )
    .expect("map registration");
    let mut levels: Vec<abioticfactor_client::levels::LevelInstance> =
        serde_json::from_value(observed["levels"].clone()).expect("level state");
    assert_eq!(registration.len(), levels.len());
    let registered: BTreeSet<_> = registration
        .iter()
        .flat_map(|level| level.volumes.iter())
        .collect();
    for volume in &facility.volumes {
        assert_eq!(
            registered.contains(&volume.name),
            indexed[volume.name.as_str()]["registered"]
                .as_bool()
                .expect("registration"),
            "registration {}",
            volume.name
        );
    }
    for (level, static_level) in levels.iter_mut().zip(&registration) {
        assert_eq!(
            level.level.as_deref(),
            Some(static_level.level.as_str()),
            "native level order"
        );
        level.overlapping = static_level
            .volumes
            .iter()
            .any(|name| actual.contains(name.as_str()));
    }
    let full = abioticfactor_client::levels::register_facility_levels(
        &std::fs::read(root.join("facility-parsed.json")).expect("map export"),
        false,
    )
    .expect("full registration");
    assert_eq!(full.iter().map(|l| l.volumes.len()).sum::<usize>(), 223);
    assert!(full.iter().any(|l| {
        l.volumes
            .iter()
            .any(|v| v == "AbioticLevelStreamingVolume_61")
    }));
    println!(
        "Map supplies all {} levels in native order and {} registered volumes",
        registration.len(),
        registered.len()
    );
    let selected =
        abioticfactor_client::levels::find_latest_level(observed["world_time"].as_f64(), &levels)
            .expect("selected level");
    assert_eq!(
        selected.level.as_deref(),
        observed["expected_level"].as_str()
    );
    let table = abioticfactor_client::levels::LevelTable::from_json(
        &std::fs::read(root.join("sector-table.json")).expect("level table"),
    )
    .expect("parsed table");
    let sector = &table
        .row_for_level(selected.level.as_deref().expect("selected world asset"))
        .expect("level row")
        .sector;
    assert_eq!(
        sector,
        observed["expected_sector"].as_str().expect("client sector")
    );
    println!(
        "All 223 map transforms and overlap results match; {} shapes overlap {actual:?}",
        shapes.len()
    );
    println!(
        "Computed collision -> {} -> {sector}",
        selected.level.as_deref().expect("selected asset")
    );
}

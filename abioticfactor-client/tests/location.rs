use abioticfactor_client::location::LocationMap;

#[test]
#[ignore = "requires extracted Facility map and sector table"]
fn recorded_sophia_coordinate_resolves_with_standalone_binary() {
    let root =
        std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    let map_bytes = std::fs::read(root.join("facility-parsed.json")).expect("map");
    let table_bytes = std::fs::read(root.join("sector-table.json")).expect("table");
    let map = LocationMap::from_json(&map_bytes, &table_bytes).expect("map data");
    // Recorded from Sophia's ordinary absolute UDP movement correction.
    // This is a historical coordinate, not a fresh live observation.
    let position = [-17111.929358970614, 13396.128366994613, 208.1500003922302];
    let location = map
        .locate("/Game/Maps/Facility", position)
        .expect("location");
    println!("Recorded Sophia position: {location}");
    assert!(
        location
            .containing_regions
            .iter()
            .any(|a| a.level == "Facility_Office1"
                && a.sector.as_deref() == Some("The Office Sector"))
    );
    assert!(map.locate("AnotherWorld", position).is_err());
    assert!(map.locate("Facility", [f64::NAN, 0.0, 0.0]).is_err());
    assert!(
        map.locate("Facility", [1.0e12; 3])
            .unwrap()
            .containing_regions
            .is_empty()
    );

    let profile = root.join("location-test-profile");
    std::fs::create_dir_all(profile.join("map")).unwrap();
    std::fs::write(profile.join("map/facility-parsed.json"), map_bytes).unwrap();
    std::fs::write(profile.join("map/sector-table.json"), table_bytes).unwrap();
    let output = std::process::Command::new(env!("CARGO_BIN_EXE_abioticfactor-client"))
        .env("SOPHIA_HOME", profile)
        .args([
            "locate",
            "Facility",
            &position[0].to_string(),
            &position[1].to_string(),
            &position[2].to_string(),
        ])
        .output()
        .expect("run standalone coordinate lookup");
    assert!(
        output.status.success(),
        "{}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stdout = String::from_utf8(output.stdout).unwrap();
    assert!(
        stdout.contains("The Office Sector (Facility_Office1)"),
        "{stdout}"
    );
    println!("{stdout}");
}

//! Offline comparison against permanent HTTP research observations. Never connects.

use abioticfactor_client::levels::LevelTable;
use serde::Deserialize;

#[derive(Deserialize)]
struct LevelSelectionObservation {
    world_time: f64,
    levels: Vec<abioticfactor_client::levels::LevelInstance>,
    expected_level: String,
    expected_sector: String,
}

#[test]
#[ignore = "requires sector_level_selection_research and sector_table_research exports"]
fn overlap_and_visibility_selection_matches_the_normal_client() {
    let directory = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../target/abioticfactor-client");
    let observed: LevelSelectionObservation = serde_json::from_slice(
        &std::fs::read(directory.join("sector-level-selection.json")).expect("level selection inputs"),
    ).expect("level selection observation");
    let table = LevelTable::from_json(
        &std::fs::read(directory.join("sector-table.json")).expect("level table research export"),
    ).expect("current level table");
    let selected = abioticfactor_client::levels::find_latest_level(Some(observed.world_time), &observed.levels)
        .expect("overlapping level");
    let level = selected.level.as_deref().expect("world asset");
    assert_eq!(level, observed.expected_level);
    let row = table.row_for_level(level).expect("level row");
    assert_eq!(row.sector, observed.expected_sector);
    println!("{} level instances -> {level} -> {}", observed.levels.len(), row.sector);
}

#[derive(Deserialize)]
struct ClientObservation {
    level: String,
    sector: String,
    #[serde(rename = "ActiveLevelFXName")]
    row: String,
    #[serde(rename = "Day_FX_Row")]
    day: String,
    #[serde(rename = "Night_FX_Row")]
    night: String,
    #[serde(rename = "CheatLevelFXName")]
    cheat: String,
    #[serde(rename = "OverrideLevelFXName")]
    override_fx: String,
    #[serde(rename = "ActiveWeatherFXName")]
    weather: String,
    #[serde(rename = "ActiveSubFXName")]
    sub_fx: String,
}

#[test]
#[ignore = "requires sector_table_research and sector_client_research exports"]
fn level_lookup_matches_the_normal_clients_observed_sector() {
    let directory = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../target/abioticfactor-client");
    let table = LevelTable::from_json(
        &std::fs::read(directory.join("sector-table.json")).expect("level table research export"),
    ).expect("current level table");
    let observed: ClientObservation = serde_json::from_slice(
        &std::fs::read(directory.join("sector-client-snapshot.json")).expect("client research export"),
    ).expect("client observation");
    for active in [&observed.cheat, &observed.override_fx, &observed.weather, &observed.sub_fx] {
        assert!(active.eq_ignore_ascii_case("None"), "observation has a higher-priority FX override: {active}");
    }
    let row = table.row_for_level(&observed.level).expect("client-selected level in game table");
    assert!(row.row.eq_ignore_ascii_case(&observed.row));
    assert!(row.day.eq_ignore_ascii_case(&observed.day));
    assert!(row.night.eq_ignore_ascii_case(&observed.night));
    assert_eq!(row.sector, observed.sector);
    println!("normal client parity: {} -> {} -> {}", observed.level, row.row, row.sector);
}

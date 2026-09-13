//! DT_Levels lookup used by the real controller's Attempt Level FXChange.
//! Level membership and HUD transitions are separate from this table lookup.
//! See abioticfactor-mod/docs/lan-loading.md, "Client sector selection".

use std::io;

use serde::Deserialize;

#[derive(Debug, Deserialize, PartialEq)]
pub struct LevelDef {
    pub row: String,
    pub level: String,
    pub sector: String,
    pub day: String,
    pub night: String,
}

pub struct LevelTable {
    rows: Vec<LevelDef>,
}

/// Static InitializeLevels result, before local loading/visibility updates.
pub struct RegisteredLevel {
    pub level: String,
    pub volumes: Vec<String>,
}

/// Preserve the World's explicit streaming array and the native demo gate.
/// This supplies registration, not local visibility timestamps.
pub fn register_facility_levels(bytes: &[u8], demo_mode: bool) -> io::Result<Vec<RegisteredLevel>> {
    use serde_json::Value;
    let invalid = || {
        io::Error::new(
            io::ErrorKind::InvalidData,
            "invalid Facility registration export",
        )
    };
    let parsed: Value = serde_json::from_slice(bytes)?;
    let exports = parsed["exports"].as_array().ok_or_else(invalid)?;
    let mut indexed = std::collections::BTreeMap::new();
    for export in exports {
        let index = export["index"].as_u64().ok_or_else(invalid)?;
        if indexed.insert(index, export).is_some() {
            return Err(invalid());
        }
    }
    let mut worlds = exports.iter().filter(|e| e["class"] == "World");
    let world = worlds.next().ok_or_else(invalid)?;
    if worlds.next().is_some() {
        return Err(invalid());
    }
    let references = world["native"]["streaming_levels"]
        .as_array()
        .ok_or_else(invalid)?;
    let mut assets = Vec::new();
    let mut levels = Vec::new();
    for reference in references {
        let index = reference.as_u64().ok_or_else(invalid)?;
        if index == 0 {
            continue;
        }
        let export = indexed.get(&index).ok_or_else(invalid)?;
        if export["class"] != "LevelStreamingDynamic" {
            return Err(invalid());
        }
        let asset = &export["properties"]["WorldAsset"];
        for key in ["package", "asset", "subpath"] {
            asset[key].as_str().ok_or_else(invalid)?;
        }
        assets.push(asset);
        levels.push(RegisteredLevel {
            level: asset["asset"].as_str().ok_or_else(invalid)?.to_owned(),
            volumes: Vec::new(),
        });
    }
    for volume in exports
        .iter()
        .filter(|e| e["class"] == "AbioticLevelStreamingVolume")
    {
        let properties = &volume["properties"];
        let disabled = match properties.get("bDisabledForDemo") {
            None => false,
            Some(value) => value.as_bool().ok_or_else(invalid)?,
        };
        if demo_mode && disabled {
            continue;
        }
        let target = &properties["LevelToLoad"];
        for key in ["package", "asset", "subpath"] {
            target[key].as_str().ok_or_else(invalid)?;
        }
        // Package/asset are FNames; subpath is the case-sensitive string.
        if let Some(index) = assets.iter().position(|asset| {
            ["package", "asset"].iter().all(|key| {
                asset[key]
                    .as_str()
                    .unwrap()
                    .eq_ignore_ascii_case(target[key].as_str().unwrap())
            }) && asset["subpath"] == target["subpath"]
        }) {
            levels[index]
                .volumes
                .push(volume["name"].as_str().ok_or_else(invalid)?.to_owned());
        }
    }
    Ok(levels)
}

/// Local level-manager inputs in native map order. Unknown overlap data must
/// not be represented as false or an empty list.
#[derive(Debug, Deserialize)]
pub struct LevelInstance {
    pub level: Option<String>,
    pub last_time_visible: f32,
    pub overlapping: bool,
}

/// FindLatestLevelPlayerIsIn, RVA 0x4707320 in the researched build.
/// Some(instance) with no asset preserves the native found/empty distinction.
/// world_time=None means the native world pointer is null, not an unknown clock.
pub fn find_latest_level(
    world_time: Option<f64>,
    levels: &[LevelInstance],
) -> Option<&LevelInstance> {
    // Exact bytes of the initial comparison constant at image RVA 0x636D718.
    let mut best_age = f32::from_bits(0x7f7f_c99e);
    let mut selected = None;
    for level in levels {
        if !level.overlapping {
            continue;
        }
        let age = world_time.map_or(0.0, |time| {
            (time - f64::from(level.last_time_visible)) as f32
        });
        if age >= best_age {
            continue;
        }
        best_age = age;
        selected = Some(level);
    }
    selected
}

impl LevelTable {
    /// Consume the current-build research export without reordering its rows.
    pub fn from_json(bytes: &[u8]) -> io::Result<Self> {
        let rows: Vec<LevelDef> = serde_json::from_slice(bytes)?;
        if rows.is_empty()
            || rows.iter().any(|row| {
                [&row.row, &row.level, &row.day, &row.night]
                    .iter()
                    .any(|name| name.is_empty() || !name.is_ascii())
            })
        {
            return Err(io::Error::new(
                io::ErrorKind::InvalidData,
                "expected current-build level table with ASCII asset names",
            ));
        }
        Ok(Self { rows })
    }

    /// First matching FName wins. No match supplies no replacement row.
    pub fn row_for_level(&self, level: &str) -> Option<&LevelDef> {
        self.rows
            .iter()
            .find(|row| row.level.eq_ignore_ascii_case(level))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn overlapping_levels_use_visibility_age_and_keep_native_order_on_ties() {
        let mut levels = [
            LevelInstance {
                level: Some("first".into()),
                last_time_visible: 10.0,
                overlapping: true,
            },
            LevelInstance {
                level: Some("later".into()),
                last_time_visible: 20.0,
                overlapping: true,
            },
            LevelInstance {
                level: Some("outside".into()),
                last_time_visible: 30.0,
                overlapping: false,
            },
        ];
        assert_eq!(
            find_latest_level(Some(40.0), &levels)
                .expect("overlap")
                .level
                .as_deref(),
            Some("later")
        );
        levels[0].last_time_visible = 20.0;
        assert_eq!(
            find_latest_level(Some(40.0), &levels)
                .expect("tie")
                .level
                .as_deref(),
            Some("first")
        );
        // Different double differences can round to equal float ages.
        levels[0].last_time_visible = 10.0;
        assert_eq!(
            find_latest_level(Some(1.0e12), &levels)
                .expect("rounded tie")
                .level
                .as_deref(),
            Some("first")
        );
        assert_eq!(
            find_latest_level(None, &levels)
                .expect("no world uses zero age")
                .level
                .as_deref(),
            Some("first")
        );
        levels[0].level = None;
        assert!(
            find_latest_level(None, &levels)
                .expect("found but empty asset")
                .level
                .is_none()
        );
        levels
            .iter_mut()
            .for_each(|level| level.overlapping = false);
        assert!(find_latest_level(Some(40.0), &levels).is_none());
    }

    #[test]
    fn duplicate_level_names_keep_table_order_and_missing_levels_have_no_fallback() {
        let table = LevelTable::from_json(br#"[
            {"row":"first","level":"Facility_Office3","sector":"first sector","day":"day","night":"night"},
            {"row":"second","level":"facility_office3","sector":"second sector","day":"day","night":"night"}
        ]"#).expect("level table");
        assert_eq!(
            table
                .row_for_level("FACILITY_OFFICE3")
                .expect("matching row")
                .row,
            "first"
        );
        assert!(table.row_for_level("Facility_Missing").is_none());
    }
}

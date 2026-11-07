//! Preload alert: what a zone holds, known as soon as it loads, from the
//! files the game loaded for it. Copies GameHelper2's PreloadAlert: a
//! list of file paths the operator cares about, each with a display
//! name, matched exactly against this area's files.

use crate::model::LoadedFile;
use serde::{Deserialize, Serialize};
use std::collections::HashSet;
use std::path::Path;

/// GameHelper2 FileInfoValueStruct.IGNORE_FIRST_X_AREAS: files marked
/// with the first two area change counts are the game's startup loads,
/// not a zone's.
const IGNORE_FIRST_AREAS: i32 = 2;

/// One thing to look for: the file the game loads when the zone has it.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct PreloadDef {
    /// The file's path as the game names it, without the `@...` suffix.
    pub path: String,
    /// What to tell the operator.
    pub name: String,
    #[serde(default = "enabled_default")]
    pub enabled: bool,
}

fn enabled_default() -> bool {
    true
}

/// The files loaded for the current area: marked with the current
/// area change count, past the startup ones, with the `@...` suffix cut
/// off (GameHelper2 LoadedFiles.AddFileIfLoadedInCurrentArea).
pub fn files_this_area(files: &[LoadedFile], area_change_counter: i32) -> HashSet<String> {
    files
        .iter()
        .filter(|f| {
            f.area_change_count > IGNORE_FIRST_AREAS && f.area_change_count == area_change_counter
        })
        .map(|f| f.path.split('@').next().unwrap_or_default().to_string())
        .collect()
}

/// The enabled preloads this area has, in the list's order (the list
/// order is the priority).
pub fn found<'a>(defs: &'a [PreloadDef], area_files: &HashSet<String>) -> Vec<&'a PreloadDef> {
    defs.iter()
        .filter(|d| d.enabled && area_files.contains(&d.path))
        .collect()
}

/// Read the preload list, a JSON array of [`PreloadDef`]. A missing
/// file is an empty list.
pub fn load(path: &Path) -> Result<Vec<PreloadDef>, String> {
    match std::fs::read_to_string(path) {
        Ok(text) => serde_json::from_str(&text).map_err(|e| format!("{}: {e}", path.display())),
        Err(e) if e.kind() == std::io::ErrorKind::NotFound => Ok(Vec::new()),
        Err(e) => Err(format!("{}: {e}", path.display())),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn file(path: &str, count: i32) -> LoadedFile {
        LoadedFile {
            path: path.into(),
            area_change_count: count,
        }
    }

    fn def(path: &str, name: &str, enabled: bool) -> PreloadDef {
        PreloadDef {
            path: path.into(),
            name: name.into(),
            enabled,
        }
    }

    #[test]
    fn only_this_areas_files_count() {
        let files = [
            file("Metadata/A.ao@2", 7),
            file("Metadata/B.ao", 6),
            file("Metadata/C.ao", 2),
        ];
        let area = files_this_area(&files, 7);
        assert_eq!(area, HashSet::from(["Metadata/A.ao".to_string()]));
        assert!(files_this_area(&[file("Metadata/C.ao", 2)], 2).is_empty());
    }

    #[test]
    fn found_keeps_list_order_and_skips_disabled() {
        let defs = [
            def("Metadata/Second.ao", "second", true),
            def("Metadata/Off.ao", "off", false),
            def("Metadata/First.ao", "first", true),
            def("Metadata/Absent.ao", "absent", true),
        ];
        let area = HashSet::from([
            "Metadata/First.ao".to_string(),
            "Metadata/Second.ao".to_string(),
            "Metadata/Off.ao".to_string(),
        ]);
        let names: Vec<_> = found(&defs, &area)
            .iter()
            .map(|d| d.name.as_str())
            .collect();
        assert_eq!(names, ["second", "first"]);
    }

    #[test]
    fn load_reads_list_and_missing_file_is_empty() {
        let dir = std::env::temp_dir().join(format!("poe2-preload-{}", std::process::id()));
        std::fs::create_dir_all(&dir).unwrap();
        let path = dir.join("preloads.json");
        std::fs::write(&path, r#"[{"path": "Metadata/X.ao", "name": "x"}]"#).unwrap();
        assert_eq!(load(&path).unwrap(), vec![def("Metadata/X.ao", "x", true)]);
        assert!(load(&dir.join("absent.json")).unwrap().is_empty());
        std::fs::write(&path, "not json").unwrap();
        assert!(load(&path).is_err());
        std::fs::remove_dir_all(&dir).unwrap();
    }
}

//! UE introspection helpers: GObjects population summaries +
//! Outer-chain sampling. Pure engine traversal, useful in any
//! UE mod for diagnosing leaks ("which package is growing?",
//! "where in the asset tree do these instances live?").

use std::collections::HashMap;

use serde_json::{Value as Json, json};

use crate::ue::{self, UObject};

/// Walk GObjects once and return a population summary:
///
/// - total entries / valid UObjects
/// - top `top_n` classes by instance count
/// - top `top_n` root-packages by hosted-object count
///   (tells you WHICH content path holds the leaking objects,
///   not just what class they are)
/// - loaded levels (`Level`, `LevelStreaming*`,
///   `WorldPartitionRuntime*`) with name + root package
///
/// Cost: O(N) over GObjects + O(D) outer-chain walk per object
/// (D ~= 3-5). One pass; no extra walks.
pub fn gobjects_population(top_n: usize) -> Json {
    let Some(rt) = ue::try_runtime() else {
        return json!({"error": "ueforge: ue runtime not initialized"});
    };
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return json!({"error": "gobjects view invalid"});
    }

    let mut total = 0usize;
    let mut valid = 0usize;
    let mut by_class: HashMap<String, usize> = HashMap::new();
    let mut by_package: HashMap<String, usize> = HashMap::new();
    let mut levels: Vec<Json> = Vec::new();

    for obj in view.iter() {
        total += 1;
        valid += 1;
        let class_name = obj
            .class()
            .map(|c| c.as_object().name())
            .unwrap_or_else(|| String::from("<no-class>"));
        *by_class.entry(class_name.clone()).or_insert(0) += 1;

        let root_name = root_package_name(obj);
        *by_package.entry(root_name.clone()).or_insert(0) += 1;

        if levels.len() < 200 && is_level_class(&class_name) {
            levels.push(json!({
                "class": class_name,
                "name": obj.name(),
                "package": root_name,
            }));
        }
    }

    let top_classes = top_n_by_count(by_class, top_n, "class", "count");
    let top_packages = top_n_by_count(by_package, top_n, "package", "hosted_count");

    json!({
        "gobjects_total": total,
        "gobjects_valid": valid,
        "top_classes": top_classes,
        "top_packages": top_packages,
        "loaded_levels": levels,
    })
}

/// For up to `k` instances of the named class, walk the Outer
/// chain and return the chain as a `"Root.Outer.Outer.Name"`
/// string. Used to find WHICH SoundWave / WHICH Package is
/// growing -- "SoundWave +144" is a class delta; this turns it
/// into specific asset paths.
///
/// `class_name` matches the short class name (e.g. `"SoundWave"`).
/// Cost: O(N) over GObjects (continues counting matches after
/// `k` samples for accurate `matched_count`).
pub fn class_outer_samples(class_name: &str, k: usize) -> Json {
    let Some(rt) = ue::try_runtime() else {
        return json!({"error": "ueforge: ue runtime not initialized"});
    };
    let view = unsafe { ue::GObjectsView::from_image(rt.image_base, rt.platform_offsets) };
    if !view.is_valid() {
        return json!({"error": "gobjects view invalid"});
    }

    let mut samples: Vec<Json> = Vec::new();
    let mut scanned = 0usize;
    let mut matched = 0usize;
    for obj in view.iter() {
        scanned += 1;
        let cls = match obj.class() {
            Some(c) => c.as_object().name(),
            None => continue,
        };
        if cls != class_name {
            continue;
        }
        matched += 1;
        if samples.len() >= k {
            continue;
        }
        let (full_path, depth) = outer_chain_path(obj);
        samples.push(json!({
            "full_path": full_path,
            "name": obj.name(),
            "depth": depth,
        }));
    }

    json!({
        "class": class_name,
        "scanned_objects": scanned,
        "matched_count": matched,
        "samples_returned": samples.len(),
        "samples": samples,
    })
}

fn root_package_name(obj: &UObject) -> String {
    let mut cur = obj.outer();
    let mut depth = 0;
    while let Some(o) = cur {
        if depth > 16 {
            break;
        }
        let next = o.outer();
        if next.is_none() {
            return o.name();
        }
        cur = next;
        depth += 1;
    }
    String::from("<no-package>")
}

fn outer_chain_path(obj: &UObject) -> (String, usize) {
    let mut parts: Vec<String> = Vec::new();
    parts.push(obj.name());
    let mut cur = obj.outer();
    let mut depth = 0;
    while let Some(o) = cur {
        if depth > 16 {
            break;
        }
        parts.push(o.name());
        cur = o.outer();
        depth += 1;
    }
    parts.reverse();
    (parts.join("."), depth + 1)
}

fn is_level_class(name: &str) -> bool {
    name == "Level"
        || name.starts_with("LevelStreaming")
        || name.starts_with("WorldPartitionRuntime")
}

fn top_n_by_count(
    map: HashMap<String, usize>,
    n: usize,
    name_key: &'static str,
    count_key: &'static str,
) -> Vec<Json> {
    let mut v: Vec<(String, usize)> = map.into_iter().collect();
    v.sort_by(|a, b| b.1.cmp(&a.1));
    v.into_iter()
        .take(n)
        .map(|(name, count)| json!({ name_key: name, count_key: count }))
        .collect()
}

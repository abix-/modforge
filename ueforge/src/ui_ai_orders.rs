//! Shared AI player selection and order controls. Rendering uses snapshots,
//! never live actors. Games dispatch the returned commands through their API.
use crate::ui;
use parking_lot::Mutex;
use serde_json::{Value, json};

static SELECTED: Mutex<Vec<String>> = Mutex::new(Vec::new());
static GROUP: Mutex<[u8; 64]> = Mutex::new([0; 64]);

pub fn render(snapshot: &Value, dispatch: impl Fn(Value)) {
    let Some(rows) = snapshot.as_array().filter(|r| !r.is_empty()) else { return; };
    let mut selected = SELECTED.lock();
    selected.retain(|name| rows.iter().any(|r| r["name"] == *name));
    for row in rows {
        let name = row["name"].as_str().unwrap_or("AI player");
        let mut checked = selected.iter().any(|n| n == name);
        if ui::checkbox(name, &mut checked) {
            selected.retain(|n| n != name);
            if checked { selected.push(name.into()); }
        }
        let def = &row["definition"];
        let assignment = if def["assignment"]["kind"] == "follow" {
            format!("Follow {}", def["assignment"]["player"].as_str().unwrap_or(""))
        } else { "Hold position".into() };
        let action = row["action"]["reason"].as_str().unwrap_or_else(|| row["action"]["kind"].as_str().unwrap_or("unknown"));
        ui::text(&format!("{assignment} | {} | {action}", def["stance"].as_str().unwrap_or("unknown")));
    }
    if ui::button("Select all") { *selected = rows.iter().filter_map(|r| r["name"].as_str().map(str::to_owned)).collect(); }
    let mut groups: Vec<&str> = rows.iter().flat_map(|r| r["definition"]["groups"].as_array().into_iter().flatten().filter_map(Value::as_str)).collect();
    groups.sort_unstable(); groups.dedup();
    for group in groups {
        ui::same_line();
        if ui::button(&format!("Select {group}")) {
            *selected = rows.iter().filter(|r| r["definition"]["groups"].as_array().is_some_and(|g| g.iter().any(|v| v == group)))
                .filter_map(|r| r["name"].as_str().map(str::to_owned)).collect();
        }
    }
    if selected.is_empty() { return; }
    ui::text(&format!("Commands affect: {}", selected.join(", ")));
    let order = |command: &str, mut args: Value| {
        args["players"] = json!(*selected); args["command"] = json!(command); dispatch(args);
    };
    for (label, command) in [("Follow me", "follow"), ("Hold position", "hold"), ("Recall", "recall"), ("Cancel attack", "cancel_attack")] {
        if ui::button(label) { order(command, json!({})); }
        ui::same_line();
    }
    ui::text("");
    for (label, stance) in [("Passive", "passive"), ("Defensive", "defensive"), ("Aggressive", "aggressive")] {
        if ui::button(label) { order("stance", json!({"stance": stance})); }
        ui::same_line();
    }
    ui::text("");
    if let Some(row) = rows.iter().find(|r| selected.iter().any(|n| r["name"] == *n)) {
        for (key, label, low, high) in [("follow_distance", "Follow distance", 50.0, 1000.0), ("hold_radius", "Hold radius", 25.0, 500.0),
            ("chase_distance", "Chase distance", 100.0, 3000.0), ("pursuit_timeout", "Pursuit seconds", 1.0, 120.0)] {
            let mut value = row["definition"]["limits"][key].as_f64().unwrap_or(low) as f32;
            if ui::slider_f32(label, &mut value, low as f32, high as f32) { order("limits", json!({"limits": {key: value}})); }
        }
    }
    let mut group = GROUP.lock();
    ui::input_text("Group name", &mut *group);
    if ui::button("Set selected group") {
        let end = group.iter().position(|c| *c == 0).unwrap_or(group.len());
        let name = String::from_utf8_lossy(&group[..end]).trim().to_owned();
        if !name.is_empty() { order("groups", json!({"groups": [name]})); }
    }
    let mut targets = std::collections::BTreeMap::new();
    for target in rows.iter().filter(|r| selected.iter().any(|n| r["name"] == *n)).flat_map(|r| r["targets"].as_array().into_iter().flatten()) {
        if let (Some(selector), Some(name)) = (target["selector"].as_str(), target["name"].as_str()) { targets.insert(selector, name); }
    }
    for (selector, name) in targets {
        if ui::button(&format!("Attack {name}##{selector}")) { order("attack", json!({"target": selector})); }
    }
}

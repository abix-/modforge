//! Repeatable skill upgrades: a bought multiplier upgrade can be
//! bought again with the tree window's own unlock button, each time
//! stacking its Value once more (Factorio-style infinite research).
//!
//! Vanilla (Cpp2IL dump, 1.2.5; docs/research.md "Repeatable skill
//! upgrades"): the unlock button calls `Skill.TryUnlockNode(node)`,
//! which needs `node.CanUnlock()` (false once `IsUnlocked`), runs
//! `node.Unlock()` and takes one point. A `...MultiplierSkillNode`'s
//! `Unlock` adds the node itself to one `ModifiableFloat`, which
//! refuses the same modifier twice, so each repeat is a separate
//! copy (`Object.Instantiate`) run through the node type's own
//! `Reset` + `Unlock`. Measured live: crafting speed 0.75 -> 0.5625
//! with one copy.
//!
//! - postfix `SkillNode.CanUnlock`: true for an owned multiplier
//!   upgrade, so the button sells it again.
//! - prefix `Skill.TryUnlockNode`: on a repeat, add a copy and count
//!   it in thewalkingtrade.json (one set of counts for every save).
//!   The original then takes the point and refreshes the window.
//! - prefix `Skill.Load`: remove every copy (the game's
//!   `Skill.OnDisable` only resets the real upgrades); after the
//!   load (lib.rs) the counted copies go back in.

use std::ffi::{CStr, c_void};
use std::os::raw::c_char;
use std::sync::Mutex;

use serde_json::{Value as Json, json};
use unityforge::hook::{
    HOOK_REGISTRY, HookCtx, patch_postfix, patch_postfix_result, patch_prefix_ctx,
    patch_prefix_instance_args, write_result,
};
use unityforge::mono::{LogLevel, MonoObject, MonoType, invoke_static, json_handle, log, owned_object};

use crate::ctx_object;
use crate::settings::settings;

const NODE: &str = "Il2CppRuntime.Progression.Skills.Nodes.SkillNode";
const SKILL: &str = "Il2CppRuntime.Progression.Skills.Skill";
/// Marks the mod's copies by name, so they are never repeated
/// themselves and can be found again.
const COPY_MARK: &str = "#twt-repeat";

const VIEW: &str = "Il2CppRuntime.Progression.Skills.Views.SkillViewController";

/// (controller, node) of the OnNodePressed call in progress, from its
/// prefix to its postfix (plain postfixes get no context).
static PRESSED: Mutex<Option<(MonoObject, MonoObject)>> = Mutex::new(None);

pub fn install() {
    let results = [
        patch_postfix_result(NODE, "CanUnlock", &json!({}), can_unlock),
        patch_prefix_instance_args(SKILL, "TryUnlockNode", on_try_unlock),
        patch_prefix_ctx(SKILL, "Load", HookCtx::Instance, on_load),
        patch_prefix_instance_args(VIEW, "OnNodePressed", on_node_pressed),
        patch_postfix(VIEW, "OnNodePressed", after_node_pressed),
    ];
    for r in results {
        match r {
            Ok(h) => HOOK_REGISTRY.register(h),
            Err(e) => log(LogLevel::Error, &format!("thewalkingtrade-mod: skill repeat FAILED: {e}")),
        }
    }
}

/// Upgrades besides the `...MultiplierSkillNode`s whose `Unlock` adds
/// the node itself to a modifiable total, so a copy stacks (read from
/// the Cpp2IL dump 1.2.5).
const STACKING: &[&str] = &[
    // +Value hire slots: Unlock adds it to a ModifiableInt.
    "Runtime.Progression.Skills.Nodes.MaximumStaffCountSkillNode",
];

/// (class, name) of a stacking upgrade that is not one of the mod's
/// copies, from Unity's "<name> (<type>)".
fn multiplier(node: &MonoObject) -> Result<Option<(String, String)>, String> {
    let s = node.invoke("ToString", &json!([]))?;
    let s = s.as_str().unwrap_or("");
    let Some((name, class)) = s.rsplit_once(" (") else { return Ok(None) };
    let class = class.trim_end_matches(')');
    let stacks = class.ends_with("MultiplierSkillNode") || STACKING.contains(&class);
    if !stacks || name.contains(COPY_MARK) {
        return Ok(None);
    }
    Ok(Some((class.to_string(), name.to_string())))
}

fn is_unlocked(node: &MonoObject) -> Result<bool, String> {
    Ok(node.invoke("get_IsUnlocked", &json!([]))?.as_bool() == Some(true))
}

extern "C" fn can_unlock(
    instance: *const c_void,
    _args: *const c_char,
    result: *const c_char,
    out: *mut c_char,
    cap: i32,
) -> i32 {
    let _m = modforge::counters::measure("twt: hook: skill CanUnlock");
    let Some(node) = ctx_object(instance) else { return -1 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let result = unsafe { CStr::from_ptr(result) }.to_str().unwrap_or("");
    if result == "true" {
        return -1;
    }
    match multiplier(&node).and_then(|m| Ok(m.is_some() && is_unlocked(&node)?)) {
        // SAFETY: out/cap are the buffer the shim passed.
        Ok(true) => unsafe { write_result(out, cap, &json!(true)) },
        Ok(false) => -1,
        Err(e) => {
            log(LogLevel::Warn, &format!("thewalkingtrade-mod: skill repeat CanUnlock: {e}"));
            -1
        }
    }
}

/// `SkillViewController.OnNodePressed` shows the unlock button only
/// when the node's `IsUnlocked` field is false (read from the dump),
/// whatever `CanUnlock` says. Remember the call for the postfix.
extern "C" fn on_node_pressed(instance: *const c_void, args: *const c_char) -> i32 {
    let _m = modforge::counters::measure("twt: hook: skill node pressed");
    let Some(view) = ctx_object(instance) else { return 0 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let args = unsafe { CStr::from_ptr(args) }.to_str().unwrap_or("[]");
    let args: Json = serde_json::from_str(args).unwrap_or(Json::Null);
    let Some(nh) = args.get(0).and_then(json_handle) else { return 0 };
    if let Ok(mut p) = PRESSED.lock() {
        *p = Some((view, owned_object(nh)));
    }
    0
}

/// Show the unlock button for an owned repeatable upgrade while the
/// skill has points.
extern "C" fn after_node_pressed(_: *const c_void) {
    let _m = modforge::counters::measure("twt: hook: skill node pressed (after)");
    let Some((view, node)) = PRESSED.lock().ok().and_then(|mut p| p.take()) else { return };
    let show = || -> Result<(), String> {
        if multiplier(&node)?.is_none() || !is_unlocked(&node)? {
            return Ok(());
        }
        let skill = node.invoke("get_Skill", &json!([]))?;
        let sh = json_handle(&skill).ok_or("node has no Skill")?;
        let points = owned_object(sh).invoke("get_UnspentPoints", &json!([]))?.as_i64().unwrap_or(0);
        if points <= 0 {
            return Ok(());
        }
        let button = view.read_field("_upgradeButton")?;
        let bh = json_handle(&button).ok_or("no _upgradeButton")?;
        owned_object(bh).invoke("SetActive", &json!([true]))?;
        Ok(())
    };
    if let Err(e) = show() {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: skill repeat button: {e}"));
    }
}

extern "C" fn on_try_unlock(instance: *const c_void, args: *const c_char) -> i32 {
    let _m = modforge::counters::measure("twt: hook: skill buy");
    let Some(skill) = ctx_object(instance) else { return 0 };
    // SAFETY: the shim passes NUL-terminated JSON valid for the call.
    let args = unsafe { CStr::from_ptr(args) }.to_str().unwrap_or("[]");
    let args: Json = serde_json::from_str(args).unwrap_or(Json::Null);
    let Some(nh) = args.get(0).and_then(json_handle) else { return 0 };
    let node = owned_object(nh);
    if let Err(e) = repeat(&skill, &node) {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: skill repeat: {e}"));
    }
    // Never skip: the original takes the point and refreshes.
    0
}

fn repeat(skill: &MonoObject, node: &MonoObject) -> Result<(), String> {
    let Some((class, name)) = multiplier(node)? else { return Ok(()) };
    if !is_unlocked(node)? {
        return Ok(());
    }
    let points = skill.invoke("get_UnspentPoints", &json!([]))?.as_i64().unwrap_or(0);
    if points <= 0 {
        return Ok(());
    }
    add_copy(&class, &name, node)?;
    let key = format!("{class}|{name}");
    let n = settings()
        .update(|s| *s.skill_repeats.entry(key.clone()).or_insert(0) += 1)
        .skill_repeats[&key];
    log(LogLevel::Info, &format!("thewalkingtrade-mod: {name} bought again, x{}", n + 1));
    Ok(())
}

/// Copy `node`, mark the copy, and run the node type's own Reset +
/// Unlock on it so it lands in that upgrade's total.
fn add_copy(class: &str, name: &str, node: &MonoObject) -> Result<(), String> {
    let copy = invoke_static(
        "UnityEngine.Object",
        "Instantiate",
        &json!([{"$handle": node.handle().0}]),
    )?;
    let ch = json_handle(&copy).ok_or("Instantiate returned no object")?;
    // Unique across hot reloads and removals: the copy must be found
    // again by this exact name below.
    let stamp = std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_nanos())
        .unwrap_or(0);
    let copy_name = format!("{name}{COPY_MARK}{stamp}");
    owned_object(ch).invoke("set_name", &json!([copy_name]))?;
    // The Instantiate handle is typed UnityEngine.Object; a class
    // search hands the copy back typed as its own class.
    let typed = find(class, &copy_name)?.ok_or("copy not found by class search")?;
    typed.invoke("Reset", &json!([]))?;
    typed.invoke("Unlock", &json!([]))?;
    Ok(())
}

/// Every live object of `class`, typed as `class`, with its name.
fn instances(class: &str) -> Result<Vec<(String, MonoObject)>, String> {
    let ty = MonoType::find(&format!("Il2Cpp{class}")).ok_or_else(|| format!("type {class} not found"))?;
    let walked = ty.walk(true)?;
    let list = walked
        .get("instances")
        .and_then(Json::as_array)
        .or_else(|| walked.as_array())
        .cloned()
        .unwrap_or_default();
    Ok(list
        .iter()
        .filter_map(|v| {
            let name = v.get("name").and_then(Json::as_str).unwrap_or("").to_string();
            json_handle(v).map(|h| (name, owned_object(h)))
        })
        .collect())
}

/// The live object of `class` named `name`, typed as `class`.
fn find(class: &str, name: &str) -> Result<Option<MonoObject>, String> {
    Ok(instances(class)?.into_iter().find(|(n, _)| n == name).map(|(_, o)| o))
}

/// Every copy of `class` in the scene, found by its name mark. The
/// copies themselves are the record, so a hot reload (which clears
/// the mod's memory and the shim's handles) loses nothing.
fn copies(class: &str) -> Result<Vec<MonoObject>, String> {
    Ok(instances(class)?.into_iter().filter(|(n, _)| n.contains(COPY_MARK)).map(|(_, o)| o).collect())
}

extern "C" fn on_load(instance: *const c_void) -> i32 {
    let _m = modforge::counters::measure("twt: hook: skill load");
    drop(ctx_object(instance));
    if let Err(e) = remove_copies() {
        log(LogLevel::Warn, &format!("thewalkingtrade-mod: skill repeat remove: {e}"));
    }
    0
}

/// Take every copy back out of its total and destroy it: every marked
/// object of each upgrade type the settings count.
fn remove_copies() -> Result<(), String> {
    let classes: std::collections::BTreeSet<String> = settings()
        .get()
        .skill_repeats
        .keys()
        .filter_map(|k| k.split_once('|').map(|(c, _)| c.to_string()))
        .collect();
    for class in classes {
        for copy in copies(&class)? {
            copy.invoke("Reset", &json!([]))?;
            invoke_static("UnityEngine.Object", "Destroy", &json!([{"$handle": copy.handle().0}]))?;
        }
    }
    Ok(())
}

/// After a save loads, add the counted copies back. Main thread;
/// lib.rs calls it once per load.
pub fn reapply() {
    let repeats = settings().get().skill_repeats;
    let mut added = 0;
    for (key, count) in repeats {
        let Some((class, name)) = key.split_once('|') else { continue };
        let result = find(class, name).and_then(|node| {
            let Some(node) = node else { return Ok(0) };
            if !is_unlocked(&node)? {
                return Ok(0);
            }
            for _ in 0..count {
                add_copy(class, name, &node)?;
            }
            Ok(count)
        });
        match result {
            Ok(n) => added += n,
            Err(e) => log(LogLevel::Warn, &format!("thewalkingtrade-mod: skill repeat {name}: {e}")),
        }
    }
    log(LogLevel::Info, &format!("thewalkingtrade-mod: skill repeats restored: {added} copies"));
}

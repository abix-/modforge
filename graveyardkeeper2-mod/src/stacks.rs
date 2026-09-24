//! Item stack size x10. ItemDef.stackCount in GameBalance.itemDefs is the
//! stack limit every inventory reads live (Item.cs stacking code). Items
//! with a vanilla stack of 1 (tools, bodies, one-offs) and the test items
//! at 2 and 3 are left alone; every other item gets STACK_MULTIPLIER x its
//! vanilla size.
//!
//! GameBalance lives for the whole session, so this runs once per
//! GameBalance object (by GetHashCode) and never multiplies twice. It runs
//! from the tweaks' MainGame.AfterSceneHasLoaded hook.

use serde_json::json;
use std::sync::atomic::{AtomicI64, Ordering};
use unityforge::mono::{LogLevel, invoke_static, log};

use crate::take_all::{call, obj};
use crate::tweaks::read_handle;

const STACK_MULTIPLIER: i64 = 10;
/// Vanilla stacks at or below this are not changed.
const KEEP_AT_OR_BELOW: i64 = 3;

/// GetHashCode of the GameBalance already multiplied; 0 when none.
static APPLIED_TO: AtomicI64 = AtomicI64::new(0);

pub(crate) fn apply() -> Result<(), String> {
    let gb = obj(invoke_static("GameBalance", "get_Me", &json!([]))?).ok_or("no GameBalance")?;
    let id = gb.invoke("GetHashCode", &json!([]))?.as_i64().unwrap_or(0);
    if APPLIED_TO.load(Ordering::Acquire) == id {
        return Ok(());
    }
    let defs = read_handle(&gb, "itemDefs")?;
    let n = defs.read_field("_size")?.as_i64().unwrap_or(0);
    let mut changed = 0;
    for i in 0..n {
        let Some(def) = call(&defs, "get_Item", json!([i]))? else {
            continue;
        };
        let stack = def.read_field("stackCount")?.as_i64().unwrap_or(0);
        if stack > KEEP_AT_OR_BELOW {
            def.write_field("stackCount", &json!(stack * STACK_MULTIPLIER))?;
            changed += 1;
        }
    }
    APPLIED_TO.store(id, Ordering::Release);
    log(
        LogLevel::Info,
        &format!("stacks: {changed} of {n} items x{STACK_MULTIPLIER}"),
    );
    Ok(())
}

use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, MonoType};

const DEFAULT_SIZE: i32 = 40;

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "set_inventory_size",
        "Set player inventory slot count (vanilla 20)",
        "{size?: int}",
        set_inventory_size,
    ));
}

fn player_inventory_item() -> Result<MonoObject, String> {
    let mg_json = MonoType::find("MainGame")
        .ok_or("MainGame type not found")?
        .walk(false)?;

    let h = mg_json
        .get("instances")
        .and_then(Json::as_array)
        .and_then(|a| a.first())
        .and_then(|i| i.get("handle"))
        .and_then(Json::as_i64)
        .ok_or("no MainGame instance")? as i32;

    let mg = unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) };
    let pc = read_handle(&mg, "playerController")?;
    std::mem::forget(mg);
    let pd = read_handle(&pc, "playerData")?;
    std::mem::forget(pc);
    let inv = read_handle(&pd, "inventory")?;
    std::mem::forget(pd);
    let item = read_handle(&inv, "inventoryItem")?;
    std::mem::forget(inv);
    Ok(item)
}

fn read_handle(obj: &MonoObject, field: &str) -> Result<MonoObject, String> {
    let j = obj.read_field(field)?;
    let h = j
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("{field} has no handle"))? as i32;
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

fn set_inventory_size(args: &Json) -> Result<Json, String> {
    let size = args
        .get("size")
        .and_then(Json::as_i64)
        .unwrap_or(DEFAULT_SIZE as i64) as i32;

    if size < 20 {
        return Err("size must be at least 20 (vanilla)".into());
    }

    MAIN_QUEUE.run(
        "set_inventory_size",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            let item = player_inventory_item()?;
            let before = item.read_field("inventorySize")?;
            item.write_field("inventorySize", &json!(size))?;
            let after = item.read_field("inventorySize")?;
            std::mem::forget(item);
            Ok(json!({"before": before, "after": after}))
        },
    )?
}

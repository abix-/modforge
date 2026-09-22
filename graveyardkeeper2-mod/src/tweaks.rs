use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, MonoType};

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "tweaks",
        "Read or write player tweaks (inventory_size, speed, energy). Pass no args to read all",
        "{inventory_size?: int, speed?: float, energy?: int}",
        tweaks,
    ));
}

fn main_game() -> Result<MonoObject, String> {
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
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

fn read_handle(obj: &MonoObject, field: &str) -> Result<MonoObject, String> {
    let j = obj.read_field(field)?;
    let h = j
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("{field} has no handle"))? as i32;
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

fn tweaks(args: &Json) -> Result<Json, String> {
    let set_inv = args.get("inventory_size").and_then(Json::as_i64).map(|v| v as i32);
    let set_speed = args.get("speed").and_then(Json::as_f64).map(|v| v as f32);
    let set_energy = args.get("energy").and_then(Json::as_f64).map(|v| v as f32);

    MAIN_QUEUE.run(
        "tweaks",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            let mg = main_game()?;

            let pc = read_handle(&mg, "playerController")?;
            std::mem::forget(mg);
            let pd = read_handle(&pc, "playerData")?;
            let phys_json = pc.invoke("get_PhysicalBody", &json!([]))?;
            let phys_h = phys_json
                .get("handle")
                .and_then(Json::as_i64)
                .ok_or("PhysicalBody has no handle")? as i32;
            let phys = unsafe {
                MonoObject::from_handle(unityforge::bridge::MonoHandle(phys_h))
            };
            std::mem::forget(pc);

            // inventory size
            let inv = read_handle(&pd, "inventory")?;
            let inv_item = read_handle(&inv, "inventoryItem")?;
            std::mem::forget(inv);
            if let Some(size) = set_inv {
                if size < 20 {
                    return Err("inventory_size must be at least 20".into());
                }
                inv_item.write_field("inventorySize", &json!(size))?;
            }
            let cur_inv = inv_item.read_field("inventorySize")?;
            std::mem::forget(inv_item);

            // speed multiplier
            if let Some(spd) = set_speed {
                if spd < 0.1 {
                    return Err("speed must be at least 0.1".into());
                }
                phys.write_field("<SpeedMultiplier>k__BackingField", &json!(spd))?;
            }
            let cur_speed = phys.read_field("<SpeedMultiplier>k__BackingField")?;
            std::mem::forget(phys);

            // energy
            let res = read_handle(&pd, "res")?;
            std::mem::forget(pd);
            if let Some(nrg) = set_energy {
                res.invoke("SetWithoutSystemsCheck", &json!(["energy", nrg]))?;
            }
            let cur_energy = res.invoke("GetInt", &json!(["energy"]))?;
            std::mem::forget(res);

            Ok(json!({
                "inventory_size": cur_inv,
                "speed": cur_speed,
                "energy": cur_energy,
            }))
        },
    )?
}

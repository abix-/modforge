use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};
use unityforge::main_thread_queue::MAIN_QUEUE;
use unityforge::mono::{MonoObject, MonoType};

pub fn install() {
    OP_REGISTRY.register(OpDef::new(
        "add_energy",
        "Set energy to max (or a specific amount)",
        "{amount?: int}",
        add_energy,
    ));
    OP_REGISTRY.register(OpDef::new(
        "add_resource",
        "Add to any player resource (energy, tech_red, tech_green, tech_blue, money, etc.)",
        "{resource: str, amount: number}",
        add_resource,
    ));
}

fn player_res() -> Result<MonoObject, String> {
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
    let res = read_handle(&pd, "res")?;
    std::mem::forget(pd);
    Ok(res)
}

fn read_handle(obj: &MonoObject, field: &str) -> Result<MonoObject, String> {
    let j = obj.read_field(field)?;
    let h = j
        .get("handle")
        .and_then(Json::as_i64)
        .ok_or_else(|| format!("{field} has no handle"))? as i32;
    // SAFETY: handle is live from the read we just did
    Ok(unsafe { MonoObject::from_handle(unityforge::bridge::MonoHandle(h)) })
}

fn add_energy(args: &Json) -> Result<Json, String> {
    let amount = args
        .get("amount")
        .and_then(Json::as_f64)
        .unwrap_or(100.0) as f32;

    MAIN_QUEUE.run(
        "add_energy",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            let res = player_res()?;
            let before = res.invoke("GetInt", &json!(["energy"]))?;
            res.invoke("SetWithoutSystemsCheck", &json!(["energy", amount]))?;
            let after = res.invoke("GetInt", &json!(["energy"]))?;
            std::mem::forget(res);
            Ok(json!({"before": before, "after": after}))
        },
    )?
}

fn add_resource(args: &Json) -> Result<Json, String> {
    let resource = args
        .get("resource")
        .and_then(Json::as_str)
        .ok_or("resource required")?
        .to_string();
    let amount = args
        .get("amount")
        .and_then(Json::as_f64)
        .ok_or("amount required")? as f32;

    MAIN_QUEUE.run(
        "add_resource",
        std::time::Duration::from_secs(2),
        move || -> Result<Json, String> {
            let res = player_res()?;
            let before = res.invoke("GetInt", &json!([&resource]))?;
            res.invoke("AddWithoutSystemsCheck", &json!([&resource, amount]))?;
            let after = res.invoke("GetInt", &json!([&resource]))?;
            std::mem::forget(res);
            Ok(json!({"resource": resource, "before": before, "after": after, "added": amount}))
        },
    )?
}

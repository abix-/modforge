//! Auto harvest for ready crops, free of energy.
//!
//! A ready crop (garden_*_ready) is a Work object in the garden_bed group
//! with hp 4: the player holds the action key to hit it down. Its death
//! (WgoData.RunLogicsAfterDeath) is the harvest: crop drop, inventory
//! drop, executeOnDeath, inspiration, tech points, and the swap back to
//! an empty bed. This deals the bed's remaining hp in one
//! HPComponent.ApplyDamage call, the game's own path to that death, so
//! no energy is spent.
//!
//! The growing craft turns the bed into its _ready object in place
//! (ChangeWgoData) and then sets the status to Finished; take_all's hooks
//! queue the station on that, and on Init for beds saved while ready.

use serde_json::json;
use unityforge::mono::{LogLevel, MonoObject, log};

use crate::take_all::call;
use crate::tweaks::read_handle;

pub(crate) fn harvest(cc: &MonoObject) -> Result<(), String> {
    let wgo = read_handle(cc, "craftableObject")?;
    let def = call(&wgo, "get_Definition", json!([]))?.ok_or("bed has no Definition")?;
    if def.read_field("wgoGroup")? != json!("garden_bed")
        || def.read_field("interactionType")? != json!("Work")
    {
        return Ok(());
    }
    let hp = read_handle(&wgo, "hpComponent")?;
    let cur = hp.read_field("hp")?.as_i64().unwrap_or(0);
    if cur <= 0 {
        return Ok(());
    }
    hp.invoke("ApplyDamage", &json!([cur]))?;

    let id = wgo.read_field("id").unwrap_or(serde_json::Value::Null);
    log(LogLevel::Info, &format!("harvest: {id}"));
    Ok(())
}

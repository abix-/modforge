//! The deploy screen: every placed card on both sides, with its unit
//! numbers (from `units`) and where it stands (research_deploy
//! units_on_field, 2026-11-07).
//!
//! Path the game keeps it on: the match (reached from the recommended
//! formation panel's `match` field) -> playerManager.playerControllers
//! -> each controller's unitManager.units, one CardElement per card
//! bought. A CardElement holds its card (`unitData`), its spot on the
//! map (`mapElement.bound`, x, y, width, height; our side has negative
//! y) and `mapElement.facing`.

use serde_json::{Value as Json, json};
use unityforge::mono::{MonoObject, MonoType, json_handle, owned_object};

use crate::units;

fn object(v: Json) -> Option<MonoObject> {
    json_handle(&v).map(owned_object)
}

fn field(o: &MonoObject, f: &str) -> Result<Option<MonoObject>, String> {
    Ok(object(o.read_field(f)?))
}

/// "(x:-20, y:-170, width:40, height:20)" -> [x, y, width, height].
fn bound(text: &str) -> Option<[f64; 4]> {
    let mut out = [0.0; 4];
    let mut n = 0;
    for part in text.trim_matches(|c| c == '(' || c == ')').split(',') {
        let v = part.split(':').nth(1)?.trim().parse().ok()?;
        *out.get_mut(n)? = v;
        n += 1;
    }
    (n == 4).then_some(out)
}

/// The live match. Main thread only.
fn current_match() -> Result<MonoObject, String> {
    let ty = MonoType::find("Il2CppGameRiver.Client.ChooseRecommendFormPanel").ok_or("type ChooseRecommendFormPanel not found")?;
    let all = ty.walk(true)?;
    let list = all.get("instances").cloned().unwrap_or(all);
    for v in list.as_array().into_iter().flatten() {
        if let Some(p) = json_handle(v).map(owned_object)
            && let Some(m) = field(&p, "match")?
        {
            return Ok(m);
        }
    }
    Err("no match open".into())
}

/// Both sides' placed cards. Main thread only.
fn sides() -> Result<Json, String> {
    let m = current_match()?;
    let local = field(&m, "localPlayerController")?.ok_or("no localPlayerController")?;
    let pcs = field(&m, "playerManager")?
        .and_then(|pm| field(&pm, "playerControllers").ok().flatten())
        .ok_or("no playerControllers")?;
    let mut out = Vec::new();
    for i in 0..pcs.list_len_or_zero()? {
        let Some(pc) = object(pcs.invoke("get_Item", &json!([i]))?) else { continue };
        let ours = pc.invoke("Equals", &json!([{"$handle": local.handle().0}]))?.as_bool() == Some(true);
        let Some(list) = field(&pc, "unitManager")?.and_then(|um| field(&um, "units").ok().flatten()) else { continue };
        let mut cards = Vec::new();
        for u in 0..list.list_len_or_zero()? {
            let Some(card) = object(list.invoke("get_Item", &json!([u]))?) else { continue };
            let id = field(&card, "unitData")?.and_then(|d| d.read_field("id").ok()).and_then(|v| v.as_i64()).unwrap_or(0);
            let me = field(&card, "mapElement")?;
            let spot = me.as_ref().and_then(|e| e.read_field("bound").ok()).and_then(|v| v.as_str().and_then(bound));
            let facing = me.as_ref().and_then(|e| e.read_field("facing").ok()).and_then(|v| v.as_i64());
            cards.push(json!({
                "unit": units::unit(id).ok(),
                "card": id,
                "bound": spot,
                "facing": facing,
            }));
        }
        out.push(json!({"ours": ours, "cards": cards}));
    }
    Ok(Json::Array(out))
}

pub fn install() {
    modforge::ops::OP_REGISTRY.register(modforge::ops::OpDef::new(
        "deploy",
        "Both sides' placed cards on the deploy screen: unit numbers, map bound [x, y, width, height] and facing",
        "",
        |_| unityforge::main_thread_queue::MAIN_QUEUE.run_result("deploy", std::time::Duration::from_secs(10), sides),
    ));
}

#[cfg(test)]
mod tests {
    #[test]
    fn bound_reads_the_game_text() {
        assert_eq!(super::bound("(x:-20, y:-170, width:40, height:20)"), Some([-20.0, -170.0, 40.0, 20.0]));
        assert_eq!(super::bound("nonsense"), None);
    }
}

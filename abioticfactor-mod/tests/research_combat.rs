//! Does the Exor's brain run on Sophia? Join her with the Exor's own AI
//! controller class (AI_Controller_NPC_Exor_C, which carries BT_Main_Exor),
//! give her body the enemies' perception, start the tree if it did not start
//! by itself, and read what the controller's target choice writes to the
//! blackboard while an enemy is near. Live; the human stands near a monster.
//!
//! ```text
//! k3sc cargo-lock test -p abioticfactor-mod --test research_combat -- --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn exor_brain_on_sophia() {
    let api = api();
    if ping_or_skip(&api).is_none() { return; }
    // A fresh join, so the controller class is the Exor's.
    let left = api.op("ai_player.stop", json!({}));
    println!("ai_player.stop: {}", if left.ok { left.result.to_string() } else { format!("{:?}", left.error) });
    let joined = api.op("ai_player.start", json!({"controller_class": "AI_Controller_NPC_Exor_C"}));
    println!("ai_player.start: {}", if joined.ok { joined.result.to_string() } else { format!("{:?}", joined.error) });
    assert!(joined.ok, "ai_player.start: {:?}", joined.error);
    assert_eq!(joined.result["controller"]["class"], "AI_Controller_NPC_Exor_C");

    let status = api.op("ai_player.status", json!({}));
    assert!(status.ok, "ai_player.status: {:?}", status.error);
    println!("brain after join: {}", status.result["brain"]);
    let controller = joined.result["controller"]["addr"].as_str().unwrap_or("").to_owned();
    let keys = api.op("bb.get", json!({"controller": format!("addr:{controller}")}));
    println!("her blackboard: {}", if keys.ok { keys.result.to_string() } else { format!("{:?}", keys.error) });
    // Her own tree (fight with the Exor's tree while TargetActor is set, else
    // follow) needs an object key for the human: ABIOTIC_FOLLOW_KEY names it.
    // Without it, the Exor's tree runs alone, as the first runs did.
    // The node classes' reflected fields, as the live game declares them.
    for class in ["BTTask_RunBehavior", "BTDecorator_Blackboard", "BTTask_MoveTo", "BTComposite_Selector", "BehaviorTree"] {
        let detail = api.op("discover_class_detail", json!({"name": class}));
        let fields: Vec<String> = detail.result["fields"].as_array().into_iter().flatten()
            .map(|f| format!("{}@{}", f["name"].as_str().unwrap_or(""), f["offset"])).collect();
        println!("{class} fields: {fields:?}");
    }
    match std::env::var("ABIOTIC_FOLLOW_KEY") {
        Ok(follow_key) => {
            let human = common::human_name(&api, "Sophia");
            let tree = api.op("ai_player.tree", json!({"follow_key": follow_key, "follow_player": human}));
            println!("ai_player.tree: {}", if tree.ok { tree.result.to_string() } else { format!("{:?}", tree.error) });
            assert!(tree.ok, "ai_player.tree: {:?}", tree.error);
        }
        Err(_) => if status.result["brain"]["running"] != true {
            let started = api.op("ai_player.brain", json!({}));
            println!("ai_player.brain: {}", if started.ok { started.result.to_string() } else { format!("{:?}", started.error) });
        },
    }
    // Her eyes: the enemies' perception component on her body.
    let eyes = api.op("ai_player.perceive", json!({"player": "Sophia"}));
    println!("ai_player.perceive: {}", if eyes.ok { eyes.result.to_string() } else { format!("{:?}", eyes.error) });
    // Same faction as the human? The Faction byte on each character.
    let players = api.op("players", json!({}));
    for player in players.result["players"].as_array().into_iter().flatten() {
        println!("faction: {} = {}", player["name"], player["faction"]);
    }
    // Eyes to brain: her sightings into the controller's potential target list.
    let targets = api.op("ai_player.targets", json!({"on": true}));
    println!("ai_player.targets: {}", if targets.ok { targets.result.to_string() } else { format!("{:?}", targets.error) });
    // Beside the human, where the human has found a monster.
    let human = common::human_name(&api, "Sophia");
    let placed = api.op("ai_player.place", json!({"near_player": human, "distance": 200.0}));
    println!("ai_player.place: {}", if placed.ok { placed.result.to_string() } else { format!("{:?}", placed.error) });
    for tick in 1..=10 {
        std::thread::sleep(std::time::Duration::from_secs(2));
        let status = api.op("ai_player.status", json!({}));
        assert!(status.ok, "ai_player.status: {:?}", status.error);
        let seen = api.op("ai_player.perceived", json!({"player": "Sophia"}));
        let seen: Vec<String> = seen.result["perceived"].as_array().into_iter().flatten().filter_map(|p| p["class"].as_str().map(str::to_owned)).collect();
        println!("{}s: pawn {} move {} brain {} sees {:?}", tick * 2, status.result["pawn"]["location"], status.result["move_status"], status.result["brain"], seen);
    }
    let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-mod/exor-brain.json");
    std::fs::create_dir_all(path.parent().unwrap()).unwrap();
    std::fs::write(&path, serde_json::to_vec_pretty(&api.op("ai_player.status", json!({})).result).unwrap()).unwrap();
}

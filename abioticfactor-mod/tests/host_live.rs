//! The host path as the running game answers it: the login check the host
//! op makes (GetPlayerController, then IsLoggedIn) through the generic call,
//! and the host op itself. Read-only unless ABIOTIC_HOST names a save.
//!
//! ```text
//! k3sc cargo-lock test -p abioticfactor-mod --test host_live -- --nocapture
//! ```

mod common;
use common::{api, ping_or_skip};
use serde_json::json;

#[test]
fn login_check_as_the_game_answers_it() {
    let api = api();
    if ping_or_skip(&api).is_none() {
        return;
    }
    let widget = api.op(
        "resolve_selector",
        json!({"selector": "first_class:W_MainMenu_ContinueGame_C"}),
    );
    println!(
        "continue widget: {}",
        if widget.ok {
            widget.result.to_string()
        } else {
            format!("{:?}", widget.error)
        }
    );
    let controller = api.op("object.call", json!({"object": "singleton:GameplayStatics", "class": "GameplayStatics", "function": "GetPlayerController",
        "params": {"WorldContextObject": "first_class:W_MainMenu_ContinueGame_C", "PlayerIndex": 0}}));
    println!(
        "GetPlayerController: {}",
        if controller.ok {
            controller.result.to_string()
        } else {
            format!("{:?}", controller.error)
        }
    );
    let Some(address) = controller.result["ReturnValue"]["addr"].as_str() else {
        println!("no player controller");
        return;
    };
    let logged = api.op("object.call", json!({"object": "singleton:KismetSystemLibrary", "class": "KismetSystemLibrary", "function": "IsLoggedIn", "params": {"SpecificPlayer": address}}));
    println!(
        "IsLoggedIn: {}",
        if logged.ok {
            logged.result.to_string()
        } else {
            format!("{:?}", logged.error)
        }
    );
    // The same function's parameter records, so a wrong decode is visible.
    let signature = api.op(
        "function_parameters",
        json!({"class": "KismetSystemLibrary", "function": "IsLoggedIn"}),
    );
    println!("IsLoggedIn parameters: {}", signature.result);
    if let Ok(save) = std::env::var("ABIOTIC_HOST") {
        let hosted = api.op("host.saved_world", json!({"save": save, "max_players": 6}));
        println!(
            "host.saved_world: {}",
            if hosted.ok {
                hosted.result.to_string()
            } else {
                format!("{:?}", hosted.error)
            }
        );
    }
}

use std::ffi::c_void;

use crate::bbp_log;
use crate::hook::{OriginalProcessEvent, ProcessEventHook};
use crate::rpg::{skills, tracker};
use crate::sdk::{UFunction, UObject, find_class_fast};

const PLAYER_FALL_HOOK_CLASSES: &[&str] = &[
    "BP_SurvivalPlayerCharacter_C",
    "BP_SurvivalPlayerCharacter_Female02_C",
    "BP_SurvivalPlayerCharacter_Gellarde_C",
];

const FN_APPLY_FALL_DAMAGE: &str = "ApplyFallDamage";
const FN_ON_LANDED: &str = "OnLanded";

pub fn install() -> Result<Vec<ProcessEventHook>, &'static str> {
    let mut hooks = Vec::new();

    for &class_name in PLAYER_FALL_HOOK_CLASSES {
        if find_class_fast(class_name).is_none() {
            bbp_log!("rpg/fall: class {} not loaded yet, skipping", class_name);
            continue;
        }
        bbp_log!(
            "rpg/fall: hooking concrete player class {} for {} / {}",
            class_name,
            FN_APPLY_FALL_DAMAGE,
            FN_ON_LANDED
        );
        let class_name_owned = class_name.to_string();
        let hook =
            ProcessEventHook::install(class_name, move |this, function, parms, original| {
                on_player_fall_event(&class_name_owned, this, function, parms, original)
            })?;
        hooks.push(hook);
    }

    if hooks.is_empty() {
        return Err("no concrete player classes were loaded for fall hook");
    }

    Ok(hooks)
}

fn on_player_fall_event(
    hook_class_name: &str,
    this: &UObject,
    function: &UFunction,
    parms: *mut c_void,
    original: OriginalProcessEvent,
) {
    let fn_name = function.as_object().name();
    let suppress = is_fall_immunity_active()
        && is_player_character(this)
        && (fn_name == FN_APPLY_FALL_DAMAGE || fn_name == FN_ON_LANDED);

    if suppress {
        bbp_log!(
            "rpg/fall: suppressed {} on {} via {}",
            fn_name,
            this.name(),
            hook_class_name
        );
        return;
    }

    unsafe { original.call(this, function, parms) };
}

fn is_player_character(obj: &UObject) -> bool {
    obj.full_name().contains("BP_SurvivalPlayerCharacter")
}

fn is_fall_immunity_active() -> bool {
    tracker::with_state(|state| {
        let level = state
            .skill_levels
            .get(skills::SKILL_FALL_RESISTANCE)
            .copied()
            .unwrap_or(0);
        if level == 0 {
            return false;
        }
        skills::skill_bonus(1.0, level) >= 0.999
    })
    .unwrap_or(false)
}

//! Custom AI-player class derived directly from the game's base NPC.
//! Assets and NPC setup are Abiotic-specific; class creation is in ueforge.
//! K8s slot: Def=explicit asset configuration, Registry=none, Instance=pawn,
//! Controller=spawn.
use serde_json::json;
use ueforge::{reflect, ue::UObject};
use crate::ai_player::{addr, object_ptr};

// Shipped PDB: ?CopyCompleteValueToScriptVM@FProperty@@UEBAXPEAXPEBX@Z.
const COPY_PROPERTY_RVA: u32 = 0x124f750;
const NPC_DIR: &str = "/Game/Blueprints/Characters/NPCs";
const AI_PLAYER: ueforge::derived_class::DerivedClassDef = ueforge::derived_class::DerivedClassDef {
    name: "Modforge_AIPlayer_C", parent: "NPC_Base_ParentBP_C",
};
const CLASS_BINDINGS: ueforge::derived_class::ClassBindings = ueforge::derived_class::ClassBindings {
    construct: 0x12e14a0, set_super: 0x119c610, bind: 0x3415500,
    link: 0x119ccc0, create_default: 0x1188950, update_defaults: 0x34447b0,
    class_flags: 0xd4, class_within: 0xe0, config_name: 0xe8,
};

/// The Pillager's animation asset, the standing human on the base NPC.
const ANIMATION: &str = "AnimBP_Pillager_C";
static WALK_FEED: parking_lot::Mutex<Option<ueforge::hook::process_event::ProcessEventHook>> = parking_lot::Mutex::new(None);

/// The Pillager's animation asset fills its Speed from its owner only after
/// casting it to a Pillager, so on our class it stays at zero and she never
/// walks. Prior art: UE4SS mods hook BlueprintUpdateAnimation and write the
/// variables themselves (PD3-ZF-Laser, meccamod, rot-radar-minimap). After
/// each update on our pawn, Speed becomes her velocity length. Pillagers
/// themselves are untouched. Installed once, kept for the DLL's life.
unsafe fn install_walk_feed() -> Result<(), String> {
    let mut feed = WALK_FEED.lock();
    if feed.is_some() { return Ok(()); }
    let hook = ueforge::hook::process_event::ProcessEventHook::install(ANIMATION, |this, function, parms, original| {
        // SAFETY: the engine's own call on a live animation instance, forwarded unchanged first.
        unsafe {
            original.call(this, function, parms);
            if function.as_object().name() != "BlueprintUpdateAnimation" { return; }
            let Ok(owner) = call(this, "AnimInstance", "TryGetPawnOwner", json!({})) else { return };
            let pawn = addr(&owner["ReturnValue"]);
            if pawn == 0 { return; }
            let pawn = &*(pawn as *const UObject);
            if pawn.class().map(|c| c.as_object().name()).as_deref() != Some(AI_PLAYER.name) { return; }
            let Ok(velocity) = call(pawn, "Actor", "GetVelocity", json!({})) else { return };
            let v = &velocity["ReturnValue"];
            let speed = ["X", "Y", "Z"].iter().map(|k| v[k].as_f64().unwrap_or(0.0).powi(2)).sum::<f64>().sqrt();
            let _ = reflect::set_fields(this, json!({"Speed": speed}).as_object().unwrap());
        }
    }).map_err(|e| format!("walk feed hook on {ANIMATION}: {e}"))?;
    *feed = Some(hook);
    Ok(())
}

unsafe fn call(object: &UObject, class: &str, function: &str, params: serde_json::Value) -> Result<serde_json::Value, String> {
    // SAFETY: all callers operate on live objects in one game-thread spawn job.
    unsafe { reflect::call(object, class, function, params.as_object().unwrap()) }
}

/// Spawn our derived class, with human rendering and native melee assets selected
/// independently of a soldier body or soldier controller.
pub(crate) unsafe fn spawn(context: &UObject, location: (f64, f64, f64), faction: serde_json::Value) -> Result<(u64, u64), String> {
    // SAFETY: the caller owns one game-thread job; every actor is constructed
    // by the engine and configured before possession or the first tick.
    unsafe {
        crate::npcs::blueprint_class(NPC_DIR, "NPC_Base_ParentBP")?;
        let base = AI_PLAYER.ensure(&CLASS_BINDINGS, |defaults| {
            let grunt = crate::npcs::blueprint_class(NPC_DIR, "NPC_Soldier_Grunt")?;
            let donor = grunt.class_default_object().ok_or("Grunt asset defaults unavailable")?;
            reflect::copy_named_fields(donor, defaults, &["MeleeAttacks"], COPY_PROPERTY_RVA)?;
            reflect::set_fields(defaults, json!({"AutoPossessAI": 0, "NPCDataTableRow": "Grunt",
                "SkipSpawnFX": true, "HeadBones": ["head"], "TorsoBones": ["hips"],
                "LeftArmBones": ["l_arm1"], "RightArmBones": ["r_arm1"],
                "LeftLegBones": ["l_leg1"], "RightLegBones": ["r_leg1"],
                "MeleeHitApex": 0.5, "PowerMeleeHitApex": 0.72}).as_object().unwrap())
        })?;
        let controller_class = crate::npcs::blueprint_class(NPC_DIR, "Abiotic_AI_Controller_ParentBP")?;
        let pawn = ueforge::spawn_ops::spawn_actor_configured(context, &base.as_object().name(), location, 180.0,
            json!({"Faction": faction}).as_object().unwrap(), |body| {
                let mesh = object_ptr(body, "Mesh")?;
                if mesh == 0 { return Err("base NPC has no native mesh component".into()); }
                let mesh_object = &*(mesh as *const UObject);
                // Female head 03 (user rejected 02, 2026-09-14). Every human part shares
                // SK_Human_Skeleton, so the animation asset is unchanged.
                call(mesh_object, "SkeletalMeshComponent", "SetSkeletalMeshAsset", json!({"NewMesh": "asset:/Game/Models/Characters/Scientist/Female/SK_Head_F_03.SK_Head_F_03"}))?;
                call(mesh_object, "SceneComponent", "K2_SetRelativeLocation", json!({"NewLocation": {"X": 0.0, "Y": 0.0, "Z": -88.0}, "bSweep": false, "bTeleport": true}))?;
                // The Pillager's animation asset: a base NPC child on scientist parts and the
                // human skeleton that stands, walks and fights. NPC_Coworker_AnimBP made her
                // crawl; ABF_NarrativeNPC_AnimBP calls a player-only function and crashed (2026-09-14).
                call(mesh_object, "SkeletalMeshComponent", "SetAnimClass", json!({"NewClass": format!("asset:/Game/Models/Characters/NPCs/LabRat/AnimBP_Pillager.{ANIMATION}")}))?;
                install_walk_feed()?;
                Ok(())
            })?;
        let mut controller = 0;
        let setup = (|| -> Result<(), String> {
            let body = &*(pawn as *const UObject);
            // BeginPlay initializes the selected stats row, including faction.
            // Apply this AI player's relationship before possession and ticking.
            reflect::set_fields(body, json!({"Faction": faction}).as_object().unwrap())?;
            let mesh = object_ptr(body, "Mesh")?;
            for (folder, asset) in [("Male", "SK_Torso_Jacket_M"), ("Female", "SK_Legs_Skirt"), ("HeadAccessories/Hair", "SK_Hair_RuggedPonytail")] {
                let component = ueforge::spawn_ops::add_component(body, "SkeletalMeshComponent", json!({"ComponentTags": ["AIPlayerBody"]}).as_object().unwrap())?;
                let part = &*(component as *const UObject);
                call(part, "SkeletalMeshComponent", "SetSkeletalMeshAsset", json!({"NewMesh": format!("asset:/Game/Models/Characters/Scientist/{folder}/{asset}.{asset}")}))?;
                call(part, "SceneComponent", "K2_AttachToComponent", json!({"Parent": format!("0x{mesh:X}"), "SocketName": "None", "LocationRule": 2, "RotationRule": 2, "ScaleRule": 2, "bWeldSimulatedBodies": false}))?;
                call(part, "SkinnedMeshComponent", "SetLeaderPoseComponent", json!({"NewLeaderBoneComponent": format!("0x{mesh:X}"), "bForceUpdate": true, "bInFollowerShouldTickPose": false}))?;
            }
            // Only the blackboard schema is reused. No stock NPC decision tree
            // runs while our controller initializes.
            let template = reflect::object_ref(&json!("asset:/Game/Blueprints/AI/Soldier/BT_Main_Soldier.BT_Main_Soldier"))?;
            let board = object_ptr(&*(template as *const UObject), "BlackboardAsset")?;
            let idle = ueforge::behavior_tree::build(pawn, board, &json!({"class": "BTComposite_Sequence", "children": [
                {"class": "BTTask_Wait", "fields": {"WaitTime": 60.0}}
            ]}))?;
            controller = ueforge::spawn_ops::spawn_actor(context, &controller_class.as_object().name(), location, 180.0,
                json!({"BehaviorTree": format!("0x{idle:X}")}).as_object().unwrap())?;
            let ai = &*(controller as *const UObject);
            ueforge::spawn_ops::initialize_path_following(ai)?;
            if object_ptr(ai, "PathFollowingComponent")? == 0 { return Err("base controller path following unavailable".into()); }
            call(ai, "Controller", "Possess", json!({"InPawn": format!("0x{pawn:X}")}))?;
            let possessed = call(ai, "Controller", "K2_GetPawn", json!({}))?;
            if addr(&possessed["ReturnValue"]) != pawn { return Err("base controller did not possess base NPC".into()); }
            Ok(())
        })();
        if let Err(error) = setup {
            for actor in [controller, pawn].into_iter().filter(|a| *a != 0) {
                call(&*(actor as *const UObject), "Actor", "K2_DestroyActor", json!({}))
                    .map_err(|cleanup| format!("{error}; cleanup: {cleanup}"))?;
            }
            return Err(error);
        }
        Ok((pawn, controller))
    }
}

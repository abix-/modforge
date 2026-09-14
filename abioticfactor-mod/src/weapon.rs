//! The companion's default kitchen knife, using the game's item data.
use serde_json::{Value, json};
use ueforge::ue::UObject;

fn field<'a>(data: &'a Value, prefix: &str) -> Result<(&'a str, &'a Value), String> {
    data.as_object().and_then(|o| o.iter().find(|(k, _)| k.starts_with(prefix)))
        .map(|(k,v)| (k.as_str(),v)).ok_or_else(|| format!("missing item field {prefix}"))
}

/// Attach the knife and select melee-only NPC attacks. Game thread.
pub(crate) unsafe fn equip(pawn: &UObject) -> Result<Value, String> {
    use ueforge::reflect::{call, get_fields, set_fields};
    // SAFETY: the caller supplies a live NPC on the game thread. The item
    // table and each struct property supply the layout of the row we read.
    unsafe {
        let table = ueforge::ue::datatable::find_by_short_name("ItemTable_Global").ok_or("ItemTable_Global not loaded")?;
        let name = ueforge::ue::fname::from_str("knife", ueforge::ue::fname::FindName::Find).ok_or("knife row name not loaded")?;
        let row = ueforge::ue::datatable::row_value_by_fname(table, name).ok_or("knife row missing")?;
        let layout = crate::ai_player::object_ptr(table, "RowStruct")?;
        if layout == 0 { return Err("item row struct missing".into()); }
        let layout = &*(layout as *const ueforge::ue::UClass);
        let mut data = serde_json::Map::new();
        for p in layout.cached_native_properties().iter().filter(|p| ["WeaponData_", "TPAttachSocket_", "Scale_TPHeldMesh_"].iter().any(|prefix| p.name.starts_with(prefix))) {
            data.insert(p.name.clone(), ueforge::reflect::read_value(row, p, &ueforge::reflect::property_type(p).unwrap_or_default()));
        }
        let data = Value::Object(data);
        let weapon = field(&data, "WeaponData_")?.1;
        let damage = field(weapon, "DamagePerHit_")?.1;
        let damage_type = field(weapon, "DamageType_Hitscan_")?.1;
        let socket = field(&data, "TPAttachSocket_")?.1;
        let scale = field(&data, "Scale_TPHeldMesh_")?.1;
        let state = get_fields(pawn, &["Mesh".into(), "NPCData".into()])?;
        let body = crate::ai_player::addr(&state["Mesh"]);
        if body == 0 { return Err("companion body mesh missing".into()); }
        let body = &*(body as *const UObject);
        let exists = call(body, "SceneComponent", "DoesSocketExist", json!({"InSocketName": socket}).as_object().unwrap())?;
        if exists["ReturnValue"] != true { return Err(format!("NPC body has no knife socket {socket}")); }
        let tagged = call(pawn, "Actor", "GetComponentsByTag", json!({"ComponentClass": "class:StaticMeshComponent", "Tag": "CompanionWeapon"}).as_object().unwrap())?;
        let existing = tagged["ReturnValue"].as_array().and_then(|v| v.first()).map(crate::ai_player::addr).unwrap_or(0);
        let component = if existing != 0 { existing } else {
            ueforge::spawn_ops::add_component(pawn, "StaticMeshComponent", json!({"ComponentTags": ["CompanionWeapon"]}).as_object().unwrap())?
        };
        let mesh = &*(component as *const UObject);
        call(mesh, "StaticMeshComponent", "SetStaticMesh", json!({"NewMesh": "asset:/Game/Models/Weapons/Melee/Knife/SM_Knife_01.SM_Knife_01"}).as_object().unwrap())?;
        // SetStaticMesh returns false when the same mesh is already assigned.
        let applied = get_fields(mesh, &["StaticMesh".into()])?;
        if applied["StaticMesh"]["name"] != "SM_Knife_01" { return Err(format!("knife mesh assignment failed: {applied}")); }
        call(mesh, "PrimitiveComponent", "SetCollisionEnabled", json!({"NewType": 0}).as_object().unwrap())?;
        let attached = call(mesh, "SceneComponent", "K2_AttachToComponent", json!({"Parent": state["Mesh"]["addr"], "SocketName": socket, "LocationRule": 2, "RotationRule": 2, "ScaleRule": 2, "bWeldSimulatedBodies": false}).as_object().unwrap())?;
        if attached["ReturnValue"] != true { return Err("knife attachment failed".into()); }
        call(mesh, "SceneComponent", "SetRelativeScale3D", json!({"NewScale3D": {"X": scale, "Y": scale, "Z": scale}}).as_object().unwrap())?;
        let mut npc = serde_json::Map::new();
        npc.insert(field(&state["NPCData"], "HasRangedAttack_")?.0.into(), json!(false));
        npc.insert(field(&state["NPCData"], "MeleeAttackDamagePerHit_")?.0.into(), damage.clone());
        npc.insert(field(&state["NPCData"], "DamageType_Melee_")?.0.into(), damage_type["addr"].clone());
        set_fields(pawn, json!({"NPCData": npc}).as_object().unwrap())?;
        Ok(json!({"item": "knife", "component": format!("0x{component:X}"), "socket": socket, "damage": damage, "ranged": false, "durability_consumption": false}))
    }
}

pub(crate) fn register() {
    ueforge::ops::OP_REGISTRY.register(ueforge::ops::OpDef::new("ai_player.equip_knife", "Attach the default kitchen knife and select melee-only attacks", "{player?: str}", |args| {
        let name = crate::ai_player::player_name(args)?;
        ueforge::debug::enqueue_pe(&crate::DRAIN, std::time::Duration::from_secs(30), crate::DRAIN_HINT, move || unsafe {
            let (_, pawn) = crate::ai_player::session_controller(&name)?;
            if pawn == 0 { return Err("companion has no body".into()); }
            equip(&*(pawn as *const UObject))
        })
    }));
}

//! Permanent encounter setup through the game's NPC spawner.
mod common;
#[path = "common/spawn_trace.rs"]
#[allow(dead_code)]
mod spawn_trace;
use common::{api, human_name};
use serde_json::json;

fn checked(
    api: &modforge::client::Api<serde_json::Value>,
    op: &str,
    args: serde_json::Value,
) -> Result<serde_json::Value, String> {
    let reply = api.op(op, args);
    if reply.ok {
        Ok(reply.result)
    } else {
        Err(format!("{op}: {:?}", reply.error))
    }
}

fn call(
    api: &modforge::client::Api<serde_json::Value>,
    object: &str,
    class: &str,
    function: &str,
    params: serde_json::Value,
) -> Result<serde_json::Value, String> {
    checked(
        api,
        "object.call",
        json!({"object": format!("addr:{object}"), "class": class, "function": function, "params": params}),
    )
}

// Convert reflected read descriptions to the write API's parameter format.
fn parameter_value(value: &serde_json::Value) -> serde_json::Value {
    if value == "None" {
        return json!({"raw": "0000000000000000"});
    }
    if value["count"] == 0 {
        return json!([]);
    }
    if value["addr"].is_string() {
        return value["addr"].clone();
    }
    match value {
        serde_json::Value::Object(fields) => fields
            .iter()
            .map(|(k, v)| (k.clone(), parameter_value(v)))
            .collect(),
        serde_json::Value::Array(items) => items.iter().map(parameter_value).collect(),
        _ => value.clone(),
    }
}

#[test]
#[ignore = "temporarily gives two empty NPC inventories one slot and tests the game's item insertion and transfer"]
fn npc_inventory_transfer() {
    let api = api();
    let players = checked(&api, "players", json!({})).unwrap();
    let human = players["players"]
        .as_array()
        .unwrap()
        .iter()
        .find(|p| p["name"] != "Sophia")
        .unwrap();
    let human_addr = human["character"].as_str().unwrap();
    let fields = checked(
        &api,
        "object.get",
        json!({"object": format!("addr:{human_addr}"), "fields": ["CharacterInventory"]}),
    )
    .unwrap();
    let human_inventory = fields["CharacterInventory"]["addr"].as_str().unwrap();
    let items = checked(
        &api,
        "array.get",
        json!({"object": format!("addr:{human_inventory}"), "field": "CurrentInventory"}),
    )
    .unwrap();
    println!(
        "human inventory sample: {}",
        items.to_string().chars().take(1800).collect::<String>()
    );
    let mut item = items["elements"]
        .as_array()
        .unwrap()
        .iter()
        .filter_map(|slot| slot.as_object())
        .flat_map(|slot| slot.values())
        .find(|value| {
            value["RowName"]
                .as_str()
                .is_some_and(|name| name != "Empty" && name != "None")
        })
        .expect("an item row in human inventory")
        .clone();
    item["DataTable"] = item["DataTable"]["addr"].clone();
    println!("test item row (human item remains untouched): {item}");
    let context = u64::from_str_radix(human_addr.trim_start_matches("0x"), 16).unwrap();
    let actors = checked(
        &api,
        "actors_of_class",
        json!({"world_context": context, "class": "Character"}),
    )
    .unwrap();
    let mut selected = Vec::new();
    for npc in actors["actors"]
        .as_array()
        .unwrap()
        .iter()
        .filter(|a| a["class"].as_str().is_some_and(|c| c.starts_with("NPC_")))
    {
        let address = npc["addr"].as_str().unwrap();
        let fields = checked(&api, "object.get", json!({"object": format!("addr:{address}"), "fields": ["CharacterInventory", "TotalCombinedHealth"]})).unwrap();
        if fields["TotalCombinedHealth"].as_f64().unwrap_or(0.0) <= 0.0 {
            continue;
        }
        let Some(inventory) = fields["CharacterInventory"]["addr"].as_str() else {
            continue;
        };
        let state = checked(&api, "object.get", json!({"object": format!("addr:{inventory}"), "fields": ["MaxSlots", "CurrentInventory"]})).unwrap();
        if state["MaxSlots"] == 0
            && (state["CurrentInventory"]["count"] == 0
                || state["CurrentInventory"]
                    .as_array()
                    .is_some_and(Vec::is_empty))
        {
            selected.push((address.to_owned(), inventory.to_owned()));
        }
        if selected.len() == 2 {
            break;
        }
    }
    assert_eq!(
        selected.len(),
        2,
        "need two living NPCs with empty zero-slot inventories"
    );
    println!("NPC inventories: {selected:?}");
    let class = "Abiotic_InventoryComponent_C";
    let outcome = (|| -> Result<(), String> {
        for (_, inventory) in &selected {
            call(
                &api,
                inventory,
                class,
                "UpdateInventorySlotCount",
                json!({"NewMaxSlots": 1}),
            )?;
        }
        let created = call(
            &api,
            &selected[0].1,
            class,
            "CreateNewItemWithDefaultData",
            json!({"DataTableRowHandle": item, "StackAmount": 1}),
        )?;
        println!("created: {created}");
        let data = created["ItemSlotData"]
            .as_object()
            .ok_or("item slot data")?
            .iter()
            .find(|(name, _)| name.starts_with("ChangeableData"))
            .map(|(_, value)| value.clone())
            .ok_or("changeable data")?;
        let inserted = call(
            &api,
            &selected[0].1,
            class,
            "Try Place Item in Inventory",
            json!({"DataTableRowHandle": item, "ChangeableData": parameter_value(&data), "Place Leftover in the Same Inventory?": true}),
        )?;
        println!("insert: {inserted}");
        if inserted["Success"] != true {
            return Err(format!("NPC insertion failed: {inserted}"));
        }
        let transfer = call(
            &api,
            &selected[0].1,
            class,
            "Server_TransferItemsToCharacterByRowName",
            json!({"Character": selected[1].0, "ItemRowName": item["RowName"], "Amount": 1}),
        )?;
        println!("transfer: {transfer}");
        let mut counts = Vec::new();
        for (_, inventory) in &selected {
            let slots = checked(
                &api,
                "array.get",
                json!({"object": format!("addr:{inventory}"), "field": "CurrentInventory"}),
            )?;
            println!("inventory {inventory}: {slots}");
            let count = slots["elements"]
                .as_array()
                .into_iter()
                .flatten()
                .filter(|slot| {
                    slot.as_object()
                        .is_some_and(|o| o.values().any(|v| v["RowName"] == item["RowName"]))
                })
                .count();
            counts.push(count);
        }
        if counts != [0, 1] {
            return Err(format!(
                "expected source empty and destination holding test item; got {counts:?}"
            ));
        }
        Ok(())
    })();
    // Remove only the item this test created, then restore the originally empty inventories.
    for (_, inventory) in &selected {
        let removed = call(
            &api,
            inventory,
            class,
            "Remove Item from Inventory",
            json!({"Item": item["RowName"], "AllItemsOfType": false, "Count": 1}),
        );
        println!("cleanup item: {removed:?}");
        assert!(removed.is_ok(), "test item cleanup failed");
        call(
            &api,
            inventory,
            class,
            "UpdateInventorySlotCount",
            json!({"NewMaxSlots": 0}),
        )
        .unwrap();
    }
    outcome.unwrap();
}

#[test]
#[ignore = "reads the native skill and inventory operation schemas before the NPC capability test"]
fn npc_capability_schemas() {
    let api = api();
    for table in ["DT_Skills", "DT_StatModifiers"] {
        println!(
            "table {table}: {:?}",
            checked(
                &api,
                "dump_data_table",
                json!({"table_name": table, "max_rows": 2})
            )
        );
        println!(
            "rows {table}: {:?}",
            checked(&api, "list_row_names", json!({"table_name": table}))
        );
    }
    for (class, function) in [
        ("AbioticCharacter", "UpdateSkillStatLevel"),
        ("AbioticCharacter", "GetStatModifierValue"),
        ("Abiotic_InventoryComponent_C", "UpdateInventorySlotCount"),
        (
            "Abiotic_InventoryComponent_C",
            "CreateNewItemWithDefaultData",
        ),
        (
            "Abiotic_InventoryComponent_C",
            "Try Place Item in Inventory",
        ),
        ("Abiotic_InventoryComponent_C", "Remove Item from Inventory"),
        (
            "Abiotic_InventoryComponent_C",
            "Server_TransferItemsToCharacterByRowName",
        ),
    ] {
        let reply = api.op(
            "function_parameters",
            json!({"class": class, "function": function}),
        );
        assert!(reply.ok, "{class}::{function}: {:?}", reply.error);
        println!("{class}::{function}: {}", reply.result);
    }
}

#[test]
#[ignore = "compares inventory struct metadata with the generic decoder"]
fn npc_inventory_layout() {
    use spawn_trace::{http_read, struct_fields};
    let api = api();
    let players = checked(&api, "players", json!({})).unwrap();
    let human = players["players"]
        .as_array()
        .unwrap()
        .iter()
        .find(|p| p["name"] != "Sophia")
        .unwrap();
    let fields = checked(&api, "object.get", json!({"object": format!("addr:{}", human["character"].as_str().unwrap()), "fields": ["CharacterInventory"]})).unwrap();
    let inventory = u64::from_str_radix(
        fields["CharacterInventory"]["addr"]
            .as_str()
            .unwrap()
            .trim_start_matches("0x"),
        16,
    )
    .unwrap();
    let pointer = |at| u64::from_le_bytes(http_read(&api, at, 8).unwrap().try_into().unwrap());
    let (property, _) =
        spawn_trace::class_field(&api, pointer(inventory + 16), "CurrentInventory").unwrap();
    let layout = pointer(pointer(property + 0x78) + 0x70);
    println!(
        "inventory struct {:?}: header {} fields {:?}",
        spawn_trace::object_name(&api, layout).unwrap(),
        hex::encode(http_read(&api, layout + 0x50, 0x68).unwrap()),
        struct_fields(&api, layout).unwrap()
    );
    let structs = checked(
        &api,
        "walk_class_chain",
        json!({"needle": "Struct", "max": 16384}),
    )
    .unwrap();
    for item in structs["instances"].as_array().unwrap().iter().filter(|s| {
        s["name"].as_str().is_some_and(|n| {
            n.contains("InventoryItem")
                || n.contains("ItemSlot")
                || n == "SkillRowHandle"
                || n == "RowHandle"
                || n == "Object"
        })
    }) {
        println!("struct: {item}");
        let address =
            u64::from_str_radix(item["addr"].as_str().unwrap().trim_start_matches("0x"), 16)
                .unwrap();
        println!(
            "header: {}",
            hex::encode(http_read(&api, address + 0x50, 0x68).unwrap())
        );
        println!("fields: {:?}", struct_fields(&api, address).unwrap());
        println!(
            "generic: {:?}",
            checked(&api, "struct.layout", json!({"name": item["name"]}))
        );
    }
}

#[test]
#[ignore = "reads a nearby NPC's existing inventory, skill state, and supported operations"]
fn npc_player_capabilities() {
    let api = api();
    let players = api.op("players", json!({}));
    assert!(players.ok, "players: {:?}", players.error);
    let human = players.result["players"]
        .as_array()
        .expect("players")
        .iter()
        .find(|p| p["name"] != "Sophia")
        .expect("human");
    let context = u64::from_str_radix(
        human["character"]
            .as_str()
            .expect("character")
            .trim_start_matches("0x"),
        16,
    )
    .unwrap();
    let actors = api.op(
        "actors_of_class",
        json!({"world_context": context, "class": "Character"}),
    );
    assert!(actors.ok, "actors: {:?}", actors.error);
    let mut npcs: Vec<_> = actors.result["actors"]
        .as_array()
        .expect("actors")
        .iter()
        .filter(|a| a["class"].as_str().is_some_and(|c| c.starts_with("NPC_")))
        .collect();
    let distance = |a: &serde_json::Value| {
        (0..3)
            .map(|i| {
                (a["location"][i].as_f64().unwrap_or(0.0)
                    - human["location"][i].as_f64().unwrap_or(0.0))
                .powi(2)
            })
            .sum::<f64>()
    };
    npcs.sort_by(|a, b| distance(a).total_cmp(&distance(b)));
    let npc = npcs.first().expect("nearby NPC");
    println!("NPC: {npc}");
    let address = npc["addr"].as_str().expect("NPC address");
    let fields = api.op("object.get", json!({"object": format!("addr:{address}"), "fields": ["CharacterInventory", "SkillLevelMap", "StatModifierMap", "TotalCombinedHealth", "Controller"]}));
    assert!(fields.ok, "NPC fields: {:?}", fields.error);
    println!("NPC fields: {}", fields.result);
    for class in [
        "AbioticCharacter",
        "Abiotic_Character_ParentBP_C",
        "Abiotic_InventoryComponent_C",
        "Abiotic_PlayerState_C",
    ] {
        let functions = api.op("class_functions_by_name", json!({"class": class}));
        assert!(functions.ok, "functions {class}: {:?}", functions.error);
        for f in functions.result["functions"]
            .as_array()
            .into_iter()
            .flatten()
            .filter(|f| {
                f["name"].as_str().is_some_and(|n| {
                    ["Skill", "Inventory", "Item", "Slot", "XP"]
                        .iter()
                        .any(|part| n.contains(part))
                })
            })
        {
            println!("{class}: {}", f["name"]);
        }
    }
    if let Some(inventory) = fields.result["CharacterInventory"]["addr"].as_str() {
        let state = api.op("object.get", json!({"object": format!("addr:{inventory}")}));
        assert!(state.ok, "inventory: {:?}", state.error);
        println!("inventory: {}", state.result);
    }
}

#[test]
#[ignore = "reads Sophia's controller setup and target-selection gates"]
fn sophia_combat_setup() {
    let api = api();
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok, "status: {:?}", status.error);
    println!("status: {}", status.result);
    let controller = status.result["controller"]["addr"]
        .as_str()
        .expect("controller");
    for field in [
        "SetupComplete",
        "MyPawn",
        "LastSeenPotentialCombatTargetsList",
        "AttackerList",
    ] {
        let value = api.op(
            "object.get",
            json!({"object": format!("addr:{controller}"), "fields": [field]}),
        );
        println!("{field}: {} {:?}", value.result, value.error);
        if field == "SetupComplete" || field == "MyPawn" {
            assert!(value.ok, "{field}: {:?}", value.error);
        }
    }
}

#[test]
#[ignore = "respawns Sophia, places her beside the human and enables close follow"]
fn sophia_respawn_near_player() {
    let api = api();
    let human = human_name(&api, "Sophia");
    let before = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(before.ok, "status: {:?}", before.error);
    let pawn = before.result["pawn"]["addr"].as_str().expect("Sophia pawn");
    // Omitted DestinationID stays zero (NAME_None); converting "None" fails in the current mod.
    let respawn = api.op("object.call", json!({"object": format!("addr:{pawn}"), "class": "Abiotic_PlayerCharacter_C", "function": "Request_RespawnPlayerCharacter",
        "params": {"RevivedOnSpot": false, "UsePlayerStartOnly": true}}));
    println!("respawn: {} {:?}", respawn.result, respawn.error);
    assert!(respawn.ok, "respawn: {:?}", respawn.error);
    std::thread::sleep(std::time::Duration::from_secs(2));
    let placed = api.op(
        "ai_player.place",
        json!({"player": "Sophia", "near_player": human, "distance": 150.0}),
    );
    println!("placed: {} {:?}", placed.result, placed.error);
    assert!(
        placed.ok && placed.result["teleported"] == true,
        "place: {} {:?}",
        placed.result,
        placed.error
    );
    let follow = api.op(
        "ai_player.follow",
        json!({"player": "Sophia", "target": human, "distance": 150.0}),
    );
    assert!(follow.ok, "follow: {:?}", follow.error);
    let status = api.op("ai_player.status", json!({"player": "Sophia"}));
    assert!(status.ok, "status: {:?}", status.error);
    println!("status: {}", status.result);
    let pawn = status.result["pawn"]["addr"].as_str().expect("Sophia pawn");
    let health = api.op("object.get", json!({"object": format!("addr:{pawn}"), "fields": ["TotalCombinedHealth", "IsDead", "IsDBNO"]}));
    println!("health: {} {:?}", health.result, health.error);
    assert!(
        health.ok
            && health.result["TotalCombinedHealth"]
                .as_f64()
                .is_some_and(|h| h > 0.0)
            && health.result["IsDead"] == false
            && health.result["IsDBNO"] == false,
        "Sophia did not revive: {}",
        health.result
    );
}

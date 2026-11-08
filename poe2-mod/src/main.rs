//! poe2-mod: Path of Exile 2 helper, run beside the game.
//!
//! Reads game memory read-only and answers on a localhost control
//! server (`POST http://127.0.0.1:17185/op`). Never loads into the
//! game, never writes to it, never presses keys.

mod entities;
mod files;
mod game;
mod item_rules;
mod items;
mod loot_value;
mod model;
mod preload;
mod states;
mod zone;

use modforge::ops::{OP_REGISTRY, OpDef};
use modforge::patterns::sleuth::{TEXT_SECTION, read_process_image, unique_rip_target};
use modforge::process_memory::{Module, ProcessMemory, find_pid_by_name, pe_timestamp};
use parking_lot::{Mutex, MutexGuard};
use serde_json::{Value as Json, json};

/// One static pattern's result.
struct Found {
    pattern: &'static game::StaticPattern,
    address: Result<u64, String>,
}

/// The game we have open, and the globals its patterns found. Kept
/// until the game's pid changes, so the exe is read and searched once
/// per game run, not on every op.
struct Attached {
    pid: u32,
    exe: Module,
    mem: ProcessMemory,
    statics: Vec<Found>,
}

impl Attached {
    /// The address the first pattern named `name` that matched found;
    /// the `statics` op shows whether the others agree.
    fn static_address(&self, name: &str) -> Result<u64, String> {
        let mut errors = Vec::new();
        for f in self.statics.iter().filter(|f| f.pattern.name == name) {
            match &f.address {
                Ok(address) => return Ok(*address),
                Err(e) => errors.push(format!("{}: {e}", f.pattern.source)),
            }
        }
        if errors.is_empty() {
            Err(format!("no pattern named {name:?}"))
        } else {
            Err(format!("{name}: {}", errors.join("; ")))
        }
    }
}

static ATTACHED: Mutex<Option<Attached>> = Mutex::new(None);

fn find_game() -> Option<(&'static str, u32)> {
    game::EXE_NAMES
        .iter()
        .find_map(|name| find_pid_by_name(name).ok().map(|pid| (*name, pid)))
}

/// Open the running game read-only and search its exe for every static
/// pattern, unless that was already done for this pid.
fn attached() -> Result<MutexGuard<'static, Option<Attached>>, String> {
    let (_, pid) = find_game().ok_or("game not running")?;
    let mut guard = ATTACHED.lock();
    if guard.as_ref().is_some_and(|a| a.pid == pid) {
        return Ok(guard);
    }
    let mem = ProcessMemory::open(pid).map_err(|e| format!("open pid {pid} read-only: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    let image = read_process_image(&mem, &exe).map_err(|e| format!("read exe image: {e:#}"))?;
    let statics = game::STATIC_PATTERNS
        .iter()
        .map(|pattern| Found {
            pattern,
            address: unique_rip_target(&image, pattern.sig, Some(TEXT_SECTION))
                .map_err(|e| format!("{e:#}")),
        })
        .collect();
    *guard = Some(Attached {
        pid,
        exe,
        mem,
        statics,
    });
    Ok(guard)
}

/// Every static pattern, the address it found, and for each name
/// whether all its patterns agree.
fn statics_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let patterns: Vec<Json> = a
        .statics
        .iter()
        .map(|f| {
            json!({
                "name": f.pattern.name,
                "source": f.pattern.source,
                "address": f.address.as_ref().ok().map(|x| format!("{x:#x}")),
                "rva": f.address.as_ref().ok().map(|x| format!("{:#x}", x - a.exe.base)),
                "error": f.address.as_ref().err(),
            })
        })
        .collect();
    let mut agree = serde_json::Map::new();
    for f in &a.statics {
        let same: Vec<_> = a
            .statics
            .iter()
            .filter(|g| g.pattern.name == f.pattern.name)
            .map(|g| g.address.as_ref().ok().copied())
            .collect();
        let all_found_and_equal = same.iter().all(|x| x.is_some() && *x == same[0]);
        agree.insert(f.pattern.name.to_string(), json!(all_found_and_equal));
    }
    Ok(
        json!({"pid": a.pid, "base": format!("{:#x}", a.exe.base), "patterns": patterns, "agree": agree}),
    )
}

/// The current game state, read the way GameHelper2's GameStates does:
/// the "Game States" global points at an object holding a vector whose
/// entry 0x10 before its end is the current state, and an array of the
/// thirteen states in a fixed order.
fn game_state_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let global = a.static_address("Game States")?;
    let s = states::read(&a.mem, global).map_err(|e| format!("{e:#}"))?;
    Ok(json!({
        "game_states_global": format!("{global:#x}"),
        "game_states": format!("{:#x}", s.object),
        "current": format!("{:#x}", s.current),
        "current_name": s.current_name(),
        "states": game::game_states::NAMES
            .iter()
            .zip(s.all)
            .map(|(name, at)| json!({"name": name, "address": format!("{at:#x}")}))
            .collect::<Vec<_>>(),
    }))
}

/// The area instance, from the in-game state.
fn area_instance(a: &Attached) -> Result<u64, String> {
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let area: u64 = a
        .mem
        .read_value(in_game + zone::IN_GAME_AREA_INSTANCE)
        .map_err(|e| format!("read area instance pointer: {e}"))?;
    if area == 0 {
        return Err("no area instance: not in game".into());
    }
    Ok(area)
}

/// Entities in the zone: awake ones, or sleeping ones too, optionally
/// only those whose path contains `path`.
fn entities_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let filter = args["path"].as_str().map(str::to_lowercase);
    let mut maps = vec![(
        "awake",
        area + entities::AREA_AWAKE_ENTITIES,
        entities::MAX_AWAKE,
    )];
    if args["sleeping"].as_bool() == Some(true) {
        maps.push((
            "sleeping",
            area + entities::AREA_SLEEPING_ENTITIES,
            entities::MAX_SLEEPING,
        ));
    }
    let mut out = serde_json::Map::new();
    for (name, map, max) in maps {
        let addresses = entities::map_addresses(&a.mem, map, max).map_err(|e| format!("{e:#}"))?;
        let mut unreadable = 0;
        let mut list = Vec::new();
        for at in &addresses {
            match entities::read(&a.mem, *at) {
                Ok(e) => {
                    if filter
                        .as_ref()
                        .is_none_or(|f| e.path.to_lowercase().contains(f))
                    {
                        list.push(e);
                    }
                }
                Err(_) => unreadable += 1,
            }
        }
        out.insert(
            name.into(),
            json!({"in_map": addresses.len(), "unreadable": unreadable, "entities": list}),
        );
    }
    Ok(Json::Object(out))
}

/// The local player's entity with its parts and every part name.
fn player_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let at = entities::local_player(&a.mem, area_instance(a)?).map_err(|e| format!("{e:#}"))?;
    let e = entities::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    Ok(json!({"entity": e, "parts": e.parts.keys().collect::<Vec<_>>()}))
}

/// The zone the player is in, from the in-game state.
fn zone_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let zone = zone::read(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let counter = files::area_change_counter(&a.mem, a.static_address("AreaChangeCounter")?)
        .map_err(|e| format!("{e:#}"))?;
    Ok(json!({
        "current_state": s.current_name(),
        "zone": zone,
        "area_change_counter": counter,
    }))
}

/// Find the running game, open it read-only, and report its exe and
/// build stamp read both from memory and from the file on disk.
fn game_op(_args: &Json) -> Result<Json, String> {
    let Some((exe_name, pid)) = find_game() else {
        return Ok(json!({"running": false, "looked_for": game::EXE_NAMES}));
    };
    let mem = ProcessMemory::open(pid).map_err(|e| format!("open pid {pid} read-only: {e}"))?;
    let exe = mem.main_module().map_err(|e| format!("main module: {e}"))?;
    let stamp_in_memory = mem
        .image_timestamp(&exe)
        .map_err(|e| format!("read PE header at {:#x}: {e}", exe.base))?;
    let stamp_on_disk = std::fs::read(&exe.path)
        .ok()
        .and_then(|bytes| pe_timestamp(&bytes));
    Ok(json!({
        "running": true,
        "exe_name": exe_name,
        "pid": pid,
        "exe_path": exe.path,
        "base": format!("{:#x}", exe.base),
        "size": exe.size,
        "access": format!("{:#x}", modforge::process_memory::READ_ACCESS),
        "stamp_in_memory": stamp_in_memory,
        "stamp_on_disk": stamp_on_disk,
    }))
}

/// The last poe.ninja price list fetched, and its league.
static PRICES: Mutex<Option<(String, loot_value::PriceList)>> = Mutex::new(None);

/// GameHelper2 LootValue's default league.
const DEFAULT_LEAGUE: &str = "Forbidden Rites";

fn parse<T: serde::de::DeserializeOwned>(args: &Json, key: &str) -> Result<T, String> {
    serde_json::from_value(args[key].clone()).map_err(|e| format!("{key}: {e}"))
}

/// Fetch poe.ninja prices for a league and keep them.
fn prices_op(args: &Json) -> Result<Json, String> {
    let league = args["league"]
        .as_str()
        .unwrap_or(DEFAULT_LEAGUE)
        .to_string();
    let (list, failed) = loot_value::fetch(&league);
    let count = list.count();
    *PRICES.lock() = Some((league.clone(), list));
    Ok(json!({"league": league, "prices": count, "failed": failed}))
}

/// An item on the ground and where it lies.
type GroundItem = (model::Item, Option<[f32; 3]>);

/// The items on the ground among the awake entities, with each one's
/// position; the second value counts ground items that could not be read.
fn ground_items(a: &Attached) -> Result<(Vec<GroundItem>, usize), String> {
    let area = area_instance(a)?;
    let addresses = entities::map_addresses(
        &a.mem,
        area + entities::AREA_AWAKE_ENTITIES,
        entities::MAX_AWAKE,
    )
    .map_err(|e| format!("{e:#}"))?;
    let mut items = Vec::new();
    let mut unreadable = 0;
    for at in addresses {
        let Ok(e) = entities::read(&a.mem, at) else {
            continue;
        };
        let Some(world_item) = e.parts.get("WorldItem") else {
            continue;
        };
        match items::on_ground(&a.mem, *world_item) {
            Ok(item) => items.push((item, e.position)),
            Err(_) => unreadable += 1,
        }
    }
    Ok((items, unreadable))
}

/// Price each item and say which rule it passes. The items are the
/// ones on the ground, or the given ones.
fn items_op(args: &Json) -> Result<Json, String> {
    let (items, positions, unreadable) = if args["items"].is_null() {
        let guard = attached()?;
        let a = guard.as_ref().ok_or("not attached")?;
        let (found, unreadable) = ground_items(a)?;
        let (items, positions): (Vec<_>, Vec<_>) = found.into_iter().unzip();
        (items, positions, unreadable)
    } else {
        let items: Vec<model::Item> = parse(args, "items")?;
        let positions = vec![None; items.len()];
        (items, positions, 0)
    };
    let rules: Vec<item_rules::ItemRule> = if args["rules"].is_null() {
        Vec::new()
    } else {
        parse(args, "rules")?
    };
    let prices = PRICES.lock();
    let stack = |item: &model::Item| prices.as_ref().and_then(|(_, p)| p.stack(item));
    let matched: std::collections::HashMap<usize, &str> =
        item_rules::matching(&rules, &items, stack)
            .into_iter()
            .collect();
    let out: Vec<Json> = items
        .iter()
        .enumerate()
        .map(|(i, item)| {
            json!({
                "item": item,
                "unique": prices.as_ref().and_then(|(_, p)| p.unique_name(&item.art)),
                "position": positions[i],
                "exalted": stack(item),
                "rule": matched.get(&i),
            })
        })
        .collect();
    Ok(json!({
        "league": prices.as_ref().map(|(l, _)| l),
        "unreadable": unreadable,
        "items": out,
    }))
}

/// The preloads found in an area. The loaded files and area change
/// counter come in the arguments until the data files reader exists.
fn preload_op(args: &Json) -> Result<Json, String> {
    let (files, counter, unreadable) = if args["files"].is_null() {
        let guard = attached()?;
        let a = guard.as_ref().ok_or("not attached")?;
        let counter = files::area_change_counter(&a.mem, a.static_address("AreaChangeCounter")?)
            .map_err(|e| format!("{e:#}"))?;
        let (files, unreadable) =
            files::loaded_files(&a.mem, a.static_address("File Root")?, |c| {
                preload::loaded_this_area(c, counter)
            })
            .map_err(|e| format!("{e:#}"))?;
        (files, counter, unreadable)
    } else {
        let counter = args["area_change_counter"]
            .as_i64()
            .ok_or("area_change_counter: missing")? as i32;
        (parse(args, "files")?, counter, 0)
    };
    let defs: Vec<preload::PreloadDef> = match args["list"].as_str() {
        Some(path) => preload::load(std::path::Path::new(path))?,
        None => parse(args, "defs")?,
    };
    let area = preload::files_this_area(&files, counter);
    let found = preload::found(&defs, &area);
    Ok(json!({
        "area_change_counter": counter,
        "area_files": area.len(),
        "unreadable_files": unreadable,
        "found": found,
    }))
}

fn main() {
    OP_REGISTRY.register(OpDef::new(
        "prices",
        "fetch poe.ninja prices in exalted orbs for a league (default Forbidden Rites) and keep them",
        "league?",
        prices_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "items",
        "price the items on the ground (or the given items) from the kept prices and name the first item rule each passes",
        "items?, rules?",
        items_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "preload",
        "the preloads found in this area's loaded files: read from the game, or the given files and area change counter",
        "list | defs, files?, area_change_counter?",
        preload_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "game",
        "find the running game, open it read-only, report exe and build stamp from memory and disk",
        "",
        game_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "statics",
        "search the game's exe for every static pattern; each address found and whether patterns of one name agree",
        "",
        statics_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "game_state",
        "the current game state and the thirteen state addresses, read like GameHelper2's GameStates",
        "",
        game_state_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "zone",
        "the zone: id, name, act, level, instance hash, town, hideout, waypoint, and the area change counter",
        "",
        zone_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "entities",
        "entities in the zone with path, life, position, rarity, chest, shrine; sleeping: true adds far ones",
        "path?, sleeping?",
        entities_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "player",
        "the local player's entity: name, level, life, mana, energy shield, position, and its part names",
        "",
        player_op,
    ));
    OP_REGISTRY.register(OpDef::new("list_ops", "every op", "", |_| {
        Ok(OP_REGISTRY.list_json())
    }));
    modforge::server::spawn(
        modforge::server::Config {
            port: game::PORT,
            endpoint: "/op",
            thread_name: "poe2-mod-http",
            auth_token: None,
        },
        |body| {
            let response = modforge::envelope::handle_request(
                body,
                &OP_REGISTRY,
                || json!({"process": "poe2-mod"}),
            );
            serde_json::to_vec(&response).unwrap_or_default()
        },
        |message| println!("{message}"),
    );
    loop {
        std::thread::park();
    }
}

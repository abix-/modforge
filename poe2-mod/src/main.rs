//! poe2-mod: Path of Exile 2 helper, run beside the game.
//!
//! Reads game memory read-only and answers on a localhost control
//! server (`POST http://127.0.0.1:17185/op`). Never loads into the
//! game, never writes to it, never presses keys.

mod abyss;
mod atlas;
mod atlas_routes;
mod buff_bar;
mod camera;
mod draw;
mod entities;
mod files;
mod game;
mod ground_labels;
mod health_bars;
mod inventory;
mod item_rules;
mod items;
mod kinds;
mod loot_value;
mod model;
mod pickup;
mod preload;
mod radar;
mod ritual;
mod skills;
mod slots;
mod states;
mod terrain;
mod ui;
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
    let mut guard = ATTACHED.lock();
    if guard.as_ref().is_some_and(|a| a.mem.is_running()) {
        return Ok(guard);
    }
    let (_, pid) = find_game().ok_or("game not running")?;
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

/// The inspector's entity view (GameHelper2 Entity.ToImGui): one entity,
/// by `id` among the awake ones, by `addr`, or the player when neither
/// is given, with every part's name and address and what is read from
/// them. `part` with `n` adds that part's first `n` bytes as words.
fn inspect_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let at = if let Some(id) = args["id"].as_u64() {
        let addresses = entities::map_addresses(
            &a.mem,
            area + entities::AREA_AWAKE_ENTITIES,
            entities::MAX_AWAKE,
        )
        .map_err(|e| format!("{e:#}"))?;
        addresses
            .into_iter()
            .find(|at| entities::read(&a.mem, *at).is_ok_and(|e| u64::from(e.id) == id))
            .ok_or(format!("no awake entity with id {id}"))?
    } else if !args["addr"].is_null() {
        modforge::memory_research::address_arg(&args["addr"])?
    } else {
        entities::local_player(&a.mem, area).map_err(|e| format!("{e:#}"))?
    };
    let e = entities::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    let parts: serde_json::Map<String, Json> = e
        .parts
        .iter()
        .map(|(name, p)| (name.clone(), json!(format!("{p:#x}"))))
        .collect();
    let mut out = json!({"address": format!("{at:#x}"), "parts": parts, "entity": e});
    if let Some(name) = args["part"].as_str() {
        let p = *e.parts.get(name).ok_or(format!("no part {name}"))?;
        let n = args["n"].as_u64().unwrap_or(0x100).min(0x1000) as usize;
        let words: Vec<u64> = a
            .mem
            .read_array(p, n / 8)
            .map_err(|e| format!("read part {name}: {e}"))?;
        let rows: Vec<String> = words
            .iter()
            .enumerate()
            .map(|(i, w)| format!("+{:#05x}: {w:#018x}", i * 8))
            .collect();
        out["part"] = json!({"name": name, "words": rows});
    }
    Ok(out)
}

/// The buffs on an entity, none when it has no Buffs part.
fn player_buffs(a: &Attached, e: &entities::Entity) -> Result<Vec<entities::Buff>, String> {
    match e.parts.get("Buffs") {
        Some(p) => entities::read_buffs(&a.mem, *p).map_err(|e| format!("{e:#}")),
        None => Ok(Vec::new()),
    }
}

/// The player buff bar: watched buffs (`watch`, a list, else
/// GameHelper2's default) with stacks and time left, charges and rage,
/// and the player's living totems.
fn buff_bar_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let at = entities::local_player(&a.mem, area).map_err(|e| format!("{e:#}"))?;
    let e = entities::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    let buffs = player_buffs(a, &e)?;
    let given: Vec<&str> = args["watch"]
        .as_array()
        .map(|v| v.iter().filter_map(Json::as_str).collect())
        .unwrap_or_default();
    let watch: &[&str] = if given.is_empty() {
        &buff_bar::DEFAULT_WATCHLIST
    } else {
        &given
    };
    let show_inactive = args["show_inactive"].as_bool().unwrap_or(true);
    let resources = e
        .stats
        .as_ref()
        .map(|s| buff_bar::resources(s, args["hide_empty"].as_bool().unwrap_or(true)));
    let deployed = e
        .parts
        .get("Actor")
        .and_then(|p| skills::read(&a.mem, *p).ok())
        .map(|actor| actor.deployed_ids)
        .unwrap_or_default();
    let totems = if deployed.is_empty() {
        Default::default()
    } else {
        buff_bar::totems(&deployed, &awake_entities(a, area)?)
    };
    Ok(json!({
        "buffs": buff_bar::entries(&buffs, watch, show_inactive),
        "resources": resources,
        "totems": totems,
    }))
}

/// The local player's entity with its parts and every part name.
fn player_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let at = entities::local_player(&a.mem, area_instance(a)?).map_err(|e| format!("{e:#}"))?;
    let e = entities::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    let buffs = match e.parts.get("Buffs") {
        Some(p) => entities::read_buffs(&a.mem, *p).map_err(|e| format!("{e:#}"))?,
        None => Vec::new(),
    };
    let actor = match e.parts.get("Actor") {
        Some(p) => Some(skills::read(&a.mem, *p).map_err(|e| format!("{e:#}"))?),
        None => None,
    };
    Ok(json!({
        "entity": e,
        "buffs": buffs,
        "actor": actor,
        "parts": e.parts.keys().collect::<Vec<_>>(),
    }))
}

/// The player's inventories with their items and prices.
fn inventories_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let wanted = args["name"].as_str();
    let all = inventory::list(&a.mem, area_instance(a)?).map_err(|e| format!("{e:#}"))?;
    let prices = PRICES.lock();
    let mut out = Vec::new();
    for (id, at) in all {
        if wanted.is_some_and(|w| !inventory::name(id).eq_ignore_ascii_case(w)) {
            continue;
        }
        let inv = match inventory::read(&a.mem, id, at) {
            Ok(inv) => inv,
            Err(e) => {
                out.push(json!({"id": id, "name": inventory::name(id), "error": format!("{e:#}")}));
                continue;
            }
        };
        let items: Vec<Json> = inv
            .items
            .iter()
            .map(|placed| match items::read(&a.mem, placed.item) {
                Ok(item) => json!({
                    "start": placed.start,
                    "end": placed.end,
                    "exalted": prices.as_ref().and_then(|(_, p)| p.stack(&item)),
                    "unique": prices.as_ref().and_then(|(_, p)| p.unique_name(&item.art)),
                    "item": item,
                }),
                Err(e) => {
                    json!({"start": placed.start, "end": placed.end, "error": format!("{e:#}")})
                }
            })
            .collect();
        out.push(json!({"id": inv.id, "name": inv.name, "boxes": inv.boxes, "items": items}));
    }
    Ok(json!({"inventories": out}))
}

/// The world to screen matrix, the game window's client area, and the
/// player's point on it (width and height override the window's size).
/// The camera matrix, the game window's client area and the screen size
/// to draw for (`width` and `height` given, else the window's).
type Screen = (camera::Matrix, Option<(i32, i32, i32, i32)>, (f32, f32));

fn screen(a: &Attached, args: &Json) -> Result<Screen, String> {
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let m = camera::matrix(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let window = modforge::input::find_hwnd_by_pid(a.pid).and_then(modforge::input::client_area);
    let (w, h) = window.map_or((1920, 1080), |(_, _, w, h)| (w, h));
    let size = (
        args["width"].as_f64().map_or(w as f32, |v| v as f32),
        args["height"].as_f64().map_or(h as f32, |v| v as f32),
    );
    Ok((m, window, size))
}

/// Each awake ritual wisp, whether the player is in its range, and its
/// range circle in world and screen positions.
fn ritual_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let (m, _, size) = screen(a, args)?;
    let player = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .map_err(|e| format!("player: {e:#}"))?
        .position
        .ok_or("player has no position")?;
    let all = awake_entities(a, area)?;
    let radius = args["radius_meters"]
        .as_f64()
        .map_or(ritual::RADIUS_METERS, |v| v as f32);
    let wisps: Vec<Json> = ritual::wisps(player, &all, radius)
        .into_iter()
        .map(|w| {
            let on_screen: Vec<_> = w
                .circle
                .iter()
                .map(|p| camera::world_to_screen(&m, p[0], p[1], p[2], size))
                .collect();
            json!({"wisp": w, "screen": on_screen})
        })
        .collect();
    Ok(json!({"player": player, "radius_meters": radius, "wisps": wisps}))
}

/// Every awake entity, read; unreadable ones are left out.
fn awake_entities(a: &Attached, area: u64) -> Result<Vec<entities::Entity>, String> {
    let addresses = entities::map_addresses(
        &a.mem,
        area + entities::AREA_AWAKE_ENTITIES,
        entities::MAX_AWAKE,
    )
    .map_err(|e| format!("{e:#}"))?;
    Ok(addresses
        .iter()
        .filter_map(|at| entities::read(&a.mem, *at).ok())
        .collect())
}

/// A health bar for each awake player and monster GameHelper2 would
/// draw one for, with its screen position (`leader` names the party
/// leader).
fn health_bars_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let (m, _, size) = screen(a, args)?;
    let me = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .map_err(|e| format!("player: {e:#}"))?;
    let settings = kinds::Settings {
        leader: args["leader"].as_str().unwrap_or_default().to_string(),
        ..kinds::Settings::default()
    };
    let bars: Vec<Json> = awake_entities(a, area)?
        .iter()
        .filter_map(|e| {
            let kind = kinds::classify(e, me.id, &settings)?;
            let b = health_bars::bar(e, &kind, args["mana_on_self"].as_bool() == Some(true))?;
            let [x, y, z] = b.anchor;
            let at = camera::world_to_screen(&m, x, y, z, size);
            Some(json!({"bar": b, "path": e.path, "screen": at}))
        })
        .collect();
    Ok(json!({"bars": bars}))
}

/// What GameHelper2 takes each awake entity for: type, subtype, state.
fn kinds_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let me = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .map_err(|e| format!("player: {e:#}"))?;
    let settings = kinds::Settings {
        leader: args["leader"].as_str().unwrap_or_default().to_string(),
        ..kinds::Settings::default()
    };
    let list: Vec<Json> = awake_entities(a, area)?
        .iter()
        .map(|e| json!({"id": e.id, "path": e.path, "kind": kinds::classify(e, me.id, &settings)}))
        .collect();
    Ok(json!({"entities": list}))
}

fn camera_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let (m, window, size) = screen(a, args)?;
    let player = entities::local_player(&a.mem, area_instance(a)?)
        .and_then(|at| entities::read(&a.mem, at))
        .ok()
        .and_then(|e| e.position)
        .map(|[x, y, z]| json!({"world": [x, y, z], "screen": camera::world_to_screen(&m, x, y, z, size)}));
    Ok(json!({"matrix": m, "window": window, "size": [size.0, size.1], "player": player}))
}

/// The zone's terrain, with the rotation tables from the game's code.
fn read_terrain(a: &Attached, area: u64) -> Result<terrain::Terrain, String> {
    let table = |name: &str, len: usize| -> Result<Vec<u8>, String> {
        a.mem
            .read_array(a.static_address(name)?, len)
            .map_err(|e| format!("read {name}: {e:#}"))
    };
    terrain::read(
        &a.mem,
        area,
        table("Terrain Rotation Selector", terrain::ROTATION_SELECTOR_LEN)?,
        table("Terrain Rotator Helper", terrain::ROTATOR_HELPER_LEN)?,
    )
    .map_err(|e| format!("{e:#}"))
}

/// The zone's points of interest from its tile files, each with the
/// walking path from the player (with `paths`), and with `files` every
/// tile key found.
fn radar_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let zone = zone::read(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let area = area_instance(a)?;
    let t = read_terrain(a, area)?;
    let files = radar::read_tile_files(&a.mem, &t);
    let lists = radar::Lists::gamehelper2().map_err(|e| format!("tile lists: {e}"))?;
    let player = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .ok()
        .and_then(|e| e.position)
        .map(|[x, y, _]| {
            let (cx, cy) = terrain::Terrain::cell_of(x, y);
            (cx as i32, cy as i32)
        });
    let with_paths = args["paths"].as_bool().unwrap_or(false);
    let points: Vec<Json> = radar::points(&files, &lists, &zone.id)
        .into_iter()
        .map(|p| {
            let route = with_paths
                .then_some(player)
                .flatten()
                .map(|from| radar::path(from, p.cell, |c| t.open(c)));
            json!({"kind": p.kind, "name": p.name, "cell": p.cell, "path": route})
        })
        .collect();
    Ok(json!({
        "zone": zone.id,
        "player_cell": player,
        "points": points,
        "tile_keys": files.len(),
        "files": args["files"].as_bool().unwrap_or(false).then_some(&files),
    }))
}

/// What the radar layer would draw now: each shape's kind and where,
/// with the large map's centre and zoom, for checking it without the
/// overlay.
fn radar_view_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let area = area_instance(a)?;
    let me = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .map_err(|e| format!("player: {e:#}"))?;
    let window = modforge::input::find_hwnd_by_pid(a.pid)
        .and_then(modforge::input::client_area)
        .ok_or("no game window")?;
    let size = (window.2 as f32, window.3 as f32);
    let shapes = radar_shapes(a, in_game, area, &me, size)?;
    Ok(json!({"window": [size.0, size.1], "shapes": shape_rows(&shapes)}))
}

/// What the atlas layer draws now (empty when the atlas is closed).
fn atlas_view_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let window = modforge::input::find_hwnd_by_pid(a.pid)
        .and_then(modforge::input::client_area)
        .ok_or("no game window")?;
    let size = (window.2 as f32, window.3 as f32);
    let shapes = atlas_shapes(a, in_game, size)?;
    Ok(json!({"window": [size.0, size.1], "shapes": shape_rows(&shapes)}))
}

/// Shapes as short rows for a research printout.
fn shape_rows(shapes: &[modforge::overlay::Shape]) -> Vec<Json> {
    use modforge::overlay::Shape;
    shapes
        .iter()
        .map(|s| match s {
            Shape::Image { corners, image } => {
                json!({"image": [image.width, image.height], "corners": corners})
            }
            Shape::Text { at, text, .. } => json!({"text": text, "at": at}),
            Shape::Path { points, .. } => {
                json!({"path": points.len(), "from": points.first(), "to": points.last()})
            }
            Shape::Rect { at, size, .. } => json!({"box": at, "size": size}),
            other => json!(format!("{other:?}")),
        })
        .collect()
}

/// The zone's terrain size and, at the player, the ground height and
/// walkable value.
fn terrain_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let area = area_instance(a)?;
    let t = read_terrain(a, area)?;
    let player = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .ok()
        .and_then(|e| e.position)
        .map(|[x, y, z]| {
            let (cx, cy) = terrain::Terrain::cell_of(x, y);
            json!({
                "world": [x, y, z],
                "cell": [cx, cy],
                "ground_height": t.height(cx, cy),
                "walkable": t.walkable(cx, cy),
            })
        });
    Ok(json!({
        "tiles": [t.tiles_x, t.tiles_y],
        "cells": t.cells(),
        "height_multiplier": t.height_multiplier,
        "bytes_per_row": t.bytes_per_row,
        "player": player,
    }))
}

/// Which important panels are open, and with depth > 0 the UI tree
/// from the root (or from `at`).
fn ui_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let (manager, controller) = ui_manager(a)?;
    let panels: Vec<Json> = ui::panels(&a.mem, manager, controller)
        .into_iter()
        .map(|(name, found)| match found {
            Some((at, shown)) => json!({"name": name, "address": at, "visible": shown}),
            None => json!({"name": name, "address": null, "visible": false}),
        })
        .collect();
    let depth = args["depth"].as_u64().unwrap_or(0) as usize;
    let tree = if depth == 0 {
        Vec::new()
    } else {
        let from = match args["at"].as_u64() {
            Some(at) => at,
            None => ui::root(&a.mem, manager).map_err(|e| format!("{e:#}"))?,
        };
        let max = args["max"].as_u64().unwrap_or(2000) as usize;
        ui::walk(&a.mem, from, depth, max)
    };
    Ok(json!({
        "manager": manager,
        "controller_mode": controller,
        "panels": panels,
        "tree": tree,
    }))
}

/// The atlas map nodes, while the atlas shows.
fn atlas_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let (manager, controller) = ui_manager(a)?;
    let Some(at) = ui::panel(&a.mem, manager, controller, "atlas") else {
        return Ok(json!({"open": false, "reason": "no atlas panel"}));
    };
    if !ui::is_visible(&a.mem, at).map_err(|e| format!("{e:#}"))? {
        return Ok(json!({"open": false, "address": at}));
    }
    let atlas = atlas::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    let given: Vec<&str> = args["targets"]
        .as_array()
        .map(|v| v.iter().filter_map(Json::as_str).collect())
        .unwrap_or_default();
    let targets: &[&str] = if given.is_empty() {
        &atlas_routes::TOWERS
    } else {
        &given
    };
    let max_hops = args["max_hops"]
        .as_u64()
        .map_or(atlas_routes::MAX_HOPS, |v| v as usize);
    let names = atlas_routes::names();
    let shown: Vec<&str> = atlas
        .nodes
        .iter()
        .map(|n| atlas_routes::display_name(&names, &n.map_id))
        .collect();
    Ok(json!({
        "open": true,
        "atlas": atlas,
        "names": shown,
        "routes": atlas_routes::routes(&atlas, targets, max_hops),
    }))
}

/// The UI manager from the in-game state, and whether it is the
/// controller one.
fn ui_manager(a: &Attached) -> Result<(u64, bool), String> {
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    ui::manager(&a.mem, in_game).map_err(|e| format!("{e:#}"))
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

/// Read-only bytes for offset research (modforge memory_research).
fn read_bytes_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    modforge::memory_research::read_bytes_reply(&a.mem, args)
}

/// Every match of `sig` in the exe's code and where its operand points
/// (modforge memory_research), for finding a moved global.
fn rip_sites_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let image = read_process_image(&a.mem, &a.exe).map_err(|e| format!("read exe image: {e:#}"))?;
    let exe = a.exe.base..a.exe.base + a.exe.size;
    modforge::memory_research::rip_sites_reply(&image, &exe, args)
}

/// How many loaded files carry each area change count: the newest count
/// is the area change counter's value now.
fn file_counts_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let counts = std::cell::RefCell::new(std::collections::BTreeMap::<i32, usize>::new());
    let (_, unreadable) = files::loaded_files(&a.mem, a.static_address("File Root")?, |c| {
        *counts.borrow_mut().entry(c).or_insert(0) += 1;
        false
    })
    .map_err(|e| format!("{e:#}"))?;
    let counts = counts.into_inner();
    let newest: Vec<_> = counts.iter().rev().take(8).collect();
    Ok(json!({"distinct": counts.len(), "newest": newest, "unreadable": unreadable}))
}

/// The game's text (std::wstring) at `addr`, or why it is not one.
fn wstring_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    modforge::memory_research::wstring_reply(&a.mem, args)
}

/// The roots offset research starts from: InGameState, its area
/// instance and world data pointers at GameHelper2's offsets.
fn roots_op(_args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let in_game = s.get("InGameState").ok_or("no InGameState")?;
    let read = |off: u64| a.mem.read_value::<u64>(in_game + off).unwrap_or(0);
    Ok(json!({
        "in_game_state": format!("{in_game:#x}"),
        "area_instance": format!("{:#x}", read(zone::IN_GAME_AREA_INSTANCE)),
        "world_data": format!("{:#x}", read(zone::IN_GAME_WORLD_DATA)),
        "exe": [format!("{:#x}", a.exe.base), format!("{:#x}", a.exe.base + a.exe.size)],
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

/// One ground item label as pickup sees it.
struct LabelRow {
    label: ground_labels::Label,
    visible: bool,
    /// On the screen, the game window's client area added.
    screen: Option<[f32; 4]>,
    item: Option<model::Item>,
    exalted: Option<f64>,
    candidate: Option<pickup::Candidate>,
}

/// Every ground item label joined with its item (by entity id among the
/// awake entities), its distance from the player in grid cells, its
/// rectangle on the screen and the first rule in `rules` it passes.
fn label_rows(a: &Attached, rules: &[item_rules::ItemRule]) -> Result<Vec<LabelRow>, String> {
    let (manager, _) = ui_manager(a)?;
    let Some(at) = ui::child_path(&a.mem, manager, &ground_labels::PATH) else {
        return Ok(Vec::new());
    };
    let labels = ground_labels::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    if labels.is_empty() {
        return Ok(Vec::new());
    }
    let area = area_instance(a)?;
    let player = entities::local_player(&a.mem, area)
        .and_then(|p| entities::read(&a.mem, p))
        .map_err(|e| format!("{e:#}"))?;
    let addresses = entities::map_addresses(
        &a.mem,
        area + entities::AREA_AWAKE_ENTITIES,
        entities::MAX_AWAKE,
    )
    .map_err(|e| format!("{e:#}"))?;
    let mut ground: std::collections::HashMap<u32, (u64, model::Item, Option<[f32; 3]>)> =
        std::collections::HashMap::new();
    for at in addresses {
        let Ok(e) = entities::read(&a.mem, at) else {
            continue;
        };
        let Some(world_item) = e.parts.get("WorldItem") else {
            continue;
        };
        if let Ok(item) = items::on_ground(&a.mem, *world_item) {
            ground.insert(e.id, (e.address, item, e.position));
        }
    }
    let cull: i32 = a
        .mem
        .read_value(a.static_address("GameCullSize")?)
        .map_err(|e| format!("read cull size: {e}"))?;
    let window = modforge::input::find_hwnd_by_pid(a.pid).and_then(modforge::input::client_area);
    let (left, top, w, h) = window.unwrap_or((0, 0, 0, 0));
    let scale = slots::Scale::new(w as f32, h as f32, cull);
    let prices = PRICES.lock();
    let cell = terrain::world_per_cell();
    let rows = labels
        .into_iter()
        .map(|label| {
            let visible = ui::is_visible(&a.mem, label.element).unwrap_or(false);
            let screen = slots::absolute_rect(&a.mem, label.element, &scale)
                .map(|r| [r.x + left as f32, r.y + top as f32, r.w, r.h]);
            let found = ground.get(&label.id);
            let item = found.map(|f| f.1.clone());
            let exalted = item
                .as_ref()
                .and_then(|i| prices.as_ref().and_then(|(_, p)| p.stack(i)));
            let candidate = match (found, screen, player.position) {
                (Some((key, item, Some(pos))), Some(rect), Some(me)) if visible => {
                    Some(pickup::Candidate {
                        key: *key,
                        name: if item.name.is_empty() { item.base.clone() } else { item.name.clone() },
                        distance: (pos[0] - me[0]).hypot(pos[1] - me[1]) / cell,
                        label: rect,
                        rule: rules
                            .iter()
                            .find(|r| r.matches(item, exalted))
                            .map(|r| r.name.clone()),
                    })
                }
                _ => None,
            };
            LabelRow {
                label,
                visible,
                screen,
                item,
                exalted,
                candidate,
            }
        })
        .collect();
    Ok(rows)
}

/// The ground item labels with their items, screen rectangles,
/// distances and the rule each passes (the first pickup rules when
/// none are given).
fn ground_labels_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let rules: Vec<item_rules::ItemRule> = if args["rules"].is_null() {
        pickup::default_rules()
    } else {
        parse(args, "rules")?
    };
    let rows = label_rows(a, &rules)?;
    let out: Vec<Json> = rows
        .iter()
        .map(|r| {
            json!({
                "element": r.label.element,
                "id": r.label.id,
                "visible": r.visible,
                "screen": r.screen,
                "item": r.item,
                "exalted": r.exalted,
                "candidate": r.candidate,
            })
        })
        .collect();
    Ok(json!({"labels": out}))
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
    let (league, mut out) = judge(&items, args)?;
    for (o, p) in out.iter_mut().zip(positions) {
        o["position"] = json!(p);
    }
    Ok(json!({
        "league": league,
        "unreadable": unreadable,
        "items": out,
    }))
}

/// Each item with its unique name, its stack's price and the first
/// rule in `rules` it passes; and the league the prices are for.
fn judge(items: &[model::Item], args: &Json) -> Result<(Option<String>, Vec<Json>), String> {
    let rules: Vec<item_rules::ItemRule> = if args["rules"].is_null() {
        Vec::new()
    } else {
        parse(args, "rules")?
    };
    let prices = PRICES.lock();
    let stack = |item: &model::Item| prices.as_ref().and_then(|(_, p)| p.stack(item));
    let matched: std::collections::HashMap<usize, &str> =
        item_rules::matching(&rules, items, stack)
            .into_iter()
            .collect();
    let out = items
        .iter()
        .enumerate()
        .map(|(i, item)| {
            json!({
                "item": item,
                "unique": prices.as_ref().and_then(|(_, p)| p.unique_name(&item.art)),
                "exalted": stack(item),
                "rule": matched.get(&i),
            })
        })
        .collect();
    Ok((prices.as_ref().map(|(l, _)| l.clone()), out))
}

/// The items shown in an open panel (GameHelper2 LootValue's slot
/// scan): the left panel (stash), the right panel (inventory, vendor)
/// or the ritual rewards, each priced and matched against `rules`.
fn panel_items_op(args: &Json) -> Result<Json, String> {
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let (manager, controller) = ui_manager(a)?;
    let which = args["panel"].as_str().unwrap_or("left_panel");
    let at = if which == "ritual" {
        ui::child_path(&a.mem, manager, &slots::RITUAL_REWARD_GRID)
    } else {
        ui::panel(&a.mem, manager, controller, which)
    };
    let Some(at) = at else {
        return Ok(json!({"panel": which, "open": false, "reason": "no such panel"}));
    };
    if !ui::is_visible(&a.mem, at).map_err(|e| format!("{e:#}"))? {
        return Ok(json!({"panel": which, "open": false, "address": at}));
    }
    let cull: i32 = a
        .mem
        .read_value(a.static_address("GameCullSize")?)
        .map_err(|e| format!("read cull size: {e}"))?;
    let window = modforge::input::find_hwnd_by_pid(a.pid).and_then(modforge::input::client_area);
    let (w, h) = window.map_or((0, 0), |(_, _, w, h)| (w, h));
    let scale = slots::Scale::new(w as f32, h as f32, cull);
    let area = slots::absolute_rect(&a.mem, at, &scale).ok_or("panel has no rectangle")?;
    let exe = a.exe.base..a.exe.base + a.exe.size;
    let (found, report) = slots::scan(&a.mem, at, area, &scale, &exe);
    let items: Vec<model::Item> = found.iter().map(|s| s.item.clone()).collect();
    let (league, mut out) = judge(&items, args)?;
    for (o, s) in out.iter_mut().zip(&found) {
        o["address"] = json!(s.address);
        o["rect"] = json!(s.rect);
        o["scroll"] = json!(s.scroll);
    }
    Ok(json!({
        "panel": which,
        "open": true,
        "address": at,
        "area": area,
        "scale": scale,
        "window": window,
        "league": league,
        "report": report,
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

/// What the overlay draws.
#[derive(Clone, Copy, Debug)]
struct Layers {
    zone: bool,
    player: bool,
    items: bool,
    health_bars: bool,
    ritual: bool,
    buffs: bool,
    mana_on_self: bool,
    radar: bool,
    atlas: bool,
}

/// What the radar keeps for one zone instance (Radar.GenerateMapTexture
/// runs once per area, paths every PathRecomputeIntervalMs).
struct RadarZone {
    hash: u32,
    terrain: terrain::Terrain,
    picture: Option<std::sync::Arc<modforge::overlay::Image>>,
    /// Name, cell, and whether the radar draws a path to it.
    labels: Vec<(String, modforge::path::Cell, bool)>,
    paths: Vec<Option<Vec<modforge::path::Cell>>>,
    reached: std::collections::HashSet<usize>,
    paths_at: Option<std::time::Instant>,
    /// Paths to the abyss nodes shown, in [`abyss::Tracked::shown`]
    /// order.
    abyss_paths: Vec<Option<Vec<modforge::path::Cell>>>,
    abyss_scan_at: Option<std::time::Instant>,
}

static RADAR: Mutex<Option<RadarZone>> = Mutex::new(None);

/// Abyss nodes by zone hash (Radar.trackedNodesByArea), so a trip to
/// town and back keeps them.
static ABYSS: Mutex<Option<std::collections::HashMap<u32, abyss::Tracked>>> = Mutex::new(None);

/// RebuildTrackedNodes: record every awake and sleeping crack and pit.
fn scan_abyss(a: &Attached, area: u64, t: &mut abyss::Tracked) {
    for (map, max) in [
        (entities::AREA_AWAKE_ENTITIES, entities::MAX_AWAKE),
        (entities::AREA_SLEEPING_ENTITIES, entities::MAX_SLEEPING),
    ] {
        let Ok(addresses) = entities::map_addresses(&a.mem, area + map, max) else {
            continue;
        };
        for at in addresses {
            let wanted = entities::read_parts(&a.mem, at)
                .is_ok_and(|(path, _)| abyss::classify(&path).is_some());
            if wanted && let Ok(e) = entities::read(&a.mem, at) {
                t.record(&e);
            }
        }
    }
}

/// The radar's shapes over the large map, when it is open and the world
/// map is not.
fn radar_shapes(
    a: &Attached,
    in_game: u64,
    area: u64,
    me: &entities::Entity,
    size: (f32, f32),
) -> Result<Vec<modforge::overlay::Shape>, String> {
    let (manager, controller) = ui::manager(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let shown = |name: &str| {
        ui::panel(&a.mem, manager, controller, name)
            .filter(|p| ui::is_visible(&a.mem, *p).unwrap_or(false))
    };
    let Some(large) = shown("large_map") else {
        return Ok(Vec::new());
    };
    if shown("world_map").is_some() {
        return Ok(Vec::new());
    }
    let cull: i32 = a
        .mem
        .read_value(a.static_address("GameCullSize")?)
        .map_err(|e| format!("read cull size: {e}"))?;
    let scale = slots::Scale::new(size.0, size.1, cull);
    let map = radar::read_large_map(&a.mem, large, &scale).ok_or("large map unreadable")?;
    let view = radar::MapView::large_map(&map, size.1);
    let zone = zone::read(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let mut cache = RADAR.lock();
    if cache.as_ref().map(|c| c.hash) != Some(zone.hash) {
        let t = read_terrain(a, area)?;
        let files = radar::read_tile_files(&a.mem, &t);
        let lists = radar::Lists::gamehelper2().map_err(|e| format!("tile lists: {e}"))?;
        let labels: Vec<_> = radar::points(&files, &lists, &zone.id)
            .into_iter()
            .map(|p| (p.name, p.cell, p.kind == radar::Kind::Important))
            .collect();
        *cache = Some(RadarZone {
            hash: zone.hash,
            picture: radar::walkable_picture(&t, draw::WALKABLE_MAP).map(std::sync::Arc::new),
            terrain: t,
            paths: vec![None; labels.len()],
            labels,
            reached: Default::default(),
            paths_at: None,
            abyss_paths: Vec::new(),
            abyss_scan_at: None,
        });
    }
    let z = cache.as_mut().ok_or("no radar zone")?;
    let Some([x, y, _]) = me.position else {
        return Ok(Vec::new());
    };
    let w = terrain::world_per_cell();
    let player = [x / w, y / w];
    let player_cell = (player[0] as i32, player[1] as i32);
    let player_height = me.terrain_height.unwrap_or(0.0);
    // MarkReachedIfClose: a path ends once the player gets near.
    for (i, (_, cell, with_path)) in z.labels.iter().enumerate() {
        let d = (cell.0 as f32 - player[0]).hypot(cell.1 as f32 - player[1]);
        if *with_path && d <= radar::REACHED_DISTANCE {
            z.reached.insert(i);
        }
    }
    let due = z.paths_at.is_none_or(|t| {
        t.elapsed() >= std::time::Duration::from_millis(radar::PATH_RECOMPUTE_MS)
    });
    if due {
        let t = &z.terrain;
        for (i, (_, cell, with_path)) in z.labels.iter().enumerate() {
            z.paths[i] = (*with_path && !z.reached.contains(&i))
                .then(|| radar::path(player_cell, *cell, |c| t.open(c)))
                .flatten();
        }
        z.paths_at = Some(std::time::Instant::now());
    }
    let height = |c: modforge::path::Cell| {
        let (Ok(x), Ok(y)) = (usize::try_from(c.0), usize::try_from(c.1)) else {
            return 0.0;
        };
        z.terrain.height(x, y).unwrap_or(0.0)
    };
    let labels: Vec<draw::RadarLabel> = z
        .labels
        .iter()
        .map(|(name, cell, _)| draw::RadarLabel {
            name,
            cell: [cell.0 as f32, cell.1 as f32],
            height: height(*cell),
        })
        .collect();
    // Colours go round the points that can have a path, in order.
    let paths: Vec<_> = z
        .labels
        .iter()
        .zip(&z.paths)
        .filter(|((_, _, with_path), _)| *with_path)
        .map(|(_, p)| {
            p.as_ref().map(|cells| {
                cells
                    .iter()
                    .map(|c| ([c.0 as f32, c.1 as f32], height(*c)))
                    .collect()
            })
        })
        .collect();
    let mut shapes = draw::radar(
        &view,
        player,
        player_height,
        z.picture.as_ref(),
        &labels,
        &paths,
    );
    // Abyss nodes: scanned once a second, retired when reached, a path
    // to each shown one with the other paths.
    let mut all_abyss = ABYSS.lock();
    let tracked = all_abyss
        .get_or_insert_with(Default::default)
        .entry(z.hash)
        .or_default();
    let scan_due = z.abyss_scan_at.is_none_or(|t| {
        t.elapsed() >= std::time::Duration::from_millis(abyss::SCAN_MS)
    });
    if scan_due {
        scan_abyss(a, area, tracked);
        z.abyss_scan_at = Some(std::time::Instant::now());
    }
    tracked.retire_near(player, radar::REACHED_DISTANCE);
    let shown: Vec<abyss::Node> = tracked.shown().copied().collect();
    if due || z.abyss_paths.len() != shown.len() {
        let t = &z.terrain;
        z.abyss_paths = shown
            .iter()
            .map(|n| {
                let to = (n.cell[0] as i32, n.cell[1] as i32);
                radar::path(player_cell, to, |c| t.open(c))
            })
            .collect();
    }
    let marks: Vec<_> = shown
        .iter()
        .zip(&z.abyss_paths)
        .map(|(n, p)| {
            let cells = p.as_ref().map(|cells| {
                cells
                    .iter()
                    .map(|c| ([c.0 as f32, c.1 as f32], height(*c)))
                    .collect()
            });
            (n.cell, n.height, cells)
        })
        .collect();
    shapes.extend(draw::radar_marks(
        &view,
        player,
        player_height,
        &marks,
        abyss::PATH_COLOR,
    ));
    Ok(shapes)
}

/// The atlas's shapes while the atlas is open (Atlas2.DrawUI): every
/// map's label at its node element's centre and a route to each tower.
fn atlas_shapes(
    a: &Attached,
    in_game: u64,
    size: (f32, f32),
) -> Result<Vec<modforge::overlay::Shape>, String> {
    let (manager, controller) = ui::manager(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let Some(at) = ui::panel(&a.mem, manager, controller, "atlas")
        .filter(|p| ui::is_visible(&a.mem, *p).unwrap_or(false))
    else {
        return Ok(Vec::new());
    };
    let atlas = atlas::read(&a.mem, at).map_err(|e| format!("{e:#}"))?;
    let cull: i32 = a
        .mem
        .read_value(a.static_address("GameCullSize")?)
        .map_err(|e| format!("read cull size: {e}"))?;
    let scale = slots::Scale::new(size.0, size.1, cull);
    let names = atlas_routes::names();
    let centres: std::collections::HashMap<[i32; 2], [f32; 2]> = atlas
        .nodes
        .iter()
        .filter_map(|n| {
            let r = slots::absolute_rect(&a.mem, n.address, &scale)?;
            Some((n.grid, [r.x + r.w * 0.5, r.y + r.h * 0.5]))
        })
        .collect();
    let nodes: Vec<draw::AtlasNode> = atlas
        .nodes
        .iter()
        .filter_map(|n| {
            Some(draw::AtlasNode {
                name: atlas_routes::display_name(&names, &n.map_id),
                centre: *centres.get(&n.grid)?,
                done: n.state == atlas::NodeState::Done,
                biome: n.biome,
                content: &n.content,
            })
        })
        .collect();
    let towers = draw::MAP_GROUPS
        .iter()
        .find(|g| g.name == "Towers")
        .ok_or("no towers group")?;
    let color = draw::most_colorful(towers.font, towers.background);
    let routes = atlas_routes::routes(&atlas, towers.maps, atlas_routes::MAX_HOPS);
    let routes: Vec<draw::AtlasRoute> = routes
        .iter()
        .map(|r| draw::AtlasRoute {
            name: &r.name,
            hops: r.hops,
            points: r.path.iter().filter_map(|g| centres.get(g).copied()).collect(),
            color,
        })
        .collect();
    Ok(draw::atlas(&nodes, &routes, size))
}

/// One overlay frame from the game: over the game window's client
/// area, every layer turned on. An empty frame when the window is not
/// found or the player is not in a zone.
fn overlay_frame(layers: &Layers) -> Result<modforge::overlay::Frame, String> {
    use modforge::overlay::Frame;
    let guard = attached()?;
    let a = guard.as_ref().ok_or("not attached")?;
    let Some(hwnd) = modforge::input::find_hwnd_by_pid(a.pid) else {
        return Ok(Frame::default());
    };
    let Some(window) = modforge::input::client_area(hwnd) else {
        return Ok(Frame::default());
    };
    let size = (window.2 as f32, window.3 as f32);
    let mut frame = Frame {
        area: window,
        shapes: Vec::new(),
    };
    let s = states::read(&a.mem, a.static_address("Game States")?).map_err(|e| format!("{e:#}"))?;
    let Some(in_game) = s.get("InGameState") else {
        return Ok(frame);
    };
    if s.current_name() != Some("InGameState") {
        return Ok(frame);
    }
    if layers.zone
        && let Ok(z) = zone::read(&a.mem, in_game)
    {
        frame
            .shapes
            .push(draw::zone_line(&z.name, Some(i32::from(z.level))));
    }
    let m = camera::matrix(&a.mem, in_game).map_err(|e| format!("{e:#}"))?;
    let to_screen = |[x, y, z]: [f32; 3]| camera::world_to_screen(&m, x, y, z, size);
    let area = area_instance(a)?;
    let me = entities::local_player(&a.mem, area)
        .and_then(|at| entities::read(&a.mem, at))
        .map_err(|e| format!("player: {e:#}"))?;
    if layers.radar {
        // Under everything else, as the map is.
        frame
            .shapes
            .extend(radar_shapes(a, in_game, area, &me, size).unwrap_or_default());
    }
    if layers.atlas {
        frame
            .shapes
            .extend(atlas_shapes(a, in_game, size).unwrap_or_default());
    }
    if layers.player
        && let Some(at) = me.position.and_then(to_screen)
    {
        frame.shapes.push(draw::player_mark(at));
    }
    // ResolveHealthBarAnchor: the top of the player's model.
    let head = me
        .position
        .map(|[x, y, z]| [x, y, z - me.model_bounds.map_or(0.0, |b| b[2])])
        .and_then(to_screen);
    if layers.buffs
        && let Some(head) = head
    {
        if let Some(s) = &me.stats {
            frame
                .shapes
                .extend(draw::resource_row(&buff_bar::resources(s, true), head));
        }
        let buffs = player_buffs(a, &me)?;
        let row = buff_bar::entries(&buffs, &buff_bar::DEFAULT_WATCHLIST, true);
        frame.shapes.extend(draw::buff_row(&row, head));
    }
    let all = awake_entities(a, area)?;
    if layers.health_bars {
        let settings = kinds::Settings::default();
        for e in &all {
            let Some(kind) = kinds::classify(e, me.id, &settings) else {
                continue;
            };
            let Some(b) = health_bars::bar(e, &kind, layers.mana_on_self) else {
                continue;
            };
            if let Some(at) = to_screen(b.anchor) {
                frame.shapes.extend(draw::health_bar(&b, at));
            }
        }
    }
    if layers.ritual
        && let Some(player) = me.position
    {
        for w in ritual::wisps(player, &all, ritual::RADIUS_METERS) {
            let ring: Vec<_> = w.circle.iter().map(|p| to_screen(*p)).collect();
            frame.shapes.extend(draw::wisp(w.inside, &ring));
        }
    }
    if layers.items {
        let prices = PRICES.lock();
        for e in &all {
            let Some(world_item) = e.parts.get("WorldItem") else {
                continue;
            };
            let (Ok(item), Some(at)) = (
                items::on_ground(&a.mem, *world_item),
                e.position.and_then(to_screen),
            ) else {
                continue;
            };
            let list = prices.as_ref().map(|(_, p)| p);
            let unique = list.and_then(|p| p.unique_name(&item.art));
            let name = match unique {
                Some(u) => u.to_string(),
                None if !item.base.is_empty() => item.base.clone(),
                None => loot_value::file_basename(&item.path).to_string(),
            };
            let exalted = list.and_then(|p| p.stack(&item));
            frame
                .shapes
                .push(draw::item_label(&name, exalted, false, at));
        }
    }
    Ok(frame)
}

/// The running overlay and the thread that feeds it.
struct OverlayRun {
    overlay: std::sync::Arc<modforge::overlay::Overlay>,
    stop: std::sync::Arc<std::sync::atomic::AtomicBool>,
    feeder: std::thread::JoinHandle<()>,
}

static OVERLAY: Mutex<Option<OverlayRun>> = Mutex::new(None);

/// Start (on: true) or stop (on: false) the overlay over the game. It
/// reads the game `fps` times a second and draws the layers asked for.
fn overlay_op(args: &Json) -> Result<Json, String> {
    use std::sync::Arc;
    use std::sync::atomic::{AtomicBool, Ordering};
    let mut run = OVERLAY.lock();
    if let Some(r) = run.take() {
        r.stop.store(true, Ordering::Release);
        let _ = r.feeder.join();
        drop(r.overlay);
    }
    if args["on"].as_bool() == Some(false) {
        return Ok(json!({"on": false}));
    }
    let layer = |name: &str| args[name].as_bool().unwrap_or(true);
    let layers = Layers {
        zone: layer("zone"),
        player: layer("player"),
        items: layer("items"),
        health_bars: layer("health_bars"),
        ritual: layer("ritual"),
        buffs: layer("buffs"),
        mana_on_self: args["mana_on_self"].as_bool() == Some(true),
        radar: layer("radar"),
        atlas: layer("atlas"),
    };
    let fps = args["fps"].as_u64().unwrap_or(20).clamp(1, 60) as u32;
    let overlay = Arc::new(modforge::overlay::Overlay::start("poe2-mod overlay", fps)?);
    let stop = Arc::new(AtomicBool::new(false));
    let (o, s) = (overlay.clone(), stop.clone());
    let feeder = std::thread::Builder::new()
        .name("overlay feeder".into())
        .spawn(move || {
            let period = std::time::Duration::from_millis(1000 / u64::from(fps));
            while !s.load(Ordering::Acquire) {
                // A frame that fails to read clears the screen.
                o.show(overlay_frame(&layers).unwrap_or_default());
                std::thread::sleep(period);
            }
        })
        .map_err(|e| format!("overlay feeder: {e}"))?;
    let hwnd = overlay.hwnd();
    *run = Some(OverlayRun {
        overlay,
        stop,
        feeder,
    });
    Ok(json!({"on": true, "fps": fps, "window": hwnd, "layers": format!("{layers:?}")}))
}

fn main() {
    OP_REGISTRY.register(OpDef::new(
        "overlay",
        "on: true draws over the game (zone, player, ground items with prices, health bars, ritual range, buff bar, radar on the large map) in a click-through window; on: false closes it",
        "on, fps?, zone?, player?, items?, health_bars?, ritual?, buffs?, mana_on_self?, radar?",
        overlay_op,
    ));
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
        "ground_labels",
        "the ground item labels: each one's item, screen rectangle, distance from the player and the pickup rule it passes (the first pickup rules unless rules are given)",
        "rules?",
        ground_labels_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "panel_items",
        "the items shown in an open panel (left_panel: stash, right_panel: inventory or vendor, ritual: rewards), priced and matched against the rules, like GameHelper2 LootValue's slot scan",
        "panel?, rules?",
        panel_items_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "preload",
        "the preloads found in this area's loaded files: read from the game, or the given files and area change counter",
        "list | defs, files?, area_change_counter?",
        preload_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "patterns.read_bytes",
        "read-only: n bytes (at most 4096) at addr as hex, for offset research",
        "addr, n",
        read_bytes_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "inspect",
        "inspector: one entity (awake id, addr, or the player) with every part's address and what is read, and a part's words",
        "id? | addr?, part?, n?",
        inspect_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "radar_view",
        "what the radar layer draws now over the large map (empty when it is closed)",
        "",
        radar_view_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "atlas_view",
        "what the atlas layer draws now: map labels and tower routes (empty when the atlas is closed)",
        "",
        atlas_view_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "patterns.rip_sites",
        "read-only: every match of sig in the exe's code, its operand address and where it points",
        "sig",
        rip_sites_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "file_counts",
        "how many loaded files carry each area change count, newest first",
        "",
        file_counts_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "mem.wstring",
        "read-only: the game's text (std::wstring) at addr",
        "addr",
        wstring_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "roots",
        "InGameState and its area instance and world data pointers, where offset research starts",
        "",
        roots_op,
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
        "the local player: name, level, life, mana, energy shield, position, buffs and charges, skills with cooldowns, deployed counts, and its part names",
        "",
        player_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "inventories",
        "the player's inventories (or the one named) with each item, its boxes and its price from the kept prices",
        "name?",
        inventories_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "ui",
        "which important UI panels are open; depth > 0 adds the UI tree from the root or from at",
        "depth?, at?, max?",
        ui_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "camera",
        "the world to screen matrix, the game window's client area, and the player's world and screen point (width and height override the size)",
        "width?, height?",
        camera_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "terrain",
        "the zone's terrain size and the ground height and walkable value at the player",
        "",
        terrain_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "radar",
        "the zone's points of interest from its tile files (important places, boss arenas, stairs, temples, runestones); paths: walking path from the player to each; files: every tile key",
        "paths?, files?",
        radar_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "buff_bar",
        "the player buff bar: watched buffs with stacks and time left, charges and rage, own totems",
        "watch?, show_inactive?, hide_empty?",
        buff_bar_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "kinds",
        "what each awake entity is, by GameHelper2's rules: type, subtype, state",
        "leader?",
        kinds_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "health_bars",
        "a health bar for each awake player and monster: style, health and ward percent, shield or mana, cull range, screen position",
        "leader?, width?, height?",
        health_bars_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "ritual",
        "each awake ritual wisp, whether the player is in its range, and the range circle in world and screen positions",
        "radius_meters?, width?, height?",
        ritual_op,
    ));
    OP_REGISTRY.register(OpDef::new(
        "atlas",
        "while the atlas shows: each map node's id, name, state (locked, open, done), grid, links, content and effect lines, and the shortest routes from open maps to the target maps (towers by default)",
        "targets?, max_hops?",
        atlas_op,
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

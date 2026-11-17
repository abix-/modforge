//! The game as the mod reads it, inside the game on Godot's main
//! thread: the hero, the floor's guardian, every owned piece and the
//! equipment grid. One place for every step that judges (operator
//! 2026-11-16: "DRY functionality in the mod itself"). Callers run
//! these inside `on_main`.

use std::sync::Mutex;

use godot::builtin::{AnyArray, AnyDictionary, Variant, Vector2i};
use godot::classes::{Node, Object};
use godot::meta::ToGodot;
use godot::obj::Gd;
use godotforge::godot4::{ops::script_vars, target};

use crate::fight::{self, Fighter};
use crate::grid;
use crate::items::stats_from;

/// inventory.gd grids.
pub const EQUIP: i64 = 0;
pub const BAG: i64 = 1;
pub const TRAY: i64 = 2;
/// The mega forge's anvil.
pub const FORGE: i64 = 3;

/// The scene the game swaps its screens under.
pub const SCENE: &str = "/root/@Control@65/CurrentScene";

pub fn call(o: &mut Gd<Object>, method: &str, args: &[Variant]) -> Result<Variant, String> {
    o.try_call(method, args)
        .map_err(|e| format!("{method}: {e}"))
}

pub fn node(path: &str) -> Result<Gd<Object>, String> {
    Ok(target::node_by_path(path)?.upcast())
}

/// An object held in a property.
pub fn held(o: &Gd<Object>, property: &str) -> Result<Gd<Object>, String> {
    o.get(property)
        .try_to::<Gd<Object>>()
        .map_err(|_| format!("no {property}"))
}

fn num_or(v: &Variant, or: f64) -> f64 {
    v.try_to::<f64>()
        .or_else(|_| v.try_to::<i64>().map(|i| i as f64))
        .unwrap_or(or)
}

fn int(v: &Variant) -> i64 {
    v.try_to::<i64>().unwrap_or(0)
}

/// The first node under `under`, `depth` levels down, whose script
/// path ends with `script`.
pub fn find(under: &Gd<Node>, script: &str, depth: u32) -> Option<Gd<Node>> {
    for c in under.get_children().iter_shared() {
        if target::script_path(&c.clone().upcast()).is_some_and(|s| s.ends_with(script)) {
            return Some(c);
        }
        if depth > 1
            && let Some(n) = find(&c, script, depth - 1)
        {
            return Some(n);
        }
    }
    None
}

/// The crawl screen (crawl.gd).
pub fn crawl() -> Result<Gd<Node>, String> {
    find(&target::node_by_path(SCENE)?, "/crawl.gd", 2).ok_or_else(|| "no crawl screen".into())
}

/// The hero at full hp (game_state.gd current_run.player).
pub fn player() -> Result<Fighter, String> {
    let run = held(&node("/root/Global")?, "current_run")?;
    let player = held(&run, "player")?;
    let mut me = fight::from_vars("Player", &script_vars(&player, 0));
    me.hp = me.max_hp;
    me.block = me.block_max;
    Ok(me)
}

/// The last guardian read, for when none is prepared (just fought).
static LAST_GUARDIAN: Mutex<Option<Fighter>> = Mutex::new(None);

/// The floor's guardian as the game builds it (combat_resolver.gd
/// _guardian, scaled by the floor and dungeon). When none is prepared
/// yet, the last one read. Mine: that fallback; the auto-player used
/// the strongest foe of the last fight.
pub fn guardian() -> Result<Fighter, String> {
    match guardian_now() {
        Ok(g) => {
            *LAST_GUARDIAN.lock().unwrap_or_else(|e| e.into_inner()) = Some(g.clone());
            Ok(g)
        }
        Err(e) => LAST_GUARDIAN
            .lock()
            .unwrap_or_else(|e| e.into_inner())
            .clone()
            .ok_or(e),
    }
}

fn guardian_now() -> Result<Fighter, String> {
    let resolver: Gd<Object> = find(&crawl()?, "combat_resolver.gd", 1)
        .ok_or("no combat resolver")?
        .upcast();
    let mut resolver = resolver;
    let data = resolver
        .get("_guardian")
        .try_to::<Gd<Object>>()
        .map_err(|_| "no guardian prepared yet".to_string())?;
    let run = held(&resolver, "run")?;
    if run.get("is_roguelite").try_to::<bool>().unwrap_or(false) {
        return Err("guardian build is campaign only".into());
    }
    let floor = int(&run.get("floor_number")).max(1);
    let mut db = node("/root/DungeonDB")?;
    let dungeon = call(&mut db, "floor_dungeon", &[run.to_variant()])?
        .try_to::<Gd<Object>>()
        .map_err(|_| "no dungeon".to_string())?;
    let floor_scale = num_or(
        &call(&mut resolver, "_floor_scale", &[dungeon.to_variant()])?,
        1.0,
    );
    let hp_scale = num_or(&dungeon.get("hp_scale_base"), 1.0);
    let atk_scale = num_or(&dungeon.get("atk_scale"), 1.0);
    let mut vars = script_vars(&held(&data, "stats")?, 0);
    if let Some(v) = script_vars(&data, 0).remove("double_dmg_chance") {
        vars.insert("double_dmg_chance".into(), v);
    }
    let name = data.get("display_name").stringify().to_string();
    let mut g = fight::from_vars(&name, &vars);
    let scale = |v: i64, by: f64| ((v as f64 * by).round() as i64).max(1);
    g.max_hp = scale(g.max_hp, floor_scale * hp_scale);
    g.atk = scale(g.atk, floor_scale);
    // EnemyCombatData LootBand: REGULAR 0, ELITE 1, BOSS 2.
    let elite = int(&data.get("loot_band")) == 1;
    if elite {
        let norm = call(
            &mut db,
            "power_norm",
            &[data.to_variant(), dungeon.to_variant()],
        )?;
        if let Ok(norm) = norm.try_to::<AnyDictionary>() {
            let f = |k: &str| norm.get(k).map_or(1.0, |v| num_or(&v, 1.0));
            g.max_hp = scale(g.max_hp, f("hp"));
            g.atk = scale(g.atk, f("atk"));
        }
    }
    if (atk_scale - 1.0).abs() > 1e-9 {
        g.atk = scale(g.atk, atk_scale);
    }
    if elite
        && let Ok(ease) = dungeon.get("elite_atk_ease").try_to::<AnyArray>()
        && let Some(e) = ease.get(floor as usize - 1)
    {
        g.atk = scale(g.atk, num_or(&e, 1.0));
    }
    g.speed = (g.speed + 1.0).max(1.0);
    g.block_chance = 1.0;
    g.hp = g.max_hp;
    g.block = g.block_max;
    Ok(g)
}

/// One owned piece as the packer sees it.
#[derive(Debug, Clone)]
pub struct Owned {
    pub id: i64,
    pub name: String,
    pub grid: i64,
    /// Origin and turn on its grid now.
    pub at: (i32, i32, i32),
    /// Why the game would refuse to wear it ("" when it would not).
    pub refusal: String,
    /// Potions and the like: the anvil takes none (inventory.gd
    /// can_place).
    pub consumable: bool,
    /// A gem (equipment_item.gd is_gem): it goes inside other pieces.
    pub gem: bool,
    pub rarity: i64,
    pub stats: Vec<(&'static str, f64)>,
    pub piece: grid::Piece,
}

impl Owned {
    /// The game never lets this hero wear it: gems, other classes, a
    /// higher level (inventory.gd equip_block_reason). "Already
    /// equipped" and the weapon limit are the packer's own rules.
    pub fn wearable(&self) -> bool {
        !(self.refusal.starts_with("Drag a gem")
            || self.refusal.starts_with("This class")
            || self.refusal.starts_with("Requires Level"))
    }
}

/// Every piece on the equipment, bag and tray grids, the equipment
/// grid's open cells and the hero's weapon slots.
#[derive(Debug, Clone)]
pub struct Seen {
    pub list: Vec<Owned>,
    pub w: i32,
    pub h: i32,
    pub open: Vec<bool>,
    /// usize::MAX in a roguelite run (no limit).
    pub hands: usize,
}

impl Seen {
    /// The owned items' ids, sorted, each once.
    pub fn ids(&self) -> Vec<i64> {
        let mut ids: Vec<i64> = self.list.iter().map(|o| o.id).collect();
        ids.sort_unstable();
        ids.dedup();
        ids
    }
}

pub fn inventory() -> Result<Gd<Object>, String> {
    held(&node("/root/Global")?, "inventory")
}

fn cells(v: &Variant) -> Vec<(i32, i32)> {
    v.try_to::<AnyArray>()
        .map(|a| {
            a.iter_shared()
                .filter_map(|c| c.try_to::<Vector2i>().ok())
                .map(|c| (c.x, c.y))
                .collect()
        })
        .unwrap_or_default()
}

/// The game's placement rows on a grid (inventory.gd placements_in),
/// as the game's own dictionaries.
pub fn placements(inv: &mut Gd<Object>, g: i64) -> Result<Vec<AnyDictionary>, String> {
    let rows = call(inv, "placements_in", &[g.to_variant()])?
        .try_to::<AnyArray>()
        .map_err(|e| e.to_string())?;
    Ok(rows
        .iter_shared()
        .filter_map(|p| p.try_to::<AnyDictionary>().ok())
        .collect())
}

pub fn placed_item(p: &AnyDictionary) -> Option<Gd<Object>> {
    p.get("item")?.try_to::<Gd<Object>>().ok()
}

/// The placement row holding the owned item `id`.
pub fn row_of(inv: &mut Gd<Object>, id: i64) -> Result<Option<AnyDictionary>, String> {
    for g in [EQUIP, BAG, TRAY, FORGE] {
        for p in placements(inv, g)? {
            if placed_item(&p).is_some_and(|i| i.instance_id().to_i64() == id) {
                return Ok(Some(p));
            }
        }
    }
    Ok(None)
}

/// An item's shape and hole cells for turns 0 to 3
/// (equipment_item.gd shape_cells, hole_cells).
pub type Cells = [Vec<(i32, i32)>; 4];

pub fn shapes_of(item: &mut Gd<Object>) -> Result<(Cells, Cells), String> {
    let mut shapes: Cells = Default::default();
    let mut holes: Cells = Default::default();
    for r in 0..4 {
        shapes[r] = cells(&call(item, "shape_cells", &[(r as i64).to_variant()])?);
        holes[r] = cells(&call(item, "hole_cells", &[(r as i64).to_variant()])?);
    }
    Ok((shapes, holes))
}

pub fn seen() -> Result<Seen, String> {
    let mut global = node("/root/Global")?;
    let mut inv = inventory()?;
    let mut list = Vec::new();
    for g in [EQUIP, BAG, TRAY] {
        for p in placements(&mut inv, g)? {
            let Some(mut item) = placed_item(&p) else {
                continue;
            };
            let at = |k: &str| p.get(k).map_or(0, |v| int(&v)) as i32;
            let (shapes, holes) = shapes_of(&mut item)?;
            let iv = item.to_variant();
            let refusal = call(
                &mut inv,
                "equip_block_reason",
                &[iv.clone(), p.to_variant()],
            )?
            .stringify()
            .to_string();
            let family = call(&mut inv, "equip_family_id", &[iv])?
                .stringify()
                .to_string();
            let weapon = call(&mut item, "is_weapon", &[])?
                .try_to::<bool>()
                .unwrap_or(false);
            list.push(Owned {
                id: item.instance_id().to_i64(),
                name: item.get("display_name").stringify().to_string(),
                grid: g,
                at: (at("x"), at("y"), at("rot")),
                refusal,
                // equipment_item.gd ItemType: EQUIPABLE, WEAPON, CONSUMABLE.
                consumable: int(&item.get("item_type")) == 2,
                gem: call(&mut item, "is_gem", &[])?
                    .try_to::<bool>()
                    .unwrap_or(false),
                rarity: int(&item.get("rarity")),
                stats: stats_from(&script_vars(&item, 0)),
                piece: grid::Piece {
                    value: 0.0,
                    shapes,
                    holes,
                    family,
                    weapon,
                },
            });
        }
    }
    let size = call(&mut inv, "grid_size", &[EQUIP.to_variant()])?
        .try_to::<Vector2i>()
        .map_err(|e| e.to_string())?;
    let mut open = Vec::new();
    for y in 0..size.y {
        for x in 0..size.x {
            let c = Vector2i::new(x, y).to_variant();
            open.push(
                call(&mut inv, "cell_open", &[EQUIP.to_variant(), c])?
                    .try_to::<bool>()
                    .unwrap_or(false),
            );
        }
    }
    let roguelite = call(&mut global, "in_roguelite_run", &[])?
        .try_to::<bool>()
        .unwrap_or(false);
    let hands = if roguelite {
        usize::MAX
    } else {
        let id = global.get("selected_character_id");
        int(&call(&mut global, "get_weapon_slot_count", &[id])?).max(1) as usize
    };
    Ok(Seen {
        list,
        w: size.x,
        h: size.y,
        open,
        hands,
    })
}

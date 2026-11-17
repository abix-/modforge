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
use crate::placement;

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

pub fn num_or(v: &Variant, or: f64) -> f64 {
    v.try_to::<f64>()
        .or_else(|_| v.try_to::<i64>().map(|i| i as f64))
        .unwrap_or(or)
}

pub fn int(v: &Variant) -> i64 {
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
    /// The player locked it (inventory.gd is_locked); the game will not
    /// sell it.
    pub locked: bool,
    pub rarity: i64,
    pub stats: Vec<(&'static str, f64)>,
    /// The game's own score of the piece (equipment_item.gd stat_score).
    pub score: f64,
    /// The hero with only this piece worn, by the game's fold.
    pub alone: Fold,
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
    pub hero: Hero,
    pub board: placement::Board,
}

impl Seen {
    /// The equipment grid as the packer sees it.
    pub fn grid(&self) -> grid::Grid {
        grid::Grid {
            w: self.w,
            h: self.h,
            open: self.open.clone(),
            board: self.board.clone(),
            sets: crate::sets::Table::default(),
        }
    }

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

/// A hero's stats as script variables, as the game folds them.
pub type Fold = serde_json::Map<String, serde_json::Value>;

/// The hero with only `items` worn, as the game builds the player for
/// a fight: CombatantRuntime.from_player on the hero's base stats
/// (combat_resolver.gd _rebuild_loadout). Battle gains and run bonuses
/// are not in it; `Hero` carries them.
pub fn fold(items: &[Gd<Object>]) -> Result<Fold, String> {
    fold_in(items, godot::builtin::VarArray::new().to_variant())
}

/// The game's own count of empty equipment cells for these placements
/// (combatant_runtime.gd _empty_equip_cells), for research.
pub fn empty_equip_cells(placements: Variant) -> Result<i64, String> {
    let run = held(&node("/root/Global")?, "current_run")?;
    let mut script = held(&held(&run, "player")?, "script")?;
    let inv = inventory()?;
    Ok(int(&call(
        &mut script,
        "_empty_equip_cells",
        &[placements, inv.to_variant()],
    )?))
}

/// The fold with the pieces' placements, as the game builds the hero
/// now (game_state.gd: from_player with placements_in(EQUIP)); it adds
/// what the spots give and the pieces' grown stats.
pub fn fold_in(items: &[Gd<Object>], placements: Variant) -> Result<Fold, String> {
    let mut global = node("/root/Global")?;
    let id = global.get("selected_character_id");
    let base = call(&mut global, "get_effective_base_stats", &[id])?;
    let run = held(&global, "current_run")?;
    let mut script = held(&held(&run, "player")?, "script")?;
    // from_player takes a typed Array[EquipmentItem]; the inventory's
    // own list is one (inventory.gd get_equipped_list).
    let mut inv = inventory()?;
    let list = call(&mut inv, "get_equipped_list", &[])?;
    list.call("clear", &[]);
    for i in items {
        list.call("append", &[i.to_variant()]);
    }
    let made = call(
        &mut script,
        "from_player",
        &[
            base,
            list,
            placements,
            true.to_variant(),
            godot::builtin::VarDictionary::new().to_variant(),
        ],
    )?
    .try_to::<Gd<Object>>()
    .map_err(|_| "the game made no player".to_string())?;
    Ok(script_vars(&made, 0))
}

/// The hero now, the game's fold with nothing worn, and with what is
/// worn now, without and with its placements. The difference between
/// the hero now and the fold of what is worn with its placements is
/// what the run adds (genie wishes, dismantle, blessings); it is added
/// to every fold, so any set of pieces is judged the same way and a
/// piece is worth the same worn or in the bag.
#[derive(Debug, Clone)]
pub struct Hero {
    pub now: Fold,
    pub empty: Fold,
    pub worn: Fold,
    pub placed: Fold,
}

pub fn hero() -> Result<Hero, String> {
    let run = held(&node("/root/Global")?, "current_run")?;
    let now = script_vars(&held(&run, "player")?, 0);
    let mut inv = inventory()?;
    let rows = call(&mut inv, "placements_in", &[EQUIP.to_variant()])?;
    let worn: Vec<Gd<Object>> = placements(&mut inv, EQUIP)?
        .iter()
        .filter_map(placed_item)
        .collect();
    Ok(Hero {
        now,
        empty: fold(&[])?,
        worn: fold(&worn)?,
        placed: fold_in(&worn, rows)?,
    })
}

/// Any item as the mod judges it: owned (`placement`, on grid `g`) or
/// not (a shop ware, a loot drop: `placement` None, grid -1).
pub fn item_of(
    inv: &mut Gd<Object>,
    item: &mut Gd<Object>,
    g: i64,
    at: (i32, i32, i32),
    placement: Option<&AnyDictionary>,
) -> Result<Owned, String> {
    let (shapes, holes) = shapes_of(item)?;
    let iv = item.to_variant();
    let mut why = vec![iv.clone()];
    why.extend(placement.map(|p| p.to_variant()));
    let refusal = call(inv, "equip_block_reason", &why)?
        .stringify()
        .to_string();
    let family = call(inv, "equip_family_id", &[iv])?.stringify().to_string();
    let weapon = call(item, "is_weapon", &[])?
        .try_to::<bool>()
        .unwrap_or(false);
    let place = place_of(item)?;
    Ok(Owned {
        id: item.instance_id().to_i64(),
        name: item.get("display_name").stringify().to_string(),
        grid: g,
        at,
        refusal,
        // equipment_item.gd ItemType: EQUIPABLE, WEAPON, CONSUMABLE.
        consumable: int(&item.get("item_type")) == 2,
        gem: call(item, "is_gem", &[])?.try_to::<bool>().unwrap_or(false),
        locked: placement
            .and_then(|p| p.get("locked"))
            .is_some_and(|v| int(&v) > 0),
        rarity: int(&item.get("rarity")),
        stats: stats_from(&script_vars(item, 0)),
        score: stat_score(item)?,
        alone: fold(std::slice::from_ref(item))?,
        piece: grid::Piece {
            value: 0.0,
            shapes,
            holes,
            family,
            weapon,
            place: std::sync::Arc::new(place),
        },
    })
}

/// slot_bonus.gd MELEE_CLASSES.
const MELEE_CLASSES: &[&str] = &["sword", "axe", "mace", "dagger", "spear", "claw"];

/// An item's placement rules and what other rules see of it
/// (equipment_item.gd adjacent_*, edge_*, tags, matches_rule).
/// The game's own score of a piece (equipment_item.gd stat_score): every
/// stat by one weight, plus points for its special effects.
pub fn stat_score(item: &mut Gd<Object>) -> Result<f64, String> {
    let v = call(item, "stat_score", &[])?;
    v.try_to::<f64>().map_err(|e| e.to_string())
}

pub fn place_of(item: &mut Gd<Object>) -> Result<placement::Place, String> {
    let weapon = call(item, "is_weapon", &[])?
        .try_to::<bool>()
        .unwrap_or(false);
    let s = |item: &Gd<Object>, k: &str| item.get(k).stringify().to_string();
    let f = |item: &Gd<Object>, k: &str| num_or(&item.get(k), 0.0);
    let tags = item
        .get("tags")
        .try_to::<AnyArray>()
        .map(|a| a.iter_shared().map(|t| t.stringify().to_string()).collect())
        .unwrap_or_default();
    let weapon_class = s(item, "weapon_class");
    let traits = placement::Traits {
        tags,
        weapon,
        weapon_class: weapon_class.clone(),
        consumable: int(&item.get("item_type")) == 2,
        cursed: call(item, "is_cursed", &[])?
            .try_to::<bool>()
            .unwrap_or(false),
        slot: call(item, "slot_name", &[])?.stringify().to_string(),
        rarity: int(&item.get("rarity")),
    };
    let tag = s(item, "adjacent_tag");
    let adjacent = (!tag.is_empty()).then(|| placement::Adjacent {
        tag,
        side: s(item, "adjacent_side"),
        min: int(&item.get("adjacent_min")),
        also_tag: s(item, "adjacent_also_tag"),
        also_side: s(item, "adjacent_also_side"),
        stat: s(item, "adjacent_stat"),
        amount: f(item, "adjacent_amount"),
        stat_2: s(item, "adjacent_stat_2"),
        amount_2: f(item, "adjacent_amount_2"),
    });
    let edge_stat = s(item, "edge_stat");
    let edge = (!edge_stat.is_empty()).then(|| placement::Edge {
        stat: edge_stat,
        amount: f(item, "edge_amount"),
        mode: s(item, "edge_mode"),
    });
    let trigger_bow = weapon_class == "bow" && int(&item.get("ammo")) > 0;
    let brawler_atk = if weapon && MELEE_CLASSES.contains(&weapon_class.as_str()) && !trigger_bow {
        int(&item.get("bonus_atk"))
    } else {
        0
    };
    Ok(placement::Place {
        traits,
        adjacent,
        edge,
        brawler_atk,
        set_count_bonus: int(&item.get("set_count_bonus")),
        set_bonus_mult: num_or(&item.get("set_bonus_mult"), 0.0),
        atk_per_empty: int(&item.get("atk_per_empty_cell")),
        gain: placement::Gain::default(),
    })
}

/// The equipment board's edges and runes (inventory.gd open_size,
/// game_state.gd get_slot_bonuses: "cX_Y" keys, "id" or "id:arg"
/// values, slot_bonus.gd key_cell, base_id).
fn board(global: &mut Gd<Object>, inv: &mut Gd<Object>) -> Result<placement::Board, String> {
    let size = call(inv, "open_size", &[EQUIP.to_variant()])?
        .try_to::<Vector2i>()
        .map_err(|e| e.to_string())?;
    let id = global.get("selected_character_id");
    let map = call(global, "get_slot_bonuses", &[id])?
        .try_to::<AnyDictionary>()
        .map_err(|e| format!("slot bonuses: {e}"))?;
    let mut runes = Vec::new();
    for (k, v) in map.iter_shared() {
        let k = k.stringify().to_string();
        let Some((x, y)) = k
            .strip_prefix('c')
            .and_then(|r| r.split_once('_'))
            .and_then(|(x, y)| Some((x.parse::<i32>().ok()?, y.parse::<i32>().ok()?)))
        else {
            continue;
        };
        let v = v.stringify().to_string();
        let base = v.split(':').next().unwrap_or("").to_string();
        if x >= 0 && y >= 0 && !base.is_empty() {
            runes.push(((x, y), base));
        }
    }
    runes.sort();
    let mut base = Vec::new();
    for y in 0..placement::EQUIP_BASE_ROWS {
        for x in 0..placement::EQUIP_COLUMNS {
            let c = Vector2i::new(x, y).to_variant();
            if call(inv, "cell_open", &[EQUIP.to_variant(), c])?
                .try_to::<bool>()
                .unwrap_or(false)
            {
                base.push((x, y));
            }
        }
    }
    Ok(placement::Board {
        size: (size.x, size.y),
        runes,
        base,
    })
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
            list.push(item_of(
                &mut inv,
                &mut item,
                g,
                (at("x"), at("y"), at("rot")),
                Some(&p),
            )?);
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
        hero: hero()?,
        board: board(&mut global, &mut inv)?,
    })
}

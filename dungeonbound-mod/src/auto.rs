//! Auto mode inside the game: every step the auto-player made, run by
//! the mod on its own thread with direct calls into the game.
//! Operator 2026-11-17: "all the functioanlity needs to in the mod ffs
//! right?? we know what we want all the auto mode hsouldbe IN the mod",
//! "and not just the shop but all the auto stuff right?? put it all in
//! the mod. we know it works". Ported from src/bin/auto.rs step for
//! step; the op `auto` turns it on and off, `auto_lines` returns what
//! it did and why.
//!
//! Each step looks at the screen and presses what the game would have
//! the player press, the way the game presses them (`pressed.emit()`,
//! crawl.gd:450): death and hub, the fight (predicted), loot, genie,
//! dismantle, shop, item stops, the fork, fusion, rune stone, mega
//! forge, gems, equipment, then CONTINUE on a known stop or START
//! BATTLE / ENTER DEEPER. Any other stop waits for the operator
//! (operator 2026-11-16: "we shouldnt skip over stuff unless there'a a
//! reason"). Reads and presses run on the game's main thread; the
//! fight math runs on the mod's thread.

use std::sync::Mutex;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

use godot::builtin::{AnyArray, AnyDictionary, GString, StringName, Variant, Vector2i};
use godot::classes::{Node, Object};
use godot::meta::ToGodot;
use godot::obj::Gd;
use godotforge::godot4::{on_main, ops::script_vars, target};
use modforge::ops::{OP_REGISTRY, OpDef};
use serde_json::{Value as Json, json};

use crate::fight::{self, Fighter, Run};
use crate::items::{ITEM_STATS, apply_bonus, stats_from};
use crate::read::{self, BAG, EQUIP, SCENE, TRAY, int};
use crate::{arrange, gems, mega, shop};

const TICK: Duration = Duration::from_millis(700);
/// Buttons pressed in this order when no stop is up.
const BAR: [&str; 2] = ["StartBattleBtn", "EnterDeeperBtn"];
/// Stops played: CONTINUE is the right press. Chest: CONTINUE opens it
/// (an item, against SKIP's 10 gold), then closes it. Campsite: it
/// heals on entry, CONTINUE leaves. Genie: CONTINUE once the wish is
/// chosen. Blessing: granted on entry (bless_encounter.gd _ready), no
/// choice.
const HANDLED: [&str; 8] = [
    "mega_forge_encounter.gd",
    "slot_bless_encounter.gd",
    "shop_encounter.gd",
    "dismantle_encounter.gd",
    "chest_encounter.gd",
    "campsite_encounter.gd",
    "genie_encounter.gd",
    "bless_encounter.gd",
];

static ON: AtomicBool = AtomicBool::new(false);
static STARTED: AtomicBool = AtomicBool::new(false);
/// Every line said, numbered from 0.
static LINES: Mutex<Vec<String>> = Mutex::new(Vec::new());

/// What the loop remembers between steps.
struct Memory {
    /// The unhandled stop already announced.
    waiting: String,
    /// The item stop already used once (its object id).
    shrine_done: i64,
    /// The fight on now was predicted.
    predicted: bool,
    /// The strongest foe of the last fight, for judging when no
    /// guardian is prepared.
    last_foe: Option<Fighter>,
    started: Option<Instant>,
}

static MEMORY: Mutex<Memory> = Mutex::new(Memory {
    waiting: String::new(),
    shrine_done: 0,
    predicted: false,
    last_foe: None,
    started: None,
});

fn memory() -> std::sync::MutexGuard<'static, Memory> {
    MEMORY.lock().unwrap_or_else(|e| e.into_inner())
}

pub fn register_ops() {
    OP_REGISTRY.register_many([
        OpDef::new(
            "auto",
            "Auto mode inside the game: on true plays every step the auto-player knows, on false stops; \
             no args reports whether it is on",
            "{on?: bool}",
            auto,
        ),
        OpDef::new(
            "auto_lines",
            "What auto mode did and why, from line number `after` on",
            "{after?: 0}",
            auto_lines,
        ),
    ]);
}

fn auto(args: &Json) -> Result<Json, String> {
    if let Some(on) = args.get("on").and_then(Json::as_bool) {
        ON.store(on, Ordering::SeqCst);
        say(if on { "auto: on" } else { "auto: off" });
        if on && !STARTED.swap(true, Ordering::SeqCst) {
            std::thread::Builder::new()
                .name("dungeonbound-auto".into())
                .spawn(run)
                .map_err(|e| e.to_string())?;
        }
    }
    Ok(json!({"on": ON.load(Ordering::SeqCst), "lines": LINES.lock().map_or(0, |l| l.len())}))
}

fn auto_lines(args: &Json) -> Result<Json, String> {
    let after = args.get("after").and_then(Json::as_u64).unwrap_or(0) as usize;
    let l = LINES.lock().unwrap_or_else(|e| e.into_inner());
    let from = after.min(l.len());
    Ok(json!({"next": l.len(), "lines": l[from..].to_vec(), "on": ON.load(Ordering::SeqCst)}))
}

/// Say a line: the mod's log and `auto_lines`.
fn say(line: &str) {
    modforge::log!("[auto] {line}");
    LINES
        .lock()
        .unwrap_or_else(|e| e.into_inner())
        .push(line.to_string());
}

fn say_all(r: &Json) {
    for l in r["lines"].as_array().into_iter().flatten() {
        say(&format!("  {}", l.as_str().unwrap_or("")));
    }
}

fn run() {
    let mut last_err = String::new();
    loop {
        if ON.load(Ordering::SeqCst) {
            match step() {
                Err(e) if e != last_err => {
                    say(&format!("error: {e}"));
                    last_err = e;
                }
                Err(_) => {}
                Ok(()) => last_err.clear(),
            }
        }
        std::thread::sleep(TICK);
    }
}

fn secs() -> f64 {
    memory()
        .started
        .get_or_insert_with(Instant::now)
        .elapsed()
        .as_secs_f64()
}

// The game's screen, on the main thread.

fn scene() -> Result<Gd<Node>, String> {
    target::node_by_path(SCENE)
}

/// The first node named `name` under `under`, `depth` levels down.
fn named(under: &Gd<Node>, name: &str, depth: u32) -> Option<Gd<Object>> {
    for c in under.get_children().iter_shared() {
        if c.get_name().to_string() == name {
            return Some(c.upcast());
        }
        if depth > 1
            && let Some(n) = named(&c, name, depth - 1)
        {
            return Some(n);
        }
    }
    None
}

fn stop(script: &str, depth: u32) -> Result<Option<Gd<Object>>, String> {
    Ok(read::find(&scene()?, script, depth).map(|n| n.upcast()))
}

fn flag(o: &Gd<Object>, p: &str) -> bool {
    o.get(p).try_to::<bool>().unwrap_or(false)
}

fn held(o: &Gd<Object>, p: &str) -> Option<Gd<Object>> {
    o.get(p).try_to::<Gd<Object>>().ok()
}

fn list(v: Variant) -> Vec<Variant> {
    v.try_to::<AnyArray>()
        .map(|a| a.iter_shared().collect())
        .unwrap_or_default()
}

fn yes(v: &Variant) -> bool {
    v.try_to::<bool>().unwrap_or(false)
}

/// A method that answers true.
fn says(o: &mut Gd<Object>, method: &str) -> bool {
    read::call(o, method, &[]).is_ok_and(|v| yes(&v))
}

/// Shown on screen and not disabled.
fn pressable(b: &mut Gd<Object>) -> bool {
    says(b, "is_visible_in_tree") && !flag(b, "disabled")
}

/// Press and say it.
fn pressed(b: &mut Gd<Object>, label: &str) -> Result<(), String> {
    read::call(
        b,
        "emit_signal",
        &[StringName::from("pressed").to_variant()],
    )?;
    say(&format!("{:7.1}s pressed {label}", secs()));
    Ok(())
}

/// Leave a stop with SKIP (or LEAVE after a use), giving the reason.
fn leave(why: &str) -> Result<(), String> {
    let why = why.to_string();
    on_main("auto leave", move || {
        if let Some(mut skip) = named(&scene()?, "EncounterSkipBtn", 8)
            && pressable(&mut skip)
        {
            pressed(&mut skip, &format!("SKIP ({why})"))?;
        }
        Ok(())
    })
}

/// Every owned item once (equipment, bag, tray), skipping `skip`.
fn owned_items(skip: impl Fn(&mut Gd<Object>) -> bool) -> Result<Vec<Gd<Object>>, String> {
    let mut inv = read::inventory()?;
    let mut out: Vec<Gd<Object>> = Vec::new();
    for g in [EQUIP, BAG, TRAY] {
        for p in read::placements(&mut inv, g)? {
            let Some(mut i) = read::placed_item(&p) else {
                continue;
            };
            if out.iter().any(|o| o.instance_id() == i.instance_id()) || skip(&mut i) {
                continue;
            }
            out.push(i);
        }
    }
    Ok(out)
}

/// An item as the per-cell judge sees it: object id, name, the game's
/// id, plain stats and cells.
#[derive(Clone)]
struct Item {
    id: i64,
    name: String,
    gid: GString,
    stats: Vec<(&'static str, f64)>,
    cells: usize,
}

fn item(i: &mut Gd<Object>) -> Result<Item, String> {
    let cells = list(read::call(i, "shape_cells", &[0i64.to_variant()])?)
        .len()
        .max(1);
    Ok(Item {
        id: i.instance_id().to_i64(),
        name: i.get("display_name").stringify().to_string(),
        gid: i.get("id").try_to().unwrap_or_default(),
        stats: stats_from(&script_vars(i, 0)),
        cells,
    })
}

fn object(id: i64) -> Result<Gd<Object>, String> {
    target::object_by_id(id)
}

// The judge, on the mod's thread.

/// The floor's guardian, or the strongest foe of the last fight when
/// none was ever read (as the auto-player did).
fn foe() -> Result<Fighter, String> {
    match on_main("auto foe", || Ok(read::guardian()))? {
        Ok(g) => Ok(g),
        Err(e) => {
            let mut last = memory().last_foe.clone().ok_or(e)?;
            last.hp = last.max_hp;
            last.block = last.block_max;
            Ok(last)
        }
    }
}

fn player_and_foe() -> Result<(Fighter, Vec<Fighter>), String> {
    let me = on_main("auto player", read::player)?;
    Ok((me, vec![foe()?]))
}

/// Items ranked by gain per grid cell, best first: the fight margin
/// its plain stats add to the player, over the cells its shape takes.
fn per_cell(me: &Fighter, squad: &[Fighter], items: &[Item]) -> Vec<(usize, f64)> {
    let base = fight::score(me, squad, Run::Campaign).margin;
    let mut out: Vec<(usize, f64)> = items
        .iter()
        .enumerate()
        .map(|(i, it)| {
            let mut p = me.clone();
            for (s, v) in &it.stats {
                apply_bonus(&mut p, s, *v);
            }
            (
                i,
                (fight::score(&p, squad, Run::Campaign).margin - base) / it.cells as f64,
            )
        })
        .collect();
    out.sort_by(|a, b| b.1.total_cmp(&a.1));
    out
}

/// The fight margin plain stats add to the player.
fn gain(me: &Fighter, squad: &[Fighter], base: f64, stats: &[(&'static str, f64)]) -> f64 {
    let mut p = me.clone();
    for (s, v) in stats {
        apply_bonus(&mut p, s, *v);
    }
    fight::score(&p, squad, Run::Campaign).margin - base
}

// The steps.

fn step() -> Result<(), String> {
    if between_runs()? {
        return Ok(());
    }
    let fighting = on_main("auto crawl", || {
        Ok(flag(&read::crawl()?.upcast(), "_fighting"))
    })?;
    if fighting {
        if !std::mem::replace(&mut memory().predicted, true) {
            predict()?;
        }
        return Ok(());
    }
    if std::mem::take(&mut memory().predicted) {
        let hp = on_main("auto hp", || {
            let run = read::held(&read::node("/root/Global")?, "current_run")?;
            Ok(int(&read::held(&run, "player")?.get("current_hp")))
        })?;
        say(&format!("  fight over: player hp {hp}"));
    }
    if loot()? || genie()? || dismantle()? {
        return Ok(());
    }
    let r = shop::shop(&json!({}))?;
    say_all(&r);
    if r["acted"] == json!(true) {
        return Ok(());
    }
    if item_stop()? || fork()? || fuse()? || rune()? {
        return Ok(());
    }
    // Before arrange, so nothing moves pieces while the mega forge has
    // the anvil; gems before arrange, so a socketed piece is packed by
    // its new value.
    for (op, flag) in [
        (
            mega::mega_forge as fn(&Json) -> Result<Json, String>,
            "acted",
        ),
        (gems::gems, "acted"),
        (arrange::arrange, "changed"),
    ] {
        let r = op(&json!({}))?;
        say_all(&r);
        if r[flag] == json!(true) {
            return Ok(());
        }
    }
    buttons()
}

/// Death and the hub. The death screen's RERUN starts the run again at
/// once, CONTINUE when it is not shown (death_screen.gd configure_bar).
/// The hub's START RUN resumes or starts the campaign (hub.gd
/// _on_start_run_pressed). True when one of them is up.
fn between_runs() -> Result<bool, String> {
    on_main("auto between runs", || {
        let s = scene()?;
        if read::find(&s, "death_screen.gd", 6).is_some() {
            for (name, label) in [
                ("EncounterSkipBtn", "RERUN (died)"),
                ("EncounterContinueBtn", "CONTINUE (died)"),
            ] {
                if let Some(mut b) = named(&s, name, 8)
                    && pressable(&mut b)
                {
                    pressed(&mut b, label)?;
                    break;
                }
            }
            return Ok(true);
        }
        if let Some(hub) = read::find(&s, "/hub.gd", 2) {
            if let Some(mut b) = held(&hub.upcast(), "_start_run_btn")
                && pressable(&mut b)
            {
                pressed(&mut b, "START RUN (hub)")?;
            }
            return Ok(true);
        }
        Ok(false)
    })
}

/// At the start of a fight: the foes the game built (the resolver's
/// squad) and the player as they stand, through the mod's fight math.
/// Logged beside the result to check the math against the game.
fn predict() -> Result<(), String> {
    let (me, squad) = on_main("auto predict", || {
        let resolver: Gd<Object> = read::find(&read::crawl()?, "combat_resolver.gd", 1)
            .ok_or("no combat resolver")?
            .upcast();
        let squad: Vec<Fighter> = list(resolver.get("squad"))
            .into_iter()
            .filter_map(|f| f.try_to::<Gd<Object>>().ok())
            .map(|f| {
                let vars = script_vars(&f, 0);
                let name = vars
                    .get("display_name")
                    .and_then(Json::as_str)
                    .unwrap_or("foe")
                    .to_string();
                fight::from_vars(&name, &vars)
            })
            .collect();
        let run = read::held(&read::node("/root/Global")?, "current_run")?;
        let me = fight::from_vars("Player", &script_vars(&read::held(&run, "player")?, 0));
        Ok((me, squad))
    })?;
    let s = fight::score(&me, &squad, Run::Campaign);
    if let Some(strongest) = squad.iter().max_by_key(|f| f.max_hp * f.atk) {
        memory().last_foe = Some(strongest.clone());
    }
    let foes: Vec<String> = squad
        .iter()
        .map(|f| {
            format!(
                "{} hp {}/{} atk {} block {} speed {:.1}",
                f.name, f.hp, f.max_hp, f.atk, f.block_max, f.speed
            )
        })
        .collect();
    say(&format!(
        "  fight: player hp {}/{} atk {} block {} speed {:.1} vs {}",
        me.hp,
        me.max_hp,
        me.atk,
        me.block_max,
        me.speed,
        foes.join("; ")
    ));
    say(&format!(
        "  predicted win {:.1}% hp left {:.0}%",
        s.win * 100.0,
        s.hp_left * 100.0
    ));
    Ok(())
}

/// Loot up: AUTO PICK when there is a choice of two (the game's own
/// pick), then CLAIM ALL. Operator 2026-11-16: "if we cant claim loot
/// for oom then we gotta sell it right???", "we gotta check free sapc
/// eright??": before claiming, every tray item needs a bag spot (the
/// game's first_fit); when one has none, or the loot did not all go
/// in, the loose piece worth least (bag or tray, the shop's choice) is
/// sold first, one per step.
fn loot() -> Result<bool, String> {
    enum Look {
        Off,
        Sell(read::Seen),
        Done,
    }
    let look = on_main("auto loot", || {
        let crawl: Gd<Object> = read::crawl()?.upcast();
        let Some(mut holder) = held(&crawl, "_loot_holder") else {
            return Ok(Look::Off);
        };
        if !says(&mut holder, "is_visible_in_tree") {
            return Ok(Look::Off);
        }
        let mut inv = read::inventory()?;
        let left = |inv: &mut Gd<Object>| -> Result<(bool, usize), String> {
            let pick = read::call(inv, "has_pick", &[])?
                .try_to::<bool>()
                .unwrap_or(false);
            Ok((pick, read::placements(inv, TRAY)?.len()))
        };
        let (pick, tray) = left(&mut inv)?;
        if !pick && tray > 0 {
            let mut room = true;
            for p in read::placements(&mut inv, TRAY)? {
                let Some(i) = read::placed_item(&p) else {
                    continue;
                };
                if read::call(&mut inv, "first_fit", &[i.to_variant(), BAG.to_variant()])?
                    .try_to::<AnyDictionary>()
                    .is_ok_and(|d| d.is_empty())
                {
                    room = false;
                    break;
                }
            }
            if !room {
                say("  no room in the bag for the loot");
                return Ok(Look::Sell(read::seen()?));
            }
        }
        let mut done = false;
        for (var, label, want) in [
            ("_loot_auto_btn", "AUTO PICK", pick),
            ("_loot_claim_btn", "CLAIM ALL", tray > 0),
        ] {
            if let Some(mut b) = held(&crawl, var)
                && want
                && pressable(&mut b)
            {
                pressed(&mut b, label)?;
                done = true;
                break;
            }
        }
        if !done {
            return Ok(Look::Off);
        }
        let (pick2, tray2) = left(&mut inv)?;
        if (pick && pick2) || (!pick && tray2 >= tray && tray2 > 0) {
            say("  bag full: the loot did not all go in");
            return Ok(Look::Sell(read::seen()?));
        }
        Ok(Look::Done)
    })?;
    match look {
        Look::Off => Ok(false),
        Look::Done => Ok(true),
        Look::Sell(seen) => {
            let judge = arrange::Judge::new(&seen.hero, vec![foe()?]);
            let mut valued: Vec<read::Owned> =
                seen.list.iter().filter(|o| o.wearable()).cloned().collect();
            judge.value_all(&mut valued);
            if let Some(o) = shop::weakest(&valued, &seen, &[BAG, TRAY]) {
                let ok = shop::sell(o.id)?;
                say(&format!(
                    "  sold {} (worth {:.5}, the least loose): {ok}",
                    o.name, o.piece.value
                ));
            } else {
                say("  nothing loose to sell (gems and potions are kept)");
            }
            Ok(true)
        }
    }
}

/// A genie wish on the player: its stat times the genie's 3
/// (game_state.gd LEVEL_BONUS_POOL, genie_encounter.gd
/// GENIE_MULTIPLIER). Percent wishes count on the stat as it is now.
fn apply_wish(p: &mut Fighter, (stat, amount): &(String, f64)) {
    const GENIE_MULTIPLIER: f64 = 3.0;
    apply_bonus(p, stat, amount * GENIE_MULTIPLIER);
}

/// Genie: three permanent stat wishes (genie_encounter.gd). Takes the
/// one that most raises the chance to beat the guardian.
fn genie() -> Result<bool, String> {
    let wishes = on_main("auto genie", || {
        let Some(g) = stop("genie_encounter.gd", 4)? else {
            return Ok(None);
        };
        if flag(&g, "_used") {
            return Ok(None);
        }
        let wishes: Vec<(String, f64)> = list(g.get("_wishes"))
            .into_iter()
            .filter_map(|w| w.try_to::<AnyDictionary>().ok())
            .map(|w| {
                let stat = w
                    .get("stat")
                    .map_or(String::new(), |v| v.stringify().to_string());
                (stat, w.get("amount").map_or(0.0, |v| read::num_or(&v, 0.0)))
            })
            .collect();
        let cards = list(g.get("_cards")).len();
        Ok((!wishes.is_empty() && cards == wishes.len()).then_some(wishes))
    })?;
    let Some(wishes) = wishes else {
        return Ok(false);
    };
    let (me, squad) = player_and_foe()?;
    let (best, rates) = fight::best_choice(&me, &squad, Run::Campaign, &wishes, apply_wish);
    let Some(best) = best else {
        return Ok(false);
    };
    for (w, r) in wishes.iter().zip(&rates) {
        say(&format!("  wish {} {}: win {:.1}%", w.0, w.1, r * 100.0));
    }
    let stat = wishes[best].0.clone();
    on_main("auto wish", move || {
        let Some(g) = stop("genie_encounter.gd", 4)? else {
            return Ok(false);
        };
        let Some(mut card) = list(g.get("_cards"))
            .get(best)
            .and_then(|c| c.try_to::<Gd<Object>>().ok())
        else {
            return Ok(false);
        };
        pressed(&mut card, &format!("wish {stat}"))?;
        Ok(true)
    })
}

/// An item stop (item_shrine.gd): the game's own drop stages the item.
/// Presses the act button when the stop takes it and it is free
/// (use_cost 0); says why not otherwise.
fn stage_and_act(s: &mut Gd<Object>, it: &mut Gd<Object>, label: &str) -> Result<bool, String> {
    let name = it.get("display_name").stringify().to_string();
    read::call(s, "_on_item_dropped", &[it.get("id")])?;
    let Some(mut act) = named(&scene()?, "EncounterContinueBtn", 8) else {
        return Ok(false);
    };
    if !pressable(&mut act) {
        say(&format!("  {name} refused"));
        return Ok(false);
    }
    let cost = int(&read::call(s, "use_cost", &[])?);
    if cost > 0 {
        say(&format!("  {name} would cost {cost} gold; not paying"));
        return Ok(false);
    }
    pressed(&mut act, &format!("{label} {name}"))?;
    Ok(true)
}

/// Dismantle: one item ground to dust for 60% of its plain stats,
/// permanently (dismantle_encounter.gd absorbed). Operator 2026-11-16:
/// "we should do it for the best overall gain / whatver the item is".
/// Every item, worn or loose, is a choice judged by the fight math.
fn dismantle() -> Result<bool, String> {
    let items = on_main("auto dismantle", || {
        let Some(mut s) = stop("dismantle_encounter.gd", 4)? else {
            return Ok(None);
        };
        if flag(&s, "_used") {
            return Ok(None);
        }
        let skip = |i: &mut Gd<Object>| {
            says(i, "is_gem")
                || says(i, "is_tome")
                // ItemType CONSUMABLE 2 (equipment_item.gd).
                || int(&i.get("item_type")) == 2
        };
        let mut out: Vec<(i64, String, Vec<(String, f64)>)> = Vec::new();
        for i in owned_items(skip)? {
            let gains: Vec<(String, f64)> =
                list(read::call(&mut s, "absorbed", &[i.to_variant()])?)
                    .into_iter()
                    .filter_map(|g| g.try_to::<AnyArray>().ok())
                    .filter_map(|g| {
                        Some((
                            g.get(0)?.stringify().to_string(),
                            read::num_or(&g.get(1)?, 0.0),
                        ))
                    })
                    .collect();
            if !gains.is_empty() {
                out.push((
                    i.instance_id().to_i64(),
                    i.get("display_name").stringify().to_string(),
                    gains,
                ));
            }
        }
        Ok(Some(out))
    })?;
    let Some(items) = items else {
        return Ok(false);
    };
    let (me, squad) = player_and_foe()?;
    let ranked = fight::rank(&me, &squad, Run::Campaign, &items, |p, (_, _, gains)| {
        for (s, v) in gains {
            apply_bonus(p, s, *v);
        }
    });
    let order: Vec<(i64, String)> = ranked
        .iter()
        .map(|(i, s)| {
            let (_, name, gains) = &items[*i];
            (
                items[*i].0,
                format!(
                    "  dismantle {name}: {gains:?} -> win {:.1}% hp left {:.0}%",
                    s.win * 100.0,
                    s.hp_left * 100.0
                ),
            )
        })
        .collect();
    let acted = on_main("auto dismantle act", move || {
        let Some(mut s) = stop("dismantle_encounter.gd", 4)? else {
            return Ok(false);
        };
        for (id, line) in &order {
            let Ok(mut it) = object(*id) else { continue };
            say(line);
            if stage_and_act(&mut s, &mut it, "DISMANTLE")? {
                return Ok(true);
            }
        }
        Ok(false)
    })?;
    if !acted {
        leave("nothing to dismantle")?;
    }
    Ok(true)
}

/// The item stops (item_shrine.gd): stage an item with the game's own
/// drop, act, then CONTINUE or the stop's own finish. Operator
/// 2026-11-16: "we should be gambling the items that can give us the
/// most gain per slot". Gamble, altar (UPGRADE), sanctify: every item
/// by gain per cell. Curse: the offer's boon and bane judged on the
/// player, taken on a worn item only when the fight margin goes up.
/// Attune and unsocket are not judged yet and are left with the
/// reason. One use per stop, free uses only.
fn item_stop() -> Result<bool, String> {
    enum Look {
        None,
        Acted,
        Judge(
            i64,
            &'static str,
            Vec<Item>,
            Option<[(String, f64); 2]>,
            Vec<i64>,
        ),
    }
    let done = memory().shrine_done;
    let look = on_main("auto item stop", move || {
        let mut found = None;
        for (script, label) in [
            ("gamble_encounter.gd", "GAMBLE"),
            ("altar_encounter.gd", "UPGRADE"),
            ("sanctify_encounter.gd", "SANCTIFY"),
            ("curse_encounter.gd", "CURSE"),
            ("attune_encounter.gd", "ATTUNE"),
            ("unsocket_encounter.gd", "UNSOCKET"),
        ] {
            if let Some(s) = stop(script, 4)? {
                found = Some((s, label));
                break;
            }
        }
        let Some((mut s, label)) = found else {
            return Ok(Look::None);
        };
        if flag(&s, "_spinning") {
            return Ok(Look::Acted);
        }
        let sid = s.instance_id().to_i64();
        let used = flag(&s, "_used");
        if done == sid || used {
            // After the use the act button is CONTINUE (item_shrine.gd
            // _act); when a paid reuse is offered, SKIP reads LEAVE.
            let sc = scene()?;
            if let Some(mut b) = named(&sc, "EncounterContinueBtn", 8)
                && used
                && pressable(&mut b)
            {
                pressed(&mut b, &format!("CONTINUE ({label})"))?;
            } else if used && !s.get("_held").is_nil() {
                // The result waits on the stop and CONTINUE stays off
                // until it is taken; the stop's own finish hands it back.
                read::call(&mut s, "finish", &[])?;
                say(&format!(
                    "{:7.1}s closed {label}; result handed back",
                    secs()
                ));
            } else if let Some(mut b) = named(&sc, "EncounterSkipBtn", 8)
                && pressable(&mut b)
            {
                pressed(&mut b, "SKIP (used once)")?;
            }
            return Ok(Look::Acted);
        }
        if label == "ATTUNE" || label == "UNSOCKET" {
            if let Some(mut b) = named(&scene()?, "EncounterSkipBtn", 8)
                && pressable(&mut b)
            {
                pressed(&mut b, &format!("SKIP ({label} is not judged yet)"))?;
            }
            return Ok(Look::Acted);
        }
        let mut items = Vec::new();
        for mut i in owned_items(|_| false)? {
            items.push(item(&mut i)?);
        }
        let mut curse = None;
        let mut worn = Vec::new();
        if label == "CURSE" {
            let offer = s
                .get("_offer")
                .try_to::<AnyDictionary>()
                .map_err(|e| e.to_string())?;
            let side = |k: &str| -> (String, f64) {
                let d = offer.get(k).and_then(|v| v.try_to::<AnyDictionary>().ok());
                let get = |f: &str| d.as_ref().and_then(|d| d.get(f));
                (
                    get("stat").map_or(String::new(), |v| v.stringify().to_string()),
                    get("amount").map_or(0.0, |v| read::num_or(&v, 0.0)),
                )
            };
            curse = Some([side("boon"), side("bane")]);
            let mut inv = read::inventory()?;
            worn = list(read::call(&mut inv, "get_equipped_list", &[])?)
                .into_iter()
                .filter_map(|w| w.try_to::<Gd<Object>>().ok())
                .map(|w| w.instance_id().to_i64())
                .collect();
        }
        Ok(Look::Judge(sid, label, items, curse, worn))
    })?;
    let (sid, label, items, curse, worn) = match look {
        Look::None => return Ok(false),
        Look::Acted => return Ok(true),
        Look::Judge(a, b, c, d, e) => (a, b, c, d, e),
    };
    let (me, squad) = player_and_foe()?;
    let mut ranked = per_cell(&me, &squad, &items);
    if let Some(offer) = curse {
        let base = fight::score(&me, &squad, Run::Campaign).margin;
        let mut p = me.clone();
        for (stat, amount) in &offer {
            if let Some((_, to)) = ITEM_STATS.iter().find(|(f, _)| f == stat) {
                apply_bonus(&mut p, to, *amount);
            }
        }
        let g = fight::score(&p, &squad, Run::Campaign).margin - base;
        say(&format!(
            "  curse offer boon {:?} bane {:?}: margin change {g:.4}",
            offer[0], offer[1]
        ));
        if g <= 0.0 {
            leave("the curse loses more than it gives")?;
            return Ok(true);
        }
        // On a worn item, so it counts now.
        ranked.retain(|(i, _)| worn.contains(&items[*i].id));
    }
    for (i, g) in &ranked {
        say(&format!("  {}: gain per cell {g:.4}", items[*i].name));
    }
    let order: Vec<i64> = ranked.iter().map(|(i, _)| items[*i].id).collect();
    let acted = on_main("auto item stop act", move || {
        let Ok(mut s) = object(sid) else {
            return Ok(false);
        };
        for id in &order {
            let Ok(mut it) = object(*id) else { continue };
            if stage_and_act(&mut s, &mut it, label)? {
                return Ok(true);
            }
        }
        Ok(false)
    })?;
    if acted {
        memory().shrine_done = sid;
    } else {
        leave(&format!("no item {label} takes for free"))?;
    }
    Ok(true)
}

/// The fork (crawl.gd, "CHOOSE YOUR PATH"): each lane's stops come
/// from the floor plan (floor_plan.gd path_stops: kind, unknown).
/// Operator 2026-11-16: "find best success rate then do it. tahts the
/// rule". A lane's success rate is the chance to win each of its fights
/// in a row. Mine, as a lane's foes are rolled only when entered: an
/// enemy stop is judged as the strongest foe of the last fight, an
/// elite as the floor's guardian, and an unknown stop is a fight 25% of
/// the time (floor_plan.gd UNKNOWN_ODDS ENEMY 25). On a tie (within
/// 0.1%), the most treasure, shrine and unknown stops, then the fewest
/// elites (mine). Picked through the PATH button's own step
/// (_choose_next_lane).
fn fork() -> Result<bool, String> {
    let lanes = on_main("auto fork", || {
        let crawl: Gd<Object> = read::crawl()?.upcast();
        let Some(mut panel) = held(&crawl, "_fork_panel") else {
            return Ok(None);
        };
        if !says(&mut panel, "is_visible_in_tree") {
            return Ok(None);
        }
        let ahead = crawl
            .get("_ahead")
            .try_to::<AnyDictionary>()
            .map_err(|e| e.to_string())?;
        let mut plan = ahead
            .get("plan")
            .and_then(|p| p.try_to::<Gd<Object>>().ok())
            .ok_or("no floor plan")?;
        let n = list(read::call(&mut plan, "all_routes", &[])?).len();
        let mut lanes: Vec<Vec<(i64, bool)>> = Vec::new();
        for lane in 0..n {
            let stops = list(read::call(
                &mut plan,
                "path_stops",
                &[(lane as i64).to_variant()],
            )?);
            lanes.push(
                stops
                    .into_iter()
                    .filter_map(|s| s.try_to::<AnyDictionary>().ok())
                    .map(|s| {
                        (
                            s.get("kind").map_or(0, |v| int(&v)),
                            s.get("unknown").is_some_and(|v| yes(&v)),
                        )
                    })
                    .collect(),
            );
        }
        Ok(Some(lanes))
    })?;
    let Some(lanes) = lanes else {
        return Ok(false);
    };
    let (p_enemy, p_elite) = match player_and_foe() {
        Ok((me, guard)) => {
            let p_elite = fight::score(&me, &guard, Run::Campaign).win;
            let p_enemy = memory().last_foe.clone().map_or(p_elite, |mut f| {
                f.hp = f.max_hp;
                f.block = f.block_max;
                fight::score(&me, &[f], Run::Campaign).win
            });
            (p_enemy, p_elite)
        }
        Err(e) => {
            say(&format!(
                "  path: no foe to judge ({e}); success rates unknown"
            ));
            (1.0, 1.0)
        }
    };
    let mut best: Option<(usize, (f64, i64, i64))> = None;
    for (lane, stops) in lanes.iter().enumerate() {
        let (mut good, mut elites, mut rate) = (0, 0, 1.0f64);
        let mut seen = Vec::new();
        for &(kind, unknown) in stops {
            // DungeonLayout Content: ENEMY 1, ELITE 2, SHRINE 6,
            // TREASURE 7, SHOP 8, CHALLENGER 9.
            rate *= match (unknown, kind) {
                (true, _) => 0.75 + 0.25 * p_enemy,
                (false, 1) => p_enemy,
                (false, 2 | 9) => p_elite,
                _ => 1.0,
            };
            if unknown || kind == 6 || kind == 7 {
                good += 1;
            }
            if kind == 2 && !unknown {
                elites += 1;
            }
            seen.push(if unknown {
                "?".to_string()
            } else {
                kind.to_string()
            });
        }
        say(&format!(
            "  path {}: stops {seen:?} success {:.1}% good {good} elites {elites}",
            lane + 1,
            rate * 100.0
        ));
        let key = ((rate * 1000.0).round() / 1000.0, good, -elites);
        if best.is_none_or(|(_, k)| key.partial_cmp(&k).is_some_and(|o| o.is_gt())) {
            best = Some((lane, key));
        }
    }
    let Some((lane, _)) = best else {
        return Ok(false);
    };
    on_main("auto fork pick", move || {
        let mut crawl: Gd<Object> = read::crawl()?.upcast();
        read::call(
            &mut crawl,
            "_choose_next_lane",
            &[(lane as i64).to_variant()],
        )?;
        Ok(())
    })?;
    say(&format!("{:7.1}s chose PATH {}", secs(), lane + 1));
    Ok(true)
}

/// Fusion forge (fuse_encounter.gd): two items become one. Every pair
/// the forge accepts (its own refusal check) is staged and both
/// variants read from the game's own preview (variant_preview, the
/// seeded fuse the FUSE button makes). Mine, until the operator sets
/// the rule: fuse the pair whose result most raises gain per cell over
/// the two parts together, and only when the result loses no gain
/// against the two parts.
fn fuse() -> Result<bool, String> {
    enum Look {
        None,
        Acted,
        Judge(Vec<Item>, Vec<(usize, usize, bool, Item)>),
    }
    let look = on_main("auto fuse", || {
        let Some(mut s) = stop("fuse_encounter.gd", 4)? else {
            return Ok(Look::None);
        };
        if flag(&s, "_closed") {
            return Ok(Look::None);
        }
        if flag(&s, "_fused") {
            // finish hands the fused item back (hand_back).
            read::call(&mut s, "finish", &[])?;
            say("  took the fused item");
            return Ok(Look::Acted);
        }
        let mut items = Vec::new();
        for i in owned_items(|_| false)?.iter_mut() {
            items.push(item(i)?);
        }
        Ok(Look::Judge(items, Vec::new()))
    })?;
    let look = match look {
        Look::Judge(items, _) => {
            let made = fuse_previews(&items)?;
            Look::Judge(items, made)
        }
        other => other,
    };
    let (items, made) = match look {
        Look::None => return Ok(false),
        Look::Acted => return Ok(true),
        Look::Judge(i, m) => (i, m),
    };
    let (me, squad) = player_and_foe()?;
    let base = fight::score(&me, &squad, Run::Campaign).margin;
    let worth: Vec<f64> = items
        .iter()
        .map(|it| gain(&me, &squad, base, &it.stats))
        .collect();
    say(&format!(
        "  fuse: judged {} variants of pairs of {} items",
        made.len(),
        items.len()
    ));
    // (a, b, flipped, improvement per cell, result gain, cells)
    let mut best: Option<(usize, usize, bool, f64, f64, usize)> = None;
    for (a, b, flipped, r) in &made {
        let parts = worth[*a] + worth[*b];
        let parts_per_cell = parts / (items[*a].cells + items[*b].cells) as f64;
        let g = gain(&me, &squad, base, &r.stats);
        let up = g / r.cells as f64 - parts_per_cell;
        if g >= parts && up > 0.0 && best.is_none_or(|x| up > x.3) {
            best = Some((*a, *b, *flipped, up, g, r.cells));
        }
    }
    let Some((a, b, flipped, up, g, cells)) = best else {
        leave("no fusion gains per cell over its two parts")?;
        return Ok(true);
    };
    say(&format!(
        "  fuse {} + {} (variant {}): gain {g:.4} in {cells} cells, was {:.4} in {} cells, per cell up {up:.5}",
        items[a].name,
        items[b].name,
        if flipped { 2 } else { 1 },
        worth[a] + worth[b],
        items[a].cells + items[b].cells
    ));
    let (ga, gb) = (items[a].gid.clone(), items[b].gid.clone());
    let fused = on_main("auto fuse act", move || {
        let Some(mut s) = stop("fuse_encounter.gd", 4)? else {
            return Ok(false);
        };
        read::call(
            &mut s,
            "_on_slot_filled",
            &[ga.to_variant(), true.to_variant()],
        )?;
        read::call(
            &mut s,
            "_on_slot_filled",
            &[gb.to_variant(), false.to_variant()],
        )?;
        if flipped {
            read::call(&mut s, "pick_variant", &[true.to_variant()])?;
        }
        let Some(mut btn) = named(&scene()?, "EncounterContinueBtn", 8) else {
            return Err("no FUSE button".into());
        };
        if !pressable(&mut btn) {
            read::call(&mut s, "_clear_slot", &[true.to_variant()])?;
            read::call(&mut s, "_clear_slot", &[false.to_variant()])?;
            return Ok(false);
        }
        pressed(&mut btn, "FUSE")?;
        Ok(true)
    })?;
    if !fused {
        leave("FUSE is not pressable")?;
    }
    Ok(true)
}

/// The forge's preview of every pair it accepts, both variants, as
/// (base, other, flipped, result). In short main-thread passes so the
/// game keeps running between them: one pass over every pair froze the
/// game at the fusion forge (2026-11-17, operator: "on fusion forge the
/// game locks up"). Mine: a pass ends after FUSE_PASS of main-thread
/// time, with both slots cleared.
const FUSE_PASS: Duration = Duration::from_millis(200);

fn fuse_previews(items: &[Item]) -> Result<Vec<(usize, usize, bool, Item)>, String> {
    let ids: Vec<(i64, String)> = items.iter().map(|i| (i.id, i.gid.to_string())).collect();
    let ids = std::sync::Arc::new(ids);
    let mut made = Vec::new();
    let mut at = Some((0usize, 1usize));
    let mut passes = 0;
    let started = Instant::now();
    while let Some((from_a, from_b)) = at {
        let ids = ids.clone();
        let (got, next) = on_main("auto fuse preview", move || {
            let pass = Instant::now();
            let Some(mut s) = stop("fuse_encounter.gd", 4)? else {
                return Ok((Vec::new(), None));
            };
            let objs: Vec<Gd<Object>> = ids
                .iter()
                .map(|(id, _)| object(*id))
                .collect::<Result<_, _>>()?;
            let refused =
                |s: &mut Gd<Object>, i: &Gd<Object>, base: bool| -> Result<bool, String> {
                    Ok(
                        !read::call(s, "_refusal_for", &[i.to_variant(), base.to_variant()])?
                            .stringify()
                            .is_empty(),
                    )
                };
            let stage = |s: &mut Gd<Object>, k: usize, base: bool| {
                read::call(
                    s,
                    "_on_slot_filled",
                    &[
                        GString::from(ids[k].1.as_str()).to_variant(),
                        base.to_variant(),
                    ],
                )
            };
            let mut out = Vec::new();
            let mut next = None;
            'rows: for a in from_a..objs.len() {
                if refused(&mut s, &objs[a], true)? {
                    continue;
                }
                stage(&mut s, a, true)?;
                let first = if a == from_a { from_b } else { a + 1 };
                for b in first.max(a + 1)..objs.len() {
                    if refused(&mut s, &objs[b], false)? {
                        continue;
                    }
                    stage(&mut s, b, false)?;
                    for flipped in [false, true] {
                        if let Ok(mut p) =
                            read::call(&mut s, "variant_preview", &[flipped.to_variant()])?
                                .try_to::<Gd<Object>>()
                        {
                            out.push((a, b, flipped, item(&mut p)?));
                        }
                    }
                    if pass.elapsed() >= FUSE_PASS {
                        next = Some((a, b + 1));
                        break 'rows;
                    }
                }
                // Staging the next b hands this one back (_on_slot_filled).
                read::call(&mut s, "_clear_slot", &[false.to_variant()])?;
                read::call(&mut s, "_clear_slot", &[true.to_variant()])?;
            }
            if next.is_some() {
                read::call(&mut s, "_clear_slot", &[false.to_variant()])?;
                read::call(&mut s, "_clear_slot", &[true.to_variant()])?;
            }
            Ok((out, next))
        })?;
        made.extend(got);
        passes += 1;
        at = next;
    }
    say(&format!(
        "  fuse: previewed by the game in {:.2}s over {passes} passes",
        started.elapsed().as_secs_f64()
    ));
    Ok(made)
}

/// Rune stone (slot_bless_encounter.gd): a 2x2 rune set on the
/// equipment grid works on the worn item covering most of it
/// (slot_bonus.gd active_placement). It goes on the worn item with the
/// most gain per cell, at a spot the game allows (slot_bonus.gd fits: 4
/// open cells, no other rune), through the stop's own placement step.
/// Not yet: which items a rune kind helps (slot_bonus.gd benefits).
fn rune() -> Result<bool, String> {
    type Spot = ((i32, i32), usize, i64);
    let look = on_main("auto rune", || {
        let Some(s) = stop("slot_bless_encounter.gd", 4)? else {
            return Ok(None);
        };
        if flag(&s, "_used") || flag(&s, "_full") {
            return Ok(None);
        }
        let mut global = read::node("/root/Global")?;
        let mut inv = read::inventory()?;
        let size = read::call(&mut inv, "grid_size", &[EQUIP.to_variant()])?
            .try_to::<Vector2i>()
            .map_err(|e| e.to_string())?;
        // Cells under runes already set (keys "c{x}_{y}" are origins).
        let mut runed: Vec<(i32, i32)> = Vec::new();
        if let Ok(map) = read::call(&mut global, "get_slot_bonuses", &[])?.try_to::<AnyDictionary>()
        {
            for key in map.keys_array().iter_shared() {
                let key = key.stringify().to_string();
                let parts: Vec<i32> = key
                    .get(1..)
                    .unwrap_or("")
                    .split('_')
                    .filter_map(|p| p.parse().ok())
                    .collect();
                if let [x, y] = parts[..] {
                    for (dx, dy) in [(0, 0), (1, 0), (0, 1), (1, 1)] {
                        runed.push((x + dx, y + dy));
                    }
                }
            }
        }
        // Worn pieces: the item, its cells, and the game's tie order.
        let mut worn: Vec<(Item, Vec<(i32, i32)>, Vec<i64>)> = Vec::new();
        for p in read::placements(&mut inv, EQUIP)? {
            let Some(mut it) = read::placed_item(&p) else {
                continue;
            };
            let at = |k: &str| p.get(k).map_or(0, |v| int(&v)) as i32;
            let (px, py, rot) = (at("x"), at("y"), at("rot"));
            let cells: Vec<(i32, i32)> = list(read::call(
                &mut it,
                "shape_cells",
                &[(rot as i64).to_variant()],
            )?)
            .into_iter()
            .filter_map(|c| c.try_to::<Vector2i>().ok())
            .map(|c| (px + c.x, py + c.y))
            .collect();
            let rarity = int(&it.get("rarity"));
            let weapon = i64::from(says(&mut it, "is_weapon"));
            let n = cells.len() as i64;
            worn.push((
                item(&mut it)?,
                cells,
                vec![rarity, weapon, n, -(py as i64), -(px as i64)],
            ));
        }
        let mut spots: Vec<Spot> = Vec::new();
        for y in 0..size.y - 1 {
            for x in 0..size.x - 1 {
                let square = [(x, y), (x + 1, y), (x, y + 1), (x + 1, y + 1)];
                let mut ok = true;
                for c in square {
                    if runed.contains(&c)
                        || !yes(&read::call(
                            &mut inv,
                            "cell_open",
                            &[EQUIP.to_variant(), Vector2i::new(c.0, c.1).to_variant()],
                        )?)
                    {
                        ok = false;
                        break;
                    }
                }
                if !ok {
                    continue;
                }
                // slot_bonus.gd active_placement: most cells covered,
                // then rarity, weapon, size, top, left.
                let active = worn
                    .iter()
                    .enumerate()
                    .filter_map(|(i, (_, cells, tie))| {
                        let covered = cells.iter().filter(|c| square.contains(c)).count() as i64;
                        (covered > 0).then(|| {
                            let mut key = vec![covered];
                            key.extend(tie);
                            (i, key)
                        })
                    })
                    .max_by(|a, b| a.1.cmp(&b.1));
                if let Some((i, key)) = active {
                    spots.push(((x, y), i, key[0]));
                }
            }
        }
        Ok(Some((
            worn.into_iter().map(|w| w.0).collect::<Vec<Item>>(),
            spots,
        )))
    })?;
    let Some((items, spots)) = look else {
        return Ok(false);
    };
    let (me, squad) = player_and_foe()?;
    for (i, _) in per_cell(&me, &squad, &items) {
        if let Some(&(origin, _, covered)) = spots.iter().filter(|s| s.1 == i).max_by_key(|s| s.2) {
            say(&format!(
                "  rune on {} at {origin:?} ({covered} cells under it)",
                items[i].name
            ));
            on_main("auto rune place", move || {
                let Some(mut s) = stop("slot_bless_encounter.gd", 4)? else {
                    return Ok(());
                };
                read::call(
                    &mut s,
                    "_on_rune_placed",
                    &[Vector2i::new(origin.0, origin.1).to_variant()],
                )?;
                Ok(())
            })?;
            return Ok(true);
        }
    }
    leave("no spot puts the rune on a worn item")?;
    Ok(true)
}

/// No step acted: CONTINUE on a stop the loop knows, any other waits
/// for the operator; with no stop, START BATTLE then ENTER DEEPER.
fn buttons() -> Result<(), String> {
    let waiting = memory().waiting.clone();
    let now = on_main("auto buttons", move || {
        let crawl = read::crawl()?;
        // The first stop under the crawl screen, 4 levels down.
        fn first_stop(n: &Gd<Node>, depth: u32) -> Option<String> {
            for c in n.get_children().iter_shared() {
                if let Some(s) = target::script_path(&c.clone().upcast())
                    && s.ends_with("_encounter.gd")
                {
                    return Some(s.rsplit('/').next().unwrap_or(&s).to_string());
                }
                if depth > 1
                    && let Some(s) = first_stop(&c, depth - 1)
                {
                    return Some(s);
                }
            }
            None
        }
        if let Some(stop) = first_stop(&crawl, 4) {
            if !HANDLED.contains(&stop.as_str()) {
                if waiting != stop {
                    say(&format!(
                        "waiting: {stop} is not handled yet, play it yourself"
                    ));
                }
                return Ok(stop);
            }
            if let Some(mut b) = named(&crawl, "EncounterContinueBtn", 4)
                && pressable(&mut b)
            {
                pressed(&mut b, &format!("CONTINUE ({stop})"))?;
            }
            return Ok(String::new());
        }
        for name in BAR {
            if let Some(mut b) = named(&crawl, name, 4)
                && pressable(&mut b)
            {
                pressed(&mut b, name)?;
                break;
            }
        }
        Ok(String::new())
    })?;
    memory().waiting = now;
    Ok(())
}

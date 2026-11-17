//! Plays Dungeonbound on its own through the game's own buttons.
//!
//! Operator 2026-11-16: "I WANT FATURES THAT AUTOMAT", "AUTOMATE THE
//! GAME". Each step it looks at the crawl screen and presses what the
//! game would have the player press, the way the game itself presses
//! them (`pressed.emit()`, crawl.gd:450):
//! - loot up: AUTO PICK when there is a choice of two (the game's own
//!   pick, the higher stat score), then CLAIM ALL; SELL ALL when the
//!   bag is full
//! - START BATTLE, then ENTER DEEPER, when shown
//! - genie: the wish that most raises the chance to beat the floor's
//!   guardian, by the mod's own fight math (src/fight.rs)
//! - equipment: rows bought and pieces packed inside the game by the
//!   mod's arrange step (src/arrange.rs), which returns its reasoning.
//!   Operator 2026-11-16: "when we loot stuff we also have to move it
//!   into equipment", "that includes placment which might mean
//!   rotation".
//! - chest: open it; campsite: continue
//! - any other stop: wait for the operator. Operator 2026-11-16: "we
//!   shouldnt skip over stuff unless there'a a reason"
//!
//! Not yet: the mod's own success rate gate (the rate is not trusted
//! yet), buying, fusing, loadout.
//!
//! Run with the game up: `dungeonbound-auto`. Ctrl+C stops it.

use std::thread::sleep;
use std::time::{Duration, Instant};

use dungeonbound_mod::fight::{self, Fighter, Run};
use dungeonbound_mod::items::{ITEM_STATS, apply_bonus, stats_from};
use modforge::client::Api;
use serde_json::{Value, json};

const SCENE: &str = "/root/@Control@65/CurrentScene";
const TICK: Duration = Duration::from_millis(700);
/// Buttons pressed in this order when no stop is up.
const BAR: [&str; 2] = ["StartBattleBtn", "EnterDeeperBtn"];
/// Stops the bot plays: CONTINUE is the right press. Chest: CONTINUE
/// opens it (an item, against SKIP's 10 gold), then closes it.
/// Campsite: it heals on entry, CONTINUE leaves. Genie: CONTINUE
/// once the wish is chosen. Blessing: granted on entry
/// (bless_encounter.gd _ready, Global.grant_blessing), no choice.
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

struct Game {
    api: Api<Value>,
    start: Instant,
    /// The unhandled stop already announced.
    waiting: std::cell::RefCell<String>,
    /// The last guardian and player line printed.
    judged: std::cell::RefCell<String>,
    /// The shop already bought from.
    shop_done: std::cell::RefCell<Value>,
    /// The item stop already used once.
    shrine_done: std::cell::RefCell<Value>,
    /// The shop on screen and the gold held when it opened.
    shop_entry: std::cell::RefCell<(Value, i64)>,
    /// The fight on now was predicted.
    predicted: std::cell::RefCell<bool>,
    /// The strongest foe of the last fight, for judging when no
    /// guardian is prepared.
    last_foe: std::cell::RefCell<Option<Fighter>>,
}

/// Share of the gold held on entering a shop that is kept.
const KEEP_GOLD: f64 = 0.25;

/// Inventory grids (inventory.gd).
const EQUIP: i64 = 0;
const BAG: i64 = 1;
const TRAY: i64 = 2;

impl Game {
    fn op(&self, name: &str, args: Value) -> Result<Value, String> {
        let r = self.api.try_op(name, args)?;
        if r.ok {
            Ok(r.result)
        } else {
            Err(format!("{name}: {:?}", r.error))
        }
    }

    fn prop(&self, target: &Value, property: &str) -> Result<Value, String> {
        let mut args = target.clone();
        args["property"] = json!(property);
        args["depth"] = json!(0);
        Ok(self.op("get_property", args)?["value"].clone())
    }

    fn call(&self, target: &Value, method: &str, args: Value) -> Result<Value, String> {
        let mut a = target.clone();
        a["method"] = json!(method);
        a["args"] = args;
        // 2: a placement row's item shows its id (research_loot.rs).
        a["depth"] = json!(2);
        Ok(self.op("call_method", a)?["result"].clone())
    }

    /// Shown on screen and not disabled.
    fn pressable(&self, button: &Value) -> bool {
        self.call(button, "is_visible_in_tree", json!([])) == Ok(json!(true))
            && self.prop(button, "disabled") != Ok(json!(true))
    }

    fn press(&self, button: &Value, label: &str) -> Result<(), String> {
        self.call(button, "emit_signal", json!(["pressed"]))?;
        println!(
            "[auto] {:7.1}s pressed {label}",
            self.start.elapsed().as_secs_f64()
        );
        Ok(())
    }

    /// The crawl screen's node (crawl.gd).
    fn crawl(&self) -> Result<Value, String> {
        let tree = self.op("tree", json!({"node": SCENE, "depth": 2}))?;
        tree["nodes"]
            .as_array()
            .into_iter()
            .flatten()
            .find(|n| {
                n["script"]
                    .as_str()
                    .is_some_and(|s| s.ends_with("/crawl.gd"))
            })
            .map(|n| json!({"id": n["id"]}))
            .ok_or_else(|| "no crawl screen".to_string())
    }

    /// Loot up: choose, claim, or sell when the bag is full. True when
    /// it acted.
    fn loot(&self, crawl: &Value) -> Result<bool, String> {
        let holder = json!({"id": self.prop(crawl, "_loot_holder")?["id"]});
        if self.call(&holder, "is_visible_in_tree", json!([]))? != json!(true) {
            return Ok(false);
        }
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let left = |inv: &Value| -> Result<(bool, usize), String> {
            let pick = self.call(inv, "has_pick", json!([]))? == json!(true);
            let tray = self
                .call(inv, "placements_in", json!([TRAY]))?
                .as_array()
                .map_or(0, Vec::len);
            Ok((pick, tray))
        };
        let (pick, tray) = left(&inv)?;
        // Operator 2026-11-16: "if we cant claim loot for oom then we
        // gotta sell it right???", "we gotta check free sapc eright??".
        // Before claiming, every tray item must have a spot in the bag
        // (the game's first_fit); if one does not, the least gain per
        // cell of bag and tray is sold first.
        if !pick && tray > 0 {
            let loot = self.owned(&inv, &[TRAY])?;
            let mut room = true;
            for item in &loot {
                if self
                    .call(&inv, "first_fit", json!([item, BAG]))?
                    .as_object()
                    .is_none_or(|o| o.is_empty())
                {
                    room = false;
                    break;
                }
            }
            if !room {
                let loose = self.owned(&inv, &[BAG, TRAY])?;
                if let Some((i, pc)) = self.per_cell(crawl, &loose)?.last() {
                    let item = &loose[*i];
                    let id = self.prop(item, "id")?;
                    let ok =
                        self.call(&json!({"node": "/root/Global"}), "sell_item", json!([id]))?
                            == json!(true);
                    println!(
                        "[auto]   no room in the bag: sold {} (gain per cell {pc:.5}, the least of {} loose): {ok}",
                        self.item_name(item),
                        loose.len()
                    );
                    return Ok(true);
                }
            }
        }
        let mut pressed = false;
        for (var, label, want) in [
            ("_loot_auto_btn", "AUTO PICK", pick),
            ("_loot_claim_btn", "CLAIM ALL", tray > 0),
        ] {
            let b = json!({"id": self.prop(crawl, var)?["id"]});
            if want && self.pressable(&b) {
                self.press(&b, label)?;
                pressed = true;
                break;
            }
        }
        if !pressed {
            return Ok(false);
        }
        // The bag and tray have limited room (the game: "No room in
        // your bag"). When the loot did not all go in, the loose item
        // with the least gain per cell (bag or tray) is sold through
        // the game's own sell, one per step, until it fits.
        let (pick2, tray2) = left(&inv)?;
        if (pick && pick2) || (!pick && tray2 >= tray && tray2 > 0) {
            let loose = self.owned(&inv, &[BAG, TRAY])?;
            let ranked = self.per_cell(crawl, &loose)?;
            if let Some((i, pc)) = ranked.last() {
                let item = &loose[*i];
                let id = self.prop(item, "id")?;
                let ok = self.call(&json!({"node": "/root/Global"}), "sell_item", json!([id]))?
                    == json!(true);
                println!(
                    "[auto]   bag full: sold {} (gain per cell {pc:.5}, the least of {} loose): {ok}",
                    self.item_name(item),
                    loose.len()
                );
            }
        }
        Ok(true)
    }

    /// An object's script variables by name.
    fn vars(&self, id: &Value) -> Result<serde_json::Map<String, Value>, String> {
        let got = self.op("inspect", json!({"id": id, "depth": 0}))?;
        Ok(got["properties"]
            .as_array()
            .into_iter()
            .flatten()
            .filter(|p| p["script"] == json!(true))
            .filter_map(|p| Some((p["name"].as_str()?.to_string(), p["value"].clone())))
            .collect())
    }

    /// The first node under `under` whose script ends with `script`.
    fn find(&self, under: &Value, script: &str, depth: u32) -> Result<Option<Value>, String> {
        let mut a = under.clone();
        a["depth"] = json!(depth);
        let tree = self.op("tree", a)?;
        Ok(tree["nodes"]
            .as_array()
            .into_iter()
            .flatten()
            .find(|n| n["script"].as_str().is_some_and(|s| s.ends_with(script)))
            .map(|n| json!({"id": n["id"]})))
    }

    /// The player at full hp and the floor's guardian, for choices
    /// that last: they are judged by the fight that ends the floor.
    fn player_and_guardian(&self, crawl: &Value) -> Result<(Fighter, Vec<Fighter>), String> {
        let run = self.prop(&json!({"node": "/root/Global"}), "current_run")?;
        let player = self.prop(&json!({"id": run["id"]}), "player")?;
        let mut me = fight::from_vars("Player", &self.vars(&player["id"])?);
        me.hp = me.max_hp;
        me.block = me.block_max;
        // No guardian prepared (it was just fought): judge against the
        // last fight's foes as the game built them.
        let g = match self.guardian(crawl) {
            Ok(g) => g,
            Err(e) => {
                let mut last = self.last_foe.borrow().clone().ok_or(e)?;
                last.hp = last.max_hp;
                last.block = last.block_max;
                last
            }
        };
        let line = format!(
            "[auto]   judged against {} hp {} atk {} block {} speed {:.1}; player hp {} atk {} block {} speed {:.1}",
            g.name,
            g.max_hp,
            g.atk,
            g.block_max,
            g.speed,
            me.max_hp,
            me.atk,
            me.block_max,
            me.speed
        );
        if *self.judged.borrow() != line {
            println!("{line}");
            *self.judged.borrow_mut() = line;
        }
        Ok((me, vec![g]))
    }

    /// The floor's guardian as the game builds it for the fight
    /// (combat_resolver.gd load_fight, CombatantRuntime.from_enemy),
    /// campaign only: stats times the floor scale (hp also times the
    /// dungeon's hp scale), an elite's power norm and attack ease, the
    /// dungeon's attack scale, block chance 1. Speed is the mean of
    /// the game's roll (base + randi -3..5). Not yet: the campaign
    /// magic resist bonus per dungeon.
    fn guardian(&self, crawl: &Value) -> Result<Fighter, String> {
        let resolver = self
            .find(crawl, "combat_resolver.gd", 1)?
            .ok_or("no combat resolver")?;
        let data = self.prop(&resolver, "_guardian")?;
        if data.is_null() || data["id"].is_null() {
            return Err("no guardian prepared yet".into());
        }
        let data = json!({"id": data["id"]});
        let run = json!({"id": self.prop(&resolver, "run")?["id"]});
        if self.prop(&run, "is_roguelite")? == json!(true) {
            return Err("guardian build is campaign only".into());
        }
        let floor = self.prop(&run, "floor_number")?.as_i64().unwrap_or(1);
        let db = json!({"node": "/root/DungeonDB"});
        let dungeon = json!({"id": self.call(&db, "floor_dungeon", json!([run]))?["id"]});
        let num = |v: Value| v.as_f64().unwrap_or(1.0);
        let floor_scale = num(self.call(&resolver, "_floor_scale", json!([dungeon]))?);
        let hp_scale = num(self.prop(&dungeon, "hp_scale_base")?);
        let atk_scale = num(self.prop(&dungeon, "atk_scale")?);
        let stats = json!({"id": self.prop(&data, "stats")?["id"]});
        let mut vars = self.vars(&stats["id"])?;
        for (k, v) in self.vars(&data["id"])? {
            if k == "double_dmg_chance" {
                vars.insert(k, v);
            }
        }
        let mut g = fight::from_vars(&self.item_name(&data), &vars);
        g.max_hp = ((g.max_hp as f64 * floor_scale * hp_scale).round() as i64).max(1);
        g.atk = ((g.atk as f64 * floor_scale).round() as i64).max(1);
        // EnemyCombatData LootBand: REGULAR 0, ELITE 1, BOSS 2.
        if self.prop(&data, "loot_band")? == json!(1) {
            let norm = self.call(&db, "power_norm", json!([data, dungeon]))?;
            g.max_hp = ((g.max_hp as f64 * num(norm["hp"].clone())).round() as i64).max(1);
            g.atk = ((g.atk as f64 * num(norm["atk"].clone())).round() as i64).max(1);
        }
        if (atk_scale - 1.0).abs() > 1e-9 {
            g.atk = ((g.atk as f64 * atk_scale).round() as i64).max(1);
        }
        if self.prop(&data, "loot_band")? == json!(1) {
            let ease = self.prop(&dungeon, "elite_atk_ease")?;
            if let Some(e) = ease.as_array().and_then(|a| a.get(floor as usize - 1)) {
                g.atk = ((g.atk as f64 * num(e.clone())).round() as i64).max(1);
            }
        }
        g.speed = (g.speed + 1.0).max(1.0);
        g.block_chance = 1.0;
        g.hp = g.max_hp;
        g.block = g.block_max;
        Ok(g)
    }

    /// Dismantle: one item ground to dust for 60% of its plain stats,
    /// permanently (dismantle_encounter.gd absorbed). Operator
    /// 2026-11-16: "we should do it for the best overall gain /
    /// whatver the item is". Every item, worn or loose, is a choice;
    /// the gain is judged by the fight math. The game's own drop
    /// (item_shrine.gd _on_item_dropped) stages it, DISMANTLE acts.
    fn dismantle(&self, crawl: &Value) -> Result<bool, String> {
        let Some(stop) = self.find(&json!({"node": SCENE}), "dismantle_encounter.gd", 4)? else {
            return Ok(false);
        };
        if self.prop(&stop, "_used")? == json!(true) {
            return Ok(false);
        }
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let mut items: Vec<(Value, Value)> = Vec::new();
        for grid in [EQUIP, BAG, TRAY] {
            for p in self
                .call(&inv, "placements_in", json!([grid]))?
                .as_array()
                .into_iter()
                .flatten()
            {
                let item = json!({"id": p["item"]["id"]});
                if items.iter().any(|(i, _)| *i == item)
                    || self.call(&item, "is_gem", json!([]))? == json!(true)
                    || self.call(&item, "is_tome", json!([]))? == json!(true)
                    // ItemType CONSUMABLE 2 (equipment_item.gd).
                    || self.prop(&item, "item_type")? == json!(2)
                {
                    continue;
                }
                let gains = self.call(&stop, "absorbed", json!([item]))?;
                if gains.as_array().is_some_and(|g| !g.is_empty()) {
                    items.push((item, gains));
                }
            }
        }
        let (me, squad) = self.player_and_guardian(crawl)?;
        let ranked = fight::rank(&me, &squad, Run::Campaign, &items, |p, (_, gains)| {
            for g in gains.as_array().into_iter().flatten() {
                apply_bonus(p, g[0].as_str().unwrap_or(""), g[1].as_f64().unwrap_or(0.0));
            }
        });
        for (i, s) in &ranked {
            let (item, _) = &items[*i];
            let Some(act) = self.stage(&stop, item)? else {
                continue;
            };
            println!(
                "[auto]   dismantle {}: {} -> win {:.1}% hp left {:.0}%",
                self.item_name(item),
                items[*i].1,
                s.win * 100.0,
                s.hp_left * 100.0
            );
            self.press(&act, "DISMANTLE")?;
            return Ok(true);
        }
        self.leave("nothing to dismantle")?;
        Ok(true)
    }

    /// An item stop (item_shrine.gd): the game's own drop stages the
    /// item. Returns the act button when the stop takes it and it is
    /// free (use_cost 0).
    fn stage(&self, stop: &Value, item: &Value) -> Result<Option<Value>, String> {
        let id = self.prop(item, "id")?;
        self.call(stop, "_on_item_dropped", json!([id]))?;
        let Some(act) = self.named("EncounterContinueBtn")? else {
            return Ok(None);
        };
        if !self.pressable(&act) {
            println!("[auto]   {} refused", self.item_name(item));
            return Ok(None);
        }
        let cost = self
            .call(stop, "use_cost", json!([]))?
            .as_i64()
            .unwrap_or(0);
        if cost > 0 {
            println!(
                "[auto]   {} would cost {cost} gold; not paying",
                self.item_name(item)
            );
            return Ok(None);
        }
        Ok(Some(act))
    }

    /// Leave a stop with SKIP (or LEAVE after a use), giving the reason.
    fn leave(&self, why: &str) -> Result<(), String> {
        if let Some(skip) = self.named("EncounterSkipBtn")?
            && self.pressable(&skip)
        {
            self.press(&skip, &format!("SKIP ({why})"))?;
        }
        Ok(())
    }

    /// Gamble (gamble_encounter.gd): a wheel on one item, break 17%,
    /// curse 23%, affinity 20%, upgrade 30%, jackpot 10%. Operator
    /// 2026-11-16: "we should be gambling the items that can give us
    /// the most gain per slot", "making wure each grid in equipment
    /// gfives most stats possible". Every item, worn or loose, ranked
    /// by gain per cell (`per_cell`). Free uses only; one spin per
    /// stop, then leave.
    ///
    /// The same flow serves every item stop (item_shrine.gd): stage
    /// an item with the game's own drop, act, then CONTINUE or the
    /// stop's own finish. Each stop only says which items, best first:
    /// - gamble, altar (UPGRADE: the item a level up), sanctify (a
    ///   blessing on the item): every item by gain per cell
    /// - curse: the offer's boon and bane judged on the player; taken
    ///   on a worn item only when the fight margin goes up
    /// - attune (needs a tag choice) and unsocket (takes gems off):
    ///   not judged yet, left with the reason
    fn item_stop(&self, crawl: &Value) -> Result<bool, String> {
        let scene = json!({"node": SCENE});
        let mut found = None;
        for (script, label) in [
            ("gamble_encounter.gd", "GAMBLE"),
            ("altar_encounter.gd", "UPGRADE"),
            ("sanctify_encounter.gd", "SANCTIFY"),
            ("curse_encounter.gd", "CURSE"),
            ("attune_encounter.gd", "ATTUNE"),
            ("unsocket_encounter.gd", "UNSOCKET"),
        ] {
            if let Some(stop) = self.find(&scene, script, 4)? {
                found = Some((stop, label));
                break;
            }
        }
        let Some((stop, label)) = found else {
            return Ok(false);
        };
        if self.prop(&stop, "_spinning")? == json!(true) {
            return Ok(true);
        }
        if *self.shrine_done.borrow() == stop || self.prop(&stop, "_used")? == json!(true) {
            // After the spin the act button is CONTINUE (item_shrine.gd
            // _act_consume / _act); when a paid reuse is offered
            // instead, SKIP reads LEAVE.
            let used = self.prop(&stop, "_used")? == json!(true);
            if let Some(b) = self.named("EncounterContinueBtn")?
                && used
                && self.pressable(&b)
            {
                self.press(&b, &format!("CONTINUE ({label})"))?;
            } else if used && !self.prop(&stop, "_held")?.is_null() {
                // The result waits on the stop to be dragged back and
                // CONTINUE stays off until then (item_shrine.gd _act).
                // The stop's own finish hands it back to the inventory
                // (hand_back), as CONTINUE would.
                self.call(&stop, "finish", json!([]))?;
                println!(
                    "[auto] {:7.1}s closed {label}; result handed back",
                    self.start.elapsed().as_secs_f64()
                );
            } else {
                self.leave("used once")?;
            }
            return Ok(true);
        }
        if label == "ATTUNE" || label == "UNSOCKET" {
            self.leave(&format!("{label} is not judged yet"))?;
            return Ok(true);
        }
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let mut items: Vec<Value> = Vec::new();
        for grid in [EQUIP, BAG, TRAY] {
            for p in self
                .call(&inv, "placements_in", json!([grid]))?
                .as_array()
                .into_iter()
                .flatten()
            {
                let item = json!({"id": p["item"]["id"]});
                if !items.contains(&item) {
                    items.push(item);
                }
            }
        }
        let mut ranked = self.per_cell(crawl, &items)?;
        if label == "CURSE" {
            let mut o = stop.clone();
            o["property"] = json!("_offer");
            o["depth"] = json!(4);
            let offer = self.op("get_property", o)?["value"].clone();
            let (me, squad) = self.player_and_guardian(crawl)?;
            let base = fight::score(&me, &squad, Run::Campaign).margin;
            let mut p = me.clone();
            for side in ["boon", "bane"] {
                let stat = offer[side]["stat"].as_str().unwrap_or("");
                if let Some((_, to)) = ITEM_STATS.iter().find(|(f, _)| *f == stat) {
                    apply_bonus(&mut p, to, offer[side]["amount"].as_f64().unwrap_or(0.0));
                }
            }
            let gain = fight::score(&p, &squad, Run::Campaign).margin - base;
            println!(
                "[auto]   curse offer boon {} bane {}: margin change {gain:.4}",
                offer["boon"], offer["bane"]
            );
            if gain <= 0.0 {
                self.leave("the curse loses more than it gives")?;
                return Ok(true);
            }
            // On a worn item, so it counts now.
            let worn = self.call(&inv, "get_equipped_list", json!([]))?;
            let worn: Vec<Value> = worn
                .as_array()
                .into_iter()
                .flatten()
                .map(|w| json!({"id": w["id"]}))
                .collect();
            ranked.retain(|(i, _)| worn.contains(&items[*i]));
        }
        for (i, gain) in &ranked {
            let item = &items[*i];
            println!("[auto]   {}: gain per cell {gain:.4}", self.item_name(item));
        }
        for (i, _) in &ranked {
            let item = &items[*i];
            if let Some(act) = self.stage(&stop, item)? {
                *self.shrine_done.borrow_mut() = stop.clone();
                return self
                    .press(&act, &format!("{label} {}", self.item_name(item)))
                    .map(|()| true);
            }
        }
        self.leave(&format!("no item {label} takes for free"))?;
        Ok(true)
    }

    /// The fork (crawl.gd, "CHOOSE YOUR PATH"): each lane's stops come
    /// from the floor plan (floor_plan.gd path_stops: kind, unknown).
    /// Mine, until the operator sets the rule: the lane with the most
    /// treasure, shrine and unknown stops (unknown is half shrines,
    /// floor_plan.gd UNKNOWN_ODDS), then the fewest elites. Picked
    /// through the PATH button's own step (_choose_next_lane).
    fn fork(&self, crawl: &Value) -> Result<bool, String> {
        let panel = self.prop(crawl, "_fork_panel")?;
        if panel.is_null() || panel["id"].is_null() {
            return Ok(false);
        }
        let panel = json!({"id": panel["id"]});
        if self.call(&panel, "is_visible_in_tree", json!([])) != Ok(json!(true)) {
            return Ok(false);
        }
        let mut a = crawl.clone();
        a["property"] = json!("_ahead");
        a["depth"] = json!(1);
        let ahead = self.op("get_property", a)?["value"].clone();
        let plan = json!({"id": ahead["plan"]["id"]});
        let lanes = self
            .call(&plan, "all_routes", json!([]))?
            .as_array()
            .map_or(0, Vec::len);
        // DungeonLayout Content: ENEMY 1, ELITE 2, SHRINE 6, TREASURE 7, SHOP 8.
        // Operator 2026-11-16: "find best success rate then do it. tahts
        // the rule". A lane's success rate is the chance to win each of
        // its fights in a row. Mine, as the foes of a lane are rolled
        // only when entered: an enemy stop is judged as the strongest
        // foe of the last fight, an elite as the floor's guardian, and
        // an unknown stop is a fight 25% of the time (floor_plan.gd
        // UNKNOWN_ODDS ENEMY 25).
        let (p_enemy, p_elite) = match self.player_and_guardian(crawl) {
            Ok((me, guard)) => {
                let p_elite = fight::score(&me, &guard, Run::Campaign).win;
                let p_enemy = self.last_foe.borrow().clone().map_or(p_elite, |mut f| {
                    f.hp = f.max_hp;
                    f.block = f.block_max;
                    fight::score(&me, &[f], Run::Campaign).win
                });
                (p_enemy, p_elite)
            }
            Err(e) => {
                println!("[auto]   path: no foe to judge ({e}); success rates unknown");
                (1.0, 1.0)
            }
        };
        let mut best: Option<(usize, (f64, i64, i64))> = None;
        for lane in 0..lanes {
            let stops = self.call(&plan, "path_stops", json!([lane]))?;
            let mut good = 0;
            let mut elites = 0;
            let mut seen = Vec::new();
            let mut rate = 1.0f64;
            for s in stops.as_array().into_iter().flatten() {
                let kind = s["kind"].as_i64().unwrap_or(0);
                let unknown = s["unknown"] == json!(true);
                // DungeonLayout Content: ENEMY 1, ELITE 2, CHALLENGER 9.
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
            println!(
                "[auto]   path {}: stops {seen:?} success {:.1}% good {good} elites {elites}",
                lane + 1,
                rate * 100.0
            );
            // Best success rate; on a tie (within 0.1%), the most good
            // stops, then the fewest elites (mine).
            let key = (((rate * 1000.0).round()) / 1000.0, good, -elites);
            if best.is_none_or(|(_, k)| key.partial_cmp(&k).is_some_and(|o| o.is_gt())) {
                best = Some((lane, key));
            }
        }
        let Some((lane, _)) = best else {
            return Ok(false);
        };
        self.call(crawl, "_choose_next_lane", json!([lane]))?;
        println!(
            "[auto] {:7.1}s chose PATH {}",
            self.start.elapsed().as_secs_f64(),
            lane + 1
        );
        Ok(true)
    }

    /// Rune stone (slot_bless_encounter.gd): a 2x2 rune set on the
    /// equipment grid works on the worn item covering most of it
    /// (slot_bonus.gd active_placement). It goes on the worn item that
    /// adds the most to the fight, at a spot the game allows
    /// (slot_bonus.gd fits: 4 open cells, no other rune), through the
    /// stop's own placement step. Not yet: which items a rune kind
    /// helps (slot_bonus.gd benefits).
    fn rune(&self, crawl: &Value) -> Result<bool, String> {
        let Some(stop) = self.find(&json!({"node": SCENE}), "slot_bless_encounter.gd", 4)? else {
            return Ok(false);
        };
        if self.prop(&stop, "_used")? == json!(true) || self.prop(&stop, "_full")? == json!(true) {
            return Ok(false);
        }
        let global = json!({"node": "/root/Global"});
        let inv = json!({"id": self.prop(&global, "inventory")?["id"]});
        let size = self.call(&inv, "grid_size", json!([EQUIP]))?;
        let xy = |v: &Value| -> (i64, i64) {
            match v {
                Value::Array(a) => (a[0].as_i64().unwrap_or(0), a[1].as_i64().unwrap_or(0)),
                _ => (v["x"].as_i64().unwrap_or(0), v["y"].as_i64().unwrap_or(0)),
            }
        };
        let (w, h) = xy(&size);
        // Cells under runes already set (keys "c{x}_{y}" are origins).
        let mut runed: Vec<(i64, i64)> = Vec::new();
        let map = self.call(&global, "get_slot_bonuses", json!([]))?;
        for key in map.as_object().into_iter().flatten().map(|(k, _)| k) {
            let parts: Vec<i64> = key[1..].split('_').filter_map(|p| p.parse().ok()).collect();
            if let [x, y] = parts[..] {
                for (dx, dy) in [(0, 0), (1, 0), (0, 1), (1, 1)] {
                    runed.push((x + dx, y + dy));
                }
            }
        }
        // Worn pieces: item, cells, and the game's tie order.
        let mut worn: Vec<(Value, Vec<(i64, i64)>, Vec<i64>)> = Vec::new();
        for p in self
            .call(&inv, "placements_in", json!([EQUIP]))?
            .as_array()
            .into_iter()
            .flatten()
        {
            let item = json!({"id": p["item"]["id"]});
            let (px, py) = (p["x"].as_i64().unwrap_or(0), p["y"].as_i64().unwrap_or(0));
            let rot = p["rot"].as_i64().unwrap_or(0);
            let cells: Vec<(i64, i64)> = self
                .call(&item, "shape_cells", json!([rot]))?
                .as_array()
                .into_iter()
                .flatten()
                .map(|c| {
                    let (cx, cy) = xy(c);
                    (px + cx, py + cy)
                })
                .collect();
            let rarity = self.prop(&item, "rarity")?.as_i64().unwrap_or(0);
            let weapon = i64::from(self.call(&item, "is_weapon", json!([]))? == json!(true));
            worn.push((
                item,
                cells.clone(),
                vec![rarity, weapon, cells.len() as i64, -py, -px],
            ));
        }
        let mut spots: Vec<((i64, i64), usize, i64)> = Vec::new();
        for y in 0..h - 1 {
            for x in 0..w - 1 {
                let square = [(x, y), (x + 1, y), (x, y + 1), (x + 1, y + 1)];
                let mut ok = true;
                for c in square {
                    if runed.contains(&c)
                        || self.call(&inv, "cell_open", json!([EQUIP, [c.0, c.1]]))? != json!(true)
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
        let items: Vec<Value> = worn.iter().map(|(i, _, _)| i.clone()).collect();
        let ranked = self.per_cell(crawl, &items)?;
        for (i, _) in &ranked {
            if let Some((origin, _, covered)) =
                spots.iter().filter(|s| s.1 == *i).max_by_key(|s| s.2)
            {
                println!(
                    "[auto]   rune on {} at {:?} ({covered} cells under it)",
                    self.item_name(&items[*i]),
                    origin
                );
                self.call(&stop, "_on_rune_placed", json!([[origin.0, origin.1]]))?;
                return Ok(true);
            }
        }
        self.leave("no spot puts the rune on a worn item")?;
        Ok(true)
    }

    /// Items ranked by gain per grid cell, best first: the fight
    /// margin its plain stats add to the player, over the cells its
    /// shape takes (EquipmentItem shape_cells). The one measure of
    /// how well an item uses its space.
    fn per_cell(&self, crawl: &Value, items: &[Value]) -> Result<Vec<(usize, f64)>, String> {
        Ok(self
            .worth(crawl, items)?
            .into_iter()
            .map(|(i, gain, cells)| (i, gain / cells as f64))
            .collect())
    }

    /// The one judge for an item: the fight margin its plain stats add
    /// to the player as it stands now, and its grid cells. Best gain
    /// per cell first.
    fn worth(&self, crawl: &Value, items: &[Value]) -> Result<Vec<(usize, f64, usize)>, String> {
        let (me, squad) = self.player_and_guardian(crawl)?;
        let base = fight::score(&me, &squad, Run::Campaign).margin;
        let mut out = Vec::new();
        for (i, item) in items.iter().enumerate() {
            let cells = self
                .call(item, "shape_cells", json!([0]))?
                .as_array()
                .map_or(1, |c| c.len().max(1));
            let mut p = me.clone();
            for (stat, v) in self.item_stats(item)? {
                apply_bonus(&mut p, stat, v);
            }
            let gain = fight::score(&p, &squad, Run::Campaign).margin - base;
            out.push((i, gain, cells));
        }
        out.sort_by(|a, b| (b.1 / b.2 as f64).total_cmp(&(a.1 / a.2 as f64)));
        Ok(out)
    }

    /// Owned items on the equipment, bag and tray grids, each once.
    fn owned(&self, inv: &Value, grids: &[i64]) -> Result<Vec<Value>, String> {
        let mut out = Vec::new();
        for grid in grids {
            for p in self
                .call(inv, "placements_in", json!([grid]))?
                .as_array()
                .into_iter()
                .flatten()
            {
                let item = json!({"id": p["item"]["id"]});
                if !out.contains(&item) {
                    out.push(item);
                }
            }
        }
        Ok(out)
    }

    /// Fusion forge (fuse_encounter.gd): two items become one. Every
    /// pair the forge accepts (its own refusal check) is staged and both
    /// variants read from the game's own preview (variant_preview, the
    /// seeded fuse the FUSE button makes). Judged by the one item judge.
    /// Mine, until the operator sets the rule: fuse the pair whose
    /// result most raises gain per cell over the two parts together,
    /// and only when the result loses no gain against the two parts.
    fn fuse(&self, crawl: &Value) -> Result<bool, String> {
        let Some(stop) = self.find(&json!({"node": SCENE}), "fuse_encounter.gd", 4)? else {
            return Ok(false);
        };
        if self.prop(&stop, "_closed")? == json!(true) {
            return Ok(false);
        }
        if self.prop(&stop, "_fused")? == json!(true) {
            // finish hands the fused item back (hand_back).
            self.call(&stop, "finish", json!([]))?;
            println!("[auto]   took the fused item");
            return Ok(true);
        }
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let items = self.owned(&inv, &[EQUIP, BAG, TRAY])?;
        let mut gain = vec![(0.0, 1usize); items.len()];
        for (i, g, c) in self.worth(crawl, &items)? {
            gain[i] = (g, c);
        }
        let ids: Vec<String> = items
            .iter()
            .map(|it| {
                self.prop(it, "id")
                    .ok()
                    .and_then(|v| v.as_str().map(str::to_string))
                    .unwrap_or_default()
            })
            .collect();
        let (me, squad) = self.player_and_guardian(crawl)?;
        let base = fight::score(&me, &squad, Run::Campaign).margin;
        // The preview is freed after the call, so its stats and cells
        // are read inside it (call_method `read`).
        let mut read: Vec<Value> = ITEM_STATS.iter().map(|(f, _)| json!(f)).collect();
        read.push(json!({"method": "shape_cells", "args": [0]}));
        read.push(json!("display_name"));
        let preview = |flipped: bool| -> Result<Option<(f64, usize)>, String> {
            let got = self.op(
                "call_method",
                json!({"id": stop["id"], "method": "variant_preview", "args": [flipped], "read": read, "depth": 1}),
            )?;
            let r = got["read"].as_object().cloned().unwrap_or_default();
            if r.is_empty() {
                return Ok(None);
            }
            let cells = r["shape_cells"].as_array().map_or(1, |c| c.len().max(1));
            let mut p = me.clone();
            for (stat, v) in stats_from(&r) {
                apply_bonus(&mut p, stat, v);
            }
            Ok(Some((
                fight::score(&p, &squad, Run::Campaign).margin - base,
                cells,
            )))
        };
        // (a, b, flipped, improvement per cell, result gain, cells)
        let mut best: Option<(usize, usize, bool, f64, f64, usize)> = None;
        // Each pair once: the second variant is the other item as base.
        println!("[auto]   fuse: judging pairs of {} items", items.len());
        for a in 0..items.len() {
            if self.call(&stop, "_refusal_for", json!([items[a], true]))? != json!("") {
                continue;
            }
            println!(
                "[auto]     pairs with {} ({}/{})",
                self.item_name(&items[a]),
                a + 1,
                items.len()
            );
            self.call(&stop, "_on_slot_filled", json!([ids[a], true]))?;
            for b in a + 1..items.len() {
                if self.call(&stop, "_refusal_for", json!([items[b], false]))? != json!("") {
                    continue;
                }
                self.call(&stop, "_on_slot_filled", json!([ids[b], false]))?;
                let parts = gain[a].0 + gain[b].0;
                let parts_per_cell = parts / (gain[a].1 + gain[b].1) as f64;
                for flipped in [false, true] {
                    let Some((g, cells)) = preview(flipped)? else {
                        continue;
                    };
                    let up = g / cells as f64 - parts_per_cell;
                    if g >= parts && up > 0.0 && best.is_none_or(|x| up > x.3) {
                        best = Some((a, b, flipped, up, g, cells));
                    }
                }
            }
            // Staging the next b hands this one back (_on_slot_filled).
            self.call(&stop, "_clear_slot", json!([false]))?;
            self.call(&stop, "_clear_slot", json!([true]))?;
        }
        let Some((a, b, flipped, up, g, cells)) = best else {
            self.leave("no fusion gains per cell over its two parts")?;
            return Ok(true);
        };
        println!(
            "[auto]   fuse {} + {} (variant {}): gain {g:.4} in {cells} cells, was {:.4} in {} cells, per cell up {up:.5}",
            self.item_name(&items[a]),
            self.item_name(&items[b]),
            if flipped { 2 } else { 1 },
            gain[a].0 + gain[b].0,
            gain[a].1 + gain[b].1
        );
        self.call(&stop, "_on_slot_filled", json!([ids[a], true]))?;
        self.call(&stop, "_on_slot_filled", json!([ids[b], false]))?;
        if flipped {
            self.call(&stop, "pick_variant", json!([true]))?;
        }
        let Some(btn) = self.named("EncounterContinueBtn")? else {
            return Err("no FUSE button".into());
        };
        if !self.pressable(&btn) {
            self.call(&stop, "_clear_slot", json!([true]))?;
            self.call(&stop, "_clear_slot", json!([false]))?;
            self.leave("FUSE is not pressable")?;
            return Ok(true);
        }
        self.press(&btn, "FUSE")?;
        Ok(true)
    }

    /// An item's plain stats as player stat bonuses (ITEM_STATS).
    fn item_stats(&self, item: &Value) -> Result<Vec<(&'static str, f64)>, String> {
        Ok(stats_from(&self.vars(&item["id"])?))
    }

    /// Genie: three permanent stat wishes (genie_encounter.gd). Takes
    /// the one that most raises the chance to beat the guardian.
    fn genie(&self, crawl: &Value) -> Result<bool, String> {
        let Some(genie) = self.find(&json!({"node": SCENE}), "genie_encounter.gd", 4)? else {
            return Ok(false);
        };
        if self.prop(&genie, "_used")? == json!(true) {
            return Ok(false);
        }
        let mut g = genie.clone();
        g["property"] = json!("_wishes");
        g["depth"] = json!(2);
        let wishes = self.op("get_property", g)?["value"]
            .as_array()
            .cloned()
            .unwrap_or_default();
        let mut g = genie.clone();
        g["property"] = json!("_cards");
        g["depth"] = json!(1);
        let cards = self.op("get_property", g)?["value"]
            .as_array()
            .cloned()
            .unwrap_or_default();
        if wishes.is_empty() || cards.len() != wishes.len() {
            return Ok(false);
        }
        let (me, squad) = self.player_and_guardian(crawl)?;
        let (best, rates) =
            fight::best_choice(&me, &squad, Run::Campaign, &wishes, |p, w| apply_wish(p, w));
        let Some(best) = best else {
            return Ok(false);
        };
        for (w, r) in wishes.iter().zip(&rates) {
            println!(
                "[auto]   wish {} {}: win {:.1}%",
                w["stat"],
                w["amount"],
                r * 100.0
            );
        }
        self.press(
            &json!({"id": cards[best]["id"]}),
            &format!("wish {}", wishes[best]["stat"]),
        )?;
        Ok(true)
    }

    /// The mega forge stop, played inside the game in one request
    /// (mega.rs); prints its reasoning lines. It previews every set, so
    /// it gets a longer wait than other requests.
    fn mega(&self) -> Result<bool, String> {
        let api: Api<Value> = Api::at(31330, "/op").with_timeout(Duration::from_secs(180));
        let r = api.try_op("mega_forge", json!({}))?;
        if !r.ok {
            return Err(format!("mega_forge: {:?}", r.error));
        }
        for line in r.result["lines"].as_array().into_iter().flatten() {
            println!("[auto]   {}", line.as_str().unwrap_or(""));
        }
        Ok(r.result["acted"] == json!(true))
    }

    /// Equipment by the mod's own packing, done inside the game in one
    /// request (arrange.rs); prints its reasoning lines.
    fn arrange(&self) -> Result<bool, String> {
        let got = self.op("arrange", json!({}))?;
        for line in got["lines"].as_array().into_iter().flatten() {
            println!("[auto]   {}", line.as_str().unwrap_or(""));
        }
        Ok(got["changed"] == json!(true))
    }

    fn item_name(&self, item: &Value) -> String {
        self.prop(item, "display_name")
            .ok()
            .and_then(|v| v.as_str().map(str::to_string))
            .unwrap_or_else(|| item.to_string())
    }

    /// The first node under the scene whose path ends with `/name`.
    fn named(&self, name: &str) -> Result<Option<Value>, String> {
        let tree = self.op("tree", json!({"node": SCENE, "depth": 8}))?;
        Ok(tree["nodes"]
            .as_array()
            .into_iter()
            .flatten()
            .find(|n| {
                n["path"]
                    .as_str()
                    .is_some_and(|p| p.ends_with(&format!("/{name}")))
            })
            .map(|n| json!({"id": n["id"]})))
    }

    /// Death and the hub. The death screen's CONTINUE is RETURN TO
    /// HUB in a campaign (death_screen.gd configure_bar). The hub's
    /// START RUN resumes or starts the campaign (hub.gd
    /// _on_start_run_pressed). True when one of them is up.
    fn between_runs(&self) -> Result<bool, String> {
        let scene = json!({"node": SCENE});
        if self.find(&scene, "death_screen.gd", 6)?.is_some() {
            // RERUN (the skip button, death_screen.gd configure_bar)
            // starts the run again at once; CONTINUE when it is not
            // shown (climb, daily).
            for (name, label) in [
                ("EncounterSkipBtn", "RERUN (died)"),
                ("EncounterContinueBtn", "CONTINUE (died)"),
            ] {
                if let Some(b) = self.named(name)?
                    && self.pressable(&b)
                {
                    self.press(&b, label)?;
                    break;
                }
            }
            return Ok(true);
        }
        if let Some(hub) = self.find(&scene, "/hub.gd", 2)? {
            let b = json!({"id": self.prop(&hub, "_start_run_btn")?["id"]});
            if self.pressable(&b) {
                self.press(&b, "START RUN (hub)")?;
            }
            return Ok(true);
        }
        Ok(false)
    }

    /// Shop: every ware not sold and affordable (shop_encounter.gd
    /// can_afford) is judged as if worn, by its plain stats. The best
    /// that beats the loadout now is bought through the shop's own
    /// buy, the same as the game's QA player; one per step, so gold
    /// is read again. None better: done, CONTINUE leaves (crawl.gd
    /// _run_encounter). What is bought is tried on by `equip`.
    fn shop(&self, crawl: &Value) -> Result<bool, String> {
        let Some(shop) = self.find(&json!({"node": SCENE}), "shop_encounter.gd", 4)? else {
            return Ok(false);
        };
        if *self.shop_done.borrow() == shop {
            return Ok(false);
        }
        // Operator 2026-11-16: "maybe we keep 25% of the gold when
        // shopping". A quarter of the gold held on entry is never spent.
        let gold = self.call(&shop, "_gold", json!([]))?.as_i64().unwrap_or(0);
        if self.shop_entry.borrow().0 != shop {
            *self.shop_entry.borrow_mut() = (shop.clone(), gold);
        }
        let keep = (self.shop_entry.borrow().1 as f64 * KEEP_GOLD).ceil() as i64;
        let mut s = shop.clone();
        s["property"] = json!("_cards");
        s["depth"] = json!(1);
        let cards = self.op("get_property", s)?["value"]
            .as_array()
            .cloned()
            .unwrap_or_default();
        let mut wares: Vec<(Value, Value, Vec<(&str, f64)>)> = Vec::new();
        for c in cards {
            let ware = json!({"id": c["id"]});
            if self.prop(&ware, "sold")? == json!(true) {
                continue;
            }
            let price = self.prop(&ware, "price")?;
            if self.call(&shop, "can_afford", json!([price]))? != json!(true)
                || gold - price.as_i64().unwrap_or(i64::MAX) < keep
            {
                continue;
            }
            let item = json!({"id": self.prop(&ware, "item")?["id"]});
            if item["id"].is_null() {
                continue;
            }
            let stats = self.item_stats(&item)?;
            if !stats.is_empty() {
                wares.push((ware, item, stats));
            }
        }
        // Operator 2026-11-16: "they're limited so all the lots need to
        // have max value items", "using max value per inventory/eq
        // slot", "DRY". The one item judge (gain per cell). A ware is
        // bought only when it has room to earn it:
        // - it merges onto an owned copy (inventory.gd absorbs): no new
        //   cells, so it goes first (operator: upgrades are preferred);
        // - it fits the open equipment cells (first_fit) with a gain;
        // - or its gain per cell beats the weakest worn item, which the
        //   packing then swaps out.
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let worn = self.owned(&inv, &[EQUIP])?;
        let weakest = self
            .per_cell(crawl, &worn)?
            .last()
            .map_or(0.0, |(_, pc)| *pc);
        let items: Vec<Value> = wares.iter().map(|(_, item, _)| item.clone()).collect();
        // Operator 2026-11-16: "those upgrad should probagbly the the
        // fIRST things we buy im a shop", "because it increase per slot
        // value right?". A ware that merges onto a worn copy (inventory.gd
        // absorbs; the game levels it, shop_encounter.gd buy) adds the
        // next level's stats in no new cells, so upgrades come first,
        // the biggest gain first.
        let worn_ids: Vec<Value> = worn
            .iter()
            .map(|w| self.prop(w, "id"))
            .collect::<Result<_, _>>()?;
        let mut upgrades: Vec<(usize, f64)> = Vec::new();
        for (i, item) in items.iter().enumerate() {
            let id = self.prop(item, "id")?;
            if self.call(&inv, "absorbs", json!([item]))? != json!(true) || !worn_ids.contains(&id)
            {
                continue;
            }
            let base_id = self.call(item, "get_base_id", json!([]))?;
            let level = self.prop(item, "level")?.as_i64().unwrap_or(1);
            let next = self.call(
                &json!({"node": "/root/EquipmentDB"}),
                "get_leveled_item",
                json!([base_id, level + 1]),
            )?;
            if next["id"].is_null() {
                continue;
            }
            let (me, squad) = self.player_and_guardian(crawl)?;
            let now = fight::score(&me, &squad, Run::Campaign).margin;
            let mut p = me.clone();
            for (stat, v) in self.item_stats(item)? {
                apply_bonus(&mut p, stat, -v);
            }
            for (stat, v) in self.item_stats(&json!({"id": next["id"]}))? {
                apply_bonus(&mut p, stat, v);
            }
            let up = fight::score(&p, &squad, Run::Campaign).margin - now;
            println!(
                "[auto]   upgrade {} to level {}: gain {up:.4}",
                self.item_name(item),
                level + 1
            );
            if up > 0.0 {
                upgrades.push((i, up));
            }
        }
        upgrades.sort_by(|a, b| b.1.total_cmp(&a.1));
        if let Some((i, up)) = upgrades.first() {
            let (ware, item, _) = &wares[*i];
            println!(
                "[auto]   buy {} (upgrade of a worn piece, gain {up:.4}, no new cells)",
                self.item_name(item)
            );
            self.call(&shop, "buy", json!([ware]))?;
            return Ok(true);
        }
        let mut picks: Vec<(usize, f64, &str)> = Vec::new();
        for (i, gain, cells) in self.worth(crawl, &items)? {
            if gain <= 0.0 {
                continue;
            }
            let pc = gain / cells as f64;
            if self.call(&inv, "absorbs", json!([items[i]]))? == json!(true) {
                // A bag copy: levels a piece not worn; judged per cell.
                if pc > weakest {
                    picks.push((i, pc, "levels a bag copy that beats the weakest worn"));
                }
            } else if self
                .call(&inv, "first_fit", json!([items[i], EQUIP]))?
                .as_object()
                .is_some_and(|o| !o.is_empty())
            {
                picks.push((i, pc, "fits the open equipment cells"));
            } else if pc > weakest {
                picks.push((i, pc, "beats the weakest worn item per cell"));
            }
        }
        picks.sort_by(|a, b| b.1.total_cmp(&a.1));
        // Room (operator 2026-11-16: "it keeps trying to buy when no room
        // in bag... plase we gotta do the math right on ROOM"): the game
        // buys into the bag, refused when the bag has no spot for it
        // (shop_encounter.gd buy: first_fit BAG, "No room in your bag").
        // With no spot, the loose piece with the least gain per cell is
        // sold to make room, only when it is worth less per cell than
        // the ware; otherwise the ware is passed.
        let mut ready = None;
        for &(i, pc, why) in &picks {
            let item = &wares[i].1;
            let merges = self.call(&inv, "absorbs", json!([item]))? == json!(true);
            let spot = self
                .call(&inv, "first_fit", json!([item, BAG]))?
                .as_object()
                .is_some_and(|o| !o.is_empty());
            if merges || spot {
                ready = Some((i, pc, why));
                break;
            }
            let loose = self.owned(&inv, &[BAG])?;
            if let Some(&(j, low)) = self.per_cell(crawl, &loose)?.last()
                && low < pc
            {
                let id = self.prop(&loose[j], "id")?;
                let ok = self.call(&json!({"node": "/root/Global"}), "sell_item", json!([id]))?
                    == json!(true);
                println!(
                    "[auto]   no bag spot for {}: sold {} (gain per cell {low:.5} < {pc:.5}): {ok}",
                    self.item_name(item),
                    self.item_name(&loose[j])
                );
                return Ok(true);
            }
            println!(
                "[auto]   no bag spot for {} and nothing loose is worth less; passed",
                self.item_name(item)
            );
        }
        if let Some((i, pc, why)) = ready {
            let (ware, item, stats) = &wares[i];
            println!(
                "[auto]   buy {} {:?}: gain per cell {pc:.5}, {why} (weakest worn {weakest:.5})",
                self.item_name(item),
                stats
            );
            self.call(&shop, "buy", json!([ware]))?;
            return Ok(true);
        }
        println!("[auto]   shop: no affordable ware has room to add value");
        *self.shop_done.borrow_mut() = shop;
        Ok(false)
    }

    /// At the start of a fight: the foes the game built (the
    /// resolver's squad, live CombatantRuntime) and the player as they
    /// stand, through the mod's fight math. Logged beside the result
    /// to check the math against the game.
    fn predict(&self, crawl: &Value) -> Result<(), String> {
        let resolver = self
            .find(crawl, "combat_resolver.gd", 1)?
            .ok_or("no combat resolver")?;
        let mut r = resolver.clone();
        r["property"] = json!("squad");
        r["depth"] = json!(1);
        let squad: Vec<Fighter> = self.op("get_property", r)?["value"]
            .as_array()
            .into_iter()
            .flatten()
            .map(|f| {
                let vars = self.vars(&f["id"])?;
                let name = vars
                    .get("display_name")
                    .and_then(Value::as_str)
                    .unwrap_or("foe")
                    .to_string();
                Ok(fight::from_vars(&name, &vars))
            })
            .collect::<Result<_, String>>()?;
        let run = self.prop(&json!({"node": "/root/Global"}), "current_run")?;
        let player = self.prop(&json!({"id": run["id"]}), "player")?;
        let me = fight::from_vars("Player", &self.vars(&player["id"])?);
        let s = fight::score(&me, &squad, Run::Campaign);
        if let Some(strongest) = squad.iter().max_by_key(|f| f.max_hp * f.atk) {
            *self.last_foe.borrow_mut() = Some(strongest.clone());
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
        println!(
            "[auto]   fight: player hp {}/{} atk {} block {} speed {:.1} vs {}",
            me.hp,
            me.max_hp,
            me.atk,
            me.block_max,
            me.speed,
            foes.join("; ")
        );
        println!(
            "[auto]   predicted win {:.1}% hp left {:.0}%",
            s.win * 100.0,
            s.hp_left * 100.0
        );
        Ok(())
    }

    fn step(&self) -> Result<(), String> {
        if self.between_runs()? {
            return Ok(());
        }
        let crawl = self.crawl()?;
        if self.prop(&crawl, "_fighting")? == json!(true) {
            if !*self.predicted.borrow() {
                *self.predicted.borrow_mut() = true;
                self.predict(&crawl)?;
            }
            return Ok(());
        }
        if std::mem::take(&mut *self.predicted.borrow_mut()) {
            let run = self.prop(&json!({"node": "/root/Global"}), "current_run")?;
            let player = self.prop(&json!({"id": run["id"]}), "player")?;
            let hp = self.prop(&json!({"id": player["id"]}), "current_hp")?;
            println!("[auto]   fight over: player hp {hp}");
        }
        if self.loot(&crawl)? {
            return Ok(());
        }
        if self.genie(&crawl)? {
            return Ok(());
        }
        if self.dismantle(&crawl)? {
            return Ok(());
        }
        if self.shop(&crawl)? {
            return Ok(());
        }
        if self.item_stop(&crawl)? {
            return Ok(());
        }
        if self.fork(&crawl)? {
            return Ok(());
        }
        if self.fuse(&crawl)? {
            return Ok(());
        }
        if self.rune(&crawl)? {
            return Ok(());
        }
        // Before arrange, so nothing moves pieces while the mega forge
        // has the anvil.
        if self.mega()? {
            return Ok(());
        }
        if self.arrange()? {
            return Ok(());
        }
        let mut c = crawl.clone();
        c["depth"] = json!(4);
        let tree = self.op("tree", c)?;
        let nodes = tree["nodes"].as_array().cloned().unwrap_or_default();
        let button = |name: &str| {
            nodes
                .iter()
                .find(|n| {
                    n["path"]
                        .as_str()
                        .is_some_and(|p| p.ends_with(&format!("/{name}")))
                })
                .map(|n| json!({"id": n["id"]}))
        };
        // A stop on screen: only the ones the bot knows are played;
        // any other waits for the operator. Nothing is skipped.
        let stop = nodes
            .iter()
            .filter_map(|n| n["script"].as_str())
            .find(|s| s.ends_with("_encounter.gd"))
            .map(|s| s.rsplit('/').next().unwrap_or(s).to_string());
        if let Some(stop) = stop {
            if !HANDLED.contains(&stop.as_str()) {
                if *self.waiting.borrow() != stop {
                    println!("[auto] waiting: {stop} is not handled yet, play it yourself");
                    *self.waiting.borrow_mut() = stop;
                }
                return Ok(());
            }
            if let Some(b) = button("EncounterContinueBtn")
                && self.pressable(&b)
            {
                return self.press(&b, &format!("CONTINUE ({stop})"));
            }
            return Ok(());
        }
        self.waiting.borrow_mut().clear();
        for name in BAR {
            if let Some(b) = button(name)
                && self.pressable(&b)
            {
                return self.press(&b, name);
            }
        }
        Ok(())
    }
}

/// A genie wish on the player: its stat times the genie's 3
/// (game_state.gd LEVEL_BONUS_POOL, genie_encounter.gd
/// GENIE_MULTIPLIER). Percent wishes count on the stat as it is now.
fn apply_wish(p: &mut Fighter, wish: &Value) {
    const GENIE_MULTIPLIER: f64 = 3.0;
    let n = wish["amount"].as_f64().unwrap_or(0.0) * GENIE_MULTIPLIER;
    apply_bonus(p, wish["stat"].as_str().unwrap_or(""), n);
}

fn main() {
    let game = Game {
        api: Api::at(31330, "/op").with_timeout(Duration::from_secs(10)),
        start: Instant::now(),
        waiting: std::cell::RefCell::new(String::new()),
        judged: std::cell::RefCell::new(String::new()),
        shop_done: std::cell::RefCell::new(Value::Null),
        shrine_done: std::cell::RefCell::new(Value::Null),
        shop_entry: std::cell::RefCell::new((Value::Null, 0)),
        predicted: std::cell::RefCell::new(false),
        last_foe: std::cell::RefCell::new(None),
    };
    println!("[auto] playing; Ctrl+C stops");
    let mut last_err = String::new();
    loop {
        if let Err(e) = game.step()
            && e != last_err
        {
            eprintln!("[auto] {e}");
            last_err = e;
        }
        sleep(TICK);
    }
}

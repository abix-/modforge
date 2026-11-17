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
//! - equipment: each bag item tried on (or in place of a worn one),
//!   kept when the fight math says it beats the guardian more often.
//!   Operator 2026-11-16: "when we loot stuff we also have to move it
//!   into equipment", "that includes placment which might mean
//!   rotation". Placement is the game's own first fit for now.
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
const HANDLED: [&str; 4] = [
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
    /// The bag and tray already tried on.
    tried: std::cell::RefCell<String>,
}

/// Inventory grids (inventory.gd).
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
        for (var, label) in [
            ("_loot_auto_btn", "AUTO PICK"),
            ("_loot_claim_btn", "CLAIM ALL"),
        ] {
            let b = json!({"id": self.prop(crawl, var)?["id"]});
            if self.pressable(&b) {
                self.press(&b, label)?;
                return Ok(true);
            }
        }
        let sell = json!({"id": self.prop(crawl, "_loot_sell_btn")?["id"]});
        if self.pressable(&sell) {
            self.press(&sell, "SELL ALL (bag full)")?;
            return Ok(true);
        }
        Ok(false)
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
        let resolver = self
            .find(crawl, "combat_resolver.gd", 1)?
            .ok_or("no combat resolver")?;
        let guardian = self.prop(&resolver, "_guardian")?;
        let foe = fight::from_vars("Guardian", &self.vars(&guardian["id"])?);
        Ok((me, vec![foe]))
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

    /// The player's score against the guardian with what is equipped now.
    fn loadout_score(&self, crawl: &Value) -> Result<fight::Score, String> {
        let (me, squad) = self.player_and_guardian(crawl)?;
        Ok(fight::score(&me, &squad, Run::Campaign))
    }

    /// The game's own steps after a move (qa_driver.gd
    /// _equip_like_a_player): equipment_changed refolds the player's
    /// stats (crawl.gd _reapply_loadout).
    fn changed(&self) -> Result<(), String> {
        self.call(
            &json!({"node": "/root/EventBus"}),
            "emit_signal",
            json!(["equipment_changed", -1]),
        )?;
        Ok(())
    }

    fn equip_auto(&self, inv: &Value, item: &Value) -> Result<bool, String> {
        let ok = self.call(inv, "equip_auto", json!([item]))? == json!(true);
        if ok {
            self.changed()?;
        }
        Ok(ok)
    }

    fn unequip(&self, inv: &Value, item: &Value) -> Result<bool, String> {
        let ok = self.call(inv, "unequip_item", json!([item]))? == json!(true);
        if ok {
            self.changed()?;
        }
        Ok(ok)
    }

    fn item_name(&self, item: &Value) -> String {
        self.prop(item, "display_name")
            .ok()
            .and_then(|v| v.as_str().map(str::to_string))
            .unwrap_or_else(|| item.to_string())
    }

    /// Equipment: every bag and tray item is tried on, through the
    /// game's own equip (inventory.gd equip_auto: the first spot that
    /// fits, any of 4 turns). When there is no room it is tried in
    /// place of each worn item of its kind (weapon for weapon). Kept
    /// only when the mod's fight math says it beats the guardian more
    /// often (or with more hp left); otherwise put back.
    fn equip(&self, crawl: &Value) -> Result<bool, String> {
        let inv = json!({"id": self.prop(&json!({"node": "/root/Global"}), "inventory")?["id"]});
        let mut loose = Vec::new();
        for grid in [BAG, TRAY] {
            for p in self
                .call(&inv, "placements_in", json!([grid]))?
                .as_array()
                .into_iter()
                .flatten()
            {
                let item = json!({"id": p["item"]["id"]});
                if !loose.contains(&item) {
                    loose.push(item);
                }
            }
        }
        let key = format!("{loose:?}");
        if *self.tried.borrow() == key {
            return Ok(false);
        }
        let mut base = self.loadout_score(crawl)?;
        println!(
            "[auto]   trying on {} loose items; now win {:.1}% hp left {:.0}%",
            loose.len(),
            base.win * 100.0,
            base.hp_left * 100.0
        );
        let mut kept = false;
        for item in &loose {
            let name = self.item_name(item);
            if self.equip_auto(&inv, item)? {
                let s = self.loadout_score(crawl)?;
                if s.cmp(&base).is_gt() {
                    println!(
                        "[auto]     equipped {name}: win {:.1}% hp left {:.0}% (was {:.1}% {:.0}%)",
                        s.win * 100.0,
                        s.hp_left * 100.0,
                        base.win * 100.0,
                        base.hp_left * 100.0
                    );
                    base = s;
                    kept = true;
                } else {
                    println!(
                        "[auto]     tried {name}: win {:.1}% hp left {:.0}%, kept the old ({:.1}% {:.0}%)",
                        s.win * 100.0,
                        s.hp_left * 100.0,
                        base.win * 100.0,
                        base.hp_left * 100.0
                    );
                    self.unequip(&inv, item)?;
                }
                continue;
            }
            let weapon = self.call(item, "is_weapon", json!([]))? == json!(true);
            let worn_list = self.call(&inv, "get_equipped_list", json!([]))?;
            for w in worn_list.as_array().into_iter().flatten() {
                let worn = json!({"id": w["id"]});
                if (self.call(&worn, "is_weapon", json!([]))? == json!(true)) != weapon {
                    continue;
                }
                if !self.unequip(&inv, &worn)? {
                    continue;
                }
                if self.equip_auto(&inv, item)? {
                    let s = self.loadout_score(crawl)?;
                    if s.cmp(&base).is_gt() {
                        println!(
                            "[auto]     swapped {} for {name}: win {:.1}% hp left {:.0}% (was {:.1}% {:.0}%)",
                            self.item_name(&worn),
                            s.win * 100.0,
                            s.hp_left * 100.0,
                            base.win * 100.0,
                            base.hp_left * 100.0
                        );
                        base = s;
                        kept = true;
                        break;
                    }
                    self.unequip(&inv, item)?;
                }
                self.equip_auto(&inv, &worn)?;
            }
        }
        if kept {
            self.call(&json!({"node": "/root/Global"}), "save_game", json!([]))?;
        }
        // What is loose now, so the same bag is not tried again.
        let mut now = Vec::new();
        for grid in [BAG, TRAY] {
            for p in self
                .call(&inv, "placements_in", json!([grid]))?
                .as_array()
                .into_iter()
                .flatten()
            {
                now.push(json!({"id": p["item"]["id"]}));
            }
        }
        now.dedup();
        *self.tried.borrow_mut() = format!("{now:?}");
        Ok(kept)
    }

    fn step(&self) -> Result<(), String> {
        let crawl = self.crawl()?;
        if self.prop(&crawl, "_fighting")? == json!(true) {
            return Ok(());
        }
        if self.loot(&crawl)? {
            return Ok(());
        }
        if self.genie(&crawl)? {
            return Ok(());
        }
        if self.equip(&crawl)? {
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
    let pct = |v: i64| (v as f64 * (1.0 + n)).round() as i64;
    match wish["stat"].as_str().unwrap_or("") {
        "max_hp_pct" => {
            p.max_hp = pct(p.max_hp);
            p.hp = p.max_hp;
        }
        "atk_pct" => p.atk = pct(p.atk),
        "armor_pct" => {
            p.block_max = pct(p.block_max);
            p.block = p.block_max;
        }
        "block_chance" => p.block_chance += n,
        "dodge_chance" => p.dodge += n,
        "crit_chance" => p.crit += n,
        "multistrike_chance" => p.multistrike += n,
        "speed" => p.speed += n,
        // Block regen and mana are not in the fight math yet.
        _ => {}
    }
}

fn main() {
    let game = Game {
        api: Api::at(31330, "/op").with_timeout(Duration::from_secs(10)),
        start: Instant::now(),
        waiting: std::cell::RefCell::new(String::new()),
        tried: std::cell::RefCell::new(String::new()),
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

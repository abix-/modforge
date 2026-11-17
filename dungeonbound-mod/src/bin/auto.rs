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
//! - any other stop: SKIP if it has one, else CONTINUE
//!
//! Not yet: the mod's own success rate gate (the rate is not trusted
//! yet), buying, fusing, loadout. Stops with choices are skipped.
//!
//! Run with the game up: `dungeonbound-auto`. Ctrl+C stops it.

use std::thread::sleep;
use std::time::{Duration, Instant};

use modforge::client::Api;
use serde_json::{Value, json};

const SCENE: &str = "/root/@Control@65/CurrentScene";
const TICK: Duration = Duration::from_millis(700);
/// Buttons pressed in this order when nothing else is up.
const BAR: [&str; 4] = [
    "StartBattleBtn",
    "EnterDeeperBtn",
    "EncounterSkipBtn",
    "EncounterContinueBtn",
];

struct Game {
    api: Api<Value>,
    start: Instant,
}

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
        a["depth"] = json!(1);
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

    fn step(&self) -> Result<(), String> {
        let crawl = self.crawl()?;
        if self.prop(&crawl, "_fighting")? == json!(true) {
            return Ok(());
        }
        if self.loot(&crawl)? {
            return Ok(());
        }
        let mut c = crawl.clone();
        c["depth"] = json!(4);
        let tree = self.op("tree", c)?;
        let nodes = tree["nodes"].as_array().cloned().unwrap_or_default();
        for name in BAR {
            let Some(n) = nodes.iter().find(|n| {
                n["path"]
                    .as_str()
                    .is_some_and(|p| p.ends_with(&format!("/{name}")))
            }) else {
                continue;
            };
            let b = json!({"id": n["id"]});
            if self.pressable(&b) {
                return self.press(&b, name);
            }
        }
        Ok(())
    }
}

fn main() {
    let game = Game {
        api: Api::at(31330, "/op").with_timeout(Duration::from_secs(10)),
        start: Instant::now(),
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

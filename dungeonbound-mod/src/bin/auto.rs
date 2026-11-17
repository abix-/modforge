//! The switch for auto mode, which runs inside the game (src/auto.rs).
//! Operator 2026-11-17: "all the auto mode hsouldbe IN the mod".
//!
//! `dungeonbound-auto` turns it on and prints what it does and why;
//! `dungeonbound-auto off` turns it off. Ctrl+C stops the printing,
//! not auto mode.

use std::thread::sleep;
use std::time::Duration;

use modforge::client::Api;
use serde_json::{Value, json};

fn op(api: &Api<Value>, name: &str, args: Value) -> Result<Value, String> {
    let r = api.try_op(name, args)?;
    if r.ok {
        Ok(r.result)
    } else {
        Err(format!("{name}: {:?}", r.error))
    }
}

fn main() {
    let api: Api<Value> = Api::at(31330, "/op").with_timeout(Duration::from_secs(10));
    let on = std::env::args().nth(1).as_deref() != Some("off");
    let mut after = match op(&api, "auto", json!({"on": on})) {
        Ok(r) => r["lines"].as_u64().unwrap_or(0),
        Err(e) => {
            eprintln!("[auto] {e}");
            std::process::exit(1);
        }
    };
    println!("[auto] {}", if on { "on" } else { "off" });
    if !on {
        return;
    }
    let mut last_err = String::new();
    loop {
        match op(&api, "auto_lines", json!({"after": after})) {
            Ok(r) => {
                for l in r["lines"].as_array().into_iter().flatten() {
                    println!("[auto] {}", l.as_str().unwrap_or(""));
                }
                after = r["next"].as_u64().unwrap_or(after);
                last_err.clear();
            }
            Err(e) if e != last_err => {
                eprintln!("[auto] {e}");
                last_err = e;
            }
            Err(_) => {}
        }
        sleep(Duration::from_millis(700));
    }
}

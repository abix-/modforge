//! How many grid cells one screen is: points 40 cells from the player
//! in each direction go through the game's own camera matrix (the
//! camera op, GameHelper2 WorldToScreen), and the pixels per cell give
//! the screen's width and height in cells. Read-only.
//!
//! ```text
//! cargo run -p poe2-mod            # game in play
//! k3sc cargo-lock test -p poe2-mod --test research_screen_cells -- --nocapture
//! ```
//!
//! SKIPs (prints why and passes) when poe2-mod or the game is not running.

use modforge::memory_research::Remote;
use serde_json::{Value, json};

const CELLS: f64 = 40.0;
/// World units per grid cell (250 / 23).
const WORLD_PER_CELL: f64 = 250.0 / 23.0;

/// camera::world_to_screen.
fn project(m: &Value, p: [f64; 3], size: [f64; 2]) -> [f64; 2] {
    let v = [p[0], p[1], p[2], 1.0];
    let o: Vec<f64> = (0..4)
        .map(|i| (0..4).map(|j| m[j][i].as_f64().unwrap_or(0.0) * v[j]).sum())
        .collect();
    [(o[0] / o[3] + 1.0) * size[0] / 2.0, (1.0 - o[1] / o[3]) * size[1] / 2.0]
}

#[test]
fn one_screen_in_cells() {
    let r = Remote::at(17185);
    let c = match r.op("camera", json!({})) {
        Ok(c) => c,
        Err(e) => {
            println!("SKIP: {e}");
            return;
        }
    };
    let size = [c["size"][0].as_f64().unwrap(), c["size"][1].as_f64().unwrap()];
    let w = &c["player"]["world"];
    let me = [w[0].as_f64().unwrap(), w[1].as_f64().unwrap(), w[2].as_f64().unwrap()];
    let at = project(&c["matrix"], me, size);
    println!("window {size:?}, player on screen at ({:.0}, {:.0})", at[0], at[1]);
    let d = CELLS * WORLD_PER_CELL;
    let mut px_per_cell = Vec::new();
    for (name, dx, dy) in [("+x", d, 0.0), ("-x", -d, 0.0), ("+y", 0.0, d), ("-y", 0.0, -d)] {
        let p = project(&c["matrix"], [me[0] + dx, me[1] + dy, me[2]], size);
        let px = (p[0] - at[0]).hypot(p[1] - at[1]);
        println!("40 cells along {name}: ({:.0}, {:.0}), {px:.0} pixels", p[0], p[1]);
        px_per_cell.push(px / CELLS);
    }
    let mean = px_per_cell.iter().sum::<f64>() / px_per_cell.len() as f64;
    println!(
        "about {mean:.1} pixels a cell: the screen is about {:.0} cells wide and {:.0} high; 40 cells is {:.0} pixels",
        size[0] / mean,
        size[1] / mean,
        CELLS * mean
    );
    assert!(mean > 0.0);
}

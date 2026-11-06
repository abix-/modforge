//! A GPS line from the player to a destination, kept up to date as the
//! player moves, drawn by the screen overlay so it shows through hills.
//!
//! Prior art: a car GPS, or the route line of any open-world game map:
//! a planned route of waypoints, re-planned from where you are each
//! moment, with passed waypoints dropped.
//!
//! The route is given as floor points with how to get from each to the
//! next ("walk", or a move the game's navigation cannot plan such as a
//! jump or a dash, which is drawn straight). Once a second, on the game
//! thread inside the HUD draw, the walking leg from the player to the
//! next waypoint is asked of the game's own navigation
//! (NavigationSystemV1::FindPathToLocationSynchronously), waypoints the
//! player has reached are dropped, and the line is redrawn. Walking legs
//! between waypoints are planned once, on the first frame after the
//! route is set.
//!
//! Ops: `gps.to` sets the route, `gps.clear` removes it, `gps.state`
//! tells where the player is on it.

use std::time::{Duration, Instant};

use parking_lot::Mutex;
use serde_json::{Value, json};

use crate::overlay::{OverlayLine, read_reals, write_reals};
use crate::ue::uobject::NativeProperty;
use crate::ue::{UFunction, UObject};

/// How often the walking leg from the player is planned again.
const REPLAN: Duration = Duration::from_secs(1);
/// A waypoint counts as reached within this distance across (game units).
const REACH: f64 = 300.0;
/// ... and this height difference.
const REACH_UP: f64 = 300.0;

struct Route {
    points: Vec<[f64; 3]>,
    kinds: Vec<String>,
    /// Index of the next waypoint not reached yet.
    next: usize,
    /// Floor polyline from each waypoint to the one after, planned once.
    legs: Option<Vec<Vec<[f64; 3]>>>,
    height: f64,
    color: [f32; 4],
    thickness: f32,
    last: Option<Instant>,
    player: Option<[f64; 3]>,
    lead: usize,
}

static ROUTE: Mutex<Option<Route>> = Mutex::new(None);

/// Engine functions and parameter slots, resolved once.
struct Calls {
    get_pawn: &'static UFunction,
    get_pawn_ret: NativeProperty,
    location: &'static UFunction,
    location_ret: NativeProperty,
    find: &'static UFunction,
    find_ctx: NativeProperty,
    find_start: NativeProperty,
    find_end: NativeProperty,
    find_ret: NativeProperty,
}

static CALLS: Mutex<Option<&'static Calls>> = Mutex::new(None);

fn function(class: &str, name: &str) -> Result<&'static UFunction, String> {
    let c = crate::ue::find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
    let f = c.get_function(class, name).ok_or_else(|| format!("{class}::{name} not found"))?;
    // SAFETY: UFunctions are class members and live as long as the class.
    Ok(unsafe { &*(f as *const UFunction) })
}

fn param(f: &UFunction, name: &str) -> Result<NativeProperty, String> {
    f.iter_parameters()
        .into_iter()
        .find(|p| p.name == name)
        .ok_or_else(|| format!("parameter {name} not found"))
}

fn resolve() -> Result<&'static Calls, String> {
    if let Some(c) = *CALLS.lock() {
        return Ok(c);
    }
    let get_pawn = function("Controller", "K2_GetPawn")?;
    let location = function("Actor", "K2_GetActorLocation")?;
    let find = function("NavigationSystemV1", "FindPathToLocationSynchronously")?;
    let calls: &'static Calls = Box::leak(Box::new(Calls {
        get_pawn,
        get_pawn_ret: param(get_pawn, "ReturnValue")?,
        location,
        location_ret: param(location, "ReturnValue")?,
        find,
        find_ctx: param(find, "WorldContextObject")?,
        find_start: param(find, "PathStart")?,
        find_end: param(find, "PathEnd")?,
        find_ret: param(find, "ReturnValue")?,
    }));
    *CALLS.lock() = Some(calls);
    Ok(calls)
}

fn read_ptr(buf: &[u8], p: &NativeProperty) -> usize {
    let o = p.offset as usize;
    usize::from_le_bytes(buf[o..o + 8].try_into().unwrap())
}

/// The player's pawn location. Game thread.
unsafe fn player_location(c: &Calls, pc: &UObject) -> Option<[f64; 3]> {
    let mut buf = vec![0u8; c.get_pawn.parms_size().max(8) as usize];
    unsafe { pc.process_event(c.get_pawn, buf.as_mut_ptr().cast()) };
    let pawn = read_ptr(&buf, &c.get_pawn_ret);
    if pawn == 0 || !crate::ue::is_live(pawn) {
        return None;
    }
    // SAFETY: just checked live.
    let pawn = unsafe { &*(pawn as *const UObject) };
    let mut buf = vec![0u8; c.location.parms_size().max(1) as usize];
    unsafe { pawn.process_event(c.location, buf.as_mut_ptr().cast()) };
    let v = read_reals(&buf, &c.location_ret, 3);
    Some([v[0], v[1], v[2]])
}

/// The game's own walking path from `a` to `b`, floor points, or None
/// when it finds none. Game thread; `ctx` is any live world object.
unsafe fn walk_path(c: &Calls, ctx: &UObject, a: [f64; 3], b: [f64; 3]) -> Option<Vec<[f64; 3]>> {
    let mut buf = vec![0u8; c.find.parms_size().max(1) as usize];
    let o = c.find_ctx.offset as usize;
    buf[o..o + 8].copy_from_slice(&(ctx as *const UObject as usize).to_le_bytes());
    write_reals(&mut buf, &c.find_start, &a);
    write_reals(&mut buf, &c.find_end, &b);
    // Static function: the target object is ignored.
    unsafe { ctx.process_event(c.find, buf.as_mut_ptr().cast()) };
    let path = read_ptr(&buf, &c.find_ret);
    if path == 0 || !crate::ue::is_live(path) {
        return None;
    }
    // SAFETY: just checked live.
    let path = unsafe { &*(path as *const UObject) };
    let off = crate::reflect::fields_of(path)
        .into_iter()
        .find(|(p, _)| p.name == "PathPoints")
        .map(|(p, _)| p.offset as usize)?;
    // TArray<FVector>: data pointer, then i32 count.
    // SAFETY: PathPoints is a reflected field of the live path object.
    let base = unsafe { path.field_ptr(off) } as *const u8;
    let (data, num) = unsafe { ((base as *const usize).read_unaligned(), (base.add(8) as *const i32).read_unaligned()) };
    if data == 0 || !(2..=4096).contains(&num) {
        return None;
    }
    // One element is one FVector, the same size as the PathStart parameter.
    let size = c.find_start.element_size as usize;
    let wide = size == 24;
    let bytes = unsafe { std::slice::from_raw_parts(data as *const u8, num as usize * size) };
    let pts = bytes
        .chunks_exact(size)
        .map(|e| {
            let v = |i: usize| {
                if wide {
                    f64::from_le_bytes(e[i * 8..i * 8 + 8].try_into().unwrap())
                } else {
                    f32::from_le_bytes(e[i * 4..i * 4 + 4].try_into().unwrap()) as f64
                }
            };
            [v(0), v(1), v(2)]
        })
        .collect();
    Some(pts)
}

fn reached(player: [f64; 3], p: [f64; 3]) -> bool {
    let (dx, dy) = (player[0] - p[0], player[1] - p[1]);
    (dx * dx + dy * dy).sqrt() < REACH && (player[2] - p[2]).abs() < REACH_UP
}

/// Every frame, before the overlay draws. Game thread.
fn frame(pc: &UObject) {
    let mut guard = ROUTE.lock();
    let Some(route) = guard.as_mut() else {
        return;
    };
    if route.last.is_some_and(|t| t.elapsed() < REPLAN) {
        return;
    }
    route.last = Some(Instant::now());
    let Ok(c) = resolve() else {
        return;
    };
    let Some(player) = (unsafe { player_location(c, pc) }) else {
        return;
    };
    route.player = Some(player);
    if route.legs.is_none() {
        let legs = route
            .points
            .windows(2)
            .zip(&route.kinds)
            .map(|(w, kind)| match kind.as_str() {
                "walk" => unsafe { walk_path(c, pc, w[0], w[1]) }.unwrap_or_else(|| w.to_vec()),
                _ => w.to_vec(),
            })
            .collect();
        route.legs = Some(legs);
    }
    // Drop every waypoint up to the furthest one the player stands at.
    if let Some(i) = (route.next..route.points.len()).rev().find(|&i| reached(player, route.points[i])) {
        route.next = i + 1;
    }
    let mut line: Vec<[f64; 3]> = Vec::new();
    if route.next < route.points.len() {
        let target = route.points[route.next];
        // The leg into the next waypoint: walk it if that leg is walked
        // (or it is the first), else straight from the player.
        let walked = route.next == 0 || route.kinds.get(route.next - 1).is_some_and(|k| k == "walk");
        let lead = walked.then(|| unsafe { walk_path(c, pc, player, target) }).flatten();
        match lead {
            Some(p) => line.extend(p),
            None => line.extend([player, target]),
        }
        route.lead = line.len();
        if let Some(legs) = &route.legs {
            for leg in legs.iter().skip(route.next) {
                line.extend(leg.iter().skip(1));
            }
        }
    }
    let up = route.height;
    let points = line.into_iter().map(|p| [p[0], p[1], p[2] + up]).collect();
    crate::overlay::set_lines(vec![OverlayLine { points, color: route.color, thickness: route.thickness }]);
}

fn point(v: &Value) -> Result<[f64; 3], String> {
    let a = v.as_array().filter(|a| a.len() == 3).ok_or("a point is [x, y, z]")?;
    let f = |i: usize| a[i].as_f64().ok_or("point values are numbers");
    Ok([f(0)?, f(1)?, f(2)?])
}

fn state() -> Value {
    let guard = ROUTE.lock();
    let Some(r) = guard.as_ref() else {
        return json!({"route": null});
    };
    let next = r.points.get(r.next).copied();
    let distance = match (r.player, next) {
        (Some(p), Some(n)) => Some(((p[0] - n[0]).powi(2) + (p[1] - n[1]).powi(2)).sqrt()),
        _ => None,
    };
    json!({
        "waypoints": r.points.len(),
        "next": r.next,
        "next_point": next,
        "next_move": r.kinds.get(r.next.saturating_sub(1)).filter(|_| r.next > 0),
        "player": r.player,
        "distance_to_next": distance,
        "lead_points": r.lead,
        "arrived": r.next >= r.points.len(),
    })
}

/// `gps.to`, `gps.clear`, `gps.state`.
pub fn register_ops() {
    use crate::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new(
            "gps.to",
            "Draw a route from the player, kept up to date as they move: points are floor waypoints [[x,y,z]...], moves[i] is how to go from point i to i+1 (walk is planned by the game's navigation, anything else is drawn straight); one point alone is a plain walk there",
            "{points: [[x,y,z]...], moves?: [walk|jump|dash|drop...], height?: 170, color?: [r,g,b,a], thickness?: 4}",
            |args| {
                let points = args["points"]
                    .as_array()
                    .ok_or("points must be an array")?
                    .iter()
                    .map(point)
                    .collect::<Result<Vec<_>, _>>()?;
                if points.is_empty() {
                    return Err("no points".into());
                }
                let kinds: Vec<String> = match args["moves"].as_array() {
                    Some(m) => m.iter().map(|k| k.as_str().unwrap_or("walk").to_string()).collect(),
                    None => vec!["walk".into(); points.len() - 1],
                };
                if kinds.len() + 1 != points.len() {
                    return Err(format!("{} points need {} moves, got {}", points.len(), points.len() - 1, kinds.len()));
                }
                let color = args["color"]
                    .as_array()
                    .map(|c| {
                        let f = |i: usize, d: f32| c.get(i).and_then(Value::as_f64).map(|x| x as f32).unwrap_or(d);
                        [f(0, 0.0), f(1, 1.0), f(2, 1.0), f(3, 1.0)]
                    })
                    .unwrap_or([0.0, 1.0, 1.0, 1.0]);
                let n = points.len();
                *ROUTE.lock() = Some(Route {
                    points,
                    kinds,
                    next: 0,
                    legs: None,
                    height: args["height"].as_f64().unwrap_or(170.0),
                    color,
                    thickness: args["thickness"].as_f64().unwrap_or(4.0) as f32,
                    last: None,
                    player: None,
                    lead: 0,
                });
                crate::overlay::set_frame_hook(Some(frame));
                let hud = crate::overlay::ensure_installed()?;
                Ok(json!({"waypoints": n, "hud": hud}))
            },
        ),
        OpDef::new("gps.clear", "Remove the GPS route", "{}", |_args| {
            ROUTE.lock().take();
            crate::overlay::set_frame_hook(None);
            crate::overlay::set_lines(Vec::new());
            Ok(json!({"cleared": true}))
        }),
        OpDef::new("gps.state", "Where the player is on the GPS route", "{}", |_args| Ok(state())),
    ]);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn reach_is_across_and_up() {
        assert!(reached([0.0, 0.0, 0.0], [200.0, 0.0, 100.0]));
        assert!(!reached([0.0, 0.0, 0.0], [400.0, 0.0, 0.0]));
        assert!(!reached([0.0, 0.0, 0.0], [0.0, 0.0, 500.0]));
    }
}

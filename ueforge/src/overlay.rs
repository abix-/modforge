//! Lines drawn over the game picture, seen through walls and terrain.
//!
//! Prior art: internal overlays such as AltimorTASDK/strivehitboxes
//! draw during the game's HUD pass with the engine's own Canvas line
//! call, after turning each world point into a screen position. Shipped
//! builds compile DrawDebugLine out, so world-space debug lines are not
//! an option.
//!
//! Here: a ProcessEvent hook on the live HUD. AHUD::DrawHUD fires
//! `ReceiveDrawHUD` every frame while the Canvas is valid; after the
//! game's own handling, each line is cut into short pieces, each piece
//! end projected with PlayerController::ProjectWorldLocationToScreen
//! (false when behind the camera) and drawn with AHUD::DrawLine. All
//! three are the game's own functions; nothing is drawn by hand.
//!
//! Parameters are written by their reflected offsets and sizes, so the
//! same code runs on UE 4 (f32 vectors) and UE 5 (f64 vectors).
//!
//! Ops: `overlay.lines` replaces the lines and installs the hook on the
//! current HUD; `overlay.clear` empties them.

use parking_lot::Mutex;
use serde_json::{Value, json};

use crate::hook::process_event::ProcessEventHook;
use crate::ue::uobject::NativeProperty;
use crate::ue::{UFunction, UObject};

/// One line in world space (game units) with its colour (linear RGBA)
/// and thickness in screen pixels.
#[derive(Clone, Debug)]
pub struct OverlayLine {
    pub points: Vec<[f64; 3]>,
    pub color: [f32; 4],
    pub thickness: f32,
}

/// Longest piece a line is cut into before projecting, so a line that
/// passes behind the camera still shows the part in front of it.
const PIECE: f64 = 200.0;

static LINES: Mutex<Vec<OverlayLine>> = Mutex::new(Vec::new());

struct Installed {
    _hook: ProcessEventHook,
    hud_vtable: usize,
}

static HOOK: Mutex<Option<Installed>> = Mutex::new(None);

/// The engine functions the drawing calls, resolved once per install.
struct Calls {
    draw_hud: usize,
    project: &'static UFunction,
    project_world: NativeProperty,
    project_screen: NativeProperty,
    project_ret: NativeProperty,
    draw_line: &'static UFunction,
    line_params: [NativeProperty; 6],
    player_owner: usize,
}

static CALLS: Mutex<Option<&'static Calls>> = Mutex::new(None);

fn param(f: &UFunction, name: &str) -> Result<NativeProperty, String> {
    f.iter_parameters()
        .into_iter()
        .find(|p| p.name == name)
        .ok_or_else(|| format!("parameter {name} not found"))
}

fn function(class: &str, name: &str) -> Result<&'static UFunction, String> {
    let c = crate::ue::find_class_fast(class).ok_or_else(|| format!("class {class} not found"))?;
    let f = c
        .get_function(class, name)
        .ok_or_else(|| format!("{class}::{name} not found"))?;
    // SAFETY: UFunctions are class members and live as long as the class.
    Ok(unsafe { &*(f as *const UFunction) })
}

fn resolve(hud: &UObject) -> Result<&'static Calls, String> {
    let project = function("PlayerController", "ProjectWorldLocationToScreen")?;
    let draw_line = function("HUD", "DrawLine")?;
    let draw_hud = function("HUD", "ReceiveDrawHUD")? as *const UFunction as usize;
    let player_owner = crate::reflect::fields_of(hud)
        .into_iter()
        .find(|(p, _)| p.name == "PlayerOwner")
        .map(|(p, _)| p.offset as usize)
        .ok_or("HUD.PlayerOwner not found")?;
    let calls = Calls {
        draw_hud,
        project,
        project_world: param(project, "WorldLocation")?,
        project_screen: param(project, "ScreenLocation")?,
        project_ret: param(project, "ReturnValue")?,
        draw_line,
        line_params: [
            param(draw_line, "StartScreenX")?,
            param(draw_line, "StartScreenY")?,
            param(draw_line, "EndScreenX")?,
            param(draw_line, "EndScreenY")?,
            param(draw_line, "LineColor")?,
            param(draw_line, "LineThickness")?,
        ],
        player_owner,
    };
    Ok(Box::leak(Box::new(calls)))
}

/// Write `v` at a parameter as f32s or f64s, whichever its size says.
fn write_reals(buf: &mut [u8], p: &NativeProperty, v: &[f64]) {
    let o = p.offset as usize;
    let wide = p.element_size as usize == v.len() * 8;
    for (i, x) in v.iter().enumerate() {
        if wide {
            buf[o + i * 8..o + i * 8 + 8].copy_from_slice(&x.to_le_bytes());
        } else {
            buf[o + i * 4..o + i * 4 + 4].copy_from_slice(&(*x as f32).to_le_bytes());
        }
    }
}

fn read_reals(buf: &[u8], p: &NativeProperty, n: usize) -> Vec<f64> {
    let o = p.offset as usize;
    let wide = p.element_size as usize == n * 8;
    (0..n)
        .map(|i| {
            if wide {
                f64::from_le_bytes(buf[o + i * 8..o + i * 8 + 8].try_into().unwrap())
            } else {
                f32::from_le_bytes(buf[o + i * 4..o + i * 4 + 4].try_into().unwrap()) as f64
            }
        })
        .collect()
}

/// Screen position of a world point, or None behind the camera.
///
/// # Safety
/// Game thread, inside the HUD draw; `pc` is the HUD's live owner.
unsafe fn project(c: &Calls, pc: &UObject, p: [f64; 3]) -> Option<[f64; 2]> {
    let mut buf = vec![0u8; c.project.parms_size().max(1) as usize];
    write_reals(&mut buf, &c.project_world, &p);
    unsafe { pc.process_event(c.project, buf.as_mut_ptr().cast()) };
    if buf[c.project_ret.offset as usize] == 0 {
        return None;
    }
    let s = read_reals(&buf, &c.project_screen, 2);
    Some([s[0], s[1]])
}

/// Draw every line. Game thread, inside the HUD draw.
unsafe fn draw(c: &Calls, hud: &UObject) {
    let Some(lines) = LINES.try_lock() else {
        return;
    };
    if lines.is_empty() {
        return;
    }
    // SAFETY: PlayerOwner is a reflected pointer field of the live HUD.
    let pc = unsafe { (hud.field_ptr(c.player_owner) as *const usize).read_unaligned() };
    if pc == 0 || !crate::ue::is_live(pc) {
        return;
    }
    // SAFETY: just checked live in GObjects.
    let pc = unsafe { &*(pc as *const UObject) };
    let mut buf = vec![0u8; c.draw_line.parms_size().max(1) as usize];
    for line in lines.iter() {
        let [r, g, b, a] = line.color;
        let color = [r as f64, g as f64, b as f64, a as f64];
        let mut last: Option<[f64; 2]> = None;
        for w in line.points.windows(2) {
            let d = [w[1][0] - w[0][0], w[1][1] - w[0][1], w[1][2] - w[0][2]];
            let len = (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]).sqrt();
            let pieces = ((len / PIECE).ceil() as usize).max(1);
            if last.is_none() {
                last = unsafe { project(c, pc, w[0]) };
            }
            for k in 1..=pieces {
                let t = k as f64 / pieces as f64;
                let p = [w[0][0] + d[0] * t, w[0][1] + d[1] * t, w[0][2] + d[2] * t];
                let now = unsafe { project(c, pc, p) };
                if let (Some(s), Some(e)) = (last, now) {
                    buf.fill(0);
                    let [sx, sy, ex, ey, col, th] = &c.line_params;
                    write_reals(&mut buf, sx, &[s[0]]);
                    write_reals(&mut buf, sy, &[s[1]]);
                    write_reals(&mut buf, ex, &[e[0]]);
                    write_reals(&mut buf, ey, &[e[1]]);
                    // FLinearColor is four f32 on every engine version.
                    for (i, v) in color.iter().enumerate() {
                        let o = col.offset as usize + i * 4;
                        buf[o..o + 4].copy_from_slice(&(*v as f32).to_le_bytes());
                    }
                    write_reals(&mut buf, th, &[line.thickness as f64]);
                    unsafe { hud.process_event(c.draw_line, buf.as_mut_ptr().cast()) };
                }
                last = now;
            }
        }
    }
}

fn live_hud() -> Option<&'static UObject> {
    crate::ue::actor::find_objects_by_chain("HUD")
        .into_iter()
        // SAFETY: addresses from the GObjects walk.
        .map(|p| unsafe { &*(p as *const UObject) })
        .find(|o| !o.is_default_object())
}

/// Hook the current HUD if it is not hooked yet (a new HUD class after a
/// map change brings a new function table).
pub fn ensure_installed() -> Result<String, String> {
    let hud = live_hud().ok_or("no live HUD")?;
    // SAFETY: a live UObject's first word is its function table.
    let vtable = unsafe { (hud as *const UObject as *const usize).read_unaligned() };
    let mut hook = HOOK.lock();
    if hook.as_ref().is_some_and(|h| h.hud_vtable == vtable) {
        return Ok(hud.name());
    }
    let calls = resolve(hud)?;
    *CALLS.lock() = Some(calls);
    let class: &'static str = Box::leak(
        hud.class()
            .map(|c| c.as_object().name())
            .unwrap_or_else(|| "HUD".into())
            .into_boxed_str(),
    );
    let installed = ProcessEventHook::install_for_object(class, hud, move |this, function, parms, original| {
        // SAFETY: the engine's own call, passed on unchanged first.
        unsafe { original.call(this, function, parms) };
        if function as *const UFunction as usize != calls.draw_hud {
            return;
        }
        let this_addr = this as *const UObject as usize;
        let drawn = modforge::seh::guard(|| {
            // SAFETY: game thread, inside AHUD::DrawHUD on the live HUD.
            unsafe { draw(calls, &*(this_addr as *const UObject)) }
        });
        if drawn.is_err() {
            LINES.lock().clear();
            crate::log!("overlay: drawing faulted; lines cleared");
        }
    })
    .map_err(|e| format!("overlay hook on {class}: {e}"))?;
    *hook = Some(Installed { _hook: installed, hud_vtable: vtable });
    crate::log!("overlay: drawing on {class} ({})", hud.name());
    Ok(hud.name())
}

/// Replace the lines drawn.
pub fn set_lines(lines: Vec<OverlayLine>) {
    *LINES.lock() = lines;
}

fn parse_line(v: &Value) -> Result<OverlayLine, String> {
    let points = v["points"]
        .as_array()
        .ok_or("points must be an array")?
        .iter()
        .map(|p| {
            let a = p.as_array().filter(|a| a.len() == 3).ok_or("a point is [x, y, z]")?;
            let f = |i: usize| a[i].as_f64().ok_or("point values are numbers");
            Ok([f(0)?, f(1)?, f(2)?])
        })
        .collect::<Result<Vec<_>, &str>>()?;
    let color = v["color"]
        .as_array()
        .map(|c| {
            let f = |i: usize, d: f32| c.get(i).and_then(Value::as_f64).map(|x| x as f32).unwrap_or(d);
            [f(0, 0.0), f(1, 1.0), f(2, 1.0), f(3, 1.0)]
        })
        .unwrap_or([0.0, 1.0, 1.0, 1.0]);
    let thickness = v["thickness"].as_f64().unwrap_or(4.0) as f32;
    Ok(OverlayLine { points, color, thickness })
}

/// `overlay.lines` and `overlay.clear`, plus the unhook at shutdown.
pub fn register_ops() {
    use crate::ops::{OP_REGISTRY, OpDef};
    OP_REGISTRY.register_many([
        OpDef::new(
            "overlay.lines",
            "Draw lines over the game picture, seen through walls: each {points: [[x,y,z]...], color?: [r,g,b,a], thickness?: px}; replaces the previous lines",
            "{lines: [{points, color?, thickness?}]}",
            |args| {
                let lines = args["lines"]
                    .as_array()
                    .ok_or("lines must be an array")?
                    .iter()
                    .map(parse_line)
                    .collect::<Result<Vec<_>, _>>()?;
                let n = lines.len();
                set_lines(lines);
                let hud = ensure_installed()?;
                Ok(json!({"lines": n, "hud": hud}))
            },
        ),
        OpDef::new("overlay.clear", "Stop drawing overlay lines", "{}", |_args| {
            set_lines(Vec::new());
            Ok(json!({"cleared": true}))
        }),
    ]);
    modforge::shutdown::SHUTDOWN_REGISTRY
        .record("ueforge/overlay", "unhook the HUD".into(), 90, || {
            LINES.lock().clear();
            HOOK.lock().take();
        })
        .keep();
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn line_defaults() {
        let l = parse_line(&json!({"points": [[0, 0, 0], [1, 2, 3]]})).unwrap();
        assert_eq!(l.points.len(), 2);
        assert_eq!(l.color, [0.0, 1.0, 1.0, 1.0]);
        assert_eq!(l.thickness, 4.0);
    }

    #[test]
    fn reals_by_size() {
        let narrow = NativeProperty { name: "v".into(), offset: 0, element_size: 12, address: 0 };
        let wide = NativeProperty { name: "v".into(), offset: 0, element_size: 24, address: 0 };
        let mut b = vec![0u8; 24];
        write_reals(&mut b, &narrow, &[1.0, 2.0, 3.0]);
        assert_eq!(read_reals(&b, &narrow, 3), vec![1.0, 2.0, 3.0]);
        write_reals(&mut b, &wide, &[4.0, 5.0, 6.0]);
        assert_eq!(read_reals(&b, &wide, 3), vec![4.0, 5.0, 6.0]);
    }
}

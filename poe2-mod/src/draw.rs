//! What the overlay draws, as shapes in the game window's pixels, with
//! GameHelper2's default looks: health bars (Plugins/HealthBars
//! HealthBars.cs DrawHealthbar, HealthBarsSettings.cs, Config.cs), the
//! ritual wisp range (Plugins/RitualWispAlert RitualWispAlertCore.cs,
//! RitualWispAlertSettings.cs) and item prices (Plugins/LootValue
//! LootValueSettings.cs, LootValueCore.cs FormatValue). Each takes data
//! already turned into screen points, so all of it is tested without a
//! window.

use crate::health_bars::{Bar, Style};
use modforge::overlay::{Rgb, Shape};

/// Config.Scale.X for every bar.
pub const BAR_WIDTH: f32 = 128.0;
/// Config: background black, energy shield and text cyan.
pub const BAR_BACKGROUND: Rgb = 0x000000;
pub const BAR_SHIELD: Rgb = 0x00FFFF;
pub const BAR_TEXT: Rgb = 0x00FFFF;
/// The health colour once health is in culling strike range.
pub const BAR_CULL: Rgb = 0xFFFFFF;
/// Text height in pixels, for the text above a bar.
pub const FONT: f32 = 16.0;
/// RitualWispAlertSettings: inside and outside colours, thickness.
pub const WISP_INSIDE: Rgb = 0x00FF00;
pub const WISP_OUTSIDE: Rgb = 0xFFE600;
pub const WISP_THICKNESS: i32 = 2;
/// LootValueSettings: text colour, highlight colour and the value from
/// which a price is highlighted, the least value shown.
pub const PRICE_TEXT: Rgb = 0xFFEB8C;
pub const PRICE_HIGHLIGHT: Rgb = 0x66FF66;
pub const HIGHLIGHT_MIN_EX: f64 = 10.0;
pub const MIN_VALUE_EX: f64 = 1.0;

/// One bar style's HealthBarsSettings defaults.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct BarLook {
    pub color: Rgb,
    pub height: f32,
    pub graduations: u32,
    pub text: bool,
}

pub fn bar_look(style: Style) -> BarLook {
    let plain = |color, height| BarLook {
        color,
        height,
        graduations: 0,
        text: false,
    };
    match style {
        Style::White => plain(0x800000, 8.0),
        Style::Magic => plain(0x0080FF, 10.0),
        Style::Rare => BarLook {
            color: 0xFFFF00,
            height: 16.0,
            graduations: 9,
            text: true,
        },
        Style::Unique => BarLook {
            color: 0xFF8000,
            height: 16.0,
            graduations: 9,
            text: true,
        },
        Style::Friendly => plain(0x00FF00, 8.0),
        Style::PlayerSelf | Style::PlayerLeader => plain(0xFF00FF, 8.0),
        Style::PlayerMember => plain(0x80FF80, 8.0),
    }
}

/// healthToHumanReadable.
pub fn human(value: i32) -> String {
    if value >= 100_000 {
        format!("{:.2}M", value as f32 / 1_000_000.0)
    } else if value >= 100 {
        format!("{:.2}K", value as f32 / 1000.0)
    } else {
        value.to_string()
    }
}

/// A filled bar part from the left, `percent` of `width`.
fn fill(at: [f32; 2], width: f32, height: f32, percent: i32, color: Rgb) -> Shape {
    Shape::Rect {
        at,
        size: [width * percent.clamp(0, 100) as f32 / 100.0, height],
        color,
        filled: true,
    }
}

/// DrawHealthbar: centred on `at`, the background, the health (white
/// once cullable), energy shield or mana over it, graduation lines and
/// the total above. GameHelper2 draws the second value with its own
/// texture over the whole bar; here it is the bar's bottom quarter so
/// the health stays visible.
pub fn health_bar(bar: &Bar, at: (f32, f32)) -> Vec<Shape> {
    let look = bar_look(bar.style);
    let start = [at.0 - BAR_WIDTH / 2.0, at.1 - look.height / 2.0];
    let mut out = vec![
        Shape::Rect {
            at: start,
            size: [BAR_WIDTH, look.height],
            color: BAR_BACKGROUND,
            filled: true,
        },
        fill(
            start,
            BAR_WIDTH,
            look.height,
            bar.health_percent,
            if bar.cullable { BAR_CULL } else { look.color },
        ),
    ];
    if let Some(p) = bar.second_percent {
        let h = (look.height / 4.0).max(2.0);
        let low = [start[0], start[1] + look.height - h];
        out.push(fill(low, BAR_WIDTH, h, p, BAR_SHIELD));
    }
    let step = BAR_WIDTH / (look.graduations + 1) as f32;
    for i in 1..=look.graduations {
        let x = start[0] + step * i as f32;
        out.push(Shape::Line {
            from: [x, start[1] - 1.0],
            to: [x, start[1] - 1.0 + look.height],
            color: BAR_BACKGROUND,
            width: 1,
        });
    }
    if look.text {
        out.push(Shape::Text {
            at: [start[0], start[1] - FONT],
            text: human(bar.total),
            color: BAR_TEXT,
        });
    }
    out
}

/// The wisp's range on the ground: green with the player inside,
/// yellow outside. Points behind the camera are left out.
pub fn wisp(inside: bool, circle: &[Option<(f32, f32)>]) -> Option<Shape> {
    let points: Vec<[f32; 2]> = circle.iter().flatten().map(|(x, y)| [*x, *y]).collect();
    (points.len() >= 2).then_some(Shape::Path {
        points,
        color: if inside { WISP_INSIDE } else { WISP_OUTSIDE },
        width: WISP_THICKNESS,
        closed: true,
    })
}

/// FormatValue for exalted orbs: at most one decimal.
pub fn price_text(exalted: f64) -> String {
    let rounded = (exalted * 10.0).round() / 10.0;
    if rounded.fract() == 0.0 {
        format!("{rounded:.0} ex")
    } else {
        format!("{rounded:.1} ex")
    }
}

/// An item's label at its screen point: its name (the unique's name
/// when known) and its price when it is worth at least
/// [`MIN_VALUE_EX`]; highlighted from [`HIGHLIGHT_MIN_EX`], or when an
/// item rule matched.
pub fn item_label(name: &str, exalted: Option<f64>, rule: bool, at: (f32, f32)) -> Shape {
    let worth = exalted.filter(|v| *v >= MIN_VALUE_EX);
    let text = match worth {
        Some(v) => format!("{name} {}", price_text(v)),
        None => name.to_string(),
    };
    let highlight = rule || worth.is_some_and(|v| v >= HIGHLIGHT_MIN_EX);
    Shape::Text {
        at: [at.0, at.1],
        text,
        color: if highlight {
            PRICE_HIGHLIGHT
        } else {
            PRICE_TEXT
        },
    }
}

/// The zone line in the top left.
pub fn zone_line(name: &str, level: Option<i32>) -> Shape {
    let text = match level {
        Some(l) => format!("{name} ({l})"),
        None => name.to_string(),
    };
    Shape::Text {
        at: [8.0, 8.0],
        text,
        color: PRICE_TEXT,
    }
}

/// PlayerBuffBarSettings: icon size and spacing, and how far below the
/// player's health bar the resource row and the buff row sit.
pub const ICON_SIZE: f32 = 28.0;
pub const ICON_SPACING: f32 = 4.0;
pub const RESOURCE_OFFSET: [f32; 2] = [0.0, 8.0];
pub const BUFF_OFFSET: [f32; 2] = [0.0, 36.0];
/// ActiveColor, the inactive border, BuffTextColor, ChargeTextColor and
/// RageTextColor.
pub const BUFF_ACTIVE: Rgb = 0x33D959;
pub const BUFF_INACTIVE: Rgb = 0x666666;
pub const BUFF_TEXT: Rgb = 0xFFFFFF;
pub const CHARGE_TEXT: Rgb = 0xFFEB59;
pub const RAGE_TEXT: Rgb = 0xFF7333;
/// The overlay draws without alpha, so an inactive icon's text is white
/// at InactiveIconAlpha (0.35) over black.
pub const INACTIVE_TEXT: Rgb = 0x595959;
/// The overlay's system font: about this wide per character, for
/// centring text.
pub const CHAR_WIDTH: f32 = 8.0;

/// GetRowWidth.
pub fn row_width(count: usize) -> f32 {
    count as f32 * ICON_SIZE + count.saturating_sub(1) as f32 * ICON_SPACING
}

/// ResolveBarTopLeft anchored to the health bar: centred under it.
fn row_start(anchor: (f32, f32), offset: [f32; 2], count: usize) -> [f32; 2] {
    [
        anchor.0 + offset[0] - row_width(count) / 2.0,
        anchor.1 + offset[1],
    ]
}

/// A box outline `width` pixels thick.
fn outline(at: [f32; 2], size: f32, color: Rgb, width: i32) -> Shape {
    let [x, y] = at;
    Shape::Path {
        points: vec![[x, y], [x + size, y], [x + size, y + size], [x, y + size]],
        color,
        width,
        closed: true,
    }
}

/// Text centred across a cell `size` wide starting at `x`.
fn centred(x: f32, y: f32, size: f32, text: String, color: Rgb) -> Shape {
    let w = text.len() as f32 * CHAR_WIDTH;
    Shape::Text {
        at: [x + (size - w) / 2.0, y],
        text,
        color,
    }
}

/// The count in a black badge at the cell's bottom
/// (ShowResourceCountBackground, on by default).
fn badge(at: [f32; 2], text: String, color: Rgb) -> [Shape; 2] {
    let h = (FONT + 2.0).max(12.0);
    let top = at[1] + ICON_SIZE - h;
    [
        Shape::Rect {
            at: [at[0], top],
            size: [ICON_SIZE, h],
            color: BAR_BACKGROUND,
            filled: true,
        },
        centred(at[0], top + (h - FONT) / 2.0, ICON_SIZE, text, color),
    ]
}

/// FormatSeconds: whole minutes from 60 seconds up, else whole seconds,
/// both rounded up.
pub fn seconds(s: f32) -> String {
    if s >= 60.0 {
        format!("{}m", (s / 60.0).ceil() as i32)
    } else {
        format!("{}s", s.ceil() as i32)
    }
}

/// The resource row (DrawResourceIconCell, no icon pictures): a black
/// cell framed in the charge's colour, its letter and its count.
pub fn resource_row(resources: &[(&str, i32)], anchor: (f32, f32)) -> Vec<Shape> {
    let start = row_start(anchor, RESOURCE_OFFSET, resources.len());
    let mut out = Vec::new();
    for (i, (id, count)) in resources.iter().enumerate() {
        let at = [start[0] + i as f32 * (ICON_SIZE + ICON_SPACING), start[1]];
        let active = *count > 0;
        let (border, letter) = match *id {
            "power_charge" => (0x598CFF, "P"),
            "frenzy_charge" => (0x59F273, "F"),
            "endurance_charge" => (0xF2594D, "E"),
            "rage" => (RAGE_TEXT, "R"),
            _ => (0x999999, "?"),
        };
        out.push(Shape::Rect {
            at,
            size: [ICON_SIZE, ICON_SIZE],
            color: BAR_BACKGROUND,
            filled: true,
        });
        out.push(outline(at, ICON_SIZE, border, if active { 2 } else { 1 }));
        let tint = if active { BUFF_TEXT } else { INACTIVE_TEXT };
        out.push(centred(
            at[0],
            at[1] + (ICON_SIZE - FONT) / 2.0,
            ICON_SIZE,
            letter.into(),
            tint,
        ));
        let color = if *id == "rage" {
            RAGE_TEXT
        } else {
            CHARGE_TEXT
        };
        out.extend(badge(at, (*count).max(0).to_string(), color));
    }
    out
}

/// The buff row (DrawBuffIconCell, no icon pictures): a black cell with
/// the watch id's first two letters, a green frame when on and grey
/// when not, the stacks from 2 up and the time left under the cell.
pub fn buff_row(entries: &[crate::buff_bar::Entry], anchor: (f32, f32)) -> Vec<Shape> {
    let start = row_start(anchor, BUFF_OFFSET, entries.len());
    let mut out = Vec::new();
    for (i, e) in entries.iter().enumerate() {
        let at = [start[0] + i as f32 * (ICON_SIZE + ICON_SPACING), start[1]];
        out.push(Shape::Rect {
            at,
            size: [ICON_SIZE, ICON_SIZE],
            color: BAR_BACKGROUND,
            filled: true,
        });
        let short: String = if e.watch.chars().count() >= 2 {
            e.watch.chars().take(2).collect::<String>().to_uppercase()
        } else {
            "?".into()
        };
        let tint = if e.active { BUFF_TEXT } else { INACTIVE_TEXT };
        out.push(centred(
            at[0],
            at[1] + (ICON_SIZE - FONT) / 2.0,
            ICON_SIZE,
            short,
            tint,
        ));
        out.push(if e.active {
            outline(at, ICON_SIZE, BUFF_ACTIVE, 2)
        } else {
            outline(at, ICON_SIZE, BUFF_INACTIVE, 1)
        });
        if e.active && e.stacks > 1 {
            out.extend(badge(at, e.stacks.to_string(), BUFF_TEXT));
        }
        if let (true, Some(t)) = (e.active, e.time_left) {
            let label = seconds(t);
            let y = at[1] + ICON_SIZE + 1.0;
            if let Shape::Text { at: p, text, .. } =
                centred(at[0], y, ICON_SIZE, label.clone(), BAR_BACKGROUND)
            {
                out.push(Shape::Text {
                    at: [p[0] + 1.0, p[1] + 1.0],
                    text,
                    color: BAR_BACKGROUND,
                });
            }
            out.push(centred(at[0], y, ICON_SIZE, label, BUFF_TEXT));
        }
    }
    out
}

/// RadarSettings.WalkableMapColor: 150 grey.
pub const WALKABLE_MAP: Rgb = 0x969696;
/// RadarSettings.POIColor (1, 0.5, 0.5).
pub const POI_TEXT: Rgb = 0xFF7F7F;
/// Radar.DrawDirectionLines poiPalette, one colour per point in turn.
pub const PATH_PALETTE: [Rgb; 8] = [
    0x00DCFF, 0xFFC800, 0xFF69B4, 0x00FF7F, 0xFF6347, 0x7B68EE, 0xFFA500, 0x32CD32,
];
/// DirectionLineThickness 0.1 plus 1, rounded to whole pixels.
pub const PATH_WIDTH: i32 = 1;

/// A named point on the radar: its grid cell and ground height.
pub struct RadarLabel<'a> {
    pub name: &'a str,
    pub cell: [f32; 2],
    pub height: f32,
}

/// The large map radar after Radar.DrawLargeMap, DrawTgtFiles and
/// DrawDirectionLines: the walkable outline picture under the map, each
/// label's name on a black box, and a path from the player to each
/// label (`paths[i]` goes with `labels[i]`, None when it has none), in
/// grid cells with ground heights. `player` is the player's grid
/// position and `player_height` its ground height.
pub fn radar(
    view: &crate::radar::MapView,
    player: [f32; 2],
    player_height: f32,
    picture: Option<&std::sync::Arc<modforge::overlay::Image>>,
    labels: &[RadarLabel],
    paths: &[Option<Vec<([f32; 2], f32)>>],
) -> Vec<Shape> {
    let mut out = Vec::new();
    let from_player = |cell: [f32; 2], height: f32| {
        view.at(
            [cell[0] - player[0], cell[1] - player[1]],
            -player_height + height,
        )
    };
    if let Some(image) = picture {
        let (w, h) = (image.width as f32, image.height as f32);
        let corner = |x: f32, y: f32| view.at([x - player[0], y - player[1]], -player_height);
        out.push(Shape::Image {
            corners: [corner(0.0, 0.0), corner(w, 0.0), corner(0.0, h)],
            image: image.clone(),
        });
    }
    for l in labels {
        let at = from_player(l.cell, l.height);
        let half = [l.name.len() as f32 * CHAR_WIDTH / 2.0, FONT / 2.0];
        let min = [at[0] - half[0], at[1] - half[1]];
        out.push(Shape::Rect {
            at: min,
            size: [half[0] * 2.0, half[1] * 2.0],
            color: BAR_BACKGROUND,
            filled: true,
        });
        out.push(Shape::Text {
            at: min,
            text: l.name.to_string(),
            color: POI_TEXT,
        });
    }
    // Paths draw over the names, as DrawDirectionLines runs after
    // DrawTgtFiles.
    let me = from_player(player, player_height);
    for (i, path) in paths.iter().enumerate() {
        let Some(path) = path else { continue };
        if path.len() < 2 {
            continue;
        }
        let mut points = vec![me];
        points.extend(path[1..].iter().map(|(c, h)| from_player(*c, *h)));
        out.push(Shape::Path {
            points,
            color: PATH_PALETTE[i % PATH_PALETTE.len()],
            width: PATH_WIDTH,
            closed: false,
        });
    }
    out
}

/// A small ring on the player's feet.
pub fn player_mark(at: (f32, f32)) -> Shape {
    Shape::Circle {
        centre: [at.0, at.1],
        radius: 6.0,
        color: 0xFF00FF,
        width: 2,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn bar(style: Style, health: i32, second: Option<i32>, cullable: bool) -> Bar {
        Bar {
            address: 0,
            id: 1,
            style,
            anchor: [0.0; 3],
            health_percent: health,
            second_percent: second,
            cullable,
            total: 12_345,
        }
    }

    #[test]
    fn a_rare_bar_like_gamehelper2() {
        let s = health_bar(&bar(Style::Rare, 50, Some(25), false), (500.0, 300.0));
        // Background, health, shield, 9 graduations, text.
        assert_eq!(s.len(), 1 + 1 + 1 + 9 + 1);
        assert_eq!(
            s[0],
            Shape::Rect {
                at: [436.0, 292.0],
                size: [128.0, 16.0],
                color: BAR_BACKGROUND,
                filled: true
            }
        );
        assert_eq!(
            s[1],
            Shape::Rect {
                at: [436.0, 292.0],
                size: [64.0, 16.0],
                color: 0xFFFF00,
                filled: true
            }
        );
        assert_eq!(
            s[2],
            Shape::Rect {
                at: [436.0, 304.0],
                size: [32.0, 4.0],
                color: BAR_SHIELD,
                filled: true
            }
        );
        assert_eq!(
            s[3],
            Shape::Line {
                from: [436.0 + 12.8, 291.0],
                to: [436.0 + 12.8, 307.0],
                color: BAR_BACKGROUND,
                width: 1
            }
        );
        assert_eq!(
            s[12],
            Shape::Text {
                at: [436.0, 276.0],
                text: "12.35K".into(),
                color: BAR_TEXT
            }
        );
        // A white monster in cull range: white health, no extras.
        let w = health_bar(&bar(Style::White, 5, None, true), (0.0, 0.0));
        assert_eq!(w.len(), 2);
        assert!(matches!(
            w[1],
            Shape::Rect {
                color: BAR_CULL,
                ..
            }
        ));
    }

    #[test]
    fn numbers_and_prices_like_gamehelper2() {
        assert_eq!(human(99), "99");
        assert_eq!(human(1500), "1.50K");
        assert_eq!(human(2_500_000), "2.50M");
        assert_eq!(price_text(3.0), "3 ex");
        assert_eq!(price_text(2.46), "2.5 ex");
        let cheap = item_label("Gold Ring", Some(0.5), false, (1.0, 2.0));
        assert_eq!(
            cheap,
            Shape::Text {
                at: [1.0, 2.0],
                text: "Gold Ring".into(),
                color: PRICE_TEXT
            }
        );
        let rich = item_label("Divine Orb", Some(150.0), false, (1.0, 2.0));
        assert!(
            matches!(rich, Shape::Text { ref text, color: PRICE_HIGHLIGHT, .. } if text == "Divine Orb 150 ex")
        );
        let ruled = item_label("Ring", None, true, (0.0, 0.0));
        assert!(matches!(
            ruled,
            Shape::Text {
                color: PRICE_HIGHLIGHT,
                ..
            }
        ));
    }

    #[test]
    fn buff_and_resource_rows_like_gamehelper2() {
        use crate::buff_bar::Entry;
        assert_eq!(row_width(3), 3.0 * 28.0 + 2.0 * 4.0);
        assert_eq!((seconds(4.2), seconds(61.0)), ("5s".into(), "2m".into()));
        let r = resource_row(&[("power_charge", 3), ("rage", 0)], (100.0, 50.0));
        // Per cell: background, frame, letter, badge and count.
        assert_eq!(r.len(), 10);
        // Two cells are 60 wide, centred on x 100, 8 below the anchor.
        assert!(matches!(
            r[0],
            Shape::Rect {
                at: [70.0, 58.0],
                ..
            }
        ));
        assert!(matches!(
            r[1],
            Shape::Path {
                color: 0x598CFF,
                width: 2,
                ..
            }
        ));
        assert!(matches!(
            r[6],
            Shape::Path {
                color: RAGE_TEXT,
                width: 1,
                ..
            }
        ));
        assert!(matches!(r[9], Shape::Text { ref text, color: RAGE_TEXT, .. } if text == "0"));
        let entry = |watch: &str, active, stacks, time_left| Entry {
            watch: watch.into(),
            active,
            buff: None,
            stacks,
            time_left,
        };
        let b = buff_row(
            &[
                entry("fortify", true, 3, Some(2.5)),
                entry("haste", false, 0, None),
            ],
            (100.0, 50.0),
        );
        // Fortify: background, "FO", frame, badge, count, shadow, time.
        // Haste: background, "HA" in grey, grey frame.
        assert_eq!(b.len(), 7 + 3);
        assert!(matches!(
            b[0],
            Shape::Rect {
                at: [70.0, 86.0],
                ..
            }
        ));
        assert!(matches!(b[1], Shape::Text { ref text, color: BUFF_TEXT, .. } if text == "FO"));
        assert!(matches!(
            b[2],
            Shape::Path {
                color: BUFF_ACTIVE,
                width: 2,
                ..
            }
        ));
        assert!(matches!(b[4], Shape::Text { ref text, .. } if text == "3"));
        assert!(matches!(b[6], Shape::Text { ref text, at: [_, 115.0], .. } if text == "3s"));
        assert!(matches!(b[8], Shape::Text { ref text, color: INACTIVE_TEXT, .. } if text == "HA"));
        assert!(matches!(
            b[9],
            Shape::Path {
                color: BUFF_INACTIVE,
                width: 1,
                ..
            }
        ));
    }

    #[test]
    fn the_wisp_ring_skips_points_behind_the_camera() {
        let ring = [Some((0.0, 0.0)), None, Some((10.0, 0.0)), Some((5.0, 5.0))];
        assert_eq!(
            wisp(true, &ring),
            Some(Shape::Path {
                points: vec![[0.0, 0.0], [10.0, 0.0], [5.0, 5.0]],
                color: WISP_INSIDE,
                width: 2,
                closed: true
            })
        );
        assert_eq!(wisp(false, &[None, Some((1.0, 1.0))]), None);
    }

    #[test]
    fn the_radar_puts_the_map_names_and_paths_around_the_player() {
        use crate::radar::{LargeMap, MapView};
        let view = MapView::large_map(
            &LargeMap {
                centre: [500.0, 400.0],
                zoom: 1.0,
            },
            1080.0,
        );
        let image = std::sync::Arc::new(modforge::overlay::Image {
            width: 100,
            height: 50,
            pixels: vec![0; 5000],
        });
        let player = [40.0, 20.0];
        let labels = [RadarLabel {
            name: "Exit",
            cell: [60.0, 20.0],
            height: -10.0,
        }];
        let paths = [Some(vec![
            ([40.0, 20.0], -10.0),
            ([50.0, 20.0], -10.0),
            ([60.0, 20.0], -10.0),
        ])];
        let s = radar(&view, player, -10.0, Some(&image), &labels, &paths);
        assert_eq!(s.len(), 4, "picture, name box, name, path: {s:?}");
        // The picture's top left corner is the grid origin.
        let Shape::Image { corners, .. } = &s[0] else {
            panic!("{:?}", s[0])
        };
        assert_eq!(corners[0], view.at([-40.0, -20.0], 10.0));
        assert_eq!(corners[1], view.at([60.0, -20.0], 10.0));
        assert_eq!(corners[2], view.at([-40.0, 30.0], 10.0));
        // The name is centred on its point, on a black box.
        let at = view.at([20.0, 0.0], 0.0);
        assert_eq!(
            s[1],
            Shape::Rect {
                at: [at[0] - 16.0, at[1] - 8.0],
                size: [32.0, 16.0],
                color: BAR_BACKGROUND,
                filled: true
            }
        );
        assert!(matches!(&s[2], Shape::Text { text, color: POI_TEXT, .. } if text == "Exit"));
        // The path starts at the player, the map's centre.
        let Shape::Path { points, color, .. } = &s[3] else {
            panic!("{:?}", s[3])
        };
        assert_eq!(points[0], [500.0, 400.0]);
        assert_eq!(points.len(), 3);
        assert_eq!(*color, PATH_PALETTE[0]);
        assert_eq!(radar(&view, player, 0.0, None, &[], &[None]), vec![]);
    }
}

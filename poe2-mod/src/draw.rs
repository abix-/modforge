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
}

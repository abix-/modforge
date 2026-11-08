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
        let color = PATH_PALETTE[i % PATH_PALETTE.len()];
        out.extend(radar_path(me, path.as_deref(), &from_player, color));
    }
    out
}

/// A path on the radar from the player's point `me` along `path`'s
/// cells after the first; none when it is shorter than two.
fn radar_path(
    me: [f32; 2],
    path: Option<&[([f32; 2], f32)]>,
    from_player: &dyn Fn([f32; 2], f32) -> [f32; 2],
    color: Rgb,
) -> Option<Shape> {
    let path = path.filter(|p| p.len() >= 2)?;
    let mut points = vec![me];
    points.extend(path[1..].iter().map(|(c, h)| from_player(*c, *h)));
    Some(Shape::Path {
        points,
        color,
        width: PATH_WIDTH,
        closed: false,
    })
}

/// A tracked node on the radar (Radar.cs DrawMapIcons and the tracked
/// node paths): a dot where its icon goes, then its path from the
/// player, both in `color`. Each mark is its cell, ground height and
/// path cells with heights.
pub fn radar_marks(
    view: &crate::radar::MapView,
    player: [f32; 2],
    player_height: f32,
    marks: &[([f32; 2], f32, Option<Vec<([f32; 2], f32)>>)],
    color: Rgb,
) -> Vec<Shape> {
    let from_player = |cell: [f32; 2], height: f32| {
        view.at(
            [cell[0] - player[0], cell[1] - player[1]],
            -player_height + height,
        )
    };
    let me = from_player(player, player_height);
    let mut out = Vec::new();
    for (cell, height, path) in marks {
        out.push(dot(from_player(*cell, *height), 8.0, color));
        out.extend(radar_path(me, path.as_deref(), &from_player, color));
    }
    out
}

/// An Atlas2 colour (0..1 parts) as an overlay colour. The overlay has
/// no see-through, so alpha is dropped.
const fn rgb(r: f32, g: f32, b: f32) -> Rgb {
    ((r * 255.0 + 0.5) as u32) << 16 | ((g * 255.0 + 0.5) as u32) << 8 | (b * 255.0 + 0.5) as u32
}

/// One Atlas2Settings map group: its name, the maps it holds, and its
/// font and background colours.
pub struct MapGroup {
    pub name: &'static str,
    pub maps: &'static [&'static str],
    pub font: Rgb,
    pub background: Rgb,
}

/// Atlas2Settings DefaultBackgroundColor (0, 0, 0, 0.85) and
/// DefaultFontColor.
pub const ATLAS_BACKGROUND: Rgb = 0x000000;
pub const ATLAS_FONT: Rgb = 0xFFFFFF;

/// The Atlas2Settings constructor's named map groups, in its order
/// (the first that matches wins). The Search, Corrupted Nexus and
/// Grand Mirror groups match by content instead and are in
/// [`atlas_group`].
pub const MAP_GROUPS: &[MapGroup] = &[
    MapGroup {
        name: "Lineage Maps",
        maps: &["Derelict Mansion", "Sacred Reservoir", "Sealed Vault", "The Jade Isles"],
        font: rgb(0.0, 0.0, 0.0),
        background: rgb(0.0, 181.0 / 255.0, 33.0 / 255.0),
    },
    MapGroup {
        name: "Atlas Progression",
        maps: &[
            "Precursor Tower",
            "Ancient Gateway",
            "The Burning Monolith",
            "Western Gateway",
            "Eastern Gateway",
            "Western Enigma Chamber",
            "Eastern Enigma Chamber",
            "The Origin Tower",
        ],
        font: rgb(0.55, 0.27, 0.07),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Quests",
        maps: &["The Withered Willow"],
        font: rgb(0.0, 1.0, 1.0),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Ritual",
        maps: &["Caer Tarth", "Crux of Nothingness"],
        font: rgb(0.25, 0.0, 0.96),
        background: rgb(1.0, 1.0, 1.0),
    },
    MapGroup {
        name: "Breach",
        maps: &["Hive Colony", "Hive Fortress"],
        font: rgb(1.0, 0.2, 0.74),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Expedition",
        // Only the targets Atlas2 turns on by default.
        maps: &[
            "Moor of Fallen Skies",
            "Mournful Cliffside",
            "Obscure Island",
            "Secluded Temple",
            "The Chained Beast",
            "The Fallen Star",
            "Tomb of the Fallen Knight",
            "Ruins of Kingsmarch",
        ],
        font: rgb(0.36, 0.76, 0.93),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Abyss",
        maps: &["The Well of Souls"],
        font: rgb(0.15, 1.0, 0.0),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Temple",
        maps: &["Vaal Ruins"],
        font: rgb(0.87, 0.65, 0.0),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Citadels",
        maps: &[
            "The Copper Citadel",
            "The Iron Citadel",
            "The Stone Citadel",
            "The Matriarch Halls",
            "The Patriarch Halls",
        ],
        font: rgb(1.0, 0.0, 0.0),
        background: rgb(1.0, 1.0, 1.0),
    },
    MapGroup {
        name: "Towers",
        maps: &crate::atlas_routes::TOWERS,
        font: rgb(0.0, 0.0, 0.0),
        background: rgb(0.86, 0.0, 0.88),
    },
    MapGroup {
        name: "Good",
        maps: &[
            "Burial Bog",
            "Creek",
            "Rustbowl",
            "Sandspit",
            "Savannah",
            "Steaming Springs",
            "Steppe",
            "Wetlands",
            "Willow",
        ],
        font: rgb(1.0, 1.0, 0.0),
        background: ATLAS_BACKGROUND,
    },
    MapGroup {
        name: "Unique Maps",
        maps: &[
            "Ancient Gateway",
            "Castaway",
            "Eastern Gateway",
            "Freight",
            "Jado's Campsite",
            "Merchant's Campsite",
            "Moment of Zen",
            "Moor of Fallen Skies",
            "Precursor Tower",
            "Site of the Chosen",
            "The Ezomyte Megaliths",
            "The Fractured Lake",
            "The Silent Cave",
            "The Viridian Wildwood",
            "The Voyage",
            "Untainted Paradise",
            "Vaults of Kamasa",
            "Western Gateway",
        ],
        font: rgb(0.0, 0.0, 0.0),
        background: rgb(1.0, 0.56, 0.0),
    },
    MapGroup {
        name: "Special",
        maps: &["Ice Cave"],
        font: rgb(1.0, 1.0, 1.0),
        background: ATLAS_BACKGROUND,
    },
];

/// The Corrupted Nexus and Grand Mirror groups' font colours.
const CORRUPTED_NEXUS: Rgb = rgb(0.45, 0.0, 0.0);
const GRAND_MIRROR: Rgb = rgb(0.0, 170.0 / 255.0, 1.0);
/// Atlas2.VaalBeaconBorderColor.
const VAAL_BEACON_BORDER: Rgb = rgb(1.0, 0.84, 0.0);
/// The Ritual group's most colourful colour, its border.
const RITUAL_BORDER: Rgb = rgb(0.25, 0.0, 0.96);
/// json/biome.json border colours by biome id.
const BIOME_BORDERS: [Rgb; 13] = [
    rgb(0.028, 0.0, 0.911),
    rgb(0.842, 0.842, 0.842),
    rgb(0.0, 0.923, 0.335),
    rgb(0.0, 0.266, 0.097),
    rgb(0.028, 0.0, 0.911),
    rgb(0.799, 0.518, 0.0),
    rgb(1.0, 1.0, 1.0),
    rgb(1.0, 1.0, 1.0),
    rgb(0.870_588_24, 0.654_902, 0.0),
    rgb(1.0, 0.2, 0.741_176_5),
    rgb(0.0, 0.4, 0.8),
    rgb(0.2, 0.7, 0.6),
    rgb(1.0, 1.0, 1.0),
];
/// Atlas2Settings ScaleMultiplier, BaseWidth and BaseHeight,
/// AnchorNudge, BiomeBorderThickness and PathLineThickness.
pub const ATLAS_SCALE_MULTIPLIER: f32 = 0.5;
pub const ATLAS_BASE: (f32, f32) = (1920.0, 1080.0);
pub const ANCHOR_NUDGE: [f32; 2] = [-8.5, 45.0];
pub const BIOME_BORDER_THICKNESS: f32 = 2.5;
pub const PATH_LINE_THICKNESS: f32 = 6.0;
/// The green dot on a route's open entry map.
const ENTRY_DOT: Rgb = rgb(0.2, 1.0, 0.2);

/// A map on the atlas as Atlas2 draws it: the shown name, its centre on
/// the screen, and what the atlas reader found.
pub struct AtlasNode<'a> {
    pub name: &'a str,
    pub centre: [f32; 2],
    pub done: bool,
    pub biome: u8,
    pub content: &'a [String],
}

/// A route to draw: the target's shown name, its length in hops, the
/// screen centres of the maps along it from the open entry map, and
/// its colour.
pub struct AtlasRoute<'a> {
    pub name: &'a str,
    pub hops: usize,
    pub points: Vec<[f32; 2]>,
    pub color: Rgb,
}

fn has_content(content: &[String], text: &str) -> bool {
    let text = text.to_ascii_lowercase();
    content.iter().any(|c| c.to_ascii_lowercase().contains(&text))
}

/// MatchesCategory over the groups in order: the font and background
/// a map's label takes, the defaults when no group matches. Search has
/// no query here, so it never matches; Corrupted Nexus needs no
/// arbiter tag, which the reader does not read.
pub fn atlas_group(name: &str, content: &[String]) -> (Rgb, Rgb) {
    let named = |g: &MapGroup| g.maps.iter().any(|m| m.eq_ignore_ascii_case(name));
    if let Some(g) = MAP_GROUPS.first().filter(|g| named(g)) {
        return (g.font, g.background);
    }
    if has_content(content, "Corruption") && has_content(content, "Powerful Map Boss") {
        return (CORRUPTED_NEXUS, ATLAS_BACKGROUND);
    }
    if has_content(content, "Grand Mirror") {
        return (GRAND_MIRROR, ATLAS_BACKGROUND);
    }
    MAP_GROUPS
        .iter()
        .find(|g| named(g))
        .map_or((ATLAS_FONT, ATLAS_BACKGROUND), |g| (g.font, g.background))
}

/// The border colour: a Vaal Beacon, corruption, a ritual, else the
/// biome's.
pub fn atlas_border(biome: u8, content: &[String]) -> Option<Rgb> {
    if has_content(content, "Vaal Beacon") {
        Some(VAAL_BEACON_BORDER)
    } else if has_content(content, "Corruption") {
        Some(CORRUPTED_NEXUS)
    } else if has_content(content, "Ritual") {
        Some(RITUAL_BORDER)
    } else {
        BIOME_BORDERS.get(usize::from(biome)).copied()
    }
}

/// MostColorfulColor: the colour with more chroma, the brighter one on
/// a tie; a route's colour from its group.
pub fn most_colorful(font: Rgb, background: Rgb) -> Rgb {
    let parts = |c: Rgb| {
        [(c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF].map(|v| v as f32 / 255.0)
    };
    let chroma = |c: Rgb| {
        let p = parts(c);
        p.iter().copied().fold(0.0, f32::max) - p.iter().copied().fold(1.0, f32::min)
    };
    let luminance = |c: Rgb| {
        let p = parts(c);
        0.2126 * p[0] + 0.7152 * p[1] + 0.0722 * p[2]
    };
    let (f, b) = (chroma(font), chroma(background));
    if (f - b).abs() > 0.001 {
        if b > f { background } else { font }
    } else if luminance(background) > luminance(font) {
        background
    } else {
        font
    }
}

/// Atlas2 ComputeDisplayScale with ScaleMultiplier, clamped.
pub fn atlas_scale(window: (f32, f32)) -> f32 {
    let display = (window.0 / ATLAS_BASE.0).min(window.1 / ATLAS_BASE.1);
    (ATLAS_SCALE_MULTIPLIER * display).clamp(0.5, 4.0)
}

/// The atlas after Atlas2.DrawUI with its defaults: each route's line
/// through its maps with a dot on each and a green dot on its entry,
/// then each map not done yet (HideCompletedMaps) as its name on its
/// group's background inside its border colour, with one content line
/// each under it (ShowContent), then each route's "name (hops)" at the
/// middle of its first step, stacked when routes share it. Labels off
/// the screen are left out. Badge squares and content icons are not
/// drawn.
pub fn atlas(nodes: &[AtlasNode], routes: &[AtlasRoute], window: (f32, f32)) -> Vec<Shape> {
    let ui = atlas_scale(window);
    let mut out = Vec::new();
    let on_screen = |[x, y]: [f32; 2]| {
        (-64.0..=window.0 + 64.0).contains(&x) && (-64.0..=window.1 + 64.0).contains(&y)
    };
    let thickness = (ui * PATH_LINE_THICKNESS).max(1.0);
    for r in routes {
        for pair in r.points.windows(2) {
            if on_screen(pair[0]) || on_screen(pair[1]) {
                out.push(Shape::Line {
                    from: pair[0],
                    to: pair[1],
                    color: r.color,
                    width: thickness.round() as i32,
                });
            }
        }
        for p in r.points.iter().filter(|p| on_screen(**p)) {
            out.push(dot(*p, thickness * 0.9, r.color));
        }
        if let Some(entry) = r.points.first() {
            out.push(dot(*entry, (thickness * 1.3).max(3.0), ENTRY_DOT));
        }
    }
    let text_size = |t: &str| [t.len() as f32 * CHAR_WIDTH, FONT];
    for n in nodes.iter().filter(|n| !n.done && !n.name.is_empty()) {
        let size = text_size(n.name);
        let at = [
            n.centre[0] - size[0] * 0.5 + ANCHOR_NUDGE[0],
            n.centre[1] - size[1] * 0.5 + ANCHOR_NUDGE[1],
        ];
        let pad = [5.0 * ui, 2.0 * ui];
        let bg = [at[0] - pad[0], at[1] - pad[1]];
        let bg_size = [size[0] + pad[0] * 2.0, size[1] + pad[1] * 2.0];
        if !on_screen(bg) && !on_screen([bg[0] + bg_size[0], bg[1] + bg_size[1]]) {
            continue;
        }
        let (font, background) = atlas_group(n.name, n.content);
        if let Some(border) = atlas_border(n.biome, n.content) {
            // AddRect's line is centred half its width outside the
            // background, so it shows a full width around it.
            let th = (ui * BIOME_BORDER_THICKNESS).max(1.0);
            out.push(Shape::Rect {
                at: [bg[0] - th, bg[1] - th],
                size: [bg_size[0] + th * 2.0, bg_size[1] + th * 2.0],
                color: border,
                filled: true,
            });
        }
        out.push(Shape::Rect {
            at: bg,
            size: bg_size,
            color: background,
            filled: true,
        });
        out.push(Shape::Text {
            at,
            text: n.name.to_string(),
            color: font,
        });
        let centre_x = at[0] + size[0] * 0.5;
        let mut row_y = at[1] + size[1] + 4.0 * ui;
        for c in n.content {
            let s = text_size(c);
            out.push(Shape::Text {
                at: [centre_x - s[0] * 0.5, row_y],
                text: c.clone(),
                color: font,
            });
            row_y += s[1] + 4.0 * ui;
        }
    }
    // Route names, grouped by their first step.
    let mut steps: Vec<([[f32; 2]; 2], Vec<(String, Rgb)>)> = Vec::new();
    for r in routes.iter().filter(|r| r.points.len() >= 2) {
        let key = [r.points[0], r.points[1]];
        let text = (format!("{} ({})", r.name, r.hops), r.color);
        match steps.iter_mut().find(|(k, _)| *k == key) {
            Some((_, list)) => list.push(text),
            None => steps.push((key, vec![text])),
        }
    }
    for ([a, b], list) in steps {
        let mid = [(a[0] + b[0]) * 0.5, (a[1] + b[1]) * 0.5];
        let line = FONT + 4.0 * ui;
        let first = mid[1] - (list.len() - 1) as f32 * line * 0.5;
        for (row, (text, color)) in list.into_iter().enumerate() {
            let s = text_size(&text);
            let at = [mid[0] - s[0] * 0.5, first + row as f32 * line - s[1] * 0.5];
            let pad = [4.0 * ui, ui];
            out.push(Shape::Rect {
                at: [at[0] - pad[0], at[1] - pad[1]],
                size: [s[0] + pad[0] * 2.0, s[1] + pad[1] * 2.0],
                color: 0x000000,
                filled: true,
            });
            out.push(Shape::Text { at, text, color });
        }
    }
    out
}

/// A filled dot: a ring as wide as its radius, around half the radius.
fn dot(centre: [f32; 2], radius: f32, color: Rgb) -> Shape {
    Shape::Circle {
        centre,
        radius: radius * 0.5,
        color,
        width: radius.round().max(1.0) as i32,
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

    #[test]
    fn atlas_colours_follow_atlas2() {
        assert_eq!(rgb(0.86, 0.0, 0.88), 0xDB00E0);
        // Towers: the magenta background is more colourful than black.
        assert_eq!(atlas_group("mesa", &[]), (0x000000, 0xDB00E0));
        assert_eq!(most_colorful(0x000000, 0xDB00E0), 0xDB00E0);
        // Lineage comes before Corrupted Nexus, which comes before Good.
        let nexus = ["Corruption".to_string(), "Powerful Map Boss".to_string()];
        assert_eq!(atlas_group("Sealed Vault", &nexus).1, rgb(0.0, 181.0 / 255.0, 33.0 / 255.0));
        assert_eq!(atlas_group("Creek", &nexus).0, CORRUPTED_NEXUS);
        assert_eq!(atlas_group("Creek", &[]).0, 0xFFFF00);
        assert_eq!(atlas_group("Nowhere", &[]), (ATLAS_FONT, ATLAS_BACKGROUND));
        // Border: beacon over corruption over ritual over biome.
        let both = ["Vaal Beacon".to_string(), "Corruption".to_string()];
        assert_eq!(atlas_border(2, &both), Some(VAAL_BEACON_BORDER));
        assert_eq!(atlas_border(2, &["Ritual Altars".to_string()]), Some(RITUAL_BORDER));
        assert_eq!(atlas_border(2, &[]), Some(rgb(0.0, 0.923, 0.335)));
        assert_eq!(atlas_border(99, &[]), None);
        assert_eq!(atlas_scale((1920.0, 1080.0)), 0.5);
        assert_eq!(atlas_scale((3840.0, 2160.0)), 1.0);
    }

    #[test]
    fn the_atlas_labels_maps_and_draws_routes() {
        let content = vec!["Breach".to_string()];
        let nodes = [
            AtlasNode {
                name: "Mesa",
                centre: [500.0, 300.0],
                done: false,
                biome: 1,
                content: &content,
            },
            AtlasNode {
                name: "Creek",
                centre: [600.0, 300.0],
                done: true,
                biome: 1,
                content: &[],
            },
        ];
        let route = AtlasRoute {
            name: "Mesa",
            hops: 1,
            points: vec![[400.0, 300.0], [500.0, 300.0]],
            color: 0xDB00E0,
        };
        let shapes = atlas(&nodes, &[route], (1920.0, 1080.0));
        // Line, two path dots, entry dot; border, background, name,
        // content line; route name box and text. Creek is done: hidden.
        assert_eq!(shapes.len(), 10, "{shapes:#?}");
        assert!(matches!(shapes[0], Shape::Line { width: 3, color: 0xDB00E0, .. }));
        let Shape::Circle { color, .. } = &shapes[3] else { panic!() };
        assert_eq!(*color, ENTRY_DOT);
        // The name sits at centre - size / 2 + AnchorNudge: 4 chars of 8.
        let Shape::Text { at, text, color } = &shapes[6] else { panic!() };
        assert_eq!((text.as_str(), *color), ("Mesa", 0x000000));
        assert_eq!(*at, [500.0 - 16.0 - 8.5, 300.0 - 8.0 + 45.0]);
        let Shape::Rect { at: bg, color, .. } = &shapes[5] else { panic!() };
        assert_eq!((*bg, *color), ([at[0] - 2.5, at[1] - 1.0], 0xDB00E0));
        let Shape::Text { text, at: line, .. } = &shapes[7] else { panic!() };
        assert_eq!(text, "Breach");
        assert_eq!(line[1], at[1] + FONT + 2.0);
        let Shape::Text { text, at: label, .. } = &shapes[9] else { panic!() };
        assert_eq!(text, "Mesa (1)");
        assert_eq!(*label, [450.0 - 32.0, 300.0 - 8.0]);
        // Off the screen: no label.
        let far = AtlasNode { centre: [5000.0, 300.0], ..nodes.into_iter().next().unwrap() };
        assert!(atlas(&[far], &[], (1920.0, 1080.0)).is_empty());
    }
}

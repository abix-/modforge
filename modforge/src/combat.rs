//! Combat decisions, engine-agnostic (topside design.md "How a hit
//! works"). The consumer finds hits (ray and shape casts in its
//! physics world) and moves bodies; this module decides everything
//! else: what a hit does, when a shooter may fire, how pellets add
//! up. Player and NPCs share every path.
//!
//! Prior art, read from source: Quake 3's `G_Damage` (one function
//! for every hit: armor, knockback, health, die or pain), Doom 3's
//! damage defs (damage as data a weapon names), Half-Life's
//! multi-damage (pellets summed per target), Quake 3's `PM_Weapon`
//! (fire rate as a timer on the shooter), Rust's falloff by
//! distance (Facepunch devblog 123).

/// What kind of hurt a hit is. Resistances multiply per type.
#[derive(Clone, Copy, PartialEq, Eq, Debug, Hash)]
pub enum DamageType {
    Blunt,
    Slash,
    Pierce,
    Bullet,
    Fire,
    Blast,
}

/// How damage falls off with distance: full up to `full_range`,
/// then straight down to `far_fraction` at `far_range` and beyond.
/// Rust: "rifles have always had a less severe damage falloff over
/// distance than pistols".
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Falloff {
    pub full_range: f32,
    pub far_range: f32,
    pub far_fraction: f32,
}

impl Falloff {
    pub const NONE: Falloff = Falloff {
        full_range: f32::INFINITY,
        far_range: f32::INFINITY,
        far_fraction: 1.0,
    };

    pub fn at(&self, distance: f32) -> f32 {
        if distance <= self.full_range {
            1.0
        } else if distance >= self.far_range {
            self.far_fraction
        } else {
            let t = (distance - self.full_range) / (self.far_range - self.full_range);
            1.0 + (self.far_fraction - 1.0) * t
        }
    }
}

/// One kind of hurt as data (Doom 3's damage def): what a weapon,
/// projectile, or hazard names when it lands. `name` is the id.
#[derive(Clone, Debug, PartialEq)]
pub struct DamageDef {
    pub name: String,
    pub amount: f32,
    pub kind: DamageType,
    /// Velocity added to the target along the hit direction, scaled
    /// by the target's mass (Quake 3: damage over a mass of 200,
    /// capped at 200).
    pub knockback: f32,
    /// Armor is skipped (Doom 3 `noArmor`).
    pub ignores_armor: bool,
    /// Damage to yourself is scaled by this (Doom 3
    /// `selfDamageScale`; Quake 3 halves it so rocket jumping works).
    pub self_scale: f32,
    pub falloff: Falloff,
}

/// The checked-in damage defs. Consumers register content at startup
/// and weapons look defs up by name.
#[derive(Default)]
pub struct DamageRegistry {
    defs: Vec<DamageDef>,
}

impl DamageRegistry {
    pub fn register(&mut self, def: DamageDef) -> Result<(), String> {
        if self.defs.iter().any(|d| d.name == def.name) {
            return Err(format!("damage def '{}' registered twice", def.name));
        }
        self.defs.push(def);
        Ok(())
    }

    pub fn def(&self, name: &str) -> Option<&DamageDef> {
        self.defs.iter().find(|d| d.name == name)
    }

    pub fn len(&self) -> usize {
        self.defs.len()
    }

    pub fn is_empty(&self) -> bool {
        self.defs.is_empty()
    }
}

/// Health for any combatant: player, NPCs, and building parts.
#[derive(Clone, Debug, PartialEq)]
pub struct Health {
    pub current: f32,
    pub max: f32,
}

impl Health {
    pub fn new(max: f32) -> Self {
        Self { current: max, max }
    }

    pub fn is_dead(&self) -> bool {
        self.current <= 0.0
    }

    pub fn fraction(&self) -> f32 {
        if self.max <= 0.0 {
            return 0.0;
        }
        (self.current / self.max).clamp(0.0, 1.0)
    }
}

/// What stands between a hit and a target's health. `armor` is the
/// pool Quake 3 style (absorbs a share until spent); `resistances`
/// multiply by damage type (Valheim). Worn gear per body area feeds
/// this once actors have parts.
#[derive(Clone, Debug, PartialEq, Default)]
pub struct Protection {
    pub armor: f32,
    pub resistances: Vec<(DamageType, f32)>,
}

/// Share of damage armor absorbs while it lasts (Quake 3
/// `ARMOR_PROTECTION`).
pub const ARMOR_PROTECTION: f32 = 0.66;
/// Quake 3's player mass for knockback.
pub const KNOCKBACK_MASS: f32 = 200.0;
pub const KNOCKBACK_CAP: f32 = 200.0;

impl Protection {
    pub fn resistance(&self, kind: DamageType) -> f32 {
        self.resistances
            .iter()
            .find(|(k, _)| *k == kind)
            .map(|(_, m)| *m)
            .unwrap_or(1.0)
    }
}

/// One hit about to be resolved: who, what, where.
#[derive(Clone, Debug)]
pub struct Hit<'a> {
    pub def: &'a DamageDef,
    /// True when the attacker is the target (rocket jump, own grenade).
    pub self_inflicted: bool,
    /// Distance from the shooter to the point of impact, for falloff.
    pub distance: f32,
    /// Multiplier for where it landed (body part), 1.0 for none.
    pub location_scale: f32,
}

/// Where on a body a hit landed, by height up the body (Rust: head
/// shots hurt double, legs less). Each area is guarded by the gear
/// worn in its equipment slot.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BodyArea {
    Head,
    Chest,
    Legs,
}

impl BodyArea {
    /// From the hit's height as a fraction of body height, feet 0 to
    /// top 1.
    pub fn from_height(fraction: f32) -> BodyArea {
        if fraction >= 0.85 {
            BodyArea::Head
        } else if fraction >= 0.45 {
            BodyArea::Chest
        } else {
            BodyArea::Legs
        }
    }

    /// Damage multiplier for the area (Rust's head 2x, legs 0.75x).
    pub fn scale(self) -> f32 {
        match self {
            BodyArea::Head => 2.0,
            BodyArea::Chest => 1.0,
            BodyArea::Legs => 0.75,
        }
    }

    /// The equipment slot whose worn item guards this area.
    pub fn slot(self) -> crate::item::EquipSlot {
        match self {
            BodyArea::Head => crate::item::EquipSlot::Head,
            BodyArea::Chest => crate::item::EquipSlot::Chest,
            BodyArea::Legs => crate::item::EquipSlot::Legs,
        }
    }
}

impl Protection {
    /// This actor's protection for a hit on `area`: the base plus the
    /// armor of whatever is worn in the area's slot. `armor_of` looks
    /// an item name up in the consumer's registry; gear worn in the
    /// wrong slot guards nothing.
    pub fn for_area(
        &self,
        area: BodyArea,
        worn: &crate::item::Equipment,
        armor_of: impl Fn(&str) -> Option<crate::item::Armor>,
    ) -> Protection {
        let worn_armor = worn
            .get(area.slot())
            .and_then(|stack| armor_of(&stack.item))
            .filter(|armor| armor.slot == area.slot())
            .map(|armor| armor.amount)
            .unwrap_or(0.0);
        Protection {
            armor: self.armor + worn_armor,
            resistances: self.resistances.clone(),
        }
    }

    /// This actor's protection with no body parts (topside combat.md
    /// "How deadly"): the base plus the armor of every piece worn in
    /// its own slot, added into one total that every hit goes through.
    /// Gear worn in the wrong slot guards nothing.
    pub fn worn(
        &self,
        worn: &crate::item::Equipment,
        armor_of: impl Fn(&str) -> Option<crate::item::Armor>,
    ) -> Protection {
        let worn_armor: f32 = crate::item::EquipSlot::ALL
            .iter()
            .filter_map(|&slot| {
                worn.get(slot)
                    .and_then(|stack| armor_of(&stack.item))
                    .filter(|armor| armor.slot == slot)
                    .map(|armor| armor.amount)
            })
            .sum();
        Protection {
            armor: self.armor + worn_armor,
            resistances: self.resistances.clone(),
        }
    }
}

/// The directions of one shot's pellets: the aim, each pellet pushed
/// off it by up to `spread_degrees` in a deterministic pattern from
/// `seed` (the tick), so a test and a replay land the same shot. One
/// pellet with no spread is the aim itself.
pub fn pellet_directions(
    forward: glam::Vec3,
    spread_degrees: f32,
    pellets: u32,
    seed: u64,
) -> Vec<glam::Vec3> {
    let forward = forward.normalize();
    if pellets <= 1 || spread_degrees <= 0.0 {
        return vec![forward; pellets.max(1) as usize];
    }
    let up = if forward.y.abs() < 0.99 {
        glam::Vec3::Y
    } else {
        glam::Vec3::X
    };
    let right = forward.cross(up).normalize();
    let up = right.cross(forward);
    let spread = spread_degrees.to_radians();
    (0..pellets)
        .map(|i| {
            let (a, r) = pellet_roll(seed, i);
            let angle = a * std::f32::consts::TAU;
            let off = r.sqrt() * spread;
            (forward + (right * angle.cos() + up * angle.sin()) * off.tan()).normalize()
        })
        .collect()
}

/// Two cheap hashes per pellet, each 0 to 1: the one seeded pattern
/// both spreads draw from.
fn pellet_roll(seed: u64, i: u32) -> (f32, f32) {
    let h = seed
        .wrapping_mul(0x9E37_79B9_7F4A_7C15)
        .wrapping_add(u64::from(i).wrapping_mul(0xBF58_476D_1CE4_E5B9));
    let a = (h >> 11) as f32 / (1u64 << 53) as f32;
    let r = (h.rotate_left(29) >> 11) as f32 / (1u64 << 53) as f32;
    (a, r)
}

/// The directions of one shot's pellets on the ground, seen from above
/// (topside combat.md "Guns"): the aim turned by up to
/// `spread_degrees` either way, from the same seeded pattern as
/// `pellet_directions`. One pellet with no spread is the aim itself.
pub fn pellet_directions_2d(forward: glam::Vec2, spread_degrees: f32, pellets: u32, seed: u64) -> Vec<glam::Vec2> {
    let forward = forward.normalize_or_zero();
    if pellets <= 1 || spread_degrees <= 0.0 {
        return vec![forward; pellets.max(1) as usize];
    }
    let spread = spread_degrees.to_radians();
    (0..pellets)
        .map(|i| {
            let (a, _) = pellet_roll(seed, i);
            glam::Vec2::from_angle((a * 2.0 - 1.0) * spread).rotate(forward)
        })
        .collect()
}

/// How fast a bullet flies, in metres per second: slow enough to see
/// from above (topside combat.md "Guns": every shot a visible bullet).
/// Tuning.
pub const BULLET_SPEED: f32 = 60.0;

/// What one resolved hit did.
#[derive(Clone, Debug, PartialEq)]
pub struct HitResult {
    /// Taken off health.
    pub damage_dealt: f32,
    /// Taken off armor.
    pub armor_absorbed: f32,
    /// Speed to add to the target along the hit direction.
    pub knockback: f32,
    pub killed: bool,
}

/// THE damage function (Quake 3's `G_Damage`). Every hit in the game
/// ends here: the consumer detected it, this decides it. Order, as
/// Quake 3 does it: knockback is figured from the raw damage even
/// if armor takes it all; self damage is scaled; damage never drops
/// below 1; armor absorbs its share; health takes the rest; the
/// caller reads `killed` to run die or pain.
pub fn resolve_hit(hit: &Hit<'_>, protection: &mut Protection, target: &mut Health) -> HitResult {
    let def = hit.def;
    let mut damage = def.amount * def.falloff.at(hit.distance) * hit.location_scale;
    damage *= protection.resistance(def.kind);

    let knockback = (def.knockback * damage.min(KNOCKBACK_CAP)) / KNOCKBACK_MASS;

    if hit.self_inflicted {
        damage *= def.self_scale;
    }
    let damage = damage.max(1.0);

    let armor_absorbed = if def.ignores_armor || protection.armor <= 0.0 {
        0.0
    } else {
        let save = (damage * ARMOR_PROTECTION).ceil().min(protection.armor);
        protection.armor -= save;
        save
    };
    let take = damage - armor_absorbed;
    target.current = (target.current - take).max(0.0);
    HitResult {
        damage_dealt: take,
        armor_absorbed,
        knockback,
        killed: target.is_dead(),
    }
}

/// Pellets summed per target before one resolve each (Half-Life's
/// multi-damage): a shotgun blast is one hit on each thing it
/// touched, not ten pains.
#[derive(Debug)]
pub struct MultiDamage<T: PartialEq> {
    hits: Vec<(T, f32, u32)>,
}

impl<T: PartialEq> Default for MultiDamage<T> {
    fn default() -> Self {
        Self { hits: Vec::new() }
    }
}

impl<T: PartialEq + Clone> MultiDamage<T> {
    /// One pellet landed on `target` at `distance`.
    pub fn add(&mut self, target: T, distance: f32) {
        match self.hits.iter_mut().find(|(t, _, _)| *t == target) {
            Some((_, d, n)) => {
                *d += distance;
                *n += 1;
            }
            None => self.hits.push((target, distance, 1)),
        }
    }

    /// Each target hit, with how many pellets and their mean distance.
    pub fn drain(&mut self) -> Vec<(T, u32, f32)> {
        self.hits
            .drain(..)
            .map(|(t, d, n)| (t, n, d / n as f32))
            .collect()
    }
}

/// Gothic's four melee moves (design.md "How a hit works" rule 4):
/// the attack key plus whatever move direction is held.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Default)]
pub enum Swing {
    /// Forward, or no direction: the overhead that steps in and
    /// chains into a combo on the beat.
    #[default]
    Overhead,
    /// A horizontal swing from the left across the body.
    Left,
    /// A horizontal swing from the right across the body.
    Right,
    /// Back: a block, no hit.
    Block,
}

impl Swing {
    /// From the move input held when the attack lands: x is right,
    /// y is forward.
    pub fn from_move(x: f32, y: f32) -> Swing {
        if y < 0.0 {
            Swing::Block
        } else if x < 0.0 {
            Swing::Left
        } else if x > 0.0 {
            Swing::Right
        } else {
            Swing::Overhead
        }
    }

    /// From a move along the ground seen from above (the ground's own
    /// axes, not the person's), read relative to the way the person
    /// faces (topside combat.md "Melee: the four moves"): forward is
    /// along `facing`, right a quarter turn clockwise from it. A part
    /// under `DEAD_ZONE` counts as none, so walking mostly forward is
    /// still the overhead.
    pub fn from_ground_move(step: glam::Vec2, facing: glam::Vec2) -> Swing {
        let facing = facing.normalize_or_zero();
        let right = glam::Vec2::new(facing.y, -facing.x);
        let step = step.normalize_or_zero();
        let part = |v: f32| if v.abs() < DEAD_ZONE { 0.0 } else { v };
        Swing::from_move(part(step.dot(right)), part(step.dot(facing)))
    }

    /// Whether a target at `offset` from the swinger is inside this
    /// swing's shape within `reach` (topside combat.md: the hit is the
    /// swing's shape in front of the person). The overhead hits a strip
    /// `STRIP_HALF_WIDTH` either side of straight ahead; a side swing
    /// sweeps the whole front half; a block hits nothing.
    pub fn covers(self, offset: glam::Vec2, facing: glam::Vec2, reach: f32) -> bool {
        let facing = facing.normalize_or_zero();
        let ahead = offset.dot(facing);
        if offset.length() > reach || ahead <= 0.0 {
            return false;
        }
        match self {
            Swing::Overhead => offset.perp_dot(facing).abs() <= STRIP_HALF_WIDTH,
            Swing::Left | Swing::Right => true,
            Swing::Block => false,
        }
    }
}

/// Half the width of the overhead's strip, in metres.
pub const STRIP_HALF_WIDTH: f32 = 0.5;
/// A move part smaller than this reads as no direction.
pub const DEAD_ZONE: f32 = 0.3;
/// How long a block holds, in seconds (topside combat.md: about a
/// second).
pub const BLOCK_TIME: f32 = 1.0;

/// Fire rate as a timer on the shooter (Quake 3's `PM_Weapon`): the
/// weapon is ready when `ready_in` reaches zero; firing adds the
/// weapon's delay; firing empty adds a penalty instead. `delay` and
/// `swing` are the last shot's, so a consumer can draw the swing as
/// "how far through the delay" without a second timer.
#[derive(Clone, Debug, PartialEq)]
pub struct FireTimer {
    pub ready_in: f32,
    pub delay: f32,
    pub swing: Swing,
    /// The trigger has been let go since the last swing, so the
    /// next press can be a chain on the beat (Gothic: a press on the
    /// beat, never a held button).
    pub released: bool,
    /// The last pull was a melee move: until it ends the person is
    /// committed to it (topside combat.md "Commitment").
    pub melee: bool,
}

impl Default for FireTimer {
    fn default() -> Self {
        Self {
            ready_in: 0.0,
            delay: 0.0,
            swing: Swing::Overhead,
            released: true,
            melee: false,
        }
    }
}

/// Quake 3: an empty click costs half a second.
pub const EMPTY_DELAY: f32 = 0.5;
/// The beat: a chained swing pressed in the last third of the delay
/// goes at once.
pub const BEAT: f32 = 1.0 / 3.0;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Trigger {
    /// Not ready yet, nothing happens.
    Waiting,
    /// Fire now; the delay has been added.
    Fire,
    /// Ready but no ammo; the penalty has been added.
    Empty,
    /// A block: no hit, the delay has been added.
    Block,
}

impl FireTimer {
    pub fn tick(&mut self, dt: f32) {
        self.ready_in = (self.ready_in - dt).max(0.0);
    }

    /// No trigger this step: the next press may chain.
    pub fn release(&mut self) {
        self.released = true;
    }

    /// The trigger is held: decide whether this step fires.
    /// `has_ammo` is true for melee and loaded guns.
    pub fn pull(&mut self, delay: f32, has_ammo: bool) -> Trigger {
        if self.ready_in > 0.0 {
            return Trigger::Waiting;
        }
        self.released = false;
        self.melee = false;
        if !has_ammo {
            self.ready_in = EMPTY_DELAY;
            self.delay = EMPTY_DELAY;
            return Trigger::Empty;
        }
        self.ready_in = delay;
        self.delay = delay;
        self.swing = Swing::Overhead;
        Trigger::Fire
    }

    /// The attack key with a direction: one of the four moves. Ready
    /// fires; a fresh press on the beat (the last third of the delay)
    /// chains at once when this person `can_chain`; otherwise wait. A
    /// block holds for `BLOCK_TIME` whatever the weapon.
    pub fn pull_melee(&mut self, delay: f32, swing: Swing, can_chain: bool) -> Trigger {
        let on_beat = can_chain && self.released && self.ready_in <= self.delay * BEAT;
        if self.ready_in > 0.0 && !on_beat {
            return Trigger::Waiting;
        }
        let delay = if swing == Swing::Block { BLOCK_TIME } else { delay };
        self.released = false;
        self.melee = true;
        self.ready_in = delay;
        self.delay = delay;
        self.swing = swing;
        if swing == Swing::Block {
            Trigger::Block
        } else {
            Trigger::Fire
        }
    }

    /// Mid swing or mid block: the person is committed and can do
    /// nothing else until it ends (topside combat.md "Commitment").
    pub fn committed(&self) -> bool {
        self.melee && self.ready_in > 0.0
    }

    /// Holding a block right now: a swing that lands does nothing.
    pub fn blocking(&self) -> bool {
        self.melee && self.swing == Swing::Block && self.ready_in > 0.0
    }
}

/// How long a roll lasts, in seconds (topside combat.md "The roll",
/// Enter the Gungeon's 0.7 s).
pub const ROLL_TIME: f32 = 0.7;
/// How much faster than walking a roll carries a person. Tuning.
pub const ROLL_SPEED_MULT: f32 = 1.4;

/// The dodge roll (topside combat.md "The roll"): `ROLL_TIME` long,
/// safe from all damage for the first half, the direction locked once
/// started.
#[derive(Clone, Copy, Debug, PartialEq, Default)]
pub struct RollTimer {
    pub left: f32,
    pub direction: glam::Vec2,
}

impl RollTimer {
    /// Start a roll along `direction` unless one is under way. Returns
    /// whether it started.
    pub fn start(&mut self, direction: glam::Vec2) -> bool {
        let direction = direction.normalize_or_zero();
        if self.rolling() || direction == glam::Vec2::ZERO {
            return false;
        }
        self.left = ROLL_TIME;
        self.direction = direction;
        true
    }

    pub fn tick(&mut self, dt: f32) {
        self.left = (self.left - dt).max(0.0);
    }

    pub fn rolling(&self) -> bool {
        self.left > 0.0
    }

    /// The first half of a roll: nothing can hurt the roller.
    pub fn safe(&self) -> bool {
        self.left > ROLL_TIME / 2.0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_roll_is_safe_for_its_first_half_and_its_direction_holds() {
        let mut r = RollTimer::default();
        assert!(!r.rolling());
        assert!(r.start(glam::Vec2::new(0.0, 2.0)));
        assert_eq!(r.direction, glam::Vec2::Y);
        assert!(r.safe());
        assert!(!r.start(glam::Vec2::X), "no new roll mid roll");
        assert_eq!(r.direction, glam::Vec2::Y, "the direction held");
        r.tick(0.3);
        assert!(r.safe(), "safe at 0.3 s");
        r.tick(0.1);
        assert!(r.rolling() && !r.safe(), "open in the second half");
        r.tick(0.4);
        assert!(!r.rolling(), "over by 0.7 s");
    }

    fn pipe() -> DamageDef {
        DamageDef {
            name: "pipe swing".to_string(),
            amount: 20.0,
            kind: DamageType::Blunt,
            knockback: 1.0,
            ignores_armor: false,
            self_scale: 0.5,
            falloff: Falloff::NONE,
        }
    }

    #[test]
    fn body_areas_by_height_with_rust_scales() {
        assert_eq!(BodyArea::from_height(0.95), BodyArea::Head);
        assert_eq!(BodyArea::from_height(0.6), BodyArea::Chest);
        assert_eq!(BodyArea::from_height(0.2), BodyArea::Legs);
        assert_eq!(BodyArea::Head.scale(), 2.0);
        assert_eq!(BodyArea::Legs.scale(), 0.75);
        assert_eq!(BodyArea::Head.slot(), crate::item::EquipSlot::Head);
    }

    #[test]
    fn worn_gear_guards_only_its_own_area() {
        let mut worn = crate::item::Equipment::default();
        worn.set(
            crate::item::EquipSlot::Chest,
            Some(crate::item::ItemStack {
                item: "vest".to_string(),
                count: 1,
                quality: None,
                note: None,
            }),
        );
        let armor_of = |name: &str| {
            (name == "vest").then_some(crate::item::Armor {
                slot: crate::item::EquipSlot::Chest,
                amount: 30.0,
            })
        };
        let base = Protection::default();
        assert_eq!(base.for_area(BodyArea::Chest, &worn, armor_of).armor, 30.0);
        assert_eq!(base.for_area(BodyArea::Head, &worn, armor_of).armor, 0.0);
        // The vest stuffed in the head slot guards nothing.
        let mut wrong = crate::item::Equipment::default();
        wrong.set(
            crate::item::EquipSlot::Head,
            worn.get(crate::item::EquipSlot::Chest).cloned(),
        );
        assert_eq!(base.for_area(BodyArea::Head, &wrong, armor_of).armor, 0.0);
    }

    #[test]
    fn flat_pellets_spread_inside_the_angle_and_repeat_by_seed() {
        let aim = glam::Vec2::X;
        assert_eq!(pellet_directions_2d(aim, 0.0, 1, 7), vec![aim]);
        let a = pellet_directions_2d(aim, 6.0, 6, 7);
        assert_eq!(a, pellet_directions_2d(aim, 6.0, 6, 7), "same seed, same pattern");
        assert_ne!(a, pellet_directions_2d(aim, 6.0, 6, 8), "another seed differs");
        for d in &a {
            assert!((d.length() - 1.0).abs() < 1e-4);
            assert!(d.angle_to(aim).abs() <= 6f32.to_radians() + 1e-4, "{d} strays");
        }
    }

    #[test]
    fn a_ground_move_reads_relative_to_facing() {
        use glam::Vec2;
        let up = Vec2::Y;
        // Facing up the screen: W is forward, A is left, D is right,
        // S is back.
        assert_eq!(Swing::from_ground_move(Vec2::Y, up), Swing::Overhead);
        assert_eq!(Swing::from_ground_move(Vec2::NEG_X, up), Swing::Left);
        assert_eq!(Swing::from_ground_move(Vec2::X, up), Swing::Right);
        assert_eq!(Swing::from_ground_move(Vec2::NEG_Y, up), Swing::Block);
        // Facing right: D is forward and W is to the left.
        assert_eq!(Swing::from_ground_move(Vec2::X, Vec2::X), Swing::Overhead);
        assert_eq!(Swing::from_ground_move(Vec2::Y, Vec2::X), Swing::Left);
        // No move is the overhead.
        assert_eq!(Swing::from_ground_move(Vec2::ZERO, up), Swing::Overhead);
    }

    #[test]
    fn the_overhead_hits_a_strip_ahead_and_a_side_swing_the_front() {
        use glam::Vec2;
        let facing = Vec2::Y;
        let ahead = Vec2::new(0.0, 1.5);
        let beside = Vec2::new(1.2, 0.6);
        let behind = Vec2::new(0.0, -1.0);
        assert!(Swing::Overhead.covers(ahead, facing, 1.8));
        assert!(!Swing::Overhead.covers(beside, facing, 1.8), "the strip misses one beside");
        assert!(Swing::Left.covers(beside, facing, 1.8));
        assert!(Swing::Right.covers(ahead, facing, 1.8));
        assert!(!Swing::Right.covers(behind, facing, 1.8), "never behind");
        assert!(!Swing::Overhead.covers(Vec2::new(0.0, 3.0), facing, 1.8), "out of reach");
        assert!(!Swing::Block.covers(ahead, facing, 1.8));
    }

    #[test]
    fn a_swing_commits_and_a_block_holds_about_a_second() {
        let mut t = FireTimer::default();
        assert!(!t.committed());
        assert_eq!(t.pull_melee(0.6, Swing::Block, true), Trigger::Block);
        assert!(t.blocking() && t.committed());
        t.tick(0.9);
        assert!(t.blocking(), "still holding at 0.9 s");
        t.tick(0.2);
        assert!(!t.blocking() && !t.committed(), "done after a second");
        // A gun shot is not a commitment.
        assert_eq!(t.pull(0.6, true), Trigger::Fire);
        assert!(!t.committed());
    }

    #[test]
    fn every_worn_piece_adds_into_one_total() {
        let stack = |name: &str| crate::item::ItemStack {
            item: name.to_string(),
            count: 1,
            quality: None,
            note: None,
        };
        let mut worn = crate::item::Equipment::default();
        worn.set(crate::item::EquipSlot::Chest, Some(stack("vest")));
        worn.set(crate::item::EquipSlot::Head, Some(stack("helmet")));
        let armor_of = |name: &str| match name {
            "vest" => Some(crate::item::Armor {
                slot: crate::item::EquipSlot::Chest,
                amount: 30.0,
            }),
            "helmet" => Some(crate::item::Armor {
                slot: crate::item::EquipSlot::Head,
                amount: 10.0,
            }),
            _ => None,
        };
        let base = Protection {
            armor: 5.0,
            resistances: vec![],
        };
        assert_eq!(base.worn(&worn, armor_of).armor, 45.0);
        // A vest in the head slot guards nothing.
        let mut wrong = crate::item::Equipment::default();
        wrong.set(crate::item::EquipSlot::Head, Some(stack("vest")));
        assert_eq!(base.worn(&wrong, armor_of).armor, 5.0);
    }

    #[test]
    fn pellets_spread_inside_the_cone_and_repeat_by_seed() {
        let aim = glam::Vec3::NEG_Z;
        let one = pellet_directions(aim, 0.0, 1, 7);
        assert_eq!(one, vec![aim]);
        let a = pellet_directions(aim, 5.0, 8, 7);
        let b = pellet_directions(aim, 5.0, 8, 7);
        assert_eq!(a, b, "same seed, same pattern");
        assert_ne!(a, pellet_directions(aim, 5.0, 8, 8), "another seed differs");
        for d in &a {
            let angle = d.angle_between(aim).to_degrees();
            assert!(angle <= 5.0 + 1e-3, "{angle}");
            assert!((d.length() - 1.0).abs() < 1e-5);
        }
        assert!(
            a.iter().any(|d| d.angle_between(aim) > 0.0),
            "not all dead centre"
        );
    }

    fn pistol() -> DamageDef {
        DamageDef {
            name: "pistol round".to_string(),
            amount: 40.0,
            kind: DamageType::Bullet,
            knockback: 1.0,
            ignores_armor: false,
            self_scale: 0.5,
            falloff: Falloff {
                full_range: 10.0,
                far_range: 50.0,
                far_fraction: 0.5,
            },
        }
    }

    fn hit(def: &DamageDef) -> Hit<'_> {
        Hit {
            def,
            self_inflicted: false,
            distance: 1.0,
            location_scale: 1.0,
        }
    }

    #[test]
    fn a_hit_takes_health_and_reports_it() {
        let pipe = pipe();
        let mut hp = Health::new(100.0);
        let r = resolve_hit(&hit(&pipe), &mut Protection::default(), &mut hp);
        assert_eq!(r.damage_dealt, 20.0);
        assert_eq!(r.armor_absorbed, 0.0);
        assert!(!r.killed);
        assert_eq!(hp.current, 80.0);
    }

    #[test]
    fn a_lethal_hit_kills_and_health_stops_at_zero() {
        let pistol = pistol();
        let mut hp = Health::new(30.0);
        let r = resolve_hit(&hit(&pistol), &mut Protection::default(), &mut hp);
        assert!(r.killed);
        assert_eq!(hp.current, 0.0);
    }

    #[test]
    fn armor_absorbs_its_share_until_spent_quake_style() {
        let pistol = pistol();
        let mut hp = Health::new(100.0);
        let mut armor = Protection {
            armor: 20.0,
            resistances: vec![],
        };
        // ceil(40 * 0.66) = 27, capped at the 20 carried.
        let r = resolve_hit(&hit(&pistol), &mut armor, &mut hp);
        assert_eq!(r.armor_absorbed, 20.0);
        assert_eq!(r.damage_dealt, 20.0);
        assert_eq!(armor.armor, 0.0);
        assert_eq!(hp.current, 80.0);
        // Armor gone: the next hit lands whole.
        let r = resolve_hit(&hit(&pistol), &mut armor, &mut hp);
        assert_eq!(r.damage_dealt, 40.0);
    }

    #[test]
    fn falloff_scales_by_distance_rust_style() {
        let pistol = pistol();
        assert_eq!(pistol.falloff.at(5.0), 1.0);
        assert!((pistol.falloff.at(30.0) - 0.75).abs() < 1e-6);
        assert_eq!(pistol.falloff.at(80.0), 0.5);
        let mut hp = Health::new(100.0);
        let far = Hit {
            distance: 80.0,
            ..hit(&pistol)
        };
        let r = resolve_hit(&far, &mut Protection::default(), &mut hp);
        assert_eq!(r.damage_dealt, 20.0);
    }

    #[test]
    fn resistance_and_location_multiply() {
        let pipe = pipe();
        let mut hp = Health::new(100.0);
        let mut skeleton = Protection {
            armor: 0.0,
            resistances: vec![(DamageType::Blunt, 2.0)],
        };
        let head = Hit {
            location_scale: 2.0,
            ..hit(&pipe)
        };
        let r = resolve_hit(&head, &mut skeleton, &mut hp);
        assert_eq!(r.damage_dealt, 80.0);
    }

    #[test]
    fn self_damage_is_scaled_after_knockback_so_rocket_jumps_work() {
        let pipe = pipe();
        let mut hp = Health::new(100.0);
        let own = Hit {
            self_inflicted: true,
            ..hit(&pipe)
        };
        let r = resolve_hit(&own, &mut Protection::default(), &mut hp);
        assert_eq!(r.damage_dealt, 10.0);
        assert!(
            (r.knockback - 20.0 / KNOCKBACK_MASS).abs() < 1e-6,
            "full knockback"
        );
    }

    #[test]
    fn damage_never_drops_below_one() {
        let mut weak = pipe();
        weak.amount = 0.1;
        let mut hp = Health::new(10.0);
        let r = resolve_hit(&hit(&weak), &mut Protection::default(), &mut hp);
        assert_eq!(r.damage_dealt, 1.0);
    }

    #[test]
    fn pellets_sum_per_target() {
        let mut blast = MultiDamage::default();
        blast.add("zombie", 4.0);
        blast.add("zombie", 6.0);
        blast.add("wall", 5.0);
        let mut hits = blast.drain();
        hits.sort_by(|a, b| a.0.cmp(b.0));
        assert_eq!(hits, vec![("wall", 1, 5.0), ("zombie", 2, 5.0)]);
        assert!(blast.drain().is_empty());
    }

    #[test]
    fn the_fire_timer_gates_shots_and_charges_for_empty_clicks() {
        let mut timer = FireTimer::default();
        assert_eq!(timer.pull(0.4, true), Trigger::Fire);
        assert_eq!(timer.pull(0.4, true), Trigger::Waiting);
        timer.tick(0.3);
        assert_eq!(timer.pull(0.4, true), Trigger::Waiting);
        timer.tick(0.1);
        assert_eq!(timer.pull(0.4, false), Trigger::Empty);
        assert_eq!(timer.ready_in, EMPTY_DELAY);
    }

    #[test]
    fn gothics_four_moves_and_the_beat() {
        assert_eq!(Swing::from_move(0.0, 0.0), Swing::Overhead);
        assert_eq!(Swing::from_move(0.0, 1.0), Swing::Overhead);
        assert_eq!(Swing::from_move(-1.0, 0.0), Swing::Left);
        assert_eq!(Swing::from_move(1.0, 0.0), Swing::Right);
        assert_eq!(Swing::from_move(0.0, -1.0), Swing::Block);

        // A swing, then a held button does nothing on the beat; let
        // go and press again in the last third and it chains at once.
        let mut timer = FireTimer::default();
        assert_eq!(timer.pull_melee(0.6, Swing::Left, true), Trigger::Fire);
        assert_eq!(timer.swing, Swing::Left);
        timer.tick(0.45);
        assert_eq!(
            timer.pull_melee(0.6, Swing::Right, true),
            Trigger::Waiting,
            "held, not pressed"
        );
        timer.release();
        assert_eq!(
            timer.pull_melee(0.6, Swing::Right, true),
            Trigger::Fire,
            "on the beat"
        );
        assert_eq!(timer.ready_in, 0.6);
        assert_eq!(timer.swing, Swing::Right);

        // Too early is a stall; a clumsy person never chains.
        timer.tick(0.1);
        timer.release();
        assert_eq!(
            timer.pull_melee(0.6, Swing::Left, true),
            Trigger::Waiting,
            "early"
        );
        timer.tick(0.4);
        assert_eq!(
            timer.pull_melee(0.6, Swing::Left, false),
            Trigger::Waiting,
            "clumsy"
        );
        timer.tick(0.1);
        assert_eq!(
            timer.pull_melee(0.6, Swing::Left, false),
            Trigger::Fire,
            "ready at last"
        );

        // Back is a block: no hit, the delay spent.
        timer.tick(1.0);
        assert_eq!(timer.pull_melee(0.6, Swing::Block, true), Trigger::Block);
        assert_eq!(timer.swing, Swing::Block);
    }

    #[test]
    fn damage_defs_register_once() {
        let mut reg = DamageRegistry::default();
        reg.register(pipe()).unwrap();
        assert!(reg.register(pipe()).is_err());
        assert_eq!(reg.def("pipe swing").unwrap().amount, 20.0);
        assert!(reg.def("nothing").is_none());
    }
}

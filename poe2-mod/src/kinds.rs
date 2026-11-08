//! What an entity is, after GameHelper2 Entity.cs TryCalculateEntityType,
//! TryCalculateEntitySubType and CalculateEntityState with the default
//! settings (GameHelper/Settings/State.cs). The health bars and radar
//! icons pick entities by these.
//!
//! Not copied yet: the pinnacle boss subtype and its hidden state (they
//! need the monster's mod names and buff names), points of interest
//! monsters (GameHelper2's default list is empty), and the is_dead stat
//! (the Life part decides death, GameHelper2's fallback).

use crate::entities::Entity;
use crate::model::Rarity;
use serde::Serialize;

/// Entity.DeliriumHiddenMonsterStarting.
pub const DELIRIUM_HIDDEN: &str = "Metadata/Monsters/LeagueDelirium/DoodadDaemons/DoodadDaemon";
/// Entity.DeliriumUselessMonsterStarting.
pub const DELIRIUM_USELESS: &str = "Metadata/Monsters/LeagueDelirium/Volatile/";

/// State.SpecialMiscObjPaths: path start and group.
pub const SPECIAL_OBJECTS: [(&str, i32); 9] = [
    (
        "Metadata/MiscellaneousObjects/Expedition/ExpeditionMarker",
        100,
    ),
    (
        "Metadata/MiscellaneousObjects/Expedition/ExpeditionRelic",
        101,
    ),
    (
        "Metadata/Terrain/Gallows/Leagues/Expedition/Objects/Expedition",
        100,
    ),
    (
        "Metadata/MiscellaneousObjects/Checkpoints/Checkpoint_Endgame_Boss",
        102,
    ),
    (
        "Metadata/MiscellaneousObjects/Expedition2/Expedition2Encounter",
        103,
    ),
    ("Metadata/Terrain/Leagues/Ritual/RitualRuneObject", 104),
    ("Metadata/MiscellaneousObjects/Abyss", 105),
    (
        "Metadata/MiscellaneousObjects/Brequel/BrequelInitiator",
        106,
    ),
    ("Metadata/Terrain/Leagues/Sanctum/Objects/SanctumMote", 107),
];

/// State.MonstersPathsToIgnore.
pub const IGNORED_MONSTERS: [&str; 12] = [
    "Metadata/Monsters/LeagueIncursionNew/Garrison/VaalTrainingDummy",
    "Metadata/Monsters/PerennialKingStage2/PerennialKingCorpseFriend",
    "Metadata/Monsters/MarakethSamdDjinn/SandDjinn",
    "Metadata/Monsters/MarakethWaterDjinn/WaterDjinn",
    "Metadata/Monsters/MarakethTimeDjinn/FireDjinn",
    "Metadata/Monsters/Monsters/LivingLightningPlayerSummoned",
    "Metadata/Monsters/Pirates/CampExplosion",
    "Metadata/Monsters/CageSkeleton/CageSkeleton",
    "Metadata/Pet",
    "Metadata/Monsters/JellfishNettler/JellyfishNettlerFlying",
    "Metadata/Monsters/MarakethSanctumTrial/Hazards/GroundSpike",
    "Metadata/Monsters/MarakethSanctumTrial/Hazards/ProjectilePortal",
];

/// RemoteEnums/Entity/EntityTypes.cs.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub enum Type {
    Chest,
    Npc,
    Player,
    Shrine,
    Monster,
    DeliriumSpawner,
    OtherImportantObjects,
}

/// RemoteEnums/Entity/EntitySubtypes.cs.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub enum Subtype {
    None,
    PlayerSelf,
    PlayerOther,
    ChestWithMagicRarity,
    ChestWithRareRarity,
    ExpeditionChest,
    BreachChest,
    Strongbox,
    SpecialNpc,
}

/// RemoteEnums/Entity/EntityStates.cs.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub enum State {
    None,
    /// Opened chests, dead monsters and spent delirium spawners.
    Useless,
    PlayerLeader,
    MonsterFriendly,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub struct Kind {
    pub kind: Type,
    pub subtype: Subtype,
    pub state: State,
    /// The special object's group, 0 for others.
    pub group: i32,
}

/// The settings the rules read.
#[derive(Clone, Debug, Default)]
pub struct Settings {
    /// State.LeaderName.
    pub leader: String,
    /// State.SpecialNPCPaths, empty by default.
    pub special_npcs: Vec<String>,
}

fn has(e: &Entity, part: &str) -> bool {
    e.parts.contains_key(part)
}

/// TryCalculateEntityType: None when GameHelper2 cannot tell.
pub fn entity_type(e: &Entity) -> Option<(Type, i32)> {
    if !has(e, "Render") {
        return None;
    }
    if has(e, "Chest") {
        return Some((Type::Chest, 0));
    }
    if has(e, "Player") {
        return Some((Type::Player, 0));
    }
    if has(e, "Shrine") {
        return Some((Type::Shrine, 0));
    }
    if let Some((_, group)) = SPECIAL_OBJECTS.iter().find(|(p, _)| e.path.starts_with(p)) {
        return Some((Type::OtherImportantObjects, *group));
    }
    if has(e, "Life") {
        if has(e, "TriggerableBlockage") || !has(e, "Positioned") {
            return None;
        }
        let friendly = e.friendly.unwrap_or(false);
        if !friendly && has(e, "DiesAfterTime") {
            return (e.targetable == Some(true)).then_some((Type::Monster, 0));
        }
        if e.path.starts_with(DELIRIUM_HIDDEN) || e.path.starts_with(DELIRIUM_USELESS) {
            return e
                .path
                .contains("ShardPack")
                .then_some((Type::DeliriumSpawner, 0));
        }
        if IGNORED_MONSTERS.iter().any(|p| e.path.starts_with(p)) {
            return None;
        }
        if has(e, "Monster") || has(e, "Buffs") || has(e, "ObjectMagicProperties") {
            return Some((Type::Monster, 0));
        }
        return None;
    }
    if has(e, "NPC") {
        return Some((Type::Npc, 0));
    }
    None
}

/// TryCalculateEntitySubType: None when GameHelper2 drops the entity
/// (a chest with a minimap icon that is not a strongbox).
pub fn subtype(e: &Entity, kind: Type, local_player: u32, s: &Settings) -> Option<Subtype> {
    Some(match kind {
        Type::Chest => {
            if e.path.starts_with("Metadata/Chests/LeaguesExpedition") {
                Subtype::ExpeditionChest
            } else if e.strongbox == Some(true) {
                Subtype::Strongbox
            } else if has(e, "MinimapIcon") {
                return None;
            } else if e.path.starts_with("Metadata/Chests/Breach") {
                Subtype::BreachChest
            } else {
                match e.rarity {
                    Some(Rarity::Rare | Rarity::Unique) => Subtype::ChestWithRareRarity,
                    Some(Rarity::Magic) => Subtype::ChestWithMagicRarity,
                    _ => Subtype::None,
                }
            }
        }
        Type::Player if e.id == local_player => Subtype::PlayerSelf,
        Type::Player => Subtype::PlayerOther,
        Type::Npc if s.special_npcs.iter().any(|p| e.path.starts_with(p)) => Subtype::SpecialNpc,
        _ => Subtype::None,
    })
}

/// CalculateEntityState.
pub fn state(e: &Entity, kind: Type, subtype: Subtype, s: &Settings) -> State {
    let dead = e.life.is_some_and(|l| !l.alive());
    match kind {
        Type::Chest if e.chest_opened == Some(true) => State::Useless,
        Type::DeliriumSpawner if dead => State::Useless,
        Type::Monster if dead => State::Useless,
        Type::Monster if e.friendly == Some(true) => State::MonsterFriendly,
        Type::Player
            if subtype == Subtype::PlayerOther
                && !s.leader.is_empty()
                && e.player.as_ref().is_some_and(|p| p.name == s.leader) =>
        {
            State::PlayerLeader
        }
        _ => State::None,
    }
}

/// The entity's type, subtype and state; None when GameHelper2 cannot
/// tell what it is.
pub fn classify(e: &Entity, local_player: u32, s: &Settings) -> Option<Kind> {
    let (kind, group) = entity_type(e)?;
    let subtype = subtype(e, kind, local_player, s)?;
    Some(Kind {
        kind,
        subtype,
        state: state(e, kind, subtype, s),
        group,
    })
}

#[cfg(test)]
pub(crate) mod tests {
    use super::*;
    use crate::entities::{Life, PlayerPart, Vital};

    pub(crate) fn with_parts(path: &str, parts: &[&str]) -> Entity {
        Entity {
            valid: true,
            path: path.into(),
            parts: parts.iter().map(|p| (p.to_string(), 1)).collect(),
            ..Entity::default()
        }
    }

    pub(crate) fn alive(health: i32) -> Option<Life> {
        Some(Life {
            health: Vital {
                current: health,
                total: 100,
                ..Vital::default()
            },
            ..Life::default()
        })
    }

    #[test]
    fn monsters_players_and_chests() {
        let s = Settings {
            leader: "Lead".into(),
            ..Settings::default()
        };
        let mut wolf = with_parts(
            "Metadata/Monsters/Wolf/Wolf",
            &["Render", "Life", "Positioned", "ObjectMagicProperties"],
        );
        wolf.life = alive(50);
        wolf.rarity = Some(Rarity::Rare);
        let k = classify(&wolf, 1, &s).unwrap();
        assert_eq!(
            (k.kind, k.subtype, k.state),
            (Type::Monster, Subtype::None, State::None)
        );
        wolf.life = alive(0);
        assert_eq!(classify(&wolf, 1, &s).unwrap().state, State::Useless);
        wolf.life = alive(50);
        wolf.friendly = Some(true);
        assert_eq!(
            classify(&wolf, 1, &s).unwrap().state,
            State::MonsterFriendly
        );

        let pet = with_parts(
            "Metadata/Pet/Cat",
            &["Render", "Life", "Positioned", "Buffs"],
        );
        assert_eq!(classify(&pet, 1, &s), None);
        let mut totem = with_parts(
            "Metadata/Monsters/Totem",
            &["Render", "Life", "Positioned", "DiesAfterTime"],
        );
        assert_eq!(classify(&totem, 1, &s), None);
        totem.targetable = Some(true);
        assert_eq!(classify(&totem, 1, &s).unwrap().kind, Type::Monster);

        let mut me = with_parts("Metadata/Characters/Int", &["Render", "Player"]);
        me.id = 1;
        assert_eq!(classify(&me, 1, &s).unwrap().subtype, Subtype::PlayerSelf);
        let mut lead = with_parts("Metadata/Characters/Str", &["Render", "Player"]);
        lead.id = 2;
        lead.player = Some(PlayerPart {
            name: "Lead".into(),
            ..PlayerPart::default()
        });
        let k = classify(&lead, 1, &s).unwrap();
        assert_eq!(
            (k.subtype, k.state),
            (Subtype::PlayerOther, State::PlayerLeader)
        );

        let mut chest = with_parts("Metadata/Chests/Urn", &["Render", "Chest"]);
        chest.rarity = Some(Rarity::Magic);
        assert_eq!(
            classify(&chest, 1, &s).unwrap().subtype,
            Subtype::ChestWithMagicRarity
        );
        chest.chest_opened = Some(true);
        assert_eq!(classify(&chest, 1, &s).unwrap().state, State::Useless);
        let mut boxed = with_parts(
            "Metadata/Chests/StrongBoxes/Arcanist",
            &["Render", "Chest", "MinimapIcon"],
        );
        assert_eq!(classify(&boxed, 1, &s), None);
        boxed.strongbox = Some(true);
        assert_eq!(classify(&boxed, 1, &s).unwrap().subtype, Subtype::Strongbox);

        let relic = with_parts(
            "Metadata/MiscellaneousObjects/Expedition/ExpeditionRelic2",
            &["Render", "Life", "Positioned"],
        );
        let k = classify(&relic, 1, &s).unwrap();
        assert_eq!((k.kind, k.group), (Type::OtherImportantObjects, 101));
        assert_eq!(
            classify(&with_parts("Metadata/Npc/Una", &["NPC"]), 1, &s),
            None
        );
    }
}

// G2's binder for `ueforge::damage::DamageHook`. The trampoline +
// parm decoding + classification + before/after dispatch all live
// framework-side; this file owns:
//
// - The Maine-specific `DamageHookConfig` (component class,
//   damage UFunction, parm offsets, FDamageInfo layout).
// - The KillerKind classifier (Player / Buggy / Other. G2 has
//   tame buggies in addition to direct player kills).
// - Per-event game-side reactions: kill credit (award XP), debug
//   PE-queue drain, damage-trace passthrough, impact-resistance
//   reversal, and (future) live-damage skills (Lifesteal,
//   Critical, Evasion, Thorns).
//
// The whole module is ~150 lines. Compare to ~600 lines in the
// pre-framework era.

use std::sync::OnceLock;

use ueforge::damage::{DamageBinder, DamageEvent, DamageHook, DamageHookConfig};
use ueforge::hook::ProcessEventHook;
use ueforge::ue::actor::{class_chain_contains, controller_pawn};
use ueforge::ue::damage_info::DamageInfoLayout;
use ueforge::ue::UObject;

/// Maine `FDamageInfo` layout. `last_damage_info_offset` is
/// `UHealthComponent.LastDamageInfo` at `0x03B0`; the four field
/// offsets are absolute (component-relative, already including
/// the base).
pub(crate) const DAMAGE_INFO: DamageInfoLayout = DamageInfoLayout {
    last_damage_info_offset: 0x03B0,
    instigator_offset: 0x03B0 + 0x0020,
    damage_source_offset: 0x03B0 + 0x0028,
    damage_type_class_offset: 0x03B0 + 0x0040,
    damage_flags_offset: 0x03B0 + 0x0070,
};

const CONFIG: DamageHookConfig = DamageHookConfig {
    component_class: "HealthComponent",
    damage_fn: "MulticastHandleEffectsWithDamageFlags",
    // Maine multicast layout: HitLocation(0x18) Damage(0x18-23
    // wait: HitLocation FVector_NetQuantize is 0x18 bytes at
    // +0x00, then Damage(f32) at +0x18, DamageFlags(i32) at
    // +0x1C, TypeFlags(u32) at +0x20.
    damage_parm_offset: 0x18,
    damage_flags_parm_offset: 0x1C,
    type_flags_parm_offset: 0x20,
    killing_blow_mask: 2, // EDamageInfoFlags::KillingBlow
    damage_info: DAMAGE_INFO,
    player_outer_filter: "BP_SurvivalPlayerCharacter",
    player_controller_filter: "PlayerController",
};

static HOOK: DamageHook<G2DamageBinder> = DamageHook::new(CONFIG);

// SurvivalCreature filter is needed for kill credit (excludes
// player deaths and prop / building destruction events that also
// fire MulticastHandleEffectsWithDamageFlags). Cached at install.
static CREATURE_CLASS: OnceLock<usize> = OnceLock::new();

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum KillerKind {
    Player,
    Buggy,
    Other,
}

fn classify(instigator: Option<&UObject>) -> KillerKind {
    let Some(controller) = instigator else {
        return KillerKind::Other;
    };
    if class_chain_contains(controller, "PlayerController") {
        return KillerKind::Player;
    }
    if class_chain_contains(controller, "Buggy") {
        return KillerKind::Buggy;
    }
    if let Some(pawn) = controller_pawn(controller)
        && class_chain_contains(pawn, "Buggy")
    {
        return KillerKind::Buggy;
    }
    KillerKind::Other
}

fn describe_instigator(instigator: Option<&UObject>) -> String {
    let Some(ctrl) = instigator else {
        return "<unresolved>".to_string();
    };
    let class_name = ctrl
        .class()
        .map(|c| c.as_object().name())
        .unwrap_or_default();
    format!("{} ({})", ctrl.name(), class_name)
}

struct G2DamageBinder;

impl DamageBinder for G2DamageBinder {
    fn before(&self, event: &DamageEvent) -> Option<f32> {
        ueforge::counters::bump(&crate::counters::KILL_HOOK_FIRES);

        // Drain the debug PE queue. Re-entrance guard inside
        // `drain_pending` prevents recursive draining if a queued
        // op fans out PE work.
        crate::debug::drain_pending();

        // Player-component diagnostic record (damage_ring + log).
        if event.victim_is_player {
            ueforge::counters::bump(&crate::counters::KILL_HOOK_PLAYER_FIRES);
            push_damage_event(event);
        }

        // Live-damage pre-application: Critical (player-dealt) and
        // Evasion (player-taken) belong here. Catalog rows pending.
        None
    }

    fn after(&self, event: &DamageEvent) {
        // Impact-resistance reversal: subtract the env-damage
        // portion from the player HC's CurrentDamage post-apply.
        if event.victim_is_player {
            apply_impact_resistance_reversal(event);
        }

        // Lifesteal: when the player damages a non-player victim,
        // heal the player by `damage * lifesteal_fraction`. Reads
        // the player's lifesteal level from the live tracker so
        // the effect tracks per-spend without re-applying CDOs.
        if event.attacker_is_player
            && !event.victim_is_player
            && event.damage > 0.0
        {
            apply_lifesteal(event);
        }

        // Kill credit on killing-blow events targeting creatures.
        if !event.is_killing_blow {
            return;
        }
        let Some(creature_addr) = CREATURE_CLASS.get().copied() else {
            return;
        };
        let Some(victim) = event.victim else {
            return;
        };
        let Some(actor_class) = victim.class() else {
            return;
        };
        let creature_uclass = unsafe {
            &*(creature_addr as *const ueforge::ue::UClass)
        };
        if !victim.is_a(creature_uclass) {
            if cfg!(debug_assertions) {
                ueforge::log!(
                    "rpg/kill: ignoring non-creature kill: {} ({})",
                    victim.name(),
                    actor_class.as_object().name()
                );
            }
            return;
        }

        let class_name = actor_class.as_object().name();
        let kind = classify(event.attacker.map(|a| a as &UObject));
        let killer_label = describe_instigator(event.attacker.map(|a| a as &UObject));

        use crate::rpg::tracker::{record_kill, KillSource};
        let (label, source) = match kind {
            KillerKind::Player => ("PLAYER", Some(KillSource::Player)),
            KillerKind::Buggy => ("BUGGY", Some(KillSource::Buggy)),
            KillerKind::Other => ("skip", None),
        };
        ueforge::log!(
            "rpg/kill: {} {} ({}) killed by {}",
            label,
            victim.name(),
            class_name,
            killer_label
        );
        if let Some(s) = source {
            record_kill(&class_name, s);
        }
    }
}

fn push_damage_event(event: &DamageEvent) {
    use ueforge::ue::field::read_f32;
    let cd_now = read_f32(event.victim_component, 0x032C);
    let now_secs = std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_secs())
        .unwrap_or(0);
    crate::debug::record_damage_event(crate::debug::DamageEvent {
        at_secs: now_secs,
        function: "MulticastHandleEffectsWithDamageFlags".to_string(),
        damage: event.damage,
        damage_flags: event.damage_flags,
        type_flags: event.type_flags,
        current_damage_before: Some(cd_now),
        current_damage_after: None,
    });
    if event.damage > 0.0 {
        ueforge::counters::bump(&crate::counters::KILL_HOOK_LOG_LINES);
        ueforge::log!(
            "rpg/dmg-trace: damage={:.2} flags=0x{:08x} type_flags=0x{:08x}",
            event.damage,
            event.damage_flags,
            event.type_flags
        );
    }
}

fn apply_lifesteal(event: &DamageEvent) {
    use crate::rpg::skills::SKILL_LIFESTEAL;
    let level = crate::rpg::tracker::with_state(|s| {
        s.skill_levels.get(SKILL_LIFESTEAL).copied().unwrap_or(0)
    })
    .unwrap_or(0);
    if level == 0 || !crate::rpg::apply::is_skill_enabled(SKILL_LIFESTEAL) {
        return;
    }
    // max_bonus = 0.90 in catalog; sqrt(level/100) progress.
    let progress = (level as f32 / 100.0).sqrt().min(1.0);
    let fraction = 0.90 * progress;
    let heal = event.damage * fraction;
    if heal <= 0.0 {
        return;
    }

    // Walk to the live player's HC and decrement CurrentDamage.
    // SAFETY: we're on the game thread inside the PE trampoline.
    let Some(pawn) = (unsafe { crate::rpg::apply::PLAYER.first_live_static() }) else {
        return;
    };
    let Some(hc) = ueforge::ue::field::read_component_ptr(
        pawn,
        crate::rpg::apply::ASC_HEALTH_COMPONENT,
    ) else {
        return;
    };
    use ueforge::ue::TypedField;
    const HC_CURRENT_DAMAGE: TypedField<f32> = TypedField::at(0x032C);
    unsafe {
        let cd_now = HC_CURRENT_DAMAGE.read(hc);
        if cd_now <= 0.0 {
            // Player at full health; nothing to heal.
            return;
        }
        let new_cd = (cd_now - heal).max(0.0);
        HC_CURRENT_DAMAGE.write(hc, new_cd);
        ueforge::log!(
            "rpg/lifesteal: dealt {:.2} -> heal {:.2} (level={}, frac={:.3}); CurrentDamage {:.2} -> {:.2}",
            event.damage,
            heal,
            level,
            fraction,
            cd_now,
            new_cd
        );
    }
}

fn apply_impact_resistance_reversal(event: &DamageEvent) {
    let level = crate::rpg::fall_hook::current_impact_resistance_level();
    if level == 0 || event.damage <= 0.0 {
        return;
    }
    let damage_type_name = DAMAGE_INFO.damage_type_name(event.victim_component);
    if !damage_type_name.contains("Environmental") {
        return;
    }
    let progress = (level as f32 / 100.0).sqrt().min(1.0);
    let to_reverse = event.damage * progress;
    use ueforge::ue::TypedField;
    const HC_CURRENT_DAMAGE: TypedField<f32> = TypedField::at(0x032C);
    unsafe {
        let cd_now = HC_CURRENT_DAMAGE.read(event.victim_component);
        let new_cd = (cd_now - to_reverse).max(0.0);
        HC_CURRENT_DAMAGE.write(event.victim_component, new_cd);
        ueforge::log!(
            "rpg/impact: reversed env damage {:.2} (raw={:.2}, level={}); CurrentDamage {:.2} -> {:.2}",
            to_reverse,
            event.damage,
            level,
            cd_now,
            new_cd
        );
    }
}

pub fn install() -> Result<ProcessEventHook, &'static str> {
    let creature_class = ueforge::ue::ClassRef::new("SurvivalCreature")
        .get()
        .ok_or("SurvivalCreature class not loaded")?;
    let _ = CREATURE_CLASS.set(
        creature_class as *const ueforge::ue::UClass as usize,
    );
    HOOK.install(G2DamageBinder)
}

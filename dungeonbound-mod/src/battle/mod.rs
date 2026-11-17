//! The game's fight code ported into the mod's own math (operator
//! 2026-11-17: "go fix the fight math", scope "Everything"). Each file
//! names the game script it follows. Built beside fight.rs; the judge
//! moves over once this matches real fights in the battle logs.

pub mod fighter;
pub mod status;

#[cfg(test)]
mod tests {
    use std::sync::Arc;

    use super::fighter::{Fighter, Tick};
    use super::status::{Data, Db, Kind};

    fn status(id: &str, kind: Kind, tick: f64, duration: f64) -> Arc<Data> {
        Arc::new(Data {
            id: id.into(),
            name: id.into(),
            kind,
            base_dmg_per_stack: 1.0,
            tick_interval: tick,
            duration,
            freeze_skip_turns: 1,
            stun_skip_chance: 0.25,
            pct_per_stack: 0.0,
            pct_cap: 0.0,
        })
    }

    fn fighter(hp: i64) -> Fighter {
        Fighter {
            current_hp: hp,
            max_hp: hp,
            poison_tick_mult: 1.0,
            damage_dealt_mult: 1.0,
            ..Fighter::default()
        }
    }

    /// Poison: the first tick does not decay, every later tick decays
    /// one stack after it hurts (combatant_runtime.gd tick_statuses).
    #[test]
    fn poison_decays_after_the_first_tick() {
        let db = Db::default();
        let poison = status("poison", Kind::Poison, 1.0, 4.0);
        let mut rng = fastrand::Rng::with_seed(1);
        let mut f = fighter(100);
        assert!(f.apply_status(&poison, 3, 2.0, 0, false, None, &db, &mut rng));
        let mut hurt = Vec::new();
        for _ in 0..6 {
            for t in f.tick_statuses(1.0) {
                if let Tick::Hurt(_, n, _) = t {
                    hurt.push(n);
                }
            }
        }
        assert_eq!(hurt, vec![6, 6, 4, 2]);
        assert_eq!(f.current_hp, 82);
        assert!(!f.has_status(Kind::Poison));
    }

    /// Stun without item stun builds stagger: two stacks, then the third
    /// stuns and stops the swing clock.
    #[test]
    fn third_stun_staggers() {
        let stagger = status("stagger", Kind::Stagger, 1.0, 4.0);
        let stun = status("stun", Kind::Stun, 1.0, 1.5);
        let db = Db {
            all: vec![stagger, stun.clone()],
        };
        let mut rng = fastrand::Rng::with_seed(1);
        let mut f = fighter(100);
        assert!(f.apply_status(&stun, 1, 0.0, 0, false, None, &db, &mut rng));
        assert!(f.apply_status(&stun, 1, 0.0, 0, false, None, &db, &mut rng));
        assert_eq!(f.get_status_stacks(Kind::Stagger), 2);
        assert!(f.attack_rate() > 0.0);
        assert!(f.apply_status(&stun, 1, 0.0, 0, false, None, &db, &mut rng));
        assert!(f.has_status(Kind::Stun));
        assert_eq!(f.attack_rate(), 0.0);
        assert!((f.stun_immunity - 3.5).abs() < 1e-9);
    }
}

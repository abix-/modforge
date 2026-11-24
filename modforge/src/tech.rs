//! Research (topside todo 28; authority.md "TechTree": deep and
//! branching, with infinite upgrade topics that never cap, the Factorio
//! model; research consumes components). A topic costs items, needs
//! other topics first, and unlocks recipes when done; an endless topic
//! is researched again and again, each level costing more (Factorio's
//! infinite research: the cost grows with the level). What a group has
//! researched is its own. The consumer pays the cost and says what a
//! level of an endless topic gives. Engine-free.

use std::collections::BTreeMap;

use serde::{Deserialize, Serialize};

/// One research topic as data.
#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct TopicDef {
    pub name: String,
    /// What researching it takes, at its first level.
    pub cost: Vec<(String, u32)>,
    /// Topics done first.
    #[serde(default)]
    pub needs: Vec<String>,
    /// The recipes it unlocks, by name: locked until it is done.
    #[serde(default)]
    pub unlocks: Vec<String>,
    /// Researched again and again, each level costing more.
    #[serde(default)]
    pub endless: bool,
    /// The least bench tier a group must have to research it (Rust's tech
    /// tree per workbench level); 1 when left out.
    #[serde(default = "first_tier")]
    pub tier: u32,
    /// Each level of it raises the group's bench tier by one (Rust's
    /// workbench 2 and 3; endless, so no last tier: topside todo "Recipes
    /// and research", operator 2026-11-23: "tier n").
    #[serde(default)]
    pub raises_tier: bool,
}

/// A topic's tier when its content leaves it out.
fn first_tier() -> u32 {
    1
}

/// Every topic.
#[derive(Clone, Debug, Default)]
pub struct TechTree {
    pub topics: Vec<TopicDef>,
}

/// What one group has researched: each topic's level (1 is done; an
/// endless topic goes on).
#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct Known {
    pub levels: BTreeMap<String, u32>,
}

impl Known {
    pub fn level(&self, topic: &str) -> u32 {
        self.levels.get(topic).copied().unwrap_or(0)
    }
}

impl TechTree {
    pub fn topic(&self, name: &str) -> Option<&TopicDef> {
        self.topics.iter().find(|t| t.name == name)
    }

    /// A group's bench tier: 1, and one more for each level of every topic
    /// that raises it. No last tier.
    pub fn tier(&self, known: &Known) -> u32 {
        1 + self.topics.iter().filter(|t| t.raises_tier).map(|t| known.level(&t.name)).sum::<u32>()
    }

    /// The topics a group can research now, in the tree's order: every
    /// one needed is done, its tier is reached, and it is not done unless
    /// endless.
    pub fn open(&self, known: &Known) -> Vec<&TopicDef> {
        let tier = self.tier(known);
        self.topics
            .iter()
            .filter(|t| t.tier <= tier)
            .filter(|t| t.needs.iter().all(|n| known.level(n) > 0))
            .filter(|t| t.endless || known.level(&t.name) == 0)
            .collect()
    }

    /// What the next level of a topic costs: its cost times the level
    /// to come (level 1 the cost itself).
    pub fn cost(&self, topic: &TopicDef, known: &Known) -> Vec<(String, u32)> {
        let next = known.level(&topic.name) + 1;
        topic.cost.iter().map(|(item, n)| (item.clone(), n * next)).collect()
    }

    /// Mark the next level researched, if it is open: the new level.
    pub fn research(&self, topic: &str, known: &mut Known) -> Option<u32> {
        let def = self.open(known).into_iter().find(|t| t.name == topic)?;
        let level = known.level(&def.name) + 1;
        known.levels.insert(def.name.clone(), level);
        Some(level)
    }

    /// Whether a recipe is locked for a group: some topic unlocks it and
    /// that topic is not done.
    pub fn locked(&self, recipe: &str, known: &Known) -> bool {
        self.topics.iter().any(|t| t.unlocks.iter().any(|r| r == recipe) && known.level(&t.name) == 0)
    }
}

/// What a level of an endless topic gives, diminishing: the first level
/// `step`, each after half as much again (Claude's rule).
pub fn endless_bonus(step: f32, level: u32) -> f32 {
    (0..level).map(|l| step * 0.5f32.powi(l as i32)).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn tree() -> TechTree {
        let t = |name: &str, needs: &[&str], unlocks: &[&str], endless| TopicDef {
            name: name.into(),
            cost: vec![("scrap".into(), 5)],
            needs: needs.iter().map(|s| s.to_string()).collect(),
            unlocks: unlocks.iter().map(|s| s.to_string()).collect(),
            endless,
            tier: 1,
            raises_tier: false,
        };
        TechTree { topics: vec![t("tools", &[], &["pipe"], false), t("guns", &["tools"], &["shotgun"], false), t("better tools", &["tools"], &[], true)] }
    }

    #[test]
    fn prerequisites_branch_and_endless_topics_cost_more() {
        let tree = tree();
        let mut known = Known::default();
        assert!(tree.locked("pipe", &known));
        assert_eq!(tree.open(&known).len(), 1, "only tools before tools");
        assert_eq!(tree.research("guns", &mut known), None);
        assert_eq!(tree.research("tools", &mut known), Some(1));
        assert!(!tree.locked("pipe", &known));
        assert_eq!(tree.open(&known).len(), 2, "guns and better tools branch from tools");
        assert_eq!(tree.research("better tools", &mut known), Some(1));
        let endless = tree.topic("better tools").unwrap();
        assert_eq!(tree.cost(endless, &known), vec![("scrap".to_string(), 10)]);
        assert_eq!(tree.research("better tools", &mut known), Some(2));
        assert!(endless_bonus(0.1, 2) > endless_bonus(0.1, 1));
    }
}

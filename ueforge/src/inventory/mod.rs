//! Inventory framework. One of ueforge's opinionated UE5 mod
//! modules (rpg / stacks / difficulty / inventory / damage).
//!
//! Universal patterns for UE5 mods that touch the player's
//! inventory. Today: [`viewport`] -- the fixed-size-visible-grid
//! paging framework that lets a mod bump the underlying capacity
//! beyond what the UI shows and scroll through pages with the
//! mouse wheel.
//!
//! Future entries (CRUD ops, stack split / merge, sort, etc) will
//! land here as second consumers materialize.

pub mod viewport;

//! Shutdown registry: the ONE list of undos for everything this
//! generation of the mod has done.
//!
//! ```text
//! K8s slot: Def=ShutdownHandlerDef, Registry=ShutdownRegistry
//!           (SHUTDOWN_REGISTRY singleton),
//!           Instance=Undo, Controller=run_all()
//! ```
//!
//! ## Do the thing, record its undo, in the same call
//!
//! Every action that changes something outside our own memory (a
//! Harmony hook, a byte patch, a listener thread, a poller, an
//! input binding) records its undo here AT THE MOMENT IT ACTS, via
//! [`ShutdownRegistry::record`], and hands back an [`Undo`]:
//!
//! - drop the [`Undo`] to undo the action now;
//! - [`Undo::keep`] to leave it on until the generation shuts down;
//! - [`ShutdownRegistry::run_all`] (the generation's shutdown) runs
//!   every undo still on the list.
//!
//! So shutdown never has to guess what was done: there is no
//! second list per subsystem, and an action held somewhere the
//! framework cannot see (a static that is never dropped) is still
//! undone, because its undo was recorded when it was done.
//!
//! Prior art: Linux kernel managed device resources (`devm_*`),
//! released automatically in reverse order when the device goes
//! away; .NET `CompositeDisposable`; Go's `defer` and `t.Cleanup`.
//!
//! ## Ordering
//!
//! Each undo carries an `order: u32`. `run_all` runs lower orders
//! first and, within one order, the most recently done first (undo
//! in reverse of doing). Conventions:
//!
//! - `100`. Hooks, so trampolines stop firing before threads join
//! - `150`. Byte patches, so the next generation finds the game's
//!   original bytes
//! - `200`. HTTP listeners
//! - `250`. Pollers
//! - `300`. `Settings::watch` watchers
//! - `400`. Scanner freeze sweeper
//!
//! Game crates that must interleave register at `50` (before the
//! framework) or `500+` (after).
//!
//! ## Why not plain Drop?
//!
//! A value in a static is never dropped, and nothing is dropped
//! when a generation is swapped out: its image just stops being
//! called. The list is run synchronously from the generation's
//! shutdown entry point, before the next generation loads.

use std::sync::atomic::{AtomicU64, Ordering};

use parking_lot::Mutex;

/// One fixed shutdown step, for a subsystem whose undo is not tied
/// to one action. Recorded with [`ShutdownRegistry::register`].
pub struct ShutdownHandlerDef {
    /// Used in the log line emitted before the step runs.
    pub name: &'static str,
    /// Lower runs first.
    pub order: u32,
    /// Cleanup function. Must be sync.
    pub run: fn(),
}

struct Entry {
    id: u64,
    /// Kind of action, e.g. "hook", "server". [`ShutdownRegistry::undo_all`]
    /// and [`ShutdownRegistry::list`] select by it.
    name: &'static str,
    /// What exactly was done, for the log and [`ShutdownRegistry::list`].
    what: String,
    order: u32,
    undo: Box<dyn FnOnce() + Send>,
}

/// The one list of recorded undos.
pub struct ShutdownRegistry {
    entries: Mutex<Vec<Entry>>,
    next_id: AtomicU64,
}

/// The undo of one recorded action. Dropping it undoes the action
/// now; [`Undo::keep`] leaves it on the list for the generation's
/// shutdown.
#[must_use = "dropping an Undo undoes the action immediately; call .keep() to leave it on until shutdown"]
pub struct Undo {
    registry: &'static ShutdownRegistry,
    id: u64,
}

impl Undo {
    /// Leave the action in place until the generation shuts down.
    pub fn keep(self) {
        std::mem::forget(self);
    }
}

impl Drop for Undo {
    fn drop(&mut self) {
        self.registry.undo_one(self.id);
    }
}

impl ShutdownRegistry {
    pub const fn new() -> Self {
        Self {
            entries: Mutex::new(Vec::new()),
            next_id: AtomicU64::new(1),
        }
    }

    /// Record the undo of something just done. Call this in the
    /// same function that does the thing, straight after it
    /// succeeds.
    pub fn record<F>(&'static self, name: &'static str, what: String, order: u32, undo: F) -> Undo
    where
        F: FnOnce() + Send + 'static,
    {
        let id = self.next_id.fetch_add(1, Ordering::Relaxed);
        self.entries.lock().push(Entry {
            id,
            name,
            what,
            order,
            undo: Box::new(undo),
        });
        Undo { registry: self, id }
    }

    /// Record a fixed shutdown step, run once by [`Self::run_all`].
    pub fn register(&'static self, def: ShutdownHandlerDef) {
        let run = def.run;
        self.record(def.name, String::new(), def.order, run).keep();
    }

    pub fn register_many<I: IntoIterator<Item = ShutdownHandlerDef>>(&'static self, defs: I) {
        for d in defs {
            self.register(d);
        }
    }

    fn undo_one(&self, id: u64) {
        let entry = {
            let mut g = self.entries.lock();
            g.iter().position(|e| e.id == id).map(|i| g.remove(i))
        };
        if let Some(e) = entry {
            run_entry(e);
        }
    }

    /// Undo every recorded action of one kind now, most recent
    /// first. For a caller that has to stop one kind of thing
    /// early (the injector stopping the listener before it
    /// unloads the DLL).
    pub fn undo_all(&self, name: &str) {
        let mut taken: Vec<Entry> = {
            let mut g = self.entries.lock();
            let (take, keep): (Vec<Entry>, Vec<Entry>) =
                std::mem::take(&mut *g).into_iter().partition(|e| e.name == name);
            *g = keep;
            take
        };
        taken.sort_by(|a, b| b.id.cmp(&a.id));
        for e in taken {
            run_entry(e);
        }
    }

    /// Run every undo still on the list: lower `order` first,
    /// within one order the most recently done first. Each undo
    /// runs even if an earlier one panicked.
    pub fn run_all(&self) {
        let mut snapshot: Vec<Entry> = std::mem::take(&mut *self.entries.lock());
        snapshot.sort_by(|a, b| a.order.cmp(&b.order).then(b.id.cmp(&a.id)));
        let n = snapshot.len();
        for e in snapshot {
            run_entry(e);
        }
        crate::log!("shutdown: {n} undo(s) complete");
    }

    /// What is recorded for one kind, oldest first.
    pub fn list(&self, name: &str) -> Vec<String> {
        self.entries
            .lock()
            .iter()
            .filter(|e| e.name == name)
            .map(|e| e.what.clone())
            .collect()
    }

    pub fn names(&self) -> Vec<&'static str> {
        self.entries.lock().iter().map(|e| e.name).collect()
    }

    pub fn len(&self) -> usize {
        self.entries.lock().len()
    }

    pub fn is_empty(&self) -> bool {
        self.entries.lock().is_empty()
    }
}

fn run_entry(e: Entry) {
    if e.what.is_empty() {
        crate::log!("shutdown: undo '{}' (order {})", e.name, e.order);
    } else {
        crate::log!("shutdown: undo '{}' {} (order {})", e.name, e.what, e.order);
    }
    let name = e.name;
    if std::panic::catch_unwind(std::panic::AssertUnwindSafe(e.undo)).is_err() {
        crate::log!("shutdown: undo '{name}' panicked; continuing");
    }
}

impl Default for ShutdownRegistry {
    fn default() -> Self {
        Self::new()
    }
}

/// Process-wide shutdown registry singleton.
pub static SHUTDOWN_REGISTRY: ShutdownRegistry = ShutdownRegistry::new();

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::AtomicU32;

    #[test]
    fn drop_undoes_now_keep_waits_for_run_all() {
        static REG: ShutdownRegistry = ShutdownRegistry::new();
        static N: AtomicU32 = AtomicU32::new(0);
        let u = REG.record("t", "a".into(), 100, || {
            N.fetch_add(1, Ordering::SeqCst);
        });
        drop(u);
        assert_eq!(N.load(Ordering::SeqCst), 1);
        assert!(REG.is_empty());

        REG.record("t", "b".into(), 100, || {
            N.fetch_add(10, Ordering::SeqCst);
        })
        .keep();
        assert_eq!(N.load(Ordering::SeqCst), 1);
        REG.run_all();
        assert_eq!(N.load(Ordering::SeqCst), 11);
        assert!(REG.is_empty());
    }

    #[test]
    fn run_all_orders_then_newest_first_and_survives_panic() {
        static REG: ShutdownRegistry = ShutdownRegistry::new();
        static SEEN: Mutex<Vec<&'static str>> = Mutex::new(Vec::new());
        REG.record("x", String::new(), 200, || SEEN.lock().push("200-old")).keep();
        REG.record("x", String::new(), 100, || panic!("boom")).keep();
        REG.record("x", String::new(), 200, || SEEN.lock().push("200-new")).keep();
        REG.record("x", String::new(), 100, || SEEN.lock().push("100")).keep();
        REG.run_all();
        assert_eq!(*SEEN.lock(), vec!["100", "200-new", "200-old"]);
    }

    #[test]
    fn undo_all_takes_one_kind_and_a_dropped_undo_after_it_is_a_no_op() {
        static REG: ShutdownRegistry = ShutdownRegistry::new();
        static N: AtomicU32 = AtomicU32::new(0);
        let u = REG.record("server", "s".into(), 200, || {
            N.fetch_add(1, Ordering::SeqCst);
        });
        REG.record("hook", "h".into(), 100, || {}).keep();
        REG.undo_all("server");
        assert_eq!(N.load(Ordering::SeqCst), 1);
        drop(u);
        assert_eq!(N.load(Ordering::SeqCst), 1);
        assert_eq!(REG.list("hook"), vec!["h".to_string()]);
    }
}

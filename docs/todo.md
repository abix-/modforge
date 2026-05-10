# TODO

> **Authoritative on:** open work. What's NEXT, not what's done.
> Completed milestones live in [`changelog.md`](changelog.md).
> Per-subject deep dives live in this `docs/` directory.

Roughly ordered by leverage. "Mid" priority items below the line
are not blocking; pick from the top of the list when starting a
new session.

---

## bbp dedup -- Phase 1 DONE (2026-05-10)

`better-backpack` consumes ueforge for every piece of generic
infrastructure. Net -930 LoC: deleted `cpp/shim.cpp`,
`src/rpg/ffi.rs`, `src/log.rs`, `src/sdk/`, `src/hook/`,
`winhttp.def`, custom DllMain + `better_backpack_start/stop`
exports, `DLL_HMODULE` static. Replaced with
`ueforge::ue4ss_mod!(MOD_INFO)`, a Rust ImGui render in
`src/rpg/tab.rs`, and a 1-line `build.rs`. Build-clean
validated; in-game smoke test pending.

**Phase 2 small promotions DONE (2026-05-10):**

- [x] **`ClassFieldTweak<T>`** -- live-UObject sibling of
  `FieldTweak<T>` (which is DataTable-row scoped). Walks
  GObjects, snapshots vanilla per instance, writes via
  `transform(vanilla) -> Option<T>`. bbp's `patch::run` and
  `survival::run` migrated -- ~150 LoC dropped from bbp.
- [x] **`hook::function_ptr` / `function_ptr_required`** -- one-line
  resolver for `*const UFunction as usize`. New mods cache the
  result in an `AtomicUsize` and dispatch by pointer identity in
  the trampoline.
- [x] **Canonical-site doc on `Queue::drain`** -- the empty-check
  / re-entrance / counter pattern is now in the rustdoc so the
  next mod gets it right on first try.

**Phase 3 first wave DONE (2026-05-10):**

- [x] **`ueforge::rpg::xp::Curve`** -- cumulative XP / level_for_xp
  math, parameterized on `(base, exponent, max_level)`.
- [x] **`ueforge::rpg::progress::sqrt_progress(level, max)`**.
- [x] **`ueforge::rpg::SkillsState`** -- the universal on-disk
  schema. `spend() / refund() / level_of()` methods.
- [x] **`ueforge::rpg::SlotStore<S>`** -- per-slot JSON persistence
  with atomic temp+rename. Generic over persisted struct.
- [x] **`ueforge::rpg::DisabledSkills`** -- toggle set for
  "disable a skill without refunding its points".
- [x] **`ueforge::rpg::SlotPoller::spawn`** -- 1Hz worker driving
  activate/deactivate transitions on a consumer-supplied resolver.
- [x] **5 unit tests** on curve + progress math -- kovarex P2
  "no unit tests on framework primitives" closed.
- [x] **bbp migrations** -- `state.rs` deleted; `tracker / world_loader
  / xp / apply / skills / debug` all consume ueforge directly.

**Phase 3 second wave (DONE 2026-05-10):**

- [x] **`ueforge::rpg::Skill<E>` + `find_skill`** (audit row 41)
  -- generic catalog row parameterized on the game's effect
  enum. `bbp::Skill = ueforge::rpg::Skill<SkillEffect>` type
  alias; bbp's CATALOG is now `&'static [Skill<SkillEffect>]`.
  Lives at `ueforge/src/rpg/skill.rs` with 2 unit tests.
- [x] **`ueforge::rpg::RpgApplier` trait + `Tracker<A>`** (audit
  row 48) -- the seam where ueforge's state/persistence layer
  meets the game's apply dispatch. Trait method signatures:
  `apply_skill(&self, state, skill)`, `apply_all`,
  `format_effect`. `Tracker<A>` owns slot binding, in-memory
  state, Applier instance, persistence, spend/refund/record_xp/
  reapply transactionally with disk save. bbp's `tracker.rs`
  shrunk to a thin shim over `static TRACKER: Tracker<GameApplier>`.
  Lives at `ueforge/src/rpg/applier.rs` and
  `ueforge/src/rpg/tracker.rs`.
- [x] **`ueforge::rpg::tab::render`** (audit row 49) -- ImGui
  template: header (level + XP bar + skill points), catalog
  rows (+1/+10/-1/-10/optional on-toggle), debug footer. Takes
  `&'static Tracker<A>` + optional `&ToggleFns` for the
  on/off column. bbp's `tab.rs` shrunk to a counter-bumping
  wrapper around `ueforge::rpg::tab::render`. Lives at
  `ueforge/src/rpg/tab.rs`.

After this wave, bbp's `rpg/` is purely game-specific content:
`SkillEffect` variants, CATALOG entries, `GameApplier` dispatch
arms, `format_effect` text, `xp::xp_for_creature` bestiary,
kill_hook / fall_hook trampolines. Everything else is ueforge.

Once the second wave lands, bbp's `rpg/` becomes: catalog content
(`SkillEffect` variants + CATALOG entries) + game-specific apply
match arms + kill / fall hooks. Everything else is ueforge.

## ueforge hardening (kovarex review, 2026-05-09)

End-to-end review of the framework against the 10-year / 100-user
bar. Items are ordered by criticality: P0 will crash users in the
field, P1 is silent rot or measurable resource bleed, P2 is
maintainability / future-proofing.

### P0 -- will crash users

- [x] **Address-relative freezes (kill raw-address freeze).**
  `ueforge/src/scanner.rs:415-426` writes blindly to `addr as *mut u8`
  every `1/hz` seconds with no check that the page is still mapped or
  still owned by the source object. UE recycles allocations; a
  multi-minute freeze on a stale address will fault the game. Replace
  the `freeze { addr, ... }` op with `freeze { selector, offset, type,
  value }`, resolve the selector each tick, log-and-skip on resolve
  failure. Also cache + recheck `VirtualQuery` page protection before
  every write.
- [x] **Mutex `unwrap()` density + `panic = "abort"` = hard crash on any
  poison.** `ueforge/src/scanner.rs:267,290,371,391,407,428,443,454`
  and `ueforge/src/hook/process_event.rs:109,117,136`. With
  `Cargo.toml:30 panic = "abort"`, one poisoned mutex on a worker
  thread aborts the game DLL with no log. Migrate to
  `parking_lot::Mutex` (no poison concept) across the framework. Also
  set `[profile.dev] panic = "unwind"` so research crashes leave a
  backtrace.
- [x] **`runtime().expect("sdk runtime not initialized")` on hot paths.**
  `ueforge/src/ue/uobject.rs:399`. Called from `UObject::name`,
  `process_event`, `iter_native_properties`, name resolution -- any
  of which can fire before `init_runtime` has set the OnceLock if a
  hook lands early. Replace consumer call sites with `try_runtime`
  + log-and-skip. Document the init ordering at the top of `ue/mod.rs`.

### P1 -- silent rot / resource bleed

- [x] **`FString` buffer leak on every FName -> String.**
  Capped via FName-keyed string cache in `NameResolver`. Each unique
  FName leaks one buffer, bounded by the game's name pool. Full
  `FMemory::Free` binding still available as future work.
- [~] **OLD bullet text below kept for traceability:**
  `ueforge/src/ue/fstring.rs:1-10` documents the leak. Every
  `find_class_fast`, `find_by_short_name`, `UObject::name`,
  `full_name`, `is_default_object` leaks ~`2 * len` bytes per call.
  Long sessions bleed MB. Bind UE4SS-exported `FMemory::Free` (already
  in `UE4SS.lib`) or call `delete[]` from a tiny helper compiled into
  `ueforge_ui.cpp`, and free the buffer in `FString`'s drop / after
  `as_string()`.
- [x] **`find_class_fast` cache.** Hits cached on first resolve; misses
  re-walk so a later call after the class loads still finds it.
  (`find_by_short_name` is a separate concern -- DataTable lookups by
  short name still walk; that's lower-impact since DTs resolve once at
  init in the on_first_sight pattern. Track separately if it shows up.)
- [ ] **`find_by_short_name` (DataTable) cache.** Same shape as the
  class cache; do when actually a hot path.
  `ueforge/src/ue/uobject.rs:424-440`,
  `ueforge/src/ue/datatable.rs:263-285`,
  `ueforge/src/selector.rs:59-81`. ~150K objects on OWS; every selector
  resolve walks the full array and calls `name()` (which leaks an
  FString -- see above). Add a lazy FName-keyed
  `OnceLock<HashMap<u64, &'static UClass>>` cache; UClasses are stable
  forever once seen.
- [x] **`inspect_address` allocates a `Vec<NativeProperty>` per
  super-class per call.** UClass now exposes `cached_native_properties`
  returning `Arc<[NativeProperty]>`; `locate_property` uses it. `ueforge/src/ue/uobject.rs:181-216` +
  `ueforge/src/ops.rs:206-229`. Click 20 rows in the Scanner UI =
  100-300 heap allocs and FName resolves on the render thread.
  Cache the property list per UClass in
  `OnceLock<HashMap<*const UClass, Arc<[NativeProperty]>>>`.
- [x] **`read_bytes` / `write_bytes` have no bounds vs the resolved
  object.** `ueforge/src/ops.rs:90-134`. The 1MiB cap bounds size,
  not location -- a malformed selector + offset reads from any
  address. When the class is known, clamp `offset + length <=
  class.properties_size()`.
- [ ] **PE hook trampoline does linear search per dispatch.**
  `ueforge/src/hook/process_event.rs:155-158`. Engine fires
  ProcessEvent thousands of times per second; the `.find()` over
  `SNAPSHOT` is fine for 2-3 hooks, measurable at 6+. Index by
  vtable pointer.
- [x] **Replace hand-rolled `SNAPSHOT` + `Box::leak` with
  `arc_swap::ArcSwap`.** `ueforge/src/hook/process_event.rs:46-64`.
  Each install/drop leaks a previous snapshot; standard answer is
  one well-tested crate. ~5 lines vs ~30, no leak.
- [x] **Stop panicking in test client / perf log.**
  `ueforge/src/client/perf.rs:83`,
  `ueforge/src/client/mod.rs:90,108,110`. A library shouldn't
  `panic!` on POST or file-open failure -- return `Result`. Test
  callers can `.unwrap()` themselves.
- [x] **`tmap::slots` / `MAX_LINEAR_SCAN = 8192` magic cap.**
  `ueforge/src/ue/tmap.rs:40-45`,
  `ueforge/src/ue/offsets.rs:157`. Real-game DataTables can exceed
  8192 rows; the iterator silently truncates. Either lift the cap
  and trust the engine header, or surface a "truncated" flag.
- [x] **Long scans hold `SESSIONS` mutex across the walk.**
  `ueforge/src/scanner.rs:264-273`. Multi-second scans block every
  other scanner op behind the listener thread. Take the snapshot
  of regions outside the lock; only re-acquire to insert the
  finished session.

### P2 -- future-proofing / maintainability

- [ ] **No unit tests on framework primitives.** Hex codec
  (`hex.rs`), arg parsers (`args.rs`), `Val::from_json`
  (`scanner.rs`), `tmap::slots` parsing, `FieldTweak` idempotency,
  queue drain stats / re-entrance. The TDD doctrine in
  `ueforge/README.md` is aspirational; the framework itself has zero
  `#[test]`. Land the obvious round-trip + boundary tests.
- [ ] **UE-version-aware offset tables.** `ueforge/src/ue/offsets.rs`
  `ffield`, `fproperty`, `ustruct` constants are hardcoded for UE
  5.4. UE 5.5/5.6 are shipping; the property walker will return
  *wrong* names silently on those builds. Add `enum UeVersion` on
  `PlatformOffsets` and dispatch.
- [ ] **`#[non_exhaustive]` on public structs.** `ModInfo`, `Tab`,
  `PlatformOffsets`, `server::Config`. Today, adding a field is a
  breaking change for every downstream mod.
- [ ] **`FName` `transmute_copy<u64>` assumes layout forever.**
  `ueforge/src/ops.rs:194`,
  `ueforge/src/ue/datatable.rs:39`. UE has changed FName before;
  document or guard.
- [ ] **Replace hand-rolled hex codec with the `hex` crate.**
  `ueforge/src/hex.rs`. ~30 lines saved; one less surface for bugs.
- [ ] **Op latency + scan duration metrics.** `counters.rs` already
  ships the primitives; nothing in the framework uses them. Add
  per-op time + queue depth counters.
- [ ] **Cancellation token on `scan_memory` / long ops.** No way to
  cancel a multi-second scan today -- it monopolizes the listener
  thread.
- [ ] **`DLL_HMODULE` happens-before `dll_dir()` callers.**
  `ueforge/src/log.rs:62-63`. Worker threads that start before
  `set_dll_module` runs in `DllMain` see `dll_dir() = None` and the
  log file lands in CWD. Document the ordering, or guard with a
  one-shot wait.
- [ ] **Plan a `tiny_http` / `ureq 2` migration window.** Both are
  on a 2-5 year support horizon. `ureq 3` is already a rewrite. Not
  urgent, but pin a quarter to do it before the upstream drops
  security fixes for v2.

## ueforge hardening (kovarex review, 2026-05-10)

Second pass focused on `ueforge::rpg` and the framework-as-save-game
lens. The 2026-05-09 list closed nearly every P0/P1; these are the
items that pass missed because they treat ueforge as a mod, not as
a durable library.

### P0 -- durability / crash

- [ ] **`SlotStore::save` swallows IO errors.**
  `ueforge/src/rpg/store.rs:65-70`. Logs and returns `()`; caller
  thinks the save succeeded. Player closes the game, points vanish.
  Return `io::Result<()>`, propagate to the caller, surface the
  most-recent save error in the snapshot so tests assert on it.
- [ ] **`save_atomic` skips fsync.** `ueforge/src/rpg/store.rs:73-83`.
  `temp + rename` without `File::sync_all()` on the temp before
  rename leaves a torn / zero-byte file on power loss. The whole
  point of atomic rename is durability; we ship half of it. ~3 LoC.
- [ ] **`SlotPoller` thread leaks for life of process; no shutdown.**
  `ueforge/src/rpg/poller.rs:32-65`. `on_shutdown` exists in
  `ModInfo`; nothing tells the poller. Hot-reload (roadmap "Hot-reload
  the DLL") will detach the thread and orphan a closure pointing into
  the unloaded DLL -- crash, not leak. Wire an `Arc<AtomicBool>` stop
  flag and join on shutdown.
- [ ] **`SkillsState::spend` / `refund` is not transactional with
  persistence.** `ueforge/src/rpg/state.rs:41-63`. Mutates in memory;
  caller must remember to call `SlotStore::save`. One missed call
  site = a player loses points on crash. Either bind them
  (`SkillsTracker<S>` owns both, `spend()` saves), or rename to
  `spend_uncommitted` so the API screams.

### P1 -- silent rot / observability

- [ ] **`SlotPoller` swallows worker-thread panics silently.**
  `ueforge/src/rpg/poller.rs:74-78`. `catch_unwind` discards the
  payload; thread exits; slot tracking dies for the rest of the
  session with no signal. Log the panic message + bump a counter +
  surface in snapshot.
- [ ] **`SlotPoller` worker thread has no name.**
  `ueforge/src/rpg/poller.rs:48-55`. `CreateThread` raw, no
  `SetThreadDescription`. Crash dumps in a 10-year deployment will
  show `Thread 7: ?? @ 0x...`. Name every thread spawned in
  ueforge -- poller, server, scanner, datatable worker.
- [ ] **`DisabledSkills` takes a mutex on every read.**
  `ueforge/src/rpg/disabled.rs:25-31`. ImGui tab calls `is_disabled`
  per skill row per frame; apply walks call it per CDO. Read-mostly
  set; switch to `ArcSwap<Arc<HashSet<&'static str>>>` so reads are
  lock-free (same trick the PE hook snapshot already uses).
- [ ] **`Curve::level_for_xp` is O(max_level) per call, no upper
  guard.** `ueforge/src/rpg/xp.rs:35-42`. Fine for 50; if a
  downstream sets `max_level = 10_000` (we advertise "any UE game"),
  every snapshot walks 10k levels. Either binary-search or assert
  `max_level <= 1024` in `Curve::new`.
- [ ] **`SlotStore` slot path is unvalidated.**
  `ueforge/src/rpg/store.rs:32-37`. Slot is a user-controlled string
  passed to `PathBuf::push`. `..\..\..\windows\system32\foo.json`
  gets opened. Reject path separators / leading dots in `path()`.
- [ ] **No coverage on `SlotStore` IO failure paths.** Disk full,
  permission denied, rename across volumes, partial write -- the
  thing whose entire job is durability has zero failure-injection
  tests. Use `tempfile` + permission flips + read-only-FS injection.

### P2 -- future-proofing

- [ ] **No `schema_version` field on `SkillsState` JSON.**
  `ueforge/src/rpg/state.rs:15-31`. `#[serde(default)]` everywhere,
  no version sentinel. In three years when `xp` becomes `u128` or
  `skill_levels` becomes a struct, no migration hook. Add
  `schema_version: u32` now (default `1`).
- [ ] **`SkillsState::skill_levels` allocates on every spend.**
  `ueforge/src/rpg/state.rs:49`. `skill_id.to_string()` per spend.
  Catalog uses `&'static str` IDs everywhere else; the persisted
  layer is the one place we pay heap on the hot path. Either
  `BTreeMap<Cow<'static, str>, u32>` or document why the JSON
  boundary forces it.
- [ ] **HTTP server has no auth.** `ueforge::server::spawn` binds
  127.0.0.1; that's enough on a single-user box, but the framework
  markets itself as a research surface -- raw `write_bytes` /
  `read_bytes` to arbitrary memory. Anything else listening on
  localhost (browser ext, misconfigured proxy) can corrupt game
  memory. Generate a per-launch token, require it in a request
  header. ~20 LoC.
- [ ] **`PlatformOffsets` has no UE-version sentinel.** Already in
  the 2026-05-09 list under offsets-by-version, but raise the
  priority -- next UE bump silently corrupts property walks.
- [ ] **No `static_assert` on `mem::size_of::<FName>() == 8`.**
  `transmute_copy::<_, u64>` is a runtime-silent corruption when UE
  changes layout. One line of `const _: () = assert!(...)`.
- [ ] **`process_event_idx: 0x4C` is hardcoded.** Engine-stable in
  UE 5.x. Was different in 4.x. Will be different in 6.x. Make it
  required, not assumed -- remove the default.
- [ ] **No fuzz / property tests on the load-bearing walkers.**
  `TArray` / `TMap` / `FieldTweak` / `inspect_address` /
  `Val::from_json`. These read raw memory under user-configurable
  offsets. A dumb fuzzer with arbitrary `&[u8]` + bad offsets would
  have caught two of last week's open P1s. Lift the bytes-as-input
  shape into `cargo-fuzz` or `proptest`.
- [ ] **`UE4SS.lib` symbol-presence check.** Bootstrap doc covers
  manual regen (`ueforge/README.md:168-191`). Nothing automates a
  build-time check that the symbols we link still exist in the
  installed UE4SS.dll. Will fail-load three years from now and
  nobody on the team will remember why. Add a `build.rs` step that
  parses `dumpbin /exports` and asserts on the ~10 symbols we use.
- [ ] **DEFER Phase 3 wave 2 promotions until a second consumer
  needs them.** `Catalog<E>`, `apply_skill` dispatcher, `rpg::tab::
  render` (todo.md:58-69) are designed off ONE consumer (bbp).
  Generic abstractions designed off one consumer fit one consumer.
  Lock the shape too early and we ship a generic that nobody else
  uses. Wait until ows-tweaks or a third game asks before designing
  the API.

## ueforge: bbp dedup plan (sequenced, 2026-05-10)

Phase 1 smoke-tested in-game and passed. Next round of dedup is
ordered into five waves; each step lands an `ueforge::` symbol +
unit tests, migrates one bbp consumer, deletes the bbp duplicate,
verifies build-clean. ~6-8 sessions total.

**Order recap (start at A1):**

1. **A1** `ueforge::ue::ClassRef`
2. **A2** `ueforge::hook::function_table!` decl-macro
3. **A3** `ueforge::ue::TypedField<T>`
4. **A4** `ueforge::rpg::VanillaCache<K, V>`
5. **B1** `SlotStore::save -> io::Result<()>` + `fsync`
6. **B2** `SlotPoller::Handle` + shutdown-on-`on_shutdown`
7. **B3** `ueforge::rpg::SkillsTracker<S>`
8. **C1** `ueforge::counters::hook_counters!` decl-macro
9. **C2** `ueforge::ue::wait_for_class(name, RetryPolicy)`
10. **D1** `ueforge/PERFORMANCE.md` doctrine lift
11. **D2** `ueforge/RESEARCH.md` methodology lift

Waves E1/E2 (global ProcessEvent pre-callback,
`AddUObjectCreateListener`) land on demand. Phase 3 wave 2 RPG
promotions (`Catalog<E>`, `apply_skill` dispatcher shape,
`rpg::tab::render`) stay deferred until a second consumer exists
(kovarex rule: don't lock abstractions off one consumer).

### Wave A -- Pure helpers, no UE4SS shim work

- [x] **A1. `ueforge::ue::ClassRef`** -- typed cached class handle.
  `ClassRef::new("WBP_Foo")` -> lazy `&'static UClass`, exposes
  `cdo()`, `find_function("Bar")`, `with_cdo`, `with_first_instance`,
  `for_each_instance`, `find_instance`. Lives at
  `ueforge/src/ue/class_ref.rs`. 3 unit tests cover
  unresolved/name-round-trip/const-constructible. Migrations:
  `bbp/rpg/save_slot.rs::find_in_game_game_state`,
  `bbp/rpg/kill_hook.rs::install` (HEALTH + SURVIVAL_CREATURE),
  `bbp/inv_hook.rs::install` (INV_IFACE + PANEL_WIDGET + BPF_INV +
  KISMET), `bbp/debug.rs` (HEALTH_CLASS used by exec_add_health /
  exec_apply_damage / exec_set_current_health). Workspace builds
  clean release; ueforge tests green (8 passing). In-game smoke
  test pending.
- [x] **A2. `ueforge::function_table!` decl-macro** -- struct-of-`usize`
  table with `install(&UClass) -> Result<Self, &'static str>`.
  `required` slots return `Err(<fn-name>)` if missing; `optional`
  slots land as `0`. Lives at `ueforge/src/hook/function_table.rs`,
  re-exported at crate root. 2 unit tests exercise expansion +
  CLASS_NAME const. Migrations: `bbp/inv_hook.rs::InvIfaceFns` (11
  fns) and `PanelFns` (2 fns). `BpfFns` / `KismetInputFns` kept
  hand-rolled (1 fn + 1 CDO each, below the macro ROI threshold).
  ~58 LoC dropped from bbp; release workspace builds clean.
  In-game smoke test pending.
- [x] **A3. `ueforge::ue::TypedField<T>`** -- `const`-constructible
  `(offset, T)` pair with `read(obj)` / `write(obj, v)` / `ptr(obj)`.
  Couples offset and type at declaration so accidental type
  mismatches between `static` decl and call site become impossible
  (different `TypedField<T>` types). Lives at
  `ueforge/src/ue/typed_field.rs`. 3 unit tests. Made
  `UObject::read_field` public so the wrapper can call it. Demo
  migration: `kill_hook::HC_CURRENT_DAMAGE` replaces 5 `field_ptr +
  cast + read_unaligned` sites. Workspace builds clean. Larger
  conversions in `apply.rs` / `fall_hook.rs` land opportunistically
  -- the surface is available; existing helpers
  (`read_f32`/`write_f32`/etc.) keep working unchanged.
  In-game smoke test pending.
- [x] **A4. `ueforge::rpg::VanillaCache<K, V>`** -- per-key
  baseline cache. `get_or_init(k, v)` returns the captured baseline
  forever (first-write wins); `set_if_unset(k, v)` returns insert
  flag; `get(k)`, `clear()`, `snapshot()`. `parking_lot::Mutex`
  internally (no poison). Lives at
  `ueforge/src/rpg/vanilla.rs`. 7 unit tests. Migrations:
  `bbp/rpg/apply.rs::VanillaTable` deleted (struct + 2 methods);
  `MOVEMENT_VANILLA`, `GLOBAL_DATA_VANILLA`, `VANILLA_HC_U32_MASK`
  all flipped to `ueforge::rpg::VanillaCache`. Single-baseline
  `OnceLock<f32>` statics (`VANILLA_HUNGER`, `VANILLA_THIRST`, etc.)
  stay -- already canonical via std and the keyed shape isn't a
  fit. Closes audit row 48 partially -- the *cache shape*; the
  dispatcher shape stays game-side per kovarex deferred-promotion
  rule. Workspace builds clean release. In-game smoke test pending.

### Wave B -- RPG durability (kovarex P0s)

- [ ] **B1. `SlotStore::save -> io::Result<()>` + `fsync` on temp
  before rename.** `ueforge/src/rpg/store.rs:65-83`. Surface
  most-recent error in snapshot via counter or
  `RwLock<Option<String>>`. **Acceptance:** integration test that
  fills a temp dir, attempts save, asserts error surfaces; happy
  path unchanged.
- [ ] **B2. `SlotPoller::Handle` + shutdown-on-`on_shutdown`.**
  `ueforge/src/rpg/poller.rs:32-65`. Replace `CreateThread` + leaked
  `Cfg` with thread that owns `Arc<AtomicBool>` stop flag + join
  handle. Name the thread (`SetThreadDescription`). Wire
  `bbp::on_shutdown` to call stop. Catch panics with logged message
  + counter bump. **Acceptance:** mod unloads cleanly; no orphan
  thread; panic in resolver logs instead of silently dying.
- [ ] **B3. `ueforge::rpg::SkillsTracker<S>`** that owns
  `SkillsState` + `SlotStore<S>`. `spend/refund/record_xp` methods
  mutate state AND call `store.save()` transactionally; return
  `Result`. bbp's `tracker.rs` shrinks to a thin wrapper.
  **Acceptance:** every spend persists; crash mid-session no longer
  loses the latest point.

### Wave C+++++ -- ueforge::ue::core_types (DONE 2026-05-10)

- [x] **`ueforge::ue::core_types`** module with `FGuid`,
  `FWeakObjectPtr`, `FDataTableRowHandle`, `EStatusEffectValueType`.
  UE-stable POD layouts every UE5 mod redefines locally; ship
  them once. 6 unit tests including size invariants. Migrations:
  bbp's `save_slot::FGuid` and `kill_hook::FWeakObjectPtr` local
  duplicates deleted -- now both consume `ueforge::ue::*`.
  `FDataTableRowHandle` and `EStatusEffectValueType` ready for
  the bbp status-effect migration.

### Wave C++++ -- DrainSite (DONE 2026-05-10)

- [x] **`ueforge::pe_queue::DrainSite`** -- `Queue` paired with
  the standard performance-counter quad (drain calls, drained
  cmds, peak depth, time_ns spent draining). One static replaces
  bbp's static `Queue` + 4 hand-declared `counter!` statics +
  the 20-LoC `drain_pending` wrapper. Counters surfaced via
  `drain_calls()` / `drained_cmds()` / `peak()` / `time_ns()`
  accessors. bbp's `drain_pending` is now a one-liner.

### Wave C+++ -- ueforge::ue::PlayerRef (DONE 2026-05-10)

- [x] **`ueforge::ue::PlayerRef`** -- canonical "find the player"
  surface for any UE5 mod. Configured once at module init with
  `(base_class_name, Option<bp_name_filter>)`; static methods
  `for_each_cdo` / `for_each_live` / `with_first_live` /
  `with_first_cdo` do the GObjects walk + filter. Replaces bbp's
  `CLASS_SURVIVAL_CHARACTER` + `PLAYER_BP_NAME` const pair with
  one cohesive abstraction. Lives at
  `ueforge/src/ue/player.rs`. 3 unit tests.

### Wave C++ -- EventRing<T> with built-in counters (DONE 2026-05-10)

- [x] **`ueforge::ring::EventRing<T>`** -- `Ring<T>` paired with
  built-in push counter (`AtomicU64`) and peak high-watermark
  (`AtomicUsize`). `record(item)` bumps both atomics, then pushes.
  Replaces the bbp boilerplate of pairing every Ring with two
  separate `counter!`-declared statics + a custom `record_*`
  wrapper. Migrated `bbp::debug::DAMAGE_RING` to `EventRing`;
  `record_damage_event` is now a one-liner.

### Wave C+ -- ClassRef walker family expansion (DONE 2026-05-10)

- [x] **`ClassRef::for_each_matching(pred, f)`** -- non-CDO walk
  filtered by a `&UObject -> bool` predicate. Replaces bbp's
  `apply_to_live_player_characters` (10 LoC -> 4 LoC).
- [x] **`ClassRef::for_each_cdo_subclass(f)`** -- walk every CDO
  matching `is_a(self)` (CDO of class + CDOs of subclasses).
  Replaces bbp's `apply_to_survival_component_cdos` walker.
- [x] **`ClassRef::for_each_cdo_matching(pred, f)`** -- predicate
  variant for "CDO whose full_name contains substring" patterns.
  Replaces bbp's `apply_to_player_character_cdos` walker.
- [x] **`ClassRef::for_each_any(f)`** -- walks both CDOs and
  non-CDOs matching `is_a(self)`. Used for singleton-style data
  assets (`UGlobalCombatData`, `USurvivalGameModeSettings`).
- [x] **`ClassRef::new_dynamic(name)`** -- runtime constructor
  that takes `&str`, leaks one heap copy. Cold path; for the
  rare apply call where the class name is computed.
- [x] **`TypedField::deref()`** specialized for
  `TypedField<*mut UObject>` -- typed component-pointer follow,
  closes the `obj.field_ptr(off).cast::<*mut UObject>().read_unaligned()`
  pattern.

bbp's `apply.rs` walker block went from ~120 LoC of GObjects-walk
boilerplate to ~30 LoC of one-liner ClassRef calls.

### Wave C -- Hook ergonomics + worker plumbing (DONE 2026-05-10)

- [x] **C1. `ueforge::counter_json!` decl-macro.** Pairs of
  `(static_ident => "json_key")` collapsed into a
  `serde_json::Value::Object` with `load(Relaxed)` per counter.
  Centralizes the `load` + `Ordering` discipline. Lives next to
  the existing `counter!` / `peak!` macros in `ueforge/src/
  counters.rs`. Migrates `bbp/counters.rs::snapshot_json` -- 22
  hand-written `.load(Ordering::Relaxed)` lines now ride the macro.
  Generic, reusable by any mod's snapshot endpoint.
- [x] **C2. `ueforge::hook::install_with_backoff` + `RetryPolicy`.**
  Generic exponential-backoff retry loop around any
  `FnMut() -> Result<H, &'static str>`. `RetryPolicy::new(base,
  max, timeout)` + `default_install()` (500ms / 5s / 10min, bbp's
  battle-tested tuning). 4 unit tests. Migrates `bbp/lib.rs::
  install_inv_hook_with_backoff` + the three `HOOK_RETRY_*` consts
  -- ~25 LoC + 3 consts dropped from bbp.
- [x] **C3. `ueforge::worker::spawn(name, FnOnce)`.** Named worker
  thread (Win32 `SetThreadDescription` via
  `thread::Builder::name`) with `catch_unwind` + logged panic
  payload. Replaces bbp's hand-rolled `CreateThread` /
  `worker_entry` / `unsafe extern "system"` plumbing. 2 unit tests.
  Closes the kovarex P1 "unnamed worker thread" + "silent panic
  swallow" findings for any future `ueforge::worker` consumer
  (poller still TODO, see Wave B2).

### Wave D -- Doctrine docs (DONE 2026-05-10)

- [x] **D1. `ueforge/PERFORMANCE.md`** -- canonical hot-path
  discipline doctrine: 10/10 bar, hot-path identification, six
  rules (zero allocs, bail early, no mutexes on empty path,
  bounded everything, install-time heavy lifting, counter every
  hot path), memory-leak vectors with named ueforge fixes,
  consume-don't-reinvent table, consumer responsibilities,
  doctrine summary. ~250 lines. Lifts everything generic from
  bbp's `docs/performance.md`; bbp's file shrinks to G2 numbers.
- [x] **D2. `ueforge/RESEARCH.md`** -- TDD investigation
  methodology for UE5 games. Headlines: research-is-code rule,
  the seven-step TDD loop, standard probes (`walk_class`,
  `read_bytes`, `inspect_address`, `call`, scanner, freeze),
  five probe types in leverage order, doctrines on status
  effects + data tables + damage paths + instigator resolution
  + install-vs-hook, snapshot-not-log validation rule,
  failure-injection-test rule, research notebook shape. ~200
  lines. Cross-references `runtime-control-http` skill +
  `PERFORMANCE.md`.

### Wave E -- Shim work (defer until pulled in)

- [ ] **E1. Global ProcessEvent pre-callback.**
  `RegisterProcessEventPreCallback` wrapper + `Queue::install_drain`
  helper. **Don't land speculatively** -- mask is gone, drain isn't
  starving today. Land when status-effect migration needs the
  guaranteed drain site.
- [ ] **E2. `AddUObjectCreateListener` integration.** **Don't land
  speculatively** -- land when ows-tweaks or bbp's CDO-revert-replay
  scenario asks. ~100 LoC of UE4SS shim glue.

### Original extraction-candidate notes (kept for reference)

The Phase 1/2/3-wave-1 promotions covered the obvious primitives.
Reviewing `better-backpack/` source against ueforge's surface
surfaces another tier of generic content -- patterns we worked out
under bbp's hood that every UE4SS Rust mod will rediscover unless
they live in ueforge. Ordered by leverage.

### Doctrine / docs

- [ ] **Hot-path discipline doctrine -> `ueforge/PERFORMANCE.md`.**
  `docs/performance.md` is bbp-titled but most of it is generic:
  zero-alloc trampolines, single-hook-surface principle, debug-only
  trace gating, identity-not-name dispatch, "what was deliberately
  not ported" pattern. Lift to a ueforge-side doc; `bbp/docs/
  performance.md` becomes the bbp-specific addendum (numbers, the
  ~123 PE/rebind figure, the SurvivalComponent CDO walk timings).
- [ ] **Root-cause-investigation playbook -> `ueforge/RESEARCH.md`.**
  `docs/damage.md` and the bandage / pkg(0) / rock-collision
  research notes encode a methodology that's framework-shaped, not
  game-shaped: snapshot baseline -> minimal repro through endpoint
  -> hypothesis as a `tests/explore_*.rs` -> probe with `walk_class`
  / `inspect_address` / `read_bytes` -> validate -> regression test.
  The skill `runtime-control-http` has the cross-project version;
  ueforge needs the UE-mod-specific concrete walk.
- [ ] **Hook-install retry/backoff doctrine.**
  `better-backpack/src/lib.rs:28-30` ships
  `HOOK_RETRY_BASE_DELAY_MS = 500`,
  `HOOK_RETRY_MAX_DELAY_MS = 5_000`, `HOOK_RETRY_TIMEOUT_SEC = 600`
  with a worker that retries `find_class_fast` until the class
  loads. Every UE4SS mod hits this -- target classes load AFTER
  `on_unreal_init`. Generic helper:
  `ueforge::ue::wait_for_class("WBP_Foo", retry_policy)
  -> Option<&UClass>`.

### Generic helpers

- [ ] **`HookIdentity` / `FunctionTable<N>`.**
  `bbp/src/inv_hook.rs::InvIfaceFns` and `PanelFns` are the same
  shape: a struct of `usize` UFunction-pointer slots, populated once
  at hook install via `find_class_fast` + `find_function`, dispatched
  by pointer identity in the trampoline. Today's
  `hook::function_ptr` returns one at a time; we want the
  table-shaped helper plus a ergonomic identity-match macro.
- [ ] **`VanillaCache<K, V>`.** Audit row 48 (todo.md:60). Every
  skill that captures a vanilla baseline does the same dance:
  `static VANILLA_X: OnceLock<f32>`, `get_or_init(|| read_field(...))`,
  later `apply(vanilla + bonus)`. `bbp/src/rpg/apply.rs:38-44`. Lift
  to `ueforge::rpg::VanillaCache<K, V>` so games stop hand-rolling
  per-field statics. Same shape as `cached_native_properties`.
- [ ] **`ClassCache<F>` -> `ClassRef`.** Generalize the cached
  `find_class_fast` pattern as a typed handle: `ClassRef::new("Name")`
  resolves once, hands back `&'static UClass` from then on, exposes
  `instances()` / `cdo()` / `find_function(...)` methods. bbp has
  this hand-rolled in 5+ places.
- [ ] **`TypedField<T>` offset wrapper.** Dozens of offset consts
  scattered across bbp (`ASC_HEALTH_COMPONENT = 0x1340`,
  `HEALTH_COMPONENT_LAST_DAMAGE_INFO = 0x03B0`, etc.).
  `TypedField::<*mut HealthComponent>::at(0x1340)` + `.read(obj)` /
  `.write(obj, v)` collapses the boilerplate, centralizes
  `read_unaligned` discipline, and gives one place to add bounds
  validation (P1 row "read_bytes / write_bytes have no bounds vs the
  resolved object").
- [ ] **`DamageRing` / structured event ring + snapshot surface.**
  `bbp/src/counters.rs::DAMAGE_RING_*` plus the not-yet-built
  `dmg-trace` ring (todo.md:769). The shape is generic: bounded ring
  of timestamped structured events, snapshot through the HTTP
  endpoint, peak-watermark counter, debug-only push. Already have
  `Ring<T>`; missing is the canonical "structured event ring you
  introspect via /debug" pattern.
- [ ] **`HookCounters` derive / decl-macro.**
  `bbp/src/counters.rs` uses `counter!(KILL_HOOK_FIRES, ...)` with
  hand-coded matching `TIME_NS_KILL_HOOK` / peak statics per hook.
  Every hook needs the same triple (fires / time-ns / alloc-count).
  Decl-macro: `hook_counters!(KILL_HOOK { fires, time_ns, allocs,
  player_fires });` expands to the static block + a typed accessor
  the trampoline uses.
- [ ] **`AddUObjectCreateListener` integration.**
  `docs/performance.md:186-193` flagged this as future work for the
  CDO-revert-replay scenario. Generic enough to live in ueforge as
  `ueforge::ue::on_class_instantiated(class, |obj| ...)`. Not yet
  needed in bbp; ows-tweaks may want it for live DataTable mutation
  protection. Land when the second use case appears.

### Ship-side

- [ ] **PE-thread queue drain helper that picks ITS OWN drain
  site.** Today bbp draws on `kill_hook` for drain (todo.md:790-809).
  Brittle when the `RequiredDamageTypeFlags` mask zeroes traffic.
  ueforge could ship `Queue::install_high_frequency_drain()` that
  hooks a guaranteed-active UFunction (`ASurvivalCharacter::
  ReceiveTick` analogue per game, fallback to UE4SS's
  `RegisterProcessEventPreCallback`). Pairs with the "Global
  ProcessEvent hook" Future infra item (todo.md:980-989).
- [ ] **Slot-key-resolver convenience for UE5.** bbp's
  `save_slot::current_slot_key` is generic-shaped: walk
  `find_class_fast(GameStateClass)`, read FGuid at offset, format.
  Most UE5 games have *something* like this; the offset varies. A
  ueforge helper that takes `(class_name, offset, field_kind)` and
  returns a closure suitable for `SlotPoller` reduces every consumer
  to a one-liner.

### What stays in the game crate

(For the audit table -- reasoning visible in case the line moves):

- Per-game offset constants (`ASC_HEALTH_COMPONENT = 0x1340`)
  remain game-side; the wrappers above just remove their
  boilerplate, not their ownership.
- `kill_hook` / `fall_hook` / `inv_hook` per-event business logic
  stays in bbp. The COUNTERS, drain pattern, identity dispatch, and
  retry doctrine come from ueforge.
- `parms.rs` `#[repr(C)]` UFunction parm layouts stay game-side.
  Per UE class, per build.

## RPG: catalog expansion

The next batch of skills to add. Each entry is one
[`skills.rs::CATALOG`](../better-backpack/src/rpg/skills.rs) row of
an existing `SkillEffect` shape (no new variants required).
Registry refactor done; adding a skill is now ~5 lines.

- [ ] **Critical Chance + Critical Damage.** `Runtime` effect
  (rolled in the kill_hook on each player-dealt hit). Multiply
  damage by 1 + crit_damage on a successful crit roll. Need a
  damage-path hook in kill_hook (see "Live damage hook" below).
- [ ] **Evasion / Dodge.** `Runtime` effect on player-taken hits.
  Roll on incoming damage, zero it out on success. Same hook
  surface as crit + lifesteal.
- [ ] **Lifesteal runtime.** Catalog entry exists; the live hook
  in kill_hook to actually heal the player by a fraction of
  damage dealt was queued behind the registry refactor. Pick up
  next: extend the existing kill_hook trampoline to also act on
  player-as-instigator events (not just KillingBlow), heal the
  player's live HealthComponent (write `CurrentDamage` at +0x32C,
  clamped at 0).
- [x] **Max Health.** Landed via new
  `SkillEffect::PlayerHealthCompAdditive` (offset +0x328). Captures
  vanilla once, writes `vanilla + max_bonus * progress` on CDOs +
  live pawn so the player stacks +HP additively. +200 HP at level
  100. Untested in-game.
- [x] **Health Regen.** Landed via new `SkillEffect::GlobalDataMult`
  pointed at `UGlobalCombatData` (offsets 0x010C tick percentage,
  0x0110 tick rate). Tick % scales with the bonus, tick rate scales
  inversely (more frequent ticks). Combat-regen delay left untouched.
  Untested in-game.
- [ ] **Leap Distance (DONE, untested).** Landed in the catalog via
  `PlayerMovementMult` over `AirControl` / `AirControlBoostMultiplier`
  / `AirControlBoostVelocityThreshold`. +500% at level 100.
  Untested in-game.
- [ ] **Auto-pickup (range).** Quality-of-life skill: the player
  automatically picks up nearby loose items (plants, fibers,
  resources on the ground) without needing to look at them and
  press E. Pickup radius scales with skill level: level 0 = 0
  (vanilla), level 100 = several meters. Open questions:
  - **Mechanism**: per-frame proximity scan that calls the
    existing PickupItem path on each eligible item, or a write
    to whatever proximity-pickup field already exists on
    ASurvivalCharacter / ItemPickupComponent? Check the SDK
    for an existing `AutoPickupRadius` or similar before adding
    a per-frame scan.
  - **Filter**: which items qualify? Open-world clutter (plant
    fibers, sap, resin) yes; equipped items / quest items / a
    just-dropped weapon a player chose to throw -- probably no.
    A blacklist on item-class or item-tag is the cheap version.
  - **Performance**: a tick that walks all loose items in N
    meters can be expensive in dense areas. Cap items-per-tick
    or sample radially from a few angles.
  - **Surface**: probably a new `Runtime` SkillEffect (no CDO
    write); kill_hook-equivalent trampoline reads the level
    each tick.
  - **Test plan**: spawn an item near the player ->
    snapshot.inventory contents before -> tick -> contents
    after. Drive via debug endpoint with new ops:
    `place_item_at_player_offset`, `read_inventory_contents`.
- [ ] **Stamina Pool + Stamina Regen.** `UStaminaComponent` on
  ASurvivalCharacter at +0x1358; offsets need a Dumper-7 dive.
- [ ] **Gear Hardiness.** Find the durability-loss-per-use field;
  per-item durability scaling. Possibly a damage-multiplier surface
  on the equipment component.
- [ ] **Thorns.** % of damage taken reflected. Same hook surface
  as evasion / lifesteal.
- [ ] **Climb Speed.** May or may not exist as a separate
  CharMovement field; check before adding.
- [ ] **Collision / Impact Damage Resistance.** New skill to
  reduce or negate the lethal self-damage from slamming into
  plants / terrain at very high movement speed. May share hook
  surface with other player-taken damage effects, but likely needs
  a specific classification path so normal enemy hits are not
  affected.

Catalog target: ~25 skills. Today: 13. War3FT had ~17, we collapse
to a flat menu so 25 is comfortable.

## RPG: live-instance writes

Some combat-side skills still write only to player CDOs.
Movement now mirrors onto the live player pawn, but the remaining
combat effects still need the same treatment so spending a point
feels immediate. Walk the live player pawn(s) on each apply and
write the same fields:

```text
World->GameState->PlayerArray[i]->PawnPrivate (APawn*)
  -> downcast to ABP_SurvivalPlayerCharacter_C*
  -> CharMovementComponent / HealthComponent / ...
  -> field at offset
```

This is the R4 follow-up that was deferred. With the registry
refactor, each `SkillEffect` variant grows a "live walk" arm
analogous to the CDO walk it already has. Movement already does
this now; combat still needs it.

## RPG: pkg(0) instigator bug

Some legitimate player kills attribute to `/Script/CoreUObject (Package)`
because `LastDamageInfo.InstigatorController` is an unset
FWeakObjectPtr (index=0 -> Package object). User loses XP for
those kills. See the Spike A section in
[`changelog.md`](changelog.md) for context.

Investigation:

1. Sample more kills with different weapons. Identify which
   attack types fail vs which succeed.
2. Hook `Maine.HealthComponent.ApplyDamageFromInfo`
   (`Maine_functions.cpp:138302`) to read the `FDamageInfo` parm
   at function entry and cache the instigator per HealthComponent.
   When `MulticastHandleEffectsWithDamageFlags` fires with
   KillingBlow, use the cached value if `LastDamageInfo` is null.
3. Failing that, fall back heuristically: if instigator is
   pkg(0) and the local player is within attack range of the
   dying actor + has swung a weapon recently, credit the player.

## RPG: live damage hook

Required by lifesteal / crit / evasion / thorns. Extend
`kill_hook`'s existing trampoline (which already runs on every
`MulticastHandleEffectsWithDamageFlags` call) to handle
non-killing hits too:

- Read `Damage` parm at +0x18.
- Classify via `LastDamageInfo.InstigatorController`:
  - Player dealt: trigger Lifesteal (heal player by `damage *
    fraction`), Critical (multiply outgoing damage on roll).
  - Player took: trigger Evasion (zero out damage on roll),
    Thorns (deal % back to attacker).

Healing path: walk the live player pawn (R4 path), follow the
HealthComponent ptr at +0x1340, decrement `CurrentDamage` at
+0x32C, clamp at 0.

This hook surface is also the likely home for collision / impact
damage mitigation. Plant / terrain collision uses
`DamageType = BP_EnvironmentalDamage_C` on `LastDamageInfo` (filterable
on the existing multicast hook), distinct from fall damage which has
its own pipeline -- see `rpg.md` for both internals.

## RPG: Impact Damage Resistance (FIXED 2026-05-09 evening)

Bug: with the previous binary mask, bandages were blocked. Now
fixed: impact_resistance is a `Runtime` effect that intercepts
`ApplyDamageFromInfo` on the player HC and scales damage by
`(1 - reduction * progress)` only when `FDamageInfo.DamageType`
is environmental. Bandages, creature combat, and fall damage are
all untouched. Per-level scaling. See `docs/damage.md` "LANDED
2026-05-09: impact_resistance is now Runtime + ApplyDamageFromInfo
intercept".



`SKILL_IMPACT_RESISTANCE` landed via a write to
`UHealthComponent.RequiredDamageTypeFlags` (+0x00FC, uint32) =
`0xFFFFFFFF` on player CDOs and the live pawn. Native ApplyDamage
gate consults the field, sees incoming `type_flags = 0` for fall /
environmental / hazard damage, no bit matches, damage rejected
before `CurrentDamage` is written. Validated in-game: rock
collision multicasts report `damage=0.00`.

**Caveat: the gate is binary.** Any level > 0 = full immunity,
level 0 = full damage. Does not scale on the `sqrt(level/100)`
curve the rest of the catalog uses. Migration to the proper
mechanism (status effects) tracked below.

## Status-effect migration: row inventory verified (2026-05-09)

Discovery test (`tests/explore_status_effect_rows.rs`) confirmed
every `EStatusEffectType` we need exists in `Table_StatusEffects`
with multiple candidate rows. Counts:

| Type | Name | Rows | Skill that wants it |
| ---- | ---- | ---- | ------------------- |
| 5    | MaxHealth | 18 | max_health |
| 14   | FallDamage | 7  | impact_resistance, fall_resistance |
| 23   | AttackDamage | 168 | attack_damage |
| 24   | Health | 116 | health_regen, AddHealth-equivalents |
| 29   | DamageReduction | 157 | armor |
| 30   | DamageReductionMultiplier | 4 | impact_resistance alt |
| 38   | LifeSteal | 11 | lifesteal |

We don't need to inject new rows; we'll reuse an existing one
per stat (mutating its `Value` at apply time before calling
`CreateAndAddEffect`).

Concrete next steps to land the fix:

- [ ] Optimize the discovery test: batch read_bytes (one big
  chunk) so it runs in seconds not minutes; capture FName for
  each row.
- [ ] Pick target row per stat type (lowest-impact / most-clearly-
  reservable name for our mod).
- [ ] Implement `SkillEffect::PlayerStatusEffect { row_name,
  base_value, max_value, ... }` variant in `skills.rs`.
- [ ] One generic apply arm in `apply.rs` that:
   1. Resolves Table_StatusEffects.
   2. Looks up the row by FName.
   3. Mutates the row's Value field to (max_value * progress).
   4. Calls `UStatusEffectComponent::CreateAndAddEffect` on the
      player's component with the row handle.
   5. On disable / level=0: removes the effect (or sets
      Value=0 then re-adds).
- [ ] Migrate `impact_resistance` first as proof of concept.
- [ ] Validate via the regression test: bandages must heal even
  with impact_resistance enabled. That's the bug fix.
- [ ] Migrate the rest of the catalog row-by-row.

## RPG: bandage HoT teaches us the canonical heal pattern (2026-05-09)

Research traced bandages to a status effect `BandageHoTTier1`:
`Type = EStatusEffectType::Health (24)`, `Value = 1.25` per tick,
modulated by `HealingReceived = 57` (1.15) for ~1.44 HP per
~250ms tick over ~3.5 seconds. Native code applies the HP gain
via the same pipeline that consults `RequiredDamageTypeFlags` --
which is why our binary mask blocks bandages.

This is the canonical Grounded 2 heal mechanism. Every skill we
add that grants HP should ride the same surface (apply a
`UStatusEffect` with `Type=Health` for HoT, `Type=MaxHealth=5`
for raw cap bumps, etc.) instead of poking native fields
directly. Beneficial side-effects: HealingReceived multipliers
auto-apply, gear/perk synergy works, multiplayer replication is
correct, no singleton-asset mutation.

**Concrete refactors** (each becomes a one-skill migration once
the status-effect apply path lands):

- [ ] `health_regen`: stop mutating `UGlobalCombatData`; apply a
  `UStatusEffect{Type=Health, Value=scaled_per_tick}` per slot
  activation, refreshed periodically. Detail in
  `docs/damage.md` "Reuse the same pattern for our health_regen
  skill".
- [ ] `max_health`: stop direct-writing `HC.MaxHealth`; apply
  `Type=MaxHealth (5)` status effect.
- [ ] `impact_resistance`: stop the binary
  `RequiredDamageTypeFlags = 0xFFFFFFFF`; apply
  `Type=DamageReductionMultiplier (30)` or `FallDamage (14)`.
  This is the bug-fix migration -- bandages stop being blocked
  the moment this lands.
- [ ] `lifesteal`: kill the runtime no-op; apply
  `Type=LifeSteal (38)`.
- [ ] `attack_damage`: stop direct-writing
  `ASC.CustomDamageMultiplier`; apply `Type=AttackDamage (23)`.
- [ ] `armor`: stop direct-writing `HC.BaseDamageReduction`;
  apply `Type=DamageReduction (29)` or
  `DamageReductionMultiplier (30)`.
- [ ] `fall_resistance`: keep the velocity-stomp (it's the
  validated mechanism); ALSO apply `Type=FallDamage (14)` for
  consistency and so the value is visible to anything that
  introspects player stats.

Movement skills (`move_speed`, `jump_height`, `glide_speed`,
`leap_distance`) stay on direct CMC field writes -- the
status-effect surface doesn't expose movement-component
parameters with the granularity we use.

Survival drains (`hunger`, `thirst`) similarly stay on the
SurvivalComponent CDO writes -- the status effect types
`HungerRate (17)` and `ThirstRate (18)` exist and could be used,
but the CDO write is simpler and battle-tested. Optional later
parity if convenient.

## RPG: Status-effect-backed skill rewrite (IN PROGRESS -- A1)

**Active work.** Migrating Impact Damage Resistance and Lifesteal
to the canonical status-effect surface first; the rest of the
catalog migrates after that pattern lands and is validated.



The canonical Grounded 2 surface for proportional, type-filtered,
stackable damage modifiers is `UStatusEffectComponent` on
`ASurvivalCharacter` at +0x1378. Native damage code calls
`GetValueForStatForDamageTypeFlags(StatType, Flags)` on every
damage event and uses the returned float as a multiplier. Every
skill in our catalog has a matching `EStatusEffectType` enum
value. See [`docs/damage.md`](damage.md) "Status Effect system"
for the full reference.

Migration plan:

1. **Locate `UStatusEffect` field layout** -- need offsets for the
   stat type field (`EStatusEffectType`) and the value float. Walk
   any default status effect on a live actor at runtime to derive.
2. **Add `SkillEffect::PlayerStatusEffect { stat_type, max_value,
   format }`** variant in `skills.rs`.
3. **`apply.rs` walks the live player `StatusEffectComponent`**,
   finds or creates a `UStatusEffect` for the given stat type, sets
   its value to `max_value * sqrt(level / 100)`.
4. **Migrate skills one at a time:**
   - `fall_resistance` -> `EStatusEffectType::FallDamage` (= 14)
   - `impact_resistance` -> `EStatusEffectType::DamageReductionMultiplier`
     (= 30) filtered by `type_flags = 0` (or use the same FallDamage
     entry if it covers all impact paths)
   - `lifesteal` -> `EStatusEffectType::LifeSteal` (= 38), removing
     the `Runtime` no-op
   - `armor` -> `EStatusEffectType::DamageReduction` (= 29) or
     `DamageReductionMultiplier` (= 30), removing the
     `BaseDamageReduction` write
   - `attack_damage` -> `EStatusEffectType::AttackDamage` (= 23),
     removing the `CustomDamageMultiplier` write
   - Future: crit (`CriticalHitChance` = 31, `CriticalDamage` =
     62), thorns (`ReflectDamage` = 37), max health
     (`MaxHealth` = 5), stun resist, etc.
5. **Remove the interim hacks** once each skill is migrated:
   `RequiredDamageTypeFlags` write from `apply.rs`, velocity-stomp
   from `fall_hook.rs`, the `Runtime` no-op for Lifesteal.

### Status-effect implementation choice (next decision point)

`UStatusEffect` is row-driven: it holds a `FDataTableRowHandle` at
+0x58 and reads `Type` / `Value` / etc. from the row each time the
component is queried. We cannot just allocate one and set its
value -- value is determined by the row. Implementation paths
(detail in `docs/damage.md` "UStatusEffect is row-driven"):

1. **Mutate an existing data-table row's `Value` field at runtime,
   then `CreateAndAddEffect(rowHandle)`**. Cheapest. Risk: row is
   shared, vanilla mods/items using the same row are affected.
2. **Find a benign / unused row to repurpose**. Same as (1) with
   smaller blast radius if such a row exists in the data tables.
3. **Inject a brand-new row into the `UDataTable`'s row map**.
   Most invasive, also most stable -- no collision with vanilla.
4. **Manual `UStatusEffect` subclass with overridden getters**.
   Heaviest; UE class manipulation at runtime.

**Validation done.** Probe ran in-game, returning both runtime
values and combine semantics (`/add` or `/mul`) per stat:

```
FallDamage(14)=1.000/mul        DamageReduction(29)=1.000/mul
DamageReductionMultiplier(30)=0.000/add
AttackDamage(23)=1.210/mul      LifeSteal(38)=0.000/add
CriticalHitChance(31)=0.060/add CriticalDamage(62)=0.000/add
ReflectDamage(37)=0.000/add     MaxHealth(5)=30.000/add
```

`EStatusEffectValueType` is `{None=0, Add=1, Multiply=2}`. Vanilla
baseline is `1.0` for `mul` stats and `0.0` for `add` stats. Per-stat
write formulas are in `docs/damage.md` "Stat semantics table".

**Vanilla data table identified.** Probe of the player's
StatusEffects array shows every status effect in the game flows
through `/Game/Blueprints/Attacks/Table_StatusEffects.Table_StatusEffects`.
~10 active rows visible on a mid-game player (PlayerUpgradeHealth1,
WeaponClub, MaxHealthSmall, etc., per `damage.md` "Vanilla data
table identified").

**Concrete next step: implement the apply step.** Plan in
`damage.md` "Implementation plan":

1. Resolve `Table_StatusEffects` (follow any existing row handle
   on the player; no GObjects scan needed).
2. Enumerate rows via `UDataTableFunctionLibrary::GetDataTableRowNames`
   + `GetDataTableRowFromName`, find or pick a row per skill's
   target stat.
3. Mutate the row's `Value` to skill-scaled value, build a row
   handle, call `CreateAndAddEffect` on the player's
   `UStatusEffectComponent` via `process_event`.
4. On level change, rewrite Value. On slot deactivate, RemoveEffect.

Migrate one skill first as a proof of concept --
`fall_resistance` is the lowest-risk because we already have the
velocity-stomp as a fallback if anything misbehaves. If the
status-effect contribution drives `FallDamage` from `1.0` toward
`0.0` and we observe reduced damage in the multicast trace, the
pattern is proven and the rest of the catalog follows.

## RPG: tuning

Open until we play more.

- XP curve: is `100 * N^1.8` (cap 50) too steep / too flat?
- Per-creature XP table: today ~20 species with placeholder
  values. Expand and balance.
- Skill `max_bonus` per skill: are the level-100 caps right?
  Backpack +460 slots feels right; Attack Damage / Move Speed /
  Jump Height / Glide Speed now all cap at +300%, Fall Damage
  Resistance at 100%, Lifesteal at 90%. Validate those against
  real play.
- Level-up frequency vs catalog size: 50 levels = 50 points,
  catalog max-everything = ~225 points (9 skills * 25 avg).
  Roughly 22% of catalog at max level. Too generous? Too tight?
  Tune.

## Distribution

- [ ] **Vortex / Nexus packaging.** `deploy.ps1`'s
  `-Package` mode produces a Vortex-installable zip with the
  right `Augusta/Binaries/WinGRTS/ue4ss/Mods/BetterBackpack/`
  layout. Need a Nexus listing (description, screenshots, mod
  page metadata). UE4SS for Grounded 2 is a Vortex mod, so
  ours rides on that.
- [ ] **Project rename.** "better-backpack" / "BetterBackpack" /
  Vortex zip name no longer fits when the mod is an RPG /
  level-up system. Candidates: `grounded-rpg`, `g2-rpg`,
  `groundlevel`, `instar`, `huntmaster`. Touches: Cargo.toml
  package name, workspace dir, settings file path, BetterBackpackMod
  C++ class name, log header, README, Vortex zip name.
- [x] **Archive winhttp proxy.** `better-backpack-cpp/` moved to
  `archive/winhttp-proxy/`. Unique Grounded 2 internals were
  ported into the authoritative subject docs first
  (`docs/inventory.md`, `docs/grounded-engine.md`). Kept as a
  reference / fallback if UE4SS ever turns out unstable.

## Integration testing (debug HTTP endpoint + Rust tests)

The bandage regression took multiple in-game cycles to find because
we had no way to drive the mod programmatically and assert state.
Build a debug surface so future bugs of this shape get caught by a
test, not by the player noticing.

### Design

- **One generic command-shaped endpoint**: `POST /debug` taking
  `{op, args}`, always returning `{ok, state, result}` where `state`
  is the **full game-state snapshot** (skills, toggle flags,
  captured vanilla baselines, live HC field reads at the offsets
  we touch, sfx-list, recent dmg-trace ring).
- **Rust integration tests** in `better-backpack/tests/integration/`,
  one file per scenario, each a separate `#[test]` binary. Shared
  `common::Api` wrapper over reqwest blocking client. Runs against
  a live game (user launches Grounded 2 + loads a save first).
- **Settings flag**: `debug.http_port: Option<u16>` (None disables).
  Production builds ship with the port off.
- **Thread safety**: HTTP server on its own worker thread. Reads
  pull from the snapshot path (UObject memory reads, already safe
  off-thread). Writes that need ProcessEvent get queued onto a
  game-thread surface -- drain inside `kill_hook`'s trampoline
  (fires every damage tick, guaranteed game thread). HTTP handler
  blocks on the queue draining before returning so callers see
  post-op state.

### Op set (initial)

| op | args | purpose |
| --- | --- | --- |
| `snapshot` | -- | no-op, just returns state |
| `skill_spend` | `{id, count}` | mirror the +N button |
| `skill_refund` | `{id, count}` | mirror the -N button |
| `skill_toggle` | `{id, enabled}` | mirror the on checkbox |
| `simulate_damage` | `{amount, type_flags}` | fire ApplyDamage on player HC |
| `simulate_heal` | `{amount}` | sugar: simulate_damage with negative amount + type_flags=0; the bandage repro |
| `reload_slot` | -- | re-trigger world_loader activate |

Adding an op = one more match arm + one more test scenario.

### Test coverage principle

**Every user-facing interaction and expectation gets an integration
test.** The control plane is what makes this affordable; the
discipline is the point. See
`~/.claude/skills/runtime-control-http/SKILL.md` "Test coverage
principle" for the cross-project rule.

For this mod, that means tests for:

- For EACH catalog skill: spend 1 -> max -> assert effect grows
  on the live target field(s).
- For EACH catalog skill: spend then refund -> assert effect
  reverts to vanilla.
- For EACH catalog skill: spend then toggle off -> assert effect
  reverts to vanilla.
- For EACH catalog skill: spend then toggle on -> assert effect
  is back.
- For EACH catalog skill: spend, simulate slot reload -> assert
  state persists.
- For EACH catalog skill: leave at 0 -> assert no effect.
- INTERACTIONS:
  - impact_resistance + bandage (the regression). Active blocks
    healing; off lets it through. **Critical fence.**
  - armor + bandage. BaseDamageReduction must not block heals.
  - Every other skill that touches HC fields: confirm bandages
    still work with it enabled.
  - fall_resistance + impact_resistance + falls onto rocks.
- USER INPUTS:
  - simulate creature kill -> XP awarded, level transitions
    correct, skill_points incremented.
  - simulate fall onto rock -> impact gate behavior.
  - simulate damage from each EDamageType bit -> resistance gating.
  - simulate consume bandage -> heal applied.
- ERROR PATHS: unknown skill id, spend 0, refund below 0, op
  while no slot, port collision.
- PERSISTENCE: save schema round-trip across each skill.

A bug is a missing test. When a regression is found, the test
goes in BEFORE the fix. The test stays as a fence forever.

### First regression test (this is the gating shape)

```rust
#[test]
fn impact_resistance_does_not_block_bandages() {
    let api = common::Api::connect();
    api.op("skill_spend", json!({"id": "impact_resistance", "count": 100}));
    api.op("skill_toggle", json!({"id": "impact_resistance", "enabled": true}));
    let before = api.snapshot().player.hp;
    let r = api.op("simulate_heal", json!({"amount": 20}));
    assert!((r.state.player.hp - before - 20.0).abs() < 0.5);
}
```

That test fails today (mask blocks heal) and is the regression
fence for the status-effect migration -- whoever reintroduces a
binary mask without type-filtering trips it immediately.

### Architectural shift: generic primitive, not domain ops (2026-05-09)

The endpoint moved from "one op per scenario" to "one generic
`call` op + test-side parm structs". The skill
`runtime-control-http` now codifies this rule across projects.
Practical consequence: 1000% parity stops meaning "implement N
domain ops" and starts meaning "the test side has structs and
helpers for the SDK functions you want to call." The mod
provides the surface; the tests provide the experiments.

Read surface still needs the two remaining items below. Drive
surface is now ~done in the generic sense; the per-domain rows
below are reframed as test-side `tests/<name>.rs` deliverables
(each one is a Rust struct + a few `call_ufunction` invocations
+ assertions, no mod work).

### Endpoint parity gap (target: 1000%)

Per `~/.claude/skills/runtime-control-http/SKILL.md`, the endpoint
must be able to:

> - **Read** any state worth introspecting, in one round-trip.
> - **Drive** any operation the process can perform internally.
> - **Provoke** events that wouldn't normally occur on demand.

We do NOT have parity yet. Audit table below; each ✗ is a thing
that has to land before we declare the endpoint done. The
research / TDD loop only works if the answer to "can I do X
through the endpoint" is yes for EVERY X the user can do in-game.

#### Read surface (snapshot fields)

- [x] skill levels + points
- [x] disabled-skills (toggle state)
- [x] vanilla baselines (hunger/thirst/fall/max_health/hc masks)
- [x] live HC fields (RequiredDmgFlags, Immunity, BDR, Max, CurrentDmg)
- [x] live CMC fields (12 movement)
- [x] live ASC fields (combat mult + fall trio)
- [x] CDO state (survival, GlobalCombatData, GMS, SMMC)
- [x] inventory.current_slot_count
- [x] **player StatusEffects array** -- exposed in snapshot via
  `fall_hook::snapshot_player_status_effects` (lifted from the
  fall_hook probe).
- [ ] **recent dmg-trace ring buffer** -- last N multicast events
  with damage/flags/type_flags/instigator. Currently log-only.
- [x] settings echo (what was loaded from settings.json)
- [x] catalog dump (server-authoritative skill list so tests don't
  hardcode ids)
- [ ] player world location + equipped weapon (context for
  fall / item-use simulation)

#### Drive surface (ops)

- [x] snapshot
- [x] skill_toggle / skill_spend / skill_refund
- [x] reload_slot
- [x] simulate_add_health (canonical heal path; PE-queued)
- [x] simulate_set_current_health (direct setter; PE-queued)
- [x] **simulate_apply_damage** -- DEPRECATED. Replaced by the
  generic `call` primitive (2026-05-09). Tests build the parm
  struct themselves, hex-encode, send through `call`. Re-entrance
  guard added to drain_pending so `call` is safe even when the
  invoked UFunction triggers PE fan-out.
- [x] **`call` generic primitive** (2026-05-09). Single op
  invokes any UFunction on any object with arbitrary parm
  bytes. Replaces every `simulate_*` op below -- tests build
  their own parm struct, hex-encode, send. New research
  scenarios are now test-file-only changes (no mod rebuild).
  Selectors: `live_player_hc`, `live_player`,
  `first_class:<Name>`.
- [ ] **High-frequency drain site for the PE queue.**
  `kill_hook`'s trampoline only fires when the engine calls a
  UFunction on a player's `UHealthComponent` vtable. With
  `impact_resistance` mask = 0xFFFFFFFF, the gate rejects most
  type_flags=0 events and multicast traffic drops near zero,
  starving the drain. `call` ops time out at 5s instead of
  executing. Options:
  - **A**: install a hook on `ASurvivalCharacter::ReceiveTick`
    or a similar high-frequency UFunction. Tick fires every
    frame regardless of damage state.
  - **B**: use UE4SS's `RegisterProcessEventPreCallback` (global
    PE pre-callback fires for every UFunction on every object
    in the process). Already on the roadmap as "Future infra"
    below; this is the canonical drain site.
  - **C**: have the test drive activity (move, attack) to
    incidentally fire the trampoline. Workaround only.
  Recommendation: B; A as fallback. Until fixed, research that
  uses `call` while the mask is on must run with the player
  active in-world.
- [~] **simulate_consume_item** -- can be done test-side via
  `call` once we know which UFunction handles bandage consume
  (TryUseItem on the player controller, takes a UItem*; getting
  a UItem* needs a `walk_class` primitive or inventory walk).
- [~] **simulate_kill** -- test-side via `call` with the right
  function on the kill_hook surface. Doable today; nobody has
  written it yet.
- [~] **simulate_fall** -- test-side via `call`. Same shape.
- [~] **simulate_status_effect_add / _remove** -- test-side via
  `call` on `UStatusEffectComponent::CreateAndAddEffect` once
  the row handle layout is captured in a `#[repr(C)]` struct.
- [x] **set_skill_points** -- maps to `tracker::debug_grant_skill_points`.
- [~] **set_xp / set_level** -- test-side via `call` if a setter
  UFunction exists, or via direct field-write (need a
  `write_field` primitive, still on roadmap).
- [~] **clear_status_effects** -- test-side via `call` on the
  appropriate UFunction or via direct TArray write.

#### Test coverage (per the per-skill principle)

For EACH catalog skill (×13):

- [x] spend -> effect grows (covered)
- [ ] refund -> reverts (only ~half the skills tested explicitly)
- [ ] toggle off -> reverts to vanilla (only for variants that
  honor the flag; others should error or be marked N/A)
- [ ] toggle on -> effect restored (move_speed only; fill in)
- [ ] **persist across slot reload** -- NOT covered for any skill
- [ ] level 0 -> no effect (implicit; make explicit per skill)

Interaction matrix (every pair touching a shared subsystem):

- [x] impact_resistance + bandage (the fence)
- [ ] armor + heal
- [ ] max_health + fall onto rocks
- [ ] fall_resistance + impact_resistance + rock collision
- [ ] every other pair touching HC fields, damage gate, regen

Error paths:

- [x] unknown skill id, spend 0, refund below 0
- [ ] op while no slot (only reload_slot covers this today)
- [ ] malformed args (wrong type)
- [ ] port collision / second instance

#### Anti-pattern audit (skill says NO)

- [x] Multiple endpoints -- one /debug
- [x] Quick GET routes -- only POST
- [x] CLI bypassing endpoint -- none exists
- [x] Mocked test fixtures -- endpoint is the fixture
- [ ] **Logs instead of state** -- status effects now in snapshot;
  dmg-trace ring still log-only. Last item to land for parity.

### Build sequence

- [x] **Crate deps + settings flag.** `tiny_http` (mod-side),
  `ureq` (dev-dep for tests). `settings.debug.http_port: Option<u16>`,
  default None. `settings.example.json` updated.
- [x] **`src/debug.rs`**: HTTP server (single POST /debug handler),
  `Snapshot` struct, `build_snapshot()` walking live UObjects. Spawn
  on a named worker thread when `settings.debug.http_port` is set.
- [x] **First op**: `snapshot` (read-only). Vanilla baselines, captured
  HC u32 masks, disabled-skills list, live player HC field reads
  (RequiredDamageTypeFlags, ImmunityFlags, BaseDamageReduction,
  MaxHealth, CurrentDamage).
- [x] **Test scaffolding**: `tests/common/mod.rs` (Api wrapper over ureq,
  response types) + `tests/debug_snapshot.rs` (smoke test). Tests skip
  with a clear note when `BBP_DEBUG_PORT` env var is unset.
- [x] **`docs/testing.md`**: how to enable the port, run tests, read
  the snapshot.
- [ ] **PE-thread command queue**: `Mutex<VecDeque<DebugCmd>>` in
  `debug.rs`; drain from `kill_hook` PE trampoline. `simulate_damage`
  / `simulate_heal` / `skill_spend` / `skill_toggle` / `reload_slot`
  push onto this.
- [ ] **First write op**: `skill_toggle`. Easiest -- already
  thread-safe (mutex on DISABLED_SKILLS).
- [ ] **`simulate_damage` op**: queue a `process_event` on
  `UHealthComponent.ApplyDamageFromInfo` with crafted FDamageInfo.
  HTTP handler blocks on the queue draining before returning so
  callers see post-op state, not a race.
- [ ] **`simulate_heal` op**: sugar for `simulate_damage` with negative
  amount + type_flags=0. The bandage repro.
- [ ] **`bandage_regression.rs` test**: the gating shape from the
  design (enable impact_resistance, simulate_heal, assert HP
  delta == amount). Fails today; passes after status-effect
  migration.
- [ ] **Per-skill test family**: `tests/skill_<id>.rs` for every
  catalog entry, exercising spend / refund / toggle-on /
  toggle-off / persist / level-0 against the live target field.
  This is the primary test layer; the control plane exists
  precisely to make this cheap. See `runtime-control-http` skill
  "Test coverage principle".
- [ ] **Interaction matrix**: `tests/interactions/<a>_<b>.rs` for
  every pair of skills that touches a shared subsystem (HC
  fields, damage gate, regen). Catches the bandage class of bug
  before the user sees it.
- [ ] **User-input scenarios**: `simulate_kill`, `simulate_fall`,
  `simulate_consume_item` ops + tests that drive each one.
- [ ] **CI**: tests already skip when env var is unset, so default
  `cargo test` stays green. Document the opt-in env var in CI docs
  if/when the project gets a CI pipeline.

### Why this catches bugs that today's logs don't

Logs are write-only history; you have to read them, eyeball
patterns, hope you catch the right line. The snapshot endpoint
gives a queryable, structured view of *current* state -- "what is
the mask right now on the live HC", "what's the HP", "what's in
the deferred queue" -- and tests assert against it deterministically.
The bandage regression would have surfaced as a one-line failure
the first time impact_resistance went out as a binary mask.

## Feature ideas (not yet scoped)

- [ ] **Auto-farming buildings.** Player can place a custom
  building that periodically yields a configured material (or
  list of materials) into a connected storage. Removes the
  farming grind for late-game players who already know the
  loops. Open design questions:
  - **Surface**: a new buildable that registers as a normal
    building (so it integrates with build mode + saves), or a
    Lua-style overlay that ticks externally and posts items
    into a target chest? Built-in surface is more invasive but
    feels native.
  - **Item source**: which materials are eligible? Plant fibers
    + resin always; rarer mats (boss drops, ant parts) gated by
    tier or by a player-set policy.
  - **Throttle**: yield/min as a function of building tier so
    upgrades have a place. Avoid trivializing the chase.
  - **Power / cost**: needs an input (water, electricity, food
    for a captured creature?) so it isn't a free ratchet.
  - **Multiplayer**: single-host vs replicated. Yield needs to
    be authority-side or it's a dupe.
  - **Reference**: vanilla Grounded 2 may already have a
    "production" building class; check `UProductionBuilding`,
    `BP_Building*` subclasses for an existing skeleton we can
    extend rather than building one from scratch.
  - **Test plan**: place building -> tick for N seconds ->
    verify storage has +M of the right item. All driven via the
    debug endpoint (need ops: `simulate_advance_time`,
    `place_building`, `read_storage_contents`).

## Hot-reload the DLL while the game is running

Editing the mod and seeing the change requires close-game ->
deploy DLL -> launch-game right now. Slow. UE4SS supports
hot-reloading CPPMods in some configurations; need to research
whether our shim shape is compatible:

- Check UE4SS's "reload mods" hotkey / chat command for cpp
  mods specifically (it's well-supported for Lua mods; cpp
  support is partial).
- Our mod installs vtable patches via `ProcessEventHook` and
  forgets the handles for life-of-process. Hot-reload would
  need to re-install those on load AND properly unhook the
  old DLL's vtable patches before the new DLL installs its
  own. Otherwise we corrupt the vtable.
- If UE4SS doesn't reload cpp mods cleanly, alternatives:
  build a tiny "loader" mod that mmaps our actual mod DLL on
  demand and provides install / uninstall hooks; or use
  Windows-side detour-redirect tricks.
- Investigate whether the inv_hook / kill_hook / fall_hook
  install paths are idempotent (i.e. handle "already
  installed" by no-op, so a reload that re-runs init doesn't
  double-hook).

This would dramatically speed up the iteration loop. Worth a
spike.

## Future infra

- [ ] **Global ProcessEvent hook.** Per-vtable hooking is fine
  for the current setup but will hit walls when we want to
  catch BP events that fire on enemy / npc vtables we don't
  hook. UE4SS exposes
  `RC::Unreal::Hook::RegisterProcessEvent[Pre|Post]Callback`
  in its Hooks header; ~20 lines of shim glue + a registry on
  the Rust side. Right call for the next round of player-state
  signals (level-up confirm, recipe learned, dialog start, save
  fired). Not blocking anything today.

## Out of scope (kept for reference)

- Visible 6-row inventory grow. Replaced by paged 4x10 viewport
  with mouse-wheel scroll. Working.
- Multiplayer correctness for hunger/thirst. Stats almost
  certainly replicate server-authoritatively, so non-host
  clients won't see the effect. Document, don't fight.
- In-world UMG HUD overlay (always-visible XP bar). Out of v1
  scope; would need a custom DX11 hook or a BPModLoader-shipped
  widget. ImGui tab is sufficient.

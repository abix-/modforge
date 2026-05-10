# grounded2mods workspace docs

> **Authoritative on:** workspace-level concerns -- cross-cutting
> open work, chronology of milestones across all crates. Per-crate
> docs live next to the code in each crate's `docs/` folder.

## What's here

| File | Authoritative on |
|---|---|
| [todo.md](todo.md) | Open work across the workspace, ordered by leverage. |
| [changelog.md](changelog.md) | Chronological history of milestones, investigations, and design pivots across every crate. |

## Per-crate docs

Each crate documents its own internals. Use the crate's `docs/`
folder when working on that crate.

| Crate | Path | Subject |
|---|---|---|
| ueforge | [`../ueforge/docs/`](../ueforge/docs/) | The UE4SS Rust mod framework -- subsystem reference, performance doctrine, research methodology. |
| grounded2-rpg | [`../grounded2-rpg/docs/`](../grounded2-rpg/docs/) | Grounded 2 RPG / level-up mod -- damage internals, inventory, RPG subsystem, build/deploy, port history. |
| outworld-station/tweaks | [`../outworld-station/tweaks/`](../outworld-station/tweaks/) | Outworld Station mod -- research notes, per-feature tweaks. |

## Adding a new mod

When you add a new game mod to the workspace:

1. Create the crate dir (`<game>-<feature>/` or `<game>/<crate>/`).
2. Add a `docs/` folder there with a `README.md` index for the
   crate.
3. Per-feature deep-dives go in that `docs/` folder.
4. Update the table above so the workspace index lists it.
5. Cross-cutting open work for the new mod lives in this
   workspace `todo.md`.

## Doc rules

- **Co-locate.** A doc lives in the same crate as the code it
  documents. The exception is this directory -- only for
  workspace-spanning concerns (todo, changelog).
- **Authoritative + dated.** Every doc states what it owns at the
  top. Updates note their date.
- **Update with the change.** When you change behavior, update
  the doc in the same commit. Stale docs lie.

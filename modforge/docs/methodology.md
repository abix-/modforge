# Methodology: research-driven modding

> How we figure out how to mod a game. The discipline that
> makes both frameworks worth their weight.

## The loop

1. **Pick a question.** "What field controls the player's max
   stamina?" "When does the game fire a dig event?" "Where do
   ore drops come from?"
2. **Pose it as an op.** Either an existing generic primitive
   (`walk_class`, `inspect_address`, `read_field`,
   `invoke_method`) or a new game-specific op the mod
   registers at init.
3. **Drive it via HTTP.** `curl POST localhost:<port>/op
   -d '{"op":"...", "args":{...}}'`. Read the envelope.
   Compare to expected.
4. **Capture the finding as a test.** Write the question,
   the curl, and the expected envelope shape under the mod's
   `tests/` directory. Now it is a regression check.
5. **Refactor the discovery into a Skill / Effect / Trigger
   / Hook**. Once the operation is well-understood, it
   becomes a reusable framework concept.

The discipline: every research question turns into a test.
Every regression has a test ready to catch it.

## Why HTTP

- **External.** Tests live outside the game process. They
  survive game restart, crash, hot reload.
- **Inspectable.** Curl from anywhere. Pipe to `jq`. Diff two
  responses.
- **Language-agnostic.** Test client is a small Rust binary
  in `modforge/client/`; you could write one in Python or
  TypeScript without changing the framework side.
- **Stable.** The envelope is documented in
  `spec/op-envelope.json`. Op surface in
  `spec/generic-primitives.md`. New game = same protocol.

## Generic primitives that pay off

`walk_class` + `inspect_address` together answer "what is the
shape of this thing in memory?" without dropping into a
debugger.

`read_field` + `write_field` + `invoke_method` together
answer "can I do this thing programmatically?" before
committing to a Skill / Effect implementation.

`scan_memory` + `freeze` together answer "where is this
value stored?" when reflection doesn't help (encrypted /
obfuscated field names, dynamic field tables).

These are the four research questions every game answers in
the first day of work.

## The "always change the framework first" rule

If you wrote the same scaffolding in two game mods, it
belongs in the framework. If you wrote it in two frameworks,
it belongs in modforge. Don't speculate; extract on the
second instance.

## Snapshot is the source of truth

Every op response carries the framework's snapshot blob.
Tests assert against snapshot, not per-op result, because
the "did X work" question is really "what changed in the
world?". The snapshot makes that visible.

## Cross-references

- `composition-model.md`: Effects + Triggers + Skills.
- `def-registry.md`: the Def -> Registry -> Instance ->
  Controller pattern.
- `naming.md`: conventions both frameworks follow.
- `spec/op-envelope.json`: wire format.
- `spec/generic-primitives.md`: the op surface every
  framework ships.

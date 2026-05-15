# Retrospective: was the decompiler project worth it?

> Written 2026-05-14 after the user asked the direct
> question and received an honest answer. Captured here so
> future contributors (and future-me) start from this
> assessment, not from the implementation-confidence of the
> other docs.

## Verdict

**Mostly a waste of time, with some real but small value.**

The session built a working r2sleigh-substrate Rust-output
decompiler with naming, CLI, and 13/18 documented Horsey
key-funcs decompiled. Shipping doesn't equal value.

## Why mostly a waste

### Ghidra C already solves the actual problem

The stated user goal: "decompile game exes to figure out
how they work then build mods in rust."

Ghidra's existing dump did this. `horsey-mod/research/decompiled/all_functions.c`
(18.3 MB, 10,332 functions) plus the hand-curated
`key-funcs/*.c` and `INDEX.md` naming was already a
complete RE workflow. Reading C decomp to plan a mod is a
totally standard practice. The Rust-vs-C syntax difference
is cosmetic when you're reading for understanding, not
compiling. `*(ptr+0x250) = 13;` reads the same to a
Rust-fluent engineer in either language.

### TypeOxidizer proves the right shape

The 2026-05-14 audit surfaced
[TypeOxidizer](https://github.com/Vector35/community-plugins)
in Binary Ninja: **a 50-line render plugin** that swaps
`int64_t` -> `i64` on top of existing C decomp output.
That is what the market actually shipped, because that is
all the problem warrants.

We built a multi-session pipeline (Falcon prototype +
r2sleigh substrate + WSL build harness + naming layer +
CLI subcommands + nine doc files). The industry built a
render filter. The size delta tells you something honest
about scope.

### Coverage is 0.15% of what Ghidra already has

16 functions decompiled by `decomp` vs 10,332 in Ghidra.
Bulk regen is deferred behind a polish ladder item that
is itself gated on fixing libsla-internal stack
overflows. Today, opening `decomp` for a random Horsey
function is more likely to fail than succeed.

### The naming layer is a parasite on Ghidra

`decomp` loads `horsey-mod/research/decompiled/INDEX.md` and
`horsey-mod/research/decompiled/key-funcs/*.c` filenames at
startup. Without Ghidra's output, every function becomes
`sub_<hex>` again. We did not replace Ghidra; we added a
downstream view that depends on Ghidra to be readable.

### Build is WSL-only

Two layers of upstream blockers (libsla-sys `_WINDOWS`
define + cxx-bridge double-include) keep this off Windows
native. Every read costs a WSL context switch. The
Ghidra Java decompiler runs on Windows.

### Opportunity cost was real

`docs/todo.md` at session start had concrete shippable
mod work outstanding:
- The Harmony bridge in `cs-shim-common/HarmonyBridge.cs`
  had been **failing silently the whole session**,
  breaking every Rust-side `patch_prefix` /
  `patch_postfix` call across the workspace.
- horsey-mod `sleep_safe_no_tire` patch-site discovery
  (in progress).
- Verify Greedy Miner in-save.
- Ship `UnitySkillProxyEffect`.
- Grounded 2 catalog expansion (Crit Chance / Evasion /
  Thorns / Stamina Pool etc.).
- Pkg(0) instigator bug in g2rpg.

None of this got attention this session because we were
building a decompiler. The Harmony bridge fix alone
unblocks every Rust-side Unity mod patch in the
workspace, which is higher-leverage than any decompiler
output by an order of magnitude.

## Where it wasn't a total waste

- **Cleared a real question.** "Can we get Rust
  decomp from binaries?" Answer: yes, with substantial
  scaffolding and WSL-only. The next person doesn't have
  to re-derive that.
- **The audit pattern is reusable.** The "smarter
  engineers have probably done this. Search before
  building" workflow we used to find r2sleigh / ReOxide /
  LLM4Decompile-Ref / TypeOxidizer is worth keeping. It
  landed late, but it landed.
- **The Falcon-printer prototype was real RE education.**
  Knowing what a structurer / flag-recovery / call-
  recovery / synth-block-collapse actually does is
  permanent skill.
- **Documentation is honest and detailed.** Future
  contributors (or future-you) can pick up or abandon
  cleanly. Strategy + survey + passes + polish-ladder +
  this retrospective tell the whole story.

## Lessons

- **Audit BEFORE building.** Three sessions earlier the
  `/rtfm` skill flagged "smarter engineers have done
  this". But the search terms were too narrow. r2sleigh
  surfaced via `gh search code "fn structure_loop"`, not
  via `gh search repos "rust decompiler"`. Capability-
  oriented searches beat name-oriented searches.
- **Existing tools count.** When you have 18.3 MB of
  perfectly-readable decomp output already on disk, the
  bar for replacing it is "meaningfully better daily
  workflow" not "shiny new thing." The Rust syntax did
  not clear that bar.
- **Coverage matters more than peak quality.** A tool
  that handles 100% of functions slightly imperfectly
  beats a tool that handles 0.15% perfectly.
- **Render layers beat pipelines for cosmetic wins.**
  TypeOxidizer is 50 lines. We could have built that on
  top of Ghidra in an hour. We didn't, because the
  pipeline framing felt more interesting. That framing
  was wrong.

## Recommended posture going forward

1. **Stop investing in `decomp` and `falcon-printer`**
   for now. Don't delete. Keep as historical archive
   with this retrospective as the entry point. Sample
   artifacts in `horsey-mod/research/decompiled/rust-r2sleigh/`
   stay as evidence the spike worked.
2. **For specific functions where Rust syntax aids mod
   planning**, do it as a one-off: paste the Ghidra C
   into Claude with "rewrite as unsafe Rust pseudocode,
   keep semantics." 30 seconds, zero infrastructure,
   beats `decomp` quality on any single function. This
   is the LLM4Decompile-Ref pattern at the smallest
   scale.
3. **Pivot back to the actual mod backlog.** The
   workspace `docs/todo.md` has higher-leverage work
   waiting.

## Open ladder items in `polish-ladder.md`

Kept for reference, but understand they are unlikely to
get worked unless the project gets revisited:

- Windows build (libsla-sys + cxx-bridge)
- libsla-internal stack overflows
- Sweep subcommand
- Arg recovery / struct shapes
- Comment passthrough
- Cutover when Windows lands

If revisited: read this retrospective first, decide
whether the cost is justified for your specific use
case, then pick from the ladder.

## What this doc supersedes

This retrospective supersedes the implicit
"continue-investing" framing in
[`polish-ladder.md`](polish-ladder.md) and
[`../README.md`](../README.md). Both still describe the
crate's surface honestly; this doc is the meta-assessment
of whether the surface is worth growing.

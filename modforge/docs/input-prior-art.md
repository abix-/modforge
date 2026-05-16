# Synthetic input: prior-art research

> **Status:** in progress (started 2026-05-16). Driving doc for
> [P0. Synthetic input](../../docs/todo.md#p0-synthetic-input-let-the-mod-and-claude-drive-the-game-like-a-human-2026-05-16).
> Mechanism: harvest existing solutions for synthesizing mouse + keyboard
> input INTO a running game / GUI app, decide which L1 (OS-global), L2
> (per-window message), and L3 (game-internal poke) shapes to adopt for
> `modforge::input`. Research-only; no code lands until PR-1..PR-10 are
> done and a recommendation is on file at the bottom of this doc.

## TL;DR (filled in last)

_Pending PR-1..PR-10._

---

## Method

All searches use the `gh` CLI (per user direction). Each PR-N section
captures: search terms tried, top hits with stars/license/last-commit,
mechanism (L1/L2/L3), API shape excerpt, fit notes.

A repo qualifies for "evaluate further" if: maintained within the last
~2 years OR battle-tested historical (>1000 stars), permissively
licensed (MIT/Apache/BSD/ISC/Zlib; copyleft flagged but not auto-out),
and either Windows-supporting or pattern-portable.

Search lexicon used across PRs:

- L1 keywords: `SendInput`, `mouse_event`, `keybd_event`, `INPUT struct`
- L2 keywords: `PostMessage`, `WM_LBUTTONDOWN`, `WM_KEYDOWN`, `WM_INPUT`
- L3 keywords: per-engine (UE: `FSlateApplication`, `UPlayerInput`,
  `FInputKeyParams`; Unity: `Input.GetKey`, `InputSystem`; SDL: `SDL_PumpEvents`)
- Anti-cheat-friendly synonyms: `humanize`, `bezier`, `interception driver`
- Replay: `input replay`, `macro record`, `event playback`

`gh search code` rate-limits aggressively; we batch reads and cache
findings in this file rather than re-querying.

---

## PR-1: Game-mod input libraries

_Status: in progress._

### Search terms

| Query | Result count (top page) | Notes |
|---|---|---|

### Top candidates

| Repo | Stars | License | Last commit | Mechanism | Notes |
|---|---|---|---|---|---|

### Findings

---

## PR-2: UI automation frameworks (concept-mining, not adoption)

_Status: pending._

### Targets

- pywinauto (Python; native + UIA)
- AutoHotkey v2 (C; AHK_L is open source; v2 is the active line)
- Microsoft UI Automation (UIA) via `windows-rs` bindings
- AutoIt (closed-source but well-documented API surface)

What we extract: the **abstraction**, not the implementation. Things to
copy: key/mouse object hierarchy, modifier-chord encoding, send vs
sendraw vs sendinput vs sendplay modes, replay loop shape.

### Findings

---

## PR-3: Game-bot ecosystems

_Status: pending._

### Targets

- RuneLite (RuneScape; permissive plugin API)
- OSRSBox / Old School RuneScape tooling
- League/Dota botting communities (mostly GPL'd; cite for L3 patterns)
- Poker botting (PokerTH OSS bots; vintage but documented)

What we extract: **per-engine click dispatcher catalogs** (which fn
inside which engine takes the click), and the "humanize the curve"
pattern for L1 mouse-movement.

### Findings

---

## PR-4: Reverse-engineered input pokes per engine

_Status: pending._

### Per-engine targets

| Engine | Input class(es) | Known RE projects |
|---|---|---|
| UE4 / UE5 | `UPlayerInput`, `FSlateApplication`, `FInputKeyParams` | UE4SS, KismetAnalyzer, Dumper-7 |
| Unity (Mono) | `UnityEngine.Input` | BepInEx samples, MelonLoader docs |
| Unity (IL2CPP) | `UnityEngine.Input` via Il2CppInterop | Il2CppInterop docs, MelonLoader |
| SDL2 | `SDL_PumpEvents`, `SDL_Event` queue | SDL source, official tutorials |
| Raw Win32 (Horsey-shape) | `GetAsyncKeyState`, `GetCursorPos`, custom message-pump | per-game RE |

This is the **L3 catalogue** we'll grow over time. One subsection per engine.

### Findings

---

## PR-5: Raw-input / `WM_INPUT` handling

_Status: pending._

Raw-input games ignore PostMessage by design (they read deltas, not
state). Two known workarounds in the field:

1. **ViGEm** (Virtual Gamepad Emulation Framework) for controllers.
2. **Interception driver** (`oblitum/Interception`) for keyboard/mouse
   at the kernel/HID level; bypasses raw-input entirely because it IS
   raw-input.

What we capture here: license, driver-install complexity, anti-cheat
flagging history, Rust bindings if any.

### Findings

---

## PR-6: Accessibility / assistive tech

_Status: pending._

The most robust L1 implementations in the wild ship in accessibility
tools because they have to work across every Windows app and degrade
gracefully on focus changes.

### Targets

- Tobii Eye Tracker SDK (closed but with sample code)
- Camera Mouse (FOSS dwell-click)
- Sensory Software / The Grid 3 (commercial, but APIs published)
- AutoControl (Android-side analogue)

### Findings

---

## PR-7: Crate audit (Rust)

_Status: pending._

`cargo search` + repo dive on:

| Crate | Mechanism | Win32 backend | Last release | License | Maintained? |
|---|---|---|---|---|---|
| `enigo` | L1 | `SendInput` | tbd | tbd | tbd |
| `autopilot` | L1 | `SendInput` | tbd | tbd | tbd |
| `rdev` | L1 + listen | `SendInput` + low-level hook | tbd | tbd | tbd |
| `winput` | L1 | `SendInput` | tbd | tbd | tbd |
| `mouce` | L1 (mouse only) | `mouse_event` | tbd | tbd | tbd |
| `inputbot` | L1 + listen | `SendInput` + hook | tbd | tbd | tbd |
| `windows`, `windows-sys` | raw bindings | both | tbd | tbd | tbd |

### Findings

---

## PR-8: In-process injection precedents

_Status: pending._

The closest match for our architecture: already-in-process mods that
expose input. They've solved L3 already.

### Targets

- UE4SS (any plugin that synthesizes input; check repo + community)
- BepInEx + UnityExplorer / RuntimeUnityEditor (Unity in-process mods)
- ReShade overlays (DX11/12 hook plus input)
- Special K
- ImGui backends (`imgui-impl-win32`). They capture input from the host
  message pump, so they're a model for the reverse direction too.

### Findings

---

## PR-9: Replay / record-playback formats

_Status: pending._

Decide canonical JSON event-stream shape for `modforge::input` replay.

### Candidates to compare

- AutoHotkey scripts (text format; well-understood)
- Cheat Engine table macros (lua; baroque but capable)
- OBS Replay Buffer / Studio (not input but timing-rigorous)
- `xdotool` shell scripts (Linux; cite for syntax)
- Speedrun TAS movie formats (`.bk2`, `.fm2`, `.lsmv`; gold standard
  for deterministic input replay)

Goal: pick a JSON shape that round-trips losslessly and is human-editable.

### Findings

---

## PR-10: Anti-cheat / legitimacy notes

_Status: pending._

Per-game stance. Even if technically possible, some surfaces (online
MP, leaderboards) treat synthetic input as TOS-violating.

| Game | Online MP? | AC | Stance on synthetic input | Source |
|---|---|---|---|---|
| Horsey Game | no | none | low risk | tbd |
| Grounded 2 | co-op (limited) | none | low risk | tbd |
| Schedule 1 | TBD | TBD | TBD | tbd |
| Outworld Station | TBD | TBD | TBD | tbd |

### Findings

---

## Recommendation (filled in last)

_Pending PR-1..PR-10._

Will cover:

- L1 backend (likely `enigo` or hand-rolled `SendInput` via `windows-sys`).
- L2 strategy (PostMessage wrapper crate vs hand-rolled).
- L3 patterns (per-engine table seeded from PR-4 + PR-8).
- Replay format (per PR-9 winner).
- Anti-cheat policy (per PR-10).

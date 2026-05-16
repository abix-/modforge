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

_Status: first pass complete (2026-05-16)._

### Search terms

| Query | Hits surveyed | Notes |
|---|---|---|
| `gh search code "PostMessageW WM_LBUTTONDOWN" --language=rust` | 1 (`ekicyou/areka`) | small, demonstrates the exact L2 shape we want |
| `gh search code "FInputKeyParams" --language=cpp` | 8 (UE forks, UnrealCV, Lyra, GSS) | confirms `UPlayerInput::InputKey(FInputKeyParams)` as canonical UE L3 |
| `gh search repos "rust input simulation windows"` | empty | covered by named-crate dive in PR-7 |

### Top candidates

| Repo | Stars | License | Last commit | Mechanism | Notes |
|---|---|---|---|---|---|
| `unrealcv/unrealcv` | 2178 | MIT | 2026-04-15 | L3 (UE-internal) | HTTP server BURIED in a UE plugin, exposes `vset /action/keyboard <key> <dt>` and routes through `PlayerController->InputKey(FInputKeyParams)`. Same architecture as us. |
| `gamaspacestation/gss_release` (Lyra fork) | n/a | Epic source | n/a | L3 (UE-internal) | Epic's own `ULyraSimulatedInputWidget::InputKeyValue` calls `UEnhancedPlayerInput::InputKey(FInputKeyParams)`. Authoritative reference. |
| `bl-sdk/oak2-mod-manager` | n/a | MIT | recent | L3 (UE-internal) | Borderlands 3 / Oak2 modding SDK; uses keybinds inside UE process. |
| `ekicyou/areka` | n/a | n/a | n/a | L2 (Win32) | Smallest Rust example of `PostMessageW(WM_LBUTTONDOWN)` clicking a target window. Useful as a literal `PostMessage` recipe. |

### Findings

- **Two clear winning architectures:**
  - **In-engine (L3) for UE:** route through `UPlayerInput::InputKey` / `UEnhancedPlayerInput::InputKey`. Works regardless of focus, regardless of raw-input mode, regardless of fullscreen. UnrealCV proves the HTTP-driven shape end-to-end.
  - **Win32 (L1/L2) for raw-Win32 games like Horsey:** `SendInput` (L1) is universal but steals focus. `PostMessage` (L2) targets one HWND, doesn't steal focus, ignored by games that use raw-input or poll `GetAsyncKeyState`.
- **L2 viability is per-game.** Test inside the consumer mod, not at the modforge layer. The modforge `Mouse`/`Keyboard` abstraction must let the consumer pick L1 vs L2 vs L3 per call; default per game.
- **Same-process advantage:** because we're injected, we can call the game's WndProc directly with `SendMessage` (synchronous, returns the LRESULT) instead of `PostMessage` (async, fire-and-forget). Worth A/B'ing for HK1 transfer.

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

_Status: first pass complete for UE; other engines pending._

### Per-engine targets

| Engine | Input class(es) | Known RE projects | Status |
|---|---|---|---|
| UE4 / UE5 | `UPlayerInput`, `FSlateApplication`, `FInputKeyParams`, `UEnhancedPlayerInput` | UE4SS, Lyra source, UnrealCV | researched |
| Unity (Mono) | `UnityEngine.Input` | BepInEx samples, MelonLoader docs | pending |
| Unity (IL2CPP) | `UnityEngine.Input` via Il2CppInterop | Il2CppInterop docs, MelonLoader | pending |
| SDL2 | `SDL_PumpEvents`, `SDL_Event` queue | SDL source, official tutorials | pending |
| Raw Win32 (Horsey-shape) | `GetAsyncKeyState`, `GetCursorPos`, custom message-pump | per-game RE | game-specific (I-R) |

### Unreal Engine 4/5

**Canonical L3 path:** `APlayerController::InputKey(FInputKeyParams)` (UE 4.26+) or, with Enhanced Input enabled, `UEnhancedPlayerInput::InputKey(FInputKeyParams)`.

Two confirmed live consumers:

- **UnrealCV** (`unrealcv/unrealcv/Source/UnrealCV/Private/Commands/ActionHandler.cpp`):
  ```cpp
  FExecStatus FActionHandler::Keyboard(const TArray<FString>& Args) {
      // Args[0] = key name, Args[1] = delta time
      const FKey Key(*KeyName);
      float Delta = 1, DeltaTime = FCString::Atof(*Args[1]);
      FInputKeyParams KeyParams(Key, Delta, DeltaTime, /*NumSamples=*/1, /*bGamepad=*/false);
      World->GetFirstPlayerController()->InputKey(KeyParams);
      // schedule a release via FTimerManager
  }
  ```
  Run a TCP/HTTP server inside the game process, expose `vset /action/keyboard <key> <dt>`, and route every command through `PlayerController->InputKey`. Same shape as `runtime-control-http`.
- **Lyra** (`gamaspacestation/gss_release/Source/LyraGame/UI/LyraSimulatedInputWidget.cpp`):
  ```cpp
  FInputKeyParams Params;
  Params.Delta = Value;          // FVector for analog
  Params.Key = KeyToSimulate;
  Params.NumSamples = 1;
  Params.DeltaTime = GetWorld()->GetDeltaSeconds();
  Params.bIsGamepadOverride = KeyToSimulate.IsGamepadKey();
  Input->InputKey(Params);
  ```
  Epic-authored. UMG widget routes a touch event into a fake key press. Confirms the API is the supported one.

**Mouse cursor:** UE's mouse position lives on the `FSlateApplication` singleton (`FSlateApplication::Get().GetCursorPos()`). To synthesize a click, the safest L3 path is to route through `FSlateApplication::OnMouseDown` / `OnMouseUp`, which fires the same dispatch as a real click. For PE games where Slate isn't easily reachable, fall back to `PostMessage(hwnd, WM_LBUTTONDOWN, ...)` with a `lParam` carrying client coords; UE's Win32 platform layer translates them.

**Grounded 2 specifics:** UE5 + Enhanced Input. The Enhanced Input subsystem (`UEnhancedInputLocalPlayerSubsystem::GetPlayerInput()`) returns the right object to feed `FInputKeyParams` to. ueforge already exposes UObject-by-name lookup; calling `InputKey` is one more `ProcessEvent`-style invocation away.

### Other engines (sketch; fill in later)

- **Unity (Mono/IL2CPP):** the `UnityEngine.Input` class is read-only; can't poke it directly. The canonical approach in the BepInEx / MelonLoader ecosystem is to either hook the `Input.GetKey*` family and lie on read, or use a 3rd-party library like InputSystem (new Unity input) and synthesize via `InputSystem.QueueStateEvent`. Schedule 1 / Outworld Station likely fall here.
- **SDL2:** `SDL_PumpEvents` reads OS events; `SDL_PushEvent` queues a fabricated one. We'd target `SDL_PushEvent(&SDL_Event{type: SDL_KEYDOWN, ...})`.
- **Raw Win32 (Horsey):** per-game I-R discovery. Working hypothesis: a small WndProc reads `WM_LBUTTONDOWN` / `WM_MOUSEMOVE` into engine-private globals. PostMessage should work; verify in I-R5.

---

## PR-5: Raw-input / `WM_INPUT` handling

_Status: first pass complete (2026-05-16)._

Raw-input games (any game using `RegisterRawInputDevices` to read mouse / keyboard deltas instead of high-level WM_KEY / WM_MOUSE messages) ignore PostMessage by design. The field has converged on driver-level workarounds:

### Interception driver

- Repo: [`oblitum/Interception`](https://github.com/oblitum/Interception)
- **1849 stars, no SPDX license declared, last commit 2021-08-09.** Effectively abandoned but battle-tested over a decade in the bot / accessibility scene.
- Mechanism: a kernel-mode upper filter driver that inserts itself in the keyboard / mouse driver stack. Synthesized events look identical to physical events to anything downstream, including raw-input.
- Trade-off: requires admin to install the driver (`install-interception.exe /install`) and a reboot. Catastrophic for "drop-in mod"; great for a power-user opt-in.
- **No first-class Rust binding found** in `gh search repos --language=rust "interception"`. Existing `interception-*` crates on crates.io are all for HTTP / syscall interception, not the driver. We'd write our own FFI wrapper around `interception.dll` if we ever go this route. ~200 LOC.
- Status flag: **defer**. Horsey doesn't need it (raw Win32 message-pump expected). Revisit only if a target game ignores PostMessage AND we cannot reach an L3.

### ViGEm (Virtual Gamepad Emulation Framework)

- Repo: [`ViGEm/ViGEmBus`](https://github.com/ViGEm/ViGEmBus) (driver) + [`ViGEm/ViGEmClient`](https://github.com/ViGEm/ViGEmClient) (user-mode SDK).
- For gamepad synthesis only. Out of scope for v1 (no current gamepad-driven targets).

### Anti-cheat flagging

Driver-level input synthesis is a primary pattern flagged by EAC / BattlEye / Vanguard. None of our current targets ship with kernel AC; document and stay clear if any future target does.

### Findings (verdict)

- **L2 PostMessage suffices for raw-WM games (Horsey class).**
- **L3 in-engine suffices for managed-runtime games (UE / Unity).**
- **Interception driver is the third-tier escape hatch.** Lift only if we hit a target that uses raw-input + has no reachable L3.

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

_Status: first pass complete (2026-05-16)._

Metadata pulled live from `gh api repos/<owner>/<repo>`. License/stars/last-push are authoritative as of today.

| Crate | Repo | Stars | License | Last commit | Mechanism | Win32 backend | Verdict |
|---|---|---|---|---|---|---|---|
| `enigo` | `enigo-rs/enigo` | 1715 | MIT | 2026-03-30 | L1 | `windows` crate -> `SendInput` | **Top L1 candidate.** Edition 2024. Mouse + keyboard, button-only, abs/rel move, scroll, X-buttons. ~5kb compiled stub. |
| `rdev` | `Narsil/rdev` | 728 | MIT | 2026-05-12 | L1 + listen (low-level hook) | `winapi` crate -> `SendInput` | Active. Listening side (hook callbacks) bigger than what we need; selectable as L1-only via not enabling features. |
| `autopilot` | `autopilot-rs/autopilot-rs` | 420 | MIT/Apache-2.0 | 2025-10-29 | L1 | `winapi` crate -> `mouse_event` / `SendInput` | Edition 2024; dual-licensed. Carries `image` dep we don't want. |
| `InputBot` | `obv-mikhail/InputBot` | 461 | MIT | 2025-08-01 | L1 + global hotkeys (listen) | `winapi` -> `SendInput` + low-level hook | Cute API (`Numrow1Key.bind(...)`); too opinionated for a primitive layer. |
| `winput` | `gymore-io/winput` | 21 | MIT | 2024-01-30 | L1 | `winapi` -> `SendInput` | Small + clean (`Vk`, `Button`, `Action`, `send_inputs`). Easiest to vendor / fork if we go DIY. |
| `mouce` | `emrebicer/mouce` | 54 | MIT | 2025-05-17 | L1 (mouse only) | `winapi` -> `mouse_event` | Mouse only; rules itself out. |
| `windows`, `windows-sys` | `microsoft/windows-rs` | n/a | MIT/Apache | active | raw FFI | both | Always-available. If we go DIY (a la `winput` shape) we'd build directly on `windows-sys`. |

### Findings (verdict)

- **`enigo` is the right L1 dependency.** Most stars, most maintained, edition 2024 (matches our workspace), MIT, uses the modern `windows` crate. Mouse + keyboard + scroll. The `Settings { dw_extra_info, ... }` knob lets us tag synthetic events so we can ignore-our-own when we hook key state later.
- **No existing crate covers L2 (PostMessage).** All Rust input crates we audited target the OS-global L1 path. We will hand-roll a thin `modforge::input::win32_message` module over `windows-sys` to PostMessage / SendMessage to a target HWND. ~80 LOC.
- **No existing crate covers L3 (game-internal).** As expected; this is per-game and goes through ueforge / horsey-mod's resolver. Modforge defines the `InputSurface` trait; consumers implement.
- **Hand-rolled DIY is a real option** if `enigo`'s `windows` crate footprint is unacceptable: `winput`'s 600-LOC shape is the template.

### Cargo footprint check (TODO during I-1)

Confirm `enigo` (no features) doesn't pull `tokio` / `serde` / `wayland` / `x11` on the Windows build. Cargo.toml inspection shows `default = ["x11rb"]` which is Linux-only and won't compile on Windows. We need `default-features = false` on our side.

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

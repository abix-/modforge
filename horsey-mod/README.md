# horsey-mod

Native-PE binding of [`modforge`](../modforge) for Horsey Game.

Sibling to `ueforge` (UE5/UE4SS) and `unityforge` (Unity Mono/IL2CPP).
Where those rely on a managed-runtime plugin loader, horsey-mod attaches
via an injector EXE that `CreateRemoteThread`s a `LoadLibraryW` on
`horsey.dll` into the running `Horsey.exe`.

## Status

| Component | Status |
|---|---|
| `horsey-mod` crate | shipped, builds clean |
| `horsey.dll` + `horsey-inject.exe` | working artifacts |
| DLL injection via `CreateRemoteThread(LoadLibraryW)` | working |
| HTTP control plane on `127.0.0.1:33077` | working, 18 ops registered |
| Auth via `X-Ueforge-Auth` + token file | working |
| `_shutdown` op + staged-DLL hot-reload | reload swap works, but causes delayed crash (hardening tracked in [`docs/todo.md`](docs/todo.md)) |
| `cheats.no_tire = true` by default at attach | working. Confirmed live 2026-05-13 |
| MinHook trampolines on game functions | not started |
| SDL3 input hooks for hotkeys | not started |
| Save-writer hook for sidecar state | not started |
| Roster UI (web frontend) | not started |

## What you get out of the box

A localhost HTTP control plane on `127.0.0.1:33077` with auth, powered by
`modforge::server`. Endpoints:

| Op | Args | Effect |
|---|---|---|
| `ping` | | Returns `"pong"` |
| `list_ops` | | Lists every registered op |
| `game.read` | | Snapshot of money/year/sleeps/races/horse_count/no_tire/debug_mode |
| `game.money.get` | | Current money |
| `game.money.set` | `{value: u32}` | Set money |
| `game.money.add` | `{value: i32}` | Add to money (saturating) |
| `game.year.get` | | Current year |
| `game.year.set` | `{value: u32}` | Set year |
| `cheats.no_tire.get` | | Read No Tire toggle |
| `cheats.no_tire.set` | `{enabled: bool}` | Toggle fatigue-disabled mode |
| `cheats.debug_mode.get` | | Read debug-mode flag |
| `cheats.debug_mode.set` | `{enabled: bool}` | Force debug mode on/off (skip the "type debug" unlock) |
| `horses.count` | | Number of horses in roster |
| `horses.roster_addr` | `{index: usize}` | Memory address of roster entry |
| `horse.read` | `{addr: hex-string}` | Read horse fields by address |
| `horse.set_age` | `{addr, value: i32}` | Set age |
| `horse.set_max_age` | `{addr, value: i32}` | Set lifespan |
| `horse.clear_tiredness` | `{addr}` | Zero the tired flags |

## Setup

1. Build:
   ```
   cargo build -p horsey-mod --release
   ```
   This produces:
   - `target/x86_64-pc-windows-msvc/release/horsey.dll`
   - `target/x86_64-pc-windows-msvc/release/horsey-inject.exe`

2. Launch `Horsey.exe` normally (via Steam or directly).

3. Inject:
   ```
   target\x86_64-pc-windows-msvc\release\horsey-inject.exe \
     --dll target\x86_64-pc-windows-msvc\release\horsey.dll
   ```
   The injector finds `Horsey.exe` and `CreateRemoteThread`s
   `LoadLibraryW(horsey.dll)` into it.

4. Check the log:
   ```
   type "C:\Games\Steam\steamapps\common\Horsey Game\horsey.log"
   ```
   You should see `horsey-mod: listening on 127.0.0.1:33077`.

5. Read the auth token:
   ```
   type "C:\Games\Steam\steamapps\common\Horsey Game\horsey.auth"
   ```

6. Test:
   ```
   curl -X POST http://127.0.0.1:33077/op \
     -H "X-Ueforge-Auth: <token from horsey.auth>" \
     -d '{"op":"ping"}'
   ```

## Architecture

```
┌──────────────────────────────────────────────────────────┐
│                       modforge                           │
│  HTTP server · op registry · selector grammar · settings │
│  RPG (Effect/Trigger/Skill) · log · scanner · winproc    │
└──────────────────────────────────┬───────────────────────┘
                                   │
        ┌──────────────────────────┼──────────────────────┐
        │                          │                      │
   ┌────▼────┐                ┌────▼─────┐         ┌──────▼──────┐
   │ ueforge │                │unityforge│         │ horsey-mod │
   │  UE5    │                │  Unity   │         │  Native PE  │
   │  UE4SS  │                │ BepInEx  │         │   inject    │
   └─────────┘                └──────────┘         └─────────────┘
```

## Why injector, not proxy DLL

We initially planned to proxy `steam_api64.dll` (rename the original,
drop ours in its place, forward 1,089 Steam API exports). MSVC link.exe's
`.DEF` forwarder support proved brittle: the linker treated `name =
OtherDll.name` as a local alias instead of a PE forwarder, producing 1,089
unresolved-symbol errors.

The injector pattern is:

- **Simpler**: a single `CreateRemoteThread` call.
- **Hot-reload-friendly**: detach via `FreeLibrary`, rebuild, re-inject.
- **No 1,089 forwarders**: only our DllMain is exported.
- **Game-agnostic**: same code injects into any native-PE Windows game.

Tradeoff: the user runs the injector after launching the game (a separate
step). This is fine for development; for end-user distribution we can
add a small launcher EXE that combines "start Horsey via Steam" with
"wait for it to load, then inject".

## Next phases

Currently horsey-mod provides READ + simple WRITE access via the HTTP
control plane. Phase 2 will add:

- **MinHook trampolines** on the 18 game function addresses (see
  `src/targets.rs::fn_addr`). With these, mods can hook
  `apply_gene_to_horse`, `check_horse_eligibility`, `breeding_state_machine`,
  etc., to inject extension behavior.
- **SDL3 input hook** for the hotkey system (Shift+Click, R/F/S/B/T,
  Numpad +/-).
- **Sidecar save state** so per-horse extension fields persist across
  game saves.

## Files

| File | Purpose |
|---|---|
| `src/lib.rs` | DllMain + worker thread + server bootstrap |
| `src/bin/inject.rs` | The injector EXE |
| `src/targets.rs` | Hardcoded function + struct addresses from our decompilation |
| `src/gamestate.rs` | Typed accessors for the GameState global |
| `src/horse.rs` | Typed accessors for the Horse struct |
| `src/ops.rs` | Horsey-specific op registrations |
| `src/snapshot.rs` | The `HorseyState` snapshot returned in every response |

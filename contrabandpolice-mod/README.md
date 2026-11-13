# contrabandpolice-mod

Contraband Police (Steam AppID 756800). Unity 2022.3.62f2, IL2CPP.
Loaded through MelonLoader by `Unityforge.Shim.Melon`, the same path
as mechabellum-mod.

v1 is the control plane only, on port 17186: the unityforge builtin
ops and selectors. Gameplay changes come after research tests show
what the game holds.

## Run

```sh
pwsh -NoProfile -File contrabandpolice-mod/scripts/restart.ps1
```

Builds the mod and the shim, installs MelonLoader from the Schedule 1
install if missing, deploys both into the game's `Mods` folder,
launches the game and waits for the control plane.

## Tests

```sh
k3sc cargo-lock test -p contrabandpolice-mod --test research_load -- --test-threads=1 --nocapture
```

| Test | Question |
|---|---|
| `research_load` | Is the mod loaded, and can it see the game's own code? |

Tests skip when the game is not running.

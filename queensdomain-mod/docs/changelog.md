# queensdomain-mod changelog

## 2026-11-05

- New mod for Queens' Domain (Steam app 1799840, UE 4.27, the first UE4 game in the workspace). Minimal: UE4SS loader, control plane on port 31310, builtin ops, no tabs, no watchers.
- `scripts/restart.ps1` builds, installs UE4SS from Alchemy Factory with every hook off except EngineTick, deploys and launches.
- `tests/research_ustruct_layout.rs` measures the UE 4.27 UStruct and FProperty offsets. Untested: the game has not run with the mod yet.

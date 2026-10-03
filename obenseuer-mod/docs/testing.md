# Testing

> **Authoritative on:** how the mod's tests and research tests run against
> the live game, what the game needs for them, and how to recover or
> investigate without restarting the game.
>
> Index of every game system's doc: [`research.md`](research.md).

## What the game needs

The game must have its "run in background" option on (OptionsMenu.cs:276),
or it stops answering while unfocused ("main-thread queue timed out").
The game only answers while its frames run, so keep the game window
focused while a test starts.

## Running the door timing test

```text
k3sc cargo-lock test -p obenseuer-mod --test research_loading -- --test-threads=1 --nocapture
```

It stops after one door trip (`OBENSEUER_WATCH_TRIPS`, default 1, and
`OBENSEUER_WATCH_SECS`, default 600) and writes `docs/loading-trips.txt`.
Its results: [`doors.md`](doors.md), where a door's time goes.

## Getting unstuck

`reload_save`, and the F7 key, reset the mod (no areas kept loaded, door
patch off, loading priority back) and load the save last loaded. Used
live when the player could not move after a door: the game came back to
one clean area.

## Investigating without restarts

`src/investigate.rs`:

- `reload_save`: loads the save last loaded, as the load menu does
  (SaveController.LoadGameWithMigration, LoadMenu.cs:539), after turning
  `first_copy_wins` off. `research_investigate.rs`: one clean area, 0
  errors, the player saw the loading screen.
- `errors`: what the game logged since a mark, grouped by the game code
  that threw it, read from Application.consoleLogPath.

`restart.ps1`'s in-place swap refuses while patched methods would be left
behind, and first_copy_wins is now always on, so every mod change
restarts the game. That check exists for IL2CPP; whether Mono needs it is
not checked.

# TODO

## Player thirst and hunger rate tweaks

Goal: let the user dial down (or off) how fast the player gets hungry and thirsty. Same vehicle as Better Backpack: a runtime patch via the injected DLL.

What we know so far (needs verification against the SDK):

- The hunger/thirst tick logic lives on the player character or a stat component, probably with float properties like `HungerRate`, `ThirstRate`, or modifier curves.
- The `USurvivalCheatManager` exposes `EnableThirstHunger(bool, ASurvivalPlayerCharacter*)` (visible from the SDK research). That toggles the systems off entirely. Useful as a sanity check that we're touching the right systems.
- The actual rate constants are likely on a stat/data component or a settings asset, not the BP itself.

Open questions:

- What's the property name and class for the hunger rate? (Search Dumper-7 SDK for "Hunger" / "Thirst" / "Starve" / "Dehydrate" properties on float types.)
- Are rates stored as scalar multipliers, per-second decay values, or curves (`UCurveFloat`)?
- Is there a single "stat decay multiplier" we can scale, or do we have to patch each stat independently?
- Do these values replicate in multiplayer? (Probably yes, server-authoritative.)

Implementation sketch:

- Add a `kHungerRateScale` / `kThirstRateScale` constant near the top of `dllmain.cpp` (default 1.0 = vanilla; 0.0 = disabled).
- Add a `PatchPlayerStatRates()` function that walks `GObjects` for the relevant stat component class, finds the rate properties (reflective if possible, hard-coded offset if necessary), and scales.
- Re-apply on the existing 10s rescan loop the same way the inventory patch does.
- Expose toggles via the same compile-time constants pattern, no settings.json yet.

Acceptance criteria when implemented:

- With the DLL injected and `kHungerRateScale = 0.5`, the player's hunger meter drops at half the vanilla rate. Empirically verifiable by sitting still in-game and timing the meter.
- With `kHungerRateScale = 0.0`, the meter does not drop at all.
- The other survival systems (temperature, stamina, health regen) are unaffected.
- Multiplayer behaviour documented (probably won't work for non-host clients).

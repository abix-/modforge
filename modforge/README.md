# modforge

> Engine-agnostic core shared by ueforge (UE5 / UE4SS / Rust)
> and unityforge (Unity Mono / BepInEx / Rust + small C# shim).
>
> Both per-framework crates depend on this crate via
> `modforge = { path = "../modforge" }` and call its modules
> natively. No FFI between Rust crates.

## What lives here

Modules migrate in from `ueforge/src/` under the Phase 0 plan
in [`../docs/unityforge-plan.md`](../docs/unityforge-plan.md).
Final destinations:

| Module | Subject |
|---|---|
| `envelope` | OpResponse + parse_request |
| `ops` | OpDef + OpRegistry + dispatch + list_ops |
| `selector` | grammar parser + SelectorRegistry |
| `settings` | JSON file + debounced save |
| `counters` | AtomicU64 counter + TimeScope + macros |
| `ring` | bounded ring buffer |
| `scanner` | process memory scanner |
| `winproc` | Win32 process probes |
| `server` | tiny_http listener + auth token + body cap |
| `shutdown` | ShutdownRegistry + handler ordering |
| `log` | file + stdout sink + level + format |
| `hot_reload` | protocol types |
| `args` | JSON arg helpers |
| `rpg` | Effect / Trigger / Skill traits + Tracker + XP + persistence + catalog |
| `snapshots` | ProjectionSnapshot generics |
| `debug` | dispatch glue |
| `ui` | declarative tab API (rendering per-framework) |
| `worker` | worker handle trait |

## What does NOT live here

Anything engine-specific:

- UObject SDK / Mono reflection wrappers (in ueforge / unityforge).
- Hook mechanics (UE vtable + PE vs HarmonyLib).
- Main-thread dispatch (PE queue vs Unity Update tick).
- Engine-touching Effect implementations.
- Asset format parsers (uasset vs Unity asset bundles).
- Mod entry shim (UE4SS C++ vs BepInEx C#).

## Layout

```
modforge/
  Cargo.toml             # [lib] crate-type = ["rlib"]
  src/                   # the Rust modules
  spec/                  # JSON schemas, ABNF grammars, op surface docs
  test-corpus/           # request/response pairs both frameworks pass
  client/                # shared HTTP test client (Rust)
  deploy/                # modforge-deploy CLI
  docs/                  # methodology, composition-model, def-registry, naming
```

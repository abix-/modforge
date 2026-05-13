# Selector grammar

A selector is a short string that names a live object in the
running game. Tests, ops, and external clients use selectors so
they never have to embed raw addresses or fragile path strings.

## Grammar (ABNF)

```
selector    = builtin / framework-extension / game-extension
builtin     = addr-form / class-form / first-class-form / singleton-form
addr-form   = "addr:" hex-prefix? 1*HEXDIG
class-form  = "class:" 1*name-char
first-class-form = "first_class:" 1*name-char
singleton-form   = "singleton:" 1*name-char
hex-prefix  = "0x" / "0X"
name-char   = ALPHA / DIGIT / "_" / "."
```

`framework-extension` and `game-extension` selectors are
registered by each framework (ueforge / unityforge) and each
game mod against the same parser at init time.

## Built-in forms (both frameworks ship these)

| Form | Meaning |
|---|---|
| `addr:0x...` | Raw object handle returned by a prior `walk_class` or `list_singletons`. The integer is opaque to the caller |
| `class:Foo` | First live (non-CDO / non-prototype) instance of class `Foo` |
| `first_class:Foo` | Alias for `class:Foo` |
| `singleton:Foo` | Class-default-object equivalent: UE's CDO, Unity's `Singleton<Foo>.Instance` |

## Per-framework extensions

Each framework registers extra resolvers against the same
`SelectorRegistry`. Names are stable across frameworks where the
concept maps cleanly:

| Form | ueforge | unityforge |
|---|---|---|
| `static_instance:Foo` | n/a | Unity's `StaticInstance<Foo>.Instance` |
| `monobehaviour:Foo` | n/a | First active MonoBehaviour of type `Foo` |

Game-mod extensions follow the same shape (`<prefix>:<arg>`)
and register at worker init time. Adding a new selector is one
`SELECTOR_REGISTRY.register(...)` line: no parser edits.

## Resolution

`modforge::selector::resolve(s)` walks the registry. The first
matching resolver returns `Some(Ok(handle))` or
`Some(Err(reason))`. If no resolver matches the prefix, the
overall resolve returns `Err("unknown selector form")`.

## Discovery

`POST /op {"op":"list_selectors"}` returns every registered
selector form + its summary. Auto-generated; no manual list to
maintain.

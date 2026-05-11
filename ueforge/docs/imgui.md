# ImGui

> **Authoritative on:** how a ueforge mod renders ImGui content,
> the safe Rust wrappers around the C++ ImGui API, the `Tab`
> registration surface, and the built-in scanner tab.

ueforge bundles ImGui v1.92.1 (matching UE4SS's bundled version)
and exposes a Rust-friendly API as `ueforge::ui`. Mods declare
tabs in `ModInfo::tabs`; the C++ shim iterates the array and
calls each `Tab::render` once per frame while the tab is
visible.

## Tab registration

```rust
static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    /* ... */
    tabs: &[
        ueforge::TabDef {
            name: "RPG",
            render: rpg::tab::render,    // fn pointer, no captures
        },
        ueforge::TabDef {
            name: "Scanner",
            render: ueforge::ui_scanner::render,
        },
    ],
};
```

`Tab::render` is a `fn()`. A non-capturing function pointer.
You can't close over state at registration; statics + lookup
inside the render body are the way. Tab order in the array is
display order in the ImGui window.

The render thread is UE4SS's render thread, NOT the game thread.
This matters for what's safe to call from inside `render`:

- **Safe**: ImGui calls (`ueforge::ui::*`), reads from
  `Tracker::with_state`, atomic counter loads, snapshot of any
  `Mutex<...>` you own.
- **Risky**: `process_event`, GObjects walks (~150K entries
  per call adds up), heavy field reads on a live UObject.
- **Use the Queue**: heavy work that mutates UObjects should
  enqueue to a game-thread drain via `ueforge::Queue` rather
  than running inline on the render thread.

## ueforge::ui surface

Safe Rust wrappers over the C++ ImGui API. Pass `&str` and Rust
types; ueforge handles the C-string conversion + null-termination
internally.

### Text

```rust
ui::text("Plain text");                        // standard label
ui::text_disabled("Greyed-out hint");          // dim color
ui::text_colored([1.0, 0.5, 0.5, 1.0], "Warn"); // RGBA float
```

### Layout

```rust
ui::separator();                               // horizontal rule
ui::same_line();                               // next item on same row
ui::spacing();                                 // small vertical gap
ui::indent();                                  // push indent
ui::unindent();                                // pop indent
```

### Buttons

```rust
if ui::button("Save") {
    // clicked this frame
}

if ui::button(&format!("+1##{id}")) {           // ##id makes labels unique
    // unique-per-row click handler
}

if ui::small_button("x") { /* ... */ }
```

The `##id` suffix is ImGui's idiom for "show this label, but
key the widget's identity off the suffix." Lets you have many
buttons with the same visible text without PushID/PopID.

### Toggles + sliders

```rust
let mut enabled = true;
if ui::checkbox("Enable feature", &mut enabled) {
    // changed this frame
}

let mut v: f32 = 1.0;
ui::slider_f32("Multiplier", &mut v, 0.0, 5.0);

let mut n: i32 = 50;
ui::slider_i32("Level", &mut n, 0, 100);
```

### Progress / status

```rust
ui::progress_bar(0.42, Some("XP: 4200/10000"));
```

### Disabled-block RAII

```rust
let _d = ui::Disabled::new(!can_spend);
if ui::button("+1") { /* ... */ }   // greyed out + click suppressed if !can_spend
// _d drops here, EndDisabled fires
```

`Disabled` is an RAII guard around `BeginDisabled` / `EndDisabled`.
The `Drop` impl calls `EndDisabled` so unbalanced begins/ends are
impossible.

### Trees / collapsing sections

```rust
if ui::collapsing_header("Stats") {
    ui::text("Health: 100/100");
    ui::text("Stamina: 80/100");
}

if ui::tree_node("Inventory") {
    // ... children ...
    ui::tree_pop();
}
```

### Tables (limited)

```rust
ui::table_columns(3, |row| {
    ui::text("col 1");
    ui::same_line();
    ui::text("col 2");
    ui::same_line();
    ui::text("col 3");
});
```

The table API is intentionally minimal. Complex grids belong
in a dedicated UI mod or a custom render.

## Scanner tab (built-in)

`ueforge::ui_scanner::render` is a complete ImGui tab for the
Cheat-Engine-style memory scanner. Drop it into your `tabs:`
array:

```rust
tabs: &[
    ueforge::TabDef { name: "RPG", render: rpg::tab::render },
    ueforge::TabDef { name: "Scanner", render: ueforge::ui_scanner::render },
],
```

It exposes:
- "Selector" + offset + type + value -> "Scan" button
- Hit list with addresses + values
- "Rescan" with new value or filter mode
- "Freeze" selected hit
- Active freezes list with "Unfreeze" buttons

Backed by the scanner ops (see [memory-tools.md](memory-tools.md));
no game-specific configuration. g2rpg doesn't include it (RPG tab
only); ows-tweaks does as a reference.

## RPG tab (template)

`ueforge::rpg::tab::render(tracker, toggle_fns)` is the canonical
RPG tab. See [rpg.md](rpg.md) for the full pattern.

```rust
ueforge::TabDef {
    name: "RPG",
    render: || ueforge::rpg::tab::render(&TRACKER, Some(&TOGGLES)),
}
```

## Conventions

### Don't allocate per-row

The tab body runs every frame the tab is visible (~144Hz on a
high-refresh monitor). `format!` per-row allocates. The g2rpg
tab does this today (the old code was straightforward to
migrate; counters track the cost). For a high-traffic tab,
cache strings between renders or use static `&str` where
possible.

### Don't grab heavy locks

Call `Tracker::with_state` once per render, copy the fields you
need, release. Don't hold the tracker lock across an ImGui
group of widgets that might trigger a callback that re-locks
(spend/refund mutate state under the same lock).

### ##id discipline

Every interactive widget needs a stable unique identity for
ImGui state to track properly. The `##id` suffix is the
cleanest way. Buttons in a per-row loop look like
`format!("+1##{}", skill.id)`. Without unique ids, ImGui treats
every button labeled "+1" as the same widget and click handling
breaks.

### Default summon key

UE4SS controls the ImGui summon key. Default is `Insert`.
Don't try to override. UE4SS owns the toggle.

## C++ bridge details

ueforge's C++ side (in `cpp/ueforge_ui.cpp`) provides
`extern "C"` shims that the Rust code calls. The bridge owns:

- ImGui context binding (UE4SS exposes it via two function
  pointers we call at every frame entry).
- Lifetime management (don't free buffers ImGui still owns).
- C-string null-terminator placement (Rust `&str` -> stack
  buffer copy + null).

If you need an ImGui call ueforge doesn't expose, add it to
`ueforge::ui` and the C bridge in the same commit. Don't FFI
directly from your mod. The framework owns the bridge.

## ImGui version

v1.92.1 vendored at `ueforge/cpp/imgui/`. Matches UE4SS's bundle
exactly. Don't bump independently. A version skew between our
bundle and UE4SS's at runtime causes context state corruption.
The right path is: UE4SS upstream bumps, we sync. Until then,
don't touch the vendored copy.

## Cross-references

- [lifecycle.md](lifecycle.md) -- `Tab` registration in `ModInfo`
- [rpg.md](rpg.md). The canonical RPG tab template
- [memory-tools.md](memory-tools.md). The Scanner tab's
  underlying ops
- [pe-queue.md](pe-queue.md). Queue heavy work to the game
  thread instead of doing it on the render thread

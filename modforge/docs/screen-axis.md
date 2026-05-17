# Screen axis: capture + recognition + annotated feedback

> **Status:** design (proposed 2026-05-17). Not yet shipped. Parallel to
> [`input-prior-art.md`](input-prior-art.md): once shipped, mods (and
> Claude) will have a third I/O axis. **vision**, alongside the
> existing **data** (HTTP get/set ops) and **input** (mouse/keyboard
> synthesis) axes.

## Why this exists

Mods today operate blind in one dimension: they can READ internal state
via HTTP and WRITE input via the `input.*` cmdlets, but they cannot SEE
what the game is rendering. For UI-driven features and for an LLM
operator deciding what to do next, this is a hard ceiling.

Concrete cases that need vision:

- "Which location is the cursor pointing at on the world map?". The
  game only renders the location name as a hover tooltip, not as
  internal state we can read.
- "Is this the main menu, the pause menu, or a modal dialog?".
  determinable from gamestate sometimes, often only from pixels.
- Visual regression: confirm a render trampoline actually changed what's
  on screen, not just what's in the data buffer.
- Closed-loop Claude operation: capture frame -> annotated image ->
  Claude picks an action -> input cmdlet -> repeat.

## Decomp-first before vision

**Vision is the last layer, not the first.** For any feature that wants
pixel input, walk the question hierarchy:

1. **Does gamestate already hold the answer?** Read a field. Done.
   Examples: `active_scene_id` answers "world map or in a location";
   `gamestate.owned_horses` answers "what horses exist".
2. **Does a vanilla function compute the answer?** Resolve via
   `patternsleuth` + `TargetRegistry`, expose as `vanilla.invoke`.
   Hook it if we want to see it on every frame. Examples (Horsey):
   the tooltip-text resolver, the cursor-to-location function, the
   world-map projection function. All exist in the binary because
   the game itself renders the answer.
3. **Only then: vision.** Use the three-layer capture + recognition
   stack below for things the decomp doesn't expose: animated popups,
   long-tail UI, visual regression testing, future content the mod
   has not pattern-resolved yet.

Why this matters: a pHash sliding window costs sub-millisecond and a
ML model costs tens of milliseconds, but a `vanilla.invoke` of the
game's own resolver costs ~one indirect call AND returns the canonical
answer (no false positives, no thresholds, no template maintenance per
game update). The decomp-first pass also tends to surface a richer
structured answer than vision would: not "an icon at (x,y)" but
"`{id: 7, name: \"circus\", world_pos, ...}`" directly.

Per-game first move when adopting this axis: do one decomp pass on the
candidate vision feature BEFORE writing any recognizer. The Horsey
world-map case is the canonical worked example, see
[`horsey-mod/docs/world-map-detection.md`](../../horsey-mod/docs/world-map-detection.md)
Layer 0.

This is the same posture as the [decomp-first rule for writes](https://github.com/abix-/modforge):
when the game has an in-game editor for X (CRISPR Lab for genes), read
its decomp first. Here we extend it: when the game has an in-game
*reader* for X (tooltip, HUD, hover label), read its decomp first.

## Three-layer design (mirrors the input axis)

| Layer | What | Cost | When to use |
|---|---|---|---|
| **L1** | OS-level capture via [`windows-capture`](https://github.com/NiiightmareXD/windows-capture) (Windows Graphics Capture API). No game hooks; captures by HWND. | Low; one dep. | Default. Works for any game, any time. |
| **L2** | In-process Present hook readback (piggyback on `hudhook`). `CopyResource` back buffer -> `D3D11_USAGE_STAGING` texture -> `Map()` on background thread. | Medium; needs D3D11 plumbing. | Zero-latency exact-frame capture; when L1's WGC frame-rate / latency pinches. |
| **L3** | Per-game `ScreenSurface` trait: a mod can override capture with a game-specific path (e.g. read a known framebuffer pointer directly). | High per game; high fidelity. | Rarely needed. Open the slot now, fill it later. |

Default backend selection (parallel to input):
- L3 if `ScreenSurface` registered
- L2 if Present hook is armed (hudhook is up)
- L1 otherwise

## Recognition stack (on top of capture)

A raw frame is BGRA bytes; useless to an LLM. We need a **recognition
layer** that turns pixels into structured marks.

### Two complementary approaches

1. **Ground-truth annotation** (cheapest, highest leverage when applicable).
   The mod already knows what's on screen via internal state. For each
   known entity (horse, building, HUD field), project its game-coords
   to screen-coords and draw a numbered bounding box + semantic label.
   Requires a `game_to_screen(...)` calibration per game; Horsey has
   one already from the HK1 work.

2. **Vision recognition** (for the unknown).
   For UI the mod doesn't have state hooks for (menu buttons, dialog
   text, tooltip popups), run a generic parser:
   - Icon detection: per-game template / perceptual-hash library, or
     a YOLO model (e.g. OmniParser V2's fine-tuned YOLOv8-nano) via
     [`ort`](https://github.com/pykeio/ort) (ONNX Runtime for Rust).
   - OCR: [`ocrs`](https://github.com/robertknight/ocrs) (pure Rust,
     ML-based, no Tesseract install), Windows.Media.Ocr via
     [`uni-ocr`](https://crates.io/crates/uni-ocr), or
     [`tesseract`](https://docs.rs/tesseract) / `leptess` for the
     classic engine.
   - Template / pixel matching:
     [`imageproc::template_matching`](https://docs.rs/imageproc/latest/imageproc/template_matching/)
     with `MatchTemplateMethod::CrossCorrelationNormalized`.
   - Perceptual hashing:
     [`img_hash`](https://github.com/abonander/img_hash) /
     [`image_hasher`](https://crates.io/crates/image_hasher). DCT pHash
     on a 32x32 downscale -> 64-bit fingerprint, compare via Hamming
     distance. Fast enough to hash thousands of sliding windows per
     frame.

### Set-of-Mark (SoM) prompting

The shipped artifact for any LLM consumer is an **annotated PNG +
structured JSON mark list**, the Set-of-Mark pattern popularized by
[Microsoft OmniParser V2 (Feb 2025)](https://www.microsoft.com/en-us/research/articles/omniparser-v2-turning-any-llm-into-a-computer-use-agent/):

```jsonc
{
  "path": "target/screens/2026-05-17-1432.png",
  "marks": [
    { "id": 1, "kind": "horse",    "label": "Tomtato (skill 47, tired)", "bbox": [412, 308, 64, 64], "source": "groundtruth" },
    { "id": 2, "kind": "hud_text", "label": "Money: $4,250",             "bbox": [12,  10,  120, 24], "source": "groundtruth" },
    { "id": 3, "kind": "button",   "label": "Sleep",                      "bbox": [1820, 1010, 92, 48], "source": "vision" }
  ]
}
```

Claude reads the PNG (sees the screen with numbered overlays) AND the
JSON (cross-references labels to internal state). Decides "click 3" ->
`input.click_mark { id: 3 }` -> mod looks up bbox -> `input.mouse.click_at(center)`.

This dwarfs OmniParser's blind-vision baseline because ground-truth
annotations carry semantic information the pixels alone cannot.

## Proposed module shape

```
modforge::screen
  Backend::{L1, L2, L3}
  trait ScreenSurface { fn capture_hwnd(hwnd) -> Frame; ... }
  struct Frame { width, height, stride, pixels: Vec<u8> /* BGRA */ }
  fn capture(backend) -> Frame
  fn annotate(frame, marks) -> Frame                  // draws boxes + numbers
  fn save_png(frame, path) -> ()
  fn perceptual_hash(frame, region) -> ImageHash
  fn template_match(frame, template, threshold) -> Vec<Hit>
  fn ocr(frame, region) -> Vec<TextRegion>

ops:
  screen.capture {hwnd?, region?, save?: bool}
      -> { path?, width, height, bytes_b64? }
  screen.annotated {marks?: "auto"|[...]}
      -> { path, marks: [...] }                       -- groundtruth + vision SoM
  screen.ocr {region?, engine: "ocrs"|"win"|"tess"}
      -> { texts: [{text, bbox, score}] }
  screen.match {template_path|template_b64, region?, threshold?}
      -> { hits: [{x, y, score}] }
  screen.click_mark {id}
      -> dispatches input.mouse.click_at(mark.bbox.center)
  screen.diff {against: "last"|<id>}
      -> { changed_regions: [bbox], score }
```

## Per-game extension points

Each game-mod implements a `GameAnnotator` (next to its existing
`InputSurface`):

```rust
pub trait GameAnnotator: Send + Sync {
    fn game_to_screen(&self, game_coords: (f32, f32)) -> Option<(i32, i32)>;
    fn enumerate_marks(&self, frame: &Frame) -> Vec<Mark>;  // groundtruth only
}
```

`screen.annotated` runs the game's `enumerate_marks` for the ground
truth pass, then runs vision recognition on the *unannotated* regions
to fill in long-tail UI.

## Build order (recommended)

1. **L1 capture + `screen.capture`**. One session. windows-capture
   crate + HTTP op that saves PNG to `target/screens/`. Smoke test:
   capture a frame, assert dims match the game window.
2. **Annotation primitives** -- `annotate(frame, marks) -> Frame` via
   the [`image`](https://crates.io/crates/image) +
   [`imageproc`](https://crates.io/crates/imageproc) crates. Pure
   function, easily unit-tested.
3. **`GameAnnotator` trait + horsey impl**. Horse positions, HUD
   readouts, scene label. No vision yet; just groundtruth.
4. **OCR layer (`screen.ocr`)** -- `ocrs` default; Windows.Media.Ocr
   fallback. Test: OCR the money HUD and compare against `game.money.get`.
5. **Template / pHash layer (`screen.match`)**. Imageproc +
   image_hasher.
6. **Per-game template libraries**. Auto-collected via input axis
   driving the game (see horsey's
   [`world-map-detection.md`](../../horsey-mod/docs/world-map-detection.md)).
7. **L2 Present-hook readback**. Only if L1 latency / frame-rate
   pinches in practice. OBS's
   [`dxgi-capture.cpp`](https://github.com/obsproject/obs-studio/blob/master/plugins/win-capture/graphics-hook/dxgi-capture.cpp)
   is the reference implementation.
8. **OmniParser sidecar (optional)**. Run
   [Microsoft OmniParser V2](https://github.com/microsoft/OmniParser)
   as a Python sidecar over HTTP for generalist UI parsing when the
   per-game template library doesn't cover the current view.

## Tests-first plan

Per the workspace tests-first rule:

- `tests/screen_smoke.rs` (modforge): capture a frame from any
  window-handle test harness, assert non-empty dims + 4-byte BGRA
  stride.
- `tests/screen_annotate_unit.rs` (modforge): unit-test `annotate(...)`
  draws boxes at the right pixel offsets. No game required.
- `horsey-mod/tests/screen_money_matches_state.rs`: capture frame,
  OCR the money HUD region, assert equal to `game.money.get`. Closes
  the loop "do we SEE what the gamestate says".
- `horsey-mod/tests/screen_groundtruth_horses.rs`: capture frame in a
  known location, annotate via `GameAnnotator`, assert one mark per
  owned horse with `kind="horse"` and a non-empty `label`.

## Crate decisions (provisional)

| Concern | Crate | Why |
|---|---|---|
| Window capture | [`windows-capture`](https://crates.io/crates/windows-capture) | Fastest WGC wrapper; HWND-targeted; works across games. |
| Image I/O | [`image`](https://crates.io/crates/image) | Standard. PNG encode for save_png. |
| Annotation drawing | [`imageproc`](https://crates.io/crates/imageproc) | Boxes, text, lines. Already pulled by template matching. |
| Template match | `imageproc::template_matching` | Normalized cross-correlation. |
| Perceptual hash | [`image_hasher`](https://crates.io/crates/image_hasher) | Maintained fork of `img_hash`. DCT pHash. |
| OCR | [`ocrs`](https://github.com/robertknight/ocrs) | Pure Rust, ML-based, no native install. Windows.Media.Ocr via [`uni-ocr`](https://crates.io/crates/uni-ocr) as a free fallback. |
| ONNX inference (vision models) | [`ort`](https://github.com/pykeio/ort) | If/when we host OmniParser's YOLO/Florence weights locally. |
| Present hook (L2) | existing `hudhook` | Already armed for overlay; add a sibling readback path. |

## Open questions

- L1 windows-capture frame-rate when the game is fullscreen-exclusive
  vs borderless. WGC is designed for the latter; needs measurement on
  Horsey's actual window mode.
- Annotation overlay drawn ON the captured PNG (post-process) vs IN
  the hudhook overlay (visible to the player too). The post-process
  path is simpler and avoids interfering with normal play.
- Cross-game `GameAnnotator` discovery: does modforge auto-detect it
  from the registered surfaces, or does the per-mod attach hook
  register one explicitly the way `input_surface::register()` does?
  Default: explicit, parallel to input.

## References

- Set-of-Mark prompting + UI parsing:
  - [Microsoft OmniParser V2](https://www.microsoft.com/en-us/research/articles/omniparser-v2-turning-any-llm-into-a-computer-use-agent/) ([GitHub](https://github.com/microsoft/OmniParser), [HuggingFace](https://huggingface.co/microsoft/OmniParser), [LearnOpenCV](https://learnopencv.com/omniparser-vision-based-gui-agent/))
  - [Anthropic Computer Use](https://docs.claude.com/en/docs/agents-and-tools/tool-use/computer-use-tool)
- Capture:
  - [`windows-capture`](https://github.com/NiiightmareXD/windows-capture)
  - [OBS `dxgi-capture.cpp`](https://github.com/obsproject/obs-studio/blob/master/plugins/win-capture/graphics-hook/dxgi-capture.cpp) reference for L2
  - [spazzarama 2011 D3D9/10/11 capture](https://spazzarama.com/2011/03/14/c-screen-capture-and-overlays-for-direct3d-9-10-and-11-using-api-hooks/)
- Recognition:
  - [`imageproc::template_matching`](https://docs.rs/imageproc/latest/imageproc/template_matching/)
  - [`img_hash`](https://github.com/abonander/img_hash) / [`image_hasher`](https://crates.io/crates/image_hasher)
  - [`ocrs`](https://github.com/robertknight/ocrs)

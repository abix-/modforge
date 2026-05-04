# Grounded 2 Mods -- inspection, reverse-engineering, and DIY notes

Notes, tooling, and worked examples for inspecting, debugging, and
authoring mods for Grounded 2 (Obsidian, Unreal Engine 5.4).

This repo started as a focused investigation of why "Bigger Backpack"
stopped working, and ended up covering generic UE5 modding methodology
applied to Grounded 2 specifically.

## Contents

- [inspection-guide.md](inspection-guide.md) -- the main document.
  Workflow, tooling, two worked examples (All-in-One Player Tweaks
  and Bigger Backpack), the SDK-derived path to a DIY backpack mod,
  and external-resource references.
- [scripts/](scripts/) -- small Python utilities used during the
  investigation.
  - `dump_strings.py` -- pull readable strings out of a cooked
    `.uasset` / `.uexp` pair, bucketed by pattern (UE names, paths,
    prose).
  - `read_property.py` -- decode a specific UE PropertyTag value
    from a cooked legacy `.uasset` + `.uexp`. Used here to read
    `DefaultMaxSize` directly without UAssetGUI or a `.usmap`
    mappings file.

## TL;DR for "I want a bigger backpack"

The player's main backpack capacity is controlled by:

```
Class:     Maine.UInventoryComponent
Property:  int32 DefaultMaxSize  (offset 0x01E0)
```

`BP_SurvivalPlayerCharacter` instantiates a main `InventoryComponent`
(40 vanilla) and a `MountInventoryComponent` (saddlebag) as instanced
sub-objects. To grow the main backpack, override `DefaultMaxSize` on
the main `InventoryComponent` sub-object's CDO defaults.

The plain "AIO Player Tweaks v13.1.6" Nexus mod does NOT do this
(verified -- main backpack stays at 40, only saddlebag is bumped to
48). The "60-slot" variant in the same mod's Optional Files does
this single byte-level override. See [inspection-guide.md](inspection-guide.md)
for the byte offset and the exact one-shot patch.

## Tooling installed locally for this work

```
C:\Tools\retoc\retoc.exe       v0.1.5      (CLI Zen IoStore packer)
C:\Tools\repak\repak.exe       v0.2.3      (CLI legacy pak packer)
C:\Tools\FModel\FModel.exe     Dec 2025    (GUI cooked-asset browser)
```

All three are portable single-binary downloads from GitHub releases.

## Game build referenced in this doc

```
Grounded 2 Steam build, version ++Augusta+release-0.4.0.2-CL-2673661
UE 5.4 (TOC version ReplaceIoChunkHashWithIoHash,
         container header SoftPackageReferencesOffset)
Unencrypted IoStore. Standard UE5 modding tooling applies as-is.
```

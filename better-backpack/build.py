"""Build the Better Backpack mod for Grounded 2.

Reads settings.json, patches two vanilla cooked assets, repacks as Zen IoStore.

Patches applied:
  1. BP_SurvivalPlayerCharacter.uexp: first DefaultMaxSize PropertyTag
     (the main inventory component) is set to settings.slot_count.
     The second PropertyTag (mount saddlebag, vanilla 30) is left alone.
  2. UI_Container_BackpackSide.uexp: MaxRows PropertyTag is set to
     ceil(slot_count / MAX_COLUMNS), so the inventory grid renders
     enough rows to show all slots.

Tools and vanilla cache paths are constants near the top of this file.
Adjust them if your environment differs.

Vanilla cache prep (run once):
    retoc to-legacy --filter BP_SurvivalPlayerCharacter \\
        <Grounded2 Paks dir> /c/Tools/work/vanilla_legacy/vanilla_bp.pak
    repak unpack /c/Tools/work/vanilla_legacy/vanilla_bp.pak \\
        --output /c/Tools/work/vanilla_legacy/bp

    retoc to-legacy --filter UI_Container_BackpackSide \\
        <Grounded2 Paks dir> /c/Tools/work/vanilla_legacy/vanilla_widget.pak
    repak unpack /c/Tools/work/vanilla_legacy/vanilla_widget.pak \\
        --output /c/Tools/work/vanilla_legacy/widget
"""
import json
import math
import shutil
import struct
import subprocess
import sys
from pathlib import Path

# Tools (single-binary CLI downloads from GitHub releases).
RETOC = Path(r"C:\Tools\retoc\retoc.exe")
REPAK = Path(r"C:\Tools\repak\repak.exe")

# Cached vanilla extractions. Run the prep commands in the docstring once.
VANILLA_BP_DIR = Path(r"C:\Tools\work\vanilla_legacy\bp")
VANILLA_WIDGET_DIR = Path(r"C:\Tools\work\vanilla_legacy\widget")

# Asset paths inside the unpacked vanilla legacy tree.
BP_REL = Path("Augusta/Content/Blueprints/Player/BP_SurvivalPlayerCharacter")
WIDGET_REL = Path("Augusta/Content/UI/Container/UI_Container_BackpackSide")

# Engine constants verified against the SDK (UI_InventoryGrid CDO).
MAX_COLUMNS = 10

# retoc to-zen engine version that produces TOC + container header bytes
# matching the shipping Grounded 2 build (UE 5.4 release-0.4.0.2).
# Empirically UE5_6 in retoc is the right name for this game's IoStore format.
ZEN_VERSION = "UE5_6"


def parse_name_table(uasset: bytes) -> list[str]:
    """Walk the .uasset cooked legacy name table and return ordered FName strings.

    UE FName entries: int32 length (positive = ASCII, negative = UTF-16),
    followed by the bytes (length includes null terminator), followed by 4 bytes
    of hash data. We scan for valid entries and pick the largest contiguous run.
    """
    candidates = []
    i = 0
    while i < len(uasset) - 8:
        length = struct.unpack_from("<i", uasset, i)[0]
        if length <= 0 or length > 256:
            i += 1
            continue
        text_bytes = uasset[i + 4 : i + 4 + length - 1]
        null_pos = i + 4 + length - 1
        if null_pos >= len(uasset) or uasset[null_pos] != 0:
            i += 1
            continue
        try:
            name = text_bytes.decode("ascii")
        except UnicodeDecodeError:
            i += 1
            continue
        if not name or any(c < 32 and c != 9 for c in text_bytes):
            i += 1
            continue
        entry_size = 4 + length + 4
        candidates.append((i, name))
        i += entry_size

    if not candidates:
        return []

    groups = []
    current = [candidates[0]]
    for prev, item in zip(candidates, candidates[1:]):
        if item[0] - prev[0] < 200:
            current.append(item)
        else:
            groups.append(current)
            current = [item]
    groups.append(current)
    longest = max(groups, key=len)
    return [name for _, name in longest]


def find_int_property_hits(uasset: bytes, uexp: bytes, prop: str) -> list[tuple[int, int]]:
    """Find every IntProperty PropertyTag for `prop` in the .uexp.

    Returns a list of (value_offset_in_uexp, current_int32_value), in document
    order. The cooked legacy PropertyTag layout is:

        offset 0   FName Key   (4 bytes name index, 4 bytes name number)
        offset 8   FName Type  (8 bytes, type=IntProperty)
        offset 16  int32 ArrayIndex
        offset 20  int32 Size
        offset 24  uint8 HasPropertyGuid
        offset 25  int32 Value     (when HasPropertyGuid is 0, which is typical)

    We do not handle the HasPropertyGuid=1 case here; none of the properties we
    target use it, but the build script verifies the byte at offset 24 is zero.
    """
    names = parse_name_table(uasset)
    if prop not in names or "IntProperty" not in names:
        return []
    name_idx = names.index(prop)
    int_idx = names.index("IntProperty")
    name_tag = struct.pack("<II", name_idx, 0)
    type_tag = struct.pack("<II", int_idx, 0)

    hits = []
    pos = 0
    while True:
        p = uexp.find(name_tag, pos)
        if p < 0:
            break
        if uexp[p + 8 : p + 16] == type_tag:
            if p + 25 + 4 > len(uexp):
                break
            if uexp[p + 24] != 0:
                # HasPropertyGuid not handled.
                pos = p + 1
                continue
            value_offset = p + 25
            value = struct.unpack_from("<i", uexp, value_offset)[0]
            hits.append((value_offset, value))
        pos = p + 1
    return hits


def patch_int32(path: Path, offset: int, new_value: int) -> int:
    """Overwrite a single int32 in a file. Returns the previous value."""
    data = bytearray(path.read_bytes())
    old = struct.unpack_from("<i", data, offset)[0]
    data[offset : offset + 4] = struct.pack("<i", new_value)
    path.write_bytes(data)
    return old


def must_exist(path: Path, label: str):
    if not path.exists():
        print(f"!! missing {label}: {path}")
        sys.exit(2)


def main() -> int:
    here = Path(__file__).parent
    settings = json.loads((here / "settings.json").read_text())

    slot_count = int(settings["slot_count"])
    load_priority = int(settings["load_priority"])
    output_basename = settings["output_basename"]
    target_max_rows = math.ceil(slot_count / MAX_COLUMNS)

    print(f"slot_count        = {slot_count}")
    print(f"max_columns       = {MAX_COLUMNS}")
    print(f"target_max_rows   = ceil({slot_count} / {MAX_COLUMNS}) = {target_max_rows}")
    print(f"load_priority     = {load_priority}")
    print(f"output_basename   = {output_basename}")

    must_exist(RETOC, "retoc.exe")
    must_exist(REPAK, "repak.exe")
    must_exist(VANILLA_BP_DIR, "vanilla BP cache dir")
    must_exist(VANILLA_WIDGET_DIR, "vanilla widget cache dir")

    bp_src_uasset = VANILLA_BP_DIR / BP_REL.with_suffix(".uasset")
    bp_src_uexp = VANILLA_BP_DIR / BP_REL.with_suffix(".uexp")
    widget_src_uasset = VANILLA_WIDGET_DIR / WIDGET_REL.with_suffix(".uasset")
    widget_src_uexp = VANILLA_WIDGET_DIR / WIDGET_REL.with_suffix(".uexp")
    must_exist(bp_src_uasset, "vanilla BP .uasset")
    must_exist(bp_src_uexp, "vanilla BP .uexp")
    must_exist(widget_src_uasset, "vanilla widget .uasset")
    must_exist(widget_src_uexp, "vanilla widget .uexp")

    # Fresh build dir.
    work = here / "build"
    if work.exists():
        shutil.rmtree(work)
    work.mkdir()

    # Stage with package paths preserved (repak respects directory layout
    # when computing internal pak entries).
    bp_dst_uasset = work / BP_REL.with_suffix(".uasset")
    bp_dst_uexp = work / BP_REL.with_suffix(".uexp")
    widget_dst_uasset = work / WIDGET_REL.with_suffix(".uasset")
    widget_dst_uexp = work / WIDGET_REL.with_suffix(".uexp")
    for d in [bp_dst_uasset, widget_dst_uasset]:
        d.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy(bp_src_uasset, bp_dst_uasset)
    shutil.copy(bp_src_uexp, bp_dst_uexp)
    shutil.copy(widget_src_uasset, widget_dst_uasset)
    shutil.copy(widget_src_uexp, widget_dst_uexp)

    so_src = VANILLA_BP_DIR / "scriptobjects.bin"
    if so_src.exists():
        shutil.copy(so_src, work / "scriptobjects.bin")

    # Patch BP: first DefaultMaxSize is the main inventory component.
    bp_hits = find_int_property_hits(
        bp_dst_uasset.read_bytes(), bp_dst_uexp.read_bytes(), "DefaultMaxSize"
    )
    print("\nBP_SurvivalPlayerCharacter DefaultMaxSize hits:")
    for off, val in bp_hits:
        print(f"  offset {off:8d}  current value {val}")
    if not bp_hits:
        print("!! no DefaultMaxSize PropertyTag found in vanilla BP")
        return 3
    main_offset, main_old = bp_hits[0]
    if main_old != 40:
        print(f"!! WARNING: first DefaultMaxSize is {main_old}, vanilla expected 40")
        print("   patching anyway, but verify in-game that the right component was hit")
    patch_int32(bp_dst_uexp, main_offset, slot_count)
    print(f"  patched first hit (main backpack): {main_old} -> {slot_count}")

    # Patch host widget MaxRows.
    w_hits = find_int_property_hits(
        widget_dst_uasset.read_bytes(), widget_dst_uexp.read_bytes(), "MaxRows"
    )
    print("\nUI_Container_BackpackSide MaxRows hits:")
    for off, val in w_hits:
        print(f"  offset {off:8d}  current value {val}")
    if not w_hits:
        print("!! no MaxRows PropertyTag found in vanilla widget")
        return 4
    rows_offset, rows_old = w_hits[0]
    if rows_old != 4:
        print(f"!! WARNING: vanilla MaxRows is {rows_old}, expected 4")
    patch_int32(widget_dst_uexp, rows_offset, target_max_rows)
    print(f"  patched MaxRows: {rows_old} -> {target_max_rows}")

    # Pack into a legacy pak.
    legacy_pak = work / "legacy.pak"
    print(f"\nrepak pack -> {legacy_pak}")
    subprocess.run([str(REPAK), "pack", str(work), str(legacy_pak)], check=True)

    # Convert to Zen IoStore.
    dist = here / "dist"
    dist.mkdir(exist_ok=True)
    pak_basename = f"{output_basename}_{load_priority:05d}_P"
    output_utoc = dist / f"{pak_basename}.utoc"
    # Clean any previous build output so retoc does not pick stale files.
    for ext in ("pak", "ucas", "utoc"):
        old = dist / f"{pak_basename}.{ext}"
        if old.exists():
            old.unlink()
    print(f"retoc to-zen --version {ZEN_VERSION} -> {output_utoc}")
    subprocess.run(
        [str(RETOC), "to-zen", "--version", ZEN_VERSION, str(legacy_pak), str(output_utoc)],
        check=True,
    )

    print("\nBuilt:")
    for ext in ("pak", "ucas", "utoc"):
        f = dist / f"{pak_basename}.{ext}"
        if f.exists():
            print(f"  {f}  ({f.stat().st_size:,} bytes)")
        else:
            print(f"  !! missing: {f}")

    print("\nInstall by copying the three dist/ files into:")
    print(r"  C:\Games\Steam\steamapps\common\Grounded2\Augusta\Content\Paks\")
    return 0


if __name__ == "__main__":
    sys.exit(main())

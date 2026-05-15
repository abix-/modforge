"""Diff save_A.dat vs save_B.dat. Walk the horse roster in each and compare."""
import struct
from pathlib import Path

A = Path(r"C:/code/horsey-mods/save-snapshots/save_A.dat").read_bytes()
B = Path(r"C:/code/horsey-mods/save-snapshots/save_B.dat").read_bytes()
print(f"A: {len(A)} bytes")
print(f"B: {len(B)} bytes")
print(f"delta: {len(B) - len(A):+d} bytes")
print()


def u32(d, off):
    return struct.unpack_from("<I", d, off)[0]


def i32(d, off):
    return struct.unpack_from("<i", d, off)[0]


HEADER = 20


def walk_roster(d):
    off = HEADER
    horses = []
    while off < len(d):
        if off + 4 > len(d):
            break
        L = u32(d, off)
        if not (1 <= L <= 64):
            break
        name = d[off + 4:off + 4 + L]
        try:
            name.decode("utf-8")
        except UnicodeDecodeError:
            break
        p = off + 4 + L
        if p + 22 > len(d):
            break
        cc = u32(d, p + 18)
        if cc > 50:
            break
        end = p + 22 + 4 * cc
        horses.append(dict(
            off=off, end=end, size=end - off,
            name=name.decode("utf-8"),
            flag_a=d[p], flag_b=d[p + 1], flag_c=d[p + 2], flag_d=d[p + 3],
            flag_e=d[p + 4], pop_id=d[p + 5],
            parent_a=i32(d, p + 6), parent_b=i32(d, p + 10),
            unknown1=u32(d, p + 14), child_count=cc,
            children=[i32(d, p + 22 + 4 * k) for k in range(cc)],
        ))
        off = end
    return horses, off


hA, endA = walk_roster(A)
hB, endB = walk_roster(B)
print(f"A roster: {len(hA)} horses, ends 0x{endA:x}")
print(f"B roster: {len(hB)} horses, ends 0x{endB:x}")
print()

# Compare by name
names_A = {h["name"]: h for h in hA}
names_B = {h["name"]: h for h in hB}

added = [n for n in names_B if n not in names_A]
removed = [n for n in names_A if n not in names_B]
common = [n for n in names_A if n in names_B]

print(f"Horses added in B: {len(added)}")
for n in added:
    print(f"  + {n!r}")
print(f"Horses removed in B: {len(removed)}")
for n in removed:
    h = names_A[n]
    print(f"  - {n!r}  pop_id={h['pop_id']}  flags=({h['flag_a']},{h['flag_b']},{h['flag_c']},{h['flag_d']},{h['flag_e']})")
print()

# For common horses, compare every field
print("Field changes for common horses:")
changes_per_field = {}
field_changes = []
for n in common:
    a, b = names_A[n], names_B[n]
    diffs = []
    for k in ("flag_a", "flag_b", "flag_c", "flag_d", "flag_e", "pop_id",
             "parent_a", "parent_b", "unknown1", "child_count"):
        if a[k] != b[k]:
            diffs.append(f"{k}: {a[k]} -> {b[k]}")
            changes_per_field[k] = changes_per_field.get(k, 0) + 1
    if a["children"] != b["children"]:
        diffs.append(f"children: {a['children']} -> {b['children']}")
        changes_per_field["children"] = changes_per_field.get("children", 0) + 1
    if diffs:
        field_changes.append((n, diffs))

if not field_changes:
    print("  (no field changes in common horses)")
else:
    for n, diffs in field_changes[:20]:
        print(f"  {n!r}:")
        for d in diffs:
            print(f"      {d}")
    print(f"  ... ({len(field_changes)} horses with field changes)")
print()
print("Summary of which fields changed:")
for k, c in sorted(changes_per_field.items(), key=lambda x: -x[1]):
    print(f"  {k}: {c} horses")

# Also compare the post-roster region. Since sizes differ, the post-roster region in B
# may be at a different offset. Compare relative to roster end.
print()
print("=" * 60)
print("Post-roster region comparison")
print("=" * 60)
print(f"A: post-roster region 0x{endA:x}..0x{len(A):x} ({len(A) - endA} bytes)")
print(f"B: post-roster region 0x{endB:x}..0x{len(B):x} ({len(B) - endB} bytes)")
print(f"delta in post-roster: {(len(B) - endB) - (len(A) - endA):+d} bytes")

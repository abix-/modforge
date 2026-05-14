"""Map out save1.dat structure. Read-only."""
import struct
from pathlib import Path

SAVE = Path(r"C:/Games/Steam/steamapps/common/Horsey Game/save/save1.dat")
data = SAVE.read_bytes()
print(f"size: {len(data)} bytes (0x{len(data):x})\n")


def u32(off):
    return struct.unpack_from("<I", data, off)[0]


def i32(off):
    return struct.unpack_from("<i", data, off)[0]


HEADER = 20

# Block 1: horse roster (we already understand this).
print("=" * 70)
print("BLOCK 1: horse roster (0x14..)")
print("=" * 70)
off = HEADER
horses = []
while off < len(data):
    if off + 4 > len(data):
        break
    L = u32(off)
    if not (1 <= L <= 64):
        break
    name = data[off + 4:off + 4 + L]
    # Allow extended UTF-8 chars too (not just ASCII)
    try:
        name.decode("utf-8")
    except UnicodeDecodeError:
        break
    p = off + 4 + L
    if p + 22 > len(data):
        break
    child_count = u32(p + 18)
    if child_count > 50:
        break
    rec_end = p + 22 + 4 * child_count
    horses.append(dict(off=off, name=name.decode("utf-8"), end=rec_end, size=rec_end-off))
    off = rec_end

print(f"Parsed {len(horses)} horse records. Ends at 0x{off:x}.")
print(f"Avg record size: {sum(h['size'] for h in horses)/len(horses):.1f} bytes")
print()

# Block 2: starts at off. Walk same record format. See where it stops.
block2_start = off
print("=" * 70)
print(f"BLOCK 2: ??? (0x{block2_start:x}..)")
print("=" * 70)
block2_records = []
while off < len(data):
    if off + 4 > len(data):
        break
    L = u32(off)
    if not (1 <= L <= 64):
        break
    name = data[off + 4:off + 4 + L]
    try:
        name.decode("utf-8")
    except UnicodeDecodeError:
        break
    # Don't require null in name. Check what comes after.
    p = off + 4 + L
    if p + 8 > len(data):
        break
    # Try-and-see: read like a horse record first
    try_child_count = u32(p + 18) if p + 22 <= len(data) else 999
    if try_child_count <= 50:
        rec_end = p + 22 + 4 * try_child_count
        block2_records.append(dict(off=off, name=name.decode("utf-8", "replace"), end=rec_end, size=rec_end-off, fmt="horse-like"))
        off = rec_end
    else:
        # Not a horse record. Stop.
        break

print(f"Block 2 horse-like records: {len(block2_records)}")
for r in block2_records[:20]:
    print(f"  0x{r['off']:06x} sz={r['size']:>3}  {r['name']!r}")
print(f"  ... (ends at 0x{off:x})")
print()

# At this point we've stopped. Dump the next 256 bytes raw.
print(f"Bytes at stop point 0x{off:x} (next 256):")
for i in range(0, 256, 16):
    row = data[off + i:off + i + 16]
    hexs = " ".join(f"{b:02x}" for b in row)
    asc = "".join(chr(b) if 32 <= b < 127 else "." for b in row)
    print(f"  0x{off+i:06x}  {hexs:<48}  |{asc}|")

# Now look at the big 55KB binary block from 0xd4f to 0xe3e4 or so.
# Maths: 54933 / 76 horses = 722.8 bytes per horse. 723 / 4 = 180.75 codons. genes.xml has 242 genes
# but maybe only some are stored. Or genome is packed differently.
# Let's see if 0xd4f starts with something structural.
print()
print("=" * 70)
print("INSPECTION: large block starting near 0xd4f")
print("=" * 70)
for start in [0xd4f, 0xb2f, 0xe3e4]:
    if start < len(data):
        print(f"\n0x{start:x} (next 128 bytes):")
        for i in range(0, 128, 16):
            row = data[start + i:start + i + 16]
            hexs = " ".join(f"{b:02x}" for b in row)
            asc = "".join(chr(b) if 32 <= b < 127 else "." for b in row)
            print(f"  0x{start+i:06x}  {hexs:<48}  |{asc}|")

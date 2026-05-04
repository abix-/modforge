"""Read a specific UE Property Tag value from a cooked legacy .uasset/.uexp pair.

Strategy:
1. Parse the .uasset to extract the FName table (the list of length-prefixed
   strings near the top of the file).
2. Find the index of the property name we care about (DefaultMaxSize).
3. Scan the .uexp for an 8-byte FName tag matching that index, followed by an
   FName tag matching IntProperty (in cooked format), and decode the value.

Limitation: this assumes UE 5.4+ legacy cooked format as produced by
retoc to-legacy. We're not handling every edge case -- this is good enough to
read a known-shape int32 property.
"""
import struct
import sys
from pathlib import Path

UE_NAME_HASH_BYTES = 4  # UE 4.13+ legacy adds a hash word to each name entry; varies


def parse_name_table(uasset: bytes) -> list[str]:
    """Walk the .uasset name table, return ordered list of FName strings.

    UE legacy cooked name table entries look like:
        int32 length (positive = ascii, negative = UTF-16, length includes null)
        bytes/wchars
        uint16 nonCasePreserving + uint16 casePreserving  (hashes)

    We don't know the exact start offset without parsing the asset header,
    but we can find the table by scanning for the densest run of valid
    length-prefixed entries.
    """
    names = []
    i = 0
    last_good_idx_at_progress = 0
    progress_count = 0

    while i < len(uasset) - 8:
        # Try to read a length-prefixed entry at position i.
        length = struct.unpack_from("<i", uasset, i)[0]
        if length == 0 or length > 256 or length < -256:
            i += 1
            continue
        absl = abs(length)
        if length > 0:
            # ASCII, length includes null
            text_bytes = uasset[i + 4 : i + 4 + length - 1]
            null_at = i + 4 + length - 1
            if null_at >= len(uasset) or uasset[null_at] != 0:
                i += 1
                continue
            try:
                name = text_bytes.decode("ascii")
            except UnicodeDecodeError:
                i += 1
                continue
            if not name or any(c < 32 and c not in (9,) for c in text_bytes):
                i += 1
                continue
            entry_size = 4 + length + 4  # length + bytes + 4-byte hash word
            names.append((i, name))
            i += entry_size
            progress_count += 1
            continue
        i += 1

    # Filter to the longest run that looks like a name table (consecutive entries close together)
    if not names:
        return []
    # group by gap
    groups = []
    cur = [names[0]]
    for prev, item in zip(names, names[1:]):
        if item[0] - prev[0] < 200:
            cur.append(item)
        else:
            groups.append(cur)
            cur = [item]
    groups.append(cur)
    # pick longest group
    best = max(groups, key=len)
    return [n for _, n in best]


def main():
    if len(sys.argv) < 3:
        print("usage: read_property.py <uasset> <uexp> [property=DefaultMaxSize]")
        return 2
    uasset = Path(sys.argv[1]).read_bytes()
    uexp = Path(sys.argv[2]).read_bytes()
    target = sys.argv[3] if len(sys.argv) > 3 else "DefaultMaxSize"

    names = parse_name_table(uasset)
    print(f"recovered {len(names)} FName entries from .uasset")

    if target not in names:
        print(f"!! '{target}' NOT in name table -- mod does not reference this property")
        return 1
    idx = names.index(target)
    print(f"FName index for '{target}': {idx}")

    int_idx = names.index("IntProperty") if "IntProperty" in names else -1
    print(f"FName index for 'IntProperty': {int_idx}")

    # Search uexp for 8-byte FName tag (4-byte name idx + 4-byte FName::Number).
    # Cooked property tags: <name_idx u32><name_num u32><type_idx u32><type_num u32><size u32><array_idx u32>...
    # We pattern-match: NameIdx==idx, NameNum==0, TypeIdx==int_idx
    target_tag = struct.pack("<II", idx, 0)  # name_idx, name_num
    type_tag = struct.pack("<II", int_idx, 0) if int_idx >= 0 else None

    print(f"\nscanning .uexp for {target} property occurrences:")
    pos = 0
    hits = 0
    while True:
        p = uexp.find(target_tag, pos)
        if p < 0:
            break
        # Check if it's followed by IntProperty type tag
        if type_tag and uexp[p+8:p+16] == type_tag:
            # Decode the size + array_idx + value
            size = struct.unpack_from("<I", uexp, p+16)[0]
            arr_idx = struct.unpack_from("<I", uexp, p+20)[0]
            # After the standard 8+8+4+4 = 24 byte tag header, there is often a
            # "has property guid" byte (0 or 1) before the value. So value starts
            # at p+25 typically, for IntProperty.
            guid_flag = uexp[p+24]
            value_offset = p + 25 + (16 if guid_flag else 0)
            value = struct.unpack_from("<i", uexp, value_offset)[0]
            print(f"  @ uexp offset {p}: size={size} arr_idx={arr_idx} guid={guid_flag} VALUE={value}")
            hits += 1
        else:
            # FName found but not followed by IntProperty -- could be a use elsewhere
            following = uexp[p+8:p+16]
            following_idx = struct.unpack_from("<II", following)[0:2] if len(following)>=8 else (0,0)
            print(f"  @ uexp offset {p}: not IntProperty-tagged (following type idx={following_idx[0]})")
        pos = p + 1
    print(f"total hits: {hits}")


if __name__ == "__main__":
    sys.exit(main())

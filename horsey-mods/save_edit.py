"""Read/write Horsey save<N>.dat files using the format reverse-engineered from
FUN_14006dc80 (save_game_writer) and FUN_14006e480 (load_game).

Usage:
  py save_edit.py info   <path>                      # print summary
  py save_edit.py dump   <path>                      # full structured dump
  py save_edit.py set-money <path> <amount>          # cheat: set money
  py save_edit.py add-money <path> <amount>          # cheat: add money

The save format (version 12):
  HEADER:
    uint32  version       (0x0c = 12)
    uint32  timestamp
    uint32  separator     (always 0)
    uint32  frame_tick    -> game_state[+0x254]
    uint32  year          -> game_state[+0x314]
    uint32  unknown_268   -> game_state[+0x268]
    uint8   unknown_114   -> game_state[+0x114]
    uint32  sleeps        -> game_state[+0x318]
    uint32  money         -> game_state[+0x308]    <-- CHEAT TARGET
    uint32  unknown_440   -> game_state[+0x440]
    uint8   flag_414      -> game_state[+0x414]
    uint8   flag_415      -> game_state[+0x415]
    uint32  unknown_37c   -> game_state[+0x37c]
    uint8   discarded_pad
    uint32  unknown_418   -> game_state[+0x418]
    uint8   flag_41c      -> game_state[+0x41c]
    uint64  unknown_39c   -> game_state[+0x39c]
    uint32  unknown_410   -> game_state[+0x410]
  SUPPLIES (6 entries, 6 bytes each):
    uint8   flag_after
    uint32  count
    uint8   flag_before
  MISC 13 PAIRS (each 8 bytes):
    uint32  field_a
    uint32  field_b
  HORSE ROSTER:
    uint32  horse_count
    for each: length-prefixed name + trailer fields
  TRAILING:
    uint32  unknown_278
    uint32  unknown_27c

NOTE: The writer's order in the code is what we use. If a future game version
shifts the field set, we update this script. Currently targets save version 12.
"""
import struct
import sys
from pathlib import Path


class SaveFile:
    def __init__(self, data: bytes):
        self.data = bytearray(data)
        self.pos = 0
        self.fields = {}     # name -> (offset, type, value)

    def read_u8(self):
        v = self.data[self.pos]
        self.pos += 1
        return v

    def read_u32(self):
        v = struct.unpack_from("<I", self.data, self.pos)[0]
        self.pos += 4
        return v

    def read_u64(self):
        v = struct.unpack_from("<Q", self.data, self.pos)[0]
        self.pos += 8
        return v

    def read_lpstring(self):
        length = self.read_u32()
        s = bytes(self.data[self.pos:self.pos + length]).decode("utf-8", errors="replace")
        self.pos += length
        return length, s

    def f(self, name, typ):
        """Record a field, advance position, store the value."""
        off = self.pos
        if typ == "u8":
            v = self.read_u8()
        elif typ == "u32":
            v = self.read_u32()
        elif typ == "u64":
            v = self.read_u64()
        else:
            raise ValueError(typ)
        self.fields[name] = (off, typ, v)
        return v

    def parse(self):
        # === HEADER ===
        self.f("version", "u32")
        self.f("timestamp", "u32")
        self.f("separator_8", "u32")
        # The writer calls FUN_140075770() after the year+0x268 which writes 4 bytes.
        # Then FUN_140075650() writes another separator.
        # Our static analysis saw 5 uint32s of header before "Dale" name at 0x14.
        # Let's match what we observed in real save_A.dat.
        # Header so far accounts for offsets 0..0x10. The 5th uint32 is the first
        # post-separator: that was 93 in our analysis (= horse-count we think?).
        # WAIT: the writer-side sequence is:
        #   version, timestamp, separator, frame_tick, year, +0x268, separator
        # That's 7 fields = 28 bytes before the next field. But we saw the first
        # name "Dale" at offset 0x14 = 20.
        # Discrepancy => the writer's FUN_140075770/FUN_140075650 are uint8 pads.
        # Let's recompute: 4+4+4+4 = 16, then 1+1 = 18, then year(4)=22, hmm.
        #
        # Trial: maybe the order is version(4)+timestamp(4)+pad(4)+horse_pos(4)+
        # horse_count(4) = 20 = 0x14. That matches the observed header size.
        # The fields 4..8 = timestamp 1645984253, 8..C = 0 (separator), C..10 = 50,
        # 10..14 = 93.
        # So actual file layout = header is 20 bytes (5 uint32s).
        # The writer code emits more uint32s, but they may concatenate differently
        # via the helper functions. Without deeper read of FUN_140075670 etc,
        # we'll trust the OBSERVED file structure.

        # === HORSE ROSTER (matches what we walked) ===
        # In observed file, header[0]=12=version, [1]=timestamp, [2]=0, [3]=50,
        # [4]=93. Then names follow starting at offset 0x14.
        # We use header offset 0x14 as the start of horse records.
        if self.pos < 0x14:
            # eat remaining header bytes
            self.pos = 0x14

        horses = []
        while self.pos + 4 < len(self.data):
            length = struct.unpack_from("<I", self.data, self.pos)[0]
            if not (1 <= length <= 64):
                break
            name_bytes = self.data[self.pos + 4:self.pos + 4 + length]
            try:
                name = name_bytes.decode("utf-8")
            except UnicodeDecodeError:
                break
            p = self.pos + 4 + length
            if p + 22 > len(self.data):
                break
            child_count = struct.unpack_from("<I", self.data, p + 18)[0]
            if child_count > 50:
                break
            end = p + 22 + 4 * child_count
            horse = {
                "off": self.pos,
                "name": name,
                "trailer": bytes(self.data[p:end]),
                "size": end - self.pos,
            }
            horses.append(horse)
            self.pos = end

        self.horses = horses
        self.roster_end = self.pos
        return self


def cmd_info(path):
    sf = SaveFile(Path(path).read_bytes()).parse()
    print(f"file: {path}")
    print(f"size: {len(sf.data)} bytes")
    if "version" in sf.fields:
        print(f"version: {sf.fields['version'][2]}")
    print(f"horse roster: {len(sf.horses)} horses (ends at 0x{sf.roster_end:x})")
    print(f"first 5 horses:")
    for h in sf.horses[:5]:
        print(f"  0x{h['off']:06x}: {h['name']!r} (record size={h['size']})")


def cmd_dump(path):
    sf = SaveFile(Path(path).read_bytes()).parse()
    print(f"=== Save File Dump: {path} ===")
    print(f"size: {len(sf.data)} bytes")
    print()
    print("HEADER (first 20 bytes interpreted as 5 uint32s):")
    for i in range(0, 20, 4):
        v = struct.unpack_from("<I", sf.data, i)[0]
        print(f"  0x{i:02x}: {v:>12d} (0x{v:08x})")
    print()
    print(f"HORSE ROSTER ({len(sf.horses)} entries, ends 0x{sf.roster_end:x}):")
    for h in sf.horses:
        print(f"  0x{h['off']:06x}  sz={h['size']:>3}  {h['name']!r}")
    remaining = len(sf.data) - sf.roster_end
    print()
    print(f"After roster: {remaining} bytes of binary data (genome, world state)")


def cmd_set_money(path, amount):
    """Set the money field. CAUTION: we infer money offset from save format
    but the exact byte position in the file is not 100% confirmed without
    reading more of the writer code."""
    print("ERROR: not yet implemented - need to confirm exact byte offset of")
    print("       money in the file. The writer sequence suggests it's after")
    print("       the horse roster, in the post-roster binary block. Pending")
    print("       further decompilation.")
    sys.exit(1)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    cmd = sys.argv[1]
    if cmd == "info":
        cmd_info(sys.argv[2])
    elif cmd == "dump":
        cmd_dump(sys.argv[2])
    elif cmd == "set-money":
        cmd_set_money(sys.argv[2], int(sys.argv[3]))
    else:
        print(f"unknown command: {cmd}")
        print(__doc__)


if __name__ == "__main__":
    main()

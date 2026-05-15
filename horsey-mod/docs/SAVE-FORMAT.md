# save1.dat - format notes
> **Authoritative on:** format notes for save1.dat (partial; static-analysis pass).

Live save dumped 2026-05-13. Total size 245,151 bytes.

All findings are from static analysis. Field meanings are HYPOTHESES until confirmed by a byte-diff experiment between two known-different saves.

## File map (high level)

| Range | Size | Confidence | Content |
|---|---|---|---|
| 0x0000..0x0014 | 20 B | medium | Header (5 uint32s) |
| 0x0014..0x0c6f | 3,163 B | high | Horse roster: 85 records |
| 0x0c6f..0x0d4f | ~224 B | low | Looks like more named records (ribbons/champions?) - records named "Meteor", "Participation Award", "Vapid Transit", "Willgo", "Buffalo" with horse-roster-shaped fields |
| 0x0d4f..0x0e3e4 | 54,933 B | low | Large binary block. Contains float values and 0x3f800000 (=1.0f) patterns. Possibly world state / positions / per-horse genome. Roughly 76*720 = 54720 bytes if it's "one genome per horse" - but the math is fuzzy. |
| 0x0e3e4..end | 187,963 B | none | Sparse strings ("unknown", short fragments). Mostly binary with float values that look like positions. Probably tile state, gene drives, item placements, money, calendar. |

Roster + champion block = 1.2% of file. The remaining 98.8% is whatever the in-game world state is.

## Header (first 20 bytes)

| Offset | Bytes | Value | Hypothesis |
|---|---|---|---|
| 0x00 | 0c 00 00 00 | 12 | Save format version |
| 0x04 | fd b9 1b 62 | 1645984253 | Unix timestamp (Feb 27 2022) - either save creation time or world seed |
| 0x08 | 00 00 00 00 | 0 | Unknown (zero) |
| 0x0c | 32 00 00 00 | 50 | Unknown - could be max horse capacity, current year, or current channel |
| 0x10 | 5d 00 00 00 | 93 | Unknown - could be next-horse-id counter or total-horses-ever |

Note: 93 != 85 (record count). So this field is NOT just "active horse count". Could be "next ID to assign" or "total horses ever created including dead/sold".

## Horse roster record (verified by walking)

Variable size, minimum 26 bytes. Layout per record:

```
struct HorseRecord {
    uint32  name_length;
    char    name[name_length];           // UTF-8, no trailing null included in length
    uint8   flag_a;                      // 0 in samples (sex? sex-male?)
    uint8   flag_b;                      // varies (color/pattern/breed sub-id?)
    uint8   flag_c;                      // varies
    uint8   flag_d;                      // varies
    uint8   flag_e;                      // 0 in samples
    uint8   pop_id;                      // 1..255: which population the horse belongs to
    int32   parent_a;                    // -1 if no parent (wild-spawn)
    int32   parent_b;                    // -1 if no parent
    uint32  unknown1;                    // 0 in all samples
    uint32  child_count;                 // 0..N
    int32   child_ids[child_count];      // IDs of offspring
}
```

### What's CONFIRMED about this struct

- Name is length-prefixed UTF-8. We've successfully parsed names with non-ASCII chars (e.g. "Señor Borde...").
- The 22-byte trailer is consistent across 85 records.
- `child_count` matches the variable-length tail of child IDs.
- Records with parents (e.g. "Whirlwind Romance" has p1=2, p2=3) cross-reference earlier record indices.

### What's STILL UNKNOWN

- **What flag_a..flag_e actually encode.** Could be sex, gender-marker, pregnant state, current location, breed sub-type, color. We do NOT know.
- **Whether the genome lives in this record.** It doesn't - the record is too small. 22 fixed bytes leaves no room for 200+ allele values.
- **Whether age/fatigue/hunger are here.** They're not visible in the 22-byte trailer. Likely stored in one of the big binary blocks.

### The pop_id field looks real

Observed values: 1, 2, 3, 4, 5, 7, 12, 255. From `pop.xml`, the populations in order are: default, scratch, fest horse, crazy horse, impala, alligator, giraffe, rabbit, duck, dino, centipede, tiger, moose, dachshund, bear, cow, human, centaur test, jockey, leprechaun, pepper, car, appletree, yeast, hay, fish, helix, freak.

If we number them 0..N (or 1..N), 1=default fits "Dale" being an ordinary horse, and 12=moose or similar fits a weird horse. 255 looks like a sentinel for "freak" or "custom". Worth testing.

## Open work

Action items (find fatigue/age fields, identify genome location, confirm pop_id mapping, run save-diff experiments) are tracked in [`todo.md`](todo.md#save-format-research).

## Tools

- `parse_save.py` (in this folder): walks the roster and dumps blocks. Read-only.

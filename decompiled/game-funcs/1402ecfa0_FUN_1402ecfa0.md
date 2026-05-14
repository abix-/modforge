# `FUN_1402ecfa0` @ 0x1402ecfa0

**Size**: 32 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 2 other funcs

**Game callers** (2): [`FUN_1402e4980`](1402e4980_FUN_1402e4980.md), [`FUN_1402ecfa0`](1402ecfa0_FUN_1402ecfa0.md)

**Game callees** (2): [`FUN_1402ecfa0`](1402ecfa0_FUN_1402ecfa0.md), [`FUN_1402ed000`](1402ed000_FUN_1402ed000.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1402ecfa0(void)

{

  FUN_1402ed000();

  return;

}
```
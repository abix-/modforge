# `FUN_1402ebdc0` @ 0x1402ebdc0

**Size**: 42 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 2 other funcs

**Game callers** (2): [`FUN_1402e8f40`](1402e8f40_FUN_1402e8f40.md), [`FUN_1402ebdc0`](1402ebdc0_FUN_1402ebdc0.md)

**Game callees** (2): [`FUN_1402ebab0`](1402ebab0_FUN_1402ebab0.md), [`FUN_1402ebdc0`](1402ebdc0_FUN_1402ebdc0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1402ebdc0(void)

{

  FUN_1402ebab0();

  return;

}
```
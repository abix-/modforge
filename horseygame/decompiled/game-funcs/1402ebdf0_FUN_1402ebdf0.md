# `FUN_1402ebdf0` @ 0x1402ebdf0

**Size**: 51 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 2 other funcs

**Game callers** (3): [`FUN_1402e8e00`](1402e8e00_FUN_1402e8e00.md), [`FUN_1402e8f40`](1402e8f40_FUN_1402e8f40.md), [`FUN_1402ebdf0`](1402ebdf0_FUN_1402ebdf0.md)

**Game callees** (2): [`FUN_1402e68b0`](1402e68b0_FUN_1402e68b0.md), [`FUN_1402ebdf0`](1402ebdf0_FUN_1402ebdf0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1402ebdf0(int param_1)

{

  undefined4 *puVar1;

  if (param_1 == 1) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x21;

  }

  else if ((param_1 == 2) || (param_1 == 3)) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x22;

    return;

  }

  return;

}
```
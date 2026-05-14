# `FUN_1400cead0` @ 0x1400cead0

**Size**: 131 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 6 other funcs

**Game callers** (15): [`FUN_14002d7c0`](14002d7c0_FUN_14002d7c0.md), [`FUN_140033a10`](140033a10_FUN_140033a10.md), [`FUN_140039190`](140039190_FUN_140039190.md), [`FUN_14005bc30`](14005bc30_FUN_14005bc30.md), [`FUN_140060710`](140060710_FUN_140060710.md), [`FUN_140061f40`](140061f40_FUN_140061f40.md), [`FUN_14007b2e0`](14007b2e0_FUN_14007b2e0.md), [`FUN_140089510`](140089510_FUN_140089510.md), [`FUN_1400c0660`](1400c0660_FUN_1400c0660.md), [`FUN_1400c9980`](1400c9980_FUN_1400c9980.md)
  ... +5 more

**Game callees** (6): [`FUN_1400b3dc0`](1400b3dc0_FUN_1400b3dc0.md), [`FUN_1400b6170`](1400b6170_FUN_1400b6170.md), [`FUN_1400b6990`](1400b6990_FUN_1400b6990.md), [`FUN_1400c5c30`](1400c5c30_FUN_1400c5c30.md), [`FUN_1400ccbd0`](1400ccbd0_FUN_1400ccbd0.md), [`FUN_1400cead0`](1400cead0_FUN_1400cead0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1400cead0(longlong param_1,longlong param_2)

{

  undefined4 uVar1;

  float fVar2;

  FUN_1400b3dc0(param_2,*(undefined8 *)(param_1 + 0x98));

  fVar2 = (float)FUN_1400b6170(param_2);

  uVar1 = FUN_1400c5c30(*(undefined4 *)(param_1 + 0x120),

                        1 - (int)(((fVar2 + DAT_14030335c) - *(float *)(param_1 + 0x110)) *

                                 DAT_140304c8c));

  FUN_1400b6990(param_2,uVar1,*(undefined1 *)(param_2 + 0x1e0));

  *(undefined1 *)(param_2 + 0x1c8) = 0;

  FUN_1400ccbd0(param_1,param_2);

  return;

}
```
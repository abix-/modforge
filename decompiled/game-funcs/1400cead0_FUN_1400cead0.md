# `FUN_1400cead0` @ 0x1400cead0

**Size**: 131 bytes
**Role**: unclassified game logic

**Game callers** (15): `FUN_14002d7c0`, `FUN_140033a10`, `FUN_140039190`, `FUN_14005bc30`, `FUN_140060710`, `FUN_140061f40`, `FUN_14007b2e0`, `FUN_140089510`, `FUN_1400c0660`, `FUN_1400c9980`
  ... +5 more

**Game callees** (6): `FUN_1400b3dc0`, `FUN_1400b6170`, `FUN_1400b6990`, `FUN_1400c5c30`, `FUN_1400ccbd0`, `FUN_1400cead0`

**Vendor callees** (0) - SDL/CRT/etc.

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
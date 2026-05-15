# `FUN_1401aaee0` @ 0x1401aaee0

**Size**: 179 bytes
**Role**: `lab_location` (string-anchored)
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 5 other funcs

**Game callers** (5): [`FUN_1401746e0`](1401746e0_FUN_1401746e0.md), [`FUN_140179150`](140179150_FUN_140179150.md), [`FUN_1401aa890`](1401aa890_FUN_1401aa890.md), [`FUN_1401aaee0`](1401aaee0_FUN_1401aaee0.md), [`FUN_1401acec0`](1401acec0_FUN_1401acec0.md)

**Game callees** (5): [`FUN_14017c930`](14017c930_FUN_14017c930.md), [`FUN_1401841a0`](1401841a0_FUN_1401841a0.md), [`FUN_1401aaea0`](1401aaea0_FUN_1401aaea0.md), [`FUN_1401aaee0`](1401aaee0_FUN_1401aaee0.md), [`FUN_1401aafa0`](1401aafa0_FUN_1401aafa0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
longlong *

FUN_1401aaee0(undefined8 param_1,char param_2,longlong param_3,longlong param_4,longlong param_5,

             longlong param_6)

{

  int iVar1;

  longlong *plVar2;

  longlong lVar3;

  iVar1 = FUN_1401aaea0();

  plVar2 = (longlong *)FUN_1401841a0(1,0x40);

  if (plVar2 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  if (param_2 != '\0') {

    lVar3 = FUN_14017c930();

    *plVar2 = lVar3;

    if (lVar3 == 0) goto LAB_1401aaf49;

  }

  lVar3 = FUN_1401841a0(iVar1,0x18);

  plVar2[1] = lVar3;

  if (lVar3 != 0) {

    plVar2[2] = param_3;

    *(int *)(plVar2 + 6) = iVar1 + -1;

    plVar2[5] = param_6;

    plVar2[4] = param_5;

    plVar2[3] = param_4;

    return plVar2;

  }

LAB_1401aaf49:

  FUN_1401aafa0(plVar2);

  return (longlong *)0x0;

}
```
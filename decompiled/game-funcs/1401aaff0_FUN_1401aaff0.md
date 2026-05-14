# `FUN_1401aaff0` @ 0x1401aaff0

**Size**: 171 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 5 other funcs

**Strings referenced**:
- `'table'`

**Game callers** (12): [`FUN_1401747e0`](1401747e0_FUN_1401747e0.md), [`FUN_1401749e0`](1401749e0_FUN_1401749e0.md), [`FUN_140174c40`](140174c40_FUN_140174c40.md), [`FUN_140174d30`](140174d30_FUN_140174d30.md), [`FUN_140174dd0`](140174dd0_FUN_140174dd0.md), [`FUN_140174e70`](140174e70_FUN_140174e70.md), [`FUN_140175050`](140175050_FUN_140175050.md), [`FUN_1401750b0`](1401750b0_FUN_1401750b0.md), [`FUN_1401755c0`](1401755c0_FUN_1401755c0.md), [`FUN_1401792e0`](1401792e0_FUN_1401792e0.md)
  ... +2 more

**Game callees** (5): [`FUN_14012e850`](14012e850_FUN_14012e850.md), [`FUN_14017caa0`](14017caa0_FUN_14017caa0.md), [`FUN_14017cae0`](14017cae0_FUN_14017cae0.md), [`FUN_1401aaff0`](1401aaff0_FUN_1401aaff0.md), [`FUN_1401ab530`](1401ab530_FUN_1401ab530.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
undefined8 FUN_1401aaff0(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  if (param_1 == (undefined8 *)0x0) {

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = 0;

    }

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","table");

    return uVar2;

  }

  FUN_14017caa0(*param_1);

  uVar2 = 0;

  iVar1 = (*(code *)param_1[2])(param_1[5],param_2);

  lVar3 = FUN_1401ab530(param_1,param_2,iVar1 * -0x61c8864f);

  if (lVar3 != 0) {

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = *(undefined8 *)(lVar3 + 8);

    }

    uVar2 = 1;

  }

  FUN_14017cae0(*param_1);

  return uVar2;

}
```
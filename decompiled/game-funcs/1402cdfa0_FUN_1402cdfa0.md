# `FUN_1402cdfa0` @ 0x1402cdfa0

**Size**: 155 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Strings referenced**:
- `'sqrtf'`

**Game callers** (17): [`FUN_1400058e0`](1400058e0_FUN_1400058e0.md), [`FUN_14000e0e0`](14000e0e0_FUN_14000e0e0.md), [`FUN_140016810`](140016810_FUN_140016810.md), [`FUN_140016c70`](140016c70_FUN_140016c70.md), [`FUN_140017910`](140017910_FUN_140017910.md), [`FUN_140018070`](140018070_FUN_140018070.md), [`FUN_140074020`](140074020_FUN_140074020.md), [`FUN_14007b2e0`](14007b2e0_FUN_14007b2e0.md), [`FUN_14009f680`](14009f680_FUN_14009f680.md), [`FUN_1400a8890`](1400a8890_FUN_1400a8890.md)
  ... +7 more

**Game callees** (3): [`FUN_1402cdfa0`](1402cdfa0_FUN_1402cdfa0.md), [`FUN_1402e8f40`](1402e8f40_FUN_1402e8f40.md), [`FUN_1402e90a0`](1402e90a0_FUN_1402e90a0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
float FUN_1402cdfa0(float param_1)

{

  float fVar1;

  if (((uint)param_1 & 0x7f800000) == 0x7f800000) {

    if (((uint)param_1 & 0x7fffff) != 0) {

      fVar1 = (float)FUN_1402e90a0(param_1);

      return fVar1;

    }

    if ((int)param_1 < 0) goto LAB_1402cdfd7;

  }

  if (-1 < (int)param_1 || ABS(param_1) == 0.0) {

    return SQRT(param_1);

  }

LAB_1402cdfd7:

  fVar1 = (float)FUN_1402e8f40("sqrtf",5,0xffc00000,1,8,0x21,param_1,0,1);

  return fVar1;

}
```
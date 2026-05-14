# `FUN_1402cdfa0` @ 0x1402cdfa0

**Size**: 155 bytes
**Role**: unclassified game logic

**Strings referenced**:
- `'sqrtf'`

**Game callers** (17): `FUN_1400058e0`, `FUN_14000e0e0`, `FUN_140016810`, `FUN_140016c70`, `FUN_140017910`, `FUN_140018070`, `FUN_140074020`, `FUN_14007b2e0`, `FUN_14009f680`, `FUN_1400a8890`
  ... +7 more

**Game callees** (3): `FUN_1402cdfa0`, `FUN_1402e8f40`, `FUN_1402e90a0`

**Vendor callees** (0) - SDL/CRT/etc.

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
# `FUN_1402ceae8` @ 0x1402ceae8

**Size**: 141 bytes
**Role**: unclassified game logic

**Game callers** (2): `FUN_1402ceae8`, `FUN_1402cf00c`

**Game callees** (5): `FUN_1402cd39c`, `FUN_1402ceae8`, `FUN_1402ceb78`, `FUN_1402e1710`, `FUN_1402e171c`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
ulonglong FUN_1402ceae8(longlong param_1,longlong param_2)

{

  ulonglong uVar1;

  if (param_1 == 0) {

    *(undefined1 *)(param_2 + 0x30) = 1;

    *(undefined4 *)(param_2 + 0x2c) = 0x16;

    FUN_1402cd39c(0,0,0,0,0,param_2);

    uVar1 = 0xffffffff;

  }

  else {

    FUN_1402e1710();

    uVar1 = FUN_1402ceb78(param_1,param_2);

    if (0x7fffffff < (longlong)uVar1) {

      *(undefined1 *)(param_2 + 0x30) = 1;

      *(undefined4 *)(param_2 + 0x2c) = 0x16;

      uVar1 = 0xffffffff;

    }

    FUN_1402e171c(param_1);

    uVar1 = uVar1 & 0xffffffff;

  }

  return uVar1;

}
```
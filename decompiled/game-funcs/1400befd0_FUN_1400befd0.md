# `FUN_1400befd0` @ 0x1400befd0

**Size**: 155 bytes
**Role**: `init_struct` - Zero-initializes consecutive struct fields  _(evidence: zero-initializes 18 fields)_
**Pattern category**: `init_struct`

**Game callers** (2): [`FUN_1400be740`](1400be740_FUN_1400be740.md), [`FUN_1400befd0`](1400befd0_FUN_1400befd0.md)

**Game callees** (1): [`FUN_1400befd0`](1400befd0_FUN_1400befd0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
longlong FUN_1400befd0(longlong param_1,longlong param_2)

{

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *(undefined8 *)(param_1 + 0x18) = 0;

    *(undefined8 *)(param_1 + 0x20) = 0;

    *(undefined8 *)(param_1 + 0x28) = 0;

    *(undefined4 *)(param_1 + 4) = 0xffffffff;

    *(undefined8 *)(param_1 + 0x30) = 0;

    *(undefined8 *)(param_1 + 0x38) = 0;

    *(undefined8 *)(param_1 + 100) = 0;

    *(undefined8 *)(param_1 + 0x40) = 0;

    *(undefined8 *)(param_1 + 0x48) = 0;

    *(undefined1 *)(param_1 + 0x14) = 1;

    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;

    *(undefined8 *)(param_1 + 0x70) = 0;

    *(undefined8 *)(param_1 + 0x78) = 0;

    *(undefined4 *)(param_1 + 0x6c) = 0;

    *(undefined8 *)(param_1 + 0x88) = 0;

    *(undefined8 *)(param_1 + 0x94) = 0;

    *(undefined4 *)(param_1 + 0x90) = 0;

    *(undefined1 *)(param_1 + 0x84) = 0;

    *(undefined8 *)(param_1 + 0x9c) = 1;

    *(undefined8 *)(param_1 + 0xb0) = 0;

    *(undefined8 *)(param_1 + 0xa4) = 0;

    *(undefined4 *)(param_1 + 0xac) = 0;

    param_1 = param_1 + 0xb8;

  }

  return param_1;

}
```
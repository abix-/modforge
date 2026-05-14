# `FUN_1400bedc0` @ 0x1400bedc0

**Size**: 528 bytes
**Role**: unclassified game logic

**Game callers** (3): `FUN_1400ab3d0`, `FUN_1400be740`, `FUN_1400bedc0`

**Game callees** (1): `FUN_1400bedc0`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
undefined4 * FUN_1400bedc0(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 *puVar6;

  undefined4 *puVar7;

  puVar7 = param_3;

  if (param_1 != param_2) {

    puVar6 = param_1 + 4;

    do {

      puVar2 = puVar6 + 0x17;

      *puVar7 = *(undefined4 *)(puVar6 + -4);

      puVar7 = puVar7 + 0x2e;

      *(undefined4 *)((longlong)param_3 + (-0xd4 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + -0x1c);

      *(undefined4 *)((longlong)param_3 + (-0xd0 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + -3);

      *(undefined4 *)((longlong)param_3 + (-0xcc - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + -0x14);

      *(undefined4 *)((longlong)param_3 + (-200 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + -2);

      *(undefined1 *)((longlong)param_3 + (-0xc4 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined1 *)((longlong)puVar6 + -0xc);

      uVar3 = *puVar6;

      uVar4 = puVar6[-1];

      uVar5 = puVar6[1];

      puVar6[1] = 0;

      *puVar6 = 0;

      puVar6[-1] = 0;

      *(undefined8 *)((longlong)param_3 + (-0xb8 - (longlong)param_1) + (longlong)puVar2) = uVar3;

      *(undefined8 *)((longlong)param_3 + (-0xc0 - (longlong)param_1) + (longlong)puVar2) = uVar4;

      *(undefined8 *)((longlong)param_3 + (-0xb0 - (longlong)param_1) + (longlong)puVar2) = uVar5;

      *(undefined8 *)((longlong)param_3 + (-0xa8 - (longlong)param_1) + (longlong)puVar2) =

           puVar6[2];

      *(undefined8 *)((longlong)param_3 + (-0xa0 - (longlong)param_1) + (longlong)puVar2) =

           puVar6[3];

      *(undefined8 *)((longlong)param_3 + (-0x98 - (longlong)param_1) + (longlong)puVar2) =

           puVar6[4];

      *(undefined4 *)((longlong)param_3 + (-0x90 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 5);

      *(undefined4 *)((longlong)param_3 + (-0x8c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x2c);

      *(undefined8 *)((longlong)param_3 + (-0x88 - (longlong)param_1) + (longlong)puVar2) =

           puVar6[6];

      *(undefined4 *)((longlong)param_3 + (-0x80 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 7);

      *(undefined8 *)((longlong)param_3 + (-0x7c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined8 *)((longlong)puVar6 + 0x3c);

      *(undefined4 *)((longlong)param_3 + (-0x74 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x44);

      *(undefined4 *)((longlong)param_3 + (-0x70 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 9);

      *(undefined4 *)((longlong)param_3 + (-0x6c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x4c);

      *(undefined4 *)((longlong)param_3 + (-0x68 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 10);

      *(undefined4 *)((longlong)param_3 + (-100 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x54);

      *(undefined4 *)((longlong)param_3 + (-0x60 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0xb);

      *(undefined4 *)((longlong)param_3 + (-0x5c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x5c);

      *(undefined4 *)((longlong)param_3 + (-0x58 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0xc);

      *(undefined1 *)((longlong)param_3 + (-0x54 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined1 *)((longlong)puVar6 + 100);

      *(undefined4 *)((longlong)param_3 + (-0x50 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0xd);

      *(undefined8 *)((longlong)param_3 + (-0x4c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined8 *)((longlong)puVar6 + 0x6c);

      *(undefined8 *)((longlong)param_3 + (-0x44 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined8 *)((longlong)puVar6 + 0x74);

      *(undefined4 *)((longlong)param_3 + (-0x3c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x7c);

      *(undefined4 *)((longlong)param_3 + (-0x38 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0x10);

      *(undefined4 *)((longlong)param_3 + (-0x34 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x84);

      *(undefined4 *)((longlong)param_3 + (-0x30 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0x11);

      *(undefined4 *)((longlong)param_3 + (-0x2c - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x8c);

      *(undefined4 *)((longlong)param_3 + (-0x28 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)(puVar6 + 0x12);

      *(undefined4 *)((longlong)param_3 + (-0x24 - (longlong)param_1) + (longlong)puVar2) =

           *(undefined4 *)((longlong)puVar6 + 0x94);

      puVar1 = puVar6 + 0x13;

      puVar6 = puVar2;

    } while (puVar1 != param_2);

  }

  return puVar7;

}
```
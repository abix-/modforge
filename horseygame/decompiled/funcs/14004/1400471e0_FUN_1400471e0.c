// Address: 0x1400471e0
// Ghidra name: FUN_1400471e0
// ============ 0x1400471e0 FUN_1400471e0 (size=169) ============


undefined8 * FUN_1400471e0(longlong param_1,longlong param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  

  if (param_1 != param_2) {

    puVar3 = param_3 + 4;

    param_1 = param_1 - (longlong)param_3;

    do {

      *param_3 = *(undefined8 *)((longlong)puVar3 + param_1 + -0x20);

      param_3 = param_3 + 8;

      puVar3[-3] = 0;

      puVar3[-2] = 0;

      puVar3[-1] = 0;

      *puVar3 = 0;

      puVar1 = (undefined8 *)(param_1 + -0x18 + (longlong)puVar3);

      uVar2 = puVar1[1];

      puVar3[-3] = *puVar1;

      puVar3[-2] = uVar2;

      puVar1 = (undefined8 *)(param_1 + -8 + (longlong)puVar3);

      uVar2 = puVar1[1];

      puVar3[-1] = *puVar1;

      *puVar3 = uVar2;

      *(undefined8 *)(param_1 + -8 + (longlong)puVar3) = 0;

      *(undefined8 *)(param_1 + (longlong)puVar3) = 0xf;

      *(undefined1 *)(param_1 + -0x18 + (longlong)puVar3) = 0;

      *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(param_1 + 8 + (longlong)puVar3);

      *(undefined4 *)((longlong)puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc + (longlong)puVar3);

      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(param_1 + 0x10 + (longlong)puVar3);

      *(undefined4 *)((longlong)puVar3 + 0x14) = *(undefined4 *)(param_1 + 0x14 + (longlong)puVar3);

      *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(param_1 + 0x18 + (longlong)puVar3);

      puVar3 = puVar3 + 8;

    } while (param_1 + -0x20 + (longlong)puVar3 != param_2);

  }

  return param_3;

}





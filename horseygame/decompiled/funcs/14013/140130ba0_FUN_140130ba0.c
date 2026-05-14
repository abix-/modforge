// Address: 0x140130ba0
// Ghidra name: FUN_140130ba0
// ============ 0x140130ba0 FUN_140130ba0 (size=232) ============


undefined8 FUN_140130ba0(longlong param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  

  uVar4 = 0;

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = 0;

  }

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","camera");

    return 0;

  }

  FUN_140130b40();

  if (*(int *)(param_1 + 0x1cc) < 1) {

    FUN_140130b70(param_1);

    FUN_14012e850("Camera permission has not been granted");

    return 0;

  }

  puVar1 = *(undefined8 **)(param_1 + 0x170);

  puVar2 = (undefined8 *)(param_1 + 0x160);

  if (*(undefined8 **)(param_1 + 0x170) != (undefined8 *)0x0) {

    do {

      puVar3 = puVar2;

      puVar2 = puVar1;

      puVar1 = (undefined8 *)puVar2[2];

    } while ((undefined8 *)puVar2[2] != (undefined8 *)0x0);

    if (puVar2 != puVar3) {

      if (param_2 != (undefined8 *)0x0) {

        *param_2 = puVar2[1];

      }

      uVar4 = *puVar2;

      puVar3[2] = puVar2[2];

      puVar2[2] = *(undefined8 *)(param_1 + 0x1a0);

      *(undefined8 **)(param_1 + 0x1a0) = puVar2;

    }

  }

  FUN_140130b70(param_1);

  return uVar4;

}





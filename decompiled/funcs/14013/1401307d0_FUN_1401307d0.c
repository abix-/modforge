// Address: 0x1401307d0
// Ghidra name: FUN_1401307d0
// ============ 0x1401307d0 FUN_1401307d0 (size=405) ============


void FUN_1401307d0(longlong param_1)



{

  undefined8 *puVar1;

  uint uVar2;

  

  if ((param_1 != 0) && (*(longlong *)(param_1 + 0x1d0) != 0)) {

    FUN_140139010(param_1 + 0x1b8,1);

    uVar2 = 0;

    if (*(longlong *)(param_1 + 0x1c0) != 0) {

      FUN_140163d80(*(longlong *)(param_1 + 0x1c0),0);

      *(undefined8 *)(param_1 + 0x1c0) = 0;

    }

    FUN_140130b40(param_1);

    if ((*(char *)(param_1 + 0x1b4) == '\0') && (*(int *)(param_1 + 0x1b0) == 0)) {

      for (puVar1 = *(undefined8 **)(param_1 + 0x170); puVar1 != (undefined8 *)0x0;

          puVar1 = (undefined8 *)puVar1[2]) {

        (**(code **)(param_1 + 0x28))(param_1,*puVar1);

      }

      for (puVar1 = *(undefined8 **)(param_1 + 0x1a0); puVar1 != (undefined8 *)0x0;

          puVar1 = (undefined8 *)puVar1[2]) {

        (**(code **)(param_1 + 0x28))(param_1,*puVar1);

      }

    }

    (*DAT_1403fb5f0)(param_1);

    *(undefined8 *)(param_1 + 0x1d0) = 0;

    FUN_1401747e0(*(undefined4 *)(param_1 + 0x1c8));

    FUN_140146010(*(undefined8 *)(param_1 + 0x90));

    *(undefined8 *)(param_1 + 0x90) = 0;

    FUN_140146010(*(undefined8 *)(param_1 + 0x98));

    *(undefined8 *)(param_1 + 0x98) = 0;

    puVar1 = (undefined8 *)(param_1 + 0xa0);

    do {

      FUN_140146010(*puVar1);

      uVar2 = uVar2 + 1;

      puVar1 = puVar1 + 3;

    } while (uVar2 < 8);

    FUN_1402f94c0(param_1 + 0xa0,0,0xc0);

    FUN_140190140(*(undefined8 *)(param_1 + 0x1a8));

    *(undefined4 *)(param_1 + 0x1cc) = 0;

    *(undefined8 *)(param_1 + 0x1a8) = 0;

    *(undefined8 *)(param_1 + 0x170) = 0;

    *(undefined8 *)(param_1 + 0x188) = 0;

    *(undefined8 *)(param_1 + 0x1a0) = 0;

    *(undefined8 *)(param_1 + 0x80) = 0;

    *(undefined8 *)(param_1 + 0x88) = 0;

    *(undefined8 *)(param_1 + 0x54) = 0;

    *(undefined8 *)(param_1 + 0x5c) = 0;

    *(undefined8 *)(param_1 + 100) = 0;

    FUN_1401324e0(param_1);

    FUN_140130b70(param_1);

  }

  return;

}





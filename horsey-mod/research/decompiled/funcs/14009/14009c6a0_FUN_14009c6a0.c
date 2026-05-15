// Address: 0x14009c6a0
// Ghidra name: FUN_14009c6a0
// ============ 0x14009c6a0 FUN_14009c6a0 (size=207) ============


void FUN_14009c6a0(undefined4 *param_1,undefined4 param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  

  FUN_14003f6f0();

  uVar3 = 0;

  *param_1 = 0;

  *(undefined8 *)(param_1 + 2) = 0;

  *(undefined8 *)(param_1 + 4) = 0;

  if (DAT_1403fb0d8 != (undefined8 *)0x0) {

    (**(code **)*DAT_1403fb0d8)(DAT_1403fb0d8,1);

  }

  lVar1 = FUN_1402c704c(0x448);

  uVar2 = uVar3;

  if (lVar1 != 0) {

    uVar2 = FUN_1400fd580(lVar1,param_2);

  }

  DAT_1403fb0d8 = (undefined8 *)uVar2;

  if (*(longlong *)(param_1 + 6) == 0) {

    lVar1 = FUN_1402c704c(0x268);

    uVar2 = uVar3;

    if (lVar1 != 0) {

      uVar2 = FUN_140066180(lVar1);

    }

    *(undefined8 *)(param_1 + 6) = uVar2;

  }

  *(undefined1 *)(param_1 + 10) = 0;

  if (*(longlong *)(param_1 + 8) == 0) {

    lVar1 = FUN_1402c704c(0x280);

    if (lVar1 != 0) {

      uVar3 = FUN_140055b20(lVar1);

    }

    *(undefined8 *)(param_1 + 8) = uVar3;

  }

  return;

}





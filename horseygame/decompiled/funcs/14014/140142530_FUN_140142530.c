// Address: 0x140142530
// Ghidra name: FUN_140142530
// ============ 0x140142530 FUN_140142530 (size=157) ============


void FUN_140142530(undefined8 *param_1)



{

  undefined4 uVar1;

  longlong lVar2;

  size_t sVar3;

  undefined1 *puVar4;

  

  _guard_check_icall();

  *(undefined4 *)(param_1 + 3) = 0;

  lVar2 = thunk_FUN_1402c9340(*(undefined8 *)(param_1[4] + 0x18),"type:");

  if (lVar2 != 0) {

    sVar3 = strlen("type:");

    lVar2 = lVar2 + sVar3;

    puVar4 = (undefined1 *)thunk_FUN_1402c9190(lVar2,0x2c);

    if (puVar4 == (undefined1 *)0x0) {

      uVar1 = FUN_14013f0c0(lVar2);

      *(undefined4 *)(param_1 + 3) = uVar1;

    }

    else {

      *puVar4 = 0;

      uVar1 = FUN_14013f0c0(lVar2);

      *(undefined4 *)(param_1 + 3) = uVar1;

      *puVar4 = 0x2c;

    }

  }

  if (*(int *)(param_1 + 3) == 0) {

    uVar1 = FUN_14013f350(*(undefined4 *)*param_1);

    *(undefined4 *)(param_1 + 3) = uVar1;

  }

  return;

}





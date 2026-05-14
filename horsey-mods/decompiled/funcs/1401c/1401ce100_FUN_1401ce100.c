// Address: 0x1401ce100
// Ghidra name: FUN_1401ce100
// ============ 0x1401ce100 FUN_1401ce100 (size=139) ============


bool FUN_1401ce100(undefined8 *param_1,undefined8 param_2,undefined8 param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  FUN_140179b40(*param_1);

  lVar1 = FUN_140184230(param_1[4],((longlong)*(int *)(param_1 + 5) + 1) * 0x18);

  if (lVar1 != 0) {

    param_1[4] = lVar1;

    lVar2 = (longlong)*(int *)(param_1 + 5);

    *(undefined8 *)(lVar1 + lVar2 * 0x18) = param_2;

    *(undefined8 *)(lVar1 + 8 + lVar2 * 0x18) = param_3;

    *(undefined1 *)(lVar1 + 0x10 + lVar2 * 0x18) = 0;

    *(int *)(param_1 + 5) = *(int *)(param_1 + 5) + 1;

  }

  FUN_140179b60(*param_1);

  return lVar1 != 0;

}





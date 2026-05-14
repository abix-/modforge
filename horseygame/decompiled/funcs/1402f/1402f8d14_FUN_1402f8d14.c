// Address: 0x1402f8d14
// Ghidra name: FUN_1402f8d14
// ============ 0x1402f8d14 FUN_1402f8d14 (size=74) ============


void FUN_1402f8d14(int *param_1,undefined8 param_2,undefined8 param_3)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = FUN_1402c9598();

  if ((((*(byte *)(param_1 + 1) & 0x66) == 0) && (*param_1 == -0x1f928c9d)) && (iVar2 == 1)) {

    lVar1 = FUN_1402c97f8();

    *(int **)(lVar1 + 0x20) = param_1;

    lVar1 = FUN_1402c97f8();

    *(undefined8 *)(lVar1 + 0x28) = param_3;

                    /* WARNING: Subroutine does not return */

    FUN_1402cf8b8();

  }

  return;

}





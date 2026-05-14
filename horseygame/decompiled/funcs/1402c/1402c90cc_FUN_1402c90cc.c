// Address: 0x1402c90cc
// Ghidra name: FUN_1402c90cc
// ============ 0x1402c90cc FUN_1402c90cc (size=101) ============


undefined8 FUN_1402c90cc(undefined8 *param_1)



{

  int *piVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  piVar1 = (int *)*param_1;

  if ((*piVar1 == -0x1fbcbcae) || (*piVar1 == -0x1fbcb0b3)) {

    lVar3 = FUN_1402c97f8();

    if (0 < *(int *)(lVar3 + 0x30)) {

      lVar3 = FUN_1402c97f8();

      *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + -1;

    }

  }

  else if (*piVar1 == -0x1f928c9d) {

    lVar3 = FUN_1402c97f8();

    *(int **)(lVar3 + 0x20) = piVar1;

    uVar2 = param_1[1];

    lVar3 = FUN_1402c97f8();

    *(undefined8 *)(lVar3 + 0x28) = uVar2;

                    /* WARNING: Subroutine does not return */

    FUN_1402cf8b8();

  }

  return 0;

}





// Address: 0x14013dbb0
// Ghidra name: FUN_14013dbb0
// ============ 0x14013dbb0 FUN_14013dbb0 (size=110) ============


undefined8 FUN_14013dbb0(undefined8 param_1,int param_2)



{

  longlong lVar1;

  int *piVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  uVar4 = 0;

  FUN_140159d30();

  lVar1 = FUN_14013e670(param_1);

  if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x90))) {

    piVar2 = *(int **)(lVar1 + 0x98);

    lVar3 = 0;

    do {

      if (*piVar2 == param_2) {

        uVar4 = 1;

        break;

      }

      lVar3 = lVar3 + 1;

      piVar2 = piVar2 + 6;

    } while (lVar3 < *(int *)(lVar1 + 0x90));

  }

  FUN_14015bb10();

  return uVar4;

}





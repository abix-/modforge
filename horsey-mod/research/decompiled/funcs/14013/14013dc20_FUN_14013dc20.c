// Address: 0x14013dc20
// Ghidra name: FUN_14013dc20
// ============ 0x14013dc20 FUN_14013dc20 (size=130) ============


undefined1 FUN_14013dc20(undefined8 param_1,int param_2)



{

  longlong lVar1;

  int *piVar2;

  ulonglong uVar3;

  undefined1 uVar4;

  ulonglong uVar5;

  

  uVar4 = 0;

  FUN_140159d30();

  lVar1 = FUN_14013e670(param_1);

  if (lVar1 != 0) {

    uVar3 = 0;

    if (0 < *(int *)(lVar1 + 0x90)) {

      piVar2 = *(int **)(lVar1 + 0x98);

      uVar5 = uVar3;

      do {

        if (*piVar2 == param_2) {

          uVar4 = (undefined1)(*(int **)(lVar1 + 0x98))[(longlong)(int)uVar5 * 6 + 1];

          break;

        }

        uVar5 = (ulonglong)((int)uVar5 + 1);

        uVar3 = uVar3 + 1;

        piVar2 = piVar2 + 6;

      } while ((longlong)uVar3 < (longlong)*(int *)(lVar1 + 0x90));

    }

  }

  FUN_14015bb10();

  return uVar4;

}





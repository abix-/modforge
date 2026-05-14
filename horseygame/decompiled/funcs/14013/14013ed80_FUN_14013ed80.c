// Address: 0x14013ed80
// Ghidra name: FUN_14013ed80
// ============ 0x14013ed80 FUN_14013ed80 (size=164) ============


undefined8 FUN_14013ed80(undefined8 param_1,int param_2,undefined8 param_3,uint param_4)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong lVar3;

  int *piVar4;

  

  FUN_140159d30();

  lVar1 = FUN_14013e670(param_1);

  if ((lVar1 != 0) && (0 < *(int *)(lVar1 + 0x90))) {

    piVar4 = *(int **)(lVar1 + 0x98);

    lVar3 = 0;

    do {

      if (*piVar4 == param_2) {

        if (2 < param_4) {

          param_4 = 3;

        }

        FUN_1402f8e20(param_3,piVar4 + 3,(longlong)(int)param_4 << 2);

        FUN_14015bb10();

        return 1;

      }

      lVar3 = lVar3 + 1;

      piVar4 = piVar4 + 6;

    } while (lVar3 < *(int *)(lVar1 + 0x90));

  }

  FUN_14015bb10();

  uVar2 = FUN_14012e850("That operation is not supported");

  return uVar2;

}





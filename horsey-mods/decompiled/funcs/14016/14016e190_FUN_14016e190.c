// Address: 0x14016e190
// Ghidra name: FUN_14016e190
// ============ 0x14016e190 FUN_14016e190 (size=83) ============


int * FUN_14016e190(int param_1)



{

  int *piVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return (int *)0x0;

  }

  if (param_1 != 0) {

    for (piVar1 = *(int **)(DAT_1403fc410 + 0x348); piVar1 != (int *)0x0;

        piVar1 = *(int **)(piVar1 + 0x68)) {

      if (*piVar1 == param_1) {

        return piVar1;

      }

    }

  }

  FUN_14012e850("Invalid window ID");

  return (int *)0x0;

}





// Address: 0x1402c6d34
// Ghidra name: FUN_1402c6d34
// ============ 0x1402c6d34 FUN_1402c6d34 (size=40) ============


char * FUN_1402c6d34(int param_1)



{

  int *piVar1;

  

  piVar1 = &DAT_140386590;

  do {

    if (*piVar1 == param_1) {

      return *(char **)(piVar1 + 2);

    }

    piVar1 = piVar1 + 4;

  } while (piVar1 != (int *)"success");

  return "unknown error";

}





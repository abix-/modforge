// Address: 0x14020d300
// Ghidra name: FUN_14020d300
// ============ 0x14020d300 FUN_14020d300 (size=56) ============


int * FUN_14020d300(int param_1)



{

  int *piVar1;

  

  _guard_check_icall();

  piVar1 = DAT_1403fd260;

  while( true ) {

    if (piVar1 == (int *)0x0) {

      return (int *)0x0;

    }

    if (param_1 == *piVar1) break;

    piVar1 = *(int **)(piVar1 + 0x42);

  }

  return piVar1;

}





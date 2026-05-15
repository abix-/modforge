// Address: 0x14021ab20
// Ghidra name: FUN_14021ab20
// ============ 0x14021ab20 FUN_14021ab20 (size=35) ============


int * FUN_14021ab20(int param_1)



{

  int *piVar1;

  

  piVar1 = DAT_1403fdb58;

  while( true ) {

    if (piVar1 == (int *)0x0) {

      return (int *)0x0;

    }

    if (param_1 == *piVar1) break;

    piVar1 = *(int **)(piVar1 + 0x124);

  }

  return piVar1;

}





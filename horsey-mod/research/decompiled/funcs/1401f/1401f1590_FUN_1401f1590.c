// Address: 0x1401f1590
// Ghidra name: FUN_1401f1590
// ============ 0x1401f1590 FUN_1401f1590 (size=137) ============


int * FUN_1401f1590(longlong param_1,int param_2,int param_3)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x1d8);

  while( true ) {

    if (piVar1 == (int *)0x0) {

      piVar1 = (int *)FUN_1401841f0(0x18);

      *piVar1 = param_2;

      piVar1[1] = param_3;

      (**(code **)(param_1 + 0xb0))(1,piVar1 + 2);

      *(undefined8 *)(piVar1 + 4) = *(undefined8 *)(param_1 + 0x1d8);

      *(int **)(param_1 + 0x1d8) = piVar1;

      return piVar1;

    }

    if ((*piVar1 == param_2) && (piVar1[1] == param_3)) break;

    piVar1 = *(int **)(piVar1 + 4);

  }

  return piVar1;

}





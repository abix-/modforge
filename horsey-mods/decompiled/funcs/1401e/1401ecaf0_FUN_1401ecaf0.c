// Address: 0x1401ecaf0
// Ghidra name: FUN_1401ecaf0
// ============ 0x1401ecaf0 FUN_1401ecaf0 (size=133) ============


int * FUN_1401ecaf0(longlong param_1,int param_2,int param_3)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 0x30);

  while( true ) {

    if (piVar1 == (int *)0x0) {

      piVar1 = (int *)FUN_1401841f0(0x18);

      if (piVar1 != (int *)0x0) {

        *piVar1 = param_2;

        piVar1[1] = param_3;

        (**(code **)(param_1 + 0x1d0))(1,piVar1 + 2);

        *(undefined8 *)(piVar1 + 4) = *(undefined8 *)(param_1 + 0x30);

        *(int **)(param_1 + 0x30) = piVar1;

      }

      return piVar1;

    }

    if ((*piVar1 == param_2) && (piVar1[1] == param_3)) break;

    piVar1 = *(int **)(piVar1 + 4);

  }

  return piVar1;

}





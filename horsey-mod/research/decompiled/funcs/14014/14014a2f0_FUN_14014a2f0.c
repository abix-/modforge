// Address: 0x14014a2f0
// Ghidra name: FUN_14014a2f0
// ============ 0x14014a2f0 FUN_14014a2f0 (size=98) ============


void FUN_14014a2f0(longlong param_1,undefined8 *param_2)



{

  float fVar1;

  int *piVar2;

  float fVar3;

  

  piVar2 = *(int **)(param_1 + 0x138);

  fVar3 = (float)piVar2[0x24];

  fVar1 = (float)piVar2[0x25];

  *param_2 = 0;

  if (piVar2[4] < 0) {

    fVar3 = (float)*piVar2 / fVar3;

  }

  else {

    fVar3 = (float)piVar2[4];

  }

  *(float *)(param_2 + 1) = fVar3;

  if (-1 < piVar2[5]) {

    *(float *)((longlong)param_2 + 0xc) = (float)piVar2[5];

    return;

  }

  *(float *)((longlong)param_2 + 0xc) = (float)piVar2[1] / fVar1;

  return;

}





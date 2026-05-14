// Address: 0x1402008a0
// Ghidra name: FUN_1402008a0
// ============ 0x1402008a0 FUN_1402008a0 (size=147) ============


undefined8

FUN_1402008a0(undefined8 param_1,longlong param_2,undefined8 param_3,float *param_4,float *param_5)



{

  float fVar1;

  int *piVar2;

  

  piVar2 = (int *)FUN_14014b940(param_1,0x20,0,param_2 + 8);

  if (piVar2 == (int *)0x0) {

    return 0;

  }

  *(undefined8 *)(param_2 + 0x10) = 1;

  *piVar2 = (int)*param_4;

  piVar2[1] = (int)param_4[1];

  piVar2[2] = (int)param_4[2];

  piVar2[3] = (int)param_4[3];

  piVar2[4] = (int)*param_5;

  piVar2[5] = (int)param_5[1];

  piVar2[6] = (int)param_5[2];

  fVar1 = param_5[3];

  piVar2[7] = (int)fVar1;

  return CONCAT71((uint7)(uint3)((uint)(int)fVar1 >> 8),1);

}





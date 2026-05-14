// Address: 0x140077fb0
// Ghidra name: FUN_140077fb0
// ============ 0x140077fb0 FUN_140077fb0 (size=172) ============


void FUN_140077fb0(undefined4 *param_1,float *param_2)



{

  float fVar1;

  double dVar2;

  float fVar3;

  char local_res10 [24];

  

  fVar1 = param_2[1];

  if (param_2[1] <= param_2[2]) {

    fVar1 = param_2[2];

  }

  fVar3 = *param_2;

  if (*param_2 <= fVar1) {

    fVar3 = fVar1;

  }

  if (fVar3 < DAT_14030a5cc) {

    *param_1 = 0;

    return;

  }

  dVar2 = (double)FUN_1402d81b0((double)fVar3,local_res10);

  fVar3 = ((float)dVar2 * DAT_14030a5d0) / fVar3;

  *(char *)param_1 = (char)(int)(fVar3 * *param_2);

  *(char *)((longlong)param_1 + 1) = (char)(int)(fVar3 * param_2[1]);

  fVar1 = param_2[2];

  *(char *)((longlong)param_1 + 3) = local_res10[0] + -0x80;

  *(char *)((longlong)param_1 + 2) = (char)(int)(fVar3 * fVar1);

  return;

}





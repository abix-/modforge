// Address: 0x1400058e0
// Ghidra name: FUN_1400058e0
// ============ 0x1400058e0 FUN_1400058e0 (size=122) ============


ulonglong FUN_1400058e0(float *param_1)



{

  ulonglong uVar1;

  float fVar2;

  

  fVar2 = param_1[1] * param_1[1] + *param_1 * *param_1;

  if (fVar2 < 0.0) {

    uVar1 = FUN_1402cdfa0(fVar2);

  }

  else {

    uVar1 = (ulonglong)(uint)SQRT(fVar2);

  }

  if ((float)uVar1 < DAT_14039c9f0) {

    return 0;

  }

  fVar2 = DAT_14039ca44 / (float)uVar1;

  param_1[1] = fVar2 * param_1[1];

  *param_1 = fVar2 * *param_1;

  return uVar1;

}





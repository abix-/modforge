// Address: 0x1402a1f50
// Ghidra name: FUN_1402a1f50
// ============ 0x1402a1f50 FUN_1402a1f50 (size=67) ============


void FUN_1402a1f50(float *param_1,float *param_2,float *param_3,float param_4,float param_5)



{

  float fVar1;

  float fVar2;

  

  fVar2 = *param_2;

  if (*param_2 <= *param_3) {

    fVar2 = *param_3;

  }

  fVar1 = *param_1;

  if (*param_1 <= fVar2) {

    fVar1 = fVar2;

  }

  if (0.0 < fVar1) {

    fVar2 = fVar1 * param_5 + DAT_14039ca44;

    FUN_1402a1fa0(0,fVar2,param_4,(fVar1 * param_4 + DAT_14039ca44) / fVar2);

    return;

  }

  return;

}





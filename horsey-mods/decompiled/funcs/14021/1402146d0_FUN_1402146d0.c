// Address: 0x1402146d0
// Ghidra name: FUN_1402146d0
// ============ 0x1402146d0 FUN_1402146d0 (size=125) ============


void FUN_1402146d0(float *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  

  fVar1 = DAT_14039ca50;

  if (0 < param_2) {

    iVar2 = 0;

    fVar4 = DAT_14039ca50 / (float)param_2;

    do {

      fVar3 = (float)thunk_FUN_1402cdc50((float)iVar2 * fVar4);

      iVar2 = iVar2 + 1;

      *param_1 = fVar3 / fVar1;

      param_1 = param_1 + 1;

    } while (iVar2 < param_2);

  }

  return;

}





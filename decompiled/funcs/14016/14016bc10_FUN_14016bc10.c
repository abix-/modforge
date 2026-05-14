// Address: 0x14016bc10
// Ghidra name: FUN_14016bc10
// ============ 0x14016bc10 FUN_14016bc10 (size=127) ============


void FUN_14016bc10(longlong param_1)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  if (*(float *)(param_1 + 0x10) <= 0.0) {

    *(undefined4 *)(param_1 + 0x10) = 0x3f800000;

  }

  iVar1 = *(int *)(param_1 + 0x18);

  if (iVar1 < 1) {

    FUN_1401aa3a0(iVar1,param_1 + 0x18);

  }

  else {

    iVar2 = *(int *)(param_1 + 0x1c);

    if (iVar2 < 1) {

      iVar2 = 1;

      *(int *)(param_1 + 0x1c) = 1;

    }

    *(float *)(param_1 + 0x14) = (float)iVar1 / (float)iVar2;

  }

  fVar3 = (float)thunk_FUN_1402e1d00(*(float *)(param_1 + 0x14) * DAT_14039ca5c);

  *(float *)(param_1 + 0x14) = fVar3 / DAT_14039ca5c;

  return;

}





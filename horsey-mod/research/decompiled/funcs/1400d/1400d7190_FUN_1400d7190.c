// Address: 0x1400d7190
// Ghidra name: FUN_1400d7190
// ============ 0x1400d7190 FUN_1400d7190 (size=339) ============


void FUN_1400d7190(longlong *param_1,longlong *param_2,longlong *param_3)



{

  longlong lVar1;

  longlong lVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  

  lVar1 = *param_2;

  lVar2 = *param_1;

  fVar4 = (float)FUN_1400b6150(lVar1);

  fVar5 = (float)FUN_1400b6150(lVar2);

  if (fVar4 == fVar5) {

    bVar3 = *(int *)(lVar1 + 0x1d0) < *(int *)(lVar2 + 0x1d0);

  }

  else {

    fVar4 = (float)FUN_1400b6150(lVar1);

    fVar5 = (float)FUN_1400b6150(lVar2);

    bVar3 = fVar4 < fVar5;

  }

  if (bVar3) {

    lVar1 = *param_2;

    *param_2 = *param_1;

    *param_1 = lVar1;

  }

  lVar1 = *param_3;

  lVar2 = *param_2;

  fVar4 = (float)FUN_1400b6150(lVar1);

  fVar5 = (float)FUN_1400b6150(lVar2);

  if (fVar4 == fVar5) {

    bVar3 = *(int *)(lVar1 + 0x1d0) < *(int *)(lVar2 + 0x1d0);

  }

  else {

    fVar4 = (float)FUN_1400b6150(lVar1);

    fVar5 = (float)FUN_1400b6150(lVar2);

    bVar3 = fVar4 < fVar5;

  }

  if (bVar3) {

    lVar1 = *param_3;

    *param_3 = *param_2;

    *param_2 = lVar1;

    lVar2 = *param_1;

    fVar4 = (float)FUN_1400b6150(lVar1);

    fVar5 = (float)FUN_1400b6150(lVar2);

    if (fVar4 == fVar5) {

      bVar3 = *(int *)(lVar1 + 0x1d0) < *(int *)(lVar2 + 0x1d0);

    }

    else {

      fVar4 = (float)FUN_1400b6150(lVar1);

      fVar5 = (float)FUN_1400b6150(lVar2);

      bVar3 = fVar4 < fVar5;

    }

    if (bVar3) {

      lVar1 = *param_2;

      *param_2 = *param_1;

      *param_1 = lVar1;

    }

  }

  return;

}





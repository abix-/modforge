// Address: 0x14001d7e0
// Ghidra name: FUN_14001d7e0
// ============ 0x14001d7e0 FUN_14001d7e0 (size=571) ============


void FUN_14001d7e0(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar9 = *(float *)(param_1 + 0x9c);

  fVar1 = *(float *)(param_1 + 0xa0);

  lVar8 = (longlong)*(int *)(param_1 + 0xb0);

  lVar7 = *(longlong *)(param_2 + 8);

  fVar2 = *(float *)(lVar7 + 8 + lVar8 * 0xc);

  fVar3 = *(float *)(lVar7 + lVar8 * 0xc);

  fVar4 = *(float *)(lVar7 + 4 + lVar8 * 0xc);

  fVar10 = (float)((uint)((fVar3 - fVar2 * *(float *)(param_1 + 0xb8)) + *(float *)(param_1 + 0xdc)

                         + fVar9 * *(float *)(param_1 + 0xa8)) ^ DAT_14039cac0);

  fVar11 = (float)((uint)(fVar2 * *(float *)(param_1 + 0xb4) + fVar4 + *(float *)(param_1 + 0xe0) +

                         fVar1 * *(float *)(param_1 + 0xa8)) ^ DAT_14039cac0);

  fVar12 = fVar11 * *(float *)(param_1 + 0xd4) + fVar10 * *(float *)(param_1 + 0xcc) + fVar9;

  fVar11 = fVar1 + fVar11 * *(float *)(param_1 + 0xd8) + fVar10 * *(float *)(param_1 + 0xd0);

  *(float *)(param_1 + 0x9c) = fVar12;

  *(float *)(param_1 + 0xa0) = fVar11;

  fVar13 = *(float *)(param_1 + 0xa4) * *param_2;

  fVar10 = fVar11 * fVar11 + fVar12 * fVar12;

  if (fVar13 * fVar13 < fVar10) {

    if (fVar10 < 0.0) {

      fVar10 = (float)FUN_1402cdfa0(fVar10);

    }

    else {

      fVar10 = SQRT(fVar10);

    }

    fVar11 = (fVar13 / fVar10) * *(float *)(param_1 + 0xa0);

    *(float *)(param_1 + 0xa0) = fVar11;

    *(float *)(param_1 + 0x9c) = (fVar13 / fVar10) * fVar12;

  }

  fVar10 = *(float *)(param_1 + 0xc4);

  fVar9 = *(float *)(param_1 + 0x9c) - fVar9;

  iVar6 = *(int *)(param_1 + 0xb0);

  lVar7 = *(longlong *)(param_2 + 8);

  fVar12 = *(float *)(param_1 + 0xb8);

  fVar13 = *(float *)(param_1 + 0xb4);

  fVar5 = *(float *)(param_1 + 200);

  *(float *)(lVar7 + (longlong)iVar6 * 0xc) = fVar10 * fVar9 + fVar3;

  *(float *)(lVar7 + 4 + (longlong)iVar6 * 0xc) = fVar10 * (fVar11 - fVar1) + fVar4;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xb0) * 0xc) =

       ((fVar11 - fVar1) * fVar13 - fVar9 * fVar12) * fVar5 + fVar2;

  return;

}





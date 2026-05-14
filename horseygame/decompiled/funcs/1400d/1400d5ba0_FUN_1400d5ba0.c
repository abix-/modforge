// Address: 0x1400d5ba0
// Ghidra name: FUN_1400d5ba0
// ============ 0x1400d5ba0 FUN_1400d5ba0 (size=483) ============


void FUN_1400d5ba0(longlong param_1,int param_2)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  undefined4 uVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar6 = DAT_14039ca38;

  fVar10 = DAT_14030d954;

  fVar5 = DAT_140304b2c;

  lVar3 = *(longlong *)(param_1 + 0x78);

  lVar9 = (longlong)param_2;

  uVar4 = DAT_1403da828;

  if (*(int *)(param_1 + 0x1c0) == param_2) {

    uVar4 = DAT_1403da86c;

  }

  iVar8 = 0;

  fVar1 = *(float *)(lVar3 + 8 + lVar9 * 0x10);

  fVar13 = *(float *)(lVar3 + 0xc + lVar9 * 0x10);

  fVar11 = *(float *)(lVar3 + 4 + lVar9 * 0x10) - DAT_14039ca38;

  fVar2 = *(float *)(lVar3 + lVar9 * 0x10);

  fVar12 = fVar13 + fVar11;

  iVar7 = (int)((fVar1 - DAT_14039ca34) - DAT_140304b2c);

  do {

    FUN_140071000(fVar2,(float)iVar8 * fVar10 + fVar11,fVar1,fVar5,uVar4);

    FUN_140071000(fVar2,fVar12 + (float)iVar8 * fVar10,fVar1,fVar5,uVar4);

    iVar8 = iVar8 + 1;

  } while (iVar8 < 2);

  fVar13 = fVar13 + fVar6;

  FUN_140071000(fVar2,fVar11,fVar5,fVar13,uVar4);

  FUN_140071000((fVar1 + fVar2) - fVar5,fVar11,fVar5,fVar13,uVar4);

  iVar8 = 1;

  if (0 < iVar7) {

    do {

      fVar10 = (float)iVar8 + fVar2 + 0.0;

      FUN_140071000(fVar10,fVar11,fVar5,fVar6,uVar4);

      FUN_140071000(fVar10,fVar12,fVar5,fVar6,uVar4);

      iVar8 = iVar8 + 1;

    } while (iVar8 <= iVar7);

  }

  return;

}





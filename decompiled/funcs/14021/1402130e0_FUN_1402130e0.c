// Address: 0x1402130e0
// Ghidra name: FUN_1402130e0
// ============ 0x1402130e0 FUN_1402130e0 (size=426) ============


void FUN_1402130e0(void)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  float *pfVar6;

  longlong lVar7;

  longlong lVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  undefined1 local_2f8 [96];

  undefined4 local_298;

  float local_294 [163];

  

  fVar1 = DAT_1403539b4;

  fVar10 = (float)FUN_140212f80(DAT_1403539b4);

  FUN_1402146d0(local_2f8,0x18);

  fVar2 = DAT_1403539bc;

  pfVar6 = local_294;

  local_298 = 0x3f800000;

  iVar4 = 1;

  do {

    fVar11 = (float)FUN_1401905d0((fVar2 - (float)(iVar4 * iVar4)) / fVar2);

    fVar11 = (float)FUN_140212f80(fVar11 * fVar1);

    fVar11 = fVar11 / fVar10;

    fVar12 = (float)FUN_140214690(local_2f8,iVar4,0x18);

    iVar4 = iVar4 + 1;

    *pfVar6 = fVar11 * fVar12;

    pfVar6 = pfVar6 + 1;

  } while (iVar4 < 0x91);

  lVar3 = 0;

  lVar7 = 8;

  lVar8 = 0x54;

  do {

    iVar4 = 6;

    iVar9 = 5;

    lVar5 = 6;

    do {

      FUN_140213000(&DAT_1403fd450 + (iVar9 + lVar3) * 0x10);

      FUN_140213000(&DAT_1403fd450 + (iVar4 + lVar8) * 0x10);

      iVar9 = iVar9 + -1;

      iVar4 = iVar4 + 1;

      lVar5 = lVar5 + -1;

    } while (lVar5 != 0);

    lVar3 = lVar3 + 0xc;

    lVar8 = lVar8 + -0xc;

    lVar7 = lVar7 + -1;

  } while (lVar7 != 0);

  return;

}





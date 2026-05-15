// Address: 0x140203d20
// Ghidra name: FUN_140203d20
// ============ 0x140203d20 FUN_140203d20 (size=589) ============


undefined1 FUN_140203d20(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  char cVar7;

  undefined1 uVar8;

  float *pfVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  float *pfVar13;

  

  fVar2 = *(float *)(param_2 + 0x1c);

  fVar3 = *(float *)(param_2 + 0x20);

  fVar4 = *(float *)(param_2 + 0x24);

  fVar5 = *(float *)(param_2 + 0x28);

  lVar12 = (longlong)param_4;

  cVar7 = FUN_1401538c0();

  pfVar9 = (float *)FUN_14014b940(param_1,lVar12 * 0x18,0,param_2 + 8);

  uVar8 = SUB81(pfVar9,0);

  if (pfVar9 != (float *)0x0) {

    if (cVar7 != '\0') {

      FUN_14014bd40();

    }

    fVar6 = DAT_14039ca34;

    lVar10 = 0;

    *(longlong *)(param_2 + 0x10) = lVar12;

    if (3 < lVar12) {

      pfVar13 = (float *)(param_3 + 8);

      lVar11 = (lVar12 - 4U >> 2) + 1;

      lVar10 = lVar11 * 4;

      do {

        *pfVar9 = pfVar13[-2] + fVar6;

        pfVar9[1] = pfVar13[-1] + fVar6;

        pfVar9[2] = fVar2;

        pfVar9[3] = fVar3;

        pfVar9[4] = fVar4;

        pfVar9[5] = fVar5;

        pfVar9[6] = *pfVar13 + fVar6;

        pfVar9[7] = pfVar13[1] + fVar6;

        pfVar9[8] = fVar2;

        pfVar9[9] = fVar3;

        pfVar9[10] = fVar4;

        pfVar9[0xb] = fVar5;

        pfVar9[0xc] = pfVar13[2] + fVar6;

        pfVar9[0xd] = pfVar13[3] + fVar6;

        pfVar9[0xe] = fVar2;

        pfVar9[0xf] = fVar3;

        pfVar9[0x10] = fVar4;

        pfVar9[0x11] = fVar5;

        pfVar9[0x12] = pfVar13[4] + fVar6;

        pfVar1 = pfVar13 + 5;

        pfVar13 = pfVar13 + 8;

        pfVar9[0x13] = *pfVar1 + fVar6;

        pfVar9[0x14] = fVar2;

        pfVar9[0x15] = fVar3;

        pfVar9[0x16] = fVar4;

        pfVar9[0x17] = fVar5;

        pfVar9 = pfVar9 + 0x18;

        lVar11 = lVar11 + -1;

      } while (lVar11 != 0);

    }

    for (; lVar10 < lVar12; lVar10 = lVar10 + 1) {

      *pfVar9 = *(float *)(param_3 + lVar10 * 8) + fVar6;

      pfVar9[1] = *(float *)(param_3 + 4 + lVar10 * 8) + fVar6;

      pfVar9[2] = fVar2;

      pfVar9[3] = fVar3;

      pfVar9[4] = fVar4;

      pfVar9[5] = fVar5;

      pfVar9 = pfVar9 + 6;

    }

    uVar8 = 1;

  }

  return uVar8;

}





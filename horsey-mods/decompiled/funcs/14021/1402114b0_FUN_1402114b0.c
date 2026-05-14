// Address: 0x1402114b0
// Ghidra name: FUN_1402114b0
// ============ 0x1402114b0 FUN_1402114b0 (size=282) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402114b0(undefined2 *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  longlong lVar2;

  float fVar3;

  undefined1 auVar4 [16];

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  undefined2 *puVar12;

  float *pfVar13;

  int iVar14;

  ulonglong uVar15;

  undefined1 (*pauVar16) [16];

  uint uVar17;

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  ulonglong uVar18;

  

  fVar11 = _UNK_14035393c;

  fVar10 = _UNK_140353938;

  fVar9 = _UNK_140353934;

  fVar8 = _DAT_140353930;

  uVar15 = 0;

  uVar17 = 0;

  if (0xf < param_3) {

    puVar12 = param_1;

    uVar18 = uVar15;

    if (((ulonglong)param_1 & 0xf) != 0) {

      do {

        lVar2 = uVar15 * 4;

        uVar17 = (int)uVar18 + 1;

        uVar18 = (ulonglong)uVar17;

        uVar15 = (ulonglong)(int)uVar17;

        auVar19._0_4_ = (int)(*(float *)(param_2 + lVar2) + fVar8) - (int)fVar8;

        auVar19._4_4_ = -(int)fVar9;

        auVar19._8_4_ = -(int)fVar10;

        auVar19._12_4_ = -(int)fVar11;

        auVar19 = packssdw(auVar19,auVar19);

        *puVar12 = auVar19._0_2_;

        puVar12 = puVar12 + 1;

      } while (((char)uVar17 * '\x02' + (char)param_1 & 0xfU) != 0);

    }

    uVar17 = (uint)uVar18;

    iVar14 = uVar17 + 0x10;

    if (iVar14 <= param_3) {

      pauVar16 = (undefined1 (*) [16])(param_1 + (int)uVar17);

      pfVar13 = (float *)(param_2 + 0x30 + (longlong)(int)uVar17 * 4);

      do {

        uVar17 = (int)uVar18 + 0x10;

        uVar18 = (ulonglong)uVar17;

        iVar14 = iVar14 + 0x10;

        auVar22._0_4_ = (int)(pfVar13[-4] + fVar8) - (int)fVar8;

        auVar22._4_4_ = (int)(pfVar13[-3] + fVar9) - (int)fVar9;

        auVar22._8_4_ = (int)(pfVar13[-2] + fVar10) - (int)fVar10;

        auVar22._12_4_ = (int)(pfVar13[-1] + fVar11) - (int)fVar11;

        auVar23._4_4_ = (int)(pfVar13[1] + fVar9) - (int)fVar9;

        auVar23._0_4_ = (int)(*pfVar13 + fVar8) - (int)fVar8;

        auVar23._8_4_ = (int)(pfVar13[2] + fVar10) - (int)fVar10;

        auVar23._12_4_ = (int)(pfVar13[3] + fVar11) - (int)fVar11;

        auVar23 = packssdw(auVar22,auVar23);

        auVar20._0_4_ = (int)(pfVar13[-0xc] + fVar8) - (int)fVar8;

        auVar20._4_4_ = (int)(pfVar13[-0xb] + fVar9) - (int)fVar9;

        auVar20._8_4_ = (int)(pfVar13[-10] + fVar10) - (int)fVar10;

        auVar20._12_4_ = (int)(pfVar13[-9] + fVar11) - (int)fVar11;

        pfVar1 = pfVar13 + -8;

        pfVar5 = pfVar13 + -7;

        pfVar6 = pfVar13 + -6;

        pfVar7 = pfVar13 + -5;

        pfVar13 = pfVar13 + 0x10;

        auVar4._4_4_ = (int)(*pfVar5 + fVar9) - (int)fVar9;

        auVar4._0_4_ = (int)(*pfVar1 + fVar8) - (int)fVar8;

        auVar4._8_4_ = (int)(*pfVar6 + fVar10) - (int)fVar10;

        auVar4._12_4_ = (int)(*pfVar7 + fVar11) - (int)fVar11;

        auVar19 = packssdw(auVar20,auVar4);

        *pauVar16 = auVar19;

        pauVar16[1] = auVar23;

        pauVar16 = pauVar16 + 2;

      } while (iVar14 <= param_3);

    }

  }

  if ((int)uVar17 < param_3) {

    uVar15 = (ulonglong)(param_3 - uVar17);

    param_1 = param_1 + (int)uVar17;

    pfVar13 = (float *)(param_2 + (longlong)(int)uVar17 * 4);

    do {

      fVar3 = *pfVar13;

      pfVar13 = pfVar13 + 1;

      auVar21._0_4_ = (int)(fVar3 + fVar8) - (int)fVar8;

      auVar21._4_4_ = -(int)fVar9;

      auVar21._8_4_ = -(int)fVar10;

      auVar21._12_4_ = -(int)fVar11;

      auVar19 = packssdw(auVar21,auVar21);

      *param_1 = auVar19._0_2_;

      param_1 = param_1 + 1;

      uVar15 = uVar15 - 1;

    } while (uVar15 != 0);

  }

  return;

}





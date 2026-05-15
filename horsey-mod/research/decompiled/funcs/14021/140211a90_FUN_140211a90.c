// Address: 0x140211a90
// Ghidra name: FUN_140211a90
// ============ 0x140211a90 FUN_140211a90 (size=244) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140211a90(undefined1 *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short sVar11;

  short sVar12;

  short sVar13;

  short sVar14;

  short sVar15;

  short sVar16;

  short sVar17;

  short sVar18;

  undefined1 auVar19 [16];

  float *pfVar20;

  float *pfVar21;

  float *pfVar22;

  uint uVar23;

  uint uVar24;

  uint uVar25;

  uint uVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  undefined1 *puVar30;

  float *pfVar31;

  int iVar32;

  ulonglong uVar33;

  char *pcVar34;

  uint uVar35;

  uint uVar37;

  uint uVar40;

  uint uVar41;

  undefined1 auVar38 [16];

  undefined1 auVar39 [16];

  uint uVar42;

  uint uVar43;

  uint uVar45;

  uint uVar46;

  undefined1 auVar44 [16];

  uint uVar47;

  ulonglong uVar36;

  

  fVar29 = _UNK_14035395c;

  fVar28 = _UNK_140353958;

  fVar2 = _UNK_140353954;

  fVar27 = _DAT_140353950;

  uVar26 = _UNK_14033c2bc;

  uVar25 = _UNK_14033c2b8;

  uVar24 = _UNK_14033c2b4;

  uVar23 = _DAT_14033c2b0;

  uVar33 = 0;

  uVar35 = 0;

  if (0xf < param_3) {

    puVar30 = param_1;

    uVar36 = uVar33;

    if (((ulonglong)param_1 & 0xf) != 0) {

      do {

        uVar35 = (int)uVar36 + 1;

        uVar36 = (ulonglong)uVar35;

        auVar38 = ZEXT416((uint)(*(float *)(param_2 + uVar33 * 4) + fVar27));

        uVar33 = (ulonglong)(int)uVar35;

        auVar38 = packsswb(auVar38,auVar38);

        *puVar30 = auVar38[0];

        puVar30 = puVar30 + 1;

      } while (((int)param_1 + uVar35 & 0xf) != 0);

    }

    uVar35 = (uint)uVar36;

    iVar32 = uVar35 + 0x10;

    if (iVar32 <= param_3) {

      pcVar34 = param_1 + (int)uVar35;

      pfVar31 = (float *)(param_2 + 0x20 + (longlong)(int)uVar35 * 4);

      do {

        uVar35 = (int)uVar36 + 0x10;

        uVar36 = (ulonglong)uVar35;

        iVar32 = iVar32 + 0x10;

        auVar44._0_4_ = pfVar31[-8] + fVar27;

        auVar44._4_4_ = pfVar31[-7] + fVar2;

        auVar44._8_4_ = pfVar31[-6] + fVar28;

        auVar44._12_4_ = pfVar31[-5] + fVar29;

        auVar39._0_4_ = *pfVar31 + fVar27;

        auVar39._4_4_ = pfVar31[1] + fVar2;

        auVar39._8_4_ = pfVar31[2] + fVar28;

        auVar39._12_4_ = pfVar31[3] + fVar29;

        auVar38._4_4_ = pfVar31[-3] + fVar2;

        auVar38._0_4_ = pfVar31[-4] + fVar27;

        auVar38._8_4_ = pfVar31[-2] + fVar28;

        auVar38._12_4_ = pfVar31[-1] + fVar29;

        auVar38 = packsswb(auVar44,auVar38);

        pfVar1 = pfVar31 + 4;

        pfVar20 = pfVar31 + 5;

        pfVar21 = pfVar31 + 6;

        pfVar22 = pfVar31 + 7;

        pfVar31 = pfVar31 + 0x10;

        uVar43 = auVar38._0_4_ & uVar23;

        uVar45 = auVar38._4_4_ & uVar24;

        uVar46 = auVar38._8_4_ & uVar25;

        uVar47 = auVar38._12_4_ & uVar26;

        auVar19._4_4_ = *pfVar20 + fVar2;

        auVar19._0_4_ = *pfVar1 + fVar27;

        auVar19._8_4_ = *pfVar21 + fVar28;

        auVar19._12_4_ = *pfVar22 + fVar29;

        auVar38 = packsswb(auVar39,auVar19);

        uVar37 = auVar38._0_4_ & uVar23;

        uVar40 = auVar38._4_4_ & uVar24;

        uVar41 = auVar38._8_4_ & uVar25;

        uVar42 = auVar38._12_4_ & uVar26;

        sVar3 = (short)uVar43;

        sVar4 = (short)(uVar43 >> 0x10);

        sVar5 = (short)uVar45;

        sVar6 = (short)(uVar45 >> 0x10);

        sVar7 = (short)uVar46;

        sVar8 = (short)(uVar46 >> 0x10);

        sVar9 = (short)uVar47;

        sVar10 = (short)(uVar47 >> 0x10);

        sVar11 = (short)uVar37;

        sVar12 = (short)(uVar37 >> 0x10);

        sVar13 = (short)uVar40;

        sVar14 = (short)(uVar40 >> 0x10);

        sVar15 = (short)uVar41;

        sVar16 = (short)(uVar41 >> 0x10);

        sVar17 = (short)uVar42;

        sVar18 = (short)(uVar42 >> 0x10);

        *pcVar34 = (0 < sVar3) * (sVar3 < 0x100) * (char)uVar43 - (0xff < sVar3);

        pcVar34[1] = (0 < sVar4) * (sVar4 < 0x100) * (char)(uVar43 >> 0x10) - (0xff < sVar4);

        pcVar34[2] = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar45 - (0xff < sVar5);

        pcVar34[3] = (0 < sVar6) * (sVar6 < 0x100) * (char)(uVar45 >> 0x10) - (0xff < sVar6);

        pcVar34[4] = (0 < sVar7) * (sVar7 < 0x100) * (char)uVar46 - (0xff < sVar7);

        pcVar34[5] = (0 < sVar8) * (sVar8 < 0x100) * (char)(uVar46 >> 0x10) - (0xff < sVar8);

        pcVar34[6] = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar47 - (0xff < sVar9);

        pcVar34[7] = (0 < sVar10) * (sVar10 < 0x100) * (char)(uVar47 >> 0x10) - (0xff < sVar10);

        pcVar34[8] = (0 < sVar11) * (sVar11 < 0x100) * (char)uVar37 - (0xff < sVar11);

        pcVar34[9] = (0 < sVar12) * (sVar12 < 0x100) * (char)(uVar37 >> 0x10) - (0xff < sVar12);

        pcVar34[10] = (0 < sVar13) * (sVar13 < 0x100) * (char)uVar40 - (0xff < sVar13);

        pcVar34[0xb] = (0 < sVar14) * (sVar14 < 0x100) * (char)(uVar40 >> 0x10) - (0xff < sVar14);

        pcVar34[0xc] = (0 < sVar15) * (sVar15 < 0x100) * (char)uVar41 - (0xff < sVar15);

        pcVar34[0xd] = (0 < sVar16) * (sVar16 < 0x100) * (char)(uVar41 >> 0x10) - (0xff < sVar16);

        pcVar34[0xe] = (0 < sVar17) * (sVar17 < 0x100) * (char)uVar42 - (0xff < sVar17);

        pcVar34[0xf] = (0 < sVar18) * (sVar18 < 0x100) * (char)(uVar42 >> 0x10) - (0xff < sVar18);

        pcVar34 = pcVar34 + 0x10;

      } while (iVar32 <= param_3);

    }

  }

  if ((int)uVar35 < param_3) {

    uVar33 = (ulonglong)(param_3 - uVar35);

    param_1 = param_1 + (int)uVar35;

    pfVar31 = (float *)(param_2 + (longlong)(int)uVar35 * 4);

    do {

      fVar2 = *pfVar31;

      pfVar31 = pfVar31 + 1;

      auVar38 = packsswb(ZEXT416((uint)(fVar2 + fVar27)),ZEXT416((uint)(fVar2 + fVar27)));

      *param_1 = auVar38[0];

      param_1 = param_1 + 1;

      uVar33 = uVar33 - 1;

    } while (uVar33 != 0);

  }

  return;

}





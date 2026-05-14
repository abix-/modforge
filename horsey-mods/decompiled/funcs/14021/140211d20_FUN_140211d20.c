// Address: 0x140211d20
// Ghidra name: FUN_140211d20
// ============ 0x140211d20 FUN_140211d20 (size=244) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140211d20(char *param_1,longlong param_2,int param_3)



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

  undefined6 uVar20;

  undefined8 uVar21;

  unkbyte10 Var22;

  undefined1 auVar23 [12];

  undefined1 auVar24 [14];

  undefined1 auVar25 [16];

  undefined1 auVar26 [12];

  undefined1 auVar27 [14];

  float fVar28;

  uint uVar29;

  float fVar30;

  uint uVar31;

  float fVar32;

  uint uVar33;

  float fVar34;

  uint uVar35;

  undefined1 auVar36 [16];

  undefined1 auVar37 [12];

  undefined1 auVar38 [14];

  undefined1 auVar39 [16];

  undefined6 uVar40;

  undefined8 uVar41;

  unkbyte10 Var42;

  undefined1 auVar43 [12];

  undefined1 auVar44 [14];

  uint uVar45;

  uint uVar46;

  uint uVar47;

  uint uVar48;

  float *pfVar49;

  float *pfVar50;

  float *pfVar51;

  uint uVar52;

  uint uVar53;

  uint uVar54;

  uint uVar55;

  float fVar56;

  float fVar57;

  float fVar58;

  float *pfVar59;

  int iVar60;

  ulonglong uVar61;

  char *pcVar62;

  uint uVar63;

  float fVar65;

  float fVar66;

  float fVar67;

  float fVar68;

  float fVar69;

  float fVar70;

  float fVar71;

  float fVar72;

  char cVar73;

  char cVar74;

  char cVar75;

  char cVar76;

  char cVar77;

  char cVar78;

  ulonglong uVar64;

  

  fVar58 = _UNK_14035396c;

  fVar57 = _UNK_140353968;

  fVar2 = _UNK_140353964;

  fVar56 = _DAT_140353960;

  uVar55 = _UNK_14033c2bc;

  uVar54 = _UNK_14033c2b8;

  uVar53 = _UNK_14033c2b4;

  uVar52 = _DAT_14033c2b0;

  uVar61 = 0;

  uVar63 = 0;

  if (0xf < param_3) {

    pcVar62 = param_1;

    uVar64 = uVar61;

    if (((ulonglong)param_1 & 0xf) != 0) {

      do {

        uVar63 = (int)uVar64 + 1;

        uVar64 = (ulonglong)uVar63;

        fVar28 = *(float *)(param_2 + uVar61 * 4) + fVar56;

        uVar61 = (ulonglong)(int)uVar63;

        sVar3 = SUB42(fVar28,0);

        *pcVar62 = (0 < sVar3) * (sVar3 < 0x100) * SUB41(fVar28,0) - (0xff < sVar3);

        pcVar62 = pcVar62 + 1;

      } while (((int)param_1 + uVar63 & 0xf) != 0);

    }

    uVar63 = (uint)uVar64;

    iVar60 = uVar63 + 0x10;

    if (iVar60 <= param_3) {

      pcVar62 = param_1 + (int)uVar63;

      pfVar59 = (float *)(param_2 + 0x20 + (longlong)(int)uVar63 * 4);

      do {

        uVar63 = (int)uVar64 + 0x10;

        uVar64 = (ulonglong)uVar63;

        iVar60 = iVar60 + 0x10;

        fVar66 = pfVar59[-8] + fVar56;

        fVar68 = pfVar59[-7] + fVar2;

        cVar76 = (char)((uint)fVar68 >> 0x10);

        fVar70 = pfVar59[-6] + fVar57;

        cVar77 = (char)((uint)fVar70 >> 0x10);

        fVar72 = pfVar59[-5] + fVar58;

        cVar78 = (char)((uint)fVar72 >> 0x10);

        fVar65 = pfVar59[-4] + fVar56;

        fVar67 = pfVar59[-3] + fVar2;

        fVar69 = pfVar59[-2] + fVar57;

        fVar71 = pfVar59[-1] + fVar58;

        fVar28 = *pfVar59 + fVar56;

        fVar30 = pfVar59[1] + fVar2;

        cVar73 = (char)((uint)fVar30 >> 0x10);

        fVar32 = pfVar59[2] + fVar57;

        cVar74 = (char)((uint)fVar32 >> 0x10);

        fVar34 = pfVar59[3] + fVar58;

        cVar75 = (char)((uint)fVar34 >> 0x10);

        uVar20 = CONCAT15((char)((uint)fVar68 >> 8),CONCAT14(SUB41(fVar68,0),fVar66));

        uVar21 = CONCAT17((char)((uint)fVar68 >> 0x18),CONCAT16(cVar76,uVar20));

        Var22 = CONCAT19((char)((uint)fVar70 >> 8),CONCAT18(SUB41(fVar70,0),uVar21));

        auVar37[10] = cVar77;

        auVar37._0_10_ = Var22;

        auVar37[0xb] = (char)((uint)fVar70 >> 0x18);

        auVar38[0xc] = SUB41(fVar72,0);

        auVar38._0_12_ = auVar37;

        auVar38[0xd] = (char)((uint)fVar72 >> 8);

        auVar36[0xe] = cVar78;

        auVar36._0_14_ = auVar38;

        auVar36[0xf] = (char)((uint)fVar72 >> 0x18);

        sVar3 = SUB42(fVar66,0);

        sVar4 = (short)((uint)fVar66 >> 0x10);

        sVar5 = (short)((uint6)uVar20 >> 0x20);

        sVar6 = (short)((ulonglong)uVar21 >> 0x30);

        sVar7 = (short)((unkuint10)Var22 >> 0x40);

        sVar8 = auVar37._10_2_;

        sVar9 = auVar38._12_2_;

        sVar10 = auVar36._14_2_;

        sVar11 = SUB42(fVar65,0);

        sVar12 = (short)((uint)fVar65 >> 0x10);

        sVar13 = SUB42(fVar67,0);

        sVar14 = (short)((uint)fVar67 >> 0x10);

        sVar15 = SUB42(fVar69,0);

        sVar16 = (short)((uint)fVar69 >> 0x10);

        sVar17 = SUB42(fVar71,0);

        sVar18 = (short)((uint)fVar71 >> 0x10);

        pfVar1 = pfVar59 + 4;

        pfVar49 = pfVar59 + 5;

        pfVar50 = pfVar59 + 6;

        pfVar51 = pfVar59 + 7;

        pfVar59 = pfVar59 + 0x10;

        uVar45 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar76 - (0xff < sVar6),

                          CONCAT12((0 < sVar5) * (sVar5 < 0x100) * SUB41(fVar68,0) - (0xff < sVar5),

                                   CONCAT11((0 < sVar4) * (sVar4 < 0x100) *

                                            (char)((uint)fVar66 >> 0x10) - (0xff < sVar4),

                                            (0 < sVar3) * (sVar3 < 0x100) * SUB41(fVar66,0) -

                                            (0xff < sVar3)))) & uVar52;

        uVar46 = CONCAT13((0 < sVar10) * (sVar10 < 0x100) * cVar78 - (0xff < sVar10),

                          CONCAT12((0 < sVar9) * (sVar9 < 0x100) * SUB41(fVar72,0) - (0xff < sVar9),

                                   CONCAT11((0 < sVar8) * (sVar8 < 0x100) * cVar77 - (0xff < sVar8),

                                            (0 < sVar7) * (sVar7 < 0x100) * SUB41(fVar70,0) -

                                            (0xff < sVar7)))) & uVar53;

        cVar76 = (char)(uVar46 >> 0x10);

        uVar47 = CONCAT13((0 < sVar14) * (sVar14 < 0x100) * (char)((uint)fVar67 >> 0x10) -

                          (0xff < sVar14),

                          CONCAT12((0 < sVar13) * (sVar13 < 0x100) * SUB41(fVar67,0) -

                                   (0xff < sVar13),

                                   CONCAT11((0 < sVar12) * (sVar12 < 0x100) *

                                            (char)((uint)fVar65 >> 0x10) - (0xff < sVar12),

                                            (0 < sVar11) * (sVar11 < 0x100) * SUB41(fVar65,0) -

                                            (0xff < sVar11)))) & uVar54;

        cVar77 = (char)(uVar47 >> 0x10);

        uVar48 = CONCAT13((0 < sVar18) * (sVar18 < 0x100) * (char)((uint)fVar71 >> 0x10) -

                          (0xff < sVar18),

                          CONCAT12((0 < sVar17) * (sVar17 < 0x100) * SUB41(fVar71,0) -

                                   (0xff < sVar17),

                                   CONCAT11((0 < sVar16) * (sVar16 < 0x100) *

                                            (char)((uint)fVar69 >> 0x10) - (0xff < sVar16),

                                            (0 < sVar15) * (sVar15 < 0x100) * SUB41(fVar69,0) -

                                            (0xff < sVar15)))) & uVar55;

        cVar78 = (char)(uVar48 >> 0x10);

        fVar66 = *pfVar1 + fVar56;

        fVar68 = *pfVar49 + fVar2;

        fVar70 = *pfVar50 + fVar57;

        fVar72 = *pfVar51 + fVar58;

        uVar20 = CONCAT15((char)((uint)fVar30 >> 8),CONCAT14(SUB41(fVar30,0),fVar28));

        uVar21 = CONCAT17((char)((uint)fVar30 >> 0x18),CONCAT16(cVar73,uVar20));

        Var22 = CONCAT19((char)((uint)fVar32 >> 8),CONCAT18(SUB41(fVar32,0),uVar21));

        auVar23[10] = cVar74;

        auVar23._0_10_ = Var22;

        auVar23[0xb] = (char)((uint)fVar32 >> 0x18);

        auVar24[0xc] = SUB41(fVar34,0);

        auVar24._0_12_ = auVar23;

        auVar24[0xd] = (char)((uint)fVar34 >> 8);

        auVar19[0xe] = cVar75;

        auVar19._0_14_ = auVar24;

        auVar19[0xf] = (char)((uint)fVar34 >> 0x18);

        sVar3 = SUB42(fVar28,0);

        sVar4 = (short)((uint)fVar28 >> 0x10);

        sVar5 = (short)((uint6)uVar20 >> 0x20);

        sVar6 = (short)((ulonglong)uVar21 >> 0x30);

        sVar7 = (short)((unkuint10)Var22 >> 0x40);

        sVar8 = auVar23._10_2_;

        sVar9 = auVar24._12_2_;

        sVar10 = auVar19._14_2_;

        sVar11 = SUB42(fVar66,0);

        sVar12 = (short)((uint)fVar66 >> 0x10);

        sVar13 = SUB42(fVar68,0);

        sVar14 = (short)((uint)fVar68 >> 0x10);

        sVar15 = SUB42(fVar70,0);

        sVar16 = (short)((uint)fVar70 >> 0x10);

        sVar17 = SUB42(fVar72,0);

        sVar18 = (short)((uint)fVar72 >> 0x10);

        uVar29 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar73 - (0xff < sVar6),

                          CONCAT12((0 < sVar5) * (sVar5 < 0x100) * SUB41(fVar30,0) - (0xff < sVar5),

                                   CONCAT11((0 < sVar4) * (sVar4 < 0x100) *

                                            (char)((uint)fVar28 >> 0x10) - (0xff < sVar4),

                                            (0 < sVar3) * (sVar3 < 0x100) * SUB41(fVar28,0) -

                                            (0xff < sVar3)))) & uVar52;

        uVar31 = CONCAT13((0 < sVar10) * (sVar10 < 0x100) * cVar75 - (0xff < sVar10),

                          CONCAT12((0 < sVar9) * (sVar9 < 0x100) * SUB41(fVar34,0) - (0xff < sVar9),

                                   CONCAT11((0 < sVar8) * (sVar8 < 0x100) * cVar74 - (0xff < sVar8),

                                            (0 < sVar7) * (sVar7 < 0x100) * SUB41(fVar32,0) -

                                            (0xff < sVar7)))) & uVar53;

        cVar73 = (char)(uVar31 >> 0x10);

        uVar33 = CONCAT13((0 < sVar14) * (sVar14 < 0x100) * (char)((uint)fVar68 >> 0x10) -

                          (0xff < sVar14),

                          CONCAT12((0 < sVar13) * (sVar13 < 0x100) * SUB41(fVar68,0) -

                                   (0xff < sVar13),

                                   CONCAT11((0 < sVar12) * (sVar12 < 0x100) *

                                            (char)((uint)fVar66 >> 0x10) - (0xff < sVar12),

                                            (0 < sVar11) * (sVar11 < 0x100) * SUB41(fVar66,0) -

                                            (0xff < sVar11)))) & uVar54;

        cVar74 = (char)(uVar33 >> 0x10);

        uVar35 = CONCAT13((0 < sVar18) * (sVar18 < 0x100) * (char)((uint)fVar72 >> 0x10) -

                          (0xff < sVar18),

                          CONCAT12((0 < sVar17) * (sVar17 < 0x100) * SUB41(fVar72,0) -

                                   (0xff < sVar17),

                                   CONCAT11((0 < sVar16) * (sVar16 < 0x100) *

                                            (char)((uint)fVar70 >> 0x10) - (0xff < sVar16),

                                            (0 < sVar15) * (sVar15 < 0x100) * SUB41(fVar70,0) -

                                            (0xff < sVar15)))) & uVar55;

        cVar75 = (char)(uVar35 >> 0x10);

        uVar40 = CONCAT15((char)(uVar46 >> 8),CONCAT14((char)uVar46,uVar45));

        uVar41 = CONCAT17((char)(uVar46 >> 0x18),CONCAT16(cVar76,uVar40));

        Var42 = CONCAT19((char)(uVar47 >> 8),CONCAT18((char)uVar47,uVar41));

        auVar43[10] = cVar77;

        auVar43._0_10_ = Var42;

        auVar43[0xb] = (char)(uVar47 >> 0x18);

        auVar44[0xc] = (char)uVar48;

        auVar44._0_12_ = auVar43;

        auVar44[0xd] = (char)(uVar48 >> 8);

        auVar39[0xe] = cVar78;

        auVar39._0_14_ = auVar44;

        auVar39[0xf] = (char)(uVar48 >> 0x18);

        uVar20 = CONCAT15((char)(uVar31 >> 8),CONCAT14((char)uVar31,uVar29));

        uVar21 = CONCAT17((char)(uVar31 >> 0x18),CONCAT16(cVar73,uVar20));

        Var22 = CONCAT19((char)(uVar33 >> 8),CONCAT18((char)uVar33,uVar21));

        auVar26[10] = cVar74;

        auVar26._0_10_ = Var22;

        auVar26[0xb] = (char)(uVar33 >> 0x18);

        auVar27[0xc] = (char)uVar35;

        auVar27._0_12_ = auVar26;

        auVar27[0xd] = (char)(uVar35 >> 8);

        auVar25[0xe] = cVar75;

        auVar25._0_14_ = auVar27;

        auVar25[0xf] = (char)(uVar35 >> 0x18);

        sVar3 = (short)uVar45;

        sVar4 = (short)(uVar45 >> 0x10);

        sVar5 = (short)((uint6)uVar40 >> 0x20);

        sVar6 = (short)((ulonglong)uVar41 >> 0x30);

        sVar7 = (short)((unkuint10)Var42 >> 0x40);

        sVar8 = auVar43._10_2_;

        sVar9 = auVar44._12_2_;

        sVar10 = auVar39._14_2_;

        sVar11 = (short)uVar29;

        sVar12 = (short)(uVar29 >> 0x10);

        sVar13 = (short)((uint6)uVar20 >> 0x20);

        sVar14 = (short)((ulonglong)uVar21 >> 0x30);

        sVar15 = (short)((unkuint10)Var22 >> 0x40);

        sVar16 = auVar26._10_2_;

        sVar17 = auVar27._12_2_;

        sVar18 = auVar25._14_2_;

        *pcVar62 = (0 < sVar3) * (sVar3 < 0x100) * (char)uVar45 - (0xff < sVar3);

        pcVar62[1] = (0 < sVar4) * (sVar4 < 0x100) * (char)(uVar45 >> 0x10) - (0xff < sVar4);

        pcVar62[2] = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar46 - (0xff < sVar5);

        pcVar62[3] = (0 < sVar6) * (sVar6 < 0x100) * cVar76 - (0xff < sVar6);

        pcVar62[4] = (0 < sVar7) * (sVar7 < 0x100) * (char)uVar47 - (0xff < sVar7);

        pcVar62[5] = (0 < sVar8) * (sVar8 < 0x100) * cVar77 - (0xff < sVar8);

        pcVar62[6] = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar48 - (0xff < sVar9);

        pcVar62[7] = (0 < sVar10) * (sVar10 < 0x100) * cVar78 - (0xff < sVar10);

        pcVar62[8] = (0 < sVar11) * (sVar11 < 0x100) * (char)uVar29 - (0xff < sVar11);

        pcVar62[9] = (0 < sVar12) * (sVar12 < 0x100) * (char)(uVar29 >> 0x10) - (0xff < sVar12);

        pcVar62[10] = (0 < sVar13) * (sVar13 < 0x100) * (char)uVar31 - (0xff < sVar13);

        pcVar62[0xb] = (0 < sVar14) * (sVar14 < 0x100) * cVar73 - (0xff < sVar14);

        pcVar62[0xc] = (0 < sVar15) * (sVar15 < 0x100) * (char)uVar33 - (0xff < sVar15);

        pcVar62[0xd] = (0 < sVar16) * (sVar16 < 0x100) * cVar74 - (0xff < sVar16);

        pcVar62[0xe] = (0 < sVar17) * (sVar17 < 0x100) * (char)uVar35 - (0xff < sVar17);

        pcVar62[0xf] = (0 < sVar18) * (sVar18 < 0x100) * cVar75 - (0xff < sVar18);

        pcVar62 = pcVar62 + 0x10;

      } while (iVar60 <= param_3);

    }

  }

  if ((int)uVar63 < param_3) {

    uVar61 = (ulonglong)(param_3 - uVar63);

    param_1 = param_1 + (int)uVar63;

    pfVar59 = (float *)(param_2 + (longlong)(int)uVar63 * 4);

    do {

      fVar2 = *pfVar59;

      pfVar59 = pfVar59 + 1;

      sVar3 = SUB42(fVar2 + fVar56,0);

      *param_1 = (0 < sVar3) * (sVar3 < 0x100) * SUB41(fVar2 + fVar56,0) - (0xff < sVar3);

      param_1 = param_1 + 1;

      uVar61 = uVar61 - 1;

    } while (uVar61 != 0);

  }

  return;

}





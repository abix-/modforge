// Address: 0x1401a4870
// Ghidra name: FUN_1401a4870
// ============ 0x1401a4870 FUN_1401a4870 (size=459) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1401a4870(ulonglong param_1,ulonglong param_2,ulonglong param_3,uint param_4)



{

  undefined4 *puVar1;

  byte *pbVar2;

  byte bVar3;

  short sVar4;

  ushort uVar5;

  short sVar6;

  ushort uVar7;

  short sVar8;

  short sVar9;

  ushort uVar10;

  short sVar11;

  short sVar12;

  ushort uVar13;

  short sVar14;

  char cVar15;

  char cVar20;

  char cVar21;

  char cVar22;

  char cVar23;

  int iVar24;

  int iVar25;

  int iVar26;

  int iVar27;

  undefined1 auVar28 [16];

  uint uVar29;

  uint uVar30;

  uint uVar31;

  uint uVar32;

  byte *pbVar33;

  int iVar34;

  int iVar35;

  int iVar36;

  longlong lVar37;

  undefined4 *puVar38;

  longlong lVar39;

  undefined1 in_XMM1 [16];

  undefined1 auVar40 [16];

  short sVar41;

  uint uVar42;

  undefined1 auVar47 [12];

  undefined1 auVar49 [12];

  uint uVar60;

  undefined1 in_XMM2 [16];

  undefined1 auVar54 [16];

  uint uVar61;

  uint uVar62;

  undefined1 auVar55 [16];

  undefined1 auVar57 [16];

  undefined1 auVar48 [12];

  undefined1 auVar59 [16];

  char cVar16;

  char cVar17;

  char cVar18;

  char cVar19;

  undefined4 uVar43;

  undefined6 uVar44;

  undefined8 uVar45;

  undefined1 auVar46 [12];

  undefined1 auVar50 [14];

  undefined1 auVar51 [14];

  undefined1 auVar52 [14];

  undefined1 auVar53 [14];

  undefined1 auVar56 [16];

  undefined1 auVar58 [16];

  

  uVar32 = _UNK_14031028c;

  uVar31 = _UNK_140310288;

  uVar30 = _UNK_140310284;

  uVar29 = _DAT_140310280;

  auVar28 = _DAT_140310250;

  iVar27 = _UNK_14031024c;

  iVar26 = _UNK_140310248;

  iVar25 = _UNK_140310244;

  iVar24 = _DAT_140310240;

  iVar35 = 0;

  iVar34 = 0;

  iVar36 = iVar35;

  if (((0 < (int)param_4) && (iVar36 = iVar34, 0xf < param_4)) && (1 < DAT_1403e8ad0)) {

    lVar37 = (longlong)(int)param_4 + -1;

    if (((lVar37 + param_3 < param_1) || (lVar37 + param_1 < param_3)) &&

       ((lVar37 + param_2 < param_1 || (lVar37 + param_1 < param_2)))) {

      lVar37 = param_2 - param_3;

      lVar39 = param_1 - param_3;

      puVar38 = (undefined4 *)(param_3 + 4);

      do {

        auVar40 = pmovzxbd(in_XMM1,puVar38[-1]);

        auVar54 = pmovzxbd(in_XMM2,*(undefined4 *)(lVar37 + -4 + (longlong)puVar38));

        auVar54 = pmulld(auVar54,auVar28);

        iVar35 = iVar35 + 0x10;

        uVar42 = (uint)(auVar54._0_4_ + auVar40._0_4_ + iVar24) >> 2 & uVar29;

        uVar60 = (uint)(auVar54._4_4_ + auVar40._4_4_ + iVar25) >> 2 & uVar30;

        uVar61 = (uint)(auVar54._8_4_ + auVar40._8_4_ + iVar26) >> 2 & uVar31;

        uVar62 = (uint)(auVar54._12_4_ + auVar40._12_4_ + iVar27) >> 2 & uVar32;

        sVar4 = (short)uVar42;

        cVar15 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        uVar5 = (ushort)(uVar42 >> 0x10);

        cVar20 = (char)(uVar42 >> 0x10);

        sVar41 = CONCAT11((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),cVar15);

        sVar6 = (short)uVar60;

        cVar16 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        uVar7 = (ushort)(uVar60 >> 0x10);

        cVar21 = (char)(uVar60 >> 0x10);

        uVar43 = CONCAT13((uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7),

                          CONCAT12(cVar16,sVar41));

        sVar8 = (short)uVar61;

        cVar17 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        uVar10 = (ushort)(uVar61 >> 0x10);

        cVar22 = (char)(uVar61 >> 0x10);

        uVar44 = CONCAT15((uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10),

                          CONCAT14(cVar17,uVar43));

        sVar9 = (short)uVar62;

        cVar18 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        uVar13 = (ushort)(uVar62 >> 0x10);

        cVar23 = (char)(uVar62 >> 0x10);

        uVar45 = CONCAT17((uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13),

                          CONCAT16(cVar18,uVar44));

        cVar19 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        auVar46._0_10_ =

             CONCAT19((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),

                      CONCAT18(cVar19,uVar45));

        cVar20 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        auVar46[10] = cVar20;

        auVar46[0xb] = (uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7);

        cVar21 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        auVar50[0xc] = cVar21;

        auVar50._0_12_ = auVar46;

        auVar50[0xd] = (uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10);

        cVar22 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        auVar54[0xe] = cVar22;

        auVar54._0_14_ = auVar50;

        auVar54[0xf] = (uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13);

        sVar4 = (short)((uint)uVar43 >> 0x10);

        sVar6 = (short)((uint6)uVar44 >> 0x20);

        sVar8 = (short)((ulonglong)uVar45 >> 0x30);

        auVar55._0_4_ =

             CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8),

                      CONCAT12((0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6),

                               CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4),

                                        (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41)))

                     );

        sVar9 = (short)((unkuint10)auVar46._0_10_ >> 0x40);

        auVar55[4] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        sVar11 = auVar46._10_2_;

        auVar55[5] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        sVar12 = auVar50._12_2_;

        auVar55[6] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        sVar14 = auVar54._14_2_;

        auVar55[7] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        auVar55[8] = (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41);

        auVar55[9] = (0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4);

        auVar55[10] = (0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6);

        auVar55[0xb] = (0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8);

        auVar55[0xc] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        auVar55[0xd] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        auVar55[0xe] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        auVar55[0xf] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        *(undefined4 *)(lVar39 + -4 + (longlong)puVar38) = auVar55._0_4_;

        auVar40 = pmovzxbd(auVar40,*puVar38);

        auVar54 = pmovzxbd(auVar55,*(undefined4 *)(lVar37 + (longlong)puVar38));

        puVar1 = puVar38 + 4;

        auVar54 = pmulld(auVar54,auVar28);

        uVar42 = (uint)(auVar54._0_4_ + auVar40._0_4_ + iVar24) >> 2 & uVar29;

        uVar60 = (uint)(auVar54._4_4_ + auVar40._4_4_ + iVar25) >> 2 & uVar30;

        uVar61 = (uint)(auVar54._8_4_ + auVar40._8_4_ + iVar26) >> 2 & uVar31;

        uVar62 = (uint)(auVar54._12_4_ + auVar40._12_4_ + iVar27) >> 2 & uVar32;

        sVar4 = (short)uVar42;

        cVar15 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        uVar5 = (ushort)(uVar42 >> 0x10);

        cVar20 = (char)(uVar42 >> 0x10);

        sVar41 = CONCAT11((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),cVar15);

        sVar6 = (short)uVar60;

        cVar16 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        uVar7 = (ushort)(uVar60 >> 0x10);

        cVar21 = (char)(uVar60 >> 0x10);

        uVar43 = CONCAT13((uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7),

                          CONCAT12(cVar16,sVar41));

        sVar8 = (short)uVar61;

        cVar17 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        uVar10 = (ushort)(uVar61 >> 0x10);

        cVar22 = (char)(uVar61 >> 0x10);

        uVar44 = CONCAT15((uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10),

                          CONCAT14(cVar17,uVar43));

        sVar9 = (short)uVar62;

        cVar18 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        uVar13 = (ushort)(uVar62 >> 0x10);

        cVar23 = (char)(uVar62 >> 0x10);

        uVar45 = CONCAT17((uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13),

                          CONCAT16(cVar18,uVar44));

        cVar19 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        auVar47._0_10_ =

             CONCAT19((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),

                      CONCAT18(cVar19,uVar45));

        cVar20 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        auVar47[10] = cVar20;

        auVar47[0xb] = (uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7);

        cVar21 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        auVar51[0xc] = cVar21;

        auVar51._0_12_ = auVar47;

        auVar51[0xd] = (uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10);

        cVar22 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        auVar56[0xe] = cVar22;

        auVar56._0_14_ = auVar51;

        auVar56[0xf] = (uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13);

        sVar4 = (short)((uint)uVar43 >> 0x10);

        sVar6 = (short)((uint6)uVar44 >> 0x20);

        sVar8 = (short)((ulonglong)uVar45 >> 0x30);

        auVar57._0_4_ =

             CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8),

                      CONCAT12((0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6),

                               CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4),

                                        (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41)))

                     );

        sVar9 = (short)((unkuint10)auVar47._0_10_ >> 0x40);

        auVar57[4] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        sVar11 = auVar47._10_2_;

        auVar57[5] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        sVar12 = auVar51._12_2_;

        auVar57[6] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        sVar14 = auVar56._14_2_;

        auVar57[7] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        auVar57[8] = (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41);

        auVar57[9] = (0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4);

        auVar57[10] = (0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6);

        auVar57[0xb] = (0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8);

        auVar57[0xc] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        auVar57[0xd] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        auVar57[0xe] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        auVar57[0xf] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        *(undefined4 *)(lVar39 + -0x10 + (longlong)puVar1) = auVar57._0_4_;

        auVar40 = pmovzxbd(auVar40,puVar38[1]);

        auVar54 = pmovzxbd(auVar57,*(undefined4 *)(lVar37 + -0xc + (longlong)puVar1));

        auVar54 = pmulld(auVar54,auVar28);

        uVar42 = (uint)(auVar54._0_4_ + auVar40._0_4_ + iVar24) >> 2 & uVar29;

        uVar60 = (uint)(auVar54._4_4_ + auVar40._4_4_ + iVar25) >> 2 & uVar30;

        uVar61 = (uint)(auVar54._8_4_ + auVar40._8_4_ + iVar26) >> 2 & uVar31;

        uVar62 = (uint)(auVar54._12_4_ + auVar40._12_4_ + iVar27) >> 2 & uVar32;

        sVar4 = (short)uVar42;

        cVar15 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        uVar5 = (ushort)(uVar42 >> 0x10);

        cVar20 = (char)(uVar42 >> 0x10);

        sVar41 = CONCAT11((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),cVar15);

        sVar6 = (short)uVar60;

        cVar16 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        uVar7 = (ushort)(uVar60 >> 0x10);

        cVar21 = (char)(uVar60 >> 0x10);

        uVar43 = CONCAT13((uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7),

                          CONCAT12(cVar16,sVar41));

        sVar8 = (short)uVar61;

        cVar17 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        uVar10 = (ushort)(uVar61 >> 0x10);

        cVar22 = (char)(uVar61 >> 0x10);

        uVar44 = CONCAT15((uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10),

                          CONCAT14(cVar17,uVar43));

        sVar9 = (short)uVar62;

        cVar18 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        uVar13 = (ushort)(uVar62 >> 0x10);

        cVar23 = (char)(uVar62 >> 0x10);

        uVar45 = CONCAT17((uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13),

                          CONCAT16(cVar18,uVar44));

        cVar19 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        auVar48._0_10_ =

             CONCAT19((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),

                      CONCAT18(cVar19,uVar45));

        cVar20 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        auVar48[10] = cVar20;

        auVar48[0xb] = (uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7);

        cVar21 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        auVar52[0xc] = cVar21;

        auVar52._0_12_ = auVar48;

        auVar52[0xd] = (uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10);

        cVar22 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        auVar58[0xe] = cVar22;

        auVar58._0_14_ = auVar52;

        auVar58[0xf] = (uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13);

        sVar4 = (short)((uint)uVar43 >> 0x10);

        sVar6 = (short)((uint6)uVar44 >> 0x20);

        sVar8 = (short)((ulonglong)uVar45 >> 0x30);

        auVar59._0_4_ =

             CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8),

                      CONCAT12((0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6),

                               CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4),

                                        (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41)))

                     );

        sVar9 = (short)((unkuint10)auVar48._0_10_ >> 0x40);

        auVar59[4] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        sVar11 = auVar48._10_2_;

        auVar59[5] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        sVar12 = auVar52._12_2_;

        auVar59[6] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        sVar14 = auVar58._14_2_;

        auVar59[7] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        auVar59[8] = (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41);

        auVar59[9] = (0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4);

        auVar59[10] = (0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6);

        auVar59[0xb] = (0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8);

        auVar59[0xc] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        auVar59[0xd] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        auVar59[0xe] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        auVar59[0xf] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        *(undefined4 *)(lVar39 + -0xc + (longlong)puVar1) = auVar59._0_4_;

        auVar54 = pmovzxbd(auVar59,*(undefined4 *)(lVar37 + -8 + (longlong)puVar1));

        in_XMM1 = pmovzxbd(auVar40,puVar38[2]);

        auVar40 = pmulld(auVar54,auVar28);

        uVar42 = (uint)(auVar40._0_4_ + in_XMM1._0_4_ + iVar24) >> 2 & uVar29;

        uVar60 = (uint)(auVar40._4_4_ + in_XMM1._4_4_ + iVar25) >> 2 & uVar30;

        uVar61 = (uint)(auVar40._8_4_ + in_XMM1._8_4_ + iVar26) >> 2 & uVar31;

        uVar62 = (uint)(auVar40._12_4_ + in_XMM1._12_4_ + iVar27) >> 2 & uVar32;

        sVar4 = (short)uVar42;

        cVar15 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        uVar5 = (ushort)(uVar42 >> 0x10);

        cVar20 = (char)(uVar42 >> 0x10);

        sVar41 = CONCAT11((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),cVar15);

        sVar6 = (short)uVar60;

        cVar16 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        uVar7 = (ushort)(uVar60 >> 0x10);

        cVar21 = (char)(uVar60 >> 0x10);

        uVar43 = CONCAT13((uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7),

                          CONCAT12(cVar16,sVar41));

        sVar8 = (short)uVar61;

        cVar17 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        uVar10 = (ushort)(uVar61 >> 0x10);

        cVar22 = (char)(uVar61 >> 0x10);

        uVar44 = CONCAT15((uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10),

                          CONCAT14(cVar17,uVar43));

        sVar9 = (short)uVar62;

        cVar18 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        uVar13 = (ushort)(uVar62 >> 0x10);

        cVar23 = (char)(uVar62 >> 0x10);

        uVar45 = CONCAT17((uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13),

                          CONCAT16(cVar18,uVar44));

        cVar19 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar42 - (0xff < sVar4);

        auVar49._0_10_ =

             CONCAT19((uVar5 != 0) * (uVar5 < 0x100) * cVar20 - (0xff < uVar5),

                      CONCAT18(cVar19,uVar45));

        cVar20 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar60 - (0xff < sVar6);

        auVar49[10] = cVar20;

        auVar49[0xb] = (uVar7 != 0) * (uVar7 < 0x100) * cVar21 - (0xff < uVar7);

        cVar21 = (0 < sVar8) * (sVar8 < 0x100) * (char)uVar61 - (0xff < sVar8);

        auVar53[0xc] = cVar21;

        auVar53._0_12_ = auVar49;

        auVar53[0xd] = (uVar10 != 0) * (uVar10 < 0x100) * cVar22 - (0xff < uVar10);

        cVar22 = (0 < sVar9) * (sVar9 < 0x100) * (char)uVar62 - (0xff < sVar9);

        auVar40[0xe] = cVar22;

        auVar40._0_14_ = auVar53;

        auVar40[0xf] = (uVar13 != 0) * (uVar13 < 0x100) * cVar23 - (0xff < uVar13);

        sVar4 = (short)((uint)uVar43 >> 0x10);

        sVar6 = (short)((uint6)uVar44 >> 0x20);

        sVar8 = (short)((ulonglong)uVar45 >> 0x30);

        in_XMM2._0_4_ =

             CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8),

                      CONCAT12((0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6),

                               CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4),

                                        (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41)))

                     );

        sVar9 = (short)((unkuint10)auVar49._0_10_ >> 0x40);

        in_XMM2[4] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        sVar11 = auVar49._10_2_;

        in_XMM2[5] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        sVar12 = auVar53._12_2_;

        in_XMM2[6] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        sVar14 = auVar40._14_2_;

        in_XMM2[7] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        in_XMM2[8] = (0 < sVar41) * (sVar41 < 0x100) * cVar15 - (0xff < sVar41);

        in_XMM2[9] = (0 < sVar4) * (sVar4 < 0x100) * cVar16 - (0xff < sVar4);

        in_XMM2[10] = (0 < sVar6) * (sVar6 < 0x100) * cVar17 - (0xff < sVar6);

        in_XMM2[0xb] = (0 < sVar8) * (sVar8 < 0x100) * cVar18 - (0xff < sVar8);

        in_XMM2[0xc] = (0 < sVar9) * (sVar9 < 0x100) * cVar19 - (0xff < sVar9);

        in_XMM2[0xd] = (0 < sVar11) * (sVar11 < 0x100) * cVar20 - (0xff < sVar11);

        in_XMM2[0xe] = (0 < sVar12) * (sVar12 < 0x100) * cVar21 - (0xff < sVar12);

        in_XMM2[0xf] = (0 < sVar14) * (sVar14 < 0x100) * cVar22 - (0xff < sVar14);

        *(undefined4 *)(lVar39 + -8 + (longlong)puVar1) = in_XMM2._0_4_;

        puVar38 = puVar1;

        iVar36 = iVar35;

      } while ((longlong)((-4 - param_3) + (longlong)puVar1) <

               (longlong)((longlong)(int)param_4 & 0xfffffffffffffff0U));

    }

  }

  lVar37 = (longlong)iVar36;

  if (lVar37 < (int)param_4) {

    pbVar33 = (byte *)(lVar37 + param_3);

    lVar37 = (int)param_4 - lVar37;

    do {

      pbVar2 = pbVar33 + (param_2 - param_3);

      bVar3 = *pbVar33;

      pbVar33 = pbVar33 + 1;

      pbVar33[(param_1 - param_3) + -1] = (byte)(bVar3 + 2 + (uint)*pbVar2 + (uint)*pbVar2 * 2 >> 2)

      ;

      lVar37 = lVar37 + -1;

    } while (lVar37 != 0);

  }

  return param_1;

}





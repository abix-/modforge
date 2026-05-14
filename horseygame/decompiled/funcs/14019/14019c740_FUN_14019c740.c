// Address: 0x14019c740
// Ghidra name: FUN_14019c740
// ============ 0x14019c740 FUN_14019c740 (size=647) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14019c740(undefined1 (*param_1) [16],longlong param_2,longlong param_3,longlong param_4,

                  int param_5,int param_6)



{

  int iVar1;

  short sVar2;

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

  short sVar19;

  short sVar20;

  short sVar21;

  short sVar22;

  short sVar23;

  short sVar24;

  char cVar25;

  undefined1 auVar26 [14];

  unkbyte10 Var27;

  undefined1 auVar28 [14];

  undefined1 auVar29 [12];

  unkbyte9 Var30;

  undefined1 auVar31 [14];

  undefined1 auVar32 [12];

  undefined1 auVar33 [14];

  undefined1 auVar34 [12];

  undefined6 uVar35;

  undefined4 uVar36;

  undefined2 uVar37;

  short sVar38;

  short sVar39;

  short sVar40;

  short sVar41;

  short sVar42;

  short sVar43;

  short sVar44;

  short sVar45;

  undefined1 auVar46 [16];

  undefined1 auVar47 [16];

  undefined1 auVar48 [16];

  undefined1 auVar49 [16];

  undefined1 auVar50 [16];

  longlong lVar51;

  uint uVar52;

  byte *pbVar53;

  int iVar54;

  int iVar55;

  undefined1 *puVar56;

  bool bVar57;

  uint uVar58;

  uint uVar62;

  undefined1 auVar59 [16];

  undefined1 auVar60 [16];

  undefined1 auVar61 [16];

  ushort uVar63;

  ushort uVar73;

  ushort uVar74;

  ushort uVar75;

  ushort uVar76;

  ushort uVar77;

  ushort uVar78;

  undefined1 auVar64 [16];

  ushort uVar79;

  undefined1 auVar72 [16];

  undefined1 auVar80 [16];

  undefined1 auVar86 [16];

  undefined2 uVar87;

  undefined1 auVar93 [16];

  undefined1 auVar94 [16];

  undefined1 auVar95 [16];

  undefined1 auVar97 [16];

  undefined1 auVar103 [16];

  undefined1 auVar104 [16];

  undefined1 auVar65 [16];

  undefined1 auVar66 [16];

  undefined1 auVar67 [16];

  undefined1 auVar68 [16];

  undefined1 auVar69 [16];

  undefined1 auVar70 [16];

  undefined1 auVar71 [16];

  undefined1 auVar81 [16];

  undefined1 auVar82 [16];

  undefined1 auVar83 [16];

  undefined1 auVar84 [16];

  undefined1 auVar85 [16];

  undefined4 uVar88;

  undefined6 uVar89;

  undefined8 uVar90;

  undefined1 auVar91 [12];

  undefined1 auVar92 [14];

  undefined1 auVar96 [16];

  undefined1 auVar98 [16];

  undefined1 auVar99 [16];

  undefined1 auVar100 [16];

  undefined1 auVar101 [16];

  undefined1 auVar102 [16];

  

  auVar50 = _DAT_14033c3a0;

  auVar49 = _DAT_14033c380;

  auVar48 = _DAT_14033c340;

  auVar47 = _DAT_14033c330;

  auVar46 = _DAT_14033c320;

  sVar45 = _UNK_14033c2be;

  sVar44 = _UNK_14033c2bc;

  sVar43 = _UNK_14033c2ba;

  sVar42 = _UNK_14033c2b8;

  sVar41 = _UNK_14033c2b6;

  sVar40 = _UNK_14033c2b4;

  sVar39 = _UNK_14033c2b2;

  sVar38 = _DAT_14033c2b0;

  iVar55 = 0;

  if ((param_6 == 4) && (iVar54 = iVar55, 7 < param_5)) {

    do {

      lVar51 = (longlong)iVar54;

      iVar55 = iVar54 + 8;

      uVar52 = auVar48._0_4_;

      uVar58 = (uint)*(undefined8 *)(lVar51 + param_4) ^ uVar52;

      uVar62 = (uint)((ulonglong)*(undefined8 *)(lVar51 + param_4) >> 0x20) ^ auVar48._4_4_;

      auVar85._0_14_ = ZEXT814(0);

      auVar85[0xe] = 0;

      auVar85[0xf] = (char)(uVar62 >> 0x18);

      auVar84._14_2_ = auVar85._14_2_;

      auVar84._0_13_ = auVar85._0_13_;

      auVar84[0xd] = (char)(uVar62 >> 0x10);

      auVar83._13_3_ = auVar84._13_3_;

      auVar83._0_12_ = auVar85._0_12_;

      auVar83[0xc] = 0;

      auVar82._12_4_ = auVar83._12_4_;

      auVar82._0_11_ = auVar85._0_11_;

      auVar82[0xb] = (char)(uVar62 >> 8);

      auVar81._11_5_ = auVar82._11_5_;

      auVar81._0_10_ = auVar85._0_10_;

      auVar81[10] = 0;

      auVar80._10_6_ = auVar81._10_6_;

      auVar80._0_9_ = auVar85._0_9_;

      auVar80[9] = (char)uVar62;

      auVar32._1_10_ =

           (unkuint10)CONCAT81((ulonglong)auVar80._9_7_ << 8,(char)(uVar58 >> 0x18)) << 8;

      auVar32[0] = (char)(uVar58 >> 0x10);

      auVar32[0xb] = 0;

      auVar31._1_12_ = auVar32 << 8;

      auVar31[0] = (char)(uVar58 >> 8);

      auVar31[0xd] = 0;

      auVar60._1_14_ = auVar31 << 8;

      auVar60[0] = (char)uVar58;

      auVar60[0xf] = 0;

      uVar58 = (uint)*(undefined8 *)(lVar51 + param_3) ^ uVar52;

      uVar62 = (uint)((ulonglong)*(undefined8 *)(lVar51 + param_3) >> 0x20) ^ auVar48._4_4_;

      auVar93 = pmulhw(auVar60 << 8,auVar46);

      auVar102._0_14_ = ZEXT814(0);

      auVar102[0xe] = 0;

      auVar102[0xf] = (char)(uVar62 >> 0x18);

      auVar101._14_2_ = auVar102._14_2_;

      auVar101._0_13_ = auVar102._0_13_;

      auVar101[0xd] = (char)(uVar62 >> 0x10);

      auVar100._13_3_ = auVar101._13_3_;

      auVar100._0_12_ = auVar102._0_12_;

      auVar100[0xc] = 0;

      auVar99._12_4_ = auVar100._12_4_;

      auVar99._0_11_ = auVar102._0_11_;

      auVar99[0xb] = (char)(uVar62 >> 8);

      auVar98._11_5_ = auVar99._11_5_;

      auVar98._0_10_ = auVar102._0_10_;

      auVar98[10] = 0;

      auVar97._10_6_ = auVar98._10_6_;

      auVar97._0_9_ = auVar102._0_9_;

      auVar97[9] = (char)uVar62;

      auVar34._1_10_ =

           (unkuint10)CONCAT81((ulonglong)auVar97._9_7_ << 8,(char)(uVar58 >> 0x18)) << 8;

      auVar34[0] = (char)(uVar58 >> 0x10);

      auVar34[0xb] = 0;

      auVar33._1_12_ = auVar34 << 8;

      auVar33[0] = (char)(uVar58 >> 8);

      auVar33[0xd] = 0;

      auVar86._1_14_ = auVar33 << 8;

      auVar86[0] = (char)uVar58;

      auVar86[0xf] = 0;

      uVar90 = *(undefined8 *)(lVar51 + param_2);

      iVar1 = iVar54 + 0xf;

      auVar71._0_14_ = auVar48._0_14_;

      auVar71[0xe] = auVar48[7];

      auVar71[0xf] = (char)((ulonglong)uVar90 >> 0x38);

      auVar70._14_2_ = auVar71._14_2_;

      auVar70._0_13_ = auVar48._0_13_;

      auVar70[0xd] = (char)((ulonglong)uVar90 >> 0x30);

      auVar69._13_3_ = auVar70._13_3_;

      auVar69._0_12_ = auVar48._0_12_;

      auVar69[0xc] = auVar48[6];

      auVar68._12_4_ = auVar69._12_4_;

      auVar68._0_11_ = auVar48._0_11_;

      auVar68[0xb] = (char)((ulonglong)uVar90 >> 0x28);

      auVar67._11_5_ = auVar68._11_5_;

      auVar67._0_10_ = auVar48._0_10_;

      auVar67[10] = auVar48[5];

      auVar66._10_6_ = auVar67._10_6_;

      auVar66._0_9_ = auVar48._0_9_;

      auVar66[9] = (char)((ulonglong)uVar90 >> 0x20);

      auVar65._9_7_ = auVar66._9_7_;

      auVar65._0_8_ = auVar48._0_8_;

      auVar65[8] = auVar48[4];

      Var27 = CONCAT91(CONCAT81(auVar65._8_8_,(char)((ulonglong)uVar90 >> 0x18)),auVar48[3]);

      auVar64._6_10_ = Var27;

      auVar64[5] = (char)((ulonglong)uVar90 >> 0x10);

      auVar64[4] = auVar48[2];

      auVar64._0_4_ = uVar52;

      auVar26._2_12_ = auVar64._4_12_;

      auVar26[1] = (char)((ulonglong)uVar90 >> 8);

      auVar26[0] = auVar48[1];

      uVar63 = CONCAT11((char)uVar90,auVar48[0]) >> 4;

      uVar73 = auVar26._0_2_ >> 4;

      uVar74 = auVar64._4_2_ >> 4;

      uVar75 = (ushort)Var27 >> 4;

      uVar76 = auVar65._8_2_ >> 4;

      uVar77 = auVar67._10_2_ >> 4;

      uVar78 = auVar69._12_2_ >> 4;

      uVar79 = auVar70._14_2_ >> 4;

      auVar94._0_2_ = auVar93._0_2_ + uVar63;

      auVar94._2_2_ = auVar93._2_2_ + uVar73;

      auVar94._4_2_ = auVar93._4_2_ + uVar74;

      auVar94._6_2_ = auVar93._6_2_ + uVar75;

      auVar94._8_2_ = auVar93._8_2_ + uVar76;

      auVar94._10_2_ = auVar93._10_2_ + uVar77;

      auVar94._12_2_ = auVar93._12_2_ + uVar78;

      auVar94._14_2_ = auVar93._14_2_ + uVar79;

      auVar93 = pmulhw(auVar86 << 8,auVar47);

      auVar103 = pmulhw(auVar86 << 8,auVar50);

      auVar95 = psraw(auVar94,4);

      auVar86 = pmulhw(auVar60 << 8,auVar49);

      auVar59._0_2_ = auVar93._0_2_ + uVar63;

      auVar59._2_2_ = auVar93._2_2_ + uVar73;

      auVar59._4_2_ = auVar93._4_2_ + uVar74;

      auVar59._6_2_ = auVar93._6_2_ + uVar75;

      auVar59._8_2_ = auVar93._8_2_ + uVar76;

      auVar59._10_2_ = auVar93._10_2_ + uVar77;

      auVar59._12_2_ = auVar93._12_2_ + uVar78;

      auVar59._14_2_ = auVar93._14_2_ + uVar79;

      auVar60 = psraw(auVar59,4);

      sVar2 = auVar95._0_2_;

      sVar4 = auVar95._2_2_;

      sVar6 = auVar95._4_2_;

      sVar8 = auVar95._6_2_;

      sVar10 = auVar95._8_2_;

      sVar12 = auVar95._10_2_;

      sVar14 = auVar95._12_2_;

      sVar3 = auVar95._14_2_;

      cVar25 = (0 < sVar3) * (sVar3 < 0x100) * auVar95[0xe] - (0xff < sVar3);

      sVar17 = auVar60._0_2_;

      sVar18 = auVar60._2_2_;

      sVar19 = auVar60._4_2_;

      sVar20 = auVar60._6_2_;

      sVar21 = auVar60._8_2_;

      sVar22 = auVar60._10_2_;

      sVar23 = auVar60._12_2_;

      sVar24 = auVar60._14_2_;

      auVar104._0_2_ = auVar103._0_2_ + uVar63 + auVar86._0_2_;

      auVar104._2_2_ = auVar103._2_2_ + uVar73 + auVar86._2_2_;

      auVar104._4_2_ = auVar103._4_2_ + uVar74 + auVar86._4_2_;

      auVar104._6_2_ = auVar103._6_2_ + uVar75 + auVar86._6_2_;

      auVar104._8_2_ = auVar103._8_2_ + uVar76 + auVar86._8_2_;

      auVar104._10_2_ = auVar103._10_2_ + uVar77 + auVar86._10_2_;

      auVar104._12_2_ = auVar103._12_2_ + uVar78 + auVar86._12_2_;

      auVar104._14_2_ = auVar103._14_2_ + uVar79 + auVar86._14_2_;

      auVar86 = psraw(auVar104,4);

      sVar3 = auVar86._0_2_;

      sVar5 = auVar86._2_2_;

      sVar7 = auVar86._4_2_;

      sVar9 = auVar86._6_2_;

      sVar11 = auVar86._8_2_;

      sVar13 = auVar86._10_2_;

      sVar15 = auVar86._12_2_;

      sVar16 = auVar86._14_2_;

      uVar37 = CONCAT11((0 < sVar16) * (sVar16 < 0x100) * auVar86[0xe] - (0xff < sVar16),cVar25);

      uVar36 = CONCAT31(CONCAT21(uVar37,(0 < sVar15) * (sVar15 < 0x100) * auVar86[0xc] -

                                        (0xff < sVar15)),

                        (0 < sVar14) * (sVar14 < 0x100) * auVar95[0xc] - (0xff < sVar14));

      uVar35 = CONCAT51(CONCAT41(uVar36,(0 < sVar13) * (sVar13 < 0x100) * auVar86[10] -

                                        (0xff < sVar13)),

                        (0 < sVar12) * (sVar12 < 0x100) * auVar95[10] - (0xff < sVar12));

      Var30 = CONCAT72(CONCAT61(uVar35,(0 < sVar11) * (sVar11 < 0x100) * auVar86[8] -

                                       (0xff < sVar11)),

                       CONCAT11((0 < sVar10) * (sVar10 < 0x100) * auVar95[8] - (0xff < sVar10),

                                cVar25));

      Var27 = CONCAT91(CONCAT81((longlong)((unkuint9)Var30 >> 8),

                                (0 < sVar9) * (sVar9 < 0x100) * auVar86[6] - (0xff < sVar9)),

                       (0 < sVar8) * (sVar8 < 0x100) * auVar95[6] - (0xff < sVar8));

      auVar29._2_10_ = Var27;

      auVar29[1] = (0 < sVar7) * (sVar7 < 0x100) * auVar86[4] - (0xff < sVar7);

      auVar29[0] = (0 < sVar6) * (sVar6 < 0x100) * auVar95[4] - (0xff < sVar6);

      auVar28._2_12_ = auVar29;

      auVar28[1] = (0 < sVar5) * (sVar5 < 0x100) * auVar86[2] - (0xff < sVar5);

      auVar28[0] = (0 < sVar4) * (sVar4 < 0x100) * auVar95[2] - (0xff < sVar4);

      auVar72._0_2_ =

           CONCAT11((0 < sVar3) * (sVar3 < 0x100) * auVar86[0] - (0xff < sVar3),

                    (0 < sVar2) * (sVar2 < 0x100) * auVar95[0] - (0xff < sVar2));

      auVar72._2_14_ = auVar28;

      uVar87 = CONCAT11((0 < sVar38) * (sVar38 < 0x100) * (char)sVar38 - (0xff < sVar38),

                        (0 < sVar17) * (sVar17 < 0x100) * auVar60[0] - (0xff < sVar17));

      uVar88 = CONCAT13((0 < sVar39) * (sVar39 < 0x100) * (char)sVar39 - (0xff < sVar39),

                        CONCAT12((0 < sVar18) * (sVar18 < 0x100) * auVar60[2] - (0xff < sVar18),

                                 uVar87));

      uVar89 = CONCAT15((0 < sVar40) * (sVar40 < 0x100) * (char)sVar40 - (0xff < sVar40),

                        CONCAT14((0 < sVar19) * (sVar19 < 0x100) * auVar60[4] - (0xff < sVar19),

                                 uVar88));

      uVar90 = CONCAT17((0 < sVar41) * (sVar41 < 0x100) * (char)sVar41 - (0xff < sVar41),

                        CONCAT16((0 < sVar20) * (sVar20 < 0x100) * auVar60[6] - (0xff < sVar20),

                                 uVar89));

      auVar91._0_10_ =

           CONCAT19((0 < sVar42) * (sVar42 < 0x100) * (char)sVar42 - (0xff < sVar42),

                    CONCAT18((0 < sVar21) * (sVar21 < 0x100) * auVar60[8] - (0xff < sVar21),uVar90))

      ;

      auVar91[10] = (0 < sVar22) * (sVar22 < 0x100) * auVar60[10] - (0xff < sVar22);

      auVar91[0xb] = (0 < sVar43) * (sVar43 < 0x100) * (char)sVar43 - (0xff < sVar43);

      auVar92[0xc] = (0 < sVar23) * (sVar23 < 0x100) * auVar60[0xc] - (0xff < sVar23);

      auVar92._0_12_ = auVar91;

      auVar92[0xd] = (0 < sVar44) * (sVar44 < 0x100) * (char)sVar44 - (0xff < sVar44);

      auVar96[0xe] = (0 < sVar24) * (sVar24 < 0x100) * auVar60[0xe] - (0xff < sVar24);

      auVar96._0_14_ = auVar92;

      auVar96[0xf] = (0 < sVar45) * (sVar45 < 0x100) * (char)sVar45 - (0xff < sVar45);

      auVar61._0_12_ = auVar72._0_12_;

      auVar61._12_2_ = (short)Var27;

      auVar61._14_2_ = (short)((ulonglong)uVar90 >> 0x30);

      auVar103._12_4_ = auVar61._12_4_;

      auVar103._0_10_ = auVar72._0_10_;

      auVar103._10_2_ = (short)((uint6)uVar89 >> 0x20);

      auVar95._10_6_ = auVar103._10_6_;

      auVar95._0_8_ = auVar72._0_8_;

      auVar95._8_2_ = auVar29._0_2_;

      auVar93._8_8_ = auVar95._8_8_;

      auVar93._6_2_ = (short)((uint)uVar88 >> 0x10);

      auVar93._4_2_ = auVar28._0_2_;

      auVar93._2_2_ = uVar87;

      auVar93._0_2_ = auVar72._0_2_;

      *param_1 = auVar93;

      *(short *)param_1[1] = (short)((unkuint9)Var30 >> 8);

      *(short *)(param_1[1] + 2) = (short)((unkuint10)auVar91._0_10_ >> 0x40);

      *(short *)(param_1[1] + 4) = (short)uVar35;

      *(short *)(param_1[1] + 6) = auVar91._10_2_;

      *(short *)(param_1[1] + 8) = (short)uVar36;

      *(short *)(param_1[1] + 10) = auVar92._12_2_;

      *(undefined2 *)(param_1[1] + 0xc) = uVar37;

      *(short *)(param_1[1] + 0xe) = auVar96._14_2_;

      param_1 = param_1 + 2;

      iVar54 = iVar55;

    } while (iVar1 < param_5);

  }

  lVar51 = (longlong)iVar55;

  if (lVar51 < param_5) {

    puVar56 = *param_1 + 2;

    pbVar53 = (byte *)(lVar51 + param_4);

    lVar51 = param_5 - lVar51;

    do {

      iVar55 = (uint)pbVar53[param_2 - param_4] * 0x100000 + 0x80000;

      uVar62 = (int)((*pbVar53 - 0x80) * 0x166f00 + iVar55) >> 0x14;

      uVar52 = (int)((0x80 - (uint)*pbVar53) * 0xb6d00 +

                    iVar55 + ((0x80 - (uint)pbVar53[param_3 - param_4]) * 0x58200 & 0xffff0000)) >>

               0x14;

      uVar58 = (int)((pbVar53[param_3 - param_4] - 0x80) * 0x1c5a00 + iVar55) >> 0x14;

      if ((0xff < uVar62) && (bVar57 = (int)uVar62 < 0, uVar62 = 0xff, bVar57)) {

        uVar62 = 0;

      }

      if ((0xff < uVar52) && (bVar57 = (int)uVar52 < 0, uVar52 = 0xff, bVar57)) {

        uVar52 = 0;

      }

      if ((0xff < uVar58) && (bVar57 = (int)uVar58 < 0, uVar58 = 0xff, bVar57)) {

        uVar58 = 0;

      }

      puVar56[-2] = (char)uVar62;

      pbVar53 = pbVar53 + 1;

      puVar56[-1] = (char)uVar52;

      *puVar56 = (char)uVar58;

      puVar56[1] = 0xff;

      puVar56 = puVar56 + param_6;

      lVar51 = lVar51 + -1;

    } while (lVar51 != 0);

  }

  return;

}





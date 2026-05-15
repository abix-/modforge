// Address: 0x1401a4670
// Ghidra name: FUN_1401a4670
// ============ 0x1401a4670 FUN_1401a4670 (size=511) ============


/* WARNING: Removing unreachable block (ram,0x0001401a4742) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



char * FUN_1401a4670(char *param_1,byte *param_2,ulonglong *param_3,int param_4)



{

  byte *pbVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  byte bVar4;

  ulonglong *puVar5;

  undefined1 auVar6 [15];

  undefined1 auVar7 [15];

  undefined1 auVar8 [15];

  undefined1 auVar9 [15];

  undefined1 auVar10 [15];

  undefined1 auVar11 [15];

  undefined1 auVar12 [15];

  undefined1 auVar13 [15];

  undefined1 auVar14 [15];

  undefined1 auVar15 [15];

  undefined1 auVar16 [15];

  undefined1 auVar17 [15];

  undefined1 auVar18 [15];

  undefined1 auVar19 [15];

  unkuint9 Var20;

  undefined1 auVar21 [11];

  undefined1 auVar22 [13];

  undefined1 auVar23 [15];

  unkuint9 Var24;

  undefined1 auVar25 [11];

  undefined1 auVar26 [15];

  undefined1 auVar27 [15];

  undefined1 auVar28 [15];

  undefined1 auVar29 [15];

  short sVar30;

  short sVar31;

  short sVar32;

  short sVar33;

  short sVar34;

  short sVar35;

  short sVar36;

  short sVar37;

  char cVar38;

  uint uVar39;

  int iVar40;

  longlong lVar41;

  longlong lVar42;

  ulonglong *puVar43;

  int iVar44;

  int iVar45;

  byte *pbVar46;

  char *pcVar47;

  ulonglong *puVar48;

  longlong lVar49;

  ulonglong uVar50;

  short sVar51;

  ushort uVar52;

  short sVar55;

  ushort uVar56;

  short sVar57;

  ushort uVar58;

  short sVar59;

  ushort uVar60;

  short sVar61;

  ushort uVar62;

  short sVar63;

  ushort uVar64;

  short sVar65;

  ushort uVar66;

  undefined1 auVar53 [16];

  undefined1 auVar54 [16];

  short sVar67;

  ushort uVar68;

  ushort uVar69;

  ushort uVar70;

  ushort uVar71;

  ushort uVar72;

  ushort uVar73;

  ushort uVar74;

  ushort uVar75;

  ushort uVar76;

  undefined1 auVar77 [16];

  

  sVar37 = _UNK_14033c2ae;

  sVar36 = _UNK_14033c2ac;

  sVar35 = _UNK_14033c2aa;

  sVar34 = _UNK_14033c2a8;

  sVar33 = _UNK_14033c2a6;

  sVar32 = _UNK_14033c2a4;

  sVar31 = _UNK_14033c2a2;

  sVar30 = _DAT_14033c2a0;

  iVar45 = 0;

  iVar44 = (uint)*param_2 + (uint)*param_2 * 2 + (uint)(byte)*param_3;

  if (param_4 == 1) {

    cVar38 = (char)(iVar44 + 2U >> 2);

    param_1[1] = cVar38;

    *param_1 = cVar38;

    return param_1;

  }

  uVar39 = param_4 - 1U & 0xfffffff8;

  lVar42 = (longlong)param_2 - (longlong)param_3;

  if (0 < (int)uVar39) {

    uVar39 = (uVar39 - 1 >> 3) + 1;

    uVar50 = (ulonglong)uVar39;

    iVar45 = uVar39 * 8;

    puVar43 = param_3;

    pcVar47 = param_1;

    puVar5 = param_3;

    do {

      puVar48 = puVar5 + 1;

      uVar2 = *(ulonglong *)(lVar42 + (longlong)puVar43);

      uVar3 = *puVar43;

      puVar43 = puVar43 + 1;

      auVar7._8_6_ = 0;

      auVar7._0_8_ = uVar2;

      auVar7[0xe] = (char)(uVar2 >> 0x38);

      auVar9._8_4_ = 0;

      auVar9._0_8_ = uVar2;

      auVar9[0xc] = (char)(uVar2 >> 0x30);

      auVar9._13_2_ = auVar7._13_2_;

      auVar11._8_4_ = 0;

      auVar11._0_8_ = uVar2;

      auVar11._12_3_ = auVar9._12_3_;

      auVar13._8_2_ = 0;

      auVar13._0_8_ = uVar2;

      auVar13[10] = (char)(uVar2 >> 0x28);

      auVar13._11_4_ = auVar11._11_4_;

      auVar15._8_2_ = 0;

      auVar15._0_8_ = uVar2;

      auVar15._10_5_ = auVar13._10_5_;

      auVar17[8] = (char)(uVar2 >> 0x20);

      auVar17._0_8_ = uVar2;

      auVar17._9_6_ = auVar15._9_6_;

      auVar19._7_8_ = 0;

      auVar19._0_7_ = auVar17._8_7_;

      Var20 = CONCAT81(SUB158(auVar19 << 0x40,7),(char)(uVar2 >> 0x18));

      auVar26._9_6_ = 0;

      auVar26._0_9_ = Var20;

      auVar21._1_10_ = SUB1510(auVar26 << 0x30,5);

      auVar21[0] = (char)(uVar2 >> 0x10);

      auVar27._11_4_ = 0;

      auVar27._0_11_ = auVar21;

      auVar22._1_12_ = SUB1512(auVar27 << 0x20,3);

      auVar22[0] = (char)(uVar2 >> 8);

      auVar54._0_2_ = CONCAT11(0,(byte)uVar2);

      auVar54._2_13_ = auVar22;

      auVar54[0xf] = 0;

      auVar6._8_6_ = 0;

      auVar6._0_8_ = uVar3;

      auVar6[0xe] = (char)(uVar3 >> 0x38);

      auVar8._8_4_ = 0;

      auVar8._0_8_ = uVar3;

      auVar8[0xc] = (char)(uVar3 >> 0x30);

      auVar8._13_2_ = auVar6._13_2_;

      auVar10._8_4_ = 0;

      auVar10._0_8_ = uVar3;

      auVar10._12_3_ = auVar8._12_3_;

      auVar12._8_2_ = 0;

      auVar12._0_8_ = uVar3;

      auVar12[10] = (char)(uVar3 >> 0x28);

      auVar12._11_4_ = auVar10._11_4_;

      auVar14._8_2_ = 0;

      auVar14._0_8_ = uVar3;

      auVar14._10_5_ = auVar12._10_5_;

      auVar16[8] = (char)(uVar3 >> 0x20);

      auVar16._0_8_ = uVar3;

      auVar16._9_6_ = auVar14._9_6_;

      auVar23._7_8_ = 0;

      auVar23._0_7_ = auVar16._8_7_;

      Var24 = CONCAT81(SUB158(auVar23 << 0x40,7),(char)(uVar3 >> 0x18));

      auVar28._9_6_ = 0;

      auVar28._0_9_ = Var24;

      auVar25._1_10_ = SUB1510(auVar28 << 0x30,5);

      auVar25[0] = (char)(uVar3 >> 0x10);

      auVar29._11_4_ = 0;

      auVar29._0_11_ = auVar25;

      auVar18[2] = (char)(uVar3 >> 8);

      auVar18._0_2_ = (ushort)uVar3;

      auVar18._3_12_ = SUB1512(auVar29 << 0x20,3);

      auVar53 = psllw(auVar54,2);

      auVar77._0_2_ = (((ushort)uVar3 & 0xff) - auVar54._0_2_) + auVar53._0_2_;

      auVar77._2_2_ = (auVar18._2_2_ - auVar22._0_2_) + auVar53._2_2_;

      auVar77._4_2_ = (auVar25._0_2_ - auVar21._0_2_) + auVar53._4_2_;

      auVar77._6_2_ = ((short)Var24 - (short)Var20) + auVar53._6_2_;

      auVar77._8_2_ = (auVar16._8_2_ - auVar17._8_2_) + auVar53._8_2_;

      auVar77._10_2_ = (auVar12._10_2_ - auVar13._10_2_) + auVar53._10_2_;

      auVar77._12_2_ = (auVar8._12_2_ - auVar9._12_2_) + auVar53._12_2_;

      auVar77._14_2_ = ((auVar6._13_2_ >> 8) - (auVar7._13_2_ >> 8)) + auVar53._14_2_;

      auVar54 = psllw(auVar77,2);

      sVar51 = auVar54._0_2_ + sVar30;

      sVar55 = auVar54._2_2_ + sVar31;

      sVar57 = auVar54._4_2_ + sVar32;

      sVar59 = auVar54._6_2_ + sVar33;

      sVar61 = auVar54._8_2_ + sVar34;

      sVar63 = auVar54._10_2_ + sVar35;

      sVar65 = auVar54._12_2_ + sVar36;

      sVar67 = auVar54._14_2_ + sVar37;

      uVar52 = (ushort)(((short)iVar44 - auVar77._0_2_) + sVar51) >> 4;

      uVar56 = (ushort)((auVar77._2_2_ - auVar77._0_2_) + sVar51) >> 4;

      uVar58 = (ushort)((auVar77._0_2_ - auVar77._2_2_) + sVar55) >> 4;

      uVar60 = (ushort)((auVar77._4_2_ - auVar77._2_2_) + sVar55) >> 4;

      uVar62 = (ushort)((auVar77._2_2_ - auVar77._4_2_) + sVar57) >> 4;

      uVar64 = (ushort)((auVar77._6_2_ - auVar77._4_2_) + sVar57) >> 4;

      uVar66 = (ushort)((auVar77._4_2_ - auVar77._6_2_) + sVar59) >> 4;

      uVar68 = (ushort)((auVar77._8_2_ - auVar77._6_2_) + sVar59) >> 4;

      uVar69 = (ushort)((auVar77._6_2_ - auVar77._8_2_) + sVar61) >> 4;

      uVar70 = (ushort)((auVar77._10_2_ - auVar77._8_2_) + sVar61) >> 4;

      uVar71 = (ushort)((auVar77._8_2_ - auVar77._10_2_) + sVar63) >> 4;

      uVar72 = (ushort)((auVar77._12_2_ - auVar77._10_2_) + sVar63) >> 4;

      uVar73 = (ushort)((auVar77._10_2_ - auVar77._12_2_) + sVar65) >> 4;

      uVar74 = (ushort)((auVar77._14_2_ - auVar77._12_2_) + sVar65) >> 4;

      uVar75 = (ushort)((auVar77._12_2_ - auVar77._14_2_) + sVar67) >> 4;

      uVar76 = (ushort)((((ushort)*(byte *)((longlong)puVar48 + lVar42) +

                          (ushort)*(byte *)((longlong)puVar48 + lVar42) * 2 + (ushort)(byte)*puVar48

                         ) - auVar77._14_2_) + sVar67) >> 4;

      *pcVar47 = (uVar52 != 0) * (uVar52 < 0x100) * (char)uVar52 - (0xff < uVar52);

      pcVar47[1] = (uVar56 != 0) * (uVar56 < 0x100) * (char)uVar56 - (0xff < uVar56);

      pcVar47[2] = (uVar58 != 0) * (uVar58 < 0x100) * (char)uVar58 - (0xff < uVar58);

      pcVar47[3] = (uVar60 != 0) * (uVar60 < 0x100) * (char)uVar60 - (0xff < uVar60);

      pcVar47[4] = (uVar62 != 0) * (uVar62 < 0x100) * (char)uVar62 - (0xff < uVar62);

      pcVar47[5] = (uVar64 != 0) * (uVar64 < 0x100) * (char)uVar64 - (0xff < uVar64);

      pcVar47[6] = (uVar66 != 0) * (uVar66 < 0x100) * (char)uVar66 - (0xff < uVar66);

      pcVar47[7] = (uVar68 != 0) * (uVar68 < 0x100) * (char)uVar68 - (0xff < uVar68);

      pcVar47[8] = (uVar69 != 0) * (uVar69 < 0x100) * (char)uVar69 - (0xff < uVar69);

      pcVar47[9] = (uVar70 != 0) * (uVar70 < 0x100) * (char)uVar70 - (0xff < uVar70);

      pcVar47[10] = (uVar71 != 0) * (uVar71 < 0x100) * (char)uVar71 - (0xff < uVar71);

      pcVar47[0xb] = (uVar72 != 0) * (uVar72 < 0x100) * (char)uVar72 - (0xff < uVar72);

      pcVar47[0xc] = (uVar73 != 0) * (uVar73 < 0x100) * (char)uVar73 - (0xff < uVar73);

      pcVar47[0xd] = (uVar74 != 0) * (uVar74 < 0x100) * (char)uVar74 - (0xff < uVar74);

      pcVar47[0xe] = (uVar75 != 0) * (uVar75 < 0x100) * (char)uVar75 - (0xff < uVar75);

      pcVar47[0xf] = (uVar76 != 0) * (uVar76 < 0x100) * (char)uVar76 - (0xff < uVar76);

      bVar4 = *(byte *)((longlong)puVar5 + lVar42 + 7);

      iVar44 = (uint)bVar4 + (uint)bVar4 * 2 + (uint)*(byte *)((longlong)puVar5 + 7);

      uVar50 = uVar50 - 1;

      pcVar47 = pcVar47 + 0x10;

      puVar5 = puVar48;

    } while (uVar50 != 0);

  }

  iVar40 = (uint)param_2[iVar45] + (uint)param_2[iVar45] * 2 +

           (uint)*(byte *)((longlong)iVar45 + (longlong)param_3);

  param_1[iVar45 * 2] = (char)(iVar44 + iVar40 * 3 + 8U >> 4);

  lVar41 = (longlong)(iVar45 + 1);

  if (lVar41 < param_4) {

    pbVar46 = (byte *)(lVar41 + (longlong)param_3);

    lVar49 = param_4 - lVar41;

    pcVar47 = param_1 + lVar41 * 2;

    iVar45 = iVar40;

    do {

      bVar4 = *pbVar46;

      pbVar1 = pbVar46 + lVar42;

      pbVar46 = pbVar46 + 1;

      iVar40 = (uint)*pbVar1 + (uint)*pbVar1 * 2 + (uint)bVar4;

      pcVar47[-1] = (char)((uint)(iVar40 + (iVar45 + 4) * 2 + iVar45) >> 4);

      *pcVar47 = (char)((uint)(iVar45 + (iVar40 + 4) * 2 + iVar40) >> 4);

      lVar49 = lVar49 + -1;

      pcVar47 = pcVar47 + 2;

      iVar45 = iVar40;

    } while (lVar49 != 0);

  }

  param_1[(longlong)(param_4 * 2) + -1] = (char)(iVar40 + 2U >> 2);

  return param_1;

}





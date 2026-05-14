// Address: 0x140212430
// Ghidra name: FUN_140212430
// ============ 0x140212430 FUN_140212430 (size=298) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140212430(longlong param_1,longlong param_2,int param_3)



{

  byte *pbVar1;

  uint *puVar2;

  undefined1 auVar3 [15];

  undefined1 auVar4 [15];

  undefined1 auVar5 [15];

  undefined1 auVar6 [15];

  undefined1 auVar7 [15];

  undefined1 auVar8 [15];

  undefined1 auVar9 [15];

  undefined1 auVar10 [15];

  undefined1 auVar11 [15];

  unkuint9 Var12;

  undefined1 auVar13 [15];

  undefined1 auVar14 [13];

  undefined1 auVar15 [12];

  undefined1 auVar16 [15];

  undefined8 uVar17;

  uint uVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  undefined2 uVar22;

  undefined2 uVar23;

  undefined2 uVar24;

  undefined2 uVar25;

  undefined2 uVar26;

  undefined2 uVar27;

  undefined2 uVar28;

  undefined2 uVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float *pfVar34;

  ulonglong uVar35;

  longlong lVar36;

  undefined1 auVar37 [16];

  undefined1 auVar39 [16];

  ushort uVar43;

  float fVar44;

  undefined1 uVar47;

  uint uVar48;

  uint uVar54;

  unkint10 Var49;

  undefined1 auVar51 [12];

  undefined1 uVar55;

  undefined1 auVar42 [16];

  undefined1 auVar40 [16];

  undefined1 auVar41 [16];

  undefined1 auVar38 [16];

  undefined1 auVar45 [12];

  undefined1 auVar46 [16];

  undefined1 auVar50 [12];

  undefined1 auVar52 [16];

  undefined1 auVar53 [16];

  

  fVar33 = _UNK_1403539ac;

  fVar32 = _UNK_1403539a8;

  fVar31 = _UNK_1403539a4;

  fVar30 = _DAT_1403539a0;

  uVar29 = _UNK_14035394e;

  uVar28 = _UNK_14035394c;

  uVar27 = _UNK_14035394a;

  uVar26 = _UNK_140353948;

  uVar25 = _UNK_140353946;

  uVar24 = _UNK_140353944;

  uVar23 = _UNK_140353942;

  uVar22 = _DAT_140353940;

  uVar21 = _UNK_14033c34c;

  uVar20 = _UNK_14033c348;

  uVar19 = _UNK_14033c344;

  uVar18 = _DAT_14033c340;

  if (0xf < param_3) {

    pfVar34 = (float *)(param_1 + (longlong)param_3 * 4);

    if (((ulonglong)pfVar34 & 0xf) != 0) {

      lVar36 = param_2 + param_3;

      do {

        pbVar1 = (byte *)(lVar36 + -1);

        lVar36 = lVar36 + -1;

        param_3 = param_3 + -1;

        pfVar34 = pfVar34 + -1;

        *pfVar34 = (float)(*pbVar1 ^ 0x47800080) + fVar30;

      } while (((char)param_3 * '\x04' + (char)param_1 & 0xfU) != 0);

    }

    uVar35 = (ulonglong)param_3;

    if (0xf < (longlong)uVar35) {

      param_3 = param_3 + (int)(uVar35 >> 4) * -0x10;

      pfVar34 = (float *)(param_1 + 0x20 + uVar35 * 4);

      do {

        puVar2 = (uint *)(param_2 + -0x10 + uVar35);

        uVar35 = uVar35 - 0x10;

        uVar48 = *puVar2 ^ uVar18;

        uVar54 = puVar2[1] ^ uVar19;

        auVar50._0_8_ = CONCAT44(uVar54,uVar48);

        auVar50._8_4_ = puVar2[2] ^ uVar20;

        auVar52._12_4_ = puVar2[3] ^ uVar21;

        auVar52._0_12_ = auVar50;

        Var49 = (unkuint10)(byte)auVar52._12_4_ << 0x40;

        uVar55 = (undefined1)(auVar52._12_4_ >> 8);

        auVar42[10] = uVar55;

        auVar42._0_10_ = Var49;

        auVar42[0xb] = 0;

        uVar47 = (undefined1)(uVar54 >> 0x18);

        auVar3[0xd] = 0;

        auVar3._0_13_ = auVar52._0_13_;

        auVar3[0xe] = uVar47;

        auVar4[0xc] = (char)(uVar54 >> 0x10);

        auVar4._0_12_ = auVar50;

        auVar4._13_2_ = auVar3._13_2_;

        auVar5[0xb] = 0;

        auVar5._0_11_ = auVar50._0_11_;

        auVar5._12_3_ = auVar4._12_3_;

        auVar6[10] = (char)(uVar54 >> 8);

        auVar6._0_10_ = auVar50._0_10_;

        auVar6._11_4_ = auVar5._11_4_;

        auVar7[9] = 0;

        auVar7._0_9_ = auVar50._0_9_;

        auVar7._10_5_ = auVar6._10_5_;

        auVar8[8] = (char)uVar54;

        auVar8._0_8_ = auVar50._0_8_;

        auVar8._9_6_ = auVar7._9_6_;

        auVar11._7_8_ = 0;

        auVar11._0_7_ = auVar8._8_7_;

        Var12 = CONCAT81(SUB158(auVar11 << 0x40,7),(char)(uVar48 >> 0x18));

        auVar16._9_6_ = 0;

        auVar16._0_9_ = Var12;

        auVar9[4] = (char)(uVar48 >> 0x10);

        auVar9._0_4_ = uVar48;

        auVar9._5_10_ = SUB1510(auVar16 << 0x30,5);

        auVar13._11_4_ = 0;

        auVar13._0_11_ = auVar9._4_11_;

        auVar14._1_12_ = SUB1512(auVar13 << 0x20,3);

        auVar14[0] = (char)(uVar48 >> 8);

        uVar43 = CONCAT11(0,(byte)uVar48);

        auVar10._2_13_ = auVar14;

        auVar10._0_2_ = uVar43;

        fVar44 = (float)CONCAT22(uVar26,auVar8._8_2_);

        auVar45._0_8_ = CONCAT26(uVar27,CONCAT24(auVar6._10_2_,fVar44));

        auVar45._8_2_ = auVar4._12_2_;

        auVar45._10_2_ = uVar28;

        auVar46[0xc] = uVar47;

        auVar46._0_12_ = auVar45;

        auVar46[0xd] = 0;

        auVar46._14_2_ = uVar29;

        auVar38._0_12_ = auVar10._0_12_;

        auVar38._12_2_ = (short)Var12;

        auVar38._14_2_ = uVar25;

        auVar37._12_4_ = auVar38._12_4_;

        auVar37._0_10_ = auVar10._0_10_;

        auVar37._10_2_ = uVar24;

        uVar17 = CONCAT62(auVar37._10_6_,auVar9._4_2_);

        auVar15._4_8_ = uVar17;

        auVar15._2_2_ = uVar23;

        auVar15._0_2_ = auVar14._0_2_;

        pfVar34[-0x18] = (float)CONCAT22(uVar22,uVar43) + fVar30;

        pfVar34[-0x17] = auVar15._0_4_ + fVar31;

        pfVar34[-0x16] = (float)uVar17 + fVar32;

        pfVar34[-0x15] = auVar37._12_4_ + fVar33;

        pfVar34[-0x14] = fVar44 + fVar30;

        pfVar34[-0x13] = (float)((ulonglong)auVar45._0_8_ >> 0x20) + fVar31;

        pfVar34[-0x12] = auVar45._8_4_ + fVar32;

        pfVar34[-0x11] = auVar46._12_4_ + fVar33;

        auVar42[0xc] = (char)(auVar50._8_4_ >> 0x18);

        auVar42[0xd] = 0;

        auVar42._14_2_ = uVar25;

        auVar41._12_4_ = auVar42._12_4_;

        auVar41._10_2_ = uVar24;

        auVar41._0_10_ = Var49;

        auVar40._10_6_ = auVar41._10_6_;

        auVar40._0_10_ = (unkuint10)(byte)(auVar50._8_4_ >> 0x10) << 0x40;

        auVar39._8_8_ = auVar40._8_8_;

        auVar39._6_2_ = uVar23;

        auVar39._0_6_ = (uint6)(byte)(auVar50._8_4_ >> 8) << 0x20;

        fVar44 = (float)CONCAT22(uVar26,(ushort)(byte)auVar52._12_4_);

        auVar51._0_8_ = CONCAT26(uVar27,(uint6)CONCAT14(uVar55,fVar44));

        auVar51[8] = (char)(auVar52._12_4_ >> 0x10);

        auVar51[9] = 0;

        auVar51._10_2_ = uVar28;

        auVar53[0xc] = (char)(auVar52._12_4_ >> 0x18);

        auVar53._0_12_ = auVar51;

        auVar53[0xd] = 0;

        auVar53._14_2_ = uVar29;

        pfVar34[-0x10] = (float)CONCAT22(uVar22,(ushort)(byte)auVar50._8_4_) + fVar30;

        pfVar34[-0xf] = auVar39._4_4_ + fVar31;

        pfVar34[-0xe] = auVar40._8_4_ + fVar32;

        pfVar34[-0xd] = auVar41._12_4_ + fVar33;

        pfVar34[-0xc] = fVar44 + fVar30;

        pfVar34[-0xb] = (float)((ulonglong)auVar51._0_8_ >> 0x20) + fVar31;

        pfVar34[-10] = auVar51._8_4_ + fVar32;

        pfVar34[-9] = auVar53._12_4_ + fVar33;

        pfVar34 = pfVar34 + -0x10;

      } while (0xf < (longlong)uVar35);

    }

  }

  lVar36 = (longlong)param_3;

  if (0 < param_3) {

    do {

      pbVar1 = (byte *)(param_2 + -1 + lVar36);

      lVar36 = lVar36 + -1;

      *(float *)(param_1 + lVar36 * 4) = (float)(*pbVar1 ^ 0x47800080) + fVar30;

    } while (0 < lVar36);

  }

  return;

}





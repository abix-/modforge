// Address: 0x1401db690
// Ghidra name: FUN_1401db690
// ============ 0x1401db690 FUN_1401db690 (size=239) ============


undefined8

FUN_1401db690(int param_1,int param_2,undefined1 (*param_3) [16],int param_4,

             undefined1 (*param_5) [16],int param_6)



{

  undefined1 uVar1;

  undefined1 uVar2;

  undefined1 uVar3;

  short sVar4;

  short sVar5;

  undefined1 auVar6 [15];

  undefined1 auVar7 [15];

  undefined1 auVar8 [15];

  undefined1 auVar9 [15];

  undefined1 auVar10 [15];

  undefined1 auVar11 [15];

  undefined1 auVar12 [15];

  undefined1 auVar13 [15];

  undefined1 auVar14 [15];

  undefined1 *puVar15;

  uint uVar16;

  uint uVar17;

  ulonglong uVar19;

  uint uVar20;

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 in_XMM2 [16];

  undefined1 auVar23 [16];

  ulonglong uVar18;

  

  uVar16 = (param_1 + 1) / 2;

  uVar17 = param_6 + uVar16 * -4;

  uVar18 = (ulonglong)uVar17;

  if (param_2 != 0) {

    do {

      param_2 = param_2 + -1;

      uVar20 = uVar16;

      if (3 < (int)uVar16) {

        uVar20 = uVar16 >> 2;

        uVar19 = (ulonglong)uVar20;

        uVar18 = (ulonglong)(uVar20 * 4);

        uVar20 = uVar16 + uVar20 * -4;

        do {

          auVar21 = *param_3;

          param_3 = param_3 + 1;

          auVar22[1] = 0;

          auVar22[0] = auVar21[8];

          auVar22[2] = auVar21[9];

          auVar22[3] = 0;

          auVar22[4] = auVar21[10];

          auVar22[5] = 0;

          auVar22[6] = auVar21[0xb];

          auVar22[7] = 0;

          auVar22[8] = auVar21[0xc];

          auVar22[9] = 0;

          auVar22[10] = auVar21[0xd];

          auVar22[0xb] = 0;

          auVar22[0xc] = auVar21[0xe];

          auVar22[0xd] = 0;

          auVar22[0xe] = auVar21[0xf];

          auVar22[0xf] = 0;

          auVar6[0xd] = 0;

          auVar6._0_13_ = auVar21._0_13_;

          auVar6[0xe] = auVar21[7];

          auVar7[0xc] = auVar21[6];

          auVar7._0_12_ = auVar21._0_12_;

          auVar7._13_2_ = auVar6._13_2_;

          auVar8[0xb] = 0;

          auVar8._0_11_ = auVar21._0_11_;

          auVar8._12_3_ = auVar7._12_3_;

          auVar9[10] = auVar21[5];

          auVar9._0_10_ = auVar21._0_10_;

          auVar9._11_4_ = auVar8._11_4_;

          auVar10[9] = 0;

          auVar10._0_9_ = auVar21._0_9_;

          auVar10._10_5_ = auVar9._10_5_;

          auVar11[8] = auVar21[4];

          auVar11._0_8_ = auVar21._0_8_;

          auVar11._9_6_ = auVar10._9_6_;

          auVar12._7_8_ = 0;

          auVar12._0_7_ = auVar11._8_7_;

          auVar13._1_8_ = SUB158(auVar12 << 0x40,7);

          auVar13[0] = auVar21[3];

          auVar13._9_6_ = 0;

          auVar14._1_10_ = SUB1510(auVar13 << 0x30,5);

          auVar14[0] = auVar21[2];

          auVar14._11_4_ = 0;

          auVar23._3_12_ = SUB1512(auVar14 << 0x20,3);

          auVar23[2] = auVar21[1];

          auVar23[0] = auVar21[0];

          auVar23[1] = 0;

          auVar23[0xf] = 0;

          auVar21 = pshuflw(auVar23,auVar23,0x6c);

          auVar23 = pshufhw(in_XMM2,auVar21,0x6c);

          auVar21 = pshuflw(auVar21,auVar22,0x6c);

          auVar21 = pshufhw(auVar22,auVar21,0x6c);

          sVar4 = auVar23._0_2_;

          sVar5 = auVar23._2_2_;

          in_XMM2[1] = (0 < sVar5) * (sVar5 < 0x100) * auVar23[2] - (0xff < sVar5);

          in_XMM2[0] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[0] - (0xff < sVar4);

          sVar4 = auVar23._4_2_;

          in_XMM2[2] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[4] - (0xff < sVar4);

          sVar4 = auVar23._6_2_;

          in_XMM2[3] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[6] - (0xff < sVar4);

          sVar4 = auVar23._8_2_;

          in_XMM2[4] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[8] - (0xff < sVar4);

          sVar4 = auVar23._10_2_;

          in_XMM2[5] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[10] - (0xff < sVar4);

          sVar4 = auVar23._12_2_;

          in_XMM2[6] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[0xc] - (0xff < sVar4);

          sVar4 = auVar23._14_2_;

          in_XMM2[7] = (0 < sVar4) * (sVar4 < 0x100) * auVar23[0xe] - (0xff < sVar4);

          sVar4 = auVar21._0_2_;

          in_XMM2[8] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[0] - (0xff < sVar4);

          sVar4 = auVar21._2_2_;

          in_XMM2[9] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[2] - (0xff < sVar4);

          sVar4 = auVar21._4_2_;

          in_XMM2[10] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[4] - (0xff < sVar4);

          sVar4 = auVar21._6_2_;

          in_XMM2[0xb] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[6] - (0xff < sVar4);

          sVar4 = auVar21._8_2_;

          in_XMM2[0xc] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[8] - (0xff < sVar4);

          sVar4 = auVar21._10_2_;

          in_XMM2[0xd] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[10] - (0xff < sVar4);

          sVar4 = auVar21._12_2_;

          in_XMM2[0xe] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[0xc] - (0xff < sVar4);

          sVar4 = auVar21._14_2_;

          in_XMM2[0xf] = (0 < sVar4) * (sVar4 < 0x100) * auVar21[0xe] - (0xff < sVar4);

          *param_5 = in_XMM2;

          param_5 = param_5 + 1;

          uVar19 = uVar19 - 1;

        } while (uVar19 != 0);

      }

      for (; uVar20 != 0; uVar20 = uVar20 - 1) {

        puVar15 = *param_3;

        uVar1 = (*param_3)[1];

        uVar2 = (*param_3)[2];

        uVar3 = (*param_3)[3];

        uVar18 = 0;

        param_3 = (undefined1 (*) [16])(*param_3 + 4);

        (*param_5)[0] = *puVar15;

        (*param_5)[1] = uVar3;

        (*param_5)[2] = uVar2;

        (*param_5)[3] = uVar1;

        param_5 = (undefined1 (*) [16])(*param_5 + 4);

      }

      param_3 = (undefined1 (*) [16])(*param_3 + (int)(param_4 + uVar16 * -4));

      param_5 = (undefined1 (*) [16])(*param_5 + (int)uVar17);

    } while (param_2 != 0);

  }

  return CONCAT71((int7)(uVar18 >> 8),1);

}





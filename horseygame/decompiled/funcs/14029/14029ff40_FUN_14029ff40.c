// Address: 0x14029ff40
// Ghidra name: FUN_14029ff40
// ============ 0x14029ff40 FUN_14029ff40 (size=1674) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14029ff40(uint *param_1,int param_2,int *param_3,longlong param_4,uint param_5,

                  float param_6,undefined4 *param_7,undefined4 *param_8,undefined4 *param_9,

                  undefined4 *param_10)



{

  char cVar1;

  longlong lVar2;

  uint uVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  ulonglong uVar7;

  byte bVar8;

  byte bVar9;

  int iVar10;

  byte bVar11;

  float fVar12;

  undefined8 uVar13;

  undefined8 extraout_XMM0_Qb;

  undefined8 extraout_XMM0_Qb_00;

  undefined8 extraout_XMM0_Qb_01;

  undefined8 extraout_XMM0_Qb_02;

  undefined1 auVar14 [16];

  undefined8 extraout_XMM0_Qb_03;

  undefined8 extraout_XMM0_Qb_04;

  undefined8 extraout_XMM0_Qb_05;

  undefined8 extraout_XMM0_Qb_06;

  undefined8 extraout_XMM0_Qb_07;

  undefined8 extraout_XMM0_Qb_08;

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  undefined1 auVar22 [16];

  undefined1 auVar23 [16];

  

  uVar3 = DAT_14039ca44;

  auVar19 = ZEXT816(0);

  auVar16 = ZEXT816(0);

  auVar18 = ZEXT816(0);

  fVar12 = DAT_14030a2d0;

  if (param_2 == 0) {

    uVar7 = (ulonglong)(byte)*param_1;

    lVar2 = *(longlong *)(param_4 + 8);

    bVar9 = *(byte *)(lVar2 + uVar7 * 4);

    bVar8 = *(byte *)(lVar2 + 1 + uVar7 * 4);

    bVar11 = *(byte *)(lVar2 + 2 + uVar7 * 4);

    bVar4 = *(byte *)(lVar2 + 3 + uVar7 * 4);

    goto LAB_1402a04b4;

  }

  if (param_2 == 1) {

    cVar1 = *(char *)((longlong)param_3 + 5);

    if (cVar1 == '\x01') {

      uVar7 = (ulonglong)(byte)*param_1;

LAB_1402a03f5:

      uVar5 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)(param_3 + 6)]

                          [((uint)param_3[2] & uVar7) >> (*(byte *)(param_3 + 7) & 0x3f)];

      uVar3 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_3 + 0x19)]

                          [((uint)param_3[3] & uVar7) >>

                           (*(byte *)((longlong)param_3 + 0x1d) & 0x3f)];

      uVar6 = (uint)(byte)(&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_3 + 0x1a)]

                          [((uint)param_3[4] & uVar7) >>

                           (*(byte *)((longlong)param_3 + 0x1e) & 0x3f)];

    }

    else {

      if (cVar1 == '\x02') {

        uVar7 = (ulonglong)(ushort)*param_1;

        goto LAB_1402a03f5;

      }

      if (cVar1 == '\x03') {

        uVar5 = (uint)*(byte *)((ulonglong)(*(byte *)(param_3 + 7) >> 3) + (longlong)param_1);

        uVar3 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1d) >> 3) +

                               (longlong)param_1);

        uVar6 = (uint)*(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1e) >> 3) +

                               (longlong)param_1);

      }

      else {

        if (cVar1 == '\x04') {

          uVar7 = (ulonglong)*param_1;

          goto LAB_1402a03f5;

        }

        uVar6 = 0;

        uVar3 = 0;

        uVar5 = 0;

      }

    }

LAB_1402a01cc:

    auVar19 = ZEXT416((uint)(float)uVar5);

    auVar23 = ZEXT416(DAT_14039ca44);

    auVar16 = ZEXT416((uint)(float)uVar3);

    auVar18 = ZEXT416((uint)(float)uVar6);

  }

  else if (param_2 == 2) {

    cVar1 = *(char *)((longlong)param_3 + 5);

    if (cVar1 == '\x01') {

      uVar7 = (ulonglong)(byte)*param_1;

LAB_1402a02d7:

      bVar9 = (&PTR_DAT_1403e28a0)[*(byte *)(param_3 + 6)]

              [((uint)param_3[2] & uVar7) >> (*(byte *)(param_3 + 7) & 0x3f)];

      bVar8 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_3 + 0x19)]

              [((uint)param_3[3] & uVar7) >> (*(byte *)((longlong)param_3 + 0x1d) & 0x3f)];

      bVar11 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_3 + 0x1a)]

               [((uint)param_3[4] & uVar7) >> (*(byte *)((longlong)param_3 + 0x1e) & 0x3f)];

      bVar4 = (&PTR_DAT_1403e28a0)[*(byte *)((longlong)param_3 + 0x1b)]

              [((uint)param_3[5] & uVar7) >> (*(byte *)((longlong)param_3 + 0x1f) & 0x3f)];

    }

    else {

      if (cVar1 == '\x02') {

        uVar7 = (ulonglong)(ushort)*param_1;

        goto LAB_1402a02d7;

      }

      if (cVar1 == '\x03') {

        bVar4 = 0xff;

        bVar9 = *(byte *)((ulonglong)(*(byte *)(param_3 + 7) >> 3) + (longlong)param_1);

        bVar8 = *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1d) >> 3) + (longlong)param_1)

        ;

        bVar11 = *(byte *)((ulonglong)(*(byte *)((longlong)param_3 + 0x1e) >> 3) + (longlong)param_1

                          );

      }

      else {

        if (cVar1 == '\x04') {

          uVar7 = (ulonglong)*param_1;

          goto LAB_1402a02d7;

        }

        bVar4 = 0;

        bVar11 = 0;

        bVar8 = 0;

        bVar9 = 0;

      }

    }

LAB_1402a04b4:

    auVar18 = ZEXT416((uint)(float)bVar11);

    auVar19 = ZEXT416((uint)(float)bVar9);

    auVar16 = ZEXT416((uint)(float)bVar8);

    auVar23 = ZEXT416((uint)((float)bVar4 / DAT_14030a2d0));

  }

  else {

    auVar17 = auVar16;

    auVar20 = auVar19;

    auVar15 = auVar18;

    auVar23 = ZEXT816(0);

    if (param_2 != 3) {

      if (param_2 != 4) goto LAB_1402a04cf;

      iVar10 = *param_3;

      auVar23 = ZEXT416(DAT_14039ca44);

      uVar5 = iVar10 >> 0x18 & 0xf;

      if (uVar5 == 8) {

        auVar19 = ZEXT416((uint)((float)(ushort)*param_1 / DAT_14030ec38));

        auVar15 = ZEXT416((uint)((float)(ushort)param_1[1] / DAT_14030ec38));

        auVar16 = ZEXT416((uint)((float)*(ushort *)((longlong)param_1 + 2) / DAT_14030ec38));

        if (*(char *)((longlong)param_3 + 5) == '\b') {

          auVar14 = ZEXT416((uint)((float)*(ushort *)((longlong)param_1 + 6) / DAT_14030ec38));

        }

        else {

LAB_1402a0083:

          auVar14 = ZEXT416(uVar3);

        }

      }

      else if (uVar5 == 10) {

        uVar13 = FUN_1402a29d0((short)*param_1);

        auVar19._8_4_ = (int)extraout_XMM0_Qb;

        auVar19._0_8_ = uVar13;

        auVar19._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);

        uVar13 = FUN_1402a29d0(*(undefined2 *)((longlong)param_1 + 2));

        auVar16._8_4_ = (int)extraout_XMM0_Qb_00;

        auVar16._0_8_ = uVar13;

        auVar16._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_00 >> 0x20);

        uVar13 = FUN_1402a29d0((short)param_1[1]);

        auVar15._8_4_ = (int)extraout_XMM0_Qb_01;

        auVar15._0_8_ = uVar13;

        auVar15._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_01 >> 0x20);

        if (*(char *)((longlong)param_3 + 5) != '\b') goto LAB_1402a0083;

        auVar14._0_8_ = FUN_1402a29d0(*(undefined2 *)((longlong)param_1 + 6));

        auVar14._8_8_ = extraout_XMM0_Qb_02;

      }

      else if (uVar5 == 0xb) {

        auVar19 = ZEXT416(*param_1);

        auVar16 = ZEXT416(param_1[1]);

        auVar15 = ZEXT416(param_1[2]);

        if (*(char *)((longlong)param_3 + 5) != '\x10') goto LAB_1402a0083;

        auVar14 = ZEXT416(param_1[3]);

      }

      else {

        auVar14 = ZEXT816(0);

        auVar15 = ZEXT816(0);

      }

      auVar17 = auVar15;

      auVar20 = auVar15;

      switch(iVar10 >> 0x14 & 0xf) {

      case 1:

        auVar17 = auVar16;

        auVar20 = auVar19;

        break;

      case 2:

        auVar17 = auVar16;

        auVar20 = auVar19;

        auVar23 = auVar14;

        break;

      case 3:

        auVar20 = auVar16;

        auVar15 = auVar14;

        auVar23 = auVar19;

        break;

      case 4:

        auVar17 = auVar16;

        auVar15 = auVar19;

        break;

      case 5:

        auVar17 = auVar16;

        auVar15 = auVar19;

        auVar23 = auVar14;

        break;

      case 6:

        auVar20 = auVar14;

        auVar15 = auVar16;

        auVar23 = auVar19;

        break;

      default:

        auVar17 = ZEXT816(0);

        auVar20 = ZEXT816(0);

        auVar15 = auVar18;

        auVar23 = ZEXT816(0);

      }

      goto LAB_1402a04cf;

    }

    iVar10 = *param_3;

    uVar3 = *param_1;

    fVar12 = _DAT_1403802bc;

    if (iVar10 == 0x16172004) {

      uVar5 = uVar3 >> 0x14;

      uVar6 = uVar3;

LAB_1402a01be:

      uVar5 = uVar5 & 0x3ff;

      uVar3 = uVar3 >> 10 & 0x3ff;

      uVar6 = uVar6 & 0x3ff;

      goto LAB_1402a01cc;

    }

    if (iVar10 == 0x16372004) {

      auVar19 = ZEXT416((uint)(float)(uVar3 >> 0x14 & 0x3ff));

      auVar16 = ZEXT416((uint)(float)(uVar3 >> 10 & 0x3ff));

      auVar18 = ZEXT416((uint)(float)(uVar3 & 0x3ff));

      auVar23 = ZEXT416((uint)((float)(uVar3 >> 0x1e) / DAT_14030338c));

    }

    else {

      if (iVar10 == 0x16572004) {

        uVar6 = uVar3 >> 0x14;

        uVar5 = uVar3;

        goto LAB_1402a01be;

      }

      if (iVar10 != 0x16772004) goto LAB_1402a04cf;

      auVar19 = ZEXT416((uint)(float)(uVar3 & 0x3ff));

      auVar16 = ZEXT416((uint)(float)(uVar3 >> 10 & 0x3ff));

      auVar18 = ZEXT416((uint)(float)(uVar3 >> 0x14 & 0x3ff));

      auVar23 = ZEXT416((uint)((float)(uVar3 >> 0x1e) / DAT_14030338c));

    }

  }

  auVar20._4_12_ = auVar19._4_12_;

  auVar20._0_4_ = auVar19._0_4_ / fVar12;

  auVar17._4_12_ = auVar16._4_12_;

  auVar17._0_4_ = auVar16._0_4_ / fVar12;

  auVar15._4_12_ = auVar18._4_12_;

  auVar15._0_4_ = auVar18._0_4_ / fVar12;

LAB_1402a04cf:

  param_5 = param_5 & 0x3e0;

  if (param_5 == 0x100) {

    auVar20._0_4_ = auVar20._0_4_ / param_6;

    auVar17._0_4_ = auVar17._0_4_ / param_6;

    auVar15._0_4_ = auVar15._0_4_ / param_6;

  }

  else if (param_5 == 0x1a0) {

    uVar13 = FUN_14017c3b0();

    auVar20._8_4_ = (int)extraout_XMM0_Qb_06;

    auVar20._0_8_ = uVar13;

    auVar20._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_06 >> 0x20);

    uVar13 = FUN_14017c3b0();

    auVar17._8_4_ = (int)extraout_XMM0_Qb_07;

    auVar17._0_8_ = uVar13;

    auVar17._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_07 >> 0x20);

    uVar13 = FUN_14017c3b0();

    auVar15._8_4_ = (int)extraout_XMM0_Qb_08;

    auVar15._0_8_ = uVar13;

    auVar15._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_08 >> 0x20);

  }

  else if (param_5 == 0x200) {

    uVar13 = FUN_14017c1c0();

    auVar21._8_4_ = (int)extraout_XMM0_Qb_03;

    auVar21._0_8_ = uVar13;

    auVar21._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_03 >> 0x20);

    auVar20._4_12_ = auVar21._4_12_;

    auVar20._0_4_ = (float)uVar13 / param_6;

    uVar13 = FUN_14017c1c0();

    auVar18._8_4_ = (int)extraout_XMM0_Qb_04;

    auVar18._0_8_ = uVar13;

    auVar18._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_04 >> 0x20);

    auVar17._4_12_ = auVar18._4_12_;

    auVar17._0_4_ = (float)uVar13 / param_6;

    uVar13 = FUN_14017c1c0();

    auVar22._8_4_ = (int)extraout_XMM0_Qb_05;

    auVar22._0_8_ = uVar13;

    auVar22._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_05 >> 0x20);

    auVar15._4_12_ = auVar22._4_12_;

    auVar15._0_4_ = (float)uVar13 / param_6;

  }

  *param_7 = auVar20._0_4_;

  *param_8 = auVar17._0_4_;

  *param_9 = auVar15._0_4_;

  *param_10 = auVar23._0_4_;

  return;

}





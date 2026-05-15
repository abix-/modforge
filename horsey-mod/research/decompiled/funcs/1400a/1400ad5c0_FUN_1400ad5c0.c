// Address: 0x1400ad5c0
// Ghidra name: FUN_1400ad5c0
// ============ 0x1400ad5c0 FUN_1400ad5c0 (size=3254) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400ad5c0(longlong param_1,undefined8 param_2,float *param_3)



{

  longlong *plVar1;

  float fVar2;

  byte bVar3;

  bool bVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  longlong lVar9;

  longlong lVar10;

  byte bVar11;

  int iVar12;

  uint uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  ulonglong uVar16;

  int iVar17;

  int *piVar18;

  bool bVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  undefined4 local_res8 [2];

  float fVar25;

  undefined4 uVar26;

  uint in_stack_ffffffffffffff20;

  char local_d8 [8];

  undefined4 local_d0;

  uint local_cc;

  undefined8 local_c8;

  undefined8 local_c0;

  

  fVar2 = param_3[0x157];

  plVar1 = (longlong *)(param_1 + 0xa8);

  uVar16 = 0;

  *(float *)(param_1 + 0xc4) = fVar2;

  fVar23 = param_3[0x158];

  *(float *)(param_1 + 200) = fVar23;

  uVar8 = 0;

  local_res8[0] = 0;

  FUN_140064380(plVar1,(longlong)((int)fVar23 * (int)fVar2),local_res8);

  FUN_1400c86f0(param_3 + 0x14d,*plVar1,*(undefined4 *)(param_1 + 0xc4),

                *(undefined4 *)(param_1 + 200));

  bVar19 = true;

  *(undefined4 *)(*plVar1 + -4 + (longlong)*(int *)(param_1 + 0xc4) * 4) = 0;

  iVar17 = *(int *)(param_1 + 0xc4) * *(int *)(param_1 + 200);

  piVar18 = (int *)*plVar1;

  iVar12 = *piVar18;

  if (1 < iVar17) {

    uVar14 = (ulonglong)(iVar17 - 1);

    bVar4 = bVar19;

    do {

      piVar18 = piVar18 + 1;

      bVar19 = false;

      if (iVar12 == *piVar18) {

        bVar19 = bVar4;

      }

      uVar14 = uVar14 - 1;

      bVar4 = bVar19;

    } while (uVar14 != 0);

  }

  if ((param_3[0x138] != 0.0) && (uVar14 = uVar16, uVar15 = uVar16, 0 < iVar17)) {

    do {

      lVar9 = *plVar1;

      if (*(float *)(uVar14 + lVar9) == 0.0) {

        *(float *)(uVar14 + lVar9) = param_3[0x138];

      }

      else if (*(float *)(uVar14 + lVar9) == param_3[0x138]) {

        *(undefined4 *)(uVar14 + lVar9) = 0;

      }

      uVar13 = (int)uVar15 + 1;

      uVar14 = uVar14 + 4;

      uVar15 = (ulonglong)uVar13;

    } while ((int)uVar13 < *(int *)(param_1 + 0xc4) * *(int *)(param_1 + 200));

  }

  uVar13 = DAT_14039ca44;

  fVar2 = param_3[5];

  iVar17 = 0xc;

  if (bVar19) {

    iVar17 = iVar12;

  }

  FUN_1400a9360(param_2,&DAT_1403f3168,0,0,*param_3 - fVar2,param_3[1],iVar17,DAT_14039ca44);

  if (0.0 < fVar2) {

    fVar23 = *param_3 - fVar2;

    in_stack_ffffffffffffff20 = uVar13;

    FUN_1400aa0d0(param_2,&DAT_1403f3168,fVar23,0,*param_3,fVar2,fVar23,fVar2,0,uVar13);

    if (fVar2 < param_3[1]) {

      FUN_1400a9360(param_2,&DAT_1403f3168,*param_3 - fVar2,fVar2,fVar2,param_3[1] - fVar2,0,uVar13)

      ;

    }

  }

  fVar23 = DAT_14039ca34;

  fVar2 = *param_3;

  *(float *)(param_1 + 0x128) = param_3[1];

  *(float *)(param_1 + 0x124) = fVar2 * fVar23;

  *(float *)(param_1 + 300) = *param_3;

  fVar2 = param_3[3];

  if ((0.0 < fVar2) && (fVar25 = param_3[2], 0.0 < fVar25)) {

    FUN_1400a9360(param_2,&DAT_1403f3168,(*param_3 - fVar25) - param_3[5],

                  (uint)fVar2 ^ DAT_14039cac0,fVar25,fVar2,0,uVar13);

  }

  fVar2 = DAT_140303358;

  fVar20 = (float)FUN_1400c5f70((float)*(int *)(param_1 + 0x210) * DAT_140303358,param_3[4],

                                DAT_140307a3c);

  fVar25 = DAT_140303380;

  if (0.0 < fVar20) {

    fVar21 = param_3[6];

    if (fVar21 == 1.4013e-45) {

      fVar22 = param_3[1];

      fVar24 = *param_3 / DAT_14030338c;

      bVar19 = true;

      uVar26 = 3;

      fVar20 = *param_3 * fVar20;

    }

    else {

      uVar26 = uVar8;

      if (*plVar1 != *(longlong *)(param_1 + 0xb0)) {

        uVar26 = *(undefined4 *)

                  (*plVar1 +

                  (longlong)

                  (*(int *)(param_1 + 0xc4) * *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc4) / 2

                  ) * 4);

      }

      fVar22 = param_3[1];

      bVar19 = fVar21 == 2.8026e-45;

      fVar24 = *param_3;

    }

    in_stack_ffffffffffffff20 = CONCAT31((int3)(in_stack_ffffffffffffff20 >> 8),bVar19);

    FUN_1400aa2b0(param_2,&DAT_1403f3168,0,fVar21,fVar24,fVar22,fVar20,uVar26,DAT_140303380,

                  in_stack_ffffffffffffff20);

  }

  fVar20 = param_3[1];

  fVar21 = (float)FUN_1400c5f70();

  if (0.0 < fVar21) {

    fVar20 = param_3[0xf];

    if (*plVar1 != *(longlong *)(param_1 + 0xb0)) {

      uVar8 = *(undefined4 *)

               (*plVar1 + (longlong)((*(int *)(param_1 + 200) + -1) * *(int *)(param_1 + 0xc4)) * 4)

      ;

    }

    FUN_1400aa2b0(param_2,&DAT_1403f3168,0,fVar20,0,param_3[1],(param_3[1] - fVar20) * fVar21,uVar8,

                  fVar25,in_stack_ffffffffffffff20 & 0xffffff00);

  }

  uVar8 = DAT_14030335c;

  fVar21 = param_3[7];

  if (0 < (int)fVar21) {

    fVar22 = *param_3;

    fVar24 = param_3[8];

    lVar9 = 0x4e0;

    if (*(char *)(param_3 + 9) == '\0') {

      lVar9 = 0x44c;

    }

    if (fVar22 < param_3[1] || fVar22 == param_3[1]) {

      if (fVar21 == 2.8026e-45) {

        fVar21 = fVar20;

        if (fVar24 * fVar25 <= fVar20) {

          fVar21 = fVar24 * fVar25;

        }

        fVar24 = fVar21 * DAT_14030d98c;

        fVar25 = fVar20 * fVar23 - fVar21 * fVar23;

        fVar20 = fVar20 * fVar23 + fVar21 * fVar23;

      }

      else {

        fVar25 = 0.0;

      }

      fVar22 = 0.0;

      fVar21 = 0.0;

    }

    else {

      fVar22 = (fVar22 - param_3[5]) - param_3[2];

      if (fVar21 == 2.8026e-45) {

        fVar20 = fVar22;

        if (fVar24 * fVar25 <= fVar22) {

          fVar20 = fVar24 * fVar25;

        }

        fVar24 = fVar20 * DAT_14030d98c;

        fVar21 = fVar22 * fVar23 - fVar20 * fVar23;

        fVar22 = fVar20 * fVar23 + fVar22 * fVar23;

      }

      else {

        fVar21 = 0.0;

      }

      fVar20 = 0.0;

      fVar25 = 0.0;

    }

    FUN_1400aa760(param_2,&DAT_1403f3168,fVar21,fVar20,fVar22,fVar25,fVar24,*(char *)(param_3 + 9),

                  *(undefined4 *)(lVar9 + (longlong)param_3),DAT_14030335c);

  }

  uVar26 = DAT_140304c58;

  if (*(int *)(param_1 + 0xcc) == 0x23) {

    lVar9 = FUN_1400ab1b0(param_1,param_2,((*param_3 - param_3[5]) - param_3[2]) * fVar23,0,0);

    uVar7 = DAT_14039ca24;

    uVar6 = DAT_140304078;

    uVar5 = DAT_140303354;

    FUN_1400a9360(lVar9,&DAT_1403f3168,DAT_140304078,uVar26,DAT_140303354,uVar8,0x13,DAT_14039ca24);

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    lVar9 = FUN_1400ab1b0(param_1,lVar9,0,uVar26,0);

    FUN_1400a9360(lVar9,&DAT_1403f3168,uVar6,uVar26,uVar5,uVar8,0x13,uVar7);

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    lVar9 = FUN_1400ab1b0(param_1,lVar9,0,uVar26,0);

    FUN_1400a9360(lVar9,&DAT_1403f3168,uVar6,uVar26,uVar5,uVar8,0x13,uVar7);

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    lVar9 = FUN_1400ab1b0(param_1,lVar9,0,uVar26,0);

    FUN_1400a9360(lVar9,&DAT_1403f3168,uVar6,uVar26,uVar5,uVar8,0x13,uVar7);

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    lVar9 = FUN_1400ab1b0(param_1,lVar9,0,uVar26,0);

    FUN_1400a9360(lVar9,&DAT_1403f3168,uVar6,uVar26,uVar5,uVar8,0x13,uVar7);

    uVar8 = DAT_140303fb4;

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    lVar9 = FUN_1400ab1b0(param_1,lVar9,uVar8,uVar26,0);

    lVar10 = FUN_1400a9180(lVar9,0xf,uVar7);

    fVar25 = DAT_1403f3170 * DAT_14030d9dc;

    *(float *)(lVar10 + 0x144) =

         (DAT_1403f3170 * 0.0 - DAT_1403f3174 * _DAT_14030cd20) + DAT_1403f316c;

    *(undefined4 *)(lVar10 + 0x148) = 0x3ea8f5c3;

    *(float *)(lVar10 + 0x140) = (DAT_1403f3174 * 0.0 - fVar25) + DAT_1403f3168;

    *(undefined4 *)(lVar10 + 0x15c) = 7;

    *(undefined1 *)(lVar9 + 0x84) = 1;

    *(undefined8 *)(lVar9 + 100) = 1;

    *(undefined8 *)(lVar9 + 0x6c) = 0;

    *(undefined8 *)(lVar9 + 0x74) = 0;

    *(undefined4 *)(lVar9 + 0x7c) = 0;

    *(undefined4 *)(lVar9 + 8) = 0xe;

    *(undefined4 *)(lVar9 + 0xc) = 0x10;

    _DAT_1403f3168 = DAT_1403f3180[-2];

    _DAT_1403f3170 = DAT_1403f3180[-1];

    DAT_1403f3180 = DAT_1403f3180 + -2;

    *DAT_1403f3190 = *DAT_1403f3190 | 1;

    *(undefined1 *)(param_1 + 0x20) = 1;

  }

  uVar5 = DAT_14030d984;

  uVar8 = DAT_14030b668;

  if (*(int *)(param_1 + 0xd8) == 0x22) {

    if ((param_3[1] < *param_3 || param_3[1] == *param_3) ||

       ((param_3[3] != 0.0 && (param_3[2] != 0.0)))) {

      *(undefined1 *)(param_1 + 0x120) = 0;

      FUN_1400a9360(param_2,&DAT_1403f3168,0,uVar8,uVar5,fVar23,5,uVar13);

      FUN_1400aa0d0(param_2,&DAT_1403f3168,uVar5,uVar8,DAT_14030d998,uVar26,uVar5,0,0xf,uVar13);

      local_d0._0_1_ = s_DecoJetEngine_14030d708[8];

      local_d0._1_1_ = s_DecoJetEngine_14030d708[9];

      local_d0._2_1_ = s_DecoJetEngine_14030d708[10];

      local_d0._3_1_ = s_DecoJetEngine_14030d708[0xb];

      local_c8 = 0xd;

      local_cc._0_2_ = (ushort)(byte)s_DecoJetEngine_14030d708[0xc];

      local_d8 = (char  [8])s_DecoJetEngine_14030d708._0_8_;

    }

    else {

      *(undefined1 *)(param_1 + 0x120) = 1;

      FUN_1400a9360(param_2,&DAT_1403f3168,uVar8,0,fVar23,uVar13,5,uVar13);

      FUN_1400aa0d0(param_2,&DAT_1403f3168,uVar8,0,uVar26,uVar26,0,0,0xf,uVar13);

      local_d0._0_1_ = s_DecoJetEngineV_14030d6f8[8];

      local_d0._1_1_ = s_DecoJetEngineV_14030d6f8[9];

      local_d0._2_1_ = s_DecoJetEngineV_14030d6f8[10];

      local_d0._3_1_ = s_DecoJetEngineV_14030d6f8[0xb];

      local_c8 = 0xe;

      local_d8 = (char  [8])s_DecoJetEngineV_14030d6f8._0_8_;

      local_cc._0_2_ = s_DecoJetEngineV_14030d6f8._12_2_;

    }

    local_cc = (uint)(ushort)local_cc;

    local_c0 = 0xf;

    uVar8 = FUN_14006fe60(local_d8);

    FUN_1400aaa30(param_2,&DAT_1403f3168,0,0,uVar13,uVar8);

    *DAT_1403f3190 = *DAT_1403f3190 | 8;

  }

  uVar8 = DAT_14030d954;

  piVar18 = (int *)(param_1 + 0x110);

  lVar9 = 4;

  bVar11 = (*piVar18 != -1) + 1;

  if (*(int *)(param_1 + 0x114) == -1) {

    bVar11 = *piVar18 != -1;

  }

  bVar3 = bVar11 + 1;

  if (*(int *)(param_1 + 0x118) == -1) {

    bVar3 = bVar11;

  }

  bVar11 = bVar3 + 1;

  if (*(int *)(param_1 + 0x11c) == -1) {

    bVar11 = bVar3;

  }

  fVar25 = (*param_3 - fVar2) - (float)bVar11 * fVar2;

  do {

    iVar12 = (int)uVar16;

    if (*piVar18 != -1) {

      local_cc = 0;

      local_c8 = 0xb;

      local_c0 = 0xf;

      local_d8[0] = s_ItemRibbon1_1403055c0[0];

      local_d8[1] = s_ItemRibbon1_1403055c0[1];

      local_d8[2] = s_ItemRibbon1_1403055c0[2];

      local_d8[3] = s_ItemRibbon1_1403055c0[3];

      local_d8[4] = s_ItemRibbon1_1403055c0[4];

      local_d8[5] = s_ItemRibbon1_1403055c0[5];

      local_d8[6] = s_ItemRibbon1_1403055c0[6];

      local_d8[7] = s_ItemRibbon1_1403055c0[7];

      local_d0 = (uint)CONCAT12(s_ItemRibbon1_1403055c0[10],s_ItemRibbon1_1403055c0._8_2_);

      iVar17 = FUN_14006fe60(local_d8);

      FUN_1400aaa30(param_2,&DAT_1403f3168,fVar25,uVar8,fVar23,iVar17 + iVar12);

      fVar25 = fVar25 + fVar2;

      uVar16 = (longlong)iVar12 + 0x11U >> 5;

      DAT_1403f3190[uVar16] = DAT_1403f3190[uVar16] | 1 << ((uint)((longlong)iVar12 + 0x11U) & 0x1f)

      ;

    }

    uVar16 = (ulonglong)(iVar12 + 1);

    piVar18 = piVar18 + 1;

    lVar9 = lVar9 + -1;

  } while (lVar9 != 0);

  return;

}





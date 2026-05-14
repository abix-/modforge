// Address: 0x140056620
// Ghidra name: FUN_140056620
// ============ 0x140056620 FUN_140056620 (size=5169) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140056620(longlong param_1)



{

  uint *puVar1;

  undefined4 *puVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  char cVar9;

  undefined8 *puVar10;

  int *piVar11;

  undefined8 uVar12;

  undefined8 *puVar13;

  longlong lVar14;

  undefined8 uVar15;

  float *pfVar16;

  int iVar17;

  int iVar18;

  uint uVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  float fVar23;

  float fVar24;

  longlong local_res8;

  undefined4 local_res10 [2];

  undefined8 in_stack_fffffffffffffef8;

  undefined4 uVar25;

  undefined4 uVar26;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  ulonglong local_d0;

  

  uVar25 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

  local_res8 = param_1;

  FUN_140070f90(DAT_1403d4b04);

  FUN_140071000();

  fVar8 = DAT_14039ca44;

  iVar18 = 0xd2;

  do {

    FUN_140071000();

    iVar18 = iVar18 + 0x10;

  } while (iVar18 < 0x132);

  iVar18 = 0x21;

  do {

    FUN_140071000();

    iVar18 = iVar18 + 0x10;

  } while (iVar18 < 0x91);

  if (*(char *)(param_1 + 0x279) != '\0') {

    FUN_140072ed0();

    uVar12 = CONCAT44(uVar25,*(undefined4 *)(param_1 + 0x26c));

    FUN_1400d6560(param_1,*(longlong *)(param_1 + 0x270) + 0x2b8,*(undefined4 *)(param_1 + 0x27c),

                  fVar8,uVar12);

    uVar25 = (undefined4)((ulonglong)uVar12 >> 0x20);

    FUN_1400730f0();

  }

  if (*(int *)(*(longlong *)(param_1 + 0x270) + 0x1f8) == -1) {

    return;

  }

  puVar10 = (undefined8 *)FUN_1400c7520();

  piVar11 = (int *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    piVar11 = DAT_1403d9530;

  }

  if ((((DAT_1403d9540 == 5) && (*piVar11 == 0x74656544)) && ((char)piVar11[1] == 's')) &&

     (*(int *)((longlong)puVar10 + 0x5c) != 2)) {

    puVar1 = (uint *)(*(longlong *)(param_1 + 0x270) + 600);

    *puVar1 = *puVar1 | 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x1fc) = 3;

    *(undefined4 *)(puVar10 + 10) = 5;

    *(undefined4 *)((longlong)puVar10 + 0x54) = 1;

    *(undefined4 *)((longlong)puVar10 + 0x5c) = 2;

    *(undefined1 *)((longlong)puVar10 + 99) = 1;

    uVar12 = FUN_1400c7560(&local_e8);

    FUN_1400c7910(3,uVar12);

    if (0xf < local_d0) {

      if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    uVar12 = FUN_1400c7560(&local_e8);

    FUN_1400c7910(4,uVar12);

    if (0xf < local_d0) {

      if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    uVar12 = FUN_1400c7560(&local_e8);

    FUN_1400c7910(0x11,uVar12);

    if (0xf < local_d0) {

      if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(undefined4 *)(puVar10 + 9) = 3;

    *(undefined4 *)((longlong)puVar10 + 0x4c) = 4;

    local_res10[0] = 0x11;

    puVar2 = (undefined4 *)puVar10[0xf];

    if (puVar2 == (undefined4 *)puVar10[0x10]) {

      FUN_140057a60(puVar10 + 0xe,puVar2,local_res10);

    }

    else {

      *puVar2 = 0x11;

      puVar10[0xf] = puVar10[0xf] + 4;

    }

  }

  lVar14 = *(longlong *)(param_1 + 0x60);

  if (*(int *)(param_1 + 0xd8) == 8) {

    FUN_140071000();

  }

  fVar23 = DAT_140303fcc;

  puVar13 = puVar10;

  if (0xf < (ulonglong)puVar10[3]) {

    puVar13 = (undefined8 *)*puVar10;

  }

  uVar12 = CONCAT44(uVar25,fVar8);

  FUN_140086570(DAT_1403ede48,puVar13,DAT_140305630,0,uVar12,

                *(undefined4 *)(&DAT_1403ea710 + (longlong)*(int *)((longlong)puVar10 + 0x44) * 4),

                puVar13);

  cVar9 = FUN_14008d2c0();

  fVar6 = DAT_14030374c;

  if (((cVar9 != '\0') && (DAT_1403ed950 % 0x1e < 0xf)) || (*(int *)(param_1 + 0xd8) == 8)) {

    uVar12 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),DAT_1403d4a70);

    FUN_140071000(*(float *)(lVar14 + 0x37c) + fVar23);

  }

  lVar14 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);

  if ((*(int *)(lVar14 + 4) < DAT_1403ea754) && (FUN_1402c7138(&DAT_1403ea754), DAT_1403ea754 == -1)

     ) {

    local_d8 = 10;

    local_d0 = 0xf;

    local_e8._0_1_ = s_StatusFoal_1403055a0[0];

    local_e8._1_1_ = s_StatusFoal_1403055a0[1];

    local_e8._2_1_ = s_StatusFoal_1403055a0[2];

    local_e8._3_1_ = s_StatusFoal_1403055a0[3];

    local_e8._4_1_ = s_StatusFoal_1403055a0[4];

    local_e8._5_1_ = s_StatusFoal_1403055a0[5];

    local_e8._6_1_ = s_StatusFoal_1403055a0[6];

    local_e8._7_1_ = s_StatusFoal_1403055a0[7];

    uStack_e0 = (ulonglong)(ushort)s_StatusFoal_1403055a0._8_2_;

    DAT_1403ea750 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea754);

  }

  if ((*(int *)(lVar14 + 4) < DAT_1403ea75c) && (FUN_1402c7138(&DAT_1403ea75c), DAT_1403ea75c == -1)

     ) {

    local_d8 = 10;

    local_d0 = 0xf;

    local_e8._0_1_ = s_ItemTrophy_1403055b0[0];

    local_e8._1_1_ = s_ItemTrophy_1403055b0[1];

    local_e8._2_1_ = s_ItemTrophy_1403055b0[2];

    local_e8._3_1_ = s_ItemTrophy_1403055b0[3];

    local_e8._4_1_ = s_ItemTrophy_1403055b0[4];

    local_e8._5_1_ = s_ItemTrophy_1403055b0[5];

    local_e8._6_1_ = s_ItemTrophy_1403055b0[6];

    local_e8._7_1_ = s_ItemTrophy_1403055b0[7];

    uStack_e0 = (ulonglong)(ushort)s_ItemTrophy_1403055b0._8_2_;

    DAT_1403ea758 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea75c);

  }

  uVar22 = 0;

  if ((*(int *)(lVar14 + 4) < DAT_1403ea764) && (FUN_1402c7138(&DAT_1403ea764), DAT_1403ea764 == -1)

     ) {

    local_d8 = 0xb;

    local_d0 = 0xf;

    local_e8._0_1_ = s_ItemRibbon1_1403055c0[0];

    local_e8._1_1_ = s_ItemRibbon1_1403055c0[1];

    local_e8._2_1_ = s_ItemRibbon1_1403055c0[2];

    local_e8._3_1_ = s_ItemRibbon1_1403055c0[3];

    local_e8._4_1_ = s_ItemRibbon1_1403055c0[4];

    local_e8._5_1_ = s_ItemRibbon1_1403055c0[5];

    local_e8._6_1_ = s_ItemRibbon1_1403055c0[6];

    local_e8._7_1_ = s_ItemRibbon1_1403055c0[7];

    uStack_e0 = (ulonglong)CONCAT12(s_ItemRibbon1_1403055c0[10],s_ItemRibbon1_1403055c0._8_2_);

    DAT_1403ea760 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea764);

  }

  if ((*(int *)(lVar14 + 4) < DAT_1403ea76c) && (FUN_1402c7138(&DAT_1403ea76c), DAT_1403ea76c == -1)

     ) {

    local_d8 = 8;

    local_d0 = 0xf;

    local_e8 = 0x746c65426f6d7553;

    uStack_e0 = 0;

    DAT_1403ea768 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea76c);

  }

  if ((*(int *)(lVar14 + 4) < DAT_1403ea774) && (FUN_1402c7138(&DAT_1403ea774), DAT_1403ea774 == -1)

     ) {

    uStack_e0 = 0;

    local_d8 = 3;

    local_d0 = 0xf;

    local_e8 = (ulonglong)(uint3)DAT_1403055cc;

    DAT_1403ea770 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea774);

  }

  if ((*(int *)(lVar14 + 4) < DAT_1403ea77c) && (FUN_1402c7138(&DAT_1403ea77c), DAT_1403ea77c == -1)

     ) {

    uStack_e0 = 0;

    local_d8 = 5;

    local_d0 = 0xf;

    local_e8 = (ulonglong)CONCAT14(s_Brain_1403055d0[4],s_Brain_1403055d0._0_4_);

    DAT_1403ea778 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea77c);

  }

  if ((*(int *)(lVar14 + 4) < DAT_1403ea784) && (FUN_1402c7138(&DAT_1403ea784), DAT_1403ea784 == -1)

     ) {

    local_d8 = 8;

    local_d0 = 0xf;

    local_e8 = 0x7461654d6d657449;

    uStack_e0 = 0;

    DAT_1403ea780 = FUN_14006fe60(&local_e8);

    _Init_thread_footer(&DAT_1403ea784);

  }

  uVar25 = DAT_140303ff8;

  fVar24 = fVar23;

  if (*(char *)(puVar10 + 0xb) != '\0') {

    FUN_140071d20(DAT_1403ea758 + 1);

    fVar24 = DAT_140303fe0;

  }

  fVar4 = DAT_14039ca58;

  fVar3 = DAT_140303390;

  uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);

  uVar20 = uVar22;

  if (0 < *(int *)((longlong)puVar10 + 0x54)) {

    do {

      FUN_140071d20(DAT_1403ea758,fVar24 + fVar3,uVar25);

      uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);

      fVar24 = fVar24 + fVar4;

      uVar19 = (int)uVar20 + 1;

      uVar20 = (ulonglong)uVar19;

    } while ((int)uVar19 < *(int *)((longlong)puVar10 + 0x54));

  }

  fVar7 = DAT_14030562c;

  uVar5 = DAT_1403033ac;

  fVar4 = DAT_1403033a4;

  if (*(char *)(puVar10 + 0xc) != '\0') {

    FUN_140071d20(DAT_1403ea760,fVar24 + DAT_14030562c,DAT_1403033ac);

    fVar24 = fVar24 + fVar4;

  }

  if (*(char *)((longlong)puVar10 + 0x61) != '\0') {

    FUN_140071d20(DAT_1403ea760 + 1,fVar24 + fVar7,uVar5);

    fVar24 = fVar24 + fVar4;

  }

  if (*(char *)((longlong)puVar10 + 0x62) != '\0') {

    FUN_140071d20(DAT_1403ea760 + 2,fVar24 + fVar7,uVar5);

    fVar24 = fVar24 + fVar4;

  }

  if (*(char *)((longlong)puVar10 + 99) != '\0') {

    FUN_140071d20(DAT_1403ea760 + 3,fVar24 + fVar7,uVar5);

    fVar24 = fVar24 + fVar4;

  }

  if (0 < *(int *)((longlong)puVar10 + 0x5c)) {

    FUN_140071d20(DAT_1403ea768);

    if (1 < *(int *)((longlong)puVar10 + 0x5c)) {

      puVar13 = (undefined8 *)FUN_14008d760(&local_e8,&DAT_14039bf04);

      if (0xf < (ulonglong)puVar13[3]) {

        puVar13 = (undefined8 *)*puVar13;

      }

      uVar12 = CONCAT44(uVar26,fVar8);

      FUN_140086570(DAT_1403ede38,fVar24 + fVar3,uVar25,0,uVar12,DAT_1403d4ad8,puVar13);

      uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);

      if (0xf < local_d0) {

        if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    fVar24 = fVar24 + fVar23;

  }

  cVar9 = FUN_1400b7720(*(undefined8 *)(param_1 + 0x270));

  if (cVar9 != '\0') {

    FUN_140071d20(DAT_1403ea778);

    fVar24 = fVar24 + fVar23;

  }

  fVar3 = DAT_140303fc0;

  if (*(int *)(*(longlong *)(param_1 + 0x270) + 0x24c) == 2) {

    FUN_140071d20(DAT_1403ea780,fVar24 + DAT_140303394,uVar25);

  }

  if (*(char *)((longlong)puVar10 + 0x6c) != '\0') {

    FUN_140071d20(DAT_1403ea770);

  }

  FUN_140086570(DAT_1403ede40);

  lVar14 = *(longlong *)(param_1 + 0x270);

  if (*(int *)(lVar14 + 0x1c) == 6) {

    iVar18 = DAT_1403ea750 + 5;

  }

  else {

    if (*(int *)(lVar14 + 0x1fc) == 0) {

      FUN_140071d20(DAT_1403ea750);

      goto LAB_1400571be;

    }

    if (*(int *)(lVar14 + 0x1fc) < *(int *)(lVar14 + 0x200)) {

      FUN_14008d760(&local_e8,&DAT_14039bf04);

      FUN_140086570(DAT_1403ede38);

      if (0xf < local_d0) {

        if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      FUN_14008d760(&local_e8,&DAT_1403055e0);

      FUN_140086570(DAT_1403ede38);

      if (0xf < local_d0) {

        if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      goto LAB_1400571be;

    }

    iVar18 = DAT_1403ea750 + 1;

  }

  FUN_140071d20(iVar18);

LAB_1400571be:

  if (0 < *(int *)(puVar10 + 10)) {

    FUN_140086570(DAT_1403ede40);

    FUN_14008d760(&local_e8,&DAT_14039bf04);

    FUN_140086570(DAT_1403ede38);

    if (0xf < local_d0) {

      if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  uVar20 = uVar22;

  uVar21 = uVar22;

  if (0 < *(int *)(*(longlong *)(param_1 + 0x270) + 0x200) + -1) {

    do {

      FUN_140071000((float)(int)uVar21 + fVar23);

      uVar19 = (int)uVar20 + 1;

      uVar20 = (ulonglong)uVar19;

      uVar21 = (ulonglong)((int)uVar21 + 3);

    } while ((int)uVar19 < *(int *)(*(longlong *)(param_1 + 0x270) + 0x200) + -1);

  }

  FUN_140086570(DAT_1403ede40);

  FUN_140086570(DAT_1403ede40);

  FUN_14008d760(&local_e8,&DAT_1403055f4);

  FUN_140086570(DAT_1403ede38);

  if (0xf < local_d0) {

    if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_1400b76e0(*(undefined8 *)(param_1 + 0x270));

  FUN_14008d760(&local_e8,&DAT_14039bf04);

  FUN_140086570(DAT_1403ede38);

  if (0xf < local_d0) {

    if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  if ((*(int *)(puVar10 + 9) != -1) ||

     (fVar24 = DAT_140304028, *(int *)((longlong)puVar10 + 0x4c) != -1)) {

    FUN_140086570(DAT_1403ede40);

    if ((*(int *)(puVar10 + 9) == -1) ||

       (lVar14 = FUN_1400c7520(), *(longlong *)(lVar14 + 0x10) == 0)) {

      FUN_140086570(DAT_1403ede48);

    }

    else {

      FUN_1400c7520(*(undefined4 *)(puVar10 + 9));

      FUN_1400c7720(*(undefined4 *)(puVar10 + 9));

      FUN_140086570(DAT_1403ede48);

    }

    if ((*(int *)((longlong)puVar10 + 0x4c) == -1) ||

       (lVar14 = FUN_1400c7520(), *(longlong *)(lVar14 + 0x10) == 0)) {

      FUN_140086570(DAT_1403ede48);

      fVar24 = DAT_140304044;

    }

    else {

      FUN_1400c7520(*(undefined4 *)((longlong)puVar10 + 0x4c));

      FUN_1400c7720(*(undefined4 *)((longlong)puVar10 + 0x4c));

      FUN_140086570(DAT_1403ede48);

      fVar24 = DAT_140304044;

    }

  }

  if (puVar10[0xe] != puVar10[0xf]) {

    uVar12 = CONCAT44(uVar26,fVar8);

    FUN_140086570(DAT_1403ede40);

    fVar7 = DAT_140305670;

    uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);

    fVar24 = fVar24 + fVar4;

    lVar14 = puVar10[0xe];

    uVar20 = uVar22;

    if (puVar10[0xf] - lVar14 >> 2 != 0) {

      do {

        uVar25 = (undefined4)((ulonglong)uVar12 >> 0x20);

        iVar18 = (int)uVar22;

        if ((*(int *)(uVar20 + lVar14) == -1) ||

           (lVar14 = FUN_1400c7520(), *(longlong *)(lVar14 + 0x10) == 0)) {

          iVar17 = 0x4a;

          if (iVar18 < 5) {

            iVar17 = 0xc;

          }

          uVar12 = CONCAT44(uVar25,fVar8);

          FUN_140086570(DAT_1403ede48,(float)iVar17 + fVar23,fVar24,0,uVar12,DAT_1403d4a7c,"Unknown"

                       );

        }

        else {

          lVar14 = FUN_1400c7520(*(undefined4 *)(puVar10[0xe] + uVar20));

          uVar15 = FUN_1400c7720(*(undefined4 *)(puVar10[0xe] + uVar20));

          iVar17 = 0x4a;

          if (iVar18 < 5) {

            iVar17 = 0xc;

          }

          uVar12 = CONCAT44(uVar25,fVar8);

          FUN_140086570(DAT_1403ede48,(float)iVar17 + fVar23,fVar24,0,uVar12,

                        *(undefined4 *)(&DAT_1403ea710 + (longlong)*(int *)(lVar14 + 0x44) * 4),

                        uVar15);

        }

        uVar26 = (undefined4)((ulonglong)uVar12 >> 0x20);

        fVar24 = fVar24 + fVar3;

        if (iVar18 == 4) {

          fVar24 = fVar24 + fVar7;

        }

        uVar22 = (ulonglong)(iVar18 + 1U);

        lVar14 = puVar10[0xe];

        param_1 = local_res8;

        uVar20 = uVar20 + 4;

      } while ((ulonglong)(longlong)(int)(iVar18 + 1U) < (ulonglong)(puVar10[0xf] - lVar14 >> 2));

    }

  }

  pfVar16 = (float *)FUN_1400b4a10(*(undefined8 *)(param_1 + 0x270),&local_res8);

  fVar23 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  fVar23 = fVar23 + fVar23;

  FUN_140072fe0(CONCAT44(fVar23 * pfVar16[1] + DAT_140305648,fVar23 * *pfVar16 + _DAT_140305668));

  FUN_1400bd820(*(undefined8 *)(param_1 + 0x270));

  FUN_1400730f0();

  FUN_1400cacd0(param_1,0,0);

  lVar14 = *(longlong *)(param_1 + 0x60);

  if (*(char *)(lVar14 + 0x335) != '\0') {

    FUN_140071000();

    uVar12 = CONCAT44(uVar26,DAT_1403d4ad0);

    FUN_140071000(*(float *)(lVar14 + 0x30c) + fVar8,*(float *)(lVar14 + 0x310) + fVar8,

                  *(float *)(lVar14 + 0x314) - fVar6,*(float *)(lVar14 + 0x318) - fVar6,uVar12);

    uVar25 = (undefined4)((ulonglong)uVar12 >> 0x20);

    puVar10 = (undefined8 *)FUN_14008d760(&local_e8,&DAT_140305624);

    if (0xf < (ulonglong)puVar10[3]) {

      puVar10 = (undefined8 *)*puVar10;

    }

    FUN_140086570(DAT_1403ede38,*(float *)(lVar14 + 0x30c) + DAT_14030338c,

                  *(float *)(lVar14 + 0x310) + DAT_140303fbc,0,CONCAT44(uVar25,fVar8),DAT_1403d4ac0,

                  puVar10);

    if (0xf < local_d0) {

      if ((0xfff < local_d0 + 1) && (0x1f < (local_e8 - *(longlong *)(local_e8 - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  return;

}





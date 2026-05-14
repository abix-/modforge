// Address: 0x140098660
// Ghidra name: FUN_140098660
// ============ 0x140098660 FUN_140098660 (size=12039) ============


/* WARNING: Removing unreachable block (ram,0x0001400999d6) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140098660(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  bool bVar1;

  undefined *puVar2;

  longlong lVar3;

  byte bVar4;

  longlong lVar5;

  int *piVar6;

  int iVar7;

  longlong *plVar8;

  uint uVar9;

  int iVar10;

  char *pcVar12;

  undefined8 uVar13;

  int iVar14;

  int iVar15;

  ulonglong uVar16;

  longlong lVar17;

  uint uVar18;

  int iVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  int iVar22;

  longlong lVar23;

  longlong lVar24;

  ulonglong uVar25;

  float fVar26;

  undefined4 uVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  float fVar35;

  float fVar36;

  int local_res8;

  int local_res18;

  undefined8 in_stack_fffffffffffffe38;

  undefined4 uVar37;

  undefined8 local_198;

  undefined8 uStack_190;

  undefined *local_188;

  ulonglong uStack_180;

  longlong local_178;

  float local_170;

  longlong local_168;

  longlong local_160;

  longlong local_158;

  float local_150 [4];

  float local_140 [4];

  longlong local_130;

  longlong local_128;

  char *local_120 [4];

  char *local_100;

  char *local_f8;

  ulonglong uVar11;

  

  *(float *)(*(longlong *)(param_1 + 0x60) + 0xac4) = (float)(DAT_1403d9e68 + -0x3c);

  *(float *)(*(longlong *)(param_1 + 0x60) + 0x9f4) = (float)(DAT_1403d9e68 + -0x3c);

  if (*(longlong *)(param_1 + 0x3c0) != 0) {

    *(float *)(*(longlong *)(param_1 + 0x60) + 0x9f4) =

         *(float *)(*(longlong *)(param_1 + 0x60) + 0x9f4) + DAT_14039ca60;

  }

  *(float *)(*(longlong *)(param_1 + 0x60) + 0xb30) = (float)(DAT_1403d9e6c + -0x19);

  uVar21 = 0;

  uVar25 = uVar21;

  uVar11 = uVar21;

  if (0 < *(int *)(param_1 + 0x298)) {

    do {

      *(float *)(*(longlong *)(param_1 + 0x60) + 0x374 + uVar25) = (float)(DAT_1403d9e68 + -0x84);

      uVar9 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar9;

      uVar25 = uVar25 + 0x68;

    } while ((int)uVar9 < *(int *)(param_1 + 0x298));

  }

  fVar32 = DAT_1403033ac;

  uVar25 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffe38 >> 0x20),DAT_1403da09c);

  FUN_140071000(-DAT_1403eda00,uVar11,param_3,param_4,uVar25);

  FUN_1400d6500(param_1,DAT_1403da0ac);

  uVar9 = DAT_14039cac0;

  iVar14 = 1;

  if (1 < *(int *)(param_1 + 0x298)) {

    iVar14 = *(int *)(param_1 + 0x298);

  }

  fVar36 = DAT_140303758 / (float)iVar14;

  fVar28 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar28 * *(float *)(param_1 + 0x110),fVar28 * *(float *)(param_1 + 0x10c)))

  ;

  fVar28 = DAT_140303354;

  lVar24 = *(longlong *)(param_1 + 0x330);

  uVar11 = uVar21;

  uVar16 = uVar21;

  if (*(longlong *)(param_1 + 0x338) - lVar24 >> 3 != 0) {

    do {

      fVar34 = *(float *)(lVar24 + 8 + uVar11);

      uVar27 = (undefined4)(uVar25 >> 0x20);

      if (*(float *)(lVar24 + uVar11) == fVar34) {

        uVar25 = CONCAT44(uVar27,DAT_1403da05c);

        if (*(float *)(lVar24 + 0xc + uVar11) <= *(float *)(lVar24 + 4 + uVar11)) {

          FUN_140071000();

        }

        else {

          FUN_140071000();

        }

      }

      else {

        uVar25 = CONCAT44(uVar27,fVar34);

        FUN_140072040();

      }

      uVar18 = (int)uVar16 + 2;

      lVar24 = *(longlong *)(param_1 + 0x330);

      uVar11 = uVar11 + 0x10;

      uVar16 = (ulonglong)uVar18;

      uVar9 = DAT_14039cac0;

    } while ((ulonglong)(longlong)(int)uVar18 <

             (ulonglong)(*(longlong *)(param_1 + 0x338) - lVar24 >> 3));

  }

  uVar27 = (undefined4)(uVar25 >> 0x20);

  if (*(longlong *)(param_1 + 0x350) - *(longlong *)(param_1 + 0x348) >> 3 != 0) {

    do {

      uVar25 = uVar25 & 0xffffffff00000000;

      FUN_140072040();

      uVar27 = (undefined4)(uVar25 >> 0x20);

      uVar18 = (int)uVar21 + 2;

      uVar21 = (ulonglong)uVar18;

    } while ((ulonglong)(longlong)(int)uVar18 <

             (ulonglong)(*(longlong *)(param_1 + 0x350) - *(longlong *)(param_1 + 0x348) >> 3));

  }

  FUN_1400730f0();

  fVar34 = (float)(*(uint *)(param_1 + 0x10c) ^ uVar9) * *(float *)(param_1 + 0x114);

  uVar25 = (ulonglong)_tls_index;

  lVar24 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8);

  local_128 = lVar24;

  if ((*(int *)(lVar24 + 4) < DAT_1403edf90) && (FUN_1402c7138(&DAT_1403edf90), DAT_1403edf90 == -1)

     ) {

    local_188 = (undefined *)0xa;

    uStack_180 = 0xf;

    local_198 = (char *)s_FinishPost_1403032f8._0_8_;

    uStack_190 = (undefined *)(ulonglong)(ushort)s_FinishPost_1403032f8._8_2_;

    DAT_1403edf8c = FUN_14006fe60(&local_198);

    _Init_thread_footer(&DAT_1403edf90);

  }

  if ((*(int *)(lVar24 + 4) < DAT_1403edf98) && (FUN_1402c7138(&DAT_1403edf98), DAT_1403edf98 == -1)

     ) {

    local_188 = (undefined *)0xa;

    uStack_180 = 0xf;

    local_198 = (char *)s_GrandStand_14030c140._0_8_;

    uStack_190 = (undefined *)(ulonglong)(ushort)s_GrandStand_14030c140._8_2_;

    DAT_1403edf94 = FUN_14006fe60(&local_198);

    _Init_thread_footer(&DAT_1403edf98);

  }

  if ((*(int *)(lVar24 + 4) < DAT_1403edfa0) && (FUN_1402c7138(&DAT_1403edfa0), DAT_1403edfa0 == -1)

     ) {

    local_188 = (undefined *)0x8;

    uStack_180 = 0xf;

    local_198 = (char *)0x38676e6f6c727546;

    uStack_190 = (undefined *)0x0;

    DAT_1403edf9c = FUN_14006fe60(&local_198);

    _Init_thread_footer(&DAT_1403edfa0);

  }

  uVar13 = CONCAT44(uVar27,DAT_1403da02c);

  FUN_140071000();

  fVar30 = DAT_1403033c0;

  FUN_140071d20(DAT_1403edf94,fVar34 - DAT_1403033c0);

  if ((1 < DAT_1403eded8) && (DAT_1403d95c4 == '\0')) {

    iVar14 = *(int *)(param_1 + 0x29c);

    if (4 < *(int *)(param_1 + 0x29c)) {

      iVar14 = 0;

    }

    FUN_140071d20(iVar14 + DAT_1403edf9c,fVar34 + DAT_1403033b0);

    if (*(int *)(param_1 + 0x29c) == 2) {

      FUN_140071d20(DAT_1403edf9c + 5,

                    *(float *)(param_1 + 0x2f8) * *(float *)(param_1 + 0x114) * DAT_14039ca34 +

                    fVar34);

    }

  }

  if (1 < *(int *)(param_1 + 0x250)) {

    uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),DAT_1403da02c);

    FUN_140071000(*(float *)(param_1 + 0x114) * *(float *)(param_1 + 0x2f8) + fVar34);

    FUN_140071d20(DAT_1403edf8c,*(float *)(param_1 + 0x2f8) * *(float *)(param_1 + 0x114) + fVar34);

    FUN_140071d20(DAT_1403edf94,

                  (*(float *)(param_1 + 0x2f8) * *(float *)(param_1 + 0x114) + fVar34) - fVar30);

  }

  fVar35 = DAT_14039ca44;

  fVar30 = DAT_14030339c;

  uVar27 = (undefined4)((ulonglong)uVar13 >> 0x20);

  if (1 < *(int *)(param_1 + 0x250)) {

    fVar31 = fVar34 + DAT_1403033c8;

    for (fVar29 = (*(float *)(param_1 + 0x2f8) - DAT_14030339c) * *(float *)(param_1 + 0x114) +

                  fVar34; uVar27 = (undefined4)((ulonglong)uVar13 >> 0x20), fVar31 < fVar29;

        fVar29 = fVar29 - *(float *)(param_1 + 0x114) * fVar30) {

      uVar13 = CONCAT44(uVar27,DAT_1403da02c);

      FUN_140071000();

    }

  }

  fVar30 = fVar34 - DAT_14030b638;

  if (*(char *)(*(longlong *)(param_1 + 0x60) + 0xa85) == '\0') {

    fVar30 = fVar30 + _DAT_14030c2a0;

  }

  uVar11 = CONCAT44(uVar27,DAT_1403da0b0);

  FUN_140071000();

  fVar29 = DAT_140304c10;

  if (fVar30 < (float)(DAT_14030b680 + DAT_1403eda00)) {

    do {

      uVar11 = CONCAT44((int)(uVar11 >> 0x20),DAT_1403da0b0);

      FUN_140071000();

      fVar30 = fVar30 + fVar29;

    } while (fVar30 < (float)(DAT_14030b680 + DAT_1403eda00));

  }

  *(float *)(*(longlong *)(param_1 + 0x60) + 0xa5c) =

       ((float)DAT_1403ed994 + fVar34) - _DAT_14030c284;

  fVar30 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar30 * *(float *)(param_1 + 0x110),fVar30 * *(float *)(param_1 + 0x10c)))

  ;

  uVar21 = 0;

  if (0 < *(int *)(param_1 + 0x298)) {

    lVar24 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8);

    uVar25 = uVar21;

    fVar30 = 0.0;

    do {

      uVar16 = 0;

      FUN_1400bd820(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar25));

      if (*(longlong *)(param_1 + 0x378) != *(longlong *)(param_1 + 0x380)) {

        FUN_1400bd820(*(undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar25));

      }

      fVar29 = fVar36 * fVar28 + fVar30;

      uVar20 = uVar16;

      if (*(longlong *)(param_1 + 0x368) - *(longlong *)(param_1 + 0x360) >> 3 != 0) {

        do {

          if ((*(int *)(lVar24 + 4) < DAT_1403edfa8) &&

             (FUN_1402c7138(&DAT_1403edfa8), DAT_1403edfa8 == -1)) {

            local_188 = (undefined *)0xc;

            uStack_180 = 0xf;

            local_198 = (char *)s_SpelunkyRock_14030c150._0_8_;

            uStack_190 = (undefined *)(ulonglong)(uint)s_SpelunkyRock_14030c150._8_4_;

            DAT_1403edfa4 = FUN_14006fe60(&local_198);

            _Init_thread_footer(&DAT_1403edfa8);

          }

          fVar31 = *(float *)(*(longlong *)(*(longlong *)(param_1 + 0x360) + uVar16) + 0x10);

          if ((fVar30 < fVar31) && (fVar31 <= fVar29)) {

            uVar11 = uVar11 & 0xffffffff00000000;

            FUN_140071ed0(DAT_1403edfa4);

          }

          uVar9 = (int)uVar20 + 1;

          uVar20 = (ulonglong)uVar9;

          uVar16 = uVar16 + 8;

        } while ((ulonglong)(longlong)(int)uVar9 <

                 (ulonglong)(*(longlong *)(param_1 + 0x368) - *(longlong *)(param_1 + 0x360) >> 3));

      }

      uVar9 = (int)uVar21 + 1;

      uVar21 = (ulonglong)uVar9;

      uVar25 = uVar25 + 8;

      fVar30 = fVar29;

    } while ((int)uVar9 < *(int *)(param_1 + 0x298));

    uVar25 = (ulonglong)_tls_index;

  }

  if (*(char *)(param_1 + 600) == '\0') {

    if (*(longlong *)(param_1 + 0x248) != 0) {

      FUN_1400c8e70();

      FUN_1400c9290(*(undefined8 *)(param_1 + 0x248));

    }

    if (DAT_1403f3110 != 0) {

      FUN_1400c8e70();

      FUN_1400c9290(DAT_1403f3110);

    }

    FUN_1400d2090(param_1);

  }

  FUN_1400730f0();

  fVar30 = DAT_14030c264;

  uVar27 = DAT_14030c260;

  fVar28 = DAT_14030c248;

  uVar21 = _UNK_1403040d8;

  puVar2 = _DAT_1403040d0;

  if (*(char *)(param_1 + 600) != '\0') {

    return;

  }

  if ((DAT_1403d95c4 == '\0') && (local_res18 = 0, 0 < *(int *)(param_1 + 0x298))) {

    local_170 = (fVar36 - DAT_140303fbc) * DAT_14039ca34;

    local_130 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8);

    lVar24 = 4;

    local_158 = 4;

    local_178 = 0;

    local_168 = 0;

    fVar29 = DAT_1403033ac;

    do {

      lVar3 = local_130;

      lVar23 = local_168;

      lVar17 = local_178;

      fVar32 = ((float)(local_res18 + 1) * fVar36 + fVar29) - local_170;

      lVar5 = *(longlong *)(param_1 + 0x280);

      if (*(longlong *)(lVar5 + 0x60 + local_178) != 0) {

        fVar32 = fVar32 + DAT_14030c29c;

      }

      pcVar12 = (char *)(lVar5 + 0x30 + local_178);

      if (0xf < *(ulonglong *)(lVar5 + 0x48 + local_178)) {

        pcVar12 = *(char **)pcVar12;

      }

      fVar31 = *(float *)(&DAT_1403edf40 +

                         (longlong)

                         *(int *)(*(longlong *)(local_168 + *(longlong *)(param_1 + 0x130)) + 0x228)

                         * 4);

      uVar11 = CONCAT44((int)(uVar11 >> 0x20),fVar35);

      FUN_140086570(DAT_1403ede48);

      if (*(longlong *)(*(longlong *)(param_1 + 0x280) + 0x60 + lVar17) != 0) {

        pcVar12 = (char *)(*(longlong *)(param_1 + 0x280) + 0x50 + lVar17);

        if (0xf < *(ulonglong *)(pcVar12 + 0x18)) {

          pcVar12 = *(char **)pcVar12;

        }

        fVar31 = *(float *)(&DAT_1403edf40 +

                           (longlong)

                           *(int *)(*(longlong *)(lVar23 + *(longlong *)(param_1 + 0x130)) + 0x228)

                           * 4);

        uVar11 = CONCAT44((int)(uVar11 >> 0x20),fVar35);

        FUN_140086570(DAT_1403ede48,*(longlong *)(param_1 + 0x130),fVar32 + DAT_14039ca58,1,uVar11,

                      fVar31,pcVar12);

      }

      if (1 < DAT_1403eded8) {

        lVar5 = *(longlong *)(param_1 + 0x280);

        if (*(int *)(lVar5 + 8 + lVar17) == -1) {

          iVar14 = 3;

          if (*(int *)(param_1 + 0x3d4) < 5) {

            iVar14 = 1;

          }

          if ((*(int *)(param_1 + 700) < iVar14) && (*(int *)(param_1 + 0x250) == 3)) {

            FUN_14008d760(&local_198,"%d-%d",*(undefined4 *)(lVar5 + lVar17),

                          *(undefined4 *)(lVar5 + 4 + lVar17),uVar11,fVar31,pcVar12);

            uVar37 = (undefined4)(uVar11 >> 0x20);

            pcVar12 = (char *)&local_198;

            if (0xf < uStack_180) {

              pcVar12 = local_198;

            }

            FUN_140086450(DAT_1403ede18,pcVar12);

            pcVar12 = (char *)&local_198;

            if (0xf < uStack_180) {

              pcVar12 = local_198;

            }

            uVar11 = CONCAT44(uVar37,DAT_14039ca34);

            fVar31 = DAT_1403da01c;

            FUN_140086570(DAT_1403ede18);

            if (0xf < uStack_180) {

              if ((0xfff < uStack_180 + 1) &&

                 ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

          }

        }

        if ((1 < DAT_1403eded8) &&

           (((*(int *)(param_1 + 0x250) == 3 || (*(int *)(param_1 + 0x250) == 4)) &&

            (*(int *)(*(longlong *)(lVar23 + *(longlong *)(param_1 + 0x130)) + 0x1f8) != -1)))) {

          iVar14 = 0;

          lVar5 = FUN_1400c7520();

          lVar17 = local_178;

          if (0 < *(int *)(lVar5 + 0x54)) {

            do {

              if ((*(int *)(lVar3 + lVar24) < DAT_1403edfb0) &&

                 (FUN_1402c7138(&DAT_1403edfb0), DAT_1403edfb0 == -1)) {

                local_188 = (undefined *)0xa;

                uStack_180 = 0xf;

                local_198 = (char *)s_MiniTrophy_14030a1f8._0_8_;

                uStack_190 = (undefined *)(ulonglong)(ushort)s_MiniTrophy_14030a1f8._8_2_;

                DAT_1403edfac = FUN_14006fe60(&local_198);

                _Init_thread_footer(&DAT_1403edfb0);

              }

              FUN_140071d20(DAT_1403edfac);

              iVar14 = iVar14 + 1;

              lVar5 = FUN_1400c7520(*(undefined4 *)

                                     (*(longlong *)(lVar23 + *(longlong *)(param_1 + 0x130)) + 0x1f8

                                     ));

              lVar17 = local_178;

              fVar29 = DAT_1403033ac;

            } while (iVar14 < *(int *)(lVar5 + 0x54));

          }

        }

      }

      piVar6 = (int *)&DAT_1403d9530;

      if (0xf < DAT_1403d9548) {

        piVar6 = DAT_1403d9530;

      }

      if (((DAT_1403d9540 == 6) && (*piVar6 == 0x65636152)) &&

         (((short)piVar6[1] == 0x4941 && (*(int *)(param_1 + 0x250) - 3U < 6)))) {

        uVar37 = (undefined4)(uVar11 >> 0x20);

        FUN_140071000();

        FUN_1400c6180();

        FUN_140071000();

        FUN_1400c6180();

        uVar11 = CONCAT44(uVar37,DAT_1403da070);

        FUN_140071000();

        iVar14 = 0x14;

        do {

          uVar18 = 1 << ((byte)iVar14 & 0x1f);

          uVar9 = *(uint *)(*(longlong *)(param_1 + 0x280) + 0x18 + lVar17);

          if ((uVar18 & (uVar9 | *(uint *)(*(longlong *)(lVar23 + *(longlong *)(param_1 + 0x130)) +

                                          600))) != 0) {

            fVar31 = DAT_1403da020;

            if ((uVar18 & uVar9) != 0) {

              fVar31 = DAT_1403da02c;

            }

            pcVar12 = (char *)FUN_14008d760(&local_198,&DAT_14030c160);

            if (0xf < *(ulonglong *)(pcVar12 + 0x18)) {

              pcVar12 = *(char **)pcVar12;

            }

            uVar11 = CONCAT44((int)(uVar11 >> 0x20),uVar27);

            FUN_140086570(DAT_1403ede18);

            lVar17 = local_178;

            if (0xf < uStack_180) {

              if ((0xfff < uStack_180 + 1) &&

                 ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

              lVar17 = local_178;

            }

          }

          iVar14 = iVar14 + -1;

        } while (-1 < iVar14);

      }

      iVar14 = *(int *)(*(longlong *)(param_1 + 0x280) + 0xc + lVar17);

      if ((-1 < iVar14) && (iVar14 < 3)) {

        local_150[0] = DAT_1403da070;

        local_150[1] = (float)DAT_1403da054;

        local_150[2] = DAT_1403da018;

        local_198 = "1st";

        uStack_190 = &DAT_14030332c;

        local_188 = &DAT_140303330;

        pcVar12 = (char *)(&local_198)[iVar14];

        fVar31 = local_150[iVar14];

        uVar11 = CONCAT44((int)(uVar11 >> 0x20),fVar35);

        FUN_140086570(DAT_1403ede20,

                      *(float *)(param_1 + 0x2f8) * *(float *)(param_1 + 0x114) + fVar34 +

                      DAT_140303398);

      }

      if (((*(char *)(param_1 + 0x2e5) == '\0') && (DAT_1403d95c4 == '\0')) &&

         (local_res8 = 0, 0 < *(int *)(param_1 + 0x298))) {

        local_160 = 0;

        do {

          lVar5 = local_160;

          iVar14 = FUN_1400c6dd0(*(int *)(param_1 + 0x254) + -0x3c,0xf);

          if (*(int *)(param_1 + 0x250) == 3) {

            lVar17 = local_178;

            lVar23 = local_168;

            lVar24 = local_158;

            if (iVar14 < local_res8) break;

            if (((-1 < iVar14) &&

                ((ulonglong)(longlong)iVar14 <

                 (ulonglong)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3)))

               && (*(int *)(param_1 + 0x254) == (*(int *)(param_1 + 0x254) / 0xf) * 0xf)) {

              local_188 = puVar2;

              uStack_180 = uVar21;

              local_198 = (char *)s_WinArrowAppear_14030c168._0_8_;

              uStack_190 = (undefined *)

                           (ulonglong)

                           CONCAT24(s_WinArrowAppear_14030c168._12_2_,

                                    s_WinArrowAppear_14030c168._8_4_);

              uVar11 = uVar11 & 0xffffffffffffff00;

              FUN_140040ca0(&local_198,100,0,(float)iVar14 * fVar28 + fVar30,uVar11,fVar31,pcVar12);

              if (0xf < uStack_180) {

                if ((0xfff < uStack_180 + 1) &&

                   ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

                FUN_1402c7088();

              }

            }

          }

          iVar7 = *(int *)(*(longlong *)(param_1 + 0x280) + 8 + lVar5);

          iVar15 = 3;

          if (*(int *)(param_1 + 0x3d4) < 5) {

            iVar15 = 1;

          }

          if ((*(int *)(param_1 + 700) != iVar15) || (iVar7 != -1)) {

            iVar10 = (int)(*(float *)(*(longlong *)(param_1 + 0x60) + 0x374) + DAT_14030339c);

            iVar19 = DAT_1403d9e68 + -0x22;

            iVar15 = *(int *)(param_1 + 0x250);

            if (iVar15 == 7) {

              iVar22 = 0;

              if (0 < *(int *)(param_1 + 0x254)) {

                iVar22 = *(int *)(param_1 + 0x254);

              }

              iVar22 = iVar10 + iVar22 * 4;

              iVar10 = iVar19;

              if (iVar22 < iVar19) {

                iVar10 = iVar22;

              }

            }

            else if (7 < iVar15) {

              iVar10 = iVar19;

            }

            fVar26 = (fVar36 - DAT_1403033a8) * DAT_14039ca34;

            local_140[0] = DAT_1403da070;

            local_140[1] = (float)DAT_1403da054;

            local_140[2] = DAT_1403da02c;

            fVar32 = DAT_1403da02c;

            if (iVar7 == -1) {

              fVar33 = DAT_1403da020;

              if (*(int *)(param_1 + 0xd8) == local_res8 + 8) {

                fVar33 = DAT_1403da024;

              }

              if ((*(int *)(param_1 + 0xd8) != local_res8 + 8) &&

                 ((iVar14 + 1) % *(int *)(param_1 + 0x298) != local_res8)) {

                iVar10 = iVar10 + 1;

              }

            }

            else {

              fVar33 = local_140[iVar7];

              if (iVar7 == 2) {

                fVar32 = DAT_1403da018;

              }

            }

            if (((iVar15 == 3) || (0xb < iVar15)) || (iVar7 != -1)) {

              uVar37 = (undefined4)(uVar11 >> 0x20);

              FUN_140071000();

              fVar31 = (float)((int)((float)local_res8 * fVar36 + fVar29 + fVar26 + fVar35) + 7);

              pcVar12 = (char *)(ulonglong)(uint)fVar33;

              uVar11 = CONCAT44(uVar37,(float)(iVar10 + -3));

              FUN_140071810();

              fVar29 = DAT_1403033ac;

            }

            local_120[0] = "Win";

            local_120[1] = "Place";

            local_120[2] = "Show";

            local_120[3] = "Win?";

            local_100 = "Place?";

            local_f8 = "Show?";

            if (iVar7 == -1) {

              if ((*(int *)(param_1 + 0x250) != 3) && (*(int *)(param_1 + 0x250) < 0xc))

              goto LAB_140099b47;

              pcVar12 = local_120[(longlong)*(int *)(param_1 + 700) + 3];

            }

            else {

              pcVar12 = local_120[iVar7];

            }

            uVar11 = CONCAT44((int)(uVar11 >> 0x20),fVar35);

            FUN_140086570(DAT_1403ede18);

            fVar31 = fVar32;

          }

LAB_140099b47:

          local_res8 = local_res8 + 1;

          local_160 = local_160 + 0x70;

          lVar17 = local_178;

          lVar23 = local_168;

          lVar24 = local_158;

        } while (local_res8 < *(int *)(param_1 + 0x298));

      }

      local_res18 = local_res18 + 1;

      local_168 = lVar23 + 8;

      local_178 = lVar17 + 0x70;

      fVar32 = DAT_1403033ac;

    } while (local_res18 < *(int *)(param_1 + 0x298));

  }

  lVar24 = local_128;

  iVar14 = DAT_1403d9e6c;

  fVar28 = DAT_140303750;

  if (((*(int *)(param_1 + 0x250) < 10) && (*(char *)(param_1 + 0x2e5) == '\0')) &&

     (DAT_1403d95c4 == '\0')) {

    bVar1 = false;

    iVar10 = 0xa0;

    iVar7 = 0xa0;

    iVar15 = DAT_1403d9e6c + -0x19;

    if ((*(int *)(local_128 + 4) < DAT_1403edfc0) &&

       (FUN_1402c7138(&DAT_1403edfc0), DAT_1403edfc0 == -1)) {

      _Init_thread_footer(&DAT_1403edfc0);

    }

    if ((*(int *)(lVar24 + 4) < DAT_1403edfd0) &&

       (FUN_1402c7138(&DAT_1403edfd0), DAT_1403edfd0 == -1)) {

      _Init_thread_footer(&DAT_1403edfd0);

    }

    if (*(int *)(param_1 + 0x250) == 8) {

      fVar34 = DAT_1403edfd4;

      if (DAT_1403edfd8 < 1) {

        if (((*(int *)(param_1 + 0xd8) == -1) && (DAT_1403ed960 != 0)) &&

           (*(char *)(param_1 + 0x2e4) == '\0')) {

          if (DAT_1403edfc4 == 0) {

            DAT_1403edfc4 = 3;

            bVar4 = FUN_1400c66c0();

            _DAT_1403edfc8 = CONCAT44(DAT_1403edfcc,(float)(int)((bVar4 ^ 1) * 2 + -1));

            fVar34 = fVar35;

            DAT_1403edfd4 = fVar35;

          }

          else {

            DAT_1403edfc4 = DAT_1403edfc4 + (DAT_14030374c <= DAT_1403edfd4) + 1;

            fVar34 = DAT_1403edfd4 + DAT_14039ca24;

            DAT_1403edfd4 = fVar34;

            if (DAT_14030562c <= fVar34) {

              *(undefined1 *)(param_1 + 0x2e5) = 1;

              _DAT_1403edfb8 = 0;

              DAT_1403edfc4 = 0;

            }

          }

        }

      }

      else {

        DAT_1403edfd8 = DAT_1403edfd8 + -1;

      }

      iVar19 = DAT_1403edfc4;

      fVar30 = DAT_1403edfcc;

      fVar31 = DAT_1403edfcc - DAT_1403edfbc;

      fVar26 = DAT_1403edfc8 - DAT_1403edfb8;

      fVar29 = fVar26 * fVar26 + fVar31 * fVar31;

      if (fVar29 < 0.0) {

        fVar29 = (float)FUN_1402cdfa0();

      }

      else {

        fVar29 = SQRT(fVar29);

      }

      fVar33 = DAT_14030374c;

      if (DAT_14039c9f0 <= fVar29) {

        fVar31 = fVar31 * (fVar35 / fVar29);

        fVar26 = fVar26 * (fVar35 / fVar29);

      }

      else {

        fVar29 = 0.0;

      }

      if (fVar34 < fVar29) {

        _DAT_1403edfb8 = CONCAT44(DAT_1403edfbc + fVar34 * fVar31,DAT_1403edfb8 + fVar34 * fVar26);

      }

      else {

        _DAT_1403edfb8 = CONCAT44(fVar30,(int)_DAT_1403edfc8);

        if (iVar19 == 0) goto LAB_140099f1f;

        DAT_1403edfc4 = iVar19 + -1;

        uVar27 = FUN_1400c6940(DAT_140304c9c - fVar34);

        iVar19 = 1;

        if (0.0 < DAT_1403edfc8) {

          iVar19 = -1;

        }

        fVar34 = (float)FUN_1400c6940(0xffffffff,DAT_1403edfd4 + fVar28);

        _DAT_1403edfc8 = CONCAT44(uVar27,fVar34 * (float)iVar19);

        if (DAT_1403edfc4 == 0) {

          DAT_1403edfd8 = (int)((DAT_1403edfd4 - fVar35) * DAT_14039ca58);

        }

      }

    }

    else {

      _DAT_1403edfb8 = 0;

      DAT_1403edfc4 = 0;

LAB_140099f1f:

      _DAT_1403edfc8 = 0;

      fVar33 = DAT_14030374c;

    }

    uVar25 = _UNK_140304098;

    puVar2 = _DAT_140304090;

    uVar21 = 0;

    if (*(char *)(param_1 + 0x2a5) == '\0') {

      if (1 < *(int *)(param_1 + 0x3d4)) {

        if (((*(char *)(param_1 + 0x2e4) == '\0') && (DAT_1403eded8 < 3)) &&

           (uVar16 = uVar21, 0 < *(int *)(param_1 + 0x298))) {

          do {

            if ((*(int *)(*(longlong *)(param_1 + 0x280) + 8 + uVar21) == 0) &&

               (600 < *(int *)(*(longlong *)(param_1 + 0x280) + 0x14 + uVar21))) {

              FUN_14003f6f0();

              local_188 = puVar2;

              uStack_180 = uVar25;

              local_198 = (char *)0x6563615265736f4c;

              uStack_190 = (undefined *)0x0;

              uVar11 = uVar11 & 0xffffffffffffff00;

              FUN_140040ca0(&local_198,100,0);

              if (0xf < uStack_180) {

                FUN_140028310(&local_198,local_198);

              }

              *(undefined1 *)(param_1 + 0x2e4) = 1;

            }

            uVar9 = (int)uVar16 + 1;

            uVar21 = uVar21 + 0x70;

            uVar16 = (ulonglong)uVar9;

          } while ((int)uVar9 < *(int *)(param_1 + 0x298));

        }

        uVar27 = (undefined4)(uVar11 >> 0x20);

        if ((*(int *)(param_1 + 0x250) == 8) &&

           ((*(int *)(param_1 + 0xd8) == 0x1b || (*(char *)(param_1 + 0x2e4) != '\0')))) {

          bVar1 = true;

        }

        else {

          bVar1 = false;

        }

        iVar14 = *(int *)(param_1 + 0x2e8);

        if ((*(int *)(param_1 + 700) < 1) || (iVar14 < 1)) {

          if ((*(int *)(param_1 + 700) == 0) && (iVar14 < 0x1a)) {

            iVar14 = 0x1a;

            goto LAB_14009a1bb;

          }

        }

        else {

          iVar14 = iVar14 + -2;

LAB_14009a1bb:

          *(int *)(param_1 + 0x2e8) = iVar14;

        }

        iVar15 = iVar15 + iVar14;

        if ((*(int *)(param_1 + 0x250) - 8U < 2) && (*(int *)(param_1 + 0xd8) == 0x1b)) {

          iVar15 = iVar15 + -1;

        }

        else if (*(int *)(param_1 + 0x250) == 9) {

          iVar14 = *(int *)(param_1 + 0x254);

          if (iVar14 < 0x259) {

            uVar9 = iVar14 / 0xf & 0x80000003;

            if ((int)uVar9 < 0) {

              uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;

            }

            if (uVar9 == 3) {

              uVar9 = 1;

            }

            iVar15 = iVar15 - uVar9;

          }

          else {

            iVar15 = iVar15 + iVar14 * 4 + -0x960;

          }

        }

        FUN_140072ed0(DAT_1403edfb8 + DAT_140303758,(float)iVar15 + DAT_1403edfbc);

        if ((((bVar1) && (*(char *)(param_1 + 0x2e4) != '\0')) && (299 < DAT_1403edfb4)) &&

           ((DAT_1403edfb4 % 0x1e < 0xf && (*(int *)(param_1 + 0x3dc) < 2)))) {

          FUN_140071000();

          *(undefined4 *)(param_1 + 0x3dc) = 1;

        }

        uVar11 = CONCAT44(uVar27,DAT_1403da02c);

        FUN_140071000();

        if (0 < *(int *)(param_1 + 700)) {

          FUN_14008d760(&local_198,"odds %d-%d",*(undefined4 *)(param_1 + 0x2d4),

                        *(undefined4 *)(param_1 + 0x2d8),uVar11);

          FUN_140086570(DAT_1403ede28);

          if (0xf < uStack_180) {

            if ((0xfff < uStack_180 + 1) &&

               ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          FUN_14008d760(&local_198,"prize $%d");

          uVar11 = (ulonglong)(uint)fVar35;

          FUN_140086570(DAT_1403ede28);

          if (0xf < uStack_180) {

            if ((0xfff < uStack_180 + 1) &&

               ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        FUN_1400730f0();

      }

    }

    else {

      iVar19 = *(int *)(param_1 + 0x250);

      if ((iVar19 == 8) &&

         ((*(int *)(param_1 + 0xd8) == 0x1b || (*(char *)(param_1 + 0x2e4) != '\0')))) {

        bVar1 = true;

      }

      iVar22 = (int)(((float)*(int *)(param_1 + 0x2ac) * fVar36 + fVar32 + fVar36 * DAT_14039ca34) -

                    DAT_1403033a4);

      iVar7 = DAT_1403d9e68 + -0x28;

      if (iVar19 != 4) {

        if (iVar19 == 7) {

          uVar25 = (ulonglong)*(uint *)(param_1 + 0x254);

          if ((int)*(uint *)(param_1 + 0x254) < 0) {

            uVar25 = uVar21;

          }

          iVar7 = iVar7 + (int)uVar25 * -4;

          if (iVar7 < 0xa0) {

            iVar7 = 0xa0;

          }

          iVar22 = (int)uVar25 * 4 + iVar22;

          if (iVar15 < iVar22) {

            iVar22 = iVar15;

          }

        }

        else {

          iVar22 = iVar15;

          iVar7 = iVar10;

          if (iVar19 - 8U < 2) {

            if (*(int *)(param_1 + 0xd8) == 0x1b) {

              iVar22 = iVar14 + -0x1a;

            }

            else if (iVar19 == 9) {

              iVar14 = *(int *)(param_1 + 0x254);

              if (iVar14 < 0x259) {

                uVar9 = iVar14 / 0xf & 0x80000003;

                if ((int)uVar9 < 0) {

                  uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;

                }

                if (uVar9 == 3) {

                  uVar9 = 1;

                }

                iVar22 = iVar15 - uVar9;

              }

              else {

                iVar22 = iVar15 + iVar14 * 4 + -0x960;

              }

            }

          }

        }

      }

      iVar15 = iVar22;

      uVar11 = (ulonglong)(*(int *)(param_1 + 0x2a0) == 6);

      FUN_140063b50(*(undefined8 *)(param_1 + 0x278),(float)iVar7 + DAT_1403edfb8,

                    (float)iVar15 + DAT_1403edfbc,*(undefined4 *)(param_1 + 0x2e0),uVar11);

    }

    if (((*(int *)(param_1 + 0x250) != 3) || (*(int *)(param_1 + 0xd8) != 0x1b)) && (!bVar1)) {

      DAT_1403edfb4 = 0;

      goto LAB_14009a576;

    }

    uVar25 = (ulonglong)_tls_index;

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8) + 4) <

         DAT_1403edfe0) && (FUN_1402c7138(&DAT_1403edfe0), DAT_1403edfe0 == -1)) {

      uStack_190 = (undefined *)0x0;

      local_188 = (undefined *)0x4;

      uStack_180 = 0xf;

      local_198 = (char *)0x72616554;

      _DAT_1403edfdc = FUN_14006fe60(&local_198);

      _Init_thread_footer(&DAT_1403edfe0);

    }

    iVar14 = (DAT_1403edfb4 / 0xf) % 5 + -1;

    if (-1 < iVar14) {

      FUN_140071d20(iVar14 + _DAT_1403edfdc,((float)iVar7 + DAT_1403edfb8) - fVar33,

                    (float)iVar15 + DAT_1403edfbc);

    }

    DAT_1403edfb4 = DAT_1403edfb4 + 1;

  }

  else {

LAB_14009a576:

    uVar25 = (ulonglong)_tls_index;

  }

  if (((*(char *)(param_1 + 0x259) != '\0') || (*(char *)(param_1 + 0x2a5) != '\0')) ||

     ((iVar14 = *(int *)(param_1 + 0x250), iVar14 != 2 &&

      (((iVar14 != 3 && (iVar14 != 7)) && (iVar14 < 0xc)))))) goto LAB_14009ac9a;

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8) + 4) < DAT_1403edfe8

      ) && (FUN_1402c7138(&DAT_1403edfe8), DAT_1403edfe8 == -1)) {

    uStack_190 = (undefined *)0x0;

    local_188 = (undefined *)0x5;

    uStack_180 = 0xf;

    local_198 = (char *)(ulonglong)CONCAT14(s_Booth_14030c1c4[4],s_Booth_14030c1c4._0_4_);

    DAT_1403edfe4 = FUN_14006fe60(&local_198);

    _Init_thread_footer(&DAT_1403edfe8);

  }

  iVar14 = *(int *)(param_1 + 0x268);

  iVar15 = DAT_1403d9e68 + -0x50;

  iVar7 = *(int *)(param_1 + 0x250);

  if (iVar7 == 2) {

LAB_14009a670:

    iVar7 = (0x28 - *(int *)(param_1 + 0x254)) * 2;

    iVar10 = 0;

    if (0 < iVar7) {

      iVar10 = iVar7;

    }

  }

  else if (iVar7 == 3) {

    iVar10 = 0;

    if (1 < DAT_1403eded8) goto LAB_14009a670;

  }

  else {

    iVar10 = 0;

    if (iVar7 == 7) {

      iVar7 = *(int *)(param_1 + 0x254) * 4;

      iVar10 = 0x78;

      if (iVar7 < 0x78) {

        iVar10 = iVar7;

      }

    }

  }

  FUN_140072ed0();

  iVar14 = iVar14 * 2;

  FUN_140071d20(DAT_1403edfe4 + 1 + iVar14);

  FUN_1400730f0();

  uVar9 = DAT_14039cac0;

  fVar32 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar32 * *(float *)(param_1 + 0x110) + 0.0,

                         fVar32 * *(float *)(param_1 + 0x10c) + (float)iVar10));

  if (*(longlong *)(param_1 + 0x3a8) != **(longlong **)(param_1 + 0x130)) {

    FUN_1400bd820();

  }

  FUN_1400730f0();

  FUN_140072ed0();

  FUN_140071d20(DAT_1403edfe4 + iVar14);

  FUN_1400730f0();

  if ((0 < *(int *)(param_1 + 0x3d4)) && (0 < *(int *)(param_1 + 0x298))) {

    FUN_140072ed0();

    iVar14 = *(int *)(param_1 + 0x2c0);

    iVar7 = *(int *)(param_1 + 0x2c4);

    FUN_140086570(DAT_1403ede40);

    FUN_14008d760(&local_198,&DAT_140307a38);

    uVar11 = (ulonglong)(uint)fVar35;

    FUN_140086570(DAT_1403ede20);

    if (0xf < uStack_180) {

      if ((0xfff < uStack_180 + 1) &&

         ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (*(int *)(param_1 + 0x250) == 3) {

      lVar24 = *(longlong *)(param_1 + 0x60);

      fVar34 = *(float *)(lVar24 + 0xac4) - (float)iVar15;

      fVar32 = *(float *)(lVar24 + 0xac8);

      FUN_140071000();

      fVar36 = DAT_14039ca34;

      FUN_140071810();

      uVar11 = (ulonglong)(uint)(fVar34 + *(float *)(lVar24 + 0xacc));

      FUN_140071810();

      uVar25 = (ulonglong)_tls_index;

      if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8) + 4) <

           DAT_1403edff0) && (FUN_1402c7138(&DAT_1403edff0), DAT_1403edff0 == -1)) {

        local_188 = (undefined *)0x8;

        uStack_180 = 0xf;

        local_198 = (char *)0x7465426573696152;

        uStack_190 = (undefined *)0x0;

        DAT_1403edfec = FUN_14006fe60(&local_198);

        _Init_thread_footer(&DAT_1403edff0);

      }

      if (((iVar14 == iVar7) || (*(int *)(param_1 + 0xdc) == 0x1a)) ||

         (*(int *)(param_1 + 0x2c0) == *(int *)(DAT_1403fb0d8 + 0x308))) {

        uVar9 = 0;

      }

      else {

        uVar9 = *(int *)(param_1 + 0x254) / 0xf & 0x80000001;

        if ((int)uVar9 < 0) {

          uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

        }

      }

      FUN_140071d20(DAT_1403edfec + uVar9,*(float *)(lVar24 + 0xacc) * fVar36 + fVar34,

                    *(float *)(lVar24 + 0xad0) * fVar36 + (fVar32 - fVar28));

      uVar9 = DAT_14039cac0;

    }

    FUN_1400730f0();

  }

  fVar32 = (float)(*(uint *)(param_1 + 0x114) ^ uVar9);

  FUN_140072fe0(CONCAT44(fVar32 * *(float *)(param_1 + 0x110) + 0.0,

                         fVar32 * *(float *)(param_1 + 0x10c) + (float)iVar10));

  if (*(longlong *)(param_1 + 0x3c0) != 0) {

    uStack_190 = (undefined *)0x0;

    local_188 = _DAT_14030c2c0;

    uStack_180 = _UNK_14030c2c8;

    local_198 = (char *)0x2e;

    FUN_14009c0d0(param_1 + 0x210,1);

    if (0xf < uStack_180) {

      if ((0xfff < uStack_180 + 1) &&

         ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  FUN_1400d2090(param_1);

  lVar24 = *(longlong *)(param_1 + 0x218);

  lVar5 = *(longlong *)(param_1 + 0x210);

  if (lVar5 != lVar24) {

    do {

      FUN_140027900(lVar5);

      lVar5 = lVar5 + 0x20;

    } while (lVar5 != lVar24);

    *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)(param_1 + 0x210);

  }

  FUN_1400730f0();

LAB_14009ac9a:

  if (*(int *)(param_1 + 0x250) == 9) {

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8) + 4) <

         DAT_1403edff8) && (FUN_1402c7138(&DAT_1403edff8), DAT_1403edff8 == -1)) {

      local_188 = (undefined *)0xd;

      uStack_180 = 0xf;

      local_198 = (char *)s_WinningTicket_14030c208._0_8_;

      uStack_190 = (undefined *)

                   (ulonglong)

                   CONCAT14(s_WinningTicket_14030c208[0xc],s_WinningTicket_14030c208._8_4_);

      DAT_1403edff4 = FUN_14006fe60(&local_198);

      _Init_thread_footer(&DAT_1403edff8);

    }

    uVar9 = *(int *)(param_1 + 0x254) / 0xf & 0x80000001;

    if ((int)uVar9 < 0) {

      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

    }

    FUN_1400c5c30(*(int *)(param_1 + 0x254) * -2 + 0xb3,0x9d);

    FUN_140071d20(DAT_1403edff4 + uVar9);

    FUN_1400c5c30(*(int *)(param_1 + 0x254) * -2 + 0xb3,0x9d);

    FUN_140071d20(DAT_1403edff4 + uVar9);

  }

  if ((*(int *)(param_1 + 0x250) < 2) || (*(char *)(param_1 + 0x259) != '\0')) {

    uVar13 = 0;

  }

  else {

    uVar13 = 1;

  }

  FUN_1400cacd0(param_1,uVar13,0);

  if ((0 < *(int *)(param_1 + 800)) && (DAT_1403d95c4 == '\0')) {

    iVar14 = (*(int *)(param_1 + 0x254) >> 0x1f & 7U) + *(int *)(param_1 + 0x254);

    iVar7 = iVar14 >> 3;

    iVar14 = iVar7 / 6 + (iVar14 >> 0x1f) +

             (int)(((longlong)iVar7 / 6 + ((longlong)iVar7 >> 0x3f) & 0xffffffffU) >> 0x1f);

    plVar8 = (longlong *)(param_1 + 0x300);

    if (0xf < *(ulonglong *)(param_1 + 0x318)) {

      plVar8 = (longlong *)*plVar8;

    }

    uVar11 = (ulonglong)(uint)fVar35;

    FUN_140086570(DAT_1403ede20,iVar14,iVar7 + iVar14 * -6,0,uVar11,DAT_1403da054,plVar8);

  }

  FUN_1400c9290(*(undefined8 *)(param_1 + 0x328));

  if (*(int *)(param_1 + 0x250) < 2) {

    lVar24 = *(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8);

    if ((*(int *)(lVar24 + 4) < DAT_1403ee000) &&

       (FUN_1402c7138(&DAT_1403ee000), DAT_1403ee000 == -1)) {

      local_188 = (undefined *)0xa;

      uStack_180 = 0xf;

      local_198 = (char *)s_LogoHorsey_140307e80._0_8_;

      uStack_190 = (undefined *)(ulonglong)(ushort)s_LogoHorsey_140307e80._8_2_;

      DAT_1403edffc = FUN_14006fe60(&local_198);

      _Init_thread_footer(&DAT_1403ee000);

    }

    if ((*(int *)(lVar24 + 4) < DAT_1403ee008) &&

       (FUN_1402c7138(&DAT_1403ee008), DAT_1403ee008 == -1)) {

      uStack_190 = (undefined *)0x0;

      local_188 = (undefined *)0x6;

      uStack_180 = 0xf;

      local_198 = (char *)(ulonglong)CONCAT24(s_Author_14030c218._4_2_,s_Author_14030c218._0_4_);

      DAT_1403ee004 = FUN_14006fe60(&local_198);

      _Init_thread_footer(&DAT_1403ee008);

    }

    fVar32 = (DAT_140303380 - *(float *)(param_1 + 0x10c)) * DAT_140303fd0 + (float)DAT_1403eda00;

    iVar14 = 0xff;

    if ((*(int *)(param_1 + 0x250) == 1) && (0xf < *(int *)(param_1 + 0x254))) {

      iVar7 = ((0xf - *(int *)(param_1 + 0x254)) * 0xff) / 0x78 + 0xff;

      iVar14 = 0;

      if (0 < iVar7) {

        iVar14 = iVar7;

      }

      FUN_140072750(iVar14);

    }

    FUN_140071ed0(DAT_1403edffc,fVar32 + DAT_140304030);

    uVar11 = 0;

    FUN_140071ed0(DAT_1403edffc + 1,fVar32 + _DAT_14030c288);

    FUN_140071d20(DAT_1403ee004,fVar32 + DAT_1403033c4);

    if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar25 * 8) + 4) <

         DAT_1403ee010) && (FUN_1402c7138(&DAT_1403ee010), DAT_1403ee010 == -1)) {

      uStack_190 = (undefined *)0x0;

      local_188 = (undefined *)0x3;

      uStack_180 = 0xf;

      local_198 = (char *)(ulonglong)(uint3)DAT_14030c220;

      DAT_1403ee00c = FUN_14006fe60(&local_198);

      _Init_thread_footer(&DAT_1403ee010);

    }

    if ((*(int *)(param_1 + 0x250) == 0) && (*(int *)(param_1 + 0x254) == 1)) {

      DAT_1403da0c0 = -600;

    }

    else {

      DAT_1403da0c0 = DAT_1403da0c0 + 4;

    }

    if (0x28f - DAT_1403da0c0 < iVar14) {

      iVar14 = 0x28f - DAT_1403da0c0;

    }

    if (0 < iVar14) {

      FUN_140072750(iVar14);

      fVar28 = DAT_14039ca34;

      FUN_140071ed0(DAT_1403ee00c,(float)DAT_1403da0c0 + fVar32);

      uVar11 = (ulonglong)(uint)fVar28;

      FUN_140071ed0(DAT_1403ee00c + 1,((float)DAT_1403da0c0 + fVar32) - DAT_14030c290);

    }

    FUN_1400727d0();

    if (((*(int *)(param_1 + 0x250) == 0) && (iVar14 = *(int *)(param_1 + 0x254), 0x77 < iVar14)) &&

       (iVar14 % 0x1e < 0x12)) {

      uVar11 = (ulonglong)(uint)fVar35;

      FUN_140086570(DAT_1403ede48);

    }

  }

  if ((*(char *)(param_1 + 600) == '\0') && (1 < *(int *)(param_1 + 0x250))) {

    FUN_14008d760(&local_198,"Race %d");

    pcVar12 = (char *)&local_198;

    if (0xf < uStack_180) {

      pcVar12 = local_198;

    }

    FUN_140086450(DAT_1403ede28,pcVar12);

    FUN_140071000();

    uVar11 = (ulonglong)(uint)fVar35;

    FUN_140086570(DAT_1403ede28);

    if (0xf < uStack_180) {

      if ((0xfff < uStack_180 + 1) &&

         ((char *)0x1f < local_198 + (-8 - *(longlong *)(local_198 + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  iVar14 = *(int *)(param_1 + 0x250);

  if (((iVar14 == 0xb) || (iVar14 == 0xc)) && (iVar7 = *(int *)(param_1 + 0x254), iVar7 < 0x10)) {

    FUN_1400c5c20(0x10,iVar7,DAT_1403eda00,iVar7,uVar11);

  }

  else if ((((DAT_1403eded8 < 2) || (iVar14 != 3)) && (iVar14 != 4)) ||

          (0xf < *(int *)(param_1 + 0x254))) {

    if (*(char *)(param_1 + 0x259) == '\0') {

      return;

    }

    if (iVar14 != 6) {

      return;

    }

    if (0xf < *(int *)(param_1 + 0x254)) {

      return;

    }

  }

  FUN_140071000();

  return;

}





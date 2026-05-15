// Address: 0x140038860
// Ghidra name: FUN_140038860
// ============ 0x140038860 FUN_140038860 (size=1707) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_140038860(longlong param_1,int param_2,int param_3)



{

  float fVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined8 uVar11;

  ulonglong uVar12;

  undefined8 uVar13;

  ulonglong uVar14;

  char cVar15;

  char *pcVar16;

  longlong lVar17;

  int iVar18;

  ulonglong uVar19;

  longlong lVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  bool bVar23;

  float local_res8;

  float local_resc;

  ulonglong in_stack_ffffffffffffff48;

  undefined4 uVar24;

  undefined1 local_a8 [16];

  undefined8 local_98;

  ulonglong uStack_90;

  

  lVar20 = (longlong)param_2;

  cVar15 = FUN_1400b7660(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar20 * 8),1,0);

  if (cVar15 == '\0') {

    bVar23 = param_3 == 0;

  }

  else {

    FUN_1400b4a10(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar20 * 8),&local_res8);

    uVar24 = DAT_14039ca44;

    uVar14 = _UNK_140304d28;

    uVar13 = _DAT_140304d20;

    uVar12 = _UNK_140304cf8;

    uVar11 = _DAT_140304cf0;

    uVar7 = _UNK_1403041b8;

    uVar6 = _DAT_1403041b0;

    uVar5 = _UNK_1403040a8;

    uVar4 = _DAT_1403040a0;

    uVar3 = DAT_140303758;

    uVar19 = 0;

    uVar21 = uVar19;

    uVar22 = uVar19;

LAB_140038920:

    do {

      lVar17 = *(longlong *)(param_1 + 0x280);

      iVar18 = (int)uVar19;

      if ((*(float *)(uVar21 + lVar17) <= local_res8) &&

         (local_res8 < *(float *)(uVar21 + lVar17) + *(float *)(uVar21 + 8 + lVar17))) {

        fVar1 = *(float *)(uVar21 + 4 + lVar17);

        if ((fVar1 <= local_resc) && (local_resc < fVar1 + *(float *)(uVar21 + 0xc + lVar17))) {

          if (iVar18 == 4) {

            local_a8 = ZEXT416(0);

            local_98 = 0;

            uStack_90 = 0;

            pcVar16 = (char *)FUN_1400285e0(0x40);

            uVar2 = s_You_must_win_all_four_ribbons_to_140304818._8_8_;

            local_a8._0_8_ = pcVar16;

            local_98 = uVar13;

            uStack_90 = uVar14;

            *(undefined8 *)pcVar16 = s_You_must_win_all_four_ribbons_to_140304818._0_8_;

            *(undefined8 *)(pcVar16 + 8) = uVar2;

            uVar10 = s_You_must_win_all_four_ribbons_to_140304818._28_4_;

            uVar9 = s_You_must_win_all_four_ribbons_to_140304818._24_4_;

            uVar8 = s_You_must_win_all_four_ribbons_to_140304818._20_4_;

            *(undefined4 *)(pcVar16 + 0x10) = s_You_must_win_all_four_ribbons_to_140304818._16_4_;

            *(undefined4 *)(pcVar16 + 0x14) = uVar8;

            *(undefined4 *)(pcVar16 + 0x18) = uVar9;

            *(undefined4 *)(pcVar16 + 0x1c) = uVar10;

            uVar2 = s_You_must_win_all_four_ribbons_to_140304818._40_8_;

            *(undefined8 *)(pcVar16 + 0x20) = s_You_must_win_all_four_ribbons_to_140304818._32_8_;

            *(undefined8 *)(pcVar16 + 0x28) = uVar2;

            *(undefined2 *)(pcVar16 + 0x30) = s_You_must_win_all_four_ribbons_to_140304818._48_2_;

            pcVar16[0x32] = s_You_must_win_all_four_ribbons_to_140304818[0x32];

            pcVar16[0x33] = '\0';

            in_stack_ffffffffffffff48 = CONCAT44((int)(in_stack_ffffffffffffff48 >> 0x20),uVar3);

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_a8,0,

                          in_stack_ffffffffffffff48);

            if (0xf < uStack_90) {

              if (0xfff < uStack_90 + 1) {

                if (0x1f < (local_a8._0_8_ - *(longlong *)(local_a8._0_8_ + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

              }

              FUN_1402c7088();

              uVar19 = 5;

              uVar22 = uVar22 + 1;

              uVar21 = uVar21 + 0x10;

              goto LAB_140038920;

            }

          }

          else if (iVar18 == 3) {

            if ((*(longlong *)(param_1 + 0x278) != 0) || (*(longlong *)(param_1 + 0x268) != 0)) {

LAB_140038d9b:

              lVar17 = FUN_1400c7520(*(undefined4 *)

                                      (*(longlong *)(*(longlong *)(param_1 + 0x130) + lVar20 * 8) +

                                      0x1f8));

              if (*(char *)(lVar17 + 0x60 + uVar22) != '\0') {

                uVar2 = *(undefined8 *)(param_1 + 0x148);

                FUN_1400cf9a0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar20 * 8));

                FUN_1400d1c40(param_1,uVar2);

                goto LAB_140038d3f;

              }

LAB_140038c68:

              *(int *)(param_1 + 0x254) = iVar18;

              *(undefined1 *)(param_1 + 0x223c) = 0;

              *(undefined1 *)(param_1 + 0x2250) = 0;

              *(int *)(param_1 + 0x2240) = *(int *)(param_1 + 0x2240) + 1;

              *(undefined8 *)(param_1 + 0x260) =

                   *(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar20 * 8);

              *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d) = 0;

              local_98 = uVar4;

              uStack_90 = uVar5;

              local_a8[8] = s_EnterTent_140304908[8];

              local_a8[0] = s_EnterTent_140304908[0];

              local_a8[1] = s_EnterTent_140304908[1];

              local_a8[2] = s_EnterTent_140304908[2];

              local_a8[3] = s_EnterTent_140304908[3];

              local_a8[4] = s_EnterTent_140304908[4];

              local_a8[5] = s_EnterTent_140304908[5];

              local_a8[6] = s_EnterTent_140304908[6];

              local_a8[7] = s_EnterTent_140304908[7];

              local_a8._9_7_ = 0;

              in_stack_ffffffffffffff48 = in_stack_ffffffffffffff48 & 0xffffffffffffff00;

              FUN_140040ca0(local_a8,100,iVar18 * 0x14 + -0x32,uVar24,in_stack_ffffffffffffff48);

              if (0xf < uStack_90) {

                if (0xfff < uStack_90 + 1) {

                  if (0x1f < (local_a8._0_8_ - *(longlong *)(local_a8._0_8_ + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                }

                FUN_1402c7088();

              }

              FUN_14003f6f0();

              *(undefined4 *)(param_1 + 0x1b0) = 0;

              *(undefined4 *)(param_1 + 0x25c) = 1;

              *(undefined4 *)(param_1 + 0x250) = 0;

              goto LAB_140038d3f;

            }

            local_a8 = ZEXT816(0);

            local_98 = 0;

            uStack_90 = 0;

            pcVar16 = (char *)FUN_1400285e0(0x20);

            uVar2 = s_The_acrobats_are_all_missing_140304850._8_8_;

            local_a8._0_8_ = pcVar16;

            local_98 = uVar11;

            uStack_90 = uVar12;

            *(undefined8 *)pcVar16 = s_The_acrobats_are_all_missing_140304850._0_8_;

            *(undefined8 *)(pcVar16 + 8) = uVar2;

            *(undefined8 *)(pcVar16 + 0x10) = s_The_acrobats_are_all_missing_140304850._16_8_;

            *(undefined4 *)(pcVar16 + 0x18) = s_The_acrobats_are_all_missing_140304850._24_4_;

            pcVar16[0x1c] = '\0';

            in_stack_ffffffffffffff48 = CONCAT44((int)(in_stack_ffffffffffffff48 >> 0x20),uVar3);

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_a8,0,

                          in_stack_ffffffffffffff48);

            if (0xf < uStack_90) {

              if (0xfff < uStack_90 + 1) {

                if (0x1f < (local_a8._0_8_ - *(longlong *)(local_a8._0_8_ + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

              }

              FUN_1402c7088();

              uVar19 = 4;

              uVar22 = uVar22 + 1;

              uVar21 = uVar21 + 0x10;

              goto LAB_140038920;

            }

          }

          else {

            if (iVar18 != 1) {

              if (iVar18 != 5) {

                if (iVar18 < 4) goto LAB_140038d9b;

                goto LAB_140038c68;

              }

              if (*(longlong *)(param_1 + 0x148) != 0) {

                cVar15 = FUN_1400b7650();

                if (cVar15 != '\0') {

                  cVar15 = FUN_140104c00(DAT_1403fb0d8,10,0);

                  if (cVar15 != '\0') goto LAB_140038c68;

                }

              }

              uVar24 = (undefined4)(in_stack_ffffffffffffff48 >> 0x20);

              local_a8 = ZEXT816(0);

              local_98 = 0;

              uStack_90 = 0;

              pcVar16 = (char *)FUN_1400285e0(0x20);

              uVar4 = s_It_s__10_to_see_a_freak_1403048d0._8_8_;

              local_a8._0_8_ = pcVar16;

              local_98 = _DAT_140304cd0;

              uStack_90 = _UNK_140304cd8;

              *(undefined8 *)pcVar16 = s_It_s__10_to_see_a_freak_1403048d0._0_8_;

              *(undefined8 *)(pcVar16 + 8) = uVar4;

              *(undefined4 *)(pcVar16 + 0x10) = s_It_s__10_to_see_a_freak_1403048d0._16_4_;

              *(undefined2 *)(pcVar16 + 0x14) = s_It_s__10_to_see_a_freak_1403048d0._20_2_;

              pcVar16[0x16] = s_It_s__10_to_see_a_freak_1403048d0[0x16];

              pcVar16[0x17] = '\0';

              FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_a8,0,

                            CONCAT44(uVar24,uVar3));

              if (0xf < uStack_90) {

                if (0xfff < uStack_90 + 1) {

                  if (0x1f < (local_a8._0_8_ - *(longlong *)(local_a8._0_8_ + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                  }

                }

                FUN_1402c7088();

              }

              break;

            }

            if ((*(longlong *)(param_1 + 0x270) != 0) || (*(longlong *)(param_1 + 0x268) != 0))

            goto LAB_140038d9b;

            local_a8 = ZEXT416(0);

            local_98 = 0;

            uStack_90 = 0;

            pcVar16 = (char *)FUN_1400285e0(0x40);

            uVar2 = s_Sorry__Strong_Horse_is_missing_s_140304870._8_8_;

            local_a8._0_8_ = pcVar16;

            local_98 = uVar6;

            uStack_90 = uVar7;

            *(undefined8 *)pcVar16 = s_Sorry__Strong_Horse_is_missing_s_140304870._0_8_;

            *(undefined8 *)(pcVar16 + 8) = uVar2;

            uVar10 = s_Sorry__Strong_Horse_is_missing_s_140304870._28_4_;

            uVar9 = s_Sorry__Strong_Horse_is_missing_s_140304870._24_4_;

            uVar8 = s_Sorry__Strong_Horse_is_missing_s_140304870._20_4_;

            *(undefined4 *)(pcVar16 + 0x10) = s_Sorry__Strong_Horse_is_missing_s_140304870._16_4_;

            *(undefined4 *)(pcVar16 + 0x14) = uVar8;

            *(undefined4 *)(pcVar16 + 0x18) = uVar9;

            *(undefined4 *)(pcVar16 + 0x1c) = uVar10;

            uVar2 = s_Sorry__Strong_Horse_is_missing_s_140304870._40_8_;

            *(undefined8 *)(pcVar16 + 0x20) = s_Sorry__Strong_Horse_is_missing_s_140304870._32_8_;

            *(undefined8 *)(pcVar16 + 0x28) = uVar2;

            pcVar16[0x30] = '\0';

            in_stack_ffffffffffffff48 = CONCAT44((int)(in_stack_ffffffffffffff48 >> 0x20),uVar3);

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_a8,0,

                          in_stack_ffffffffffffff48);

            if (0xf < uStack_90) {

              if (0xfff < uStack_90 + 1) {

                if (0x1f < (local_a8._0_8_ - *(longlong *)(local_a8._0_8_ + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

                }

              }

              FUN_1402c7088();

            }

            lVar17 = FUN_14010de40(DAT_1403fb0d8);

            if (lVar17 != 0) {

              uVar2 = *(undefined8 *)(param_1 + 0x148);

              FUN_14010de40(DAT_1403fb0d8);

              FUN_1400d1c40(param_1,uVar2);

            }

          }

          uVar19 = (ulonglong)(iVar18 + 1);

          uVar22 = uVar22 + 1;

          uVar21 = uVar21 + 0x10;

          goto LAB_140038920;

        }

      }

LAB_140038d3f:

      uVar19 = (ulonglong)(iVar18 + 1U);

      uVar22 = uVar22 + 1;

      uVar21 = uVar21 + 0x10;

    } while ((int)(iVar18 + 1U) < 6);

    bVar23 = true;

  }

  return bVar23;

}





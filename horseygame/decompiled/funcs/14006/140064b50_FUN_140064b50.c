// Address: 0x140064b50
// Ghidra name: FUN_140064b50
// ============ 0x140064b50 FUN_140064b50 (size=2940) ============


/* WARNING: Removing unreachable block (ram,0x000140064e30) */

/* WARNING: Removing unreachable block (ram,0x000140065029) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140064b50(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  size_t _Size;

  bool bVar2;

  bool bVar3;

  undefined4 uVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  longlong lVar8;

  undefined8 *puVar9;

  int *piVar10;

  undefined8 uVar11;

  size_t sVar12;

  undefined8 *******pppppppuVar13;

  undefined8 *_Buf1;

  ulonglong uVar14;

  ulonglong uVar15;

  void *pvVar16;

  longlong lVar17;

  undefined8 *puVar18;

  uint uVar19;

  ulonglong uVar20;

  longlong lVar21;

  undefined8 *******pppppppuVar22;

  undefined8 in_stack_ffffffffffffff38;

  undefined4 uVar23;

  int *local_b8;

  int *piStack_b0;

  int *local_a8;

  undefined8 ******local_a0;

  undefined8 uStack_98;

  size_t local_90;

  ulonglong local_88;

  undefined8 local_80;

  undefined8 uStack_78;

  undefined8 local_70;

  ulonglong uStack_68;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if (param_3 == 0) {

    if (*(char *)(param_1 + 0x2f8) != '\0') {

      return 1;

    }

    *(undefined1 *)(lVar1 + 0x204) = 1;

    return 1;

  }

  if (param_3 != 3) {

    return 1;

  }

  if (*(int *)(lVar1 + 0x1f8) == -1) {

    return 1;

  }

  pcVar7 = (char *)FUN_1400cf970(param_1,lVar1);

  local_a0 = (undefined8 *******)0x0;

  uStack_98 = 0;

  local_90 = 0;

  local_88 = 0;

  strlen(pcVar7);

  FUN_140027e30();

  sVar12 = local_90;

  pppppppuVar22 = (undefined8 *******)local_a0;

  if ((*(char *)(param_1 + 0x2f8) == '\0') || (*(int *)(lVar1 + 0x1f8) != *(int *)(param_1 + 800)))

  {

    pvVar16 = (void *)(param_1 + 600);

    if (0xf < *(ulonglong *)(param_1 + 0x270)) {

      pvVar16 = *(void **)(param_1 + 600);

    }

    pppppppuVar13 = &local_a0;

    if (0xf < local_88) {

      pppppppuVar13 = (undefined8 *******)local_a0;

    }

    if ((local_90 == *(size_t *)(param_1 + 0x268)) &&

       ((local_90 == 0 || (iVar5 = memcmp(pppppppuVar13,pvVar16,local_90), iVar5 == 0))))

    goto LAB_140064d2f;

    pvVar16 = (void *)(param_1 + 0x278);

    if (0xf < *(ulonglong *)(param_1 + 0x290)) {

      pvVar16 = *(void **)(param_1 + 0x278);

    }

    pppppppuVar13 = &local_a0;

    if (0xf < local_88) {

      pppppppuVar13 = pppppppuVar22;

    }

    if ((sVar12 == *(size_t *)(param_1 + 0x288)) &&

       ((sVar12 == 0 || (iVar5 = memcmp(pppppppuVar13,pvVar16,sVar12), iVar5 == 0))))

    goto LAB_140064d2f;

    pvVar16 = (void *)(param_1 + 0x298);

    if (0xf < *(ulonglong *)(param_1 + 0x2b0)) {

      pvVar16 = *(void **)(param_1 + 0x298);

    }

    pppppppuVar13 = &local_a0;

    if (0xf < local_88) {

      pppppppuVar13 = pppppppuVar22;

    }

    if ((sVar12 == *(size_t *)(param_1 + 0x2a8)) &&

       ((sVar12 == 0 || (iVar5 = memcmp(pppppppuVar13,pvVar16,sVar12), iVar5 == 0))))

    goto LAB_140064d2f;

    pvVar16 = (void *)(param_1 + 0x2b8);

    if (0xf < *(ulonglong *)(param_1 + 0x2d0)) {

      pvVar16 = *(void **)(param_1 + 0x2b8);

    }

    pppppppuVar13 = &local_a0;

    if (0xf < local_88) {

      pppppppuVar13 = pppppppuVar22;

    }

    if ((sVar12 == *(size_t *)(param_1 + 0x2c8)) &&

       ((sVar12 == 0 || (iVar5 = memcmp(pppppppuVar13,pvVar16,sVar12), iVar5 == 0))))

    goto LAB_140064d2f;

  }

  else {

LAB_140064d2f:

    *(undefined1 *)(lVar1 + 0x204) = 0;

  }

  if ((*(longlong *)(param_1 + 0x148) == 0) || (*(char *)(param_1 + 0x2f8) != '\0'))

  goto LAB_14006541a;

  local_b8 = (int *)0x0;

  piStack_b0 = (int *)0x0;

  local_a8 = (int *)0x0;

  bVar3 = false;

  lVar21 = 0x48;

  do {

    lVar8 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

    if (*(int *)(lVar8 + lVar21) != -1) {

      lVar8 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

      if (piStack_b0 == local_a8) {

        lVar17 = (longlong)piStack_b0 - (longlong)local_b8 >> 2;

        if (lVar17 == 0x3fffffffffffffff) {

LAB_14006564e:

                    /* WARNING: Subroutine does not return */

          FUN_14002f0d0();

        }

        uVar20 = lVar17 + 1;

        uVar14 = (longlong)local_a8 - (longlong)local_b8 >> 2;

        if (0x3fffffffffffffff - (uVar14 >> 1) < uVar14) {

          uVar15 = 0x3fffffffffffffff;

        }

        else {

          uVar14 = (uVar14 >> 1) + uVar14;

          uVar15 = uVar20;

          if (uVar20 <= uVar14) {

            uVar15 = uVar14;

          }

          if (0x3fffffffffffffff < uVar15) {

LAB_140065648:

                    /* WARNING: Subroutine does not return */

            FUN_140024090();

          }

        }

        piVar10 = (int *)FUN_1400285e0(uVar15 * 4);

        piVar10[lVar17] = *(int *)(lVar8 + lVar21);

        FUN_1402f8e20(piVar10);

        if (local_b8 != (int *)0x0) {

          if ((0xfff < ((longlong)local_a8 - (longlong)local_b8 & 0xfffffffffffffffcU)) &&

             (0x1f < (ulonglong)((longlong)local_b8 + (-8 - *(longlong *)(local_b8 + -2))))) {

LAB_14006562f:

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        piStack_b0 = piVar10 + uVar20;

        local_a8 = piVar10 + uVar15;

        local_b8 = piVar10;

      }

      else {

        *piStack_b0 = *(int *)(lVar8 + lVar21);

        piStack_b0 = piStack_b0 + 1;

      }

    }

    lVar21 = lVar21 + 4;

  } while (lVar21 < 0x50);

  bVar2 = false;

  if (local_b8 == piStack_b0) {

LAB_1400650f5:

    bVar3 = false;

LAB_1400650f9:

    uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

    piVar10 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar10 = DAT_1403d9530;

    }

    if (DAT_1403d9540 == 5) {

      iVar5 = *piVar10 + -0x63747548;

      if (iVar5 == 0) {

        iVar5 = *(byte *)(piVar10 + 1) - 0x68;

      }

      if (iVar5 == 0) goto LAB_140065137;

    }

    if (*(char *)(param_1 + 0x324) == '\0') {

      if (bVar3) {

        uVar11 = *(undefined8 *)(param_1 + 0x148);

        FUN_1400cf9a0(param_1,lVar1);

        FUN_1400d1c40(param_1,uVar11,"%s hasn\'t won a race");

        local_70 = _DAT_140303400;

        uStack_68 = _UNK_140303408;

        local_80._0_1_ = s_I_want_a_winner_140307d20[0];

        local_80._1_1_ = s_I_want_a_winner_140307d20[1];

        local_80._2_1_ = s_I_want_a_winner_140307d20[2];

        local_80._3_1_ = s_I_want_a_winner_140307d20[3];

        local_80._4_1_ = s_I_want_a_winner_140307d20[4];

        local_80._5_1_ = s_I_want_a_winner_140307d20[5];

        local_80._6_1_ = s_I_want_a_winner_140307d20[6];

        local_80._7_1_ = s_I_want_a_winner_140307d20[7];

        uStack_78 = (ulonglong)

                    CONCAT16(s_I_want_a_winner_140307d20[0xe],

                             CONCAT24(s_I_want_a_winner_140307d20._12_2_,

                                      s_I_want_a_winner_140307d20._8_4_));

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_80,0,

                      CONCAT44(uVar23,DAT_140303758));

        if (0xf < uStack_68) {

          if ((0xfff < uStack_68 + 1) &&

             (0x1f < ((longlong)local_80 - *(longlong *)((longlong)local_80 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      else {

        iVar5 = 0;

        puVar18 = (undefined8 *)(param_1 + 600);

        do {

          pcVar7 = (char *)FUN_1400cf970(param_1,lVar1);

          sVar12 = strlen(pcVar7);

          pvVar16 = (void *)((longlong)iVar5 * 0x20 + 600 + param_1);

          if (0xf < (ulonglong)puVar18[3]) {

            pvVar16 = (void *)*puVar18;

          }

          _Size = puVar18[2];

          if ((_Size == sVar12) &&

             ((_Size == 0 || (iVar6 = memcmp(pvVar16,pcVar7,_Size), iVar6 == 0))))

          goto LAB_1400653cc;

          uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

          iVar5 = iVar5 + 1;

          puVar18 = puVar18 + 4;

        } while (iVar5 < 4);

        local_80 = (char *)0x0;

        uStack_78 = 0;

        local_70 = 0;

        uStack_68 = 0;

        local_80 = (char *)FUN_1400285e0(0x30);

        uVar11 = s_That_horse_isn_t_a_descendant_of_140307d30._8_8_;

        local_70 = _DAT_140304150;

        uStack_68 = _UNK_140304158;

        *(undefined8 *)local_80 = s_That_horse_isn_t_a_descendant_of_140307d30._0_8_;

        *(undefined8 *)(local_80 + 8) = uVar11;

        uVar11 = s_That_horse_isn_t_a_descendant_of_140307d30._24_8_;

        *(undefined8 *)(local_80 + 0x10) = s_That_horse_isn_t_a_descendant_of_140307d30._16_8_;

        *(undefined8 *)(local_80 + 0x18) = uVar11;

        local_80[0x20] = '\0';

        uVar4 = DAT_140303758;

        uVar11 = CONCAT44(uVar23,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_80,0,uVar11);

        uVar23 = (undefined4)((ulonglong)uVar11 >> 0x20);

        if (0xf < uStack_68) {

          if ((0xfff < uStack_68 + 1) &&

             ((char *)0x1f < local_80 + (-8 - *(longlong *)(local_80 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        pcVar7 = (char *)(param_1 + 0x2d8);

        if (0xf < *(ulonglong *)(param_1 + 0x2f0)) {

          pcVar7 = *(char **)pcVar7;

        }

        local_80 = (char *)0x0;

        uStack_78 = 0;

        local_70 = 0;

        uStack_68 = 0;

        sVar12 = strlen(pcVar7);

        FUN_140027e30(&local_80,pcVar7,sVar12);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_80,0,CONCAT44(uVar23,uVar4));

        if (0xf < uStack_68) {

          if ((0xfff < uStack_68 + 1) &&

             (0x1f < ((longlong)local_80 - *(longlong *)((longlong)local_80 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

    }

  }

  else {

    do {

      if (bVar2) goto LAB_1400650d9;

      piStack_b0 = piStack_b0 + -1;

      iVar5 = *piStack_b0;

      if (iVar5 != -1) {

        uVar20 = 0;

        puVar18 = (undefined8 *)(param_1 + 600);

        do {

          if (bVar2) goto LAB_1400650bc;

          puVar9 = (undefined8 *)FUN_1400c7520(iVar5);

          pvVar16 = (void *)(uVar20 * 0x20 + 600 + param_1);

          if (0xf < (ulonglong)puVar18[3]) {

            pvVar16 = (void *)*puVar18;

          }

          _Buf1 = puVar9;

          if (0xf < (ulonglong)puVar9[3]) {

            _Buf1 = (undefined8 *)*puVar9;

          }

          sVar12 = puVar9[2];

          bVar2 = bVar3;

          if ((sVar12 == puVar18[2]) &&

             ((sVar12 == 0 || (iVar6 = memcmp(_Buf1,pvVar16,sVar12), iVar6 == 0)))) {

            bVar2 = true;

          }

          uVar19 = (int)uVar20 + 1;

          uVar20 = (ulonglong)uVar19;

          puVar18 = puVar18 + 4;

          bVar3 = bVar2;

        } while ((int)uVar19 < 4);

        if (!bVar2) {

          lVar21 = 0x48;

          do {

            lVar8 = FUN_1400c7520(iVar5);

            if (*(int *)(lVar8 + lVar21) != -1) {

              lVar8 = FUN_1400c7520(iVar5);

              if (piStack_b0 == local_a8) {

                lVar17 = (longlong)piStack_b0 - (longlong)local_b8 >> 2;

                if (lVar17 == 0x3fffffffffffffff) goto LAB_14006564e;

                uVar20 = lVar17 + 1;

                uVar14 = (longlong)local_a8 - (longlong)local_b8 >> 2;

                if (0x3fffffffffffffff - (uVar14 >> 1) < uVar14) {

                  uVar15 = 0x3fffffffffffffff;

                }

                else {

                  uVar14 = (uVar14 >> 1) + uVar14;

                  uVar15 = uVar20;

                  if (uVar20 <= uVar14) {

                    uVar15 = uVar14;

                  }

                  if (0x3fffffffffffffff < uVar15) goto LAB_140065648;

                }

                piVar10 = (int *)FUN_1400285e0(uVar15 * 4);

                piVar10[lVar17] = *(int *)(lVar8 + lVar21);

                FUN_1402f8e20(piVar10,local_b8);

                if (local_b8 != (int *)0x0) {

                  if ((0xfff < ((longlong)local_a8 - (longlong)local_b8 & 0xfffffffffffffffcU)) &&

                     (0x1f < (ulonglong)((longlong)local_b8 + (-8 - *(longlong *)(local_b8 + -2)))))

                  goto LAB_14006562f;

                  FUN_1402c7088();

                }

                piStack_b0 = piVar10 + uVar20;

                local_a8 = piVar10 + uVar15;

                local_b8 = piVar10;

              }

              else {

                *piStack_b0 = *(int *)(lVar8 + lVar21);

                piStack_b0 = piStack_b0 + 1;

              }

            }

            lVar21 = lVar21 + 4;

          } while (lVar21 < 0x50);

        }

      }

LAB_1400650bc:

    } while (local_b8 != piStack_b0);

    if (!bVar2) goto LAB_1400650f5;

LAB_1400650d9:

    lVar21 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

    if (*(int *)(lVar21 + 0x54) < 1) goto LAB_1400650f9;

LAB_140065137:

    uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

    *(undefined4 *)(param_1 + 0x1f8) = 0;

    lVar21 = *(longlong *)(param_1 + 0x218);

    lVar8 = *(longlong *)(param_1 + 0x210);

    if (lVar8 != lVar21) {

      do {

        FUN_140027900(lVar8);

        uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

        lVar8 = lVar8 + 0x20;

      } while (lVar8 != lVar21);

      *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)(param_1 + 0x210);

    }

    local_80 = (char *)0x0;

    uStack_78 = 0;

    local_70 = 0;

    uStack_68 = 0;

    local_80 = (char *)FUN_1400285e0(0x30);

    uVar11 = s_Wow_you_did_it__Here_s_your_rewa_140307ce0._8_8_;

    local_70 = _DAT_140304170;

    uStack_68 = _UNK_140304178;

    *(undefined8 *)local_80 = s_Wow_you_did_it__Here_s_your_rewa_140307ce0._0_8_;

    *(undefined8 *)(local_80 + 8) = uVar11;

    uVar11 = s_Wow_you_did_it__Here_s_your_rewa_140307ce0._24_8_;

    *(undefined8 *)(local_80 + 0x10) = s_Wow_you_did_it__Here_s_your_rewa_140307ce0._16_8_;

    *(undefined8 *)(local_80 + 0x18) = uVar11;

    *(undefined2 *)(local_80 + 0x20) = s_Wow_you_did_it__Here_s_your_rewa_140307ce0._32_2_;

    local_80[0x22] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_80,0,

                  CONCAT44(uVar23,DAT_140303758));

    if (0xf < uStack_68) {

      if ((0xfff < uStack_68 + 1) && ((char *)0x1f < local_80 + (-8 - *(longlong *)(local_80 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    uStack_78 = 0;

    local_70 = _DAT_1403033d0;

    uStack_68 = _UNK_1403033d8;

    local_80 = (char *)(ulonglong)CONCAT24(s_bubber_1403042a8._4_2_,s_bubber_1403042a8._0_4_);

    FUN_140037710(&local_80);

    if (0xf < uStack_68) {

      if ((0xfff < uStack_68 + 1) &&

         (0x1f < ((longlong)local_80 - *(longlong *)((longlong)local_80 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(undefined1 *)(param_1 + 0x2f8) = 1;

    FUN_140104b20(DAT_1403fb0d8,2000);

    *(undefined1 *)(lVar1 + 0x204) = 0;

    uVar11 = FUN_1400cf9a0(param_1,lVar1);

    FUN_1400278e0(param_1 + 0x300,uVar11);

    *(undefined4 *)(param_1 + 800) = *(undefined4 *)(lVar1 + 0x1f8);

  }

LAB_1400653cc:

  pppppppuVar22 = (undefined8 *******)local_a0;

  if (local_b8 != (int *)0x0) {

    if ((0xfff < ((longlong)local_a8 - (longlong)local_b8 & 0xfffffffffffffffcU)) &&

       (0x1f < (ulonglong)((longlong)local_b8 + (-8 - *(longlong *)(local_b8 + -2))))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

    pppppppuVar22 = (undefined8 *******)local_a0;

  }

LAB_14006541a:

  if (0xf < local_88) {

    pppppppuVar13 = pppppppuVar22;

    if ((0xfff < local_88 + 1) &&

       (pppppppuVar13 = (undefined8 *******)pppppppuVar22[-1],

       0x1f < (ulonglong)((longlong)pppppppuVar22 + (-8 - (longlong)pppppppuVar13)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(pppppppuVar13);

  }

  return 1;

}





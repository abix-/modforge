// Hint: rest_your_horse_or_too_young
// Address: 0x140060a80
// Ghidra name: FUN_140060a80
// ============ 0x140060a80 FUN_140060a80 (size=3713) ============


/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140060a80(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 uVar2;

  char cVar3;

  uint uVar4;

  longlong lVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  char *_Str;

  size_t sVar8;

  longlong lVar9;

  undefined8 *******pppppppuVar10;

  longlong lVar11;

  bool bVar12;

  undefined8 in_stack_ffffffffffffff78;

  undefined4 uVar13;

  char *local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  ulonglong uStack_60;

  undefined8 *******local_50;

  undefined8 uStack_48;

  longlong local_40;

  ulonglong uStack_38;

  

  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

  lVar11 = (longlong)param_2;

  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x130) + lVar11 * 8);

  if (*(int *)(param_1 + 0x254) != 2) {

    return 1;

  }

  if (*(longlong *)(param_1 + 0x148) == 0) {

    return 1;

  }

  if (param_3 - 3U < 2) {

    lVar5 = FUN_1400c7520(*(undefined4 *)(lVar9 + 0x1f8));

    if (*(char *)(lVar5 + 0x58) != '\0') {

      uVar7 = *(undefined8 *)(param_1 + 0x148);

      uVar6 = FUN_1400cf9a0(param_1,lVar9);

      FUN_1400d1c40(param_1,uVar7,"%s is already a Champion horse!",uVar6);

      return 0;

    }

    cVar3 = FUN_1400b76a0(lVar9);

    if (cVar3 != '\0') {

      FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"That horse is too old to race");

      return 0;

    }

    if (*(char *)(lVar9 + 0x205) != '\0') {

      local_78 = (char *)0x0;

      uStack_70 = 0;

      local_68 = 0;

      uStack_60 = 0;

      local_78 = (char *)FUN_1400285e0(0x30);

      uVar7 = s_Your_horse_is_hungry__Feed_it_fi_1403073d0._8_8_;

      local_68 = _DAT_140305fe0;

      uStack_60 = _UNK_140305fe8;

      *(undefined8 *)local_78 = s_Your_horse_is_hungry__Feed_it_fi_1403073d0._0_8_;

      *(undefined8 *)(local_78 + 8) = uVar7;

      uVar7 = s_Your_horse_is_hungry__Feed_it_fi_1403073d0._24_8_;

      *(undefined8 *)(local_78 + 0x10) = s_Your_horse_is_hungry__Feed_it_fi_1403073d0._16_8_;

      *(undefined8 *)(local_78 + 0x18) = uVar7;

      *(undefined2 *)(local_78 + 0x20) = s_Your_horse_is_hungry__Feed_it_fi_1403073d0._32_2_;

      local_78[0x22] = s_Your_horse_is_hungry__Feed_it_fi_1403073d0[0x22];

      local_78[0x23] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                    CONCAT44(uVar13,DAT_140303758));

      if (0xf < uStack_60) {

        if ((0xfff < uStack_60 + 1) &&

           ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if (DAT_1403f4bb2 != '\0') {

        return 0;

      }

      *(undefined4 *)(DAT_1403fb0d8 + 0x440) = 0;

      return 0;

    }

    if (*(char *)(lVar9 + 0x206) != '\0') {

      local_78 = (char *)0x0;

      uStack_70 = 0;

      local_68 = 0;

      uStack_60 = 0;

      local_78 = (char *)FUN_1400285e0(0x30);

      uVar7 = s_Go_home_and_rest_your_horse_firs_1403073f8._8_8_;

      local_68 = _DAT_140304160;

      uStack_60 = _UNK_140304168;

      *(undefined8 *)local_78 = s_Go_home_and_rest_your_horse_firs_1403073f8._0_8_;

      *(undefined8 *)(local_78 + 8) = uVar7;

      uVar7 = s_Go_home_and_rest_your_horse_firs_1403073f8._24_8_;

      *(undefined8 *)(local_78 + 0x10) = s_Go_home_and_rest_your_horse_firs_1403073f8._16_8_;

      *(undefined8 *)(local_78 + 0x18) = uVar7;

      local_78[0x20] = s_Go_home_and_rest_your_horse_firs_1403073f8[0x20];

      local_78[0x21] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                    CONCAT44(uVar13,DAT_140303758));

      if (uStack_60 < 0x10) {

        return 0;

      }

      if ((0xfff < uStack_60 + 1) && ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      goto LAB_140061687;

    }

    if (param_3 == 3) {

      iVar1 = *(int *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4);

      if (iVar1 == 3) {

        return 1;

      }

      if (iVar1 == 4) {

        FUN_140104b20(DAT_1403fb0d8,0xfa,0);

        *(undefined1 *)(param_1 + 0x2b0) = 0;

      }

      cVar3 = FUN_140104c00(DAT_1403fb0d8,0x19,0);

      if (cVar3 == '\0') {

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x20);

        uVar7 = s_Not_enough_money_140307478._8_8_;

        local_68 = _DAT_1403040e0;

        uStack_60 = _UNK_1403040e8;

        *(undefined8 *)local_78 = s_Not_enough_money_140307478._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        local_78[0x10] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                      CONCAT44(uVar13,DAT_140303758));

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 0xffffffff;

        return 0;

      }

      if (*(char *)(param_1 + 0x26d) == '\0') {

        *(undefined1 *)(param_1 + 0x26d) = 1;

        uVar7 = FUN_1400cf9a0(param_1,lVar9);

        FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),

                      "Now go to the track to watch %s race",uVar7);

        _Str = (char *)FUN_1400cf970(param_1,lVar9);

        local_50 = (undefined8 *******)0x0;

        uStack_48 = 0;

        local_40 = 0;

        uStack_38 = 0;

        sVar8 = strlen(_Str);

        FUN_140027e30(&local_50,_Str,sVar8);

        pppppppuVar10 = &local_50;

        if (0xf < uStack_38) {

          pppppppuVar10 = local_50;

        }

        if (local_40 == 5) {

          lVar9 = 0;

          do {

            lVar5 = lVar9 + 1;

            if (*(byte *)((longlong)pppppppuVar10 + lVar9) != "Horse"[lVar9]) {

              uVar4 = -(uint)(*(byte *)((longlong)pppppppuVar10 + lVar9) < (byte)"Horse"[lVar9]) | 1

              ;

              goto LAB_140060e0d;

            }

            lVar9 = lVar5;

          } while (lVar5 != 5);

          uVar4 = 0;

LAB_140060e0d:

          bVar12 = uVar4 == 0;

        }

        else {

          bVar12 = false;

        }

        if (0xf < uStack_38) {

          pppppppuVar10 = local_50;

          if ((0xfff < uStack_38 + 1) &&

             (pppppppuVar10 = (undefined8 *******)local_50[-1],

             0x1f < (ulonglong)((longlong)local_50 + (-8 - (longlong)pppppppuVar10)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(pppppppuVar10);

        }

        if (bVar12) {

          FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"Hay, why not give %s a new name",

                        uVar7);

        }

      }

      else {

        local_68 = _DAT_1403033f0;

        uStack_60 = _UNK_1403033f8;

        local_78 = (char *)s_Good_luck__140307468._0_8_;

        uStack_70 = (ulonglong)(ushort)s_Good_luck__140307468._8_2_;

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                      CONCAT44(uVar13,DAT_140303758));

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

      }

      FUN_1400d1e10(param_1,param_2,0x19);

      *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 3;

      return 1;

    }

  }

  iVar1 = *(int *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4);

  if (param_3 == 4) {

    if (iVar1 == 4) {

      return 1;

    }

    if (*(int *)(param_1 + 0x1b0) == 0) {

      if (*(char *)(param_1 + 0x294) == '\0') {

        if (iVar1 == 3) {

          FUN_140104b20(DAT_1403fb0d8,0x19,0);

          *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 0xffffffff;

        }

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x30);

        uVar7 = s_The_corral_is_inside_the_fence_p_140307490._8_8_;

        local_68 = _DAT_140305ff0;

        uStack_60 = _UNK_140305ff8;

        *(undefined8 *)local_78 = s_The_corral_is_inside_the_fence_p_140307490._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        uVar7 = s_The_corral_is_inside_the_fence_p_140307490._24_8_;

        *(undefined8 *)(local_78 + 0x10) = s_The_corral_is_inside_the_fence_p_140307490._16_8_;

        *(undefined8 *)(local_78 + 0x18) = uVar7;

        *(undefined4 *)(local_78 + 0x20) = s_The_corral_is_inside_the_fence_p_140307490._32_4_;

        local_78[0x24] = s_The_corral_is_inside_the_fence_p_140307490[0x24];

        local_78[0x25] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                      CONCAT44(uVar13,DAT_140303758));

        if (uStack_60 < 0x10) {

          return 1;

        }

        if ((0xfff < uStack_60 + 1) &&

           ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

        return 1;

      }

      if (*(char *)(param_1 + 0x2b0) != '\0') {

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x30);

        uVar7 = s_Only_one_Champion_entry_at_a_tim_1403074b8._8_8_;

        local_68 = _DAT_140304190;

        uStack_60 = _UNK_140304198;

        *(undefined8 *)local_78 = s_Only_one_Champion_entry_at_a_tim_1403074b8._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        uVar7 = s_Only_one_Champion_entry_at_a_tim_1403074b8._24_8_;

        *(undefined8 *)(local_78 + 0x10) = s_Only_one_Champion_entry_at_a_tim_1403074b8._16_8_;

        *(undefined8 *)(local_78 + 0x18) = uVar7;

        *(undefined8 *)(local_78 + 0x20) = s_Only_one_Champion_entry_at_a_tim_1403074b8._32_8_;

        local_78[0x28] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                      CONCAT44(uVar13,DAT_140303758));

        FUN_140027900(&local_78);

        return 0;

      }

      if (*(char *)(param_1 + 0x295) == '\0') {

        if (iVar1 == 3) {

          FUN_140104b20(DAT_1403fb0d8,0x19,0);

          *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 0xffffffff;

        }

        uVar2 = DAT_140303758;

        local_68 = _DAT_140303400;

        uStack_60 = _UNK_140303408;

        local_78 = (char *)s_Try_again_later_1403074e8._0_8_;

        uStack_70._0_6_ =

             CONCAT24(s_Try_again_later_1403074e8._12_2_,s_Try_again_later_1403074e8._8_4_);

        uStack_70 = (ulonglong)CONCAT16(s_Try_again_later_1403074e8[0xe],(uint6)uStack_70);

        uVar7 = CONCAT44(uVar13,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,uVar7);

        uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

        FUN_140027900(&local_78);

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x50);

        uVar7 = s_There_aren_t_enough_winning_hors_140307500._8_8_;

        local_68 = _DAT_140307a80;

        uStack_60 = _UNK_140307a88;

        *(undefined8 *)local_78 = s_There_aren_t_enough_winning_hors_140307500._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        uVar7 = s_There_aren_t_enough_winning_hors_140307500._24_8_;

        *(undefined8 *)(local_78 + 0x10) = s_There_aren_t_enough_winning_hors_140307500._16_8_;

        *(undefined8 *)(local_78 + 0x18) = uVar7;

        uVar7 = s_There_aren_t_enough_winning_hors_140307500._40_8_;

        *(undefined8 *)(local_78 + 0x20) = s_There_aren_t_enough_winning_hors_140307500._32_8_;

        *(undefined8 *)(local_78 + 0x28) = uVar7;

        uVar7 = s_There_aren_t_enough_winning_hors_140307500._56_8_;

        *(undefined8 *)(local_78 + 0x30) = s_There_aren_t_enough_winning_hors_140307500._48_8_;

        *(undefined8 *)(local_78 + 0x38) = uVar7;

        *(undefined2 *)(local_78 + 0x40) = s_There_aren_t_enough_winning_hors_140307500._64_2_;

        local_78[0x42] = '\0';

        uVar7 = CONCAT44(uVar13,uVar2);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,uVar7);

        uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x20);

        uVar7 = s_Maybe_watch_some_more_races_140307548._8_8_;

        local_68 = _DAT_140304130;

        uStack_60 = _UNK_140304138;

        *(undefined8 *)local_78 = s_Maybe_watch_some_more_races_140307548._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        *(undefined8 *)(local_78 + 0x10) = s_Maybe_watch_some_more_races_140307548._16_8_;

        *(undefined2 *)(local_78 + 0x18) = s_Maybe_watch_some_more_races_140307548._24_2_;

        local_78[0x1a] = s_Maybe_watch_some_more_races_140307548[0x1a];

        local_78[0x1b] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,CONCAT44(uVar13,uVar2));

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        *(int *)(param_1 + 0x270) = *(int *)(param_1 + 0x270) + 1;

        return 1;

      }

      if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) == 2) {

        cVar3 = FUN_140104c00(DAT_1403fb0d8,0xfa,0);

        if (cVar3 != '\0') {

          if (*(int *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) == 3) {

            FUN_140104b20(DAT_1403fb0d8,0x19,0);

          }

          *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 4;

          *(undefined1 *)(param_1 + 0x2b0) = 1;

          uVar7 = *(undefined8 *)(param_1 + 0x148);

          uVar6 = FUN_1400cf9a0(param_1,lVar9);

          FUN_1400d1c40(param_1,uVar7,"%s is a shure fire winner!",uVar6);

          return 1;

        }

        local_68 = _DAT_1403040d0;

        uStack_60 = _UNK_1403040d8;

        local_78 = (char *)s_More_monneeey__140307568._0_8_;

        uStack_70._0_6_ =

             CONCAT24(s_More_monneeey__140307568._12_2_,s_More_monneeey__140307568._8_4_);

        uStack_70 = (ulonglong)(uint6)uStack_70;

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                      CONCAT44(uVar13,DAT_140303758));

        if (uStack_60 < 0x10) {

          return 0;

        }

        if ((0xfff < uStack_60 + 1) &&

           ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      else {

        cVar3 = FUN_1400cfa00(param_1,lVar9,5);

        if (cVar3 != '\0') {

          cVar3 = FUN_140104c00(DAT_1403fb0d8,0xfa,0,0);

          if (cVar3 == '\0') {

            local_78 = (char *)0x0;

            uStack_70 = 0;

            local_68 = 0;

            uStack_60 = 0;

            local_78 = (char *)FUN_1400285e0(0x20);

            uVar7 = s_Not_enough_money_140307478._8_8_;

            local_68 = _DAT_1403040e0;

            uStack_60 = _UNK_1403040e8;

            *(undefined8 *)local_78 = s_Not_enough_money_140307478._0_8_;

            *(undefined8 *)(local_78 + 8) = uVar7;

            local_78[0x10] = '\0';

            FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,

                          CONCAT44(uVar13,DAT_140303758));

            FUN_140027900(&local_78);

            return 0;

          }

          if (*(int *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) == 3) {

            FUN_140104b20(DAT_1403fb0d8,0x19,0);

          }

          *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 4;

          *(undefined1 *)(param_1 + 0x2b0) = 1;

          uVar7 = *(undefined8 *)(param_1 + 0x148);

          uVar6 = FUN_1400cf9a0(param_1,lVar9);

          FUN_1400d1c40(param_1,uVar7,"%s is a sure fire winner!",uVar6);

          cVar3 = FUN_1400b7730(lVar9);

          if (cVar3 == '\0') {

            return 1;

          }

          FUN_1400d1e10(param_1,param_2,0x19);

          return 1;

        }

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x20);

        uVar7 = s_Your_horse_needs_to_win_2_races_140307598._8_8_;

        local_68 = _DAT_140304140;

        uStack_60 = _UNK_140304148;

        *(undefined8 *)local_78 = s_Your_horse_needs_to_win_2_races_140307598._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        *(undefined8 *)(local_78 + 0x10) = s_Your_horse_needs_to_win_2_races_140307598._16_8_;

        *(undefined4 *)(local_78 + 0x18) = s_Your_horse_needs_to_win_2_races_140307598._24_4_;

        *(undefined2 *)(local_78 + 0x1c) = s_Your_horse_needs_to_win_2_races_140307598._28_2_;

        local_78[0x1e] = s_Your_horse_needs_to_win_2_races_140307598[0x1e];

        local_78[0x1f] = '\0';

        uVar2 = DAT_140303758;

        uVar7 = CONCAT44(uVar13,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,uVar7);

        uVar13 = (undefined4)((ulonglong)uVar7 >> 0x20);

        if (0xf < uStack_60) {

          if ((0xfff < uStack_60 + 1) &&

             ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_78 = (char *)0x0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_78 = (char *)FUN_1400285e0(0x30);

        uVar7 = s_Before_it_can_enter_the_Champion_1403075b8._8_8_;

        local_68 = _DAT_140305ff0;

        uStack_60 = _UNK_140305ff8;

        *(undefined8 *)local_78 = s_Before_it_can_enter_the_Champion_1403075b8._0_8_;

        *(undefined8 *)(local_78 + 8) = uVar7;

        uVar7 = s_Before_it_can_enter_the_Champion_1403075b8._24_8_;

        *(undefined8 *)(local_78 + 0x10) = s_Before_it_can_enter_the_Champion_1403075b8._16_8_;

        *(undefined8 *)(local_78 + 0x18) = uVar7;

        *(undefined4 *)(local_78 + 0x20) = s_Before_it_can_enter_the_Champion_1403075b8._32_4_;

        local_78[0x24] = s_Before_it_can_enter_the_Champion_1403075b8[0x24];

        local_78[0x25] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_78,0,CONCAT44(uVar13,uVar2));

        if (uStack_60 < 0x10) {

          return 0;

        }

        if ((0xfff < uStack_60 + 1) &&

           ((char *)0x1f < local_78 + (-8 - *(longlong *)(local_78 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

LAB_140061687:

      FUN_1402c7088();

      return 0;

    }

    if (iVar1 != 3) {

      return 1;

    }

  }

  else if (iVar1 != 3) {

    if (iVar1 == 4) {

      FUN_140104b20(DAT_1403fb0d8,0xfa,0);

      *(undefined1 *)(param_1 + 0x2b0) = 0;

    }

    goto LAB_1400617c2;

  }

  FUN_140104b20(DAT_1403fb0d8,0x19,0);

LAB_1400617c2:

  *(undefined4 *)(*(longlong *)(param_1 + 0x278) + lVar11 * 4) = 0xffffffff;

  return 1;

}





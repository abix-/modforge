// Address: 0x14007f3e0
// Ghidra name: FUN_14007f3e0
// ============ 0x14007f3e0 FUN_14007f3e0 (size=2128) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14007f3e0(longlong param_1,longlong param_2,int param_3)



{

  undefined4 uVar1;

  char cVar2;

  undefined8 in_stack_ffffffffffffffa8;

  undefined4 uVar4;

  undefined8 uVar3;

  undefined8 local_48;

  ulonglong uStack_40;

  undefined8 local_38;

  ulonglong uStack_30;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

  if (*(int *)(param_2 + 8) != 3) {

    return;

  }

  if (*(char *)(param_2 + 0x10) != '\0') {

    return;

  }

  if (param_3 != 0) {

    return;

  }

  if (*(int *)(param_2 + 0xc) == 0) {

    cVar2 = FUN_1400d0c50();

    if (cVar2 == '\0') goto LAB_14007fb3d;

    if (*(char *)(DAT_1403f4e00 + 0x262) != '\0') {

      cVar2 = FUN_140104c00(DAT_1403fb0d8,5,0);

      if (cVar2 == '\0') {

        if (*(char *)(param_1 + 0x250) != '\0') {

          local_48 = (char *)0x0;

          uStack_40 = 0;

          local_38 = 0;

          uStack_30 = 0;

          local_48 = (char *)FUN_1400285e0(0x20);

          uVar3 = s_You_can_t_afford_any_more_hay_14030abf0._8_8_;

          local_38 = _DAT_140304d00;

          uStack_30 = _UNK_140304d08;

          *(undefined8 *)local_48 = s_You_can_t_afford_any_more_hay_14030abf0._0_8_;

          *(undefined8 *)(local_48 + 8) = uVar3;

          *(undefined8 *)(local_48 + 0x10) = s_You_can_t_afford_any_more_hay_14030abf0._16_8_;

          *(undefined4 *)(local_48 + 0x18) = s_You_can_t_afford_any_more_hay_14030abf0._24_4_;

          local_48[0x1c] = s_You_can_t_afford_any_more_hay_14030abf0[0x1c];

          local_48[0x1d] = '\0';

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,

                        CONCAT44(uVar4,DAT_140303758));

          if (uStack_30 < 0x10) goto LAB_14007fa73;

          if ((0xfff < uStack_30 + 1) &&

             ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          goto LAB_14007fa6e;

        }

        if (*(int *)(*(longlong *)(param_1 + 0x148) + 0x1c) != 2) {

          *(undefined1 *)(param_1 + 0x250) = 1;

        }

        local_48 = (char *)0x0;

        uStack_40 = 0;

        local_38 = 0;

        uStack_30 = 0;

        local_48 = (char *)FUN_1400285e0(0x20);

        uVar3 = s_Have_a_hay_on_the_house_14030abb0._8_8_;

        local_38 = _DAT_140304cd0;

        uStack_30 = _UNK_140304cd8;

        *(undefined8 *)local_48 = s_Have_a_hay_on_the_house_14030abb0._0_8_;

        *(undefined8 *)(local_48 + 8) = uVar3;

        *(undefined4 *)(local_48 + 0x10) = s_Have_a_hay_on_the_house_14030abb0._16_4_;

        *(undefined2 *)(local_48 + 0x14) = s_Have_a_hay_on_the_house_14030abb0._20_2_;

        local_48[0x16] = s_Have_a_hay_on_the_house_14030abb0[0x16];

        local_48[0x17] = '\0';

        uVar1 = DAT_140303758;

        uVar3 = CONCAT44(uVar4,DAT_140303758);

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,uVar3);

        uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

        if (0xf < uStack_30) {

          if ((0xfff < uStack_30 + 1) &&

             ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        local_48 = (char *)0x0;

        uStack_40 = 0;

        local_38 = 0;

        uStack_30 = 0;

        local_48 = (char *)FUN_1400285e0(0x30);

        uVar3 = s_But_don_t_build_a_house_out_of_h_14030abc8._8_8_;

        local_38 = _DAT_140304170;

        uStack_30 = _UNK_140304178;

        *(undefined8 *)local_48 = s_But_don_t_build_a_house_out_of_h_14030abc8._0_8_;

        *(undefined8 *)(local_48 + 8) = uVar3;

        uVar3 = s_But_don_t_build_a_house_out_of_h_14030abc8._24_8_;

        *(undefined8 *)(local_48 + 0x10) = s_But_don_t_build_a_house_out_of_h_14030abc8._16_8_;

        *(undefined8 *)(local_48 + 0x18) = uVar3;

        *(undefined2 *)(local_48 + 0x20) = s_But_don_t_build_a_house_out_of_h_14030abc8._32_2_;

        local_48[0x22] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,uVar1));

        if (uStack_30 < 0x10) goto LAB_14007fb3d;

        if ((0xfff < uStack_30 + 1) &&

           ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      else {

        uStack_40 = 0;

        local_38 = _DAT_1403033e0;

        uStack_30 = _UNK_1403033e8;

        local_48 = (char *)(ulonglong)

                           CONCAT16(s_One_hay_14030aba8[6],

                                    CONCAT24(s_One_hay_14030aba8._4_2_,s_One_hay_14030aba8._0_4_));

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,

                      CONCAT44(uVar4,DAT_140303758));

        if (uStack_30 < 0x10) goto LAB_14007fb3d;

        if ((0xfff < uStack_30 + 1) &&

           ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

LAB_14007fb3d:

      *(undefined1 *)(param_2 + 0x10) = 1;

      return;

    }

    local_48 = (char *)0x0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_48 = (char *)FUN_1400285e0(0x20);

    uVar3 = s_You_don_t_need_hay_yet_14030ab90._8_8_;

    local_38 = _DAT_140305fd0;

    uStack_30 = _UNK_140305fd8;

    *(undefined8 *)local_48 = s_You_don_t_need_hay_yet_14030ab90._0_8_;

    *(undefined8 *)(local_48 + 8) = uVar3;

    *(undefined4 *)(local_48 + 0x10) = s_You_don_t_need_hay_yet_14030ab90._16_4_;

    *(undefined2 *)(local_48 + 0x14) = s_You_don_t_need_hay_yet_14030ab90._20_2_;

    local_48[0x16] = '\0';

    uVar1 = DAT_140303758;

    uVar3 = CONCAT44(uVar4,DAT_140303758);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,uVar3);

    uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

    if (0xf < uStack_30) {

      if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (*(int *)(param_1 + 0x308) != 0) goto LAB_14007fa73;

    local_48 = (char *)0x0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    if (*(int *)(DAT_1403fb0d8 + 0x308) < 0x32) {

      local_48 = (char *)FUN_1400285e0(0x40);

      uVar3 = s_Try_betting_on_horse_races_until_14030aac8._8_8_;

      local_38 = _DAT_1403041d0;

      uStack_30 = _UNK_1403041d8;

      *(undefined8 *)local_48 = s_Try_betting_on_horse_races_until_14030aac8._0_8_;

      *(undefined8 *)(local_48 + 8) = uVar3;

      uVar3 = s_Try_betting_on_horse_races_until_14030aac8._24_8_;

      *(undefined8 *)(local_48 + 0x10) = s_Try_betting_on_horse_races_until_14030aac8._16_8_;

      *(undefined8 *)(local_48 + 0x18) = uVar3;

      uVar3 = s_Try_betting_on_horse_races_until_14030aac8._40_8_;

      *(undefined8 *)(local_48 + 0x20) = s_Try_betting_on_horse_races_until_14030aac8._32_8_;

      *(undefined8 *)(local_48 + 0x28) = uVar3;

      *(undefined4 *)(local_48 + 0x30) = s_Try_betting_on_horse_races_until_14030aac8._48_4_;

      *(undefined2 *)(local_48 + 0x34) = s_Try_betting_on_horse_races_until_14030aac8._52_2_;

      local_48[0x36] = s_Try_betting_on_horse_races_until_14030aac8[0x36];

      local_48[0x37] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,uVar1));

      if (uStack_30 < 0x10) goto LAB_14007fa73;

      if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      local_48 = (char *)FUN_1400285e0(0x20);

      uVar3 = s_Grab_that_lasso_up_there_14030aaa8._8_8_;

      local_38 = _DAT_140304120;

      uStack_30 = _UNK_140304128;

      *(undefined8 *)local_48 = s_Grab_that_lasso_up_there_14030aaa8._0_8_;

      *(undefined8 *)(local_48 + 8) = uVar3;

      *(undefined8 *)(local_48 + 0x10) = s_Grab_that_lasso_up_there_14030aaa8._16_8_;

      local_48[0x18] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,uVar1));

      if (uStack_30 < 0x10) goto LAB_14007fa73;

      if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  else {

    if (*(int *)(param_2 + 0xc) != 1) {

      return;

    }

    cVar2 = FUN_1400d0c50();

    if ((cVar2 == '\0') || (cVar2 = FUN_140104c00(DAT_1403fb0d8,0x96,0), cVar2 != '\0')) {

      local_38 = _DAT_1403040b0;

      uStack_30 = _UNK_1403040b8;

      local_48._0_1_ = s_One_hay_bale_14030ac10[0];

      local_48._1_1_ = s_One_hay_bale_14030ac10[1];

      local_48._2_1_ = s_One_hay_bale_14030ac10[2];

      local_48._3_1_ = s_One_hay_bale_14030ac10[3];

      local_48._4_1_ = s_One_hay_bale_14030ac10[4];

      local_48._5_1_ = s_One_hay_bale_14030ac10[5];

      local_48._6_1_ = s_One_hay_bale_14030ac10[6];

      local_48._7_1_ = s_One_hay_bale_14030ac10[7];

      uStack_40 = (ulonglong)(uint)s_One_hay_bale_14030ac10._8_4_;

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,

                    CONCAT44(uVar4,DAT_140303758));

      if (0xf < uStack_30) {

        if ((0xfff < uStack_30 + 1) &&

           (0x1f < ((longlong)local_48 - *(longlong *)((longlong)local_48 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      FUN_14005cf50(param_2);

      goto LAB_14007fb3d;

    }

    local_48 = (char *)0x0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_48 = (char *)FUN_1400285e0(0x20);

    uVar3 = s_You_can_t_afford_that_hay_bale_14030ac20._8_8_;

    local_38 = _DAT_140303770;

    uStack_30 = _UNK_140303778;

    *(undefined8 *)local_48 = s_You_can_t_afford_that_hay_bale_14030ac20._0_8_;

    *(undefined8 *)(local_48 + 8) = uVar3;

    *(undefined8 *)(local_48 + 0x10) = s_You_can_t_afford_that_hay_bale_14030ac20._16_8_;

    *(undefined4 *)(local_48 + 0x18) = s_You_can_t_afford_that_hay_bale_14030ac20._24_4_;

    *(undefined2 *)(local_48 + 0x1c) = s_You_can_t_afford_that_hay_bale_14030ac20._28_2_;

    local_48[0x1e] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,DAT_140303758)

                 );

    if (uStack_30 < 0x10) goto LAB_14007fa73;

    if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

LAB_14007fa6e:

  FUN_1402c7088();

LAB_14007fa73:

  FUN_1400a8890(param_2);

  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;

  return;

}





// Address: 0x14002f300
// Ghidra name: FUN_14002f300
// ============ 0x14002f300 FUN_14002f300 (size=1698) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14002f300(longlong param_1,int param_2)



{

  int iVar1;

  undefined4 uVar2;

  char cVar3;

  uint uVar4;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar6;

  undefined8 uVar5;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  cVar3 = FUN_1400d0c50();

  if (cVar3 == '\0') {

    return;

  }

  if (*(longlong *)(param_1 + 0x148) !=

      *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8)) {

    return;

  }

  if ((*(int *)(param_1 + 600) == 1) &&

     (1 < (ulonglong)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3))) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar5 = _UNK_140303520;

    local_28 = _DAT_140303770;

    uStack_20 = _UNK_140303778;

    *(undefined8 *)local_38 = _DAT_140303518;

    *(undefined8 *)((longlong)local_38 + 8) = uVar5;

    *(undefined8 *)((longlong)local_38 + 0x10) = _DAT_140303528;

    *(undefined4 *)((longlong)local_38 + 0x18) = s_scratched_14030352d._3_4_;

    *(undefined2 *)((longlong)local_38 + 0x1c) = s_scratched_14030352d._7_2_;

    *(undefined1 *)((longlong)local_38 + 0x1e) = 0;

    uVar2 = DAT_140303758;

    uVar5 = CONCAT44(uVar6,DAT_140303758);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar5);

    uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) &&

         (0x1f < (ulonglong)((longlong)local_38 + (-8 - *(longlong *)((longlong)local_38 + -8))))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x40);

    uVar5 = _UNK_140303540;

    local_28 = _DAT_1403037a0;

    uStack_20 = _UNK_1403037a8;

    *(undefined8 *)local_38 = _DAT_140303538;

    *(undefined8 *)((longlong)local_38 + 8) = uVar5;

    uVar5 = _UNK_140303550;

    *(undefined8 *)((longlong)local_38 + 0x10) = _DAT_140303548;

    *(undefined8 *)((longlong)local_38 + 0x18) = uVar5;

    uVar5 = _UNK_140303560;

    *(undefined8 *)((longlong)local_38 + 0x20) = _DAT_140303558;

    *(undefined8 *)((longlong)local_38 + 0x28) = uVar5;

    *(undefined1 *)((longlong)local_38 + 0x30) = DAT_140303568;

    *(undefined1 *)((longlong)local_38 + 0x31) = 0;

    uVar5 = CONCAT44(uVar6,uVar2);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar5);

    uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) &&

         (0x1f < (ulonglong)((longlong)local_38 + (-8 - *(longlong *)((longlong)local_38 + -8))))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    uStack_30 = 0;

    local_28 = _DAT_1403033d0;

    uStack_20 = _UNK_1403033d8;

    local_38 = (char *)(ulonglong)CONCAT24(s_Try_it_14030356c._4_2_,s_Try_it_14030356c._0_4_);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar6,uVar2));

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) &&

         (0x1f < ((longlong)local_38 - *(longlong *)((longlong)local_38 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(undefined4 *)(param_1 + 600) = 2;

    *(undefined4 *)(param_1 + 0x254) = 0;

    return;

  }

  iVar1 = *(int *)(param_1 + 0x254);

  if (iVar1 == 0) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x30);

    uVar5 = s_I_ll_take_care_of_your_old_horse_140303578._8_8_;

    local_28 = _DAT_140303780;

    uStack_20 = _UNK_140303788;

    *(undefined8 *)local_38 = s_I_ll_take_care_of_your_old_horse_140303578._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar5;

    uVar5 = s_I_ll_take_care_of_your_old_horse_140303578._24_8_;

    *(undefined8 *)(local_38 + 0x10) = s_I_ll_take_care_of_your_old_horse_140303578._16_8_;

    *(undefined8 *)(local_38 + 0x18) = uVar5;

    *(undefined8 *)(local_38 + 0x20) = s_I_ll_take_care_of_your_old_horse_140303578._32_8_;

    *(undefined2 *)(local_38 + 0x28) = s_I_ll_take_care_of_your_old_horse_140303578._40_2_;

    local_38[0x2a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar6,DAT_140303758)

                 );

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (*(int *)(param_1 + 600) < 3) {

      *(undefined4 *)(param_1 + 600) = 1;

    }

    goto LAB_14002f8c9;

  }

  if (iVar1 == 1) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x50);

    uVar5 = s_They_ll_be_fed_and_sheltered_and_1403035b0._8_8_;

    local_28 = _DAT_1403037c0;

    uStack_20 = _UNK_1403037c8;

    *(undefined8 *)local_38 = s_They_ll_be_fed_and_sheltered_and_1403035b0._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar5;

    uVar5 = s_They_ll_be_fed_and_sheltered_and_1403035b0._24_8_;

    *(undefined8 *)(local_38 + 0x10) = s_They_ll_be_fed_and_sheltered_and_1403035b0._16_8_;

    *(undefined8 *)(local_38 + 0x18) = uVar5;

    uVar5 = s_They_ll_be_fed_and_sheltered_and_1403035b0._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_They_ll_be_fed_and_sheltered_and_1403035b0._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar5;

    uVar5 = s_They_ll_be_fed_and_sheltered_and_1403035b0._56_8_;

    *(undefined8 *)(local_38 + 0x30) = s_They_ll_be_fed_and_sheltered_and_1403035b0._48_8_;

    *(undefined8 *)(local_38 + 0x38) = uVar5;

    local_38[0x40] = s_They_ll_be_fed_and_sheltered_and_1403035b0[0x40];

    local_38[0x41] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar6,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14002f8c9;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar1 == 2) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x30);

    uVar5 = s__100_is_not_much__What_are_the_o_1403035f8._8_8_;

    local_28 = _DAT_140303790;

    uStack_20 = _UNK_140303798;

    *(undefined8 *)local_38 = s__100_is_not_much__What_are_the_o_1403035f8._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar5;

    uVar5 = s__100_is_not_much__What_are_the_o_1403035f8._24_8_;

    *(undefined8 *)(local_38 + 0x10) = s__100_is_not_much__What_are_the_o_1403035f8._16_8_;

    *(undefined8 *)(local_38 + 0x18) = uVar5;

    *(undefined8 *)(local_38 + 0x20) = s__100_is_not_much__What_are_the_o_1403035f8._32_8_;

    *(undefined4 *)(local_38 + 0x28) = s__100_is_not_much__What_are_the_o_1403035f8._40_4_;

    local_38[0x2c] = s__100_is_not_much__What_are_the_o_1403035f8[0x2c];

    local_38[0x2d] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar6,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14002f8c9;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (iVar1 != 3) goto LAB_14002f8c9;

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x40);

    uVar5 = s_And_you_can_come_back_any_time_t_140303628._8_8_;

    local_28 = _DAT_1403037b0;

    uStack_20 = _UNK_1403037b8;

    *(undefined8 *)local_38 = s_And_you_can_come_back_any_time_t_140303628._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar5;

    uVar5 = s_And_you_can_come_back_any_time_t_140303628._24_8_;

    *(undefined8 *)(local_38 + 0x10) = s_And_you_can_come_back_any_time_t_140303628._16_8_;

    *(undefined8 *)(local_38 + 0x18) = uVar5;

    uVar5 = s_And_you_can_come_back_any_time_t_140303628._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_And_you_can_come_back_any_time_t_140303628._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar5;

    *(undefined8 *)(local_38 + 0x30) = s_And_you_can_come_back_any_time_t_140303628._48_8_;

    local_38[0x38] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar6,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14002f8c9;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_14002f8c9:

  uVar4 = *(int *)(param_1 + 0x254) + 1U & 0x80000003;

  if ((int)uVar4 < 0) {

    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;

  }

  *(uint *)(param_1 + 0x254) = uVar4;

  return;

}





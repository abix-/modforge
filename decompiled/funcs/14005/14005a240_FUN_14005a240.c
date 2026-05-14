// Address: 0x14005a240
// Ghidra name: FUN_14005a240
// ============ 0x14005a240 FUN_14005a240 (size=1234) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005a240(longlong param_1,int param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  char cVar6;

  uint uVar7;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar8;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  cVar6 = FUN_1400d0c50();

  if (cVar6 == '\0') {

    return;

  }

  if (*(longlong *)(param_1 + 0x148) !=

      *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8)) {

    return;

  }

  *(undefined4 *)(param_1 + 0x158) = DAT_1403d4b68;

  iVar1 = *(int *)(param_1 + 0x2c8);

  if (*(int *)(param_1 + 0x254) == 2) {

    if (iVar1 != 0) {

      return;

    }

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_I_worked_hard_for_this_140305e08._8_8_;

    local_28 = _DAT_140305fd0;

    uStack_20 = _UNK_140305fd8;

    *(undefined8 *)local_38 = s_I_worked_hard_for_this_140305e08._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    *(undefined4 *)(local_38 + 0x10) = s_I_worked_hard_for_this_140305e08._16_4_;

    *(undefined2 *)(local_38 + 0x14) = s_I_worked_hard_for_this_140305e08._20_2_;

    local_38[0x16] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

    return;

  }

  if (iVar1 == 0) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_Check_out_my_research_goals_140305e20._8_8_;

    local_28 = _DAT_140304130;

    uStack_20 = _UNK_140304138;

    *(undefined8 *)local_38 = s_Check_out_my_research_goals_140305e20._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    *(undefined8 *)(local_38 + 0x10) = s_Check_out_my_research_goals_140305e20._16_8_;

    *(undefined2 *)(local_38 + 0x18) = s_Check_out_my_research_goals_140305e20._24_2_;

    local_38[0x1a] = s_Check_out_my_research_goals_140305e20[0x1a];

    local_38[0x1b] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14005a66e;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar1 == 1) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x30);

    uVar2 = s_Ecosystem__More_like_freakosyste_140305e40._8_8_;

    local_28 = _DAT_140304160;

    uStack_20 = _UNK_140304168;

    *(undefined8 *)local_38 = s_Ecosystem__More_like_freakosyste_140305e40._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    uVar5 = s_Ecosystem__More_like_freakosyste_140305e40._28_4_;

    uVar4 = s_Ecosystem__More_like_freakosyste_140305e40._24_4_;

    uVar3 = s_Ecosystem__More_like_freakosyste_140305e40._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_Ecosystem__More_like_freakosyste_140305e40._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar3;

    *(undefined4 *)(local_38 + 0x18) = uVar4;

    *(undefined4 *)(local_38 + 0x1c) = uVar5;

    local_38[0x20] = s_Ecosystem__More_like_freakosyste_140305e40[0x20];

    local_38[0x21] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14005a66e;

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

    local_38 = (char *)FUN_1400285e0(0x40);

    uVar2 = s_The_east_end_of_the_island_is_sp_140305e68._8_8_;

    local_28 = _DAT_1403041b0;

    uStack_20 = _UNK_1403041b8;

    *(undefined8 *)local_38 = s_The_east_end_of_the_island_is_sp_140305e68._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    uVar5 = s_The_east_end_of_the_island_is_sp_140305e68._28_4_;

    uVar4 = s_The_east_end_of_the_island_is_sp_140305e68._24_4_;

    uVar3 = s_The_east_end_of_the_island_is_sp_140305e68._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_The_east_end_of_the_island_is_sp_140305e68._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar3;

    *(undefined4 *)(local_38 + 0x18) = uVar4;

    *(undefined4 *)(local_38 + 0x1c) = uVar5;

    uVar2 = s_The_east_end_of_the_island_is_sp_140305e68._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_The_east_end_of_the_island_is_sp_140305e68._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar2;

    local_38[0x30] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14005a66e;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (iVar1 != 3) goto LAB_14005a66e;

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x40);

    uVar2 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._8_8_;

    local_28 = _DAT_1403037b0;

    uStack_20 = _UNK_1403037b8;

    *(undefined8 *)local_38 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    uVar5 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._28_4_;

    uVar4 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._24_4_;

    uVar3 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar3;

    *(undefined4 *)(local_38 + 0x18) = uVar4;

    *(undefined4 *)(local_38 + 0x1c) = uVar5;

    uVar2 = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar2;

    *(undefined8 *)(local_38 + 0x30) = s_The_Nuclear_Power_Plant_helps_ke_140305ea0._48_8_;

    local_38[0x38] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14005a66e;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_14005a66e:

  uVar7 = *(int *)(param_1 + 0x2c8) + 1U & 0x80000003;

  if ((int)uVar7 < 0) {

    uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;

  }

  *(uint *)(param_1 + 0x2c8) = uVar7;

  return;

}





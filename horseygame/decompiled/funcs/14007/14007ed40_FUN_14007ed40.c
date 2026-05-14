// Address: 0x14007ed40
// Ghidra name: FUN_14007ed40
// ============ 0x14007ed40 FUN_14007ed40 (size=1627) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14007ed40(longlong param_1,int param_2)



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

  if (*(char *)(DAT_1403fb0d8 + 0x415) == '\0') {

    if (*(int *)(param_1 + 0x308) == 0) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      if (*(int *)(DAT_1403fb0d8 + 0x308) < 0x32) {

        local_38 = (char *)FUN_1400285e0(0x40);

        uVar2 = s_Try_betting_on_horse_races_until_14030aac8._8_8_;

        local_28 = _DAT_1403041d0;

        uStack_20 = _UNK_1403041d8;

        *(undefined8 *)local_38 = s_Try_betting_on_horse_races_until_14030aac8._0_8_;

        *(undefined8 *)(local_38 + 8) = uVar2;

        uVar5 = s_Try_betting_on_horse_races_until_14030aac8._28_4_;

        uVar4 = s_Try_betting_on_horse_races_until_14030aac8._24_4_;

        uVar3 = s_Try_betting_on_horse_races_until_14030aac8._20_4_;

        *(undefined4 *)(local_38 + 0x10) = s_Try_betting_on_horse_races_until_14030aac8._16_4_;

        *(undefined4 *)(local_38 + 0x14) = uVar3;

        *(undefined4 *)(local_38 + 0x18) = uVar4;

        *(undefined4 *)(local_38 + 0x1c) = uVar5;

        uVar2 = s_Try_betting_on_horse_races_until_14030aac8._40_8_;

        *(undefined8 *)(local_38 + 0x20) = s_Try_betting_on_horse_races_until_14030aac8._32_8_;

        *(undefined8 *)(local_38 + 0x28) = uVar2;

        *(undefined4 *)(local_38 + 0x30) = s_Try_betting_on_horse_races_until_14030aac8._48_4_;

        *(undefined2 *)(local_38 + 0x34) = s_Try_betting_on_horse_races_until_14030aac8._52_2_;

        local_38[0x36] = s_Try_betting_on_horse_races_until_14030aac8[0x36];

        local_38[0x37] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      else {

        local_38 = (char *)FUN_1400285e0(0x20);

        uVar2 = s_Grab_that_lasso_up_there_14030aaa8._8_8_;

        local_28 = _DAT_140304120;

        uStack_20 = _UNK_140304128;

        *(undefined8 *)local_38 = s_Grab_that_lasso_up_there_14030aaa8._0_8_;

        *(undefined8 *)(local_38 + 8) = uVar2;

        *(undefined8 *)(local_38 + 0x10) = s_Grab_that_lasso_up_there_14030aaa8._16_8_;

        local_38[0x18] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

    }

    else {

      iVar1 = *(int *)(param_1 + 0x304);

      if (iVar1 == 0) {

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x30);

        uVar2 = _UNK_14030ab08;

        local_28 = _DAT_140304d10;

        uStack_20 = _UNK_140304d18;

        *(undefined8 *)local_38 = _DAT_14030ab00;

        *(undefined8 *)(local_38 + 8) = uVar2;

        uVar5 = _UNK_14030ab1c;

        uVar4 = _UNK_14030ab18;

        uVar3 = _UNK_14030ab14;

        *(undefined4 *)(local_38 + 0x10) = _DAT_14030ab10;

        *(undefined4 *)(local_38 + 0x14) = uVar3;

        *(undefined4 *)(local_38 + 0x18) = uVar4;

        *(undefined4 *)(local_38 + 0x1c) = uVar5;

        *(undefined4 *)(local_38 + 0x20) = DAT_14030ab20;

        local_38[0x24] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

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

        uVar2 = _UNK_14030ab30;

        local_28 = _DAT_140304190;

        uStack_20 = _UNK_140304198;

        *(undefined8 *)local_38 = _DAT_14030ab28;

        *(undefined8 *)(local_38 + 8) = uVar2;

        uVar5 = _UNK_14030ab44;

        uVar4 = _UNK_14030ab40;

        uVar3 = _UNK_14030ab3c;

        *(undefined4 *)(local_38 + 0x10) = _DAT_14030ab38;

        *(undefined4 *)(local_38 + 0x14) = uVar3;

        *(undefined4 *)(local_38 + 0x18) = uVar4;

        *(undefined4 *)(local_38 + 0x1c) = uVar5;

        *(undefined8 *)(local_38 + 0x20) = _DAT_14030ab48;

        local_38[0x28] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      else if (iVar1 == 2) {

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x20);

        uVar2 = _UNK_14030ab60;

        local_28 = _DAT_140304cf0;

        uStack_20 = _UNK_140304cf8;

        *(undefined8 *)local_38 = _DAT_14030ab58;

        *(undefined8 *)(local_38 + 8) = uVar2;

        *(undefined8 *)(local_38 + 0x10) = _DAT_14030ab68;

        *(undefined4 *)(local_38 + 0x18) = s_shovel_14030ab6e._2_4_;

        local_38[0x1c] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      else {

        if (iVar1 != 3) goto LAB_14007f2c7;

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x20);

        uVar2 = s_Being_a_cowboy_is_easy_14030ab78._8_8_;

        local_28 = _DAT_140305fd0;

        uStack_20 = _UNK_140305fd8;

        *(undefined8 *)local_38 = s_Being_a_cowboy_is_easy_14030ab78._0_8_;

        *(undefined8 *)(local_38 + 8) = uVar2;

        *(undefined4 *)(local_38 + 0x10) = s_Being_a_cowboy_is_easy_14030ab78._16_4_;

        *(undefined2 *)(local_38 + 0x14) = s_Being_a_cowboy_is_easy_14030ab78._20_2_;

        local_38[0x16] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar8,DAT_140303758));

        if (uStack_20 < 0x10) goto LAB_14007f2c7;

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

    }

  }

  else {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x30);

    uVar2 = s_I_saw_wild_horses_south_west_of_h_14030a9b8._8_8_;

    local_28 = _DAT_140304d10;

    uStack_20 = _UNK_140304d18;

    *(undefined8 *)local_38 = s_I_saw_wild_horses_south_west_of_h_14030a9b8._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    uVar5 = s_I_saw_wild_horses_south_west_of_h_14030a9b8._28_4_;

    uVar4 = s_I_saw_wild_horses_south_west_of_h_14030a9b8._24_4_;

    uVar3 = s_I_saw_wild_horses_south_west_of_h_14030a9b8._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_I_saw_wild_horses_south_west_of_h_14030a9b8._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar3;

    *(undefined4 *)(local_38 + 0x18) = uVar4;

    *(undefined4 *)(local_38 + 0x1c) = uVar5;

    *(undefined4 *)(local_38 + 0x20) = s_I_saw_wild_horses_south_west_of_h_14030a9b8._32_4_;

    local_38[0x24] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_20 < 0x10) goto LAB_14007f2c7;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_14007f2c7:

  uVar7 = *(int *)(param_1 + 0x304) + 1U & 0x80000003;

  if ((int)uVar7 < 0) {

    uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;

  }

  *(uint *)(param_1 + 0x304) = uVar7;

  return;

}





// Address: 0x14005c3d0
// Ghidra name: FUN_14005c3d0
// ============ 0x14005c3d0 FUN_14005c3d0 (size=476) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005c3d0(longlong param_1,int param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 in_stack_ffffffffffffffa8;

  undefined4 uVar6;

  undefined8 uVar5;

  char *local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  ulonglong uStack_30;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

  if (((*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) ==

        *(longlong *)(param_1 + 0x148)) && (*(char *)(param_1 + 0x254) != '\0')) &&

     (0x3c < *(int *)(param_1 + 0x250))) {

    local_48 = (char *)0x0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_48 = (char *)FUN_1400285e0(0x30);

    uVar5 = s_If_you_want_to_hear_my_story_aga_140306558._8_8_;

    local_38 = _DAT_140304170;

    uStack_30 = _UNK_140304178;

    *(undefined8 *)local_48 = s_If_you_want_to_hear_my_story_aga_140306558._0_8_;

    *(undefined8 *)(local_48 + 8) = uVar5;

    uVar3 = s_If_you_want_to_hear_my_story_aga_140306558._28_4_;

    uVar2 = s_If_you_want_to_hear_my_story_aga_140306558._24_4_;

    uVar1 = s_If_you_want_to_hear_my_story_aga_140306558._20_4_;

    *(undefined4 *)(local_48 + 0x10) = s_If_you_want_to_hear_my_story_aga_140306558._16_4_;

    *(undefined4 *)(local_48 + 0x14) = uVar1;

    *(undefined4 *)(local_48 + 0x18) = uVar2;

    *(undefined4 *)(local_48 + 0x1c) = uVar3;

    *(undefined2 *)(local_48 + 0x20) = s_If_you_want_to_hear_my_story_aga_140306558._32_2_;

    local_48[0x22] = '\0';

    uVar1 = DAT_140303758;

    uVar5 = CONCAT44(uVar6,DAT_140303758);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,uVar5);

    uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);

    if (0xf < uStack_30) {

      if (0xfff < uStack_30 + 1) {

        if ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    local_48 = (char *)0x0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_48 = (char *)FUN_1400285e0(0x30);

    uVar5 = s_You_ll_have_to_leave_and_come_ba_140306580._8_8_;

    local_38 = _DAT_140304170;

    uStack_30 = _UNK_140304178;

    *(undefined8 *)local_48 = s_You_ll_have_to_leave_and_come_ba_140306580._0_8_;

    *(undefined8 *)(local_48 + 8) = uVar5;

    uVar4 = s_You_ll_have_to_leave_and_come_ba_140306580._28_4_;

    uVar3 = s_You_ll_have_to_leave_and_come_ba_140306580._24_4_;

    uVar2 = s_You_ll_have_to_leave_and_come_ba_140306580._20_4_;

    *(undefined4 *)(local_48 + 0x10) = s_You_ll_have_to_leave_and_come_ba_140306580._16_4_;

    *(undefined4 *)(local_48 + 0x14) = uVar2;

    *(undefined4 *)(local_48 + 0x18) = uVar3;

    *(undefined4 *)(local_48 + 0x1c) = uVar4;

    *(undefined2 *)(local_48 + 0x20) = s_You_ll_have_to_leave_and_come_ba_140306580._32_2_;

    local_48[0x22] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar6,uVar1));

    if (0xf < uStack_30) {

      if (0xfff < uStack_30 + 1) {

        if ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return;

}





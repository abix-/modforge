// Address: 0x14005e930
// Ghidra name: FUN_14005e930
// ============ 0x14005e930 FUN_14005e930 (size=1653) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005e930(longlong param_1,int param_2)



{

  char *pcVar1;

  undefined4 uVar2;

  int iVar3;

  size_t sVar4;

  int iVar5;

  longlong lVar6;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar8;

  undefined8 uVar7;

  undefined8 local_38;

  ulonglong uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  if (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) !=

      *(longlong *)(param_1 + 0x148)) {

    return;

  }

  if (*(longlong *)(param_1 + 0x260) != 0) {

    if ((*(int *)(*(longlong *)(param_1 + 0x260) + 0x1c) == 6) &&

       (*(char *)(param_1 + 0x268) == '\0')) {

      *(undefined1 *)(param_1 + 0x268) = 1;

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar7 = s_Clarence_is_dead_now_140307148._8_8_;

      local_28 = _DAT_140303420;

      uStack_20 = _UNK_140303428;

      *(undefined8 *)local_38 = s_Clarence_is_dead_now_140307148._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar7;

      *(undefined4 *)(local_38 + 0x10) = s_Clarence_is_dead_now_140307148._16_4_;

      local_38[0x14] = '\0';

      uVar2 = DAT_140303758;

      uVar7 = CONCAT44(uVar8,DAT_140303758);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar7);

      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      uStack_30 = 0;

      local_28 = _DAT_1403033e0;

      uStack_20 = _UNK_1403033e8;

      local_38 = (char *)(ulonglong)

                         CONCAT16(s_Finally_140307160[6],

                                  CONCAT24(s_Finally_140307160._4_2_,s_Finally_140307160._0_4_));

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,uVar2));

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) &&

         (0x1f < ((longlong)local_38 - *(longlong *)((longlong)local_38 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      goto LAB_14005eec1;

    }

    if (*(char *)(param_1 + 0x269) == '\0') {

      *(undefined1 *)(param_1 + 0x269) = 1;

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar7 = s_Look_at_this_awful_thing_140307168._8_8_;

      local_28 = _DAT_140304120;

      uStack_20 = _UNK_140304128;

      *(undefined8 *)local_38 = s_Look_at_this_awful_thing_140307168._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar7;

      *(undefined8 *)(local_38 + 0x10) = s_Look_at_this_awful_thing_140307168._16_8_;

      local_38[0x18] = '\0';

      uVar2 = DAT_140303758;

      uVar7 = CONCAT44(uVar8,DAT_140303758);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar7);

      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

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

      uVar7 = s_My_so_called_friend_won_the_cham_140307188._8_8_;

      local_28 = _DAT_1403041b0;

      uStack_20 = _UNK_1403041b8;

      *(undefined8 *)local_38 = s_My_so_called_friend_won_the_cham_140307188._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar7;

      uVar7 = s_My_so_called_friend_won_the_cham_140307188._24_8_;

      *(undefined8 *)(local_38 + 0x10) = s_My_so_called_friend_won_the_cham_140307188._16_8_;

      *(undefined8 *)(local_38 + 0x18) = uVar7;

      uVar7 = s_My_so_called_friend_won_the_cham_140307188._40_8_;

      *(undefined8 *)(local_38 + 0x20) = s_My_so_called_friend_won_the_cham_140307188._32_8_;

      *(undefined8 *)(local_38 + 0x28) = uVar7;

      local_38[0x30] = '\0';

      uVar7 = CONCAT44(uVar8,uVar2);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar7);

      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

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

      uVar7 = s_But_then_I_got_stuck_with_it_whe_1403071c0._8_8_;

      local_28 = _DAT_1403037b0;

      uStack_20 = _UNK_1403037b8;

      *(undefined8 *)local_38 = s_But_then_I_got_stuck_with_it_whe_1403071c0._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar7;

      uVar7 = s_But_then_I_got_stuck_with_it_whe_1403071c0._24_8_;

      *(undefined8 *)(local_38 + 0x10) = s_But_then_I_got_stuck_with_it_whe_1403071c0._16_8_;

      *(undefined8 *)(local_38 + 0x18) = uVar7;

      uVar7 = s_But_then_I_got_stuck_with_it_whe_1403071c0._40_8_;

      *(undefined8 *)(local_38 + 0x20) = s_But_then_I_got_stuck_with_it_whe_1403071c0._32_8_;

      *(undefined8 *)(local_38 + 0x28) = uVar7;

      *(undefined8 *)(local_38 + 0x30) = s_But_then_I_got_stuck_with_it_whe_1403071c0._48_8_;

      local_38[0x38] = '\0';

      uVar7 = CONCAT44(uVar8,uVar2);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar7);

      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_28 = _DAT_1403040a0;

      uStack_20 = _UNK_1403040a8;

      local_38._0_1_ = s_Clarence__140307200[0];

      local_38._1_1_ = s_Clarence__140307200[1];

      local_38._2_1_ = s_Clarence__140307200[2];

      local_38._3_1_ = s_Clarence__140307200[3];

      local_38._4_1_ = s_Clarence__140307200[4];

      local_38._5_1_ = s_Clarence__140307200[5];

      local_38._6_1_ = s_Clarence__140307200[6];

      local_38._7_1_ = s_Clarence__140307200[7];

      uStack_30 = (ulonglong)(byte)s_Clarence__140307200[8];

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,uVar2));

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) &&

         (0x1f < ((longlong)local_38 - *(longlong *)((longlong)local_38 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      goto LAB_14005eec1;

    }

  }

  iVar5 = 0;

  while( true ) {

    iVar3 = FUN_1400c6580(0xe);

    uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

    lVar6 = (longlong)iVar3;

    if ((&DAT_1403d5fe0)[lVar6 * 0x18] == '\0') break;

    if (((*(longlong *)(param_1 + 0x260) != 0) &&

        (*(int *)(*(longlong *)(param_1 + 0x260) + 0x1c) != 6)) || (iVar5 = iVar5 + 1, 9 < iVar5))

    break;

  }

  pcVar1 = (&PTR_s_I_m_NOT_Bald__1403d5fd0)[lVar6 * 3];

  local_38 = (char *)0x0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  sVar4 = strlen(pcVar1);

  FUN_140027e30(&local_38,pcVar1,sVar4);

  uVar2 = DAT_140303758;

  uVar7 = CONCAT44(uVar8,DAT_140303758);

  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar7);

  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);

  if (0xf < uStack_20) {

    if ((0xfff < uStack_20 + 1) &&

       (0x1f < ((longlong)local_38 - *(longlong *)((longlong)local_38 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  pcVar1 = *(char **)(&DAT_1403d5fd8 + lVar6 * 0x18);

  if (pcVar1 == (char *)0x0) {

    return;

  }

  local_38 = (char *)0x0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  sVar4 = strlen(pcVar1);

  FUN_140027e30(&local_38,pcVar1,sVar4);

  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar8,uVar2));

  if (uStack_20 < 0x10) {

    return;

  }

  if ((0xfff < uStack_20 + 1) &&

     (0x1f < ((longlong)local_38 - *(longlong *)((longlong)local_38 - 8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

  }

LAB_14005eec1:

  FUN_1402c7088();

  return;

}





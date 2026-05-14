// Address: 0x14003ea10
// Ghidra name: FUN_14003ea10
// ============ 0x14003ea10 FUN_14003ea10 (size=766) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14003ea10(longlong param_1,int param_2)



{

  undefined8 uVar1;

  int iVar2;

  longlong lVar3;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar4;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar3 = (longlong)param_2;

  if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8) + 0x204) != '\0') {

    return;

  }

  if (DAT_1403ea270 == 0) {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar1 = s_You_re_not_supposed_to_be_here_140304ee8._8_8_;

    local_18 = _DAT_140303770;

    uStack_10 = _UNK_140303778;

    *(undefined8 *)local_28 = s_You_re_not_supposed_to_be_here_140304ee8._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar1;

    *(undefined8 *)(local_28 + 0x10) = s_You_re_not_supposed_to_be_here_140304ee8._16_8_;

    *(undefined4 *)(local_28 + 0x18) = s_You_re_not_supposed_to_be_here_140304ee8._24_4_;

    *(undefined2 *)(local_28 + 0x1c) = s_You_re_not_supposed_to_be_here_140304ee8._28_2_;

    local_28[0x1e] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8),&local_28,0,

                  CONCAT44(uVar4,DAT_140303758));

    if (uStack_10 < 0x10) goto LAB_14003ec9a;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (DAT_1403ea270 == 1) {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar1 = s_This_place_isn_t_built_yet_140304f08._8_8_;

    local_18 = _DAT_140304ce0;

    uStack_10 = _UNK_140304ce8;

    *(undefined8 *)local_28 = s_This_place_isn_t_built_yet_140304f08._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar1;

    *(undefined8 *)(local_28 + 0x10) = s_This_place_isn_t_built_yet_140304f08._16_8_;

    *(undefined2 *)(local_28 + 0x18) = s_This_place_isn_t_built_yet_140304f08._24_2_;

    local_28[0x1a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8),&local_28,0,

                  CONCAT44(uVar4,DAT_140303758));

    if (uStack_10 < 0x10) goto LAB_14003ec9a;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (DAT_1403ea270 != 2) goto LAB_14003ec9a;

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar1 = s_Be_gone__Vamoose__140304f28._8_8_;

    local_18 = _DAT_1403040f0;

    uStack_10 = _UNK_1403040f8;

    *(undefined8 *)local_28 = s_Be_gone__Vamoose__140304f28._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar1;

    local_28[0x10] = s_Be_gone__Vamoose__140304f28[0x10];

    local_28[0x11] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8),&local_28,0,

                  CONCAT44(uVar4,DAT_140303758));

    if (uStack_10 < 0x10) goto LAB_14003ec9a;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_14003ec9a:

  iVar2 = DAT_1403ea270 + 1;

  DAT_1403ea270 =

       iVar2 + (iVar2 / 3 + (iVar2 >> 0x1f) +

               (int)(((longlong)iVar2 / 3 + ((longlong)iVar2 >> 0x3f) & 0xffffffffU) >> 0x1f)) * -3;

  return;

}





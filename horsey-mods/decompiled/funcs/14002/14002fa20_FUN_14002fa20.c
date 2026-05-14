// Address: 0x14002fa20
// Ghidra name: FUN_14002fa20
// ============ 0x14002fa20 FUN_14002fa20 (size=979) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14002fa20(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  longlong *plVar2;

  longlong lVar3;

  char cVar4;

  undefined8 uVar5;

  longlong lVar6;

  longlong local_res8;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar7;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  local_res8 = lVar1;

  if (param_3 != 3) {

    if (((param_3 == 0) && (*(char *)(lVar1 + 0x204) == '\0')) &&

       (lVar3 = *(longlong *)(param_1 + 0x268),

       lVar6 = thunk_FUN_1402c62d0(*(undefined8 *)(param_1 + 0x260),lVar3,lVar1), lVar6 != lVar3)) {

      local_28 = (char *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (char *)FUN_1400285e0(0x20);

      uVar5 = s_Oh__you_changed_your_mind_1403036b8._8_8_;

      local_18 = _DAT_140303760;

      uStack_10 = _UNK_140303768;

      *(undefined8 *)local_28 = s_Oh__you_changed_your_mind_1403036b8._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar5;

      *(undefined8 *)(local_28 + 0x10) = s_Oh__you_changed_your_mind_1403036b8._16_8_;

      local_28[0x18] = s_Oh__you_changed_your_mind_1403036b8[0x18];

      local_28[0x19] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar7,DAT_140303758));

      if (0xf < uStack_10) {

        if ((0xfff < uStack_10 + 1) &&

           ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      *(undefined1 *)(lVar1 + 0x204) = 1;

      FUN_140104b20(DAT_1403fb0d8,100,0);

    }

    return 1;

  }

  if (*(char *)(lVar1 + 0x204) == '\0') {

    return 1;

  }

  cVar4 = FUN_1400b76a0(lVar1);

  if (cVar4 == '\0') {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar5 = s_I_only_take_care_of_old_horses_140303698._8_8_;

    local_18 = _DAT_140303770;

    uStack_10 = _UNK_140303778;

    *(undefined8 *)local_28 = s_I_only_take_care_of_old_horses_140303698._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar5;

    *(undefined8 *)(local_28 + 0x10) = s_I_only_take_care_of_old_horses_140303698._16_8_;

    *(undefined4 *)(local_28 + 0x18) = s_I_only_take_care_of_old_horses_140303698._24_4_;

    *(undefined2 *)(local_28 + 0x1c) = s_I_only_take_care_of_old_horses_140303698._28_2_;

    local_28[0x1e] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar7,DAT_140303758)

                 );

    if (uStack_10 < 0x10) {

      return 0;

    }

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    cVar4 = FUN_140104c00(DAT_1403fb0d8,100,0);

    if (cVar4 != '\0') {

      *(undefined1 *)(lVar1 + 0x204) = 0;

      *(undefined1 *)(param_1 + 0x25c) = 1;

      uVar5 = FUN_1400cf9a0(param_1,lVar1);

      uVar5 = FUN_14008d760(&local_28,"I\'ll take good care of %s",uVar5);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),uVar5,0,CONCAT44(uVar7,DAT_140303758));

      FUN_140027900(&local_28);

      FUN_1400d1e10(param_1,param_2,0xd);

      plVar2 = *(longlong **)(param_1 + 0x268);

      if (plVar2 != *(longlong **)(param_1 + 0x270)) {

        *plVar2 = lVar1;

        *(longlong *)(param_1 + 0x268) = *(longlong *)(param_1 + 0x268) + 8;

        return 1;

      }

      FUN_140030680(param_1 + 0x260,plVar2,&local_res8);

      return 1;

    }

    local_18 = _DAT_140303400;

    uStack_10 = _UNK_140303408;

    local_28 = (char *)s_It_ll_cost__100_140303688._0_8_;

    uStack_20 = (ulonglong)

                CONCAT16(s_It_ll_cost__100_140303688[0xe],

                         CONCAT24(s_It_ll_cost__100_140303688._12_2_,

                                  s_It_ll_cost__100_140303688._8_4_));

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar7,DAT_140303758)

                 );

    if (uStack_10 < 0x10) {

      return 0;

    }

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

  return 0;

}





// Address: 0x14008e5c0
// Ghidra name: FUN_14008e5c0
// ============ 0x14008e5c0 FUN_14008e5c0 (size=562) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008e5c0(longlong param_1,int param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  int iVar3;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar4;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) != lVar1) {

    return;

  }

  iVar3 = *(int *)(param_1 + 0x260);

  if (iVar3 == 0) {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_No_money_down__No_interest_14030b810._8_8_;

    local_18 = _DAT_140304ce0;

    uStack_10 = _UNK_140304ce8;

    *(undefined8 *)local_28 = s_No_money_down__No_interest_14030b810._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    *(undefined8 *)(local_28 + 0x10) = s_No_money_down__No_interest_14030b810._16_8_;

    *(undefined2 *)(local_28 + 0x18) = s_No_money_down__No_interest_14030b810._24_2_;

    local_28[0x1a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar4,DAT_140303758)

                 );

    if (uStack_10 < 0x10) goto LAB_14008e78d;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (iVar3 != 1) {

      if (iVar3 == 2) {

        uVar2 = FUN_1400cf9a0(param_1,lVar1);

        FUN_1400d1c40(param_1,lVar1,"I\'m %s and these are my rides",uVar2);

      }

      goto LAB_14008e78d;

    }

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_Guaranteed_to_run_14030b830._8_8_;

    local_18 = _DAT_1403040f0;

    uStack_10 = _UNK_1403040f8;

    *(undefined8 *)local_28 = s_Guaranteed_to_run_14030b830._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    local_28[0x10] = s_Guaranteed_to_run_14030b830[0x10];

    local_28[0x11] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar4,DAT_140303758)

                 );

    if (uStack_10 < 0x10) goto LAB_14008e78d;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_14008e78d:

  if (0 < *(int *)(param_1 + 0x1f8)) {

    iVar3 = *(int *)(param_1 + 0x260) + 1;

    *(int *)(param_1 + 0x260) =

         iVar3 + (iVar3 / 3 + (iVar3 >> 0x1f) +

                 (int)(((longlong)iVar3 / 3 + ((longlong)iVar3 >> 0x3f) & 0xffffffffU) >> 0x1f)) *

                 -3;

  }

  return;

}





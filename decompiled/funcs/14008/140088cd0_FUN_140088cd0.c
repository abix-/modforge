// Address: 0x140088cd0
// Ghidra name: FUN_140088cd0
// ============ 0x140088cd0 FUN_140088cd0 (size=1208) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140088cd0(longlong param_1,int param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar7;

  undefined8 uVar6;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  if (*(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8) !=

      *(longlong *)(param_1 + 0x148)) {

    return;

  }

  if ((*(int *)(param_1 + 0x1f8) != 0) && (*(int *)(param_1 + 0x48c) != 0)) {

    return;

  }

  iVar5 = *(int *)(param_1 + 0x48c) + 1;

  iVar5 = iVar5 + (iVar5 / 3 + (iVar5 >> 0x1f) +

                  (int)(((longlong)iVar5 / 3 + ((longlong)iVar5 >> 0x3f) & 0xffffffffU) >> 0x1f)) *

                  -3;

  *(int *)(param_1 + 0x48c) = iVar5;

  if (iVar5 == 0) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar6 = s_I_m_a_geneticist_14030b148._8_8_;

    local_28 = _DAT_1403040e0;

    uStack_20 = _UNK_1403040e8;

    *(undefined8 *)local_38 = s_I_m_a_geneticist_14030b148._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar6;

    local_38[0x10] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar7,DAT_140303758)

                 );

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar5 == 1) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x50);

    uVar6 = _UNK_14030b168;

    local_28 = _DAT_140307a80;

    uStack_20 = _UNK_140307a88;

    *(undefined8 *)local_38 = _DAT_14030b160;

    *(undefined8 *)(local_38 + 8) = uVar6;

    uVar6 = _UNK_14030b178;

    *(undefined8 *)(local_38 + 0x10) = _DAT_14030b170;

    *(undefined8 *)(local_38 + 0x18) = uVar6;

    uVar6 = _UNK_14030b188;

    *(undefined8 *)(local_38 + 0x20) = _DAT_14030b180;

    *(undefined8 *)(local_38 + 0x28) = uVar6;

    uVar3 = _UNK_14030b19c;

    uVar2 = _UNK_14030b198;

    uVar1 = _UNK_14030b194;

    *(undefined4 *)(local_38 + 0x30) = _DAT_14030b190;

    *(undefined4 *)(local_38 + 0x34) = uVar1;

    *(undefined4 *)(local_38 + 0x38) = uVar2;

    *(undefined4 *)(local_38 + 0x3c) = uVar3;

    *(undefined2 *)(local_38 + 0x40) = DAT_14030b1a0;

    local_38[0x42] = '\0';

    uVar1 = DAT_140303758;

    uVar6 = CONCAT44(uVar7,DAT_140303758);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar6);

    uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

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

    uVar6 = s_They_form_a_spiral_scructure_tha_14030b1a8._8_8_;

    local_28 = _DAT_1403037b0;

    uStack_20 = _UNK_1403037b8;

    *(undefined8 *)local_38 = s_They_form_a_spiral_scructure_tha_14030b1a8._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar6;

    uVar4 = s_They_form_a_spiral_scructure_tha_14030b1a8._28_4_;

    uVar3 = s_They_form_a_spiral_scructure_tha_14030b1a8._24_4_;

    uVar2 = s_They_form_a_spiral_scructure_tha_14030b1a8._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_They_form_a_spiral_scructure_tha_14030b1a8._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar2;

    *(undefined4 *)(local_38 + 0x18) = uVar3;

    *(undefined4 *)(local_38 + 0x1c) = uVar4;

    uVar6 = s_They_form_a_spiral_scructure_tha_14030b1a8._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_They_form_a_spiral_scructure_tha_14030b1a8._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar6;

    *(undefined8 *)(local_38 + 0x30) = s_They_form_a_spiral_scructure_tha_14030b1a8._48_8_;

    local_38[0x38] = '\0';

    uVar6 = CONCAT44(uVar7,uVar1);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,uVar6);

    uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar6 = _UNK_14030b1f0;

    local_28 = _DAT_140303770;

    uStack_20 = _UNK_140303778;

    *(undefined8 *)local_38 = _DAT_14030b1e8;

    *(undefined8 *)(local_38 + 8) = uVar6;

    *(undefined8 *)(local_38 + 0x10) = DAT_14030b1f8;

    *(undefined4 *)(local_38 + 0x18) = DAT_14030b200;

    *(undefined2 *)(local_38 + 0x1c) = DAT_14030b204;

    local_38[0x1e] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar7,uVar1));

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (iVar5 != 2) {

      return;

    }

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x40);

    uVar6 = s_Did_you_know_that_99__of_horse_g_14030b208._8_8_;

    local_28 = _DAT_140304d20;

    uStack_20 = _UNK_140304d28;

    *(undefined8 *)local_38 = s_Did_you_know_that_99__of_horse_g_14030b208._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar6;

    uVar3 = s_Did_you_know_that_99__of_horse_g_14030b208._28_4_;

    uVar2 = s_Did_you_know_that_99__of_horse_g_14030b208._24_4_;

    uVar1 = s_Did_you_know_that_99__of_horse_g_14030b208._20_4_;

    *(undefined4 *)(local_38 + 0x10) = s_Did_you_know_that_99__of_horse_g_14030b208._16_4_;

    *(undefined4 *)(local_38 + 0x14) = uVar1;

    *(undefined4 *)(local_38 + 0x18) = uVar2;

    *(undefined4 *)(local_38 + 0x1c) = uVar3;

    uVar6 = s_Did_you_know_that_99__of_horse_g_14030b208._40_8_;

    *(undefined8 *)(local_38 + 0x20) = s_Did_you_know_that_99__of_horse_g_14030b208._32_8_;

    *(undefined8 *)(local_38 + 0x28) = uVar6;

    *(undefined2 *)(local_38 + 0x30) = s_Did_you_know_that_99__of_horse_g_14030b208._48_2_;

    local_38[0x32] = s_Did_you_know_that_99__of_horse_g_14030b208[0x32];

    local_38[0x33] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar7,DAT_140303758)

                 );

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

  return;

}





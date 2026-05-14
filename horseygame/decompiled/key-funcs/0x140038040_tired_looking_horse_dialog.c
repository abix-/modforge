// Hint: tired_looking_horse_dialog
// Address: 0x140038040
// Ghidra name: FUN_140038040
// ============ 0x140038040 FUN_140038040 (size=2059) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140038040(longlong param_1,int param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  char cVar3;

  int iVar4;

  undefined8 uVar5;

  undefined1 local_res8 [8];

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar7;

  undefined8 uVar6;

  char *local_58 [5];

  char *local_30;

  char *local_28;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  if (*(int *)(param_1 + 0x254) == 3) {

    if ((longlong)param_2 !=

        (*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3) + -1) {

      return;

    }

    local_58[2] = (char *)_DAT_1403033f0;

    local_58[3] = (char *)_UNK_1403033f8;

    local_58[0] = (char *)s_Tra_la_la__140304678._0_8_;

    local_58[1] = (char *)(ulonglong)(ushort)s_Tra_la_la__140304678._8_2_;

    FUN_1400d0c80(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8),

                  local_58,0,CONCAT44(uVar7,DAT_140303758));

    if (local_58[3] < 0x10) {

      return;

    }

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

    return;

  }

  if (*(int *)(param_1 + 0x25c) != 0) {

    return;

  }

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if (*(longlong *)(param_1 + 0x148) != lVar1) {

    if (*(int *)(param_1 + 0x250) < 0x79) {

      return;

    }

    uVar6 = *(undefined8 *)(param_1 + 0x78);

    uVar5 = FUN_1400b4a10(lVar1,local_res8);

    cVar3 = FUN_1400c5740(uVar5,uVar6,0);

    if (cVar3 == '\0') {

      return;

    }

    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

    if (*(char *)(lVar1 + 0x206) != '\0') {

      FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"That\'s a tired looking horse!");

      return;

    }

    if (*(char *)(lVar1 + 0x205) != '\0') {

      FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"That\'s a hungry looking horse!");

      return;

    }

    local_58[0] = "strong";

    local_58[1] = "sleek";

    local_58[2] = "fine";

    local_58[3] = "fast";

    local_58[4] = "nimble";

    local_30 = "talented";

    local_28 = "beautiful";

    iVar4 = FUN_1400c6580(7);

    FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"That\'s a %s looking horse!",

                  local_58[iVar4]);

    return;

  }

  iVar4 = *(int *)(param_1 + 600);

  local_58[0] = (char *)0x0;

  local_58[1] = (char *)0x0;

  local_58[2] = (char *)0x0;

  local_58[3] = (char *)0x0;

  if (iVar4 == 0) {

    local_58[0] = (char *)FUN_1400285e0(0x20);

    uVar6 = s_I_m_afraid_of_heights_140304688._8_8_;

    local_58[2] = (char *)_DAT_140304110;

    local_58[3] = (char *)_UNK_140304118;

    *(undefined8 *)local_58[0] = s_I_m_afraid_of_heights_140304688._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    *(undefined4 *)(local_58[0] + 0x10) = s_I_m_afraid_of_heights_140304688._16_4_;

    local_58[0][0x14] = s_I_m_afraid_of_heights_140304688[0x14];

    local_58[0][0x15] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,DAT_140303758))

    ;

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar4 == 1) {

    local_58[0] = (char *)FUN_1400285e0(0x30);

    uVar6 = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._8_8_;

    local_58[2] = (char *)_DAT_140303780;

    local_58[3] = (char *)_UNK_140303788;

    *(undefined8 *)local_58[0] = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    uVar6 = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._24_8_;

    *(undefined8 *)(local_58[0] + 0x10) = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._16_8_;

    *(undefined8 *)(local_58[0] + 0x18) = uVar6;

    *(undefined8 *)(local_58[0] + 0x20) = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._32_8_;

    *(undefined2 *)(local_58[0] + 0x28) = s_Strong_Horse_is_sponsored_by_Cli_1403046a0._40_2_;

    local_58[0][0x2a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,DAT_140303758))

    ;

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar4 == 2) {

    local_58[0] = (char *)FUN_1400285e0(0x20);

    uVar6 = s_Anyone_can_jump_on_a_trampoline_1403046d0._8_8_;

    local_58[2] = (char *)_DAT_140304140;

    local_58[3] = (char *)_UNK_140304148;

    *(undefined8 *)local_58[0] = s_Anyone_can_jump_on_a_trampoline_1403046d0._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    *(undefined8 *)(local_58[0] + 0x10) = s_Anyone_can_jump_on_a_trampoline_1403046d0._16_8_;

    *(undefined4 *)(local_58[0] + 0x18) = s_Anyone_can_jump_on_a_trampoline_1403046d0._24_4_;

    *(undefined2 *)(local_58[0] + 0x1c) = s_Anyone_can_jump_on_a_trampoline_1403046d0._28_2_;

    local_58[0][0x1e] = s_Anyone_can_jump_on_a_trampoline_1403046d0[0x1e];

    local_58[0][0x1f] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,DAT_140303758))

    ;

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar4 == 3) {

    local_58[0] = (char *)FUN_1400285e0(0x20);

    uVar6 = s_Those_jockeys_sure_are_nimble_1403046f0._8_8_;

    local_58[2] = (char *)_DAT_140304d00;

    local_58[3] = (char *)_UNK_140304d08;

    *(undefined8 *)local_58[0] = s_Those_jockeys_sure_are_nimble_1403046f0._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    *(undefined8 *)(local_58[0] + 0x10) = s_Those_jockeys_sure_are_nimble_1403046f0._16_8_;

    *(undefined4 *)(local_58[0] + 0x18) = s_Those_jockeys_sure_are_nimble_1403046f0._24_4_;

    local_58[0][0x1c] = s_Those_jockeys_sure_are_nimble_1403046f0[0x1c];

    local_58[0][0x1d] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,DAT_140303758))

    ;

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar4 == 5) {

    local_58[0] = (char *)FUN_1400285e0(0x30);

    uVar6 = _UNK_140304718;

    local_58[2] = (char *)_DAT_140303780;

    local_58[3] = (char *)_UNK_140303788;

    *(undefined8 *)local_58[0] = _DAT_140304710;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    uVar6 = _UNK_140304728;

    *(undefined8 *)(local_58[0] + 0x10) = _DAT_140304720;

    *(undefined8 *)(local_58[0] + 0x18) = uVar6;

    *(undefined8 *)(local_58[0] + 0x20) = DAT_140304730;

    *(undefined2 *)(local_58[0] + 0x28) = DAT_140304738;

    local_58[0][0x2a] = '\0';

    uVar2 = DAT_140303758;

    uVar6 = CONCAT44(uVar7,DAT_140303758);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,uVar6);

    uVar7 = (undefined4)((ulonglong)uVar6 >> 0x20);

    if (0xf < local_58[3]) {

      if ((0xfff < (longlong)local_58[3] + 1U) &&

         ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_58[0] = (char *)0x0;

    local_58[1] = (char *)0x0;

    local_58[2] = (char *)0x0;

    local_58[3] = (char *)0x0;

    local_58[0] = (char *)FUN_1400285e0(0x20);

    uVar6 = s_It_s_completely_ethical_140304740._8_8_;

    local_58[2] = (char *)_DAT_140304cd0;

    local_58[3] = (char *)_UNK_140304cd8;

    *(undefined8 *)local_58[0] = s_It_s_completely_ethical_140304740._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    *(undefined4 *)(local_58[0] + 0x10) = s_It_s_completely_ethical_140304740._16_4_;

    *(undefined2 *)(local_58[0] + 0x14) = s_It_s_completely_ethical_140304740._20_2_;

    local_58[0][0x16] = s_It_s_completely_ethical_140304740[0x16];

    local_58[0][0x17] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,uVar2));

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    local_58[0] = (char *)FUN_1400285e0(0x20);

    uVar6 = s_Drag_a_horse_into_any_tent_140304758._8_8_;

    local_58[2] = (char *)_DAT_140304ce0;

    local_58[3] = (char *)_UNK_140304ce8;

    *(undefined8 *)local_58[0] = s_Drag_a_horse_into_any_tent_140304758._0_8_;

    *(undefined8 *)(local_58[0] + 8) = uVar6;

    *(undefined8 *)(local_58[0] + 0x10) = s_Drag_a_horse_into_any_tent_140304758._16_8_;

    *(undefined2 *)(local_58[0] + 0x18) = s_Drag_a_horse_into_any_tent_140304758._24_2_;

    local_58[0][0x1a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_58,0,CONCAT44(uVar7,DAT_140303758))

    ;

    if (local_58[3] < 0x10) goto LAB_140038669;

    if ((0xfff < (longlong)local_58[3] + 1U) &&

       ((char *)0x1f < local_58[0] + (-8 - *(longlong *)(local_58[0] + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_140038669:

  *(undefined4 *)(param_1 + 600) = 0xffffffff;

  return;

}





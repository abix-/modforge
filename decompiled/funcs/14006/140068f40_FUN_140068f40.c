// Address: 0x140068f40
// Ghidra name: FUN_140068f40
// ============ 0x140068f40 FUN_140068f40 (size=1110) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140068f40(longlong param_1)



{

  undefined4 uVar1;

  uint uVar2;

  undefined8 in_stack_ffffffffffffffa8;

  undefined4 uVar4;

  undefined8 uVar3;

  char *local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  ulonglong uStack_30;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);

  local_48 = (char *)0x0;

  uStack_40 = 0;

  if (*(char *)(param_1 + 0x270) == '\0') {

    local_38 = 0;

    uStack_30 = 0;

    if (*(int *)(param_1 + 0x274) == 0) {

      local_48 = (char *)FUN_1400285e0(0x30);

      uVar3 = s_The_power_plant_has_malfunctione_140309af8._8_8_;

      local_38 = _DAT_140304160;

      uStack_30 = _UNK_140304168;

      *(undefined8 *)local_48 = s_The_power_plant_has_malfunctione_140309af8._0_8_;

      *(undefined8 *)(local_48 + 8) = uVar3;

      uVar3 = s_The_power_plant_has_malfunctione_140309af8._24_8_;

      *(undefined8 *)(local_48 + 0x10) = s_The_power_plant_has_malfunctione_140309af8._16_8_;

      *(undefined8 *)(local_48 + 0x18) = uVar3;

      local_48[0x20] = s_The_power_plant_has_malfunctione_140309af8[0x20];

      local_48[0x21] = '\0';

      uVar1 = DAT_140303758;

      uVar3 = CONCAT44(uVar4,DAT_140303758);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,uVar3);

      uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);

      if (0xf < uStack_30) {

        if ((0xfff < uStack_30 + 1) &&

           ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      local_48 = (char *)0x0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      local_48 = (char *)FUN_1400285e0(0x30);

      uVar3 = s_How_am_I_going_to_get_the_turbin_140309b20._8_8_;

      local_38 = _DAT_1403041a0;

      uStack_30 = _UNK_1403041a8;

      *(undefined8 *)local_48 = s_How_am_I_going_to_get_the_turbin_140309b20._0_8_;

      *(undefined8 *)(local_48 + 8) = uVar3;

      uVar3 = s_How_am_I_going_to_get_the_turbin_140309b20._24_8_;

      *(undefined8 *)(local_48 + 0x10) = s_How_am_I_going_to_get_the_turbin_140309b20._16_8_;

      *(undefined8 *)(local_48 + 0x18) = uVar3;

      *(undefined8 *)(local_48 + 0x20) = s_How_am_I_going_to_get_the_turbin_140309b20._32_8_;

      *(undefined2 *)(local_48 + 0x28) = s_How_am_I_going_to_get_the_turbin_140309b20._40_2_;

      local_48[0x2a] = s_How_am_I_going_to_get_the_turbin_140309b20[0x2a];

      local_48[0x2b] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,uVar1));

      if (uStack_30 < 0x10) {

        return;

      }

      if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      local_48 = (char *)FUN_1400285e0(0x20);

      uVar3 = s_The_turbine_stopped_again_140309b50._8_8_;

      local_38 = _DAT_140303760;

      uStack_30 = _UNK_140303768;

      *(undefined8 *)local_48 = s_The_turbine_stopped_again_140309b50._0_8_;

      *(undefined8 *)(local_48 + 8) = uVar3;

      *(undefined8 *)(local_48 + 0x10) = s_The_turbine_stopped_again_140309b50._16_8_;

      local_48[0x18] = s_The_turbine_stopped_again_140309b50[0x18];

      local_48[0x19] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,

                    CONCAT44(uVar4,DAT_140303758));

      if (uStack_30 < 0x10) {

        return;

      }

      if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

    return;

  }

  if (*(int *)(param_1 + 0x27c) == 0) {

    local_38 = _DAT_140304cc0;

    uStack_30 = _UNK_140304cc8;

    local_48 = (char *)s_Power_is_on_140309b70._0_8_;

    uStack_40 = (ulonglong)CONCAT12(s_Power_is_on_140309b70[10],s_Power_is_on_140309b70._8_2_);

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,DAT_140303758)

                 );

    if (uStack_30 < 0x10) goto LAB_1400692ef;

    if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    local_38 = 0;

    uStack_30 = 0;

    local_48 = (char *)FUN_1400285e0(0x30);

    uVar3 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._8_8_;

    local_38 = _DAT_140304180;

    uStack_30 = _UNK_140304188;

    *(undefined8 *)local_48 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._0_8_;

    *(undefined8 *)(local_48 + 8) = uVar3;

    uVar3 = s_Don_t_worry_I_buried_all_the_plu_140309aa0._24_8_;

    *(undefined8 *)(local_48 + 0x10) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._16_8_;

    *(undefined8 *)(local_48 + 0x18) = uVar3;

    *(undefined4 *)(local_48 + 0x20) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._32_4_;

    *(undefined2 *)(local_48 + 0x24) = s_Don_t_worry_I_buried_all_the_plu_140309aa0._36_2_;

    local_48[0x26] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_48,0,CONCAT44(uVar4,DAT_140303758)

                 );

    if (uStack_30 < 0x10) goto LAB_1400692ef;

    if ((0xfff < uStack_30 + 1) && ((char *)0x1f < local_48 + (-8 - *(longlong *)(local_48 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_1400692ef:

  uVar2 = *(int *)(param_1 + 0x27c) + 1U & 0x80000001;

  if ((int)uVar2 < 0) {

    uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;

  }

  *(uint *)(param_1 + 0x27c) = uVar2;

  return;

}





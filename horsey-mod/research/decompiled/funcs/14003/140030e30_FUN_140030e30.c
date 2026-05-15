// Address: 0x140030e30
// Ghidra name: FUN_140030e30
// ============ 0x140030e30 FUN_140030e30 (size=2291) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140030e30(longlong param_1,int param_2)



{

  longlong lVar1;

  bool bVar2;

  bool bVar3;

  undefined4 uVar4;

  char cVar5;

  longlong *plVar6;

  int iVar7;

  ulonglong uVar8;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar10;

  undefined8 uVar9;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  cVar5 = FUN_1400d0c50();

  uVar4 = DAT_140303758;

  if (cVar5 == '\0') {

    return;

  }

  lVar1 = *(longlong *)(param_1 + 0x148);

  if (lVar1 != *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8)) {

    return;

  }

  iVar7 = *(int *)(param_1 + 0x250);

  if (iVar7 == 3) {

    if (*(int *)(param_1 + 0x27c) != 0) {

      if (*(int *)(param_1 + 0x27c) != 3) {

        return;

      }

      local_28 = _DAT_1403040c0;

      uStack_20 = _UNK_1403040c8;

      local_38 = (char *)s_Simulating____140303968._0_8_;

      uStack_30 = (ulonglong)

                  CONCAT14(s_Simulating____140303968[0xc],s_Simulating____140303968._8_4_);

      FUN_1400d0c80(param_1,lVar1,&local_38,0,CONCAT44(uVar10,DAT_140303758));

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

LAB_140031631:

      FUN_1402c7088();

      return;

    }

    if (*(int *)(param_1 + 0x6a0) == 0) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x30);

      uVar9 = s_Push_that_red_button_to_run_a_si_1403038c8._8_8_;

      local_28 = _DAT_140304190;

      uStack_20 = _UNK_140304198;

      *(undefined8 *)local_38 = s_Push_that_red_button_to_run_a_si_1403038c8._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar9;

      uVar9 = s_Push_that_red_button_to_run_a_si_1403038c8._24_8_;

      *(undefined8 *)(local_38 + 0x10) = s_Push_that_red_button_to_run_a_si_1403038c8._16_8_;

      *(undefined8 *)(local_38 + 0x18) = uVar9;

      *(undefined8 *)(local_38 + 0x20) = s_Push_that_red_button_to_run_a_si_1403038c8._32_8_;

      local_38[0x28] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar10,DAT_140303758));

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      goto LAB_140031631;

    }

    if (0x2ff < *(int *)(param_1 + 0x690)) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar9 = _UNK_140303900;

      local_28 = _DAT_140303760;

      uStack_20 = _UNK_140303768;

      *(undefined8 *)local_38 = _DAT_1403038f8;

      *(undefined8 *)(local_38 + 8) = uVar9;

      *(undefined8 *)(local_38 + 0x10) = DAT_140303908;

      local_38[0x18] = DAT_140303910;

      local_38[0x19] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar10,DAT_140303758));

      if (uStack_20 < 0x10) {

        return;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      goto LAB_140031631;

    }

    if (DAT_1403ea0f0 == 0) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x30);

      uVar9 = s_Biological_mating_is_pointless_a_140303918._8_8_;

      local_28 = _DAT_1403041a0;

      uStack_20 = _UNK_1403041a8;

      *(undefined8 *)local_38 = s_Biological_mating_is_pointless_a_140303918._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar9;

      uVar9 = s_Biological_mating_is_pointless_a_140303918._24_8_;

      *(undefined8 *)(local_38 + 0x10) = s_Biological_mating_is_pointless_a_140303918._16_8_;

      *(undefined8 *)(local_38 + 0x18) = uVar9;

      *(undefined8 *)(local_38 + 0x20) = s_Biological_mating_is_pointless_a_140303918._32_8_;

      *(undefined2 *)(local_38 + 0x28) = s_Biological_mating_is_pointless_a_140303918._40_2_;

      local_38[0x2a] = s_Biological_mating_is_pointless_a_140303918[0x2a];

      local_38[0x2b] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar10,DAT_140303758));

      if (uStack_20 < 0x10) goto LAB_1400311a9;

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      if (DAT_1403ea0f0 != 1) goto LAB_1400311a9;

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar9 = _UNK_140303950;

      local_28 = _DAT_140304120;

      uStack_20 = _UNK_140304128;

      *(undefined8 *)local_38 = _DAT_140303948;

      *(undefined8 *)(local_38 + 8) = uVar9;

      *(undefined8 *)(local_38 + 0x10) = DAT_140303958;

      local_38[0x18] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar10,DAT_140303758));

      if (uStack_20 < 0x10) goto LAB_1400311a9;

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

LAB_1400311a9:

    DAT_1403ea0f0 = DAT_1403ea0f0 + 1 & 0x80000001;

    if (-1 < (int)DAT_1403ea0f0) {

      return;

    }

    DAT_1403ea0f0 = (DAT_1403ea0f0 - 1 | 0xfffffffe) + 1;

    return;

  }

  if (iVar7 != 0) {

    if (iVar7 != 2) {

      return;

    }

    bVar3 = false;

    bVar2 = false;

    iVar7 = 0;

    plVar6 = *(longlong **)(param_1 + 0xb8);

    uVar8 = *(longlong *)(param_1 + 0xc0) - (longlong)plVar6 >> 3;

    if (uVar8 != 0) {

      do {

        if ((*(int *)(*plVar6 + 8) == 3) && (bVar2 = bVar3, *(int *)(*plVar6 + 0xc) == 0xc)) {

          bVar3 = true;

          bVar2 = true;

        }

        iVar7 = iVar7 + 1;

        plVar6 = plVar6 + 1;

      } while ((ulonglong)(longlong)iVar7 < uVar8);

      if (bVar2) {

        local_38 = (char *)0x0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_38 = (char *)FUN_1400285e0(0x40);

        uVar9 = _UNK_1403039b8;

        local_28 = _DAT_1403041b0;

        uStack_20 = _UNK_1403041b8;

        *(undefined8 *)local_38 = _DAT_1403039b0;

        *(undefined8 *)(local_38 + 8) = uVar9;

        uVar9 = s_into_the_vat_over_there_1403039c8._0_8_;

        *(undefined8 *)(local_38 + 0x10) = _DAT_1403039c0;

        *(undefined8 *)(local_38 + 0x18) = uVar9;

        uVar9 = s_into_the_vat_over_there_1403039c8._16_8_;

        *(undefined8 *)(local_38 + 0x20) = s_into_the_vat_over_there_1403039c8._8_8_;

        *(undefined8 *)(local_38 + 0x28) = uVar9;

        local_38[0x30] = '\0';

        FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                      CONCAT44(uVar10,DAT_140303758));

        if (uStack_20 < 0x10) {

          return;

        }

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        goto LAB_140031631;

      }

    }

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar9 = _UNK_1403039f0;

    local_28 = _DAT_140304110;

    uStack_20 = _UNK_140304118;

    *(undefined8 *)local_38 = _DAT_1403039e8;

    *(undefined8 *)(local_38 + 8) = uVar9;

    *(undefined4 *)(local_38 + 0x10) = DAT_1403039f8;

    local_38[0x14] = DAT_1403039fc;

    local_38[0x15] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                  CONCAT44(uVar10,DAT_140303758));

    if (uStack_20 < 0x10) {

      return;

    }

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    goto LAB_140031631;

  }

  if (DAT_1403ea0f4 == 0) {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar9 = s_What_lovely_weather_140303978._8_8_;

    local_28 = _DAT_140304100;

    uStack_20 = _UNK_140304108;

    *(undefined8 *)local_38 = s_What_lovely_weather_140303978._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar9;

    *(undefined2 *)(local_38 + 0x10) = s_What_lovely_weather_140303978._16_2_;

    local_38[0x12] = s_What_lovely_weather_140303978[0x12];

    local_38[0x13] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                  CONCAT44(uVar10,DAT_140303758));

    if (uStack_20 < 0x10) goto LAB_140031458;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (DAT_1403ea0f4 != 1) goto LAB_140031458;

    local_28 = _DAT_1403033f0;

    uStack_20 = _UNK_1403033f8;

    local_38 = (char *)s_Might_rain_140303990._0_8_;

    uStack_30 = (ulonglong)(ushort)s_Might_rain_140303990._8_2_;

    uVar9 = CONCAT44(uVar10,DAT_140303758);

    FUN_1400d0c80(param_1,lVar1,&local_38,0,uVar9);

    uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    local_28 = _DAT_1403040a0;

    uStack_20 = _UNK_1403040a8;

    local_38 = (char *)s_Might_not_1403039a0._0_8_;

    uStack_30 = (ulonglong)(byte)s_Might_not_1403039a0[8];

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar10,uVar4));

    if (uStack_20 < 0x10) goto LAB_140031458;

    if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_140031458:

  DAT_1403ea0f4 = DAT_1403ea0f4 + 1 & 0x80000001;

  if (-1 < (int)DAT_1403ea0f4) {

    return;

  }

  DAT_1403ea0f4 = (DAT_1403ea0f4 - 1 | 0xfffffffe) + 1;

  return;

}





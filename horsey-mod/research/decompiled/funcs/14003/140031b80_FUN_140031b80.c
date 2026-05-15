// Address: 0x140031b80
// Ghidra name: FUN_140031b80
// ============ 0x140031b80 FUN_140031b80 (size=1935) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140031b80(longlong param_1,longlong param_2,int param_3)



{

  byte *pbVar1;

  undefined8 uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  bool bVar6;

  ulonglong in_stack_ffffffffffffffc8;

  ulonglong uVar7;

  undefined4 uVar8;

  char *local_28;

  ulonglong uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if (((param_3 != 3) || (*(int *)(param_1 + 0x250) == 0)) || (*(int *)(param_2 + 8) != 3)) {

    if (*(int *)(param_2 + 0xc) != 0x30) {

      return;

    }

    if (param_3 != 4) {

      return;

    }

    if (*(char *)(param_1 + 0x6b0) != '\0') {

      return;

    }

    if (*(int *)(param_1 + 0x27c) != 0) {

      return;

    }

    local_18 = _DAT_1403040a0;

    uStack_10 = _UNK_1403040a8;

    local_28 = (char *)s_InsertRam_140303ac0._0_8_;

    uStack_20 = (ulonglong)(byte)s_InsertRam_140303ac0[8];

    uVar7 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;

    FUN_140040ca0(&local_28,100,0,DAT_14039ca44,uVar7);

    uVar8 = (undefined4)(uVar7 >> 0x20);

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(undefined1 *)(param_2 + 0x11) = 1;

    *(undefined4 *)(param_2 + 0x28) = 0x447a0000;

    *(undefined1 *)(param_1 + 0x6b0) = 1;

    *(undefined4 *)(param_1 + 0x6a8) = 0x10;

    *(undefined4 *)(param_1 + 0x6ac) = 0x28;

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x30);

    uVar2 = s_Now_the_simulation_will_run_twic_140303ad0._8_8_;

    local_18 = _DAT_140303780;

    uStack_10 = _UNK_140303788;

    *(undefined8 *)local_28 = s_Now_the_simulation_will_run_twic_140303ad0._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    uVar2 = s_Now_the_simulation_will_run_twic_140303ad0._24_8_;

    *(undefined8 *)(local_28 + 0x10) = s_Now_the_simulation_will_run_twic_140303ad0._16_8_;

    *(undefined8 *)(local_28 + 0x18) = uVar2;

    *(undefined8 *)(local_28 + 0x20) = s_Now_the_simulation_will_run_twic_140303ad0._32_8_;

    *(undefined2 *)(local_28 + 0x28) = s_Now_the_simulation_will_run_twic_140303ad0._40_2_;

    local_28[0x2a] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_10 < 0x10) {

      return;

    }

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

LAB_140032248:

    FUN_1402c7088();

    return;

  }

  if (*(int *)(param_2 + 0xc) == 0x30) {

    local_28 = (char *)0x0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_WHOA__THAT_RAM_IS_VALUABLE__140303a30._8_8_;

    local_18 = _DAT_140304130;

    uStack_10 = _UNK_140304138;

    *(undefined8 *)local_28 = s_WHOA__THAT_RAM_IS_VALUABLE__140303a30._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    *(undefined8 *)(local_28 + 0x10) = s_WHOA__THAT_RAM_IS_VALUABLE__140303a30._16_8_;

    *(undefined2 *)(local_28 + 0x18) = s_WHOA__THAT_RAM_IS_VALUABLE__140303a30._24_2_;

    local_28[0x1a] = s_WHOA__THAT_RAM_IS_VALUABLE__140303a30[0x1a];

    local_28[0x1b] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,DAT_140303758);

    if (uStack_10 < 0x10) {

      return;

    }

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    goto LAB_140032248;

  }

  FUN_14005cf70(param_2);

  iVar3 = *(int *)(param_2 + 0xc);

  bVar6 = false;

  if (*(longlong *)(param_2 + 0x78) == 0) {

    if (iVar3 == 5) {

      if (0xef < *(int *)(param_1 + 0x690)) {

        lVar5 = 0x14;

        do {

          iVar3 = FUN_1400c6580(0xf0);

          iVar4 = FUN_1400c6580(4);

          *(undefined1 *)((longlong)iVar4 + (longlong)iVar3 * 4 + 0x2b8 + param_1) = 1;

          lVar5 = lVar5 + -1;

        } while (lVar5 != 0);

        goto LAB_140031dbb;

      }

    }

    else if (iVar3 - 0x13U < 4) {

      bVar6 = iVar3 != 0x13;

      iVar3 = FUN_1400c6580(0xf0);

      iVar4 = FUN_1400c6580(4);

      *(bool *)((longlong)iVar4 + (longlong)iVar3 * 4 + 0x2b8 + param_1) = bVar6;

      iVar3 = FUN_1400c6580(0xf0);

      iVar4 = FUN_1400c6580(4);

      *(bool *)((longlong)iVar4 + (longlong)iVar3 * 4 + 0x2b8 + param_1) = bVar6;

      iVar3 = FUN_1400c6580(0xf0);

      iVar4 = FUN_1400c6580(4);

      *(bool *)((longlong)iVar4 + (longlong)iVar3 * 4 + 0x2b8 + param_1) = bVar6;

      iVar3 = FUN_1400c6580(0xf0);

      iVar4 = FUN_1400c6580(4);

      *(bool *)((longlong)iVar4 + (longlong)iVar3 * 4 + 0x2b8 + param_1) = bVar6;

      goto LAB_140031dbb;

    }

  }

  else {

    FUN_1400325b0(param_1);

LAB_140031dbb:

    FUN_140032610(param_1);

    bVar6 = true;

  }

  *(undefined1 *)(param_2 + 0x11) = 1;

  FUN_1400cce00(param_1);

  *(undefined4 *)(param_1 + 0x694) = 0x3c;

  local_18 = _DAT_1403040a0;

  uStack_10 = _UNK_1403040a8;

  local_28 = (char *)s_VatBurble_140303a00._0_8_;

  uStack_20 = (ulonglong)(byte)s_VatBurble_140303a00[8];

  uVar7 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;

  FUN_140040ca0(&local_28,100,0,DAT_14039ca44,uVar7);

  uVar8 = (undefined4)(uVar7 >> 0x20);

  if (0xf < uStack_10) {

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  if ((*(int *)(param_1 + 0x250) == 2) || (*(int *)(param_1 + 0x250) == 1)) {

    FUN_14003f6f0();

    *(undefined8 *)(param_1 + 0x250) = 3;

    return;

  }

  local_28 = (char *)0x0;

  uStack_20 = 0;

  local_18 = 0;

  uStack_10 = 0;

  if (!bVar6) {

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = _UNK_140303a58;

    local_18 = _DAT_140303770;

    uStack_10 = _UNK_140303778;

    *(undefined8 *)local_28 = _DAT_140303a50;

    *(undefined8 *)(local_28 + 8) = uVar2;

    *(undefined8 *)(local_28 + 0x10) = _DAT_140303a60;

    *(undefined4 *)(local_28 + 0x18) = s_in_that_140303a66._2_4_;

    *(undefined2 *)(local_28 + 0x1c) = s_in_that_140303a66._6_2_;

    local_28[0x1e] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (0xf < uStack_10) {

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    *(int *)(param_1 + 0x6a4) = *(int *)(param_1 + 0x6a4) + 1;

    return;

  }

  pbVar1 = (byte *)(param_1 + 0x6a4);

  if ((*pbVar1 & 1) == 0) {

    local_28 = (char *)FUN_1400285e0(0x40);

    uVar2 = _UNK_140303a78;

    local_18 = _DAT_1403041b0;

    uStack_10 = _UNK_1403041b8;

    *(undefined8 *)local_28 = _DAT_140303a70;

    *(undefined8 *)(local_28 + 8) = uVar2;

    uVar2 = s_means_more_variety_of_sim_horses_140303a7e._10_8_;

    *(undefined8 *)(local_28 + 0x10) = s_means_more_variety_of_sim_horses_140303a7e._2_8_;

    *(undefined8 *)(local_28 + 0x18) = uVar2;

    uVar2 = s_means_more_variety_of_sim_horses_140303a7e._26_8_;

    *(undefined8 *)(local_28 + 0x20) = s_means_more_variety_of_sim_horses_140303a7e._18_8_;

    *(undefined8 *)(local_28 + 0x28) = uVar2;

    local_28[0x30] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_10 < 0x10) goto LAB_140032098;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    local_28 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_That_s_the_stuff__140303aa8._8_8_;

    local_18 = _DAT_1403040f0;

    uStack_10 = _UNK_1403040f8;

    *(undefined8 *)local_28 = s_That_s_the_stuff__140303aa8._0_8_;

    *(undefined8 *)(local_28 + 8) = uVar2;

    local_28[0x10] = s_That_s_the_stuff__140303aa8[0x10];

    local_28[0x11] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,CONCAT44(uVar8,DAT_140303758)

                 );

    if (uStack_10 < 0x10) goto LAB_140032098;

    if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8))))

    {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

LAB_140032098:

  *(int *)pbVar1 = *(int *)pbVar1 + 1;

  return;

}





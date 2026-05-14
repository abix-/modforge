// Address: 0x14008e800
// Ghidra name: FUN_14008e800
// ============ 0x14008e800 FUN_14008e800 (size=846) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14008e800(longlong param_1,int param_2,int param_3)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  char cVar6;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar7;

  char *local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if (*(char *)(lVar1 + 0x204) != '\0') {

    if (param_3 != 0) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x30);

      uVar2 = s_That_horse_is_looking_a_bit_rust_14030b8c0._8_8_;

      local_28 = _DAT_140304160;

      uStack_20 = _UNK_140304168;

      *(undefined8 *)local_38 = s_That_horse_is_looking_a_bit_rust_14030b8c0._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar2;

      uVar5 = s_That_horse_is_looking_a_bit_rust_14030b8c0._28_4_;

      uVar4 = s_That_horse_is_looking_a_bit_rust_14030b8c0._24_4_;

      uVar3 = s_That_horse_is_looking_a_bit_rust_14030b8c0._20_4_;

      *(undefined4 *)(local_38 + 0x10) = s_That_horse_is_looking_a_bit_rust_14030b8c0._16_4_;

      *(undefined4 *)(local_38 + 0x14) = uVar3;

      *(undefined4 *)(local_38 + 0x18) = uVar4;

      *(undefined4 *)(local_38 + 0x1c) = uVar5;

      local_38[0x20] = s_That_horse_is_looking_a_bit_rust_14030b8c0[0x20];

      local_38[0x21] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar7,DAT_140303758));

      if (0xf < uStack_20) {

        if ((0xfff < uStack_20 + 1) &&

           ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    return 1;

  }

  if (param_3 != 0) {

    return 0;

  }

  cVar6 = FUN_140104c00(DAT_1403fb0d8,*(undefined4 *)(lVar1 + 0x220));

  if (cVar6 == '\0') {

    if (*(int *)(DAT_1403fb0d8 + 0x308) < (*(int *)(lVar1 + 0x220) * 0x5a) / 100) {

      local_38 = (char *)0x0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_38 = (char *)FUN_1400285e0(0x20);

      uVar2 = s_The_price_is_firm_14030b8a8._8_8_;

      local_28 = _DAT_1403040f0;

      uStack_20 = _UNK_1403040f8;

      *(undefined8 *)local_38 = s_The_price_is_firm_14030b8a8._0_8_;

      *(undefined8 *)(local_38 + 8) = uVar2;

      local_38[0x10] = s_The_price_is_firm_14030b8a8[0x10];

      local_38[0x11] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,

                    CONCAT44(uVar7,DAT_140303758));

      if (uStack_20 < 0x10) {

        return 0;

      }

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

      return 0;

    }

    FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"OK I\'ll let you have it for %d");

    FUN_140104c00(DAT_1403fb0d8,*(undefined4 *)(DAT_1403fb0d8 + 0x308),0,0);

  }

  else {

    local_38 = (char *)0x0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_38 = (char *)FUN_1400285e0(0x20);

    uVar2 = s_You_got_yourself_a_deal__14030b868._8_8_;

    local_28 = _DAT_140304120;

    uStack_20 = _UNK_140304128;

    *(undefined8 *)local_38 = s_You_got_yourself_a_deal__14030b868._0_8_;

    *(undefined8 *)(local_38 + 8) = uVar2;

    *(undefined8 *)(local_38 + 0x10) = s_You_got_yourself_a_deal__14030b868._16_8_;

    local_38[0x18] = '\0';

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_38,0,CONCAT44(uVar7,DAT_140303758)

                 );

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && ((char *)0x1f < local_38 + (-8 - *(longlong *)(local_38 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  *(undefined1 *)(lVar1 + 0x204) = 1;

  *(undefined4 *)(lVar1 + 0x220) = 0x1e;

  *(int *)(param_1 + 0x268) = *(int *)(param_1 + 0x268) + -1;

  FUN_1400c7c60(*(undefined4 *)(lVar1 + 0x1f8),0);

  return 1;

}





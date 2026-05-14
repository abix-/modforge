// Address: 0x14009c7d0
// Ghidra name: FUN_14009c7d0
// ============ 0x14009c7d0 FUN_14009c7d0 (size=225) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14009c7d0(longlong param_1,undefined8 param_2)



{

  ulonglong in_stack_ffffffffffffffc8;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  local_18 = _DAT_140303400;

  uStack_10 = _UNK_140303408;

  local_28 = s_ShowStatsScreen_14030c650._0_8_;

  uStack_20 = (ulonglong)

              CONCAT16(s_ShowStatsScreen_14030c650[0xe],

                       CONCAT24(s_ShowStatsScreen_14030c650._12_2_,s_ShowStatsScreen_14030c650._8_4_

                               ));

  FUN_140040ca0(&local_28,100,0,DAT_14039ca44,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  FUN_140055c30(*(undefined8 *)(param_1 + 0x20),param_2);

  return;

}





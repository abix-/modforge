// Address: 0x1400b6e90
// Ghidra name: FUN_1400b6e90
// ============ 0x1400b6e90 FUN_1400b6e90 (size=307) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1400b6e90(longlong param_1,int param_2,undefined4 param_3)



{

  longlong lVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong in_stack_ffffffffffffffc8;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar3 = (ulonglong)param_2;

  lVar4 = uVar3 * 0xb8;

  lVar1 = *(longlong *)(param_1 + 0x40);

  if (((0x7fffffff < *(uint *)(lVar4 + 0x10 + lVar1)) &&

      (uVar3 = *(ulonglong *)(lVar4 + 0x18 + lVar1), uVar3 != *(ulonglong *)(lVar4 + 0x20 + lVar1)))

     && (*(int *)(uVar3 + 0x15c) == 0xb)) {

    local_18 = _DAT_140304cc0;

    uStack_10 = _UNK_140304cc8;

    local_28 = s_HelixAttach_14030d7c8._0_8_;

    uStack_20 = (ulonglong)CONCAT12(s_HelixAttach_14030d7c8[10],s_HelixAttach_14030d7c8._8_2_);

    uVar2 = FUN_140040fe0(*(undefined4 *)(lVar4 + 0x40 + lVar1));

    FUN_140040ca0(&local_28,100,uVar2,DAT_14039ca44,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    lVar1 = *(longlong *)(param_1 + 0x40);

    *(undefined4 *)(lVar1 + 0x10 + lVar4) = param_3;

    return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

  }

  return uVar3 & 0xffffffffffffff00;

}





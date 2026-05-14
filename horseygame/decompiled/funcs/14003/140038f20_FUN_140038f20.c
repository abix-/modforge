// Address: 0x140038f20
// Ghidra name: FUN_140038f20
// ============ 0x140038f20 FUN_140038f20 (size=218) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140038f20(longlong param_1)



{

  ulonglong uVar1;

  undefined4 uVar2;

  undefined8 local_28;

  

  uVar2 = FUN_1400c7600(0,4,0xffffffff,0xffffffff,0xffffffff);

  *(undefined4 *)(*(longlong *)(param_1 + 0x268) + 0x1f8) = uVar2;

  uVar1 = _UNK_140304088;

  local_28 = (ulonglong)CONCAT14(s_Freak_140304914[4],s_Freak_140304914._0_4_);

  FUN_1400cf950(param_1,*(undefined8 *)(param_1 + 0x268));

  if (0xf < uVar1) {

    if (0xfff < uVar1 + 1) {

      if (0x1f < (local_28 - *(longlong *)(local_28 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  *(undefined8 *)(param_1 + 0x268) = 0;

  return;

}





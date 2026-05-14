// Address: 0x140037df0
// Ghidra name: FUN_140037df0
// ============ 0x140037df0 FUN_140037df0 (size=473) ============


undefined8 FUN_140037df0(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  ulonglong uVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong local_38;

  longlong lStack_30;

  longlong local_28;

  longlong local_20;

  longlong local_18;

  longlong local_10;

  

  FUN_1400d0a00(param_1,0);

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1,0);

  *(undefined4 *)(param_1 + 0x254) = 0xffffffff;

  uVar6 = 0;

  *(undefined4 *)(param_1 + 0x25c) = 0;

  *(undefined4 *)(param_1 + 0x250) = 0;

  *(undefined8 *)(param_1 + 0x298) = 0;

  *(undefined8 *)(param_1 + 0x2a0) = 0;

  *(undefined1 *)(param_1 + 0x223c) = 0;

  *(undefined4 *)(param_1 + 0x2240) = 0;

  *(undefined4 *)(param_1 + 0x225c) = 0xffffffff;

  uVar2 = FUN_140107510(DAT_1403fb0d8);

  *(undefined8 *)(param_1 + 0x270) = uVar2;

  FUN_140107550(DAT_1403fb0d8,&local_20);

  if (local_20 != local_18) {

    local_38 = 0;

    lStack_30 = 0;

    local_28 = 0;

    uVar4 = local_18 - local_20 >> 3;

    if (uVar4 != 0) {

      if (0x1fffffffffffffff < uVar4) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      lVar3 = FUN_1400285e0(uVar4 * 8);

      local_28 = uVar4 * 8 + lVar3;

      lVar5 = local_18 - local_20;

      local_38 = lVar3;

      lStack_30 = lVar3;

      FUN_1402f8e20(lVar3);

      lStack_30 = lVar3 + (lVar5 >> 3) * 8;

    }

    if (local_38 != lStack_30) {

      iVar1 = FUN_1400c6580(lStack_30 - local_38 >> 3);

      uVar6 = *(undefined8 *)(local_38 + (longlong)iVar1 * 8);

    }

    FUN_140030810(&local_38);

    *(undefined8 *)(param_1 + 0x278) = uVar6;

  }

  if (local_20 != 0) {

    if ((0xfff < (local_10 - local_20 & 0xfffffffffffffff8U)) &&

       (0x1f < (local_20 - *(longlong *)(local_20 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return 1;

}





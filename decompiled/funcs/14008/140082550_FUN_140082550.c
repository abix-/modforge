// Address: 0x140082550
// Ghidra name: FUN_140082550
// ============ 0x140082550 FUN_140082550 (size=227) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140082550(longlong param_1)



{

  longlong lVar1;

  longlong local_28 [3];

  ulonglong uStack_10;

  

  lVar1 = *(longlong *)(param_1 + 0x80);

  if (((*(int *)(lVar1 + 0x1c) < 4) && (*(int *)(lVar1 + 0x1ac) != -1)) &&

     (0 < *(int *)(lVar1 + 0x1b0))) {

    local_28[1] = 0;

    local_28[2] = _DAT_14039caa0;

    uStack_10 = _UNK_14039caa8;

    local_28[0] = 0;

    FUN_14010de70(DAT_1403fb0d8,local_28,*(int *)(lVar1 + 0x1ac),*(undefined8 *)(param_1 + 0x28),10,

                  *(int *)(lVar1 + 0x1b0),*(undefined4 *)(lVar1 + 0x1b4));

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return;

}





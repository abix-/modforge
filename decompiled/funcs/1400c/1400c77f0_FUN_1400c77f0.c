// Address: 0x1400c77f0
// Ghidra name: FUN_1400c77f0
// ============ 0x1400c77f0 FUN_1400c77f0 (size=200) ============


undefined1 * FUN_1400c77f0(int param_1)



{

  undefined8 uVar1;

  longlong *plVar2;

  longlong lVar3;

  longlong local_28 [3];

  ulonglong local_10;

  

  if (param_1 == -1) {

    FUN_1400c4320("No Record!");

    return &DAT_14039bcb9;

  }

  lVar3 = (longlong)param_1 * 0x88 + DAT_1403f34e0;

  if (*(char *)(lVar3 + 0x40) != '\0') {

    *(undefined1 *)(lVar3 + 0x40) = 0;

    uVar1 = FUN_1400c7560(local_28);

    FUN_1400c7910(param_1,uVar1);

    if (0xf < local_10) {

      if (0xfff < local_10 + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  plVar2 = (longlong *)(lVar3 + 0x20);

  if (0xf < *(ulonglong *)(lVar3 + 0x38)) {

    plVar2 = (longlong *)*plVar2;

  }

  return (undefined1 *)plVar2;

}





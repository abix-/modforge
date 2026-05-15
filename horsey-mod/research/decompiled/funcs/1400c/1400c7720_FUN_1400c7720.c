// Address: 0x1400c7720
// Ghidra name: FUN_1400c7720
// ============ 0x1400c7720 FUN_1400c7720 (size=199) ============


undefined8 * FUN_1400c7720(int param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  longlong local_28 [3];

  ulonglong local_10;

  

  if (param_1 == -1) {

    FUN_1400c4320("No Record!");

    return (undefined8 *)&DAT_14039bcb9;

  }

  puVar2 = (undefined8 *)((longlong)param_1 * 0x88 + DAT_1403f34e0);

  if (*(char *)(puVar2 + 8) != '\0') {

    *(undefined1 *)(puVar2 + 8) = 0;

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

  if (0xf < (ulonglong)puVar2[3]) {

    puVar2 = (undefined8 *)*puVar2;

  }

  return puVar2;

}





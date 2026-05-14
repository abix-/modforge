// Address: 0x1400cf9a0
// Ghidra name: FUN_1400cf9a0
// ============ 0x1400cf9a0 FUN_1400cf9a0 (size=28) ============


char * FUN_1400cf9a0(undefined8 param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  longlong alStack_28 [3];

  ulonglong uStack_10;

  

  if (param_2 != 0) {

    iVar1 = *(int *)(param_2 + 0x1f8);

    if (iVar1 != -1) {

      if (iVar1 == -1) {

        FUN_1400c4320("No Record!");

        return "";

      }

      lVar4 = (longlong)iVar1 * 0x88 + DAT_1403f34e0;

      if (*(char *)(lVar4 + 0x40) != '\0') {

        *(undefined1 *)(lVar4 + 0x40) = 0;

        uVar2 = FUN_1400c7560(alStack_28);

        FUN_1400c7910(iVar1,uVar2);

        if (0xf < uStack_10) {

          if (0xfff < uStack_10 + 1) {

            if (0x1f < (alStack_28[0] - *(longlong *)(alStack_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

          }

          FUN_1402c7088();

        }

      }

      plVar3 = (longlong *)(lVar4 + 0x20);

      if (0xf < *(ulonglong *)(lVar4 + 0x38)) {

        plVar3 = (longlong *)*plVar3;

      }

      return (char *)plVar3;

    }

  }

  return "Horse";

}





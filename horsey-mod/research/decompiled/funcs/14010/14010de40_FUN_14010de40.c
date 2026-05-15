// Address: 0x14010de40
// Ghidra name: FUN_14010de40
// ============ 0x14010de40 FUN_14010de40 (size=38) ============


char * FUN_14010de40(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  longlong lVar4;

  longlong alStack_28 [3];

  ulonglong uStack_10;

  

  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x90);

  if ((lVar4 != 0) && (lVar4 = *(longlong *)(lVar4 + 0x148), lVar4 != 0)) {

    if (lVar4 != 0) {

      iVar1 = *(int *)(lVar4 + 0x1f8);

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

  return (char *)0x0;

}





// Address: 0x1400cf970
// Ghidra name: FUN_1400cf970
// ============ 0x1400cf970 FUN_1400cf970 (size=28) ============


char * FUN_1400cf970(undefined8 param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  char *pcVar3;

  longlong alStack_28 [3];

  ulonglong uStack_10;

  

  if (param_2 != 0) {

    iVar1 = *(int *)(param_2 + 0x1f8);

    if (iVar1 != -1) {

      if (iVar1 == -1) {

        FUN_1400c4320("No Record!");

        return "";

      }

      pcVar3 = (char *)((longlong)iVar1 * 0x88 + DAT_1403f34e0);

      if (pcVar3[0x40] != '\0') {

        pcVar3[0x40] = '\0';

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

      if (0xf < *(ulonglong *)(pcVar3 + 0x18)) {

        pcVar3 = *(char **)pcVar3;

      }

      return pcVar3;

    }

  }

  return "Horse";

}





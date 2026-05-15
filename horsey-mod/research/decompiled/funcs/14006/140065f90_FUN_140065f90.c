// Address: 0x140065f90
// Ghidra name: FUN_140065f90
// ============ 0x140065f90 FUN_140065f90 (size=381) ============


void FUN_140065f90(longlong param_1)



{

  int iVar1;

  longlong local_28 [3];

  ulonglong local_10;

  

  iVar1 = 0;

  do {

    FUN_1400760f0(local_28,(longlong)iVar1 * 0x20 + 600 + param_1);

    if (0xf < local_10) {

      if (0xfff < local_10 + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 4);

  FUN_1400760f0(local_28,param_1 + 0x2d8);

  if (0xf < local_10) {

    if (0xfff < local_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  FUN_1400760f0(local_28,param_1 + 0x300);

  if (0xf < local_10) {

    if (0xfff < local_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  FUN_140075b80(param_1 + 800);

  FUN_140075e80(param_1 + 0x2f8);

  FUN_140075e80(param_1 + 0x325);

  return;

}





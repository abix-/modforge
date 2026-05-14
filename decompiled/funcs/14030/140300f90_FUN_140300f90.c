// Address: 0x140300f90
// Ghidra name: FUN_140300f90
// ============ 0x140300f90 FUN_140300f90 (size=226) ============


void FUN_140300f90(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = DAT_1403f34e8;

  lVar2 = DAT_1403f34e0;

  if (DAT_1403f34e0 != 0) {

    for (; lVar2 != lVar1; lVar2 = lVar2 + 0x88) {

      thunk_FUN_1400308d0(lVar2 + 0x70);

      FUN_140027900(lVar2 + 0x20);

      FUN_140027900(lVar2);

    }

    lVar2 = DAT_1403f34e0;

    if ((0xfff < (ulonglong)(((DAT_1403f34f0 - DAT_1403f34e0) / 0x88) * 0x88)) &&

       (lVar2 = *(longlong *)(DAT_1403f34e0 + -8), 0x1f < (DAT_1403f34e0 - lVar2) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar2);

    DAT_1403f34e0 = 0;

    DAT_1403f34e8 = 0;

    DAT_1403f34f0 = 0;

  }

  return;

}





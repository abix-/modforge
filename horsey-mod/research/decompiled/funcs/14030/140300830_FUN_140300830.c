// Address: 0x140300830
// Ghidra name: FUN_140300830
// ============ 0x140300830 FUN_140300830 (size=119) ============


void FUN_140300830(void)



{

  longlong lVar1;

  

  if (DAT_1403edf28 != 0) {

    lVar1 = DAT_1403edf28;

    if ((0xfff < (DAT_1403edf38 - DAT_1403edf28 & 0xfffffffffffffff8U)) &&

       (lVar1 = *(longlong *)(DAT_1403edf28 + -8), 0x1f < (DAT_1403edf28 - lVar1) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(lVar1);

    DAT_1403edf28 = 0;

    DAT_1403edf30 = 0;

    DAT_1403edf38 = 0;

  }

  return;

}





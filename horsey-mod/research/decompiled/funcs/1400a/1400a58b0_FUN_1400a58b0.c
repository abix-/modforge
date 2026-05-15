// Address: 0x1400a58b0
// Ghidra name: FUN_1400a58b0
// ============ 0x1400a58b0 FUN_1400a58b0 (size=151) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400a58b0(undefined8 param_1)



{

  char cVar1;

  longlong local_28 [3];

  ulonglong uStack_10;

  

  local_28[1] = 0;

  local_28[2] = _DAT_14039caa0;

  uStack_10 = _UNK_14039caa8;

  local_28[0] = 0;

  cVar1 = FUN_14008d150(local_28);

  if (cVar1 != '\0') {

    FUN_1400a5950(local_28,param_1);

  }

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  return;

}





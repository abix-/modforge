// Address: 0x1400fb9f0
// Ghidra name: FUN_1400fb9f0
// ============ 0x1400fb9f0 FUN_1400fb9f0 (size=228) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400fb9f0(longlong param_1)



{

  ulonglong in_stack_ffffffffffffffb8;

  longlong local_28 [3];

  ulonglong uStack_10;

  

  local_28[1] = 0;

  local_28[2] = _DAT_140305680;

  uStack_10 = _UNK_140305688;

  local_28[0] = 0x6b6e6f48;

  FUN_140040ca0(local_28,100,0,DAT_14039ca44,in_stack_ffffffffffffffb8 & 0xffffffffffffff00);

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  *(undefined4 *)(param_1 + 0x8c) = 0x16;

  FUN_140102860(DAT_1403fb0d8);

  return;

}





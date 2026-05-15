// Address: 0x140026610
// Ghidra name: FUN_140026610
// ============ 0x140026610 FUN_140026610 (size=441) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_140026610(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  char *pcVar3;

  longlong lVar4;

  undefined1 auStackY_98 [32];

  ulonglong local_68 [10];

  

  local_68[8] = DAT_1403e8b00 ^ (ulonglong)auStackY_98;

  local_68[5] = 0;

  local_68[6] = 0;

  local_68[7] = 0xf;

  local_68[4] = 0;

  local_68[1] = 0;

  local_68[2] = 0;

  local_68[3] = 0xf;

  local_68[0] = 0;

  FUN_140024dc0(param_1 + 0x20,local_68 + 4);

  FUN_140024dc0(param_1 + 0x40,local_68);

  lVar4 = param_1 + 0x40;

  if (0xf < *(ulonglong *)(param_1 + 0x58)) {

    lVar4 = *(longlong *)(param_1 + 0x40);

  }

  if (((*(longlong *)(param_1 + 0x50) == 0) ||

      (lVar1 = *(longlong *)(param_1 + 0x50) + lVar4, lVar2 = thunk_FUN_1402c61c0(lVar4,lVar1),

      lVar2 == lVar1)) || (lVar2 - lVar4 == -1)) {

    if (param_2 == 0) goto LAB_1400266fb;

    pcVar3 = "%s=\"%s\"";

  }

  else {

    if (param_2 == 0) goto LAB_1400266fb;

    pcVar3 = "%s=\'%s\'";

  }

  FUN_140023ee0(param_2,pcVar3);

LAB_1400266fb:

  if (0xf < local_68[3]) {

    if ((0xfff < local_68[3] + 1) && (0x1f < (local_68[0] - *(longlong *)(local_68[0] - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  local_68[2] = 0;

  local_68[3] = 0xf;

  local_68[0] = local_68[0] & 0xffffffffffffff00;

  if (0xf < local_68[7]) {

    if ((0xfff < local_68[7] + 1) && (0x1f < (local_68[4] - *(longlong *)(local_68[4] + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}





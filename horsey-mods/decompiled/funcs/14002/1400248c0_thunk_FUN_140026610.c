// Address: 0x1400248c0
// Ghidra name: thunk_FUN_140026610
// ============ 0x1400248c0 thunk_FUN_140026610 (size=5) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void thunk_FUN_140026610(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  char *pcVar3;

  longlong lVar4;

  undefined1 auStackY_98 [32];

  ulonglong auStack_68 [10];

  

  auStack_68[8] = DAT_1403e8b00 ^ (ulonglong)auStackY_98;

  auStack_68[5] = 0;

  auStack_68[6] = 0;

  auStack_68[7] = 0xf;

  auStack_68[4] = 0;

  auStack_68[1] = 0;

  auStack_68[2] = 0;

  auStack_68[3] = 0xf;

  auStack_68[0] = 0;

  FUN_140024dc0(param_1 + 0x20,auStack_68 + 4);

  FUN_140024dc0(param_1 + 0x40,auStack_68);

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

  if (0xf < auStack_68[3]) {

    if ((0xfff < auStack_68[3] + 1) &&

       (0x1f < (auStack_68[0] - *(longlong *)(auStack_68[0] - 8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  auStack_68[2] = 0;

  auStack_68[3] = 0xf;

  auStack_68[0] = auStack_68[0] & 0xffffffffffffff00;

  if (0xf < auStack_68[7]) {

    if ((0xfff < auStack_68[7] + 1) &&

       (0x1f < (auStack_68[4] - *(longlong *)(auStack_68[4] + -8)) - 8)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}





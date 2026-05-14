// Address: 0x140026990
// Ghidra name: FUN_140026990
// ============ 0x140026990 FUN_140026990 (size=337) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140026990(longlong param_1,longlong param_2,uint param_3)



{

  ulonglong uVar1;

  longlong *plVar2;

  undefined1 auStackY_68 [32];

  longlong local_38 [3];

  ulonglong uStack_20;

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStackY_68;

  uVar1 = (ulonglong)param_3;

  if (param_2 == 0) {

    FID_conflict__assert(L"cfile",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x508);

  }

  if (*(char *)(param_1 + 0x68) == '\0') {

    local_38[1] = 0;

    local_38[2] = _DAT_14039caa0;

    uStack_20 = _UNK_14039caa8;

    local_38[0] = 0;

    FUN_140024dc0(param_1 + 0x38,local_38);

    FUN_140023ee0(param_2,&DAT_14039bf30);

    if (0xf < uStack_20) {

      if ((0xfff < uStack_20 + 1) && (0x1f < (local_38[0] - *(longlong *)(local_38[0] + -8)) - 8U))

      {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  else {

    FUN_140023ee0(param_2,&DAT_14039bd10);

    if (0 < (int)param_3) {

      do {

        FUN_140023ee0(param_2,&DAT_14039bd08);

        uVar1 = uVar1 - 1;

      } while (uVar1 != 0);

    }

    plVar2 = (longlong *)(param_1 + 0x38);

    if (0xf < *(ulonglong *)(param_1 + 0x50)) {

      plVar2 = (longlong *)*plVar2;

    }

    FUN_140023ee0(param_2,"<![CDATA[%s]]>\n",plVar2);

  }

  return;

}





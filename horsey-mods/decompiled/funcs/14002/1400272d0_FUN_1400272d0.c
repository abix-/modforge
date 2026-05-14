// Address: 0x1400272d0
// Ghidra name: FUN_1400272d0
// ============ 0x1400272d0 FUN_1400272d0 (size=264) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1400272d0(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined1 auStackY_68 [32];

  longlong local_30 [5];

  

  local_30[4] = DAT_1403e8b00 ^ (ulonglong)auStackY_68;

  puVar1 = (undefined8 *)(param_2 + 0x20);

  if (0xf < *(ulonglong *)(param_2 + 0x38)) {

    puVar1 = (undefined8 *)*puVar1;

  }

  local_30[0] = 0;

  local_30[1] = 0;

  lVar2 = -1;

  local_30[2] = 0;

  local_30[3] = 0;

  do {

    lVar2 = lVar2 + 1;

  } while (*(char *)((longlong)puVar1 + lVar2) != '\0');

  FUN_140027e30(local_30);

  lVar2 = FUN_1400273e0(param_1,local_30);

  if (lVar2 != 0) {

    FID_conflict__assert

              (L"!Find( TIXML_STRING( addMe->Name() ) )",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x5be);

  }

  if (0xf < (ulonglong)local_30[3]) {

    if (0xfff < local_30[3] + 1U) {

      if (0x1f < (local_30[0] - *(longlong *)(local_30[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  *(longlong *)(param_2 + 0x68) = param_1;

  *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_1 + 0x60);

  *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x68) = param_2;

  *(longlong *)(param_1 + 0x60) = param_2;

  return;

}





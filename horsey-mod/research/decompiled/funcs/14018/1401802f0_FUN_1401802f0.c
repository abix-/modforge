// Address: 0x1401802f0
// Ghidra name: FUN_1401802f0
// ============ 0x1401802f0 FUN_1401802f0 (size=263) ============


void FUN_1401802f0(undefined4 *param_1,undefined4 *param_2)



{

  WCHAR WVar1;

  int iVar2;

  WCHAR *pWVar3;

  WCHAR local_a8;

  WCHAR local_a6 [79];

  

  if ((param_1 != (undefined4 *)0x0) &&

     (iVar2 = GetLocaleInfoW(0x400,0x1f,&local_a8,0x50), iVar2 != 0)) {

    pWVar3 = &local_a8;

    WVar1 = local_a8;

    while (WVar1 != L'\0') {

      pWVar3 = pWVar3 + 1;

      if (WVar1 == L'M') {

        *param_1 = 2;

        break;

      }

      if (WVar1 == L'd') {

        *param_1 = 1;

        break;

      }

      if (WVar1 == L'y') {

        *param_1 = 0;

        break;

      }

      WVar1 = *pWVar3;

    }

  }

  if (((param_2 != (undefined4 *)0x0) &&

      (iVar2 = GetLocaleInfoW(0x400,0x1003,&local_a8,0x50), iVar2 != 0)) &&

     (pWVar3 = &local_a8, local_a8 != L'\0')) {

    while (pWVar3 = pWVar3 + 1, local_a8 != L'H') {

      if (local_a8 == L'h') {

        *param_2 = 1;

        return;

      }

      local_a8 = *pWVar3;

      if (local_a8 == L'\0') {

        return;

      }

    }

    *param_2 = 0;

  }

  return;

}





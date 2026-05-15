// Address: 0x14008d150
// Ghidra name: FUN_14008d150
// ============ 0x14008d150 FUN_14008d150 (size=160) ============


ulonglong FUN_14008d150(undefined8 param_1)



{

  BOOL BVar1;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  HANDLE hMem;

  char *_Str;

  size_t sVar2;

  undefined4 extraout_var_01;

  undefined4 extraout_var_02;

  ulonglong uVar3;

  

  BVar1 = IsClipboardFormatAvailable(1);

  uVar3 = CONCAT44(extraout_var,BVar1);

  if (BVar1 != 0) {

    BVar1 = OpenClipboard((HWND)0x0);

    uVar3 = CONCAT44(extraout_var_00,BVar1);

    if (BVar1 != 0) {

      hMem = GetClipboardData(1);

      if (hMem != (HANDLE)0x0) {

        _Str = GlobalLock(hMem);

        if (_Str != (char *)0x0) {

          sVar2 = strlen(_Str);

          FUN_140027f50(param_1,_Str,sVar2);

          GlobalUnlock(hMem);

          BVar1 = CloseClipboard();

          return CONCAT71((int7)(CONCAT44(extraout_var_01,BVar1) >> 8),1);

        }

      }

      BVar1 = CloseClipboard();

      uVar3 = CONCAT44(extraout_var_02,BVar1);

    }

  }

  return uVar3 & 0xffffffffffffff00;

}





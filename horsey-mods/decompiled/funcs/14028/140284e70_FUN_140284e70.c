// Address: 0x140284e70
// Ghidra name: FUN_140284e70
// ============ 0x140284e70 FUN_140284e70 (size=327) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_140284e70(void)



{

  undefined1 uVar1;

  undefined7 uVar2;

  

  if (DAT_1403fde10 == (HMODULE)0x0) {

    DAT_1403fde10 = LoadLibraryW(L"XInput1_4.dll");

    uVar1 = (char)DAT_1403fde10;

    uVar2 = (int7)((ulonglong)DAT_1403fde10 >> 8);

    if (DAT_1403fde10 == (HMODULE)0x0) {

      DAT_1403fde10 = LoadLibraryW(L"XInput1_3.dll");

      uVar1 = (char)DAT_1403fde10;

      uVar2 = (int7)((ulonglong)DAT_1403fde10 >> 8);

    }

    if (DAT_1403fde10 == (HMODULE)0x0) {

      DAT_1403fde10 = LoadLibraryW(L"XInput9_1_0.dll");

      uVar1 = (char)DAT_1403fde10;

      uVar2 = (int7)((ulonglong)DAT_1403fde10 >> 8);

      if (DAT_1403fde10 == (HMODULE)0x0) {

        return 0;

      }

    }

    _DAT_1403fde18 = 1;

    DAT_1403fdde8 = GetProcAddress((HMODULE)CONCAT71(uVar2,uVar1),(LPCSTR)0x64);

    if (DAT_1403fdde8 == (FARPROC)0x0) {

      DAT_1403fdde8 = GetProcAddress(DAT_1403fde10,"XInputGetState");

    }

    DAT_1403fddf0 = GetProcAddress(DAT_1403fde10,"XInputSetState");

    DAT_1403fddf8 = GetProcAddress(DAT_1403fde10,"XInputGetCapabilities");

    DAT_1403fde00 = GetProcAddress(DAT_1403fde10,(LPCSTR)0x6c);

    DAT_1403fde08 = GetProcAddress(DAT_1403fde10,"XInputGetBatteryInformation");

    if (((DAT_1403fdde8 == (FARPROC)0x0) || (DAT_1403fddf0 == (FARPROC)0x0)) ||

       (DAT_1403fddf8 == (FARPROC)0x0)) {

      FUN_140284fc0();

      return 0;

    }

  }

  else {

    _DAT_1403fde18 = _DAT_1403fde18 + 1;

  }

  return 1;

}





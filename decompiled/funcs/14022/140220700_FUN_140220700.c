// Address: 0x140220700
// Ghidra name: FUN_140220700
// ============ 0x140220700 FUN_140220700 (size=359) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined1 FUN_140220700(void)



{

  if (DAT_1403fdbb0 != (HMODULE)0x0) {

    _DAT_1403fdbb8 = _DAT_1403fdbb8 + 1;

    return 1;

  }

  DAT_1403fdbb0 = LoadLibraryW(L"hid.dll");

  if (DAT_1403fdbb0 != (HMODULE)0x0) {

    _DAT_1403fdbb8 = 1;

    _DAT_1403ffc40 = GetProcAddress(DAT_1403fdbb0,"HidD_GetAttributes");

    DAT_1403ffc38 = GetProcAddress(DAT_1403fdbb0,"HidD_GetManufacturerString");

    DAT_1403ffc30 = GetProcAddress(DAT_1403fdbb0,"HidD_GetProductString");

    DAT_1403ffc28 = GetProcAddress(DAT_1403fdbb0,"HidP_GetCaps");

    DAT_1403ffc20 = GetProcAddress(DAT_1403fdbb0,"HidP_GetButtonCaps");

    DAT_1403ffc18 = GetProcAddress(DAT_1403fdbb0,"HidP_GetValueCaps");

    DAT_1403ffc10 = GetProcAddress(DAT_1403fdbb0,"HidP_MaxDataListLength");

    DAT_1403ffc08 = GetProcAddress(DAT_1403fdbb0,"HidP_GetData");

    if ((((DAT_1403ffc38 != (FARPROC)0x0) && (DAT_1403ffc30 != (FARPROC)0x0)) &&

        (DAT_1403ffc28 != (FARPROC)0x0)) &&

       (((DAT_1403ffc20 != (FARPROC)0x0 && (DAT_1403ffc18 != (FARPROC)0x0)) &&

        ((DAT_1403ffc10 != (FARPROC)0x0 && (DAT_1403ffc08 != (FARPROC)0x0)))))) {

      return 1;

    }

    FUN_140220910();

  }

  return 0;

}





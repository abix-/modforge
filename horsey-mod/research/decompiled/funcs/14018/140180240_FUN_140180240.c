// Address: 0x140180240
// Ghidra name: FUN_140180240
// ============ 0x140180240 FUN_140180240 (size=174) ============


undefined8 FUN_140180240(undefined8 *param_1)



{

  undefined8 uVar1;

  HMODULE hModule;

  _FILETIME local_res8 [4];

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","ticks");

    return uVar1;

  }

  local_res8[0].dwLowDateTime = 0;

  local_res8[0].dwHighDateTime = 0;

  if (DAT_1403fc6d0 == (FARPROC)0x0) {

    if (DAT_1403fc6d8 == '\0') {

      hModule = GetModuleHandleW(L"kernel32.dll");

      if (hModule != (HMODULE)0x0) {

        DAT_1403fc6d0 = GetProcAddress(hModule,"GetSystemTimePreciseAsFileTime");

      }

      DAT_1403fc6d8 = '\x01';

      if (DAT_1403fc6d0 != (FARPROC)0x0) goto LAB_1401802cf;

    }

    GetSystemTimeAsFileTime(local_res8);

  }

  else {

LAB_1401802cf:

    (*DAT_1403fc6d0)(local_res8);

  }

  uVar1 = FUN_14017d450((ulonglong)local_res8[0] & 0xffffffff,local_res8[0].dwHighDateTime);

  *param_1 = uVar1;

  return 1;

}





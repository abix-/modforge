// Address: 0x1402c6fd8
// Ghidra name: FUN_1402c6fd8
// ============ 0x1402c6fd8 FUN_1402c6fd8 (size=76) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402c6fd8(void)



{

  HMODULE hModule;

  

  hModule = GetModuleHandleW(L"kernel32.dll");

  DAT_1403fe510 = GetProcAddress(hModule,"GetSystemTimePreciseAsFileTime");

  _DAT_1403fe518 = GetProcAddress(hModule,"GetTempPath2W");

  return 0;

}





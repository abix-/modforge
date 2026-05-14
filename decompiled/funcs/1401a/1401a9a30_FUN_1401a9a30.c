// Address: 0x1401a9a30
// Ghidra name: FUN_1401a9a30
// ============ 0x1401a9a30 FUN_1401a9a30 (size=100) ============


undefined1 FUN_1401a9a30(void)



{

  HMODULE hModule;

  FARPROC pFVar1;

  

  if (DAT_1403fcd6b == '\0') {

    hModule = LoadLibraryW(L"ntdll.dll");

    if (hModule != (HMODULE)0x0) {

      pFVar1 = GetProcAddress(hModule,"wine_get_version");

      if (pFVar1 != (FARPROC)0x0) {

        DAT_1403fcd6c = 1;

      }

      FreeLibrary(hModule);

    }

    DAT_1403fcd6b = '\x01';

  }

  return DAT_1403fcd6c;

}





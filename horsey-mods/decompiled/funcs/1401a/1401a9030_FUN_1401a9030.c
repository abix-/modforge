// Address: 0x1401a9030
// Ghidra name: FUN_1401a9030
// ============ 0x1401a9030 FUN_1401a9030 (size=179) ============


bool FUN_1401a9030(uint param_1)



{

  HMODULE hModule;

  FARPROC pFVar1;

  bool bVar2;

  undefined4 local_128 [3];

  uint local_11c;

  

  if (DAT_1403fcd78 != 0) {

    return param_1 <= DAT_1403fcd78;

  }

  hModule = LoadLibraryW(L"ntdll.dll");

  bVar2 = false;

  if (hModule != (HMODULE)0x0) {

    pFVar1 = GetProcAddress(hModule,"RtlGetVersion");

    local_128[0] = 0x114;

    local_11c = 0;

    if (pFVar1 != (FARPROC)0x0) {

      (*pFVar1)(local_128);

    }

    FreeLibrary(hModule);

    DAT_1403fcd78 = local_11c & 0xfffffff;

    bVar2 = param_1 <= DAT_1403fcd78;

  }

  return bVar2;

}





// Address: 0x140210a10
// Ghidra name: FUN_140210a10
// ============ 0x140210a10 FUN_140210a10 (size=182) ============


_FILETIME FUN_140210a10(char *param_1)



{

  BOOL BVar1;

  size_t sVar2;

  LPCWSTR lpFileName;

  HANDLE hFile;

  _FILETIME _Var3;

  _FILETIME local_res10;

  

  _Var3.dwLowDateTime = 0;

  _Var3.dwHighDateTime = 0;

  sVar2 = strlen(param_1);

  lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar2 + 1);

  if (lpFileName != (LPCWSTR)0x0) {

    hFile = CreateFileW(lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);

    if (hFile != (HANDLE)0xffffffffffffffff) {

      BVar1 = GetFileTime(hFile,(LPFILETIME)0x0,(LPFILETIME)0x0,&local_res10);

      if (BVar1 != 0) {

        _Var3 = local_res10;

      }

      CloseHandle(hFile);

    }

    FUN_1401841e0(lpFileName);

  }

  return _Var3;

}





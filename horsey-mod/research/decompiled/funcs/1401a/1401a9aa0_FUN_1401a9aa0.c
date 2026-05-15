// Address: 0x1401a9aa0
// Ghidra name: FUN_1401a9aa0
// ============ 0x1401a9aa0 FUN_1401a9aa0 (size=91) ============


void FUN_1401a9aa0(LPCSTR param_1)



{

  if (DAT_1403fcd6a == '\0') {

    DAT_1403fcd70 = LoadLibraryExW(L"combase.dll",(HANDLE)0x0,0x800);

    DAT_1403fcd6a = '\x01';

  }

  if (DAT_1403fcd70 == (HMODULE)0x0) {

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401a9aee. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  GetProcAddress(DAT_1403fcd70,param_1);

  return;

}





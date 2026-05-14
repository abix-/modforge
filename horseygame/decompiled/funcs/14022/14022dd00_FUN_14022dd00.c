// Address: 0x14022dd00
// Ghidra name: FUN_14022dd00
// ============ 0x14022dd00 FUN_14022dd00 (size=197) ============


undefined8 FUN_14022dd00(char *param_1)



{

  int iVar1;

  undefined8 uVar2;

  size_t sVar3;

  LPCWSTR lpFile;

  HINSTANCE pHVar4;

  

  iVar1 = FUN_1401a9610();

  if (iVar1 < 0) {

    uVar2 = FUN_1401a9ef0("CoInitialize failed",iVar1);

    return uVar2;

  }

  sVar3 = strlen(param_1);

  lpFile = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar3 + 1);

  if (lpFile == (LPCWSTR)0x0) {

    CoUninitialize();

    return 0;

  }

  pHVar4 = ShellExecuteW((HWND)0x0,L"open",lpFile,(LPCWSTR)0x0,(LPCWSTR)0x0,1);

  FUN_1401841e0(lpFile);

  CoUninitialize();

  if (pHVar4 < (HINSTANCE)0x21) {

    uVar2 = FUN_1401a9ed0("Couldn\'t open given URL.");

    return uVar2;

  }

  return 1;

}





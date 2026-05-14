// Address: 0x1401885b0
// Ghidra name: FUN_1401885b0
// ============ 0x1401885b0 FUN_1401885b0 (size=185) ============


HMODULE FUN_1401885b0(char *param_1)



{

  size_t sVar1;

  LPCWSTR lpLibFileName;

  HMODULE pHVar2;

  undefined1 local_208 [512];

  

  if (param_1 == (char *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","sofile");

    return (HMODULE)0x0;

  }

  sVar1 = strlen(param_1);

  lpLibFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar1 + 1);

  pHVar2 = LoadLibraryW(lpLibFileName);

  FUN_1401841e0(lpLibFileName);

  if (pHVar2 == (HMODULE)0x0) {

    FUN_14012ef10(local_208,0x200,"Failed loading %s",param_1);

    FUN_1401a9ed0(local_208);

  }

  return pHVar2;

}





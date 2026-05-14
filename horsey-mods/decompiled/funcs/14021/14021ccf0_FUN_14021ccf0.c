// Address: 0x14021ccf0
// Ghidra name: FUN_14021ccf0
// ============ 0x14021ccf0 FUN_14021ccf0 (size=227) ============


undefined8 FUN_14021ccf0(char *param_1,char *param_2)



{

  BOOL BVar1;

  size_t sVar2;

  LPCWSTR lpExistingFileName;

  LPCWSTR lpNewFileName;

  undefined8 uVar3;

  

  sVar2 = strlen(param_1);

  lpExistingFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar2 + 1);

  if (lpExistingFileName != (LPCWSTR)0x0) {

    sVar2 = strlen(param_2);

    lpNewFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_2,sVar2 + 1);

    if (lpNewFileName != (LPCWSTR)0x0) {

      BVar1 = CopyFileExW(lpExistingFileName,lpNewFileName,(LPPROGRESS_ROUTINE)0x0,(LPVOID)0x0,

                          (LPBOOL)0x0,0x1008);

      FUN_1401841e0(lpNewFileName);

      FUN_1401841e0(lpExistingFileName);

      if (BVar1 == 0) {

        uVar3 = FUN_1401a9ed0("Couldn\'t copy path");

        return uVar3;

      }

      return 1;

    }

    FUN_1401841e0();

  }

  return 0;

}





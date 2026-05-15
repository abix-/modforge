// Address: 0x14021cde0
// Ghidra name: FUN_14021cde0
// ============ 0x14021cde0 FUN_14021cde0 (size=171) ============


undefined8 FUN_14021cde0(char *param_1)



{

  BOOL BVar1;

  DWORD DVar2;

  BOOL BVar3;

  size_t sVar4;

  LPCWSTR lpPathName;

  undefined8 uVar5;

  byte local_38 [48];

  

  sVar4 = strlen(param_1);

  lpPathName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar4 + 1);

  if (lpPathName == (LPCWSTR)0x0) {

    return 0;

  }

  BVar1 = CreateDirectoryW(lpPathName,(LPSECURITY_ATTRIBUTES)0x0);

  if ((((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 == 0xb7)) &&

      (BVar3 = GetFileAttributesExW(lpPathName,GetFileExInfoStandard,local_38), BVar3 != 0)) &&

     ((local_38[0] & 0x10) != 0)) {

    FUN_1401841e0(lpPathName);

    return 1;

  }

  FUN_1401841e0(lpPathName);

  if (BVar1 != 0) {

    return 1;

  }

  uVar5 = FUN_1401a9ed0("Couldn\'t create directory");

  return uVar5;

}





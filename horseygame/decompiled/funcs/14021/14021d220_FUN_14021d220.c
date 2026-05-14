// Address: 0x14021d220
// Ghidra name: FUN_14021d220
// ============ 0x14021d220 FUN_14021d220 (size=182) ============


undefined8 FUN_14021d220(char *param_1)



{

  BOOL BVar1;

  DWORD DVar2;

  int iVar3;

  size_t sVar4;

  LPCWSTR lpFileName;

  undefined8 uVar5;

  byte local_38 [48];

  

  sVar4 = strlen(param_1);

  lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar4 + 1);

  if (lpFileName == (LPCWSTR)0x0) {

    return 0;

  }

  BVar1 = GetFileAttributesExW(lpFileName,GetFileExInfoStandard,local_38);

  if (BVar1 == 0) {

    FUN_1401841e0();

    DVar2 = GetLastError();

    if (DVar2 != 2) {

      uVar5 = FUN_1401a9ed0("Couldn\'t get path\'s attributes");

      return uVar5;

    }

  }

  else {

    if ((local_38[0] & 0x10) == 0) {

      iVar3 = DeleteFileW(lpFileName);

    }

    else {

      iVar3 = RemoveDirectoryW(lpFileName);

    }

    FUN_1401841e0(lpFileName);

    if (iVar3 == 0) {

      uVar5 = FUN_1401a9ed0("Couldn\'t remove path");

      return uVar5;

    }

  }

  return 1;

}





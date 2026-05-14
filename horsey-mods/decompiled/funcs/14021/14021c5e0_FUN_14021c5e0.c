// Address: 0x14021c5e0
// Ghidra name: FUN_14021c5e0
// ============ 0x14021c5e0 FUN_14021c5e0 (size=245) ============


undefined8 FUN_14021c5e0(void)



{

  LPWSTR lpFilename;

  LPWSTR pWVar1;

  DWORD DVar2;

  LPWSTR pWVar3;

  longlong lVar4;

  undefined8 uVar5;

  int iVar6;

  uint nSize;

  

  nSize = 0x80;

  pWVar3 = (LPWSTR)FUN_140184230(0,0x100);

  pWVar1 = (LPWSTR)0x0;

  while( true ) {

    lpFilename = pWVar3;

    if (lpFilename == (LPWSTR)0x0) {

      FUN_1401841e0(pWVar1);

      return 0;

    }

    DVar2 = GetModuleFileNameW((HMODULE)0x0,lpFilename,nSize);

    if (DVar2 < nSize - 1) break;

    nSize = nSize * 2;

    pWVar3 = (LPWSTR)FUN_140184230(lpFilename,(ulonglong)nSize * 2);

    pWVar1 = lpFilename;

  }

  if (DVar2 == 0) {

    FUN_1401841e0(lpFilename);

    FUN_1401a9ed0("Couldn\'t locate our .exe");

    return 0;

  }

  iVar6 = DVar2 - 1;

  lVar4 = (longlong)iVar6;

  if (0 < iVar6) {

    do {

      if (lpFilename[lVar4] == L'\\') break;

      iVar6 = iVar6 + -1;

      lVar4 = lVar4 + -1;

    } while (0 < lVar4);

  }

  lpFilename[(longlong)iVar6 + 1] = L'\0';

  lVar4 = FUN_14012fd40(lpFilename);

  uVar5 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lpFilename,lVar4 * 2 + 2);

  FUN_1401841e0(lpFilename);

  return uVar5;

}





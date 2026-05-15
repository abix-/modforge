// Address: 0x140178ad0
// Ghidra name: thunk_FUN_14021c6e0
// ============ 0x140178ad0 thunk_FUN_14021c6e0 (size=5) ============


undefined8 thunk_FUN_14021c6e0(void)



{

  LPWSTR pWVar1;

  uint nBufferLength;

  uint uVar2;

  DWORD DVar3;

  LPWSTR lpBuffer;

  longlong lVar4;

  undefined8 uVar5;

  

  DVar3 = GetCurrentDirectoryW(0,(LPWSTR)0x0);

  pWVar1 = (LPWSTR)0x0;

  uVar2 = 0;

  while( true ) {

    nBufferLength = DVar3;

    if (nBufferLength == 0) {

      FUN_1401a9ed0("GetCurrentDirectoryW failed");

      return 0;

    }

    if (nBufferLength < uVar2) break;

    lpBuffer = (LPWSTR)FUN_140184230(pWVar1,(ulonglong)(nBufferLength + 1) * 2);

    if (lpBuffer == (LPWSTR)0x0) {

      FUN_1401841e0(pWVar1);

      return 0;

    }

    DVar3 = GetCurrentDirectoryW(nBufferLength,lpBuffer);

    pWVar1 = lpBuffer;

    uVar2 = nBufferLength;

  }

  if (pWVar1[nBufferLength - 1] != L'\\') {

    pWVar1[nBufferLength + 1] = L'\0';

    pWVar1[nBufferLength] = L'\\';

  }

  lVar4 = FUN_14012fd40(pWVar1);

  uVar5 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",pWVar1,lVar4 * 2 + 2);

  FUN_1401841e0(pWVar1);

  return uVar5;

}





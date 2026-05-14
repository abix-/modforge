// Address: 0x1402f47f4
// Ghidra name: FUN_1402f47f4
// ============ 0x1402f47f4 FUN_1402f47f4 (size=270) ============


longlong FUN_1402f47f4(void)



{

  WCHAR WVar1;

  int iVar2;

  LPWCH pWVar3;

  longlong lVar4;

  WCHAR *pWVar6;

  ulonglong uVar7;

  longlong lVar5;

  

  pWVar3 = GetEnvironmentStringsW();

  if (pWVar3 != (LPWCH)0x0) {

    WVar1 = *pWVar3;

    pWVar6 = pWVar3;

    while (WVar1 != L'\0') {

      lVar4 = -1;

      do {

        lVar5 = lVar4;

        lVar4 = lVar5 + 1;

      } while (pWVar6[lVar4] != L'\0');

      pWVar6 = pWVar6 + lVar5 + 2;

      WVar1 = *pWVar6;

    }

    uVar7 = (longlong)pWVar6 + (2 - (longlong)pWVar3) >> 1;

    iVar2 = FUN_1402f31e0(0,0,pWVar3,uVar7 & 0xffffffff,0,0,0,0);

    if (iVar2 != 0) {

      lVar4 = _malloc_base((longlong)iVar2);

      if (lVar4 != 0) {

        iVar2 = FUN_1402f31e0(0,0,pWVar3,uVar7 & 0xffffffff,lVar4,iVar2,0,0);

        if (iVar2 == 0) {

          FUN_1402e9a80(lVar4);

          lVar4 = 0;

        }

        else {

          FUN_1402e9a80(0);

        }

        FreeEnvironmentStringsW(pWVar3);

        return lVar4;

      }

      FUN_1402e9a80(0);

    }

    FreeEnvironmentStringsW(pWVar3);

  }

  return 0;

}





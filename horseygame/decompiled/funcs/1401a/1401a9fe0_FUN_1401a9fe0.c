// Address: 0x1401a9fe0
// Ghidra name: FUN_1401a9fe0
// ============ 0x1401a9fe0 FUN_1401a9fe0 (size=390) ============


void FUN_1401a9fe0(HWND param_1)



{

  int iVar1;

  HMODULE pHVar2;

  FARPROC pFVar3;

  FARPROC pFVar4;

  FARPROC pFVar5;

  FARPROC pFVar6;

  INT_PTR IVar7;

  HMODULE pHVar8;

  undefined8 uVar9;

  bool bVar10;

  uint local_res10 [2];

  undefined4 local_38 [2];

  uint *local_30;

  undefined8 local_28;

  

  iVar1 = FUN_1401a9030(0x4563);

  if ((iVar1 != 0) && (pHVar2 = LoadLibraryW(L"uxtheme.dll"), pHVar2 != (HMODULE)0x0)) {

    pFVar3 = GetProcAddress(pHVar2,(LPCSTR)0x68);

    pFVar4 = GetProcAddress(pHVar2,(LPCSTR)0x84);

    pFVar5 = GetProcAddress(pHVar2,(LPCSTR)0x85);

    iVar1 = FUN_1401a9030(0x47ba);

    uVar9 = 0;

    if (iVar1 == 0) {

      pHVar8 = pHVar2;

      pFVar6 = GetProcAddress(pHVar2,(LPCSTR)0x87);

      if (pFVar6 != (FARPROC)0x0) {

        (*pFVar6)(CONCAT71((int7)((ulonglong)pHVar8 >> 8),1));

      }

    }

    else {

      pFVar6 = GetProcAddress(pHVar2,(LPCSTR)0x87);

      if (pFVar6 != (FARPROC)0x0) {

        (*pFVar6)(1);

      }

    }

    if (pFVar3 != (FARPROC)0x0) {

      (*pFVar3)();

    }

    if (pFVar5 != (FARPROC)0x0) {

      (*pFVar5)(param_1,CONCAT71((int7)((ulonglong)uVar9 >> 8),1));

    }

    if (pFVar4 == (FARPROC)0x0) {

      iVar1 = FUN_14016dbe0();

      bVar10 = iVar1 == 2;

    }

    else {

      IVar7 = (*pFVar4)();

      bVar10 = (char)IVar7 != '\0';

    }

    local_res10[0] = (uint)bVar10;

    FreeLibrary(pHVar2);

    iVar1 = FUN_1401a9030(0x47ba);

    if (iVar1 == 0) {

      SetPropW(param_1,L"UseImmersiveDarkModeColors",(HANDLE)(longlong)(int)local_res10[0]);

      return;

    }

    pHVar2 = GetModuleHandleW(L"user32.dll");

    if ((pHVar2 != (HMODULE)0x0) &&

       (pFVar3 = GetProcAddress(pHVar2,"SetWindowCompositionAttribute"), pFVar3 != (FARPROC)0x0)) {

      local_30 = local_res10;

      local_38[0] = 0x1a;

      local_28 = 4;

      (*pFVar3)(param_1,local_38);

    }

  }

  return;

}





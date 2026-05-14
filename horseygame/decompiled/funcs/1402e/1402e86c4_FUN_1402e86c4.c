// Address: 0x1402e86c4
// Ghidra name: FUN_1402e86c4
// ============ 0x1402e86c4 FUN_1402e86c4 (size=144) ============


PVOID FUN_1402e86c4(void)



{

  DWORD dwErrCode;

  PVOID pvVar1;

  PVOID pvVar2;

  

  pvVar2 = (PVOID)0x0;

  if (DAT_1403ff148 == '\0') {

    dwErrCode = GetLastError();

    pvVar1 = pvVar2;

    if (DAT_1403e8d20 != 0xffffffff) {

      pvVar1 = FlsGetValue(DAT_1403e8d20);

    }

    if ((pvVar1 != (PVOID)0xffffffffffffffff) && (pvVar2 = pvVar1, pvVar1 == (PVOID)0x0)) {

      pvVar2 = (PVOID)FUN_1402e8544();

    }

    SetLastError(dwErrCode);

  }

  else {

    pvVar1 = pvVar2;

    if (DAT_1403e8d20 != 0xffffffff) {

      pvVar1 = (PVOID)FUN_1402ec3b0();

    }

    if ((pvVar1 != (PVOID)0xffffffffffffffff) && (pvVar2 = pvVar1, pvVar1 == (PVOID)0x0)) {

      pvVar2 = (PVOID)FUN_1402e8544();

    }

  }

  return pvVar2;

}





// Address: 0x1402e8544
// Ghidra name: FUN_1402e8544
// ============ 0x1402e8544 FUN_1402e8544 (size=181) ============


__acrt_ptd * FUN_1402e8544(void)



{

  DWORD dwErrCode;

  BOOL BVar1;

  __acrt_ptd *lpFlsData;

  

  dwErrCode = GetLastError();

  BVar1 = FlsSetValue(DAT_1403e8d20,(PVOID)0xffffffffffffffff);

  if (BVar1 != 0) {

    lpFlsData = (__acrt_ptd *)_calloc_base(1);

    if (lpFlsData != (__acrt_ptd *)0x0) {

      BVar1 = FlsSetValue(DAT_1403e8d20,lpFlsData);

      if (BVar1 == 0) {

        FlsSetValue(DAT_1403e8d20,(PVOID)0x0);

        FUN_1402e9a80(lpFlsData);

        lpFlsData = (__acrt_ptd *)0x0;

      }

      else {

        construct_ptd_array(lpFlsData);

        FUN_1402e9a80(0);

      }

      SetLastError(dwErrCode);

      return lpFlsData;

    }

    FlsSetValue(DAT_1403e8d20,(PVOID)0x0);

    FUN_1402e9a80(0);

  }

  SetLastError(dwErrCode);

  return (__acrt_ptd *)0x0;

}





// Address: 0x1402c98e0
// Ghidra name: __vcrt_getptd_noinit
// ============ 0x1402c98e0 __vcrt_getptd_noinit (size=77) ============


/* Library Function - Single Match

    __vcrt_getptd_noinit

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



longlong __vcrt_getptd_noinit(void)



{

  DWORD dwErrCode;

  longlong lVar1;

  

  if (DAT_1403e8b50 == -1) {

    lVar1 = 0;

  }

  else {

    dwErrCode = GetLastError();

    lVar1 = __vcrt_FlsGetValue(DAT_1403e8b50);

    SetLastError(dwErrCode);

    if (lVar1 == -1) {

      lVar1 = 0;

    }

  }

  return lVar1;

}





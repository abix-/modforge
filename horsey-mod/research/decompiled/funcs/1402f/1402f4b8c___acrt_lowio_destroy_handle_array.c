// Address: 0x1402f4b8c
// Ghidra name: __acrt_lowio_destroy_handle_array
// ============ 0x1402f4b8c __acrt_lowio_destroy_handle_array (size=80) ============


/* Library Function - Single Match

    __acrt_lowio_destroy_handle_array

   

   Library: Visual Studio 2019 Release */



void __acrt_lowio_destroy_handle_array(LPCRITICAL_SECTION param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  

  if (param_1 != (LPCRITICAL_SECTION)0x0) {

    for (lpCriticalSection = param_1;

        lpCriticalSection != (LPCRITICAL_SECTION)&param_1[0x73].LockCount;

        lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].SpinCount) {

      DeleteCriticalSection(lpCriticalSection);

    }

    FUN_1402e9a80(param_1);

  }

  return;

}





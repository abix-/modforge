// Address: 0x1402f8534
// Ghidra name: __dcrt_lowio_ensure_console_output_initialized
// ============ 0x1402f8534 __dcrt_lowio_ensure_console_output_initialized (size=82) ============


/* Library Function - Single Match

    __dcrt_lowio_ensure_console_output_initialized

   

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual

   Studio 2019 Release */



bool __dcrt_lowio_ensure_console_output_initialized(void)



{

  if (DAT_1403e96e0 == (HANDLE)0xfffffffffffffffe) {

    DAT_1403e96e0 = CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);

  }

  return DAT_1403e96e0 != (HANDLE)0xffffffffffffffff;

}





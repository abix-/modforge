// Address: 0x1402c8008
// Ghidra name: __raise_securityfailure
// ============ 0x1402c8008 __raise_securityfailure (size=52) ============


/* Library Function - Single Match

    __raise_securityfailure

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)



{

  HANDLE hProcess;

  

  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);

  UnhandledExceptionFilter(param_1);

  hProcess = GetCurrentProcess();

                    /* WARNING: Could not recover jumptable at 0x0001402c8035. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  TerminateProcess(hProcess,0xc0000409);

  return;

}





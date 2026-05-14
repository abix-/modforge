// Address: 0x14017e1a0
// Ghidra name: FUN_14017e1a0
// ============ 0x14017e1a0 FUN_14017e1a0 (size=33) ============


void FUN_14017e1a0(UINT param_1)



{

  HANDLE hProcess;

  

  hProcess = GetCurrentProcess();

  TerminateProcess(hProcess,param_1);

                    /* WARNING: Subroutine does not return */

  ExitProcess(param_1);

}





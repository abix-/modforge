// Address: 0x1402da150
// Ghidra name: FUN_1402da150
// ============ 0x1402da150 FUN_1402da150 (size=44) ============


void FUN_1402da150(UINT param_1,char param_2)



{

  HANDLE hProcess;

  

  if (param_2 != '\0') {

    hProcess = GetCurrentProcess();

    TerminateProcess(hProcess,param_1);

  }

  FUN_1402da180(param_1);

                    /* WARNING: Subroutine does not return */

  ExitProcess(param_1);

}





// Address: 0x140180210
// Ghidra name: FUN_140180210
// ============ 0x140180210 FUN_140180210 (size=43) ============


void FUN_140180210(longlong param_1)



{

  WaitForSingleObjectEx(*(HANDLE *)(param_1 + 8),0xffffffff,0);

                    /* WARNING: Could not recover jumptable at 0x000140180234. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  CloseHandle(*(HANDLE *)(param_1 + 8));

  return;

}





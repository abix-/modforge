// Address: 0x1402c7024
// Ghidra name: FUN_1402c7024
// ============ 0x1402c7024 FUN_1402c7024 (size=39) ============


void FUN_1402c7024(LPFILETIME param_1)



{

  if (DAT_1403fe510 != 0) {

    (*(code *)PTR__guard_dispatch_icall_140302c68)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001402c7044. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  GetSystemTimeAsFileTime(param_1);

  return;

}





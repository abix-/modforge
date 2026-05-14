// Address: 0x1401a9ea0
// Ghidra name: FUN_1401a9ea0
// ============ 0x1401a9ea0 FUN_1401a9ea0 (size=33) ============


void FUN_1401a9ea0(void)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = (code *)FUN_1401a9aa0("RoUninitialize");

  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0001401a9eb9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*UNRECOVERED_JUMPTABLE)();

    return;

  }

  return;

}





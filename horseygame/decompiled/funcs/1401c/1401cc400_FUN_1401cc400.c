// Address: 0x1401cc400
// Ghidra name: FUN_1401cc400
// ============ 0x1401cc400 FUN_1401cc400 (size=23) ============


void FUN_1401cc400(longlong param_1,undefined1 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = *(code **)(**(longlong **)(param_1 + 0x120) + 0xc0);

                    /* WARNING: Could not recover jumptable at 0x0001401cc414. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(longlong **)(param_1 + 0x120),param_2,UNRECOVERED_JUMPTABLE);

  return;

}





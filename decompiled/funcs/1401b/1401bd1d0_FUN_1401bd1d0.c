// Address: 0x1401bd1d0
// Ghidra name: FUN_1401bd1d0
// ============ 0x1401bd1d0 FUN_1401bd1d0 (size=39) ============


void FUN_1401bd1d0(longlong param_1,undefined1 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  

  *(undefined1 *)(param_1 + 0x238) = param_2;

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(param_1 + 0x110) + 0xae0);

                    /* WARNING: Could not recover jumptable at 0x0001401bd1f4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(undefined8 *)(param_1 + 0x118),3,param_2,UNRECOVERED_JUMPTABLE);

  return;

}





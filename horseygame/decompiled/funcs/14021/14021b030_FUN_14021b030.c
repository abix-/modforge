// Address: 0x14021b030
// Ghidra name: FUN_14021b030
// ============ 0x14021b030 FUN_14021b030 (size=15) ============


void FUN_14021b030(longlong param_1,undefined8 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x60);

                    /* WARNING: Could not recover jumptable at 0x00014021b03c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(longlong *)(param_1 + 0x28),param_2,UNRECOVERED_JUMPTABLE);

  return;

}





// Address: 0x14021b3a0
// Ghidra name: FUN_14021b3a0
// ============ 0x14021b3a0 FUN_14021b3a0 (size=15) ============


void FUN_14021b3a0(longlong param_1)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x78);

                    /* WARNING: Could not recover jumptable at 0x00014021b3ac. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(longlong *)(param_1 + 0x28),UNRECOVERED_JUMPTABLE);

  return;

}





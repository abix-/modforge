// Address: 0x14021b430
// Ghidra name: FUN_14021b430
// ============ 0x14021b430 FUN_14021b430 (size=18) ============


void FUN_14021b430(longlong param_1)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x88);

                    /* WARNING: Could not recover jumptable at 0x00014021b43f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(longlong *)(param_1 + 0x28),UNRECOVERED_JUMPTABLE);

  return;

}





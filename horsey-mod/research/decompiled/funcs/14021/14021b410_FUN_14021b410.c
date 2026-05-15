// Address: 0x14021b410
// Ghidra name: FUN_14021b410
// ============ 0x14021b410 FUN_14021b410 (size=15) ============


void FUN_14021b410(longlong param_1,undefined8 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  

  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x70);

                    /* WARNING: Could not recover jumptable at 0x00014021b41c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(*(longlong *)(param_1 + 0x28),param_2,UNRECOVERED_JUMPTABLE);

  return;

}





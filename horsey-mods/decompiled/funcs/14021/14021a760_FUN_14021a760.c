// Address: 0x14021a760
// Ghidra name: FUN_14021a760
// ============ 0x14021a760 FUN_14021a760 (size=57) ============


void FUN_14021a760(undefined4 param_1,undefined8 param_2,code *UNRECOVERED_JUMPTABLE)



{

  undefined4 local_res8 [2];

  undefined8 local_res10 [3];

  

  local_res8[0] = param_1;

  local_res10[0] = param_2;

  FUN_14021a7a0(local_res8,local_res10);

  FUN_14017eb20();

                    /* WARNING: Could not recover jumptable at 0x00014021a796. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(local_res8[0],local_res10[0]);

  return;

}





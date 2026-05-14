// Address: 0x1402069e0
// Ghidra name: FUN_1402069e0
// ============ 0x1402069e0 FUN_1402069e0 (size=55) ============


void FUN_1402069e0(undefined8 param_1,undefined4 param_2)



{

  code *UNRECOVERED_JUMPTABLE;

  longlong lVar1;

  undefined4 local_res18 [4];

  

  lVar1 = FUN_140207ae0(param_1,local_res18);

  if (lVar1 != 0) {

    UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(lVar1 + 0x68) + 0x40);

                    /* WARNING: Could not recover jumptable at 0x000140206a0e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*UNRECOVERED_JUMPTABLE)(lVar1,local_res18[0],param_2,UNRECOVERED_JUMPTABLE);

    return;

  }

  return;

}





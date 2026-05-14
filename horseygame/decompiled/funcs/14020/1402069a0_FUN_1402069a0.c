// Address: 0x1402069a0
// Ghidra name: FUN_1402069a0
// ============ 0x1402069a0 FUN_1402069a0 (size=51) ============


undefined8 FUN_1402069a0(undefined8 param_1)



{

  code *UNRECOVERED_JUMPTABLE;

  longlong lVar1;

  undefined8 uVar2;

  undefined4 local_res10 [6];

  

  lVar1 = FUN_140207ae0(param_1,local_res10);

  if (lVar1 != 0) {

    UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)(lVar1 + 0x68) + 0x38);

                    /* WARNING: Could not recover jumptable at 0x0001402069c6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (*UNRECOVERED_JUMPTABLE)(lVar1,local_res10[0],UNRECOVERED_JUMPTABLE);

    return uVar2;

  }

  return 0xffffffff;

}





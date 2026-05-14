// Address: 0x1401e22a0
// Ghidra name: FUN_1401e22a0
// ============ 0x1401e22a0 FUN_1401e22a0 (size=79) ============


void FUN_1401e22a0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  longlong *plVar2;

  code *UNRECOVERED_JUMPTABLE;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  (**(code **)(**(longlong **)(lVar1 + 0x28) + 0xc0))();

  plVar2 = *(longlong **)(lVar1 + 0x28);

  UNRECOVERED_JUMPTABLE = *(code **)(*plVar2 + 0x68);

                    /* WARNING: Could not recover jumptable at 0x0001401e22ec. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*UNRECOVERED_JUMPTABLE)(plVar2,param_4,param_3,UNRECOVERED_JUMPTABLE);

  return;

}





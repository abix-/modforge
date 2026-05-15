// Address: 0x1401efba0
// Ghidra name: FUN_1401efba0
// ============ 0x1401efba0 FUN_1401efba0 (size=92) ============


void FUN_1401efba0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 uVar1;

  

  uVar1 = FUN_1401efcb0(param_3);

  (**(code **)(param_1 + 0x188))(param_2,0x2802,uVar1);

  uVar1 = FUN_1401efcb0(param_4);

                    /* WARNING: Could not recover jumptable at 0x0001401efbf9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x188))(param_2,0x2803,uVar1);

  return;

}





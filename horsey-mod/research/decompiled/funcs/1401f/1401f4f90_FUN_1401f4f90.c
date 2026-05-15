// Address: 0x1401f4f90
// Ghidra name: FUN_1401f4f90
// ============ 0x1401f4f90 FUN_1401f4f90 (size=92) ============


void FUN_1401f4f90(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  undefined4 uVar1;

  

  uVar1 = FUN_1401efcb0(param_3);

  (**(code **)(param_1 + 0x130))(param_2,0x2802,uVar1);

  uVar1 = FUN_1401efcb0(param_4);

                    /* WARNING: Could not recover jumptable at 0x0001401f4fe9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x130))(param_2,0x2803,uVar1);

  return;

}





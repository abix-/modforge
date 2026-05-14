// Address: 0x1401377d0
// Ghidra name: FUN_1401377d0
// ============ 0x1401377d0 FUN_1401377d0 (size=39) ============


undefined8 FUN_1401377d0(longlong param_1)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401377f4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 8))();

  return uVar1;

}





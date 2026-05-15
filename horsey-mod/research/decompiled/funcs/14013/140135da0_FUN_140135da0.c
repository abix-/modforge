// Address: 0x140135da0
// Ghidra name: FUN_140135da0
// ============ 0x140135da0 FUN_140135da0 (size=23) ============


void FUN_140135da0(undefined8 *param_1)



{

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x000140135db4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*(code *)*param_1)();

  return;

}





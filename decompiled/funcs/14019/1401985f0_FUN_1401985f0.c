// Address: 0x1401985f0
// Ghidra name: FUN_1401985f0
// ============ 0x1401985f0 FUN_1401985f0 (size=54) ============


undefined8 FUN_1401985f0(undefined8 *param_1)



{

  undefined8 uVar1;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","asyncio");

    return 0xffffffffffffffff;

  }

                    /* WARNING: Could not recover jumptable at 0x000140198623. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (*(code *)*param_1)(param_1[5]);

  return uVar1;

}





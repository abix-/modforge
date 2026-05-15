// Address: 0x1401783e0
// Ghidra name: FUN_1401783e0
// ============ 0x1401783e0 FUN_1401783e0 (size=55) ============


ulonglong FUN_1401783e0(longlong param_1)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid storage container");

    return uVar1 & 0xffffffffffffff00;

  }

  if (*(code **)(param_1 + 0x10) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014017840d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x60));

    return uVar1;

  }

  return 1;

}





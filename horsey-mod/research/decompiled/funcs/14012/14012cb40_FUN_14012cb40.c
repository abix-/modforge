// Address: 0x14012cb40
// Ghidra name: FUN_14012cb40
// ============ 0x14012cb40 FUN_14012cb40 (size=84) ============


undefined8 FUN_14012cb40(longlong param_1)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

    return 0xffffffffffffffff;

  }

  if (*(code **)(param_1 + 0x10) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return 0xffffffffffffffff;

  }

                    /* WARNING: Could not recover jumptable at 0x00014012cb91. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x38));

  return uVar1;

}





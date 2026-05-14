// Address: 0x14012c730
// Ghidra name: FUN_14012c730
// ============ 0x14012c730 FUN_14012c730 (size=173) ============


undefined8 FUN_14012c730(longlong param_1,undefined8 param_2,longlong param_3)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

  }

  else {

    if (*(longlong *)(param_1 + 0x18) == 0) {

      *(undefined4 *)(param_1 + 0x40) = 5;

      FUN_14012e850("That operation is not supported");

      return 0;

    }

    if (param_3 != 0) {

      *(undefined4 *)(param_1 + 0x40) = 0;

      FUN_14012e710();

                    /* WARNING: Could not recover jumptable at 0x00014012c7da. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar1 = (**(code **)(param_1 + 0x18))

                        (*(undefined8 *)(param_1 + 0x38),param_2,param_3,param_1 + 0x40);

      return uVar1;

    }

  }

  return 0;

}





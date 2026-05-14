// Address: 0x14012cbb0
// Ghidra name: FUN_14012cbb0
// ============ 0x14012cbb0 FUN_14012cbb0 (size=173) ============


undefined8 FUN_14012cbb0(longlong param_1,undefined8 param_2,longlong param_3)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

  }

  else {

    if (*(longlong *)(param_1 + 0x20) == 0) {

      *(undefined4 *)(param_1 + 0x40) = 4;

      FUN_14012e850("That operation is not supported");

      return 0;

    }

    if (param_3 != 0) {

      *(undefined4 *)(param_1 + 0x40) = 0;

      FUN_14012e710();

                    /* WARNING: Could not recover jumptable at 0x00014012cc5a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar1 = (**(code **)(param_1 + 0x20))

                        (*(undefined8 *)(param_1 + 0x38),param_2,param_3,param_1 + 0x40);

      return uVar1;

    }

  }

  return 0;

}





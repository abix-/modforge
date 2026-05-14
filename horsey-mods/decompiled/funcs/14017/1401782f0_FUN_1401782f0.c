// Address: 0x1401782f0
// Ghidra name: FUN_1401782f0
// ============ 0x1401782f0 FUN_1401782f0 (size=240) ============


ulonglong FUN_1401782f0(longlong param_1,longlong param_2,longlong param_3)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid storage container");

    return uVar1;

  }

  if (param_2 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","oldpath");

    return uVar1;

  }

  if (param_3 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","newpath");

    return uVar1;

  }

  uVar1 = FUN_1401784e0(param_2);

  if ((char)uVar1 != '\0') {

    uVar1 = FUN_1401784e0(param_3);

    if ((char)uVar1 != '\0') {

      if (*(code **)(param_1 + 0x48) == (code *)0x0) {

        uVar1 = FUN_14012e850("That operation is not supported");

        return uVar1;

      }

                    /* WARNING: Could not recover jumptable at 0x0001401783cb. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar1 = (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x60),param_2,param_3);

      return uVar1;

    }

  }

  return uVar1 & 0xffffffffffffff00;

}





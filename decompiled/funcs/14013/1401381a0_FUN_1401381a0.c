// Address: 0x1401381a0
// Ghidra name: FUN_1401381a0
// ============ 0x1401381a0 FUN_1401381a0 (size=154) ============


void FUN_1401381a0(longlong param_1,longlong param_2,longlong param_3)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","buffer");

    return;

  }

  if (param_3 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140319a7c);

  }

                    /* WARNING: Could not recover jumptable at 0x000140138237. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x48))(*(undefined8 *)(param_1 + 0x298),param_2,param_3);

  return;

}





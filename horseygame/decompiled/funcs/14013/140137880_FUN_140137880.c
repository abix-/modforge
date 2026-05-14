// Address: 0x140137880
// Ghidra name: FUN_140137880
// ============ 0x140137880 FUN_140137880 (size=80) ============


undefined8 FUN_140137880(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","window");

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401378cd. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x228))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





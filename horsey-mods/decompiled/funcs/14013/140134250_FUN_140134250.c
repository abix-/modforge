// Address: 0x140134250
// Ghidra name: FUN_140134250
// ============ 0x140134250 FUN_140134250 (size=103) ============


ulonglong FUN_140134250(longlong param_1,longlong param_2)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid GPU device");

    return uVar1 & 0xffffffffffffff00;

  }

  if (param_2 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","window");

    return uVar1;

  }

  if ((*(uint *)(param_2 + 0x48) >> 0x1e & 1) != 0) {

    uVar1 = FUN_14012e850("The GPU API doesn\'t support transparent windows");

    return uVar1;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401342b4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





// Address: 0x140138bc0
// Ghidra name: FUN_140138bc0
// ============ 0x140138bc0 FUN_140138bc0 (size=77) ============


ulonglong FUN_140138bc0(longlong param_1,longlong param_2)



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

                    /* WARNING: Could not recover jumptable at 0x000140138c0a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x240))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





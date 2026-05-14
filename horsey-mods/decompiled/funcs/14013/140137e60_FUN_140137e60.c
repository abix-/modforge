// Address: 0x140137e60
// Ghidra name: FUN_140137e60
// ============ 0x140137e60 FUN_140137e60 (size=80) ============


ulonglong FUN_140137e60(longlong param_1,longlong param_2)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid GPU device");

    return uVar1 & 0xffffffffffffff00;

  }

  if (param_2 == 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","fence");

    return uVar1 & 0xffffffffffffff00;

  }

                    /* WARNING: Could not recover jumptable at 0x000140137ead. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x278))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





// Address: 0x140138b20
// Ghidra name: FUN_140138b20
// ============ 0x140138b20 FUN_140138b20 (size=85) ============


ulonglong FUN_140138b20(longlong param_1,undefined8 param_2,longlong param_3,int param_4)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid GPU device");

    return uVar1 & 0xffffffffffffff00;

  }

  if ((param_3 == 0) && (param_4 != 0)) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","fences");

    return uVar1 & 0xffffffffffffff00;

  }

                    /* WARNING: Could not recover jumptable at 0x000140138b72. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x270))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





// Address: 0x140138b80
// Ghidra name: FUN_140138b80
// ============ 0x140138b80 FUN_140138b80 (size=49) ============


ulonglong FUN_140138b80(longlong param_1)



{

  ulonglong uVar1;

  

  if (param_1 == 0) {

    uVar1 = FUN_14012e850("Invalid GPU device");

    return uVar1 & 0xffffffffffffff00;

  }

                    /* WARNING: Could not recover jumptable at 0x000140138bae. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x268))(*(undefined8 *)(param_1 + 0x298));

  return uVar1;

}





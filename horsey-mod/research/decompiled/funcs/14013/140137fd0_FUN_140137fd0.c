// Address: 0x140137fd0
// Ghidra name: FUN_140137fd0
// ============ 0x140137fd0 FUN_140137fd0 (size=37) ============


void FUN_140137fd0(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140137ff1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x298));

    return;

  }

  return;

}





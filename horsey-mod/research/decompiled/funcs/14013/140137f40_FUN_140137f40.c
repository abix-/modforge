// Address: 0x140137f40
// Ghidra name: FUN_140137f40
// ============ 0x140137f40 FUN_140137f40 (size=40) ============


void FUN_140137f40(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140137f64. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(param_1 + 0xa0))(*(undefined8 *)(param_1 + 0x298));

    return;

  }

  return;

}





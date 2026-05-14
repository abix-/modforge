// Address: 0x140137eb0
// Ghidra name: FUN_140137eb0
// ============ 0x140137eb0 FUN_140137eb0 (size=40) ============


void FUN_140137eb0(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140137ed4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x298));

    return;

  }

  return;

}





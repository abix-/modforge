// Address: 0x140137f70
// Ghidra name: FUN_140137f70
// ============ 0x140137f70 FUN_140137f70 (size=37) ============


void FUN_140137f70(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140137f91. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x298));

    return;

  }

  return;

}





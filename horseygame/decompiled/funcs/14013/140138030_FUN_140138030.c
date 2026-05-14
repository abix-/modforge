// Address: 0x140138030
// Ghidra name: FUN_140138030
// ============ 0x140138030 FUN_140138030 (size=58) ============


void FUN_140138030(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","window");

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x000140138067. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x210))(*(undefined8 *)(param_1 + 0x298));

  return;

}





// Address: 0x140138000
// Ghidra name: FUN_140138000
// ============ 0x140138000 FUN_140138000 (size=40) ============


void FUN_140138000(longlong param_1,longlong param_2)



{

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return;

  }

  if (param_2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x000140138024. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x298));

    return;

  }

  return;

}





// Address: 0x140133940
// Ghidra name: FUN_140133940
// ============ 0x140133940 FUN_140133940 (size=130) ============


void FUN_140133940(undefined8 *param_1,longlong param_2)



{

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","graphics_pipeline");

    return;

  }

  (**(code **)(*(longlong *)*param_1 + 0xb0))();

  if (*(char *)(*(longlong *)*param_1 + 0x2ac) != '\0') {

    param_1[0xc] = param_2;

  }

  return;

}





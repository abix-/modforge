// Address: 0x1401779f0
// Ghidra name: FUN_1401779f0
// ============ 0x1401779f0 FUN_1401779f0 (size=151) ============


void FUN_1401779f0(longlong param_1,longlong param_2)



{

  char cVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335b8c);

    return;

  }

  cVar1 = FUN_1401784e0(param_2);

  if (cVar1 == '\0') {

    return;

  }

  if (*(code **)(param_1 + 0x38) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x000140177a84. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x60),param_2);

  return;

}





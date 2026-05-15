// Address: 0x140178250
// Ghidra name: FUN_140178250
// ============ 0x140178250 FUN_140178250 (size=151) ============


void FUN_140178250(longlong param_1,longlong param_2)



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

  if (*(code **)(param_1 + 0x40) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0001401782e4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x60),param_2);

  return;

}





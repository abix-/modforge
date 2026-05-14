// Address: 0x140177c50
// Ghidra name: FUN_140177c50
// ============ 0x140177c50 FUN_140177c50 (size=67) ============


undefined8 FUN_140177c50(longlong param_1)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid storage container");

    return 0;

  }

  if (*(code **)(param_1 + 0x58) == (code *)0x0) {

    FUN_14012e850("That operation is not supported");

    return 0;

  }

                    /* WARNING: Could not recover jumptable at 0x000140177c90. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x60));

  return uVar1;

}





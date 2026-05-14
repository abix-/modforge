// Address: 0x14016bb50
// Ghidra name: FUN_14016bb50
// ============ 0x14016bb50 FUN_14016bb50 (size=79) ============


undefined8 FUN_14016bb50(undefined8 param_1)



{

  undefined8 uVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

  }

  else {

    if (*(longlong *)(DAT_1403fc410 + 0x690) == 0) {

      FUN_14012e850("There is no current EGL display");

      return 0;

    }

    if (*(code **)(DAT_1403fc410 + 0x1c8) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014016bb9c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar1 = (**(code **)(DAT_1403fc410 + 0x1c8))(DAT_1403fc410,param_1);

      return uVar1;

    }

  }

  return 0;

}





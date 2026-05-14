// Address: 0x14016f490
// Ghidra name: FUN_14016f490
// ============ 0x14016f490 FUN_14016f490 (size=88) ============


undefined8 FUN_14016f490(longlong param_1)



{

  undefined8 uVar1;

  

  if ((DAT_1403fc410 != 0) && (*(code **)(DAT_1403fc410 + 0x238) != (code *)0x0)) {

    if (param_1 == 0) {

      FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140335680);

      return 0;

    }

                    /* WARNING: Could not recover jumptable at 0x00014016f4d2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(DAT_1403fc410 + 0x238))();

    return uVar1;

  }

  FUN_14012e850("Metal is not supported.");

  return 0;

}





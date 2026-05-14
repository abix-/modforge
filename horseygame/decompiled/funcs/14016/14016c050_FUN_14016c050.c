// Address: 0x14016c050
// Ghidra name: FUN_14016c050
// ============ 0x14016c050 FUN_14016c050 (size=102) ============


void FUN_14016c050(longlong param_1)



{

  longlong lVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return;

  }

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

    return;

  }

  lVar1 = FUN_14016c6d0();

  if (lVar1 == param_1) {

    FUN_14016c930(0,0);

  }

                    /* WARNING: Could not recover jumptable at 0x00014016c0b3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(DAT_1403fc410 + 0x1e8))(DAT_1403fc410,param_1);

  return;

}





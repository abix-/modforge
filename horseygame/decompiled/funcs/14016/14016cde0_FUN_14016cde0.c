// Address: 0x14016cde0
// Ghidra name: FUN_14016cde0
// ============ 0x14016cde0 FUN_14016cde0 (size=101) ============


void FUN_14016cde0(undefined4 param_1)



{

  longlong lVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return;

  }

  lVar1 = FUN_14016c6d0();

  if (lVar1 == 0) {

    FUN_14012e850("No OpenGL context has been made current");

    return;

  }

  if (*(code **)(DAT_1403fc410 + 0x1d0) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014016ce31. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(DAT_1403fc410 + 0x1d0))(DAT_1403fc410,param_1);

    return;

  }

  FUN_14012e850("Setting the swap interval is not supported");

  return;

}





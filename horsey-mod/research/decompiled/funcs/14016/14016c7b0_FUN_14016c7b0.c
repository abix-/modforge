// Address: 0x14016c7b0
// Ghidra name: FUN_14016c7b0
// ============ 0x14016c7b0 FUN_14016c7b0 (size=145) ============


void FUN_14016c7b0(undefined4 *param_1)



{

  longlong lVar1;

  bool bVar2;

  

  if (param_1 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","interval");

    return;

  }

  bVar2 = DAT_1403fc410 == 0;

  *param_1 = 0;

  if (bVar2) {

    FUN_14012e850("no video driver");

    return;

  }

  lVar1 = FUN_14016c6d0();

  if (lVar1 == 0) {

    FUN_14012e850("no current context");

    return;

  }

  if (*(code **)(DAT_1403fc410 + 0x1d8) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014016c82d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(DAT_1403fc410 + 0x1d8))(DAT_1403fc410,param_1);

    return;

  }

  FUN_14012e850("not implemented");

  return;

}





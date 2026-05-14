// Address: 0x14016c730
// Ghidra name: FUN_14016c730
// ============ 0x14016c730 FUN_14016c730 (size=126) ============


undefined8 FUN_14016c730(undefined8 param_1)



{

  undefined8 uVar1;

  

  if (DAT_1403fc410 == (undefined8 *)0x0) {

    FUN_1401730c0();

    return 0;

  }

  if ((code *)DAT_1403fc410[0x35] != (code *)0x0) {

    if (*(int *)(DAT_1403fc410 + 0x82) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00014016c776. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar1 = (*(code *)DAT_1403fc410[0x35])(DAT_1403fc410,param_1);

      return uVar1;

    }

    FUN_14012e850("No GL driver has been loaded");

    return 0;

  }

  FUN_14012e850("No dynamic GL support in current SDL video driver (%s)",*DAT_1403fc410);

  return 0;

}





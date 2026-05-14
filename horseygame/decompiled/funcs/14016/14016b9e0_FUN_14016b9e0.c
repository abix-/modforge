// Address: 0x14016b9e0
// Ghidra name: FUN_14016b9e0
// ============ 0x14016b9e0 FUN_14016b9e0 (size=62) ============


undefined8 FUN_14016b9e0(void)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_14012e850("Video subsystem has not been initialized");

    return uVar2;

  }

  if (*(char *)(DAT_1403fc410 + 0x31a) != '\0') {

    return 1;

  }

  puVar1 = (undefined8 *)(DAT_1403fc410 + 600);

  *(undefined1 *)(DAT_1403fc410 + 0x31a) = 1;

  if ((code *)*puVar1 != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014016ba0f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (*(code *)*puVar1)();

    return uVar2;

  }

  uVar2 = FUN_14012e850("That operation is not supported");

  return uVar2;

}





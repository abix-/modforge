// Address: 0x14016baa0
// Ghidra name: FUN_14016baa0
// ============ 0x14016baa0 FUN_14016baa0 (size=68) ============


undefined8 FUN_14016baa0(void)



{

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (*(longlong *)(DAT_1403fc410 + 0x690) == 0) {

    FUN_14012e850("There is no current EGL display");

    return 0;

  }

  return *(undefined8 *)(*(longlong *)(DAT_1403fc410 + 0x690) + 0x10);

}





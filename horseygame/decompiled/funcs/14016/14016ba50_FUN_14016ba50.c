// Address: 0x14016ba50
// Ghidra name: FUN_14016ba50
// ============ 0x14016ba50 FUN_14016ba50 (size=68) ============


undefined8 FUN_14016ba50(void)



{

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (*(longlong *)(DAT_1403fc410 + 0x690) == 0) {

    FUN_14012e850("There is no current EGL display");

    return 0;

  }

  return *(undefined8 *)(*(longlong *)(DAT_1403fc410 + 0x690) + 0x18);

}





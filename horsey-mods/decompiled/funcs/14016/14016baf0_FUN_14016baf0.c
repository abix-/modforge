// Address: 0x14016baf0
// Ghidra name: FUN_14016baf0
// ============ 0x14016baf0 FUN_14016baf0 (size=86) ============


undefined8 FUN_14016baf0(undefined8 param_1)



{

  undefined8 uVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (*(longlong *)(DAT_1403fc410 + 0x690) != 0) {

    uVar1 = FUN_140219030();

    return uVar1;

  }

  FUN_14012e850("No EGL library has been loaded",param_1);

  return 0;

}





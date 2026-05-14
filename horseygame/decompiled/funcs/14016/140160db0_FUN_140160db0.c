// Address: 0x140160db0
// Ghidra name: FUN_140160db0
// ============ 0x140160db0 FUN_140160db0 (size=92) ============


longlong FUN_140160db0(undefined4 param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_1401611a0();

  if (*(code **)(lVar1 + 0x10) == (code *)0x0) {

    FUN_14012e850("CreateSystemCursor is not currently supported");

    return 0;

  }

  lVar2 = (**(code **)(lVar1 + 0x10))(param_1);

  if (lVar2 != 0) {

    *(undefined8 *)(lVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x110);

    *(longlong *)(lVar1 + 0x110) = lVar2;

  }

  return lVar2;

}





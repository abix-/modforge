// Address: 0x14020cc60
// Ghidra name: FUN_14020cc60
// ============ 0x14020cc60 FUN_14020cc60 (size=58) ============


undefined1 FUN_14020cc60(undefined4 param_1)



{

  undefined1 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14020d300();

  if (lVar2 == 0) {

    uVar1 = FUN_14012e850("Virtual joystick data not found");

    return uVar1;

  }

  FUN_14020d110(lVar2);

  FUN_14015a550(param_1);

  return 1;

}





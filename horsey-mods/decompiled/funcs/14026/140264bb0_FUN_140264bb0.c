// Address: 0x140264bb0
// Ghidra name: FUN_140264bb0
// ============ 0x140264bb0 FUN_140264bb0 (size=174) ============


undefined8

FUN_140264bb0(undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,

             undefined1 param_5)



{

  char cVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined1 local_18;

  undefined1 local_17;

  undefined1 local_16;

  undefined1 local_15;

  undefined1 local_14;

  

  lVar2 = FUN_140268130();

  local_18 = 0;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e850("Invalid joystick");

    return uVar3;

  }

  if ((*(byte *)(lVar2 + 0x14c) & 0x40) == 0) {

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  local_14 = param_5;

  local_17 = 0;

  local_16 = param_3;

  local_15 = param_4;

  cVar1 = FUN_140267ef0(lVar2,0xe,0,&local_18,5);

  if (cVar1 == '\0') {

    uVar3 = FUN_14012e850("Couldn\'t send LED packet");

    return uVar3;

  }

  return 1;

}





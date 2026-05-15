// Address: 0x1402827e0
// Ghidra name: FUN_1402827e0
// ============ 0x1402827e0 FUN_1402827e0 (size=141) ============


undefined8

FUN_1402827e0(longlong param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,

             undefined1 param_5)



{

  int iVar1;

  undefined8 uVar2;

  undefined2 local_38;

  undefined1 local_36;

  undefined1 local_35;

  undefined1 local_34;

  undefined8 local_33;

  undefined8 uStack_2b;

  undefined8 local_23;

  undefined8 uStack_1b;

  undefined8 local_13;

  undefined2 local_b;

  undefined1 local_9;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0xf) == '\0') {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  local_34 = param_5;

  local_13 = 0;

  local_b = 0;

  local_9 = 0;

  local_38 = 0x403;

  local_33 = 0;

  uStack_2b = 0;

  local_23 = 0;

  uStack_1b = 0;

  local_36 = param_3;

  local_35 = param_4;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_38,0x30);

  if (iVar1 < 0) {

    FUN_14012e850("SInput device joystick rgb command could not write");

    return 0;

  }

  return 1;

}





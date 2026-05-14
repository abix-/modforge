// Address: 0x140282360
// Ghidra name: FUN_140282360
// ============ 0x140282360 FUN_140282360 (size=108) ============


undefined4 FUN_140282360(longlong param_1,char param_2)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_28;

  undefined1 local_24;

  undefined1 local_23;

  undefined8 local_22;

  undefined8 local_1a;

  undefined8 local_12;

  undefined2 local_a;

  

  local_23 = param_2 != '\0';

  local_28 = 0x1ca55a03;

  local_24 = 0x17;

  local_22 = 0x4c4453;

  local_1a = 0;

  local_12 = 0;

  local_a = 0;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_28,0x20);

  if (iVar1 < 0) {

    uVar2 = FUN_14012e850("Couldn\'t send acquire command");

    return uVar2;

  }

  return 1;

}





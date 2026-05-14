// Address: 0x14027df70
// Ghidra name: FUN_14027df70
// ============ 0x14027df70 FUN_14027df70 (size=145) ============


undefined8 FUN_14027df70(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  undefined2 uVar2;

  int iVar3;

  undefined1 local_48;

  undefined8 local_47;

  undefined8 uStack_3f;

  undefined8 local_37;

  undefined8 uStack_2f;

  undefined8 local_27;

  undefined8 uStack_1f;

  undefined8 local_17;

  undefined4 local_f;

  undefined2 local_b;

  undefined1 local_9;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  uVar2 = 0;

  local_48 = 1;

  local_17 = 0;

  local_f = 0;

  local_b = 0;

  local_9 = 0;

  uStack_3f = 0;

  local_37 = 0;

  uStack_2f = 0;

  local_27 = 0;

  uStack_1f = 0;

  if (param_3 != '\0') {

    uVar2 = 0x18;

  }

  local_47 = (ulonglong)CONCAT23(uVar2,0x300387);

  iVar3 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),&local_48,0x40);

  if (iVar3 != 0x40) {

    return 0;

  }

  *(char *)(lVar1 + 1) = param_3;

  return 1;

}





// Address: 0x1402823d0
// Ghidra name: FUN_1402823d0
// ============ 0x1402823d0 FUN_1402823d0 (size=70) ============


undefined4 FUN_1402823d0(longlong param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_res8;

  undefined2 local_resc;

  

  local_res8 = 0x1a55a03;

  local_resc = 2;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,6);

  if (iVar1 < 0) {

    uVar2 = FUN_14012e850("Couldn\'t query controller info");

    return uVar2;

  }

  return 1;

}





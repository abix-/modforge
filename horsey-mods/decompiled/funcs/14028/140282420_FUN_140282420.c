// Address: 0x140282420
// Ghidra name: FUN_140282420
// ============ 0x140282420 FUN_140282420 (size=63) ============


undefined4 FUN_140282420(longlong param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined4 local_res8 [8];

  

  local_res8[0] = 0x10a55a03;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),local_res8,4);

  if (iVar1 < 0) {

    uVar2 = FUN_14012e850("Couldn\'t query controller status");

    return uVar2;

  }

  return 1;

}





// Address: 0x14026d790
// Ghidra name: FUN_14026d790
// ============ 0x14026d790 FUN_14026d790 (size=157) ============


undefined8 FUN_14026d790(longlong param_1,undefined8 param_2,ulonglong param_3,ushort param_4)



{

  int iVar1;

  undefined8 uVar2;

  int iVar3;

  undefined4 local_18;

  undefined1 local_14;

  undefined1 local_13;

  undefined2 local_12;

  undefined1 local_10;

  

  if (*(short *)(param_1 + 0x22) != 0x419) {

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  iVar1 = (int)((param_3 & 0xffff) * 0x903847eb >> 0x20);

  local_18 = 0xf03;

  local_12 = 0xff;

  iVar3 = (int)((ulonglong)param_4 * 0x903847eb >> 0x20);

  local_14 = (undefined1)(((uint)((int)(param_3 & 0xffff) - iVar1) >> 1) + iVar1 >> 9);

  local_10 = 0xeb;

  local_13 = (undefined1)(((uint)param_4 - iVar3 >> 1) + iVar3 >> 9);

  iVar1 = FUN_140284590(param_1,&local_18,9);

  if (iVar1 != 9) {

    uVar2 = FUN_14012e850("Couldn\'t send rumble packet");

    return uVar2;

  }

  return 1;

}





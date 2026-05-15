// Address: 0x14006db30
// Ghidra name: FUN_14006db30
// ============ 0x14006db30 FUN_14006db30 (size=182) ============


void FUN_14006db30(longlong param_1)



{

  byte local_res8 [8];

  undefined1 local_res10 [24];

  

  FUN_140075e30(local_res8);

  *(uint *)(param_1 + 0x38) = (local_res8[0] & 7) - 1;

  *(byte *)(param_1 + 0x10) = local_res8[0] >> 3 & 1;

  *(byte *)(param_1 + 0x11) = local_res8[0] >> 4 & 1;

  FUN_140075c60(param_1 + 0xc);

  FUN_140075c60(param_1 + 0x48);

  if (DAT_1403fb0e0 < 9) {

    FUN_140075cb0(param_1 + 0x3c);

    FUN_140075cb0(param_1 + 0x40);

  }

  FUN_140075cb0(param_1 + 0x44);

  FUN_140075b80(param_1 + 0x18);

  FUN_140075b80(param_1 + 0x24);

  FUN_140075f20(local_res10,param_1 + 0x1c);

  FUN_140075ed0(param_1 + 0x28);

  FUN_140075ed0(param_1 + 0x2c);

  FUN_140075ed0(param_1 + 0x30);

  FUN_140075ed0(param_1 + 0x34);

  return;

}





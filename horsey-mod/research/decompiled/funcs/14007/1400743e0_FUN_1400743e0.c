// Address: 0x1400743e0
// Ghidra name: FUN_1400743e0
// ============ 0x1400743e0 FUN_1400743e0 (size=109) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400743e0(undefined4 param_1,undefined4 param_2)



{

  undefined8 *puVar1;

  undefined8 local_58;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined8 local_40;

  undefined4 local_38;

  undefined1 local_30 [48];

  

  local_58 = 0x3f800000;

  local_4c = 0;

  local_48 = 0x3f800000;

  local_40 = 0;

  local_38 = 0x3f800000;

  local_50 = param_1;

  local_44 = param_2;

  puVar1 = (undefined8 *)FUN_140075120(&DAT_1403d94d8,local_30,&local_58);

  _DAT_1403d94d8 = *puVar1;

  _DAT_1403d94e0 = puVar1[1];

  _DAT_1403d94e8 = puVar1[2];

  uRam00000001403d94f0 = puVar1[3];

  DAT_1403d94f8 = *(undefined4 *)(puVar1 + 4);

  return;

}





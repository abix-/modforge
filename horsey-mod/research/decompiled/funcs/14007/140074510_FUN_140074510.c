// Address: 0x140074510
// Ghidra name: FUN_140074510
// ============ 0x140074510 FUN_140074510 (size=99) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140074510(undefined4 param_1,undefined4 param_2)



{

  undefined8 *puVar1;

  undefined4 local_58;

  undefined8 local_54;

  undefined4 local_4c;

  undefined4 local_48;

  undefined8 local_44;

  undefined8 uStack_3c;

  undefined1 local_30 [48];

  

  local_44 = _DAT_14030a330;

  uStack_3c = _UNK_14030a338;

  local_54 = 0;

  local_4c = 0;

  local_58 = param_1;

  local_48 = param_2;

  puVar1 = (undefined8 *)FUN_140075120(&DAT_1403d94d8,local_30,&local_58);

  _DAT_1403d94d8 = *puVar1;

  _DAT_1403d94e0 = puVar1[1];

  _DAT_1403d94e8 = puVar1[2];

  uRam00000001403d94f0 = puVar1[3];

  DAT_1403d94f8 = *(undefined4 *)(puVar1 + 4);

  return;

}





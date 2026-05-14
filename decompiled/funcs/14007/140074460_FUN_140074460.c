// Address: 0x140074460
// Ghidra name: FUN_140074460
// ============ 0x140074460 FUN_140074460 (size=163) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140074460(undefined4 param_1)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  undefined4 local_78;

  uint local_74;

  undefined4 local_70;

  uint local_6c;

  undefined4 local_68;

  undefined8 local_64;

  undefined8 uStack_5c;

  undefined1 local_50 [80];

  

  local_64 = _DAT_14030a330;

  uStack_5c = _UNK_14030a338;

  local_70 = 0;

  uVar2 = FUN_1402cfda0();

  local_6c = FUN_1402cdc50(param_1);

  local_74 = local_6c ^ DAT_14039cac0;

  local_78 = uVar2;

  local_68 = uVar2;

  puVar1 = (undefined8 *)FUN_140075120(&DAT_1403d94d8,local_50,&local_78);

  _DAT_1403d94d8 = *puVar1;

  _DAT_1403d94e0 = puVar1[1];

  _DAT_1403d94e8 = puVar1[2];

  uRam00000001403d94f0 = puVar1[3];

  DAT_1403d94f8 = *(undefined4 *)(puVar1 + 4);

  return;

}





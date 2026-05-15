// Address: 0x140070df0
// Ghidra name: FUN_140070df0
// ============ 0x140070df0 FUN_140070df0 (size=331) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140070df0(void)



{

  undefined8 uVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  undefined4 local_88;

  undefined8 local_84;

  undefined4 local_7c;

  undefined4 local_78;

  undefined8 local_74;

  undefined8 uStack_6c;

  undefined1 local_60 [96];

  

  uVar2 = DAT_1403eda08;

  uVar1 = _UNK_14030a2e8;

  puVar3 = DAT_1403eacf0;

  if (DAT_1403eacf0 == DAT_1403eacf8) {

    puVar3 = DAT_1403eacf8;

  }

  DAT_1403d94f8 = 0x3f800000;

  _DAT_1403d94d8 = _DAT_14030a2e0;

  _DAT_1403d94e0 = _UNK_14030a2e8;

  _DAT_1403d94e8 = _DAT_14030a2e0;

  uRam00000001403d94f0 = _UNK_14030a2e8;

  DAT_1403eacf8 = puVar3;

  if (puVar3 == DAT_1403ead00) {

    FUN_1400749b0(&DAT_1403eacf0,_DAT_14030a2e0,&DAT_1403d94d8);

  }

  else {

    *puVar3 = _DAT_14030a2e0;

    puVar3[1] = uVar1;

    uVar1 = uRam00000001403d94f0;

    puVar3[2] = _DAT_1403d94e8;

    puVar3[3] = uVar1;

    *(undefined4 *)(puVar3 + 4) = DAT_1403d94f8;

    DAT_1403eacf8 = (undefined8 *)((longlong)DAT_1403eacf8 + 0x24);

  }

  FUN_1400743e0();

  FUN_140074460();

  local_88 = uVar2;

  local_78 = uVar2;

  local_74 = _DAT_14030a330;

  uStack_6c = _UNK_14030a338;

  local_84 = 0;

  local_7c = 0;

  puVar3 = (undefined8 *)FUN_140075120(&DAT_1403d94d8,local_60,&local_88);

  _DAT_1403d94d8 = *puVar3;

  _DAT_1403d94e0 = puVar3[1];

  _DAT_1403d94e8 = puVar3[2];

  uRam00000001403d94f0 = puVar3[3];

  DAT_1403d94f8 = *(undefined4 *)(puVar3 + 4);

  return;

}





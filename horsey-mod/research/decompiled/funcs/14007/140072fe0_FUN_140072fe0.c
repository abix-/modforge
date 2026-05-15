// Address: 0x140072fe0
// Ghidra name: FUN_140072fe0
// ============ 0x140072fe0 FUN_140072fe0 (size=259) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140072fe0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined4 local_res20;

  undefined4 uStackX_24;

  undefined4 local_70;

  undefined8 local_6c;

  undefined4 local_64;

  undefined4 local_60;

  undefined8 local_5c;

  undefined8 uStack_54;

  undefined1 local_48 [72];

  

  puVar2 = DAT_1403eacf8;

  uVar1 = _DAT_1403d94e0;

  if (DAT_1403eacf8 == DAT_1403ead00) {

    FUN_1400749b0(&DAT_1403eacf0,DAT_1403eacf8,&DAT_1403d94d8);

  }

  else {

    *DAT_1403eacf8 = _DAT_1403d94d8;

    puVar2[1] = uVar1;

    uVar1 = uRam00000001403d94f0;

    puVar2[2] = _DAT_1403d94e8;

    puVar2[3] = uVar1;

    *(undefined4 *)(puVar2 + 4) = DAT_1403d94f8;

    DAT_1403eacf8 = (undefined8 *)((longlong)DAT_1403eacf8 + 0x24);

  }

  FUN_1400743e0();

  FUN_140074460();

  uStackX_24 = (undefined4)((ulonglong)param_3 >> 0x20);

  local_5c = _DAT_14030a330;

  uStack_54 = _UNK_14030a338;

  local_6c = 0;

  local_res20 = (undefined4)param_3;

  local_70 = local_res20;

  local_60 = uStackX_24;

  local_64 = 0;

  puVar2 = (undefined8 *)FUN_140075120(&DAT_1403d94d8,local_48,&local_70,param_4,param_1);

  _DAT_1403d94d8 = *puVar2;

  _DAT_1403d94e0 = puVar2[1];

  _DAT_1403d94e8 = puVar2[2];

  uRam00000001403d94f0 = puVar2[3];

  DAT_1403d94f8 = *(undefined4 *)(puVar2 + 4);

  return;

}





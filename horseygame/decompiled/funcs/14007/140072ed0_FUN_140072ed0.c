// Address: 0x140072ed0
// Ghidra name: FUN_140072ed0
// ============ 0x140072ed0 FUN_140072ed0 (size=120) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140072ed0(undefined4 param_1,undefined4 param_2)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  

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

  FUN_1400743e0(param_1,param_2);

  return;

}





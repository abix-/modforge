// Address: 0x140074630
// Ghidra name: FUN_140074630
// ============ 0x140074630 FUN_140074630 (size=116) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140074630(void)



{

  undefined8 *puVar1;

  

  puVar1 = DAT_1403eacf8;

  if (DAT_1403eacf8 == DAT_1403ead00) {

    FUN_1400749b0(&DAT_1403eacf0,DAT_1403eacf8,&DAT_1403d94d8);

  }

  else {

    *DAT_1403eacf8 = _DAT_1403d94d8;

    puVar1[1] = _DAT_1403d94e0;

    puVar1[2] = _DAT_1403d94e8;

    puVar1[3] = uRam00000001403d94f0;

    *(undefined4 *)(puVar1 + 4) = DAT_1403d94f8;

    DAT_1403eacf8 = (undefined8 *)((longlong)DAT_1403eacf8 + 0x24);

  }

  _DAT_1403d94d8 = _DAT_14030a2e0;

  _DAT_1403d94e0 = _UNK_14030a2e8;

  DAT_1403d94f8 = 0x3f800000;

  _DAT_1403d94e8 = _DAT_14030a2e0;

  uRam00000001403d94f0 = _UNK_14030a2e8;

  return;

}





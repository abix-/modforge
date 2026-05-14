// Address: 0x140141200
// Ghidra name: FUN_140141200
// ============ 0x140141200 FUN_140141200 (size=161) ============


void FUN_140141200(void)



{

  undefined8 *puVar1;

  

  FUN_140159d30();

  for (puVar1 = DAT_1403fbef8; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[10]) {

    FUN_1401400c0(*(undefined4 *)*puVar1);

  }

  DAT_1403fbef0 = 0;

  FUN_14013b2e0(FUN_14013d790,0);

  puVar1 = DAT_1403fbef8;

  while (DAT_1403fbef8 = puVar1, puVar1 != (undefined8 *)0x0) {

    *(undefined4 *)(puVar1 + 1) = 1;

    FUN_14013cac0(puVar1);

    puVar1 = DAT_1403fbef8;

  }

  if (DAT_1403fbf00 != 0) {

    FUN_1401aafa0();

    DAT_1403fbf00 = 0;

  }

  FUN_14015bb10();

  return;

}





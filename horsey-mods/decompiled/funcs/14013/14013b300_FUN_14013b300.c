// Address: 0x14013b300
// Ghidra name: FUN_14013b300
// ============ 0x14013b300 FUN_14013b300 (size=136) ============


void FUN_14013b300(void)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  FUN_140179b40(DAT_1403fbed8);

  puVar2 = DAT_1403fbee0;

  DAT_1403fbee0 = (undefined8 *)0x0;

  DAT_1403fbee8 = 0;

  FUN_140179b60(DAT_1403fbed8);

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[4];

    (*(code *)*puVar2)(puVar2[1]);

    if (puVar2[3] == 0) {

      FUN_1401393f0(puVar2);

      puVar2 = puVar1;

    }

    else {

      FUN_140139010(puVar2 + 2,1);

      FUN_14017cea0(puVar2[3]);

      puVar2 = puVar1;

    }

  }

  return;

}





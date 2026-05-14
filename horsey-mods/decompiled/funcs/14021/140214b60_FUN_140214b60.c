// Address: 0x140214b60
// Ghidra name: FUN_140214b60
// ============ 0x140214b60 FUN_140214b60 (size=183) ============


void FUN_140214b60(void)



{

  undefined1 uVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  

  do {

    FUN_140179b40(DAT_1403fdad8);

    while( true ) {

      puVar3 = (undefined8 *)FUN_140138ff0(&DAT_1403fdad0);

      if (puVar3 != (undefined8 *)0x0) break;

      iVar2 = FUN_140138fe0(&DAT_1403fdae8);

      if (iVar2 != 0) {

        FUN_140179b60(DAT_1403fdad8);

        return;

      }

      FUN_140163d40(DAT_1403fdae0,DAT_1403fdad8);

    }

    FUN_140139020(&DAT_1403fdad0,puVar3[5]);

    FUN_140179b60(DAT_1403fdad8);

    uVar1 = (*(code *)*puVar3)(puVar3[1]);

    *(undefined1 *)(puVar3 + 2) = uVar1;

    if (puVar3[3] == 0) {

      FUN_1401841e0(puVar3);

    }

    else {

      uVar4 = FUN_14012e730();

      uVar4 = FUN_14012f0d0(uVar4);

      puVar3[4] = uVar4;

      FUN_14017cea0(puVar3[3]);

    }

  } while( true );

}





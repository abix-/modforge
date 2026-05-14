// Address: 0x14013f6a0
// Ghidra name: FUN_14013f6a0
// ============ 0x14013f6a0 FUN_14013f6a0 (size=171) ============


void FUN_14013f6a0(void)



{

  char *pcVar1;

  undefined1 *puVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  

  pcVar1 = (char *)FUN_140142960("SDL_GAMECONTROLLERCONFIG");

  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {

    puVar2 = (undefined1 *)FUN_14012f0d0(pcVar1);

    FUN_14013c7b0();

    if (puVar2 != (undefined1 *)0x0) {

      puVar4 = puVar2;

      do {

        puVar3 = (undefined1 *)thunk_FUN_1402c9190(puVar4,10);

        if (puVar3 != (undefined1 *)0x0) {

          *puVar3 = 0;

        }

        FUN_14013f8f0(puVar4,2);

        puVar4 = puVar3 + 1;

        if (puVar3 == (undefined1 *)0x0) {

          puVar4 = (undefined1 *)0x0;

        }

      } while (puVar4 != (undefined1 *)0x0);

    }

    FUN_14013c640();

    FUN_1401841e0(puVar2);

  }

  return;

}





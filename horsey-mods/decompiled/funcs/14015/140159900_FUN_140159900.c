// Address: 0x140159900
// Ghidra name: FUN_140159900
// ============ 0x140159900 FUN_140159900 (size=52) ============


void FUN_140159900(void)



{

  char cVar1;

  uint uVar2;

  undefined4 *puVar3;

  

  uVar2 = 0;

  puVar3 = &DAT_140333478;

  do {

    cVar1 = FUN_140139420(*puVar3);

    if (cVar1 != '\0') {

      return;

    }

    uVar2 = uVar2 + 1;

    puVar3 = puVar3 + 1;

  } while (uVar2 < 8);

  return;

}





// Address: 0x14013d930
// Ghidra name: FUN_14013d930
// ============ 0x14013d930 FUN_14013d930 (size=52) ============


void FUN_14013d930(void)



{

  char cVar1;

  uint uVar2;

  undefined4 *puVar3;

  

  uVar2 = 0;

  puVar3 = &DAT_1403300d0;

  do {

    cVar1 = FUN_140139420(*puVar3);

    if (cVar1 != '\0') {

      return;

    }

    uVar2 = uVar2 + 1;

    puVar3 = puVar3 + 1;

  } while (uVar2 < 10);

  return;

}





// Address: 0x140178ea0
// Ghidra name: FUN_140178ea0
// ============ 0x140178ea0 FUN_140178ea0 (size=93) ============


void FUN_140178ea0(void)



{

  longlong *plVar1;

  uint uVar2;

  

  uVar2 = 0;

  if (DAT_1403fc490 != 0) {

    FUN_1401841e0();

    DAT_1403fc490 = 0;

  }

  plVar1 = &DAT_1403fc4a0;

  do {

    if (*plVar1 != 0) {

      FUN_1401841e0();

      *plVar1 = 0;

    }

    uVar2 = uVar2 + 1;

    plVar1 = plVar1 + 1;

  } while (uVar2 < 0xb);

  return;

}





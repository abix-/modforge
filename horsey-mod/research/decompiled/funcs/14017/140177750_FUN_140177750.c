// Address: 0x140177750
// Ghidra name: FUN_140177750
// ============ 0x140177750 FUN_140177750 (size=131) ============


void FUN_140177750(void)



{

  undefined8 uVar1;

  int iVar2;

  

  DAT_1403fc474 = DAT_1403fc474 + -1;

  if ((DAT_1403fc478 == '\0') && (DAT_1403fc474 == 0)) {

    iVar2 = FUN_140138fe0(&DAT_1403fc470);

    uVar1 = DAT_1403fc468;

    if (iVar2 == 0) {

      FUN_140179b40(DAT_1403fc468);

      FUN_140179b60(DAT_1403fc468);

      DAT_1403fc468 = 0;

      FUN_140179b60(uVar1);

      FUN_140179b30(uVar1);

      return;

    }

  }

  FUN_140179b60(DAT_1403fc468);

  return;

}





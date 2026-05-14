// Address: 0x1402145b0
// Ghidra name: FUN_1402145b0
// ============ 0x1402145b0 FUN_1402145b0 (size=224) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402145b0(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined *puVar6;

  

  FUN_1402130e0();

  cVar1 = FUN_14017fed0();

  if (cVar1 != '\0') {

    lVar4 = 0;

    _DAT_1403fda50 = FUN_140213710;

    puVar6 = &DAT_1403fd450;

    _DAT_1403fda58 = FUN_140213710;

    lVar5 = 8;

    _DAT_1403fda60 = FUN_140213710;

    _DAT_1403fda68 = FUN_140213710;

    _DAT_1403fda70 = FUN_140213710;

    _DAT_1403fda78 = FUN_140213710;

    _DAT_1403fda80 = FUN_140213710;

    _DAT_1403fda88 = FUN_140213710;

    do {

      iVar3 = 0;

      do {

        iVar2 = FUN_140214750(puVar6 + (iVar3 + lVar4) * 0x10);

        iVar3 = iVar2 + 4;

      } while (iVar2 + 8 < 0xd);

      lVar4 = lVar4 + 0xc;

      lVar5 = lVar5 + -1;

    } while (lVar5 != 0);

    return;

  }

  _DAT_1403fda60 = FUN_140213290;

  _DAT_1403fda68 = FUN_140213290;

  _DAT_1403fda70 = FUN_140213290;

  _DAT_1403fda78 = FUN_140213290;

  _DAT_1403fda80 = FUN_140213290;

  _DAT_1403fda88 = FUN_140213290;

  _DAT_1403fda50 = FUN_140213c90;

  _DAT_1403fda58 = FUN_140213f40;

  return;

}





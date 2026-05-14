// Address: 0x1402306a0
// Ghidra name: FUN_1402306a0
// ============ 0x1402306a0 FUN_1402306a0 (size=174) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402306a0(void)



{

  char cVar1;

  char *pcVar2;

  bool bVar3;

  

  cVar1 = FUN_140163c40(&DAT_1403fdd10);

  if (cVar1 != '\0') {

    cVar1 = FUN_140230460();

    pcVar2 = "ioring";

    if (cVar1 == '\0') {

      pcVar2 = "generic";

    }

    FUN_1401aa7a0("asyncio",pcVar2);

    bVar3 = cVar1 == '\0';

    _DAT_1403fdd28 = FUN_140230990;

    if (bVar3) {

      _DAT_1403fdd28 = FUN_1402c50c0;

    }

    DAT_1403fdd30 = &LAB_140230ba0;

    if (bVar3) {

      DAT_1403fdd30 = &LAB_1402c5160;

    }

    _DAT_1403fdd38 = FUN_140230870;

    if (bVar3) {

      _DAT_1403fdd38 = FUN_1402c5010;

    }

    FUN_140163ab0(&DAT_1403fdd10,0x1402c5001);

    return;

  }

  return;

}





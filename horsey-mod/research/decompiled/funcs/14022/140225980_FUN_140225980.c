// Address: 0x140225980
// Ghidra name: FUN_140225980
// ============ 0x140225980 FUN_140225980 (size=145) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140225980(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 *puVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  FUN_140224b10(lVar1);

  if (*(longlong *)(lVar1 + 0x168) != 0) {

    FUN_1401841e0();

    *(undefined8 *)(lVar1 + 0x168) = 0;

  }

  iVar2 = 0;

  if (0 < DAT_1403fdc40) {

    puVar3 = &DAT_1403fdc08;

    do {

      FUN_1401819c0(*puVar3);

      iVar2 = iVar2 + 1;

      puVar3 = puVar3 + 2;

    } while (iVar2 < DAT_1403fdc40);

  }

  DAT_1403fdc40 = 0;

  DAT_1403fdc00 = 0;

  DAT_1403fdc08 = 0;

  DAT_1403fdc10 = 0;

  DAT_1403fdc18 = 0;

  _DAT_1403fdc20 = 0;

  uRam00000001403fdc28 = 0;

  _DAT_1403fdc30 = 0;

  DAT_1403fdc38 = 0;

  return;

}





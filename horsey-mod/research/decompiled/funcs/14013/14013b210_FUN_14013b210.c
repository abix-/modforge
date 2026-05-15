// Address: 0x14013b210
// Ghidra name: FUN_14013b210
// ============ 0x14013b210 FUN_14013b210 (size=155) ============


void FUN_14013b210(void)



{

  longlong lVar1;

  longlong lVar2;

  

  FUN_140179b40(DAT_1403fbed8);

  lVar2 = DAT_1403fbee0;

  DAT_1403fbee0 = 0;

  DAT_1403fbee8 = 0;

  FUN_140179b60(DAT_1403fbed8);

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0x20);

    if (*(longlong *)(lVar2 + 0x18) == 0) {

      FUN_1401393f0(lVar2);

      lVar2 = lVar1;

    }

    else {

      FUN_140139010(lVar2 + 0x10,2);

      FUN_14017cea0(*(undefined8 *)(lVar2 + 0x18));

      lVar2 = lVar1;

    }

  }

  FUN_140179b30(DAT_1403fbed8);

  DAT_1403fbed8 = 0;

  return;

}





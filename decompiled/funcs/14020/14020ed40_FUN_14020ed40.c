// Address: 0x14020ed40
// Ghidra name: FUN_14020ed40
// ============ 0x14020ed40 FUN_14020ed40 (size=149) ============


void FUN_14020ed40(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = DAT_1403ffc48;

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0x578);

    FUN_1401841e0(*(undefined8 *)(lVar2 + 0x10));

    FUN_1401841e0(lVar2);

    lVar2 = lVar1;

  }

  DAT_1403ffc48 = 0;

  if (DAT_1403fd310 != '\0') {

    FUN_14020f500();

    FUN_140286bd0();

    FUN_140285650();

    FUN_140220870();

    return;

  }

  FUN_14020f120(&DAT_1403fd330);

  FUN_140286bd0();

  FUN_140285650();

  FUN_140220870();

  return;

}





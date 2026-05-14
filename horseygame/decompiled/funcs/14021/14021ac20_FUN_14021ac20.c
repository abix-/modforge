// Address: 0x14021ac20
// Ghidra name: FUN_14021ac20
// ============ 0x14021ac20 FUN_14021ac20 (size=68) ============


undefined1 FUN_14021ac20(void)



{

  longlong lVar1;

  char cVar2;

  

  cVar2 = FUN_1402879d0();

  lVar1 = DAT_1403ffc48;

  if (cVar2 == '\0') {

    return 0;

  }

  for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x578)) {

    FUN_140287b80(lVar1 + 0x24);

  }

  return 1;

}





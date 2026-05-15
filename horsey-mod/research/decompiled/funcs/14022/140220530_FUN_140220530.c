// Address: 0x140220530
// Ghidra name: FUN_140220530
// ============ 0x140220530 FUN_140220530 (size=75) ============


undefined8 FUN_140220530(void)



{

  char cVar1;

  int iVar2;

  

  cVar1 = FUN_140220700();

  do {

    FUN_14018bef0(cVar1);

    WaitForSingleObject(DAT_1403e54a0,0xffffffff);

    iVar2 = FUN_140138fe0(&DAT_1403fdbe0);

  } while (iVar2 != 0);

  if (cVar1 != '\0') {

    FUN_140220910();

  }

  return 0;

}





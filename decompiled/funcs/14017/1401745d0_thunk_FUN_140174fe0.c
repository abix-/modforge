// Address: 0x1401745d0
// Ghidra name: thunk_FUN_140174fe0
// ============ 0x1401745d0 thunk_FUN_140174fe0 (size=5) ============


bool thunk_FUN_140174fe0(void)



{

  char cVar1;

  bool bVar2;

  

  cVar1 = FUN_140163c40(&DAT_1403fc438);

  if (cVar1 == '\0') {

    return true;

  }

  DAT_1403fc450 = FUN_1401aaee0(0,1,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

  bVar2 = DAT_1403fc450 != 0;

  FUN_140163ab0(&DAT_1403fc438,bVar2);

  return bVar2;

}





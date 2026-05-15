// Address: 0x140198730
// Ghidra name: thunk_FUN_140230b50
// ============ 0x140198730 thunk_FUN_140230b50 (size=5) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void thunk_FUN_140230b50(void)



{

  char cVar1;

  

  cVar1 = FUN_140163cb0(&DAT_1403fdd10);

  if (cVar1 != '\0') {

    (*DAT_1403fdd30)();

    _DAT_1403fdd28 = 0;

    DAT_1403fdd30 = (code *)0x0;

    _DAT_1403fdd38 = 0;

    FUN_140163ab0(&DAT_1403fdd10,0);

    return;

  }

  return;

}





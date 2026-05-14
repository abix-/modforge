// Address: 0x1401904d0
// Ghidra name: thunk_FUN_1402e1c90
// ============ 0x1401904d0 thunk_FUN_1402e1c90 (size=5) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int thunk_FUN_1402e1c90(undefined4 param_1)



{

  short sVar1;

  double dVar2;

  

  sVar1 = FUN_1402f18e0();

  if (sVar1 != 0) {

    if ((sVar1 != 1) && (sVar1 != 2)) {

      dVar2 = (double)FUN_1402e1d50(param_1);

      if ((_DAT_14038abb8 <= dVar2) && (dVar2 <= DAT_14038abb0)) {

        return (int)dVar2;

      }

    }

    FUN_1402eb620(1);

  }

  return 0;

}





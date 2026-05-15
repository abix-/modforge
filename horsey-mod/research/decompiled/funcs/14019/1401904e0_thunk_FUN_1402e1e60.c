// Address: 0x1401904e0
// Ghidra name: thunk_FUN_1402e1e60
// ============ 0x1401904e0 thunk_FUN_1402e1e60 (size=5) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int thunk_FUN_1402e1e60(undefined4 param_1)



{

  short sVar1;

  float fVar2;

  

  sVar1 = FUN_1402f19c0();

  if (sVar1 != 0) {

    if ((sVar1 != 1) && (sVar1 != 2)) {

      fVar2 = (float)FUN_1402e1d00(param_1);

      if ((_DAT_14038abc4 <= fVar2) && (fVar2 <= DAT_14038abc0)) {

        return (int)fVar2;

      }

    }

    FUN_1402eb620(1);

  }

  return 0;

}





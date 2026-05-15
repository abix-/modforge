// Address: 0x14015dd70
// Ghidra name: FUN_14015dd70
// ============ 0x14015dd70 FUN_14015dd70 (size=92) ============


longlong FUN_14015dd70(longlong param_1,int param_2)



{

  longlong lVar1;

  

  if ((0 < param_2) && (param_1 != 0)) {

    lVar1 = FUN_1401841f0((longlong)param_2 << 2);

    if (lVar1 != 0) {

      FUN_1402f8e20(lVar1,param_1,(longlong)param_2 << 2);

    }

    return lVar1;

  }

  return 0;

}





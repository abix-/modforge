// Address: 0x140045a50
// Ghidra name: FUN_140045a50
// ============ 0x140045a50 FUN_140045a50 (size=51) ============


double FUN_140045a50(void)



{

  longlong lVar1;

  

  lVar1 = FUN_14004f010();

  if (lVar1 == 0) {

    return 0.0;

  }

  return *(double *)(lVar1 + 0x20) / (double)**(int **)(lVar1 + 0x28);

}





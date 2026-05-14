// Address: 0x140045b80
// Ghidra name: FUN_140045b80
// ============ 0x140045b80 FUN_140045b80 (size=83) ============


undefined8 FUN_140045b80(void)



{

  longlong lVar1;

  double extraout_XMM0_Qa;

  double dVar2;

  

  lVar1 = FUN_14004f010();

  if (lVar1 == 0) {

    return 2;

  }

  dVar2 = (double)**(int **)(lVar1 + 0x28) * extraout_XMM0_Qa;

  if ((double)(*(int **)(lVar1 + 0x28))[1] < dVar2) {

    return 0xd;

  }

  *(double *)(lVar1 + 0x20) = dVar2;

  return 0;

}





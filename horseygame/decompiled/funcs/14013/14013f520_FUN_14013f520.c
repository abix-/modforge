// Address: 0x14013f520
// Ghidra name: FUN_14013f520
// ============ 0x14013f520 FUN_14013f520 (size=178) ============


undefined8 FUN_14013f520(void)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  longlong lVar5;

  

  DAT_1403fbef0 = 1;

  FUN_140159d30();

  lVar5 = 0;

  DAT_1403fbf00 = FUN_1401aaee0(0,0,&LAB_1401aa980,&LAB_1401aa9c0,&LAB_1401aafe0,0);

  FUN_1401391a0(FUN_14013d790,0);

  piVar4 = (int *)FUN_140158f60(0);

  if (piVar4 != (int *)0x0) {

    iVar2 = *piVar4;

    piVar1 = piVar4;

    while (iVar2 != 0) {

      cVar3 = FUN_14013f5e0(iVar2);

      if (cVar3 != '\0') {

        FUN_140140020(*piVar1);

      }

      lVar5 = lVar5 + 4;

      piVar1 = (int *)(lVar5 + (longlong)piVar4);

      iVar2 = *(int *)(lVar5 + (longlong)piVar4);

    }

    FUN_1401841e0(piVar4);

  }

  FUN_14015bb10();

  return 1;

}





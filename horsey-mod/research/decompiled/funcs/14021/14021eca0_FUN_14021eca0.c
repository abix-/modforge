// Address: 0x14021eca0
// Ghidra name: FUN_14021eca0
// ============ 0x14021eca0 FUN_14021eca0 (size=111) ============


longlong * FUN_14021eca0(void)



{

  longlong *plVar1;

  longlong lVar2;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x20);

  if (plVar1 != (longlong *)0x0) {

    lVar2 = FUN_140179a30();

    *plVar1 = lVar2;

    if (lVar2 != 0) {

      lVar2 = FUN_140160230();

      plVar1[1] = lVar2;

      if (lVar2 != 0) {

        FUN_140139010(plVar1 + 3,0);

        FUN_140139010((longlong)plVar1 + 0x1c,0);

        return plVar1;

      }

      FUN_140179b30(*plVar1);

    }

    FUN_1401841e0(plVar1);

  }

  return (longlong *)0x0;

}





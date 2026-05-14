// Address: 0x140217350
// Ghidra name: FUN_140217350
// ============ 0x140217350 FUN_140217350 (size=107) ============


longlong * FUN_140217350(void)



{

  longlong *plVar1;

  longlong lVar2;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x20);

  if (plVar1 != (longlong *)0x0) {

    lVar2 = FUN_14017cda0(0);

    *plVar1 = lVar2;

    lVar2 = FUN_14017cda0(0);

    plVar1[1] = lVar2;

    lVar2 = FUN_14017cda0(1);

    plVar1[2] = lVar2;

    if (((*plVar1 != 0) && (plVar1[1] != 0)) && (lVar2 != 0)) {

      return plVar1;

    }

    FUN_1402173c0(plVar1);

  }

  return (longlong *)0x0;

}





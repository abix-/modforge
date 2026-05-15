// Address: 0x140181910
// Ghidra name: FUN_140181910
// ============ 0x140181910 FUN_140181910 (size=166) ============


longlong * FUN_140181910(undefined1 param_1)



{

  longlong *plVar1;

  longlong lVar2;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x20);

  if (plVar1 != (longlong *)0x0) {

    *(undefined1 *)((longlong)plVar1 + 0x14) = param_1;

    lVar2 = FUN_1401aaee0(0x100,0,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

    *plVar1 = lVar2;

    lVar2 = FUN_1401aaee0(0x100,0,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

    plVar1[1] = lVar2;

    if ((*plVar1 != 0) && (lVar2 != 0)) {

      return plVar1;

    }

    FUN_1401819c0(plVar1);

  }

  return (longlong *)0x0;

}





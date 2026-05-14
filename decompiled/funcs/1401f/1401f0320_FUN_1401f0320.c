// Address: 0x1401f0320
// Ghidra name: FUN_1401f0320
// ============ 0x1401f0320 FUN_1401f0320 (size=110) ============


undefined1 FUN_1401f0320(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  char cVar4;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  lVar2 = *plVar1;

  lVar3 = FUN_14016c6d0();

  if (lVar3 != lVar2) {

    plVar1[0x58] = 0;

    cVar4 = FUN_14016c930(*(undefined8 *)(param_1 + 0x118),lVar2);

    if (cVar4 == '\0') {

      return 0;

    }

  }

  FUN_1401f4710(param_1);

  return 1;

}





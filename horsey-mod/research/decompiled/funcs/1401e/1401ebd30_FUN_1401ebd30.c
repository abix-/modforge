// Address: 0x1401ebd30
// Ghidra name: FUN_1401ebd30
// ============ 0x1401ebd30 FUN_1401ebd30 (size=84) ============


undefined1 FUN_1401ebd30(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  longlong lVar3;

  

  lVar1 = **(longlong **)(param_1 + 0x2e0);

  lVar3 = FUN_14016c6d0();

  if (lVar3 != lVar1) {

    cVar2 = FUN_14016c930(*(undefined8 *)(param_1 + 0x118),lVar1);

    if (cVar2 == '\0') {

      return 0;

    }

  }

  FUN_1401ebed0(param_1);

  return 1;

}





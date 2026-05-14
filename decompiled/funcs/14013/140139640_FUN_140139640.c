// Address: 0x140139640
// Ghidra name: FUN_140139640
// ============ 0x140139640 FUN_140139640 (size=65) ============


void FUN_140139640(void)



{

  longlong lVar1;

  longlong *plVar2;

  

  plVar2 = (longlong *)FUN_14013aaf0(0);

  if (plVar2 != (longlong *)0x0) {

    lVar1 = *plVar2;

    while (lVar1 != 0) {

      FUN_14013bb10(plVar2);

      FUN_140139690(plVar2);

      lVar1 = *plVar2;

    }

  }

  return;

}





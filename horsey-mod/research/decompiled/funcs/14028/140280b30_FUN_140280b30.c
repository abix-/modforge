// Address: 0x140280b30
// Ghidra name: FUN_140280b30
// ============ 0x140280b30 FUN_140280b30 (size=76) ============


void FUN_140280b30(longlong param_1)



{

  longlong *plVar1;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x80);

  if (plVar1 == (longlong *)0x0) {

    return;

  }

  *plVar1 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar1;

  if (*(short *)(param_1 + 0x20) == 0x4b4) {

    FUN_140281cc0();

    return;

  }

  FUN_140281e30(param_1);

  return;

}





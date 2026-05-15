// Address: 0x140025d60
// Ghidra name: FUN_140025d60
// ============ 0x140025d60 FUN_140025d60 (size=94) ============


longlong FUN_140025d60(longlong param_1)



{

  undefined8 uVar1;

  longlong lVar2;

  longlong *plVar3;

  

  uVar1 = FUN_1402c704c(0xd8);

  plVar3 = (longlong *)(param_1 + 0x38);

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    plVar3 = (longlong *)*plVar3;

  }

  lVar2 = FUN_140025490(uVar1,plVar3);

  if (lVar2 == 0) {

    return 0;

  }

  FUN_140025bc0(param_1,lVar2);

  return lVar2;

}





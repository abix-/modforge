// Address: 0x1401b85d0
// Ghidra name: FUN_1401b85d0
// ============ 0x1401b85d0 FUN_1401b85d0 (size=98) ============


longlong * FUN_1401b85d0(undefined8 param_1,undefined4 param_2)



{

  longlong *plVar1;

  longlong lVar2;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x10);

  lVar2 = FUN_1401b5a30(param_1,param_2,0,1,0,0);

  *plVar1 = lVar2;

  plVar1[1] = 0;

  *(longlong **)(lVar2 + 0x38) = plVar1;

  return plVar1;

}





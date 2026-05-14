// Address: 0x140140a30
// Ghidra name: FUN_140140a30
// ============ 0x140140a30 FUN_140140a30 (size=148) ============


longlong FUN_140140a30(undefined8 param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar1 = thunk_FUN_1402c9190(param_1,0x2c);

  if ((lVar1 != 0) && (lVar2 = thunk_FUN_1402c9190(lVar1 + 1,0x2c), lVar2 != 0)) {

    lVar3 = FUN_1401841f0(lVar2 - lVar1);

    if (lVar3 != 0) {

      FUN_1402f8e20(lVar3,lVar1 + 1,lVar2 - lVar1);

      *(undefined1 *)((lVar3 - lVar1) + -1 + lVar2) = 0;

      return lVar3;

    }

  }

  return 0;

}





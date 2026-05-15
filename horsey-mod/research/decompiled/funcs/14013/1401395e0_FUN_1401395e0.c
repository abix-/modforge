// Address: 0x1401395e0
// Ghidra name: FUN_1401395e0
// ============ 0x1401395e0 FUN_1401395e0 (size=85) ============


longlong FUN_1401395e0(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  

  if (param_1 == 0) {

    return 0;

  }

  lVar1 = FUN_14013aaf0(1);

  if (lVar1 != 0) {

    plVar2 = (longlong *)FUN_1401841f0(0x18);

    if (plVar2 != (longlong *)0x0) {

      *plVar2 = param_1;

      FUN_14013acc0(lVar1,plVar2);

    }

  }

  return param_1;

}





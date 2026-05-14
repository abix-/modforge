// Address: 0x140228070
// Ghidra name: FUN_140228070
// ============ 0x140228070 FUN_140228070 (size=103) ============


longlong FUN_140228070(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  

  if (param_1 != 0) {

    lVar1 = FUN_1401841a0(1,0x18);

    if (lVar1 != 0) {

      plVar2 = (longlong *)FUN_1401841a0(1,0x30);

      if (plVar2 != (longlong *)0x0) {

        *plVar2 = param_1;

        *(longlong **)(lVar1 + 8) = plVar2;

        return lVar1;

      }

      FUN_1401841e0(lVar1);

    }

  }

  return 0;

}





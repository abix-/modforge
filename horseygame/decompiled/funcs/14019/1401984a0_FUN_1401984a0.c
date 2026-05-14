// Address: 0x1401984a0
// Ghidra name: FUN_1401984a0
// ============ 0x1401984a0 FUN_1401984a0 (size=77) ============


longlong FUN_1401984a0(void)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401841a0(1,0x40);

  if (lVar2 != 0) {

    FUN_140139010(lVar2 + 0x38,0);

    cVar1 = FUN_140230970(lVar2);

    if (cVar1 == '\0') {

      FUN_1401841e0(lVar2);

      return 0;

    }

  }

  return lVar2;

}





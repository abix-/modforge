// Address: 0x14016dcb0
// Ghidra name: FUN_14016dcb0
// ============ 0x14016dcb0 FUN_14016dcb0 (size=52) ============


longlong FUN_14016dcb0(void)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = FUN_140183290();

  if (lVar3 != 0) {

    lVar2 = *(longlong *)(lVar3 + 0x1a8);

    while (lVar1 = lVar2, lVar1 != 0) {

      lVar3 = lVar1;

      lVar2 = *(longlong *)(lVar1 + 0x1a8);

    }

  }

  return lVar3;

}





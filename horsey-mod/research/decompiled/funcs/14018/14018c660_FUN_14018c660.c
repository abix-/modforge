// Address: 0x14018c660
// Ghidra name: FUN_14018c660
// ============ 0x14018c660 FUN_14018c660 (size=79) ============


longlong FUN_14018c660(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dcf0();

  if (lVar2 != 0) {

    for (lVar2 = *(longlong *)(lVar2 + 0x348); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x1a0)) {

      lVar1 = *(longlong *)(lVar2 + 0x188);

      if ((lVar1 != 0) && (*(longlong *)(lVar1 + 8) == param_1)) {

        return lVar1;

      }

    }

  }

  return 0;

}





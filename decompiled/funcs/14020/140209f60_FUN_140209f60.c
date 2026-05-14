// Address: 0x140209f60
// Ghidra name: FUN_140209f60
// ============ 0x140209f60 FUN_140209f60 (size=34) ============


longlong FUN_140209f60(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = DAT_1403ffc50;

  while( true ) {

    if (lVar1 == 0) {

      return 0;

    }

    if (*(longlong *)(lVar1 + 0x40) == param_1) break;

    lVar1 = *(longlong *)(lVar1 + 0x58);

  }

  return lVar1;

}





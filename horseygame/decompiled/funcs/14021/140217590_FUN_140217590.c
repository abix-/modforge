// Address: 0x140217590
// Ghidra name: FUN_140217590
// ============ 0x140217590 FUN_140217590 (size=62) ============


void FUN_140217590(void)



{

  if (DAT_1403fdb28 != '\0') {

    FUN_140163670();

    DAT_1403fdb28 = 0;

    return;

  }

  if (DAT_1403e5308 != 0xffffffff) {

    TlsFree(DAT_1403e5308);

    DAT_1403e5308 = 0xffffffff;

  }

  return;

}





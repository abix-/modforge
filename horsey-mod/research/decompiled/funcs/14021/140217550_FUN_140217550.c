// Address: 0x140217550
// Ghidra name: FUN_140217550
// ============ 0x140217550 FUN_140217550 (size=56) ============


void FUN_140217550(void)



{

  if ((DAT_1403e5308 == 0xffffffff) && (DAT_1403fdb28 == '\0')) {

    DAT_1403e5308 = TlsAlloc();

    if (DAT_1403e5308 == 0xffffffff) {

      FUN_140163650();

      DAT_1403fdb28 = '\x01';

    }

  }

  return;

}





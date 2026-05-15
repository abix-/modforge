// Address: 0x1401639d0
// Ghidra name: thunk_FUN_140217550
// ============ 0x1401639d0 thunk_FUN_140217550 (size=5) ============


void thunk_FUN_140217550(void)



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





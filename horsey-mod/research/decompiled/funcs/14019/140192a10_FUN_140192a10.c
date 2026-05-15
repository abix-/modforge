// Address: 0x140192a10
// Ghidra name: FUN_140192a10
// ============ 0x140192a10 FUN_140192a10 (size=65) ============


undefined8 FUN_140192a10(void)



{

  int iVar1;

  

  FUN_140196b40(0);

  if (DAT_1403fccf8 == '\0') {

    iVar1 = FUN_1401964d0();

    if (iVar1 < 0) {

      FUN_140196b50(L"resolve DLL functions");

      return 0xffffffff;

    }

    DAT_1403fccf8 = '\x01';

  }

  return 0;

}





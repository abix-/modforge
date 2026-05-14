// Address: 0x140210280
// Ghidra name: FUN_140210280
// ============ 0x140210280 FUN_140210280 (size=91) ============


undefined1 FUN_140210280(longlong param_1)



{

  char cVar1;

  uint uVar2;

  

  uVar2 = *(uint *)(param_1 + 0x68);

  cVar1 = FUN_14000c9a0();

  if ((cVar1 == '\x01') || (cVar1 == '\x03')) {

    return 6;

  }

  if (cVar1 == '\x02') {

    return 7;

  }

  if ((uVar2 >> 0x13 & 1) != 0) {

    return 2;

  }

  if ((uVar2 >> 0x10 & 1) != 0) {

    return 3;

  }

  if ((uVar2 >> 0x11 & 1) != 0) {

    return 4;

  }

  return (uVar2 & 0x4000e) != 0;

}





// Address: 0x1402f0160
// Ghidra name: FUN_1402f0160
// ============ 0x1402f0160 FUN_1402f0160 (size=56) ============


ulonglong FUN_1402f0160(byte *param_1)



{

  byte bVar1;

  ulonglong uVar2;

  

  bVar1 = *param_1;

  if (-1 < (char)bVar1) {

    return (ulonglong)(bVar1 != 0);

  }

  if ((bVar1 & 0xe0) == 0xc0) {

    return 2;

  }

  if ((bVar1 & 0xf0) == 0xe0) {

    return 3;

  }

  uVar2 = 0xffffffff;

  if ((bVar1 & 0xf8) == 0xf0) {

    uVar2 = 4;

  }

  return uVar2;

}





// Address: 0x14018c5c0
// Ghidra name: FUN_14018c5c0
// ============ 0x14018c5c0 FUN_14018c5c0 (size=155) ============


ulonglong FUN_14018c5c0(void)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  if (DAT_1403fcb98 == '\0') {

    return 0;

  }

  uVar1 = FUN_140149300();

  uVar2 = (ulonglong)DAT_1403fcb9c * 1000000 + DAT_1403fcba0;

  if (DAT_1403fcba0 == 0) {

    DAT_1403fcba0 = uVar1 - uVar2;

    return uVar1;

  }

  if (-1 < (longlong)((uVar1 - uVar2) + -0xf424000000000)) {

    DAT_1403fcba0 = DAT_1403fcba0 + 0xf424000000000;

    return uVar2 + 0xf424000000000;

  }

  if (uVar1 < uVar2) {

    DAT_1403fcba0 = DAT_1403fcba0 + (uVar1 - uVar2);

    uVar2 = uVar1;

  }

  return uVar2;

}





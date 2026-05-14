// Address: 0x1402796b0
// Ghidra name: FUN_1402796b0
// ============ 0x1402796b0 FUN_1402796b0 (size=184) ============


ulonglong FUN_1402796b0(longlong param_1,ushort *param_2)



{

  byte bVar1;

  byte bVar2;

  ulonglong uVar3;

  

  if (*(char *)(param_1 + 0x2c) != '!') {

    uVar3 = FUN_14012e850("Unexpected extension response type");

    return uVar3 & 0xffffffffffffff00;

  }

  if ((*(char *)(param_1 + 0x30) != '\0') || (*(char *)(param_1 + 0x31) != -2)) {

    uVar3 = FUN_14012e850("Unexpected extension response address");

    return uVar3 & 0xffffffffffffff00;

  }

  bVar1 = *(byte *)(param_1 + 0x2f);

  if (bVar1 == 0x10) {

    *param_2 = 0;

    bVar1 = *(byte *)(param_1 + 0x32);

    *param_2 = (ushort)bVar1;

    *param_2 = CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x33));

    return CONCAT71((uint7)bVar1,1);

  }

  bVar2 = bVar1 & 0xf;

  if (bVar2 == 7) {

    *param_2 = 0x2e2e;

    return 1;

  }

  if (bVar2 != 0) {

    uVar3 = FUN_14012e850("Failed to read extension type: %u",bVar2);

    return uVar3 & 0xffffffffffffff00;

  }

  uVar3 = FUN_14012e850("Unexpected read length when reading extension type: %d",(bVar1 >> 4) + 1);

  return uVar3 & 0xffffffffffffff00;

}





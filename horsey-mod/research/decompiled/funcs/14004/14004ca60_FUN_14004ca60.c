// Address: 0x14004ca60
// Ghidra name: FUN_14004ca60
// ============ 0x14004ca60 FUN_14004ca60 (size=72) ============


ulonglong FUN_14004ca60(longlong param_1)



{

  byte bVar1;

  byte *pbVar2;

  ulonglong in_RAX;

  

  pbVar2 = *(byte **)(param_1 + 0x40);

  if (pbVar2 == (byte *)0x0) {

    in_RAX = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

    if ((int)in_RAX != -1) {

      return in_RAX;

    }

  }

  else if (pbVar2 < *(byte **)(param_1 + 0x50)) {

    bVar1 = *pbVar2;

    *(byte **)(param_1 + 0x40) = pbVar2 + 1;

    return (ulonglong)bVar1;

  }

  *(undefined4 *)(param_1 + 0x98) = 1;

  return in_RAX & 0xffffffffffffff00;

}





// Address: 0x140189d80
// Ghidra name: FUN_140189d80
// ============ 0x140189d80 FUN_140189d80 (size=227) ============


undefined1 FUN_140189d80(longlong param_1,ulonglong param_2)



{

  ushort uVar1;

  undefined1 uVar2;

  longlong lVar3;

  

  if (*(short *)(param_1 + 0x22) == 1) {

    uVar1 = *(ushort *)(param_1 + 0x32);

    if ((uVar1 != 8) && (((uVar1 - 0x10 & 0xffffffe7) != 0 || (uVar1 == 0x28)))) {

      uVar2 = FUN_14012e850("%u-bit PCM format not supported");

      return uVar2;

    }

  }

  else if ((*(short *)(param_1 + 0x22) == 3) && (*(short *)(param_1 + 0x32) != 0x20)) {

    uVar2 = FUN_14012e850("%u-bit IEEE floating-point format not supported",

                          *(short *)(param_1 + 0x32));

    return uVar2;

  }

  uVar1 = *(ushort *)(param_1 + 0x30);

  if ((int)((uint)*(ushort *)(param_1 + 0x32) * (uint)*(ushort *)(param_1 + 0x24)) %

      (int)((uint)uVar1 << 3) != 0) {

    uVar2 = FUN_14012e850("Unsupported block alignment");

    return uVar2;

  }

  if ((((*(int *)(param_1 + 0x6c) == 1) || (*(int *)(param_1 + 0x6c) == 2)) && (1 < uVar1)) &&

     (param_2 % (ulonglong)uVar1 != 0)) {

    uVar2 = FUN_14012e850("Truncated data chunk in WAVE file");

    return uVar2;

  }

  lVar3 = FUN_14018a0e0(param_1,param_2 / uVar1);

  *(longlong *)(param_1 + 0x58) = lVar3;

  return -1 < lVar3;

}





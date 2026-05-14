// Address: 0x1401891b0
// Ghidra name: FUN_1401891b0
// ============ 0x1401891b0 FUN_1401891b0 (size=150) ============


undefined1 FUN_1401891b0(longlong param_1,ulonglong param_2)



{

  ushort uVar1;

  undefined1 uVar2;

  longlong lVar3;

  

  if (*(short *)(param_1 + 0x32) != 8) {

    uVar2 = FUN_14012e850("Invalid companded bits per sample of %u",*(short *)(param_1 + 0x32));

    return uVar2;

  }

  uVar1 = *(ushort *)(param_1 + 0x30);

  if (uVar1 != *(ushort *)(param_1 + 0x24)) {

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





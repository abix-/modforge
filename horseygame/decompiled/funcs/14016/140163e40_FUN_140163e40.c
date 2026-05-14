// Address: 0x140163e40
// Ghidra name: FUN_140163e40
// ============ 0x140163e40 FUN_140163e40 (size=39) ============


undefined1 FUN_140163e40(longlong param_1)



{

  undefined1 uVar1;

  

  if (*(int *)(param_1 + 0x30) == 0) {

    uVar1 = FUN_14012e850("Stream has no source format");

    return uVar1;

  }

  if (*(int *)(param_1 + 0x3c) == 0) {

    uVar1 = FUN_14012e850("Stream has no destination format");

    return uVar1;

  }

  return 1;

}





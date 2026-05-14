// Address: 0x1401bb280
// Ghidra name: FUN_1401bb280
// ============ 0x1401bb280 FUN_1401bb280 (size=87) ============


undefined8 FUN_1401bb280(undefined8 param_1)



{

  undefined8 uVar1;

  char cVar2;

  longlong lVar3;

  uint uVar4;

  

  lVar3 = FUN_1401b9ab0();

  if (lVar3 == 0) {

    return 0;

  }

  if ((*(int *)(lVar3 + 0x1c) == 0) && (cVar2 = FUN_1401b2ca0(param_1,lVar3), cVar2 == '\0')) {

    return 0;

  }

  uVar4 = *(int *)(lVar3 + 0x1c) - 1;

  uVar1 = *(undefined8 *)(*(longlong *)(lVar3 + 0x10) + (ulonglong)uVar4 * 8);

  *(uint *)(lVar3 + 0x1c) = uVar4;

  return uVar1;

}





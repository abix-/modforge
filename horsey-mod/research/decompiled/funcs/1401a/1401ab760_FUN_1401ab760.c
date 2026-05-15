// Address: 0x1401ab760
// Ghidra name: FUN_1401ab760
// ============ 0x1401ab760 FUN_1401ab760 (size=51) ============


ulonglong FUN_1401ab760(longlong param_1)



{

  ulonglong in_RAX;

  ulonglong uVar1;

  uint uVar2;

  

  uVar2 = *(int *)(param_1 + 0x30) + 1;

  if (0x3ffffff < uVar2) {

    return in_RAX & 0xffffffffffffff00;

  }

  if ((uint)((ulonglong)uVar2 * 0xd9 >> 8) < *(uint *)(param_1 + 0x38)) {

    uVar1 = FUN_1401ab7a0(param_1,uVar2 * 2);

    return uVar1;

  }

  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);

}





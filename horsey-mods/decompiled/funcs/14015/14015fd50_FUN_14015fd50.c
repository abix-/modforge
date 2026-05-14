// Address: 0x14015fd50
// Ghidra name: FUN_14015fd50
// ============ 0x14015fd50 FUN_14015fd50 (size=80) ============


void FUN_14015fd50(longlong param_1)



{

  uint uVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  

  uVar1 = *(uint *)(param_1 + 0x60);

  uVar2 = FUN_14015e760(uVar1);

  *(undefined4 *)(param_1 + 0x88) = uVar2;

  iVar4 = (uVar1 >> 3 & 0x1f) * *(int *)(param_1 + 0x84) * *(int *)(param_1 + 100);

  iVar3 = *(int *)(param_1 + 0x84) * *(int *)(param_1 + 100) * 4;

  *(int *)(param_1 + 0x6c) = iVar4;

  if (iVar4 <= iVar3) {

    iVar4 = iVar3;

  }

  *(int *)(param_1 + 0xb0) = iVar4;

  return;

}





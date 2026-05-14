// Address: 0x140287450
// Ghidra name: FUN_140287450
// ============ 0x140287450 FUN_140287450 (size=166) ============


uint FUN_140287450(longlong param_1,longlong param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  

  iVar2 = FUN_140287500();

  uVar3 = -(uint)(iVar2 != 0) & 0x40;

  uVar1 = uVar3 | 1;

  if (*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) {

    uVar1 = uVar3;

  }

  iVar2 = FUN_140287550(param_1,param_2);

  uVar3 = uVar1 | 0x80;

  if (iVar2 == 0) {

    uVar3 = uVar1;

  }

  uVar1 = uVar3 | 0x200;

  if (*(int *)(param_1 + 0x48) == *(int *)(param_2 + 0x48)) {

    uVar1 = uVar3;

  }

  uVar3 = uVar1 | 8;

  if (*(int *)(param_1 + 0x14) == *(int *)(param_2 + 0x14)) {

    uVar3 = uVar1;

  }

  uVar1 = uVar3 | 0x10;

  if (*(int *)(param_1 + 0x18) == *(int *)(param_2 + 0x18)) {

    uVar1 = uVar3;

  }

  iVar2 = FUN_1402875c0(param_1,param_2);

  uVar3 = uVar1 | 0x100;

  if (iVar2 == 0) {

    uVar3 = uVar1;

  }

  if (uVar3 == 0) {

    uVar3 = 0x3d9;

  }

  return uVar3;

}





// Address: 0x140287720
// Ghidra name: FUN_140287720
// ============ 0x140287720 FUN_140287720 (size=419) ============


undefined8 FUN_140287720(longlong param_1,longlong param_2)



{

  int iVar1;

  uint *puVar2;

  uint *puVar3;

  

  param_1 = param_1 + 4;

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b30);

  if (iVar1 != 0) {

    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x80;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b40);

  if (iVar1 != 0) {

    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b50);

  if (iVar1 != 0) {

    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x200;

  }

  puVar3 = (uint *)(param_2 + 0x20);

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b60);

  if (iVar1 != 0) {

    *puVar3 = *(uint *)(param_2 + 0x20) | 0x400;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350ac0);

  if (iVar1 != 0) {

    *puVar3 = *puVar3 | 1;

  }

  puVar2 = (uint *)(param_2 + 0x20);

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b70);

  if (iVar1 != 0) {

    *puVar2 = *puVar3 | 0x8000;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350af0);

  if (iVar1 != 0) {

    *puVar2 = *puVar2 | 2;

  }

  puVar3 = (uint *)(param_2 + 0x20);

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350ae0);

  if (iVar1 != 0) {

    *puVar3 = *puVar2 | 4;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b00);

  if (iVar1 != 0) {

    *puVar3 = *puVar3 | 8;

  }

  puVar2 = (uint *)(param_2 + 0x20);

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b10);

  if (iVar1 != 0) {

    *puVar2 = *puVar3 | 0x10;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350b20);

  if (iVar1 != 0) {

    *puVar2 = *puVar2 | 0x20;

  }

  iVar1 = FUN_1401a98e0(param_1,&DAT_140350ad0);

  if (iVar1 != 0) {

    *(uint *)(param_2 + 0x20) = *puVar2 | 0x40;

  }

  return 1;

}





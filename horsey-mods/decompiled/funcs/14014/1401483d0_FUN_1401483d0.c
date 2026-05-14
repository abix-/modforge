// Address: 0x1401483d0
// Ghidra name: FUN_1401483d0
// ============ 0x1401483d0 FUN_1401483d0 (size=116) ============


undefined8 FUN_1401483d0(longlong param_1,char param_2)



{

  uint uVar1;

  char cVar2;

  undefined8 uVar3;

  uint uVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  uVar1 = *(uint *)(param_1 + 0x108);

  *(char *)(param_1 + 0x113) = param_2;

  uVar4 = uVar1 | 2;

  if (param_2 == -1) {

    uVar4 = uVar1 & 0xfffffffd;

  }

  *(uint *)(param_1 + 0x108) = uVar4;

  if (uVar4 != uVar1) {

    FUN_14017ba60(param_1 + 0x78);

  }

  return 1;

}





// Address: 0x140148630
// Ghidra name: FUN_140148630
// ============ 0x140148630 FUN_140148630 (size=180) ============


undefined8 FUN_140148630(longlong param_1,char param_2,uint param_3)



{

  uint uVar1;

  char cVar2;

  uint uVar3;

  undefined8 uVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar4;

  }

  if ((*(uint **)(param_1 + 0x48) != (uint *)0x0) && (**(uint **)(param_1 + 0x48) <= param_3)) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e68);

    return uVar4;

  }

  uVar1 = *(uint *)(param_1 + 0x108);

  if (param_2 == '\0') {

    uVar3 = uVar1 & 0xfffffbff;

  }

  else {

    uVar3 = uVar1 | 0x400;

    *(uint *)(param_1 + 0x10c) = param_3;

  }

  *(uint *)(param_1 + 0x108) = uVar3;

  if (uVar3 != uVar1) {

    FUN_14017ba60(param_1 + 0x78);

  }

  return 1;

}





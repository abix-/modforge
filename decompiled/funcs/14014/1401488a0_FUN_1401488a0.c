// Address: 0x1401488a0
// Ghidra name: FUN_1401488a0
// ============ 0x1401488a0 FUN_1401488a0 (size=129) ============


undefined8 FUN_1401488a0(longlong param_1,char param_2)



{

  uint uVar1;

  char cVar2;

  undefined8 uVar3;

  uint uVar4;

  

  cVar2 = FUN_1401489c0();

  if ((cVar2 != '\0') &&

     ((*(uint *)(param_1 + 4) == 0 || ((*(uint *)(param_1 + 4) & 0xf0000000) == 0x10000000)))) {

    uVar1 = *(uint *)(param_1 + 0x108);

    uVar4 = uVar1 | 0x1000;

    if (param_2 == '\0') {

      uVar4 = uVar1 & 0xffffefff;

    }

    *(uint *)(param_1 + 0x108) = uVar4;

    if (uVar4 != uVar1) {

      FUN_14017ba60(param_1 + 0x78);

    }

    return 1;

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

  return uVar3;

}





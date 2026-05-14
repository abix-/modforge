// Address: 0x1401486f0
// Ghidra name: FUN_1401486f0
// ============ 0x1401486f0 FUN_1401486f0 (size=161) ============


undefined8 FUN_1401486f0(longlong param_1,char param_2,char param_3,char param_4)



{

  uint uVar1;

  char cVar2;

  uint uVar3;

  undefined8 uVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

  }

  else {

    uVar1 = *(uint *)(param_1 + 0x108);

    *(char *)(param_1 + 0x110) = param_2;

    *(char *)(param_1 + 0x111) = param_3;

    *(char *)(param_1 + 0x112) = param_4;

    if (((param_2 == -1) && (param_3 == -1)) && (param_4 == -1)) {

      uVar3 = uVar1 & 0xfffffffe;

    }

    else {

      uVar3 = uVar1 | 1;

    }

    *(uint *)(param_1 + 0x108) = uVar3;

    if (uVar3 != uVar1) {

      FUN_14017ba60(param_1 + 0x78);

    }

    uVar4 = 1;

  }

  return uVar4;

}





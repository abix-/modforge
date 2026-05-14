// Address: 0x1401487f0
// Ghidra name: FUN_1401487f0
// ============ 0x1401487f0 FUN_1401487f0 (size=176) ============


undefined8 FUN_1401487f0(longlong param_1,int *param_2)



{

  uint uVar1;

  char cVar2;

  undefined8 uVar3;

  byte bVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  if (param_2 != (int *)0x0) {

    uVar1 = *(uint *)(param_1 + 4);

    if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

      bVar4 = (byte)(uVar1 >> 8);

    }

    else {

      bVar4 = 0;

    }

    if (1 << (bVar4 & 0x1f) < *param_2) {

      uVar3 = FUN_14012e850("Palette doesn\'t match surface format");

      return uVar3;

    }

  }

  if (param_2 != *(int **)(param_1 + 0x48)) {

    if (*(int **)(param_1 + 0x48) != (int *)0x0) {

      FUN_14017a0f0();

    }

    *(int **)(param_1 + 0x48) = param_2;

    if (param_2 != (int *)0x0) {

      param_2[5] = param_2[5] + 1;

    }

  }

  FUN_14017ba60(param_1 + 0x78);

  return 1;

}





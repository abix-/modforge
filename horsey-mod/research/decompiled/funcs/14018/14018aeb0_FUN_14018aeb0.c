// Address: 0x14018aeb0
// Ghidra name: FUN_14018aeb0
// ============ 0x14018aeb0 FUN_14018aeb0 (size=464) ============


undefined8 FUN_14018aeb0(longlong param_1)



{

  short *psVar1;

  ulonglong uVar2;

  char cVar3;

  undefined2 uVar4;

  undefined8 uVar5;

  longlong lVar6;

  

  uVar2 = *(ulonglong *)(param_1 + 0x18);

  psVar1 = (short *)(param_1 + 0x20);

  if (0x7fffffff < uVar2) {

    uVar5 = FUN_14012e850("Data of WAVE fmt chunk too big");

    return uVar5;

  }

  lVar6 = FUN_14012bf40(*(undefined8 *)(param_1 + 0x10),(longlong)(int)uVar2);

  if (((((lVar6 == 0) || (cVar3 = FUN_14012c8c0(lVar6,psVar1), cVar3 == '\0')) ||

       (cVar3 = FUN_14012c8c0(lVar6,param_1 + 0x24), cVar3 == '\0')) ||

      ((cVar3 = FUN_14012c940(lVar6,param_1 + 0x28), cVar3 == '\0' ||

       (cVar3 = FUN_14012c940(lVar6,param_1 + 0x2c), cVar3 == '\0')))) ||

     (cVar3 = FUN_14012c8c0(lVar6,param_1 + 0x30), cVar3 == '\0')) {

    return 0;

  }

  *(short *)(param_1 + 0x22) = *psVar1;

  if (uVar2 < 0x10) {

    if (*psVar1 == 1) {

      FUN_14012bd50(lVar6);

      uVar5 = FUN_14012e850("Missing wBitsPerSample field in WAVE fmt chunk");

      return uVar5;

    }

  }

  else {

    cVar3 = FUN_14012c8c0(lVar6,param_1 + 0x32);

    if (cVar3 == '\0') {

      return 0;

    }

    if ((0x11 < uVar2) && (cVar3 = FUN_14012c8c0(lVar6,param_1 + 0x34), cVar3 == '\0')) {

      return 0;

    }

  }

  if (*psVar1 == -2) {

    if ((uVar2 < 0x28) || (*(ushort *)(param_1 + 0x34) < 0x16)) {

      FUN_14012bd50(lVar6);

      uVar5 = FUN_14012e850("Extensible WAVE header too small");

      return uVar5;

    }

    cVar3 = FUN_14012c8c0(lVar6,param_1 + 0x36);

    if ((cVar3 != '\0') && (cVar3 = FUN_14012c940(lVar6,param_1 + 0x3c), cVar3 != '\0')) {

      FUN_14012c730(lVar6,param_1 + 0x40,0x10);

    }

    *(uint *)(param_1 + 0x38) = (uint)*(ushort *)(param_1 + 0x36);

    uVar4 = FUN_14018a560(psVar1);

    *(undefined2 *)(param_1 + 0x22) = uVar4;

  }

  FUN_14012bd50(lVar6);

  return 1;

}





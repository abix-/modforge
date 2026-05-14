// Address: 0x14004cab0
// Ghidra name: FUN_14004cab0
// ============ 0x14004cab0 FUN_14004cab0 (size=130) ============


uint FUN_14004cab0(longlong param_1)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  uint uVar4;

  

  if (*(char *)(param_1 + 0x6e4) == '\0') {

    if (*(int *)(param_1 + 0x6ec) != 0) {

      return 0xffffffff;

    }

    iVar3 = FUN_14004eeb0();

    if (iVar3 == 0) {

      return 0xffffffff;

    }

  }

  *(char *)(param_1 + 0x6e4) = *(char *)(param_1 + 0x6e4) + -1;

  *(int *)(param_1 + 0x6fc) = *(int *)(param_1 + 0x6fc) + 1;

  pbVar2 = *(byte **)(param_1 + 0x40);

  if (pbVar2 == (byte *)0x0) {

    uVar4 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

    if (uVar4 != 0xffffffff) goto LAB_14004cb29;

  }

  else if (pbVar2 < *(byte **)(param_1 + 0x50)) {

    bVar1 = *pbVar2;

    *(byte **)(param_1 + 0x40) = pbVar2 + 1;

    return (uint)bVar1;

  }

  uVar4 = 0;

  *(undefined4 *)(param_1 + 0x98) = 1;

LAB_14004cb29:

  return uVar4 & 0xff;

}





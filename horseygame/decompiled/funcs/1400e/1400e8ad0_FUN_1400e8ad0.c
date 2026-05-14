// Address: 0x1400e8ad0
// Ghidra name: FUN_1400e8ad0
// ============ 0x1400e8ad0 FUN_1400e8ad0 (size=171) ============


int FUN_1400e8ad0(longlong param_1)



{

  byte bVar1;

  byte *pbVar2;

  uint uVar3;

  uint uVar4;

  

  pbVar2 = *(byte **)(param_1 + 0xb8);

  uVar3 = 0;

  if (pbVar2 < *(byte **)(param_1 + 0xc0)) {

    uVar4 = (uint)*pbVar2;

    pbVar2 = pbVar2 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar2;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    uVar4 = 0;

  }

  else {

    FUN_1400ed820();

    uVar4 = (uint)**(byte **)(param_1 + 0xb8);

    pbVar2 = *(byte **)(param_1 + 0xb8) + 1;

    *(byte **)(param_1 + 0xb8) = pbVar2;

  }

  if (pbVar2 < *(byte **)(param_1 + 0xc0)) {

    bVar1 = *pbVar2;

  }

  else {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400e8b65;

    FUN_1400ed820(param_1);

    pbVar2 = *(byte **)(param_1 + 0xb8);

    bVar1 = *pbVar2;

  }

  uVar3 = (uint)bVar1;

  *(byte **)(param_1 + 0xb8) = pbVar2 + 1;

LAB_1400e8b65:

  return uVar3 + uVar4 * 0x100;

}





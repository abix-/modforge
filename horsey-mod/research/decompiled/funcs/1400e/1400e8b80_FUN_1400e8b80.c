// Address: 0x1400e8b80
// Ghidra name: FUN_1400e8b80
// ============ 0x1400e8b80 FUN_1400e8b80 (size=171) ============


int FUN_1400e8b80(longlong param_1)



{

  byte bVar1;

  byte *pbVar2;

  uint uVar3;

  uint uVar4;

  

  pbVar2 = *(byte **)(param_1 + 0xb8);

  uVar4 = 0;

  if (pbVar2 < *(byte **)(param_1 + 0xc0)) {

    uVar3 = (uint)*pbVar2;

    pbVar2 = pbVar2 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar2;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    uVar3 = 0;

  }

  else {

    FUN_1400ed820();

    uVar3 = (uint)**(byte **)(param_1 + 0xb8);

    pbVar2 = *(byte **)(param_1 + 0xb8) + 1;

    *(byte **)(param_1 + 0xb8) = pbVar2;

  }

  if (pbVar2 < *(byte **)(param_1 + 0xc0)) {

    bVar1 = *pbVar2;

  }

  else {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400e8c15;

    FUN_1400ed820(param_1);

    pbVar2 = *(byte **)(param_1 + 0xb8);

    bVar1 = *pbVar2;

  }

  uVar4 = (uint)bVar1;

  *(byte **)(param_1 + 0xb8) = pbVar2 + 1;

LAB_1400e8c15:

  return uVar3 + uVar4 * 0x100;

}





// Address: 0x14019f260
// Ghidra name: FUN_14019f260
// ============ 0x14019f260 FUN_14019f260 (size=162) ============


int FUN_14019f260(longlong param_1)



{

  byte *pbVar1;

  byte bVar2;

  byte bVar3;

  

  pbVar1 = *(byte **)(param_1 + 0xc0);

  if (pbVar1 < *(byte **)(param_1 + 200)) {

    bVar3 = *pbVar1;

    pbVar1 = pbVar1 + 1;

    *(byte **)(param_1 + 0xc0) = pbVar1;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    bVar3 = 0;

  }

  else {

    FUN_1401a4400();

    bVar3 = **(byte **)(param_1 + 0xc0);

    pbVar1 = *(byte **)(param_1 + 0xc0) + 1;

    *(byte **)(param_1 + 0xc0) = pbVar1;

  }

  if (*(byte **)(param_1 + 200) <= pbVar1) {

    if (*(int *)(param_1 + 0x30) == 0) {

      bVar2 = 0;

      goto LAB_14019f2eb;

    }

    FUN_1401a4400(param_1,param_1);

    pbVar1 = *(byte **)(param_1 + 0xc0);

  }

  bVar2 = *pbVar1;

  *(byte **)(param_1 + 0xc0) = pbVar1 + 1;

LAB_14019f2eb:

  return (uint)bVar3 * 0x100 + (uint)bVar2;

}





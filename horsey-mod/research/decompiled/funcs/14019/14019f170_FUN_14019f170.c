// Address: 0x14019f170
// Ghidra name: FUN_14019f170
// ============ 0x14019f170 FUN_14019f170 (size=96) ============


void FUN_14019f170(undefined8 *param_1)



{

  int iVar1;

  byte *pbVar2;

  byte bVar3;

  byte bVar4;

  

  do {

    bVar3 = (byte)*(int *)(param_1 + 2);

    if ((uint)(1 << (bVar3 & 0x1f)) <= *(uint *)(param_1 + 3)) {

      *param_1 = param_1[1];

      return;

    }

    pbVar2 = (byte *)*param_1;

    if (pbVar2 < (byte *)param_1[1]) {

      bVar4 = *pbVar2;

      *param_1 = pbVar2 + 1;

    }

    else {

      bVar4 = 0;

    }

    iVar1 = *(int *)(param_1 + 2) + 8;

    *(int *)(param_1 + 2) = iVar1;

    *(uint *)(param_1 + 3) = (uint)bVar4 << (bVar3 & 0x1f) | *(uint *)(param_1 + 3);

  } while (iVar1 < 0x19);

  return;

}





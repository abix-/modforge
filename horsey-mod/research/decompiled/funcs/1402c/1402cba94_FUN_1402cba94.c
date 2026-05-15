// Address: 0x1402cba94
// Ghidra name: FUN_1402cba94
// ============ 0x1402cba94 FUN_1402cba94 (size=228) ============


uint * FUN_1402cba94(uint *param_1,longlong param_2,longlong param_3)



{

  byte bVar1;

  uint uVar2;

  byte *pbVar3;

  uint *puVar4;

  

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  if (*(int *)(param_2 + 0xc) == 0) {

    *param_1 = 0;

  }

  else {

    pbVar3 = (byte *)(*(int *)(param_2 + 0xc) + param_3);

    *(byte **)(param_1 + 2) = pbVar3;

    bVar1 = (&DAT_1403872d0)[*pbVar3 & 0xf];

    pbVar3 = pbVar3 + -(longlong)(char)(&DAT_1403872c0)[*pbVar3 & 0xf];

    uVar2 = *(uint *)(pbVar3 + -4);

    *(byte **)(param_1 + 2) = pbVar3;

    *param_1 = uVar2 >> (bVar1 & 0x1f);

    *(byte **)(param_1 + 4) = pbVar3;

    bVar1 = (&DAT_1403872d0)[*pbVar3 & 0xf];

    pbVar3 = pbVar3 + -(longlong)(char)(&DAT_1403872c0)[*pbVar3 & 0xf];

    uVar2 = *(uint *)(pbVar3 + -4);

    *(byte **)(param_1 + 2) = pbVar3;

    param_1[6] = uVar2 >> (bVar1 & 0x1f);

    bVar1 = (&DAT_1403872d0)[*pbVar3 & 0xf];

    pbVar3 = pbVar3 + -(longlong)(char)(&DAT_1403872c0)[*pbVar3 & 0xf];

    uVar2 = *(uint *)(pbVar3 + -4);

    *(byte **)(param_1 + 2) = pbVar3;

    param_1[7] = uVar2 >> (bVar1 & 0x1f);

    puVar4 = (uint *)(pbVar3 + -(longlong)(char)(&DAT_1403872c0)[*pbVar3 & 0xf]);

    param_1[8] = puVar4[-1] >> ((&DAT_1403872d0)[*pbVar3 & 0xf] & 0x1f);

    *(uint **)(param_1 + 2) = puVar4;

    uVar2 = *puVar4;

    *(uint **)(param_1 + 2) = puVar4 + 1;

    param_1[9] = uVar2;

  }

  return param_1;

}





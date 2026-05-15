// Address: 0x1400e53d0
// Ghidra name: FUN_1400e53d0
// ============ 0x1400e53d0 FUN_1400e53d0 (size=226) ============


byte * FUN_1400e53d0(byte *param_1,byte *param_2,undefined8 param_3,int param_4)



{

  longlong lVar1;

  int iVar2;

  byte bVar3;

  byte *pbVar4;

  byte *pbVar5;

  longlong lVar6;

  int iVar7;

  longlong lVar8;

  

  bVar3 = *param_2;

  *param_1 = bVar3;

  if (param_4 == 1) {

    param_1[1] = bVar3;

    return param_1;

  }

  lVar6 = (longlong)param_4;

  iVar7 = 1;

  param_1[1] = (byte)(param_2[1] + 2 + (uint)*param_2 + (uint)*param_2 * 2 >> 2);

  lVar1 = lVar6 + -1;

  if (1 < lVar1) {

    lVar8 = lVar6 + -2;

    iVar7 = (int)lVar8 + 1;

    pbVar5 = param_2 + 2;

    pbVar4 = param_1;

    do {

      iVar2 = (uint)pbVar5[-1] * 3 + 2;

      pbVar4[2] = (byte)((uint)pbVar5[-2] + iVar2 >> 2);

      pbVar4[3] = (byte)((uint)*pbVar5 + iVar2 >> 2);

      lVar8 = lVar8 + -1;

      pbVar5 = pbVar5 + 1;

      pbVar4 = pbVar4 + 2;

    } while (lVar8 != 0);

  }

  param_1[iVar7 * 2] =

       (byte)(param_2[lVar1] + 2 + (uint)param_2[lVar6 + -2] + (uint)param_2[lVar6 + -2] * 2 >> 2);

  param_1[(longlong)(iVar7 * 2) + 1] = param_2[lVar1];

  return param_1;

}





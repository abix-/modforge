// Address: 0x1402c83f4
// Ghidra name: FUN_1402c83f4
// ============ 0x1402c83f4 FUN_1402c83f4 (size=300) ============


longlong FUN_1402c83f4(byte *param_1,byte *param_2,longlong param_3,int param_4,char param_5)



{

  uint *puVar1;

  byte *pbVar2;

  byte bVar3;

  byte bVar4;

  undefined4 uVar5;

  int iVar6;

  code *pcVar7;

  uint uVar8;

  uint uVar9;

  byte *pbVar10;

  byte *pbVar11;

  

  bVar3 = *param_1;

  pbVar11 = param_1 + 1;

  *param_2 = bVar3;

  if ((bVar3 & 4) != 0) {

    bVar4 = *pbVar11;

    pbVar11 = pbVar11 + -(longlong)(char)(&DAT_1403872c0)[bVar4 & 0xf];

    *(uint *)(param_2 + 4) = *(uint *)(pbVar11 + -4) >> ((&DAT_1403872d0)[bVar4 & 0xf] & 0x1f);

  }

  if ((bVar3 & 8) != 0) {

    uVar5 = *(undefined4 *)pbVar11;

    pbVar11 = pbVar11 + 4;

    *(undefined4 *)(param_2 + 8) = uVar5;

  }

  if ((bVar3 & 0x10) != 0) {

    uVar5 = *(undefined4 *)pbVar11;

    pbVar11 = pbVar11 + 4;

    *(undefined4 *)(param_2 + 0xc) = uVar5;

  }

  uVar9 = 0;

  pbVar10 = pbVar11 + 4;

  if ((param_5 == '\0') && ((bVar3 & 2) != 0)) {

    param_2[0x10] = 0;

    param_2[0x11] = 0;

    param_2[0x12] = 0;

    param_2[0x13] = 0;

    if (*(int *)pbVar11 == 0) {

      pcVar7 = (code *)swi(0x29);

      (*pcVar7)(7);

    }

    else {

      uVar8 = *(byte *)(param_3 + *(int *)pbVar11) & 0xf;

      pbVar11 = (byte *)(param_3 + *(int *)pbVar11) + -(longlong)(char)(&DAT_1403872c0)[uVar8];

      puVar1 = (uint *)(pbVar11 + -4);

      if (*puVar1 >> ((&DAT_1403872d0)[uVar8] & 0x1f) != 0) {

        do {

          iVar6 = *(int *)pbVar11;

          pbVar2 = pbVar11 + 4;

          pbVar11 = pbVar11 + 8;

          if (iVar6 == param_4) {

            *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)pbVar2;

            break;

          }

          uVar9 = uVar9 + 1;

        } while (uVar9 < *puVar1 >> ((&DAT_1403872d0)[uVar8] & 0x1f));

      }

    }

  }

  else {

    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)pbVar11;

  }

  if ((bVar3 & 1) != 0) {

    bVar3 = *pbVar10;

    pbVar10 = pbVar10 + -(longlong)(char)(&DAT_1403872c0)[bVar3 & 0xf];

    *(uint *)(param_2 + 0x14) = *(uint *)(pbVar10 + -4) >> ((&DAT_1403872d0)[bVar3 & 0xf] & 0x1f);

  }

  return (longlong)pbVar10 - (longlong)param_1;

}





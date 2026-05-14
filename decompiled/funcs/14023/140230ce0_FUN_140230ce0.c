// Address: 0x140230ce0
// Ghidra name: FUN_140230ce0
// ============ 0x140230ce0 FUN_140230ce0 (size=1566) ============


void FUN_140230ce0(int param_1,int param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  byte *pbVar5;

  ulonglong uVar6;

  int iVar7;

  byte *pbVar8;

  int iVar9;

  longlong lVar10;

  int iVar11;

  byte *pbVar12;

  byte *pbVar13;

  uint *puVar14;

  uint *puVar15;

  ulonglong local_50;

  

  lVar10 = (longlong)(int)param_10 * 3;

  param_10 = 0;

  uVar2 = 0;

  if (param_2 != 1) {

    do {

      uVar6 = (ulonglong)((param_10 >> 1) * param_7);

      pbVar8 = (byte *)(param_5 + uVar6);

      pbVar12 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      puVar14 = (uint *)((ulonglong)(param_10 * param_9) + param_8);

      pbVar5 = (byte *)(uVar6 + param_4);

      puVar15 = (uint *)((ulonglong)((param_10 + 1) * param_9) + param_8);

      pbVar13 = (byte *)((ulonglong)((param_10 + 1) * param_6) + param_3);

      iVar4 = 0;

      if (param_1 != 1) {

        uVar2 = (param_1 - 2U >> 1) + 1;

        local_50 = (ulonglong)uVar2;

        iVar4 = uVar2 * 2;

        do {

          iVar11 = (int)*(short *)(&DAT_1403582ba + lVar10 * 4) * (*pbVar5 - 0x80);

          iVar7 = (int)*(short *)(&DAT_1403582b4 + lVar10 * 4) * (*pbVar8 - 0x80);

          iVar3 = (int)*(short *)(&DAT_1403582b6 + lVar10 * 4) * (*pbVar5 - 0x80) +

                  (int)*(short *)(&DAT_1403582b8 + lVar10 * 4) * (*pbVar8 - 0x80);

          iVar9 = ((uint)*pbVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          bVar1 = FUN_140230cc0(iVar9 + iVar11);

          uVar2 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar3);

          uVar2 = (uVar2 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar7);

          *puVar14 = uVar2 | bVar1;

          iVar9 = ((uint)pbVar12[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          bVar1 = FUN_140230cc0(iVar9 + iVar11);

          uVar2 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar3);

          uVar2 = (uVar2 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar7);

          puVar14[1] = uVar2 | bVar1;

          puVar14 = puVar14 + 2;

          iVar9 = ((uint)*pbVar13 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          bVar1 = FUN_140230cc0(iVar9 + iVar11);

          uVar2 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar3);

          uVar2 = (uVar2 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar7);

          *puVar15 = uVar2 | bVar1;

          iVar9 = ((uint)pbVar13[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          bVar1 = FUN_140230cc0(iVar9 + iVar11);

          uVar2 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar3);

          uVar2 = (uVar2 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar9 + iVar7);

          pbVar12 = pbVar12 + 2;

          pbVar13 = pbVar13 + 2;

          puVar15[1] = uVar2 | bVar1;

          pbVar5 = pbVar5 + 1;

          puVar15 = puVar15 + 2;

          pbVar8 = pbVar8 + 1;

          local_50 = local_50 - 1;

        } while (local_50 != 0);

      }

      if (iVar4 == param_1 + -1) {

        iVar3 = (int)*(short *)(&DAT_1403582b4 + lVar10 * 4) * (*pbVar8 - 0x80);

        iVar9 = (int)*(short *)(&DAT_1403582ba + lVar10 * 4) * (*pbVar5 - 0x80);

        iVar4 = (int)*(short *)(&DAT_1403582b8 + lVar10 * 4) * (*pbVar8 - 0x80) +

                (int)*(short *)(&DAT_1403582b6 + lVar10 * 4) * (*pbVar5 - 0x80);

        iVar7 = ((uint)*pbVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        bVar1 = FUN_140230cc0(iVar9 + iVar7);

        uVar2 = (bVar1 | 0xffffff00) << 8;

        bVar1 = FUN_140230cc0(iVar4 + iVar7);

        uVar2 = (uVar2 | bVar1) << 8;

        bVar1 = FUN_140230cc0(iVar3 + iVar7);

        *puVar14 = uVar2 | bVar1;

        iVar7 = ((uint)*pbVar13 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        bVar1 = FUN_140230cc0(iVar9 + iVar7);

        uVar2 = (bVar1 | 0xffffff00) << 8;

        bVar1 = FUN_140230cc0(iVar4 + iVar7);

        uVar2 = (uVar2 | bVar1) << 8;

        bVar1 = FUN_140230cc0(iVar3 + iVar7);

        *puVar15 = uVar2 | bVar1;

      }

      uVar2 = param_10 + 2;

      param_10 = uVar2;

    } while (uVar2 < param_2 - 1U);

  }

  iVar4 = 0;

  if (uVar2 == param_2 - 1U) {

    uVar6 = (ulonglong)((uVar2 >> 1) * param_7);

    pbVar12 = (byte *)(param_4 + uVar6);

    pbVar5 = (byte *)(param_5 + uVar6);

    pbVar8 = (byte *)((ulonglong)(uVar2 * param_6) + param_3);

    puVar14 = (uint *)((ulonglong)(uVar2 * param_9) + param_8);

    if (param_1 != 1) {

      uVar2 = (param_1 - 2U >> 1) + 1;

      uVar6 = (ulonglong)uVar2;

      iVar4 = uVar2 * 2;

      do {

        iVar11 = (int)*(short *)(&DAT_1403582ba + lVar10 * 4) * (*pbVar12 - 0x80);

        iVar7 = (int)*(short *)(&DAT_1403582b4 + lVar10 * 4) * (*pbVar5 - 0x80);

        iVar3 = (int)*(short *)(&DAT_1403582b6 + lVar10 * 4) * (*pbVar12 - 0x80) +

                (int)*(short *)(&DAT_1403582b8 + lVar10 * 4) * (*pbVar5 - 0x80);

        iVar9 = ((uint)*pbVar8 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        bVar1 = FUN_140230cc0(iVar9 + iVar11);

        uVar2 = (bVar1 | 0xffffff00) << 8;

        bVar1 = FUN_140230cc0(iVar9 + iVar3);

        uVar2 = (uVar2 | bVar1) << 8;

        bVar1 = FUN_140230cc0(iVar9 + iVar7);

        *puVar14 = uVar2 | bVar1;

        iVar9 = ((uint)pbVar8[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        bVar1 = FUN_140230cc0(iVar9 + iVar11);

        uVar2 = (bVar1 | 0xffffff00) << 8;

        bVar1 = FUN_140230cc0(iVar9 + iVar3);

        uVar2 = (uVar2 | bVar1) << 8;

        bVar1 = FUN_140230cc0(iVar9 + iVar7);

        pbVar8 = pbVar8 + 2;

        pbVar12 = pbVar12 + 1;

        puVar14[1] = uVar2 | bVar1;

        pbVar5 = pbVar5 + 1;

        puVar14 = puVar14 + 2;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (iVar4 == param_1 + -1) {

      iVar3 = *pbVar5 - 0x80;

      iVar7 = ((uint)*pbVar8 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) *

              (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

      iVar4 = *pbVar12 - 0x80;

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b6 + lVar10 * 4) * iVar4 +

                            *(short *)(&DAT_1403582b8 + lVar10 * 4) * iVar3 + iVar7);

      uVar2 = (uint)bVar1;

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582ba + lVar10 * 4) * iVar4 + iVar7);

      uVar2 = (uVar2 | (bVar1 | 0xffffff00) << 8) << 8;

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar10 * 4) * iVar3 + iVar7);

      *puVar14 = uVar2 | bVar1;

    }

  }

  return;

}





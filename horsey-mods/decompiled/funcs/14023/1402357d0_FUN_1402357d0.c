// Address: 0x1402357d0
// Ghidra name: FUN_1402357d0
// ============ 0x1402357d0 FUN_1402357d0 (size=1616) ============


void FUN_1402357d0(int param_1,int param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  byte bVar1;

  uint uVar2;

  ushort uVar3;

  int iVar4;

  int iVar5;

  byte *pbVar6;

  ushort *puVar7;

  int iVar8;

  byte *pbVar9;

  int iVar10;

  longlong lVar11;

  int iVar12;

  byte *pbVar13;

  ulonglong uVar14;

  ushort *puVar15;

  byte *pbVar16;

  

  lVar11 = (longlong)(int)param_10 * 3;

  param_10 = 0;

  uVar2 = 0;

  if (param_2 != 1) {

    do {

      iVar5 = 0;

      uVar14 = (ulonglong)((param_10 >> 1) * param_7);

      pbVar9 = (byte *)(param_5 + uVar14);

      pbVar16 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      pbVar13 = (byte *)((ulonglong)((param_10 + 1) * param_6) + param_3);

      pbVar6 = (byte *)(uVar14 + param_4);

      puVar7 = (ushort *)((ulonglong)(param_10 * param_9) + param_8);

      puVar15 = (ushort *)((ulonglong)((param_10 + 1) * param_9) + param_8);

      if (param_1 != 1) {

        uVar2 = (param_1 - 2U >> 1) + 1;

        iVar5 = uVar2 * 2;

        uVar14 = (ulonglong)uVar2;

        do {

          iVar4 = (int)*(short *)(&DAT_1403582ba + lVar11 * 4) * (*pbVar6 - 0x80);

          iVar10 = (int)*(short *)(&DAT_1403582b4 + lVar11 * 4) * (*pbVar9 - 0x80);

          iVar12 = (int)*(short *)(&DAT_1403582b6 + lVar11 * 4) * (*pbVar6 - 0x80) +

                   (int)*(short *)(&DAT_1403582b8 + lVar11 * 4) * (*pbVar9 - 0x80);

          iVar8 = ((uint)*pbVar16 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

          bVar1 = FUN_140230cc0(iVar8 + iVar10);

          uVar3 = (bVar1 & 0xfff8) << 5;

          bVar1 = FUN_140230cc0(iVar8 + iVar12);

          uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

          bVar1 = FUN_140230cc0(iVar8 + iVar4);

          *puVar7 = uVar3 | bVar1 >> 3;

          iVar8 = ((uint)pbVar16[1] - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

          bVar1 = FUN_140230cc0(iVar8 + iVar10);

          uVar3 = (bVar1 & 0xfff8) << 5;

          bVar1 = FUN_140230cc0(iVar8 + iVar12);

          uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

          bVar1 = FUN_140230cc0(iVar8 + iVar4);

          puVar7[1] = uVar3 | bVar1 >> 3;

          puVar7 = puVar7 + 2;

          iVar8 = ((uint)*pbVar13 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

          bVar1 = FUN_140230cc0(iVar8 + iVar10);

          uVar3 = (bVar1 & 0xfff8) << 5;

          bVar1 = FUN_140230cc0(iVar8 + iVar12);

          uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

          bVar1 = FUN_140230cc0(iVar8 + iVar4);

          *puVar15 = uVar3 | bVar1 >> 3;

          iVar8 = ((uint)pbVar13[1] - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

          bVar1 = FUN_140230cc0(iVar8 + iVar10);

          uVar3 = (bVar1 & 0xfff8) << 5;

          bVar1 = FUN_140230cc0(iVar8 + iVar12);

          uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

          bVar1 = FUN_140230cc0(iVar8 + iVar4);

          pbVar16 = pbVar16 + 2;

          pbVar13 = pbVar13 + 2;

          pbVar6 = pbVar6 + 2;

          puVar15[1] = uVar3 | bVar1 >> 3;

          pbVar9 = pbVar9 + 2;

          puVar15 = puVar15 + 2;

          uVar14 = uVar14 - 1;

        } while (uVar14 != 0);

      }

      if (iVar5 == param_1 + -1) {

        iVar8 = (int)*(short *)(&DAT_1403582b4 + lVar11 * 4) * (*pbVar9 - 0x80);

        iVar5 = (int)*(short *)(&DAT_1403582ba + lVar11 * 4) * (*pbVar6 - 0x80);

        iVar10 = (int)*(short *)(&DAT_1403582b8 + lVar11 * 4) * (*pbVar9 - 0x80) +

                 (int)*(short *)(&DAT_1403582b6 + lVar11 * 4) * (*pbVar6 - 0x80);

        iVar4 = ((uint)*pbVar16 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

        bVar1 = FUN_140230cc0(iVar8 + iVar4);

        uVar3 = (bVar1 & 0xfff8) << 5;

        bVar1 = FUN_140230cc0(iVar10 + iVar4);

        uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

        bVar1 = FUN_140230cc0(iVar5 + iVar4);

        *puVar7 = uVar3 | bVar1 >> 3;

        iVar4 = ((uint)*pbVar13 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

        bVar1 = FUN_140230cc0(iVar8 + iVar4);

        uVar3 = (bVar1 & 0xfff8) << 5;

        bVar1 = FUN_140230cc0(iVar10 + iVar4);

        uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

        bVar1 = FUN_140230cc0(iVar5 + iVar4);

        *puVar15 = uVar3 | bVar1 >> 3;

      }

      uVar2 = param_10 + 2;

      param_10 = uVar2;

    } while (uVar2 < param_2 - 1U);

  }

  iVar5 = 0;

  if (uVar2 == param_2 - 1U) {

    uVar14 = (ulonglong)((uVar2 >> 1) * param_7);

    pbVar6 = (byte *)((ulonglong)(param_6 * uVar2) + param_3);

    pbVar9 = (byte *)(param_4 + uVar14);

    pbVar13 = (byte *)(param_5 + uVar14);

    puVar7 = (ushort *)((ulonglong)(uVar2 * param_9) + param_8);

    if (param_1 != 1) {

      uVar2 = (param_1 - 2U >> 1) + 1;

      uVar14 = (ulonglong)uVar2;

      iVar5 = uVar2 * 2;

      do {

        iVar4 = (int)*(short *)(&DAT_1403582ba + lVar11 * 4) * (*pbVar9 - 0x80);

        iVar10 = (int)*(short *)(&DAT_1403582b4 + lVar11 * 4) * (*pbVar13 - 0x80);

        iVar12 = (int)*(short *)(&DAT_1403582b6 + lVar11 * 4) * (*pbVar9 - 0x80) +

                 (int)*(short *)(&DAT_1403582b8 + lVar11 * 4) * (*pbVar13 - 0x80);

        iVar8 = ((uint)*pbVar6 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

        bVar1 = FUN_140230cc0(iVar8 + iVar10);

        uVar3 = (bVar1 & 0xfff8) << 5;

        bVar1 = FUN_140230cc0(iVar8 + iVar12);

        uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

        bVar1 = FUN_140230cc0(iVar8 + iVar4);

        *puVar7 = uVar3 | bVar1 >> 3;

        iVar8 = ((uint)pbVar6[1] - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

        bVar1 = FUN_140230cc0(iVar10 + iVar8);

        uVar3 = (bVar1 & 0xfff8) << 5;

        bVar1 = FUN_140230cc0(iVar12 + iVar8);

        uVar3 = (uVar3 | bVar1 & 0xfc) << 3;

        bVar1 = FUN_140230cc0(iVar4 + iVar8);

        pbVar6 = pbVar6 + 2;

        pbVar9 = pbVar9 + 2;

        pbVar13 = pbVar13 + 2;

        puVar7[1] = uVar3 | bVar1 >> 3;

        puVar7 = puVar7 + 2;

        uVar14 = uVar14 - 1;

      } while (uVar14 != 0);

    }

    if (iVar5 == param_1 + -1) {

      iVar5 = *pbVar13 - 0x80;

      iVar4 = ((uint)*pbVar6 - (uint)(byte)(&DAT_1403582b0)[lVar11 * 4]) *

              (int)*(short *)(&DAT_1403582b2 + lVar11 * 4);

      iVar8 = *pbVar9 - 0x80;

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b6 + lVar11 * 4) * iVar8 +

                            *(short *)(&DAT_1403582b8 + lVar11 * 4) * iVar5 + iVar4);

      uVar3 = (ushort)(bVar1 & 0xfc);

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar11 * 4) * iVar5 + iVar4);

      uVar3 = (uVar3 | (bVar1 & 0xfff8) << 5) << 3;

      bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582ba + lVar11 * 4) * iVar8 + iVar4);

      *puVar7 = uVar3 | bVar1 >> 3;

    }

  }

  return;

}





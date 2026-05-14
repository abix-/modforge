// Address: 0x1402352e0
// Ghidra name: FUN_1402352e0
// ============ 0x1402352e0 FUN_1402352e0 (size=1252) ============


void FUN_1402352e0(int param_1,int param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  short sVar1;

  undefined1 uVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  ulonglong uVar6;

  undefined1 *puVar7;

  undefined1 *puVar8;

  int iVar9;

  byte *pbVar10;

  int iVar11;

  longlong lVar12;

  int iVar13;

  byte *pbVar14;

  byte *pbVar15;

  byte *pbVar16;

  

  uVar3 = 0;

  lVar12 = (longlong)(int)param_10 * 3;

  param_10 = 0;

  if (param_2 != 1) {

    do {

      iVar5 = 0;

      uVar6 = (ulonglong)((param_10 >> 1) * param_7);

      pbVar10 = (byte *)(param_5 + uVar6);

      pbVar15 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      pbVar14 = (byte *)(uVar6 + param_4);

      pbVar16 = (byte *)((ulonglong)((param_10 + 1) * param_6) + param_3);

      puVar8 = (undefined1 *)((ulonglong)(param_10 * param_9) + param_8);

      puVar7 = (undefined1 *)((ulonglong)((param_10 + 1) * param_9) + param_8);

      if (param_1 != 1) {

        uVar3 = (param_1 - 2U >> 1) + 1;

        uVar6 = (ulonglong)uVar3;

        iVar5 = uVar3 * 2;

        do {

          iVar11 = (int)*(short *)(&DAT_1403582b4 + lVar12 * 4) * (*pbVar10 - 0x80);

          iVar13 = (int)*(short *)(&DAT_1403582ba + lVar12 * 4) * (*pbVar14 - 0x80);

          iVar9 = (int)*(short *)(&DAT_1403582b8 + lVar12 * 4) * (*pbVar10 - 0x80) +

                  (int)*(short *)(&DAT_1403582b6 + lVar12 * 4) * (*pbVar14 - 0x80);

          iVar4 = ((uint)*pbVar15 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

          uVar2 = FUN_140230cc0(iVar4 + iVar11,iVar4,iVar9);

          *puVar8 = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar9);

          puVar8[1] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar13);

          puVar8[2] = uVar2;

          iVar4 = ((uint)pbVar15[1] - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

          uVar2 = FUN_140230cc0(iVar4 + iVar11);

          puVar8[3] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar9);

          puVar8[4] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar13);

          puVar8[5] = uVar2;

          puVar8 = puVar8 + 6;

          iVar4 = ((uint)*pbVar16 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

          uVar2 = FUN_140230cc0(iVar4 + iVar11);

          *puVar7 = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar9);

          puVar7[1] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar13);

          puVar7[2] = uVar2;

          iVar4 = ((uint)pbVar16[1] - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

          uVar2 = FUN_140230cc0(iVar4 + iVar11);

          puVar7[3] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar9);

          puVar7[4] = uVar2;

          uVar2 = FUN_140230cc0(iVar4 + iVar13);

          puVar7[5] = uVar2;

          pbVar15 = pbVar15 + 2;

          puVar7 = puVar7 + 6;

          pbVar16 = pbVar16 + 2;

          pbVar14 = pbVar14 + 2;

          pbVar10 = pbVar10 + 2;

          uVar6 = uVar6 - 1;

        } while (uVar6 != 0);

      }

      if (iVar5 == param_1 + -1) {

        iVar9 = (int)*(short *)(&DAT_1403582b4 + lVar12 * 4) * (*pbVar10 - 0x80);

        iVar11 = (int)*(short *)(&DAT_1403582ba + lVar12 * 4) * (*pbVar14 - 0x80);

        iVar4 = (int)*(short *)(&DAT_1403582b8 + lVar12 * 4) * (*pbVar10 - 0x80) +

                (int)*(short *)(&DAT_1403582b6 + lVar12 * 4) * (*pbVar14 - 0x80);

        iVar5 = ((uint)*pbVar15 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

        uVar2 = FUN_140230cc0(iVar9 + iVar5,iVar5,iVar4);

        *puVar8 = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + iVar5);

        puVar8[1] = uVar2;

        uVar2 = FUN_140230cc0(iVar11 + iVar5);

        puVar8[2] = uVar2;

        iVar5 = ((uint)*pbVar16 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

        uVar2 = FUN_140230cc0(iVar9 + iVar5);

        *puVar7 = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + iVar5);

        puVar7[1] = uVar2;

        uVar2 = FUN_140230cc0(iVar11 + iVar5);

        puVar7[2] = uVar2;

      }

      uVar3 = param_10 + 2;

      param_10 = uVar3;

    } while (uVar3 < param_2 - 1U);

  }

  iVar5 = 0;

  if (uVar3 == param_2 - 1U) {

    uVar6 = (ulonglong)((uVar3 >> 1) * param_7);

    pbVar10 = (byte *)((ulonglong)(uVar3 * param_6) + param_3);

    puVar7 = (undefined1 *)((ulonglong)(uVar3 * param_9) + param_8);

    pbVar14 = (byte *)(uVar6 + param_4);

    pbVar15 = (byte *)(param_5 + uVar6);

    if (param_1 != 1) {

      uVar3 = (param_1 - 2U >> 1) + 1;

      uVar6 = (ulonglong)uVar3;

      iVar5 = uVar3 * 2;

      do {

        iVar9 = *pbVar14 - 0x80;

        sVar1 = *(short *)(&DAT_1403582ba + lVar12 * 4);

        iVar13 = (int)*(short *)(&DAT_1403582b4 + lVar12 * 4) * (*pbVar15 - 0x80);

        iVar11 = *(short *)(&DAT_1403582b6 + lVar12 * 4) * iVar9 +

                 (int)*(short *)(&DAT_1403582b8 + lVar12 * 4) * (*pbVar15 - 0x80);

        iVar4 = ((uint)*pbVar10 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

        uVar2 = FUN_140230cc0(iVar4 + iVar13,iVar4,iVar9,iVar11);

        *puVar7 = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + iVar11);

        puVar7[1] = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + sVar1 * iVar9);

        puVar7[2] = uVar2;

        iVar4 = ((uint)pbVar10[1] - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

        uVar2 = FUN_140230cc0(iVar4 + iVar13);

        puVar7[3] = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + iVar11);

        puVar7[4] = uVar2;

        uVar2 = FUN_140230cc0(iVar4 + sVar1 * iVar9);

        puVar7[5] = uVar2;

        pbVar10 = pbVar10 + 2;

        puVar7 = puVar7 + 6;

        pbVar14 = pbVar14 + 2;

        pbVar15 = pbVar15 + 2;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (iVar5 == param_1 + -1) {

      iVar4 = *pbVar15 - 0x80;

      iVar11 = (int)*(short *)(&DAT_1403582ba + lVar12 * 4) * (*pbVar14 - 0x80);

      iVar9 = *(short *)(&DAT_1403582b8 + lVar12 * 4) * iVar4 +

              (int)*(short *)(&DAT_1403582b6 + lVar12 * 4) * (*pbVar14 - 0x80);

      iVar5 = ((uint)*pbVar10 - (uint)(byte)(&DAT_1403582b0)[lVar12 * 4]) *

              (int)*(short *)(&DAT_1403582b2 + lVar12 * 4);

      uVar2 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar12 * 4) * iVar4 + iVar5,iVar5,iVar4,

                            iVar9);

      *puVar7 = uVar2;

      uVar2 = FUN_140230cc0(iVar5 + iVar9);

      puVar7[1] = uVar2;

      uVar2 = FUN_140230cc0(iVar5 + iVar11);

      puVar7[2] = uVar2;

    }

  }

  return;

}





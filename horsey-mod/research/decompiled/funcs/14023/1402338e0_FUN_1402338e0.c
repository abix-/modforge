// Address: 0x1402338e0
// Ghidra name: FUN_1402338e0
// ============ 0x1402338e0 FUN_1402338e0 (size=535) ============


void FUN_1402338e0(int param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,int param_10)



{

  longlong lVar1;

  byte *pbVar2;

  undefined1 uVar3;

  uint uVar4;

  undefined1 *puVar5;

  byte *pbVar6;

  byte *pbVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  ulonglong uVar14;

  byte *pbVar15;

  

  if (param_2 != 0) {

    uVar8 = 0;

    lVar1 = (longlong)param_10 * 0xc;

    pbVar2 = &DAT_1403582b0 + lVar1;

    do {

      iVar10 = 0;

      pbVar15 = (byte *)(param_5 + (ulonglong)(uVar8 * param_7));

      pbVar7 = (byte *)((ulonglong)(uVar8 * param_6) + param_3);

      puVar5 = (undefined1 *)((ulonglong)(uVar8 * param_9) + param_8);

      pbVar6 = (byte *)((ulonglong)(uVar8 * param_7) + param_4);

      if (param_1 != 1) {

        uVar4 = (param_1 - 2U >> 1) + 1;

        uVar14 = (ulonglong)uVar4;

        iVar10 = uVar4 * 2;

        do {

          iVar12 = (int)*(short *)(&DAT_1403582b4 + lVar1) * (*pbVar15 - 0x80);

          iVar13 = (int)*(short *)(&DAT_1403582ba + lVar1) * (*pbVar6 - 0x80);

          iVar11 = (int)*(short *)(&DAT_1403582b8 + lVar1) * (*pbVar15 - 0x80) +

                   (int)*(short *)(&DAT_1403582b6 + lVar1) * (*pbVar6 - 0x80);

          iVar9 = ((uint)*pbVar7 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          uVar3 = FUN_140230cc0(iVar9 + iVar12,puVar5,iVar9,iVar11);

          *puVar5 = uVar3;

          uVar3 = FUN_140230cc0(iVar9 + iVar11);

          puVar5[1] = uVar3;

          uVar3 = FUN_140230cc0(iVar9 + iVar13);

          puVar5[2] = uVar3;

          iVar9 = ((uint)pbVar7[2] - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          uVar3 = FUN_140230cc0(iVar9 + iVar12);

          puVar5[3] = uVar3;

          uVar3 = FUN_140230cc0(iVar9 + iVar11);

          puVar5[4] = uVar3;

          uVar3 = FUN_140230cc0(iVar9 + iVar13);

          puVar5[5] = uVar3;

          pbVar7 = pbVar7 + 4;

          puVar5 = puVar5 + 6;

          pbVar6 = pbVar6 + 4;

          pbVar15 = pbVar15 + 4;

          uVar14 = uVar14 - 1;

        } while (uVar14 != 0);

      }

      if (iVar10 == param_1 + -1) {

        iVar11 = (int)*(short *)(&DAT_1403582ba + lVar1) * (*pbVar6 - 0x80);

        iVar9 = (int)*(short *)(&DAT_1403582b8 + lVar1) * (*pbVar15 - 0x80) +

                (int)*(short *)(&DAT_1403582b6 + lVar1) * (*pbVar6 - 0x80);

        iVar10 = ((uint)*pbVar7 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

        uVar3 = FUN_140230cc0((int)*(short *)(&DAT_1403582b4 + lVar1) * (*pbVar15 - 0x80) + iVar10);

        *puVar5 = uVar3;

        uVar3 = FUN_140230cc0(iVar9 + iVar10);

        puVar5[1] = uVar3;

        uVar3 = FUN_140230cc0(iVar11 + iVar10);

        puVar5[2] = uVar3;

      }

      uVar8 = uVar8 + 1;

    } while (uVar8 < param_2);

  }

  return;

}





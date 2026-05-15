// Address: 0x140233380
// Ghidra name: FUN_140233380
// ============ 0x140233380 FUN_140233380 (size=683) ============


void FUN_140233380(int param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  byte *pbVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  int iVar9;

  byte *pbVar10;

  byte *pbVar11;

  uint *puVar12;

  ulonglong uVar13;

  

  if (param_2 != 0) {

    lVar8 = (longlong)(int)param_10 * 3;

    param_10 = 0;

    do {

      pbVar5 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      pbVar11 = (byte *)(param_5 + (ulonglong)(param_10 * param_7));

      puVar12 = (uint *)((ulonglong)(param_10 * param_9) + param_8);

      pbVar10 = (byte *)((ulonglong)(param_10 * param_7) + param_4);

      iVar2 = 0;

      if (param_1 != 1) {

        uVar3 = (param_1 - 2U >> 1) + 1;

        uVar13 = (ulonglong)uVar3;

        iVar2 = uVar3 * 2;

        do {

          iVar4 = (int)*(short *)(&DAT_1403582b4 + lVar8 * 4) * (*pbVar11 - 0x80);

          iVar6 = (int)*(short *)(&DAT_1403582ba + lVar8 * 4) * (*pbVar10 - 0x80);

          iVar9 = (int)*(short *)(&DAT_1403582b6 + lVar8 * 4) * (*pbVar10 - 0x80) +

                  (int)*(short *)(&DAT_1403582b8 + lVar8 * 4) * (*pbVar11 - 0x80);

          iVar7 = ((uint)*pbVar5 - (uint)(byte)(&DAT_1403582b0)[lVar8 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar8 * 4);

          bVar1 = FUN_140230cc0(iVar7 + iVar4);

          uVar3 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar7 + iVar9);

          uVar3 = (uVar3 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar7 + iVar6);

          *puVar12 = uVar3 | bVar1;

          iVar7 = ((uint)pbVar5[2] - (uint)(byte)(&DAT_1403582b0)[lVar8 * 4]) *

                  (int)*(short *)(&DAT_1403582b2 + lVar8 * 4);

          bVar1 = FUN_140230cc0(iVar7 + iVar4);

          uVar3 = (bVar1 | 0xffffff00) << 8;

          bVar1 = FUN_140230cc0(iVar7 + iVar9);

          uVar3 = (uVar3 | bVar1) << 8;

          bVar1 = FUN_140230cc0(iVar7 + iVar6);

          pbVar5 = pbVar5 + 4;

          pbVar10 = pbVar10 + 4;

          puVar12[1] = uVar3 | bVar1;

          pbVar11 = pbVar11 + 4;

          puVar12 = puVar12 + 2;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

      }

      if (iVar2 == param_1 + -1) {

        iVar2 = *pbVar11 - 0x80;

        iVar4 = ((uint)*pbVar5 - (uint)(byte)(&DAT_1403582b0)[lVar8 * 4]) *

                (int)*(short *)(&DAT_1403582b2 + lVar8 * 4);

        iVar6 = *pbVar10 - 0x80;

        bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b6 + lVar8 * 4) * iVar6 +

                              *(short *)(&DAT_1403582b8 + lVar8 * 4) * iVar2 + iVar4);

        uVar3 = (uint)bVar1;

        bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar8 * 4) * iVar2 + iVar4);

        uVar3 = (uVar3 | (bVar1 | 0xffffff00) << 8) << 8;

        bVar1 = FUN_140230cc0(*(short *)(&DAT_1403582ba + lVar8 * 4) * iVar6 + iVar4);

        *puVar12 = uVar3 | bVar1;

      }

      param_10 = param_10 + 1;

    } while (param_10 < param_2);

  }

  return;

}





// Address: 0x140233da0
// Ghidra name: FUN_140233da0
// ============ 0x140233da0 FUN_140233da0 (size=669) ============


void FUN_140233da0(int param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  longlong lVar1;

  byte *pbVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  byte *pbVar8;

  int iVar9;

  int iVar10;

  ulonglong uVar11;

  int iVar12;

  byte *pbVar13;

  uint *puVar14;

  

  if (param_2 != 0) {

    lVar1 = (longlong)(int)param_10 * 0xc;

    pbVar2 = &DAT_1403582b0 + lVar1;

    param_10 = 0;

    do {

      iVar5 = 0;

      pbVar6 = (byte *)(param_5 + (ulonglong)(param_10 * param_7));

      pbVar8 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      puVar14 = (uint *)((ulonglong)(param_10 * param_9) + param_8);

      pbVar13 = (byte *)((ulonglong)(param_10 * param_7) + param_4);

      if (param_1 != 1) {

        uVar4 = (param_1 - 2U >> 1) + 1;

        uVar11 = (ulonglong)uVar4;

        iVar5 = uVar4 * 2;

        do {

          iVar9 = (int)*(short *)(&DAT_1403582ba + lVar1) * (*pbVar13 - 0x80);

          iVar7 = (int)*(short *)(&DAT_1403582b4 + lVar1) * (*pbVar6 - 0x80);

          iVar12 = (int)*(short *)(&DAT_1403582b6 + lVar1) * (*pbVar13 - 0x80) +

                   (int)*(short *)(&DAT_1403582b8 + lVar1) * (*pbVar6 - 0x80);

          iVar10 = ((uint)*pbVar8 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          bVar3 = FUN_140230cc0(iVar10 + iVar7);

          uVar4 = (uint)bVar3 << 8;

          bVar3 = FUN_140230cc0(iVar10 + iVar12);

          uVar4 = (uVar4 | bVar3) << 8;

          bVar3 = FUN_140230cc0(iVar10 + iVar9);

          *puVar14 = (uVar4 | bVar3) << 8 | 0xff;

          iVar10 = ((uint)pbVar8[2] - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          bVar3 = FUN_140230cc0(iVar10 + iVar7);

          uVar4 = (uint)bVar3 << 8;

          bVar3 = FUN_140230cc0(iVar10 + iVar12);

          uVar4 = (uVar4 | bVar3) << 8;

          bVar3 = FUN_140230cc0(iVar10 + iVar9);

          pbVar8 = pbVar8 + 4;

          pbVar13 = pbVar13 + 4;

          pbVar6 = pbVar6 + 4;

          puVar14[1] = (uVar4 | bVar3) << 8 | 0xff;

          puVar14 = puVar14 + 2;

          uVar11 = uVar11 - 1;

        } while (uVar11 != 0);

      }

      if (iVar5 == param_1 + -1) {

        iVar5 = *pbVar6 - 0x80;

        iVar7 = ((uint)*pbVar8 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

        iVar9 = *pbVar13 - 0x80;

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582b6 + lVar1) * iVar9 +

                              *(short *)(&DAT_1403582b8 + lVar1) * iVar5 + iVar7);

        uVar4 = (uint)bVar3;

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar1) * iVar5 + iVar7);

        uVar4 = (uVar4 | (uint)bVar3 << 8) << 8;

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582ba + lVar1) * iVar9 + iVar7);

        *puVar14 = (uVar4 | bVar3) << 8 | 0xff;

      }

      param_10 = param_10 + 1;

    } while (param_10 < param_2);

  }

  return;

}





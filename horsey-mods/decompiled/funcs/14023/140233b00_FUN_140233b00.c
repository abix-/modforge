// Address: 0x140233b00
// Ghidra name: FUN_140233b00
// ============ 0x140233b00 FUN_140233b00 (size=669) ============


void FUN_140233b00(int param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5,

                  int param_6,int param_7,longlong param_8,int param_9,uint param_10)



{

  longlong lVar1;

  byte *pbVar2;

  byte bVar3;

  uint uVar4;

  ushort uVar5;

  int iVar6;

  int iVar7;

  byte *pbVar8;

  ushort *puVar9;

  int iVar10;

  int iVar11;

  undefined8 uVar12;

  int iVar13;

  byte *pbVar14;

  byte *pbVar15;

  ulonglong uVar16;

  

  if (param_2 != 0) {

    lVar1 = (longlong)(int)param_10 * 0xc;

    pbVar2 = &DAT_1403582b0 + lVar1;

    param_10 = 0;

    do {

      iVar6 = 0;

      pbVar15 = (byte *)(param_5 + (ulonglong)(param_10 * param_7));

      pbVar8 = (byte *)((ulonglong)(param_10 * param_6) + param_3);

      puVar9 = (ushort *)((ulonglong)(param_10 * param_9) + param_8);

      pbVar14 = (byte *)((ulonglong)(param_10 * param_7) + param_4);

      if (param_1 != 1) {

        uVar12 = 0xfff8;

        uVar4 = (param_1 - 2U >> 1) + 1;

        uVar16 = (ulonglong)uVar4;

        iVar6 = uVar4 * 2;

        do {

          iVar7 = (int)*(short *)(&DAT_1403582ba + lVar1) * (*pbVar14 - 0x80);

          iVar11 = (int)*(short *)(&DAT_1403582b4 + lVar1) * (*pbVar15 - 0x80);

          iVar13 = (int)*(short *)(&DAT_1403582b6 + lVar1) * (*pbVar14 - 0x80) +

                   (int)*(short *)(&DAT_1403582b8 + lVar1) * (*pbVar15 - 0x80);

          iVar10 = ((uint)*pbVar8 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          bVar3 = FUN_140230cc0(iVar10 + iVar11);

          uVar5 = ((ushort)bVar3 & (ushort)uVar12) << 5;

          bVar3 = FUN_140230cc0(iVar10 + iVar13);

          uVar5 = (uVar5 | bVar3 & 0xfc) << 3;

          bVar3 = FUN_140230cc0(iVar10 + iVar7);

          *puVar9 = uVar5 | bVar3 >> 3;

          iVar10 = ((uint)pbVar8[2] - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

          bVar3 = FUN_140230cc0(iVar10 + iVar11);

          uVar5 = ((ushort)bVar3 & (ushort)uVar12) << 5;

          bVar3 = FUN_140230cc0(iVar10 + iVar13);

          uVar5 = (uVar5 | bVar3 & 0xfc) << 3;

          bVar3 = FUN_140230cc0(iVar10 + iVar7);

          pbVar8 = pbVar8 + 4;

          pbVar14 = pbVar14 + 4;

          pbVar15 = pbVar15 + 4;

          puVar9[1] = uVar5 | bVar3 >> 3;

          puVar9 = puVar9 + 2;

          uVar16 = uVar16 - 1;

        } while (uVar16 != 0);

      }

      if (iVar6 == param_1 + -1) {

        iVar6 = *pbVar15 - 0x80;

        iVar7 = ((uint)*pbVar8 - (uint)*pbVar2) * (int)*(short *)(&DAT_1403582b2 + lVar1);

        iVar10 = *pbVar14 - 0x80;

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582b6 + lVar1) * iVar10 +

                              *(short *)(&DAT_1403582b8 + lVar1) * iVar6 + iVar7);

        uVar5 = (ushort)(bVar3 & 0xfc);

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582b4 + lVar1) * iVar6 + iVar7);

        uVar5 = (uVar5 | (bVar3 & 0xfff8) << 5) << 3;

        bVar3 = FUN_140230cc0(*(short *)(&DAT_1403582ba + lVar1) * iVar10 + iVar7);

        *puVar9 = uVar5 | bVar3 >> 3;

      }

      param_10 = param_10 + 1;

    } while (param_10 < param_2);

  }

  return;

}





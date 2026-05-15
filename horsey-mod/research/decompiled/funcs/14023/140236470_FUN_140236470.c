// Address: 0x140236470
// Ghidra name: FUN_140236470
// ============ 0x140236470 FUN_140236470 (size=1695) ============


void FUN_140236470(int param_1,int param_2,longlong param_3,longlong param_4,longlong param_5,

                  uint param_6,uint param_7,longlong param_8,int param_9,uint param_10)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  ushort *puVar5;

  ulonglong uVar6;

  int iVar7;

  int iVar8;

  ushort *puVar9;

  longlong lVar10;

  int iVar11;

  ushort *puVar12;

  uint *puVar13;

  uint *puVar14;

  ushort *local_60;

  ulonglong local_58;

  

  uVar2 = 0;

  lVar10 = (longlong)(int)param_10 * 3;

  param_6 = param_6 >> 1;

  param_10 = 0;

  if (param_2 != 1) {

    do {

      iVar3 = 0;

      puVar13 = (uint *)((ulonglong)(param_10 * param_9) + param_8);

      puVar12 = (ushort *)(param_3 + (ulonglong)(param_10 * param_6) * 2);

      uVar6 = (ulonglong)((param_10 >> 1) * (param_7 >> 1));

      puVar5 = (ushort *)(param_4 + uVar6 * 2);

      puVar9 = (ushort *)(param_5 + uVar6 * 2);

      puVar14 = (uint *)((ulonglong)((param_10 + 1) * param_9) + param_8);

      local_60 = (ushort *)(param_3 + (ulonglong)((param_10 + 1) * param_6) * 2);

      if (param_1 != 1) {

        uVar2 = (param_1 - 2U >> 1) + 1;

        local_58 = (ulonglong)uVar2;

        iVar3 = uVar2 * 2;

        do {

          iVar8 = (*puVar5 >> 6) - 0x200;

          iVar4 = (*puVar9 >> 6) - 0x200;

          iVar11 = *(short *)(&DAT_1403582ba + lVar10 * 4) * iVar8;

          iVar7 = *(short *)(&DAT_1403582b4 + lVar10 * 4) * iVar4;

          iVar4 = *(short *)(&DAT_1403582b6 + lVar10 * 4) * iVar8 +

                  *(short *)(&DAT_1403582b8 + lVar10 * 4) * iVar4;

          iVar8 = ((int)((uint)*puVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          uVar1 = FUN_140230ca0(iVar11 + iVar8);

          uVar2 = (uVar1 | 0xfffffc00) << 10;

          uVar1 = FUN_140230ca0(iVar4 + iVar8);

          uVar2 = (uVar2 | uVar1) << 10;

          uVar1 = FUN_140230ca0(iVar7 + iVar8);

          *puVar13 = uVar2 | uVar1;

          iVar8 = ((int)((uint)puVar12[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          uVar1 = FUN_140230ca0(iVar11 + iVar8);

          uVar2 = (uVar1 | 0xfffffc00) << 10;

          uVar1 = FUN_140230ca0(iVar4 + iVar8);

          uVar2 = (uVar2 | uVar1) << 10;

          uVar1 = FUN_140230ca0(iVar7 + iVar8);

          puVar13[1] = uVar2 | uVar1;

          puVar13 = puVar13 + 2;

          iVar8 = ((int)((uint)*local_60 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          uVar1 = FUN_140230ca0(iVar11 + iVar8);

          uVar2 = (uVar1 | 0xfffffc00) << 10;

          uVar1 = FUN_140230ca0(iVar4 + iVar8);

          uVar2 = (uVar2 | uVar1) << 10;

          uVar1 = FUN_140230ca0(iVar7 + iVar8);

          *puVar14 = uVar2 | uVar1;

          iVar8 = ((int)((uint)local_60[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                  (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

          uVar1 = FUN_140230ca0(iVar11 + iVar8);

          uVar2 = (uVar1 | 0xfffffc00) << 10;

          uVar1 = FUN_140230ca0(iVar4 + iVar8);

          uVar2 = (uVar2 | uVar1) << 10;

          uVar1 = FUN_140230ca0(iVar7 + iVar8);

          puVar12 = puVar12 + 2;

          local_60 = local_60 + 2;

          puVar14[1] = uVar2 | uVar1;

          puVar5 = puVar5 + 2;

          puVar14 = puVar14 + 2;

          puVar9 = puVar9 + 2;

          local_58 = local_58 - 1;

        } while (local_58 != 0);

      }

      if (iVar3 == param_1 + -1) {

        iVar3 = (*puVar9 >> 6) - 0x200;

        iVar4 = (*puVar5 >> 6) - 0x200;

        iVar7 = *(short *)(&DAT_1403582b4 + lVar10 * 4) * iVar3;

        iVar8 = *(short *)(&DAT_1403582ba + lVar10 * 4) * iVar4;

        iVar3 = *(short *)(&DAT_1403582b8 + lVar10 * 4) * iVar3 +

                *(short *)(&DAT_1403582b6 + lVar10 * 4) * iVar4;

        iVar4 = ((int)((uint)*puVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        uVar1 = FUN_140230ca0(iVar8 + iVar4);

        uVar2 = (uVar1 | 0xfffffc00) << 10;

        uVar1 = FUN_140230ca0(iVar3 + iVar4);

        uVar2 = (uVar2 | uVar1) << 10;

        uVar1 = FUN_140230ca0(iVar7 + iVar4);

        *puVar13 = uVar2 | uVar1;

        iVar4 = ((int)((uint)*local_60 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        uVar1 = FUN_140230ca0(iVar8 + iVar4);

        uVar2 = (uVar1 | 0xfffffc00) << 10;

        uVar1 = FUN_140230ca0(iVar3 + iVar4);

        uVar2 = (uVar2 | uVar1) << 10;

        uVar1 = FUN_140230ca0(iVar7 + iVar4);

        *puVar14 = uVar2 | uVar1;

      }

      uVar2 = param_10 + 2;

      param_10 = uVar2;

    } while (uVar2 < param_2 - 1U);

  }

  if (uVar2 == param_2 - 1U) {

    puVar12 = (ushort *)(param_3 + (ulonglong)(uVar2 * param_6) * 2);

    uVar6 = (ulonglong)((uVar2 >> 1) * (param_7 >> 1));

    puVar13 = (uint *)((ulonglong)(uVar2 * param_9) + param_8);

    puVar5 = (ushort *)(param_4 + uVar6 * 2);

    puVar9 = (ushort *)(param_5 + uVar6 * 2);

    if (param_1 == 1) {

      iVar3 = 0;

    }

    else {

      uVar2 = (param_1 - 2U >> 1) + 1;

      uVar6 = (ulonglong)uVar2;

      iVar3 = uVar2 * 2;

      do {

        iVar8 = (*puVar5 >> 6) - 0x200;

        iVar4 = (*puVar9 >> 6) - 0x200;

        iVar11 = *(short *)(&DAT_1403582ba + lVar10 * 4) * iVar8;

        iVar7 = *(short *)(&DAT_1403582b4 + lVar10 * 4) * iVar4;

        iVar4 = *(short *)(&DAT_1403582b6 + lVar10 * 4) * iVar8 +

                *(short *)(&DAT_1403582b8 + lVar10 * 4) * iVar4;

        iVar8 = ((int)((uint)*puVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        uVar1 = FUN_140230ca0(iVar8 + iVar11);

        uVar2 = (uVar1 | 0xfffffc00) << 10;

        uVar1 = FUN_140230ca0(iVar8 + iVar4);

        uVar2 = (uVar2 | uVar1) << 10;

        uVar1 = FUN_140230ca0(iVar8 + iVar7);

        *puVar13 = uVar2 | uVar1;

        iVar8 = ((int)((uint)puVar12[1] - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

                (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

        uVar1 = FUN_140230ca0(iVar8 + iVar11);

        uVar2 = (uVar1 | 0xfffffc00) << 10;

        uVar1 = FUN_140230ca0(iVar8 + iVar4);

        uVar2 = (uVar2 | uVar1) << 10;

        uVar1 = FUN_140230ca0(iVar8 + iVar7);

        puVar12 = puVar12 + 2;

        puVar5 = puVar5 + 2;

        puVar13[1] = uVar2 | uVar1;

        puVar9 = puVar9 + 2;

        puVar13 = puVar13 + 2;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (iVar3 == param_1 + -1) {

      iVar7 = ((int)((uint)*puVar12 - (uint)(byte)(&DAT_1403582b0)[lVar10 * 4]) >> 6) *

              (int)*(short *)(&DAT_1403582b2 + lVar10 * 4);

      iVar4 = (*puVar9 >> 6) - 0x200;

      iVar3 = (*puVar5 >> 6) - 0x200;

      uVar1 = FUN_140230ca0(*(short *)(&DAT_1403582b6 + lVar10 * 4) * iVar3 +

                            *(short *)(&DAT_1403582b8 + lVar10 * 4) * iVar4 + iVar7);

      uVar2 = (uint)uVar1;

      uVar1 = FUN_140230ca0(*(short *)(&DAT_1403582ba + lVar10 * 4) * iVar3 + iVar7);

      uVar2 = (uVar2 | (uVar1 | 0xfffffc00) << 10) << 10;

      uVar1 = FUN_140230ca0(*(short *)(&DAT_1403582b4 + lVar10 * 4) * iVar4 + iVar7);

      *puVar13 = uVar2 | uVar1;

    }

  }

  return;

}





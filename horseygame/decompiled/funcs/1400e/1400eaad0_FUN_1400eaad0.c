// Address: 0x1400eaad0
// Ghidra name: FUN_1400eaad0
// ============ 0x1400eaad0 FUN_1400eaad0 (size=1165) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400eaad0(undefined8 *param_1)



{

  byte bVar1;

  undefined1 uVar2;

  ushort uVar3;

  ushort uVar4;

  byte *pbVar5;

  undefined1 *puVar6;

  int *piVar7;

  ulonglong uVar8;

  undefined1 *puVar9;

  longlong lVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  

  do {

    while( true ) {

      iVar14 = *(int *)(param_1 + 2);

      uVar12 = *(uint *)((longlong)param_1 + 0x14);

      if (iVar14 < 0x10) {

        iVar15 = iVar14;

        do {

          pbVar5 = (byte *)*param_1;

          if (pbVar5 < (byte *)param_1[1]) {

            uVar13 = (uint)*pbVar5;

            *param_1 = pbVar5 + 1;

          }

          else {

            uVar13 = 0;

          }

          iVar14 = iVar15 + 8;

          uVar12 = uVar12 | uVar13 << ((byte)iVar15 & 0x1f);

          *(int *)(param_1 + 2) = iVar14;

          *(uint *)((longlong)param_1 + 0x14) = uVar12;

          iVar15 = iVar14;

        } while (iVar14 < 0x19);

      }

      uVar3 = *(ushort *)((longlong)param_1 + (ulonglong)(uVar12 & 0x1ff) * 2 + 0x34);

      uVar8 = (ulonglong)uVar3;

      if (uVar3 < 0xffff) {

        bVar1 = *(byte *)(uVar8 + 0x4b8 + (longlong)param_1);

        uVar12 = uVar12 >> (bVar1 & 0x1f);

        iVar14 = iVar14 - (uint)bVar1;

        *(uint *)((longlong)param_1 + 0x14) = uVar12;

        *(int *)(param_1 + 2) = iVar14;

      }

      else {

        lVar10 = 10;

        uVar12 = (int)uVar12 >> 1 & 0x5555U | (uVar12 & 0x5555) * 2;

        iVar15 = 10;

        uVar12 = uVar12 >> 2 & 0x3333 | (uVar12 & 0x3333) << 2;

        uVar12 = uVar12 >> 4 & 0xf0f | (uVar12 & 0xf0f) << 4;

        uVar13 = (uVar12 & 0xff) << 8 | uVar12 >> 8;

        piVar7 = (int *)((longlong)param_1 + 0x47c);

        if (*piVar7 <= (int)uVar13) {

          do {

            iVar15 = iVar15 + 1;

            piVar7 = piVar7 + 1;

            lVar10 = lVar10 + 1;

          } while (*piVar7 <= (int)uVar13);

          if (iVar15 == 0x10) goto LAB_1400eaf1b;

        }

        uVar3 = *(ushort *)((longlong)param_1 + lVar10 * 2 + 0x434);

        uVar4 = *(ushort *)((longlong)param_1 + lVar10 * 2 + 0x498);

        *(uint *)((longlong)param_1 + 0x14) =

             *(uint *)((longlong)param_1 + 0x14) >> ((byte)iVar15 & 0x1f);

        *(int *)(param_1 + 2) = *(int *)(param_1 + 2) - iVar15;

        iVar14 = *(int *)(param_1 + 2);

        uVar12 = *(uint *)((longlong)param_1 + 0x14);

        uVar8 = (ulonglong)

                (int)((uint)uVar4 + (((int)uVar13 >> (0x10 - (byte)iVar15 & 0x1f)) - (uint)uVar3));

      }

      uVar3 = *(ushort *)((longlong)param_1 + uVar8 * 2 + 0x5d8);

      if (0xff < uVar3) break;

      if (((ulonglong)param_1[5] <= (ulonglong)param_1[3]) &&

         (iVar14 = FUN_1400e8a20(param_1,1), iVar14 == 0)) {

        return 0;

      }

      *(char *)param_1[3] = (char)uVar3;

      param_1[3] = param_1[3] + 1;

    }

    if (uVar3 == 0x100) {

      return 1;

    }

    iVar15 = *(int *)(&DAT_1403dab2c + (ulonglong)uVar3 * 4);

    iVar11 = *(int *)(&DAT_1403daaac + (ulonglong)uVar3 * 4);

    uVar13 = uVar12;

    if (iVar15 != 0) {

      if (iVar14 < iVar15) {

        iVar17 = iVar14;

        do {

          iVar14 = iVar14 + 8;

          pbVar5 = (byte *)*param_1;

          if (pbVar5 < (byte *)param_1[1]) {

            uVar13 = (uint)*pbVar5;

            *param_1 = pbVar5 + 1;

          }

          else {

            uVar13 = 0;

          }

          *(int *)(param_1 + 2) = iVar14;

          uVar12 = uVar12 | uVar13 << ((byte)iVar17 & 0x1f);

          iVar17 = iVar17 + 8;

          *(uint *)((longlong)param_1 + 0x14) = uVar12;

        } while (iVar14 < 0x19);

      }

      uVar13 = uVar12 >> ((byte)iVar15 & 0x1f);

      iVar14 = iVar14 - iVar15;

      *(uint *)((longlong)param_1 + 0x14) = uVar13;

      *(int *)(param_1 + 2) = iVar14;

      iVar11 = iVar11 + ((1 << ((byte)iVar15 & 0x1f)) - 1U & uVar12);

    }

    if (iVar14 < 0x10) {

      iVar15 = iVar14;

      do {

        iVar14 = iVar14 + 8;

        pbVar5 = (byte *)*param_1;

        if (pbVar5 < (byte *)param_1[1]) {

          uVar12 = (uint)*pbVar5;

          *param_1 = pbVar5 + 1;

        }

        else {

          uVar12 = 0;

        }

        *(int *)(param_1 + 2) = iVar14;

        uVar13 = uVar12 << ((byte)iVar15 & 0x1f) | uVar13;

        iVar15 = iVar15 + 8;

        *(uint *)((longlong)param_1 + 0x14) = uVar13;

      } while (iVar14 < 0x19);

    }

    uVar3 = *(ushort *)((longlong)param_1 + (ulonglong)(uVar13 & 0x1ff) * 2 + 0x818);

    uVar8 = (ulonglong)uVar3;

    if (uVar3 < 0xffff) {

      bVar1 = *(byte *)(uVar8 + 0xc9c + (longlong)param_1);

      uVar13 = uVar13 >> (bVar1 & 0x1f);

      iVar14 = iVar14 - (uint)bVar1;

      *(uint *)((longlong)param_1 + 0x14) = uVar13;

      *(int *)(param_1 + 2) = iVar14;

    }

    else {

      lVar10 = 10;

      uVar12 = (int)uVar13 >> 1 & 0x5555U | (uVar13 & 0x5555) * 2;

      iVar15 = 10;

      uVar12 = uVar12 >> 2 & 0x3333 | (uVar12 & 0x3333) << 2;

      uVar12 = uVar12 >> 4 & 0xf0f | (uVar12 & 0xf0f) << 4;

      uVar12 = (uVar12 & 0xff) << 8 | uVar12 >> 8;

      piVar7 = (int *)(param_1 + 0x18c);

      if (*piVar7 <= (int)uVar12) {

        do {

          iVar15 = iVar15 + 1;

          piVar7 = piVar7 + 1;

          lVar10 = lVar10 + 1;

        } while (*piVar7 <= (int)uVar12);

        if (iVar15 == 0x10) {

LAB_1400eaf1b:

          _DAT_1403f4c40 = "bad huffman code";

          return 0;

        }

      }

      uVar3 = *(ushort *)((longlong)param_1 + lVar10 * 2 + 0xc18);

      uVar4 = *(ushort *)((longlong)param_1 + lVar10 * 2 + 0xc7c);

      *(uint *)((longlong)param_1 + 0x14) =

           *(uint *)((longlong)param_1 + 0x14) >> ((byte)iVar15 & 0x1f);

      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) - iVar15;

      iVar14 = *(int *)(param_1 + 2);

      uVar13 = *(uint *)((longlong)param_1 + 0x14);

      uVar8 = (ulonglong)

              (int)((uint)uVar4 + (((int)uVar12 >> (0x10 - (byte)iVar15 & 0x1f)) - (uint)uVar3));

    }

    uVar8 = (ulonglong)*(ushort *)((longlong)param_1 + uVar8 * 2 + 0xdbc);

    iVar15 = *(int *)(&DAT_1403db030 + uVar8 * 4);

    iVar17 = *(int *)(&DAT_1403dafb0 + uVar8 * 4);

    if (iVar15 != 0) {

      iVar16 = iVar14;

      if (iVar14 < iVar15) {

        do {

          iVar16 = iVar16 + 8;

          pbVar5 = (byte *)*param_1;

          if (pbVar5 < (byte *)param_1[1]) {

            uVar12 = (uint)*pbVar5;

            *param_1 = pbVar5 + 1;

          }

          else {

            uVar12 = 0;

          }

          *(int *)(param_1 + 2) = iVar16;

          uVar13 = uVar12 << ((byte)iVar14 & 0x1f) | uVar13;

          iVar14 = iVar14 + 8;

          *(uint *)((longlong)param_1 + 0x14) = uVar13;

        } while (iVar16 < 0x19);

      }

      *(int *)(param_1 + 2) = iVar16 - iVar15;

      *(uint *)((longlong)param_1 + 0x14) = uVar13 >> ((byte)iVar15 & 0x1f);

      iVar17 = iVar17 + ((1 << ((byte)iVar15 & 0x1f)) - 1U & uVar13);

    }

    if ((longlong)(param_1[3] - param_1[4]) < (longlong)iVar17) {

      _DAT_1403f4c40 = "bad dist";

      return 0;

    }

    if (((ulonglong)param_1[5] < (ulonglong)((longlong)iVar11 + param_1[3])) &&

       (iVar14 = FUN_1400e8a20(param_1,iVar11), iVar14 == 0)) {

      return 0;

    }

    puVar6 = (undefined1 *)param_1[3];

    puVar9 = puVar6 + -(longlong)iVar17;

    for (; iVar11 != 0; iVar11 = iVar11 + -1) {

      uVar2 = *puVar9;

      puVar9 = puVar9 + 1;

      *puVar6 = uVar2;

      param_1[3] = param_1[3] + 1;

      puVar6 = (undefined1 *)param_1[3];

    }

  } while( true );

}





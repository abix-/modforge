// Address: 0x14006d0c0
// Ghidra name: FUN_14006d0c0
// ============ 0x14006d0c0 FUN_14006d0c0 (size=839) ============


void FUN_14006d0c0(int *param_1,int *param_2,longlong param_3,undefined1 param_4)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar9;

  int *piVar10;

  int *piVar11;

  longlong lVar12;

  longlong lVar13;

  bool bVar14;

  bool bVar15;

  int local_res8 [2];

  int *local_48;

  int *local_40;

  

  uVar8 = (longlong)param_2 - (longlong)param_1;

  while( true ) {

    if ((longlong)(uVar8 & 0xfffffffffffffffc) < 0x81) {

      if ((param_1 != param_2) && (piVar10 = param_1 + 1, piVar10 != param_2)) {

        lVar12 = 4;

        do {

          iVar4 = *piVar10;

          lVar13 = (longlong)iVar4;

          iVar5 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar13 * 4);

          iVar3 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)*param_1 * 4);

          bVar15 = SBORROW4(iVar5,iVar3);

          iVar6 = iVar5 - iVar3;

          bVar14 = false;

          if (iVar5 == iVar3) {

            iVar3 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)*param_1 * 4);

            iVar5 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar13 * 4);

            bVar15 = SBORROW4(iVar5,iVar3);

            iVar6 = iVar5 - iVar3;

            bVar14 = iVar5 == iVar3;

          }

          piVar11 = piVar10;

          if (bVar14 || bVar15 != iVar6 < 0) {

            while( true ) {

              iVar5 = piVar11[-1];

              iVar6 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar13 * 4);

              iVar3 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar5 * 4);

              bVar15 = SBORROW4(iVar6,iVar3);

              iVar7 = iVar6 - iVar3;

              bVar14 = false;

              if (iVar6 == iVar3) {

                iVar3 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar5 * 4);

                iVar6 = *(int *)(DAT_1403fb0d8 + (lVar13 + 0xa6) * 4);

                bVar15 = SBORROW4(iVar6,iVar3);

                iVar7 = iVar6 - iVar3;

                bVar14 = iVar6 == iVar3;

              }

              if (bVar14 || bVar15 != iVar7 < 0) break;

              *piVar11 = iVar5;

              piVar11 = piVar11 + -1;

            }

            *piVar11 = iVar4;

          }

          else {

            FUN_1402f8e20((longlong)piVar10 + (4 - lVar12),param_1,lVar12);

            *param_1 = iVar4;

          }

          piVar10 = piVar10 + 1;

          lVar12 = lVar12 + 4;

        } while (piVar10 != param_2);

      }

      return;

    }

    if (param_3 < 1) break;

    FUN_14006cc30(&local_48,param_1,param_2,param_4);

    piVar11 = local_40;

    piVar10 = local_48;

    param_3 = (param_3 >> 1) + (param_3 >> 2);

    if ((longlong)((longlong)local_48 - (longlong)param_1 & 0xfffffffffffffffcU) <

        (longlong)((longlong)param_2 - (longlong)local_40 & 0xfffffffffffffffcU)) {

      FUN_14006d0c0(param_1,local_48,param_3,param_4);

      param_1 = piVar11;

      piVar10 = param_2;

    }

    else {

      FUN_14006d0c0(local_40,param_2,param_3,param_4);

    }

    uVar8 = (longlong)piVar10 - (longlong)param_1;

    param_2 = piVar10;

  }

  uVar8 = (longlong)param_2 - (longlong)param_1 >> 2;

  lVar12 = (longlong)param_2 - (longlong)param_1 >> 3;

  if (0 < lVar12) {

    lVar13 = (longlong)(uVar8 - 1) >> 1;

    do {

      iVar3 = param_1[lVar12 + -1];

      lVar12 = lVar12 + -1;

      lVar1 = lVar12;

      while (lVar1 < lVar13) {

        lVar2 = lVar1 * 2 + 2;

        lVar9 = lVar1 * 2 + 1;

        iVar5 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)param_1[lVar2] * 4);

        iVar4 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)param_1[lVar9] * 4);

        bVar15 = SBORROW4(iVar5,iVar4);

        iVar6 = iVar5 - iVar4;

        bVar14 = false;

        if (iVar5 == iVar4) {

          iVar4 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)param_1[lVar9] * 4);

          iVar5 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)param_1[lVar2] * 4);

          bVar15 = SBORROW4(iVar5,iVar4);

          iVar6 = iVar5 - iVar4;

          bVar14 = iVar5 == iVar4;

        }

        if (bVar14 || bVar15 != iVar6 < 0) {

          lVar9 = lVar2;

        }

        param_1[lVar1] = param_1[lVar9];

        lVar1 = lVar9;

      }

      if ((lVar1 == lVar13) && ((uVar8 & 1) == 0)) {

        param_1[lVar1] = param_1[uVar8 - 1];

        lVar1 = uVar8 - 1;

      }

      while (lVar12 < lVar1) {

        lVar9 = lVar1 + -1 >> 1;

        iVar5 = param_1[lVar9];

        iVar6 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar5 * 4);

        iVar4 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)iVar3 * 4);

        bVar15 = SBORROW4(iVar6,iVar4);

        iVar7 = iVar6 - iVar4;

        bVar14 = false;

        if (iVar6 == iVar4) {

          iVar4 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar3 * 4);

          iVar6 = *(int *)(DAT_1403fb0d8 + 0x298 + (longlong)iVar5 * 4);

          bVar15 = SBORROW4(iVar6,iVar4);

          iVar7 = iVar6 - iVar4;

          bVar14 = iVar6 == iVar4;

        }

        if (bVar14 || bVar15 != iVar7 < 0) break;

        param_1[lVar1] = iVar5;

        lVar1 = lVar9;

      }

      param_1[lVar1] = iVar3;

    } while (0 < lVar12);

  }

  if ((longlong)uVar8 < 2) {

    return;

  }

  param_2 = param_2 + -1;

  do {

    local_res8[0] = *param_2;

    *param_2 = *param_1;

    FUN_14006cfa0(param_1,0,(longlong)param_2 - (longlong)param_1 >> 2,local_res8,param_4);

    param_2 = param_2 + -1;

  } while (7 < (longlong)((4 - (longlong)param_1) + (longlong)param_2 & 0xfffffffffffffffcU));

  return;

}





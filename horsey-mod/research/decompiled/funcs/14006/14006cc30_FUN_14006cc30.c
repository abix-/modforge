// Address: 0x14006cc30
// Ghidra name: FUN_14006cc30
// ============ 0x14006cc30 FUN_14006cc30 (size=873) ============


void FUN_14006cc30(ulonglong *param_1,int *param_2,int *param_3,ulonglong param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  longlong lVar9;

  longlong lVar10;

  int *piVar11;

  int *piVar12;

  int *piVar13;

  bool bVar14;

  bool bVar15;

  

  piVar13 = param_2 + ((longlong)param_3 - (longlong)param_2 >> 3);

  lVar5 = (longlong)param_3 + (-4 - (longlong)param_2) >> 2;

  if (lVar5 < 0x29) {

    piVar8 = param_3 + -1;

    piVar7 = param_2;

  }

  else {

    lVar5 = lVar5 + 1 >> 3;

    FUN_14006cb40(param_2,param_2 + lVar5,param_2 + lVar5 * 2);

    FUN_14006cb40(piVar13 + -lVar5,piVar13,piVar13 + lVar5,param_4 & 0xff);

    piVar8 = param_3 + (-1 - lVar5);

    FUN_14006cb40(param_3 + lVar5 * -2 + -1,piVar8,param_3 + -1,param_4 & 0xff);

    param_4 = param_4 & 0xff;

    piVar7 = param_2 + lVar5;

  }

  FUN_14006cb40(piVar7,piVar13,piVar8,param_4);

  piVar7 = piVar13 + 1;

  if (param_2 < piVar13) {

    iVar6 = *piVar13;

    while( true ) {

      piVar8 = piVar13 + -1;

      lVar10 = (longlong)*piVar8;

      piVar11 = piVar13 + -1;

      lVar5 = (longlong)iVar6;

      iVar6 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar10 * 4);

      iVar1 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar5 * 4);

      bVar15 = SBORROW4(iVar6,iVar1);

      iVar4 = iVar6 - iVar1;

      bVar14 = false;

      if (iVar6 == iVar1) {

        iVar2 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar5 * 4);

        iVar3 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar10 * 4);

        bVar15 = SBORROW4(iVar3,iVar2);

        iVar4 = iVar3 - iVar2;

        bVar14 = iVar3 == iVar2;

      }

      if (!bVar14 && bVar15 == iVar4 < 0) break;

      bVar15 = SBORROW4(iVar1,iVar6);

      iVar4 = iVar1 - iVar6;

      bVar14 = false;

      if (iVar1 == iVar6) {

        iVar6 = *(int *)(DAT_1403fb0d8 + (lVar10 + 0xa6) * 4);

        iVar1 = *(int *)(DAT_1403fb0d8 + (lVar5 + 0xa6) * 4);

        bVar15 = SBORROW4(iVar1,iVar6);

        iVar4 = iVar1 - iVar6;

        bVar14 = iVar1 == iVar6;

      }

      if ((!bVar14 && bVar15 == iVar4 < 0) ||

         (piVar13 = piVar11, iVar6 = *piVar8, piVar11 <= param_2)) break;

    }

  }

  piVar8 = piVar7;

  lVar5 = DAT_1403fb0d8;

  piVar11 = piVar13;

  if (piVar7 < param_3) {

    iVar6 = *(int *)(DAT_1403fb0d8 + 0x2cc + (longlong)*piVar13 * 4);

    lVar10 = DAT_1403fb0d8 + (longlong)*piVar13 * 4;

    while( true ) {

      lVar9 = (longlong)*piVar7;

      iVar1 = *(int *)(DAT_1403fb0d8 + 0x2cc + lVar9 * 4);

      bVar15 = SBORROW4(iVar1,iVar6);

      iVar4 = iVar1 - iVar6;

      bVar14 = false;

      if (iVar1 == iVar6) {

        iVar2 = *(int *)(lVar10 + 0x298);

        iVar3 = *(int *)(DAT_1403fb0d8 + 0x298 + lVar9 * 4);

        bVar15 = SBORROW4(iVar3,iVar2);

        iVar4 = iVar3 - iVar2;

        bVar14 = iVar3 == iVar2;

      }

      piVar8 = piVar7;

      if (!bVar14 && bVar15 == iVar4 < 0) break;

      bVar15 = SBORROW4(iVar6,iVar1);

      iVar4 = iVar6 - iVar1;

      bVar14 = false;

      if (iVar6 == iVar1) {

        iVar1 = *(int *)(DAT_1403fb0d8 + (lVar9 + 0xa6) * 4);

        iVar2 = *(int *)(lVar10 + 0x298);

        bVar15 = SBORROW4(iVar2,iVar1);

        iVar4 = iVar2 - iVar1;

        bVar14 = iVar2 == iVar1;

      }

      if ((!bVar14 && bVar15 == iVar4 < 0) ||

         (piVar7 = piVar7 + 1, piVar8 = piVar7, param_3 <= piVar7)) break;

    }

  }

joined_r0x00014006cdca:

  do {

    piVar12 = piVar11;

    if (param_3 <= piVar7) {

joined_r0x00014006ce49:

      for (; param_2 < piVar11; piVar11 = piVar11 + -1) {

        piVar12 = piVar12 + -1;

        lVar10 = (longlong)*piVar12;

        lVar9 = (longlong)*piVar13;

        iVar6 = *(int *)(lVar5 + 0x2cc + lVar10 * 4);

        iVar1 = *(int *)(lVar5 + 0x2cc + lVar9 * 4);

        bVar15 = SBORROW4(iVar6,iVar1);

        iVar4 = iVar6 - iVar1;

        bVar14 = false;

        if (iVar6 == iVar1) {

          iVar2 = *(int *)(lVar5 + 0x298 + lVar9 * 4);

          iVar3 = *(int *)(lVar5 + 0x298 + lVar10 * 4);

          bVar15 = SBORROW4(iVar3,iVar2);

          iVar4 = iVar3 - iVar2;

          bVar14 = iVar3 == iVar2;

        }

        if (bVar14 || bVar15 != iVar4 < 0) {

          bVar15 = SBORROW4(iVar1,iVar6);

          iVar4 = iVar1 - iVar6;

          bVar14 = false;

          if (iVar1 == iVar6) {

            iVar6 = *(int *)(lVar5 + (lVar10 + 0xa6) * 4);

            iVar1 = *(int *)(lVar5 + (lVar9 + 0xa6) * 4);

            bVar15 = SBORROW4(iVar1,iVar6);

            iVar4 = iVar1 - iVar6;

            bVar14 = iVar1 == iVar6;

          }

          if (!bVar14 && bVar15 == iVar4 < 0) break;

          piVar13 = piVar13 + -1;

          if (piVar13 != piVar12) {

            iVar6 = *piVar13;

            *piVar13 = *piVar12;

            *piVar12 = iVar6;

            lVar5 = DAT_1403fb0d8;

          }

        }

      }

      if (piVar11 == param_2) {

        if (piVar7 == param_3) {

          *param_1 = (ulonglong)piVar13;

          param_1[1] = (ulonglong)piVar8;

          return;

        }

        if (piVar8 != piVar7) {

          iVar6 = *piVar13;

          *piVar13 = *piVar8;

          *piVar8 = iVar6;

        }

        iVar6 = *piVar13;

        *piVar13 = *piVar7;

        piVar13 = piVar13 + 1;

        *piVar7 = iVar6;

        piVar7 = piVar7 + 1;

        piVar8 = piVar8 + 1;

        lVar5 = DAT_1403fb0d8;

      }

      else {

        piVar11 = piVar11 + -1;

        if (piVar7 == param_3) {

          piVar13 = piVar13 + -1;

          if (piVar11 != piVar13) {

            iVar6 = *piVar11;

            *piVar11 = *piVar13;

            *piVar13 = iVar6;

          }

          iVar6 = *piVar13;

          *piVar13 = piVar8[-1];

          piVar8[-1] = iVar6;

          piVar8 = piVar8 + -1;

          lVar5 = DAT_1403fb0d8;

        }

        else {

          iVar6 = *piVar7;

          *piVar7 = *piVar11;

          piVar7 = piVar7 + 1;

          *piVar11 = iVar6;

          lVar5 = DAT_1403fb0d8;

        }

      }

      goto joined_r0x00014006cdca;

    }

    lVar10 = (longlong)*piVar7;

    lVar9 = (longlong)*piVar13;

    iVar6 = *(int *)(lVar5 + 0x2cc + lVar10 * 4);

    iVar1 = *(int *)(lVar5 + 0x2cc + lVar9 * 4);

    bVar15 = SBORROW4(iVar1,iVar6);

    iVar4 = iVar1 - iVar6;

    bVar14 = false;

    if (iVar1 == iVar6) {

      iVar2 = *(int *)(lVar5 + 0x298 + lVar10 * 4);

      iVar3 = *(int *)(lVar5 + 0x298 + lVar9 * 4);

      bVar15 = SBORROW4(iVar3,iVar2);

      iVar4 = iVar3 - iVar2;

      bVar14 = iVar3 == iVar2;

    }

    if (bVar14 || bVar15 != iVar4 < 0) {

      bVar15 = SBORROW4(iVar6,iVar1);

      iVar4 = iVar6 - iVar1;

      bVar14 = false;

      if (iVar6 == iVar1) {

        iVar6 = *(int *)(lVar5 + (lVar9 + 0xa6) * 4);

        iVar1 = *(int *)(lVar5 + (lVar10 + 0xa6) * 4);

        bVar15 = SBORROW4(iVar1,iVar6);

        iVar4 = iVar1 - iVar6;

        bVar14 = iVar1 == iVar6;

      }

      if (!bVar14 && bVar15 == iVar4 < 0) goto joined_r0x00014006ce49;

      if (piVar8 != piVar7) {

        iVar6 = *piVar8;

        *piVar8 = *piVar7;

        *piVar7 = iVar6;

        lVar5 = DAT_1403fb0d8;

      }

      piVar8 = piVar8 + 1;

    }

    piVar7 = piVar7 + 1;

  } while( true );

}





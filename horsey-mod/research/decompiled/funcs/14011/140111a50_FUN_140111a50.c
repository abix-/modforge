// Address: 0x140111a50
// Ghidra name: FUN_140111a50
// ============ 0x140111a50 FUN_140111a50 (size=508) ============


void FUN_140111a50(longlong param_1,longlong param_2,ulonglong param_3,undefined8 *param_4)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  longlong lVar12;

  bool bVar13;

  bool bVar14;

  

  lVar12 = (longlong)(param_3 - 1) >> 1;

  lVar6 = param_2;

  while (lVar6 < lVar12) {

    iVar7 = *(int *)(param_1 + 0x3c + lVar6 * 0x50);

    lVar11 = param_1 + lVar6 * 0x50;

    iVar8 = *(int *)(lVar11 + 100);

    if (iVar8 == iVar7) {

      iVar3 = *(int *)(lVar11 + 0x2c);

      iVar9 = *(int *)(lVar11 + 0x54);

      iVar7 = -iVar3;

      if (-iVar3 < 0) {

        iVar7 = iVar3;

      }

      iVar8 = -iVar9;

      if (-iVar9 < 0) {

        iVar8 = iVar9;

      }

      if (iVar8 != iVar7) goto LAB_140111af4;

      iVar7 = *(int *)(lVar11 + 0x30);

      iVar8 = *(int *)(lVar11 + 0x58);

      iVar4 = -iVar7;

      if (-iVar7 < 0) {

        iVar4 = iVar7;

      }

      iVar10 = -iVar8;

      if (-iVar8 < 0) {

        iVar10 = iVar8;

      }

      bVar14 = SBORROW4(iVar10,iVar4);

      bVar13 = iVar10 - iVar4 < 0;

      if (iVar10 == iVar4) {

        bVar14 = SBORROW4(iVar9,iVar3);

        bVar13 = iVar9 - iVar3 < 0;

        if (iVar9 == iVar3) {

          bVar14 = SBORROW4(iVar8,iVar7);

          bVar13 = iVar8 - iVar7 < 0;

        }

      }

    }

    else {

LAB_140111af4:

      bVar14 = SBORROW4(iVar8,iVar7);

      bVar13 = iVar8 - iVar7 < 0;

    }

    lVar11 = (ulonglong)(bVar14 == bVar13) + 1 + lVar6 * 2;

    puVar1 = (undefined8 *)(param_1 + lVar11 * 0x28);

    uVar5 = puVar1[1];

    puVar2 = (undefined8 *)(param_1 + lVar6 * 0x28);

    *puVar2 = *puVar1;

    puVar2[1] = uVar5;

    puVar1 = (undefined8 *)(param_1 + 0x10 + lVar11 * 0x28);

    uVar5 = puVar1[1];

    puVar2 = (undefined8 *)(param_1 + 0x10 + lVar6 * 0x28);

    *puVar2 = *puVar1;

    puVar2[1] = uVar5;

    *(undefined8 *)(param_1 + 0x20 + lVar6 * 0x28) = *(undefined8 *)(param_1 + 0x20 + lVar11 * 0x28)

    ;

    lVar6 = lVar11;

  }

  lVar11 = lVar6;

  if ((lVar6 == lVar12) && ((param_3 & 1) == 0)) {

    puVar2 = (undefined8 *)(param_1 + -0x28 + param_3 * 0x28);

    uVar5 = puVar2[1];

    lVar11 = param_3 - 1;

    puVar1 = (undefined8 *)(param_1 + lVar6 * 0x28);

    *puVar1 = *puVar2;

    puVar1[1] = uVar5;

    puVar1 = (undefined8 *)(param_1 + -0x18 + param_3 * 0x28);

    uVar5 = puVar1[1];

    puVar2 = (undefined8 *)(param_1 + 0x10 + lVar6 * 0x28);

    *puVar2 = *puVar1;

    puVar2[1] = uVar5;

    *(undefined8 *)(param_1 + 0x20 + lVar6 * 0x28) = *(undefined8 *)(param_1 + -8 + param_3 * 0x28);

  }

  while (param_2 < lVar11) {

    lVar6 = lVar11 + -1 >> 1;

    puVar1 = (undefined8 *)(param_1 + lVar6 * 0x28);

    iVar7 = *(int *)((longlong)param_4 + 0x14);

    iVar8 = *(int *)((longlong)puVar1 + 0x14);

    bVar14 = SBORROW4(iVar8,iVar7);

    bVar13 = iVar8 - iVar7 < 0;

    if (iVar8 == iVar7) {

      iVar7 = *(int *)((longlong)param_4 + 4);

      iVar8 = *(int *)((longlong)puVar1 + 4);

      iVar3 = -iVar7;

      if (-iVar7 < 0) {

        iVar3 = iVar7;

      }

      iVar9 = -iVar8;

      if (-iVar8 < 0) {

        iVar9 = iVar8;

      }

      bVar14 = SBORROW4(iVar9,iVar3);

      bVar13 = iVar9 - iVar3 < 0;

      if (iVar9 == iVar3) {

        iVar3 = *(int *)(param_4 + 1);

        iVar9 = *(int *)(puVar1 + 1);

        iVar4 = -iVar3;

        if (-iVar3 < 0) {

          iVar4 = iVar3;

        }

        iVar10 = -iVar9;

        if (-iVar9 < 0) {

          iVar10 = iVar9;

        }

        bVar14 = SBORROW4(iVar10,iVar4);

        bVar13 = iVar10 - iVar4 < 0;

        if (iVar10 == iVar4) {

          bVar14 = SBORROW4(iVar8,iVar7);

          bVar13 = iVar8 - iVar7 < 0;

          if (iVar8 == iVar7) {

            bVar14 = SBORROW4(iVar9,iVar3);

            bVar13 = iVar9 - iVar3 < 0;

          }

        }

      }

    }

    if (bVar14 == bVar13) break;

    uVar5 = puVar1[1];

    puVar2 = (undefined8 *)(param_1 + lVar11 * 0x28);

    *puVar2 = *puVar1;

    puVar2[1] = uVar5;

    uVar5 = puVar1[3];

    puVar2 = (undefined8 *)(param_1 + 0x10 + lVar11 * 0x28);

    *puVar2 = puVar1[2];

    puVar2[1] = uVar5;

    *(undefined8 *)(param_1 + 0x20 + lVar11 * 0x28) = puVar1[4];

    lVar11 = lVar6;

  }

  uVar5 = param_4[1];

  puVar1 = (undefined8 *)(param_1 + lVar11 * 0x28);

  *puVar1 = *param_4;

  puVar1[1] = uVar5;

  uVar5 = param_4[3];

  puVar1 = (undefined8 *)(param_1 + 0x10 + lVar11 * 0x28);

  *puVar1 = param_4[2];

  puVar1[1] = uVar5;

  *(undefined8 *)(param_1 + 0x20 + lVar11 * 0x28) = param_4[4];

  return;

}





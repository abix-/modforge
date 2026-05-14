// Address: 0x140110bf0
// Ghidra name: FUN_140110bf0
// ============ 0x140110bf0 FUN_140110bf0 (size=625) ============


void FUN_140110bf0(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined8 uVar5;

  int iVar6;

  int iVar7;

  ulonglong uVar8;

  undefined4 uVar9;

  int iVar10;

  int iVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  undefined4 uVar14;

  undefined4 uVar15;

  undefined4 uVar16;

  int iVar17;

  undefined4 uVar18;

  undefined4 uVar19;

  undefined8 uVar20;

  longlong lVar21;

  int iVar22;

  int iVar23;

  int iVar24;

  longlong lVar25;

  int iVar26;

  longlong lVar27;

  longlong lVar28;

  longlong lVar29;

  bool bVar30;

  bool bVar31;

  

  uVar8 = (param_2 - param_1) / 0x28;

  lVar28 = (longlong)uVar8 >> 1;

  if (0 < lVar28) {

    lVar29 = (longlong)(uVar8 - 1) >> 1;

    lVar27 = param_1 + lVar28 * 0x28;

    do {

      uVar9 = *(undefined4 *)(lVar27 + -0x28);

      iVar10 = *(int *)(lVar27 + -0x24);

      iVar11 = *(int *)(lVar27 + -0x20);

      uVar12 = *(undefined4 *)(lVar27 + -0x1c);

      lVar28 = lVar28 + -1;

      uVar5 = *(undefined8 *)(lVar27 + -8);

      uVar16 = *(undefined4 *)(lVar27 + -0x18);

      iVar17 = *(int *)(lVar27 + -0x14);

      uVar18 = *(undefined4 *)(lVar27 + -0x10);

      uVar19 = *(undefined4 *)(lVar27 + -0xc);

      lVar21 = lVar28;

      while (lVar21 < lVar29) {

        iVar24 = *(int *)(param_1 + 0x3c + lVar21 * 0x50);

        lVar25 = param_1 + lVar21 * 0x50;

        iVar26 = *(int *)(lVar25 + 100);

        if (iVar26 == iVar24) {

          iVar22 = *(int *)(lVar25 + 0x2c);

          iVar23 = *(int *)(lVar25 + 0x54);

          iVar24 = -iVar22;

          if (-iVar22 < 0) {

            iVar24 = iVar22;

          }

          iVar26 = -iVar23;

          if (-iVar23 < 0) {

            iVar26 = iVar23;

          }

          if (iVar26 != iVar24) goto LAB_140110cf0;

          iVar24 = *(int *)(lVar25 + 0x30);

          iVar26 = *(int *)(lVar25 + 0x58);

          iVar6 = -iVar24;

          if (-iVar24 < 0) {

            iVar6 = iVar24;

          }

          iVar7 = -iVar26;

          if (-iVar26 < 0) {

            iVar7 = iVar26;

          }

          bVar31 = SBORROW4(iVar7,iVar6);

          bVar30 = iVar7 - iVar6 < 0;

          if (iVar7 == iVar6) {

            bVar31 = SBORROW4(iVar23,iVar22);

            bVar30 = iVar23 - iVar22 < 0;

            if (iVar23 == iVar22) {

              bVar31 = SBORROW4(iVar26,iVar24);

              bVar30 = iVar26 - iVar24 < 0;

            }

          }

        }

        else {

LAB_140110cf0:

          bVar31 = SBORROW4(iVar26,iVar24);

          bVar30 = iVar26 - iVar24 < 0;

        }

        lVar25 = (ulonglong)(bVar31 == bVar30) + 1 + lVar21 * 2;

        puVar1 = (undefined8 *)(param_1 + lVar25 * 0x28);

        uVar20 = puVar1[1];

        puVar2 = (undefined8 *)(param_1 + lVar21 * 0x28);

        *puVar2 = *puVar1;

        puVar2[1] = uVar20;

        puVar3 = (undefined4 *)(param_1 + 0x10 + lVar25 * 0x28);

        uVar13 = puVar3[1];

        uVar14 = puVar3[2];

        uVar15 = puVar3[3];

        puVar4 = (undefined4 *)(param_1 + 0x10 + lVar21 * 0x28);

        *puVar4 = *puVar3;

        puVar4[1] = uVar13;

        puVar4[2] = uVar14;

        puVar4[3] = uVar15;

        puVar3 = (undefined4 *)(param_1 + 0x20 + lVar25 * 0x28);

        uVar13 = puVar3[1];

        puVar4 = (undefined4 *)(param_1 + 0x20 + lVar21 * 0x28);

        *puVar4 = *puVar3;

        puVar4[1] = uVar13;

        lVar21 = lVar25;

      }

      if ((lVar21 == lVar29) && ((uVar8 & 1) == 0)) {

        puVar2 = (undefined8 *)(param_1 + -0x28 + uVar8 * 0x28);

        uVar20 = puVar2[1];

        puVar1 = (undefined8 *)(param_1 + lVar21 * 0x28);

        *puVar1 = *puVar2;

        puVar1[1] = uVar20;

        puVar3 = (undefined4 *)(param_1 + -0x18 + uVar8 * 0x28);

        uVar13 = puVar3[1];

        uVar14 = puVar3[2];

        uVar15 = puVar3[3];

        puVar4 = (undefined4 *)(param_1 + 0x10 + lVar21 * 0x28);

        *puVar4 = *puVar3;

        puVar4[1] = uVar13;

        puVar4[2] = uVar14;

        puVar4[3] = uVar15;

        puVar3 = (undefined4 *)(param_1 + -8 + uVar8 * 0x28);

        uVar13 = puVar3[1];

        puVar4 = (undefined4 *)(param_1 + 0x20 + lVar21 * 0x28);

        *puVar4 = *puVar3;

        puVar4[1] = uVar13;

        lVar21 = uVar8 - 1;

      }

      while (lVar28 < lVar21) {

        lVar25 = lVar21 + -1 >> 1;

        iVar24 = *(int *)(param_1 + 0x14 + lVar25 * 0x28);

        bVar31 = SBORROW4(iVar24,iVar17);

        bVar30 = iVar24 - iVar17 < 0;

        puVar1 = (undefined8 *)(param_1 + lVar25 * 0x28);

        if (iVar24 == iVar17) {

          iVar24 = *(int *)((longlong)puVar1 + 4);

          iVar26 = -iVar10;

          if (-iVar10 < 0) {

            iVar26 = iVar10;

          }

          iVar22 = -iVar24;

          if (-iVar24 < 0) {

            iVar22 = iVar24;

          }

          bVar31 = SBORROW4(iVar22,iVar26);

          bVar30 = iVar22 - iVar26 < 0;

          if (iVar22 == iVar26) {

            iVar26 = *(int *)(puVar1 + 1);

            iVar22 = -iVar11;

            if (-iVar11 < 0) {

              iVar22 = iVar11;

            }

            iVar23 = -iVar26;

            if (-iVar26 < 0) {

              iVar23 = iVar26;

            }

            bVar31 = SBORROW4(iVar23,iVar22);

            bVar30 = iVar23 - iVar22 < 0;

            if (iVar23 == iVar22) {

              bVar31 = SBORROW4(iVar24,iVar10);

              bVar30 = iVar24 - iVar10 < 0;

              if (iVar24 == iVar10) {

                bVar31 = SBORROW4(iVar26,iVar11);

                bVar30 = iVar26 - iVar11 < 0;

              }

            }

          }

        }

        if (bVar31 == bVar30) break;

        uVar20 = puVar1[1];

        puVar2 = (undefined8 *)(param_1 + lVar21 * 0x28);

        *puVar2 = *puVar1;

        puVar2[1] = uVar20;

        uVar13 = *(undefined4 *)((longlong)puVar1 + 0x14);

        uVar14 = *(undefined4 *)(puVar1 + 3);

        uVar15 = *(undefined4 *)((longlong)puVar1 + 0x1c);

        puVar3 = (undefined4 *)(param_1 + 0x10 + lVar21 * 0x28);

        *puVar3 = *(undefined4 *)(puVar1 + 2);

        puVar3[1] = uVar13;

        puVar3[2] = uVar14;

        puVar3[3] = uVar15;

        uVar13 = *(undefined4 *)((longlong)puVar1 + 0x24);

        puVar3 = (undefined4 *)(param_1 + 0x20 + lVar21 * 0x28);

        *puVar3 = *(undefined4 *)(puVar1 + 4);

        puVar3[1] = uVar13;

        lVar21 = lVar25;

      }

      puVar3 = (undefined4 *)(param_1 + lVar21 * 0x28);

      *puVar3 = uVar9;

      puVar3[1] = iVar10;

      puVar3[2] = iVar11;

      puVar3[3] = uVar12;

      puVar3 = (undefined4 *)(param_1 + 0x10 + lVar21 * 0x28);

      *puVar3 = uVar16;

      puVar3[1] = iVar17;

      puVar3[2] = uVar18;

      puVar3[3] = uVar19;

      *(undefined8 *)(param_1 + 0x20 + lVar21 * 0x28) = uVar5;

      lVar27 = lVar27 + -0x28;

    } while (0 < lVar28);

  }

  return;

}





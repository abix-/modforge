// Address: 0x140130440
// Ghidra name: FUN_140130440
// ============ 0x140130440 FUN_140130440 (size=903) ============


void FUN_140130440(longlong param_1,uint *param_2,undefined1 (*param_3) [16])



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined8 *puVar4;

  undefined1 (*pauVar5) [16];

  undefined4 uVar6;

  undefined8 uVar7;

  int iVar8;

  uint *puVar9;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  longlong lVar13;

  int iVar14;

  uint uVar15;

  ulonglong uVar16;

  uint uVar17;

  ulonglong uVar18;

  longlong lVar19;

  float fVar20;

  float fVar21;

  undefined1 auVar22 [16];

  float fVar23;

  float fVar24;

  undefined1 auVar25 [16];

  float fVar26;

  float fVar27;

  

  *(undefined8 *)*param_3 = 0;

  *(undefined8 *)(*param_3 + 8) = 0;

  *(undefined8 *)param_3[1] = 0;

  fVar24 = DAT_14030c670;

  iVar1 = *(int *)(param_1 + 0x38);

  lVar10 = (longlong)iVar1;

  if (iVar1 == 0) {

    if (param_2 != (uint *)0x0) {

      uVar7 = *(undefined8 *)(param_2 + 2);

      *(undefined8 *)*param_3 = *(undefined8 *)param_2;

      *(undefined8 *)(*param_3 + 8) = uVar7;

      *(undefined8 *)param_3[1] = *(undefined8 *)(param_2 + 4);

      return;

    }

  }

  else {

    if (param_2 == (uint *)0x0) {

      puVar4 = *(undefined8 **)(param_1 + 0x30);

      uVar7 = puVar4[1];

      *(undefined8 *)*param_3 = *puVar4;

      *(undefined8 *)(*param_3 + 8) = uVar7;

      *(undefined8 *)param_3[1] = puVar4[2];

      return;

    }

    uVar15 = param_2[2];

    lVar13 = 0;

    if (((int)uVar15 < 1) || (uVar17 = param_2[3], (int)uVar17 < 1)) {

      pauVar5 = *(undefined1 (**) [16])(param_1 + 0x30);

      *param_3 = *pauVar5;

      uVar6 = *(undefined4 *)(pauVar5[1] + 4);

      *(undefined4 *)param_3[1] = *(undefined4 *)pauVar5[1];

      *(undefined4 *)(param_3[1] + 4) = uVar6;

    }

    else {

      iVar14 = 9999999;

      lVar19 = lVar10;

      fVar23 = DAT_140317788;

      fVar27 = DAT_140317790;

      if (0 < iVar1) {

        do {

          iVar2 = *(int *)(lVar13 + 8 + *(longlong *)(param_1 + 0x30));

          iVar3 = *(int *)(lVar13 + 0xc + *(longlong *)(param_1 + 0x30));

          fVar26 = (float)iVar2 / (float)iVar3;

          fVar20 = (float)FUN_140190250((float)(int)uVar15 / (float)(int)uVar17 - fVar26);

          fVar21 = (float)FUN_140190250(fVar27 - fVar26);

          iVar8 = FUN_140190050(iVar2 - uVar15);

          if (fVar24 <= fVar21) {

            if (fVar20 < fVar23) goto LAB_1401305fb;

          }

          else {

            fVar20 = fVar23;

            fVar26 = fVar27;

            if (iVar8 < iVar14) {

LAB_1401305fb:

              *(int *)(*param_3 + 0xc) = iVar3;

              *(int *)(*param_3 + 8) = iVar2;

              fVar23 = fVar20;

              fVar27 = fVar26;

              iVar14 = iVar8;

            }

          }

          lVar13 = lVar13 + 0x18;

          lVar19 = lVar19 + -1;

        } while (lVar19 != 0);

      }

    }

    uVar12 = 0;

    uVar15 = 0;

    uVar17 = uVar15;

    if (0 < iVar1) {

      puVar9 = *(uint **)(param_1 + 0x30);

      uVar11 = uVar12;

      uVar16 = uVar12;

      uVar18 = uVar12;

      do {

        if ((puVar9[2] == *(uint *)(*param_3 + 8)) && (puVar9[3] == *(uint *)(*param_3 + 0xc))) {

          if ((int)uVar16 == 0) {

            uVar16 = (ulonglong)*puVar9;

            uVar18 = (ulonglong)puVar9[1];

          }

          uVar15 = *puVar9;

          if (uVar15 == *param_2) {

            uVar17 = puVar9[1];

            break;

          }

        }

        uVar17 = (uint)uVar18;

        uVar15 = (uint)uVar16;

        uVar11 = uVar11 + 1;

        puVar9 = puVar9 + 6;

      } while ((longlong)uVar11 < lVar10);

    }

    *(uint *)*param_3 = uVar15;

    *(uint *)(*param_3 + 4) = uVar17;

    if (param_2[5] == 0) {

      auVar25 = ZEXT816(0);

    }

    else {

      auVar25 = ZEXT416((uint)((float)(int)param_2[4] / (float)(int)param_2[5]));

    }

    uVar11 = uVar12;

    fVar24 = DAT_14031778c;

    if (0 < iVar1) {

      do {

        lVar13 = *(longlong *)(param_1 + 0x30);

        if (((*(int *)(uVar11 + lVar13) == *(int *)*param_3) &&

            (*(int *)(uVar11 + 8 + lVar13) == *(int *)(*param_3 + 8))) &&

           (*(int *)(uVar11 + 0xc + lVar13) == *(int *)(*param_3 + 0xc))) {

          uVar15 = *(uint *)(uVar11 + 0x10 + lVar13);

          if ((uVar15 == param_2[4]) && (*(uint *)(uVar11 + 0x14 + lVar13) == param_2[5])) {

            *(uint *)param_3[1] = uVar15;

            *(undefined4 *)(param_3[1] + 4) = *(undefined4 *)(uVar11 + 0x14 + lVar13);

            return;

          }

          iVar1 = *(int *)(uVar11 + 0x14 + lVar13);

          if (iVar1 == 0) {

            fVar23 = 0.0;

          }

          else {

            fVar23 = (float)(int)uVar15 / (float)iVar1;

          }

          auVar22._4_12_ = auVar25._4_12_;

          auVar22._0_4_ = auVar25._0_4_ - fVar23;

          fVar23 = (float)FUN_140190250(auVar22._0_8_);

          if (fVar23 < fVar24) {

            *(undefined4 *)param_3[1] = *(undefined4 *)(uVar11 + 0x10 + lVar13);

            *(undefined4 *)(param_3[1] + 4) = *(undefined4 *)(uVar11 + 0x14 + lVar13);

            fVar24 = fVar23;

          }

        }

        uVar12 = uVar12 + 1;

        uVar11 = uVar11 + 0x18;

      } while ((longlong)uVar12 < lVar10);

    }

  }

  return;

}





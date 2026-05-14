// Address: 0x1400bc580
// Ghidra name: FUN_1400bc580
// ============ 0x1400bc580 FUN_1400bc580 (size=1371) ============


void FUN_1400bc580(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  int iVar10;

  float fVar11;

  undefined4 uVar12;

  undefined4 uVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  undefined4 uVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  int local_res8;

  longlong local_a8;

  

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  fVar14 = DAT_14030c2a4;

  fVar20 = DAT_140304c4c;

  fVar19 = DAT_140304c34;

  uVar13 = DAT_1403033a4;

  uVar12 = DAT_140303398;

  iVar10 = 0;

  lVar2 = *(longlong *)(param_1 + 0x48);

  lVar7 = *(longlong *)(param_1 + 0x40);

  lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar2 - lVar7),8) + (lVar2 - lVar7);

  uVar5 = (lVar4 >> 7) - (lVar4 >> 0x3f);

  if (uVar5 != 0) {

    lVar4 = 0;

    do {

      iVar3 = *(int *)(lVar4 + 8 + lVar7);

      uVar17 = uVar12;

      if (iVar3 != 7) {

        if (iVar3 == 1) {

          if (*(int *)(param_1 + 0xc) == 3) {

LAB_1400bc684:

            iVar3 = *(int *)(lVar4 + 100 + lVar7);

            uVar17 = uVar13;

            if ((iVar3 != 1) && (uVar17 = uVar12, iVar3 == 0)) {

              iVar3 = (int)((ulonglong)((longlong)*(int *)(param_1 + 0x10) * -0x77777777) >> 0x20) +

                      *(int *)(param_1 + 0x10);

              uVar5 = (ulonglong)(uint)((iVar3 >> 3) - (iVar3 >> 0x1f));

            }

          }

        }

        else if (((iVar3 == 2) && (*(int *)(param_1 + 0xc) == 3)) &&

                (*(int *)(lVar4 + 0xc + lVar7) == 1)) goto LAB_1400bc684;

      }

      fVar11 = (float)FUN_1400c5c40(*(undefined4 *)(lVar4 + 0x48 + lVar7),uVar5,uVar17);

      *(float *)(lVar4 + 0x48 + lVar7) = fVar11;

      if (fVar19 < fVar11) {

        do {

          fVar11 = fVar11 - fVar20;

        } while (fVar19 < fVar11);

        *(float *)(lVar4 + 0x48 + lVar7) = fVar11;

      }

      if (fVar11 < fVar14) {

        do {

          fVar11 = fVar11 + fVar20;

        } while (fVar11 < fVar14);

        *(float *)(lVar4 + 0x48 + lVar7) = fVar11;

      }

      iVar10 = iVar10 + 1;

      lVar4 = lVar4 + 0xb8;

      lVar2 = *(longlong *)(param_1 + 0x48);

      lVar7 = *(longlong *)(param_1 + 0x40);

      lVar6 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar2 - lVar7),8) + (lVar2 - lVar7);

      uVar5 = (lVar6 >> 7) - (lVar6 >> 0x3f);

    } while ((ulonglong)(longlong)iVar10 < uVar5);

  }

  lVar2 = (lVar2 - lVar7) + SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar2 - lVar7),8);

  uVar5 = (lVar2 >> 7) - (lVar2 >> 0x3f);

  local_a8 = 0;

  if (uVar5 == 0) {

    lVar2 = 0;

  }

  else {

    if (0xfffffffffffffff < uVar5) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    lVar2 = FUN_1400285e0(uVar5 * 0x10);

    local_a8 = lVar2 + uVar5 * 0x10;

  }

  local_res8 = 0;

  lVar7 = *(longlong *)(param_1 + 0x40);

  lVar4 = *(longlong *)(param_1 + 0x48) - lVar7;

  lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

  if (lVar4 >> 7 != lVar4 >> 0x3f) {

    lVar4 = 0;

    lVar6 = 0;

    do {

      iVar10 = *(int *)(lVar6 + 4 + lVar7);

      lVar8 = (longlong)iVar10;

      if (iVar10 < 1) {

        uVar12 = FUN_1400c5f10(*(undefined4 *)(lVar6 + 0x48 + lVar7));

        *(undefined8 *)(lVar2 + lVar4) = *(undefined8 *)(lVar6 + 0x40 + lVar7);

        uVar13 = FUN_1402cdc50();

        *(undefined4 *)(lVar2 + 8 + lVar4) = uVar13;

        uVar12 = FUN_1402cfda0(uVar12);

        *(undefined4 *)(lVar2 + 0xc + lVar4) = uVar12;

      }

      else {

        uVar12 = FUN_1400c5f10(*(undefined4 *)(lVar6 + 0x58 + lVar7));

        fVar14 = (float)FUN_1402cdc50();

        fVar11 = (float)FUN_1402cfda0(uVar12);

        lVar1 = *(longlong *)(param_1 + 0x40);

        fVar19 = *(float *)(lVar1 + 0x50 + lVar6);

        fVar20 = *(float *)(lVar1 + 0x54 + lVar6);

        lVar9 = lVar8 * 0xb8;

        uVar12 = FUN_1400c5f10(*(undefined4 *)(lVar9 + 0x58 + lVar1));

        fVar15 = (float)FUN_1402cdc50();

        fVar16 = (float)FUN_1402cfda0(uVar12);

        fVar21 = fVar16 * fVar14 - fVar15 * fVar11;

        fVar18 = fVar16 * fVar11 + fVar15 * fVar14;

        fVar20 = fVar20 - *(float *)(lVar9 + 0x54 + *(longlong *)(param_1 + 0x40));

        fVar19 = fVar19 - *(float *)(lVar9 + 0x50 + *(longlong *)(param_1 + 0x40));

        fVar11 = fVar19 * fVar16 + fVar20 * fVar15;

        fVar15 = fVar20 * fVar16 - fVar19 * fVar15;

        fVar19 = *(float *)(lVar2 + 0xc + lVar8 * 0x10);

        fVar20 = *(float *)(lVar2 + 8 + lVar8 * 0x10);

        fVar14 = *(float *)(lVar2 + 4 + lVar8 * 0x10);

        *(float *)(lVar2 + lVar4) =

             (fVar19 * fVar11 - fVar20 * fVar15) + *(float *)(lVar2 + lVar8 * 0x10);

        *(float *)(lVar2 + 4 + lVar4) = fVar19 * fVar15 + fVar20 * fVar11 + fVar14;

        *(float *)(lVar2 + 8 + lVar4) = fVar20 * fVar18 + fVar19 * fVar21;

        *(float *)(lVar2 + 0xc + lVar4) = fVar19 * fVar18 - fVar20 * fVar21;

        *(undefined8 *)(lVar6 + 0x40 + lVar7) = *(undefined8 *)(lVar2 + lVar4);

        FUN_1402cd4c0(*(undefined4 *)(lVar2 + 8 + lVar4));

        uVar12 = FUN_1400c5f30();

        *(undefined4 *)(lVar6 + 0x48 + lVar7) = uVar12;

      }

      local_res8 = local_res8 + 1;

      lVar6 = lVar6 + 0xb8;

      lVar4 = lVar4 + 0x10;

      lVar7 = *(longlong *)(param_1 + 0x40);

      lVar8 = *(longlong *)(param_1 + 0x48) - lVar7;

      lVar8 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar8),8) + lVar8;

    } while ((ulonglong)(longlong)local_res8 < (ulonglong)((lVar8 >> 7) - (lVar8 >> 0x3f)));

  }

  if (lVar2 != 0) {

    uVar5 = local_a8 - lVar2 & 0xfffffffffffffff0;

    lVar7 = lVar2;

    if (0xfff < uVar5) {

      uVar5 = uVar5 + 0x27;

      lVar7 = *(longlong *)(lVar2 + -8);

      if (0x1f < (lVar2 - lVar7) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088(lVar7,uVar5);

  }

  return;

}





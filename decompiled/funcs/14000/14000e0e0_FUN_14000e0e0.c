// Address: 0x14000e0e0
// Ghidra name: FUN_14000e0e0
// ============ 0x14000e0e0 FUN_14000e0e0 (size=601) ============


undefined8 FUN_14000e0e0(longlong param_1,undefined8 *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  ulonglong uVar7;

  undefined8 *puVar8;

  undefined8 uVar9;

  longlong lVar10;

  float *pfVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  undefined1 local_res20 [8];

  ulonglong uVar6;

  

  if (param_3 - 3U < 6) {

    uVar15 = 0;

    *(int *)(param_1 + 0x98) = param_3;

    if (0 < param_3) {

      lVar10 = param_1 - (longlong)param_2;

      uVar6 = uVar15;

      do {

        uVar5 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar5;

        *(undefined8 *)((longlong)param_2 + lVar10 + 0x18) = *param_2;

        param_2 = param_2 + 1;

        param_3 = *(int *)(param_1 + 0x98);

      } while ((int)uVar5 < param_3);

    }

    fVar4 = DAT_14039ca80;

    fVar3 = DAT_14039ca44;

    fVar2 = DAT_14039c9f0;

    fVar1 = DAT_14039c9ec;

    uVar6 = uVar15;

    uVar12 = uVar15;

    if (0 < param_3) {

      do {

        uVar5 = (int)uVar6 + 1;

        uVar6 = uVar12 + 1;

        if (param_3 <= (int)uVar5) {

          uVar6 = uVar15;

        }

        fVar16 = *(float *)(param_1 + 0x18 + uVar6 * 8) - *(float *)(param_1 + 0x18 + uVar12 * 8);

        fVar18 = *(float *)(param_1 + 0x1c + uVar6 * 8) - *(float *)(param_1 + 0x1c + uVar12 * 8);

        if (fVar16 * fVar16 + fVar18 * fVar18 <= fVar1) goto LAB_14000e301;

        fVar16 = fVar16 * fVar4;

        *(float *)(param_1 + 0x58 + uVar12 * 8) = fVar18;

        *(float *)(param_1 + 0x5c + uVar12 * 8) = fVar16;

        fVar17 = fVar16 * fVar16 + fVar18 * fVar18;

        if (fVar17 < 0.0) {

          fVar17 = (float)FUN_1402cdfa0(fVar17);

        }

        else {

          fVar17 = SQRT(fVar17);

        }

        if (fVar2 <= fVar17) {

          *(float *)(param_1 + 0x58 + uVar12 * 8) = (fVar3 / fVar17) * fVar18;

          *(float *)(param_1 + 0x5c + uVar12 * 8) = (fVar3 / fVar17) * fVar16;

        }

        param_3 = *(int *)(param_1 + 0x98);

        uVar6 = (ulonglong)uVar5;

        uVar12 = uVar12 + 1;

      } while ((int)uVar5 < param_3);

    }

    uVar6 = uVar15;

    uVar12 = uVar15;

    if (0 < param_3) {

      do {

        pfVar11 = (float *)(param_1 + 0x1c);

        uVar14 = uVar6 + 1;

        if (param_3 <= (int)uVar12 + 1) {

          uVar14 = uVar15;

        }

        uVar7 = uVar15;

        uVar13 = uVar15;

        do {

          if (((uVar7 != uVar6) && (uVar7 != uVar14)) &&

             ((*pfVar11 - *(float *)(param_1 + 0x1c + uVar6 * 8)) *

              (*(float *)(param_1 + 0x18 + uVar14 * 8) - *(float *)(param_1 + 0x18 + uVar6 * 8)) -

              (pfVar11[-1] - *(float *)(param_1 + 0x18 + uVar6 * 8)) *

              (*(float *)(param_1 + 0x1c + uVar14 * 8) - *(float *)(param_1 + 0x1c + uVar6 * 8)) <=

              0.0)) goto LAB_14000e301;

          uVar5 = (int)uVar13 + 1;

          uVar13 = (ulonglong)uVar5;

          uVar7 = uVar7 + 1;

          pfVar11 = pfVar11 + 2;

        } while ((int)uVar5 < param_3);

        uVar5 = (int)uVar12 + 1;

        uVar6 = uVar6 + 1;

        uVar12 = (ulonglong)uVar5;

      } while ((int)uVar5 < param_3);

    }

    puVar8 = (undefined8 *)FUN_14000da90(local_res20,param_1 + 0x18,param_3);

    uVar9 = 1;

    *(undefined8 *)(param_1 + 0x10) = *puVar8;

  }

  else {

LAB_14000e301:

    uVar9 = 0;

  }

  return uVar9;

}





// Address: 0x14004b390
// Ghidra name: FUN_14004b390
// ============ 0x14004b390 FUN_14004b390 (size=954) ============


void FUN_14004b390(longlong param_1,undefined8 *param_2,undefined8 *param_3,int param_4,int param_5,

                  int param_6)



{

  float *pfVar1;

  float *pfVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  undefined8 uVar13;

  float *pfVar14;

  longlong lVar15;

  longlong lVar16;

  longlong lVar17;

  float local_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float local_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  

  lVar17 = (longlong)param_5;

  lVar3 = *(longlong *)(param_1 + 0x10);

  lVar4 = *(longlong *)(param_1 + 0x18);

  lVar5 = *(longlong *)(DAT_1403ea2a8 + 0xb8);

  if (0 < lVar17) {

    lVar16 = *(longlong *)(DAT_1403ea2a8 + 0xc0) - lVar5;

    lVar15 = ((longlong)param_6 - (longlong)param_4) * 0x10 - lVar5;

    pfVar14 = (float *)((longlong)param_4 * 0x10 + lVar5);

    if (*(int *)(param_1 + 8) == 2) {

      fStack_bc = (float)((ulonglong)param_3[1] >> 0x20);

      fStack_c0 = (float)param_3[1];

      fStack_c4 = (float)((ulonglong)*param_3 >> 0x20);

      local_c8 = (float)*param_3;

      fStack_cc = (float)((ulonglong)param_2[1] >> 0x20);

      fStack_d0 = (float)param_2[1];

      fStack_d4 = (float)((ulonglong)*param_2 >> 0x20);

      local_d8 = (float)*param_2;

      do {

        pfVar1 = (float *)(lVar15 + lVar4 + (longlong)pfVar14);

        pfVar2 = (float *)((lVar3 - lVar4) + (longlong)pfVar1);

        fVar6 = pfVar2[1];

        fVar7 = pfVar2[2];

        fVar8 = pfVar2[3];

        fVar9 = *pfVar1;

        fVar10 = pfVar1[1];

        fVar11 = pfVar1[2];

        fVar12 = pfVar1[3];

        *pfVar14 = local_d8 * *pfVar2 + *pfVar14;

        pfVar14[1] = fStack_d4 * fVar6 + pfVar14[1];

        pfVar14[2] = fStack_d0 * fVar7 + pfVar14[2];

        pfVar14[3] = fStack_cc * fVar8 + pfVar14[3];

        pfVar1 = (float *)(lVar16 + (longlong)pfVar14);

        fVar6 = pfVar1[1];

        fVar7 = pfVar1[2];

        fVar8 = pfVar1[3];

        pfVar2 = (float *)(lVar16 + (longlong)pfVar14);

        *pfVar2 = local_c8 * fVar9 + *pfVar1;

        pfVar2[1] = fStack_c4 * fVar10 + fVar6;

        pfVar2[2] = fStack_c0 * fVar11 + fVar7;

        pfVar2[3] = fStack_bc * fVar12 + fVar8;

        pfVar14 = pfVar14 + 4;

        lVar17 = lVar17 + -1;

      } while (lVar17 != 0);

    }

    else {

      uVar13 = *param_2;

      fStack_bc = (float)((ulonglong)param_3[1] >> 0x20);

      fStack_c0 = (float)param_3[1];

      fStack_c4 = (float)((ulonglong)*param_3 >> 0x20);

      local_c8 = (float)*param_3;

      fStack_cc = (float)((ulonglong)param_2[1] >> 0x20);

      fStack_d0 = (float)param_2[1];

      fStack_d4 = (float)((ulonglong)uVar13 >> 0x20);

      do {

        pfVar1 = (float *)(lVar15 + lVar3 + (longlong)pfVar14);

        fVar6 = *pfVar1;

        fVar7 = pfVar1[1];

        fVar8 = pfVar1[2];

        fVar9 = pfVar1[3];

        local_d8 = (float)uVar13;

        *pfVar14 = fVar6 * local_d8 + *pfVar14;

        pfVar14[1] = fVar7 * fStack_d4 + pfVar14[1];

        pfVar14[2] = fVar8 * fStack_d0 + pfVar14[2];

        pfVar14[3] = fVar9 * fStack_cc + pfVar14[3];

        pfVar1 = (float *)(lVar16 + (longlong)pfVar14);

        fVar10 = pfVar1[1];

        fVar11 = pfVar1[2];

        fVar12 = pfVar1[3];

        pfVar2 = (float *)(lVar16 + (longlong)pfVar14);

        *pfVar2 = fVar6 * local_c8 + *pfVar1;

        pfVar2[1] = fVar7 * fStack_c4 + fVar10;

        pfVar2[2] = fVar8 * fStack_c0 + fVar11;

        pfVar2[3] = fVar9 * fStack_bc + fVar12;

        pfVar14 = pfVar14 + 4;

        lVar17 = lVar17 + -1;

      } while (lVar17 != 0);

    }

  }

  return;

}





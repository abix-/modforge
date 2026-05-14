// Address: 0x1400f4560
// Ghidra name: FUN_1400f4560
// ============ 0x1400f4560 FUN_1400f4560 (size=793) ============


void FUN_1400f4560(longlong param_1,longlong param_2,int *param_3,uint param_4,float param_5,

                  float param_6,float param_7,float param_8,undefined4 param_9,undefined4 param_10,

                  int param_11,undefined8 param_12)



{

  int *piVar1;

  longlong lVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  float *pfVar12;

  undefined4 *puVar13;

  longlong lVar14;

  ulonglong uVar15;

  bool bVar16;

  int iVar17;

  int iVar18;

  int iVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  int iVar23;

  int iVar24;

  

  uVar15 = (ulonglong)param_4;

  if (param_11 != 0) {

    param_6 = (float)((uint)param_6 ^ DAT_14039cac0);

  }

  iVar5 = 5;

  if (*(int *)(param_1 + 4) < 8) {

    iVar5 = 0xf;

  }

  iVar18 = 0;

  iVar7 = 0;

  iVar17 = iVar7;

  if ((0 < (int)param_4) && (iVar17 = 0, 7 < param_4)) {

    iVar17 = 0;

    iVar18 = 0;

    iVar19 = 0;

    iVar20 = 0;

    iVar21 = 0;

    iVar22 = 0;

    iVar23 = 0;

    iVar24 = 0;

    lVar6 = 0;

    do {

      piVar1 = param_3 + lVar6;

      iVar7 = iVar7 + 8;

      iVar17 = iVar17 + *piVar1;

      iVar18 = iVar18 + piVar1[1];

      iVar19 = iVar19 + piVar1[2];

      iVar20 = iVar20 + piVar1[3];

      piVar1 = param_3 + lVar6 + 4;

      lVar6 = lVar6 + 8;

      iVar21 = iVar21 + *piVar1;

      iVar22 = iVar22 + piVar1[1];

      iVar23 = iVar23 + piVar1[2];

      iVar24 = iVar24 + piVar1[3];

    } while (lVar6 < (longlong)((longlong)(int)param_4 & 0xfffffffffffffff8U));

    iVar18 = iVar21 + iVar17 + iVar23 + iVar19 + iVar22 + iVar18 + iVar24 + iVar20;

    iVar17 = iVar7;

  }

  iVar7 = 0;

  lVar6 = (longlong)iVar17;

  iVar17 = 0;

  lVar14 = (longlong)(int)param_4;

  if (lVar14 <= lVar6) goto LAB_1400f4661;

  if (lVar14 - lVar6 < 2) {

LAB_1400f4656:

    iVar18 = iVar18 + param_3[lVar6];

  }

  else {

    do {

      iVar7 = iVar7 + param_3[lVar6];

      iVar17 = iVar17 + param_3[lVar6 + 1];

      lVar6 = lVar6 + 2;

    } while (lVar6 < lVar14 + -1);

    if (lVar6 < lVar14) goto LAB_1400f4656;

  }

  iVar18 = iVar18 + iVar17 + iVar7;

LAB_1400f4661:

  lVar6 = _malloc_base(((longlong)iVar18 + 1) * 0x14);

  if (lVar6 != 0) {

    iVar17 = 0;

    iVar7 = 0;

    if (0 < (int)param_4) {

      lVar14 = 0;

      do {

        iVar19 = 0;

        lVar2 = param_2 + (longlong)iVar7 * 8;

        iVar18 = *param_3;

        iVar7 = iVar7 + iVar18;

        if (0 < iVar18) {

          pfVar12 = (float *)(lVar2 + 4);

          puVar13 = (undefined4 *)(lVar14 * 0x14 + 0x10 + lVar6);

          lVar8 = (longlong)(iVar18 + -1);

          lVar10 = 0;

          do {

            if (*(float *)(lVar2 + 4 + lVar8 * 8) != *pfVar12) {

              *puVar13 = 0;

              fVar3 = *(float *)(lVar2 + 4 + lVar8 * 8);

              fVar4 = *pfVar12;

              if (param_11 == 0) {

                bVar16 = fVar4 < fVar3;

              }

              else {

                bVar16 = fVar3 < fVar4;

              }

              lVar9 = lVar8;

              lVar11 = lVar10;

              if (!bVar16 && fVar3 != fVar4) {

                *puVar13 = 1;

                lVar9 = lVar10;

                lVar11 = lVar8;

              }

              iVar17 = iVar17 + 1;

              lVar14 = lVar14 + 1;

              puVar13[-4] = param_5 * *(float *)(lVar2 + lVar11 * 8) + param_7;

              puVar13[-3] = param_6 * *(float *)(lVar2 + 4 + lVar11 * 8) * (float)iVar5 + param_8;

              puVar13[-2] = param_5 * *(float *)(lVar2 + lVar9 * 8) + param_7;

              puVar13[-1] = param_6 * *(float *)(lVar2 + 4 + lVar9 * 8) * (float)iVar5 + param_8;

              puVar13 = puVar13 + 5;

            }

            iVar19 = iVar19 + 1;

            pfVar12 = pfVar12 + 2;

            lVar8 = lVar10;

            lVar10 = lVar10 + 1;

          } while (iVar19 < *param_3);

        }

        param_3 = param_3 + 1;

        uVar15 = uVar15 - 1;

      } while (uVar15 != 0);

    }

    FUN_1402cf520(lVar6,(longlong)iVar17,0x14,&LAB_1400f3700);

    FUN_1400f4880(param_1,lVar6,iVar17,iVar5,param_9,param_10,param_12);

    thunk_FUN_1402e9a80(lVar6);

  }

  return;

}





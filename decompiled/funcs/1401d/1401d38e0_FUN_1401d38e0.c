// Address: 0x1401d38e0
// Ghidra name: FUN_1401d38e0
// ============ 0x1401d38e0 FUN_1401d38e0 (size=1603) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401d38e0(longlong param_1,longlong param_2,int param_3,int param_4,int param_5,int param_6

                  ,int param_7,int *param_8,float *param_9)



{

  longlong lVar1;

  longlong lVar2;

  double dVar3;

  double dVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  uint uVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  int iVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  char *pcVar22;

  double dVar23;

  double dVar24;

  double dVar25;

  double dVar26;

  float fVar27;

  float fVar28;

  int local_e4;

  

  dVar4 = DAT_14034a970;

  dVar3 = DAT_140304b70;

  iVar7 = *(int *)(param_2 + 8);

  iVar16 = *(int *)(param_1 + 8) + -1;

  iVar8 = *(int *)(param_1 + 0xc) + -1;

  pcVar22 = *(char **)(param_2 + 0x18);

  iVar12 = *(int *)(param_2 + 0x10) + iVar7 * -4;

  fVar27 = *param_9;

  fVar28 = param_9[1];

  dVar23 = (double)fVar27 * _DAT_14034a978;

  dVar24 = (double)fVar28 * _DAT_14034a978;

  if (param_7 == 0) {

    param_7 = 0;

    if (0 < *(int *)(param_2 + 0xc)) {

      do {

        iVar15 = 0;

        dVar26 = ((double)*param_8 + 0.0 + dVar3) - (double)fVar27;

        dVar25 = ((double)param_8[1] + (double)param_7 + dVar3) - (double)fVar28;

        iVar13 = (int)((((double)param_4 * dVar26 - dVar25 * (double)param_3) + (double)(int)dVar23)

                      - dVar4);

        iVar18 = (int)(((double)param_3 * dVar26 + dVar25 * (double)param_4 + (double)(int)dVar24) -

                      dVar4);

        if (0 < iVar7) {

          do {

            uVar20 = iVar13 >> 0x10;

            uVar21 = iVar18 >> 0x10;

            if ((uVar20 < *(uint *)(param_1 + 8)) && (uVar21 < *(uint *)(param_1 + 0xc))) {

              if (param_5 != 0) {

                uVar20 = iVar16 - uVar20;

              }

              if (param_6 != 0) {

                uVar21 = iVar8 - uVar21;

              }

              *(undefined4 *)pcVar22 =

                   *(undefined4 *)

                    ((longlong)(int)(uVar21 * *(int *)(param_1 + 0x10)) + (longlong)(int)uVar20 * 4

                    + *(longlong *)(param_1 + 0x18));

            }

            iVar7 = *(int *)(param_2 + 8);

            iVar13 = iVar13 + param_4;

            iVar18 = iVar18 + param_3;

            pcVar22 = pcVar22 + 4;

            iVar15 = iVar15 + 1;

          } while (iVar15 < iVar7);

          fVar27 = *param_9;

          fVar28 = param_9[1];

        }

        pcVar22 = pcVar22 + iVar12;

        param_7 = param_7 + 1;

      } while (param_7 < *(int *)(param_2 + 0xc));

    }

  }

  else {

    local_e4 = 0;

    if (0 < *(int *)(param_2 + 0xc)) {

      do {

        param_7 = 0;

        dVar26 = ((double)*param_8 + 0.0 + dVar3) - (double)fVar27;

        dVar25 = ((double)param_8[1] + (double)local_e4 + dVar3) - (double)fVar28;

        uVar20 = (uint)((((double)param_4 * dVar26 - (double)param_3 * dVar25) + (double)(int)dVar23

                        ) - dVar4);

        uVar21 = (uint)(((double)param_4 * dVar25 + (double)param_3 * dVar26 + (double)(int)dVar24)

                       - dVar4);

        if (0 < iVar7) {

          do {

            iVar7 = iVar16 - ((int)uVar20 >> 0x10);

            if (param_5 == 0) {

              iVar7 = (int)uVar20 >> 0x10;

            }

            iVar15 = iVar8 - ((int)uVar21 >> 0x10);

            if (param_6 == 0) {

              iVar15 = (int)uVar21 >> 0x10;

            }

            if ((((-1 < iVar7) && (-1 < iVar15)) && (iVar7 < *(int *)(param_1 + 8) + -1)) &&

               (iVar15 < *(int *)(param_1 + 0xc) + -1)) {

              iVar13 = *(int *)(param_1 + 0x10);

              lVar1 = (longlong)(iVar13 * iVar15) + (longlong)iVar7 * 4;

              lVar2 = *(longlong *)(param_1 + 0x18);

              uVar17 = *(uint *)(lVar1 + 4 + lVar2);

              uVar10 = *(uint *)(lVar1 + lVar2);

              if (iVar13 < 0) {

                iVar13 = iVar13 + 3;

              }

              uVar14 = uVar17;

              uVar6 = uVar10;

              if (param_5 == 0) {

                uVar14 = uVar10;

                uVar6 = uVar17;

              }

              uVar11 = *(uint *)(lVar1 + lVar2 + 4 + (longlong)(iVar13 >> 2) * 4);

              uVar19 = *(uint *)(lVar1 + lVar2 + (longlong)(iVar13 >> 2) * 4);

              uVar9 = uVar11;

              uVar5 = uVar19;

              if (param_5 == 0) {

                uVar9 = uVar19;

                uVar5 = uVar11;

              }

              if ((param_6 != 0) &&

                 (uVar6 = uVar19, uVar14 = uVar11, uVar9 = uVar17, uVar5 = uVar10, param_5 == 0)) {

                uVar6 = uVar11;

                uVar14 = uVar19;

                uVar9 = uVar10;

                uVar5 = uVar17;

              }

              uVar11 = uVar20 & 0xffff;

              uVar10 = uVar21 & 0xffff;

              uVar17 = ((int)(((uVar6 & 0xff) - (uVar14 & 0xff)) * uVar11) >> 0x10) +

                       (uVar14 & 0xff);

              *pcVar22 = (char)(((((int)(((uVar5 & 0xff) - (uVar9 & 0xff)) * uVar11) >> 0x10) +

                                  (uVar9 & 0xff) & 0xff) - (uVar17 & 0xff)) * uVar10 >> 0x10) +

                         (char)uVar17;

              uVar17 = uVar14 >> 8 & 0xff;

              uVar17 = ((int)(((uVar6 >> 8 & 0xff) - uVar17) * uVar11) >> 0x10) + uVar17;

              uVar19 = uVar9 >> 8 & 0xff;

              pcVar22[1] = (char)(((((int)(((uVar5 >> 8 & 0xff) - uVar19) * uVar11) >> 0x10) +

                                    uVar19 & 0xff) - (uVar17 & 0xff)) * uVar10 >> 0x10) +

                           (char)uVar17;

              uVar17 = uVar14 >> 0x10 & 0xff;

              uVar17 = ((int)(((uVar6 >> 0x10 & 0xff) - uVar17) * uVar11) >> 0x10) + uVar17;

              uVar19 = uVar9 >> 0x10 & 0xff;

              pcVar22[2] = (char)(((((int)(((uVar5 >> 0x10 & 0xff) - uVar19) * uVar11) >> 0x10) +

                                    uVar19 & 0xff) - (uVar17 & 0xff)) * uVar10 >> 0x10) +

                           (char)uVar17;

              uVar17 = ((int)(((uVar6 >> 0x18) - (uVar14 >> 0x18)) * uVar11) >> 0x10) +

                       (uVar14 >> 0x18);

              pcVar22[3] = (char)(((((int)(((uVar5 >> 0x18) - (uVar9 >> 0x18)) * uVar11) >> 0x10) +

                                    (uVar9 >> 0x18) & 0xff) - (uVar17 & 0xff)) * uVar10 >> 0x10) +

                           (char)uVar17;

            }

            iVar7 = *(int *)(param_2 + 8);

            param_7 = param_7 + 1;

            uVar20 = uVar20 + param_4;

            uVar21 = uVar21 + param_3;

            pcVar22 = pcVar22 + 4;

          } while (param_7 < iVar7);

          fVar27 = *param_9;

          fVar28 = param_9[1];

        }

        pcVar22 = pcVar22 + iVar12;

        local_e4 = local_e4 + 1;

      } while (local_e4 < *(int *)(param_2 + 0xc));

    }

  }

  return;

}





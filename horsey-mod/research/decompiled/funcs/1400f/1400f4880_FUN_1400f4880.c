// Address: 0x1400f4880
// Ghidra name: FUN_1400f4880
// ============ 0x1400f4880 FUN_1400f4880 (size=1061) ============


void FUN_1400f4880(int *param_1,float *param_2,int param_3,uint param_4,int param_5,int param_6)



{

  bool bVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  int *piVar5;

  int iVar6;

  undefined1 *puVar7;

  int *piVar8;

  int *piVar9;

  int *piVar10;

  int **ppiVar11;

  int *piVar12;

  int iVar13;

  ulonglong uVar14;

  double dVar15;

  float fVar16;

  float fVar17;

  int local_res18;

  int *local_2b8 [2];

  undefined1 local_2a8 [616];

  

  piVar12 = (int *)0x0;

  local_2b8[0] = (int *)0x0;

  local_res18 = 0;

  if (*param_1 < 0x201) {

    puVar7 = local_2a8;

  }

  else {

    puVar7 = (undefined1 *)_malloc_base((longlong)*param_1);

  }

  iVar13 = param_4 * param_6;

  param_2[(longlong)param_3 * 5 + 1] =

       (float)(param_1[1] + param_6) * (float)(int)param_4 + DAT_14039ca44;

  uVar4 = DAT_14039cac0;

  fVar3 = DAT_14039ca34;

  fVar2 = DAT_1403102f4;

  if (0 < param_1[1]) {

    do {

      FUN_1402f94c0(puVar7,0);

      if (0 < (int)param_4) {

        uVar14 = (ulonglong)param_4;

        do {

          ppiVar11 = local_2b8;

          fVar17 = (float)iVar13 + fVar3;

          piVar8 = piVar12;

          while (piVar12 != (int *)0x0) {

            if (fVar17 < (float)piVar12[2]) {

              *piVar12 = *piVar12 + piVar12[1];

              ppiVar11 = (int **)(*ppiVar11 + 4);

            }

            else {

              *ppiVar11 = *(int **)(piVar12 + 4);

              piVar12[6] = 0;

              thunk_FUN_1402e9a80(piVar12);

            }

            piVar8 = local_2b8[0];

            piVar12 = *ppiVar11;

          }

          do {

            bVar1 = false;

            ppiVar11 = local_2b8;

            piVar12 = piVar8;

            if (piVar8 == (int *)0x0) break;

            do {

              piVar12 = *(int **)(piVar8 + 4);

              if (piVar12 == (int *)0x0) break;

              if (*piVar12 < *piVar8) {

                bVar1 = true;

                *(undefined8 *)(piVar8 + 4) = *(undefined8 *)(piVar12 + 4);

                *(int **)(piVar12 + 4) = piVar8;

                *ppiVar11 = piVar12;

                piVar8 = piVar12;

              }

              ppiVar11 = (int **)(piVar8 + 4);

              piVar8 = *(int **)(piVar8 + 4);

            } while (piVar8 != (int *)0x0);

            piVar8 = local_2b8[0];

            piVar12 = local_2b8[0];

          } while (bVar1);

          fVar16 = param_2[1];

          while (fVar16 <= fVar17) {

            if (fVar17 < param_2[3]) {

              piVar8 = (int *)_malloc_base(0x20);

              fVar16 = (param_2[2] - *param_2) / (param_2[3] - param_2[1]);

              if (piVar8 != (int *)0x0) {

                if (0.0 <= fVar16) {

                  dVar15 = (double)FUN_1402d0290((double)(fVar16 * fVar2));

                  iVar6 = (int)dVar15;

                }

                else {

                  dVar15 = (double)FUN_1402d0290((double)((float)((uint)fVar16 ^ uVar4) * fVar2));

                  iVar6 = -(int)dVar15;

                }

                piVar8[1] = iVar6;

                dVar15 = (double)FUN_1402d0290((double)(((fVar17 - param_2[1]) * fVar16 + *param_2)

                                                       * fVar2));

                *piVar8 = (int)dVar15 + param_5 * -0x400;

                piVar8[2] = (int)param_2[3];

                piVar8[4] = 0;

                piVar8[5] = 0;

                iVar6 = -1;

                if (param_2[4] != 0.0) {

                  iVar6 = 1;

                }

                piVar8[6] = iVar6;

              }

              if (piVar12 == (int *)0x0) {

                local_2b8[0] = piVar8;

                piVar12 = piVar8;

              }

              else if (*piVar8 < *piVar12) {

                *(int **)(piVar8 + 4) = piVar12;

                local_2b8[0] = piVar8;

                piVar12 = piVar8;

              }

              else {

                piVar10 = piVar12;

                if (*(longlong *)(piVar12 + 4) != 0) {

                  piVar5 = *(int **)(piVar12 + 4);

                  do {

                    piVar9 = piVar5;

                    if (*piVar8 <= *piVar9) break;

                    piVar5 = *(int **)(piVar9 + 4);

                    piVar10 = piVar9;

                  } while (*(int **)(piVar9 + 4) != (int *)0x0);

                }

                *(undefined8 *)(piVar8 + 4) = *(undefined8 *)(piVar10 + 4);

                *(int **)(piVar10 + 4) = piVar8;

              }

            }

            fVar16 = param_2[6];

            param_2 = param_2 + 5;

          }

          if (piVar12 != (int *)0x0) {

            FUN_1400f3e30(puVar7,*param_1,piVar12,(int)(0xff / (longlong)(int)param_4));

          }

          iVar13 = iVar13 + 1;

          uVar14 = uVar14 - 1;

        } while (uVar14 != 0);

      }

      FUN_1402f8e20((longlong)(local_res18 * param_1[2]) + *(longlong *)(param_1 + 4),puVar7,

                    (longlong)*param_1);

      local_res18 = local_res18 + 1;

    } while (local_res18 < param_1[1]);

    while (piVar12 != (int *)0x0) {

      piVar8 = *(int **)(piVar12 + 4);

      thunk_FUN_1402e9a80(piVar12);

      piVar12 = piVar8;

    }

  }

  if (puVar7 != local_2a8) {

    thunk_FUN_1402e9a80(puVar7);

  }

  return;

}





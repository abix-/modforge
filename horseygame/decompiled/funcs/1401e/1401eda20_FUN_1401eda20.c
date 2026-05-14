// Address: 0x1401eda20
// Ghidra name: FUN_1401eda20
// ============ 0x1401eda20 FUN_1401eda20 (size=1568) ============


undefined8

FUN_1401eda20(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  ulonglong uVar1;

  float fVar2;

  byte bVar3;

  float *pfVar4;

  undefined8 uVar5;

  longlong lVar6;

  longlong lVar7;

  float *pfVar8;

  ulonglong uVar9;

  uint *puVar10;

  ulonglong uVar11;

  int iVar12;

  uint uVar13;

  ushort *puVar14;

  longlong lVar15;

  uint uVar16;

  longlong local_58;

  

  uVar9 = 0;

  fVar2 = *(float *)(param_2 + 0x18);

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar15 = (longlong)param_10;

  lVar7 = 0x18;

  if (param_3 != 0) {

    lVar7 = 0x20;

  }

  pfVar4 = (float *)FUN_14014b940(param_1,lVar7 * lVar15,0,param_2 + 8);

  uVar5 = 0;

  if (pfVar4 != (float *)0x0) {

    uVar11 = uVar9;

    if (param_3 != 0) {

      uVar11 = *(ulonglong *)(param_3 + 0x138);

    }

    *(longlong *)(param_2 + 0x10) = lVar15;

    iVar12 = 0;

    if (param_11 != 0) {

      iVar12 = param_13;

    }

    if (0 < param_10) {

      if (iVar12 == 1) {

        do {

          bVar3 = *(byte *)(param_11 + uVar9);

          lVar6 = (longlong)(int)((uint)bVar3 * param_5);

          lVar7 = (longlong)(int)((uint)bVar3 * param_7);

          *pfVar4 = param_14 * *(float *)(lVar6 + param_4);

          pfVar4[1] = param_15 * *(float *)(lVar6 + 4 + param_4);

          pfVar4[2] = fVar2 * *(float *)(lVar7 + param_6);

          pfVar4[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

          pfVar4[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

          pfVar4[5] = *(float *)(lVar7 + 0xc + param_6);

          pfVar8 = pfVar4 + 6;

          if (param_3 != 0) {

            lVar7 = (longlong)(int)((uint)bVar3 * param_9);

            *pfVar8 = *(float *)(uVar11 + 8) * *(float *)(lVar7 + param_8);

            pfVar4[7] = *(float *)(lVar7 + 4 + param_8) * *(float *)(uVar11 + 0xc);

            pfVar8 = pfVar4 + 8;

          }

          uVar9 = uVar9 + 1;

          pfVar4 = pfVar8;

        } while ((longlong)uVar9 < lVar15);

      }

      else {

        uVar1 = uVar9;

        if (3 < lVar15) {

          puVar14 = (ushort *)(param_11 + 4);

          uVar16 = 2;

          puVar10 = (uint *)(param_11 + 8);

          local_58 = (lVar15 - 4U >> 2) + 1;

          uVar1 = local_58 * 4;

          do {

            if (iVar12 == 4) {

              uVar13 = puVar10[-2];

            }

            else {

              uVar13 = (uint)uVar9;

              if (iVar12 == 2) {

                uVar13 = (uint)puVar14[-2];

              }

            }

            lVar7 = (longlong)(int)(uVar13 * param_7);

            *pfVar4 = param_14 * *(float *)((int)(uVar13 * param_5) + param_4);

            pfVar4[1] = param_15 * *(float *)((longlong)(int)(uVar13 * param_5) + 4 + param_4);

            pfVar4[2] = fVar2 * *(float *)(lVar7 + param_6);

            pfVar4[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

            pfVar4[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

            pfVar4[5] = *(float *)(lVar7 + 0xc + param_6);

            pfVar8 = pfVar4 + 6;

            if (param_3 != 0) {

              *pfVar8 = *(float *)(uVar11 + 8) * *(float *)((int)(uVar13 * param_9) + param_8);

              pfVar4[7] = *(float *)((longlong)(int)(uVar13 * param_9) + 4 + param_8) *

                          *(float *)(uVar11 + 0xc);

              pfVar8 = pfVar4 + 8;

            }

            if (iVar12 == 4) {

              uVar13 = puVar10[-1];

            }

            else if (iVar12 == 2) {

              uVar13 = (uint)puVar14[-1];

            }

            else {

              uVar13 = uVar16 - 1;

            }

            lVar7 = (longlong)(int)(uVar13 * param_7);

            *pfVar8 = param_14 * *(float *)((int)(uVar13 * param_5) + param_4);

            pfVar8[1] = param_15 * *(float *)((longlong)(int)(uVar13 * param_5) + 4 + param_4);

            pfVar8[2] = fVar2 * *(float *)(lVar7 + param_6);

            pfVar8[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

            pfVar8[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

            pfVar8[5] = *(float *)(lVar7 + 0xc + param_6);

            pfVar4 = pfVar8 + 6;

            if (param_3 != 0) {

              *pfVar4 = *(float *)(uVar11 + 8) * *(float *)((int)(uVar13 * param_9) + param_8);

              pfVar8[7] = *(float *)((longlong)(int)(uVar13 * param_9) + 4 + param_8) *

                          *(float *)(uVar11 + 0xc);

              pfVar4 = pfVar8 + 8;

            }

            if (iVar12 == 4) {

              uVar13 = *puVar10;

            }

            else {

              uVar13 = uVar16;

              if (iVar12 == 2) {

                uVar13 = (uint)*puVar14;

              }

            }

            lVar7 = (longlong)(int)(uVar13 * param_7);

            *pfVar4 = param_14 * *(float *)((int)(uVar13 * param_5) + param_4);

            pfVar4[1] = param_15 * *(float *)((longlong)(int)(uVar13 * param_5) + 4 + param_4);

            pfVar4[2] = fVar2 * *(float *)(lVar7 + param_6);

            pfVar4[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

            pfVar4[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

            pfVar4[5] = *(float *)(lVar7 + 0xc + param_6);

            pfVar8 = pfVar4 + 6;

            if (param_3 != 0) {

              *pfVar8 = *(float *)(uVar11 + 8) * *(float *)((int)(uVar13 * param_9) + param_8);

              pfVar4[7] = *(float *)((longlong)(int)(uVar13 * param_9) + 4 + param_8) *

                          *(float *)(uVar11 + 0xc);

              pfVar8 = pfVar4 + 8;

            }

            if (iVar12 == 4) {

              uVar13 = puVar10[1];

            }

            else if (iVar12 == 2) {

              uVar13 = (uint)puVar14[1];

            }

            else {

              uVar13 = uVar16 + 1;

            }

            lVar7 = (longlong)(int)(uVar13 * param_7);

            *pfVar8 = param_14 * *(float *)((int)(uVar13 * param_5) + param_4);

            pfVar8[1] = param_15 * *(float *)((longlong)(int)(uVar13 * param_5) + 4 + param_4);

            pfVar8[2] = fVar2 * *(float *)(lVar7 + param_6);

            pfVar8[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

            pfVar8[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

            pfVar8[5] = *(float *)(lVar7 + 0xc + param_6);

            pfVar4 = pfVar8 + 6;

            if (param_3 != 0) {

              *pfVar4 = *(float *)(uVar11 + 8) * *(float *)((int)(uVar13 * param_9) + param_8);

              pfVar8[7] = *(float *)((longlong)(int)(uVar13 * param_9) + 4 + param_8) *

                          *(float *)(uVar11 + 0xc);

              pfVar4 = pfVar8 + 8;

            }

            uVar9 = (ulonglong)((uint)uVar9 + 4);

            uVar16 = uVar16 + 4;

            puVar10 = puVar10 + 4;

            puVar14 = puVar14 + 4;

            local_58 = local_58 + -1;

          } while (local_58 != 0);

        }

        for (; (longlong)uVar1 < lVar15; uVar1 = uVar1 + 1) {

          if (iVar12 == 4) {

            uVar16 = *(uint *)(param_11 + uVar1 * 4);

          }

          else {

            uVar16 = (uint)uVar9;

            if (iVar12 == 2) {

              uVar16 = (uint)*(ushort *)(param_11 + uVar1 * 2);

            }

          }

          lVar7 = (longlong)(int)(uVar16 * param_7);

          *pfVar4 = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

          pfVar4[1] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

          pfVar4[2] = fVar2 * *(float *)(lVar7 + param_6);

          pfVar4[3] = fVar2 * *(float *)(lVar7 + 4 + param_6);

          pfVar4[4] = fVar2 * *(float *)(lVar7 + 8 + param_6);

          pfVar4[5] = *(float *)(lVar7 + 0xc + param_6);

          pfVar8 = pfVar4 + 6;

          if (param_3 != 0) {

            *pfVar8 = *(float *)(uVar11 + 8) * *(float *)((int)(uVar16 * param_9) + param_8);

            pfVar4[7] = *(float *)((longlong)(int)(uVar16 * param_9) + 4 + param_8) *

                        *(float *)(uVar11 + 0xc);

            pfVar8 = pfVar4 + 8;

          }

          uVar9 = (ulonglong)((uint)uVar9 + 1);

          pfVar4 = pfVar8;

        }

      }

    }

    uVar5 = 1;

  }

  return uVar5;

}





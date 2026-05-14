// Address: 0x1401e2b00
// Ghidra name: FUN_1401e2b00
// ============ 0x1401e2b00 FUN_1401e2b00 (size=818) ============


undefined8

FUN_1401e2b00(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  undefined8 *puVar1;

  byte bVar2;

  int *piVar3;

  char cVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined8 *puVar8;

  uint uVar9;

  uint uVar10;

  longlong lVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar11 = (longlong)param_10;

  lVar5 = FUN_14014b940(param_1,lVar11 << 5,0,param_2 + 8);

  cVar4 = FUN_1401538c0(param_1);

  if ((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0x138), piVar3 == (int *)0x0)) {

    fVar14 = 0.0;

    fVar15 = 0.0;

  }

  else {

    fVar14 = (float)*(int *)(param_3 + 4) / (float)*piVar3;

    fVar15 = (float)*(int *)(param_3 + 8) / (float)piVar3[1];

  }

  if (lVar5 == 0) {

    uVar6 = 0;

  }

  else {

    *(longlong *)(param_2 + 0x10) = lVar11;

    iVar12 = 0;

    if (param_11 != 0) {

      iVar12 = param_13;

    }

    if (0 < param_10) {

      if (iVar12 == 1) {

        puVar8 = (undefined8 *)(lVar5 + 0x10);

        lVar5 = 0;

        do {

          bVar2 = *(byte *)(lVar5 + param_11);

          lVar7 = (longlong)(int)((uint)bVar2 * param_5);

          *(float *)(puVar8 + -2) = param_14 * *(float *)(lVar7 + param_4);

          *(float *)((longlong)puVar8 + -0xc) = param_15 * *(float *)(lVar7 + 4 + param_4);

          puVar1 = (undefined8 *)((int)((uint)bVar2 * param_7) + param_6);

          uVar6 = puVar1[1];

          *puVar8 = *puVar1;

          puVar8[1] = uVar6;

          if (cVar4 != '\0') {

            FUN_14014bd40(puVar8);

          }

          if (param_3 == 0) {

            *(undefined4 *)(puVar8 + -1) = 0;

            fVar13 = 0.0;

          }

          else {

            lVar7 = (longlong)(int)((uint)bVar2 * param_9);

            *(float *)(puVar8 + -1) = fVar14 * *(float *)(lVar7 + param_8);

            fVar13 = fVar15 * *(float *)(lVar7 + 4 + param_8);

          }

          lVar5 = lVar5 + 1;

          *(float *)((longlong)puVar8 + -4) = fVar13;

          puVar8 = puVar8 + 4;

        } while (lVar5 < lVar11);

      }

      else {

        uVar9 = 0;

        if (0 < param_10) {

          puVar8 = (undefined8 *)(lVar5 + 0x10);

          lVar5 = 0;

          do {

            if (iVar12 == 4) {

              uVar10 = *(uint *)(param_11 + lVar5 * 4);

            }

            else {

              uVar10 = uVar9;

              if (iVar12 == 2) {

                uVar10 = (uint)*(ushort *)(param_11 + lVar5 * 2);

              }

            }

            *(float *)(puVar8 + -2) = param_14 * *(float *)((int)(uVar10 * param_5) + param_4);

            *(float *)((longlong)puVar8 + -0xc) =

                 param_15 * *(float *)((longlong)(int)(uVar10 * param_5) + 4 + param_4);

            puVar1 = (undefined8 *)((int)(uVar10 * param_7) + param_6);

            uVar6 = puVar1[1];

            *puVar8 = *puVar1;

            puVar8[1] = uVar6;

            if (cVar4 != '\0') {

              FUN_14014bd40(puVar8);

            }

            if (param_3 == 0) {

              *(undefined4 *)(puVar8 + -1) = 0;

              fVar13 = 0.0;

            }

            else {

              *(float *)(puVar8 + -1) = fVar14 * *(float *)((int)(uVar10 * param_9) + param_8);

              fVar13 = fVar15 * *(float *)((longlong)(int)(uVar10 * param_9) + 4 + param_8);

            }

            uVar9 = uVar9 + 1;

            *(float *)((longlong)puVar8 + -4) = fVar13;

            lVar5 = lVar5 + 1;

            puVar8 = puVar8 + 4;

          } while (lVar5 < lVar11);

        }

      }

    }

    uVar6 = 1;

  }

  return uVar6;

}





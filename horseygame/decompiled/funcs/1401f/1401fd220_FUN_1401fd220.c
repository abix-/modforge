// Address: 0x1401fd220
// Ghidra name: FUN_1401fd220
// ============ 0x1401fd220 FUN_1401fd220 (size=819) ============


undefined8

FUN_1401fd220(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  undefined8 *puVar1;

  byte bVar2;

  char cVar3;

  longlong lVar4;

  undefined8 uVar5;

  longlong lVar6;

  undefined8 *puVar7;

  uint uVar8;

  uint uVar9;

  longlong lVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar10 = (longlong)param_10;

  lVar4 = FUN_14014b940(param_1,lVar10 << 5,0,param_2 + 8);

  cVar3 = FUN_1401538c0(param_1);

  if ((param_3 == 0) || (lVar6 = *(longlong *)(param_3 + 0x138), lVar6 == 0)) {

    fVar13 = 0.0;

    fVar14 = 0.0;

  }

  else {

    fVar13 = (float)*(int *)(param_3 + 4) / (float)*(int *)(lVar6 + 0x70);

    fVar14 = (float)*(int *)(param_3 + 8) / (float)*(int *)(lVar6 + 0x74);

  }

  if (lVar4 == 0) {

    uVar5 = 0;

  }

  else {

    *(longlong *)(param_2 + 0x10) = lVar10;

    iVar11 = 0;

    if (param_11 != 0) {

      iVar11 = param_13;

    }

    if (0 < param_10) {

      if (iVar11 == 1) {

        puVar7 = (undefined8 *)(lVar4 + 0x10);

        lVar4 = 0;

        do {

          bVar2 = *(byte *)(lVar4 + param_11);

          lVar6 = (longlong)(int)((uint)bVar2 * param_5);

          *(float *)(puVar7 + -2) = param_14 * *(float *)(lVar6 + param_4);

          *(float *)((longlong)puVar7 + -0xc) = param_15 * *(float *)(lVar6 + 4 + param_4);

          puVar1 = (undefined8 *)((int)((uint)bVar2 * param_7) + param_6);

          uVar5 = puVar1[1];

          *puVar7 = *puVar1;

          puVar7[1] = uVar5;

          if (cVar3 != '\0') {

            FUN_14014bd40(puVar7);

          }

          if (param_3 == 0) {

            *(undefined4 *)(puVar7 + -1) = 0;

            fVar12 = 0.0;

          }

          else {

            lVar6 = (longlong)(int)((uint)bVar2 * param_9);

            *(float *)(puVar7 + -1) = fVar13 * *(float *)(lVar6 + param_8);

            fVar12 = fVar14 * *(float *)(lVar6 + 4 + param_8);

          }

          lVar4 = lVar4 + 1;

          *(float *)((longlong)puVar7 + -4) = fVar12;

          puVar7 = puVar7 + 4;

        } while (lVar4 < lVar10);

      }

      else {

        uVar8 = 0;

        if (0 < param_10) {

          puVar7 = (undefined8 *)(lVar4 + 0x10);

          lVar4 = 0;

          do {

            if (iVar11 == 4) {

              uVar9 = *(uint *)(param_11 + lVar4 * 4);

            }

            else {

              uVar9 = uVar8;

              if (iVar11 == 2) {

                uVar9 = (uint)*(ushort *)(param_11 + lVar4 * 2);

              }

            }

            *(float *)(puVar7 + -2) = param_14 * *(float *)((int)(uVar9 * param_5) + param_4);

            *(float *)((longlong)puVar7 + -0xc) =

                 param_15 * *(float *)((longlong)(int)(uVar9 * param_5) + 4 + param_4);

            puVar1 = (undefined8 *)((int)(uVar9 * param_7) + param_6);

            uVar5 = puVar1[1];

            *puVar7 = *puVar1;

            puVar7[1] = uVar5;

            if (cVar3 != '\0') {

              FUN_14014bd40(puVar7);

            }

            if (param_3 == 0) {

              *(undefined4 *)(puVar7 + -1) = 0;

              fVar12 = 0.0;

            }

            else {

              *(float *)(puVar7 + -1) = fVar13 * *(float *)((int)(uVar9 * param_9) + param_8);

              fVar12 = fVar14 * *(float *)((longlong)(int)(uVar9 * param_9) + 4 + param_8);

            }

            uVar8 = uVar8 + 1;

            *(float *)((longlong)puVar7 + -4) = fVar12;

            lVar4 = lVar4 + 1;

            puVar7 = puVar7 + 4;

          } while (lVar4 < lVar10);

        }

      }

    }

    uVar5 = 1;

  }

  return uVar5;

}





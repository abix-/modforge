// Address: 0x14002d170
// Ghidra name: FUN_14002d170
// ============ 0x14002d170 FUN_14002d170 (size=1491) ============


void FUN_14002d170(longlong param_1,int param_2)



{

  uint *puVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  ulonglong uVar11;

  undefined8 uVar12;

  ulonglong uVar13;

  longlong lVar14;

  longlong lVar15;

  ulonglong uVar16;

  int iVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  undefined4 uVar20;

  float fVar21;

  float fVar22;

  uint local_res10;

  

  fVar22 = DAT_14039ca44;

  uVar11 = 0;

  lVar5 = *(longlong *)(param_1 + 0x268);

  uVar16 = (ulonglong)param_2;

  lVar15 = *(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3;

  iVar17 = 0;

  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x130) + uVar16 * 8);

  fVar21 = 0.0;

  iVar10 = (int)lVar15;

  lVar14 = uVar16 * 0x20;

  local_res10 = 0;

  uVar13 = uVar11;

  uVar18 = uVar11;

  uVar19 = uVar11;

  if (0 < (longlong)iVar10) {

    do {

      if (uVar16 != uVar13) {

        fVar2 = *(float *)(lVar14 + 0x18 + lVar5);

        fVar3 = *(float *)(uVar19 + 0x18 + *(longlong *)(param_1 + 0x268));

        if (fVar3 <= fVar2 + fVar22) {

          if (fVar3 < fVar2 - fVar22) {

            uVar18 = (ulonglong)((int)uVar18 + 1);

          }

        }

        else {

          local_res10 = (int)uVar11 + 1;

          uVar11 = (ulonglong)local_res10;

        }

        if (fVar2 < fVar3) {

          fVar21 = (float)FUN_1400c5c10(uVar11,fVar3 - fVar2);

          uVar11 = (ulonglong)local_res10;

        }

      }

      iVar17 = (int)uVar18;

      uVar13 = uVar13 + 1;

      uVar19 = uVar19 + 0x20;

    } while ((longlong)uVar13 < (longlong)iVar10);

  }

  fVar2 = DAT_140303394;

  uVar4 = *(uint *)(lVar6 + 600);

  iVar7 = (*(int *)(param_1 + 0x254) + -1) / 0x3c;

  if (*(int *)(param_1 + 0x254) % 0x3c != 1) {

    return;

  }

  *(undefined4 *)(lVar14 + 0xc + lVar5) = 0;

  if ((((uVar4 >> 0x16 & 1) != 0) && (2 < iVar7)) &&

     ((*(char *)(lVar6 + 0x1a) != '\0' || (*(int *)(lVar14 + 8 + lVar5) < 0x1e)))) {

    uVar12 = 500;

    if (*(char *)(lVar6 + 0x1a) != '\0') {

      uVar12 = 10;

    }

    iVar9 = FUN_1400c6580(uVar12);

    if (iVar9 == 0) {

      FUN_1400b47e0(lVar6);

      *(bool *)(lVar6 + 0x1a) = *(char *)(lVar6 + 0x1a) == '\0';

      FUN_1400b3dc0(lVar6,*(undefined8 *)(param_1 + 0x98));

      FUN_1400b7fe0(lVar6,0);

      FUN_1400b9540(lVar6,0);

      FUN_1400d4f50(param_1,lVar6);

      goto LAB_14002d6d3;

    }

  }

  if ((((uVar4 >> 0x12 & 1) != 0) && (iVar7 < 1)) && (iVar9 = FUN_1400c6580(2), iVar9 == 0)) {

    uVar20 = FUN_1400c6940();

    *(undefined4 *)(lVar6 + 0x268) = uVar20;

    puVar1 = (uint *)(lVar14 + 0xc + lVar5);

    *puVar1 = *puVar1 | 0x40000;

    return;

  }

  if (((uVar4 >> 0xc & 1) != 0) && (iVar7 < 5)) {

    *(float *)(lVar6 + 0x268) = (float)(iVar7 + 5) * DAT_14039ca24;

    puVar1 = (uint *)(lVar14 + 0xc + lVar5);

    *puVar1 = *puVar1 | 0x1000;

    return;

  }

  if (((uVar4 >> 0x13 & 1) == 0) ||

     (*(float *)(lVar14 + 0x18 + lVar5) <= *(float *)(param_1 + 0x264) - fVar2)) {

    if ((*(float *)(lVar14 + 0x18 + lVar5) <= *(float *)(param_1 + 0x264) - fVar22) ||

       (iVar9 = FUN_1400c6580(8), iVar9 != 0)) {

      if ((((uVar4 >> 0xf & 1) == 0) || (fVar21 <= DAT_14039ca34)) || (iVar7 < 5)) {

        if ((((uVar4 >> 0x10 & 1) == 0) || (iVar7 < 5)) || (iVar17 != iVar10 + -1)) {

          if ((((uVar4 >> 0xd & 1) == 0) || (*(int *)(lVar6 + 0xc) != 4)) ||

             (((iVar7 < 8 || (local_res10 != iVar10 - 1U)) &&

              (iVar10 = FUN_1400c6580(1000), iVar10 != 0)))) {

            if ((uVar4 >> 0xe & 1) == 0) {

              if ((uVar4 >> 0x15 & 1) == 0) {

                *(undefined4 *)(lVar6 + 0x268) = 0x3f800000;

              }

              else {

                iVar10 = FUN_1400c6580(2);

                if (iVar10 == 0) {

                  cVar8 = FUN_1400c66c0();

                  if (cVar8 == '\0') {

                    *(undefined4 *)(lVar6 + 0x268) = DAT_14030336c;

                  }

                  else {

                    *(undefined4 *)(lVar6 + 0x268) = DAT_140303364;

                  }

                }

              }

            }

            else if (*(char *)(lVar14 + 0x1c + lVar5) == '\0') {

              *(undefined4 *)(lVar6 + 0x268) = 0x3f400000;

              puVar1 = (uint *)(lVar14 + 0xc + lVar5);

              *puVar1 = *puVar1 | 0x4000;

              iVar10 = FUN_1400c6580(8);

              if (iVar10 == 0) {

                *(undefined1 *)(lVar14 + 0x1c + lVar5) = 1;

              }

            }

            else {

              uVar4 = *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268));

              if ((uVar4 >> 0xe & 1) == 0) {

                *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x4000;

                FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar16 * 8));

                FUN_1400d4f50(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar16 * 8));

              }

              *(undefined4 *)(lVar6 + 0x268) = 0x3f8ccccd;

            }

            goto LAB_14002d6d3;

          }

          FUN_1400b8420(lVar6);

          puVar1 = (uint *)(lVar14 + 0xc + lVar5);

          *puVar1 = *puVar1 | 0x2000;

          uVar4 = *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268));

          if ((uVar4 >> 0xd & 1) != 0) goto LAB_14002d6d3;

          *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x2000;

        }

        else {

          uVar20 = FUN_1400c6940(lVar15,DAT_140303368);

          *(undefined4 *)(lVar6 + 0x268) = uVar20;

          puVar1 = (uint *)(lVar14 + 0xc + lVar5);

          *puVar1 = *puVar1 | 0x10000;

          uVar4 = *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268));

          if ((uVar4 >> 0x10 & 1) != 0) goto LAB_14002d6d3;

          *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x10000;

        }

      }

      else {

        fVar22 = (fVar21 - DAT_14039ca34) * DAT_140303350 + fVar22;

        if (DAT_140303378 <= fVar22) {

          fVar22 = DAT_140303378;

        }

        *(float *)(lVar6 + 0x268) = fVar22;

        puVar1 = (uint *)(lVar14 + 0xc + lVar5);

        *puVar1 = *puVar1 | 0x8000;

        uVar4 = *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268));

        if ((uVar4 >> 0xf & 1) != 0) goto LAB_14002d6d3;

        *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x8000;

      }

    }

    else {

      uVar20 = FUN_1400c6940();

      *(undefined4 *)(lVar6 + 0x268) = uVar20;

      uVar4 = *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268));

      if ((uVar4 >> 0x13 & 1) != 0) goto LAB_14002d6d3;

      *(uint *)(uVar16 * 0x20 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x80000;

    }

  }

  else {

    uVar20 = FUN_1400c6940();

    *(undefined4 *)(lVar6 + 0x268) = uVar20;

    puVar1 = (uint *)(lVar14 + 0xc + lVar5);

    *puVar1 = *puVar1 | 0x80000;

    uVar4 = *(uint *)(lVar14 + 0x10 + *(longlong *)(param_1 + 0x268));

    if ((uVar4 >> 0x13 & 1) != 0) goto LAB_14002d6d3;

    *(uint *)(lVar14 + 0x10 + *(longlong *)(param_1 + 0x268)) = uVar4 | 0x80000;

  }

  FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar16 * 8));

  FUN_1400d4f50(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar16 * 8));

LAB_14002d6d3:

  if (((iVar7 == 10) && (fVar22 = *(float *)(lVar14 + 0x18 + lVar5), DAT_14030338c < fVar22)) &&

     (fVar22 < *(float *)(param_1 + 0x264) - fVar2)) {

    FUN_1400d1e10(param_1,param_2,(0xb4 < *(int *)(lVar14 + 8 + lVar5)) + '\x1b');

  }

  return;

}





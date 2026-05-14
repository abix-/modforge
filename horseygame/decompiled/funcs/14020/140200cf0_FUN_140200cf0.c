// Address: 0x140200cf0
// Ghidra name: FUN_140200cf0
// ============ 0x140200cf0 FUN_140200cf0 (size=1134) ============


undefined8

FUN_140200cf0(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined8 uVar4;

  longlong lVar5;

  ulonglong uVar6;

  undefined1 *puVar7;

  int iVar8;

  int *piVar9;

  ulonglong uVar10;

  uint uVar11;

  longlong lVar12;

  float fVar13;

  undefined1 auVar14 [16];

  undefined1 auVar15 [16];

  undefined1 auVar16 [16];

  undefined1 auVar17 [16];

  undefined1 auVar18 [16];

  undefined1 auVar19 [16];

  undefined1 auVar20 [16];

  undefined1 auVar21 [16];

  float fVar22;

  float fVar23;

  

  fVar1 = *(float *)(param_2 + 0x18);

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar12 = (longlong)param_10;

  lVar5 = 0xc;

  if (param_3 != 0) {

    lVar5 = 0x14;

  }

  lVar5 = FUN_14014b940(param_1,lVar5 * lVar12,0,param_2 + 8);

  uVar4 = 0;

  if (lVar5 != 0) {

    uVar6 = 0;

    iVar8 = 0;

    if (param_11 != 0) {

      iVar8 = param_13;

    }

    *(longlong *)(param_2 + 0x10) = lVar12;

    fVar3 = DAT_14039ca44;

    fVar2 = DAT_14030a2d0;

    if (param_3 == 0) {

      if (0 < lVar12) {

        puVar7 = (undefined1 *)(lVar5 + 8);

        uVar10 = uVar6;

        do {

          if (iVar8 == 4) {

            uVar11 = *(uint *)(param_11 + uVar10 * 4);

          }

          else if (iVar8 == 2) {

            uVar11 = (uint)*(ushort *)(param_11 + uVar10 * 2);

          }

          else {

            uVar11 = (uint)uVar6;

            if (iVar8 == 1) {

              uVar11 = (uint)*(byte *)(uVar10 + param_11);

            }

          }

          auVar17 = *(undefined1 (*) [16])((int)(uVar11 * param_7) + param_6);

          fVar13 = auVar17._12_4_;

          *(int *)(puVar7 + -8) = (int)(param_14 * *(float *)((int)(uVar11 * param_5) + param_4));

          *(int *)(puVar7 + -4) =

               (int)(param_15 * *(float *)((longlong)(int)(uVar11 * param_5) + 4 + param_4));

          FUN_140263160();

          fVar22 = auVar17._0_4_ * fVar1;

          if (0.0 <= fVar22) {

            auVar14 = ZEXT416((uint)fVar3);

            if (fVar22 <= fVar3) {

              auVar14 = ZEXT416((uint)fVar22);

            }

          }

          else {

            auVar14 = ZEXT816(0);

          }

          auVar14._0_4_ = auVar14._0_4_ * fVar2;

          fVar22 = (float)thunk_FUN_1402e1d00(auVar14._0_8_);

          fVar23 = auVar17._4_4_ * fVar1;

          *puVar7 = (char)(int)fVar22;

          if (0.0 <= fVar23) {

            auVar14 = ZEXT416((uint)fVar3);

            if (fVar23 <= fVar3) {

              auVar14 = ZEXT416((uint)fVar23);

            }

          }

          else {

            auVar14 = ZEXT816(0);

          }

          auVar20._4_12_ = auVar14._4_12_;

          auVar20._0_4_ = auVar14._0_4_ * fVar2;

          fVar22 = (float)thunk_FUN_1402e1d00(auVar20._0_8_);

          fVar23 = auVar17._8_4_ * fVar1;

          puVar7[1] = (char)(int)fVar22;

          if (0.0 <= fVar23) {

            auVar17 = ZEXT416((uint)fVar3);

            if (fVar23 <= fVar3) {

              auVar17 = ZEXT416((uint)fVar23);

            }

          }

          else {

            auVar17 = ZEXT816(0);

          }

          auVar17._0_4_ = auVar17._0_4_ * fVar2;

          fVar22 = (float)thunk_FUN_1402e1d00(auVar17._0_8_);

          puVar7[2] = (char)(int)fVar22;

          if (0.0 <= fVar13) {

            auVar17 = ZEXT416((uint)fVar3);

            if (fVar13 <= fVar3) {

              auVar17 = ZEXT416((uint)fVar13);

            }

          }

          else {

            auVar17 = ZEXT816(0);

          }

          auVar21._4_12_ = auVar17._4_12_;

          auVar21._0_4_ = auVar17._0_4_ * fVar2;

          fVar13 = (float)thunk_FUN_1402e1d00(auVar21._0_8_);

          uVar6 = (ulonglong)((uint)uVar6 + 1);

          uVar10 = uVar10 + 1;

          puVar7[3] = (char)(int)fVar13;

          puVar7 = puVar7 + 0xc;

        } while ((longlong)uVar10 < lVar12);

      }

    }

    else if (0 < lVar12) {

      piVar9 = (int *)(lVar5 + 8);

      uVar10 = uVar6;

      do {

        if (iVar8 == 4) {

          uVar11 = *(uint *)(param_11 + uVar6 * 4);

        }

        else if (iVar8 == 2) {

          uVar11 = (uint)*(ushort *)(param_11 + uVar6 * 2);

        }

        else {

          uVar11 = (uint)uVar10;

          if (iVar8 == 1) {

            uVar11 = (uint)*(byte *)(param_11 + uVar6);

          }

        }

        auVar17 = *(undefined1 (*) [16])((int)(uVar11 * param_7) + param_6);

        fVar13 = auVar17._12_4_;

        piVar9[-2] = (int)((float)*(int *)(param_3 + 4) *

                          *(float *)((int)(uVar11 * param_9) + param_8));

        piVar9[-1] = (int)((float)*(int *)(param_3 + 8) *

                          *(float *)((longlong)(int)(uVar11 * param_9) + 4 + param_8));

        *piVar9 = (int)(param_14 * *(float *)((int)(uVar11 * param_5) + param_4));

        piVar9[1] = (int)(param_15 * *(float *)((longlong)(int)(uVar11 * param_5) + 4 + param_4));

        FUN_140263160(piVar9);

        fVar22 = auVar17._0_4_ * fVar1;

        if (0.0 <= fVar22) {

          auVar14 = ZEXT416((uint)fVar3);

          if (fVar22 <= fVar3) {

            auVar14 = ZEXT416((uint)fVar22);

          }

        }

        else {

          auVar14 = ZEXT816(0);

        }

        auVar15._4_12_ = auVar14._4_12_;

        auVar15._0_4_ = auVar14._0_4_ * fVar2;

        fVar22 = (float)thunk_FUN_1402e1d00(auVar15._0_8_);

        fVar23 = auVar17._4_4_ * fVar1;

        *(char *)(piVar9 + 2) = (char)(int)fVar22;

        if (0.0 <= fVar23) {

          auVar14 = ZEXT416((uint)fVar3);

          if (fVar23 <= fVar3) {

            auVar14 = ZEXT416((uint)fVar23);

          }

        }

        else {

          auVar14 = ZEXT816(0);

        }

        auVar16._4_12_ = auVar14._4_12_;

        auVar16._0_4_ = auVar14._0_4_ * fVar2;

        fVar22 = (float)thunk_FUN_1402e1d00(auVar16._0_8_);

        fVar23 = auVar17._8_4_ * fVar1;

        *(char *)((longlong)piVar9 + 9) = (char)(int)fVar22;

        if (0.0 <= fVar23) {

          auVar17 = ZEXT416((uint)fVar3);

          if (fVar23 <= fVar3) {

            auVar17 = ZEXT416((uint)fVar23);

          }

        }

        else {

          auVar17 = ZEXT816(0);

        }

        auVar18._4_12_ = auVar17._4_12_;

        auVar18._0_4_ = auVar17._0_4_ * fVar2;

        fVar22 = (float)thunk_FUN_1402e1d00(auVar18._0_8_);

        *(char *)((longlong)piVar9 + 10) = (char)(int)fVar22;

        if (0.0 <= fVar13) {

          auVar17 = ZEXT416((uint)fVar3);

          if (fVar13 <= fVar3) {

            auVar17 = ZEXT416((uint)fVar13);

          }

        }

        else {

          auVar17 = ZEXT816(0);

        }

        auVar19._4_12_ = auVar17._4_12_;

        auVar19._0_4_ = auVar17._0_4_ * fVar2;

        fVar13 = (float)thunk_FUN_1402e1d00(auVar19._0_8_);

        uVar10 = (ulonglong)((uint)uVar10 + 1);

        uVar6 = uVar6 + 1;

        *(char *)((longlong)piVar9 + 0xb) = (char)(int)fVar13;

        piVar9 = piVar9 + 5;

      } while ((longlong)uVar6 < lVar12);

    }

    uVar4 = 1;

  }

  return uVar4;

}





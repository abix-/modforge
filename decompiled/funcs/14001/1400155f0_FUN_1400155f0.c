// Address: 0x1400155f0
// Ghidra name: FUN_1400155f0
// ============ 0x1400155f0 FUN_1400155f0 (size=1250) ============


void FUN_1400155f0(uint *param_1,uint param_2)



{

  float *pfVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  uint uVar8;

  ulonglong uVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  

  param_1[8] = param_1[8] + 1;

  uVar8 = *param_1;

  uVar9 = (ulonglong)(int)uVar8;

  lVar7 = *(longlong *)(param_1 + 2);

  lVar12 = (longlong)(int)param_2;

  if (uVar8 == 0xffffffff) {

    *param_1 = param_2;

    *(undefined4 *)(lVar7 + 0x18 + lVar12 * 0x28) = 0xffffffff;

  }

  else {

    pfVar1 = (float *)(lVar7 + lVar12 * 0x28);

    fVar17 = *pfVar1;

    fVar16 = pfVar1[1];

    fVar25 = pfVar1[2];

    fVar24 = pfVar1[3];

    iVar5 = *(int *)(lVar7 + 0x1c + uVar9 * 0x28);

    while (iVar5 != -1) {

      uVar8 = (uint)uVar9;

      lVar6 = (longlong)(int)uVar8;

      fVar20 = *(float *)(lVar7 + 0xc + lVar6 * 0x28);

      fVar23 = *(float *)(lVar7 + 8 + lVar6 * 0x28);

      fVar22 = *(float *)(lVar7 + lVar6 * 0x28);

      fVar21 = fVar20;

      if (fVar20 <= fVar24) {

        fVar21 = fVar24;

      }

      fVar13 = *(float *)(lVar7 + 4 + lVar6 * 0x28);

      uVar4 = *(uint *)(lVar7 + 0x1c + lVar6 * 0x28);

      lVar10 = (longlong)(int)uVar4;

      uVar2 = *(uint *)(lVar7 + 0x20 + lVar6 * 0x28);

      lVar6 = (longlong)(int)uVar2;

      fVar14 = fVar13;

      if (fVar16 <= fVar13) {

        fVar14 = fVar16;

      }

      fVar18 = fVar22;

      if (fVar17 <= fVar22) {

        fVar18 = fVar17;

      }

      fVar19 = fVar23;

      if (fVar23 <= fVar25) {

        fVar19 = fVar25;

      }

      fVar23 = (fVar20 - fVar13) + (fVar23 - fVar22);

      fVar20 = (fVar21 - fVar14) + (fVar19 - fVar18);

      fVar20 = fVar20 + fVar20;

      if (*(int *)(lVar7 + 0x1c + lVar10 * 0x28) == -1) {

        fVar22 = *(float *)(lVar7 + 8 + lVar10 * 0x28);

        fVar21 = fVar25;

        if (fVar25 <= fVar22) {

          fVar21 = fVar22;

        }

        fVar22 = *(float *)(lVar7 + lVar10 * 0x28);

        fVar13 = fVar17;

        if (fVar22 <= fVar17) {

          fVar13 = fVar22;

        }

        fVar22 = *(float *)(lVar7 + 0xc + lVar10 * 0x28);

        fVar14 = fVar24;

        if (fVar24 <= fVar22) {

          fVar14 = fVar22;

        }

        fVar22 = *(float *)(lVar7 + 4 + lVar10 * 0x28);

        fVar18 = fVar16;

        if (fVar22 <= fVar16) {

          fVar18 = fVar22;

        }

        fVar22 = (fVar21 - fVar13) + (fVar14 - fVar18);

        fVar22 = fVar22 + fVar22;

      }

      else {

        fVar22 = *(float *)(lVar7 + 8 + lVar10 * 0x28);

        fVar21 = *(float *)(lVar7 + 0xc + lVar10 * 0x28);

        fVar13 = fVar24;

        if (fVar24 <= fVar21) {

          fVar13 = fVar21;

        }

        fVar21 = fVar25;

        if (fVar25 <= fVar22) {

          fVar21 = fVar22;

        }

        fVar18 = (*(float *)(lVar7 + 0xc + lVar10 * 0x28) - *(float *)(lVar7 + 4 + lVar10 * 0x28)) +

                 (fVar22 - *(float *)(lVar7 + lVar10 * 0x28));

        fVar22 = *(float *)(lVar7 + 4 + lVar10 * 0x28);

        fVar14 = fVar16;

        if (fVar22 <= fVar16) {

          fVar14 = fVar22;

        }

        fVar22 = *(float *)(lVar7 + lVar10 * 0x28);

        fVar19 = fVar17;

        if (fVar22 <= fVar17) {

          fVar19 = fVar22;

        }

        fVar22 = (fVar13 - fVar14) + (fVar21 - fVar19);

        fVar22 = (fVar22 + fVar22) - (fVar18 + fVar18);

      }

      if (*(int *)(lVar7 + 0x1c + lVar6 * 0x28) == -1) {

        fVar21 = *(float *)(lVar7 + 8 + lVar6 * 0x28);

        fVar13 = fVar25;

        if (fVar25 <= fVar21) {

          fVar13 = fVar21;

        }

        fVar21 = *(float *)(lVar7 + lVar6 * 0x28);

        fVar14 = fVar17;

        if (fVar21 <= fVar17) {

          fVar14 = fVar21;

        }

        fVar21 = *(float *)(lVar7 + 0xc + lVar6 * 0x28);

        fVar18 = fVar24;

        if (fVar24 <= fVar21) {

          fVar18 = fVar21;

        }

        fVar21 = *(float *)(lVar7 + 4 + lVar6 * 0x28);

        fVar19 = fVar16;

        if (fVar21 <= fVar16) {

          fVar19 = fVar21;

        }

        fVar21 = (fVar13 - fVar14) + (fVar18 - fVar19);

        fVar21 = fVar21 + fVar21;

      }

      else {

        fVar21 = *(float *)(lVar7 + 8 + lVar6 * 0x28);

        fVar13 = fVar25;

        if (fVar25 <= fVar21) {

          fVar13 = fVar21;

        }

        fVar14 = *(float *)(lVar7 + 0xc + lVar6 * 0x28);

        fVar18 = fVar24;

        if (fVar24 <= fVar14) {

          fVar18 = fVar14;

        }

        fVar19 = (*(float *)(lVar7 + 0xc + lVar6 * 0x28) - *(float *)(lVar7 + 4 + lVar6 * 0x28)) +

                 (fVar21 - *(float *)(lVar7 + lVar6 * 0x28));

        fVar21 = *(float *)(lVar7 + lVar6 * 0x28);

        fVar14 = fVar17;

        if (fVar21 <= fVar17) {

          fVar14 = fVar21;

        }

        fVar21 = *(float *)(lVar7 + 4 + lVar6 * 0x28);

        fVar15 = fVar16;

        if (fVar21 <= fVar16) {

          fVar15 = fVar21;

        }

        fVar21 = (fVar13 - fVar14) + (fVar18 - fVar15);

        fVar21 = (fVar21 + fVar21) - (fVar19 + fVar19);

      }

      fVar23 = fVar20 - (fVar23 + fVar23);

      fVar23 = fVar23 + fVar23;

      fVar21 = fVar23 + fVar21;

      fVar23 = fVar23 + fVar22;

      if ((fVar20 + fVar20 < fVar23) && (fVar20 + fVar20 < fVar21)) break;

      uVar8 = uVar2;

      if (fVar23 < fVar21) {

        uVar8 = uVar4;

      }

      uVar9 = (ulonglong)uVar8;

      iVar5 = *(int *)(lVar7 + 0x1c + (longlong)(int)uVar8 * 0x28);

    }

    lVar6 = (longlong)(int)uVar8;

    iVar5 = *(int *)(lVar7 + 0x18 + lVar6 * 0x28);

    lVar11 = (longlong)iVar5;

    uVar4 = FUN_1400153e0(param_1);

    lVar10 = (longlong)(int)uVar4;

    *(int *)(*(longlong *)(param_1 + 2) + 0x18 + lVar10 * 0x28) = iVar5;

    *(undefined8 *)(*(longlong *)(param_1 + 2) + 0x10 + lVar10 * 0x28) = 0;

    lVar7 = *(longlong *)(param_1 + 2);

    fVar20 = *(float *)(lVar7 + 4 + lVar6 * 0x28);

    if (fVar20 <= fVar16) {

      fVar16 = fVar20;

    }

    fVar20 = *(float *)(lVar7 + lVar6 * 0x28);

    if (fVar20 <= fVar17) {

      fVar17 = fVar20;

    }

    *(float *)(lVar7 + 4 + lVar10 * 0x28) = fVar16;

    *(float *)(lVar7 + lVar10 * 0x28) = fVar17;

    fVar17 = *(float *)(lVar7 + 0xc + lVar6 * 0x28);

    if (fVar24 <= fVar17) {

      fVar24 = fVar17;

    }

    fVar17 = *(float *)(lVar7 + 8 + lVar6 * 0x28);

    if (fVar25 <= fVar17) {

      fVar25 = fVar17;

    }

    *(float *)(lVar7 + 0xc + lVar10 * 0x28) = fVar24;

    *(float *)(lVar7 + 8 + lVar10 * 0x28) = fVar25;

    *(int *)(*(longlong *)(param_1 + 2) + 0x24 + lVar10 * 0x28) =

         *(int *)(*(longlong *)(param_1 + 2) + 0x24 + lVar6 * 0x28) + 1;

    lVar7 = *(longlong *)(param_1 + 2);

    if (iVar5 == -1) {

      *(uint *)(lVar7 + 0x1c + lVar10 * 0x28) = uVar8;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x20 + lVar10 * 0x28) = param_2;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x18 + lVar6 * 0x28) = uVar4;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x18 + lVar12 * 0x28) = uVar4;

      *param_1 = uVar4;

    }

    else {

      if (*(uint *)(lVar7 + 0x1c + lVar11 * 0x28) == uVar8) {

        *(uint *)(lVar7 + 0x1c + lVar11 * 0x28) = uVar4;

      }

      else {

        *(uint *)(lVar7 + 0x20 + lVar11 * 0x28) = uVar4;

      }

      *(uint *)(*(longlong *)(param_1 + 2) + 0x1c + lVar10 * 0x28) = uVar8;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x20 + lVar10 * 0x28) = param_2;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x18 + lVar6 * 0x28) = uVar4;

      *(uint *)(*(longlong *)(param_1 + 2) + 0x18 + lVar12 * 0x28) = uVar4;

    }

    iVar5 = *(int *)(*(longlong *)(param_1 + 2) + 0x18 + lVar12 * 0x28);

    while (iVar5 != -1) {

      iVar5 = FUN_140015c30(param_1,iVar5);

      lVar7 = (longlong)iVar5;

      iVar5 = *(int *)(*(longlong *)(param_1 + 2) + 0x1c + lVar7 * 0x28);

      lVar12 = (longlong)iVar5;

      iVar3 = *(int *)(*(longlong *)(param_1 + 2) + 0x20 + lVar7 * 0x28);

      lVar6 = (longlong)iVar3;

      if (iVar5 == -1) {

        FID_conflict__assert

                  (L"child1 != (-1)",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x133);

      }

      if (iVar3 == -1) {

        FID_conflict__assert

                  (L"child2 != (-1)",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x134);

      }

      lVar10 = *(longlong *)(param_1 + 2);

      iVar5 = *(int *)(lVar10 + 0x24 + lVar6 * 0x28);

      if (iVar5 < *(int *)(lVar10 + 0x24 + lVar12 * 0x28)) {

        iVar5 = *(int *)(lVar10 + 0x24 + lVar12 * 0x28);

      }

      *(int *)(lVar10 + 0x24 + lVar7 * 0x28) = iVar5 + 1;

      lVar10 = *(longlong *)(param_1 + 2);

      fVar17 = *(float *)(lVar10 + 4 + lVar12 * 0x28);

      fVar16 = *(float *)(lVar10 + lVar12 * 0x28);

      fVar25 = *(float *)(lVar10 + 4 + lVar6 * 0x28);

      if (fVar25 <= fVar17) {

        fVar17 = fVar25;

      }

      fVar25 = *(float *)(lVar10 + lVar6 * 0x28);

      if (fVar25 <= fVar16) {

        fVar16 = fVar25;

      }

      *(float *)(lVar10 + 4 + lVar7 * 0x28) = fVar17;

      *(float *)(lVar10 + lVar7 * 0x28) = fVar16;

      fVar17 = *(float *)(lVar10 + 0xc + lVar12 * 0x28);

      fVar16 = *(float *)(lVar10 + 8 + lVar12 * 0x28);

      fVar25 = *(float *)(lVar10 + 0xc + lVar6 * 0x28);

      if (fVar17 <= fVar25) {

        fVar17 = fVar25;

      }

      fVar25 = *(float *)(lVar10 + 8 + lVar6 * 0x28);

      if (fVar16 <= fVar25) {

        fVar16 = fVar25;

      }

      *(float *)(lVar10 + 0xc + lVar7 * 0x28) = fVar17;

      *(float *)(lVar10 + 8 + lVar7 * 0x28) = fVar16;

      iVar5 = *(int *)(*(longlong *)(param_1 + 2) + 0x18 + lVar7 * 0x28);

    }

  }

  return;

}





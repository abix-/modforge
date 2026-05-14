// Address: 0x140015c30
// Ghidra name: FUN_140015c30
// ============ 0x140015c30 FUN_140015c30 (size=1718) ============


int FUN_140015c30(int *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  int iVar6;

  longlong lVar7;

  int iVar8;

  int iVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  longlong lVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  

  lVar12 = (longlong)param_2;

  if (param_2 == -1) {

    FID_conflict__assert

              (L"iA != (-1)",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x17e);

  }

  lVar3 = *(longlong *)(param_1 + 2);

  iVar8 = *(int *)(lVar3 + 0x1c + lVar12 * 0x28);

  lVar14 = (longlong)iVar8;

  if ((iVar8 != -1) && (1 < *(int *)(lVar3 + 0x24 + lVar12 * 0x28))) {

    iVar9 = *(int *)(lVar3 + 0x20 + lVar12 * 0x28);

    lVar13 = (longlong)iVar9;

    if ((iVar8 < 0) || (param_1[5] <= iVar8)) {

      FID_conflict__assert

                (L"0 <= iB && iB < m_nodeCapacity",

                 L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x188);

    }

    if ((iVar9 < 0) || (param_1[5] <= iVar9)) {

      FID_conflict__assert

                (L"0 <= iC && iC < m_nodeCapacity",

                 L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x189);

    }

    lVar4 = *(longlong *)(param_1 + 2);

    iVar6 = *(int *)(lVar4 + 0x24 + lVar13 * 0x28) - *(int *)(lVar4 + 0x24 + lVar14 * 0x28);

    if (iVar6 < 2) {

      if (iVar6 < -1) {

        iVar9 = *(int *)(lVar4 + 0x1c + lVar14 * 0x28);

        lVar10 = (longlong)iVar9;

        iVar6 = *(int *)(lVar4 + 0x20 + lVar14 * 0x28);

        lVar11 = (longlong)iVar6;

        if ((iVar9 < 0) || (param_1[5] <= iVar9)) {

          FID_conflict__assert

                    (L"0 <= iD && iD < m_nodeCapacity",

                     L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x1d3);

        }

        if ((iVar6 < 0) || (param_1[5] <= iVar6)) {

          FID_conflict__assert

                    (L"0 <= iE && iE < m_nodeCapacity",

                     L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x1d4);

        }

        *(int *)(lVar4 + 0x1c + lVar14 * 0x28) = param_2;

        *(undefined4 *)(lVar4 + 0x18 + lVar14 * 0x28) =

             *(undefined4 *)(lVar3 + 0x18 + lVar12 * 0x28);

        *(int *)(lVar3 + 0x18 + lVar12 * 0x28) = iVar8;

        iVar2 = *(int *)(lVar4 + 0x18 + lVar14 * 0x28);

        lVar7 = (longlong)iVar2;

        if (iVar2 == -1) {

          *param_1 = iVar8;

        }

        else {

          lVar5 = *(longlong *)(param_1 + 2);

          if (*(int *)(lVar5 + 0x1c + lVar7 * 0x28) == param_2) {

            *(int *)(lVar5 + 0x1c + lVar7 * 0x28) = iVar8;

          }

          else {

            if (*(int *)(lVar5 + 0x20 + lVar7 * 0x28) != param_2) {

              FID_conflict__assert

                        (L"m_nodes[B->parent].child2 == iA",

                         L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x1e4);

            }

            *(int *)(*(longlong *)(param_1 + 2) + 0x20 +

                    (longlong)*(int *)(lVar4 + 0x18 + lVar14 * 0x28) * 0x28) = iVar8;

          }

        }

        if (*(int *)(lVar4 + 0x24 + lVar11 * 0x28) < *(int *)(lVar4 + 0x24 + lVar10 * 0x28)) {

          *(int *)(lVar4 + 0x20 + lVar14 * 0x28) = iVar9;

          *(int *)(lVar3 + 0x1c + lVar12 * 0x28) = iVar6;

          *(int *)(lVar4 + 0x18 + lVar11 * 0x28) = param_2;

          fVar18 = *(float *)(lVar4 + lVar13 * 0x28);

          fVar16 = *(float *)(lVar4 + 4 + lVar13 * 0x28);

          fVar17 = *(float *)(lVar4 + lVar11 * 0x28);

          if (fVar17 <= fVar18) {

            fVar18 = fVar17;

          }

          fVar17 = *(float *)(lVar4 + 4 + lVar11 * 0x28);

          if (fVar17 <= fVar16) {

            fVar16 = fVar17;

          }

          *(float *)(lVar3 + lVar12 * 0x28) = fVar18;

          *(float *)(lVar3 + 4 + lVar12 * 0x28) = fVar16;

          fVar17 = *(float *)(lVar4 + 0xc + lVar13 * 0x28);

          fVar15 = *(float *)(lVar4 + 8 + lVar13 * 0x28);

          fVar1 = *(float *)(lVar4 + 0xc + lVar11 * 0x28);

          if (fVar17 <= fVar1) {

            fVar17 = fVar1;

          }

          fVar1 = *(float *)(lVar4 + 8 + lVar11 * 0x28);

          if (fVar15 <= fVar1) {

            fVar15 = fVar1;

          }

          *(float *)(lVar3 + 0xc + lVar12 * 0x28) = fVar17;

          *(float *)(lVar3 + 8 + lVar12 * 0x28) = fVar15;

          fVar17 = *(float *)(lVar4 + 4 + lVar10 * 0x28);

          if (fVar17 <= fVar16) {

            fVar16 = fVar17;

          }

          fVar17 = *(float *)(lVar4 + lVar10 * 0x28);

          if (fVar17 <= fVar18) {

            fVar18 = fVar17;

          }

          *(float *)(lVar4 + 4 + lVar14 * 0x28) = fVar16;

          *(float *)(lVar4 + lVar14 * 0x28) = fVar18;

          fVar18 = *(float *)(lVar3 + 0xc + lVar12 * 0x28);

          fVar16 = *(float *)(lVar3 + 8 + lVar12 * 0x28);

          fVar17 = *(float *)(lVar4 + 0xc + lVar10 * 0x28);

          if (fVar18 <= fVar17) {

            fVar18 = fVar17;

          }

          fVar17 = *(float *)(lVar4 + 8 + lVar10 * 0x28);

          if (fVar16 <= fVar17) {

            fVar16 = fVar17;

          }

          *(float *)(lVar4 + 0xc + lVar14 * 0x28) = fVar18;

          *(float *)(lVar4 + 8 + lVar14 * 0x28) = fVar16;

          iVar9 = *(int *)(lVar4 + 0x24 + lVar11 * 0x28);

          if (iVar9 < *(int *)(lVar4 + 0x24 + lVar13 * 0x28)) {

            iVar9 = *(int *)(lVar4 + 0x24 + lVar13 * 0x28);

          }

          iVar9 = iVar9 + 1;

          *(int *)(lVar3 + 0x24 + lVar12 * 0x28) = iVar9;

          iVar6 = *(int *)(lVar4 + 0x24 + lVar10 * 0x28);

          if (iVar6 < iVar9) {

            iVar6 = iVar9;

          }

          *(int *)(lVar4 + 0x24 + lVar14 * 0x28) = iVar6 + 1;

          param_2 = iVar8;

        }

        else {

          *(int *)(lVar4 + 0x20 + lVar14 * 0x28) = iVar6;

          *(int *)(lVar3 + 0x1c + lVar12 * 0x28) = iVar9;

          *(int *)(lVar4 + 0x18 + lVar10 * 0x28) = param_2;

          fVar18 = *(float *)(lVar4 + lVar13 * 0x28);

          fVar16 = *(float *)(lVar4 + lVar10 * 0x28);

          if (fVar16 <= fVar18) {

            fVar18 = fVar16;

          }

          fVar16 = *(float *)(lVar4 + 4 + lVar13 * 0x28);

          fVar17 = *(float *)(lVar4 + 4 + lVar10 * 0x28);

          if (fVar17 <= fVar16) {

            fVar16 = fVar17;

          }

          *(float *)(lVar3 + lVar12 * 0x28) = fVar18;

          *(float *)(lVar3 + 4 + lVar12 * 0x28) = fVar16;

          fVar17 = *(float *)(lVar4 + 0xc + lVar13 * 0x28);

          fVar15 = *(float *)(lVar4 + 0xc + lVar10 * 0x28);

          if (fVar17 <= fVar15) {

            fVar17 = fVar15;

          }

          fVar15 = *(float *)(lVar4 + 8 + lVar13 * 0x28);

          fVar1 = *(float *)(lVar4 + 8 + lVar10 * 0x28);

          if (fVar15 <= fVar1) {

            fVar15 = fVar1;

          }

          *(float *)(lVar3 + 0xc + lVar12 * 0x28) = fVar17;

          *(float *)(lVar3 + 8 + lVar12 * 0x28) = fVar15;

          fVar17 = *(float *)(lVar4 + 4 + lVar11 * 0x28);

          if (fVar17 <= fVar16) {

            fVar16 = fVar17;

          }

          fVar17 = *(float *)(lVar4 + lVar11 * 0x28);

          if (fVar17 <= fVar18) {

            fVar18 = fVar17;

          }

          *(float *)(lVar4 + 4 + lVar14 * 0x28) = fVar16;

          *(float *)(lVar4 + lVar14 * 0x28) = fVar18;

          fVar18 = *(float *)(lVar3 + 0xc + lVar12 * 0x28);

          fVar16 = *(float *)(lVar3 + 8 + lVar12 * 0x28);

          fVar17 = *(float *)(lVar4 + 0xc + lVar11 * 0x28);

          if (fVar18 <= fVar17) {

            fVar18 = fVar17;

          }

          fVar17 = *(float *)(lVar4 + 8 + lVar11 * 0x28);

          if (fVar16 <= fVar17) {

            fVar16 = fVar17;

          }

          *(float *)(lVar4 + 0xc + lVar14 * 0x28) = fVar18;

          *(float *)(lVar4 + 8 + lVar14 * 0x28) = fVar16;

          iVar9 = *(int *)(lVar4 + 0x24 + lVar10 * 0x28);

          if (iVar9 < *(int *)(lVar4 + 0x24 + lVar13 * 0x28)) {

            iVar9 = *(int *)(lVar4 + 0x24 + lVar13 * 0x28);

          }

          iVar9 = iVar9 + 1;

          *(int *)(lVar3 + 0x24 + lVar12 * 0x28) = iVar9;

          iVar6 = *(int *)(lVar4 + 0x24 + lVar11 * 0x28);

          if (iVar6 < iVar9) {

            iVar6 = iVar9;

          }

          *(int *)(lVar4 + 0x24 + lVar14 * 0x28) = iVar6 + 1;

          param_2 = iVar8;

        }

      }

    }

    else {

      iVar8 = *(int *)(lVar4 + 0x1c + lVar13 * 0x28);

      lVar11 = (longlong)iVar8;

      iVar6 = *(int *)(lVar4 + 0x20 + lVar13 * 0x28);

      lVar10 = (longlong)iVar6;

      if ((iVar8 < 0) || (param_1[5] <= iVar8)) {

        FID_conflict__assert

                  (L"0 <= iF && iF < m_nodeCapacity",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x197);

      }

      if ((iVar6 < 0) || (param_1[5] <= iVar6)) {

        FID_conflict__assert

                  (L"0 <= iG && iG < m_nodeCapacity",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x198);

      }

      *(int *)(lVar4 + 0x1c + lVar13 * 0x28) = param_2;

      *(undefined4 *)(lVar4 + 0x18 + lVar13 * 0x28) = *(undefined4 *)(lVar3 + 0x18 + lVar12 * 0x28);

      *(int *)(lVar3 + 0x18 + lVar12 * 0x28) = iVar9;

      iVar2 = *(int *)(lVar4 + 0x18 + lVar13 * 0x28);

      lVar7 = (longlong)iVar2;

      if (iVar2 == -1) {

        *param_1 = iVar9;

      }

      else {

        lVar5 = *(longlong *)(param_1 + 2);

        if (*(int *)(lVar5 + 0x1c + lVar7 * 0x28) == param_2) {

          *(int *)(lVar5 + 0x1c + lVar7 * 0x28) = iVar9;

        }

        else {

          if (*(int *)(lVar5 + 0x20 + lVar7 * 0x28) != param_2) {

            FID_conflict__assert

                      (L"m_nodes[C->parent].child2 == iA",

                       L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x1a8);

          }

          *(int *)(*(longlong *)(param_1 + 2) + 0x20 +

                  (longlong)*(int *)(lVar4 + 0x18 + lVar13 * 0x28) * 0x28) = iVar9;

        }

      }

      if (*(int *)(lVar4 + 0x24 + lVar10 * 0x28) < *(int *)(lVar4 + 0x24 + lVar11 * 0x28)) {

        *(int *)(lVar4 + 0x20 + lVar13 * 0x28) = iVar8;

        *(int *)(lVar3 + 0x20 + lVar12 * 0x28) = iVar6;

        *(int *)(lVar4 + 0x18 + lVar10 * 0x28) = param_2;

        fVar18 = *(float *)(lVar4 + lVar14 * 0x28);

        fVar16 = *(float *)(lVar4 + 4 + lVar14 * 0x28);

        fVar17 = *(float *)(lVar4 + lVar10 * 0x28);

        if (fVar17 <= fVar18) {

          fVar18 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + 4 + lVar10 * 0x28);

        if (fVar17 <= fVar16) {

          fVar16 = fVar17;

        }

        *(float *)(lVar3 + lVar12 * 0x28) = fVar18;

        *(float *)(lVar3 + 4 + lVar12 * 0x28) = fVar16;

        fVar17 = *(float *)(lVar4 + 0xc + lVar14 * 0x28);

        fVar15 = *(float *)(lVar4 + 8 + lVar14 * 0x28);

        fVar1 = *(float *)(lVar4 + 0xc + lVar10 * 0x28);

        if (fVar17 <= fVar1) {

          fVar17 = fVar1;

        }

        fVar1 = *(float *)(lVar4 + 8 + lVar10 * 0x28);

        if (fVar15 <= fVar1) {

          fVar15 = fVar1;

        }

        *(float *)(lVar3 + 0xc + lVar12 * 0x28) = fVar17;

        *(float *)(lVar3 + 8 + lVar12 * 0x28) = fVar15;

        fVar17 = *(float *)(lVar4 + 4 + lVar11 * 0x28);

        if (fVar17 <= fVar16) {

          fVar16 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + lVar11 * 0x28);

        if (fVar17 <= fVar18) {

          fVar18 = fVar17;

        }

        *(float *)(lVar4 + 4 + lVar13 * 0x28) = fVar16;

        *(float *)(lVar4 + lVar13 * 0x28) = fVar18;

        fVar18 = *(float *)(lVar3 + 0xc + lVar12 * 0x28);

        fVar16 = *(float *)(lVar3 + 8 + lVar12 * 0x28);

        fVar17 = *(float *)(lVar4 + 0xc + lVar11 * 0x28);

        if (fVar18 <= fVar17) {

          fVar18 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + 8 + lVar11 * 0x28);

        if (fVar16 <= fVar17) {

          fVar16 = fVar17;

        }

        *(float *)(lVar4 + 0xc + lVar13 * 0x28) = fVar18;

        *(float *)(lVar4 + 8 + lVar13 * 0x28) = fVar16;

        iVar8 = *(int *)(lVar4 + 0x24 + lVar10 * 0x28);

        if (iVar8 < *(int *)(lVar4 + 0x24 + lVar14 * 0x28)) {

          iVar8 = *(int *)(lVar4 + 0x24 + lVar14 * 0x28);

        }

        iVar8 = iVar8 + 1;

        *(int *)(lVar3 + 0x24 + lVar12 * 0x28) = iVar8;

        iVar6 = *(int *)(lVar4 + 0x24 + lVar11 * 0x28);

        if (iVar6 < iVar8) {

          iVar6 = iVar8;

        }

        *(int *)(lVar4 + 0x24 + lVar13 * 0x28) = iVar6 + 1;

        param_2 = iVar9;

      }

      else {

        *(int *)(lVar4 + 0x20 + lVar13 * 0x28) = iVar6;

        *(int *)(lVar3 + 0x20 + lVar12 * 0x28) = iVar8;

        *(int *)(lVar4 + 0x18 + lVar11 * 0x28) = param_2;

        fVar18 = *(float *)(lVar4 + lVar14 * 0x28);

        fVar16 = *(float *)(lVar4 + 4 + lVar14 * 0x28);

        fVar17 = *(float *)(lVar4 + lVar11 * 0x28);

        if (fVar17 <= fVar18) {

          fVar18 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + 4 + lVar11 * 0x28);

        if (fVar17 <= fVar16) {

          fVar16 = fVar17;

        }

        *(float *)(lVar3 + lVar12 * 0x28) = fVar18;

        *(float *)(lVar3 + 4 + lVar12 * 0x28) = fVar16;

        fVar17 = *(float *)(lVar4 + 0xc + lVar14 * 0x28);

        fVar15 = *(float *)(lVar4 + 8 + lVar14 * 0x28);

        fVar1 = *(float *)(lVar4 + 0xc + lVar11 * 0x28);

        if (fVar17 <= fVar1) {

          fVar17 = fVar1;

        }

        fVar1 = *(float *)(lVar4 + 8 + lVar11 * 0x28);

        if (fVar15 <= fVar1) {

          fVar15 = fVar1;

        }

        *(float *)(lVar3 + 0xc + lVar12 * 0x28) = fVar17;

        *(float *)(lVar3 + 8 + lVar12 * 0x28) = fVar15;

        fVar17 = *(float *)(lVar4 + 4 + lVar10 * 0x28);

        if (fVar17 <= fVar16) {

          fVar16 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + lVar10 * 0x28);

        if (fVar17 <= fVar18) {

          fVar18 = fVar17;

        }

        *(float *)(lVar4 + 4 + lVar13 * 0x28) = fVar16;

        *(float *)(lVar4 + lVar13 * 0x28) = fVar18;

        fVar18 = *(float *)(lVar3 + 0xc + lVar12 * 0x28);

        fVar16 = *(float *)(lVar3 + 8 + lVar12 * 0x28);

        fVar17 = *(float *)(lVar4 + 0xc + lVar10 * 0x28);

        if (fVar18 <= fVar17) {

          fVar18 = fVar17;

        }

        fVar17 = *(float *)(lVar4 + 8 + lVar10 * 0x28);

        if (fVar16 <= fVar17) {

          fVar16 = fVar17;

        }

        *(float *)(lVar4 + 0xc + lVar13 * 0x28) = fVar18;

        *(float *)(lVar4 + 8 + lVar13 * 0x28) = fVar16;

        iVar8 = *(int *)(lVar4 + 0x24 + lVar11 * 0x28);

        if (iVar8 < *(int *)(lVar4 + 0x24 + lVar14 * 0x28)) {

          iVar8 = *(int *)(lVar4 + 0x24 + lVar14 * 0x28);

        }

        iVar8 = iVar8 + 1;

        *(int *)(lVar3 + 0x24 + lVar12 * 0x28) = iVar8;

        iVar6 = *(int *)(lVar4 + 0x24 + lVar10 * 0x28);

        if (iVar6 < iVar8) {

          iVar6 = iVar8;

        }

        *(int *)(lVar4 + 0x24 + lVar13 * 0x28) = iVar6 + 1;

        param_2 = iVar9;

      }

    }

  }

  return param_2;

}





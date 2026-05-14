// Address: 0x1400111f0
// Ghidra name: FUN_1400111f0
// ============ 0x1400111f0 FUN_1400111f0 (size=493) ============


void FUN_1400111f0(longlong param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  undefined8 *puVar5;

  longlong *plVar6;

  longlong lVar7;

  longlong lVar8;

  bool bVar9;

  bool bVar10;

  longlong lVar11;

  char cVar12;

  longlong lVar13;

  longlong lVar14;

  

  lVar11 = *(longlong *)(param_1 + 0x58);

  do {

    while( true ) {

      while( true ) {

        if (lVar11 == 0) {

          return;

        }

        lVar13 = *(longlong *)(lVar11 + 0x60);

        lVar14 = *(longlong *)(lVar11 + 0x68);

        iVar1 = *(int *)(lVar11 + 0x70);

        iVar2 = *(int *)(lVar11 + 0x74);

        piVar3 = *(int **)(lVar13 + 0x10);

        piVar4 = *(int **)(lVar14 + 0x10);

        if (((*(byte *)(piVar3 + 1) & 2) == 0) || (*piVar3 == 0)) {

          bVar9 = false;

        }

        else {

          bVar9 = true;

        }

        if (((*(byte *)(piVar4 + 1) & 2) == 0) || (*piVar4 == 0)) {

          bVar10 = false;

        }

        else {

          bVar10 = true;

        }

        if ((bVar9) || (bVar10)) break;

        lVar11 = *(longlong *)(lVar11 + 0x18);

      }

      if ((*(byte *)(lVar11 + 8) & 8) == 0) break;

      if ((*piVar4 == 2) || (*piVar3 == 2)) {

        for (puVar5 = *(undefined8 **)(piVar4 + 0x20); puVar5 != (undefined8 *)0x0;

            puVar5 = (undefined8 *)puVar5[3]) {

          if (((int *)*puVar5 == piVar3) && (*(char *)(puVar5[1] + 0x71) == '\0'))

          goto LAB_1400113a4;

        }

        plVar6 = *(longlong **)(param_1 + 0x68);

        if ((plVar6 == (longlong *)0x0) ||

           (cVar12 = (**(code **)(*plVar6 + 8))(plVar6,lVar13), cVar12 != '\0')) {

          *(uint *)(lVar11 + 8) = *(uint *)(lVar11 + 8) & 0xfffffff7;

          break;

        }

      }

LAB_1400113a4:

      lVar13 = *(longlong *)(lVar11 + 0x18);

      FUN_140011000(param_1,lVar11);

      lVar11 = lVar13;

    }

    iVar1 = *(int *)((longlong)iVar1 * 0x20 + 0x1c + *(longlong *)(lVar13 + 0x28));

    lVar13 = (longlong)iVar1;

    iVar2 = *(int *)((longlong)iVar2 * 0x20 + 0x1c + *(longlong *)(lVar14 + 0x28));

    lVar14 = (longlong)iVar2;

    if ((iVar1 < 0) || (*(int *)(param_1 + 0x14) <= iVar1)) {

      FID_conflict__assert

                (L"0 <= proxyId && proxyId < m_nodeCapacity",

                 L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.h",0x9f);

    }

    lVar7 = *(longlong *)(param_1 + 8);

    if ((iVar2 < 0) || (*(int *)(param_1 + 0x14) <= iVar2)) {

      FID_conflict__assert

                (L"0 <= proxyId && proxyId < m_nodeCapacity",

                 L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.h",0x9f);

    }

    lVar8 = *(longlong *)(param_1 + 8);

    if ((((0.0 < *(float *)(lVar8 + lVar14 * 0x28) - *(float *)(lVar7 + 8 + lVar13 * 0x28)) ||

         (0.0 < *(float *)(lVar8 + 4 + lVar14 * 0x28) - *(float *)(lVar7 + 0xc + lVar13 * 0x28))) ||

        (0.0 < *(float *)(lVar7 + lVar13 * 0x28) - *(float *)(lVar8 + 8 + lVar14 * 0x28))) ||

       (0.0 < *(float *)(lVar7 + 4 + lVar13 * 0x28) - *(float *)(lVar8 + 0xc + lVar14 * 0x28)))

    goto LAB_1400113a4;

    FUN_140010ce0(lVar11,*(undefined8 *)(param_1 + 0x70));

    lVar11 = *(longlong *)(lVar11 + 0x18);

  } while( true );

}





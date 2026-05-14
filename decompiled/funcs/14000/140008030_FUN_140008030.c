// Address: 0x140008030
// Ghidra name: FUN_140008030
// ============ 0x140008030 FUN_140008030 (size=688) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140008030(longlong param_1,longlong param_2,float *param_3,float *param_4)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  float fVar7;

  ulonglong uVar8;

  uint uVar9;

  ulonglong uVar10;

  longlong lVar11;

  float fVar12;

  float fVar13;

  float local_a8;

  float fStack_a4;

  float fStack_a0;

  float fStack_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  

  fVar7 = DAT_14039ca24;

  if ((*(int *)(param_1 + 0x30) != 0) && (uVar8 = 0, uVar10 = uVar8, 0 < *(int *)(param_1 + 0x30)))

  {

    do {

      lVar5 = *(longlong *)(param_1 + 0x28);

      (**(code **)(**(longlong **)(param_1 + 0x18) + 0x28))

                (*(longlong **)(param_1 + 0x18),&local_98,param_3,

                 *(undefined4 *)(uVar8 + 0x18 + lVar5));

      (**(code **)(**(longlong **)(param_1 + 0x18) + 0x28))

                (*(longlong **)(param_1 + 0x18),&local_88,param_4,

                 *(undefined4 *)(uVar8 + 0x18 + lVar5));

      fVar13 = local_98;

      if (local_88 <= local_98) {

        fVar13 = local_88;

      }

      fVar12 = local_94;

      if (local_84 <= local_94) {

        fVar12 = local_84;

      }

      *(float *)(uVar8 + lVar5) = fVar13;

      *(float *)(uVar8 + 4 + lVar5) = fVar12;

      fVar13 = local_8c;

      if (local_8c <= local_7c) {

        fVar13 = local_7c;

      }

      fVar12 = local_90;

      if (local_90 <= local_80) {

        fVar12 = local_80;

      }

      *(float *)(uVar8 + 0xc + lVar5) = fVar13;

      *(float *)(uVar8 + 8 + lVar5) = fVar12;

      iVar4 = *(int *)(uVar8 + 0x1c + lVar5);

      lVar11 = (longlong)iVar4;

      fVar13 = *param_4;

      fVar12 = param_4[1];

      fVar2 = *param_3;

      fVar3 = param_3[1];

      if ((iVar4 < 0) || (*(int *)(param_2 + 0x14) <= iVar4)) {

        FID_conflict__assert

                  (L"0 <= proxyId && proxyId < m_nodeCapacity",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x87);

      }

      if (*(int *)(*(longlong *)(param_2 + 8) + 0x1c + lVar11 * 0x28) != -1) {

        FID_conflict__assert

                  (L"m_nodes[proxyId].IsLeaf()",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x89);

      }

      lVar6 = *(longlong *)(param_2 + 8);

      if ((((*(float *)(uVar8 + lVar5) < *(float *)(lVar6 + lVar11 * 0x28)) ||

           (*(float *)(uVar8 + 4 + lVar5) < *(float *)(lVar6 + 4 + lVar11 * 0x28))) ||

          (*(float *)(lVar6 + 8 + lVar11 * 0x28) < *(float *)(uVar8 + 8 + lVar5))) ||

         (*(float *)(lVar6 + 0xc + lVar11 * 0x28) < *(float *)(uVar8 + 0xc + lVar5))) {

        FUN_140015ae0(param_2,iVar4);

        pfVar1 = (float *)(uVar8 + lVar5);

        fVar13 = (fVar13 - fVar2) + (fVar13 - fVar2);

        fStack_a0 = pfVar1[2] + fVar7;

        fStack_9c = pfVar1[3] + fVar7;

        fStack_a4 = pfVar1[1] - fVar7;

        local_a8 = *pfVar1 - fVar7;

        if (0.0 <= fVar13) {

          fStack_a0 = fVar13 + fStack_a0;

        }

        else {

          local_a8 = fVar13 + local_a8;

        }

        fVar13 = (fVar12 - fVar3) + (fVar12 - fVar3);

        if (0.0 <= fVar13) {

          fStack_9c = fVar13 + fStack_9c;

        }

        else {

          fStack_a4 = fVar13 + fStack_a4;

        }

        pfVar1 = (float *)(*(longlong *)(param_2 + 8) + lVar11 * 0x28);

        *pfVar1 = local_a8;

        pfVar1[1] = fStack_a4;

        pfVar1[2] = fStack_a0;

        pfVar1[3] = fStack_9c;

        FUN_1400155f0(param_2,iVar4);

        FUN_1400125b0(param_2,iVar4);

      }

      _DAT_1403ff7b0 = _DAT_1403ff7b0 + 1;

      uVar9 = (int)uVar10 + 1;

      uVar8 = uVar8 + 0x20;

      uVar10 = (ulonglong)uVar9;

    } while ((int)uVar9 < *(int *)(param_1 + 0x30));

  }

  return;

}





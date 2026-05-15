// Address: 0x14009edd0
// Ghidra name: FUN_14009edd0
// ============ 0x14009edd0 FUN_14009edd0 (size=567) ============


int FUN_14009edd0(longlong param_1,undefined8 *param_2,float param_3)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  float *pfVar5;

  bool bVar6;

  longlong *plVar7;

  longlong *plVar8;

  undefined8 *puVar9;

  longlong *plVar10;

  longlong *plVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  int iVar15;

  int iVar16;

  ulonglong uVar17;

  ulonglong uVar18;

  int iVar19;

  float fVar20;

  longlong *local_78;

  uint uStack_70;

  

  iVar3 = *(int *)(param_2 + 2);

  fVar20 = 0.0;

  iVar19 = 1;

  uVar14 = 0;

  if (0 < iVar3) {

    plVar1 = (longlong *)(param_1 + 0x10);

    uVar12 = 0xffffffff;

    uVar13 = uVar14;

    uVar17 = 0xffffffffffffffff;

    do {

      iVar16 = (int)uVar13;

      puVar9 = param_2;

      if (0xf < (ulonglong)param_2[3]) {

        puVar9 = (undefined8 *)*param_2;

      }

      iVar15 = (int)*(char *)(uVar14 + (longlong)puVar9);

      plVar7 = (longlong *)((longlong *)*plVar1)[1];

      cVar2 = *(char *)((longlong)plVar7 + 0x19);

      plVar8 = (longlong *)*plVar1;

      while (cVar2 == '\0') {

        plVar10 = plVar7;

        if ((int)plVar7[4] < iVar15) {

          plVar7 = plVar7 + 2;

          plVar10 = plVar8;

        }

        plVar7 = (longlong *)*plVar7;

        plVar8 = plVar10;

        cVar2 = *(char *)((longlong)plVar7 + 0x19);

      }

      if ((*(char *)((longlong)plVar8 + 0x19) == '\0') && ((int)plVar8[4] <= iVar15)) {

        uVar18 = uVar14;

        if ((iVar15 == 0x20) || (uVar13 = uVar12, uVar18 = uVar17, iVar15 != 10))

        goto LAB_14009eeac;

LAB_14009efc5:

        uVar18 = 0xffffffffffffffff;

        uVar13 = 0xffffffff;

        iVar19 = iVar19 + 1;

        fVar20 = 0.0;

      }

      else {

        iVar15 = 0x3f;

        uVar13 = uVar12;

        uVar18 = uVar17;

LAB_14009eeac:

        plVar7 = (longlong *)((longlong *)*plVar1)[1];

        uStack_70 = 0;

        cVar2 = *(char *)((longlong)plVar7 + 0x19);

        plVar8 = (longlong *)*plVar1;

        local_78 = plVar7;

        while (plVar10 = plVar7, cVar2 == '\0') {

          bVar6 = iVar15 <= (int)plVar10[4];

          plVar7 = plVar10;

          plVar11 = plVar10;

          if (!bVar6) {

            plVar7 = plVar10 + 2;

            plVar11 = plVar8;

          }

          uStack_70 = (uint)bVar6;

          cVar2 = *(char *)(*plVar7 + 0x19);

          plVar8 = plVar11;

          plVar7 = (longlong *)*plVar7;

          local_78 = plVar10;

        }

        if ((*(char *)((longlong)plVar8 + 0x19) != '\0') || (iVar15 < (int)plVar8[4])) {

          if (*(longlong *)(param_1 + 0x18) == 0x555555555555555) {

                    /* WARNING: Subroutine does not return */

            FUN_1400478f0();

          }

          lVar4 = *plVar1;

          plVar7 = (longlong *)FUN_1402c704c();

          *(int *)(plVar7 + 4) = iVar15;

          plVar7[5] = 0;

          *plVar7 = lVar4;

          plVar7[1] = lVar4;

          plVar7[2] = lVar4;

          *(undefined2 *)(plVar7 + 3) = 0;

          plVar8 = (longlong *)FUN_140047690(plVar1,&local_78,plVar7);

        }

        pfVar5 = (float *)plVar8[5];

        fVar20 = pfVar5[8] + *pfVar5 + pfVar5[9] + *(float *)(param_1 + 0x30) + fVar20;

        if ((param_3 < fVar20) && ((int)uVar13 != -1)) {

          puVar9 = param_2;

          if (0xf < (ulonglong)param_2[3]) {

            puVar9 = (undefined8 *)*param_2;

          }

          *(undefined1 *)((longlong)puVar9 + uVar18) = 10;

          uVar14 = uVar18;

          iVar16 = (int)uVar13;

          goto LAB_14009efc5;

        }

      }

      uVar14 = uVar14 + 1;

      uVar12 = uVar13;

      uVar13 = (ulonglong)(iVar16 + 1);

      uVar17 = uVar18;

    } while ((longlong)uVar14 < (longlong)iVar3);

  }

  return iVar19;

}





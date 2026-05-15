// Address: 0x1401bb850
// Ghidra name: FUN_1401bb850
// ============ 0x1401bb850 FUN_1401bb850 (size=492) ============


void FUN_1401bb850(longlong param_1,longlong *param_2,longlong param_3,ulonglong param_4)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  int iVar10;

  longlong *plVar11;

  

  iVar10 = 0;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  uVar5 = (int)param_2[6] - 1;

  if (-1 < (int)uVar5) {

    lVar2 = param_2[5];

    plVar11 = (longlong *)(lVar2 + (longlong)(int)uVar5 * 8);

    do {

      lVar1 = *(longlong *)(*plVar11 + 8);

      if (*(longlong *)(*plVar11 + 0x10) + lVar1 == param_3) {

        lVar2 = *(longlong *)(lVar2 + (ulonglong)uVar5 * 8);

        param_3 = *(longlong *)(lVar2 + 8);

LAB_1401bba1a:

        lVar2 = *(longlong *)(lVar2 + 0x10);

        FUN_1401bcb70(param_1);

        FUN_1401bb850(param_1,param_2,param_3,lVar2 + param_4);

        goto LAB_1401bb9e4;

      }

      if (lVar1 == param_3 + param_4) {

        lVar2 = *(longlong *)(lVar2 + (ulonglong)uVar5 * 8);

        goto LAB_1401bba1a;

      }

      plVar11 = plVar11 + -1;

      uVar5 = uVar5 - 1;

    } while (-1 < (int)uVar5);

  }

  uVar5 = (int)param_2[6] + 1;

  *(uint *)(param_2 + 6) = uVar5;

  if (*(uint *)((longlong)param_2 + 0x34) < uVar5) {

    uVar5 = *(uint *)((longlong)param_2 + 0x34) * 2;

    *(uint *)((longlong)param_2 + 0x34) = uVar5;

    lVar2 = FUN_140184230(param_2[5],(ulonglong)uVar5 << 3);

    param_2[5] = lVar2;

  }

  puVar3 = (undefined8 *)FUN_1401841f0(0x20);

  puVar3[1] = param_3;

  puVar3[2] = param_4;

  *puVar3 = param_2;

  param_2[8] = param_2[8] + param_4;

  *(undefined8 **)(param_2[5] + (ulonglong)((int)param_2[6] - 1) * 8) = puVar3;

  *(int *)(puVar3 + 3) = (int)param_2[6] + -1;

  if ((char)param_2[7] != '\0') {

    lVar2 = *param_2;

    uVar6 = 0;

    uVar5 = *(uint *)(lVar2 + 0x20);

    if (uVar5 != 0) {

      do {

        if (*(ulonglong *)(*(longlong *)(*(longlong *)(lVar2 + 0x18) + (ulonglong)uVar6 * 8) + 0x10)

            < param_4) break;

        iVar10 = iVar10 + 1;

        uVar6 = uVar6 + 1;

      } while (uVar6 < uVar5);

    }

    if (*(uint *)(lVar2 + 0x24) < uVar5 + 1) {

      *(uint *)(lVar2 + 0x24) = *(uint *)(lVar2 + 0x24) * 2;

      uVar4 = FUN_140184230(*(undefined8 *)(*param_2 + 0x18),

                            (ulonglong)*(uint *)(*param_2 + 0x24) << 3);

      *(undefined8 *)(*param_2 + 0x18) = uVar4;

    }

    iVar7 = *(int *)(*param_2 + 0x20);

    uVar8 = (ulonglong)iVar7;

    if ((iVar7 != 0) && (iVar10 != iVar7)) {

      uVar9 = uVar8;

      while (((longlong)iVar10 < (longlong)uVar8 && (iVar7 = (int)uVar9, 0 < iVar7))) {

        *(undefined8 *)(*(longlong *)(*param_2 + 0x18) + uVar8 * 8) =

             *(undefined8 *)(*(longlong *)(*param_2 + 0x18) + -8 + uVar8 * 8);

        lVar2 = uVar8 * 8;

        uVar8 = uVar8 - 1;

        *(int *)(*(longlong *)(*(longlong *)(*param_2 + 0x18) + lVar2) + 0x1c) = iVar7;

        uVar9 = (ulonglong)(iVar7 - 1);

      }

    }

    *(int *)(*param_2 + 0x20) = *(int *)(*param_2 + 0x20) + 1;

    *(undefined8 **)(*(longlong *)(*param_2 + 0x18) + (longlong)iVar10 * 8) = puVar3;

    *(int *)((longlong)puVar3 + 0x1c) = iVar10;

  }

LAB_1401bb9e4:

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return;

}





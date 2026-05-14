// Address: 0x1401c46c0
// Ghidra name: FUN_1401c46c0
// ============ 0x1401c46c0 FUN_1401c46c0 (size=872) ============


void FUN_1401c46c0(longlong param_1,longlong *param_2,longlong *param_3)



{

  undefined4 uVar1;

  longlong lVar2;

  longlong lVar3;

  bool bVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  longlong *plVar8;

  longlong *plVar9;

  longlong lVar10;

  undefined8 uVar11;

  int iVar12;

  longlong lVar13;

  bool bVar14;

  ulonglong in_stack_ffffffffffffff18;

  int local_c8;

  int local_c4;

  int local_c0;

  int local_bc;

  int local_b8;

  int local_b4;

  undefined8 local_b0;

  undefined4 local_a8;

  ulonglong local_a0;

  undefined4 local_98;

  int local_94;

  int local_90;

  int local_8c;

  int local_88;

  undefined8 local_80;

  undefined4 local_78;

  undefined4 local_70;

  

  lVar10 = *param_2;

  lVar2 = *(longlong *)(param_1 + 0x110);

  iVar7 = *(int *)((longlong)param_3 + 0xc);

  iVar12 = (int)param_3[2];

  plVar9 = (longlong *)0x0;

  lVar13 = lVar10;

  plVar8 = (longlong *)

           FUN_1401c9f20(lVar10,*(undefined4 *)((longlong)param_2 + 0xc),(int)param_2[1]);

  lVar3 = *(longlong *)(*param_3 + 0x10);

  if (iVar7 == 0) {

    iVar7 = *(int *)((longlong)param_2 + 0x1c);

  }

  uVar1 = *(undefined4 *)(lVar13 + 4);

  uVar5 = FUN_1401cd860(uVar1);

  iVar6 = FUN_140136a90(uVar1);

  iVar6 = iVar6 * (((uVar5 - 1) + iVar7) / uVar5);

  if (iVar12 == 0) {

    iVar12 = (int)param_2[4];

  }

  if (*(char *)(lVar2 + 0x9a) == '\0') {

    iVar7 = FUN_1401c5ab0(iVar6,0x100);

    if ((iVar12 == (int)param_2[4]) && (iVar6 == iVar7)) {

      bVar4 = false;

    }

    else {

      bVar4 = true;

    }

    bVar14 = (*(uint *)(param_3 + 1) & 0x1ff) != 0;

  }

  else {

    bVar4 = false;

    bVar14 = false;

    iVar7 = iVar6;

  }

  local_c0 = (int)param_2[3];

  local_94 = *(int *)((longlong)param_2 + 0x1c);

  local_78 = 0;

  local_70 = *(undefined4 *)((longlong)plVar8 + 0x14);

  local_80 = *(undefined8 *)(*plVar8 + 0x20);

  local_c8 = (int)param_2[2];

  local_bc = local_c8 + local_94;

  local_c4 = *(int *)((longlong)param_2 + 0x14);

  local_a8 = 1;

  local_b8 = local_c4 + iVar12;

  local_8c = *(int *)((longlong)param_2 + 0x24);

  local_b4 = local_8c + local_c0;

  local_98 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)*(int *)(lVar10 + 4) * 4);

  local_90 = iVar12;

  local_88 = iVar7;

  if ((bVar4) || (bVar14)) {

    plVar9 = (longlong *)FUN_1401841f0(0x30);

    if (plVar9 == (longlong *)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Failed to create texture download structure!");

    }

    in_stack_ffffffffffffff18 = 0;

    lVar10 = FUN_1401c7580(*(undefined8 *)(param_1 + 0x110),0,

                           iVar7 * *(int *)((longlong)param_2 + 0x24) * iVar12,3,0);

    plVar9[1] = lVar10;

    if (lVar10 == 0) {

      FUN_1401841e0(plVar9);

      return;

    }

    *plVar9 = lVar3;

    *(int *)((longlong)plVar9 + 0x1c) = (int)param_3[1];

    *(undefined4 *)(plVar9 + 2) = *(undefined4 *)((longlong)param_2 + 0x1c);

    *(int *)((longlong)plVar9 + 0x14) = iVar12;

    uVar1 = *(undefined4 *)((longlong)param_2 + 0x24);

    *(int *)(plVar9 + 4) = iVar6;

    *(undefined4 *)(plVar9 + 3) = uVar1;

    *(int *)(plVar9 + 5) = iVar7;

    *(int *)((longlong)plVar9 + 0x24) = iVar6 * iVar12;

    local_b0 = *(undefined8 *)(lVar10 + 0x10);

    local_a0 = 0;

    if (*(char *)(*(longlong *)(param_1 + 0x110) + 0x98) != '\0') {

      FUN_14012e2e0(9,"Texture pitch or offset not aligned properly! This is suboptimal on D3D12!");

    }

  }

  else {

    local_b0 = *(undefined8 *)(lVar3 + 0x10);

    local_a0 = (ulonglong)*(uint *)(param_3 + 1);

  }

  FUN_1401cb470(param_1,0x800,plVar8);

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x80))

            (*(longlong **)(param_1 + 0x120),&local_b0,0,0,

             in_stack_ffffffffffffff18 & 0xffffffff00000000,&local_80,&local_c8);

  FUN_1401cb4c0(param_1,0x800,plVar8);

  FUN_1401cb5f0(param_1,lVar3);

  FUN_1401cb900(param_1,*plVar8);

  if (plVar9 != (longlong *)0x0) {

    FUN_1401cb5f0(param_1,plVar9[1]);

    if (*(uint *)(param_1 + 0x9bc) <= *(uint *)(param_1 + 0x9b8)) {

      uVar5 = *(uint *)(param_1 + 0x9bc) * 2;

      *(uint *)(param_1 + 0x9bc) = uVar5;

      uVar11 = FUN_140184230(*(undefined8 *)(param_1 + 0x9b0),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_1 + 0x9b0) = uVar11;

    }

    *(longlong **)(*(longlong *)(param_1 + 0x9b0) + (ulonglong)*(uint *)(param_1 + 0x9b8) * 8) =

         plVar9;

    *(int *)(param_1 + 0x9b8) = *(int *)(param_1 + 0x9b8) + 1;

    FUN_1401cac30(*(undefined8 *)(param_1 + 0x110),plVar9[1]);

  }

  return;

}





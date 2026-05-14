// Address: 0x1401ccf50
// Ghidra name: FUN_1401ccf50
// ============ 0x1401ccf50 FUN_1401ccf50 (size=1209) ============


void FUN_1401ccf50(longlong param_1,longlong *param_2,longlong *param_3,undefined1 param_4)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  bool bVar4;

  undefined8 *puVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  bool bVar13;

  undefined8 in_stack_ffffffffffffff08;

  undefined8 uVar14;

  undefined4 uVar15;

  uint local_d4;

  longlong *local_b8;

  undefined8 local_a8;

  undefined4 local_a0;

  ulonglong local_98;

  undefined4 local_90;

  undefined4 local_8c;

  int local_88;

  undefined4 local_84;

  int local_80;

  undefined8 *local_78;

  ulonglong local_70;

  undefined8 local_68;

  undefined4 local_60;

  undefined4 local_58;

  

  lVar9 = *param_3;

  lVar2 = *(longlong *)(param_1 + 0x110);

  iVar12 = (int)param_2[2];

  iVar10 = *(int *)((longlong)param_2 + 0xc);

  lVar3 = *param_2;

  uVar14 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff08 >> 8),param_4);

  local_78 = (undefined8 *)

             FUN_1401ca910(param_1,lVar9,*(undefined4 *)((longlong)param_3 + 0xc),(int)param_3[1],

                           uVar14,0x400);

  uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);

  if (iVar10 == 0) {

    iVar10 = *(int *)((longlong)param_3 + 0x1c);

  }

  plVar1 = param_3 + 4;

  if (iVar12 == 0) {

    iVar12 = (int)*plVar1;

  }

  uVar6 = FUN_1401cd860(*(undefined4 *)(lVar9 + 4));

  iVar7 = FUN_140136a90(*(undefined4 *)(lVar9 + 4));

  iVar10 = (((uVar6 - 1) + iVar10) / uVar6) * iVar7;

  uVar11 = ((uVar6 - 1) + iVar12) / uVar6;

  if (*(char *)(lVar2 + 0x9a) == '\0') {

    iVar7 = FUN_1401c5ab0(((*(int *)((longlong)param_3 + 0x1c) + -1 + uVar6) / uVar6) * iVar7);

    if ((iVar12 == (int)*plVar1) && (iVar10 == iVar7)) {

      bVar4 = false;

    }

    else {

      bVar4 = true;

    }

    bVar13 = (*(uint *)(param_2 + 1) & 0x1ff) != 0;

  }

  else {

    bVar4 = false;

    bVar13 = false;

    iVar7 = iVar10;

  }

  local_b8 = param_3 + 4;

  local_a0 = 1;

  iVar8 = (int)*plVar1 * iVar7;

  local_90 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)*(int *)(lVar9 + 4) * 4);

  local_68 = *(undefined8 *)(*(longlong *)(lVar9 + 0x28) + 0x20);

  local_60 = 0;

  local_58 = *(undefined4 *)((longlong)local_78 + 0x14);

  local_80 = iVar7;

  if (bVar4) {

    uVar14 = 0;

    lVar9 = FUN_1401c7580(*(undefined8 *)(param_1 + 0x110),0,

                          iVar7 * *(int *)((longlong)param_3 + 0x24) * uVar11,2,0);

    if (lVar9 == 0) {

      return;

    }

    local_a8 = *(undefined8 *)(lVar9 + 0x10);

    local_d4 = 0;

    if (*(int *)((longlong)param_3 + 0x24) != 0) {

      do {

        uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);

        uVar6 = 0;

        if (uVar11 != 0) {

          local_70 = (ulonglong)(local_d4 * iVar8);

          do {

            FUN_1402f8e20((ulonglong)(uVar6 * iVar7) + *(longlong *)(lVar9 + 0x80) + local_70,

                          (ulonglong)*(uint *)(param_2 + 1) +

                          (ulonglong)(local_d4 * iVar10 * iVar12) +

                          (ulonglong)(uVar6 * iVar10) +

                          *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x80),iVar10);

            uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);

            uVar6 = uVar6 + 1;

          } while (uVar6 < uVar11);

        }

        local_8c = *(undefined4 *)((longlong)param_3 + 0x1c);

        local_84 = 1;

        local_88 = (int)*local_b8;

        local_98 = (ulonglong)(local_d4 * iVar8);

        uVar14 = CONCAT44(uVar15,(int)param_3[3] + local_d4);

        (**(code **)(**(longlong **)(param_1 + 0x120) + 0x80))

                  (*(longlong **)(param_1 + 0x120),&local_68,(int)param_3[2],

                   *(undefined4 *)((longlong)param_3 + 0x14),uVar14,&local_a8,0);

        local_d4 = local_d4 + 1;

      } while (local_d4 < *(uint *)((longlong)param_3 + 0x24));

    }

    FUN_1401cb5f0(param_1,lVar9);

    FUN_1401cac30(*(undefined8 *)(param_1 + 0x110),lVar9);

    if (*(char *)(*(longlong *)(param_1 + 0x110) + 0x98) != '\0') {

      FUN_14012e2e0(9,

                    "Texture upload row pitch not aligned to 256 bytes! This is suboptimal on D3D12!"

                   );

    }

  }

  else if (bVar13) {

    uVar15 = 0;

    lVar9 = FUN_1401c7580(*(undefined8 *)(param_1 + 0x110),0,

                          iVar7 * uVar11 * *(int *)((longlong)param_3 + 0x24),2,0);

    if (lVar9 == 0) {

      return;

    }

    FUN_1402f8e20(*(undefined8 *)(lVar9 + 0x80),

                  (ulonglong)*(uint *)(param_2 + 1) +

                  *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x80));

    local_a8 = *(undefined8 *)(lVar9 + 0x10);

    local_8c = *(undefined4 *)((longlong)param_3 + 0x1c);

    local_98 = 0;

    local_88 = (int)*local_b8;

    local_84 = *(undefined4 *)((longlong)param_3 + 0x24);

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0x80))

              (*(longlong **)(param_1 + 0x120),&local_68,(int)param_3[2],

               *(undefined4 *)((longlong)param_3 + 0x14),CONCAT44(uVar15,(int)param_3[3]),&local_a8,

               0);

    FUN_1401cb5f0(param_1,lVar9);

    FUN_1401cac30(*(undefined8 *)(param_1 + 0x110),lVar9);

    if (*(char *)(*(longlong *)(param_1 + 0x110) + 0x98) != '\0') {

      FUN_14012e2e0(9,"Texture upload offset not aligned to 512 bytes! This is suboptimal on D3D12!"

                   );

    }

  }

  else {

    local_a8 = *(undefined8 *)(*(longlong *)(lVar3 + 0x10) + 0x10);

    local_98 = (ulonglong)*(uint *)(param_2 + 1);

    local_8c = *(undefined4 *)((longlong)param_3 + 0x1c);

    local_84 = *(undefined4 *)((longlong)param_3 + 0x24);

    local_88 = (int)*plVar1;

    (**(code **)(**(longlong **)(param_1 + 0x120) + 0x80))

              (*(longlong **)(param_1 + 0x120),&local_68,(int)param_3[2],

               *(undefined4 *)((longlong)param_3 + 0x14),CONCAT44(uVar15,(int)param_3[3]),&local_a8,

               0);

  }

  puVar5 = local_78;

  FUN_1401cb4c0(param_1,0x400,local_78);

  FUN_1401cb5f0(param_1,*(undefined8 *)(lVar3 + 0x10));

  FUN_1401cb900(param_1,*puVar5);

  return;

}





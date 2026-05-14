// Address: 0x1401c27f0
// Ghidra name: FUN_1401c27f0
// ============ 0x1401c27f0 FUN_1401c27f0 (size=887) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401c27f0(longlong param_1,longlong *param_2,uint param_3,longlong *param_4)



{

  int iVar1;

  int *piVar2;

  undefined8 uVar3;

  uint uVar4;

  undefined8 *puVar5;

  undefined8 *puVar6;

  byte bVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint *puVar11;

  ulonglong uVar12;

  longlong *plVar13;

  ulonglong uVar14;

  uint local_res8;

  undefined8 auStack_200 [34];

  undefined8 uStack_f0;

  undefined8 *local_c8;

  undefined4 local_c0;

  undefined8 local_b8;

  uint local_a8;

  undefined8 local_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined4 local_88;

  undefined4 local_84;

  undefined1 local_78 [64];

  

  uVar4 = 0xffffffff;

  uVar9 = 0xffffffff;

  local_res8 = 0xffffffff;

  local_a8 = 0xffffffff;

  uVar12 = (ulonglong)param_3;

  uVar14 = (ulonglong)param_3;

  plVar13 = param_2;

  if (param_3 != 0) {

    do {

      bVar7 = (byte)(int)plVar13[1];

      uVar10 = *(uint *)(*plVar13 + 0x10) >> (bVar7 & 0x1f);

      uVar8 = *(uint *)(*plVar13 + 0xc) >> (bVar7 & 0x1f);

      if (uVar4 <= uVar8) {

        uVar8 = uVar4;

      }

      uVar4 = uVar8;

      if (uVar9 <= uVar10) {

        uVar10 = uVar9;

      }

      uVar9 = uVar10;

      uVar12 = uVar12 - 1;

      plVar13 = plVar13 + 8;

      local_res8 = uVar4;

      local_a8 = uVar9;

    } while (uVar12 != 0);

  }

  if (param_4 != (longlong *)0x0) {

    uVar4 = *(uint *)(*param_4 + 0xc) >> (*(byte *)((longlong)param_4 + 0x1e) & 0x1f);

    uVar9 = *(uint *)(*param_4 + 0x10) >> (*(byte *)((longlong)param_4 + 0x1e) & 0x1f);

    if (local_res8 <= uVar4) {

      uVar4 = local_res8;

    }

    local_res8 = uVar4;

    if (uVar9 < local_a8) {

      local_a8 = uVar9;

    }

  }

  if (param_3 != 0) {

    puVar6 = (undefined8 *)(param_1 + 0x188);

    puVar11 = (uint *)((longlong)param_2 + 0xc);

    do {

      piVar2 = *(int **)(puVar11 + -3);

      uVar4 = 0;

      if (*piVar2 != 2) {

        uVar4 = *puVar11;

      }

      local_c0 = 4;

      local_c8 = (undefined8 *)CONCAT71(local_c8._1_7_,(char)puVar11[0xb]);

      uStack_f0 = 0x1401c2910;

      puVar5 = (undefined8 *)FUN_1401ca910(param_1,piVar2,uVar4,puVar11[-1]);

      uVar4 = 0;

      if (*piVar2 == 2) {

        uVar4 = *puVar11;

      }

      uVar3 = *(undefined8 *)((ulonglong)uVar4 * 0x20 + 0x10 + puVar5[3]);

      if (puVar11[5] == 1) {

        local_98 = *(undefined8 *)(puVar11 + 1);

        uStack_90 = *(undefined8 *)(puVar11 + 3);

        local_c8 = (undefined8 *)0x0;

        uStack_f0 = 0x1401c2961;

        (**(code **)(**(longlong **)(param_1 + 0x120) + 0x180))

                  (*(longlong **)(param_1 + 0x120),uVar3,&local_98,0);

      }

      *(undefined8 *)((longlong)puVar6 + ((longlong)auStack_200 - param_1)) = uVar3;

      puVar6[-8] = puVar5;

      uStack_f0 = 0x1401c2978;

      FUN_1401cb900(param_1,*puVar5);

      if (puVar11[6] - 2 < 2) {

        local_c0 = 0x1000;

        local_c8 = (undefined8 *)CONCAT71(local_c8._1_7_,*(undefined1 *)((longlong)puVar11 + 0x2d));

        uStack_f0 = 0x1401c29a7;

        puVar5 = (undefined8 *)

                 FUN_1401ca910(param_1,*(undefined8 *)(puVar11 + 7),puVar11[10],puVar11[9]);

        *puVar6 = puVar5;

        uStack_f0 = 0x1401c29b5;

        FUN_1401cb900(param_1,*puVar5);

      }

      puVar6 = puVar6 + 1;

      puVar11 = puVar11 + 0x10;

      uVar14 = uVar14 - 1;

    } while (uVar14 != 0);

  }

  uVar4 = local_a8;

  if (param_4 != (longlong *)0x0) {

    local_c0 = 0x10;

    uStack_f0 = 0x1401c2a1d;

    local_c8._0_1_ = *(undefined1 *)((longlong)param_4 + 0x1c);

    puVar6 = (undefined8 *)

             FUN_1401ca910(param_1,*param_4,*(undefined1 *)((longlong)param_4 + 0x1f),

                           *(undefined1 *)((longlong)param_4 + 0x1e));

    iVar1 = *(int *)((longlong)param_4 + 0xc);

    if ((iVar1 == 1) || (*(int *)((longlong)param_4 + 0x14) == 1)) {

      local_b8 = 0;

      local_c0 = 0;

      bVar7 = iVar1 == 1 | 2;

      if (*(int *)((longlong)param_4 + 0x14) != 1) {

        bVar7 = iVar1 == 1;

      }

      local_c8._0_1_ = *(undefined1 *)((longlong)param_4 + 0x1d);

      uStack_f0 = 0x1401c2a7a;

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0x178))

                (*(longlong **)(param_1 + 0x120),puVar6[10],bVar7,(int)param_4[1]);

    }

    local_a0 = puVar6[10];

    *(undefined8 **)(param_1 + 0x1c8) = puVar6;

    uStack_f0 = 0x1401c2a95;

    FUN_1401cb900(param_1,*puVar6);

  }

  local_c8 = &local_a0;

  if (param_4 == (longlong *)0x0) {

    local_c8 = (undefined8 *)0x0;

  }

  uStack_f0 = 0x1401c2ac4;

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x170))

            (*(longlong **)(param_1 + 0x120),param_3,local_78,0);

  local_98 = 0;

  local_88 = 0;

  local_84 = 0x3f800000;

  uStack_90 = CONCAT44((float)uVar4,(float)local_res8);

  uStack_f0 = 0x1401c2b0b;

  FUN_1401cc600(param_1,&local_98);

  local_98 = 0;

  uStack_90 = CONCAT44(uVar4,local_res8);

  uStack_f0 = 0x1401c2b2a;

  FUN_1401cc3b0(param_1,&local_98);

  uStack_f0 = 0x1401c2b34;

  FUN_1401cc400(param_1,0);

  local_98 = _DAT_14030a340;

  uStack_90 = _UNK_14030a348;

  uStack_f0 = 0x1401c2b4e;

  FUN_1401cc2f0(param_1,&local_98);

  return;

}





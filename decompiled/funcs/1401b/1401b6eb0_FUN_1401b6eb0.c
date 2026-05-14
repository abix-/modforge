// Address: 0x1401b6eb0
// Ghidra name: FUN_1401b6eb0
// ============ 0x1401b6eb0 FUN_1401b6eb0 (size=805) ============


undefined8 FUN_1401b6eb0(longlong param_1,longlong param_2,uint param_3,longlong *param_4)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  uint *puVar4;

  int *piVar5;

  uint uVar6;

  uint *puVar7;

  int iVar8;

  uint uVar9;

  int iVar10;

  uint *puVar12;

  uint *puVar13;

  int local_res8 [2];

  undefined8 local_res20;

  undefined8 local_3b8;

  undefined4 local_3b0;

  undefined8 local_3a8;

  uint local_3a0;

  int *local_398;

  uint *local_390;

  int *local_388;

  undefined4 local_380;

  undefined8 local_378;

  undefined4 local_368 [2];

  undefined8 local_360;

  undefined4 local_358;

  int local_354;

  undefined4 *local_350;

  undefined4 local_348;

  undefined8 *local_340;

  undefined4 local_338;

  undefined8 local_330;

  uint local_328 [16];

  int local_2e8 [16];

  undefined4 local_2a8 [3];

  undefined8 uStack_29c;

  undefined4 auStack_294 [151];

  uint *puVar11;

  

  puVar13 = (uint *)0x0;

  iVar2 = 0;

  puVar12 = puVar13;

  if (param_3 != 0) {

    piVar5 = (int *)(param_2 + 0x24);

    puVar4 = puVar13;

    puVar7 = puVar13;

    do {

      lVar1 = *(longlong *)(piVar5 + -9);

      iVar8 = (int)puVar12;

      iVar2 = *piVar5;

      local_2a8[(longlong)puVar12 * 9] = 0;

      local_2a8[(longlong)puVar12 * 9 + 1] =

           *(undefined4 *)(&DAT_1403e3ec0 + (longlong)*(int *)(lVar1 + 4) * 4);

      iVar10 = *(int *)(lVar1 + 0x1c);

      auStack_294[(longlong)puVar12 * 9] = 2;

      auStack_294[(longlong)puVar12 * 9 + 1] = 1;

      auStack_294[(longlong)puVar12 * 9 + 2] = 2;

      local_2a8[(longlong)puVar12 * 9 + 2] = *(undefined4 *)(&DAT_1403e4250 + (longlong)iVar10 * 4);

      iVar10 = piVar5[-1];

      auStack_294[(longlong)puVar12 * 9 + 3] = 2;

      *(undefined4 *)((longlong)&uStack_29c + (longlong)puVar12 * 0x24) =

           *(undefined4 *)(&DAT_1403e4230 + (longlong)iVar10 * 4);

      auStack_294[(longlong)puVar12 * 9 + -1] =

           *(undefined4 *)(&DAT_1403e4240 + (longlong)iVar2 * 4);

      local_2e8[(longlong)puVar7 * 2] = iVar8;

      uVar9 = iVar8 + 1;

      puVar11 = (uint *)(ulonglong)uVar9;

      local_2e8[(longlong)puVar7 * 2 + 1] = 2;

      if (iVar2 - 2U < 2) {

        lVar1 = *(longlong *)(piVar5 + 1);

        local_2a8[(longlong)puVar11 * 9] = 0;

        puVar12 = (uint *)(ulonglong)(iVar8 + 2);

        puVar4 = (uint *)(ulonglong)((int)puVar4 + 1);

        local_2a8[(longlong)puVar11 * 9 + 1] =

             *(undefined4 *)(&DAT_1403e3ec0 + (longlong)*(int *)(lVar1 + 4) * 4);

        iVar2 = *(int *)(lVar1 + 0x1c);

        *(undefined8 *)((longlong)&uStack_29c + (longlong)puVar11 * 0x24) = 2;

        auStack_294[(longlong)puVar11 * 9] = 2;

        auStack_294[(longlong)puVar11 * 9 + 1] = 1;

        local_2a8[(longlong)puVar11 * 9 + 2] = *(undefined4 *)(&DAT_1403e4250 + (longlong)iVar2 * 4)

        ;

        auStack_294[(longlong)puVar11 * 9 + 2] = 2;

        auStack_294[(longlong)puVar11 * 9 + 3] = 2;

        local_328[(longlong)puVar7 * 2 + 1] = 2;

      }

      else {

        uVar9 = 0xffffffff;

        puVar12 = puVar11;

      }

      iVar2 = (int)puVar4;

      uVar6 = (int)puVar7 + 1;

      piVar5 = piVar5 + 0x10;

      local_328[(longlong)puVar7 * 2] = uVar9;

      puVar7 = (uint *)(ulonglong)uVar6;

    } while (uVar6 < param_3);

  }

  iVar10 = (int)puVar12;

  local_3b8 = 0;

  local_398 = local_2e8;

  local_3b0 = 0;

  local_3a8 = 0;

  local_380 = 0;

  local_378 = 0;

  if (param_4 == (longlong *)0x0) {

    local_388 = (int *)0x0;

    local_354 = iVar10;

  }

  else {

    lVar1 = *param_4;

    local_2a8[(longlong)puVar12 * 9] = 0;

    local_2a8[(longlong)puVar12 * 9 + 1] =

         *(undefined4 *)(&DAT_1403e3ec0 + (longlong)*(int *)(lVar1 + 4) * 4);

    iVar8 = *(int *)(lVar1 + 0x1c);

    local_354 = iVar10 + 1;

    auStack_294[(longlong)puVar12 * 9 + 2] = 3;

    auStack_294[(longlong)puVar12 * 9 + 3] = 3;

    local_2a8[(longlong)puVar12 * 9 + 2] = *(undefined4 *)(&DAT_1403e4250 + (longlong)iVar8 * 4);

    local_res8[1] = 3;

    *(undefined4 *)((longlong)&uStack_29c + (longlong)puVar12 * 0x24) =

         *(undefined4 *)(&DAT_1403e4230 + (longlong)*(int *)((longlong)param_4 + 0xc) * 4);

    auStack_294[(longlong)puVar12 * 9 + -1] =

         *(undefined4 *)(&DAT_1403e4240 + (longlong)(int)param_4[2] * 4);

    auStack_294[(longlong)puVar12 * 9] =

         *(undefined4 *)(&DAT_1403e4230 + (longlong)*(int *)((longlong)param_4 + 0x14) * 4);

    auStack_294[(longlong)puVar12 * 9 + 1] =

         *(undefined4 *)(&DAT_1403e4240 + (longlong)(int)param_4[3] * 4);

    local_388 = local_res8;

    local_res8[0] = iVar10;

  }

  local_368[0] = 0x26;

  local_360 = 0;

  local_390 = local_328;

  if (iVar2 == 0) {

    local_390 = puVar13;

  }

  local_358 = 0;

  local_350 = local_2a8;

  local_340 = &local_3b8;

  local_348 = 1;

  local_338 = 0;

  local_330 = 0;

  local_3a0 = param_3;

  iVar2 = (**(code **)(param_1 + 0xb50))(*(undefined8 *)(param_1 + 0x570),local_368,0,&local_res20);

  if (iVar2 != 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar3 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateRenderPass",uVar3);

    }

    uVar3 = FUN_1401c0ba0(iVar2);

    FUN_14012e850("%s %s","vkCreateRenderPass",uVar3);

    local_res20 = 0;

  }

  return local_res20;

}





// Address: 0x1401c3db0
// Ghidra name: FUN_1401c3db0
// ============ 0x1401c3db0 FUN_1401c3db0 (size=970) ============


undefined4 * FUN_1401c3db0(longlong param_1,longlong *param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  code *pcVar4;

  char cVar5;

  int iVar6;

  undefined4 *puVar7;

  undefined8 *puVar8;

  undefined8 uVar9;

  undefined4 *puVar10;

  int *piVar11;

  uint uVar12;

  ulonglong uVar13;

  undefined8 local_res8;

  longlong local_6e8;

  longlong lStack_6e0;

  longlong local_6d8;

  undefined4 uStack_6d0;

  undefined4 uStack_6cc;

  undefined8 local_6c8;

  undefined4 local_6c0;

  undefined8 local_6b8;

  undefined8 local_6b0;

  undefined8 local_6a8;

  undefined8 local_6a0;

  undefined8 local_698;

  undefined1 local_640 [328];

  undefined4 local_4f8;

  undefined1 local_4f4 [44];

  undefined1 local_4c8 [56];

  undefined1 *local_490;

  int local_488;

  undefined4 local_47c;

  uint local_478;

  undefined4 local_474 [8];

  undefined4 local_454;

  undefined4 local_450;

  undefined4 local_44c;

  undefined4 local_448;

  undefined8 local_440;

  undefined8 local_438;

  undefined4 local_430;

  undefined1 local_428 [1024];

  

  puVar1 = (undefined8 *)*param_2;

  puVar2 = (undefined8 *)param_2[1];

  if (*(char *)(param_1 + 0x98) != '\0') {

    if (*(int *)(puVar1 + 2) != 0) {

      do {

        iVar6 = FUN_14017f2a0(&DAT_1403e4a40,"D3D12_CreateGraphicsPipeline",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\d3d12\\SDL_gpu_d3d12.c",0xc5a);

      } while (iVar6 == 0);

      if (iVar6 == 1) {

        pcVar4 = (code *)swi(3);

        puVar7 = (undefined4 *)(*pcVar4)();

        return puVar7;

      }

    }

    if (*(int *)(puVar2 + 2) != 1) {

      do {

        iVar6 = FUN_14017f2a0(&DAT_1403e4a70,"D3D12_CreateGraphicsPipeline",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\d3d12\\SDL_gpu_d3d12.c",0xc5d);

      } while (iVar6 == 0);

      if (iVar6 == 1) {

        pcVar4 = (code *)swi(3);

        puVar7 = (undefined4 *)(*pcVar4)();

        return puVar7;

      }

    }

  }

  FUN_1402f94c0(&local_6b8,0,0x290);

  local_6b0 = *puVar1;

  local_6a8 = puVar1[1];

  local_6a0 = *puVar2;

  local_698 = puVar2[1];

  if ((int)param_2[5] != 0) {

    local_6e8 = param_2[2];

    lStack_6e0 = param_2[3];

    local_490 = local_428;

    local_6d8 = param_2[4];

    uStack_6d0 = (undefined4)param_2[5];

    uStack_6cc = *(undefined4 *)((longlong)param_2 + 0x2c);

    local_488 = (int)param_2[5];

    FUN_1401c7380(&local_6e8,local_428,*(undefined8 *)(param_1 + 0x80));

  }

  local_6e8 = *(longlong *)((longlong)param_2 + 0x34);

  lStack_6e0 = *(undefined8 *)((longlong)param_2 + 0x3c);

  local_6d8 = *(undefined8 *)((longlong)param_2 + 0x44);

  local_47c = *(undefined4 *)(&DAT_1403e4a18 + (longlong)(int)param_2[6] * 4);

  uStack_6d0 = *(undefined4 *)((longlong)param_2 + 0x4c);

  cVar5 = FUN_1401c72a0(&local_6e8,local_4f4);

  if ((cVar5 != '\0') && (cVar5 = FUN_1401c6d10(param_2,local_640), cVar5 != '\0')) {

    local_6e8 = *(longlong *)((longlong)param_2 + 0x5c);

    lStack_6e0 = *(undefined8 *)((longlong)param_2 + 100);

    local_6c0 = *(undefined4 *)((longlong)param_2 + 0x84);

    local_6d8 = *(undefined8 *)((longlong)param_2 + 0x6c);

    uStack_6d0 = *(undefined4 *)((longlong)param_2 + 0x74);

    uStack_6cc = (undefined4)param_2[0xf];

    local_6c8 = *(undefined8 *)((longlong)param_2 + 0x7c);

    cVar5 = FUN_1401c71c0(&local_6e8,local_4c8);

    if ((cVar5 != '\0') &&

       (puVar7 = (undefined4 *)FUN_1401841a0(1,0x78), puVar7 != (undefined4 *)0x0)) {

      local_4f8 = 0xffffffff;

      local_450 = *(undefined4 *)(&DAT_1403e49f0 + (longlong)(int)param_2[10] * 4);

      local_44c = 0;

      if (0 < (int)param_2[10]) {

        local_44c = 0xffffffff;

      }

      if ((char)param_2[0x13] != '\0') {

        local_454 = *(undefined4 *)

                     (&DAT_1403e45a0 + (longlong)*(int *)((longlong)param_2 + 0x94) * 4);

      }

      local_478 = *(uint *)(param_2 + 0x12);

      if (local_478 != 0) {

        piVar11 = (int *)param_2[0x11];

        uVar13 = (ulonglong)local_478;

        puVar10 = local_474;

        do {

          iVar6 = *piVar11;

          piVar11 = piVar11 + 9;

          *puVar10 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)iVar6 * 4);

          uVar13 = uVar13 - 1;

          puVar10 = puVar10 + 1;

        } while (uVar13 != 0);

      }

      local_430 = 0;

      local_438 = 0;

      local_440 = 0;

      local_448 = 0;

      puVar8 = (undefined8 *)FUN_1401c7fa0(param_1,puVar1,puVar2);

      if (puVar8 != (undefined8 *)0x0) {

        *(undefined8 **)(puVar7 + 10) = puVar8;

        local_6b8 = *puVar8;

        iVar6 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x50))

                          (*(longlong **)(param_1 + 0x70),&local_6b8,&DAT_140349368,&local_res8);

        if (-1 < iVar6) {

          *(undefined8 *)(puVar7 + 8) = local_res8;

          uVar13 = 0;

          if ((int)param_2[3] != 0) {

            do {

              uVar12 = (int)uVar13 + 1;

              puVar7[(ulonglong)*(uint *)(param_2[2] + uVar13 * 0x10) + 0xd] =

                   *(undefined4 *)(param_2[2] + 4 + uVar13 * 0x10);

              uVar13 = (ulonglong)uVar12;

            } while (uVar12 < *(uint *)(param_2 + 3));

          }

          puVar7[0xc] = (int)param_2[6];

          *puVar7 = *(undefined4 *)((longlong)puVar1 + 0x14);

          puVar7[1] = *(undefined4 *)(puVar1 + 4);

          puVar7[2] = *(undefined4 *)((longlong)puVar1 + 0x1c);

          puVar7[3] = *(undefined4 *)(puVar1 + 3);

          puVar7[4] = *(undefined4 *)((longlong)puVar2 + 0x14);

          puVar7[5] = *(undefined4 *)(puVar2 + 4);

          puVar7[6] = *(undefined4 *)((longlong)puVar2 + 0x1c);

          puVar7[7] = *(undefined4 *)(puVar2 + 3);

          FUN_140139010(puVar7 + 0x1d,0);

          if (*(char *)(param_1 + 0x98) == '\0') {

            return puVar7;

          }

          cVar5 = FUN_140174fc0((int)param_2[0x14],"SDL.gpu.graphicspipeline.create.name");

          if (cVar5 == '\0') {

            return puVar7;

          }

          uVar3 = *(undefined8 *)(puVar7 + 8);

          uVar9 = FUN_140174e70((int)param_2[0x14],"SDL.gpu.graphicspipeline.create.name",0);

          FUN_1401cb3d0(param_1,uVar3,uVar9);

          return puVar7;

        }

        FUN_1401cb240(param_1,"Could not create graphics pipeline state",iVar6);

      }

      FUN_1401c97a0(puVar7);

      return (undefined4 *)0x0;

    }

  }

  return (undefined4 *)0x0;

}





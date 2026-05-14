// Address: 0x1401b9790
// Ghidra name: FUN_1401b9790
// ============ 0x1401b9790 FUN_1401b9790 (size=654) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401b9790(undefined8 *param_1,undefined8 param_2)



{

  undefined4 *puVar1;

  undefined8 uVar2;

  longlong lVar3;

  longlong lVar4;

  char cVar5;

  int iVar6;

  undefined8 uVar7;

  code *pcVar8;

  ulonglong uVar9;

  undefined8 *puVar10;

  uint uVar11;

  ulonglong uVar12;

  longlong lVar13;

  undefined4 uVar14;

  longlong lVar15;

  uint local_res8 [2];

  undefined8 local_res10;

  undefined4 local_res18 [2];

  undefined8 local_res20;

  undefined8 auStack_90 [5];

  longlong alStack_68 [2];

  longlong local_58;

  longlong local_50;

  

  auStack_90[0] = 0x1401b97c0;

  local_res10 = param_2;

  iVar6 = (*(code *)param_1[299])(*param_1,local_res8,0);

  if (iVar6 == 0) {

    if (local_res8[0] == 0) {

      auStack_90[0] = 0x1401b9839;

      FUN_14012e0e0(9,"Failed to find any GPUs with Vulkan support");

    }

    else {

      uVar12 = (ulonglong)local_res8[0] * 8;

      uVar9 = uVar12 + 0xf;

      if (uVar9 <= uVar12) {

        uVar9 = 0xffffffffffffff0;

      }

      auStack_90[0] = 0x1401b9868;

      lVar3 = -(uVar9 & 0xfffffffffffffff0);

      uVar12 = (ulonglong)local_res8[0] * 6;

      lVar13 = (longlong)&local_58 + lVar3;

      uVar9 = uVar12 + 0xf;

      if (uVar9 <= uVar12) {

        uVar9 = 0xffffffffffffff0;

      }

      local_50 = lVar13;

      *(undefined8 *)((longlong)auStack_90 + lVar3) = 0x1401b9893;

      pcVar8 = (code *)param_1[299];

      lVar4 = -(uVar9 & 0xfffffffffffffff0);

      uVar7 = *param_1;

      lVar15 = (longlong)&local_58 + lVar4 + lVar3;

      local_58 = lVar15;

      *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b98b2;

      iVar6 = (*pcVar8)(uVar7,local_res8,lVar13);

      if (iVar6 == 5) {

        *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b98cc;

        FUN_14012e2e0(9,

                      "vkEnumeratePhysicalDevices returned VK_INCOMPLETE, will keep trying anyway..."

                     );

      }

      else if (iVar6 != 0) {

        *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b99d5;

        uVar7 = FUN_1401c0ba0(iVar6);

        *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b99e9;

        FUN_14012e2e0(9,"vkEnumeratePhysicalDevices failed: %s",uVar7);

        return 0;

      }

      uVar14 = 0;

      uVar7 = 0;

      uVar12 = 0;

      uVar9 = 0xffffffff;

      if (local_res8[0] != 0) {

        do {

          uVar2 = *(undefined8 *)(lVar13 + uVar12 * 8);

          lVar15 = lVar15 + uVar12 * 6;

          *(undefined4 **)((longlong)alStack_68 + lVar4 + lVar3) = local_res18;

          *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b9918;

          cVar5 = FUN_1401bb360(param_1,local_res10,uVar2,lVar15);

          if (cVar5 != '\0') {

            uVar2 = *(undefined8 *)(lVar13 + uVar12 * 8);

            *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b9933;

            local_res20 = uVar7;

            cVar5 = FUN_1401bb0a0(param_1,uVar2,lVar15,&local_res20);

            if (cVar5 != '\0') {

              uVar7 = local_res20;

              uVar9 = uVar12;

              uVar14 = local_res18[0];

            }

          }

          uVar11 = (int)uVar12 + 1;

          uVar12 = (ulonglong)uVar11;

          lVar13 = local_50;

          lVar15 = local_58;

        } while (uVar11 < local_res8[0]);

        iVar6 = (int)uVar9;

        if (iVar6 != -1) {

          puVar1 = (undefined4 *)(local_58 + (longlong)iVar6 * 6);

          *(undefined4 *)(param_1 + 0xb1) = *puVar1;

          *(undefined2 *)((longlong)param_1 + 0x58c) = *(undefined2 *)(puVar1 + 1);

          uVar7 = *(undefined8 *)(local_50 + (longlong)iVar6 * 8);

          puVar10 = param_1 + 2;

          *(undefined4 *)puVar10 = 0x3b9bb079;

          param_1[1] = uVar7;

          *(undefined4 *)(param_1 + 0xf8) = uVar14;

          if (*(char *)((longlong)param_1 + 0x58a) == '\0') {

            pcVar8 = (code *)param_1[0x131];

            puVar10 = param_1 + 4;

            param_1[3] = 0;

          }

          else {

            param_1[0x6c] = 0;

            *(undefined4 *)(param_1 + 0x6b) = 0x3b9dc7a0;

            param_1[3] = param_1 + 0x6b;

            pcVar8 = (code *)param_1[0x133];

          }

          *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b9a03;

          (*pcVar8)(uVar7,puVar10);

          pcVar8 = (code *)param_1[0x130];

          uVar7 = param_1[1];

          *(undefined8 *)((longlong)auStack_90 + lVar4 + lVar3) = 0x1401b9a17;

          (*pcVar8)(uVar7,param_1 + 0xb4);

          return 1;

        }

      }

    }

  }

  else {

    if (*(char *)((longlong)param_1 + 0x57c) != '\0') {

      auStack_90[0] = 0x1401b97d6;

      uVar7 = FUN_1401c0ba0(iVar6);

                    /* WARNING: Subroutine does not return */

      auStack_90[0] = 0x1401b97f1;

      FUN_14012e0b0(9,"%s %s","vkEnumeratePhysicalDevices",uVar7);

    }

    auStack_90[0] = 0x1401b97f8;

    uVar7 = FUN_1401c0ba0(iVar6);

    auStack_90[0] = 0x1401b980e;

    FUN_14012e850("%s %s","vkEnumeratePhysicalDevices",uVar7);

  }

  return 0;

}





// Address: 0x1401b5d50
// Ghidra name: FUN_1401b5d50
// ============ 0x1401b5d50 FUN_1401b5d50 (size=805) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401b5d50(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  uint uVar2;

  longlong lVar3;

  char cVar4;

  int iVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  undefined8 *puVar10;

  bool bVar11;

  uint local_res10 [2];

  int local_res18 [4];

  undefined *apuStack_f0 [5];

  longlong alStack_c8 [4];

  undefined8 local_a8 [3];

  undefined4 local_90;

  char *local_88;

  undefined4 local_80;

  undefined4 local_7c;

  undefined4 local_78 [2];

  undefined8 local_70;

  uint local_68;

  undefined8 *local_60;

  undefined4 local_58;

  undefined **local_50;

  int local_48;

  longlong local_40;

  

  local_80 = 0x2dd664;

  local_a8[0]._0_4_ = 0;

  local_a8[1] = 0;

  local_a8[2] = 0;

  local_90 = 0;

  local_88 = "SDLGPU";

  if (*(char *)(param_2 + 0x90) == '\0') {

    local_7c = 0x400000;

  }

  else {

    local_7c = *param_2;

  }

  apuStack_f0[0] = (undefined *)0x1401b5dbc;

  lVar6 = FUN_140174040(local_res10);

  if (lVar6 == 0) {

    apuStack_f0[0] = (undefined *)0x1401b5dc9;

    uVar7 = FUN_14012e730();

                    /* WARNING: Subroutine does not return */

    apuStack_f0[0] = &UNK_1401b5ddd;

    FUN_14012e0b0(9,"SDL_Vulkan_GetInstanceExtensions(): getExtensionCount: %s",uVar7);

  }

  uVar2 = param_2[0x94];

  uVar7 = *(undefined8 *)(param_2 + 0x96);

  uVar9 = (ulonglong)(local_res10[0] + 4 + uVar2) * 8;

  uVar8 = uVar9 + 0xf;

  if (uVar8 <= uVar9) {

    uVar8 = 0xffffffffffffff0;

  }

  apuStack_f0[0] = (undefined *)0x1401b5e20;

  lVar3 = -(uVar8 & 0xfffffffffffffff0);

  lVar1 = (longlong)local_a8 + lVar3;

  *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5e34;

  FUN_1402f8e20(lVar1,lVar6,(ulonglong)local_res10[0] << 3);

  puVar10 = (undefined8 *)(lVar1 + (ulonglong)local_res10[0] * 8);

  if (uVar2 != 0) {

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5e58;

    FUN_1402f8e20(puVar10,uVar7,(ulonglong)uVar2 * 8);

    puVar10 = puVar10 + uVar2;

  }

  local_res18[0] = 0;

  *(int **)((longlong)alStack_c8 + lVar3 + 0x10) = local_res18;

  *(longlong *)((longlong)alStack_c8 + lVar3 + 8) = param_1 + 0x591;

  *(longlong *)((longlong)alStack_c8 + lVar3) = param_1 + 0x590;

  *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5ea6;

  cVar4 = FUN_1401b52b0(lVar1,uVar2 + local_res10[0],param_1 + 0x58e,param_1 + 0x58f);

  if (cVar4 == '\0') {

    if (*(char *)(param_1 + 0x57c) == '\0') {

      uVar7 = *(undefined8 *)(lVar1 + (longlong)local_res18[0] * 8);

      *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5edf;

      FUN_14012e850("Required Vulkan instance extension \'%s\' not supported",uVar7);

      return 0;

    }

    uVar7 = *(undefined8 *)(lVar1 + (longlong)local_res18[0] * 8);

                    /* WARNING: Subroutine does not return */

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5ecf;

    FUN_14012e0b0(9,"Required Vulkan instance extension \'%s\' not supported",uVar7);

  }

  if (*(char *)(param_1 + 0x58e) == '\0') {

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5f1e;

    FUN_14012e2e0(9,"%s is not supported!");

  }

  else {

    *puVar10 = "VK_EXT_debug_utils";

    puVar10 = puVar10 + 1;

    local_res10[0] = local_res10[0] + 1;

  }

  if (*(char *)(param_1 + 0x58f) != '\0') {

    *puVar10 = "VK_EXT_swapchain_colorspace";

    puVar10 = puVar10 + 1;

    local_res10[0] = local_res10[0] + 1;

  }

  if (*(char *)(param_1 + 0x590) != '\0') {

    *puVar10 = "VK_KHR_get_physical_device_properties2";

    puVar10 = puVar10 + 1;

    local_res10[0] = local_res10[0] + 1;

  }

  bVar11 = *(char *)(param_1 + 0x591) != '\0';

  if (bVar11) {

    *puVar10 = "VK_KHR_portability_enumeration";

    local_res10[0] = local_res10[0] + 1;

  }

  local_68 = (uint)bVar11;

  local_78[0] = 1;

  local_48 = local_res10[0] + uVar2;

  local_70 = 0;

  local_50 = &PTR_s_VK_LAYER_KHRONOS_validation_1403e3e90;

  local_60 = local_a8;

  local_40 = lVar1;

  if (*(char *)(param_1 + 0x57c) != '\0') {

    local_58 = 1;

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5fdc;

    cVar4 = FUN_1401b54e0(&PTR_s_VK_LAYER_KHRONOS_validation_1403e3e90,1);

    if (cVar4 != '\0') {

      *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b6061;

      FUN_14012e0e0(9,"Validation layers enabled, expect debug level performance!");

      goto LAB_1401b5ff4;

    }

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b5ff1;

    FUN_14012e2e0(9,"Validation layers not found, continuing without validation");

  }

  local_58 = 0;

LAB_1401b5ff4:

  *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b6003;

  iVar5 = (*DAT_1403fce18)(local_78,0,param_1);

  if (iVar5 == 0) {

    uVar7 = 1;

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b6019;

      uVar7 = FUN_1401c0ba0(iVar5);

                    /* WARNING: Subroutine does not return */

      *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b6034;

      FUN_14012e0b0(9,"%s %s","vkCreateInstance",uVar7);

    }

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b603b;

    uVar7 = FUN_1401c0ba0(iVar5);

    *(undefined8 *)((longlong)apuStack_f0 + lVar3) = 0x1401b6051;

    FUN_14012e850("%s %s","vkCreateInstance",uVar7);

    uVar7 = 0;

  }

  return uVar7;

}





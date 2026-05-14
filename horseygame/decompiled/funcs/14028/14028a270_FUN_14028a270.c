// Address: 0x14028a270
// Ghidra name: FUN_14028a270
// ============ 0x14028a270 FUN_14028a270 (size=492) ============


undefined8 FUN_14028a270(longlong param_1,undefined *param_2)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  code *pcVar7;

  char *pcVar8;

  uint uVar9;

  undefined **ppuVar10;

  undefined *puVar11;

  uint local_res8 [2];

  undefined *local_res10;

  

  local_res10 = param_2;

  bVar1 = false;

  local_res8[0] = 0;

  bVar3 = false;

  bVar2 = false;

  if (*(longlong *)(param_1 + 0x678) != 0) {

    uVar5 = FUN_14012e850("Vulkan already loaded");

    return uVar5;

  }

  if (param_2 == (undefined *)0x0) {

    param_2 = (undefined *)FUN_140142960("SDL_VULKAN_LIBRARY");

    local_res10 = param_2;

  }

  ppuVar10 = &local_res10;

  if (param_2 == (undefined *)0x0) {

    ppuVar10 = &PTR_s_vulkan_1_dll_1403e79b8;

  }

  puVar11 = (undefined *)0x0;

  local_res10 = param_2;

  if (*(longlong *)(param_1 + 0x678) == 0) {

    puVar11 = *ppuVar10;

    lVar6 = FUN_1401885b0(puVar11);

    *(longlong *)(param_1 + 0x678) = lVar6;

    if (lVar6 == 0) {

      uVar5 = FUN_14012e850("Failed to load Vulkan Portability library");

      return uVar5;

    }

  }

  FUN_14012f1a0(param_1 + 0x574,puVar11,0x100);

  pcVar7 = (code *)FUN_140188550(*(undefined8 *)(param_1 + 0x678),"vkGetInstanceProcAddr");

  if (pcVar7 == (code *)0x0) {

    pcVar8 = "Failed to load vkGetInstanceProcAddr from Vulkan Portability library";

  }

  else {

    *(code **)(param_1 + 0x560) = pcVar7;

    lVar6 = (*pcVar7)(0,"vkEnumerateInstanceExtensionProperties");

    *(longlong *)(param_1 + 0x568) = lVar6;

    if ((lVar6 == 0) || (lVar6 = FUN_140241110(lVar6,local_res8), lVar6 == 0)) goto LAB_14028a365;

    uVar9 = 0;

    if (local_res8[0] != 0) {

      do {

        pcVar8 = (char *)((ulonglong)uVar9 * 0x104 + lVar6);

        iVar4 = strcmp("VK_KHR_surface",pcVar8);

        if (iVar4 == 0) {

          bVar1 = true;

        }

        else {

          iVar4 = strcmp("VK_EXT_headless_surface",pcVar8);

          bVar2 = bVar3;

          if (iVar4 == 0) {

            bVar3 = true;

            bVar2 = true;

          }

        }

        uVar9 = uVar9 + 1;

      } while (uVar9 < local_res8[0]);

    }

    FUN_1401841e0(lVar6);

    if (bVar1) {

      if (!bVar2) {

        FUN_14012e310("Installed Vulkan doesn\'t implement the VK_EXT_headless_surface extension");

      }

      return 1;

    }

    pcVar8 = "Installed Vulkan doesn\'t implement the VK_KHR_surface extension";

  }

  FUN_14012e850(pcVar8);

LAB_14028a365:

  FUN_140188670(*(undefined8 *)(param_1 + 0x678));

  *(undefined8 *)(param_1 + 0x678) = 0;

  return 0;

}





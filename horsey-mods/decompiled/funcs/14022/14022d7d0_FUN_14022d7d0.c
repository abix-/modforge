// Address: 0x14022d7d0
// Ghidra name: FUN_14022d7d0
// ============ 0x14022d7d0 FUN_14022d7d0 (size=448) ============


undefined4 FUN_14022d7d0(longlong param_1,char *param_2)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  undefined4 uVar4;

  int iVar5;

  char *pcVar6;

  longlong lVar7;

  code *pcVar8;

  uint uVar9;

  uint local_res8 [2];

  

  bVar1 = false;

  local_res8[0] = 0;

  bVar3 = false;

  bVar2 = false;

  if (*(longlong *)(param_1 + 0x678) != 0) {

    uVar4 = FUN_14012e850("Vulkan already loaded");

    return uVar4;

  }

  if (param_2 == (char *)0x0) {

    pcVar6 = (char *)FUN_140142960("SDL_VULKAN_LIBRARY");

    param_2 = "vulkan-1.dll";

    if (pcVar6 != (char *)0x0) {

      param_2 = pcVar6;

    }

  }

  lVar7 = FUN_1401885b0(param_2);

  *(longlong *)(param_1 + 0x678) = lVar7;

  if (lVar7 != 0) {

    FUN_14012f1a0(param_1 + 0x574,param_2,0x100);

    pcVar8 = (code *)FUN_140188550(*(undefined8 *)(param_1 + 0x678),"vkGetInstanceProcAddr");

    if (pcVar8 != (code *)0x0) {

      *(code **)(param_1 + 0x560) = pcVar8;

      lVar7 = (*pcVar8)(0,"vkEnumerateInstanceExtensionProperties");

      *(longlong *)(param_1 + 0x568) = lVar7;

      if ((lVar7 != 0) && (lVar7 = FUN_140241110(lVar7,local_res8), lVar7 != 0)) {

        uVar9 = 0;

        if (local_res8[0] != 0) {

          do {

            pcVar6 = (char *)((ulonglong)uVar9 * 0x104 + lVar7);

            iVar5 = strcmp("VK_KHR_surface",pcVar6);

            if (iVar5 == 0) {

              bVar1 = true;

            }

            else {

              iVar5 = strcmp("VK_KHR_win32_surface",pcVar6);

              bVar2 = bVar3;

              if (iVar5 == 0) {

                bVar3 = true;

                bVar2 = true;

              }

            }

            uVar9 = uVar9 + 1;

          } while (uVar9 < local_res8[0]);

        }

        FUN_1401841e0(lVar7);

        if (bVar1) {

          if (bVar2) {

            return 1;

          }

          pcVar6 = "Installed Vulkan doesn\'t implement the VK_KHR_win32_surface extension";

        }

        else {

          pcVar6 = "Installed Vulkan doesn\'t implement the VK_KHR_surface extension";

        }

        FUN_14012e850(pcVar6);

      }

    }

    FUN_140188670(*(undefined8 *)(param_1 + 0x678));

    *(undefined8 *)(param_1 + 0x678) = 0;

    return 0;

  }

  return 0;

}





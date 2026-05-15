// Address: 0x1401f9f40
// Ghidra name: FUN_1401f9f40
// ============ 0x1401f9f40 FUN_1401f9f40 (size=1449) ============


int FUN_1401f9f40(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  char *pcVar9;

  uint uVar10;

  ulonglong uVar11;

  uint uVar12;

  uint local_res8 [2];

  uint local_res10 [2];

  uint local_res18 [2];

  uint local_res20;

  uint local_68;

  int local_64;

  uint local_60;

  longlong local_58;

  

  uVar11 = 0;

  local_res18[0] = 0;

  local_68 = 0;

  local_60 = 0;

  iVar3 = (*DAT_1403fd100)(*(undefined8 *)(param_1 + 8),local_res18,0);

  if (iVar3 != 0) {

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

      uVar5 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkEnumeratePhysicalDevices()",uVar5);

    }

    uVar5 = FUN_140241280(iVar3);

    FUN_14012e850("%s: %s","vkEnumeratePhysicalDevices()",uVar5);

    return iVar3;

  }

  if (local_res18[0] == 0) {

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkEnumeratePhysicalDevices(): no physical devices");

    }

    FUN_14012e850(&DAT_14039bf30,"vkEnumeratePhysicalDevices(): no physical devices");

    return -0xd;

  }

  lVar6 = FUN_1401841f0((ulonglong)local_res18[0] << 3);

  local_58 = lVar6;

  iVar3 = (*DAT_1403fd100)(*(undefined8 *)(param_1 + 8),local_res18,lVar6);

  if (iVar3 == 0) {

    *(undefined8 *)(param_1 + 0x28) = 0;

    local_res20 = 0;

    uVar8 = uVar11;

    uVar7 = uVar11;

    if (local_res18[0] != 0) {

      do {

        uVar12 = (uint)uVar11;

        local_res8[0] = 0;

        local_res10[0] = 0;

        uVar5 = *(undefined8 *)(lVar6 + uVar11 * 8);

        (*DAT_1403fd118)(uVar5,(uint *)(param_1 + 0x30));

        if (0x3fffff < (*(uint *)(param_1 + 0x30) & 0xffc00000)) {

          (*DAT_1403fd120)(uVar5,param_1 + 0x368);

          (*DAT_1403fd110)(uVar5,param_1 + 0x570);

          (*DAT_1403fd128)(uVar5,local_res8,0);

          if (local_res8[0] != 0) {

            if (local_68 < local_res8[0]) {

              FUN_1401841e0(uVar7);

              local_68 = local_res8[0];

              uVar7 = FUN_1401841f0((ulonglong)local_res8[0] * 0x18);

              if (uVar7 == 0) {

                FUN_1401841e0(lVar6);

                FUN_1401841e0(uVar8);

                return -0xd;

              }

            }

            (*DAT_1403fd128)(uVar5,local_res8);

            uVar11 = 0;

            *(uint *)(param_1 + 0x66c) = local_res8[0];

            *(uint *)(param_1 + 0x670) = local_res8[0];

            uVar10 = local_res8[0];

            if (local_res8[0] != 0) {

              do {

                local_64 = 0;

                lVar1 = uVar11 * 0x18;

                iVar3 = (int)uVar11;

                if (*(int *)(lVar1 + 4 + uVar7) != 0) {

                  if ((*(byte *)(lVar1 + uVar7) & 1) != 0) {

                    *(int *)(param_1 + 0x66c) = iVar3;

                  }

                  iVar4 = (*DAT_1403fd148)(uVar5,uVar11,*(undefined8 *)(param_1 + 0x18),&local_64);

                  if (iVar4 != 0) {

                    FUN_1401841e0(local_58);

                    FUN_1401841e0(uVar7);

                    FUN_1401841e0(uVar8);

                    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

                    if (cVar2 != '\0') {

                      uVar5 = FUN_140241280(iVar4);

                    /* WARNING: Subroutine does not return */

                      FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfaceSupportKHR()",uVar5);

                    }

                    uVar5 = FUN_140241280(iVar4);

                    pcVar9 = "vkGetPhysicalDeviceSurfaceSupportKHR()";

                    goto LAB_1401fa4c0;

                  }

                  uVar10 = local_res8[0];

                  if ((local_64 != 0) &&

                     (*(int *)(param_1 + 0x670) = iVar3, lVar6 = local_58, uVar12 = local_res20,

                     (*(byte *)(lVar1 + uVar7) & 1) != 0)) break;

                }

                uVar11 = (ulonglong)(iVar3 + 1U);

                lVar6 = local_58;

                uVar12 = local_res20;

              } while (iVar3 + 1U < uVar10);

            }

            if ((*(uint *)(param_1 + 0x66c) != uVar10) && (*(uint *)(param_1 + 0x670) != uVar10)) {

              iVar3 = (*DAT_1403fd0f8)(uVar5,0,local_res10,0);

              if (iVar3 != 0) {

                FUN_1401841e0(lVar6);

                FUN_1401841e0(uVar7);

                FUN_1401841e0(uVar8);

                cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

                if (cVar2 != '\0') {

                  uVar5 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

                  FUN_14012e0b0(6,"%s: %s","vkEnumerateDeviceExtensionProperties()",uVar5);

                }

                uVar5 = FUN_140241280(iVar3);

                pcVar9 = "vkEnumerateDeviceExtensionProperties()";

LAB_1401fa4c0:

                FUN_14012e850("%s: %s",pcVar9,uVar5);

                return -0xd;

              }

              if (local_res10[0] != 0) {

                if (local_60 < local_res10[0]) {

                  FUN_1401841e0(uVar8);

                  local_60 = local_res10[0];

                  uVar8 = FUN_1401841f0((ulonglong)local_res10[0] * 0x104);

                  if (uVar8 == 0) {

                    FUN_1401841e0(lVar6);

                    FUN_1401841e0(uVar7);

                    return -0xd;

                  }

                }

                iVar3 = (*DAT_1403fd0f8)(uVar5,0);

                if (iVar3 != 0) {

                  FUN_1401841e0(lVar6);

                  FUN_1401841e0(uVar7);

                  FUN_1401841e0(uVar8);

                  cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

                  if (cVar2 == '\0') {

                    uVar5 = FUN_140241280(iVar3);

                    FUN_14012e850("%s: %s","vkEnumerateDeviceExtensionProperties()",uVar5);

                    return iVar3;

                  }

                  uVar5 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

                  FUN_14012e0b0(6,"%s: %s","vkEnumerateDeviceExtensionProperties()",uVar5);

                }

                if (local_res10[0] != 0) {

                  uVar11 = 0;

                  do {

                    iVar3 = strcmp((char *)(uVar11 * 0x104 + uVar8),"VK_KHR_swapchain");

                    if (iVar3 == 0) {

                      *(undefined8 *)(param_1 + 0x28) = uVar5;

                      goto LAB_1401fa38c;

                    }

                    uVar10 = (int)uVar11 + 1;

                    uVar11 = (ulonglong)uVar10;

                  } while (uVar10 < local_res10[0]);

                }

              }

            }

          }

        }

        local_res20 = uVar12 + 1;

        uVar11 = (ulonglong)local_res20;

      } while (local_res20 < local_res18[0]);

    }

LAB_1401fa38c:

    FUN_1401841e0(lVar6);

    FUN_1401841e0(uVar7);

    FUN_1401841e0(uVar8);

    if (*(longlong *)(param_1 + 0x28) == 0) {

      cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar2 != '\0') {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,&DAT_14039bf30,"No viable physical devices found");

      }

      FUN_14012e850(&DAT_14039bf30,"No viable physical devices found");

      iVar3 = -0xd;

    }

    else {

      iVar3 = 0;

    }

  }

  else {

    FUN_1401841e0(lVar6);

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

      uVar5 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkEnumeratePhysicalDevices()",uVar5);

    }

    uVar5 = FUN_140241280(iVar3);

    FUN_14012e850("%s: %s","vkEnumeratePhysicalDevices()",uVar5);

  }

  return iVar3;

}





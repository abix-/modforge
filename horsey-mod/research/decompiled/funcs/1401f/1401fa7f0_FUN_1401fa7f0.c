// Address: 0x1401fa7f0
// Ghidra name: FUN_1401fa7f0
// ============ 0x1401fa7f0 FUN_1401fa7f0 (size=359) ============


int FUN_1401fa7f0(longlong param_1)



{

  uint *puVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  

  puVar1 = (uint *)(param_1 + 0x2878);

  iVar3 = (*DAT_1403fd138)(*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x18),puVar1,0)

  ;

  if (iVar3 != 0) {

    *puVar1 = 0;

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

      uVar4 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfaceFormatsKHR()",uVar4);

    }

    uVar4 = FUN_140241280(iVar3);

    FUN_14012e850("%s: %s","vkGetPhysicalDeviceSurfaceFormatsKHR()",uVar4);

    return iVar3;

  }

  if (*(uint *)(param_1 + 0x2874) < *puVar1) {

    *(uint *)(param_1 + 0x2874) = *puVar1;

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x6e0));

    uVar4 = FUN_1401841f0((ulonglong)*(uint *)(param_1 + 0x2874) << 3);

    *(undefined8 *)(param_1 + 0x6e0) = uVar4;

  }

  iVar3 = (*DAT_1403fd138)(*(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x18),puVar1,

                           *(undefined8 *)(param_1 + 0x6e0));

  if (iVar3 != 0) {

    *puVar1 = 0;

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

      uVar4 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfaceFormatsKHR()",uVar4);

    }

    uVar4 = FUN_140241280(iVar3);

    FUN_14012e850("%s: %s","vkGetPhysicalDeviceSurfaceFormatsKHR()",uVar4);

    return iVar3;

  }

  return 0;

}





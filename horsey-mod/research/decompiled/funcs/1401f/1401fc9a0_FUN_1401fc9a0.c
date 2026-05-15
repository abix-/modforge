// Address: 0x1401fc9a0
// Ghidra name: FUN_1401fc9a0
// ============ 0x1401fc9a0 FUN_1401fc9a0 (size=302) ============


undefined8 FUN_1401fc9a0(undefined8 *param_1)



{

  char cVar1;

  

  DAT_1403fd0c8 = (*(code *)*param_1)(0,"vkCreateInstance");

  if (DAT_1403fd0c8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkCreateInstance\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkCreateInstance\") failed");

    return 0;

  }

  DAT_1403fd0d0 = (*(code *)*param_1)(0,"vkEnumerateInstanceExtensionProperties");

  if (DAT_1403fd0d0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceExtensionProperties\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceExtensionProperties\") failed"

                 );

    return 0;

  }

  DAT_1403fd0d8 = (*(code *)*param_1)(0,"vkEnumerateInstanceLayerProperties");

  if (DAT_1403fd0d8 != 0) {

    return 1;

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,&DAT_14039bf30,

                  "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceLayerProperties\") failed"

                 );

  }

  FUN_14012e850(&DAT_14039bf30,

                "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceLayerProperties\") failed"

               );

  return 0;

}





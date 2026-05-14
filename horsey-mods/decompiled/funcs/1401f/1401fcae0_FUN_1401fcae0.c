// Address: 0x1401fcae0
// Ghidra name: FUN_1401fcae0
// ============ 0x1401fcae0 FUN_1401fcae0 (size=1587) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1401fcae0(undefined8 *param_1)



{

  char cVar1;

  

  DAT_1403fd0e0 = (*(code *)*param_1)(param_1[1],"vkCreateDevice");

  if (DAT_1403fd0e0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkCreateDevice\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkCreateDevice\") failed");

    return 0;

  }

  DAT_1403fd0e8 = (*(code *)*param_1)(param_1[1],"vkDestroyInstance");

  if (DAT_1403fd0e8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkDestroyInstance\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkDestroyInstance\") failed");

    return 0;

  }

  DAT_1403fd0f0 = (*(code *)*param_1)(param_1[1],"vkDestroySurfaceKHR");

  if (DAT_1403fd0f0 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkDestroySurfaceKHR\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkDestroySurfaceKHR\") failed");

    return 0;

  }

  DAT_1403fd0f8 = (*(code *)*param_1)(param_1[1],"vkEnumerateDeviceExtensionProperties");

  if (DAT_1403fd0f8 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkEnumerateDeviceExtensionProperties\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkEnumerateDeviceExtensionProperties\") failed"

                 );

    return 0;

  }

  DAT_1403fd100 = (*(code *)*param_1)(param_1[1],"vkEnumeratePhysicalDevices");

  if (DAT_1403fd100 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkEnumeratePhysicalDevices\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkEnumeratePhysicalDevices\") failed");

    return 0;

  }

  DAT_1403fd108 = (*(code *)*param_1)(param_1[1],"vkGetDeviceProcAddr");

  if (DAT_1403fd108 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetDeviceProcAddr\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkGetDeviceProcAddr\") failed");

    return 0;

  }

  DAT_1403fd110 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceFeatures");

  if (DAT_1403fd110 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceFeatures\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceFeatures\") failed");

    return 0;

  }

  DAT_1403fd118 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceProperties");

  if (DAT_1403fd118 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceProperties\") failed");

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceProperties\") failed");

    return 0;

  }

  DAT_1403fd120 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceMemoryProperties");

  if (DAT_1403fd120 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceMemoryProperties\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceMemoryProperties\") failed")

    ;

    return 0;

  }

  DAT_1403fd128 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceQueueFamilyProperties");

  if (DAT_1403fd128 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceQueueFamilyProperties\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceQueueFamilyProperties\") failed"

                 );

    return 0;

  }

  DAT_1403fd130 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceSurfaceCapabilitiesKHR");

  if (DAT_1403fd130 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceCapabilitiesKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceCapabilitiesKHR\") failed"

                 );

    return 0;

  }

  DAT_1403fd138 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceSurfaceFormatsKHR");

  if (DAT_1403fd138 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceFormatsKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceFormatsKHR\") failed"

                 );

    return 0;

  }

  DAT_1403fd140 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceSurfacePresentModesKHR");

  if (DAT_1403fd140 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfacePresentModesKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfacePresentModesKHR\") failed"

                 );

    return 0;

  }

  DAT_1403fd148 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceSurfaceSupportKHR");

  if (DAT_1403fd148 == 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,

                    "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceSupportKHR\") failed"

                   );

    }

    FUN_14012e850(&DAT_14039bf30,

                  "vkGetInstanceProcAddr(instance, \"vkGetPhysicalDeviceSurfaceSupportKHR\") failed"

                 );

    return 0;

  }

  _DAT_1403fd150 = (*(code *)*param_1)(param_1[1],"vkQueueWaitIdle");

  if (_DAT_1403fd150 != 0) {

    _DAT_1403fd158 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceFeatures2KHR");

    _DAT_1403fd160 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceFormatProperties2KHR");

    _DAT_1403fd168 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceImageFormatProperties2KHR");

    _DAT_1403fd170 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceMemoryProperties2KHR");

    _DAT_1403fd178 = (*(code *)*param_1)(param_1[1],"vkGetPhysicalDeviceProperties2KHR");

    return 1;

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkQueueWaitIdle\") failed");

  }

  FUN_14012e850(&DAT_14039bf30,"vkGetInstanceProcAddr(instance, \"vkQueueWaitIdle\") failed");

  return 0;

}





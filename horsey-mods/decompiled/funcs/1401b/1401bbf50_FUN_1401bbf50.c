// Address: 0x1401bbf50
// Ghidra name: FUN_1401bbf50
// ============ 0x1401bbf50 FUN_1401bbf50 (size=828) ============


undefined1 FUN_1401bbf50(undefined8 *param_1,longlong param_2,undefined4 param_3)



{

  undefined8 uVar1;

  char cVar2;

  undefined1 uVar3;

  

  FUN_1401bb5b0();

  FUN_1402f94c0(param_2,0,0x260);

  cVar2 = FUN_1401749e0(param_3,"SDL.gpu.device.create.feature.anisotropy",1);

  *(uint *)(param_2 + 0x50) = (uint)(cVar2 != '\0');

  cVar2 = FUN_1401749e0(param_3,"SDL.gpu.device.create.feature.depth_clamping",1);

  *(uint *)(param_2 + 0x30) = (uint)(cVar2 != '\0');

  cVar2 = FUN_1401749e0(param_3,"SDL.gpu.device.create.feature.clip_distance",1);

  *(uint *)(param_2 + 0x98) = (uint)(cVar2 != '\0');

  cVar2 = FUN_1401749e0(param_3,"SDL.gpu.device.create.feature.indirect_draw_first_instance",1);

  *(undefined4 *)(param_2 + 0x10) = 1;

  *(undefined4 *)(param_2 + 0x1c) = 1;

  *(undefined4 *)(param_2 + 0xc) = 1;

  *(uint *)(param_2 + 0x2c) = (uint)(cVar2 != '\0');

  FUN_1401b2ae0(param_3,param_1,param_2);

  uVar3 = FUN_1401749e0(param_3,"SDL.gpu.device.create.vulkan.requirehardwareacceleration",0);

  *(undefined1 *)((longlong)param_1 + 0x57e) = uVar3;

  cVar2 = FUN_1401b5d50(param_1,param_2);

  if (cVar2 == '\0') {

    FUN_14012e2e0(9,"Vulkan: Could not create Vulkan instance");

    uVar3 = 0;

  }

  else {

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetDeviceProcAddr");

    param_1[0x127] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkCreateDevice");

    param_1[0x128] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkDestroyInstance");

    param_1[0x129] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkEnumerateDeviceExtensionProperties");

    param_1[0x12a] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkEnumeratePhysicalDevices");

    param_1[299] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceFeatures");

    param_1[300] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceQueueFamilyProperties");

    param_1[0x12d] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceFormatProperties");

    param_1[0x12e] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceImageFormatProperties");

    param_1[0x12f] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceMemoryProperties");

    param_1[0x130] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceProperties");

    param_1[0x131] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceFeatures2");

    param_1[0x132] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceProperties2KHR");

    param_1[0x133] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkDestroySurfaceKHR");

    param_1[0x134] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceSurfaceCapabilitiesKHR");

    param_1[0x135] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceSurfaceFormatsKHR");

    param_1[0x136] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceSurfacePresentModesKHR");

    param_1[0x137] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkGetPhysicalDeviceSurfaceSupportKHR");

    param_1[0x138] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkCmdBeginDebugUtilsLabelEXT");

    param_1[0x139] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkSetDebugUtilsObjectNameEXT");

    param_1[0x13a] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkCmdEndDebugUtilsLabelEXT");

    param_1[0x13b] = uVar1;

    uVar1 = (*DAT_1403fce10)(*param_1,"vkCmdInsertDebugUtilsLabelEXT");

    param_1[0x13c] = uVar1;

    cVar2 = FUN_1401b9790(param_1,param_2);

    if (cVar2 == '\0') {

      FUN_14012e2e0(9,"Vulkan: Failed to determine a suitable physical device");

      uVar3 = 0;

    }

    else {

      uVar3 = 1;

    }

  }

  return uVar3;

}





// Address: 0x14022d740
// Ghidra name: FUN_14022d740
// ============ 0x14022d740 FUN_14022d740 (size=143) ============


undefined1 FUN_14022d740(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  undefined1 uVar1;

  int iVar2;

  code *pcVar3;

  

  pcVar3 = (code *)(**(code **)(param_1 + 0x560))

                             (param_2,"vkGetPhysicalDeviceWin32PresentationSupportKHR");

  if (*(longlong *)(param_1 + 0x678) == 0) {

    uVar1 = FUN_14012e850("Vulkan is not loaded");

    return uVar1;

  }

  if (pcVar3 == (code *)0x0) {

    uVar1 = FUN_14012e850("VK_KHR_win32_surface extension is not enabled in the Vulkan instance.");

    return uVar1;

  }

  iVar2 = (*pcVar3)(param_3,param_4);

  return iVar2 != 0;

}





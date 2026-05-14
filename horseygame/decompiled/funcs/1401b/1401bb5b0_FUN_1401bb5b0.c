// Address: 0x1401bb5b0
// Ghidra name: FUN_1401bb5b0
// ============ 0x1401bb5b0 FUN_1401bb5b0 (size=252) ============


void FUN_1401bb5b0(void)



{

  undefined8 uVar1;

  char cVar2;

  

  FUN_140179780("MVK_CONFIG_FULL_IMAGE_VIEW_SWIZZLE",&DAT_140338120,1);

  cVar2 = FUN_140174130(0);

  if (cVar2 == '\0') {

    FUN_14012e2e0(9,"Vulkan: SDL_Vulkan_LoadLibrary failed!");

    return;

  }

  DAT_1403fce10 = (code *)FUN_1401740e0();

  if (DAT_1403fce10 == (code *)0x0) {

    uVar1 = FUN_14012e730();

    FUN_14012e2e0(9,"SDL_Vulkan_GetVkGetInstanceProcAddr(): %s",uVar1);

    return;

  }

  DAT_1403fce18 = (*DAT_1403fce10)(0,"vkCreateInstance");

  if (DAT_1403fce18 == 0) {

    FUN_14012e2e0(9,"vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkCreateInstance\") failed");

    return;

  }

  DAT_1403fce20 = (*DAT_1403fce10)(0,"vkEnumerateInstanceExtensionProperties");

  if (DAT_1403fce20 == 0) {

    FUN_14012e2e0(9,

                  "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceExtensionProperties\") failed"

                 );

    return;

  }

  DAT_1403fce28 = (*DAT_1403fce10)(0,"vkEnumerateInstanceLayerProperties");

  if (DAT_1403fce28 == 0) {

    FUN_14012e2e0(9,

                  "vkGetInstanceProcAddr(VK_NULL_HANDLE, \"vkEnumerateInstanceLayerProperties\") failed"

                 );

    return;

  }

  return;

}





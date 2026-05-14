// Address: 0x14022d620
// Ghidra name: FUN_14022d620
// ============ 0x14022d620 FUN_14022d620 (size=211) ============


undefined8

FUN_14022d620(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,

             undefined8 param_5)



{

  longlong lVar1;

  int iVar2;

  code *pcVar3;

  undefined8 uVar4;

  undefined4 local_38 [2];

  undefined8 local_30;

  undefined4 local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  pcVar3 = (code *)(**(code **)(param_1 + 0x560))(param_3,"vkCreateWin32SurfaceKHR");

  if (*(longlong *)(param_1 + 0x678) == 0) {

    uVar4 = FUN_14012e850("Vulkan is not loaded");

  }

  else if (pcVar3 == (code *)0x0) {

    uVar4 = FUN_14012e850("VK_KHR_win32_surface extension is not enabled in the Vulkan instance.");

  }

  else {

    local_38[0] = 0x3b9aed28;

    local_30 = 0;

    local_28 = 0;

    local_20 = *(undefined8 *)(lVar1 + 0x28);

    local_18 = *(undefined8 *)(lVar1 + 8);

    iVar2 = (*pcVar3)(param_3,local_38,param_4,param_5);

    if (iVar2 == 0) {

      uVar4 = 1;

    }

    else {

      uVar4 = FUN_140241280(iVar2);

      uVar4 = FUN_14012e850("vkCreateWin32SurfaceKHR failed: %s",uVar4);

    }

  }

  return uVar4;

}





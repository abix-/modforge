// Address: 0x14028a100
// Ghidra name: FUN_14028a100
// ============ 0x14028a100 FUN_14028a100 (size=183) ============


undefined8

FUN_14028a100(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined8 *param_5)



{

  int iVar1;

  undefined8 uVar2;

  code *pcVar3;

  undefined8 local_28;

  undefined8 local_20;

  undefined8 local_18;

  

  *param_5 = 0;

  if (*(longlong *)(param_1 + 0x678) == 0) {

    uVar2 = FUN_14012e850("Vulkan is not loaded");

  }

  else {

    pcVar3 = (code *)(**(code **)(param_1 + 0x560))(param_3,"vkCreateHeadlessSurfaceEXT");

    if (pcVar3 == (code *)0x0) {

      uVar2 = FUN_14012e850(

                           "VK_EXT_headless_surface extension is not enabled in the Vulkan instance."

                           );

    }

    else {

      local_28 = 0x3b9eb200;

      local_18 = 0;

      local_20 = 0;

      iVar1 = (*pcVar3)(param_3,&local_28,param_4,param_5);

      if (iVar1 == 0) {

        uVar2 = 1;

      }

      else {

        uVar2 = FUN_140241280(iVar1);

        uVar2 = FUN_14012e850("vkCreateHeadlessSurfaceEXT failed: %s",uVar2);

      }

    }

  }

  return uVar2;

}





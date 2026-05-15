// Address: 0x140241110
// Ghidra name: FUN_140241110
// ============ 0x140241110 FUN_140241110 (size=280) ============


longlong FUN_140241110(code *param_1,int *param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  int local_res8 [2];

  

  local_res8[0] = 0;

  iVar1 = (*param_1)(0,local_res8,0);

  if (iVar1 == -9) {

    uVar2 = FUN_140241280(0xfffffff7);

    FUN_14012e850("You probably don\'t have a working Vulkan driver installed. %s %s %s(%d)",

                  "Getting Vulkan extensions failed:",

                  "vkEnumerateInstanceExtensionProperties returned",uVar2,0xfffffff7);

  }

  else {

    if (iVar1 != 0) {

      uVar2 = FUN_140241280(iVar1);

      FUN_14012e850("Getting Vulkan extensions failed: vkEnumerateInstanceExtensionProperties returned %s(%d)"

                    ,uVar2,iVar1);

      return 0;

    }

    iVar1 = 1;

    if (local_res8[0] != 0) {

      iVar1 = local_res8[0];

    }

    lVar3 = FUN_1401841a0(iVar1,0x104);

    if (lVar3 != 0) {

      iVar1 = (*param_1)(0,local_res8,lVar3);

      if (iVar1 != 0) {

        uVar2 = FUN_140241280(iVar1);

        FUN_14012e850("Getting Vulkan extensions failed: vkEnumerateInstanceExtensionProperties returned %s(%d)"

                      ,uVar2,iVar1);

        FUN_1401841e0(lVar3);

        return 0;

      }

      *param_2 = local_res8[0];

      return lVar3;

    }

  }

  return 0;

}





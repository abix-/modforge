// Address: 0x1401b2fa0
// Ghidra name: FUN_1401b2fa0
// ============ 0x1401b2fa0 FUN_1401b2fa0 (size=542) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8

FUN_1401b2fa0(longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined8 param_5

             )



{

  code *pcVar1;

  longlong lVar2;

  int iVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  undefined8 *puVar7;

  char *pcVar8;

  undefined8 auStack_60 [5];

  undefined8 local_38 [3];

  uint local_20;

  undefined8 *local_18;

  

  uVar6 = (ulonglong)param_4;

  uVar4 = uVar6 * 8 + 0xf;

  if (uVar4 <= uVar6 * 8) {

    uVar4 = 0xffffffffffffff0;

  }

  auStack_60[0] = 0x1401b2fe0;

  lVar2 = -(uVar4 & 0xfffffffffffffff0);

  puVar7 = (undefined8 *)((longlong)local_38 + lVar2);

  if (param_4 != 0) {

    for (; uVar6 != 0; uVar6 = uVar6 - 1) {

      *puVar7 = param_3;

      puVar7 = puVar7 + 1;

    }

  }

  pcVar1 = *(code **)(param_1 + 0x9f0);

  uVar5 = *(undefined8 *)(param_1 + 0x570);

  local_38[0]._0_4_ = 0x22;

  local_38[1] = 0;

  local_38[2] = param_2;

  local_20 = param_4;

  local_18 = (undefined8 *)((longlong)local_38 + lVar2);

  *(undefined8 *)((longlong)auStack_60 + lVar2) = 0x1401b302d;

  iVar3 = (*pcVar1)(uVar5,local_38,param_5);

  if (iVar3 == 0) {

    return 1;

  }

  if (*(char *)(param_1 + 0x57c) == '\0') {

    *(undefined8 *)((longlong)auStack_60 + lVar2) = 0x1401b3180;

    uVar5 = FUN_1401c0ba0(iVar3);

    *(undefined8 *)((longlong)auStack_60 + lVar2) = 0x1401b3196;

    FUN_14012e850("%s %s","vkAllocateDescriptorSets",uVar5);

    return 0;

  }

  if (iVar3 < -0xb) {

    if (iVar3 == -0xc) {

      pcVar8 = "VK_ERROR_FRAGMENTED_POOL";

      goto LAB_1401b3161;

    }

    if (iVar3 < -0x3b9acdeb) {

      if (iVar3 == -0x3b9acdec) {

        pcVar8 = "VK_ERROR_OUT_OF_DATE_KHR";

        goto LAB_1401b3161;

      }

      if (iVar3 == -0x3b9eae18) {

        pcVar8 = "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";

        goto LAB_1401b3161;

      }

      if (iVar3 == -0x3b9bd788) {

        pcVar8 = "VK_ERROR_OUT_OF_POOL_MEMORY";

        goto LAB_1401b3161;

      }

      if (iVar3 == -0x3b9af8e0) {

        pcVar8 = "VK_ERROR_INVALID_SHADER_NV";

        goto LAB_1401b3161;

      }

    }

    else {

      if (iVar3 == -0x3b9aca01) {

        pcVar8 = "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";

        goto LAB_1401b3161;

      }

      if (iVar3 == -1000000000) {

        pcVar8 = "VK_ERROR_SURFACE_LOST_KHR";

        goto LAB_1401b3161;

      }

    }

  }

  else if (iVar3 < 0x3b9acdec) {

    if (iVar3 == 0x3b9acdeb) {

      pcVar8 = "VK_SUBOPTIMAL_KHR";

      goto LAB_1401b3161;

    }

    switch(iVar3) {

    case -10:

      pcVar8 = "VK_ERROR_TOO_MANY_OBJECTS";

      break;

    case -9:

      pcVar8 = "VK_ERROR_INCOMPATIBLE_DRIVER";

      break;

    case -8:

      pcVar8 = "VK_ERROR_FEATURE_NOT_PRESENT";

      break;

    case -7:

      pcVar8 = "VK_ERROR_EXTENSION_NOT_PRESENT";

      break;

    case -6:

      pcVar8 = "VK_ERROR_LAYER_NOT_PRESENT";

      break;

    default:

      goto switchD_1401b30fe_caseD_fffffffb;

    case -4:

      pcVar8 = "VK_ERROR_DEVICE_LOST";

      break;

    case -3:

      pcVar8 = "VK_ERROR_INITIALIZATION_FAILED";

      break;

    case -2:

      pcVar8 = "VK_ERROR_OUT_OF_DEVICE_MEMORY";

      break;

    case -1:

      pcVar8 = "VK_ERROR_OUT_OF_HOST_MEMORY";

    }

    goto LAB_1401b3161;

  }

switchD_1401b30fe_caseD_fffffffb:

  pcVar8 = "Unhandled VkResult!";

LAB_1401b3161:

                    /* WARNING: Subroutine does not return */

  *(undefined8 *)((longlong)auStack_60 + lVar2) = 0x1401b3179;

  FUN_14012e0b0(9,"%s %s","vkAllocateDescriptorSets",pcVar8);

}





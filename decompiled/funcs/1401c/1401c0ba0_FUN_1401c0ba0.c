// Address: 0x1401c0ba0
// Ghidra name: FUN_1401c0ba0
// ============ 0x1401c0ba0 FUN_1401c0ba0 (size=259) ============


char * FUN_1401c0ba0(int param_1)



{

  char *pcVar1;

  

  if (-0xc < param_1) {

    if (param_1 < 0x3b9acdec) {

      if (param_1 == 0x3b9acdeb) {

        return "VK_SUBOPTIMAL_KHR";

      }

      switch(param_1) {

      case -10:

        return "VK_ERROR_TOO_MANY_OBJECTS";

      case -9:

        return "VK_ERROR_INCOMPATIBLE_DRIVER";

      case -8:

        return "VK_ERROR_FEATURE_NOT_PRESENT";

      case -7:

        return "VK_ERROR_EXTENSION_NOT_PRESENT";

      case -6:

        return "VK_ERROR_LAYER_NOT_PRESENT";

      case -4:

        return "VK_ERROR_DEVICE_LOST";

      case -3:

        return "VK_ERROR_INITIALIZATION_FAILED";

      case -2:

        return "VK_ERROR_OUT_OF_DEVICE_MEMORY";

      case -1:

        return "VK_ERROR_OUT_OF_HOST_MEMORY";

      }

    }

    return "Unhandled VkResult!";

  }

  if (param_1 == -0xc) {

    return "VK_ERROR_FRAGMENTED_POOL";

  }

  if (-0x3b9acdec < param_1) {

    if (param_1 != -0x3b9aca01) {

      pcVar1 = "Unhandled VkResult!";

      if (param_1 == -1000000000) {

        pcVar1 = "VK_ERROR_SURFACE_LOST_KHR";

      }

      return pcVar1;

    }

    return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";

  }

  if (param_1 != -0x3b9acdec) {

    if (param_1 == -0x3b9eae18) {

      return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";

    }

    if (param_1 != -0x3b9bd788) {

      pcVar1 = "Unhandled VkResult!";

      if (param_1 == -0x3b9af8e0) {

        pcVar1 = "VK_ERROR_INVALID_SHADER_NV";

      }

      return pcVar1;

    }

    return "VK_ERROR_OUT_OF_POOL_MEMORY";

  }

  return "VK_ERROR_OUT_OF_DATE_KHR";

}





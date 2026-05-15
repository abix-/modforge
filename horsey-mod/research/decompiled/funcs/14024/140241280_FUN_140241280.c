// Address: 0x140241280
// Ghidra name: FUN_140241280
// ============ 0x140241280 FUN_140241280 (size=582) ============


char * FUN_140241280(int param_1)



{

  char *pcVar1;

  

  if (-0xd < param_1) {

    if (param_1 < 0x3b9acdec) {

      if (param_1 != 0x3b9acdeb) {

        switch(param_1) {

        case 0:

          return "VK_SUCCESS";

        case 1:

          return "VK_NOT_READY";

        case 2:

          return "VK_TIMEOUT";

        case 3:

          return "VK_EVENT_SET";

        case 4:

          return "VK_EVENT_RESET";

        case 5:

          return "VK_INCOMPLETE";

        case -0xc:

          return "VK_ERROR_FRAGMENTED_POOL";

        case -0xb:

          return "VK_ERROR_FORMAT_NOT_SUPPORTED";

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

        case -5:

          return "VK_ERROR_MEMORY_MAP_FAILED";

        case -4:

          return "VK_ERROR_DEVICE_LOST";

        case -3:

          return "VK_ERROR_INITIALIZATION_FAILED";

        case -2:

          return "VK_ERROR_OUT_OF_DEVICE_MEMORY";

        case -1:

          return "VK_ERROR_OUT_OF_HOST_MEMORY";

        }

        pcVar1 = "VK_<Unknown>";

        if (param_1 < 0) {

          pcVar1 = "VK_ERROR_<Unknown>";

        }

        return pcVar1;

      }

      return "VK_SUBOPTIMAL_KHR";

    }

    if (param_1 == 0x3b9ee0e0) {

      return "VK_THREAD_IDLE_KHR";

    }

    if (param_1 == 0x3b9ee0e1) {

      return "VK_THREAD_DONE_KHR";

    }

    if (param_1 != 0x3b9ee0e2) {

      if (param_1 == 0x3b9ee0e3) {

        return "VK_OPERATION_NOT_DEFERRED_KHR";

      }

      if (param_1 == 0x3b9f5228) {

        return "VK_PIPELINE_COMPILE_REQUIRED_EXT";

      }

      return "VK_<Unknown>";

    }

    return "VK_OPERATION_DEFERRED_KHR";

  }

  if (param_1 == -0xd) {

    return "VK_ERROR_UNKNOWN";

  }

  if (-0x3b9bd788 < param_1) {

    if (-0x3b9acdec < param_1) {

      if (param_1 == -0x3b9aca01) {

        return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";

      }

      pcVar1 = "VK_ERROR_<Unknown>";

      if (param_1 == -1000000000) {

        pcVar1 = "VK_ERROR_SURFACE_LOST_KHR";

      }

      return pcVar1;

    }

    if (param_1 == -0x3b9acdec) {

      return "VK_ERROR_OUT_OF_DATE_KHR";

    }

    if (param_1 == -0x3b9af8e0) {

      return "VK_ERROR_INVALID_SHADER_NV";

    }

    if (param_1 == -0x3b9af4f9) {

      return "VK_ERROR_VALIDATION_FAILED_EXT";

    }

    pcVar1 = "VK_ERROR_<Unknown>";

    if (param_1 == -0x3b9ad5b9) {

      pcVar1 = "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";

    }

    return pcVar1;

  }

  if (param_1 == -0x3b9bd788) {

    return "VK_ERROR_OUT_OF_POOL_MEMORY";

  }

  if (-0x3b9d3ee8 < param_1) {

    if (param_1 == -0x3b9d3330) {

      return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";

    }

    pcVar1 = "VK_ERROR_<Unknown>";

    if (param_1 == -0x3b9be343) {

      pcVar1 = "VK_ERROR_INVALID_EXTERNAL_HANDLE";

    }

    return pcVar1;

  }

  if (param_1 == -0x3b9d3ee8) {

    return "VK_ERROR_FRAGMENTATION";

  }

  if (param_1 == -0x3b9eb5e8) {

    return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";

  }

  if (param_1 == -0x3b9eae18) {

    return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";

  }

  pcVar1 = "VK_ERROR_<Unknown>";

  if (param_1 == -0x3b9d71b1) {

    pcVar1 = "VK_ERROR_NOT_PERMITTED_EXT";

  }

  return pcVar1;

}





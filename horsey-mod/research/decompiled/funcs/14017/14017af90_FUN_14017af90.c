// Address: 0x14017af90
// Ghidra name: FUN_14017af90
// ============ 0x14017af90 FUN_14017af90 (size=1292) ============


char * FUN_14017af90(int param_1)



{

  char *pcVar1;

  

  if (0x17101803 < param_1) {

    if (0x1b308010 < param_1) {

      if (0x3132564e < param_1) {

        if (0x47504a4d < param_1) {

          if (param_1 == 0x55595659) {

            return "SDL_PIXELFORMAT_YVYU";

          }

          if (param_1 != 0x56555949) {

            pcVar1 = "SDL_PIXELFORMAT_UYVY";

            if (param_1 != 0x59565955) {

              pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

            }

            return pcVar1;

          }

          return "SDL_PIXELFORMAT_IYUV";

        }

        if (param_1 == 0x47504a4d) {

          return "SDL_PIXELFORMAT_MJPG";

        }

        if (param_1 != 0x3231564e) {

          if (param_1 == 0x32315659) {

            return "SDL_PIXELFORMAT_YV12";

          }

          if (param_1 != 0x32595559) {

            return "SDL_PIXELFORMAT_UNKNOWN";

          }

          return "SDL_PIXELFORMAT_YUY2";

        }

        return "SDL_PIXELFORMAT_NV12";

      }

      if (param_1 == 0x3132564e) {

        return "SDL_PIXELFORMAT_NV21";

      }

      if (0x1c100200 < param_1) {

        if (param_1 == 0x1c200200) {

          return "SDL_PIXELFORMAT_INDEX2MSB";

        }

        if (param_1 != 0x2053454f) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x30313050) {

            pcVar1 = "SDL_PIXELFORMAT_P010";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_EXTERNAL_OES";

      }

      if (param_1 == 0x1c100200) {

        return "SDL_PIXELFORMAT_INDEX2LSB";

      }

      if (param_1 != 0x1b40600c) {

        if (param_1 != 0x1b508010) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x1b608010) {

            pcVar1 = "SDL_PIXELFORMAT_ABGR128_FLOAT";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_BGRA128_FLOAT";

      }

      return "SDL_PIXELFORMAT_BGR96_FLOAT";

    }

    if (param_1 == 0x1b308010) {

      return "SDL_PIXELFORMAT_ARGB128_FLOAT";

    }

    if (0x1a103006 < param_1) {

      if (0x1a504008 < param_1) {

        if (param_1 == 0x1a604008) {

          return "SDL_PIXELFORMAT_ABGR64_FLOAT";

        }

        if (param_1 != 0x1b10600c) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x1b208010) {

            pcVar1 = "SDL_PIXELFORMAT_RGBA128_FLOAT";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_RGB96_FLOAT";

      }

      if (param_1 == 0x1a504008) {

        return "SDL_PIXELFORMAT_BGRA64_FLOAT";

      }

      if (param_1 != 0x1a204008) {

        if (param_1 != 0x1a304008) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x1a403006) {

            pcVar1 = "SDL_PIXELFORMAT_BGR48_FLOAT";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_ARGB64_FLOAT";

      }

      return "SDL_PIXELFORMAT_RGBA64_FLOAT";

    }

    if (param_1 == 0x1a103006) {

      return "SDL_PIXELFORMAT_RGB48_FLOAT";

    }

    if (0x18304008 < param_1) {

      if (param_1 == 0x18403006) {

        return "SDL_PIXELFORMAT_BGR48";

      }

      if (param_1 != 0x18504008) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x18604008) {

          pcVar1 = "SDL_PIXELFORMAT_ABGR64";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_BGRA64";

    }

    if (param_1 == 0x18304008) {

      return "SDL_PIXELFORMAT_ARGB64";

    }

    if (param_1 != 0x17401803) {

      if (param_1 != 0x18103006) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x18204008) {

          pcVar1 = "SDL_PIXELFORMAT_RGBA64";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_RGB48";

    }

    return "SDL_PIXELFORMAT_BGR24";

  }

  if (param_1 == 0x17101803) {

    return "SDL_PIXELFORMAT_RGB24";

  }

  if (0x15721002 < param_1) {

    if (0x16372004 < param_1) {

      if (0x16661804 < param_1) {

        if (param_1 == 0x16762004) {

          return "SDL_PIXELFORMAT_ABGR8888";

        }

        if (param_1 != 0x16772004) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x16862004) {

            pcVar1 = "SDL_PIXELFORMAT_BGRA8888";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_ABGR2101010";

      }

      if (param_1 == 0x16661804) {

        return "SDL_PIXELFORMAT_BGRX8888";

      }

      if (param_1 != 0x16462004) {

        if (param_1 != 0x16561804) {

          pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

          if (param_1 == 0x16572004) {

            pcVar1 = "SDL_PIXELFORMAT_XBGR2101010";

          }

          return pcVar1;

        }

        return "SDL_PIXELFORMAT_XBGR8888";

      }

      return "SDL_PIXELFORMAT_RGBA8888";

    }

    if (param_1 == 0x16372004) {

      return "SDL_PIXELFORMAT_ARGB2101010";

    }

    if (0x16161804 < param_1) {

      if (param_1 == 0x16172004) {

        return "SDL_PIXELFORMAT_XRGB2101010";

      }

      if (param_1 != 0x16261804) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x16362004) {

          pcVar1 = "SDL_PIXELFORMAT_ARGB8888";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_RGBX8888";

    }

    if (param_1 == 0x16161804) {

      return "SDL_PIXELFORMAT_XRGB8888";

    }

    if (param_1 != 0x15731002) {

      if (param_1 != 0x15821002) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x15841002) {

          pcVar1 = "SDL_PIXELFORMAT_BGRA5551";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_BGRA4444";

    }

    return "SDL_PIXELFORMAT_ABGR1555";

  }

  if (param_1 == 0x15721002) {

    return "SDL_PIXELFORMAT_ABGR4444";

  }

  if (0x15151002 < param_1) {

    if (0x15441002 < param_1) {

      if (param_1 == 0x15520c02) {

        return "SDL_PIXELFORMAT_XBGR4444";

      }

      if (param_1 != 0x15530f02) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x15551002) {

          pcVar1 = "SDL_PIXELFORMAT_BGR565";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_XBGR1555";

    }

    if (param_1 == 0x15441002) {

      return "SDL_PIXELFORMAT_RGBA5551";

    }

    if (param_1 != 0x15321002) {

      if (param_1 != 0x15331002) {

        pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

        if (param_1 == 0x15421002) {

          pcVar1 = "SDL_PIXELFORMAT_RGBA4444";

        }

        return pcVar1;

      }

      return "SDL_PIXELFORMAT_ARGB1555";

    }

    return "SDL_PIXELFORMAT_ARGB4444";

  }

  if (param_1 == 0x15151002) {

    return "SDL_PIXELFORMAT_RGB565";

  }

  if (0x13000801 < param_1) {

    if (param_1 == 0x14110801) {

      return "SDL_PIXELFORMAT_RGB332";

    }

    if (param_1 != 0x15120c02) {

      pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

      if (param_1 == 0x15130f02) {

        pcVar1 = "SDL_PIXELFORMAT_XRGB1555";

      }

      return pcVar1;

    }

    return "SDL_PIXELFORMAT_XRGB4444";

  }

  if (param_1 == 0x13000801) {

    return "SDL_PIXELFORMAT_INDEX8";

  }

  if (param_1 != 0x11100100) {

    if (param_1 == 0x11200100) {

      return "SDL_PIXELFORMAT_INDEX1MSB";

    }

    if (param_1 != 0x12100400) {

      pcVar1 = "SDL_PIXELFORMAT_UNKNOWN";

      if (param_1 == 0x12200400) {

        pcVar1 = "SDL_PIXELFORMAT_INDEX4MSB";

      }

      return pcVar1;

    }

    return "SDL_PIXELFORMAT_INDEX4LSB";

  }

  return "SDL_PIXELFORMAT_INDEX1LSB";

}





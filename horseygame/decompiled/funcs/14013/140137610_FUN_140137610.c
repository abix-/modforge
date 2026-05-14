// Address: 0x140137610
// Ghidra name: FUN_140137610
// ============ 0x140137610 FUN_140137610 (size=386) ============


void FUN_140137610(longlong *param_1,longlong param_2)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","texture");

    return;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_140137714:

    (**(code **)(*param_1 + 0x1d0))(param_1);

    if (*(char *)(*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)((longlong)param_1 + 0x10a) = 0;

    }

    return;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) {

      if (*(uint *)(param_2 + 0x18) < 2) {

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403e0ca8,"SDL_GenerateMipmapsForGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xbe2);

        } while (iVar2 == 0);

        if (iVar2 != 1) {

          return;

        }

      }

      else {

        if (((byte)*(undefined4 *)(param_2 + 8) & 3) == 3) {

          *(undefined1 *)((longlong)param_1 + 0x10a) = 1;

          goto LAB_140137714;

        }

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403e0cd8,"SDL_GenerateMipmapsForGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xbe7);

        } while (iVar2 == 0);

        if (iVar2 != 1) {

          return;

        }

      }

    }

    else {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0c78,"SDL_GenerateMipmapsForGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xbde);

      } while (iVar2 == 0);

      if (iVar2 != 1) {

        return;

      }

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0c48,"SDL_GenerateMipmapsForGPUTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xbdd);

    } while (iVar2 == 0);

    if (iVar2 != 1) {

      return;

    }

  }

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}





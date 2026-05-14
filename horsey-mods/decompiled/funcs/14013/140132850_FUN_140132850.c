// Address: 0x140132850
// Ghidra name: FUN_140132850
// ============ 0x140132850 FUN_140132850 (size=307) ============


ulonglong FUN_140132850(longlong *param_1,longlong param_2,longlong *param_3)



{

  code *pcVar1;

  ulonglong uVar2;

  

  if (param_1 == (longlong *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return uVar2;

  }

  if (param_2 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","window");

    return uVar2;

  }

  if (param_3 == (longlong *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","swapchain_texture");

    return uVar2;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_140132957:

    uVar2 = (**(code **)(*param_1 + 0x238))();

    if (*param_3 != 0) {

      *(undefined1 *)(param_1 + 0x21) = 1;

    }

    return uVar2;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) goto LAB_140132957;

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403e0fd8,"SDL_AcquireGPUSwapchainTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xcd9);

    } while ((int)uVar2 == 0);

  }

  else {

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403e0fa8,"SDL_AcquireGPUSwapchainTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xcd8);

    } while ((int)uVar2 == 0);

  }

  if ((int)uVar2 != 1) {

    return uVar2 & 0xffffffffffffff00;

  }

  pcVar1 = (code *)swi(3);

  uVar2 = (*pcVar1)();

  return uVar2;

}





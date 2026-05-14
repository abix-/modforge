// Address: 0x1401389e0
// Ghidra name: FUN_1401389e0
// ============ 0x1401389e0 FUN_1401389e0 (size=307) ============


ulonglong FUN_1401389e0(longlong *param_1,longlong param_2,longlong *param_3)



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

LAB_140138ae7:

    uVar2 = (**(code **)(*param_1 + 0x248))();

    if (*param_3 != 0) {

      *(undefined1 *)(param_1 + 0x21) = 1;

    }

    return uVar2;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) goto LAB_140138ae7;

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403e1038,"SDL_WaitAndAcquireGPUSwapchainTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xd0e);

    } while ((int)uVar2 == 0);

  }

  else {

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403e1008,"SDL_WaitAndAcquireGPUSwapchainTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xd0d);

    } while ((int)uVar2 == 0);

  }

  if ((int)uVar2 != 1) {

    return uVar2 & 0xffffffffffffff00;

  }

  pcVar1 = (code *)swi(3);

  uVar2 = (*pcVar1)();

  return uVar2;

}





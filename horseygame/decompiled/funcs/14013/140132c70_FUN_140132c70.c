// Address: 0x140132c70
// Ghidra name: FUN_140132c70
// ============ 0x140132c70 FUN_140132c70 (size=219) ============


longlong * FUN_140132c70(longlong *param_1)



{

  code *pcVar1;

  int iVar2;

  longlong *plVar3;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return (longlong *)0x0;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_140132d22:

    (**(code **)(*param_1 + 0x1a8))();

    if (*(char *)(*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)(param_1 + 0x20) = 1;

    }

    return param_1 + 0x1f;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) goto LAB_140132d22;

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0858,"SDL_BeginGPUCopyPass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xabd);

    } while (iVar2 == 0);

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0828,"SDL_BeginGPUCopyPass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xabc);

    } while (iVar2 == 0);

  }

  if (iVar2 != 1) {

    return (longlong *)0x0;

  }

  pcVar1 = (code *)swi(3);

  plVar3 = (longlong *)(*pcVar1)();

  return plVar3;

}





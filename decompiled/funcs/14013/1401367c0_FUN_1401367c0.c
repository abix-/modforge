// Address: 0x1401367c0
// Ghidra name: FUN_1401367c0
// ============ 0x1401367c0 FUN_1401367c0 (size=239) ============


void FUN_1401367c0(longlong *param_1)



{

  longlong *plVar1;

  code *pcVar2;

  int iVar3;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  plVar1 = (longlong *)*param_1;

  if ((*(char *)(*plVar1 + 0x2ac) == '\0') || ((char)param_1[1] != '\0')) {

    (**(code **)(*plVar1 + 0x148))(plVar1);

    if (*(char *)(*(longlong *)*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)(plVar1 + 2) = 0;

      plVar1[3] = 0;

      plVar1[4] = 0;

      plVar1[5] = 0;

      plVar1[6] = 0;

      plVar1[7] = 0;

      plVar1[8] = 0;

      plVar1[9] = 0;

      plVar1[10] = 0;

      *(undefined4 *)(plVar1 + 0xb) = 0;

      plVar1[0xc] = 0;

      plVar1[0xd] = 0;

      plVar1[0xe] = 0;

      plVar1[0xf] = 0;

      plVar1[0x10] = 0;

      plVar1[0x11] = 0;

      plVar1[0x12] = 0;

      plVar1[0x13] = 0;

      plVar1[0x14] = 0;

      plVar1[0x15] = 0;

    }

  }

  else {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0558,"SDL_EndGPURenderPass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x956);

    } while (iVar3 == 0);

    if (iVar3 == 1) {

      pcVar2 = (code *)swi(3);

      (*pcVar2)();

      return;

    }

  }

  return;

}





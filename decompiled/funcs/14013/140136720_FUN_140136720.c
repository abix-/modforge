// Address: 0x140136720
// Ghidra name: FUN_140136720
// ============ 0x140136720 FUN_140136720 (size=143) ============


void FUN_140136720(longlong *param_1)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","copy_pass");

    return;

  }

  if ((*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') || ((char)param_1[1] != '\0')) {

    (**(code **)(*(longlong *)*param_1 + 0x1e8))();

    if (*(char *)(*(longlong *)*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)((longlong *)*param_1 + 0x20) = 0;

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0c18,"SDL_EndGPUCopyPass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xbc4);

    } while (iVar2 == 0);

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

  }

  return;

}





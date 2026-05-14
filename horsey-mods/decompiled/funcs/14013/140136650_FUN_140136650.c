// Address: 0x140136650
// Ghidra name: FUN_140136650
// ============ 0x140136650 FUN_140136650 (size=194) ============


void FUN_140136650(longlong *param_1)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","compute_pass");

    return;

  }

  if ((*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') || ((char)param_1[1] != '\0')) {

    (**(code **)(*(longlong *)*param_1 + 400))();

    param_1 = (longlong *)*param_1;

    if (*(char *)(*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)(param_1 + 0x17) = 0;

      param_1[0x18] = 0;

      param_1[0x19] = 0;

      param_1[0x1a] = 0;

      param_1[0x1b] = 0;

      param_1[0x1c] = 0;

      param_1[0x1d] = 0;

      param_1[0x1e] = 0;

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e07f8,"SDL_EndGPUComputePass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xa79);

    } while (iVar2 == 0);

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

  }

  return;

}





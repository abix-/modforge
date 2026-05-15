// Address: 0x140133240
// Ghidra name: FUN_140133240
// ============ 0x140133240 FUN_140133240 (size=193) ============


void FUN_140133240(undefined8 *param_1,longlong param_2)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","compute_pass");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","compute_pipeline");

    return;

  }

  if ((*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') || (*(char *)(param_1 + 1) != '\0')) {

    (**(code **)(*(longlong *)*param_1 + 0x158))();

    if (*(char *)(*(longlong *)*param_1 + 0x2ac) != '\0') {

      param_1[2] = param_2;

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0678,"SDL_BindGPUComputePipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x9cd);

    } while (iVar2 == 0);

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

  }

  return;

}





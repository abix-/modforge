// Address: 0x140135dc0
// Ghidra name: FUN_140135dc0
// ============ 0x140135dc0 FUN_140135dc0 (size=248) ============


void FUN_140135dc0(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","compute_pass");

    return;

  }

  if (*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') {

LAB_140135ea2:

    (**(code **)(*(longlong *)*param_1 + 0x188))((longlong *)*param_1,param_2,param_3);

    return;

  }

  if (*(char *)(param_1 + 1) == '\0') {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e0798,"SDL_DispatchGPUComputeIndirect_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xa63);

    } while (iVar2 == 0);

    if (iVar2 != 1) {

      return;

    }

  }

  else {

    if (param_1[2] != 0) {

      FUN_140136fb0(param_1);

      goto LAB_140135ea2;

    }

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403e07c8,"SDL_DispatchGPUComputeIndirect_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xa64);

    } while (iVar2 == 0);

    if (iVar2 != 1) {

      return;

    }

  }

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}





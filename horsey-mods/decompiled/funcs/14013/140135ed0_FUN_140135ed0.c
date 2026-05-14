// Address: 0x140135ed0
// Ghidra name: FUN_140135ed0
// ============ 0x140135ed0 FUN_140135ed0 (size=226) ============


void FUN_140135ed0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","compute_pass");

    return;

  }

  if (*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') {

LAB_140135f87:

    (**(code **)(*(longlong *)*param_1 + 0x180))((longlong *)*param_1,param_2,param_3,param_4);

  }

  else {

    if (*(char *)(param_1 + 1) == '\0') {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0738,"SDL_DispatchGPUCompute_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xa4c);

      } while (iVar2 == 0);

    }

    else {

      if (param_1[2] != 0) {

        FUN_140136fb0(param_1);

        goto LAB_140135f87;

      }

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0768,"SDL_DispatchGPUCompute_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xa4d);

      } while (iVar2 == 0);

    }

    if (iVar2 == 1) {

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

  }

  return;

}





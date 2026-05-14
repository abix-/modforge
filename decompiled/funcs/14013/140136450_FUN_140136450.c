// Address: 0x140136450
// Ghidra name: FUN_140136450
// ============ 0x140136450 FUN_140136450 (size=258) ============


void FUN_140136450(undefined8 *param_1,longlong param_2,undefined4 param_3,undefined4 param_4)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","buffer");

    return;

  }

  if (*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') {

LAB_140136526:

    (**(code **)(*(longlong *)*param_1 + 0x138))((longlong *)*param_1,param_2,param_3,param_4);

  }

  else {

    if (*(char *)(param_1 + 1) == '\0') {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0498,"SDL_DrawGPUPrimitivesIndirect_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x922);

      } while (iVar2 == 0);

    }

    else {

      if (param_1[0xc] != 0) {

        FUN_140137150(param_1);

        goto LAB_140136526;

      }

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e04c8,"SDL_DrawGPUPrimitivesIndirect_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x923);

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





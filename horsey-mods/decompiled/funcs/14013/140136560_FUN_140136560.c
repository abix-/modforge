// Address: 0x140136560
// Ghidra name: FUN_140136560
// ============ 0x140136560 FUN_140136560 (size=234) ============


void FUN_140136560(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if (*(char *)(*(longlong *)*param_1 + 0x2ac) == '\0') {

LAB_140136617:

    (**(code **)(*(longlong *)*param_1 + 0x130))

              ((longlong *)*param_1,param_2,param_3,param_4,param_5);

  }

  else {

    if (*(char *)(param_1 + 1) == '\0') {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0438,"SDL_DrawGPUPrimitives_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x905);

      } while (iVar2 == 0);

    }

    else {

      if (param_1[0xc] != 0) {

        FUN_140137150(param_1);

        goto LAB_140136617;

      }

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403e0468,"SDL_DrawGPUPrimitives_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x906);

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





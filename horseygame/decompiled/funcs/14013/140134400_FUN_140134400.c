// Address: 0x140134400
// Ghidra name: FUN_140134400
// ============ 0x140134400 FUN_140134400 (size=383) ============


void FUN_140134400(undefined8 *param_1,longlong *param_2,longlong *param_3)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","copy_pass");

    return;

  }

  if (param_2 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","source");

    return;

  }

  if (param_3 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","destination");

    return;

  }

  lVar1 = *(longlong *)*param_1;

  if (*(char *)(lVar1 + 0x2ac) == '\0') {

LAB_14013455f:

                    /* WARNING: Could not recover jumptable at 0x00014013457c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x1c0))((longlong *)*param_1);

    return;

  }

  if (*(char *)(param_1 + 1) == '\0') {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e09a8,"SDL_CopyGPUTextureToTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb2f);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  else if (*param_2 == 0) {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e09d8,"SDL_CopyGPUTextureToTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb31);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  else if (*param_3 == 0) {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0a08,"SDL_CopyGPUTextureToTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb35);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  else {

    if (*(int *)(*param_2 + 4) == *(int *)(*param_3 + 4)) goto LAB_14013455f;

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0a38,"SDL_CopyGPUTextureToTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb3c);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  pcVar2 = (code *)swi(3);

  (*pcVar2)();

  return;

}





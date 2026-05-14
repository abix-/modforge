// Address: 0x1401342c0
// Ghidra name: FUN_1401342c0
// ============ 0x1401342c0 FUN_1401342c0 (size=313) ============


void FUN_1401342c0(undefined8 *param_1,longlong *param_2,longlong *param_3)



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

LAB_1401343df:

                    /* WARNING: Could not recover jumptable at 0x0001401343f6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x1c8))((longlong *)*param_1);

    return;

  }

  if (*(char *)(param_1 + 1) == '\0') {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0a68,"SDL_CopyGPUBufferToBuffer_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb60);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  else if (*param_2 == 0) {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0a98,"SDL_CopyGPUBufferToBuffer_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb62);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  else {

    if (*param_3 != 0) goto LAB_1401343df;

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e0ac8,"SDL_CopyGPUBufferToBuffer_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xb66);

    } while (iVar3 == 0);

    if (iVar3 != 1) {

      return;

    }

  }

  pcVar2 = (code *)swi(3);

  (*pcVar2)();

  return;

}





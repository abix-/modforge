// Address: 0x140137150
// Ghidra name: FUN_140137150
// ============ 0x140137150 FUN_140137150 (size=486) ============


void FUN_140137150(longlong param_1)



{

  uint *puVar1;

  code *pcVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar6;

  ulonglong uVar5;

  

  puVar1 = *(uint **)(param_1 + 0x60);

  uVar6 = 0;

  uVar5 = uVar6;

  if (*puVar1 != 0) {

    do {

      if (*(char *)(uVar5 + 0x68 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403ded28,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x217);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < *puVar1);

  }

  uVar5 = uVar6;

  if (puVar1[1] != 0) {

    do {

      if (*(char *)(uVar5 + 0x78 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403ded58,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x21c);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[1]);

  }

  uVar5 = uVar6;

  if (puVar1[2] != 0) {

    do {

      if (*(char *)(uVar5 + 0x80 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403ded88,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x221);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[2]);

  }

  uVar5 = uVar6;

  if (puVar1[4] != 0) {

    do {

      if (*(char *)(uVar5 + 0x88 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403dedb8,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x226);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[4]);

  }

  uVar5 = uVar6;

  if (puVar1[5] != 0) {

    do {

      if (*(char *)(uVar5 + 0x98 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403dede8,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x22b);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[5]);

  }

  if (puVar1[6] != 0) {

    do {

      if (*(char *)(uVar6 + 0xa0 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403dee18,"SDL_GPU_CheckGraphicsBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x230);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[6]);

  }

  return;

}





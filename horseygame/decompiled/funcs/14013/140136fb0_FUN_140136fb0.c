// Address: 0x140136fb0
// Ghidra name: FUN_140136fb0
// ============ 0x140136fb0 FUN_140136fb0 (size=406) ============


void FUN_140136fb0(longlong param_1)



{

  uint *puVar1;

  code *pcVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar6;

  ulonglong uVar5;

  

  puVar1 = *(uint **)(param_1 + 0x10);

  uVar6 = 0;

  uVar5 = uVar6;

  if (*puVar1 != 0) {

    do {

      if (*(char *)(uVar5 + 0x18 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403dee48,"SDL_GPU_CheckComputeBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x23b);

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

      if (*(char *)(uVar5 + 0x28 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403dee78,"SDL_GPU_CheckComputeBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x240);

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

      if (*(char *)(uVar5 + 0x30 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403deea8,"SDL_GPU_CheckComputeBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x245);

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

  if (puVar1[3] != 0) {

    do {

      if (*(char *)(uVar5 + 0x38 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403deed8,"SDL_GPU_CheckComputeBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x24a);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[3]);

  }

  if (puVar1[4] != 0) {

    do {

      if (*(char *)(uVar6 + 0x40 + param_1) == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403def08,"SDL_GPU_CheckComputeBindings",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x24f);

        } while (iVar3 == 0);

        if (iVar3 == 1) {

          pcVar2 = (code *)swi(3);

          (*pcVar2)();

          return;

        }

      }

      uVar4 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar4;

    } while (uVar4 < puVar1[4]);

  }

  return;

}





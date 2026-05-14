// Address: 0x140134650
// Ghidra name: FUN_140134650
// ============ 0x140134650 FUN_140134650 (size=547) ============


undefined8 FUN_140134650(longlong param_1,longlong param_2)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return 0;

  }

  if (*(char *)(param_1 + 0x2ac) == '\0') {

LAB_140134861:

                    /* WARNING: Could not recover jumptable at 0x000140134870. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x298));

    return uVar3;

  }

  if (*(uint *)(param_2 + 0x18) == 0) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403defc8,"SDL_CreateGPUComputePipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3d0);

    } while (iVar2 == 0);

  }

  else if ((*(uint *)(param_1 + 0x2a8) & *(uint *)(param_2 + 0x18)) == 0) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403deff8,"SDL_CreateGPUComputePipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3d4);

    } while (iVar2 == 0);

  }

  else if (*(uint *)(param_2 + 0x28) < 9) {

    if (*(uint *)(param_2 + 0x2c) < 9) {

      if (*(uint *)(param_2 + 0x1c) < 0x11) {

        if (*(uint *)(param_2 + 0x20) < 9) {

          if (*(uint *)(param_2 + 0x24) < 9) {

            if (*(uint *)(param_2 + 0x30) < 5) {

              if (((*(int *)(param_2 + 0x34) != 0) && (*(int *)(param_2 + 0x38) != 0)) &&

                 (*(int *)(param_2 + 0x3c) != 0)) goto LAB_140134861;

              do {

                iVar2 = FUN_14017f2a0(&DAT_1403df148,"SDL_CreateGPUComputePipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3f8);

              } while (iVar2 == 0);

            }

            else {

              do {

                iVar2 = FUN_14017f2a0(&DAT_1403df118,"SDL_CreateGPUComputePipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3f2);

              } while (iVar2 == 0);

            }

          }

          else {

            do {

              iVar2 = FUN_14017f2a0(&DAT_1403df0e8,"SDL_CreateGPUComputePipeline_REAL",

                                    "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3ed);

            } while (iVar2 == 0);

          }

        }

        else {

          do {

            iVar2 = FUN_14017f2a0(&DAT_1403df0b8,"SDL_CreateGPUComputePipeline_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",1000);

          } while (iVar2 == 0);

        }

      }

      else {

        do {

          iVar2 = FUN_14017f2a0(&DAT_1403df088,"SDL_CreateGPUComputePipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3e3);

        } while (iVar2 == 0);

      }

    }

    else {

      do {

        iVar2 = FUN_14017f2a0(&DAT_1403df058,"SDL_CreateGPUComputePipeline_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3de);

      } while (iVar2 == 0);

    }

  }

  else {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403df028,"SDL_CreateGPUComputePipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x3d9);

    } while (iVar2 == 0);

  }

  if (iVar2 != 1) {

    return 0;

  }

  pcVar1 = (code *)swi(3);

  uVar3 = (*pcVar1)();

  return uVar3;

}





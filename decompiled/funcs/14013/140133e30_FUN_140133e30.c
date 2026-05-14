// Address: 0x140133e30
// Ghidra name: FUN_140133e30
// ============ 0x140133e30 FUN_140133e30 (size=756) ============


void FUN_140133e30(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  code *pcVar3;

  bool bVar4;

  int iVar5;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return;

  }

  if (param_2 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14031a308);

    return;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_1401340a8:

    (**(code **)(*param_1 + 0x1f0))(param_1,param_2);

  }

  else {

    if (*(char *)((longlong)param_1 + 0x109) == '\0') {

      if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

         ((char)param_1[0x20] == '\0')) {

        lVar1 = *param_2;

        bVar4 = false;

        lVar2 = param_2[4];

        if (lVar1 == 0) {

          do {

            iVar5 = FUN_14017f2a0(&DAT_1403e0d68,"SDL_BlitGPUTexture_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc10);

          } while (iVar5 == 0);

        }

        else {

          if (lVar2 != 0) {

            if (*(int *)(lVar1 + 0x1c) != 0) {

              do {

                iVar5 = FUN_14017f2a0(&DAT_1403e0dc8,"SDL_BlitGPUTexture_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc18);

              } while (iVar5 == 0);

              if (iVar5 == 1) {

                pcVar3 = (code *)swi(3);

                (*pcVar3)();

                return;

              }

              bVar4 = true;

            }

            if ((*(byte *)(lVar1 + 8) & 1) == 0) {

              do {

                iVar5 = FUN_14017f2a0(&DAT_1403e0df8,"SDL_BlitGPUTexture_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc1c);

              } while (iVar5 == 0);

              if (iVar5 == 1) {

                pcVar3 = (code *)swi(3);

                (*pcVar3)();

                return;

              }

              bVar4 = true;

            }

            if ((*(byte *)(lVar2 + 8) & 2) == 0) {

              do {

                iVar5 = FUN_14017f2a0(&DAT_1403e0e28,"SDL_BlitGPUTexture_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc20);

              } while (iVar5 == 0);

              if (iVar5 == 1) {

                pcVar3 = (code *)swi(3);

                (*pcVar3)();

                return;

              }

              bVar4 = true;

            }

            iVar5 = *(int *)(lVar1 + 4);

            if (((iVar5 == 0x3a) || (iVar5 == 0x3b)) ||

               ((iVar5 == 0x3c || ((iVar5 == 0x3d || (iVar5 == 0x3e)))))) {

              do {

                iVar5 = FUN_14017f2a0(&DAT_1403e0e58,"SDL_BlitGPUTexture_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc24);

              } while (iVar5 == 0);

              if (iVar5 == 1) {

                pcVar3 = (code *)swi(3);

                (*pcVar3)();

                return;

              }

              bVar4 = true;

            }

            if (((((int)param_2[3] == 0) || (*(int *)((longlong)param_2 + 0x1c) == 0)) ||

                ((int)param_2[7] == 0)) || (*(int *)((longlong)param_2 + 0x3c) == 0)) {

              do {

                iVar5 = FUN_14017f2a0(&DAT_1403e0e88,"SDL_BlitGPUTexture_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc28);

              } while (iVar5 == 0);

              if (iVar5 != 1) {

                return;

              }

              pcVar3 = (code *)swi(3);

              (*pcVar3)();

              return;

            }

            if (bVar4) {

              return;

            }

            goto LAB_1401340a8;

          }

          do {

            iVar5 = FUN_14017f2a0(&DAT_1403e0d98,"SDL_BlitGPUTexture_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc14);

          } while (iVar5 == 0);

        }

      }

      else {

        do {

          iVar5 = FUN_14017f2a0(&DAT_1403e0d38,"SDL_BlitGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc08);

        } while (iVar5 == 0);

      }

    }

    else {

      do {

        iVar5 = FUN_14017f2a0(&DAT_1403e0d08,"SDL_BlitGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xc07);

      } while (iVar5 == 0);

    }

    if (iVar5 == 1) {

      pcVar3 = (code *)swi(3);

      (*pcVar3)();

      return;

    }

  }

  return;

}





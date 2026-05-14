// Address: 0x1401355b0
// Ghidra name: FUN_1401355b0
// ============ 0x1401355b0 FUN_1401355b0 (size=1816) ============


undefined8 FUN_1401355b0(longlong param_1,int *param_2)



{

  code *pcVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  undefined8 uVar5;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == (int *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return 0;

  }

  if (*(char *)(param_1 + 0x2ac) == '\0') goto LAB_140135c6c;

  bVar2 = false;

  if (param_2[1] - 1U < 0x68) {

    if (((param_2[3] == 0) || (param_2[4] == 0)) || (param_2[5] == 0)) {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403df8f8,"SDL_CreateGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4e6);

      } while (iVar4 == 0);

      if (iVar4 == 1) {

        pcVar1 = (code *)swi(3);

        uVar5 = (*pcVar1)();

        return uVar5;

      }

      bVar2 = true;

    }

    if (param_2[6] == 0) {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403df928,"SDL_CreateGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4ea);

      } while (iVar4 == 0);

      if (iVar4 == 1) {

        pcVar1 = (code *)swi(3);

        uVar5 = (*pcVar1)();

        return uVar5;

      }

      bVar2 = true;

    }

    if (((byte)param_2[2] & 9) == 9) {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403df958,"SDL_CreateGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4ee);

      } while (iVar4 == 0);

      if (iVar4 == 1) {

        pcVar1 = (code *)swi(3);

        uVar5 = (*pcVar1)();

        return uVar5;

      }

      bVar2 = true;

    }

    if ((0 < param_2[7]) && ((*(byte *)(param_2 + 2) & 0x39) != 0)) {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403df988,"SDL_CreateGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4f6);

      } while (iVar4 == 0);

      if (iVar4 == 1) {

        pcVar1 = (code *)swi(3);

        uVar5 = (*pcVar1)();

        return uVar5;

      }

      bVar2 = true;

    }

    iVar4 = param_2[1];

    if ((((iVar4 == 0x3a) || (iVar4 == 0x3b)) ||

        ((iVar4 == 0x3c || ((iVar4 == 0x3d || (iVar4 == 0x3e)))))) &&

       ((param_2[2] & 0xfffffffaU) != 0)) {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403df9b8,"SDL_CreateGPUTexture_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4fa);

      } while (iVar4 == 0);

      if (iVar4 == 1) {

        pcVar1 = (code *)swi(3);

        uVar5 = (*pcVar1)();

        return uVar5;

      }

      bVar2 = true;

    }

    switch(param_2[1]) {

    case 0x22:

    case 0x23:

    case 0x24:

    case 0x25:

    case 0x26:

    case 0x27:

    case 0x2b:

    case 0x2c:

    case 0x2d:

    case 0x2e:

    case 0x2f:

    case 0x30:

      if ((*(byte *)(param_2 + 2) & 1) != 0) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403df9e8,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4fe);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

    }

    iVar4 = *param_2;

    if (iVar4 == 3) {

      if (param_2[3] != param_2[4]) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfa18,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x505);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if ((0x4000 < (uint)param_2[3]) || (0x4000 < (uint)param_2[4])) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfa48,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x509);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if (param_2[5] != 6) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfa78,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x50d);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if (0 < param_2[7]) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfaa8,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x511);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      cVar3 = FUN_140136bc0(param_1,param_2[1],3,param_2[2]);

      if (cVar3 == '\0') {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfad8,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x515);

        } while (iVar4 == 0);

        if (iVar4 != 1) {

          return 0;

        }

        goto LAB_140135cb9;

      }

    }

    else if (iVar4 == 4) {

      if (param_2[3] != param_2[4]) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfb08,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x51b);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if ((0x4000 < (uint)param_2[3]) || (0x4000 < (uint)param_2[4])) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfb38,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x51f);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if (param_2[5] != ((uint)param_2[5] / 6) * 6) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfb68,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x523);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if (0 < param_2[7]) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfb98,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x527);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      cVar3 = FUN_140136bc0(param_1,param_2[1],4,param_2[2]);

      if (cVar3 == '\0') {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfbc8,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x52b);

        } while (iVar4 == 0);

        if (iVar4 != 1) {

          return 0;

        }

        goto LAB_140135cb9;

      }

    }

    else if (iVar4 == 2) {

      if (((0x800 < (uint)param_2[3]) || (0x800 < (uint)param_2[4])) || (0x800 < (uint)param_2[5]))

      {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfbf8,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x531);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if ((*(byte *)(param_2 + 2) & 4) != 0) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfc28,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x535);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      if (0 < param_2[7]) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfc58,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x539);

        } while (iVar4 == 0);

        if (iVar4 == 1) {

          pcVar1 = (code *)swi(3);

          uVar5 = (*pcVar1)();

          return uVar5;

        }

        bVar2 = true;

      }

      cVar3 = FUN_140136bc0(param_1,param_2[1],2,param_2[2]);

      if (cVar3 == '\0') {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfc88,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x53d);

        } while (iVar4 == 0);

        if (iVar4 != 1) {

          return 0;

        }

        goto LAB_140135cb9;

      }

    }

    else {

      if (iVar4 == 1) {

        if ((*(byte *)(param_2 + 2) & 4) != 0) {

          do {

            iVar4 = FUN_14017f2a0(&DAT_1403dfcb8,"SDL_CreateGPUTexture_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x544);

          } while (iVar4 == 0);

          if (iVar4 == 1) {

            pcVar1 = (code *)swi(3);

            uVar5 = (*pcVar1)();

            return uVar5;

          }

          bVar2 = true;

        }

        if (0 < param_2[7]) {

          do {

            iVar4 = FUN_14017f2a0(&DAT_1403dfce8,"SDL_CreateGPUTexture_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x548);

          } while (iVar4 == 0);

          if (iVar4 == 1) {

            pcVar1 = (code *)swi(3);

            uVar5 = (*pcVar1)();

            return uVar5;

          }

          bVar2 = true;

          goto LAB_140135bee;

        }

      }

      else {

LAB_140135bee:

        if ((0 < param_2[7]) && (1 < (uint)param_2[6])) {

          do {

            iVar4 = FUN_14017f2a0(&DAT_1403dfd18,"SDL_CreateGPUTexture_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x54d);

          } while (iVar4 == 0);

          if (iVar4 == 1) {

            pcVar1 = (code *)swi(3);

            uVar5 = (*pcVar1)();

            return uVar5;

          }

          bVar2 = true;

        }

      }

      cVar3 = FUN_140136bc0(param_1,param_2[1],0,param_2[2]);

      if (cVar3 == '\0') {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403dfd48,"SDL_CreateGPUTexture_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x551);

        } while (iVar4 == 0);

        goto LAB_140135cb4;

      }

    }

    if (!bVar2) {

LAB_140135c6c:

                    /* WARNING: Could not recover jumptable at 0x000140135c89. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar5 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x298),param_2);

      return uVar5;

    }

  }

  else {

    do {

      iVar4 = FUN_14017f2a0(&DAT_1403df8c8,"SDL_CreateGPUTexture_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x4e3);

    } while (iVar4 == 0);

LAB_140135cb4:

    if (iVar4 == 1) {

LAB_140135cb9:

      pcVar1 = (code *)swi(3);

      uVar5 = (*pcVar1)();

      return uVar5;

    }

  }

  return 0;

}





// Address: 0x140132d50
// Ghidra name: FUN_140132d50
// ============ 0x140132d50 FUN_140132d50 (size=1185) ============


longlong * FUN_140132d50(longlong *param_1,longlong *param_2,uint param_3,longlong *param_4)



{

  longlong lVar1;

  int *piVar2;

  code *pcVar3;

  int iVar4;

  longlong *plVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  uVar8 = (ulonglong)param_3;

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return (longlong *)0x0;

  }

  if ((param_2 == (longlong *)0x0) && (param_3 != 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","color_target_infos");

    return (longlong *)0x0;

  }

  if (8 < param_3) {

    FUN_14012e850("num_color_targets exceeds MAX_COLOR_TARGET_BINDINGS");

    return (longlong *)0x0;

  }

  if (*(char *)(*param_1 + 0x2ac) == '\0') {

LAB_1401331be:

    (**(code **)(*param_1 + 0xa8))(param_1,param_2,param_3,param_4);

    if (*(char *)(*param_1 + 0x2ac) != '\0') {

      *(undefined1 *)(param_1 + 2) = 1;

      if (param_3 != 0) {

        plVar5 = param_1 + 3;

        do {

          lVar1 = *param_2;

          param_2 = param_2 + 8;

          *plVar5 = lVar1;

          plVar5 = plVar5 + 1;

          uVar8 = uVar8 - 1;

        } while (uVar8 != 0);

      }

      *(uint *)(param_1 + 0xb) = param_3;

      if (param_4 == (longlong *)0x0) {

        param_1[0xc] = 0;

      }

      else {

        param_1[0xc] = *param_4;

      }

    }

    return param_1 + 1;

  }

  if (*(char *)((longlong)param_1 + 0x109) == '\0') {

    if ((((char)param_1[2] == '\0') && ((char)param_1[0x17] == '\0')) &&

       ((char)param_1[0x20] == '\0')) {

      uVar7 = 0;

      if (param_3 != 0) {

        do {

          plVar5 = param_2 + uVar7 * 8;

          lVar1 = *plVar5;

          if (((char)plVar5[7] != '\0') && ((int)plVar5[4] == 0)) goto LAB_140132f30;

          if (*(int *)((longlong)plVar5 + 0x24) - 2U < 2) {

            piVar2 = (int *)plVar5[5];

            if (piVar2 == (int *)0x0) goto LAB_140133050;

            if (*(int *)(lVar1 + 0x1c) == 0) goto LAB_140133020;

            if (piVar2[7] != 0) goto LAB_140132ff0;

            if (piVar2[1] != *(int *)(lVar1 + 4)) goto LAB_140132fc0;

            if (*piVar2 == 2) goto LAB_140132f90;

            if ((*(byte *)(piVar2 + 2) & 2) == 0) goto LAB_140132f60;

          }

          if (*(uint *)(lVar1 + 0x14) <= *(uint *)(uVar7 * 0x40 + 0xc + (longlong)param_2))

          goto LAB_1401330b0;

          if (*(uint *)(lVar1 + 0x18) <= *(uint *)(param_2 + uVar7 * 8 + 1)) goto LAB_140133080;

          uVar6 = (int)uVar7 + 1;

          uVar7 = (ulonglong)uVar6;

        } while (uVar6 < param_3);

      }

      if (param_4 == (longlong *)0x0) goto LAB_1401331be;

      if ((*(byte *)(*param_4 + 8) & 4) == 0) {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403e00d8,"SDL_BeginGPURenderPass_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x73c);

        } while (iVar4 == 0);

      }

      else if (*(uint *)(*param_4 + 0x14) < 0x100) {

        if ((*(char *)((longlong)param_4 + 0x1c) == '\0') ||

           ((*(int *)((longlong)param_4 + 0xc) != 0 && (*(int *)((longlong)param_4 + 0x14) != 0))))

        {

          if (((int)param_4[2] != 2) &&

             ((((int)param_4[3] != 2 && ((int)param_4[2] != 3)) && ((int)param_4[3] != 3))))

          goto LAB_1401331be;

          do {

            iVar4 = FUN_14017f2a0(&DAT_1403e0168,"SDL_BeginGPURenderPass_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x74e);

          } while (iVar4 == 0);

        }

        else {

          do {

            iVar4 = FUN_14017f2a0(&DAT_1403e0138,"SDL_BeginGPURenderPass_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x746);

          } while (iVar4 == 0);

        }

      }

      else {

        do {

          iVar4 = FUN_14017f2a0(&DAT_1403e0108,"SDL_BeginGPURenderPass_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x741);

        } while (iVar4 == 0);

      }

    }

    else {

      do {

        iVar4 = FUN_14017f2a0(&DAT_1403dfef8,"SDL_BeginGPURenderPass_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x707);

      } while (iVar4 == 0);

    }

  }

  else {

    do {

      iVar4 = FUN_14017f2a0(&DAT_1403dfec8,"SDL_BeginGPURenderPass_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x706);

    } while (iVar4 == 0);

  }

LAB_1401331b4:

  if (iVar4 != 1) {

    return (longlong *)0x0;

  }

  pcVar3 = (code *)swi(3);

  plVar5 = (longlong *)(*pcVar3)();

  return plVar5;

LAB_140132f30:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403dff28,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x70d);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140133050:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403dff58,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x713);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140133020:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403dff88,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x718);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140132ff0:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403dffb8,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x71c);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140132fc0:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403dffe8,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x720);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140132f90:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403e0018,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x724);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140132f60:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403e0048,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x728);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_1401330b0:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403e0078,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x72f);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

LAB_140133080:

  do {

    iVar4 = FUN_14017f2a0(&DAT_1403e00a8,"SDL_BeginGPURenderPass_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x734);

  } while (iVar4 == 0);

  goto LAB_1401331b4;

}





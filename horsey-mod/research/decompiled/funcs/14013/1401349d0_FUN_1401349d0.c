// Address: 0x1401349d0
// Ghidra name: FUN_1401349d0
// ============ 0x1401349d0 FUN_1401349d0 (size=2234) ============


undefined8 FUN_1401349d0(longlong param_1,longlong *param_2)



{

  code *pcVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  uint uVar5;

  uint uVar6;

  longlong lVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  uint uVar10;

  int aiStack_48 [16];

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","graphicsPipelineCreateInfo");

    return 0;

  }

  if (*(char *)(param_1 + 0x2ac) == '\0') {

LAB_1401352de:

    uVar4 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x298),param_2);

    return uVar4;

  }

  if (*param_2 == 0) {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403df178,"SDL_CreateGPUGraphicsPipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x40f);

    } while (iVar3 == 0);

  }

  else if (param_2[1] == 0) {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403df1a8,"SDL_CreateGPUGraphicsPipeline_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x413);

    } while (iVar3 == 0);

  }

  else {

    if ((int)param_2[0x12] != 0) {

      if (param_2[0x11] == 0) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df1d8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x417);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

      uVar8 = 0;

      do {

        iVar3 = *(int *)(uVar8 * 0x24 + param_2[0x11]);

        if (0x67 < iVar3 - 1U) goto LAB_140134dd0;

        if ((((iVar3 == 0x3a) || (iVar3 == 0x3b)) || (iVar3 == 0x3c)) ||

           ((iVar3 == 0x3d || (iVar3 == 0x3e)))) goto LAB_140134da0;

        cVar2 = FUN_140136bc0(param_1,iVar3,0,2);

        if (cVar2 == '\0') goto LAB_140134d70;

        lVar7 = param_2[0x11] + uVar8 * 0x24;

        if (*(char *)(lVar7 + 0x1d) != '\0') {

          if (0xc < *(int *)(lVar7 + 4) - 1U) goto LAB_140134d40;

          if (0xc < *(int *)(lVar7 + 8) - 1U) goto LAB_140134d10;

          if (4 < *(int *)(lVar7 + 0xc) - 1U) goto LAB_140134ce0;

          if (0xc < *(int *)(lVar7 + 0x10) - 1U) goto LAB_140134cb0;

          if (0xc < *(int *)(lVar7 + 0x14) - 1U) goto LAB_140134c80;

          if (4 < *(int *)(lVar7 + 0x18) - 1U) goto LAB_140134c50;

        }

        uVar10 = (int)uVar8 + 1;

        uVar8 = (ulonglong)uVar10;

      } while (uVar10 < *(uint *)(param_2 + 0x12));

    }

    if ((char)param_2[0x13] != '\0') {

      iVar3 = *(int *)((longlong)param_2 + 0x94);

      if ((iVar3 < 1) || (0x68 < iVar3)) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df3b8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x431);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

      if ((((iVar3 != 0x3a) && (iVar3 != 0x3b)) && (iVar3 != 0x3c)) &&

         ((iVar3 != 0x3d && (iVar3 != 0x3e)))) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df3e8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x433);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

      cVar2 = FUN_140136bc0(param_1,iVar3,0,4);

      if (cVar2 == '\0') {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df418,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x437);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

    }

    if (*(char *)((longlong)param_2 + 0x59) != '\0') {

      if ((int)param_2[0x12] != 0) {

        switch(*(undefined4 *)param_2[0x11]) {

        case 1:

        case 4:

        case 7:

        case 8:

        case 10:

        case 0xb:

        case 0xc:

        case 0xd:

        case 0xe:

        case 0xf:

        case 0x12:

        case 0x17:

        case 0x1a:

        case 0x1d:

        case 0x20:

        case 0x24:

        case 0x27:

        case 0x2a:

        case 0x2d:

        case 0x30:

        case 0x33:

        case 0x34:

        case 0x35:

        case 0x36:

        case 0x37:

        case 0x38:

        case 0x39:

        case 0x3f:

        case 0x40:

        case 0x41:

        case 0x42:

        case 0x43:

        case 0x44:

        case 0x45:

        case 0x46:

        case 0x47:

        case 0x48:

        case 0x49:

        case 0x4a:

        case 0x4b:

        case 0x4c:

        case 0x4d:

        case 0x4e:

        case 0x4f:

        case 0x50:

        case 0x51:

        case 0x52:

        case 0x53:

        case 0x54:

        case 0x55:

        case 0x56:

        case 0x57:

        case 0x58:

        case 0x59:

        case 0x5a:

        case 0x5b:

        case 0x5c:

        case 0x5d:

        case 0x5e:

        case 0x5f:

        case 0x60:

        case 0x61:

        case 0x62:

        case 99:

        case 100:

        case 0x65:

        case 0x66:

        case 0x67:

        case 0x68:

          goto switchD_140134ed5_caseD_1;

        default:

          do {

            iVar3 = FUN_14017f2a0(&DAT_1403df478,"SDL_CreateGPUGraphicsPipeline_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x441);

          } while (iVar3 == 0);

          goto LAB_1401352d4;

        }

      }

      do {

        iVar3 = FUN_14017f2a0(&DAT_1403df448,"SDL_CreateGPUGraphicsPipeline_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x43d);

      } while (iVar3 == 0);

      goto LAB_1401352d4;

    }

switchD_140134ed5_caseD_1:

    uVar10 = *(uint *)(param_2 + 3);

    if (uVar10 != 0) {

      if (param_2[2] == 0) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df4a8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x448);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

      if (0x10 < uVar10) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df4d8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x44d);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

    }

    if (*(uint *)(param_2 + 5) != 0) {

      if (param_2[4] == 0) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df508,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x451);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

      if (0x10 < *(uint *)(param_2 + 5)) {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df538,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x456);

        } while (iVar3 == 0);

        goto LAB_1401352d4;

      }

    }

    uVar8 = 0;

    if (uVar10 != 0) {

      do {

        if (*(int *)(param_2[2] + 0xc + uVar8 * 0x10) != 0) goto LAB_1401350a0;

        uVar5 = (int)uVar8 + 1;

        uVar8 = (ulonglong)uVar5;

      } while (uVar5 < uVar10);

    }

    uVar10 = *(uint *)(param_2 + 5);

    uVar5 = 0;

    if (uVar10 != 0) {

      lVar7 = param_2[4];

      do {

        uVar8 = (ulonglong)uVar5;

        if (0x1d < *(int *)(lVar7 + 8 + uVar8 * 0x10) - 1U) goto LAB_140135100;

        iVar3 = *(int *)(lVar7 + uVar8 * 0x10);

        uVar9 = 0;

        aiStack_48[uVar8] = iVar3;

        if (uVar5 != 0) {

          do {

            if (aiStack_48[uVar9] == iVar3) goto LAB_1401350d0;

            uVar6 = (int)uVar9 + 1;

            uVar9 = (ulonglong)uVar6;

          } while (uVar6 < uVar5);

        }

        uVar5 = uVar5 + 1;

      } while (uVar5 < uVar10);

    }

    if ((char)param_2[0xb] == '\0') {

      if (*(int *)((longlong)param_2 + 0x54) == 0) {

        if ((*(char *)((longlong)param_2 + 0x82) == '\0') ||

           ((0 < *(int *)((longlong)param_2 + 0x5c) && (*(int *)((longlong)param_2 + 0x5c) < 9)))) {

          if (*(char *)((longlong)param_2 + 0x84) != '\0') {

            if (7 < *(int *)((longlong)param_2 + 0x6c) - 1U) {

              do {

                iVar3 = FUN_14017f2a0(&DAT_1403df688,"SDL_CreateGPUGraphicsPipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x478);

              } while (iVar3 == 0);

              goto LAB_1401352d4;

            }

            if (7 < (int)param_2[0xc] - 1U) {

              do {

                iVar3 = FUN_14017f2a0(&DAT_1403df6b8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x479);

              } while (iVar3 == 0);

              goto LAB_1401352d4;

            }

            if (7 < *(int *)((longlong)param_2 + 100) - 1U) {

              do {

                iVar3 = FUN_14017f2a0(&DAT_1403df6e8,"SDL_CreateGPUGraphicsPipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x47a);

              } while (iVar3 == 0);

              goto LAB_1401352d4;

            }

            if (((int)param_2[0xd] < 1) || (8 < (int)param_2[0xd])) {

              do {

                iVar3 = FUN_14017f2a0(&DAT_1403df718,"SDL_CreateGPUGraphicsPipeline_REAL",

                                      "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x47b);

              } while (iVar3 == 0);

              goto LAB_1401352d4;

            }

          }

          if ((*(char *)(param_1 + 0x2ae) == '\0') || (*(char *)((longlong)param_2 + 0x4d) != '\0'))

          goto LAB_1401352de;

          do {

            iVar3 = FUN_14017f2a0(&DAT_1403df748,"SDL_CreateGPUGraphicsPipeline_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x480);

          } while (iVar3 == 0);

        }

        else {

          do {

            iVar3 = FUN_14017f2a0(&DAT_1403df658,"SDL_CreateGPUGraphicsPipeline_REAL",

                                  "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x474);

          } while (iVar3 == 0);

        }

      }

      else {

        do {

          iVar3 = FUN_14017f2a0(&DAT_1403df628,"SDL_CreateGPUGraphicsPipeline_REAL",

                                "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x470);

        } while (iVar3 == 0);

      }

    }

    else {

      do {

        iVar3 = FUN_14017f2a0(&DAT_1403df5f8,"SDL_CreateGPUGraphicsPipeline_REAL",

                              "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x46c);

      } while (iVar3 == 0);

    }

  }

LAB_1401352d4:

  if (iVar3 != 1) {

    return 0;

  }

  pcVar1 = (code *)swi(3);

  uVar4 = (*pcVar1)();

  return uVar4;

LAB_140134dd0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df208,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x41b);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134da0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df238,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x41d);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134d70:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df268,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x421);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134d40:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df298,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x426);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134d10:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df2c8,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x427);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134ce0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df2f8,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x428);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134cb0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df328,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x429);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134c80:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df358,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x42a);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140134c50:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df388,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x42b);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_1401350a0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df568,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x45b);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_140135100:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df598,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x461);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

LAB_1401350d0:

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403df5c8,"SDL_CreateGPUGraphicsPipeline_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x466);

  } while (iVar3 == 0);

  goto LAB_1401352d4;

}





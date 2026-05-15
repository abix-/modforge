// Address: 0x140219730
// Ghidra name: FUN_140219730
// ============ 0x140219730 FUN_140219730 (size=1716) ============


undefined8 FUN_140219730(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong lVar2;

  char *pcVar3;

  longlong lVar4;

  char *pcVar5;

  undefined8 uVar6;

  char **ppcVar7;

  uint uVar8;

  char *local_18 [2];

  

  lVar2 = FUN_140142960("SDL_VIDEO_WIN_D3DCOMPILER");

  if (lVar2 == 0) {

    iVar1 = FUN_1401a9990();

    if (iVar1 == 0) {

      lVar2 = FUN_1401885b0("d3dcompiler_43.dll");

      goto joined_r0x0001402197d6;

    }

    uVar8 = 0;

    local_18[0] = "d3dcompiler_47.dll";

    ppcVar7 = local_18;

    local_18[1] = "d3dcompiler_46.dll";

    do {

      lVar2 = FUN_1401885b0(*ppcVar7);

      if (lVar2 != 0) break;

      FUN_14012e710();

      uVar8 = uVar8 + 1;

      ppcVar7 = ppcVar7 + 1;

    } while (uVar8 < 2);

  }

  else {

    iVar1 = FUN_14012ef60(lVar2,&DAT_140338bac);

    if (iVar1 != 0) {

      lVar2 = FUN_1401885b0(lVar2);

joined_r0x0001402197d6:

      if (lVar2 == 0) {

        FUN_14012e710();

      }

    }

  }

  pcVar3 = (char *)FUN_140142960("SDL_OPENGL_LIBRARY");

  if ((pcVar3 == (char *)0x0) || (lVar2 = FUN_1401885b0(pcVar3), lVar2 == 0)) {

    if (*(int *)(param_1 + 0x3f0) == 4) {

      if (*(int *)(param_1 + 0x3e4) < 2) {

        pcVar3 = "libGLESv1_CM.dll";

        lVar2 = FUN_1401885b0("libGLESv1_CM.dll");

        if (lVar2 != 0) goto LAB_14021984e;

        pcVar3 = "libGLES_CM.dll";

      }

      else {

        pcVar3 = "libGLESv2.dll";

      }

    }

    else {

      pcVar3 = "opengl32.dll";

    }

    lVar2 = FUN_1401885b0(pcVar3);

  }

LAB_14021984e:

  **(longlong **)(param_1 + 0x690) = lVar2;

  if (lVar2 == 0) {

    pcVar3 = "Could not initialize OpenGL / GLES library";

    goto LAB_140219dca;

  }

  if ((param_2 == 0) || (lVar2 = FUN_1401885b0(param_2), lVar2 == 0)) {

LAB_14021989a:

    pcVar5 = (char *)FUN_140142960("SDL_EGL_LIBRARY");

    pcVar3 = "libEGL.dll";

    if (pcVar5 != (char *)0x0) {

      pcVar3 = pcVar5;

    }

    lVar2 = FUN_1401885b0(pcVar3);

    if (lVar2 != 0) {

      lVar4 = FUN_140188550(lVar2,"eglChooseConfig");

      if (lVar4 != 0) {

        FUN_14012e710();

        goto LAB_1402198e5;

      }

      FUN_140188670(lVar2);

    }

    pcVar3 = "Could not load EGL library";

  }

  else {

    lVar4 = FUN_140188550(lVar2,"eglChooseConfig");

    if (lVar4 == 0) {

      FUN_140188670(lVar2);

      goto LAB_14021989a;

    }

LAB_1402198e5:

    *(longlong *)(*(longlong *)(param_1 + 0x690) + 8) = lVar2;

    lVar2 = *(longlong *)(param_1 + 0x690);

    uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglGetDisplay");

    *(undefined8 *)(lVar2 + 0x40) = uVar6;

    lVar2 = *(longlong *)(param_1 + 0x690);

    if (*(longlong *)(lVar2 + 0x40) == 0) {

      pcVar3 = "Could not retrieve EGL function eglGetDisplay";

    }

    else {

      uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglInitialize");

      *(undefined8 *)(lVar2 + 0x48) = uVar6;

      lVar2 = *(longlong *)(param_1 + 0x690);

      if (*(longlong *)(lVar2 + 0x48) == 0) {

        pcVar3 = "Could not retrieve EGL function eglInitialize";

      }

      else {

        uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglTerminate");

        *(undefined8 *)(lVar2 + 0x50) = uVar6;

        lVar2 = *(longlong *)(param_1 + 0x690);

        if (*(longlong *)(lVar2 + 0x50) == 0) {

          pcVar3 = "Could not retrieve EGL function eglTerminate";

        }

        else {

          uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglGetProcAddress");

          *(undefined8 *)(lVar2 + 0x58) = uVar6;

          lVar2 = *(longlong *)(param_1 + 0x690);

          if (*(longlong *)(lVar2 + 0x58) == 0) {

            pcVar3 = "Could not retrieve EGL function eglGetProcAddress";

          }

          else {

            uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglChooseConfig");

            *(undefined8 *)(lVar2 + 0x60) = uVar6;

            lVar2 = *(longlong *)(param_1 + 0x690);

            if (*(longlong *)(lVar2 + 0x60) == 0) {

              pcVar3 = "Could not retrieve EGL function eglChooseConfig";

            }

            else {

              uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglCreateContext");

              *(undefined8 *)(lVar2 + 0x68) = uVar6;

              lVar2 = *(longlong *)(param_1 + 0x690);

              if (*(longlong *)(lVar2 + 0x68) == 0) {

                pcVar3 = "Could not retrieve EGL function eglCreateContext";

              }

              else {

                uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglDestroyContext");

                *(undefined8 *)(lVar2 + 0x70) = uVar6;

                lVar2 = *(longlong *)(param_1 + 0x690);

                if (*(longlong *)(lVar2 + 0x70) == 0) {

                  pcVar3 = "Could not retrieve EGL function eglDestroyContext";

                }

                else {

                  uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglCreatePbufferSurface");

                  *(undefined8 *)(lVar2 + 0x78) = uVar6;

                  lVar2 = *(longlong *)(param_1 + 0x690);

                  if (*(longlong *)(lVar2 + 0x78) == 0) {

                    pcVar3 = "Could not retrieve EGL function eglCreatePbufferSurface";

                  }

                  else {

                    uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglCreateWindowSurface");

                    *(undefined8 *)(lVar2 + 0x80) = uVar6;

                    lVar2 = *(longlong *)(param_1 + 0x690);

                    if (*(longlong *)(lVar2 + 0x80) == 0) {

                      pcVar3 = "Could not retrieve EGL function eglCreateWindowSurface";

                    }

                    else {

                      uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglDestroySurface");

                      *(undefined8 *)(lVar2 + 0x88) = uVar6;

                      lVar2 = *(longlong *)(param_1 + 0x690);

                      if (*(longlong *)(lVar2 + 0x88) == 0) {

                        pcVar3 = "Could not retrieve EGL function eglDestroySurface";

                      }

                      else {

                        uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglMakeCurrent");

                        *(undefined8 *)(lVar2 + 0x90) = uVar6;

                        lVar2 = *(longlong *)(param_1 + 0x690);

                        if (*(longlong *)(lVar2 + 0x90) == 0) {

                          pcVar3 = "Could not retrieve EGL function eglMakeCurrent";

                        }

                        else {

                          uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglSwapBuffers");

                          *(undefined8 *)(lVar2 + 0x98) = uVar6;

                          lVar2 = *(longlong *)(param_1 + 0x690);

                          if (*(longlong *)(lVar2 + 0x98) == 0) {

                            pcVar3 = "Could not retrieve EGL function eglSwapBuffers";

                          }

                          else {

                            uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglSwapInterval");

                            *(undefined8 *)(lVar2 + 0xa0) = uVar6;

                            lVar2 = *(longlong *)(param_1 + 0x690);

                            if (*(longlong *)(lVar2 + 0xa0) == 0) {

                              pcVar3 = "Could not retrieve EGL function eglSwapInterval";

                            }

                            else {

                              uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglQueryString");

                              *(undefined8 *)(lVar2 + 0xa8) = uVar6;

                              lVar2 = *(longlong *)(param_1 + 0x690);

                              if (*(longlong *)(lVar2 + 0xa8) == 0) {

                                pcVar3 = "Could not retrieve EGL function eglQueryString";

                              }

                              else {

                                uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),

                                                      "eglGetConfigAttrib");

                                *(undefined8 *)(lVar2 + 0xb0) = uVar6;

                                lVar2 = *(longlong *)(param_1 + 0x690);

                                if (*(longlong *)(lVar2 + 0xb0) == 0) {

                                  pcVar3 = "Could not retrieve EGL function eglGetConfigAttrib";

                                }

                                else {

                                  uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglWaitNative");

                                  *(undefined8 *)(lVar2 + 0xb8) = uVar6;

                                  lVar2 = *(longlong *)(param_1 + 0x690);

                                  if (*(longlong *)(lVar2 + 0xb8) == 0) {

                                    pcVar3 = "Could not retrieve EGL function eglWaitNative";

                                  }

                                  else {

                                    uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglWaitGL");

                                    *(undefined8 *)(lVar2 + 0xc0) = uVar6;

                                    lVar2 = *(longlong *)(param_1 + 0x690);

                                    if (*(longlong *)(lVar2 + 0xc0) == 0) {

                                      pcVar3 = "Could not retrieve EGL function eglWaitGL";

                                    }

                                    else {

                                      uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),"eglBindAPI")

                                      ;

                                      *(undefined8 *)(lVar2 + 200) = uVar6;

                                      lVar2 = *(longlong *)(param_1 + 0x690);

                                      if (*(longlong *)(lVar2 + 200) == 0) {

                                        pcVar3 = "Could not retrieve EGL function eglBindAPI";

                                      }

                                      else {

                                        uVar6 = FUN_140188550(*(undefined8 *)(lVar2 + 8),

                                                              "eglGetError");

                                        *(undefined8 *)(lVar2 + 0xd0) = uVar6;

                                        lVar2 = *(longlong *)(param_1 + 0x690);

                                        if (*(longlong *)(lVar2 + 0xd0) != 0) {

                                          uVar6 = (**(code **)(lVar2 + 0x58))("eglQueryDevicesEXT");

                                          *(undefined8 *)(lVar2 + 0xd8) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))

                                                            ("eglGetPlatformDisplayEXT");

                                          *(undefined8 *)(lVar2 + 0xe8) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))("eglCreateSyncKHR");

                                          *(undefined8 *)(lVar2 + 0xf0) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))("eglDestroySyncKHR");

                                          *(undefined8 *)(lVar2 + 0xf8) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))

                                                            ("eglDupNativeFenceFDANDROID");

                                          *(undefined8 *)(lVar2 + 0x100) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))("eglWaitSyncKHR");

                                          *(undefined8 *)(lVar2 + 0x108) = uVar6;

                                          lVar2 = *(longlong *)(param_1 + 0x690);

                                          uVar6 = (**(code **)(lVar2 + 0x58))

                                                            ("eglClientWaitSyncKHR");

                                          *(undefined8 *)(lVar2 + 0x110) = uVar6;

                                          if (pcVar3 != (char *)0x0) {

                                            FUN_14012f1a0(param_1 + 0x418,pcVar3,0xff);

                                            return 1;

                                          }

                                          *(undefined1 *)(param_1 + 0x418) = 0;

                                          return 1;

                                        }

                                        pcVar3 = "Could not retrieve EGL function eglGetError";

                                      }

                                    }

                                  }

                                }

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

LAB_140219dca:

  uVar6 = FUN_14012e850(pcVar3);

  return uVar6;

}





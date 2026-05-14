// Address: 0x1402d20f0
// Ghidra name: FUN_1402d20f0
// ============ 0x1402d20f0 FUN_1402d20f0 (size=1898) ============


uint FUN_1402d20f0(longlong param_1,longlong *param_2,uint param_3,uint param_4)



{

  short sVar1;

  ushort *puVar2;

  short *psVar3;

  ushort *puVar4;

  longlong *plVar5;

  int iVar6;

  uint uVar7;

  undefined4 *puVar8;

  ulonglong uVar9;

  uint uVar10;

  uint uVar11;

  ulonglong uVar12;

  ushort uVar13;

  uint uVar14;

  int local_a8;

  

  puVar2 = (ushort *)*param_2;

  uVar9 = (ulonglong)param_3;

  if (puVar2 == (ushort *)0x0) {

    puVar8 = (undefined4 *)FUN_1402e68b0();

    *puVar8 = 0x16;

    FUN_1402cd454();

LAB_1402d2169:

    if ((longlong *)param_2[1] != (longlong *)0x0) {

      *(longlong *)param_2[1] = *param_2;

    }

    return 0;

  }

  if ((param_3 != 0) && (0x22 < param_3 - 2)) {

    *(undefined1 *)(param_1 + 0x30) = 1;

    *(undefined4 *)(param_1 + 0x2c) = 0x16;

    FUN_1402cd39c(0,0,0,0,0,param_1);

    goto LAB_1402d2169;

  }

  uVar13 = *puVar2;

  *param_2 = (longlong)(puVar2 + 1);

  uVar14 = param_4 & 0xff | 2;

  if (uVar13 != 0x2d) {

    uVar14 = param_4 & 0xff;

  }

  if ((uVar13 - 0x2b & 0xfffd) == 0) {

    uVar13 = puVar2[1];

    *param_2 = (longlong)(puVar2 + 2);

  }

  local_a8 = 0xae6;

  if ((param_3 & 0xffffffef) != 0) goto LAB_1402d252d;

  if (uVar13 < 0x30) goto LAB_1402d247e;

  iVar6 = 0x30;

  if (uVar13 < 0x3a) {

LAB_1402d22c3:

    iVar6 = (uint)uVar13 - iVar6;

LAB_1402d2479:

    if (iVar6 == -1) goto LAB_1402d247e;

LAB_1402d24a4:

    if (iVar6 != 0) goto LAB_1402d251e;

    psVar3 = (short *)*param_2;

    sVar1 = *psVar3;

    *param_2 = (longlong)(psVar3 + 1);

    if ((sVar1 - 0x58U & 0xffdf) != 0) {

      *param_2 = (longlong)psVar3;

      uVar9 = 8;

      if (param_3 != 0) {

        uVar9 = (ulonglong)param_3;

      }

      if ((sVar1 != 0) && (*psVar3 != sVar1)) {

        puVar8 = (undefined4 *)FUN_1402e68b0();

        *puVar8 = 0x16;

        FUN_1402cd454();

      }

      goto LAB_1402d252d;

    }

    uVar13 = psVar3[1];

    *param_2 = (longlong)(psVar3 + 2);

    uVar9 = 0x10;

  }

  else {

    if (uVar13 < 0xff10) {

      if (0x65f < uVar13) {

        if (uVar13 < 0x66a) {

          iVar6 = uVar13 - 0x660;

          goto LAB_1402d2479;

        }

        if (0x6ef < uVar13) {

          if (uVar13 < 0x6fa) {

            iVar6 = uVar13 - 0x6f0;

            goto LAB_1402d2479;

          }

          if (0x965 < uVar13) {

            if (uVar13 < 0x970) {

              iVar6 = uVar13 - 0x966;

              goto LAB_1402d2479;

            }

            if (0x9e5 < uVar13) {

              if (uVar13 < 0x9f0) {

                iVar6 = uVar13 - 0x9e6;

                goto LAB_1402d2479;

              }

              if (0xa65 < uVar13) {

                if (uVar13 < 0xa70) {

                  iVar6 = uVar13 - 0xa66;

                  goto LAB_1402d2479;

                }

                if ((0xae5 < uVar13) &&

                   ((iVar6 = local_a8, uVar13 < 0xaf0 ||

                    ((iVar6 = 0xb66, 0xb65 < uVar13 &&

                     ((uVar13 < 0xb70 ||

                      ((iVar6 = 0xc66, 0xc65 < uVar13 &&

                       ((uVar13 < 0xc70 ||

                        ((iVar6 = 0xce6, 0xce5 < uVar13 &&

                         ((uVar13 < 0xcf0 ||

                          ((iVar6 = 0xd66, 0xd65 < uVar13 &&

                           ((uVar13 < 0xd70 ||

                            ((iVar6 = 0xe50, 0xe4f < uVar13 &&

                             ((uVar13 < 0xe5a ||

                              ((iVar6 = 0xed0, 0xecf < uVar13 &&

                               ((uVar13 < 0xeda ||

                                ((iVar6 = 0xf20, 0xf1f < uVar13 &&

                                 ((uVar13 < 0xf2a ||

                                  ((iVar6 = 0x1040, 0x103f < uVar13 &&

                                   ((uVar13 < 0x104a ||

                                    ((iVar6 = 0x17e0, 0x17df < uVar13 &&

                                     ((uVar13 < 0x17ea ||

                                      (iVar6 = 0x1810, (ushort)(uVar13 + 0xe7f0) < 10)))))))))))))))

                               ))))))))))))))))))))))))) goto LAB_1402d22c3;

              }

            }

          }

        }

      }

    }

    else if (uVar13 < 0xff1a) {

      iVar6 = uVar13 - 0xff10;

      goto LAB_1402d2479;

    }

LAB_1402d247e:

    uVar10 = (uint)uVar13;

    if ((uVar13 - 0x41 < 0x1a) || (uVar13 - 0x61 < 0x1a)) {

      if (uVar13 - 0x61 < 0x1a) {

        uVar10 = uVar13 - 0x20;

      }

      iVar6 = uVar10 - 0x37;

      goto LAB_1402d24a4;

    }

LAB_1402d251e:

    uVar9 = 10;

  }

  if (param_3 != 0) {

    uVar9 = (ulonglong)param_3;

  }

LAB_1402d252d:

  uVar12 = 0xffffffff % uVar9;

  uVar10 = 0;

  do {

    if (uVar13 < 0x30) goto LAB_1402d26fa;

    if (uVar13 < 0x3a) {

      uVar11 = uVar13 - 0x30;

LAB_1402d26f5:

      if (uVar11 == 0xffffffff) goto LAB_1402d26fa;

    }

    else {

      if (uVar13 < 0xff10) {

        if (0x65f < uVar13) {

          if (uVar13 < 0x66a) {

            uVar11 = uVar13 - 0x660;

            goto LAB_1402d26f5;

          }

          if (0x6ef < uVar13) {

            if (uVar13 < 0x6fa) {

              uVar11 = uVar13 - 0x6f0;

              goto LAB_1402d26f5;

            }

            if (0x965 < uVar13) {

              iVar6 = 0x966;

              if (uVar13 < 0x970) {

LAB_1402d25c1:

                uVar11 = (uint)uVar13 - iVar6;

                goto LAB_1402d26f5;

              }

              if (0x9e5 < uVar13) {

                iVar6 = 0x9e6;

                if (uVar13 < 0x9f0) goto LAB_1402d25c1;

                if (0xa65 < uVar13) {

                  iVar6 = 0xa66;

                  if (uVar13 < 0xa70) goto LAB_1402d25c1;

                  if (0xae5 < uVar13) {

                    iVar6 = local_a8;

                    if (uVar13 < 0xaf0) goto LAB_1402d25c1;

                    iVar6 = 0xb66;

                    if (0xb65 < uVar13) {

                      if (uVar13 < 0xb70) goto LAB_1402d25c1;

                      iVar6 = 0xc66;

                      if (0xc65 < uVar13) {

                        if (uVar13 < 0xc70) goto LAB_1402d25c1;

                        iVar6 = 0xce6;

                        if (0xce5 < uVar13) {

                          if (uVar13 < 0xcf0) goto LAB_1402d25c1;

                          iVar6 = 0xd66;

                          if (0xd65 < uVar13) {

                            if (uVar13 < 0xd70) goto LAB_1402d25c1;

                            iVar6 = 0xe50;

                            if (0xe4f < uVar13) {

                              if (uVar13 < 0xe5a) goto LAB_1402d25c1;

                              iVar6 = 0xed0;

                              if (0xecf < uVar13) {

                                if (uVar13 < 0xeda) goto LAB_1402d25c1;

                                iVar6 = 0xf20;

                                if (0xf1f < uVar13) {

                                  if (uVar13 < 0xf2a) goto LAB_1402d25c1;

                                  iVar6 = 0x1040;

                                  if (0x103f < uVar13) {

                                    if (uVar13 < 0x104a) goto LAB_1402d25c1;

                                    iVar6 = 0x17e0;

                                    if (0x17df < uVar13) {

                                      if (uVar13 < 0x17ea) goto LAB_1402d25c1;

                                      uVar12 = 0x1810;

                                      if ((ushort)(uVar13 + 0xe7f0) < 10) {

                                        uVar11 = uVar13 - 0x1810;

                                        goto LAB_1402d26f5;

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

      else if (uVar13 < 0xff1a) {

        uVar11 = uVar13 - 0xff10;

        goto LAB_1402d26f5;

      }

LAB_1402d26fa:

      uVar11 = (uint)uVar13;

      if (((uVar13 < 0x41) || (0x5a < uVar13)) && ((uVar11 < 0x61 || (0x7a < uVar13)))) {

        uVar11 = 0xffffffff;

      }

      else {

        if ((ushort)(uVar13 - 0x61) < 0x1a) {

          uVar11 = uVar11 - 0x20;

        }

        uVar11 = uVar11 - 0x37;

      }

    }

    puVar4 = (ushort *)*param_2;

    if ((uint)uVar9 <= uVar11) break;

    uVar13 = *puVar4;

    uVar7 = uVar10 * (uint)uVar9;

    uVar11 = uVar7 + uVar11;

    uVar12 = (ulonglong)uVar11;

    *param_2 = (longlong)(puVar4 + 1);

    uVar14 = uVar14 | (uint)(uVar11 < uVar7 || (uint)(0xffffffff / uVar9) < uVar10) << 2 | 8;

    uVar10 = uVar11;

  } while( true );

  *param_2 = (longlong)(puVar4 + -1);

  if ((uVar13 != 0) && (puVar4[-1] != uVar13)) {

    puVar8 = (undefined4 *)FUN_1402e68b0(uVar11,uVar12);

    *puVar8 = 0x16;

    FUN_1402cd454();

  }

  if ((uVar14 & 8) == 0) {

    *param_2 = (longlong)puVar2;

    if ((undefined8 *)param_2[1] == (undefined8 *)0x0) {

      return 0;

    }

    *(undefined8 *)param_2[1] = puVar2;

    return 0;

  }

  if ((uVar14 & 4) == 0) {

    if ((uVar14 & 1) == 0) {

      if ((uVar14 & 2) == 0) goto LAB_1402d27f7;

LAB_1402d2816:

      uVar10 = -uVar10;

      goto LAB_1402d27f7;

    }

    if ((uVar14 & 2) == 0) {

      if (uVar10 < 0x80000000) goto LAB_1402d27f7;

    }

    else if (uVar10 < 0x80000001) goto LAB_1402d2816;

  }

  *(undefined1 *)(param_1 + 0x30) = 1;

  *(undefined4 *)(param_1 + 0x2c) = 0x22;

  if ((uVar14 & 1) != 0) {

    plVar5 = (longlong *)param_2[1];

    if ((uVar14 & 2) != 0) {

      if (plVar5 != (longlong *)0x0) {

        *plVar5 = *param_2;

      }

      return 0x80000000;

    }

    if (plVar5 != (longlong *)0x0) {

      *plVar5 = *param_2;

      return 0x7fffffff;

    }

    return 0x7fffffff;

  }

  uVar10 = 0xffffffff;

LAB_1402d27f7:

  if ((longlong *)param_2[1] != (longlong *)0x0) {

    *(longlong *)param_2[1] = *param_2;

    return uVar10;

  }

  return uVar10;

}





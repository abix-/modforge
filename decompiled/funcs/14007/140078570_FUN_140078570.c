// Address: 0x140078570
// Ghidra name: FUN_140078570
// ============ 0x140078570 FUN_140078570 (size=4222) ============


int * FUN_140078570(longlong param_1,int param_2,int *param_3,int param_4)



{

  int iVar1;

  byte *pbVar2;

  ushort *puVar3;

  byte bVar4;

  ushort uVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  longlong *plVar10;

  undefined8 *puVar11;

  int *piVar12;

  byte bVar13;

  uint uVar14;

  uint uVar15;

  int *piVar16;

  ulonglong uVar17;

  longlong lVar18;

  uint uVar19;

  longlong *plVar20;

  ulonglong uVar21;

  int *piVar22;

  int iVar23;

  longlong lVar24;

  longlong lVar25;

  int *piVar26;

  uint uVar27;

  uint local_res20;

  int local_78;

  longlong local_70;

  int *local_60;

  

  local_60 = (int *)0x0;

  plVar10 = (longlong *)_malloc_base(0x20000);

  iVar7 = 5;

  if (4 < param_4) {

    iVar7 = param_4;

  }

  puVar11 = (undefined8 *)_realloc_base(0,10);

  if (puVar11 != (undefined8 *)0x0) {

    local_60 = (int *)(puVar11 + 1);

    *puVar11 = 2;

  }

  *(undefined1 *)((longlong)local_60[-1] + (longlong)local_60) = 0x78;

  local_60[-1] = local_60[-1] + 1;

  iVar8 = local_60[-2];

  if (iVar8 <= local_60[-1] + 1) {

    iVar8 = iVar8 * 2;

    piVar12 = local_60 + -2;

    if (local_60 == (int *)0x0) {

      piVar12 = (int *)0x0;

    }

    piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 9);

    if (piVar12 != (int *)0x0) {

      local_60 = piVar12 + 2;

      *piVar12 = iVar8 + 1;

    }

  }

  uVar19 = 3;

  uVar27 = 3;

  *(undefined1 *)((longlong)local_60[-1] + (longlong)local_60) = 0x5e;

  local_60[-1] = local_60[-1] + 1;

  FUN_1402f94c0(plVar10,0,0x20000);

  iVar8 = 0;

  local_78 = 0;

  if (0 < param_2 + -3) {

    do {

      lVar18 = 0;

      lVar24 = (longlong)local_78;

      local_70 = 0;

      uVar14 = (uint)((byte *)(param_1 + lVar24))[2] * 0x10000 +

               (uint)*(byte *)(param_1 + 1 + lVar24) * 0x100 + (uint)*(byte *)(param_1 + lVar24);

      uVar14 = uVar14 * 8 ^ uVar14;

      uVar14 = (uVar14 >> 5) + uVar14;

      uVar14 = uVar14 * 0x10 ^ uVar14;

      uVar14 = (uVar14 >> 0x11) + uVar14;

      uVar15 = 3;

      local_res20 = 3;

      uVar14 = (uVar14 >> 6) + uVar14 & 0x3fff;

      plVar20 = plVar10 + uVar14;

      lVar25 = plVar10[uVar14];

      if (lVar25 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(lVar25 + -4);

      }

      if (0 < iVar8) {

        do {

          lVar6 = *(longlong *)(lVar25 + lVar18 * 8);

          if ((longlong)(local_78 + -0x8000) < lVar6 - param_1) {

            uVar14 = 0;

            if (0 < param_2 - local_78) {

              uVar17 = 0;

              uVar21 = 0;

              do {

                uVar14 = (uint)uVar21;

                uVar15 = local_res20;

                if ((0x101 < uVar17) ||

                   (*(char *)(lVar6 + uVar17) !=

                    ((char *)(lVar6 + uVar17))[(lVar24 - lVar6) + param_1])) break;

                uVar14 = uVar14 + 1;

                uVar21 = (ulonglong)uVar14;

                uVar17 = uVar17 + 1;

              } while ((longlong)uVar17 < (longlong)(param_2 - local_78));

            }

            if ((int)uVar15 <= (int)uVar14) {

              uVar15 = uVar14;

              local_res20 = uVar14;

              local_70 = lVar6;

            }

          }

          lVar18 = lVar18 + 1;

        } while (lVar18 < iVar8);

      }

      if ((lVar25 != 0) && (*(int *)(lVar25 + -4) == iVar7 * 2)) {

        FUN_1402f8e20(lVar25,(longlong)iVar7 * 8 + lVar25);

        *(int *)(*plVar20 + -4) = iVar7;

      }

      lVar25 = *plVar20;

      if (lVar25 == 0) {

        piVar12 = (int *)0x0;

        iVar8 = 2;

LAB_140078816:

        piVar12 = (int *)_realloc_base(piVar12,(longlong)(iVar8 * 8) + 8);

        if (piVar12 != (int *)0x0) {

          if (*plVar20 == 0) {

            piVar12[1] = 0;

          }

          *plVar20 = (longlong)(piVar12 + 2);

          *piVar12 = iVar8;

        }

      }

      else {

        piVar12 = (int *)(lVar25 + -8);

        if (*piVar12 <= *(int *)(lVar25 + -4) + 1) {

          iVar8 = *(int *)(lVar25 + -8) * 2 + 1;

          goto LAB_140078816;

        }

      }

      lVar25 = param_1 + lVar24;

      *(longlong *)(*plVar20 + (longlong)*(int *)(*plVar20 + -4) * 8) = lVar25;

      *(int *)(*plVar20 + -4) = *(int *)(*plVar20 + -4) + 1;

      bVar13 = (byte)uVar27;

      if (local_70 == 0) {

LAB_140078f53:

        bVar4 = *(byte *)(param_1 + local_78);

        if (bVar4 < 0x90) {

          uVar15 = bVar4 + 0x30;

          iVar8 = 8;

          piVar12 = (int *)0x0;

          do {

            uVar14 = uVar15 & 1;

            uVar15 = (int)uVar15 >> 1;

            uVar14 = (int)piVar12 * 2 | uVar14;

            piVar12 = (int *)(ulonglong)uVar14;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 8;

          uVar19 = uVar19 | uVar14 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078fe0:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078fe0;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        else {

          uVar15 = bVar4 + 0x100;

          iVar8 = 9;

          piVar12 = (int *)0x0;

          do {

            uVar14 = uVar15 & 1;

            uVar15 = (int)uVar15 >> 1;

            uVar14 = (int)piVar12 * 2 | uVar14;

            piVar12 = (int *)(ulonglong)uVar14;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 9;

          uVar19 = uVar19 | uVar14 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

                piVar12 = (int *)0x0;

LAB_140079097:

                piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  piVar12 = local_60 + -2;

                  goto LAB_140079097;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        local_res20 = 1;

      }

      else {

        uVar15 = (uint)*(byte *)(lVar25 + 3) * 0x10000 + (uint)*(byte *)(lVar25 + 2) * 0x100 +

                 (uint)*(byte *)(lVar25 + 1);

        uVar15 = uVar15 * 8 ^ uVar15;

        uVar15 = (uVar15 >> 5) + uVar15;

        uVar15 = uVar15 * 0x10 ^ uVar15;

        uVar15 = (uVar15 >> 0x11) + uVar15;

        lVar25 = plVar10[(uVar15 >> 6) + uVar15 & 0x3fff];

        if (lVar25 != 0) {

          lVar18 = 0;

          if (0 < *(int *)(lVar25 + -4)) {

            do {

              uVar17 = 0;

              lVar6 = *(longlong *)(lVar25 + lVar18 * 8);

              if ((longlong)(local_78 + -0x7fff) < lVar6 - param_1) {

                uVar15 = 0;

                iVar8 = (param_2 - local_78) + -1;

                if (0 < iVar8) {

                  uVar21 = uVar17;

                  do {

                    uVar15 = (uint)uVar21;

                    if ((0x101 < uVar17) ||

                       (*(char *)(uVar17 + lVar6) != *(char *)(uVar17 + lVar24 + 1 + param_1)))

                    break;

                    uVar15 = uVar15 + 1;

                    uVar21 = (ulonglong)uVar15;

                    uVar17 = uVar17 + 1;

                  } while ((longlong)uVar17 < (longlong)iVar8);

                }

                if ((int)local_res20 < (int)uVar15) goto LAB_140078f53;

              }

              lVar18 = lVar18 + 1;

            } while (lVar18 < *(int *)(lVar25 + -4));

          }

        }

        uVar15 = 0;

        iVar8 = 0;

        iVar23 = ((int)param_1 - (int)local_70) + local_78;

        lVar25 = 0;

        uVar5 = DAT_1403d95da;

        while ((int)(uVar5 - 1) < (int)local_res20) {

          puVar3 = &DAT_1403d95dc + lVar25;

          lVar25 = lVar25 + 1;

          iVar8 = iVar8 + 1;

          uVar5 = *puVar3;

        }

        iVar1 = iVar8 + 0x101;

        if (iVar1 < 0x90) {

          uVar14 = iVar8 + 0x131;

          iVar8 = 8;

          do {

            uVar9 = uVar14 & 1;

            uVar14 = (int)uVar14 >> 1;

            uVar15 = uVar15 * 2 | uVar9;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 8;

          uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078a45:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078a45;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        else if (iVar1 < 0x100) {

          uVar14 = iVar8 + 0x201;

          iVar8 = 9;

          do {

            uVar9 = uVar14 & 1;

            uVar14 = (int)uVar14 >> 1;

            uVar15 = uVar15 * 2 | uVar9;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 9;

          uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078b03:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078b03;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        else if (iVar1 < 0x118) {

          uVar14 = iVar8 + 1;

          iVar8 = 7;

          do {

            uVar9 = uVar14 & 1;

            uVar14 = (int)uVar14 >> 1;

            uVar15 = uVar15 * 2 | uVar9;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 7;

          uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078bc3:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078bc3;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        else {

          uVar14 = iVar8 + 0xa9;

          iVar8 = 8;

          do {

            uVar9 = uVar14 & 1;

            uVar14 = (int)uVar14 >> 1;

            uVar15 = uVar15 * 2 | uVar9;

            iVar8 = iVar8 + -1;

          } while (iVar8 != 0);

          uVar27 = uVar27 + 8;

          uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078c73:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078c73;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        uVar15 = uVar27;

        if (*(byte *)(lVar25 + 0x1403d9618) != 0) {

          uVar15 = uVar27 + *(byte *)(lVar25 + 0x1403d9618);

          uVar19 = uVar19 | local_res20 - *(ushort *)(lVar25 * 2 + 0x1403d95d8) <<

                            ((byte)uVar27 & 0x1f);

          if (7 < (int)uVar15) {

            uVar17 = (ulonglong)(uVar15 >> 3);

            uVar15 = uVar15 + (uVar15 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078d40:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078d40;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

        uVar14 = 0;

        uVar27 = 0;

        lVar25 = 0;

        uVar5 = DAT_1403d963a;

        while ((int)(uVar5 - 1) < iVar23) {

          puVar3 = &DAT_1403d963c + lVar25;

          lVar25 = lVar25 + 1;

          uVar27 = uVar27 + 1;

          uVar5 = *puVar3;

        }

        iVar8 = 5;

        do {

          uVar9 = uVar27 & 1;

          uVar27 = (int)uVar27 >> 1;

          uVar14 = uVar14 * 2 | uVar9;

          iVar8 = iVar8 + -1;

        } while (iVar8 != 0);

        uVar27 = uVar15 + 5;

        uVar19 = uVar19 | uVar14 << ((byte)uVar15 & 0x1f);

        if (7 < (int)uVar27) {

          uVar17 = (ulonglong)(uVar27 >> 3);

          uVar27 = uVar27 + (uVar27 >> 3) * -8;

          do {

            if (local_60 == (int *)0x0) {

              iVar8 = 2;

LAB_140078e30:

              piVar12 = local_60 + -2;

              if (local_60 == (int *)0x0) {

                piVar12 = (int *)0x0;

              }

              piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

              if (piVar12 != (int *)0x0) {

                if (local_60 == (int *)0x0) {

                  piVar12[1] = 0;

                }

                local_60 = piVar12 + 2;

                *piVar12 = iVar8;

              }

            }

            else {

              iVar8 = local_60[-2];

              if (iVar8 <= local_60[-1] + 1) {

                iVar8 = iVar8 * 2 + 1;

                goto LAB_140078e30;

              }

            }

            *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

            local_60[-1] = local_60[-1] + 1;

            uVar19 = uVar19 >> 8;

            uVar17 = uVar17 - 1;

          } while (uVar17 != 0);

        }

        if (*(byte *)(lVar25 + 0x1403d9678) != 0) {

          bVar13 = (byte)uVar27;

          uVar27 = uVar27 + *(byte *)(lVar25 + 0x1403d9678);

          uVar19 = uVar19 | iVar23 - (uint)*(ushort *)(lVar25 * 2 + 0x1403d9638) << (bVar13 & 0x1f);

          if (7 < (int)uVar27) {

            uVar17 = (ulonglong)(uVar27 >> 3);

            uVar27 = uVar27 + (uVar27 >> 3) * -8;

            do {

              if (local_60 == (int *)0x0) {

                iVar8 = 2;

LAB_140078f00:

                piVar12 = local_60 + -2;

                if (local_60 == (int *)0x0) {

                  piVar12 = (int *)0x0;

                }

                piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

                if (piVar12 != (int *)0x0) {

                  if (local_60 == (int *)0x0) {

                    piVar12[1] = 0;

                  }

                  local_60 = piVar12 + 2;

                  *piVar12 = iVar8;

                }

              }

              else {

                iVar8 = local_60[-2];

                if (iVar8 <= local_60[-1] + 1) {

                  iVar8 = iVar8 * 2 + 1;

                  goto LAB_140078f00;

                }

              }

              *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

              local_60[-1] = local_60[-1] + 1;

              uVar19 = uVar19 >> 8;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

        }

      }

      iVar8 = local_78 + local_res20;

      local_78 = iVar8;

    } while (iVar8 < param_2 + -3);

  }

  lVar18 = (longlong)param_2;

  iVar7 = 2;

  for (lVar25 = (longlong)iVar8; bVar13 = (byte)uVar27, lVar25 < lVar18; lVar25 = lVar25 + 1) {

    uVar15 = 0;

    bVar4 = *(byte *)(param_1 + lVar25);

    if (bVar4 < 0x90) {

      uVar14 = bVar4 + 0x30;

      iVar8 = 8;

      do {

        uVar9 = uVar14 & 1;

        uVar14 = (int)uVar14 >> 1;

        uVar15 = uVar15 * 2 | uVar9;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

      uVar27 = uVar27 + 8;

      uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

      if (7 < (int)uVar27) {

        uVar17 = (ulonglong)(uVar27 >> 3);

        uVar27 = uVar27 + (uVar27 >> 3) * -8;

        do {

          if (local_60 == (int *)0x0) {

            iVar8 = 2;

LAB_1400791b0:

            piVar12 = local_60 + -2;

            if (local_60 == (int *)0x0) {

              piVar12 = (int *)0x0;

            }

            piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

            if (piVar12 != (int *)0x0) {

              if (local_60 == (int *)0x0) {

                piVar12[1] = 0;

              }

              local_60 = piVar12 + 2;

              *piVar12 = iVar8;

            }

          }

          else {

            iVar8 = local_60[-2];

            if (iVar8 <= local_60[-1] + 1) {

              iVar8 = iVar8 * 2 + 1;

              goto LAB_1400791b0;

            }

          }

          *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

          local_60[-1] = local_60[-1] + 1;

          uVar19 = uVar19 >> 8;

          uVar17 = uVar17 - 1;

        } while (uVar17 != 0);

      }

    }

    else {

      uVar14 = bVar4 + 0x100;

      iVar8 = 9;

      do {

        uVar9 = uVar14 & 1;

        uVar14 = (int)uVar14 >> 1;

        uVar15 = uVar15 * 2 | uVar9;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

      uVar27 = uVar27 + 9;

      uVar19 = uVar19 | uVar15 << (bVar13 & 0x1f);

      if (7 < (int)uVar27) {

        uVar17 = (ulonglong)(uVar27 >> 3);

        uVar27 = uVar27 + (uVar27 >> 3) * -8;

        do {

          piVar12 = (int *)0x0;

          if (local_60 == (int *)0x0) {

            iVar8 = 2;

LAB_140079259:

            piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

            if (piVar12 != (int *)0x0) {

              if (local_60 == (int *)0x0) {

                piVar12[1] = 0;

              }

              local_60 = piVar12 + 2;

              *piVar12 = iVar8;

            }

          }

          else {

            piVar12 = local_60 + -2;

            if (*piVar12 <= local_60[-1] + 1) {

              iVar8 = *piVar12 * 2 + 1;

              goto LAB_140079259;

            }

          }

          *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

          local_60[-1] = local_60[-1] + 1;

          uVar19 = uVar19 >> 8;

          uVar17 = uVar17 - 1;

        } while (uVar17 != 0);

      }

    }

  }

  iVar8 = 7;

  do {

    iVar8 = iVar8 + -1;

  } while (iVar8 != 0);

  uVar27 = uVar27 + 7;

  uVar19 = uVar19 | 0 << (bVar13 & 0x1f);

  if (7 < (int)uVar27) {

    uVar17 = (ulonglong)(uVar27 >> 3);

    uVar27 = uVar27 + (uVar27 >> 3) * -8;

    do {

      piVar12 = (int *)0x0;

      if (local_60 == (int *)0x0) {

        iVar8 = 2;

LAB_140079314:

        piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

        if (piVar12 != (int *)0x0) {

          if (local_60 == (int *)0x0) {

            piVar12[1] = 0;

          }

          local_60 = piVar12 + 2;

          *piVar12 = iVar8;

        }

      }

      else {

        piVar12 = local_60 + -2;

        if (*piVar12 <= local_60[-1] + 1) {

          iVar8 = *piVar12 * 2 + 1;

          goto LAB_140079314;

        }

      }

      *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

      local_60[-1] = local_60[-1] + 1;

      uVar19 = uVar19 >> 8;

      uVar17 = uVar17 - 1;

    } while (uVar17 != 0);

  }

  while (uVar27 != 0) {

    uVar27 = uVar27 + 1;

    if (7 < (int)uVar27) {

      uVar17 = (ulonglong)(uVar27 >> 3);

      uVar27 = uVar27 + (uVar27 >> 3) * -8;

      do {

        piVar12 = (int *)0x0;

        if (local_60 == (int *)0x0) {

          iVar8 = 2;

LAB_1400793a6:

          piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar8 + 8);

          if (piVar12 != (int *)0x0) {

            if (local_60 == (int *)0x0) {

              piVar12[1] = 0;

            }

            local_60 = piVar12 + 2;

            *piVar12 = iVar8;

          }

        }

        else {

          piVar12 = local_60 + -2;

          if (*piVar12 <= local_60[-1] + 1) {

            iVar8 = *piVar12 * 2 + 1;

            goto LAB_1400793a6;

          }

        }

        *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar19;

        local_60[-1] = local_60[-1] + 1;

        uVar19 = uVar19 >> 8;

        uVar17 = uVar17 - 1;

      } while (uVar17 != 0);

    }

  }

  lVar25 = 0x4000;

  plVar20 = plVar10;

  do {

    if (*plVar20 != 0) {

      thunk_FUN_1402e9a80(*plVar20 + -8);

    }

    plVar20 = plVar20 + 1;

    lVar25 = lVar25 + -1;

  } while (lVar25 != 0);

  thunk_FUN_1402e9a80(plVar10);

  piVar26 = (int *)0x0;

  uVar27 = 1;

  piVar12 = piVar26;

  if (0 < lVar18) {

    lVar25 = (longlong)(param_2 % 0x15b0);

    piVar22 = piVar26;

    do {

      if (0 < lVar25) {

        piVar16 = piVar26;

        do {

          pbVar2 = (byte *)((longlong)piVar16 + (longlong)piVar22 + param_1);

          piVar16 = (int *)((longlong)piVar16 + 1);

          uVar27 = uVar27 + *pbVar2;

          piVar12 = (int *)(ulonglong)((int)piVar12 + uVar27);

        } while ((longlong)piVar16 < lVar25);

      }

      piVar22 = (int *)((longlong)piVar22 + lVar25);

      lVar25 = 0x15b0;

      uVar27 = uVar27 % 0xfff1;

      piVar12 = (int *)(ulonglong)

                       (uint)((int)piVar12 + (int)((ulonglong)piVar12 / 0xfff1) * -0xfff1);

    } while ((longlong)piVar22 < lVar18);

  }

  piVar22 = piVar26;

  if (local_60 != (int *)0x0) {

    if (local_60[-1] + 1 < local_60[-2]) goto LAB_1400794ff;

    iVar7 = local_60[-2] * 2 + 1;

    piVar22 = local_60 + -2;

  }

  piVar22 = (int *)_realloc_base(piVar22,(longlong)iVar7 + 8);

  if (piVar22 != (int *)0x0) {

    if (local_60 == (int *)0x0) {

      piVar22[1] = 0;

    }

    local_60 = piVar22 + 2;

    *piVar22 = iVar7;

  }

LAB_1400794ff:

  *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)((ulonglong)piVar12 >> 8);

  local_60[-1] = local_60[-1] + 1;

  iVar7 = local_60[-2];

  if (iVar7 <= local_60[-1] + 1) {

    iVar7 = iVar7 * 2;

    piVar22 = local_60 + -2;

    if (local_60 == (int *)0x0) {

      piVar22 = piVar26;

    }

    piVar22 = (int *)_realloc_base(piVar22,(longlong)iVar7 + 9);

    if (piVar22 != (int *)0x0) {

      local_60 = piVar22 + 2;

      *piVar22 = iVar7 + 1;

    }

  }

  *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)piVar12;

  local_60[-1] = local_60[-1] + 1;

  iVar7 = local_60[-2];

  if (iVar7 <= local_60[-1] + 1) {

    iVar7 = iVar7 * 2;

    piVar12 = local_60 + -2;

    if (local_60 == (int *)0x0) {

      piVar12 = piVar26;

    }

    piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar7 + 9);

    if (piVar12 != (int *)0x0) {

      local_60 = piVar12 + 2;

      *piVar12 = iVar7 + 1;

    }

  }

  *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)(uVar27 >> 8);

  local_60[-1] = local_60[-1] + 1;

  iVar7 = local_60[-2];

  if (iVar7 <= local_60[-1] + 1) {

    iVar7 = iVar7 * 2;

    piVar12 = local_60 + -2;

    if (local_60 == (int *)0x0) {

      piVar12 = piVar26;

    }

    piVar12 = (int *)_realloc_base(piVar12,(longlong)iVar7 + 9);

    if (piVar12 != (int *)0x0) {

      local_60 = piVar12 + 2;

      *piVar12 = iVar7 + 1;

    }

  }

  *(char *)((longlong)local_60[-1] + (longlong)local_60) = (char)uVar27;

  local_60[-1] = local_60[-1] + 1;

  iVar7 = local_60[-1];

  *param_3 = iVar7;

  FUN_1402f8e20(local_60 + -2,local_60,(longlong)iVar7);

  return local_60 + -2;

}





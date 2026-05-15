// Address: 0x1401112f0
// Ghidra name: FUN_1401112f0
// ============ 0x1401112f0 FUN_1401112f0 (size=1624) ============


void FUN_1401112f0(ulonglong *param_1,int *param_2,int *param_3,undefined1 param_4)



{

  int *piVar1;

  undefined8 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  undefined8 uVar10;

  longlong lVar11;

  int *piVar12;

  int *piVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  int iVar18;

  int *piVar19;

  int *piVar20;

  int *piVar21;

  int *piVar22;

  bool bVar23;

  bool bVar24;

  

  piVar21 = param_2 + (((longlong)param_3 - (longlong)param_2) / 0x28 >> 1) * 10;

  lVar11 = ((longlong)param_3 + (-0x28 - (longlong)param_2)) / 0x28;

  if (lVar11 < 0x29) {

    piVar12 = param_3 + -10;

    piVar13 = param_2;

  }

  else {

    lVar11 = lVar11 + 1 >> 3;

    FUN_140110ef0(param_2,param_2 + lVar11 * 10,param_2 + lVar11 * 0x14,param_4);

    FUN_140110ef0(piVar21 + lVar11 * -10,piVar21,piVar21 + lVar11 * 10,param_4);

    piVar12 = param_3 + lVar11 * -10 + -10;

    FUN_140110ef0(param_3 + lVar11 * -0x14 + -10,piVar12,param_3 + -10,param_4);

    piVar13 = param_2 + lVar11 * 10;

  }

  FUN_140110ef0(piVar13,piVar21,piVar12,param_4);

  piVar12 = piVar21 + 10;

  if (param_2 < piVar21) {

    while( true ) {

      iVar3 = piVar21[5];

      iVar4 = piVar21[-5];

      bVar24 = SBORROW4(iVar4,iVar3);

      bVar23 = iVar4 - iVar3 < 0;

      if (iVar4 == iVar3) {

        iVar5 = piVar21[1];

        iVar16 = piVar21[-9];

        iVar17 = -iVar5;

        if (-iVar5 < 0) {

          iVar17 = iVar5;

        }

        iVar14 = -iVar16;

        if (-iVar16 < 0) {

          iVar14 = iVar16;

        }

        bVar24 = SBORROW4(iVar14,iVar17);

        bVar23 = iVar14 - iVar17 < 0;

        if (iVar14 == iVar17) {

          iVar17 = piVar21[2];

          iVar14 = piVar21[-8];

          iVar18 = -iVar17;

          if (-iVar17 < 0) {

            iVar18 = iVar17;

          }

          iVar15 = -iVar14;

          if (-iVar14 < 0) {

            iVar15 = iVar14;

          }

          bVar24 = SBORROW4(iVar15,iVar18);

          bVar23 = iVar15 - iVar18 < 0;

          if (iVar15 == iVar18) {

            bVar24 = SBORROW4(iVar16,iVar5);

            bVar23 = iVar16 - iVar5 < 0;

            if (iVar16 == iVar5) {

              bVar24 = SBORROW4(iVar14,iVar17);

              bVar23 = iVar14 - iVar17 < 0;

            }

          }

        }

      }

      if (bVar24 != bVar23) break;

      bVar24 = SBORROW4(iVar3,iVar4);

      bVar23 = iVar3 - iVar4 < 0;

      if (iVar3 == iVar4) {

        iVar3 = piVar21[-9];

        iVar4 = piVar21[1];

        iVar5 = -iVar3;

        if (-iVar3 < 0) {

          iVar5 = iVar3;

        }

        iVar16 = -iVar4;

        if (-iVar4 < 0) {

          iVar16 = iVar4;

        }

        bVar24 = SBORROW4(iVar16,iVar5);

        bVar23 = iVar16 - iVar5 < 0;

        if (iVar16 == iVar5) {

          iVar5 = piVar21[-8];

          iVar16 = piVar21[2];

          iVar17 = -iVar5;

          if (-iVar5 < 0) {

            iVar17 = iVar5;

          }

          iVar14 = -iVar16;

          if (-iVar16 < 0) {

            iVar14 = iVar16;

          }

          bVar24 = SBORROW4(iVar14,iVar17);

          bVar23 = iVar14 - iVar17 < 0;

          if (iVar14 == iVar17) {

            bVar24 = SBORROW4(iVar4,iVar3);

            bVar23 = iVar4 - iVar3 < 0;

            if (iVar4 == iVar3) {

              bVar24 = SBORROW4(iVar16,iVar5);

              bVar23 = iVar16 - iVar5 < 0;

            }

          }

        }

      }

      if ((bVar24 != bVar23) || (piVar21 = piVar21 + -10, piVar21 <= param_2)) break;

    }

  }

  piVar13 = piVar12;

  piVar19 = piVar21;

  if (piVar12 < param_3) {

    iVar3 = piVar21[5];

    while( true ) {

      iVar4 = piVar12[5];

      bVar24 = SBORROW4(iVar4,iVar3);

      bVar23 = iVar4 - iVar3 < 0;

      if (iVar4 == iVar3) {

        iVar5 = piVar21[1];

        iVar16 = piVar12[1];

        iVar17 = -iVar5;

        if (-iVar5 < 0) {

          iVar17 = iVar5;

        }

        iVar14 = -iVar16;

        if (-iVar16 < 0) {

          iVar14 = iVar16;

        }

        bVar24 = SBORROW4(iVar14,iVar17);

        bVar23 = iVar14 - iVar17 < 0;

        if (iVar14 == iVar17) {

          iVar17 = piVar21[2];

          iVar14 = piVar12[2];

          iVar18 = -iVar17;

          if (-iVar17 < 0) {

            iVar18 = iVar17;

          }

          iVar15 = -iVar14;

          if (-iVar14 < 0) {

            iVar15 = iVar14;

          }

          bVar24 = SBORROW4(iVar15,iVar18);

          bVar23 = iVar15 - iVar18 < 0;

          if (iVar15 == iVar18) {

            bVar24 = SBORROW4(iVar16,iVar5);

            bVar23 = iVar16 - iVar5 < 0;

            if (iVar16 == iVar5) {

              bVar24 = SBORROW4(iVar14,iVar17);

              bVar23 = iVar14 - iVar17 < 0;

            }

          }

        }

      }

      piVar13 = piVar12;

      if (bVar24 != bVar23) break;

      bVar24 = SBORROW4(iVar3,iVar4);

      bVar23 = iVar3 - iVar4 < 0;

      if (iVar3 == iVar4) {

        iVar4 = piVar12[1];

        iVar5 = piVar21[1];

        iVar16 = -iVar4;

        if (-iVar4 < 0) {

          iVar16 = iVar4;

        }

        iVar17 = -iVar5;

        if (-iVar5 < 0) {

          iVar17 = iVar5;

        }

        bVar24 = SBORROW4(iVar17,iVar16);

        bVar23 = iVar17 - iVar16 < 0;

        if (iVar17 == iVar16) {

          iVar16 = piVar12[2];

          iVar17 = piVar21[2];

          iVar14 = -iVar16;

          if (-iVar16 < 0) {

            iVar14 = iVar16;

          }

          iVar18 = -iVar17;

          if (-iVar17 < 0) {

            iVar18 = iVar17;

          }

          bVar24 = SBORROW4(iVar18,iVar14);

          bVar23 = iVar18 - iVar14 < 0;

          if (iVar18 == iVar14) {

            bVar24 = SBORROW4(iVar5,iVar4);

            bVar23 = iVar5 - iVar4 < 0;

            if (iVar5 == iVar4) {

              bVar24 = SBORROW4(iVar17,iVar16);

              bVar23 = iVar17 - iVar16 < 0;

            }

          }

        }

      }

      if ((bVar24 != bVar23) || (piVar12 = piVar12 + 10, piVar13 = piVar12, param_3 <= piVar12))

      break;

    }

  }

joined_r0x000140111599:

  do {

    if (param_3 <= piVar12) {

LAB_1401116b7:

      if (param_2 < piVar19) {

        piVar22 = piVar19 + -9;

        piVar20 = piVar21;

        do {

          iVar3 = piVar20[5];

          iVar4 = piVar22[4];

          bVar24 = SBORROW4(iVar4,iVar3);

          bVar23 = iVar4 - iVar3 < 0;

          if (iVar4 == iVar3) {

            iVar5 = piVar20[1];

            iVar16 = *piVar22;

            iVar17 = -iVar5;

            if (-iVar5 < 0) {

              iVar17 = iVar5;

            }

            iVar14 = -iVar16;

            if (-iVar16 < 0) {

              iVar14 = iVar16;

            }

            bVar24 = SBORROW4(iVar14,iVar17);

            bVar23 = iVar14 - iVar17 < 0;

            if (iVar14 == iVar17) {

              iVar17 = piVar20[2];

              iVar14 = piVar22[1];

              iVar18 = -iVar17;

              if (-iVar17 < 0) {

                iVar18 = iVar17;

              }

              iVar15 = -iVar14;

              if (-iVar14 < 0) {

                iVar15 = iVar14;

              }

              bVar24 = SBORROW4(iVar15,iVar18);

              bVar23 = iVar15 - iVar18 < 0;

              if (iVar15 == iVar18) {

                bVar24 = SBORROW4(iVar16,iVar5);

                bVar23 = iVar16 - iVar5 < 0;

                if (iVar16 == iVar5) {

                  bVar24 = SBORROW4(iVar14,iVar17);

                  bVar23 = iVar14 - iVar17 < 0;

                }

              }

            }

          }

          piVar21 = piVar20;

          if (bVar24 == bVar23) {

            bVar24 = SBORROW4(iVar3,iVar4);

            bVar23 = iVar3 - iVar4 < 0;

            if (iVar3 == iVar4) {

              iVar3 = piVar20[1];

              iVar4 = *piVar22;

              iVar5 = -iVar4;

              if (-iVar4 < 0) {

                iVar5 = iVar4;

              }

              iVar16 = -iVar3;

              if (-iVar3 < 0) {

                iVar16 = iVar3;

              }

              bVar24 = SBORROW4(iVar16,iVar5);

              bVar23 = iVar16 - iVar5 < 0;

              if (iVar16 == iVar5) {

                iVar5 = piVar22[1];

                iVar16 = piVar20[2];

                iVar17 = -iVar5;

                if (-iVar5 < 0) {

                  iVar17 = iVar5;

                }

                iVar14 = -iVar16;

                if (-iVar16 < 0) {

                  iVar14 = iVar16;

                }

                bVar24 = SBORROW4(iVar14,iVar17);

                bVar23 = iVar14 - iVar17 < 0;

                if (iVar14 == iVar17) {

                  bVar24 = SBORROW4(iVar3,iVar4);

                  bVar23 = iVar3 - iVar4 < 0;

                  if (iVar3 == iVar4) {

                    bVar24 = SBORROW4(iVar16,iVar5);

                    bVar23 = iVar16 - iVar5 < 0;

                  }

                }

              }

            }

            if (bVar24 != bVar23) break;

            piVar21 = piVar20 + -10;

            piVar1 = piVar22 + -1;

            if (piVar21 != piVar1) {

              uVar6 = *(undefined8 *)(piVar22 + 1);

              uVar7 = *(undefined8 *)piVar21;

              uVar8 = *(undefined8 *)(piVar20 + -8);

              uVar9 = *(undefined8 *)(piVar20 + -6);

              uVar10 = *(undefined8 *)(piVar20 + -4);

              uVar2 = *(undefined8 *)(piVar20 + -2);

              *(undefined8 *)piVar21 = *(undefined8 *)piVar1;

              *(undefined8 *)(piVar20 + -8) = uVar6;

              uVar6 = *(undefined8 *)(piVar22 + 5);

              *(undefined8 *)(piVar20 + -6) = *(undefined8 *)(piVar22 + 3);

              *(undefined8 *)(piVar20 + -4) = uVar6;

              *(undefined8 *)(piVar20 + -2) = *(undefined8 *)(piVar22 + 7);

              *(undefined8 *)piVar1 = uVar7;

              *(undefined8 *)(piVar22 + 1) = uVar8;

              *(undefined8 *)(piVar22 + 3) = uVar9;

              *(undefined8 *)(piVar22 + 5) = uVar10;

              *(undefined8 *)(piVar22 + 7) = uVar2;

            }

          }

          piVar19 = piVar19 + -10;

          piVar22 = piVar22 + -10;

          piVar20 = piVar21;

        } while (param_2 < piVar19);

      }

      if (piVar19 == param_2) {

        if (piVar12 == param_3) {

          *param_1 = (ulonglong)piVar21;

          param_1[1] = (ulonglong)piVar13;

          return;

        }

        if (piVar13 != piVar12) {

          uVar6 = *(undefined8 *)(piVar13 + 2);

          uVar7 = *(undefined8 *)piVar21;

          uVar8 = *(undefined8 *)(piVar21 + 2);

          uVar9 = *(undefined8 *)(piVar21 + 4);

          uVar10 = *(undefined8 *)(piVar21 + 6);

          uVar2 = *(undefined8 *)(piVar21 + 8);

          *(undefined8 *)piVar21 = *(undefined8 *)piVar13;

          *(undefined8 *)(piVar21 + 2) = uVar6;

          uVar6 = *(undefined8 *)(piVar13 + 6);

          *(undefined8 *)(piVar21 + 4) = *(undefined8 *)(piVar13 + 4);

          *(undefined8 *)(piVar21 + 6) = uVar6;

          *(undefined8 *)(piVar21 + 8) = *(undefined8 *)(piVar13 + 8);

          *(undefined8 *)piVar13 = uVar7;

          *(undefined8 *)(piVar13 + 2) = uVar8;

          *(undefined8 *)(piVar13 + 4) = uVar9;

          *(undefined8 *)(piVar13 + 6) = uVar10;

          *(undefined8 *)(piVar13 + 8) = uVar2;

        }

        uVar6 = *(undefined8 *)(piVar12 + 2);

        uVar7 = *(undefined8 *)piVar21;

        uVar8 = *(undefined8 *)(piVar21 + 2);

        uVar9 = *(undefined8 *)(piVar21 + 4);

        uVar10 = *(undefined8 *)(piVar21 + 6);

        uVar2 = *(undefined8 *)(piVar21 + 8);

        *(undefined8 *)piVar21 = *(undefined8 *)piVar12;

        *(undefined8 *)(piVar21 + 2) = uVar6;

        uVar6 = *(undefined8 *)(piVar12 + 6);

        *(undefined8 *)(piVar21 + 4) = *(undefined8 *)(piVar12 + 4);

        *(undefined8 *)(piVar21 + 6) = uVar6;

        *(undefined8 *)(piVar21 + 8) = *(undefined8 *)(piVar12 + 8);

        *(undefined8 *)piVar12 = uVar7;

        *(undefined8 *)(piVar12 + 2) = uVar8;

        *(undefined8 *)(piVar12 + 4) = uVar9;

        *(undefined8 *)(piVar12 + 6) = uVar10;

        *(undefined8 *)(piVar12 + 8) = uVar2;

        piVar12 = piVar12 + 10;

        piVar13 = piVar13 + 10;

        piVar21 = piVar21 + 10;

      }

      else {

        piVar22 = piVar19 + -10;

        if (piVar12 == param_3) {

          piVar20 = piVar21 + -10;

          if (piVar22 != piVar20) {

            uVar6 = *(undefined8 *)(piVar21 + -8);

            uVar7 = *(undefined8 *)piVar22;

            uVar8 = *(undefined8 *)(piVar19 + -8);

            uVar9 = *(undefined8 *)(piVar19 + -6);

            uVar10 = *(undefined8 *)(piVar19 + -4);

            uVar2 = *(undefined8 *)(piVar19 + -2);

            *(undefined8 *)piVar22 = *(undefined8 *)piVar20;

            *(undefined8 *)(piVar19 + -8) = uVar6;

            uVar6 = *(undefined8 *)(piVar21 + -4);

            *(undefined8 *)(piVar19 + -6) = *(undefined8 *)(piVar21 + -6);

            *(undefined8 *)(piVar19 + -4) = uVar6;

            *(undefined8 *)(piVar19 + -2) = *(undefined8 *)(piVar21 + -2);

            *(undefined8 *)piVar20 = uVar7;

            *(undefined8 *)(piVar21 + -8) = uVar8;

            *(undefined8 *)(piVar21 + -6) = uVar9;

            *(undefined8 *)(piVar21 + -4) = uVar10;

            *(undefined8 *)(piVar21 + -2) = uVar2;

          }

          uVar6 = *(undefined8 *)(piVar13 + -8);

          uVar7 = *(undefined8 *)piVar20;

          uVar8 = *(undefined8 *)(piVar21 + -8);

          uVar9 = *(undefined8 *)(piVar21 + -6);

          uVar10 = *(undefined8 *)(piVar21 + -4);

          uVar2 = *(undefined8 *)(piVar21 + -2);

          *(undefined8 *)piVar20 = *(undefined8 *)(piVar13 + -10);

          *(undefined8 *)(piVar21 + -8) = uVar6;

          uVar6 = *(undefined8 *)(piVar13 + -4);

          *(undefined8 *)(piVar21 + -6) = *(undefined8 *)(piVar13 + -6);

          *(undefined8 *)(piVar21 + -4) = uVar6;

          *(undefined8 *)(piVar21 + -2) = *(undefined8 *)(piVar13 + -2);

          *(undefined8 *)(piVar13 + -10) = uVar7;

          *(undefined8 *)(piVar13 + -8) = uVar8;

          *(undefined8 *)(piVar13 + -6) = uVar9;

          *(undefined8 *)(piVar13 + -4) = uVar10;

          *(undefined8 *)(piVar13 + -2) = uVar2;

          piVar13 = piVar13 + -10;

          piVar21 = piVar20;

          piVar19 = piVar22;

        }

        else {

          uVar6 = *(undefined8 *)(piVar19 + -8);

          uVar7 = *(undefined8 *)piVar12;

          uVar8 = *(undefined8 *)(piVar12 + 2);

          uVar9 = *(undefined8 *)(piVar12 + 4);

          uVar10 = *(undefined8 *)(piVar12 + 6);

          uVar2 = *(undefined8 *)(piVar12 + 8);

          *(undefined8 *)piVar12 = *(undefined8 *)piVar22;

          *(undefined8 *)(piVar12 + 2) = uVar6;

          uVar6 = *(undefined8 *)(piVar19 + -4);

          *(undefined8 *)(piVar12 + 4) = *(undefined8 *)(piVar19 + -6);

          *(undefined8 *)(piVar12 + 6) = uVar6;

          *(undefined8 *)(piVar12 + 8) = *(undefined8 *)(piVar19 + -2);

          piVar12 = piVar12 + 10;

          *(undefined8 *)piVar22 = uVar7;

          *(undefined8 *)(piVar19 + -8) = uVar8;

          *(undefined8 *)(piVar19 + -6) = uVar9;

          *(undefined8 *)(piVar19 + -4) = uVar10;

          *(undefined8 *)(piVar19 + -2) = uVar2;

          piVar19 = piVar22;

        }

      }

      goto joined_r0x000140111599;

    }

    iVar3 = piVar12[5];

    iVar4 = piVar21[5];

    bVar24 = SBORROW4(iVar4,iVar3);

    bVar23 = iVar4 - iVar3 < 0;

    if (iVar4 == iVar3) {

      iVar5 = piVar12[1];

      iVar16 = piVar21[1];

      iVar17 = -iVar5;

      if (-iVar5 < 0) {

        iVar17 = iVar5;

      }

      iVar14 = -iVar16;

      if (-iVar16 < 0) {

        iVar14 = iVar16;

      }

      bVar24 = SBORROW4(iVar14,iVar17);

      bVar23 = iVar14 - iVar17 < 0;

      if (iVar14 == iVar17) {

        iVar17 = piVar12[2];

        iVar14 = piVar21[2];

        iVar18 = -iVar17;

        if (-iVar17 < 0) {

          iVar18 = iVar17;

        }

        iVar15 = -iVar14;

        if (-iVar14 < 0) {

          iVar15 = iVar14;

        }

        bVar24 = SBORROW4(iVar15,iVar18);

        bVar23 = iVar15 - iVar18 < 0;

        if (iVar15 == iVar18) {

          bVar24 = SBORROW4(iVar16,iVar5);

          bVar23 = iVar16 - iVar5 < 0;

          if (iVar16 == iVar5) {

            bVar24 = SBORROW4(iVar14,iVar17);

            bVar23 = iVar14 - iVar17 < 0;

          }

        }

      }

    }

    if (bVar24 == bVar23) {

      bVar24 = SBORROW4(iVar3,iVar4);

      bVar23 = iVar3 - iVar4 < 0;

      if (iVar3 == iVar4) {

        iVar3 = piVar21[1];

        iVar4 = piVar12[1];

        iVar5 = -iVar3;

        if (-iVar3 < 0) {

          iVar5 = iVar3;

        }

        iVar16 = -iVar4;

        if (-iVar4 < 0) {

          iVar16 = iVar4;

        }

        bVar24 = SBORROW4(iVar16,iVar5);

        bVar23 = iVar16 - iVar5 < 0;

        if (iVar16 == iVar5) {

          iVar5 = piVar21[2];

          iVar16 = piVar12[2];

          iVar17 = -iVar5;

          if (-iVar5 < 0) {

            iVar17 = iVar5;

          }

          iVar14 = -iVar16;

          if (-iVar16 < 0) {

            iVar14 = iVar16;

          }

          bVar24 = SBORROW4(iVar14,iVar17);

          bVar23 = iVar14 - iVar17 < 0;

          if (iVar14 == iVar17) {

            bVar24 = SBORROW4(iVar4,iVar3);

            bVar23 = iVar4 - iVar3 < 0;

            if (iVar4 == iVar3) {

              bVar24 = SBORROW4(iVar16,iVar5);

              bVar23 = iVar16 - iVar5 < 0;

            }

          }

        }

      }

      if (bVar24 != bVar23) goto LAB_1401116b7;

      if (piVar13 != piVar12) {

        uVar6 = *(undefined8 *)(piVar12 + 2);

        uVar7 = *(undefined8 *)piVar13;

        uVar8 = *(undefined8 *)(piVar13 + 2);

        uVar9 = *(undefined8 *)(piVar13 + 4);

        uVar10 = *(undefined8 *)(piVar13 + 6);

        uVar2 = *(undefined8 *)(piVar13 + 8);

        *(undefined8 *)piVar13 = *(undefined8 *)piVar12;

        *(undefined8 *)(piVar13 + 2) = uVar6;

        uVar6 = *(undefined8 *)(piVar12 + 6);

        *(undefined8 *)(piVar13 + 4) = *(undefined8 *)(piVar12 + 4);

        *(undefined8 *)(piVar13 + 6) = uVar6;

        *(undefined8 *)(piVar13 + 8) = *(undefined8 *)(piVar12 + 8);

        *(undefined8 *)piVar12 = uVar7;

        *(undefined8 *)(piVar12 + 2) = uVar8;

        *(undefined8 *)(piVar12 + 4) = uVar9;

        *(undefined8 *)(piVar12 + 6) = uVar10;

        *(undefined8 *)(piVar12 + 8) = uVar2;

      }

      piVar13 = piVar13 + 10;

    }

    piVar12 = piVar12 + 10;

  } while( true );

}





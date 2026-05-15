// Address: 0x140168840
// Ghidra name: FUN_140168840
// ============ 0x140168840 FUN_140168840 (size=1721) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_140168840(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4,longlong param_5

                  ,uint param_6)



{

  int iVar1;

  undefined1 uVar2;

  undefined1 uVar3;

  undefined2 uVar4;

  undefined2 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  longlong lVar8;

  ulonglong uVar9;

  undefined4 *puVar10;

  uint uVar11;

  undefined4 *puVar12;

  longlong lVar13;

  longlong lVar14;

  undefined4 *puVar15;

  undefined1 *puVar16;

  longlong lVar17;

  ulonglong uVar18;

  bool bVar19;

  undefined1 auStack_58 [32];

  ulonglong local_38 [2];

  

  puVar16 = auStack_58;

  bVar19 = false;

  uVar18 = (ulonglong)param_1;

  uVar11 = param_6 & 0xff;

  lVar17 = (longlong)param_4;

  if (0 < param_4) {

    lVar8 = 0;

    do {

      if (*(int *)(param_5 + lVar8 * 4) == -1) {

        bVar19 = true;

        break;

      }

      lVar8 = lVar8 + 1;

    } while (lVar8 < lVar17);

  }

  if (uVar11 == 8) {

    if (param_3 != param_2) {

      if (!bVar19) {

        if ((int)param_1 < 1) {

          return;

        }

        do {

          lVar8 = 0;

          if (0 < param_4) {

            do {

              *(undefined1 *)(lVar8 + (longlong)param_2) =

                   *(undefined1 *)((longlong)*(int *)(param_5 + lVar8 * 4) + (longlong)param_3);

              lVar8 = lVar8 + 1;

            } while (lVar8 < lVar17);

          }

          param_3 = (undefined4 *)((longlong)param_3 + lVar17);

          param_2 = (undefined4 *)((longlong)param_2 + lVar17);

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        return;

      }

      uVar2 = FUN_14015e760();

      if ((int)param_1 < 1) {

        return;

      }

      do {

        lVar8 = 0;

        if (0 < lVar17) {

          do {

            iVar1 = *(int *)(param_5 + lVar8 * 4);

            uVar3 = uVar2;

            if (iVar1 != -1) {

              uVar3 = *(undefined1 *)((longlong)iVar1 + (longlong)param_3);

            }

            *(undefined1 *)((longlong)param_2 + lVar8) = uVar3;

            lVar8 = lVar8 + 1;

          } while (lVar8 < lVar17);

        }

        param_3 = (undefined4 *)((longlong)param_3 + lVar17);

        param_2 = (undefined4 *)((longlong)param_2 + lVar17);

        uVar18 = uVar18 - 1;

      } while (uVar18 != 0);

      return;

    }

    local_38[0] = lVar17 * 4;

    if (local_38[0] < 0x80) {

      uVar9 = local_38[0] + 0xf;

      if (uVar9 <= local_38[0]) {

        uVar9 = 0xffffffffffffff0;

      }

      puVar10 = (undefined4 *)((longlong)local_38 + -(uVar9 & 0xfffffffffffffff0));

      puVar16 = auStack_58 + -(uVar9 & 0xfffffffffffffff0);

    }

    else {

      puVar10 = (undefined4 *)FUN_1401841f0();

      puVar16 = auStack_58;

    }

    if (puVar10 == (undefined4 *)0x0) {

      return;

    }

    if (bVar19) {

      *(undefined8 *)(puVar16 + -8) = 0x140168e0f;

      uVar2 = FUN_14015e760();

      if (0 < (int)param_1) {

        do {

          lVar8 = 0;

          if (0 < lVar17) {

            do {

              iVar1 = *(int *)(param_5 + lVar8 * 4);

              uVar3 = uVar2;

              if (iVar1 != -1) {

                uVar3 = *(undefined1 *)((longlong)iVar1 + (longlong)param_3);

              }

              *(undefined1 *)((longlong)puVar10 + lVar8) = uVar3;

              lVar8 = lVar8 + 1;

            } while (lVar8 < lVar17);

            puVar15 = param_2;

            lVar8 = lVar17;

            do {

              *(undefined1 *)puVar15 =

                   *(undefined1 *)((longlong)puVar15 + ((longlong)puVar10 - (longlong)param_2));

              puVar15 = (undefined4 *)((longlong)puVar15 + 1);

              lVar8 = lVar8 + -1;

            } while (lVar8 != 0);

          }

          param_3 = (undefined4 *)((longlong)param_3 + lVar17);

          param_2 = (undefined4 *)((longlong)param_2 + lVar17);

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

      }

    }

    else if (0 < (int)param_1) {

      do {

        lVar8 = 0;

        if (0 < lVar17) {

          do {

            *(undefined1 *)(lVar8 + (longlong)puVar10) =

                 *(undefined1 *)((longlong)*(int *)(param_5 + lVar8 * 4) + (longlong)param_3);

            lVar8 = lVar8 + 1;

          } while (lVar8 < lVar17);

          puVar15 = param_2;

          lVar8 = lVar17;

          do {

            *(undefined1 *)puVar15 =

                 *(undefined1 *)((longlong)puVar15 + ((longlong)puVar10 - (longlong)param_2));

            puVar15 = (undefined4 *)((longlong)puVar15 + 1);

            lVar8 = lVar8 + -1;

          } while (lVar8 != 0);

        }

        param_3 = (undefined4 *)((longlong)param_3 + lVar17);

        param_2 = (undefined4 *)((longlong)param_2 + lVar17);

        uVar18 = uVar18 - 1;

      } while (uVar18 != 0);

    }

    bVar19 = local_38[0] < 0x80;

  }

  else if (uVar11 == 0x10) {

    if (param_3 != param_2) {

      if (!bVar19) {

        if ((int)param_1 < 1) {

          return;

        }

        puVar10 = param_2;

        do {

          lVar8 = 0;

          if (0 < lVar17) {

            do {

              *(undefined2 *)((longlong)puVar10 + lVar8 * 2) =

                   *(undefined2 *)

                    ((longlong)puVar10 +

                    (longlong)

                    ((longlong)param_3 +

                    ((longlong)*(int *)(param_5 + lVar8 * 4) * 2 - (longlong)param_2)));

              lVar8 = lVar8 + 1;

            } while (lVar8 < lVar17);

          }

          puVar10 = (undefined4 *)((longlong)puVar10 + lVar17 * 2);

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        return;

      }

      uVar4 = FUN_14015e760(param_6);

      if ((int)param_1 < 1) {

        return;

      }

      puVar10 = param_2;

      do {

        lVar8 = 0;

        if (0 < lVar17) {

          do {

            iVar1 = *(int *)(param_5 + lVar8 * 4);

            uVar5 = uVar4;

            if (iVar1 != -1) {

              uVar5 = *(undefined2 *)

                       ((undefined1 *)

                        ((longlong)param_3 + ((longlong)iVar1 * 2 - (longlong)param_2)) +

                       (longlong)puVar10);

            }

            *(undefined2 *)((longlong)puVar10 + lVar8 * 2) = uVar5;

            lVar8 = lVar8 + 1;

          } while (lVar8 < lVar17);

        }

        puVar10 = (undefined4 *)((longlong)puVar10 + lVar17 * 2);

        uVar18 = uVar18 - 1;

      } while (uVar18 != 0);

      return;

    }

    local_38[0] = lVar17 * 4;

    if (local_38[0] < 0x80) {

      uVar9 = local_38[0] + 0xf;

      if (uVar9 <= local_38[0]) {

        uVar9 = 0xffffffffffffff0;

      }

      puVar10 = (undefined4 *)((longlong)local_38 + -(uVar9 & 0xfffffffffffffff0));

      puVar16 = auStack_58 + -(uVar9 & 0xfffffffffffffff0);

    }

    else {

      puVar10 = (undefined4 *)FUN_1401841f0();

      puVar16 = auStack_58;

    }

    if (puVar10 == (undefined4 *)0x0) {

      return;

    }

    if (bVar19) {

      *(undefined8 *)(puVar16 + -8) = 0x140168c12;

      uVar4 = FUN_14015e760(param_6);

      if (0 < (int)param_1) {

        lVar8 = (longlong)puVar10 - (longlong)param_2;

        puVar15 = param_2;

        do {

          lVar13 = 0;

          if (0 < lVar17) {

            do {

              iVar1 = *(int *)(param_5 + lVar13 * 4);

              uVar5 = uVar4;

              if (iVar1 != -1) {

                uVar5 = *(undefined2 *)

                         ((undefined1 *)

                          ((longlong)param_3 + ((longlong)iVar1 * 2 - (longlong)param_2)) +

                         (longlong)puVar15);

              }

              *(undefined2 *)((longlong)puVar10 + lVar13 * 2) = uVar5;

              lVar13 = lVar13 + 1;

              puVar12 = puVar15;

              lVar14 = lVar17;

            } while (lVar13 < lVar17);

            do {

              *(undefined2 *)puVar12 = *(undefined2 *)(lVar8 + (longlong)puVar12);

              lVar14 = lVar14 + -1;

              puVar12 = (undefined4 *)((longlong)puVar12 + 2);

            } while (lVar14 != 0);

          }

          puVar15 = (undefined4 *)((longlong)puVar15 + lVar17 * 2);

          lVar8 = lVar8 + lVar17 * -2;

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        bVar19 = local_38[0] < 0x80;

        goto LAB_140168ed5;

      }

    }

    else if (0 < (int)param_1) {

      lVar8 = (longlong)puVar10 - (longlong)param_2;

      puVar15 = param_2;

      do {

        lVar13 = 0;

        if (0 < lVar17) {

          do {

            *(undefined2 *)((longlong)puVar10 + lVar13 * 2) =

                 *(undefined2 *)

                  ((longlong)puVar15 +

                  (longlong)

                  ((longlong)param_3 +

                  ((longlong)*(int *)(param_5 + lVar13 * 4) * 2 - (longlong)param_2)));

            lVar13 = lVar13 + 1;

            puVar12 = puVar15;

            lVar14 = lVar17;

          } while (lVar13 < lVar17);

          do {

            *(undefined2 *)puVar12 = *(undefined2 *)(lVar8 + (longlong)puVar12);

            lVar14 = lVar14 + -1;

            puVar12 = (undefined4 *)((longlong)puVar12 + 2);

          } while (lVar14 != 0);

        }

        puVar15 = (undefined4 *)((longlong)puVar15 + lVar17 * 2);

        lVar8 = lVar8 + lVar17 * -2;

        uVar18 = uVar18 - 1;

      } while (uVar18 != 0);

    }

    bVar19 = local_38[0] < 0x80;

  }

  else {

    if (uVar11 != 0x20) {

      return;

    }

    if (param_3 != param_2) {

      if (!bVar19) {

        if ((int)param_1 < 1) {

          return;

        }

        param_5 = param_5 - (longlong)param_2;

        puVar10 = param_2;

        do {

          puVar15 = puVar10;

          lVar8 = lVar17;

          if (0 < lVar17) {

            do {

              *puVar15 = *(undefined4 *)

                          ((longlong)puVar10 +

                          (longlong)

                          ((longlong)param_3 +

                          ((longlong)*(int *)(param_5 + (longlong)puVar15) * 4 - (longlong)param_2))

                          );

              lVar8 = lVar8 + -1;

              puVar15 = puVar15 + 1;

            } while (lVar8 != 0);

          }

          puVar10 = puVar10 + lVar17;

          param_5 = param_5 + lVar17 * -4;

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        return;

      }

      uVar6 = FUN_14015e760(param_6);

      if ((int)param_1 < 1) {

        return;

      }

      param_5 = param_5 - (longlong)param_2;

      puVar10 = param_2;

      do {

        puVar15 = puVar10;

        lVar8 = lVar17;

        if (0 < lVar17) {

          do {

            uVar7 = uVar6;

            if (*(int *)(param_5 + (longlong)puVar15) != -1) {

              uVar7 = *(undefined4 *)

                       ((undefined1 *)

                        ((longlong)param_3 +

                        ((longlong)*(int *)(param_5 + (longlong)puVar15) * 4 - (longlong)param_2)) +

                       (longlong)puVar10);

            }

            *puVar15 = uVar7;

            lVar8 = lVar8 + -1;

            puVar15 = puVar15 + 1;

          } while (lVar8 != 0);

        }

        puVar10 = puVar10 + lVar17;

        param_5 = param_5 + lVar17 * -4;

        uVar18 = uVar18 - 1;

      } while (uVar18 != 0);

      return;

    }

    local_38[0] = lVar17 * 4;

    if (local_38[0] < 0x80) {

      uVar9 = local_38[0] + 0xf;

      if (uVar9 <= local_38[0]) {

        uVar9 = 0xffffffffffffff0;

      }

      puVar16 = auStack_58 + -(uVar9 & 0xfffffffffffffff0);

      puVar10 = (undefined4 *)((longlong)local_38 + -(uVar9 & 0xfffffffffffffff0));

    }

    else {

      puVar10 = (undefined4 *)FUN_1401841f0();

    }

    if (puVar10 == (undefined4 *)0x0) {

      return;

    }

    if (bVar19) {

      *(undefined8 *)(puVar16 + -8) = 0x1401689fd;

      uVar6 = FUN_14015e760(param_6);

      uVar9 = local_38[0];

      if (0 < (int)param_1) {

        do {

          if (0 < lVar17) {

            puVar15 = puVar10;

            lVar8 = lVar17;

            do {

              iVar1 = *(int *)((param_5 - (longlong)puVar10) + (longlong)puVar15);

              uVar7 = uVar6;

              if (iVar1 != -1) {

                uVar7 = param_3[iVar1];

              }

              *puVar15 = uVar7;

              puVar15 = puVar15 + 1;

              lVar8 = lVar8 + -1;

            } while (lVar8 != 0);

            puVar15 = param_2;

            lVar8 = lVar17;

            do {

              *puVar15 = *(undefined4 *)

                          (((longlong)puVar10 - (longlong)param_2) + (longlong)puVar15);

              puVar15 = puVar15 + 1;

              lVar8 = lVar8 + -1;

            } while (lVar8 != 0);

          }

          param_3 = param_3 + lVar17;

          param_2 = param_2 + lVar17;

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        bVar19 = (ulonglong)(lVar17 * 4) < 0x80;

        goto LAB_140168ed5;

      }

    }

    else {

      uVar9 = lVar17 * 4;

      if (0 < (int)param_1) {

        do {

          if (0 < lVar17) {

            puVar15 = puVar10;

            lVar8 = lVar17;

            do {

              *puVar15 = param_3[*(int *)((param_5 - (longlong)puVar10) + (longlong)puVar15)];

              lVar8 = lVar8 + -1;

              puVar15 = puVar15 + 1;

            } while (lVar8 != 0);

            puVar15 = param_2;

            lVar8 = lVar17;

            do {

              *puVar15 = *(undefined4 *)

                          (((longlong)puVar10 - (longlong)param_2) + (longlong)puVar15);

              puVar15 = puVar15 + 1;

              lVar8 = lVar8 + -1;

            } while (lVar8 != 0);

          }

          param_3 = param_3 + lVar17;

          param_2 = param_2 + lVar17;

          uVar18 = uVar18 - 1;

        } while (uVar18 != 0);

        bVar19 = (ulonglong)(lVar17 * 4) < 0x80;

        goto LAB_140168ed5;

      }

    }

    bVar19 = uVar9 < 0x80;

  }

LAB_140168ed5:

  if (!bVar19) {

    *(undefined8 *)(puVar16 + -8) = 0x140168edf;

    FUN_1401841e0(puVar10);

  }

  return;

}





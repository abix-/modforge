// Address: 0x1401f9010
// Ghidra name: FUN_1401f9010
// ============ 0x1401f9010 FUN_1401f9010 (size=2240) ============


void FUN_1401f9010(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  uint uVar4;

  longlong lVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  if ((param_1 != 0) && (lVar1 = *(longlong *)(param_1 + 0x2e0), lVar1 != 0)) {

    for (lVar5 = *(longlong *)(param_1 + 0x1e8); lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x148)) {

      FUN_1401f9a50(param_1,lVar5);

    }

    uVar7 = 0;

    if (*(longlong *)(lVar1 + 0x28d0) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x28d0) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28d8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x28d8) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28e8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x28e8) = 0;

    }

    if (*(longlong *)(lVar1 + 0x6e0) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x6e0) = 0;

      *(undefined4 *)(lVar1 + 0x2874) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2898) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x2898) = 0;

    }

    if (*(longlong *)(lVar1 + 0x678) != 0) {

      (*DAT_1403fd028)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x678),0);

      *(undefined8 *)(lVar1 + 0x678) = 0;

    }

    if (*(longlong *)(lVar1 + 0x6a0) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          lVar5 = *(longlong *)(uVar3 * 8 + *(longlong *)(lVar1 + 0x6a0));

          if (lVar5 != 0) {

            (*DAT_1403fcfd8)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

            *(undefined8 *)(uVar3 * 8 + *(longlong *)(lVar1 + 0x6a0)) = 0;

          }

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x6a0));

      *(undefined8 *)(lVar1 + 0x6a0) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28a0) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          lVar5 = *(longlong *)(*(longlong *)(lVar1 + 0x28a0) + uVar3 * 8);

          if (lVar5 != 0) {

            (*DAT_1403fcff0)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

          }

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x28a0));

      *(undefined8 *)(lVar1 + 0x28a0) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28a8) != 0) {

      FUN_1401841e0();

      *(undefined8 *)(lVar1 + 0x28a8) = 0;

    }

    if (*(longlong *)(lVar1 + 0x6f8) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          lVar5 = *(longlong *)(*(longlong *)(lVar1 + 0x6f8) + uVar3 * 8);

          if (lVar5 != 0) {

            (*DAT_1403fcfe0)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

          }

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x6f8));

      *(undefined8 *)(lVar1 + 0x6f8) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2800) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2800),0);

      *(undefined8 *)(lVar1 + 0x2800) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2808) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2808),0);

      *(undefined8 *)(lVar1 + 0x2808) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2810) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2810),0);

      *(undefined8 *)(lVar1 + 0x2810) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2818) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2818),0);

      *(undefined8 *)(lVar1 + 0x2818) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2820) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2820),0);

      *(undefined8 *)(lVar1 + 0x2820) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2828) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2828),0);

      *(undefined8 *)(lVar1 + 0x2828) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2830) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2830),0);

      *(undefined8 *)(lVar1 + 0x2830) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2838) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x2838),0);

      *(undefined8 *)(lVar1 + 0x2838) = 0;

    }

    lVar5 = lVar1 + 0x758;

    lVar2 = 0x100;

    do {

      FUN_1401f98d0(lVar1,lVar5);

      lVar5 = lVar5 + 0x20;

      lVar2 = lVar2 + -1;

    } while (lVar2 != 0);

    FUN_1402f94c0(lVar1 + 0x758,0,0x2000);

    if (*(longlong *)(lVar1 + 0x700) != 0) {

      (*DAT_1403fd008)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x700),0);

      *(undefined8 *)(lVar1 + 0x700) = 0;

    }

    if (*(longlong *)(lVar1 + 0x708) != 0) {

      (*DAT_1403fd008)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x708),0);

      *(undefined8 *)(lVar1 + 0x708) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28b0) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          lVar5 = *(longlong *)(*(longlong *)(lVar1 + 0x28b0) + uVar3 * 8);

          if (lVar5 != 0) {

            (*DAT_1403fd018)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

          }

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x28b0));

      *(undefined8 *)(lVar1 + 0x28b0) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28b8) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          lVar5 = *(longlong *)(*(longlong *)(lVar1 + 0x28b8) + uVar3 * 8);

          if (lVar5 != 0) {

            (*DAT_1403fd018)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

          }

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x28b8));

      *(undefined8 *)(lVar1 + 0x28b8) = 0;

    }

    if (*(longlong *)(lVar1 + 0x688) != 0) {

      (*DAT_1403fd040)(*(undefined8 *)(lVar1 + 0x660),*(undefined8 *)(lVar1 + 0x680),

                       *(undefined4 *)(lVar1 + 0x2894));

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x688));

      *(undefined8 *)(lVar1 + 0x688) = 0;

      *(undefined8 *)(lVar1 + 0x698) = 0;

      *(undefined4 *)(lVar1 + 0x690) = 0;

    }

    if (*(longlong *)(lVar1 + 0x680) != 0) {

      (*DAT_1403fcfb8)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x680),0);

      *(undefined8 *)(lVar1 + 0x680) = 0;

    }

    if (*(longlong *)(lVar1 + 0x2840) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          uVar6 = uVar7;

          if (*(int *)(*(longlong *)(lVar1 + 0x2848) + uVar3 * 4) != 0) {

            do {

              lVar5 = *(longlong *)

                       (*(longlong *)(*(longlong *)(lVar1 + 0x2840) + uVar3 * 8) + uVar6 * 8);

              if (lVar5 != 0) {

                (*DAT_1403fcfc8)(*(undefined8 *)(lVar1 + 0x660),lVar5,0);

              }

              uVar4 = (int)uVar6 + 1;

              uVar6 = (ulonglong)uVar4;

            } while (uVar4 < *(uint *)(*(longlong *)(lVar1 + 0x2848) + uVar3 * 4));

          }

          FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar1 + 0x2840) + uVar3 * 8));

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x2840));

      *(undefined8 *)(lVar1 + 0x2840) = 0;

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x2848));

      *(undefined8 *)(lVar1 + 0x2848) = 0;

    }

    if (*(longlong *)(lVar1 + 0x718) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x718),0);

      *(undefined8 *)(lVar1 + 0x718) = 0;

    }

    if (*(longlong *)(lVar1 + 0x730) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x730),0);

      *(undefined8 *)(lVar1 + 0x730) = 0;

    }

    if (*(longlong *)(lVar1 + 0x720) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x720),0);

      *(undefined8 *)(lVar1 + 0x720) = 0;

    }

    if (*(longlong *)(lVar1 + 0x738) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x738),0);

      *(undefined8 *)(lVar1 + 0x738) = 0;

    }

    if (*(longlong *)(lVar1 + 0x728) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x728),0);

      *(undefined8 *)(lVar1 + 0x728) = 0;

    }

    if (*(longlong *)(lVar1 + 0x740) != 0) {

      (*DAT_1403fd020)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x740),0);

      *(undefined8 *)(lVar1 + 0x740) = 0;

    }

    if (*(longlong *)(lVar1 + 0x748) != 0) {

      (*DAT_1403fcfd0)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x748),0);

      *(undefined8 *)(lVar1 + 0x748) = 0;

    }

    if (*(longlong *)(lVar1 + 0x750) != 0) {

      (*DAT_1403fd000)(*(undefined8 *)(lVar1 + 0x660),*(longlong *)(lVar1 + 0x750),0);

      *(undefined8 *)(lVar1 + 0x750) = 0;

    }

    uVar3 = uVar7;

    uVar6 = uVar7;

    if (0 < *(int *)(lVar1 + 0x2858)) {

      do {

        (*DAT_1403fcff8)(*(undefined8 *)(lVar1 + 0x660),

                         *(undefined8 *)(*(longlong *)(lVar1 + 0x2860) + 0x50 + uVar3),0);

        uVar4 = (int)uVar6 + 1;

        uVar3 = uVar3 + 0x58;

        uVar6 = (ulonglong)uVar4;

      } while ((int)uVar4 < *(int *)(lVar1 + 0x2858));

    }

    FUN_1401841e0(*(undefined8 *)(lVar1 + 0x2860));

    *(undefined8 *)(lVar1 + 0x2860) = 0;

    *(undefined4 *)(lVar1 + 0x2858) = 0;

    if (*(longlong *)(lVar1 + 0x27e0) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          uVar6 = uVar7;

          if (0 < *(int *)(*(longlong *)(lVar1 + 0x27e0) + uVar3 * 4)) {

            do {

              FUN_1401f98d0(lVar1,(longlong)(int)uVar6 * 0x20 +

                                  *(longlong *)(*(longlong *)(lVar1 + 0x27d8) + uVar3 * 8));

              uVar4 = (int)uVar6 + 1;

              uVar6 = (ulonglong)uVar4;

            } while ((int)uVar4 < *(int *)(*(longlong *)(lVar1 + 0x27e0) + uVar3 * 4));

          }

          FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar1 + 0x27d8) + uVar3 * 8));

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x27d8));

      *(undefined8 *)(lVar1 + 0x27d8) = 0;

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x27e0));

      *(undefined8 *)(lVar1 + 0x27e0) = 0;

    }

    if (*(longlong *)(lVar1 + 0x27e8) != 0) {

      uVar3 = uVar7;

      if (*(int *)(lVar1 + 0x2894) != 0) {

        do {

          uVar6 = uVar7;

          if (*(int *)(*(longlong *)(lVar1 + 0x27f0) + uVar3 * 4) != 0) {

            do {

              FUN_1401f98d0(lVar1,uVar6 * 0x20 +

                                  *(longlong *)(*(longlong *)(lVar1 + 0x27e8) + uVar3 * 8));

              uVar4 = (int)uVar6 + 1;

              uVar6 = (ulonglong)uVar4;

            } while (uVar4 < *(uint *)(*(longlong *)(lVar1 + 0x27f0) + uVar3 * 4));

          }

          FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar1 + 0x27e8) + uVar3 * 8));

          uVar4 = (int)uVar3 + 1;

          uVar3 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + 0x2894));

      }

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x27e8));

      *(undefined8 *)(lVar1 + 0x27e8) = 0;

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x27f0));

      *(undefined8 *)(lVar1 + 0x27f0) = 0;

    }

    if ((*(longlong *)(lVar1 + 0x660) != 0) && (*(char *)(lVar1 + 0x668) == '\0')) {

      (*DAT_1403fcfc0)(*(longlong *)(lVar1 + 0x660),0);

      *(undefined8 *)(lVar1 + 0x660) = 0;

    }

    if ((*(longlong *)(lVar1 + 0x18) != 0) && (*(char *)(lVar1 + 0x20) == '\0')) {

      (*DAT_1403fd0f0)(*(undefined8 *)(lVar1 + 8),*(longlong *)(lVar1 + 0x18),0);

      *(undefined8 *)(lVar1 + 0x18) = 0;

    }

    if ((*(longlong *)(lVar1 + 8) != 0) && (*(char *)(lVar1 + 0x10) == '\0')) {

      (*DAT_1403fd0e8)(*(longlong *)(lVar1 + 8),0);

      *(undefined8 *)(lVar1 + 8) = 0;

    }

  }

  return;

}





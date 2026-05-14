// Address: 0x140184d90
// Ghidra name: FUN_140184d90
// ============ 0x140184d90 FUN_140184d90 (size=1075) ============


undefined8 FUN_140184d90(uint *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint *puVar9;

  uint *puVar10;

  ulonglong uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint *puVar15;

  uint *puVar16;

  uint uVar17;

  ulonglong uVar18;

  uint uVar19;

  uint uVar20;

  

  uVar20 = 0;

  uVar19 = 0;

  if (param_1 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

    return 0;

  }

  puVar9 = param_1;

  puVar10 = param_2;

  puVar15 = param_4;

  puVar16 = param_3;

  cVar4 = FUN_140185e20();

  if (cVar4 != '\0') {

    FUN_14012e850("Potential rect math overflow");

    return 0;

  }

  if (param_2 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d58);

    return 0;

  }

  if (puVar16 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d5c);

    return 0;

  }

  if (puVar15 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d60);

    return 0;

  }

  if (param_5 == (uint *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140338d64);

    return 0;

  }

  if ((int)puVar9[2] < 1) {

    return 0;

  }

  if ((int)puVar9[3] < 1) {

    return 0;

  }

  uVar13 = *puVar10;

  uVar1 = *param_1;

  uVar2 = param_1[1];

  uVar5 = (puVar9[2] - 1) + uVar1;

  uVar14 = *puVar16;

  uVar8 = (puVar9[3] - 1) + uVar2;

  uVar6 = *puVar15;

  uVar18 = (ulonglong)uVar6;

  uVar12 = *param_5;

  if ((int)uVar13 < (int)uVar1) {

    if ((int)uVar6 < (int)uVar1) {

      return 0;

    }

    if ((int)uVar5 < (int)uVar13) {

LAB_140184f2f:

      if ((int)uVar5 < (int)uVar6) {

        return 0;

      }

    }

LAB_140184f38:

    if ((int)uVar14 < (int)uVar2) {

LAB_140184f3d:

      if ((int)uVar12 < (int)uVar2) {

        return 0;

      }

    }

    if ((int)uVar14 <= (int)uVar8) goto LAB_140184f52;

  }

  else {

    if ((int)uVar5 < (int)uVar13) goto LAB_140184f2f;

    if (((int)uVar6 < (int)uVar1) || ((int)uVar5 < (int)uVar6)) goto LAB_140184f38;

    if ((int)uVar14 < (int)uVar2) goto LAB_140184f3d;

    if ((int)uVar14 <= (int)uVar8) {

      if (((int)uVar2 <= (int)uVar12) && ((int)uVar12 <= (int)uVar8)) {

        return 1;

      }

      goto LAB_140184f52;

    }

  }

  if ((int)uVar8 < (int)uVar12) {

    return 0;

  }

LAB_140184f52:

  if (uVar14 == uVar12) {

    if ((int)uVar13 < (int)uVar1) {

      *param_2 = uVar1;

    }

    else if ((int)uVar5 < (int)uVar13) {

      *param_2 = uVar5;

    }

    if ((int)uVar6 < (int)uVar1) {

      *puVar15 = uVar1;

      return 1;

    }

    if ((int)uVar5 < (int)uVar6) {

      *puVar15 = uVar5;

      return 1;

    }

  }

  else {

    if (uVar13 != uVar6) {

      uVar6 = FUN_140184830(param_1,uVar13,uVar14);

      uVar11 = uVar18 & 0xffffffff;

      do {

        uVar7 = FUN_140184830(param_1,uVar11,uVar12);

        while( true ) {

          uVar17 = (uint)uVar18;

          if ((uVar6 == 0) && (uVar7 == 0)) {

            *param_2 = uVar13;

            *param_3 = uVar14;

            *param_4 = uVar17;

            *param_5 = uVar12;

            return 1;

          }

          if ((uVar6 & uVar7) != 0) {

            return 0;

          }

          if (uVar6 == 0) break;

          if ((uVar6 & 2) == 0) {

            if ((uVar6 & 1) == 0) {

              if ((uVar6 & 4) == 0) {

                if ((uVar6 & 8) != 0) {

                  uVar19 = uVar14 + (int)(((longlong)(int)(uVar5 - uVar13) *

                                          (longlong)(int)(uVar12 - uVar14)) /

                                         (longlong)(int)(uVar17 - uVar13));

                  uVar20 = uVar5;

                }

              }

              else {

                uVar19 = uVar14 + (int)(((longlong)(int)(uVar1 - uVar13) *

                                        (longlong)(int)(uVar12 - uVar14)) /

                                       (longlong)(int)(uVar17 - uVar13));

                uVar20 = uVar1;

              }

            }

            else {

              uVar19 = uVar8;

              uVar20 = uVar13 + (int)(((longlong)(int)(uVar8 - uVar14) *

                                      (longlong)(int)(uVar17 - uVar13)) /

                                     (longlong)(int)(uVar12 - uVar14));

            }

          }

          else {

            uVar19 = uVar2;

            uVar20 = uVar13 + (int)(((longlong)(int)(uVar2 - uVar14) *

                                    (longlong)(int)(uVar17 - uVar13)) /

                                   (longlong)(int)(uVar12 - uVar14));

          }

          uVar6 = FUN_140184830(param_1,uVar20,uVar19);

          uVar13 = uVar20;

          uVar14 = uVar19;

        }

        if ((uVar7 & 2) == 0) {

          if ((uVar7 & 1) == 0) {

            uVar3 = uVar1;

            if (((uVar7 & 4) != 0) || (uVar3 = uVar5, (uVar7 & 8) != 0)) {

              uVar20 = uVar3;

              uVar19 = uVar14 + (int)(((longlong)(int)(uVar20 - uVar13) *

                                      (longlong)(int)(uVar12 - uVar14)) /

                                     (longlong)(int)(uVar17 - uVar13));

            }

          }

          else {

            uVar20 = uVar13 + (int)(((longlong)(int)(uVar8 - uVar14) *

                                    (longlong)(int)(uVar17 - uVar13)) /

                                   (longlong)(int)(uVar12 - uVar14));

            uVar19 = uVar8;

          }

        }

        else {

          uVar20 = uVar13 + (int)(((longlong)(int)(uVar2 - uVar14) *

                                  (longlong)(int)(uVar17 - uVar13)) /

                                 (longlong)(int)(uVar12 - uVar14));

          uVar19 = uVar2;

        }

        uVar18 = (ulonglong)uVar20;

        uVar11 = (ulonglong)uVar20;

        uVar12 = uVar19;

      } while( true );

    }

    if ((int)uVar14 < (int)uVar2) {

      *puVar16 = uVar2;

    }

    else if ((int)uVar8 < (int)uVar14) {

      *puVar16 = uVar8;

    }

    if ((int)uVar12 < (int)uVar2) {

      *param_5 = uVar2;

      return 1;

    }

    if ((int)uVar8 < (int)uVar12) {

      *param_5 = uVar8;

    }

  }

  return 1;

}





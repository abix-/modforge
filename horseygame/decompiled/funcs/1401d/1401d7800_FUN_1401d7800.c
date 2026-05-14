// Address: 0x1401d7800
// Ghidra name: FUN_1401d7800
// ============ 0x1401d7800 FUN_1401d7800 (size=13691) ============


undefined1

FUN_1401d7800(uint param_1,uint param_2,longlong param_3,int param_4,int param_5,undefined1 *param_6

             ,int param_7,int param_8)



{

  float fVar1;

  char cVar2;

  undefined1 uVar3;

  undefined1 uVar4;

  undefined1 uVar5;

  uint uVar6;

  uint uVar7;

  undefined8 uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  uint uVar11;

  longlong lVar12;

  undefined1 uVar13;

  int iVar14;

  uint uVar15;

  undefined1 *puVar16;

  ulonglong uVar17;

  longlong lVar18;

  uint uVar19;

  longlong lVar20;

  uint uVar21;

  uint uVar22;

  longlong lVar23;

  ulonglong uVar24;

  int iVar25;

  uint *puVar26;

  longlong lVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  longlong local_res18;

  int local_98 [2];

  longlong local_90;

  undefined1 *local_88;

  undefined1 *local_80 [2];

  undefined1 *local_70;

  ulonglong local_68;

  uint local_60;

  

  fVar1 = DAT_14039ca34;

  uVar24 = (ulonglong)param_2;

  lVar23 = (longlong)(int)param_1;

  lVar12 = (longlong)param_8;

  lVar18 = (longlong)param_4;

  param_4 = param_4 * 2;

  local_68 = CONCAT44(local_68._4_4_,(int)param_2 / 2);

  local_60 = param_2 & 1;

  uVar6 = param_1 & 1;

  local_90 = (longlong)((int)param_1 / 2);

  if (param_5 < 0x3259555a) {

    if (param_5 != 0x32595559) {

      if (((param_5 != 0x3132564e) && (param_5 != 0x3231564e)) && (param_5 != 0x32315659)) {

LAB_1401d793b:

        uVar8 = FUN_14017af90(param_5);

        uVar3 = FUN_14012e850("Unsupported YUV destination format: %s",uVar8);

        return uVar3;

      }

LAB_1401d78ba:

      cVar2 = FUN_1401d4490(param_1,param_2,param_5,param_6,param_7,local_80,&local_88,&local_70,

                            local_98,&param_8);

      fVar1 = DAT_14039ca34;

      if (cVar2 == '\0') {

        return 0;

      }

      uVar9 = 0;

      iVar25 = 0;

      puVar16 = local_80[0] + local_98[0] * param_2;

      uVar3 = 0;

      lVar27 = param_3;

      if (0 < (int)param_2) {

        do {

          uVar17 = uVar9;

          if (3 < lVar23) {

            puVar26 = (uint *)(lVar27 + 8);

            lVar20 = (lVar23 - 4U >> 2) + 1;

            uVar17 = lVar20 * 4;

            do {

              uVar11 = puVar26[-2];

              iVar14 = (int)((float)(uVar11 >> 8 & 0xff) *

                             *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 >> 0x10 & 0xff) *

                             *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar14) && (uVar13 = (char)iVar14, 0xff < iVar14)) {

                uVar13 = 0xff;

              }

              *local_80[0] = uVar13;

              uVar11 = puVar26[-1];

              iVar14 = (int)((float)(uVar11 >> 8 & 0xff) *

                             *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 >> 0x10 & 0xff) *

                             *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar14) && (uVar13 = (char)iVar14, 0xff < iVar14)) {

                uVar13 = 0xff;

              }

              local_80[0][1] = uVar13;

              uVar11 = *puVar26;

              iVar14 = (int)((float)(uVar11 >> 8 & 0xff) *

                             *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 >> 0x10 & 0xff) *

                             *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar14) && (uVar13 = (char)iVar14, 0xff < iVar14)) {

                uVar13 = 0xff;

              }

              local_80[0][2] = uVar13;

              uVar11 = puVar26[1];

              iVar14 = (int)((float)(uVar11 >> 8 & 0xff) *

                             *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 >> 0x10 & 0xff) *

                             *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar14) && (uVar13 = (char)iVar14, 0xff < iVar14)) {

                uVar13 = 0xff;

              }

              local_80[0][3] = uVar13;

              puVar26 = puVar26 + 4;

              local_80[0] = local_80[0] + 4;

              lVar20 = lVar20 + -1;

            } while (lVar20 != 0);

          }

          if ((longlong)uVar17 < lVar23) {

            puVar26 = (uint *)(lVar27 + uVar17 * 4);

            lVar20 = lVar23 - uVar17;

            do {

              uVar11 = *puVar26;

              iVar14 = (int)((float)(uVar11 >> 8 & 0xff) *

                             *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 >> 0x10 & 0xff) *

                             *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar14) && (uVar13 = (char)iVar14, 0xff < iVar14)) {

                uVar13 = 0xff;

              }

              *local_80[0] = uVar13;

              puVar26 = puVar26 + 1;

              local_80[0] = local_80[0] + 1;

              lVar20 = lVar20 + -1;

            } while (lVar20 != 0);

          }

          local_80[0] = local_80[0] + (local_98[0] - param_1);

          uVar24 = uVar24 - 1;

          lVar27 = lVar27 + lVar18;

        } while (uVar24 != 0);

      }

      lVar18 = lVar18 + param_3;

      uVar4 = 0;

      uVar5 = 0;

      uVar13 = 0;

      if ((param_5 != 0x32315659) && (param_5 != 0x56555949)) {

        uVar11 = param_8 + ((int)(param_1 + 1) / 2) * -2;

        local_80[0] = (undefined1 *)(local_68 & 0xffffffff);

        if (param_5 == 0x3231564e) {

          if (0 < (int)local_68) {

            do {

              uVar24 = uVar9;

              if (3 < local_90) {

                lVar27 = param_3 - lVar18;

                puVar26 = (uint *)(lVar18 + 4);

                lVar23 = (local_90 - 4U >> 2) + 1;

                uVar24 = lVar23 * 4;

                do {

                  uVar7 = puVar26[-1];

                  uVar15 = *puVar26;

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + -4);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar15 & 0xff0000) +

                                   (uVar7 & 0xff0000) + (uVar19 & 0xff0000) + (uVar21 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar15 & 0xff) +

                                   (uVar7 & 0xff) + (uVar19 & 0xff) + (uVar21 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar3;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  *puVar16 = uVar4;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar3;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[1] = uVar4;

                  uVar7 = puVar26[1];

                  uVar15 = puVar26[2];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 8);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 4);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar3;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[2] = uVar4;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[3] = uVar4;

                  uVar7 = puVar26[3];

                  uVar15 = puVar26[4];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 0x10);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 0xc);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[4] = uVar4;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[5] = uVar4;

                  uVar7 = puVar26[5];

                  uVar15 = puVar26[6];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 0x18);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 0x14);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[6] = uVar4;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  puVar16[7] = uVar4;

                  puVar26 = puVar26 + 8;

                  puVar16 = puVar16 + 8;

                  lVar23 = lVar23 + -1;

                } while (lVar23 != 0);

              }

              if ((longlong)uVar24 < local_90) {

                puVar26 = (uint *)(uVar24 * 8 + 4 + lVar18);

                lVar23 = local_90 - uVar24;

                uVar24 = uVar24 + lVar23;

                do {

                  uVar7 = *(uint *)((param_3 - lVar18) + -4 + (longlong)puVar26);

                  uVar15 = puVar26[-1];

                  uVar19 = *(uint *)((param_3 - lVar18) + (longlong)puVar26);

                  uVar21 = *puVar26;

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar4 = uVar13;

                  if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                    uVar4 = 0xff;

                  }

                  *puVar16 = uVar4;

                  uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

                  uVar17 = uVar9;

                  if ((-1 < (int)uVar7) && (uVar17 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

                    uVar17 = 0xff;

                  }

                  puVar16[1] = (char)uVar17;

                  puVar26 = puVar26 + 2;

                  puVar16 = puVar16 + 2;

                  lVar23 = lVar23 + -1;

                } while (lVar23 != 0);

              }

              if (uVar6 != 0) {

                uVar7 = *(uint *)(param_3 + uVar24 * 8);

                uVar15 = *(uint *)(lVar18 + uVar24 * 8);

                fVar29 = (float)((uVar7 & 0xff00) + (uVar15 & 0xff00) >> 9);

                fVar28 = (float)((uVar7 & 0xff0000) + (uVar15 & 0xff0000) >> 0x11);

                fVar30 = (float)((uVar7 & 0xff) + (uVar15 & 0xff) >> 1);

                iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                               fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                               fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

                uVar4 = uVar13;

                if ((-1 < iVar14) && (uVar4 = (char)iVar14, 0xff < iVar14)) {

                  uVar4 = 0xff;

                }

                *puVar16 = uVar4;

                uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                              fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                              fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

                uVar24 = uVar9;

                if ((-1 < (int)uVar7) && (uVar24 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

                  uVar24 = 0xff;

                }

                puVar16[1] = (char)uVar24;

                puVar16 = puVar16 + 2;

              }

              param_3 = param_3 + param_4;

              puVar16 = puVar16 + uVar11;

              lVar18 = lVar18 + param_4;

              local_80[0] = local_80[0] + -1;

            } while (local_80[0] != (undefined1 *)0x0);

          }

          if (local_60 == 0) {

            return 1;

          }

          uVar24 = uVar9;

          if (3 < local_90) {

            puVar26 = (uint *)(param_3 + 8);

            lVar18 = (local_90 - 4U >> 2) + 1;

            iVar25 = (int)lVar18 * 4;

            uVar24 = lVar18 * 4;

            do {

              uVar11 = puVar26[-2];

              uVar7 = puVar26[-1];

              fVar29 = (float)((uVar7 & 0xff00) + (uVar11 & 0xff00) >> 9);

              fVar28 = (float)((uVar7 & 0xff0000) + (uVar11 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *puVar16 = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[1] = uVar3;

              uVar11 = *puVar26;

              uVar7 = puVar26[1];

              fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[2] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[3] = uVar3;

              uVar11 = puVar26[2];

              uVar7 = puVar26[3];

              fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[4] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[5] = uVar3;

              uVar11 = puVar26[4];

              uVar7 = puVar26[5];

              fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[6] = uVar3;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar17 = uVar9;

              if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar17 = 0xff;

              }

              puVar16[7] = (char)uVar17;

              puVar26 = puVar26 + 8;

              puVar16 = puVar16 + 8;

              lVar18 = lVar18 + -1;

            } while (lVar18 != 0);

          }

          if ((longlong)uVar24 < local_90) {

            iVar25 = iVar25 + ((int)local_90 - (int)uVar24);

            do {

              uVar11 = *(uint *)(param_3 + uVar24 * 8);

              uVar7 = *(uint *)(param_3 + 4 + uVar24 * 8);

              fVar29 = (float)((uVar7 & 0xff00) + (uVar11 & 0xff00) >> 9);

              fVar28 = (float)((uVar7 & 0xff0000) + (uVar11 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar5;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *puVar16 = uVar3;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar17 = uVar9;

              if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar17 = 0xff;

              }

              puVar16[1] = (char)uVar17;

              uVar24 = uVar24 + 1;

              puVar16 = puVar16 + 2;

            } while ((longlong)uVar24 < local_90);

          }

          if (uVar6 == 0) {

            return 1;

          }

          uVar6 = *(uint *)(param_3 + (longlong)(iVar25 * 2) * 4);

          fVar29 = (float)(uVar6 >> 0x10 & 0xff);

          fVar28 = (float)(uVar6 >> 8 & 0xff);

          iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1)

                   + 0x80;

          if ((-1 < iVar25) && (uVar5 = (undefined1)iVar25, 0xff < iVar25)) {

            uVar5 = 0xff;

          }

          *puVar16 = uVar5;

          fVar28 = fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28);

          fVar29 = fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28);

          fVar30 = (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28);

        }

        else {

          if (0 < (int)local_68) {

            do {

              uVar24 = uVar9;

              if (3 < local_90) {

                lVar27 = param_3 - lVar18;

                puVar26 = (uint *)(lVar18 + 4);

                lVar23 = (local_90 - 4U >> 2) + 1;

                uVar24 = lVar23 * 4;

                do {

                  uVar7 = *(uint *)((longlong)puVar26 + lVar27 + -4);

                  uVar15 = puVar26[-1];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27);

                  uVar21 = *puVar26;

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  *puVar16 = uVar3;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[1] = uVar3;

                  uVar7 = puVar26[1];

                  uVar15 = puVar26[2];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 8);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 4);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[2] = uVar3;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[3] = uVar3;

                  uVar7 = puVar26[3];

                  uVar15 = puVar26[4];

                  uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 0x10);

                  uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 0xc);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[4] = uVar3;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[5] = uVar3;

                  uVar7 = puVar26[5];

                  uVar15 = puVar26[6];

                  uVar19 = *(uint *)(lVar27 + 0x18 + (longlong)puVar26);

                  uVar21 = *(uint *)(lVar27 + 0x14 + (longlong)puVar26);

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[6] = uVar3;

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  puVar16[7] = uVar3;

                  puVar26 = puVar26 + 8;

                  puVar16 = puVar16 + 8;

                  lVar23 = lVar23 + -1;

                } while (lVar23 != 0);

              }

              if ((longlong)uVar24 < local_90) {

                puVar26 = (uint *)(uVar24 * 8 + 4 + lVar18);

                lVar23 = local_90 - uVar24;

                uVar24 = uVar24 + lVar23;

                do {

                  uVar7 = *(uint *)((longlong)puVar26 + (param_3 - lVar18) + -4);

                  uVar15 = puVar26[-1];

                  uVar19 = *(uint *)((longlong)puVar26 + (param_3 - lVar18));

                  uVar21 = *puVar26;

                  fVar29 = (float)((uVar21 & 0xff00) +

                                   (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

                  fVar28 = (float)((uVar21 & 0xff0000) +

                                   (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                                  0x12);

                  fVar30 = (float)((uVar21 & 0xff) +

                                   (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff) >> 2);

                  iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                                 fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                                 fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80

                  ;

                  uVar3 = uVar5;

                  if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                    uVar3 = 0xff;

                  }

                  *puVar16 = uVar3;

                  uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                                fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                                fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

                  uVar17 = uVar9;

                  if ((-1 < (int)uVar7) && (uVar17 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

                    uVar17 = 0xff;

                  }

                  puVar16[1] = (char)uVar17;

                  puVar26 = puVar26 + 2;

                  puVar16 = puVar16 + 2;

                  lVar23 = lVar23 + -1;

                } while (lVar23 != 0);

              }

              if (uVar6 != 0) {

                uVar7 = *(uint *)(param_3 + uVar24 * 8);

                uVar15 = *(uint *)(lVar18 + uVar24 * 8);

                fVar29 = (float)((uVar7 & 0xff00) + (uVar15 & 0xff00) >> 9);

                fVar28 = (float)((uVar7 & 0xff0000) + (uVar15 & 0xff0000) >> 0x11);

                fVar30 = (float)((uVar7 & 0xff) + (uVar15 & 0xff) >> 1);

                iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                               fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                               fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

                uVar3 = uVar5;

                if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                  uVar3 = 0xff;

                }

                *puVar16 = uVar3;

                uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                              fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                              fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

                uVar24 = uVar9;

                if ((-1 < (int)uVar7) && (uVar24 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

                  uVar24 = 0xff;

                }

                puVar16[1] = (char)uVar24;

                puVar16 = puVar16 + 2;

              }

              param_3 = param_3 + param_4;

              puVar16 = puVar16 + uVar11;

              lVar18 = lVar18 + param_4;

              local_80[0] = local_80[0] + -1;

            } while (local_80[0] != (undefined1 *)0x0);

          }

          if (local_60 == 0) {

            return 1;

          }

          uVar24 = uVar9;

          if (3 < local_90) {

            puVar26 = (uint *)(param_3 + 8);

            lVar18 = (local_90 - 4U >> 2) + 1;

            iVar25 = (int)lVar18 * 4;

            uVar24 = lVar18 * 4;

            do {

              uVar11 = puVar26[-2];

              uVar7 = puVar26[-1];

              fVar28 = (float)((uVar7 & 0xff00) + (uVar11 & 0xff00) >> 9);

              fVar29 = (float)((uVar7 & 0xff0000) + (uVar11 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar14 = (int)(fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar5;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *puVar16 = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar5;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[1] = uVar3;

              uVar11 = *puVar26;

              uVar7 = puVar26[1];

              fVar28 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar29 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar5;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[2] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar5;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[3] = uVar3;

              uVar11 = puVar26[2];

              uVar7 = puVar26[3];

              fVar28 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar29 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[4] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[5] = uVar3;

              uVar11 = puVar26[4];

              uVar7 = puVar26[5];

              fVar28 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

              fVar29 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

              iVar14 = (int)(fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              puVar16[6] = uVar3;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar17 = uVar9;

              if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar17 = 0xff;

              }

              puVar16[7] = (char)uVar17;

              puVar26 = puVar26 + 8;

              puVar16 = puVar16 + 8;

              lVar18 = lVar18 + -1;

            } while (lVar18 != 0);

          }

          if ((longlong)uVar24 < local_90) {

            iVar25 = iVar25 + ((int)local_90 - (int)uVar24);

            do {

              uVar11 = *(uint *)(param_3 + uVar24 * 8);

              uVar7 = *(uint *)(param_3 + 4 + uVar24 * 8);

              fVar28 = (float)((uVar7 & 0xff00) + (uVar11 & 0xff00) >> 9);

              fVar29 = (float)((uVar7 & 0xff0000) + (uVar11 & 0xff0000) >> 0x11);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar14 = (int)(fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *puVar16 = uVar3;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar17 = uVar9;

              if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar17 = 0xff;

              }

              puVar16[1] = (char)uVar17;

              uVar24 = uVar24 + 1;

              puVar16 = puVar16 + 2;

            } while ((longlong)uVar24 < local_90);

          }

          if (uVar6 == 0) {

            return 1;

          }

          uVar6 = *(uint *)(param_3 + (longlong)(iVar25 * 2) * 4);

          fVar29 = (float)(uVar6 >> 0x10 & 0xff);

          fVar28 = (float)(uVar6 >> 8 & 0xff);

          iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1)

                   + 0x80;

          if ((-1 < iVar25) && (uVar4 = (undefined1)iVar25, 0xff < iVar25)) {

            uVar4 = 0xff;

          }

          *puVar16 = uVar4;

          fVar28 = fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28);

          fVar29 = fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28);

          fVar30 = (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28);

        }

        uVar6 = (int)(fVar28 + fVar29 + fVar30 + fVar1) + 0x80;

        if (-1 < (int)uVar6) {

          if (0xff < (int)uVar6) {

            uVar6 = 0xff;

          }

          uVar9 = (ulonglong)uVar6;

        }

        puVar16[1] = (char)uVar9;

        return 1;

      }

      uVar11 = param_8 - (int)(param_1 + 1) / 2;

      local_80[0] = (undefined1 *)(local_68 & 0xffffffff);

      local_res18 = param_3;

      if (0 < (int)local_68) {

        do {

          uVar24 = uVar9;

          if (3 < local_90) {

            lVar27 = local_res18 - lVar18;

            lVar23 = (local_90 - 4U >> 2) + 1;

            puVar26 = (uint *)(lVar18 + 4);

            uVar24 = lVar23 * 4;

            do {

              uVar7 = *(uint *)((longlong)puVar26 + lVar27 + -4);

              uVar15 = puVar26[-1];

              uVar19 = *(uint *)((longlong)puVar26 + lVar27);

              uVar21 = *puVar26;

              fVar29 = (float)((uVar21 & 0xff00) +

                               (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

              fVar28 = (float)((uVar21 & 0xff0000) +

                               (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                              0x12);

              fVar30 = (float)((uVar21 & 0xff) + (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff)

                              >> 2);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *local_88 = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *local_70 = uVar3;

              uVar7 = puVar26[1];

              uVar15 = puVar26[2];

              uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 8);

              uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 4);

              fVar29 = (float)((uVar21 & 0xff00) +

                               (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

              fVar28 = (float)((uVar21 & 0xff0000) +

                               (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                              0x12);

              fVar30 = (float)((uVar21 & 0xff) + (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff)

                              >> 2);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_88[1] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_70[1] = uVar3;

              uVar7 = puVar26[3];

              uVar15 = puVar26[4];

              uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 0x10);

              uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 0xc);

              fVar29 = (float)((uVar21 & 0xff00) +

                               (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

              fVar28 = (float)((uVar21 & 0xff0000) +

                               (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                              0x12);

              fVar30 = (float)((uVar21 & 0xff) + (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff)

                              >> 2);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_88[2] = uVar3;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_70[2] = uVar3;

              uVar7 = puVar26[5];

              uVar15 = puVar26[6];

              uVar19 = *(uint *)((longlong)puVar26 + lVar27 + 0x18);

              uVar21 = *(uint *)((longlong)puVar26 + lVar27 + 0x14);

              fVar29 = (float)((uVar21 & 0xff00) +

                               (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

              fVar28 = (float)((uVar21 & 0xff0000) +

                               (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                              0x12);

              fVar30 = (float)((uVar21 & 0xff) + (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff)

                              >> 2);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar4;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_88[3] = uVar3;

              local_88 = local_88 + 4;

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              local_70[3] = uVar3;

              puVar26 = puVar26 + 8;

              local_70 = local_70 + 4;

              lVar23 = lVar23 + -1;

            } while (lVar23 != 0);

          }

          if ((longlong)uVar24 < local_90) {

            puVar26 = (uint *)(uVar24 * 8 + 4 + lVar18);

            lVar23 = local_90 - uVar24;

            uVar24 = uVar24 + lVar23;

            do {

              uVar7 = *(uint *)((longlong)puVar26 + (local_res18 - lVar18) + -4);

              uVar15 = puVar26[-1];

              uVar19 = *(uint *)((longlong)puVar26 + (local_res18 - lVar18));

              uVar21 = *puVar26;

              fVar29 = (float)((uVar21 & 0xff00) +

                               (uVar15 & 0xff00) + (uVar7 & 0xff00) + (uVar19 & 0xff00) >> 10);

              fVar28 = (float)((uVar21 & 0xff0000) +

                               (uVar15 & 0xff0000) + (uVar7 & 0xff0000) + (uVar19 & 0xff0000) >>

                              0x12);

              fVar30 = (float)((uVar21 & 0xff) + (uVar15 & 0xff) + (uVar7 & 0xff) + (uVar19 & 0xff)

                              >> 2);

              iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar3 = uVar13;

              if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

                uVar3 = 0xff;

              }

              *local_88 = uVar3;

              local_88 = local_88 + 1;

              uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                            fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                            fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar17 = uVar9;

              if ((-1 < (int)uVar7) && (uVar17 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

                uVar17 = 0xff;

              }

              *local_70 = (char)uVar17;

              puVar26 = puVar26 + 2;

              local_70 = local_70 + 1;

              lVar23 = lVar23 + -1;

            } while (lVar23 != 0);

          }

          if (uVar6 != 0) {

            uVar7 = *(uint *)(local_res18 + uVar24 * 8);

            uVar15 = *(uint *)(lVar18 + uVar24 * 8);

            fVar29 = (float)((uVar7 & 0xff00) + (uVar15 & 0xff00) >> 9);

            fVar28 = (float)((uVar7 & 0xff0000) + (uVar15 & 0xff0000) >> 0x11);

            fVar30 = (float)((uVar7 & 0xff) + (uVar15 & 0xff) >> 1);

            iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar3 = uVar13;

            if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

              uVar3 = 0xff;

            }

            *local_88 = uVar3;

            local_88 = local_88 + 1;

            uVar7 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                          fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                          fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar24 = uVar9;

            if ((-1 < (int)uVar7) && (uVar24 = (ulonglong)uVar7, 0xff < (int)uVar7)) {

              uVar24 = 0xff;

            }

            *local_70 = (char)uVar24;

            local_70 = local_70 + 1;

          }

          local_res18 = local_res18 + param_4;

          local_88 = local_88 + uVar11;

          lVar18 = lVar18 + param_4;

          local_70 = local_70 + uVar11;

          local_80[0] = local_80[0] + -1;

        } while (local_80[0] != (undefined1 *)0x0);

      }

      if (local_60 == 0) {

        return 1;

      }

      uVar24 = uVar9;

      if (3 < local_90) {

        puVar26 = (uint *)(local_res18 + 8);

        lVar18 = (local_90 - 4U >> 2) + 1;

        iVar25 = (int)lVar18 * 4;

        uVar24 = lVar18 * 4;

        do {

          uVar11 = puVar26[-2];

          uVar7 = puVar26[-1];

          fVar29 = (float)((uVar7 & 0xff00) + (uVar11 & 0xff00) >> 9);

          fVar28 = (float)((uVar7 & 0xff0000) + (uVar11 & 0xff0000) >> 0x11);

          fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          *local_88 = uVar3;

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          *local_70 = uVar3;

          uVar11 = *puVar26;

          uVar7 = puVar26[1];

          fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

          fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

          fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          local_88[1] = uVar3;

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          local_70[1] = uVar3;

          uVar11 = puVar26[2];

          uVar7 = puVar26[3];

          fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

          fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

          fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          local_88[2] = uVar3;

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          local_70[2] = uVar3;

          uVar11 = puVar26[4];

          uVar7 = puVar26[5];

          fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

          fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

          fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar13;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          local_88[3] = uVar3;

          local_88 = local_88 + 4;

          uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar17 = uVar9;

          if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

            uVar17 = 0xff;

          }

          local_70[3] = (char)uVar17;

          puVar26 = puVar26 + 8;

          local_70 = local_70 + 4;

          lVar18 = lVar18 + -1;

        } while (lVar18 != 0);

      }

      if ((longlong)uVar24 < local_90) {

        local_90 = local_90 - uVar24;

        puVar26 = (uint *)(local_res18 + uVar24 * 8);

        iVar25 = iVar25 + (int)local_90;

        do {

          uVar11 = *puVar26;

          uVar7 = puVar26[1];

          fVar29 = (float)((uVar11 & 0xff00) + (uVar7 & 0xff00) >> 9);

          fVar28 = (float)((uVar11 & 0xff0000) + (uVar7 & 0xff0000) >> 0x11);

          fVar30 = (float)((uVar11 & 0xff) + (uVar7 & 0xff) >> 1);

          iVar14 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar3 = uVar5;

          if ((-1 < iVar14) && (uVar3 = (char)iVar14, 0xff < iVar14)) {

            uVar3 = 0xff;

          }

          *local_88 = uVar3;

          local_88 = local_88 + 1;

          uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar24 = uVar9;

          if ((-1 < (int)uVar11) && (uVar24 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

            uVar24 = 0xff;

          }

          *local_70 = (char)uVar24;

          puVar26 = puVar26 + 2;

          local_70 = local_70 + 1;

          local_90 = local_90 + -1;

        } while (local_90 != 0);

      }

      if (uVar6 == 0) {

        return 1;

      }

      uVar6 = *(uint *)(local_res18 + (longlong)(iVar25 * 2) * 4);

      fVar29 = (float)(uVar6 >> 0x10 & 0xff);

      fVar28 = (float)(uVar6 >> 8 & 0xff);

      iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                     fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                     (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) +

               0x80;

      if ((-1 < iVar25) && (uVar5 = (undefined1)iVar25, 0xff < iVar25)) {

        uVar5 = 0xff;

      }

      *local_88 = uVar5;

      uVar6 = (int)(fVar28 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                    fVar29 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                    (float)(uVar6 & 0xff) * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) +

              0x80;

      if ((-1 < (int)uVar6) && (uVar9 = (ulonglong)uVar6, 0xff < (int)uVar6)) {

        uVar9 = 0xff;

      }

      *local_70 = (char)uVar9;

      return 1;

    }

  }

  else if (param_5 != 0x55595659) {

    if (param_5 == 0x56555949) goto LAB_1401d78ba;

    if (param_5 != 0x59565955) goto LAB_1401d793b;

  }

  iVar25 = (int)(param_1 + 1) / 2;

  iVar14 = iVar25 * 4;

  if (iVar14 <= param_7) {

    param_7 = param_7 + iVar25 * -4;

    if (param_5 == 0x32595559) {

      if (0 < (int)param_2) {

        uVar9 = 0;

        do {

          uVar3 = 0;

          uVar17 = uVar9;

          if (0 < local_90) {

            do {

              uVar11 = *(uint *)(param_3 + uVar17 * 8);

              uVar19 = uVar11 >> 0x10 & 0xff;

              uVar7 = *(uint *)(param_3 + 4 + uVar17 * 8);

              uVar15 = uVar11 >> 8 & 0xff;

              uVar21 = uVar7 >> 0x10 & 0xff;

              uVar22 = uVar7 >> 8 & 0xff;

              iVar25 = (int)((float)uVar15 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)uVar19 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              *param_6 = uVar13;

              fVar29 = (float)(uVar15 + uVar22 >> 1);

              fVar28 = (float)(uVar21 + uVar19 >> 1);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              param_6[1] = uVar13;

              iVar25 = (int)((float)uVar21 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)uVar22 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar7 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              param_6[2] = uVar13;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar10 = uVar9;

              if ((-1 < (int)uVar11) && (uVar10 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar10 = 0xff;

              }

              uVar17 = uVar17 + 1;

              param_6[3] = (char)uVar10;

              param_6 = param_6 + 4;

            } while ((longlong)uVar17 < local_90);

          }

          if (uVar6 != 0) {

            uVar11 = *(uint *)(param_3 + uVar17 * 8);

            uVar15 = uVar11 >> 0x10 & 0xff;

            uVar7 = uVar11 >> 8 & 0xff;

            fVar30 = (float)(uVar11 & 0xff);

            fVar28 = (float)uVar7;

            fVar29 = (float)uVar15;

            iVar25 = (int)(fVar29 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           fVar28 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) + fVar1) +

                     *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            *param_6 = uVar13;

            iVar25 = (int)(fVar29 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                           fVar28 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            param_6[1] = uVar13;

            iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) + fVar1) +

                     *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            if ((-1 < iVar25) && (uVar3 = (undefined1)iVar25, 0xff < iVar25)) {

              uVar3 = 0xff;

            }

            param_6[2] = uVar3;

            uVar11 = (int)((float)uVar7 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                           (float)uVar15 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                           (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) +

                          fVar1) + 0x80;

            uVar17 = uVar9;

            if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

              uVar17 = 0xff;

            }

            param_6[3] = (char)uVar17;

            param_6 = param_6 + 4;

          }

          param_3 = param_3 + lVar18;

          param_6 = param_6 + param_7;

          uVar24 = uVar24 - 1;

        } while (uVar24 != 0);

      }

    }

    else if (param_5 == 0x59565955) {

      if (0 < (int)param_2) {

        uVar9 = 0;

        do {

          uVar3 = 0;

          uVar17 = uVar9;

          if (0 < local_90) {

            do {

              uVar11 = *(uint *)(param_3 + uVar17 * 8);

              uVar15 = uVar11 >> 0x10 & 0xff;

              uVar7 = *(uint *)(param_3 + 4 + uVar17 * 8);

              uVar19 = uVar11 >> 8 & 0xff;

              uVar21 = uVar7 >> 0x10 & 0xff;

              uVar22 = uVar7 >> 8 & 0xff;

              fVar29 = (float)(uVar22 + uVar19 >> 1);

              fVar28 = (float)(uVar21 + uVar15 >> 1);

              fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

              iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              *param_6 = uVar13;

              iVar25 = (int)((float)uVar15 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)uVar19 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              param_6[1] = uVar13;

              uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                             fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                             fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

              uVar10 = uVar9;

              if ((-1 < (int)uVar11) && (uVar10 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

                uVar10 = 0xff;

              }

              param_6[2] = (char)uVar10;

              iVar25 = (int)((float)uVar21 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                             (float)uVar22 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                             (float)(uVar7 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                            fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

              uVar13 = uVar3;

              if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

                uVar13 = 0xff;

              }

              uVar17 = uVar17 + 1;

              param_6[3] = uVar13;

              param_6 = param_6 + 4;

            } while ((longlong)uVar17 < local_90);

          }

          if (uVar6 != 0) {

            uVar11 = *(uint *)(param_3 + uVar17 * 8);

            uVar15 = uVar11 >> 0x10 & 0xff;

            uVar7 = uVar11 >> 8 & 0xff;

            fVar30 = (float)(uVar11 & 0xff);

            fVar29 = (float)uVar7;

            fVar28 = (float)uVar15;

            iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            *param_6 = uVar13;

            iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) + fVar1) +

                     *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            param_6[1] = uVar13;

            uVar19 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar17 = uVar9;

            if ((-1 < (int)uVar19) && (uVar17 = (ulonglong)uVar19, 0xff < (int)uVar19)) {

              uVar17 = 0xff;

            }

            param_6[2] = (char)uVar17;

            iVar25 = (int)((float)uVar7 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           (float)uVar15 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                          fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            if ((-1 < iVar25) && (uVar3 = (undefined1)iVar25, 0xff < iVar25)) {

              uVar3 = 0xff;

            }

            param_6[3] = uVar3;

            param_6 = param_6 + 4;

          }

          param_3 = param_3 + lVar18;

          param_6 = param_6 + param_7;

          uVar24 = uVar24 - 1;

        } while (uVar24 != 0);

      }

    }

    else if ((param_5 == 0x55595659) && (0 < (int)param_2)) {

      uVar9 = 0;

      do {

        uVar3 = 0;

        uVar17 = uVar9;

        if (0 < local_90) {

          do {

            uVar11 = *(uint *)(param_3 + uVar17 * 8);

            uVar15 = uVar11 >> 0x10 & 0xff;

            uVar7 = *(uint *)(param_3 + 4 + uVar17 * 8);

            uVar19 = uVar11 >> 8 & 0xff;

            uVar21 = uVar7 >> 0x10 & 0xff;

            uVar22 = uVar7 >> 8 & 0xff;

            iVar25 = (int)((float)uVar15 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           (float)uVar19 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                          fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            *param_6 = uVar13;

            fVar29 = (float)(uVar19 + uVar22 >> 1);

            fVar28 = (float)(uVar21 + uVar15 >> 1);

            fVar30 = (float)((uVar7 & 0xff) + (uVar11 & 0xff) >> 1);

            iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            param_6[1] = uVar13;

            iVar25 = (int)((float)uVar22 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                           (float)uVar21 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                           (float)(uVar7 & 0xff) * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) +

                          fVar1) + *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

            uVar13 = uVar3;

            if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

              uVar13 = 0xff;

            }

            param_6[2] = uVar13;

            uVar11 = (int)(fVar28 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                           fVar29 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                           fVar30 * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1) + 0x80;

            uVar10 = uVar9;

            if ((-1 < (int)uVar11) && (uVar10 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

              uVar10 = 0xff;

            }

            uVar17 = uVar17 + 1;

            param_6[3] = (char)uVar10;

            param_6 = param_6 + 4;

          } while ((longlong)uVar17 < local_90);

        }

        if (uVar6 != 0) {

          uVar11 = *(uint *)(param_3 + uVar17 * 8);

          uVar15 = uVar11 >> 0x10 & 0xff;

          uVar7 = uVar11 >> 8 & 0xff;

          fVar30 = (float)(uVar11 & 0xff);

          fVar29 = (float)uVar7;

          fVar28 = (float)uVar15;

          iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) + fVar1) +

                   *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

          uVar13 = uVar3;

          if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

            uVar13 = 0xff;

          }

          *param_6 = uVar13;

          iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4abc + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4ac0 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4ac4 + lVar12 * 0x28) + fVar1) + 0x80;

          uVar13 = uVar3;

          if ((-1 < iVar25) && (uVar13 = (char)iVar25, 0xff < iVar25)) {

            uVar13 = 0xff;

          }

          param_6[1] = uVar13;

          iVar25 = (int)(fVar28 * *(float *)(&DAT_1403e4aa4 + lVar12 * 0x28) +

                         fVar29 * *(float *)(&DAT_1403e4aa8 + lVar12 * 0x28) +

                         fVar30 * *(float *)(&DAT_1403e4aac + lVar12 * 0x28) + fVar1) +

                   *(int *)(&DAT_1403e4aa0 + lVar12 * 0x28);

          if ((-1 < iVar25) && (uVar3 = (undefined1)iVar25, 0xff < iVar25)) {

            uVar3 = 0xff;

          }

          param_6[2] = uVar3;

          uVar11 = (int)((float)uVar7 * *(float *)(&DAT_1403e4ab4 + lVar12 * 0x28) +

                         (float)uVar15 * *(float *)(&DAT_1403e4ab0 + lVar12 * 0x28) +

                         (float)(uVar11 & 0xff) * *(float *)(&DAT_1403e4ab8 + lVar12 * 0x28) + fVar1

                        ) + 0x80;

          uVar17 = uVar9;

          if ((-1 < (int)uVar11) && (uVar17 = (ulonglong)uVar11, 0xff < (int)uVar11)) {

            uVar17 = 0xff;

          }

          param_6[3] = (char)uVar17;

          param_6 = param_6 + 4;

        }

        param_3 = param_3 + lVar18;

        param_6 = param_6 + param_7;

        uVar24 = uVar24 - 1;

      } while (uVar24 != 0);

    }

    return 1;

  }

  uVar3 = FUN_14012e850("Destination pitch is too small, expected at least %d",iVar14);

  return uVar3;

}





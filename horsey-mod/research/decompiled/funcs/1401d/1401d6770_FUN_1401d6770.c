// Address: 0x1401d6770
// Ghidra name: FUN_1401d6770
// ============ 0x1401d6770 FUN_1401d6770 (size=4235) ============


undefined8

FUN_1401d6770(uint param_1,uint param_2,longlong param_3,int param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,uint param_8)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  float fVar5;

  short sVar6;

  int iVar7;

  int iVar8;

  undefined8 uVar9;

  ulonglong uVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  longlong lVar14;

  uint *puVar15;

  ulonglong uVar16;

  longlong lVar17;

  short *psVar18;

  ulonglong uVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  uint local_88 [2];

  ulonglong local_80;

  int local_78;

  uint local_74;

  short *local_70;

  undefined1 local_68 [8];

  undefined1 local_60 [32];

  

  uVar19 = (ulonglong)param_2;

  lVar12 = (longlong)(int)param_1;

  lVar11 = (longlong)(int)param_8;

  local_78 = param_4 * 2;

  local_80 = CONCAT44(local_80._4_4_,(int)param_2 / 2);

  local_74 = param_2 & 1;

  iVar7 = (int)param_1 / 2;

  uVar9 = FUN_1401d4490(param_1,param_2,param_5,param_6,param_7,&local_70,local_60,local_68,&param_8

                        ,local_88);

  fVar5 = DAT_14039ca34;

  if ((char)uVar9 != '\0') {

    psVar18 = local_70 + (param_8 >> 1) * param_2;

    if (0 < (int)param_2) {

      lVar14 = param_3;

      do {

        lVar13 = 0;

        if (3 < lVar12) {

          puVar15 = (uint *)(lVar14 + 8);

          lVar17 = (lVar12 - 4U >> 2) + 1;

          lVar13 = lVar17 * 4;

          do {

            uVar1 = puVar15[-2];

            *local_70 = ((short)(int)((float)(uVar1 >> 10 & 0x3ff) *

                                      *(float *)(&DAT_1403e4aa8 + lVar11 * 0x28) +

                                      (float)(uVar1 & 0x3ff) *

                                      *(float *)(&DAT_1403e4aa4 + lVar11 * 0x28) +

                                      (float)(uVar1 >> 0x14 & 0x3ff) *

                                      *(float *)(&DAT_1403e4aac + lVar11 * 0x28) + fVar5) +

                        *(short *)(&DAT_1403e4aa0 + lVar11 * 0x28)) * 0x40;

            uVar1 = puVar15[-1];

            local_70[1] = ((short)(int)((float)(uVar1 >> 10 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa8 + lVar11 * 0x28) +

                                        (float)(uVar1 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa4 + lVar11 * 0x28) +

                                        (float)(uVar1 >> 0x14 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aac + lVar11 * 0x28) + fVar5) +

                          *(short *)(&DAT_1403e4aa0 + lVar11 * 0x28)) * 0x40;

            uVar1 = *puVar15;

            local_70[2] = ((short)(int)((float)(uVar1 >> 10 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa8 + lVar11 * 0x28) +

                                        (float)(uVar1 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa4 + lVar11 * 0x28) +

                                        (float)(uVar1 >> 0x14 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aac + lVar11 * 0x28) + fVar5) +

                          *(short *)(&DAT_1403e4aa0 + lVar11 * 0x28)) * 0x40;

            uVar1 = puVar15[1];

            puVar15 = puVar15 + 4;

            local_70[3] = ((short)(int)((float)(uVar1 >> 10 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa8 + lVar11 * 0x28) +

                                        (float)(uVar1 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aa4 + lVar11 * 0x28) +

                                        (float)(uVar1 >> 0x14 & 0x3ff) *

                                        *(float *)(&DAT_1403e4aac + lVar11 * 0x28) + fVar5) +

                          *(short *)(&DAT_1403e4aa0 + lVar11 * 0x28)) * 0x40;

            local_70 = local_70 + 4;

            lVar17 = lVar17 + -1;

          } while (lVar17 != 0);

        }

        for (; lVar13 < lVar12; lVar13 = lVar13 + 1) {

          uVar1 = *(uint *)(lVar14 + lVar13 * 4);

          *local_70 = ((short)(int)((float)(uVar1 >> 10 & 0x3ff) *

                                    *(float *)(&DAT_1403e4aa8 + lVar11 * 0x28) +

                                    (float)(uVar1 & 0x3ff) *

                                    *(float *)(&DAT_1403e4aa4 + lVar11 * 0x28) +

                                    (float)(uVar1 >> 0x14 & 0x3ff) *

                                    *(float *)(&DAT_1403e4aac + lVar11 * 0x28) + fVar5) +

                      *(short *)(&DAT_1403e4aa0 + lVar11 * 0x28)) * 0x40;

          local_70 = local_70 + 1;

        }

        local_70 = local_70 + ((param_8 >> 1) - param_1);

        lVar14 = lVar14 + param_4;

        uVar19 = uVar19 - 1;

      } while (uVar19 != 0);

    }

    lVar12 = param_4 + param_3;

    iVar8 = (int)(param_1 + 1) / 2;

    uVar19 = (ulonglong)(uint)(iVar8 * 2);

    if (0 < (int)local_80) {

      uVar10 = (ulonglong)((local_88[0] >> 1) + iVar8 * -2);

      uVar19 = uVar10 * 2;

      local_80 = local_80 & 0xffffffff;

      do {

        lVar14 = 0;

        if (3 < (longlong)iVar7) {

          lVar13 = param_3 - lVar12;

          lVar17 = ((longlong)iVar7 - 4U >> 2) + 1;

          puVar15 = (uint *)(lVar12 + 4);

          lVar14 = lVar17 * 4;

          do {

            uVar1 = *(uint *)(lVar13 + (longlong)puVar15);

            uVar2 = *puVar15;

            uVar3 = *(uint *)(lVar13 + -4 + (longlong)puVar15);

            uVar4 = puVar15[-1];

            fVar22 = (float)((uVar2 & 0xffc00) +

                             (uVar4 & 0xffc00) + (uVar3 & 0xffc00) + (uVar1 & 0xffc00) >> 0xc);

            fVar21 = (float)((uVar2 & 0x3ff) + (uVar4 & 0x3ff) + (uVar3 & 0x3ff) + (uVar1 & 0x3ff)

                            >> 2);

            fVar20 = (float)((uVar2 & 0x3ff00000) + (uVar1 & 0x3ff00000) + (uVar4 & 0x3ff00000) +

                             (uVar3 & 0x3ff00000) >> 0x16);

            *psVar18 = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

            psVar18[1] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            uVar1 = puVar15[1];

            uVar2 = puVar15[2];

            uVar3 = *(uint *)(lVar13 + 8 + (longlong)puVar15);

            uVar4 = *(uint *)(lVar13 + 4 + (longlong)puVar15);

            fVar22 = (float)((uVar4 & 0xffc00) +

                             (uVar2 & 0xffc00) + (uVar1 & 0xffc00) + (uVar3 & 0xffc00) >> 0xc);

            fVar21 = (float)((uVar4 & 0x3ff) + (uVar2 & 0x3ff) + (uVar1 & 0x3ff) + (uVar3 & 0x3ff)

                            >> 2);

            fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) + (uVar3 & 0x3ff00000) +

                             (uVar4 & 0x3ff00000) >> 0x16);

            psVar18[2] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            psVar18[3] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            uVar1 = puVar15[3];

            uVar2 = puVar15[4];

            uVar3 = *(uint *)(lVar13 + 0x10 + (longlong)puVar15);

            uVar4 = *(uint *)(lVar13 + 0xc + (longlong)puVar15);

            fVar22 = (float)((uVar4 & 0xffc00) +

                             (uVar2 & 0xffc00) + (uVar1 & 0xffc00) + (uVar3 & 0xffc00) >> 0xc);

            fVar21 = (float)((uVar4 & 0x3ff) + (uVar2 & 0x3ff) + (uVar1 & 0x3ff) + (uVar3 & 0x3ff)

                            >> 2);

            fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) + (uVar3 & 0x3ff00000) +

                             (uVar4 & 0x3ff00000) >> 0x16);

            psVar18[4] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            psVar18[5] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            uVar1 = *(uint *)(lVar13 + 0x18 + (longlong)puVar15);

            uVar2 = *(uint *)(lVar13 + 0x14 + (longlong)puVar15);

            uVar3 = puVar15[5];

            uVar4 = puVar15[6];

            fVar22 = (float)((uVar2 & 0xffc00) +

                             (uVar4 & 0xffc00) + (uVar3 & 0xffc00) + (uVar1 & 0xffc00) >> 0xc);

            fVar21 = (float)((uVar2 & 0x3ff) + (uVar4 & 0x3ff) + (uVar3 & 0x3ff) + (uVar1 & 0x3ff)

                            >> 2);

            fVar20 = (float)((uVar2 & 0x3ff00000) + (uVar1 & 0x3ff00000) + (uVar4 & 0x3ff00000) +

                             (uVar3 & 0x3ff00000) >> 0x16);

            puVar15 = puVar15 + 8;

            psVar18[6] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                      fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                      fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                         0x40 + -0x8000;

            iVar8 = (int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                          fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                          fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

            sVar6 = (short)iVar8 * 0x40 + -0x8000;

            uVar19 = (ulonglong)CONCAT22((short)((uint)iVar8 >> 0x10),sVar6);

            psVar18[7] = sVar6;

            psVar18 = psVar18 + 8;

            lVar17 = lVar17 + -1;

          } while (lVar17 != 0);

        }

        if (lVar14 < iVar7) {

          puVar15 = (uint *)(lVar14 * 8 + 4 + lVar12);

          lVar13 = iVar7 - lVar14;

          lVar14 = lVar14 + lVar13;

          do {

            uVar1 = *(uint *)((longlong)puVar15 + (param_3 - lVar12) + -4);

            uVar2 = puVar15[-1];

            uVar3 = *(uint *)((longlong)puVar15 + (param_3 - lVar12));

            uVar4 = *puVar15;

            puVar15 = puVar15 + 2;

            fVar22 = (float)((uVar4 & 0xffc00) +

                             (uVar2 & 0xffc00) + (uVar1 & 0xffc00) + (uVar3 & 0xffc00) >> 0xc);

            fVar21 = (float)((uVar4 & 0x3ff) + (uVar2 & 0x3ff) + (uVar1 & 0x3ff) + (uVar3 & 0x3ff)

                            >> 2);

            fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) + (uVar3 & 0x3ff00000) +

                             (uVar4 & 0x3ff00000) >> 0x16);

            *psVar18 = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

            iVar8 = (int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                          fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                          fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

            sVar6 = (short)iVar8 * 0x40 + -0x8000;

            uVar19 = (ulonglong)CONCAT22((short)((uint)iVar8 >> 0x10),sVar6);

            psVar18[1] = sVar6;

            psVar18 = psVar18 + 2;

            lVar13 = lVar13 + -1;

          } while (lVar13 != 0);

        }

        if ((param_1 & 1) != 0) {

          uVar1 = *(uint *)(param_3 + lVar14 * 8);

          uVar2 = *(uint *)(lVar12 + lVar14 * 8);

          fVar22 = (float)((uVar1 & 0xffc00) + (uVar2 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar1 & 0x3ff) + (uVar2 & 0x3ff) >> 1);

          fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) >> 0x15);

          *psVar18 = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                  fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                  fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                     0x40 + -0x8000;

          iVar8 = (int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                        fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                        fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

          sVar6 = (short)iVar8 * 0x40 + -0x8000;

          uVar19 = (ulonglong)CONCAT22((short)((uint)iVar8 >> 0x10),sVar6);

          psVar18[1] = sVar6;

          psVar18 = psVar18 + 2;

        }

        psVar18 = psVar18 + uVar10;

        param_3 = param_3 + local_78;

        lVar12 = lVar12 + local_78;

        local_80 = local_80 - 1;

      } while (local_80 != 0);

    }

    lVar12 = (longlong)iVar7;

    uVar10 = 0;

    if (local_74 != 0) {

      uVar16 = uVar10;

      if (3 < lVar12) {

        puVar15 = (uint *)(param_3 + 8);

        lVar14 = (lVar12 - 4U >> 2) + 1;

        uVar10 = (ulonglong)(uint)((int)lVar14 * 4);

        uVar16 = lVar14 * 4;

        do {

          uVar1 = puVar15[-2];

          uVar2 = puVar15[-1];

          fVar22 = (float)((uVar2 & 0xffc00) + (uVar1 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar2 & 0x3ff) + (uVar1 & 0x3ff) >> 1);

          fVar20 = (float)((uVar2 & 0x3ff00000) + (uVar1 & 0x3ff00000) >> 0x15);

          *psVar18 = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                  fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                  fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                     0x40 + -0x8000;

          psVar18[1] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          uVar1 = *puVar15;

          uVar2 = puVar15[1];

          fVar22 = (float)((uVar1 & 0xffc00) + (uVar2 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar1 & 0x3ff) + (uVar2 & 0x3ff) >> 1);

          fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) >> 0x15);

          psVar18[2] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          psVar18[3] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          uVar1 = puVar15[2];

          uVar2 = puVar15[3];

          fVar22 = (float)((uVar1 & 0xffc00) + (uVar2 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar1 & 0x3ff) + (uVar2 & 0x3ff) >> 1);

          fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) >> 0x15);

          psVar18[4] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          psVar18[5] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          uVar1 = puVar15[4];

          uVar2 = puVar15[5];

          fVar22 = (float)((uVar1 & 0xffc00) + (uVar2 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar1 & 0x3ff) + (uVar2 & 0x3ff) >> 1);

          puVar15 = puVar15 + 8;

          fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) >> 0x15);

          psVar18[6] = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                    fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                    fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                       0x40 + -0x8000;

          iVar8 = (int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                        fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                        fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

          sVar6 = (short)iVar8 * 0x40 + -0x8000;

          uVar19 = (ulonglong)CONCAT22((short)((uint)iVar8 >> 0x10),sVar6);

          psVar18[7] = sVar6;

          psVar18 = psVar18 + 8;

          lVar14 = lVar14 + -1;

        } while (lVar14 != 0);

      }

      iVar8 = (int)uVar10;

      if ((longlong)uVar16 < lVar12) {

        iVar8 = iVar8 + (iVar7 - (int)uVar16);

        do {

          uVar1 = *(uint *)(param_3 + uVar16 * 8);

          uVar2 = *(uint *)(param_3 + 4 + uVar16 * 8);

          uVar16 = uVar16 + 1;

          fVar22 = (float)((uVar1 & 0xffc00) + (uVar2 & 0xffc00) >> 0xb);

          fVar21 = (float)((uVar1 & 0x3ff) + (uVar2 & 0x3ff) >> 1);

          fVar20 = (float)((uVar1 & 0x3ff00000) + (uVar2 & 0x3ff00000) >> 0x15);

          *psVar18 = (short)(int)(fVar21 * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28) +

                                  fVar22 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                  fVar20 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                     0x40 + -0x8000;

          iVar7 = (int)(fVar21 * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                        fVar22 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                        fVar20 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

          sVar6 = (short)iVar7 * 0x40 + -0x8000;

          uVar19 = (ulonglong)CONCAT22((short)((uint)iVar7 >> 0x10),sVar6);

          psVar18[1] = sVar6;

          psVar18 = psVar18 + 2;

        } while ((longlong)uVar16 < lVar12);

      }

      if ((param_1 & 1) != 0) {

        uVar1 = *(uint *)(param_3 + (longlong)(iVar8 * 2) * 4);

        fVar21 = (float)(uVar1 >> 0x14 & 0x3ff);

        fVar20 = (float)(uVar1 >> 10 & 0x3ff);

        *psVar18 = (short)(int)(fVar20 * *(float *)(&DAT_1403e4ab4 + lVar11 * 0x28) +

                                (float)(uVar1 & 0x3ff) * *(float *)(&DAT_1403e4ab0 + lVar11 * 0x28)

                                + fVar21 * *(float *)(&DAT_1403e4ab8 + lVar11 * 0x28) + fVar5) *

                   0x40 + -0x8000;

        iVar7 = (int)(fVar20 * *(float *)(&DAT_1403e4ac0 + lVar11 * 0x28) +

                      (float)(uVar1 & 0x3ff) * *(float *)(&DAT_1403e4abc + lVar11 * 0x28) +

                      fVar21 * *(float *)(&DAT_1403e4ac4 + lVar11 * 0x28) + fVar5);

        sVar6 = (short)iVar7 * 0x40 + -0x8000;

        uVar19 = (ulonglong)CONCAT22((short)((uint)iVar7 >> 0x10),sVar6);

        psVar18[1] = sVar6;

      }

    }

    return CONCAT71((int7)(uVar19 >> 8),1);

  }

  return uVar9;

}





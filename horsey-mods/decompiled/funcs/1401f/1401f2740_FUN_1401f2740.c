// Address: 0x1401f2740
// Ghidra name: FUN_1401f2740
// ============ 0x1401f2740 FUN_1401f2740 (size=2616) ============


undefined8

FUN_1401f2740(longlong param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  float fVar1;

  byte bVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  bool bVar7;

  float *pfVar8;

  longlong lVar9;

  float *pfVar10;

  float *pfVar11;

  ulonglong uVar12;

  uint *puVar13;

  int iVar14;

  longlong lVar15;

  uint uVar16;

  ushort *puVar17;

  uint uVar18;

  longlong lVar19;

  ulonglong uVar20;

  float local_58;

  float fStack_50;

  

  if ((*(int **)(param_1 + 0x1f0) == (int *)0x0) ||

     ((iVar14 = **(int **)(param_1 + 0x1f0), iVar14 != 0x16362004 && (iVar14 != 0x16161804)))) {

    bVar7 = false;

  }

  else {

    bVar7 = true;

  }

  fVar1 = *(float *)(param_2 + 0x18);

  if (param_11 != 0) {

    param_10 = param_12;

  }

  uVar12 = 0;

  lVar19 = (longlong)param_10;

  iVar14 = 0;

  if (param_11 != 0) {

    iVar14 = param_13;

  }

  *(longlong *)(param_2 + 0x10) = lVar19;

  if (param_3 == 0) {

    pfVar8 = (float *)FUN_14014b940(param_1,lVar19 * 0x18,0,param_2 + 8);

    if (pfVar8 == (float *)0x0) {

      return 0;

    }

    if (0 < param_10) {

      if (iVar14 == 1) {

        pfVar8 = pfVar8 + 2;

        do {

          lVar9 = (longlong)(int)((uint)*(byte *)(param_11 + uVar12) * param_5);

          pfVar11 = (float *)((int)((uint)*(byte *)(param_11 + uVar12) * param_7) + param_6);

          fVar3 = *pfVar11;

          fVar4 = pfVar11[1];

          fVar5 = pfVar11[2];

          fVar6 = pfVar11[3];

          pfVar8[-2] = param_14 * *(float *)(lVar9 + param_4);

          pfVar8[-1] = param_15 * *(float *)(lVar9 + 4 + param_4);

          local_58 = fVar3 * fVar1;

          fStack_50 = fVar5 * fVar1;

          if (bVar7) {

            local_58 = fVar5 * fVar1;

            fStack_50 = fVar3 * fVar1;

          }

          uVar12 = uVar12 + 1;

          *(ulonglong *)pfVar8 = CONCAT44(fVar4 * fVar1,local_58);

          *(ulonglong *)(pfVar8 + 2) = CONCAT44(fVar6,fStack_50);

          pfVar8 = pfVar8 + 6;

        } while ((longlong)uVar12 < lVar19);

      }

      else {

        uVar20 = uVar12;

        if (3 < lVar19) {

          puVar17 = (ushort *)(param_11 + 4);

          uVar18 = 2;

          puVar13 = (uint *)(param_11 + 8);

          pfVar11 = pfVar8 + 2;

          lVar9 = (lVar19 - 4U >> 2) + 1;

          uVar20 = lVar9 * 4;

          do {

            if (iVar14 == 4) {

              uVar16 = puVar13[-2];

            }

            else {

              uVar16 = (uint)uVar12;

              if (iVar14 == 2) {

                uVar16 = (uint)puVar17[-2];

              }

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            *pfVar8 = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[-1] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)pfVar11 = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 2) = CONCAT44(fVar6,fStack_50);

            if (iVar14 == 4) {

              uVar16 = puVar13[-1];

            }

            else if (iVar14 == 2) {

              uVar16 = (uint)puVar17[-1];

            }

            else {

              uVar16 = uVar18 - 1;

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar11[4] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[5] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)(pfVar11 + 6) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 8) = CONCAT44(fVar6,fStack_50);

            if (iVar14 == 4) {

              uVar16 = *puVar13;

            }

            else {

              uVar16 = uVar18;

              if (iVar14 == 2) {

                uVar16 = (uint)*puVar17;

              }

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar11[10] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[0xb] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)(pfVar11 + 0xc) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 0xe) = CONCAT44(fVar6,fStack_50);

            if (iVar14 == 4) {

              uVar16 = puVar13[1];

            }

            else if (iVar14 == 2) {

              uVar16 = (uint)puVar17[1];

            }

            else {

              uVar16 = uVar18 + 1;

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar11[0x10] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[0x11] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            pfVar8 = pfVar8 + 0x18;

            uVar12 = (ulonglong)((uint)uVar12 + 4);

            uVar18 = uVar18 + 4;

            *(ulonglong *)(pfVar11 + 0x12) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 0x14) = CONCAT44(fVar6,fStack_50);

            pfVar11 = pfVar11 + 0x18;

            puVar13 = puVar13 + 4;

            puVar17 = puVar17 + 4;

            lVar9 = lVar9 + -1;

          } while (lVar9 != 0);

        }

        if ((longlong)uVar20 < lVar19) {

          pfVar8 = pfVar8 + 2;

          do {

            if (iVar14 == 4) {

              uVar18 = *(uint *)(param_11 + uVar20 * 4);

            }

            else {

              uVar18 = (uint)uVar12;

              if (iVar14 == 2) {

                uVar18 = (uint)*(ushort *)(param_11 + uVar20 * 2);

              }

            }

            pfVar11 = (float *)((int)(uVar18 * param_7) + param_6);

            fVar3 = *pfVar11;

            fVar4 = pfVar11[1];

            fVar5 = pfVar11[2];

            fVar6 = pfVar11[3];

            pfVar8[-2] = param_14 * *(float *)((int)(uVar18 * param_5) + param_4);

            pfVar8[-1] = param_15 * *(float *)((longlong)(int)(uVar18 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            uVar12 = (ulonglong)((uint)uVar12 + 1);

            uVar20 = uVar20 + 1;

            *(ulonglong *)pfVar8 = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar8 + 2) = CONCAT44(fVar6,fStack_50);

            pfVar8 = pfVar8 + 6;

          } while ((longlong)uVar20 < lVar19);

        }

      }

    }

  }

  else {

    pfVar8 = (float *)FUN_14014b940(param_1,lVar19 << 5,0,param_2 + 8);

    if (pfVar8 == (float *)0x0) {

      return 0;

    }

    if (0 < param_10) {

      if (iVar14 == 1) {

        pfVar8 = pfVar8 + 2;

        do {

          bVar2 = *(byte *)(param_11 + uVar12);

          lVar15 = (longlong)(int)((uint)bVar2 * param_5);

          pfVar11 = (float *)((int)((uint)bVar2 * param_7) + param_6);

          fVar3 = *pfVar11;

          fVar4 = pfVar11[1];

          fVar5 = pfVar11[2];

          fVar6 = pfVar11[3];

          lVar9 = (longlong)(int)((uint)bVar2 * param_9);

          pfVar8[-2] = param_14 * *(float *)(lVar15 + param_4);

          pfVar8[-1] = param_15 * *(float *)(lVar15 + 4 + param_4);

          local_58 = fVar3 * fVar1;

          fStack_50 = fVar5 * fVar1;

          if (bVar7) {

            local_58 = fVar5 * fVar1;

            fStack_50 = fVar3 * fVar1;

          }

          uVar12 = uVar12 + 1;

          *(ulonglong *)pfVar8 = CONCAT44(fVar4 * fVar1,local_58);

          *(ulonglong *)(pfVar8 + 2) = CONCAT44(fVar6,fStack_50);

          pfVar8[4] = *(float *)(lVar9 + param_8);

          pfVar8[5] = *(float *)(lVar9 + 4 + param_8);

          pfVar8 = pfVar8 + 8;

        } while ((longlong)uVar12 < lVar19);

      }

      else {

        uVar20 = uVar12;

        if (3 < lVar19) {

          puVar17 = (ushort *)(param_11 + 4);

          uVar18 = 2;

          puVar13 = (uint *)(param_11 + 8);

          pfVar11 = pfVar8 + 2;

          lVar9 = (lVar19 - 4U >> 2) + 1;

          uVar20 = lVar9 * 4;

          do {

            if (iVar14 == 4) {

              uVar16 = puVar13[-2];

            }

            else {

              uVar16 = (uint)uVar12;

              if (iVar14 == 2) {

                uVar16 = (uint)puVar17[-2];

              }

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar10 = (float *)((int)(uVar16 * param_9) + param_8);

            *pfVar8 = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[-1] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)pfVar11 = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 2) = CONCAT44(fVar6,fStack_50);

            pfVar11[4] = *pfVar10;

            pfVar11[5] = pfVar10[1];

            if (iVar14 == 4) {

              uVar16 = puVar13[-1];

            }

            else if (iVar14 == 2) {

              uVar16 = (uint)puVar17[-1];

            }

            else {

              uVar16 = uVar18 - 1;

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar10 = (float *)((int)(uVar16 * param_9) + param_8);

            pfVar11[6] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[7] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)(pfVar11 + 8) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 10) = CONCAT44(fVar6,fStack_50);

            pfVar11[0xc] = *pfVar10;

            pfVar11[0xd] = pfVar10[1];

            if (iVar14 == 4) {

              uVar16 = *puVar13;

            }

            else {

              uVar16 = uVar18;

              if (iVar14 == 2) {

                uVar16 = (uint)*puVar17;

              }

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar10 = (float *)((int)(uVar16 * param_9) + param_8);

            pfVar11[0xe] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[0xf] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            *(ulonglong *)(pfVar11 + 0x10) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 0x12) = CONCAT44(fVar6,fStack_50);

            pfVar11[0x14] = *pfVar10;

            pfVar11[0x15] = pfVar10[1];

            if (iVar14 == 4) {

              uVar16 = puVar13[1];

            }

            else if (iVar14 == 2) {

              uVar16 = (uint)puVar17[1];

            }

            else {

              uVar16 = uVar18 + 1;

            }

            pfVar10 = (float *)((int)(uVar16 * param_7) + param_6);

            fVar3 = *pfVar10;

            fVar4 = pfVar10[1];

            fVar5 = pfVar10[2];

            fVar6 = pfVar10[3];

            pfVar10 = (float *)((int)(uVar16 * param_9) + param_8);

            pfVar11[0x16] = param_14 * *(float *)((int)(uVar16 * param_5) + param_4);

            pfVar11[0x17] = param_15 * *(float *)((longlong)(int)(uVar16 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            uVar12 = (ulonglong)((uint)uVar12 + 4);

            uVar18 = uVar18 + 4;

            pfVar8 = pfVar8 + 0x20;

            *(ulonglong *)(pfVar11 + 0x18) = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar11 + 0x1a) = CONCAT44(fVar6,fStack_50);

            puVar13 = puVar13 + 4;

            pfVar11[0x1c] = *pfVar10;

            puVar17 = puVar17 + 4;

            pfVar11[0x1d] = pfVar10[1];

            pfVar11 = pfVar11 + 0x20;

            lVar9 = lVar9 + -1;

          } while (lVar9 != 0);

        }

        if ((longlong)uVar20 < lVar19) {

          pfVar8 = pfVar8 + 2;

          do {

            if (iVar14 == 4) {

              uVar18 = *(uint *)(param_11 + uVar20 * 4);

            }

            else {

              uVar18 = (uint)uVar12;

              if (iVar14 == 2) {

                uVar18 = (uint)*(ushort *)(param_11 + uVar20 * 2);

              }

            }

            pfVar11 = (float *)((int)(uVar18 * param_7) + param_6);

            fVar3 = *pfVar11;

            fVar4 = pfVar11[1];

            fVar5 = pfVar11[2];

            fVar6 = pfVar11[3];

            pfVar8[-2] = param_14 * *(float *)((int)(uVar18 * param_5) + param_4);

            pfVar8[-1] = param_15 * *(float *)((longlong)(int)(uVar18 * param_5) + 4 + param_4);

            local_58 = fVar3 * fVar1;

            fStack_50 = fVar5 * fVar1;

            if (bVar7) {

              local_58 = fVar5 * fVar1;

              fStack_50 = fVar3 * fVar1;

            }

            uVar12 = (ulonglong)((uint)uVar12 + 1);

            uVar20 = uVar20 + 1;

            *(ulonglong *)pfVar8 = CONCAT44(fVar4 * fVar1,local_58);

            *(ulonglong *)(pfVar8 + 2) = CONCAT44(fVar6,fStack_50);

            pfVar8[4] = *(float *)((int)(uVar18 * param_9) + param_8);

            pfVar8[5] = *(float *)((longlong)(int)(uVar18 * param_9) + 4 + param_8);

            pfVar8 = pfVar8 + 8;

          } while ((longlong)uVar20 < lVar19);

        }

      }

    }

  }

  return 1;

}





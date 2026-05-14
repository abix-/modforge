// Address: 0x140044140
// Ghidra name: FUN_140044140
// ============ 0x140044140 FUN_140044140 (size=1687) ============


/* WARNING: Type propagation algorithm not settling */



int * FUN_140044140(int *param_1,ulonglong param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  ushort uVar2;

  short sVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  undefined4 *puVar7;

  longlong lVar8;

  uint uVar9;

  uint uVar10;

  int *piVar11;

  undefined4 *puVar12;

  int iVar13;

  code *pcVar14;

  longlong lVar15;

  int iVar16;

  int iVar17;

  ulonglong uVar18;

  undefined4 uVar19;

  undefined4 uVar20;

  undefined4 uVar21;

  undefined4 uVar22;

  undefined4 uVar23;

  undefined4 uVar24;

  

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0;

  }

  if (param_1 == (int *)0x0) {

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = 1;

    }

  }

  else if (((param_2 < 0xc) || (*param_1 != 0x46464952)) || (param_1[2] != 0x45564157)) {

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = 5;

    }

  }

  else {

    for (piVar11 = param_1 + 3; 7 < (longlong)((longlong)param_1 + (param_2 - (longlong)piVar11));

        piVar11 = (int *)((longlong)piVar11 + ((ulonglong)(uVar9 + 1) & 0xfffffffe) + 8)) {

      uVar9 = piVar11[1];

      if (*piVar11 == 0x20746d66) {

        lVar15 = (longlong)param_1 + (param_2 - (longlong)piVar11);

        if (((longlong)(ulonglong)(uVar9 + 8) <= lVar15) && (0xf < uVar9)) {

          uVar2 = *(ushort *)((longlong)piVar11 + 10);

          iVar5 = piVar11[3];

          sVar3 = *(short *)((longlong)piVar11 + 0x16);

          uVar9 = (uint)uVar2;

          if ((uVar9 != 1) && (uVar9 != 2)) {

            if (param_3 == (undefined4 *)0x0) {

              return (int *)0x0;

            }

            *param_3 = 8;

            return (int *)0x0;

          }

          iVar13 = 2;

          iVar17 = 4;

          if ((short)piVar11[2] == 1) {

            if (sVar3 == 8) {

              pcVar14 = (code *)&LAB_140046090;

              iVar16 = 1;

              goto joined_r0x00014004433f;

            }

            if (sVar3 == 0x10) {

              pcVar14 = (code *)&LAB_1400460c0;

              iVar16 = 2;

              goto joined_r0x00014004433f;

            }

            if (sVar3 == 0x18) {

              pcVar14 = (code *)&LAB_1400460e0;

              iVar16 = 3;

              goto joined_r0x00014004433f;

            }

            if (sVar3 != 0x20) goto LAB_1400447c2;

            pcVar14 = FUN_140046130;

          }

          else {

            if ((short)piVar11[2] != 3) {

LAB_1400447c2:

              if (param_3 == (undefined4 *)0x0) {

                return (int *)0x0;

              }

              *param_3 = 9;

              return (int *)0x0;

            }

            if (sVar3 != 0x20) {

              if (sVar3 != 0x40) goto LAB_1400447c2;

              pcVar14 = (code *)&LAB_140046170;

              iVar16 = 8;

              goto joined_r0x00014004433f;

            }

            pcVar14 = (code *)&LAB_140046150;

          }

          iVar16 = 4;

          goto joined_r0x00014004433f;

        }

        break;

      }

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = 6;

    }

  }

  return (int *)0x0;

joined_r0x00014004433f:

  if (lVar15 < 8) {

LAB_140044367:

    if (param_3 == (undefined4 *)0x0) {

      return (int *)0x0;

    }

    *param_3 = 7;

    return (int *)0x0;

  }

  uVar4 = piVar11[1];

  if (*piVar11 == 0x61746164) {

    piVar11 = piVar11 + 2;

    if ((longlong)(ulonglong)uVar4 <= (longlong)((longlong)param_1 + (param_2 - (longlong)piVar11)))

    {

      piVar6 = (int *)_malloc_base(0x20);

      piVar6[3] = 0;

      *piVar6 = iVar5;

      piVar6[2] = uVar9;

      uVar4 = uVar4 / (uVar9 * iVar16);

      piVar6[1] = uVar4;

      uVar10 = uVar4 & 3;

      iVar5 = (int)((uVar4 + 3 & 0xfffffffc) + ((int)(uVar4 + 3) >> 0x1f & 3U)) >> 2;

      lVar15 = (longlong)iVar5 * 0x10;

      uVar9 = iVar5 - 1;

      uVar18 = (ulonglong)uVar9;

      if (uVar2 == 1) {

        puVar7 = (undefined4 *)FUN_14004a210(lVar15);

        *(undefined4 **)(piVar6 + 4) = puVar7;

        piVar6[6] = 0;

        piVar6[7] = 0;

        if (0 < (int)uVar9) {

          uVar18 = (ulonglong)uVar9;

          puVar12 = puVar7;

          do {

            uVar19 = (*pcVar14)(piVar11,iVar13 + -2,1);

            uVar20 = (*pcVar14)(piVar11,iVar13 + -1,1);

            uVar21 = (*pcVar14)(piVar11,iVar13,1);

            uVar22 = (*pcVar14)(piVar11,iVar13 + 1,1);

            iVar13 = iVar13 + 4;

            *puVar12 = uVar19;

            puVar12[1] = uVar20;

            puVar12[2] = uVar21;

            puVar12[3] = uVar22;

            uVar18 = uVar18 - 1;

            puVar12 = puVar12 + 4;

          } while (uVar18 != 0);

        }

        iVar5 = iVar5 * 4;

        uVar22 = (*pcVar14)(piVar11,iVar5 + -4,1);

        if (uVar10 < 2) {

          uVar23 = 0;

        }

        else {

          uVar23 = (*pcVar14)(piVar11,iVar5 + -3,1);

        }

        if (uVar10 < 3) {

          uVar24 = 0;

        }

        else {

          uVar24 = (*pcVar14)(piVar11,iVar5 + -2,1);

        }

      }

      else {

        lVar8 = FUN_14004a210((longlong)iVar5 << 5);

        puVar7 = (undefined4 *)(lVar15 + lVar8);

        if (0 < (int)uVar9) {

          puVar12 = puVar7;

          do {

            uVar19 = (*pcVar14)(piVar11,iVar17 + -4,1);

            uVar20 = (*pcVar14)(piVar11,iVar17 + -2,1);

            uVar21 = (*pcVar14)(piVar11,iVar17,1);

            uVar22 = (*pcVar14)(piVar11,iVar17 + 2,1);

            puVar1 = (undefined4 *)((lVar8 - (longlong)puVar7) + (longlong)puVar12);

            *puVar1 = uVar19;

            puVar1[1] = uVar20;

            puVar1[2] = uVar21;

            puVar1[3] = uVar22;

            uVar19 = (*pcVar14)(piVar11,iVar17 + -3,1);

            uVar20 = (*pcVar14)(piVar11,iVar17 + -1,1);

            uVar21 = (*pcVar14)(piVar11,iVar17 + 1,1);

            uVar22 = (*pcVar14)(piVar11,iVar17 + 3,1);

            iVar17 = iVar17 + 8;

            *puVar12 = uVar19;

            puVar12[1] = uVar20;

            puVar12[2] = uVar21;

            puVar12[3] = uVar22;

            uVar18 = uVar18 - 1;

            puVar12 = puVar12 + 4;

          } while (uVar18 != 0);

        }

        iVar5 = iVar5 * 8;

        uVar19 = (*pcVar14)(piVar11,iVar5 + -8,1);

        if (uVar10 < 2) {

          uVar20 = 0;

        }

        else {

          uVar20 = (*pcVar14)(piVar11,iVar5 + -6,1);

        }

        if (uVar10 < 3) {

          uVar21 = 0;

        }

        else {

          uVar21 = (*pcVar14)(piVar11,iVar5 + -4,1);

        }

        uVar22 = (*pcVar14)(piVar11,iVar5 + -7,1);

        if (uVar10 < 2) {

          uVar23 = 0;

        }

        else {

          uVar23 = (*pcVar14)(piVar11,iVar5 + -5,1);

        }

        if (uVar10 < 3) {

          uVar24 = 0;

        }

        else {

          uVar24 = (*pcVar14)(piVar11,iVar5 + -3,1);

        }

        FUN_14004a120(lVar8,uVar9,uVar19,uVar20,uVar21,0,uVar10);

        *(longlong *)(piVar6 + 4) = lVar8;

        *(undefined4 **)(piVar6 + 6) = puVar7;

      }

      FUN_14004a120(puVar7,uVar9,uVar22,uVar23,uVar24,0,uVar10);

      return piVar6;

    }

    goto LAB_140044367;

  }

  piVar11 = (int *)((longlong)piVar11 + ((ulonglong)(uVar4 + 1) & 0xfffffffe) + 8);

  lVar15 = (longlong)param_1 + (param_2 - (longlong)piVar11);

  goto joined_r0x00014004433f;

}





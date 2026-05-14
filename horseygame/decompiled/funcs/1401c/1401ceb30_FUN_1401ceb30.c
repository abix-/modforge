// Address: 0x1401ceb30
// Ghidra name: FUN_1401ceb30
// ============ 0x1401ceb30 FUN_1401ceb30 (size=1637) ============


undefined8 FUN_1401ceb30(longlong param_1)



{

  uint uVar1;

  longlong lVar2;

  longlong lVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  undefined4 *puVar8;

  longlong lVar9;

  undefined4 *puVar10;

  ulonglong uVar11;

  uint uVar12;

  longlong lVar13;

  ulonglong uVar14;

  undefined4 *puVar15;

  int iVar16;

  ulonglong uVar17;

  longlong lVar18;

  int iVar19;

  int iVar20;

  ulonglong uVar21;

  uint local_res18;

  ulonglong local_90;

  code *local_88;

  code *local_80;

  undefined4 *local_78;

  ulonglong local_68;

  

  lVar18 = *(longlong *)(param_1 + 0xb8);

  if ((lVar18 != 0) &&

     (lVar2 = *(longlong *)(lVar18 + 0x38), *(char *)(*(longlong *)(param_1 + 0x38) + 4) == ' ')) {

    uVar7 = *(uint *)(lVar2 + 0x10);

    uVar12 = *(uint *)(lVar2 + 0xc);

    uVar1 = *(uint *)(lVar2 + 8);

    uVar4 = uVar7 | uVar12 | uVar1;

    if (*(char *)(lVar2 + 5) == '\x02') {

      if (uVar4 == 0x7fff) {

        if (((uVar12 != 0x3e0) && (uVar1 != 0x3e0)) && (uVar7 != 0x3e0)) {

          return 0;

        }

        local_80 = FUN_1401d2e70;

      }

      else {

        if (uVar4 != 0xffff) {

          return 0;

        }

        if (((uVar12 != 0x7e0) && (uVar1 != 0x7e0)) && (uVar7 != 0x7e0)) {

          return 0;

        }

        local_80 = FUN_1401d2f80;

      }

      local_88 = FUN_1401d2d50;

      iVar5 = (*(int *)(param_1 + 8) * 6 + 8) * *(int *)(param_1 + 0xc) + 6;

    }

    else {

      if (*(char *)(lVar2 + 5) != '\x04') {

        return 0;

      }

      if (uVar4 != 0xffffff) {

        return 0;

      }

      local_88 = FUN_1401d2c70;

      local_80 = FUN_1401d2c70;

      iVar5 = (*(int *)(param_1 + 8) + 1) * *(int *)(param_1 + 0xc) * 8 + 8;

    }

    puVar8 = (undefined4 *)FUN_1401841f0((longlong)iVar5);

    if (puVar8 != (undefined4 *)0x0) {

      *puVar8 = *(undefined4 *)(lVar18 + 4);

      puVar10 = puVar8 + 1;

      iVar5 = *(int *)(param_1 + 8);

      lVar13 = (longlong)iVar5;

      local_68 = (ulonglong)*(uint *)(param_1 + 0xc);

      lVar3 = *(longlong *)(param_1 + 0x38);

      lVar18 = *(longlong *)(param_1 + 0x18);

      puVar15 = puVar10;

      local_78 = puVar10;

      if (0 < (int)*(uint *)(param_1 + 0xc)) {

        do {

          uVar14 = 0;

          local_res18 = 0;

          local_90 = 0;

          uVar17 = uVar14;

          uVar11 = uVar14;

          do {

            uVar21 = uVar11;

            if ((longlong)uVar17 < lVar13) {

              do {

                if ((*(uint *)(lVar18 + uVar17 * 4) & *(uint *)(lVar3 + 0x14)) >>

                    (*(byte *)(lVar3 + 0x1f) & 0x1f) == 0xff) break;

                uVar21 = (ulonglong)((int)uVar21 + 1);

                uVar17 = uVar17 + 1;

              } while ((longlong)uVar17 < lVar13);

              local_res18 = (uint)uVar21;

              local_90 = uVar17;

            }

            iVar20 = (int)uVar21;

            if ((longlong)uVar17 < lVar13) {

              do {

                if ((*(uint *)(lVar18 + uVar17 * 4) & *(uint *)(lVar3 + 0x14)) >>

                    (*(byte *)(lVar3 + 0x1f) & 0x1f) != 0xff) break;

                uVar21 = (ulonglong)((int)uVar21 + 1);

                uVar17 = uVar17 + 1;

              } while ((longlong)uVar17 < lVar13);

              local_res18 = (uint)uVar21;

              local_90 = uVar17;

            }

            iVar19 = iVar20 - (int)uVar11;

            uVar7 = (uint)uVar14;

            if (iVar19 == iVar5) {

              uVar7 = 1;

            }

            iVar16 = (int)uVar21 - iVar20;

            if (0xff < iVar19) {

              uVar12 = (iVar19 - 0x100U) / 0xff + 1;

              uVar11 = (ulonglong)uVar12;

              iVar19 = iVar19 + uVar12 * -0xff;

              do {

                if (*(char *)(lVar2 + 5) == '\x04') {

                  *puVar15 = 0xff;

                  lVar9 = 4;

                }

                else {

                  *(undefined2 *)puVar15 = 0xff;

                  lVar9 = 2;

                }

                puVar15 = (undefined4 *)((longlong)puVar15 + lVar9);

                uVar11 = uVar11 - 1;

              } while (uVar11 != 0);

            }

            iVar6 = 0xff;

            if (iVar16 < 0xff) {

              iVar6 = iVar16;

            }

            if (*(char *)(lVar2 + 5) == '\x04') {

              *(short *)puVar15 = (short)iVar19;

              lVar9 = 4;

              *(short *)((longlong)puVar15 + 2) = (short)iVar6;

            }

            else {

              *(char *)puVar15 = (char)iVar19;

              lVar9 = 2;

              *(char *)((longlong)puVar15 + 1) = (char)iVar6;

            }

            iVar19 = (*local_88)((undefined1 *)(lVar9 + (longlong)puVar15),

                                 lVar18 + (longlong)iVar20 * 4,iVar6,lVar3,lVar2);

            iVar20 = iVar20 + iVar6;

            puVar15 = (undefined4 *)((longlong)puVar15 + iVar19 + lVar9);

            iVar16 = iVar16 - iVar6;

            if (iVar16 != 0) {

              do {

                iVar19 = 0xff;

                if (iVar16 < 0xff) {

                  iVar19 = iVar16;

                }

                if (*(char *)(lVar2 + 5) == '\x04') {

                  *(short *)((longlong)puVar15 + 2) = (short)iVar19;

                  *(undefined2 *)puVar15 = 0;

                  lVar9 = 4;

                }

                else {

                  *(undefined1 *)puVar15 = 0;

                  lVar9 = 2;

                  *(char *)((longlong)puVar15 + 1) = (char)iVar19;

                }

                iVar6 = (*local_88)((undefined1 *)(lVar9 + (longlong)puVar15),

                                    (longlong)iVar20 * 4 + lVar18,iVar19,lVar3,lVar2);

                iVar20 = iVar20 + iVar19;

                puVar15 = (undefined4 *)((longlong)puVar15 + iVar6 + lVar9);

                iVar16 = iVar16 - iVar19;

              } while (iVar16 != 0);

              uVar21 = (ulonglong)local_res18;

              uVar17 = local_90;

            }

            uVar14 = (ulonglong)uVar7;

            uVar11 = uVar21;

          } while ((longlong)uVar17 < lVar13);

          puVar15 = (undefined4 *)((longlong)puVar15 + (ulonglong)((uint)puVar15 & 2));

          uVar17 = 0;

          local_res18 = 0;

          local_90 = 0;

          uVar11 = uVar17;

          do {

            uVar14 = uVar11;

            if ((longlong)uVar17 < lVar13) {

              do {

                if (((*(uint *)(lVar18 + uVar17 * 4) & *(uint *)(lVar3 + 0x14)) >>

                    (*(byte *)(lVar3 + 0x1f) & 0x1f)) - 1 < 0xfe) break;

                uVar14 = (ulonglong)((int)uVar14 + 1);

                uVar17 = uVar17 + 1;

              } while ((longlong)uVar17 < lVar13);

              local_res18 = (uint)uVar14;

              local_90 = uVar17;

            }

            iVar20 = (int)uVar14;

            if ((longlong)uVar17 < lVar13) {

              do {

                if (0xfd < ((*(uint *)(lVar18 + uVar17 * 4) & *(uint *)(lVar3 + 0x14)) >>

                           (*(byte *)(lVar3 + 0x1f) & 0x1f)) - 1) break;

                uVar14 = (ulonglong)((int)uVar14 + 1);

                uVar17 = uVar17 + 1;

              } while ((longlong)uVar17 < lVar13);

              local_res18 = (uint)uVar14;

              local_90 = uVar17;

            }

            iVar19 = iVar20 - (int)uVar11;

            iVar16 = (int)uVar14 - iVar20;

            uVar7 = iVar19 == iVar5 & uVar7;

            if (0xffff < iVar19) {

              uVar12 = (iVar19 - 0x10000U) / 0xffff + 1;

              uVar11 = (ulonglong)uVar12;

              iVar19 = iVar19 + uVar12 * -0xffff;

              do {

                *puVar15 = 0xffff;

                puVar15 = puVar15 + 1;

                uVar11 = uVar11 - 1;

              } while (uVar11 != 0);

            }

            *(short *)puVar15 = (short)iVar19;

            iVar19 = 0xffff;

            if (iVar16 < 0xffff) {

              iVar19 = iVar16;

            }

            *(short *)((longlong)puVar15 + 2) = (short)iVar19;

            iVar6 = (*local_80)(puVar15 + 1,lVar18 + (longlong)iVar20 * 4,iVar19,lVar3,lVar2);

            iVar20 = iVar20 + iVar19;

            puVar15 = (undefined4 *)((longlong)iVar6 + (longlong)(puVar15 + 1));

            iVar16 = iVar16 - iVar19;

            if (iVar16 != 0) {

              do {

                iVar19 = 0xffff;

                if (iVar16 < 0xffff) {

                  iVar19 = iVar16;

                }

                *(short *)((longlong)puVar15 + 2) = (short)iVar19;

                *(undefined2 *)puVar15 = 0;

                iVar6 = (*local_80)(puVar15 + 1,(longlong)iVar20 * 4 + lVar18,iVar19,lVar3,lVar2);

                iVar20 = iVar20 + iVar19;

                puVar15 = (undefined4 *)((longlong)iVar6 + (longlong)(puVar15 + 1));

                iVar16 = iVar16 - iVar19;

              } while (iVar16 != 0);

              uVar14 = (ulonglong)local_res18;

              uVar17 = local_90;

            }

            puVar10 = puVar15;

            if (uVar7 != 0) {

              puVar10 = local_78;

            }

            uVar11 = uVar14;

            local_78 = puVar10;

          } while ((longlong)uVar17 < lVar13);

          local_68 = local_68 - 1;

          lVar18 = lVar18 + ((longlong)*(int *)(param_1 + 0x10) >> 2) * 4;

        } while (local_68 != 0);

      }

      lVar18 = 4;

      if (*(char *)(lVar2 + 5) == '\x04') {

        *puVar10 = 0;

      }

      else {

        *(undefined2 *)puVar10 = 0;

        lVar18 = 2;

      }

      puVar10 = (undefined4 *)

                FUN_140184230(puVar8,(undefined1 *)((longlong)puVar10 + (lVar18 - (longlong)puVar8))

                             );

      if (puVar10 == (undefined4 *)0x0) {

        puVar10 = puVar8;

      }

      *(undefined4 **)(param_1 + 0x88) = puVar10;

      return 1;

    }

  }

  return 0;

}





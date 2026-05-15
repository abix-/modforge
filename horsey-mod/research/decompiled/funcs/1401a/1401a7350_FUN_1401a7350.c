// Address: 0x1401a7350
// Ghidra name: FUN_1401a7350
// ============ 0x1401a7350 FUN_1401a7350 (size=1736) ============


void FUN_1401a7350(longlong param_1)



{

  short *psVar1;

  char cVar2;

  longlong lVar3;

  ulonglong uVar4;

  byte bVar5;

  uint uVar6;

  uint *puVar7;

  ulonglong uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  int iVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  uint *puVar15;

  ulonglong uVar16;

  int iVar17;

  byte *pbVar18;

  byte bVar19;

  int iVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  byte local_2b8 [320];

  byte local_178 [320];

  

  uVar8 = 0;

  *(undefined2 *)(param_1 + 0x83ca) = 1;

  uVar16 = 0xff;

  FUN_1401a6e50(param_1,0,0x120,0xf,0);

  FUN_1401a6e50(param_1,1,0x20,0xf,0);

  iVar20 = 0x11e;

  lVar3 = 0x11e;

  do {

    if (*(char *)(param_1 + 0x8f49 + lVar3) != '\0') break;

    iVar20 = iVar20 + -1;

    lVar3 = lVar3 + -1;

  } while (0x101 < lVar3);

  iVar17 = 0x1e;

  lVar3 = 0x1e;

  do {

    if (*(char *)(param_1 + 0x9069 + lVar3) != '\0') break;

    iVar17 = iVar17 + -1;

    lVar3 = lVar3 + -1;

  } while (1 < lVar3);

  FUN_1402f8e20(local_178,param_1 + 0x8f4a,(longlong)iVar20);

  FUN_1402f8e20(local_178 + iVar20,param_1 + 0x906a,(longlong)iVar17);

  uVar4 = (ulonglong)(uint)(iVar20 + iVar17);

  *(undefined8 *)(param_1 + 0x864a) = 0;

  *(undefined8 *)(param_1 + 0x8652) = 0;

  *(undefined8 *)(param_1 + 0x865a) = 0;

  *(undefined8 *)(param_1 + 0x8662) = 0;

  *(undefined4 *)(param_1 + 0x866a) = 0;

  *(undefined2 *)(param_1 + 0x866e) = 0;

  uVar14 = uVar8;

  uVar21 = uVar8;

  if (iVar20 + iVar17 != 0) {

    pbVar18 = local_178;

    uVar13 = uVar8;

    uVar22 = uVar16;

    do {

      bVar19 = *pbVar18;

      uVar16 = (ulonglong)bVar19;

      uVar9 = (uint)uVar8;

      iVar12 = (int)uVar13;

      uVar10 = (uint)uVar21;

      if (bVar19 == 0) {

        if (uVar9 != 0) {

          if (uVar9 < 3) {

            psVar1 = (short *)(param_1 + 0x864a + uVar22 * 2);

            *psVar1 = *psVar1 + (short)uVar8;

            FUN_1402f94c0(local_2b8 + uVar13,uVar22,uVar8);

            do {

              uVar13 = (ulonglong)((int)uVar13 + 1);

              uVar9 = (int)uVar8 - 1;

              uVar8 = (ulonglong)uVar9;

            } while (uVar9 != 0);

          }

          else {

            *(short *)(param_1 + 0x866a) = *(short *)(param_1 + 0x866a) + 1;

            local_2b8[uVar13] = 0x10;

            local_2b8[iVar12 + 1] = (char)uVar8 - 3;

            uVar13 = (ulonglong)(iVar12 + 2);

          }

          uVar8 = 0;

        }

        uVar21 = (ulonglong)(uVar10 + 1);

        uVar14 = uVar13;

        if (uVar10 + 1 == 0x8a) {

          *(short *)(param_1 + 0x866e) = *(short *)(param_1 + 0x866e) + 1;

          uVar21 = 0;

          uVar14 = (ulonglong)((int)uVar13 + 2);

          local_2b8[uVar13] = 0x12;

          local_2b8[(int)uVar13 + 1] = 0x7f;

        }

      }

      else {

        if (uVar10 != 0) {

          if (uVar10 < 3) {

            *(short *)(param_1 + 0x864a) = *(short *)(param_1 + 0x864a) + (short)uVar21;

            FUN_1402f94c0(local_2b8 + uVar13,0,uVar21);

            do {

              uVar13 = (ulonglong)((int)uVar13 + 1);

              uVar10 = (int)uVar21 - 1;

              uVar21 = (ulonglong)uVar10;

            } while (uVar10 != 0);

          }

          else {

            if (uVar10 < 0xb) {

              *(short *)(param_1 + 0x866c) = *(short *)(param_1 + 0x866c) + 1;

              cVar2 = -3;

              local_2b8[uVar13] = 0x11;

            }

            else {

              *(short *)(param_1 + 0x866e) = *(short *)(param_1 + 0x866e) + 1;

              cVar2 = -0xb;

              local_2b8[uVar13] = 0x12;

            }

            local_2b8[iVar12 + 1] = (char)uVar21 + cVar2;

            uVar13 = (ulonglong)(iVar12 + 2);

          }

          uVar21 = 0;

        }

        iVar12 = (int)uVar13;

        if (bVar19 == (byte)uVar22) {

          uVar8 = (ulonglong)(uVar9 + 1);

          uVar14 = uVar13;

          if (uVar9 + 1 == 6) {

            *(short *)(param_1 + 0x866a) = *(short *)(param_1 + 0x866a) + 1;

            local_2b8[uVar13] = 0x10;

            local_2b8[iVar12 + 1] = 3;

            uVar14 = (ulonglong)(iVar12 + 2);

            uVar8 = 0;

          }

        }

        else {

          if (uVar9 != 0) {

            if (uVar9 < 3) {

              psVar1 = (short *)(param_1 + 0x864a + uVar22 * 2);

              *psVar1 = *psVar1 + (short)uVar8;

              FUN_1402f94c0(local_2b8 + uVar13,uVar22,uVar8);

              do {

                uVar13 = (ulonglong)((int)uVar13 + 1);

                uVar9 = (int)uVar8 - 1;

                uVar8 = (ulonglong)uVar9;

              } while (uVar9 != 0);

            }

            else {

              *(short *)(param_1 + 0x866a) = *(short *)(param_1 + 0x866a) + 1;

              local_2b8[uVar13] = 0x10;

              local_2b8[iVar12 + 1] = (char)uVar8 - 3;

              uVar13 = (ulonglong)(iVar12 + 2);

            }

            uVar8 = 0;

          }

          psVar1 = (short *)(param_1 + 0x864a + uVar16 * 2);

          *psVar1 = *psVar1 + 1;

          uVar14 = (ulonglong)((int)uVar13 + 1);

          local_2b8[uVar13] = bVar19;

        }

      }

      pbVar18 = pbVar18 + 1;

      uVar4 = uVar4 - 1;

      uVar13 = uVar14;

      uVar22 = uVar16;

    } while (uVar4 != 0);

  }

  uVar4 = 0;

  uVar9 = (uint)uVar14;

  if ((uint)uVar8 == 0) {

    uVar10 = (uint)uVar21;

    if (uVar10 != 0) {

      if (uVar10 < 3) {

        *(short *)(param_1 + 0x864a) = *(short *)(param_1 + 0x864a) + (short)uVar21;

        FUN_1402f94c0(local_2b8 + uVar14,0,uVar21);

        do {

          uVar9 = (int)uVar14 + 1;

          uVar14 = (ulonglong)uVar9;

          uVar10 = (int)uVar21 - 1;

          uVar21 = (ulonglong)uVar10;

        } while (uVar10 != 0);

      }

      else {

        uVar11 = uVar9 + 1;

        uVar9 = uVar9 + 2;

        if (uVar10 < 0xb) {

          *(short *)(param_1 + 0x866c) = *(short *)(param_1 + 0x866c) + 1;

          bVar19 = (char)uVar21 - 3;

          local_2b8[uVar14] = 0x11;

        }

        else {

          *(short *)(param_1 + 0x866e) = *(short *)(param_1 + 0x866e) + 1;

          bVar19 = (char)uVar21 - 0xb;

          local_2b8[uVar14] = 0x12;

        }

        local_2b8[uVar11] = bVar19;

      }

    }

  }

  else if ((uint)uVar8 < 3) {

    psVar1 = (short *)(param_1 + 0x864a + uVar16 * 2);

    *psVar1 = *psVar1 + (short)uVar8;

    FUN_1402f94c0(local_2b8 + uVar14,uVar16,uVar8);

    do {

      uVar9 = (int)uVar14 + 1;

      uVar14 = (ulonglong)uVar9;

      uVar10 = (int)uVar8 - 1;

      uVar8 = (ulonglong)uVar10;

    } while (uVar10 != 0);

  }

  else {

    *(short *)(param_1 + 0x866a) = *(short *)(param_1 + 0x866a) + 1;

    local_2b8[uVar14] = 0x10;

    local_2b8[uVar9 + 1] = (char)uVar8 - 3;

    uVar9 = uVar9 + 2;

  }

  FUN_1401a6e50(param_1,2,0x13,7,0);

  uVar10 = *(int *)(param_1 + 0x5c) + 2;

  uVar11 = 2 << ((byte)*(int *)(param_1 + 0x5c) & 0x1f) | *(uint *)(param_1 + 0x60);

  *(uint *)(param_1 + 0x60) = uVar11;

  *(uint *)(param_1 + 0x5c) = uVar10;

  while (7 < uVar10) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    uVar11 = *(uint *)(param_1 + 0x60) >> 8;

    uVar10 = *(int *)(param_1 + 0x5c) - 8;

    *(uint *)(param_1 + 0x60) = uVar11;

    *(uint *)(param_1 + 0x5c) = uVar10;

  }

  uVar6 = uVar10 + 5;

  uVar11 = iVar20 + -0x101 << ((byte)uVar10 & 0x1f) | uVar11;

  *(uint *)(param_1 + 0x5c) = uVar6;

  *(uint *)(param_1 + 0x60) = uVar11;

  while (7 < uVar6) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    uVar11 = *(uint *)(param_1 + 0x60) >> 8;

    uVar6 = *(uint *)(param_1 + 0x5c) - 8;

    *(uint *)(param_1 + 0x60) = uVar11;

    *(uint *)(param_1 + 0x5c) = uVar6;

  }

  puVar15 = (uint *)(param_1 + 0x5c);

  puVar7 = (uint *)(param_1 + 0x60);

  uVar10 = uVar6 + 5;

  *puVar15 = uVar10;

  uVar11 = iVar17 + -1 << ((byte)uVar6 & 0x1f) | uVar11;

  *puVar7 = uVar11;

  while (7 < uVar10) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    *puVar7 = *puVar7 >> 8;

    *puVar15 = *puVar15 - 8;

    uVar11 = (uint)*(byte *)puVar7;

    uVar10 = *puVar15;

  }

  iVar20 = 0x12;

  lVar3 = 0x12;

  do {

    if (*(char *)((ulonglong)(byte)(&DAT_1403e3d30)[lVar3] + 0x918a + param_1) != '\0') break;

    iVar20 = iVar20 + -1;

    lVar3 = lVar3 + -1;

  } while (-1 < lVar3);

  iVar17 = *(int *)(param_1 + 0x5c);

  iVar20 = iVar20 + 1;

  if (iVar20 < 4) {

    iVar20 = 4;

  }

  uVar10 = iVar17 + 4;

  *(uint *)(param_1 + 0x5c) = uVar10;

  uVar11 = iVar20 + -4 << ((byte)iVar17 & 0x1f) | *(uint *)(param_1 + 0x60);

  *(uint *)(param_1 + 0x60) = uVar11;

  while (7 < uVar10) {

    if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

      **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

      *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

    }

    uVar11 = *(uint *)(param_1 + 0x60) >> 8;

    uVar10 = *(int *)(param_1 + 0x5c) - 8;

    *(uint *)(param_1 + 0x60) = uVar11;

    *(uint *)(param_1 + 0x5c) = uVar10;

  }

  uVar8 = uVar4;

  if (iVar20 != 0) {

    do {

      uVar11 = (uint)*(byte *)((ulonglong)(byte)(&DAT_1403e3d30)[uVar8] + 0x918a + param_1) <<

               ((byte)uVar10 & 0x1f) | uVar11;

      *(uint *)(param_1 + 0x5c) = uVar10 + 3;

      *(uint *)(param_1 + 0x60) = uVar11;

      uVar10 = uVar10 + 3;

      while (7 < uVar10) {

        if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

          **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

          *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

        }

        uVar11 = *(uint *)(param_1 + 0x60) >> 8;

        uVar10 = *(int *)(param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0x60) = uVar11;

        *(uint *)(param_1 + 0x5c) = uVar10;

      }

      uVar6 = (int)uVar8 + 1;

      uVar8 = (ulonglong)uVar6;

    } while ((int)uVar6 < iVar20);

  }

  if (uVar9 != 0) {

    do {

      bVar19 = local_2b8[uVar4];

      iVar20 = (int)uVar4;

      uVar4 = (ulonglong)(iVar20 + 1);

      bVar5 = (byte)uVar10;

      uVar10 = uVar10 + *(byte *)((ulonglong)bVar19 + 0x918a + param_1);

      uVar11 = (uint)*(ushort *)(param_1 + 0x8d0a + (ulonglong)bVar19 * 2) << (bVar5 & 0x1f) |

               uVar11;

      *(uint *)(param_1 + 0x5c) = uVar10;

      *(uint *)(param_1 + 0x60) = uVar11;

      while (7 < uVar10) {

        if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

          **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

          *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

        }

        uVar11 = *(uint *)(param_1 + 0x60) >> 8;

        uVar10 = *(int *)(param_1 + 0x5c) - 8;

        *(uint *)(param_1 + 0x60) = uVar11;

        *(uint *)(param_1 + 0x5c) = uVar10;

      }

      if (0xf < bVar19) {

        bVar5 = (byte)uVar10;

        uVar10 = uVar10 + (int)(char)(&DAT_14033c19c)[bVar19 - 0x10];

        uVar11 = (uint)local_2b8[uVar4] << (bVar5 & 0x1f) | uVar11;

        *(uint *)(param_1 + 0x5c) = uVar10;

        uVar4 = (ulonglong)(iVar20 + 2);

        *(uint *)(param_1 + 0x60) = uVar11;

        while (7 < uVar10) {

          if (*(undefined1 **)(param_1 + 0x40) < *(undefined1 **)(param_1 + 0x48)) {

            **(undefined1 **)(param_1 + 0x40) = (char)uVar11;

            *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 1;

          }

          uVar11 = *(uint *)(param_1 + 0x60) >> 8;

          uVar10 = *(int *)(param_1 + 0x5c) - 8;

          *(uint *)(param_1 + 0x60) = uVar11;

          *(uint *)(param_1 + 0x5c) = uVar10;

        }

      }

    } while ((uint)uVar4 < uVar9);

  }

  return;

}





// Address: 0x1401a0a00
// Ghidra name: FUN_1401a0a00
// ============ 0x1401a0a00 FUN_1401a0a00 (size=1796) ============


undefined8 FUN_1401a0a00(longlong param_1,longlong param_2,longlong param_3,longlong param_4)



{

  uint *puVar1;

  ushort *puVar2;

  byte bVar3;

  ushort uVar4;

  uint uVar5;

  undefined4 uVar6;

  byte bVar7;

  undefined8 uVar8;

  byte bVar9;

  uint uVar10;

  char *pcVar11;

  uint uVar12;

  int iVar13;

  int iVar14;

  ulonglong uVar15;

  byte *pbVar16;

  ulonglong uVar17;

  uint uVar18;

  short sVar19;

  longlong lVar20;

  int iVar21;

  ulonglong uVar22;

  ushort uVar23;

  ushort uVar24;

  

  iVar13 = *(int *)(param_1 + 0x4834);

  uVar15 = (ulonglong)iVar13;

  if (iVar13 == 0) {

    uVar8 = FUN_14019f050("Corrupt JPEG");

    return uVar8;

  }

  iVar21 = *(int *)(param_1 + 0x4844);

  bVar9 = (byte)*(undefined4 *)(param_1 + 0x4840);

  if (*(int *)(param_1 + 0x483c) != 0) {

    uVar23 = 1 << (bVar9 & 0x1f);

    uVar22 = uVar15;

    if (iVar21 == 0) {

      do {

        if (*(int *)(param_1 + 0x4824) < 0x10) {

          FUN_14019f510(param_1);

        }

        uVar12 = *(uint *)(param_1 + 0x4820);

        bVar9 = *(byte *)((ulonglong)(uVar12 >> 0x17) + param_3);

        uVar17 = (ulonglong)bVar9;

        if (bVar9 == 0xff) {

          puVar1 = (uint *)(param_3 + 0x62c);

          iVar13 = 10;

          lVar20 = 10;

          uVar10 = *puVar1;

          while (uVar10 <= uVar12 >> 0x10) {

            iVar13 = iVar13 + 1;

            puVar1 = puVar1 + 1;

            lVar20 = lVar20 + 1;

            uVar10 = *puVar1;

          }

          iVar21 = *(int *)(param_1 + 0x4824);

          if (iVar13 == 0x11) goto LAB_1401a10d3;

          if (iVar21 < iVar13) goto LAB_1401a10d9;

          bVar9 = (byte)iVar13;

          uVar10 = *(int *)(param_3 + 0x64c + lVar20 * 4) +

                   (uVar12 >> (0x20 - bVar9 & 0x1f) & *(uint *)(&DAT_14033b310 + lVar20 * 4));

          if (0xff < uVar10) goto LAB_1401a10d9;

          iVar21 = iVar21 - iVar13;

          uVar17 = (ulonglong)(int)uVar10;

        }

        else {

          bVar9 = *(byte *)(uVar17 + 0x500 + param_3);

          if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar9) goto LAB_1401a10d9;

          iVar21 = *(int *)(param_1 + 0x4824) - (uint)bVar9;

        }

        *(int *)(param_1 + 0x4824) = iVar21;

        *(uint *)(param_1 + 0x4820) = uVar12 << (bVar9 & 0x1f);

        bVar9 = *(byte *)(uVar17 + 0x400 + param_3);

        bVar3 = bVar9 >> 4;

        uVar17 = (ulonglong)bVar3;

        uVar24 = bVar9 & 0xf;

        if ((bVar9 & 0xf) == 0) {

          if (bVar3 < 0xf) {

            iVar13 = (1 << bVar3) + -1;

            *(int *)(param_1 + 0x4844) = iVar13;

            uVar12 = (uint)bVar3;

            if (uVar12 != 0) {

              if (iVar21 < (int)uVar12) {

                FUN_14019f510(param_1);

                iVar13 = *(int *)(param_1 + 0x4844);

              }

              if (*(int *)(param_1 + 0x4824) < (int)uVar12) {

                uVar17 = 0x40;

                *(int *)(param_1 + 0x4844) = iVar13;

                goto LAB_1401a1014;

              }

              uVar10 = *(uint *)(param_1 + 0x4820) << bVar3 |

                       *(uint *)(param_1 + 0x4820) >> 0x20 - bVar3;

              uVar12 = *(uint *)(&DAT_14033b310 + uVar17 * 4);

              *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - (uint)bVar3;

              *(uint *)(param_1 + 0x4820) = ~uVar12 & uVar10;

              *(uint *)(param_1 + 0x4844) = iVar13 + (uVar10 & uVar12);

            }

            uVar17 = 0x40;

          }

        }

        else {

          if (uVar24 != 1) goto LAB_1401a10d9;

          if (iVar21 < 1) {

            FUN_14019f510(param_1);

          }

          if (0 < *(int *)(param_1 + 0x4824)) {

            iVar13 = *(int *)(param_1 + 0x4820);

            *(int *)(param_1 + 0x4820) = iVar13 * 2;

            *(int *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) + -1;

            uVar24 = uVar23;

            if (iVar13 < 0) goto LAB_1401a1014;

          }

          uVar24 = -uVar23;

        }

LAB_1401a1014:

        if (*(int *)(param_1 + 0x4838) < (int)uVar15) {

          return 1;

        }

        do {

          pbVar16 = &DAT_14033b3a0 + uVar22;

          uVar12 = (int)uVar15 + 1;

          uVar15 = (ulonglong)uVar12;

          uVar22 = uVar22 + 1;

          puVar2 = (ushort *)(param_2 + (ulonglong)*pbVar16 * 2);

          if (*(short *)(param_2 + (ulonglong)*pbVar16 * 2) == 0) {

            if ((int)uVar17 == 0) {

              *puVar2 = uVar24;

              break;

            }

            uVar17 = (ulonglong)((int)uVar17 - 1);

          }

          else {

            if (*(int *)(param_1 + 0x4824) < 1) {

              FUN_14019f510(param_1);

            }

            if (0 < *(int *)(param_1 + 0x4824)) {

              iVar13 = *(int *)(param_1 + 0x4820);

              *(int *)(param_1 + 0x4820) = iVar13 * 2;

              *(int *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) + -1;

              if ((iVar13 < 0) && (uVar4 = *puVar2, (uVar23 & uVar4) == 0)) {

                if ((short)uVar4 < 1) {

                  *puVar2 = uVar4 - uVar23;

                }

                else {

                  *puVar2 = uVar4 + uVar23;

                }

              }

            }

          }

        } while ((int)uVar12 <= *(int *)(param_1 + 0x4838));

      } while ((int)uVar12 <= *(int *)(param_1 + 0x4838));

    }

    else {

      *(int *)(param_1 + 0x4844) = iVar21 + -1;

      if (iVar13 <= *(int *)(param_1 + 0x4838)) {

        pbVar16 = &DAT_14033b3a0 + uVar15;

        do {

          puVar2 = (ushort *)(param_2 + (ulonglong)*pbVar16 * 2);

          if (*(short *)(param_2 + (ulonglong)*pbVar16 * 2) != 0) {

            if (*(int *)(param_1 + 0x4824) < 1) {

              FUN_14019f510(param_1);

            }

            if (0 < *(int *)(param_1 + 0x4824)) {

              iVar13 = *(int *)(param_1 + 0x4820);

              *(int *)(param_1 + 0x4820) = iVar13 * 2;

              *(int *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) + -1;

              if ((iVar13 < 0) && (uVar24 = *puVar2, (uVar23 & uVar24) == 0)) {

                uVar4 = uVar23;

                if ((short)uVar24 < 1) {

                  uVar4 = -uVar23;

                }

                *puVar2 = uVar24 + uVar4;

              }

            }

          }

          uVar12 = (int)uVar15 + 1;

          uVar15 = (ulonglong)uVar12;

          pbVar16 = pbVar16 + 1;

        } while ((int)uVar12 <= *(int *)(param_1 + 0x4838));

        return 1;

      }

    }

    return 1;

  }

  if (iVar21 != 0) {

    *(int *)(param_1 + 0x4844) = iVar21 + -1;

    return 1;

  }

  do {

    if (*(int *)(param_1 + 0x4824) < 0x10) {

      FUN_14019f510(param_1);

    }

    iVar13 = *(int *)(param_1 + 0x4824);

    sVar19 = *(short *)(param_4 + (ulonglong)(*(uint *)(param_1 + 0x4820) >> 0x17) * 2);

    uVar12 = (uint)sVar19;

    iVar14 = (int)uVar15;

    if (uVar12 == 0) {

      if (iVar13 < 0x10) {

        FUN_14019f510(param_1);

      }

      uVar12 = *(uint *)(param_1 + 0x4820);

      bVar3 = *(byte *)((ulonglong)(uVar12 >> 0x17) + param_3);

      uVar15 = (ulonglong)bVar3;

      if (bVar3 == 0xff) {

        puVar1 = (uint *)(param_3 + 0x62c);

        iVar13 = 10;

        lVar20 = 10;

        uVar10 = *puVar1;

        while (uVar10 <= uVar12 >> 0x10) {

          iVar13 = iVar13 + 1;

          puVar1 = puVar1 + 1;

          lVar20 = lVar20 + 1;

          uVar10 = *puVar1;

        }

        iVar21 = *(int *)(param_1 + 0x4824);

        if (iVar13 == 0x11) break;

        if (iVar21 < iVar13) goto LAB_1401a10d9;

        bVar3 = (byte)iVar13;

        uVar10 = *(int *)(param_3 + 0x64c + lVar20 * 4) +

                 (uVar12 >> (0x20 - bVar3 & 0x1f) & *(uint *)(&DAT_14033b310 + lVar20 * 4));

        if (0xff < uVar10) goto LAB_1401a10d9;

        iVar21 = iVar21 - iVar13;

        uVar15 = (ulonglong)(int)uVar10;

      }

      else {

        bVar3 = *(byte *)(uVar15 + 0x500 + param_3);

        if (*(int *)(param_1 + 0x4824) < (int)(uint)bVar3) goto LAB_1401a10d9;

        iVar21 = *(int *)(param_1 + 0x4824) - (uint)bVar3;

      }

      *(int *)(param_1 + 0x4824) = iVar21;

      *(uint *)(param_1 + 0x4820) = uVar12 << (bVar3 & 0x1f);

      bVar3 = *(byte *)(uVar15 + 0x400 + param_3);

      bVar7 = bVar3 >> 4;

      uVar12 = bVar3 & 0xf;

      if ((bVar3 & 0xf) == 0) {

        if (bVar7 < 0xf) {

          iVar13 = 1 << bVar7;

          *(int *)(param_1 + 0x4844) = iVar13;

          uVar12 = (uint)bVar7;

          if (uVar12 != 0) {

            if (iVar21 < (int)uVar12) {

              FUN_14019f510(param_1);

              iVar13 = *(int *)(param_1 + 0x4844);

            }

            if (*(int *)(param_1 + 0x4824) < (int)uVar12) {

              *(int *)(param_1 + 0x4844) = iVar13 + -1;

              return 1;

            }

            uVar10 = *(uint *)(param_1 + 0x4820) << bVar7 |

                     *(uint *)(param_1 + 0x4820) >> 0x20 - bVar7;

            uVar12 = *(uint *)(&DAT_14033b310 + (ulonglong)bVar7 * 4);

            *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - (uint)bVar7;

            iVar13 = iVar13 + (uVar10 & uVar12);

            *(uint *)(param_1 + 0x4820) = ~uVar12 & uVar10;

          }

          *(int *)(param_1 + 0x4844) = iVar13 + -1;

          return 1;

        }

        uVar15 = (ulonglong)(iVar14 + 0x10);

      }

      else {

        uVar15 = (ulonglong)((uint)bVar7 + iVar14 + 1);

        bVar3 = (&DAT_14033b3a0)[(int)((uint)bVar7 + iVar14)];

        if (iVar21 < (int)uVar12) {

          FUN_14019f510(param_1);

        }

        if (*(int *)(param_1 + 0x4824) < (int)uVar12) {

          sVar19 = 0;

        }

        else {

          uVar10 = *(uint *)(param_1 + 0x4820);

          uVar18 = uVar10 << (sbyte)uVar12 | uVar10 >> 0x20 - (sbyte)uVar12;

          uVar5 = *(uint *)(&DAT_14033b310 + (ulonglong)uVar12 * 4);

          *(uint *)(param_1 + 0x4824) = *(int *)(param_1 + 0x4824) - uVar12;

          uVar6 = *(undefined4 *)(&DAT_14033b360 + (ulonglong)uVar12 * 4);

          *(uint *)(param_1 + 0x4820) = ~uVar5 & uVar18;

          sVar19 = (0xffffU - (short)((int)uVar10 >> 0x1f) & (ushort)uVar6) +

                   ((ushort)uVar5 & (ushort)uVar18);

        }

        *(short *)(param_2 + (ulonglong)bVar3 * 2) = (1 << (bVar9 & 0x1f)) * sVar19;

      }

    }

    else {

      uVar10 = uVar12 & 0xf;

      iVar14 = iVar14 + ((int)uVar12 >> 4 & 0xfU);

      if (iVar13 < (int)uVar10) {

        pcVar11 = "Combined length longer than code bits available";

        goto LAB_1401a10e0;

      }

      *(uint *)(param_1 + 0x4824) = iVar13 - uVar10;

      uVar15 = (ulonglong)(iVar14 + 1);

      bVar3 = (&DAT_14033b3a0)[iVar14];

      *(uint *)(param_1 + 0x4820) = *(uint *)(param_1 + 0x4820) << (sbyte)uVar10;

      *(short *)(param_2 + (ulonglong)bVar3 * 2) =

           (short)(char)((ushort)sVar19 >> 8) * (1 << (bVar9 & 0x1f));

    }

    if (*(int *)(param_1 + 0x4838) < (int)uVar15) {

      return 1;

    }

  } while( true );

LAB_1401a10d3:

  *(int *)(param_1 + 0x4824) = iVar21 + -0x10;

LAB_1401a10d9:

  pcVar11 = "Corrupt JPEG";

LAB_1401a10e0:

  uVar8 = FUN_14019f050(pcVar11);

  return uVar8;

}





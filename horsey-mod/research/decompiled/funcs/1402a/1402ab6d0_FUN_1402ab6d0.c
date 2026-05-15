// Address: 0x1402ab6d0
// Ghidra name: FUN_1402ab6d0
// ============ 0x1402ab6d0 FUN_1402ab6d0 (size=680) ============


void FUN_1402ab6d0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ushort uVar9;

  ushort uVar10;

  ushort uVar11;

  ushort uVar12;

  uint uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  uint uVar16;

  uint *puVar17;

  uint uVar18;

  

  bVar1 = *(byte *)(param_1 + 0x81);

  uVar15 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar14 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x80);

  bVar3 = *(byte *)(param_1 + 0x83);

  bVar4 = *(byte *)(param_1 + 0x82);

  uVar6 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar15;

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar14;

  uVar8 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    uVar18 = uVar5 & 2;

    do {

      puVar17 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar15 + -1;

      if ((int)uVar14 != 0) {

        uVar15 = uVar7 >> 1;

        if ((uVar5 & 1) == 0) {

          do {

            uVar13 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar8 >> 0x10) +

                               (uVar15 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            uVar16 = uVar13 & 0xff;

            if (uVar18 != 0) {

              uVar9 = (ushort)bVar3 * (short)uVar16 + 1;

              uVar16 = (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

            }

            uVar15 = uVar15 + uVar7;

            *puVar17 = ((uVar16 << 8 | uVar13 >> 0x18) << 8 | uVar13 >> 0x10 & 0xff) << 8 |

                       uVar13 >> 8 & 0xff;

            puVar17 = puVar17 + 1;

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

          } while (uVar13 != 0);

        }

        else {

          do {

            uVar13 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar8 >> 0x10) +

                               (uVar15 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            uVar16 = uVar13 & 0xff;

            uVar9 = (ushort)(byte)(uVar13 >> 0x18) * (ushort)bVar2 + 1;

            uVar10 = ((ushort)(uVar13 >> 0x10) & 0xff) * (ushort)bVar1 + 1;

            uVar11 = ((ushort)(uVar13 >> 8) & 0xff) * (ushort)bVar4 + 1;

            if (uVar18 != 0) {

              uVar12 = (ushort)bVar3 * (short)uVar16 + 1;

              uVar16 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            }

            *puVar17 = ((ushort)((uVar9 >> 8) + uVar9) & 0xffffff00 | uVar16 << 0x10 |

                       (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8)) << 8 |

                       (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

            puVar17 = puVar17 + 1;

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

            uVar15 = uVar15 + uVar7;

          } while (uVar13 != 0);

        }

        uVar14 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar8 = uVar8 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar15 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





// Address: 0x1402c3690
// Ghidra name: FUN_1402c3690
// ============ 0x1402c3690 FUN_1402c3690 (size=685) ============


void FUN_1402c3690(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ushort uVar8;

  ulonglong uVar9;

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

  uVar9 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    uVar18 = uVar5 & 2;

    do {

      puVar17 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar15 + -1;

      if ((int)uVar14 != 0) {

        uVar15 = uVar7 >> 1;

        if ((uVar5 & 1) == 0) {

          do {

            uVar13 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar9 >> 0x10) +

                               (uVar15 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            uVar16 = uVar13 & 0xff;

            if (uVar18 != 0) {

              uVar8 = (ushort)bVar3 * (short)uVar16 + 1;

              uVar16 = (uint)((ushort)((uVar8 >> 8) + uVar8) >> 8);

            }

            uVar15 = uVar15 + uVar7;

            *puVar17 = ((uVar16 << 8 | uVar13 >> 8 & 0xff) << 8 | uVar13 >> 0x10 & 0xff) << 8 |

                       uVar13 >> 0x18;

            puVar17 = puVar17 + 1;

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

          } while (uVar13 != 0);

        }

        else {

          do {

            uVar13 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar9 >> 0x10) +

                               (uVar15 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            uVar16 = uVar13 & 0xff;

            uVar10 = ((ushort)(uVar13 >> 8) & 0xff) * (ushort)bVar2 + 1;

            uVar11 = ((ushort)(uVar13 >> 0x10) & 0xff) * (ushort)bVar1 + 1;

            uVar8 = (ushort)(byte)(uVar13 >> 0x18) * (ushort)bVar4 + 1;

            if (uVar18 != 0) {

              uVar12 = (ushort)bVar3 * (short)uVar16 + 1;

              uVar16 = (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

            }

            *puVar17 = ((ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 | uVar16 << 0x10 |

                       (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8)) << 8 |

                       (uint)((ushort)((uVar8 >> 8) + uVar8) >> 8);

            puVar17 = puVar17 + 1;

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

            uVar15 = uVar15 + uVar7;

          } while (uVar13 != 0);

        }

        uVar14 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar9 = uVar9 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar15 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





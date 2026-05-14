// Address: 0x1402b18c0
// Ghidra name: FUN_1402b18c0
// ============ 0x1402b18c0 FUN_1402b18c0 (size=597) ============


void FUN_1402b18c0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  uint *puVar8;

  ushort uVar9;

  ushort uVar10;

  ulonglong uVar11;

  ushort uVar12;

  uint uVar13;

  uint uVar14;

  ulonglong uVar15;

  ulonglong uVar16;

  

  bVar1 = *(byte *)(param_1 + 0x81);

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar11 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar15 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar2 = *(byte *)(param_1 + 0x80);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar13 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar13 = (uint)*(byte *)(param_1 + 0x83);

  }

  uVar6 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar11;

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar15;

  uVar16 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      *(int *)(param_1 + 0x3c) = (int)uVar11 + -1;

      if ((int)uVar15 != 0) {

        if ((uVar4 & 1) == 0) {

          puVar8 = *(uint **)(param_1 + 0x30);

          uVar11 = uVar7 >> 1;

          do {

            uVar14 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar16 >> 0x10) +

                               (uVar11 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            *puVar8 = ((uVar14 & 0xff | uVar13 << 8) << 8 | uVar14 >> 8 & 0xff) << 8 |

                      uVar14 >> 0x10 & 0xff;

            uVar14 = (int)uVar15 - 1;

            uVar15 = (ulonglong)uVar14;

            puVar8 = puVar8 + 1;

            uVar11 = uVar11 + uVar7;

          } while (uVar14 != 0);

        }

        else {

          puVar8 = *(uint **)(param_1 + 0x30);

          uVar11 = uVar7 >> 1;

          do {

            uVar5 = *(undefined4 *)

                     ((longlong)*(int *)(param_1 + 0x18) * (uVar16 >> 0x10) + (uVar11 >> 0x10) * 4 +

                     *(longlong *)(param_1 + 8));

            uVar9 = ((ushort)uVar5 & 0xff) * (ushort)bVar3 + 1;

            uVar10 = ((ushort)((uint)uVar5 >> 8) & 0xff) * (ushort)bVar1 + 1;

            uVar12 = ((ushort)((uint)uVar5 >> 0x10) & 0xff) * (ushort)bVar2 + 1;

            *puVar8 = ((ushort)((uVar9 >> 8) + uVar9) & 0xffffff00) << 8 |

                      (ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 |

                      (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) | uVar13 << 0x18;

            uVar14 = (int)uVar15 - 1;

            uVar15 = (ulonglong)uVar14;

            puVar8 = puVar8 + 1;

            uVar11 = uVar11 + uVar7;

          } while (uVar14 != 0);

        }

        uVar15 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar16 = uVar16 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar11 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





// Address: 0x1402c0460
// Ghidra name: FUN_1402c0460
// ============ 0x1402c0460 FUN_1402c0460 (size=544) ============


void FUN_1402c0460(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ushort uVar8;

  uint *puVar9;

  ushort uVar10;

  uint uVar11;

  ulonglong uVar12;

  ushort uVar13;

  uint uVar14;

  ulonglong uVar15;

  ulonglong uVar16;

  

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar12 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar15 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar6 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar12;

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar15;

  uVar16 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar9 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar12 + -1;

      if ((int)uVar15 != 0) {

        uVar12 = uVar7 >> 1;

        if ((uVar4 & 1) == 0) {

          do {

            uVar14 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar16 >> 0x10) +

                               (uVar12 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            uVar11 = uVar14 >> 8;

            *puVar9 = (uVar14 >> 0x10 & 0xff) << 8 | uVar11 & 0xff0000 | uVar11 & 0xff;

            uVar14 = (int)uVar15 - 1;

            uVar15 = (ulonglong)uVar14;

            puVar9 = puVar9 + 1;

            uVar12 = uVar12 + uVar7;

          } while (uVar14 != 0);

        }

        else {

          do {

            uVar5 = *(undefined4 *)

                     ((longlong)*(int *)(param_1 + 0x18) * (uVar16 >> 0x10) + (uVar12 >> 0x10) * 4 +

                     *(longlong *)(param_1 + 8));

            uVar10 = ((ushort)((uint)uVar5 >> 0x10) & 0xff) * (ushort)bVar2 + 1;

            uVar13 = ((ushort)((uint)uVar5 >> 8) & 0xff) * (ushort)bVar1 + 1;

            uVar8 = (ushort)(byte)((uint)uVar5 >> 0x18) * (ushort)bVar3 + 1;

            *puVar9 = ((ushort)((uVar8 >> 8) + uVar8) & 0xffffff00) << 8 |

                      (ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 |

                      (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar14 = (int)uVar15 - 1;

            uVar15 = (ulonglong)uVar14;

            puVar9 = puVar9 + 1;

            uVar12 = uVar12 + uVar7;

          } while (uVar14 != 0);

        }

        uVar15 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar16 = uVar16 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar12 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





// Address: 0x1402bde90
// Ghidra name: FUN_1402bde90
// ============ 0x1402bde90 FUN_1402bde90 (size=578) ============


void FUN_1402bde90(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  undefined4 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  uint uVar8;

  ulonglong uVar9;

  uint *puVar10;

  ushort uVar11;

  ulonglong uVar12;

  ushort uVar13;

  ushort uVar14;

  ulonglong uVar15;

  

  bVar1 = *(byte *)(param_1 + 0x82);

  uVar12 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar9 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar2 = *(byte *)(param_1 + 0x80);

  bVar3 = *(byte *)(param_1 + 0x81);

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar6 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar12;

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar9;

  uVar15 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar10 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar12 + -1;

      if ((int)uVar9 != 0) {

        uVar12 = uVar7 >> 1;

        if ((uVar4 & 1) == 0) {

          do {

            uVar8 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar15 >> 0x10) +

                              (uVar12 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            *puVar10 = ((uVar8 >> 8 & 0xff) << 8 | uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;

            uVar8 = (int)uVar9 - 1;

            uVar9 = (ulonglong)uVar8;

            uVar12 = uVar12 + uVar7;

            puVar10 = puVar10 + 1;

          } while (uVar8 != 0);

        }

        else {

          do {

            uVar5 = *(undefined4 *)

                     ((longlong)*(int *)(param_1 + 0x18) * (uVar15 >> 0x10) + (uVar12 >> 0x10) * 4 +

                     *(longlong *)(param_1 + 8));

            uVar14 = ((ushort)((uint)uVar5 >> 8) & 0xff) * (ushort)bVar2 + 1;

            uVar11 = ((ushort)((uint)uVar5 >> 0x10) & 0xff) * (ushort)bVar3 + 1;

            uVar13 = (ushort)(byte)((uint)uVar5 >> 0x18) * (ushort)bVar1 + 1;

            *puVar10 = ((ushort)((uVar14 >> 8) + uVar14) & 0xffffff00) << 8 |

                       (ushort)((uVar11 >> 8) + uVar11) & 0xffffff00 |

                       (uint)((ushort)((uVar13 >> 8) + uVar13) >> 8);

            uVar8 = (int)uVar9 - 1;

            uVar9 = (ulonglong)uVar8;

            uVar12 = uVar12 + uVar7;

            puVar10 = puVar10 + 1;

          } while (uVar8 != 0);

        }

        uVar9 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar15 = uVar15 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar12 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





// Address: 0x1402a9e60
// Ghidra name: FUN_1402a9e60
// ============ 0x1402a9e60 FUN_1402a9e60 (size=547) ============


void FUN_1402a9e60(longlong param_1)



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

  ulonglong uVar14;

  ulonglong uVar15;

  

  uVar4 = *(uint *)(param_1 + 0x78);

  uVar11 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar14 = (ulonglong)*(int *)(param_1 + 0x38);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  uVar6 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar11;

  uVar7 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar14;

  uVar15 = uVar6 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar8 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar11 + -1;

      if ((int)uVar14 != 0) {

        uVar11 = uVar7 >> 1;

        if ((uVar4 & 1) == 0) {

          do {

            uVar13 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar15 >> 0x10) +

                               (uVar11 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

            *puVar8 = ((uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 8 & 0xff) << 8 | uVar13 & 0xff;

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

            puVar8 = puVar8 + 1;

            uVar11 = uVar11 + uVar7;

          } while (uVar13 != 0);

        }

        else {

          do {

            uVar5 = *(undefined4 *)

                     ((longlong)*(int *)(param_1 + 0x18) * (uVar15 >> 0x10) + (uVar11 >> 0x10) * 4 +

                     *(longlong *)(param_1 + 8));

            uVar12 = ((ushort)((uint)uVar5 >> 0x10) & 0xff) * (ushort)bVar1 + 1;

            uVar10 = ((ushort)((uint)uVar5 >> 8) & 0xff) * (ushort)bVar2 + 1;

            uVar9 = ((ushort)uVar5 & 0xff) * (ushort)bVar3 + 1;

            *puVar8 = ((ushort)((uVar12 >> 8) + uVar12) & 0xffffff00) << 8 |

                      (ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 |

                      (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

            uVar13 = (int)uVar14 - 1;

            uVar14 = (ulonglong)uVar13;

            puVar8 = puVar8 + 1;

            uVar11 = uVar11 + uVar7;

          } while (uVar13 != 0);

        }

        uVar14 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar15 = uVar15 + uVar6;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar11 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





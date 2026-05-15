// Address: 0x1402ab4a0
// Ghidra name: FUN_1402ab4a0
// ============ 0x1402ab4a0 FUN_1402ab4a0 (size=548) ============


void FUN_1402ab4a0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  ushort uVar8;

  ushort uVar9;

  ushort uVar10;

  ushort uVar11;

  uint *puVar12;

  int iVar13;

  uint uVar14;

  uint *puVar15;

  uint uVar16;

  

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  bVar4 = *(byte *)(param_1 + 0x83);

  iVar6 = *(int *)(param_1 + 0x3c);

  while (iVar6 != 0) {

    iVar13 = *(int *)(param_1 + 0x38);

    puVar12 = *(uint **)(param_1 + 8);

    puVar15 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar6 + -1;

    if (iVar13 != 0) {

      uVar16 = uVar5 & 2;

      if ((uVar5 & 1) == 0) {

        do {

          uVar7 = *puVar12;

          uVar14 = uVar7 & 0xff;

          if (uVar16 != 0) {

            uVar8 = (ushort)bVar4 * (short)uVar14 + 1;

            uVar14 = (uint)((ushort)((uVar8 >> 8) + uVar8) >> 8);

          }

          puVar12 = puVar12 + 1;

          *puVar15 = ((uVar14 << 8 | uVar7 >> 0x18) << 8 | uVar7 >> 0x10 & 0xff) << 8 |

                     uVar7 >> 8 & 0xff;

          puVar15 = puVar15 + 1;

          iVar13 = iVar13 + -1;

        } while (iVar13 != 0);

      }

      else {

        do {

          uVar7 = *puVar12;

          uVar14 = uVar7 & 0xff;

          uVar8 = (ushort)(byte)(uVar7 >> 0x18) * (ushort)bVar1 + 1;

          uVar9 = ((ushort)(uVar7 >> 0x10) & 0xff) * (ushort)bVar2 + 1;

          uVar10 = ((ushort)(uVar7 >> 8) & 0xff) * (ushort)bVar3 + 1;

          if (uVar16 != 0) {

            uVar11 = (ushort)bVar4 * (short)uVar14 + 1;

            uVar14 = (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          }

          puVar12 = puVar12 + 1;

          *puVar15 = ((ushort)((uVar8 >> 8) + uVar8) & 0xffffff00 | uVar14 << 0x10 |

                     (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8)) << 8 |

                     (uint)((ushort)((uVar10 >> 8) + uVar10) >> 8);

          puVar15 = puVar15 + 1;

          iVar13 = iVar13 + -1;

        } while (iVar13 != 0);

      }

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar6 = *(int *)(param_1 + 0x3c);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





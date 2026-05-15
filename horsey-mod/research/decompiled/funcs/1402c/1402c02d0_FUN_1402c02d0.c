// Address: 0x1402c02d0
// Ghidra name: FUN_1402c02d0
// ============ 0x1402c02d0 FUN_1402c02d0 (size=392) ============


void FUN_1402c02d0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  ushort uVar7;

  uint *puVar8;

  int iVar9;

  uint uVar10;

  ushort uVar11;

  ushort uVar12;

  uint *puVar13;

  

  bVar1 = *(byte *)(param_1 + 0x82);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar2 = *(byte *)(param_1 + 0x80);

  bVar3 = *(byte *)(param_1 + 0x81);

  iVar4 = *(int *)(param_1 + 0x3c);

  while (iVar4 != 0) {

    iVar9 = *(int *)(param_1 + 0x38);

    puVar13 = *(uint **)(param_1 + 8);

    puVar8 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar4 + -1;

    if (iVar9 != 0) {

      if ((uVar5 & 1) == 0) {

        do {

          uVar6 = *puVar13;

          puVar13 = puVar13 + 1;

          uVar10 = uVar6 >> 8;

          *puVar8 = (uVar6 >> 0x10 & 0xff) << 8 | uVar10 & 0xff0000 | uVar10 & 0xff;

          iVar9 = iVar9 + -1;

          puVar8 = puVar8 + 1;

        } while (iVar9 != 0);

      }

      else {

        do {

          uVar6 = *puVar13;

          puVar13 = puVar13 + 1;

          uVar11 = ((ushort)(uVar6 >> 0x10) & 0xff) * (ushort)bVar3 + 1;

          uVar12 = ((ushort)(uVar6 >> 8) & 0xff) * (ushort)bVar2 + 1;

          uVar7 = (ushort)(byte)(uVar6 >> 0x18) * (ushort)bVar1 + 1;

          *puVar8 = ((ushort)((uVar7 >> 8) + uVar7) & 0xffffff00) << 8 |

                    (ushort)((uVar11 >> 8) + uVar11) & 0xffffff00 |

                    (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8);

          iVar9 = iVar9 + -1;

          puVar8 = puVar8 + 1;

        } while (iVar9 != 0);

      }

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar4 = *(int *)(param_1 + 0x3c);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





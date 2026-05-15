// Address: 0x1402bd7d0
// Ghidra name: FUN_1402bd7d0
// ============ 0x1402bd7d0 FUN_1402bd7d0 (size=426) ============


void FUN_1402bd7d0(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint *puVar7;

  int iVar8;

  uint *puVar9;

  ushort uVar10;

  ushort uVar11;

  ushort uVar12;

  

  bVar1 = *(byte *)(param_1 + 0x81);

  bVar2 = *(byte *)(param_1 + 0x82);

  uVar5 = *(uint *)(param_1 + 0x78);

  bVar3 = *(byte *)(param_1 + 0x80);

  iVar4 = *(int *)(param_1 + 0x3c);

  while (iVar4 != 0) {

    iVar8 = *(int *)(param_1 + 0x38);

    puVar7 = *(uint **)(param_1 + 8);

    puVar9 = *(uint **)(param_1 + 0x30);

    *(int *)(param_1 + 0x3c) = iVar4 + -1;

    if (iVar8 != 0) {

      if ((uVar5 & 1) == 0) {

        do {

          uVar6 = *puVar7;

          puVar7 = puVar7 + 1;

          *puVar9 = ((uVar6 >> 8 & 0xff) << 8 | uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;

          iVar8 = iVar8 + -1;

          puVar9 = puVar9 + 1;

        } while (iVar8 != 0);

      }

      else {

        do {

          uVar6 = *puVar7;

          puVar7 = puVar7 + 1;

          uVar12 = ((ushort)(uVar6 >> 8) & 0xff) * (ushort)bVar3 + 1;

          uVar10 = ((ushort)(uVar6 >> 0x10) & 0xff) * (ushort)bVar1 + 1;

          uVar11 = (ushort)(byte)(uVar6 >> 0x18) * (ushort)bVar2 + 1;

          *puVar9 = ((ushort)((uVar12 >> 8) + uVar12) & 0xffffff00) << 8 |

                    (ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 |

                    (uint)((ushort)((uVar11 >> 8) + uVar11) >> 8);

          iVar8 = iVar8 + -1;

          puVar9 = puVar9 + 1;

        } while (iVar8 != 0);

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





// Address: 0x1402b2070
// Ghidra name: FUN_1402b2070
// ============ 0x1402b2070 FUN_1402b2070 (size=385) ============


void FUN_1402b2070(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint *puVar7;

  int iVar8;

  ushort uVar9;

  ushort uVar10;

  ushort uVar11;

  uint *puVar12;

  

  uVar4 = *(uint *)(param_1 + 0x78);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  bVar3 = *(byte *)(param_1 + 0x82);

  iVar5 = *(int *)(param_1 + 0x3c);

  while (iVar5 != 0) {

    iVar8 = *(int *)(param_1 + 0x38);

    puVar12 = *(uint **)(param_1 + 8);

    *(int *)(param_1 + 0x3c) = iVar5 + -1;

    puVar7 = *(uint **)(param_1 + 0x30);

    if (iVar8 != 0) {

      if ((uVar4 & 1) == 0) {

        do {

          uVar6 = *puVar12;

          puVar12 = puVar12 + 1;

          *puVar7 = (uVar6 >> 8 & 0xff | (uVar6 & 0xff) << 8) << 8 | uVar6 >> 0x10 & 0xff;

          iVar8 = iVar8 + -1;

          puVar7 = puVar7 + 1;

        } while (iVar8 != 0);

      }

      else {

        do {

          uVar6 = *puVar12;

          puVar12 = puVar12 + 1;

          uVar11 = ((ushort)uVar6 & 0xff) * (ushort)bVar1 + 1;

          uVar10 = ((ushort)(uVar6 >> 8) & 0xff) * (ushort)bVar2 + 1;

          uVar9 = ((ushort)(uVar6 >> 0x10) & 0xff) * (ushort)bVar3 + 1;

          *puVar7 = ((ushort)((uVar11 >> 8) + uVar11) & 0xffffff00) << 8 |

                    (ushort)((uVar10 >> 8) + uVar10) & 0xffffff00 |

                    (uint)((ushort)((uVar9 >> 8) + uVar9) >> 8);

          iVar8 = iVar8 + -1;

          puVar7 = puVar7 + 1;

        } while (iVar8 != 0);

      }

    }

    *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + (longlong)*(int *)(param_1 + 0x18);

    *(longlong *)(param_1 + 0x30) =

         *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

    iVar5 = *(int *)(param_1 + 0x3c);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}





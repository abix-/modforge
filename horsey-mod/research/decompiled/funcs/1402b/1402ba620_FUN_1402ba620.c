// Address: 0x1402ba620
// Ghidra name: FUN_1402ba620
// ============ 0x1402ba620 FUN_1402ba620 (size=482) ============


void FUN_1402ba620(longlong param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint *puVar7;

  uint uVar8;

  int iVar9;

  ushort uVar10;

  ushort uVar11;

  ushort uVar12;

  uint *puVar13;

  

  uVar4 = *(uint *)(param_1 + 0x78);

  bVar1 = *(byte *)(param_1 + 0x80);

  bVar2 = *(byte *)(param_1 + 0x81);

  uVar8 = 0xff;

  if ((uVar4 & 2) != 0) {

    uVar8 = (uint)*(byte *)(param_1 + 0x83);

  }

  bVar3 = *(byte *)(param_1 + 0x82);

  iVar5 = *(int *)(param_1 + 0x3c);

  while (iVar5 != 0) {

    iVar9 = *(int *)(param_1 + 0x38);

    puVar13 = *(uint **)(param_1 + 8);

    *(int *)(param_1 + 0x3c) = iVar5 + -1;

    if (iVar9 != 0) {

      if ((uVar4 & 1) == 0) {

        puVar7 = *(uint **)(param_1 + 0x30);

        do {

          uVar6 = *puVar13;

          puVar13 = puVar13 + 1;

          *puVar7 = ((uVar6 >> 0x10 & 0xff | uVar8 << 8) << 8 | uVar6 >> 8 & 0xff) << 8 |

                    uVar6 & 0xff;

          iVar9 = iVar9 + -1;

          puVar7 = puVar7 + 1;

        } while (iVar9 != 0);

      }

      else {

        puVar7 = *(uint **)(param_1 + 0x30);

        do {

          uVar6 = *puVar13;

          puVar13 = puVar13 + 1;

          uVar12 = ((ushort)uVar6 & 0xff) * (ushort)bVar1 + 1;

          uVar10 = ((ushort)(uVar6 >> 0x10) & 0xff) * (ushort)bVar3 + 1;

          uVar11 = ((ushort)(uVar6 >> 8) & 0xff) * (ushort)bVar2 + 1;

          *puVar7 = ((ushort)((uVar10 >> 8) + uVar10) & 0xffffff00) << 8 |

                    (ushort)((uVar11 >> 8) + uVar11) & 0xffffff00 |

                    (uint)((ushort)((uVar12 >> 8) + uVar12) >> 8) | uVar8 << 0x18;

          iVar9 = iVar9 + -1;

          puVar7 = puVar7 + 1;

        } while (iVar9 != 0);

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





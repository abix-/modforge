// Address: 0x140299510
// Ghidra name: FUN_140299510
// ============ 0x140299510 FUN_140299510 (size=596) ============


void FUN_140299510(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  longlong lVar6;

  longlong lVar7;

  uint *puVar8;

  uint *puVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  int iVar13;

  uint local_res18 [2];

  undefined1 local_res20 [8];

  

  lVar6 = *(longlong *)(param_1 + 0x58);

  uVar1 = *(uint *)(param_1 + 0x38);

  iVar13 = *(int *)(param_1 + 0x3c);

  puVar9 = *(uint **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  puVar8 = *(uint **)(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  lVar7 = *(longlong *)(param_1 + 0x48);

  iVar4 = *(int *)(lVar6 + 0x14);

  FUN_14017a300(lVar6,local_res18,local_res20);

  while (iVar13 != 0) {

    iVar13 = iVar13 + -1;

    if (0 < (int)uVar1) {

      uVar12 = (ulonglong)uVar1;

      if (iVar4 == 0) {

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          uVar11 = (ulonglong)

                   ((uVar5 >> (*(byte *)(lVar7 + 0x1d) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1d) & 0x1f) |

                    (uVar5 >> (*(byte *)(lVar7 + 0x1c) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1c) & 0x1f) |

                    (uVar5 >> (*(byte *)(lVar7 + 0x1e) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1e) & 0x1f) | *(uint *)(lVar6 + 0x14));

          uVar10 = ((ulonglong)*puVar8 << 0x18 | (ulonglong)*puVar8) & 0xff00ff00ff00ff;

          uVar10 = (((uVar11 << 0x18 | uVar11) & 0xff00ff00ff00ff) - uVar10) *

                   ((ulonglong)(uVar5 >> (*(byte *)(lVar7 + 0x1f) & 0x3f)) & 0xff) + 0x1000100010001

                   + uVar10 * 0xff;

          uVar10 = (uVar10 >> 8 & 0xff00ff00ff00ff) + uVar10 & 0xff00ff00ff00ff00;

          *puVar8 = (uint)(uVar10 >> 0x20) | (uint)(uVar10 >> 8) | local_res18[0];

          puVar8 = puVar8 + 1;

          uVar12 = uVar12 - 1;

        } while (uVar12 != 0);

      }

      else {

        do {

          uVar5 = *puVar9;

          puVar9 = puVar9 + 1;

          uVar11 = (ulonglong)

                   ((uVar5 >> (*(byte *)(lVar7 + 0x1d) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1d) & 0x1f) |

                    (uVar5 >> (*(byte *)(lVar7 + 0x1c) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1c) & 0x1f) |

                    (uVar5 >> (*(byte *)(lVar7 + 0x1e) & 0x1f) & 0xff) <<

                    (*(byte *)(lVar6 + 0x1e) & 0x1f) | *(uint *)(lVar6 + 0x14));

          uVar10 = ((ulonglong)*puVar8 << 0x18 | (ulonglong)*puVar8) & 0xff00ff00ff00ff;

          uVar10 = (((uVar11 << 0x18 | uVar11) & 0xff00ff00ff00ff) - uVar10) *

                   ((ulonglong)(uVar5 >> (*(byte *)(lVar7 + 0x1f) & 0x3f)) & 0xff) + 0x1000100010001

                   + uVar10 * 0xff;

          uVar10 = (uVar10 >> 8 & 0xff00ff00ff00ff) + uVar10 & 0xff00ff00ff00ff00;

          *puVar8 = (uint)(uVar10 >> 0x20) | (uint)(uVar10 >> 8);

          puVar8 = puVar8 + 1;

          uVar12 = uVar12 - 1;

        } while (uVar12 != 0);

      }

    }

    puVar9 = (uint *)((longlong)puVar9 + (longlong)iVar2);

    puVar8 = (uint *)((longlong)puVar8 + (longlong)iVar3);

  }

  return;

}





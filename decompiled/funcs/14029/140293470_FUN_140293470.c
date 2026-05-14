// Address: 0x140293470
// Ghidra name: FUN_140293470
// ============ 0x140293470 FUN_140293470 (size=373) ============


void FUN_140293470(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  ushort *puVar5;

  uint *puVar6;

  int iVar7;

  int iVar8;

  

  uVar1 = *(uint *)(param_1 + 0x38);

  puVar6 = *(uint **)(param_1 + 8);

  puVar5 = *(ushort **)(param_1 + 0x30);

  iVar2 = (int)(*(int *)(param_1 + 0x1c) + (*(int *)(param_1 + 0x1c) >> 0x1f & 3U)) >> 2;

  iVar3 = *(int *)(param_1 + 0x44) / 2;

  iVar8 = *(int *)(param_1 + 0x3c);

  while (iVar8 != 0) {

    iVar7 = uVar1 + 3;

    iVar7 = (int)((iVar7 >> 0x1f & 3U) + iVar7) >> 2;

    uVar4 = uVar1 & 3;

    if (uVar4 == 0) goto LAB_140293501;

    if (uVar4 == 1) goto LAB_140293588;

    if (uVar4 == 2) goto LAB_14029355b;

    if (uVar4 == 3) {

      while( true ) {

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 5) & 0x7e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 8) & 0xf800;

        puVar5 = puVar5 + 1;

LAB_14029355b:

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 5) & 0x7e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 8) & 0xf800;

        puVar5 = puVar5 + 1;

LAB_140293588:

        uVar4 = *puVar6;

        iVar7 = iVar7 + -1;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 5) & 0x7e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 8) & 0xf800;

        puVar5 = puVar5 + 1;

        if (iVar7 < 1) break;

LAB_140293501:

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 5) & 0x7e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 8) & 0xf800;

        puVar5 = puVar5 + 1;

      }

      puVar6 = puVar6 + iVar2;

      puVar5 = puVar5 + iVar3;

      iVar8 = iVar8 + -1;

    }

    else {

      puVar6 = puVar6 + iVar2;

      puVar5 = puVar5 + iVar3;

      iVar8 = iVar8 + -1;

    }

  }

  return;

}





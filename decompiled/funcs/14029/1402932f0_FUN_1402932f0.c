// Address: 0x1402932f0
// Ghidra name: FUN_1402932f0
// ============ 0x1402932f0 FUN_1402932f0 (size=373) ============


void FUN_1402932f0(longlong param_1)



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

    if (uVar4 == 0) goto LAB_140293381;

    if (uVar4 == 1) goto LAB_140293408;

    if (uVar4 == 2) goto LAB_1402933db;

    if (uVar4 == 3) {

      while( true ) {

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 6) & 0x3e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 9) & 0x7c00;

        puVar5 = puVar5 + 1;

LAB_1402933db:

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 6) & 0x3e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 9) & 0x7c00;

        puVar5 = puVar5 + 1;

LAB_140293408:

        uVar4 = *puVar6;

        iVar7 = iVar7 + -1;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 6) & 0x3e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 9) & 0x7c00;

        puVar5 = puVar5 + 1;

        if (iVar7 < 1) break;

LAB_140293381:

        uVar4 = *puVar6;

        puVar6 = puVar6 + 1;

        *puVar5 = (ushort)(uVar4 >> 6) & 0x3e0 | (ushort)(uVar4 >> 3) & 0x1f |

                  (ushort)(uVar4 >> 9) & 0x7c00;

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





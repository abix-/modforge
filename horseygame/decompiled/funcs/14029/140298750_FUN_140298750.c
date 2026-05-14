// Address: 0x140298750
// Ghidra name: FUN_140298750
// ============ 0x140298750 FUN_140298750 (size=279) ============


void FUN_140298750(longlong param_1,longlong param_2)



{

  byte *pbVar1;

  byte bVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  byte *pbVar8;

  uint *puVar9;

  int iVar10;

  

  uVar3 = *(uint *)(param_1 + 0x38);

  pbVar8 = *(byte **)(param_1 + 8);

  iVar4 = *(int *)(param_1 + 0x1c);

  puVar9 = *(uint **)(param_1 + 0x30);

  iVar5 = (int)(*(int *)(param_1 + 0x44) + (*(int *)(param_1 + 0x44) >> 0x1f & 3U)) >> 2;

  iVar7 = *(int *)(param_1 + 0x3c);

  while (iVar7 != 0) {

    iVar10 = uVar3 + 3;

    iVar10 = (int)((iVar10 >> 0x1f & 3U) + iVar10) >> 2;

    uVar6 = uVar3 & 3;

    if (uVar6 == 0) goto LAB_1402987ca;

    if (uVar6 == 1) goto LAB_140298821;

    if (uVar6 == 2) goto LAB_140298804;

    if (uVar6 == 3) {

      while( true ) {

        *puVar9 = *(uint *)(param_2 + 4 + (ulonglong)pbVar8[1] * 8) |

                  *(uint *)(param_2 + (ulonglong)*pbVar8 * 8);

        puVar9 = puVar9 + 1;

        pbVar8 = pbVar8 + 2;

LAB_140298804:

        *puVar9 = *(uint *)(param_2 + 4 + (ulonglong)pbVar8[1] * 8) |

                  *(uint *)(param_2 + (ulonglong)*pbVar8 * 8);

        puVar9 = puVar9 + 1;

        pbVar8 = pbVar8 + 2;

LAB_140298821:

        pbVar1 = pbVar8 + 1;

        iVar10 = iVar10 + -1;

        bVar2 = *pbVar8;

        pbVar8 = pbVar8 + 2;

        *puVar9 = *(uint *)(param_2 + 4 + (ulonglong)*pbVar1 * 8) |

                  *(uint *)(param_2 + (ulonglong)bVar2 * 8);

        puVar9 = puVar9 + 1;

        if (iVar10 < 1) break;

LAB_1402987ca:

        *puVar9 = *(uint *)(param_2 + 4 + (ulonglong)pbVar8[1] * 8) |

                  *(uint *)(param_2 + (ulonglong)*pbVar8 * 8);

        puVar9 = puVar9 + 1;

        pbVar8 = pbVar8 + 2;

      }

      pbVar8 = pbVar8 + iVar4;

      puVar9 = puVar9 + iVar5;

      iVar7 = iVar7 + -1;

    }

    else {

      pbVar8 = pbVar8 + iVar4;

      puVar9 = puVar9 + iVar5;

      iVar7 = iVar7 + -1;

    }

  }

  return;

}





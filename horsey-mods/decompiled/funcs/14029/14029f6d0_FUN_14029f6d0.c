// Address: 0x14029f6d0
// Ghidra name: FUN_14029f6d0
// ============ 0x14029f6d0 FUN_14029f6d0 (size=405) ============


void FUN_14029f6d0(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint *puVar6;

  uint *puVar7;

  int iVar8;

  

  uVar1 = *(uint *)(param_1 + 0x38);

  puVar7 = *(uint **)(param_1 + 8);

  puVar6 = *(uint **)(param_1 + 0x30);

  iVar5 = *(int *)(param_1 + 0x1c) >> 2;

  iVar4 = *(int *)(param_1 + 0x44) >> 2;

  iVar3 = *(int *)(param_1 + 0x3c);

  while (iVar3 != 0) {

    iVar8 = uVar1 + 3;

    iVar8 = (int)((iVar8 >> 0x1f & 3U) + iVar8) >> 2;

    uVar2 = uVar1 & 3;

    if (uVar2 == 0) goto LAB_14029f749;

    if (uVar2 == 1) goto LAB_14029f7f7;

    if (uVar2 == 2) goto LAB_14029f7bd;

    if (uVar2 == 3) {

      while( true ) {

        uVar2 = *puVar7;

        puVar7 = puVar7 + 1;

        *puVar6 = ((*puVar6 & 0xfefefe) + (uVar2 & 0xfefefe) >> 1) + (*puVar6 & uVar2 & 0x10101) |

                  0xff000000;

        puVar6 = puVar6 + 1;

LAB_14029f7bd:

        uVar2 = *puVar7;

        puVar7 = puVar7 + 1;

        *puVar6 = ((*puVar6 & 0xfefefe) + (uVar2 & 0xfefefe) >> 1) + (*puVar6 & uVar2 & 0x10101) |

                  0xff000000;

        puVar6 = puVar6 + 1;

LAB_14029f7f7:

        uVar2 = *puVar7;

        iVar8 = iVar8 + -1;

        puVar7 = puVar7 + 1;

        *puVar6 = ((*puVar6 & 0xfefefe) + (uVar2 & 0xfefefe) >> 1) + (*puVar6 & uVar2 & 0x10101) |

                  0xff000000;

        puVar6 = puVar6 + 1;

        if (iVar8 < 1) break;

LAB_14029f749:

        uVar2 = *puVar7;

        puVar7 = puVar7 + 1;

        *puVar6 = ((*puVar6 & 0xfefefe) + (uVar2 & 0xfefefe) >> 1) + (*puVar6 & uVar2 & 0x10101) |

                  0xff000000;

        puVar6 = puVar6 + 1;

      }

      puVar7 = puVar7 + iVar5;

      puVar6 = puVar6 + iVar4;

      iVar3 = iVar3 + -1;

    }

    else {

      puVar7 = puVar7 + iVar5;

      puVar6 = puVar6 + iVar4;

      iVar3 = iVar3 + -1;

    }

  }

  return;

}





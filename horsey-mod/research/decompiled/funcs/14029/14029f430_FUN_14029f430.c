// Address: 0x14029f430
// Ghidra name: FUN_14029f430
// ============ 0x14029f430 FUN_14029f430 (size=657) ============


void FUN_14029f430(longlong param_1)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  ulonglong uVar6;

  uint *puVar7;

  uint *puVar8;

  ulonglong uVar9;

  int iVar10;

  

  uVar9 = (ulonglong)*(byte *)(param_1 + 0x83);

  if (*(byte *)(param_1 + 0x83) == 0x80) {

    FUN_14029f6d0();

    return;

  }

  puVar8 = *(uint **)(param_1 + 8);

  puVar7 = *(uint **)(param_1 + 0x30);

  uVar1 = *(uint *)(param_1 + 0x38);

  iVar4 = *(int *)(param_1 + 0x1c) >> 2;

  iVar10 = *(int *)(param_1 + 0x44) >> 2;

  iVar3 = *(int *)(param_1 + 0x3c);

  while (iVar3 != 0) {

    iVar5 = uVar1 + 3;

    iVar5 = (int)((iVar5 >> 0x1f & 3U) + iVar5) >> 2;

    uVar2 = uVar1 & 3;

    if (uVar2 == 0) goto LAB_14029f4f7;

    if (uVar2 == 1) goto LAB_14029f617;

    if (uVar2 == 2) goto LAB_14029f5b7;

    if (uVar2 == 3) {

      while( true ) {

        uVar2 = *puVar8;

        puVar8 = puVar8 + 1;

        uVar6 = ((ulonglong)*puVar7 << 0x18 | (ulonglong)*puVar7) & 0xff00ff00ff00ff;

        uVar6 = ((((ulonglong)uVar2 << 0x18 | (ulonglong)uVar2) & 0xff00ff00ff00ff) - uVar6) * uVar9

                + 0x1000100010001 + uVar6 * 0xff;

        uVar6 = (uVar6 >> 8 & 0xff00ff00ff00ff) + uVar6 & 0xff00ff00ff00ff00;

        *puVar7 = (uint)(uVar6 >> 0x20) | (uint)(uVar6 >> 8) | 0xff000000;

        puVar7 = puVar7 + 1;

LAB_14029f5b7:

        uVar2 = *puVar8;

        puVar8 = puVar8 + 1;

        uVar6 = ((ulonglong)*puVar7 << 0x18 | (ulonglong)*puVar7) & 0xff00ff00ff00ff;

        uVar6 = ((((ulonglong)uVar2 << 0x18 | (ulonglong)uVar2) & 0xff00ff00ff00ff) - uVar6) * uVar9

                + 0x1000100010001 + uVar6 * 0xff;

        uVar6 = (uVar6 >> 8 & 0xff00ff00ff00ff) + uVar6 & 0xff00ff00ff00ff00;

        *puVar7 = (uint)(uVar6 >> 0x20) | (uint)(uVar6 >> 8) | 0xff000000;

        puVar7 = puVar7 + 1;

LAB_14029f617:

        uVar2 = *puVar8;

        iVar5 = iVar5 + -1;

        uVar6 = ((ulonglong)*puVar7 << 0x18 | (ulonglong)*puVar7) & 0xff00ff00ff00ff;

        puVar8 = puVar8 + 1;

        uVar6 = ((((ulonglong)uVar2 << 0x18 | (ulonglong)uVar2) & 0xff00ff00ff00ff) - uVar6) * uVar9

                + 0x1000100010001 + uVar6 * 0xff;

        uVar6 = (uVar6 >> 8 & 0xff00ff00ff00ff) + uVar6 & 0xff00ff00ff00ff00;

        *puVar7 = (uint)(uVar6 >> 0x20) | (uint)(uVar6 >> 8) | 0xff000000;

        puVar7 = puVar7 + 1;

        if (iVar5 < 1) break;

LAB_14029f4f7:

        uVar2 = *puVar8;

        puVar8 = puVar8 + 1;

        uVar6 = ((ulonglong)*puVar7 << 0x18 | (ulonglong)*puVar7) & 0xff00ff00ff00ff;

        uVar6 = ((((ulonglong)uVar2 << 0x18 | (ulonglong)uVar2) & 0xff00ff00ff00ff) - uVar6) * uVar9

                + 0x1000100010001 + uVar6 * 0xff;

        uVar6 = (uVar6 >> 8 & 0xff00ff00ff00ff) + uVar6 & 0xff00ff00ff00ff00;

        *puVar7 = (uint)(uVar6 >> 0x20) | (uint)(uVar6 >> 8) | 0xff000000;

        puVar7 = puVar7 + 1;

      }

      puVar8 = puVar8 + iVar4;

      puVar7 = puVar7 + iVar10;

      iVar3 = iVar3 + -1;

    }

    else {

      puVar8 = puVar8 + iVar4;

      puVar7 = puVar7 + iVar10;

      iVar3 = iVar3 + -1;

    }

  }

  return;

}





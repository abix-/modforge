// Address: 0x140291000
// Ghidra name: FUN_140291000
// ============ 0x140291000 FUN_140291000 (size=367) ============


void FUN_140291000(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  undefined1 *puVar9;

  byte *pbVar10;

  

  uVar1 = *(uint *)(param_1 + 0x38);

  pbVar10 = *(byte **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x1c);

  puVar9 = *(undefined1 **)(param_1 + 0x30);

  iVar3 = *(int *)(param_1 + 0x44);

  lVar5 = *(longlong *)(param_1 + 0x68);

  uVar4 = *(uint *)(param_1 + 0x7c);

  iVar8 = *(int *)(param_1 + 0x3c);

  while (iVar8 != 0) {

    iVar7 = uVar1 + 3;

    iVar7 = (int)((iVar7 >> 0x1f & 3U) + iVar7) >> 2;

    uVar6 = uVar1 & 3;

    if (uVar6 == 0) goto LAB_14029106f;

    if (uVar6 == 1) goto LAB_14029110e;

    if (uVar6 == 2) goto LAB_1402910d9;

    if (uVar6 == 3) {

      while( true ) {

        if (*pbVar10 != uVar4) {

          uVar6 = (uint)*pbVar10 * 4;

          *puVar9 = *(undefined1 *)((ulonglong)uVar6 + lVar5);

          puVar9[1] = *(undefined1 *)((ulonglong)uVar6 + 1 + lVar5);

          puVar9[2] = *(undefined1 *)((ulonglong)uVar6 + 2 + lVar5);

        }

        pbVar10 = pbVar10 + 1;

        puVar9 = puVar9 + 3;

LAB_1402910d9:

        if (*pbVar10 != uVar4) {

          uVar6 = (uint)*pbVar10 * 4;

          *puVar9 = *(undefined1 *)((ulonglong)uVar6 + lVar5);

          puVar9[1] = *(undefined1 *)((ulonglong)uVar6 + 1 + lVar5);

          puVar9[2] = *(undefined1 *)((ulonglong)uVar6 + 2 + lVar5);

        }

        pbVar10 = pbVar10 + 1;

        puVar9 = puVar9 + 3;

LAB_14029110e:

        if (*pbVar10 != uVar4) {

          uVar6 = (uint)*pbVar10 * 4;

          *puVar9 = *(undefined1 *)((ulonglong)uVar6 + lVar5);

          puVar9[1] = *(undefined1 *)((ulonglong)uVar6 + 1 + lVar5);

          puVar9[2] = *(undefined1 *)((ulonglong)uVar6 + 2 + lVar5);

        }

        pbVar10 = pbVar10 + 1;

        puVar9 = puVar9 + 3;

        iVar7 = iVar7 + -1;

        if (iVar7 < 1) break;

LAB_14029106f:

        if (*pbVar10 != uVar4) {

          uVar6 = (uint)*pbVar10 * 4;

          *puVar9 = *(undefined1 *)((ulonglong)uVar6 + lVar5);

          puVar9[1] = *(undefined1 *)((ulonglong)uVar6 + 1 + lVar5);

          puVar9[2] = *(undefined1 *)((ulonglong)uVar6 + 2 + lVar5);

        }

        pbVar10 = pbVar10 + 1;

        puVar9 = puVar9 + 3;

      }

      pbVar10 = pbVar10 + iVar2;

      puVar9 = puVar9 + iVar3;

      iVar8 = iVar8 + -1;

    }

    else {

      pbVar10 = pbVar10 + iVar2;

      puVar9 = puVar9 + iVar3;

      iVar8 = iVar8 + -1;

    }

  }

  return;

}





// Address: 0x140290ea0
// Ghidra name: FUN_140290ea0
// ============ 0x140290ea0 FUN_140290ea0 (size=337) ============


void FUN_140290ea0(longlong param_1)



{

  byte bVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  uint uVar6;

  int iVar7;

  undefined1 *puVar8;

  byte *pbVar9;

  int iVar10;

  

  uVar2 = *(uint *)(param_1 + 0x38);

  pbVar9 = *(byte **)(param_1 + 8);

  iVar3 = *(int *)(param_1 + 0x1c);

  puVar8 = *(undefined1 **)(param_1 + 0x30);

  iVar4 = *(int *)(param_1 + 0x44);

  lVar5 = *(longlong *)(param_1 + 0x68);

  iVar7 = *(int *)(param_1 + 0x3c);

  while (iVar7 != 0) {

    iVar10 = uVar2 + 3;

    iVar10 = (int)((iVar10 >> 0x1f & 3U) + iVar10) >> 2;

    uVar6 = uVar2 & 3;

    if (uVar6 == 0) goto LAB_140290f0d;

    if (uVar6 == 1) goto LAB_140290f97;

    if (uVar6 == 2) goto LAB_140290f69;

    if (uVar6 == 3) {

      while( true ) {

        bVar1 = *pbVar9;

        pbVar9 = pbVar9 + 1;

        *puVar8 = *(undefined1 *)((ulonglong)bVar1 * 4 + lVar5);

        puVar8[1] = *(undefined1 *)((ulonglong)bVar1 * 4 + 1 + lVar5);

        puVar8[2] = *(undefined1 *)(lVar5 + 2 + (ulonglong)bVar1 * 4);

        puVar8 = puVar8 + 3;

LAB_140290f69:

        bVar1 = *pbVar9;

        pbVar9 = pbVar9 + 1;

        *puVar8 = *(undefined1 *)((ulonglong)bVar1 * 4 + lVar5);

        puVar8[1] = *(undefined1 *)((ulonglong)bVar1 * 4 + 1 + lVar5);

        puVar8[2] = *(undefined1 *)(lVar5 + 2 + (ulonglong)bVar1 * 4);

        puVar8 = puVar8 + 3;

LAB_140290f97:

        bVar1 = *pbVar9;

        iVar10 = iVar10 + -1;

        pbVar9 = pbVar9 + 1;

        *puVar8 = *(undefined1 *)((ulonglong)bVar1 * 4 + lVar5);

        puVar8[1] = *(undefined1 *)((ulonglong)bVar1 * 4 + 1 + lVar5);

        puVar8[2] = *(undefined1 *)(lVar5 + 2 + (ulonglong)bVar1 * 4);

        puVar8 = puVar8 + 3;

        if (iVar10 < 1) break;

LAB_140290f0d:

        bVar1 = *pbVar9;

        pbVar9 = pbVar9 + 1;

        *puVar8 = *(undefined1 *)((ulonglong)bVar1 * 4 + lVar5);

        puVar8[1] = *(undefined1 *)((ulonglong)bVar1 * 4 + 1 + lVar5);

        puVar8[2] = *(undefined1 *)(lVar5 + 2 + (ulonglong)bVar1 * 4);

        puVar8 = puVar8 + 3;

      }

      pbVar9 = pbVar9 + iVar3;

      puVar8 = puVar8 + iVar4;

      iVar7 = iVar7 + -1;

    }

    else {

      pbVar9 = pbVar9 + iVar3;

      puVar8 = puVar8 + iVar4;

      iVar7 = iVar7 + -1;

    }

  }

  return;

}





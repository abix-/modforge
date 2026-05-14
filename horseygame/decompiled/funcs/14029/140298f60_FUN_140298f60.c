// Address: 0x140298f60
// Ghidra name: FUN_140298f60
// ============ 0x140298f60 FUN_140298f60 (size=563) ============


void FUN_140298f60(longlong param_1)



{

  byte bVar1;

  undefined2 uVar2;

  uint uVar3;

  ushort *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  undefined2 *puVar9;

  uint uVar10;

  int iVar11;

  

  bVar1 = *(byte *)(param_1 + 0x83);

  if (bVar1 == 0x80) {

    FUN_140298cc0(param_1,0xfbde);

    return;

  }

  puVar9 = *(undefined2 **)(param_1 + 8);

  uVar3 = *(uint *)(param_1 + 0x38);

  puVar4 = *(ushort **)(param_1 + 0x30);

  iVar11 = *(int *)(param_1 + 0x44) >> 1;

  iVar6 = *(int *)(param_1 + 0x1c) >> 1;

  iVar7 = *(int *)(param_1 + 0x3c);

  while (iVar7 != 0) {

    iVar5 = uVar3 + 3;

    iVar5 = (int)((iVar5 >> 0x1f & 3U) + iVar5) >> 2;

    uVar8 = uVar3 & 3;

    uVar10 = (uint)(bVar1 >> 3);

    if (uVar8 == 0) goto LAB_14029900c;

    if (uVar8 == 1) goto LAB_140299105;

    if (uVar8 == 2) goto LAB_1402990b2;

    if (uVar8 == 3) {

      while( true ) {

        uVar2 = *puVar9;

        uVar8 = CONCAT22(*puVar4,*puVar4) & 0x3e07c1f;

        puVar9 = puVar9 + 1;

        uVar8 = (((CONCAT22(uVar2,uVar2) & 0x3e07c1f) - uVar8) * uVar10 >> 5) + uVar8 & 0x3e07c1f;

        *puVar4 = (ushort)(uVar8 >> 0x10) | (ushort)uVar8;

        puVar4 = puVar4 + 1;

LAB_1402990b2:

        uVar2 = *puVar9;

        uVar8 = CONCAT22(*puVar4,*puVar4) & 0x3e07c1f;

        puVar9 = puVar9 + 1;

        uVar8 = (((CONCAT22(uVar2,uVar2) & 0x3e07c1f) - uVar8) * uVar10 >> 5) + uVar8 & 0x3e07c1f;

        *puVar4 = (ushort)(uVar8 >> 0x10) | (ushort)uVar8;

        puVar4 = puVar4 + 1;

LAB_140299105:

        iVar5 = iVar5 + -1;

        uVar2 = *puVar9;

        uVar8 = CONCAT22(*puVar4,*puVar4) & 0x3e07c1f;

        puVar9 = puVar9 + 1;

        uVar8 = (((CONCAT22(uVar2,uVar2) & 0x3e07c1f) - uVar8) * uVar10 >> 5) + uVar8 & 0x3e07c1f;

        *puVar4 = (ushort)(uVar8 >> 0x10) | (ushort)uVar8;

        puVar4 = puVar4 + 1;

        if (iVar5 < 1) break;

LAB_14029900c:

        uVar2 = *puVar9;

        uVar8 = CONCAT22(*puVar4,*puVar4) & 0x3e07c1f;

        puVar9 = puVar9 + 1;

        uVar8 = (((CONCAT22(uVar2,uVar2) & 0x3e07c1f) - uVar8) * uVar10 >> 5) + uVar8 & 0x3e07c1f;

        *puVar4 = (ushort)(uVar8 >> 0x10) | (ushort)uVar8;

        puVar4 = puVar4 + 1;

      }

      puVar9 = puVar9 + iVar6;

      puVar4 = puVar4 + iVar11;

      iVar7 = iVar7 + -1;

    }

    else {

      puVar9 = puVar9 + iVar6;

      puVar4 = puVar4 + iVar11;

      iVar7 = iVar7 + -1;

    }

  }

  return;

}





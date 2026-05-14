// Address: 0x1402949f0
// Ghidra name: FUN_1402949f0
// ============ 0x1402949f0 FUN_1402949f0 (size=547) ============


void FUN_1402949f0(longlong param_1)



{

  undefined1 uVar1;

  undefined1 uVar2;

  uint uVar3;

  longlong lVar4;

  uint3 uVar5;

  uint uVar6;

  int iVar7;

  longlong lVar8;

  int iVar9;

  uint3 *puVar10;

  uint *puVar11;

  ulonglong uVar12;

  uint uVar13;

  ulonglong uVar14;

  longlong lVar15;

  

  uVar3 = *(uint *)(param_1 + 0x38);

  puVar10 = *(uint3 **)(param_1 + 8);

  lVar8 = (longlong)*(int *)(param_1 + 0x1c);

  puVar11 = *(uint **)(param_1 + 0x30);

  lVar15 = (longlong)*(int *)(param_1 + 0x44);

  lVar4 = *(longlong *)(param_1 + 0x58);

  uVar12 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x48) + 5);

  uVar14 = (ulonglong)*(byte *)(lVar4 + 5);

  iVar9 = *(int *)(param_1 + 0x3c);

  if (*(int *)(lVar4 + 0x14) == 0) {

    while (iVar9 != 0) {

      iVar7 = (int)(((int)(uVar3 + 3) >> 0x1f & 3U) + uVar3 + 3) >> 2;

      uVar13 = uVar3 & 3;

      if (uVar13 == 0) goto LAB_140294b6b;

      if (uVar13 == 1) goto LAB_140294bc8;

      if (uVar13 == 2) goto LAB_140294ba9;

      if (uVar13 == 3) {

        while( true ) {

          uVar1 = *(undefined1 *)((longlong)puVar10 + 1);

          uVar2 = *(undefined1 *)((longlong)puVar10 + 2);

          *(char *)puVar11 = (char)*puVar10;

          *(undefined1 *)((longlong)puVar11 + 1) = uVar1;

          *(undefined1 *)((longlong)puVar11 + 2) = uVar2;

          puVar11 = (uint *)((longlong)puVar11 + uVar14);

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

LAB_140294ba9:

          uVar1 = *(undefined1 *)((longlong)puVar10 + 1);

          uVar2 = *(undefined1 *)((longlong)puVar10 + 2);

          *(char *)puVar11 = (char)*puVar10;

          *(undefined1 *)((longlong)puVar11 + 1) = uVar1;

          *(undefined1 *)((longlong)puVar11 + 2) = uVar2;

          puVar11 = (uint *)((longlong)puVar11 + uVar14);

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

LAB_140294bc8:

          uVar5 = *puVar10;

          iVar7 = iVar7 + -1;

          uVar1 = *(undefined1 *)((longlong)puVar10 + 1);

          uVar2 = *(undefined1 *)((longlong)puVar10 + 2);

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

          *(char *)puVar11 = (char)uVar5;

          *(undefined1 *)((longlong)puVar11 + 1) = uVar1;

          *(undefined1 *)((longlong)puVar11 + 2) = uVar2;

          puVar11 = (uint *)((longlong)puVar11 + uVar14);

          if (iVar7 < 1) break;

LAB_140294b6b:

          uVar1 = *(undefined1 *)((longlong)puVar10 + 1);

          uVar2 = *(undefined1 *)((longlong)puVar10 + 2);

          *(char *)puVar11 = (char)*puVar10;

          *(undefined1 *)((longlong)puVar11 + 1) = uVar1;

          *(undefined1 *)((longlong)puVar11 + 2) = uVar2;

          puVar11 = (uint *)((longlong)puVar11 + uVar14);

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

        }

        puVar10 = (uint3 *)((longlong)puVar10 + lVar8);

        puVar11 = (uint *)((longlong)puVar11 + lVar15);

        iVar9 = iVar9 + -1;

      }

      else {

        puVar10 = (uint3 *)((longlong)puVar10 + lVar8);

        puVar11 = (uint *)((longlong)puVar11 + lVar15);

        iVar9 = iVar9 + -1;

      }

    }

  }

  else {

    uVar13 = (uint)*(byte *)(param_1 + 0x83) << (*(byte *)(lVar4 + 0x1f) & 0x1f);

    while (iVar9 != 0) {

      iVar7 = (int)(((int)(uVar3 + 3) >> 0x1f & 3U) + uVar3 + 3) >> 2;

      uVar6 = uVar3 & 3;

      if (uVar6 == 0) goto LAB_140294a8b;

      if (uVar6 == 1) goto LAB_140294afa;

      if (uVar6 == 2) goto LAB_140294ad5;

      if (uVar6 == 3) {

        while( true ) {

          *puVar11 = *puVar10 | uVar13;

          puVar11 = puVar11 + 1;

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

LAB_140294ad5:

          *puVar11 = *puVar10 | uVar13;

          puVar11 = puVar11 + 1;

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

LAB_140294afa:

          iVar7 = iVar7 + -1;

          uVar5 = *puVar10;

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

          *puVar11 = uVar5 | uVar13;

          puVar11 = puVar11 + 1;

          if (iVar7 < 1) break;

LAB_140294a8b:

          *puVar11 = *puVar10 | uVar13;

          puVar11 = puVar11 + 1;

          puVar10 = (uint3 *)((longlong)puVar10 + uVar12);

        }

        puVar10 = (uint3 *)((longlong)puVar10 + lVar8);

        puVar11 = (uint *)((longlong)puVar11 + lVar15);

        iVar9 = iVar9 + -1;

      }

      else {

        puVar10 = (uint3 *)((longlong)puVar10 + lVar8);

        puVar11 = (uint *)((longlong)puVar11 + lVar15);

        iVar9 = iVar9 + -1;

      }

    }

  }

  return;

}





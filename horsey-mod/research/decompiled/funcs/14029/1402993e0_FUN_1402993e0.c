// Address: 0x1402993e0
// Ghidra name: FUN_1402993e0
// ============ 0x1402993e0 FUN_1402993e0 (size=292) ============


void FUN_1402993e0(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  uint *puVar6;

  ulonglong uVar7;

  int iVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  uint *puVar11;

  

  iVar8 = *(int *)(param_1 + 0x3c);

  uVar1 = *(uint *)(param_1 + 0x38);

  puVar11 = *(uint **)(param_1 + 8);

  puVar6 = *(uint **)(param_1 + 0x30);

  lVar5 = *(longlong *)(param_1 + 0x48);

  if (iVar8 != 0) {

    iVar2 = *(int *)(param_1 + 0x1c);

    iVar3 = *(int *)(param_1 + 0x44);

    do {

      iVar8 = iVar8 + -1;

      uVar9 = (ulonglong)uVar1;

      if (0 < (int)uVar1) {

        do {

          uVar4 = *puVar11;

          puVar11 = puVar11 + 1;

          uVar7 = (ulonglong)(*(uint *)(lVar5 + 0x14) | uVar4);

          uVar10 = ((ulonglong)*puVar6 << 0x18 | (ulonglong)*puVar6) & 0xff00ff00ff00ff;

          uVar7 = (((uVar7 << 0x18 | uVar7) & 0xff00ff00ff00ff) - uVar10) *

                  ((ulonglong)(uVar4 >> (*(byte *)(lVar5 + 0x1f) & 0x3f)) & 0xff) + 0x1000100010001

                  + uVar10 * 0xff;

          uVar7 = (uVar7 >> 8 & 0xff00ff00ff00ff) + uVar7 & 0xff00ff00ff00ff00;

          *puVar6 = (uint)(uVar7 >> 0x20) | (uint)(uVar7 >> 8);

          puVar6 = puVar6 + 1;

          uVar9 = uVar9 - 1;

        } while (uVar9 != 0);

      }

      puVar11 = (uint *)((longlong)puVar11 + (longlong)iVar2);

      puVar6 = (uint *)((longlong)puVar6 + (longlong)iVar3);

    } while (iVar8 != 0);

  }

  return;

}





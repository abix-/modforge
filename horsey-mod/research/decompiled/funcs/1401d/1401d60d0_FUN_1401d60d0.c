// Address: 0x1401d60d0
// Ghidra name: FUN_1401d60d0
// ============ 0x1401d60d0 FUN_1401d60d0 (size=291) ============


undefined8

FUN_1401d60d0(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6)



{

  undefined1 *puVar1;

  int iVar2;

  uint uVar3;

  ushort uVar4;

  int iVar5;

  int iVar6;

  ulonglong uVar7;

  ushort *puVar8;

  int iVar9;

  int iVar10;

  ushort *puVar11;

  

  iVar5 = (param_1 + 1) / 2;

  iVar6 = (param_2 + 1) / 2;

  puVar11 = (ushort *)(param_2 * param_4 + param_3);

  puVar8 = (ushort *)(param_5 + param_2 * param_6);

  iVar2 = ((param_4 + 1) / 2 - iVar5) * 2;

  uVar3 = ((param_6 + 1) / 2 - iVar5) * 2;

  uVar7 = (ulonglong)uVar3;

  if ((~((uint)puVar8 | (uint)puVar11) & 1) == 0) {

    if (iVar6 != 0) {

      do {

        iVar6 = iVar6 + -1;

        for (iVar10 = iVar5; iVar10 != 0; iVar10 = iVar10 + -1) {

          puVar1 = (undefined1 *)((longlong)puVar11 + 1);

          uVar7 = 0;

          uVar4 = *puVar11;

          puVar11 = puVar11 + 1;

          *(undefined1 *)puVar8 = *puVar1;

          *(char *)((longlong)puVar8 + 1) = (char)uVar4;

          puVar8 = puVar8 + 1;

        }

        puVar11 = (ushort *)((longlong)puVar11 + (longlong)iVar2);

        puVar8 = (ushort *)((longlong)puVar8 + (longlong)(int)uVar3);

      } while (iVar6 != 0);

    }

  }

  else {

    uVar7 = (ulonglong)(longlong)(int)uVar3 >> 1;

    if (iVar6 != 0) {

      iVar10 = (int)uVar7;

      do {

        iVar6 = iVar6 + -1;

        for (iVar9 = iVar5; iVar9 != 0; iVar9 = iVar9 + -1) {

          uVar4 = *puVar11;

          puVar11 = puVar11 + 1;

          uVar4 = uVar4 >> 8 | uVar4 << 8;

          uVar7 = (ulonglong)uVar4;

          *puVar8 = uVar4;

          puVar8 = puVar8 + 1;

        }

        puVar11 = puVar11 + (int)((ulonglong)(longlong)iVar2 >> 1);

        puVar8 = puVar8 + iVar10;

      } while (iVar6 != 0);

      return CONCAT71((int7)(uVar7 >> 8),1);

    }

  }

  return CONCAT71((int7)(uVar7 >> 8),1);

}





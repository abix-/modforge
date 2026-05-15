// Address: 0x1401d4c40
// Ghidra name: FUN_1401d4c40
// ============ 0x1401d4c40 FUN_1401d4c40 (size=319) ============


undefined8

FUN_1401d4c40(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6,

             char param_7)



{

  undefined1 uVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined1 *puVar6;

  undefined1 *puVar7;

  undefined1 *puVar8;

  uint uVar9;

  ulonglong uVar10;

  undefined1 *puVar11;

  

  iVar3 = (param_1 + 1) / 2;

  puVar6 = (undefined1 *)0x0;

  iVar4 = (param_2 + 1) / 2;

  uVar10 = (ulonglong)iVar4;

  puVar11 = (undefined1 *)(param_3 + param_2 * param_4);

  iVar5 = (param_4 + 1) / 2;

  puVar8 = (undefined1 *)(param_5 + param_2 * param_6);

  if (puVar11 == puVar8) {

    lVar2 = (longlong)iVar5 * uVar10 * 2;

    puVar6 = (undefined1 *)FUN_1401841f0(lVar2);

    if (puVar6 == (undefined1 *)0x0) {

      return 0;

    }

    FUN_1402f8e20(puVar6,puVar11,lVar2);

    puVar11 = puVar6;

  }

  if (iVar4 != 0) {

    puVar7 = puVar11 + iVar5 * iVar4;

    if (param_7 == '\0') {

      puVar7 = puVar11;

      puVar11 = puVar11 + iVar5 * iVar4;

    }

    do {

      uVar9 = (int)uVar10 - 1;

      uVar10 = (ulonglong)uVar9;

      for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {

        uVar1 = *puVar7;

        puVar7 = puVar7 + 1;

        *puVar8 = uVar1;

        uVar1 = *puVar11;

        puVar11 = puVar11 + 1;

        puVar8[1] = uVar1;

        puVar8 = puVar8 + 2;

      }

      puVar7 = puVar7 + (iVar5 - iVar3);

      puVar11 = puVar11 + (iVar5 - iVar3);

      puVar8 = puVar8 + ((param_6 + 1) / 2 - iVar3) * 2;

    } while (uVar9 != 0);

  }

  FUN_1401841e0(puVar6);

  return 1;

}





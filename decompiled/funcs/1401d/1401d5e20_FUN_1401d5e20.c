// Address: 0x1401d5e20
// Ghidra name: FUN_1401d5e20
// ============ 0x1401d5e20 FUN_1401d5e20 (size=319) ============


undefined8

FUN_1401d5e20(int param_1,int param_2,longlong param_3,int param_4,longlong param_5,int param_6,

             char param_7)



{

  undefined1 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  undefined1 *puVar6;

  undefined1 *puVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  ulonglong uVar11;

  undefined1 *puVar12;

  undefined1 *puVar13;

  

  iVar3 = (param_1 + 1) / 2;

  iVar4 = (param_2 + 1) / 2;

  uVar11 = (ulonglong)iVar4;

  iVar2 = ((param_4 + 1) / 2) * 2;

  iVar5 = (param_6 + 1) / 2;

  iVar8 = iVar5 - iVar3;

  puVar7 = (undefined1 *)(param_3 + param_2 * param_4);

  puVar12 = (undefined1 *)(param_2 * param_6 + param_5);

  puVar6 = puVar7;

  puVar13 = (undefined1 *)0x0;

  if (puVar7 == puVar12) {

    lVar9 = (longlong)iVar2 * uVar11;

    puVar6 = (undefined1 *)FUN_1401841f0(lVar9);

    if (puVar6 == (undefined1 *)0x0) {

      return 0;

    }

    FUN_1402f8e20(puVar6,puVar7,lVar9);

    puVar13 = puVar6;

  }

  if (iVar4 != 0) {

    puVar7 = puVar12 + iVar5 * iVar4;

    if (param_7 == '\0') {

      puVar7 = puVar12;

      puVar12 = puVar12 + iVar5 * iVar4;

    }

    do {

      uVar10 = (int)uVar11 - 1;

      uVar11 = (ulonglong)uVar10;

      for (iVar4 = iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar7 = *puVar6;

        puVar7 = puVar7 + 1;

        puVar1 = puVar6 + 1;

        puVar6 = puVar6 + 2;

        *puVar12 = *puVar1;

        puVar12 = puVar12 + 1;

      }

      puVar6 = puVar6 + (iVar2 + iVar3 * -2);

      puVar7 = puVar7 + iVar8;

      puVar12 = puVar12 + iVar8;

    } while (uVar10 != 0);

  }

  FUN_1401841e0(puVar13);

  return 1;

}





// Address: 0x14019c3f0
// Ghidra name: FUN_14019c3f0
// ============ 0x14019c3f0 FUN_14019c3f0 (size=528) ============


undefined8 FUN_14019c3f0(undefined8 *param_1,longlong param_2)



{

  undefined1 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  undefined1 *puVar9;

  undefined1 *puVar10;

  undefined1 *puVar11;

  uint uVar12;

  uint uVar13;

  

  piVar8 = (int *)*param_1;

  uVar13 = 0;

  if (*(int *)(param_2 + 8) == *piVar8) {

    FUN_1402f8e20(*(undefined8 *)(param_2 + 0x10),param_1[0x8da],piVar8[1] * *piVar8);

  }

  else {

    uVar12 = 0;

    if (piVar8[1] != 0) {

      do {

        FUN_1402f8e20((ulonglong)(uVar12 * *(int *)(param_2 + 8)) + *(longlong *)(param_2 + 0x10),

                      (ulonglong)(*piVar8 * uVar12) + param_1[0x8da],*piVar8);

        piVar8 = (int *)*param_1;

        uVar12 = uVar12 + 1;

      } while (uVar12 < (uint)piVar8[1]);

    }

  }

  piVar8 = (int *)*param_1;

  if (piVar8[2] != 3) {

    if ((piVar8[1] + 1U & 0xfffffffe) != 0) {

      do {

        FUN_1402f94c0((ulonglong)(uVar13 * *(int *)(param_2 + 8)) + *(longlong *)(param_2 + 0x18),

                      0x80808080,*piVar8 + 1U & 0xfffffffe);

        piVar8 = (int *)*param_1;

        uVar13 = uVar13 + 1;

      } while (uVar13 < piVar8[1] + 1U >> 1);

    }

    return *(undefined8 *)(param_2 + 0x10);

  }

  iVar2 = *(int *)(param_1 + 0x8d1);

  iVar3 = *(int *)((longlong)param_1 + 0x468c);

  iVar4 = *(int *)((longlong)param_1 + 0x4704);

  uVar13 = 0;

  iVar5 = *(int *)(param_1 + 0x8e1);

  iVar6 = *(int *)((longlong)param_1 + 0x4764);

  iVar7 = *(int *)(param_1 + 0x8ed);

  if ((piVar8[1] + 1U & 0xfffffffe) != 0) {

    do {

      uVar12 = 0;

      puVar10 = (undefined1 *)

                ((ulonglong)((3 - iVar3 / iVar5) * uVar13 * *(int *)((longlong)param_1 + 0x471c)) +

                param_1[0x8e6]);

      puVar11 = (undefined1 *)

                ((ulonglong)((3 - iVar3 / iVar7) * *(int *)((longlong)param_1 + 0x477c) * uVar13) +

                param_1[0x8f2]);

      if ((*piVar8 + 1U & 0xfffffffe) != 0) {

        puVar9 = (undefined1 *)

                 ((ulonglong)(uVar13 * *(int *)(param_2 + 8)) + *(longlong *)(param_2 + 0x18));

        do {

          uVar1 = *puVar10;

          puVar10 = puVar10 + (3 - iVar2 / iVar4);

          *puVar9 = uVar1;

          uVar12 = uVar12 + 1;

          puVar9[1] = *puVar11;

          puVar11 = puVar11 + (3 - iVar2 / iVar6);

          piVar8 = (int *)*param_1;

          puVar9 = puVar9 + 2;

        } while (uVar12 < *piVar8 + 1U >> 1);

      }

      uVar13 = uVar13 + 1;

    } while (uVar13 < piVar8[1] + 1U >> 1);

  }

  return *(undefined8 *)(param_2 + 0x10);

}





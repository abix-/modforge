// Address: 0x1401ab630
// Ghidra name: FUN_1401ab630
// ============ 0x1401ab630 FUN_1401ab630 (size=290) ============


undefined8 * FUN_1401ab630(undefined8 *param_1,longlong param_2,uint param_3,uint *param_4)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  uint uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  uint uVar7;

  uint uVar9;

  uint uVar10;

  undefined8 *puVar11;

  undefined8 *puVar12;

  uint *puVar13;

  ulonglong uVar8;

  

  uVar7 = *(uint *)(param_1 + 2) & param_3;

  uVar8 = (ulonglong)uVar7;

  puVar11 = (undefined8 *)0x0;

  puVar1 = (undefined8 *)(param_2 + uVar8 * 0x18);

  uVar3 = *(uint *)((longlong)puVar1 + 0x14);

  while ((int)uVar3 < 0) {

    puVar13 = (uint *)((longlong)puVar1 + 0x14);

    uVar10 = (uint)uVar8;

    uVar9 = uVar10 - (param_3 & *(uint *)(param_1 + 2));

    uVar7 = uVar9 + param_3 + 1;

    if ((param_3 & *(uint *)(param_1 + 2)) <= uVar10) {

      uVar7 = uVar9;

    }

    if ((uVar3 & 0x7fffffff) < uVar7) {

      uVar4 = *puVar1;

      uVar5 = puVar1[1];

      uVar2 = puVar1[2];

      uVar6 = param_1[1];

      *puVar1 = *param_1;

      puVar1[1] = uVar6;

      puVar1[2] = param_1[2];

      if (puVar11 != (undefined8 *)0x0) {

        puVar1 = puVar11;

      }

      puVar11 = puVar1;

      *param_1 = uVar4;

      param_1[1] = uVar5;

      param_1[2] = uVar2;

      *puVar13 = *puVar13 ^ (uVar7 ^ *puVar13) & 0x7fffffff;

      if (*param_4 < uVar7) {

        *param_4 = uVar7;

      }

    }

    uVar7 = uVar10 + 1 & param_3;

    uVar8 = (ulonglong)uVar7;

    puVar1 = (undefined8 *)(param_2 + uVar8 * 0x18);

    uVar3 = *(uint *)((longlong)puVar1 + 0x14);

  }

  uVar2 = param_1[1];

  puVar12 = puVar1;

  if (puVar11 != (undefined8 *)0x0) {

    puVar12 = puVar11;

  }

  *puVar1 = *param_1;

  puVar1[1] = uVar2;

  puVar1[2] = param_1[2];

  uVar10 = uVar7 - (param_3 & *(uint *)(puVar1 + 2));

  uVar3 = uVar10 + param_3 + 1;

  if ((param_3 & *(uint *)(puVar1 + 2)) <= uVar7) {

    uVar3 = uVar10;

  }

  *(uint *)((longlong)puVar1 + 0x14) =

       *(uint *)((longlong)puVar1 + 0x14) ^

       (uVar3 ^ *(uint *)((longlong)puVar1 + 0x14)) & 0x7fffffff;

  if (*param_4 < uVar3) {

    *param_4 = uVar3;

  }

  return puVar12;

}





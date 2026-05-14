// Address: 0x1401ab3d0
// Ghidra name: FUN_1401ab3d0
// ============ 0x1401ab3d0 FUN_1401ab3d0 (size=229) ============


void FUN_1401ab3d0(longlong param_1,undefined8 *param_2)



{

  uint uVar1;

  uint uVar2;

  longlong lVar3;

  undefined8 uVar4;

  uint uVar5;

  ulonglong uVar6;

  undefined8 *puVar7;

  

  uVar1 = *(uint *)(param_1 + 0x30);

  lVar3 = *(longlong *)(param_1 + 8);

  if (*(code **)(param_1 + 0x20) != (code *)0x0) {

    (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28),*param_2,param_2[1]);

  }

  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;

  uVar6 = (ulonglong)((int)(((longlong)param_2 - *(longlong *)(param_1 + 8)) / 0x18) + 1U & uVar1);

  uVar2 = *(uint *)(lVar3 + 0x14 + uVar6 * 0x18);

  while ((uVar2 & 0x7fffffff) != 0) {

    puVar7 = (undefined8 *)(lVar3 + uVar6 * 0x18);

    uVar4 = puVar7[1];

    *param_2 = *puVar7;

    param_2[1] = uVar4;

    param_2[2] = puVar7[2];

    uVar2 = *(uint *)((longlong)param_2 + 0x14);

    uVar5 = (int)uVar6 + 1U & uVar1;

    *(uint *)((longlong)param_2 + 0x14) = (uVar2 - 1 ^ uVar2) & 0x7fffffff ^ uVar2;

    uVar6 = (ulonglong)uVar5;

    param_2 = puVar7;

    uVar2 = *(uint *)(lVar3 + 0x14 + (ulonglong)uVar5 * 0x18);

  }

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  return;

}





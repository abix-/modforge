// Address: 0x1401e80a0
// Ghidra name: FUN_1401e80a0
// ============ 0x1401e80a0 FUN_1401e80a0 (size=313) ============


undefined8 FUN_1401e80a0(longlong param_1,int *param_2,int *param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined8 uVar7;

  int *piVar8;

  

  piVar8 = (int *)(*(longlong *)(param_1 + 0x2e0) + 0x422f4);

  iVar6 = FUN_1401e7f20();

  if (iVar6 == 1) {

    iVar6 = *param_2;

    *param_3 = iVar6;

    iVar1 = param_2[2];

    iVar2 = *param_2;

    param_3[2] = iVar1 + iVar2;

    iVar3 = param_2[1];

    param_3[1] = iVar3;

    iVar4 = param_2[3];

    iVar5 = param_2[1];

    param_3[3] = iVar5 + iVar4;

    if (param_4 != 0) {

      *param_3 = *piVar8 + iVar6;

      param_3[2] = *piVar8 + iVar1 + iVar2;

      param_3[1] = piVar8[1] + iVar3;

      param_3[3] = piVar8[1] + iVar5 + iVar4;

    }

    return 1;

  }

  if (iVar6 == 2) {

    *param_3 = (piVar8[3] - param_2[3]) - param_2[1];

    param_3[2] = piVar8[3] - param_2[1];

    param_3[1] = *param_2;

    iVar6 = *param_2;

    iVar1 = param_2[3];

    param_3[3] = iVar6 + iVar1;

    return CONCAT71((uint7)(uint3)((uint)(iVar6 + iVar1) >> 8),1);

  }

  if (iVar6 == 3) {

    *param_3 = (piVar8[2] - param_2[2]) - *param_2;

    param_3[2] = piVar8[2] - *param_2;

    param_3[1] = (piVar8[3] - param_2[3]) - param_2[1];

    iVar6 = piVar8[3];

    iVar1 = param_2[1];

    param_3[3] = iVar6 - iVar1;

    return CONCAT71((uint7)(uint3)((uint)(iVar6 - iVar1) >> 8),1);

  }

  if (iVar6 != 4) {

    uVar7 = FUN_14012e850("The physical display is in an unknown or unsupported rotation");

    return uVar7;

  }

  *param_3 = param_2[1];

  param_3[2] = param_2[3] + param_2[1];

  param_3[1] = (piVar8[2] - param_2[2]) - *param_2;

  iVar6 = piVar8[2];

  iVar1 = *param_2;

  param_3[3] = iVar6 - iVar1;

  return CONCAT71((uint7)(uint3)((uint)(iVar6 - iVar1) >> 8),1);

}





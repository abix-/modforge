// Address: 0x1401c9e50
// Ghidra name: FUN_1401c9e50
// ============ 0x1401c9e50 FUN_1401c9e50 (size=204) ============


undefined8 FUN_1401c9e50(undefined8 param_1,uint *param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  int iVar6;

  ulonglong uVar7;

  

  lVar2 = FUN_1401c7e90(param_1,*(undefined4 *)(**(longlong **)(param_2 + 2) + 8),0x400,1);

  if (lVar2 == 0) {

    return 0;

  }

  *param_2 = *param_2 + 1;

  lVar3 = FUN_140184230(*(undefined8 *)(param_2 + 2),(ulonglong)*param_2 << 3);

  *(longlong *)(param_2 + 2) = lVar3;

  *(longlong *)(lVar3 + (ulonglong)(*param_2 - 1) * 8) = lVar2;

  param_2[4] = param_2[4] + 0x400;

  param_2[5] = param_2[5] + 0x400;

  uVar4 = FUN_140184230(*(undefined8 *)(param_2 + 6),(ulonglong)param_2[4] << 5);

  uVar7 = 0;

  *(undefined8 *)(param_2 + 6) = uVar4;

  uVar5 = uVar7;

  do {

    uVar1 = uVar5 + 0x20;

    iVar6 = (int)uVar7;

    *(uint **)(uVar5 + *(longlong *)(param_2 + 6)) = param_2;

    *(longlong *)(*(longlong *)(param_2 + 6) + -0x18 + uVar1) = lVar2;

    *(int *)(*(longlong *)(param_2 + 6) + -8 + uVar1) = iVar6;

    uVar7 = (ulonglong)(iVar6 + 1U);

    lVar3 = *(longlong *)(param_2 + 6);

    *(ulonglong *)(lVar3 + -0x10 + uVar1) =

         (ulonglong)(uint)(iVar6 * *(int *)(lVar2 + 0x24)) + *(longlong *)(lVar2 + 0x10);

    uVar5 = uVar1;

  } while (iVar6 + 1U < 0x400);

  return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);

}





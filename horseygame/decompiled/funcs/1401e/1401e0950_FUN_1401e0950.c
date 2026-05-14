// Address: 0x1401e0950
// Ghidra name: FUN_1401e0950
// ============ 0x1401e0950 FUN_1401e0950 (size=158) ============


void FUN_1401e0950(longlong param_1,int param_2,int param_3,ulonglong param_4)



{

  undefined4 uVar1;

  longlong *plVar2;

  

  param_4 = param_4 & 0xffffffff;

  if (param_2 != *(int *)(param_1 + 0x70 + param_4 * 4)) {

    plVar2 = *(longlong **)(param_1 + 0x10);

    uVar1 = FUN_1401e0840(param_2);

    (**(code **)(*plVar2 + 0x228))(plVar2,param_4,1,uVar1);

    *(int *)(param_1 + 0x70 + param_4 * 4) = param_2;

  }

  if (param_3 != *(int *)(param_1 + 0x7c + param_4 * 4)) {

    plVar2 = *(longlong **)(param_1 + 0x10);

    uVar1 = FUN_1401e0840(param_3);

    (**(code **)(*plVar2 + 0x228))(plVar2,param_4,2,uVar1);

    *(int *)(param_1 + 0x7c + param_4 * 4) = param_3;

  }

  return;

}





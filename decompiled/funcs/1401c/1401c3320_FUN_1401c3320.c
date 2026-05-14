// Address: 0x1401c3320
// Ghidra name: FUN_1401c3320
// ============ 0x1401c3320 FUN_1401c3320 (size=138) ============


void FUN_1401c3320(longlong param_1,longlong *param_2,int param_3)



{

  longlong *plVar1;

  longlong local_18;

  int local_10;

  undefined4 local_c;

  

  plVar1 = *(longlong **)(*param_2 + 0x10);

  FUN_1401cb5f0(param_1,plVar1);

  local_18 = (ulonglong)*(uint *)(param_2 + 1) + plVar1[0xf];

  local_10 = *(int *)(*plVar1 + 4) - *(uint *)(param_2 + 1);

  local_c = 0x2a;

  if (param_3 == 0) {

    local_c = 0x39;

  }

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0x158))(*(longlong **)(param_1 + 0x120),&local_18)

  ;

  return;

}





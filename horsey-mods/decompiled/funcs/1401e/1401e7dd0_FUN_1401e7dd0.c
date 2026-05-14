// Address: 0x1401e7dd0
// Ghidra name: FUN_1401e7dd0
// ============ 0x1401e7dd0 FUN_1401e7dd0 (size=94) ============


void FUN_1401e7dd0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)



{

  longlong lVar1;

  longlong *plVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  (**(code **)(**(longlong **)(lVar1 + 0x48) + 0xa0))();

  plVar2 = *(longlong **)(lVar1 + 0x48);

  (**(code **)(*plVar2 + 0x60))(plVar2,param_4,1,param_3,0);

  return;

}





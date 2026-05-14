// Address: 0x14002cc70
// Ghidra name: FUN_14002cc70
// ============ 0x14002cc70 FUN_14002cc70 (size=36) ============


void FUN_14002cc70(longlong *param_1)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)((longlong)*(int *)(*(longlong *)*param_1 + 4) + 0x48 + *param_1);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x10))();

  }

  return;

}




